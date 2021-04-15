#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (4, c); T (4, f); T (2, x); T (7, y); T (1, x)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x18_p_0, x19_p_0, xp_1, x18_p_1, xp_2, x18, x19, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y10 = 0;
IND_TYPE x20 = 0;
IND_TYPE h9 = 0;
IND_TYPE w10 = 0;
IND_TYPE c16 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 1) (56 / 56)
for (x19 = x20, x19_p_0 = 0;
	x19 < x20 + 56;
	x19 += 56, x19_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (y, 7) (56 / 8)
	for (y = y10, yp_0 = 0;
		y < y10 + 56;
		y += 8, yp_0 += 8){
		// y = 8, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (56 / 28)
		for (x18 = x19, x18_p_1 = x19_p_0, x18_p_0 = 0;
			x18 < x19 + 56;
			x18 += 28, x18_p_1 += 28, x18_p_0 += 28){
			// y = 8, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 4) (128 / 32)
			for (f = f10, fp_0 = 0;
				f < f10 + 128;
				f += 32, fp_0 += 32){
				// y = 8, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 4) (128 / 32)
				for (c15 = c16, c15_p_0 = 0;
					c15 < c16 + 128;
					c15 += 32, c15_p_0 += 32){
					// y = 8, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w10, wp_0 = 0;
						w < w10 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 28, h = 3, w = 1, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x18, xp_2 = x18_p_1, xp_1 = x18_p_0, xp_0 = 0;
							x < x18 + 28;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 8, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h9, hp_0 = 0;
								h < h9 + 3;
								h += 1, hp_0 += 1){
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
										// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
											c < c15 + 32;
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