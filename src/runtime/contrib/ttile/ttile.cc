/*!
 * \file Use external ttile library call.
 */
#include <tvm/runtime/data_type.h>
#include <tvm/runtime/registry.h>
#include <tvm/support/logging.h>

extern "C" {
#include "ttile.h"
}

#include "ttile_utils.h"

namespace tvm {
namespace contrib {


struct TtileCon2dSOp {
  typedef float TDatatype;
  void operator()(float * I, float * W, float * O, int batch_size, int height, int width, int in_channels, int out_channels, int kernel_h, int kernel_w, int pad_h, int pad_w, int stride_h, int stride_w, int dilation_h, int dilation_w ) {

    ttile_conv2d(W, I, O, 
    stride_w, 
    stride_h, 
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

  if (TypeMatch(A->dtype, kDLFloat, 32))
    CallTtile(args, ret, TtileCon2dSOp());
});

}  // namespace contrib
}  // namespace tvm