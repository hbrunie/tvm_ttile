#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (256, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (8, f); T (17, x); T (17, y); T (1, f); T (1, c); T (1, f)]
*/
IND_TYPE c, c0, cp_0, c0_p_0, cp_1, f, f0, fp_0, f0_p_0, f1_p_0, f1, fp_1, f0_p_1, fp_2, w, wp_0, x, x0, xp_0, x0_p_0, xp_1, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y0 = 0;
IND_TYPE x1 = 0;
IND_TYPE h = 0;
IND_TYPE w0 = 0;
IND_TYPE c1 = 0;
IND_TYPE f2 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_0 ,mem_vec_1 ,mem_vec_2 ,mem_vec_3 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f1 = f2, f1_p_0 = 0;
	f1 < f2 + 512;
	f1 += 512, f1_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 1) (256 / 256)
	for (c0 = c1, c0_p_0 = 0;
		c0 < c1 + 256;
		c0 += 256, c0_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (f, 1) (512 / 512)
		for (f0 = f1, f0_p_1 = f1_p_0, f0_p_0 = 0;
			f0 < f1 + 512;
			f0 += 512, f0_p_1 += 512, f0_p_0 += 512){
			// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (y, 17) (34 / 2)
			for (y = y0, yp_0 = 0;
				y < y0 + 34;
				y += 2, yp_0 += 2){
				// y = 2, x = 34, h = 3, w = 3, c = 256, f = 512
				// T (x, 17) (34 / 2)
				for (x0 = x1, x0_p_0 = 0;
					x0 < x1 + 34;
					x0 += 2, x0_p_0 += 2){
					// y = 2, x = 2, h = 3, w = 3, c = 256, f = 512
					// T (f, 8) (512 / 64)
					for (f = f0, fp_2 = f0_p_1, fp_1 = f0_p_0, fp_0 = 0;
						f < f0 + 512;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 2, x = 2, h = 3, w = 3, c = 256, f = 64
						// T (w, 3) (3 / 1)
						for (w = w0, wp_0 = 0;
							w < w0 + 3;
							w += 1, wp_0 += 1){
							// y = 2, x = 2, h = 3, w = 1, c = 256, f = 64
							// T (x, 2) (2 / 1)
							for (x = x0, xp_1 = x0_p_0, xp_0 = 0;
								x < x0 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_0 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_3 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_4 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 3, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c0, cp_1 = c0_p_0, cp_0 = 0;
											c < c0 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_0);
											mem_vec_0 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1);
											mem_vec_1 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2);
											mem_vec_2 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3);
											mem_vec_3 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4);
											mem_vec_4 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5);
											mem_vec_5 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6);
											mem_vec_6 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7);
											mem_vec_7 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_0);
											mem_vec_0 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_1);
											mem_vec_1 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_2);
											mem_vec_2 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_3);
											mem_vec_3 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_4);
											mem_vec_4 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_5);
											mem_vec_5 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_6);
											mem_vec_6 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_7);
											mem_vec_7 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_0);
											mem_vec_0 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_1);
											mem_vec_1 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_2);
											mem_vec_2 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_3);
											mem_vec_3 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_4);
											mem_vec_4 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_5);
											mem_vec_5 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_6);
											mem_vec_6 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_7);
											mem_vec_7 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7);
							}
						}
					}
				}
			}
		}
	}
}


}