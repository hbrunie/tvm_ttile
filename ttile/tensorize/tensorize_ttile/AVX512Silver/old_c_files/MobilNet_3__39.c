#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (16, c); Hoist_vars [c]; T (56, x);
  T (3, w); T (8, c); T (2, f); T (1, x); T (1, y); T (14, y)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, w, wp_0, x, xp_0, x44_p_0, xp_1, x44, y, yp_0, y27_p_0, yp_1, y27;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y28 = 0;
IND_TYPE x45 = 0;
IND_TYPE h = 0;
IND_TYPE w22 = 0;
IND_TYPE c37 = 0;
IND_TYPE f24 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_252 ,mem_vec_253 ,mem_vec_254 ,mem_vec_255 ,mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (y, 14) (56 / 4)
for (y27 = y28, y27_p_0 = 0;
	y27 < y28 + 56;
	y27 += 4, y27_p_0 += 4){
	// y = 4, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (y, 1) (4 / 4)
	for (y = y27, yp_1 = y27_p_0, yp_0 = 0;
		y < y27 + 4;
		y += 4, yp_1 += 4, yp_0 += 4){
		// y = 4, x = 56, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (56 / 56)
		for (x44 = x45, x44_p_0 = 0;
			x44 < x45 + 56;
			x44 += 56, x44_p_0 += 56){
			// y = 4, x = 56, h = 3, w = 3, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f = f24, fp_0 = 0;
				f < f24 + 128;
				f += 64, fp_0 += 64){
				// y = 4, x = 56, h = 3, w = 3, c = 128, f = 64
				// T (c, 8) (128 / 16)
				for (c36 = c37, c36_p_0 = 0;
					c36 < c37 + 128;
					c36 += 16, c36_p_0 += 16){
					// y = 4, x = 56, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w22, wp_0 = 0;
						w < w22 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 56, h = 3, w = 1, c = 16, f = 64
						// T (x, 56) (56 / 1)
						for (x = x44, xp_1 = x44_p_0, xp_0 = 0;
							x < x44 + 56;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_254 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_255 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
										c < c36 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_252);
										mem_vec_252 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_253);
										mem_vec_253 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_254);
										mem_vec_254 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_255);
										mem_vec_255 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_256);
										mem_vec_256 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_257);
										mem_vec_257 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_258);
										mem_vec_258 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_259);
										mem_vec_259 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_260);
										mem_vec_260 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_261);
										mem_vec_261 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_262);
										mem_vec_262 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_263);
										mem_vec_263 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_264);
										mem_vec_264 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_265);
										mem_vec_265 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_266);
										mem_vec_266 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_267);
										mem_vec_267 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_252);
										mem_vec_252 = vec_24;

										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_253);
										mem_vec_253 = vec_27;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_254);
										mem_vec_254 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_255);
										mem_vec_255 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_256);
										mem_vec_256 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_257);
										mem_vec_257 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_258);
										mem_vec_258 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_259);
										mem_vec_259 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_260);
										mem_vec_260 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_261);
										mem_vec_261 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_262);
										mem_vec_262 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_263);
										mem_vec_263 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_264);
										mem_vec_264 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_265);
										mem_vec_265 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_266);
										mem_vec_266 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_267);
										mem_vec_267 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_252);
										mem_vec_252 = vec_48;

										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_253);
										mem_vec_253 = vec_51;

										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_254);
										mem_vec_254 = vec_53;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_255);
										mem_vec_255 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_9);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_256);
										mem_vec_256 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_257);
										mem_vec_257 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_258);
										mem_vec_258 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_259);
										mem_vec_259 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_63 = _mm512_set1_ps(scal_10);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_260);
										mem_vec_260 = vec_62;



										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_261);
										mem_vec_261 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_262);
										mem_vec_262 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_263);
										mem_vec_263 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_264);
										mem_vec_264 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_265);
										mem_vec_265 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_266);
										mem_vec_266 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_267);
										mem_vec_267 = vec_71;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_267);
						}
					}
				}
			}
		}
	}
}


}