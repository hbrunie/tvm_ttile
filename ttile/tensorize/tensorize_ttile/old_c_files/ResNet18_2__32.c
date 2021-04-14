#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (14, x); T (7, y); T (2, f); T (8, c); T (4, x)]
*/
IND_TYPE c, cp_0, c24_p_0, cp_1, c24, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x32_p_0, x33_p_0, xp_1, x32_p_1, xp_2, x32, x33, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y16 = 0;
IND_TYPE x34 = 0;
IND_TYPE h16 = 0;
IND_TYPE w16 = 0;
IND_TYPE c25 = 0;
IND_TYPE f16 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
for (x33 = x34, x33_p_0 = 0;
	x33 < x34 + 56;
	x33 += 14, x33_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 64, f = 64
	// T (c, 8) (64 / 8)
	for (c24 = c25, c24_p_0 = 0;
		c24 < c25 + 64;
		c24 += 8, c24_p_0 += 8){
		// y = 56, x = 14, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f = f16, fp_0 = 0;
			f < f16 + 64;
			f += 32, fp_0 += 32){
			// y = 56, x = 14, h = 3, w = 3, c = 8, f = 32
			// T (y, 7) (56 / 8)
			for (y = y16, yp_0 = 0;
				y < y16 + 56;
				y += 8, yp_0 += 8){
				// y = 8, x = 14, h = 3, w = 3, c = 8, f = 32
				// T (x, 14) (14 / 1)
				for (x32 = x33, x32_p_1 = x33_p_0, x32_p_0 = 0;
					x32 < x33 + 14;
					x32 += 1, x32_p_1 += 1, x32_p_0 += 1){
					// y = 8, x = 1, h = 3, w = 3, c = 8, f = 32
					// T (h, 3) (3 / 1)
					for (h = h16, hp_0 = 0;
						h < h16 + 3;
						h += 1, hp_0 += 1){
						// y = 8, x = 1, h = 1, w = 3, c = 8, f = 32
						// T (w, 3) (3 / 1)
						for (w = w16, wp_0 = 0;
							w < w16 + 3;
							w += 1, wp_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 8, f = 32
							// T (x, 1) (1 / 1)
							for (x = x32, xp_2 = x32_p_1, xp_1 = x32_p_0, xp_0 = 0;
								x < x32 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_128 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_129 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c24, cp_1 = c24_p_0, cp_0 = 0;
											c < c24 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_128);
											mem_vec_128 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_129);
											mem_vec_129 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_130);
											mem_vec_130 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_131);
											mem_vec_131 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_132);
											mem_vec_132 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_133);
											mem_vec_133 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_134);
											mem_vec_134 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_135);
											mem_vec_135 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_136);
											mem_vec_136 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_137);
											mem_vec_137 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_138);
											mem_vec_138 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_139);
											mem_vec_139 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_140);
											mem_vec_140 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_141);
											mem_vec_141 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_142);
											mem_vec_142 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_143);
											mem_vec_143 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_128);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_129);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_130);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_131);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_132);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_133);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_134);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_135);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_136);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_137);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_138);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_139);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_140);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_143);
							}
						}
					}
				}
			}
		}
	}
}


}