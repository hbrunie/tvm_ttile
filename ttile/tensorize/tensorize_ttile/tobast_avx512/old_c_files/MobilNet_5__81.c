#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (256, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (8, f); T (1, x); T (7, y); T (1, f); T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c174_p_0, cp_1, c174, f, fp_0, f112_p_0, f113_p_0, fp_1, f112_p_1, fp_2, f112, f113, h, hp_0, x, xp_0, x138_p_0, xp_1, x138, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y92 = 0;
IND_TYPE x139 = 0;
IND_TYPE h58 = 0;
IND_TYPE w = 0;
IND_TYPE c175 = 0;
IND_TYPE f114 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f113 = f114, f113_p_0 = 0;
	f113 < f114 + 256;
	f113 += 128, f113_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
	// T (c, 1) (256 / 256)
	for (c174 = c175, c174_p_0 = 0;
		c174 < c175 + 256;
		c174 += 256, c174_p_0 += 256){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
		// T (f, 1) (128 / 128)
		for (f112 = f113, f112_p_1 = f113_p_0, f112_p_0 = 0;
			f112 < f113 + 128;
			f112 += 128, f112_p_1 += 128, f112_p_0 += 128){
			// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
			// T (y, 7) (28 / 4)
			for (y = y92, yp_0 = 0;
				y < y92 + 28;
				y += 4, yp_0 += 4){
				// y = 4, x = 28, h = 3, w = 3, c = 256, f = 128
				// T (x, 1) (28 / 28)
				for (x138 = x139, x138_p_0 = 0;
					x138 < x139 + 28;
					x138 += 28, x138_p_0 += 28){
					// y = 4, x = 28, h = 3, w = 3, c = 256, f = 128
					// T (f, 8) (128 / 16)
					for (f = f112, fp_2 = f112_p_1, fp_1 = f112_p_0, fp_0 = 0;
						f < f112 + 128;
						f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
						// y = 4, x = 28, h = 3, w = 3, c = 256, f = 16
						// T (h, 3) (3 / 1)
						for (h = h58, hp_0 = 0;
							h < h58 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 28, h = 1, w = 3, c = 256, f = 16
							// T (x, 28) (28 / 1)
							for (x = x138, xp_1 = x138_p_0, xp_0 = 0;
								x < x138 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										// y = 4, x = 1, h = 1, w = 3, c = 256, f = 16
										// T (c, 256) (256 / 1)
										for (c = c174, cp_1 = c174_p_0, cp_0 = 0;
											c < c174 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_906);
											mem_vec_906 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_907);
											mem_vec_907 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_908);
											mem_vec_908 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_909);
											mem_vec_909 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_906);
											mem_vec_906 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_13 = _mm512_set1_ps(scal_5);


											vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_907);
											mem_vec_907 = vec_12;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_908);
											mem_vec_908 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_909);
											mem_vec_909 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);
											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_906);
											mem_vec_906 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_22 = _mm512_set1_ps(scal_9);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_907);
											mem_vec_907 = vec_21;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_24 = _mm512_set1_ps(scal_10);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_908);
											mem_vec_908 = vec_23;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_909);
											mem_vec_909 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_906);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_907);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_908);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_909);
							}
						}
					}
				}
			}
		}
	}
}


}