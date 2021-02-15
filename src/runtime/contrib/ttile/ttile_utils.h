/*!
 * \file 
 * \brief 
 */

#ifndef TVM_RUNTIME_CONTRIB_TTILE_COMMON_H_
#define TVM_RUNTIME_CONTRIB_TTILE_COMMON_H_

#include <tvm/runtime/data_type.h>
#include <tvm/runtime/registry.h>

#include <algorithm>
#include <string>

namespace tvm {
namespace contrib {

using namespace runtime;

template <typename TTtileOp>
inline void CallTtile(TVMArgs args, TVMRetValue* ret, TTtileOp op) {
  DLTensor* I = args[0];
  DLTensor* W = args[1];
  DLTensor* O = args[2];

  int batch_size = args[3];
  int height = args[4];
  int width = args[5]; 
  int in_channels = args[6]; 
  int out_channels = args[7];
  int kernel_h = args[8];
  int kernel_w = args[9];
  int pad_h = args[10];
  int pad_w = args[11]; 
  int stride_h = args[12]; 
  int stride_w = args[13]; 
  int dilation_h = args[14]; 
  int dilation_w = args[15];

op(
reinterpret_cast<typename TTtileOp::TDatatype*>(static_cast<char*>(I->data) + I->byte_offset),
reinterpret_cast<typename TTtileOp::TDatatype*>(static_cast<char*>(W->data) + W->byte_offset),
reinterpret_cast<typename TTtileOp::TDatatype*>(static_cast<char*>(O->data) + O->byte_offset),
batch_size, height, width, in_channels, out_channels, kernel_h, kernel_w, pad_h, pad_w, stride_h, stride_w, dilation_h, dilation_w
);
}

}  // namespace contrib
}  // namespace tvm
#endif  // TVM_RUNTIME_CONTRIB_TTILE_COMMON_H_
