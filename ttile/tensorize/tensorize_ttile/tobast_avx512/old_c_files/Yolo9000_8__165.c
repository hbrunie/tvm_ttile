#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (128, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (34, y); T (1, f); T (1, c); T (2, f); T (34, x); T (2, f)]
*/
IND_TYPE c, cp_0, c102_p_0, cp_1, c102, f, fp_0, f136_p_0, f137_p_0, fp_1, f136_p_1, fp_2, f136, f137, h, hp_0, x, xp_0, x120_p_0, xp_1, x120, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y68 = 0;
IND_TYPE x121 = 0;
IND_TYPE h62 = 0;
IND_TYPE w = 0;
IND_TYPE c103 = 0;
IND_TYPE f138 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_464 ,mem_vec_465 ,mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f137 = f138, f137_p_0 = 0;
	f137 < f138 + 256;
	f137 += 128, f137_p_0 += 128){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 128
	// T (x, 34) (68 / 2)
	for (x120 = x121, x120_p_0 = 0;
		x120 < x121 + 68;
		x120 += 2, x120_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 128
		// T (f, 2) (128 / 64)
		for (f136 = f137, f136_p_1 = f137_p_0, f136_p_0 = 0;
			f136 < f137 + 128;
			f136 += 64, f136_p_1 += 64, f136_p_0 += 64){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c102 = c103, c102_p_0 = 0;
				c102 < c103 + 128;
				c102 += 128, c102_p_0 += 128){
				// y = 68, x = 2, h = 3, w = 3, c = 128, f = 64
				// T (f, 1) (64 / 64)
				for (f = f136, fp_2 = f136_p_1, fp_1 = f136_p_0, fp_0 = 0;
					f < f136 + 64;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 68, x = 2, h = 3, w = 3, c = 128, f = 64
					// T (y, 34) (68 / 2)
					for (y = y68, yp_0 = 0;
						y < y68 + 68;
						y += 2, yp_0 += 2){
						// y = 2, x = 2, h = 3, w = 3, c = 128, f = 64
						// T (h, 3) (3 / 1)
						for (h = h62, hp_0 = 0;
							h < h62 + 3;
							h += 1, hp_0 += 1){
							// y = 2, x = 2, h = 1, w = 3, c = 128, f = 64
							// T (x, 2) (2 / 1)
							for (x = x120, xp_1 = x120_p_0, xp_0 = 0;
								x < x120 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_464 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_465 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_466 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_467 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										// y = 2, x = 1, h = 1, w = 3, c = 128, f = 64
										// T (c, 128) (128 / 1)
										for (c = c102, cp_1 = c102_p_0, cp_0 = 0;
											c < c102 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_464);
											mem_vec_464 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_465);
											mem_vec_465 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_466);
											mem_vec_466 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_467);
											mem_vec_467 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_468);
											mem_vec_468 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_469);
											mem_vec_469 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_470);
											mem_vec_470 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_471);
											mem_vec_471 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);
											vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_464);
											mem_vec_464 = vec_14;

											vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_465);
											mem_vec_465 = vec_17;

											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_466);
											mem_vec_466 = vec_19;

											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_467);
											mem_vec_467 = vec_21;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_24 = _mm512_set1_ps(scal_3);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_468);
											mem_vec_468 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_469);
											mem_vec_469 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_470);
											mem_vec_470 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_471);
											mem_vec_471 = vec_27;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);
											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_464);
											mem_vec_464 = vec_28;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_465);
											mem_vec_465 = vec_31;

											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_466);
											mem_vec_466 = vec_33;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_467);
											mem_vec_467 = vec_35;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_5);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_468);
											mem_vec_468 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_469);
											mem_vec_469 = vec_39;



											vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_470);
											mem_vec_470 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_471);
											mem_vec_471 = vec_41;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_467);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_471);
							}
						}
					}
				}
			}
		}
	}
}


}