#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, f); T (34, x); T (17, y); T (2, f); T (4, c); T (2, f)]
*/
IND_TYPE c, cp_0, c12_p_0, cp_1, c12, f, fp_0, f16_p_0, f17_p_0, fp_1, f16_p_1, fp_2, f16, f17, w, wp_0, x, xp_0, x12_p_0, xp_1, x12, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y8 = 0;
IND_TYPE x13 = 0;
IND_TYPE h = 0;
IND_TYPE w8 = 0;
IND_TYPE c13 = 0;
IND_TYPE f18 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_32 ,mem_vec_33 ,mem_vec_34 ,mem_vec_35 ,mem_vec_36 ,mem_vec_37 ,mem_vec_38 ,mem_vec_39 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f17 = f18, f17_p_0 = 0;
	f17 < f18 + 512;
	f17 += 256, f17_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 4) (256 / 64)
	for (c12 = c13, c12_p_0 = 0;
		c12 < c13 + 256;
		c12 += 64, c12_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 64, f = 256
		// T (f, 2) (256 / 128)
		for (f16 = f17, f16_p_1 = f17_p_0, f16_p_0 = 0;
			f16 < f17 + 256;
			f16 += 128, f16_p_1 += 128, f16_p_0 += 128){
			// y = 34, x = 34, h = 3, w = 3, c = 64, f = 128
			// T (y, 17) (34 / 2)
			for (y = y8, yp_0 = 0;
				y < y8 + 34;
				y += 2, yp_0 += 2){
				// y = 2, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (x, 34) (34 / 1)
				for (x12 = x13, x12_p_0 = 0;
					x12 < x13 + 34;
					x12 += 1, x12_p_0 += 1){
					// y = 2, x = 1, h = 3, w = 3, c = 64, f = 128
					// T (f, 2) (128 / 64)
					for (f = f16, fp_2 = f16_p_1, fp_1 = f16_p_0, fp_0 = 0;
						f < f16 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 2, x = 1, h = 3, w = 3, c = 64, f = 64
						// T (w, 3) (3 / 1)
						for (w = w8, wp_0 = 0;
							w < w8 + 3;
							w += 1, wp_0 += 1){
							// y = 2, x = 1, h = 3, w = 1, c = 64, f = 64
							// T (x, 1) (1 / 1)
							for (x = x12, xp_1 = x12_p_0, xp_0 = 0;
								x < x12 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_32 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_33 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_34 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_35 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_36 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_37 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_38 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_39 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 3, w = 1, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
											c < c12 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_32);
											mem_vec_32 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_33);
											mem_vec_33 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_34);
											mem_vec_34 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_35);
											mem_vec_35 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_36);
											mem_vec_36 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_37);
											mem_vec_37 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_38);
											mem_vec_38 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_39);
											mem_vec_39 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_32);
											mem_vec_32 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_33);
											mem_vec_33 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_34);
											mem_vec_34 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_35);
											mem_vec_35 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_36);
											mem_vec_36 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_37);
											mem_vec_37 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_38);
											mem_vec_38 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_39);
											mem_vec_39 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_32);
											mem_vec_32 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_33);
											mem_vec_33 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_34);
											mem_vec_34 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_35);
											mem_vec_35 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_36);
											mem_vec_36 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_37);
											mem_vec_37 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_38);
											mem_vec_38 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_39);
											mem_vec_39 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_32);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_33);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_34);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_35);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_36);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_37);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_38);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_39);
							}
						}
					}
				}
			}
		}
	}
}


}