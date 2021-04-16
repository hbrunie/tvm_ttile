#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (1, f); T (1, x); T (4, y); T (4, f)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, f18_p_0, fp_1, f18, h, hp_0, w, wp_0, x, xp_0, x18_p_0, xp_1, x18, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y12 = 0;
IND_TYPE x19 = 0;
IND_TYPE h12 = 0;
IND_TYPE w12 = 0;
IND_TYPE c19 = 0;
IND_TYPE f19 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f18 = f19, f18_p_0 = 0;
	f18 < f19 + 256;
	f18 += 64, f18_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (y, 4) (28 / 7)
	for (y = y12, yp_0 = 0;
		y < y12 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (x, 1) (28 / 28)
		for (x18 = x19, x18_p_0 = 0;
			x18 < x19 + 28;
			x18 += 28, x18_p_0 += 28){
			// y = 7, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (f, 1) (64 / 64)
			for (f = f18, fp_1 = f18_p_0, fp_0 = 0;
				f < f18 + 64;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 7, x = 28, h = 3, w = 3, c = 128, f = 64
				// T (c, 8) (128 / 16)
				for (c18 = c19, c18_p_0 = 0;
					c18 < c19 + 128;
					c18 += 16, c18_p_0 += 16){
					// y = 7, x = 28, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w12, wp_0 = 0;
						w < w12 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 28, h = 3, w = 1, c = 16, f = 64
						// T (x, 28) (28 / 1)
						for (x = x18, xp_1 = x18_p_0, xp_0 = 0;
							x < x18 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 7, x = 1, h = 3, w = 1, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h12, hp_0 = 0;
								h < h12 + 3;
								h += 1, hp_0 += 1){
										mem_vec_168 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_169 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_170 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_171 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
											c < c18 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_168);
											mem_vec_168 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_169);
											mem_vec_169 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_170);
											mem_vec_170 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_171);
											mem_vec_171 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_172);
											mem_vec_172 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_173);
											mem_vec_173 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_174);
											mem_vec_174 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_175);
											mem_vec_175 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_176);
											mem_vec_176 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_177);
											mem_vec_177 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_178);
											mem_vec_178 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_179);
											mem_vec_179 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_180);
											mem_vec_180 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_181);
											mem_vec_181 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_182);
											mem_vec_182 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_183);
											mem_vec_183 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_184);
											mem_vec_184 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_185);
											mem_vec_185 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_186);
											mem_vec_186 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_187);
											mem_vec_187 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_188);
											mem_vec_188 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_189);
											mem_vec_189 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_190);
											mem_vec_190 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_191);
											mem_vec_191 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_192);
											mem_vec_192 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_193);
											mem_vec_193 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_194);
											mem_vec_194 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_195);
											mem_vec_195 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_177);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_178);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_179);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_180);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_181);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_182);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_183);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_184);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_185);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_186);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_187);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_188);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_189);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_190);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_191);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_192);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_193);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_194);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_195);
							}
						}
					}
				}
			}
		}
	}
}


}