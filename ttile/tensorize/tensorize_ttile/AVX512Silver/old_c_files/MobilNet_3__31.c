#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (16, c); Hoist_vars [c]; T (56, x);
  T (3, w); T (8, c); T (2, f); T (1, x); T (7, y); T (2, y)]
*/
IND_TYPE c, cp_0, c30_p_0, cp_1, c30, f, fp_0, w, wp_0, x, xp_0, x38_p_0, xp_1, x38, y, yp_0, y21_p_0, yp_1, y21;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y22 = 0;
IND_TYPE x39 = 0;
IND_TYPE h = 0;
IND_TYPE w18 = 0;
IND_TYPE c31 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_220 ,mem_vec_221 ,mem_vec_222 ,mem_vec_223 ,mem_vec_224 ,mem_vec_225 ,mem_vec_226 ,mem_vec_227 ,mem_vec_228 ,mem_vec_229 ,mem_vec_230 ,mem_vec_231 ,mem_vec_232 ,mem_vec_233 ,mem_vec_234 ,mem_vec_235 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (y, 2) (56 / 28)
for (y21 = y22, y21_p_0 = 0;
	y21 < y22 + 56;
	y21 += 28, y21_p_0 += 28){
	// y = 28, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (y, 7) (28 / 4)
	for (y = y21, yp_1 = y21_p_0, yp_0 = 0;
		y < y21 + 28;
		y += 4, yp_1 += 4, yp_0 += 4){
		// y = 4, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (56 / 56)
		for (x38 = x39, x38_p_0 = 0;
			x38 < x39 + 56;
			x38 += 56, x38_p_0 += 56){
			// y = 4, x = 56, h = 3, w = 3, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f = f20, fp_0 = 0;
				f < f20 + 128;
				f += 64, fp_0 += 64){
				// y = 4, x = 56, h = 3, w = 3, c = 128, f = 64
				// T (c, 8) (128 / 16)
				for (c30 = c31, c30_p_0 = 0;
					c30 < c31 + 128;
					c30 += 16, c30_p_0 += 16){
					// y = 4, x = 56, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w18, wp_0 = 0;
						w < w18 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 56, h = 3, w = 1, c = 16, f = 64
						// T (x, 56) (56 / 1)
						for (x = x38, xp_1 = x38_p_0, xp_0 = 0;
							x < x38 + 56;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_220 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_221 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_222 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_223 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c30, cp_1 = c30_p_0, cp_0 = 0;
										c < c30 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_220);
										mem_vec_220 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_221);
										mem_vec_221 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_222);
										mem_vec_222 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_223);
										mem_vec_223 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_224);
										mem_vec_224 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_225);
										mem_vec_225 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_226);
										mem_vec_226 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_227);
										mem_vec_227 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_228);
										mem_vec_228 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_229);
										mem_vec_229 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_230);
										mem_vec_230 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_231);
										mem_vec_231 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_232);
										mem_vec_232 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_233);
										mem_vec_233 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_234);
										mem_vec_234 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_235);
										mem_vec_235 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_220);
										mem_vec_220 = vec_24;

										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_221);
										mem_vec_221 = vec_27;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_222);
										mem_vec_222 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_223);
										mem_vec_223 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_224);
										mem_vec_224 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_225);
										mem_vec_225 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_226);
										mem_vec_226 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_227);
										mem_vec_227 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_228);
										mem_vec_228 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_229);
										mem_vec_229 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_230);
										mem_vec_230 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_231);
										mem_vec_231 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_232);
										mem_vec_232 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_233);
										mem_vec_233 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_234);
										mem_vec_234 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_235);
										mem_vec_235 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_220);
										mem_vec_220 = vec_48;

										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_221);
										mem_vec_221 = vec_51;

										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_222);
										mem_vec_222 = vec_53;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_223);
										mem_vec_223 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_9);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_224);
										mem_vec_224 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_225);
										mem_vec_225 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_226);
										mem_vec_226 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_227);
										mem_vec_227 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_63 = _mm512_set1_ps(scal_10);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_228);
										mem_vec_228 = vec_62;



										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_229);
										mem_vec_229 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_230);
										mem_vec_230 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_231);
										mem_vec_231 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_232);
										mem_vec_232 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_233);
										mem_vec_233 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_234);
										mem_vec_234 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_235);
										mem_vec_235 = vec_71;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_220);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_221);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_222);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_223);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_224);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_225);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_226);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_227);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_228);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_229);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_230);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_231);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_232);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_233);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_234);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_235);
						}
					}
				}
			}
		}
	}
}


}