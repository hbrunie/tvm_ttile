#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (2, f); T (1, x); T (4, y); T (2, f)]
*/
IND_TYPE c, cp_0, c15_p_0, cp_1, c15, f, fp_0, f15_p_0, fp_1, f15, h, hp_0, w, wp_0, x, xp_0, x15_p_0, xp_1, x15, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y10 = 0;
IND_TYPE x16 = 0;
IND_TYPE h10 = 0;
IND_TYPE w10 = 0;
IND_TYPE c16 = 0;
IND_TYPE f16 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_140 ,mem_vec_141 ,mem_vec_142 ,mem_vec_143 ,mem_vec_144 ,mem_vec_145 ,mem_vec_146 ,mem_vec_147 ,mem_vec_148 ,mem_vec_149 ,mem_vec_150 ,mem_vec_151 ,mem_vec_152 ,mem_vec_153 ,mem_vec_154 ,mem_vec_155 ,mem_vec_156 ,mem_vec_157 ,mem_vec_158 ,mem_vec_159 ,mem_vec_160 ,mem_vec_161 ,mem_vec_162 ,mem_vec_163 ,mem_vec_164 ,mem_vec_165 ,mem_vec_166 ,mem_vec_167 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f15 = f16, f15_p_0 = 0;
	f15 < f16 + 256;
	f15 += 128, f15_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 4) (28 / 7)
	for (y = y10, yp_0 = 0;
		y < y10 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (28 / 28)
		for (x15 = x16, x15_p_0 = 0;
			x15 < x16 + 28;
			x15 += 28, x15_p_0 += 28){
			// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f = f15, fp_1 = f15_p_0, fp_0 = 0;
				f < f15 + 128;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 7, x = 28, h = 3, w = 3, c = 128, f = 64
				// T (c, 8) (128 / 16)
				for (c15 = c16, c15_p_0 = 0;
					c15 < c16 + 128;
					c15 += 16, c15_p_0 += 16){
					// y = 7, x = 28, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w10, wp_0 = 0;
						w < w10 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 28, h = 3, w = 1, c = 16, f = 64
						// T (x, 28) (28 / 1)
						for (x = x15, xp_1 = x15_p_0, xp_0 = 0;
							x < x15 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 7, x = 1, h = 3, w = 1, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h10, hp_0 = 0;
								h < h10 + 3;
								h += 1, hp_0 += 1){
										mem_vec_140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_142 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_143 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c15, cp_1 = c15_p_0, cp_0 = 0;
											c < c15 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_140);
											mem_vec_140 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_141);
											mem_vec_141 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_142);
											mem_vec_142 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_143);
											mem_vec_143 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_144);
											mem_vec_144 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_145);
											mem_vec_145 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_146);
											mem_vec_146 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_147);
											mem_vec_147 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_148);
											mem_vec_148 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_149);
											mem_vec_149 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_150);
											mem_vec_150 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_151);
											mem_vec_151 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_152);
											mem_vec_152 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_153);
											mem_vec_153 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_154);
											mem_vec_154 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_155);
											mem_vec_155 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_156);
											mem_vec_156 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_157);
											mem_vec_157 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_158);
											mem_vec_158 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_159);
											mem_vec_159 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_160);
											mem_vec_160 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_161);
											mem_vec_161 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_162);
											mem_vec_162 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_163);
											mem_vec_163 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_164);
											mem_vec_164 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_165);
											mem_vec_165 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_166);
											mem_vec_166 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_167);
											mem_vec_167 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_140);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_141);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_142);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_143);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_144);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_145);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_146);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_147);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_148);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_149);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_150);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_151);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_152);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_153);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_154);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_155);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_156);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_157);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_158);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_159);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_160);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_161);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_163);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_167);
							}
						}
					}
				}
			}
		}
	}
}


}