#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (34, x);
  T (3, w); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (16, f);
  T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c53_p_0, cp_1, c53, f, fp_0, w, wp_0, x, xp_0, x50_p_0, xp_1, x50, y, yp_0, y34_p_0, yp_1, y34;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y35 = 0;
IND_TYPE x51 = 0;
IND_TYPE h = 0;
IND_TYPE w18 = 0;
IND_TYPE c54 = 0;
IND_TYPE f55 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_218 ,mem_vec_219 ,mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,mem_vec_236 ,mem_vec_237 ,mem_vec_238 ,mem_vec_239 ,mem_vec_240 ,mem_vec_241 ,mem_vec_242 ,mem_vec_243 ,mem_vec_244 ,mem_vec_245 ,mem_vec_246 ,mem_vec_247 ,mem_vec_248 ,mem_vec_249 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (y, 1) (34 / 34)
for (y34 = y35, y34_p_0 = 0;
	y34 < y35 + 34;
	y34 += 34, y34_p_0 += 34){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 1) (34 / 34)
	for (x50 = x51, x50_p_0 = 0;
		x50 < x51 + 34;
		x50 += 34, x50_p_0 += 34){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (f, 16) (512 / 32)
		for (f = f55, fp_0 = 0;
			f < f55 + 512;
			f += 32, fp_0 += 32){
				for (y = y34, yp_1 = y34_p_0, yp_0 = 0;
					y < y34 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c53 = c54, c53_p_0 = 0;
						c53 < c54 + 256;
						c53 += 32, c53_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w18, wp_0 = 0;
							w < w18 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 32, f = 32
							// T (x, 34) (34 / 1)
							for (x = x50, xp_1 = x50_p_0, xp_0 = 0;
								x < x50 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_218 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_219 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c53, cp_1 = c53_p_0, cp_0 = 0;
											c < c53 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_218);
											mem_vec_218 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_219);
											mem_vec_219 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_220);
											mem_vec_220 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_221);
											mem_vec_221 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_222);
											mem_vec_222 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_223);
											mem_vec_223 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_224);
											mem_vec_224 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_225);
											mem_vec_225 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_226);
											mem_vec_226 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_227);
											mem_vec_227 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_228);
											mem_vec_228 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_229);
											mem_vec_229 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_230);
											mem_vec_230 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_231);
											mem_vec_231 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_218);
											mem_vec_218 = vec_23;

											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_219);
											mem_vec_219 = vec_26;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_220);
											mem_vec_220 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_221);
											mem_vec_221 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_222);
											mem_vec_222 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_223);
											mem_vec_223 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_224);
											mem_vec_224 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_225);
											mem_vec_225 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_226);
											mem_vec_226 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_227);
											mem_vec_227 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_228);
											mem_vec_228 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_229);
											mem_vec_229 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_230);
											mem_vec_230 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_231);
											mem_vec_231 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_218);
											mem_vec_218 = vec_46;

											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_219);
											mem_vec_219 = vec_49;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_220);
											mem_vec_220 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_221);
											mem_vec_221 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_222);
											mem_vec_222 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_223);
											mem_vec_223 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_224);
											mem_vec_224 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_225);
											mem_vec_225 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_226);
											mem_vec_226 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_227);
											mem_vec_227 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_228);
											mem_vec_228 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_229);
											mem_vec_229 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_230);
											mem_vec_230 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_231);
											mem_vec_231 = vec_68;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_218);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_219);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_220);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_221);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_222);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_223);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_224);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_225);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_226);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_227);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_228);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_229);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_230);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_231);
							}
						}
					}
				}
				for (y = y34 + 7, yp_1 = y34_p_0, yp_0 = 0;
					y < y34 + 7 + 27;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c53 = c54, c53_p_0 = 0;
						c53 < c54 + 256;
						c53 += 32, c53_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w18, wp_0 = 0;
							w < w18 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 32, f = 32
							// T (x, 34) (34 / 1)
							for (x = x50, xp_1 = x50_p_0, xp_0 = 0;
								x < x50 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c53, cp_1 = c53_p_0, cp_0 = 0;
											c < c53 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_232);
											mem_vec_232 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_233);
											mem_vec_233 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_234);
											mem_vec_234 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_235);
											mem_vec_235 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_236);
											mem_vec_236 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_237);
											mem_vec_237 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_238);
											mem_vec_238 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_239);
											mem_vec_239 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_240);
											mem_vec_240 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_241);
											mem_vec_241 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_242);
											mem_vec_242 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_243);
											mem_vec_243 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_244);
											mem_vec_244 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_245);
											mem_vec_245 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_246);
											mem_vec_246 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_247);
											mem_vec_247 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_248);
											mem_vec_248 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_249);
											mem_vec_249 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_232);
											mem_vec_232 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_233);
											mem_vec_233 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_234);
											mem_vec_234 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_235);
											mem_vec_235 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_236);
											mem_vec_236 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_237);
											mem_vec_237 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_238);
											mem_vec_238 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_239);
											mem_vec_239 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_240);
											mem_vec_240 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_241);
											mem_vec_241 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_242);
											mem_vec_242 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_243);
											mem_vec_243 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_244);
											mem_vec_244 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_245);
											mem_vec_245 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_246);
											mem_vec_246 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_247);
											mem_vec_247 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_248);
											mem_vec_248 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_249);
											mem_vec_249 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_232);
											mem_vec_232 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_233);
											mem_vec_233 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_234);
											mem_vec_234 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_235);
											mem_vec_235 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_236);
											mem_vec_236 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_237);
											mem_vec_237 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_238);
											mem_vec_238 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_239);
											mem_vec_239 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_240);
											mem_vec_240 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_241);
											mem_vec_241 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_242);
											mem_vec_242 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_243);
											mem_vec_243 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_244);
											mem_vec_244 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_245);
											mem_vec_245 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_246);
											mem_vec_246 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_247);
											mem_vec_247 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_248);
											mem_vec_248 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_249);
											mem_vec_249 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_232);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_233);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_234);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_235);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_236);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_237);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_238);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_239);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_240);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_241);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_242);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_243);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_244);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_249);
							}
						}
					}
				}
		}
	}
}


}