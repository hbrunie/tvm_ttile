#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (7, y); U (3, w); T (32, c); Hoist_vars [c]; T (3, h);
  T (28, x); T (4, y); T (8, c); T (16, f); T (1, c)]
*/
IND_TYPE c, cp_0, c454_p_0, c455_p_0, cp_1, c454_p_1, cp_2, c454, c455, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y398 = 0;
IND_TYPE x409 = 0;
IND_TYPE h221 = 0;
IND_TYPE w = 0;
IND_TYPE c456 = 0;
IND_TYPE f368 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2649 ,mem_vec_2650 ,mem_vec_2651 ,mem_vec_2652 ,mem_vec_2653 ,mem_vec_2654 ,mem_vec_2655 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (c, 1) (256 / 256)
for (c455 = c456, c455_p_0 = 0;
	c455 < c456 + 256;
	c455 += 256, c455_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (f, 16) (256 / 16)
	for (f = f368, fp_0 = 0;
		f < f368 + 256;
		f += 16, fp_0 += 16){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 16
		// T (c, 8) (256 / 32)
		for (c454 = c455, c454_p_1 = c455_p_0, c454_p_0 = 0;
			c454 < c455 + 256;
			c454 += 32, c454_p_1 += 32, c454_p_0 += 32){
			// y = 28, x = 28, h = 3, w = 3, c = 32, f = 16
			// T (y, 4) (28 / 7)
			for (y = y398, yp_0 = 0;
				y < y398 + 28;
				y += 7, yp_0 += 7){
				// y = 7, x = 28, h = 3, w = 3, c = 32, f = 16
				// T (x, 28) (28 / 1)
				for (x = x409, xp_0 = 0;
					x < x409 + 28;
					x += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 32, f = 16
					// T (h, 3) (3 / 1)
					for (h = h221, hp_0 = 0;
						h < h221 + 3;
						h += 1, hp_0 += 1){
								mem_vec_2649 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								// y = 7, x = 1, h = 1, w = 3, c = 32, f = 16
								// T (c, 32) (32 / 1)
								for (c = c454, cp_2 = c454_p_1, cp_1 = c454_p_0, cp_0 = 0;
									c < c454 + 32;
									c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2649);
									mem_vec_2649 = vec_0;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_4 = _mm512_set1_ps(scal_1);


									vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2650);
									mem_vec_2650 = vec_3;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_6 = _mm512_set1_ps(scal_2);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2651);
									mem_vec_2651 = vec_5;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_8 = _mm512_set1_ps(scal_3);


									vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2652);
									mem_vec_2652 = vec_7;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_10 = _mm512_set1_ps(scal_4);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2653);
									mem_vec_2653 = vec_9;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_12 = _mm512_set1_ps(scal_5);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2654);
									mem_vec_2654 = vec_11;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_14 = _mm512_set1_ps(scal_6);


									vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_2655);
									mem_vec_2655 = vec_13;
									scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_16 = _mm512_set1_ps(scal_7);
									vec_17 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_15 = _mm512_fmadd_ps(vec_16, vec_17, mem_vec_2649);
									mem_vec_2649 = vec_15;
									scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_19 = _mm512_set1_ps(scal_8);


									vec_18 = _mm512_fmadd_ps(vec_19, vec_17, mem_vec_2650);
									mem_vec_2650 = vec_18;
									scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_21 = _mm512_set1_ps(scal_9);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_17, mem_vec_2651);
									mem_vec_2651 = vec_20;
									scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_23 = _mm512_set1_ps(scal_10);


									vec_22 = _mm512_fmadd_ps(vec_23, vec_17, mem_vec_2652);
									mem_vec_2652 = vec_22;
									scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_11);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_17, mem_vec_2653);
									mem_vec_2653 = vec_24;
									scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
									vec_27 = _mm512_set1_ps(scal_12);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_17, mem_vec_2654);
									mem_vec_2654 = vec_26;
									scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
									vec_29 = _mm512_set1_ps(scal_13);


									vec_28 = _mm512_fmadd_ps(vec_29, vec_17, mem_vec_2655);
									mem_vec_2655 = vec_28;
									scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_31 = _mm512_set1_ps(scal_14);
									vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_30 = _mm512_fmadd_ps(vec_31, vec_32, mem_vec_2649);
									mem_vec_2649 = vec_30;
									scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_34 = _mm512_set1_ps(scal_15);


									vec_33 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2650);
									mem_vec_2650 = vec_33;
									scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_36 = _mm512_set1_ps(scal_16);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_32, mem_vec_2651);
									mem_vec_2651 = vec_35;
									scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_38 = _mm512_set1_ps(scal_17);


									vec_37 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_2652);
									mem_vec_2652 = vec_37;
									scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
									vec_40 = _mm512_set1_ps(scal_18);


									vec_39 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_2653);
									mem_vec_2653 = vec_39;
									scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
									vec_42 = _mm512_set1_ps(scal_19);


									vec_41 = _mm512_fmadd_ps(vec_42, vec_32, mem_vec_2654);
									mem_vec_2654 = vec_41;
									scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
									vec_44 = _mm512_set1_ps(scal_20);


									vec_43 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_2655);
									mem_vec_2655 = vec_43;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2649);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2650);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2651);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2652);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2653);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2654);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2655);
					}
				}
			}
		}
	}
}


}