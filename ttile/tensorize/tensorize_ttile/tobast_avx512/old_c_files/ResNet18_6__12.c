#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (1, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, f); T (128, c); T (2, x); T (7, y); T (2, f)]
*/
IND_TYPE c, cp_0, c12_p_0, cp_1, c12, f, fp_0, f12_p_0, fp_1, f12, h, hp_0, w, wp_0, x, xp_0, x12_p_0, xp_1, x12, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y8 = 0;
IND_TYPE x13 = 0;
IND_TYPE h8 = 0;
IND_TYPE w8 = 0;
IND_TYPE c13 = 0;
IND_TYPE f13 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_84 ,mem_vec_85 ,mem_vec_86 ,mem_vec_87 ,mem_vec_88 ,mem_vec_89 ,mem_vec_90 ,mem_vec_91 ,mem_vec_92 ,mem_vec_93 ,mem_vec_94 ,mem_vec_95 ,mem_vec_96 ,mem_vec_97 ,mem_vec_98 ,mem_vec_99 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f12 = f13, f12_p_0 = 0;
	f12 < f13 + 128;
	f12 += 64, f12_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (y, 7) (28 / 4)
	for (y = y8, yp_0 = 0;
		y < y8 + 28;
		y += 4, yp_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (x, 2) (28 / 14)
		for (x12 = x13, x12_p_0 = 0;
			x12 < x13 + 28;
			x12 += 14, x12_p_0 += 14){
			// y = 4, x = 14, h = 3, w = 3, c = 128, f = 64
			// T (c, 128) (128 / 1)
			for (c12 = c13, c12_p_0 = 0;
				c12 < c13 + 128;
				c12 += 1, c12_p_0 += 1){
				// y = 4, x = 14, h = 3, w = 3, c = 1, f = 64
				// T (f, 1) (64 / 64)
				for (f = f12, fp_1 = f12_p_0, fp_0 = 0;
					f < f12 + 64;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 14, h = 3, w = 3, c = 1, f = 64
					// T (h, 3) (3 / 1)
					for (h = h8, hp_0 = 0;
						h < h8 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 14, h = 1, w = 3, c = 1, f = 64
						// T (w, 3) (3 / 1)
						for (w = w8, wp_0 = 0;
							w < w8 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 14, h = 1, w = 1, c = 1, f = 64
							// T (x, 14) (14 / 1)
							for (x = x12, xp_1 = x12_p_0, xp_0 = 0;
								x < x12 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_84 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_85 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_86 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_87 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_88 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_89 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_90 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_91 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_92 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_93 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_94 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_95 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_96 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_97 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_98 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_99 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 1, c = 1, f = 64
										// T (c, 1) (1 / 1)
										for (c = c12, cp_1 = c12_p_0, cp_0 = 0;
											c < c12 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_84);
											mem_vec_84 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_85);
											mem_vec_85 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_86);
											mem_vec_86 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_87);
											mem_vec_87 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_88);
											mem_vec_88 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_89);
											mem_vec_89 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_90);
											mem_vec_90 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_91);
											mem_vec_91 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_92);
											mem_vec_92 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_93);
											mem_vec_93 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_94);
											mem_vec_94 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_95);
											mem_vec_95 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_96);
											mem_vec_96 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_97);
											mem_vec_97 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_98);
											mem_vec_98 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_99);
											mem_vec_99 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_84);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_85);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_86);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_87);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_88);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_89);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_90);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_91);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_92);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_93);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_94);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_95);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_96);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_97);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_98);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_99);
							}
						}
					}
				}
			}
		}
	}
}


}