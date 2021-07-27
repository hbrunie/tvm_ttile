#undef BIAS

#include <stdio.h>
#include "ttile.h"


void ttile_conv2d(float* K, float * Input, float * Output, int W, int H, int C, int F, int X, int Y) {
	/*
	Simple Convolution

	Inputs:
		- K: weight
		- Input: Input
		- Output: Output
		- W: kernel_w
		- H: kernel_h
		- C: in_channels
		- F: out_channels
		- X: width
		- Y: height

	*/
    for (int f=0; f<F; f++){
        for (int y=0; y<Y; y++){
            for (int x=0; x<X; x++){
                Output[f*Y*X + y*X + x] = 0.0;
                for (int c=0; c<C; c++){
                    for (int h=0; h<H; h++){
                        for (int w=0; w<W; w++){
                            Output[f*Y*X + y*X + x] += Input[c*(Y+H-1)*(X+W-1) + (y+h)*(X+W-1) + x+w] * K[f * C*H*W + c * H*W + h*W + w];
						}
					}
				}
			}
	    }
	}
    return;
}
