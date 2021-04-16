#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (1, x);
  T (4, y)]
*/
IND_TYPE c, cp_0, c18_p_0, cp_1, c18, f, fp_0, x, xp_0, x24_p_0, x25_p_0, xp_1, x24_p_1, xp_2, x24, x25, y, yp_0, y18_p_0, yp_1, y18;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y19 = 0;
IND_TYPE x26 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c19 = 0;
IND_TYPE f12 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_168 ,mem_vec_169 ,mem_vec_170 ,mem_vec_171 ,mem_vec_172 ,mem_vec_173 ,mem_vec_174 ,mem_vec_175 ,mem_vec_176 ,mem_vec_177 ,mem_vec_178 ,mem_vec_179 ,mem_vec_180 ,mem_vec_181 ,mem_vec_182 ,mem_vec_183 ,mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,mem_vec_192 ,mem_vec_193 ,mem_vec_194 ,mem_vec_195 ,mem_vec_196 ,mem_vec_197 ,mem_vec_198 ,mem_vec_199 ,mem_vec_200 ,mem_vec_201 ,mem_vec_202 ,mem_vec_203 ,mem_vec_204 ,mem_vec_205 ,mem_vec_206 ,mem_vec_207 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 4) (68 / 17)
for (y18 = y19, y18_p_0 = 0;
	y18 < y19 + 68;
	y18 += 17, y18_p_0 += 17){
	// y = 17, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x25 = x26, x25_p_0 = 0;
		x25 < x26 + 68;
		x25 += 68, x25_p_0 += 68){
			for (y = y18, yp_1 = y18_p_0, yp_0 = 0;
				y < y18 + 3;
				y += 3, yp_1 += 3, yp_0 += 3){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x24 = x25, x24_p_1 = x25_p_0, x24_p_0 = 0;
					x24 < x25 + 68;
					x24 += 68, x24_p_1 += 68, x24_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f12, fp_0 = 0;
						f < f12 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c18 = c19, c18_p_0 = 0;
							c18 < c19 + 256;
							c18 += 256, c18_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x24, xp_2 = x24_p_1, xp_1 = x24_p_0, xp_0 = 0;
								x < x24 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
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
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
											c < c18 + 256;
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
							}
						}
					}
				}
			}
			for (y = y18 + 3, yp_1 = y18_p_0, yp_0 = 0;
				y < y18 + 3 + 14;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x24 = x25, x24_p_1 = x25_p_0, x24_p_0 = 0;
					x24 < x25 + 68;
					x24 += 68, x24_p_1 += 68, x24_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f12, fp_0 = 0;
						f < f12 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c18 = c19, c18_p_0 = 0;
							c18 < c19 + 256;
							c18 += 256, c18_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x24, xp_2 = x24_p_1, xp_1 = x24_p_0, xp_0 = 0;
								x < x24 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_180 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_181 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_182 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_183 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c18, cp_1 = c18_p_0, cp_0 = 0;
											c < c18 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_180);
											mem_vec_180 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_181);
											mem_vec_181 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_182);
											mem_vec_182 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_183);
											mem_vec_183 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_184);
											mem_vec_184 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_185);
											mem_vec_185 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_186);
											mem_vec_186 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_187);
											mem_vec_187 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_188);
											mem_vec_188 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_189);
											mem_vec_189 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_190);
											mem_vec_190 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_191);
											mem_vec_191 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_192);
											mem_vec_192 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_193);
											mem_vec_193 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_194);
											mem_vec_194 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_195);
											mem_vec_195 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_196);
											mem_vec_196 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_197);
											mem_vec_197 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_198);
											mem_vec_198 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_199);
											mem_vec_199 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_200);
											mem_vec_200 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_201);
											mem_vec_201 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_202);
											mem_vec_202 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_203);
											mem_vec_203 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_204);
											mem_vec_204 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_205);
											mem_vec_205 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_206);
											mem_vec_206 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_207);
											mem_vec_207 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_180);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_181);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_182);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_183);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_184);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_185);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_186);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_187);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_188);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_189);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_190);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_191);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_192);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_193);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_194);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_195);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_196);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_197);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_198);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_199);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_200);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_201);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_202);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_203);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_204);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_205);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_206);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_207);
							}
						}
					}
				}
			}
	}
}


}