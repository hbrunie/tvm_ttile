/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*!
 * \file Use external ttile library call.
 */
#include <tvm/runtime/data_type.h>
#include <tvm/runtime/registry.h>
#include <tvm/support/logging.h>

#include <iostream>
#include <fstream>

extern "C" {
#include "ttile.h"
}

#include "ttile_utils.h"


void create_library(){
  std::ofstream myfile, header;

  header.open ("/home/cali/Documents/tvm_ttile/tmp/ttile.h");

  header << "#ifndef _TTILE_H_\n";
  header << "#define _TTILE_H_\n";

  header << "extern void ttile_conv2d(float *, float *, float *, int, int, int, int, int, int);\n";

  header << "#endif\n";

  header.close();

  myfile.open ("/home/cali/Documents/tvm_ttile/tmp/ttile.c");

  myfile << "#include <stdio.h>\n";
  myfile << "#include \"ttile.h\"\n";
  myfile << "void ttile_conv2d(float* K, float * Input, float * Output, int W, int H, int C, int F, int X, int Y) {";
  myfile << " printf(\"new function\");\n";
  myfile << " for (int f=0; f<F; f++){\n";
  myfile << "   for (int y=0; y<Y; y++){\n";
  myfile << "     for (int x=0; x<X; x++){\n";
  myfile << "       Output[f*Y*X + y*X + x] = 0.0;\n";
  myfile << "       for (int c=0; c<C; c++){\n";
  myfile << "         for (int h=0; h<H; h++){\n";
  myfile << "           for (int w=0; w<W; w++){\n";
  myfile << "             Output[f*Y*X + y*X + x] += Input[c*(Y+H-1)*(X+W-1) + (y+h)*(X+W-1) + x+w] * K[f * C*H*W + c * H*W + h*W + w];\n";
  myfile << "           }\n";
  myfile << "         }\n";
  myfile << "       }\n";
  myfile << "     }\n";
  myfile << "    }\n";
  myfile << "   }\n";
  myfile << "   return;\n";
  myfile << "}\n";

  myfile.close();
  system("gcc -o /home/cali/Documents/tvm_ttile/tmp/ttile.o -c /home/cali/Documents/tvm_ttile/tmp/ttile.c");
  system("gcc -shared -o /home/cali/Documents/tvm_ttile/tmp/libttile.so /home/cali/Documents/tvm_ttile/tmp/ttile.o -lm");
  system("sudo mv /home/cali/Documents/tvm_ttile/tmp/libttile.so /usr/lib/");
  return;
}



namespace tvm {
namespace contrib {

struct TtileCon2dSOp {
  typedef float TDatatype;
  void operator()(float * I, float * W, float * O, int batch_size, int height, int width, int in_channels, int out_channels, int kernel_h, int kernel_w, int pad_h, int pad_w, int stride_h, int stride_w, int dilation_h, int dilation_w ) {
    
    ttile_conv2d(W, I, O, 
    kernel_w, 
    kernel_h, 
    in_channels, 
    out_channels, 
    width, 
    height
    );
  }
};


TVM_REGISTER_GLOBAL("tvm.contrib.ttile.conv2d").set_body([](TVMArgs args, TVMRetValue* ret) {
  DLTensor* A = args[0];
  ICHECK(TypeMatch(A->dtype, kDLFloat, 32) || TypeMatch(A->dtype, kDLFloat, 64));

  create_library();

  if (TypeMatch(A->dtype, kDLFloat, 32))
    CallTtile(args, ret, TtileCon2dSOp());
});

}  // namespace contrib
}  // namespace tvm
