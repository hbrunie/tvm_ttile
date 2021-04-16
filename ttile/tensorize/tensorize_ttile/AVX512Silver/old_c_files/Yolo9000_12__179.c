#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (256, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (4, f); T (17, y); T (1, x); T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c27_p_0, cp_1, c27, f, fp_0, f29_p_0, f30_p_0, fp_1, f29_p_1, fp_2, f29, f30, h, hp_0, x, xp_0, x24_p_0, xp_1, x24, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y16 = 0;
IND_TYPE x25 = 0;
IND_TYPE h16 = 0;
IND_TYPE w = 0;
IND_TYPE c28 = 0;
IND_TYPE f31 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_88 ,mem_vec_89 ,mem_vec_90 ,mem_vec_91 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f30 = f31, f30_p_0 = 0;
	f30 < f31 + 512;
	f30 += 512, f30_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (f, 2) (512 / 256)
	for (f29 = f30, f29_p_1 = f30_p_0, f29_p_0 = 0;
		f29 < f30 + 512;
		f29 += 256, f29_p_1 += 256, f29_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (x, 1) (34 / 34)
		for (x24 = x25, x24_p_0 = 0;
			x24 < x25 + 34;
			x24 += 34, x24_p_0 += 34){
			// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
			// T (y, 17) (34 / 2)
			for (y = y16, yp_0 = 0;
				y < y16 + 34;
				y += 2, yp_0 += 2){
				// y = 2, x = 34, h = 3, w = 3, c = 256, f = 256
				// T (f, 4) (256 / 64)
				for (f = f29, fp_2 = f29_p_1, fp_1 = f29_p_0, fp_0 = 0;
					f < f29 + 256;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 2, x = 34, h = 3, w = 3, c = 256, f = 64
					// T (c, 1) (256 / 256)
					for (c27 = c28, c27_p_0 = 0;
						c27 < c28 + 256;
						c27 += 256, c27_p_0 += 256){
						// y = 2, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (h, 3) (3 / 1)
						for (h = h16, hp_0 = 0;
							h < h16 + 3;
							h += 1, hp_0 += 1){
							// y = 2, x = 34, h = 1, w = 3, c = 256, f = 64
							// T (x, 34) (34 / 1)
							for (x = x24, xp_1 = x24_p_0, xp_0 = 0;
								x < x24 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_88 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_89 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_90 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_91 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_92 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_93 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_94 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_95 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 1, w = 3, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c27, cp_1 = c27_p_0, cp_0 = 0;
											c < c27 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_88);
											mem_vec_88 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_89);
											mem_vec_89 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_90);
											mem_vec_90 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_91);
											mem_vec_91 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_92);
											mem_vec_92 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_93);
											mem_vec_93 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_94);
											mem_vec_94 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_95);
											mem_vec_95 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_88);
											mem_vec_88 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_89);
											mem_vec_89 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_90);
											mem_vec_90 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_91);
											mem_vec_91 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_92);
											mem_vec_92 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_93);
											mem_vec_93 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_94);
											mem_vec_94 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_95);
											mem_vec_95 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_88);
											mem_vec_88 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_89);
											mem_vec_89 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_90);
											mem_vec_90 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_91);
											mem_vec_91 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_92);
											mem_vec_92 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_93);
											mem_vec_93 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_94);
											mem_vec_94 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_95);
											mem_vec_95 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_88);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_89);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_90);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_91);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_92);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_93);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_94);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_95);
							}
						}
					}
				}
			}
		}
	}
}


}