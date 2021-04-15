#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (2, f); T (32, c); T (7, x); T (7, y); T (1, f)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, f18_p_0, fp_1, f18, h, hp_0, w, wp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y12 = 0;
IND_TYPE x19 = 0;
IND_TYPE h12 = 0;
IND_TYPE w12 = 0;
IND_TYPE c19 = 0;
IND_TYPE f19 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_116 ,mem_vec_117 ,mem_vec_118 ,mem_vec_119 ,mem_vec_120 ,mem_vec_121 ,mem_vec_122 ,mem_vec_123 ,mem_vec_124 ,mem_vec_125 ,mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f18 = f19, f18_p_0 = 0;
	f18 < f19 + 128;
	f18 += 128, f18_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 7) (28 / 4)
	for (y = y12, yp_0 = 0;
		y < y12 + 28;
		y += 4, yp_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 7) (28 / 4)
		for (x18 = x19, x18_p_0 = 0;
			x18 < x19 + 28;
			x18 += 4, x18_p_0 += 4){
			// y = 4, x = 4, h = 3, w = 3, c = 128, f = 128
			// T (c, 32) (128 / 4)
			for (c18 = c19, c18_p_0 = 0;
				c18 < c19 + 128;
				c18 += 4, c18_p_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 4, f = 128
				// T (f, 2) (128 / 64)
				for (f = f18, fp_1 = f18_p_0, fp_0 = 0;
					f < f18 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 4, x = 4, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h12, hp_0 = 0;
						h < h12 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 4, h = 1, w = 3, c = 4, f = 64
						// T (w, 3) (3 / 1)
						for (w = w12, wp_0 = 0;
							w < w12 + 3;
							w += 1, wp_0 += 1){
							// y = 4, x = 4, h = 1, w = 1, c = 4, f = 64
							// T (x, 4) (4 / 1)
							for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
								x < x18 + 4;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_116 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_117 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_118 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_119 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 1, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
											c < c18 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_116);
											mem_vec_116 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_117);
											mem_vec_117 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_118);
											mem_vec_118 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_119);
											mem_vec_119 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_120);
											mem_vec_120 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_121);
											mem_vec_121 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_122);
											mem_vec_122 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_123);
											mem_vec_123 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_124);
											mem_vec_124 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_125);
											mem_vec_125 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_126);
											mem_vec_126 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_127);
											mem_vec_127 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_128);
											mem_vec_128 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_129);
											mem_vec_129 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_130);
											mem_vec_130 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_131);
											mem_vec_131 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_116);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_117);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_118);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_119);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_120);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_121);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_122);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_123);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_124);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_125);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_126);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_127);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_128);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_129);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_130);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_131);
							}
						}
					}
				}
			}
		}
	}
}


}