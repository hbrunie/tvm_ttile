#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (4, c); T (4, x); T (2, y); T (34, y); T (17, x)]
*/
IND_TYPE c, cp_0, c363_p_0, cp_1, c363, h, hp_0, x, xp_0, x439_p_0, x440_p_0, xp_1, x439_p_1, xp_2, x439, x440, y, yp_0, y404_p_0, yp_1, y404;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y405 = 0;
IND_TYPE x441 = 0;
IND_TYPE h201 = 0;
IND_TYPE w = 0;
IND_TYPE c364 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3177 ,mem_vec_3178 ,mem_vec_3179 ,mem_vec_3180 ,mem_vec_3181 ,mem_vec_3182 ,mem_vec_3183 ,mem_vec_3184 ,mem_vec_3185 ,mem_vec_3186 ,mem_vec_3187 ,mem_vec_3188 ,mem_vec_3189 ,mem_vec_3190 ,mem_vec_3191 ,mem_vec_3192 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 17) (272 / 16)
for (x440 = x441, x440_p_0 = 0;
	x440 < x441 + 272;
	x440 += 16, x440_p_0 += 16){
	// y = 272, x = 16, h = 3, w = 3, c = 32, f = 64
	// T (y, 34) (272 / 8)
	for (y404 = y405, y404_p_0 = 0;
		y404 < y405 + 272;
		y404 += 8, y404_p_0 += 8){
		// y = 8, x = 16, h = 3, w = 3, c = 32, f = 64
		// T (y, 2) (8 / 4)
		for (y = y404, yp_1 = y404_p_0, yp_0 = 0;
			y < y404 + 8;
			y += 4, yp_1 += 4, yp_0 += 4){
			// y = 4, x = 16, h = 3, w = 3, c = 32, f = 64
			// T (x, 4) (16 / 4)
			for (x439 = x440, x439_p_1 = x440_p_0, x439_p_0 = 0;
				x439 < x440 + 16;
				x439 += 4, x439_p_1 += 4, x439_p_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 32, f = 64
				// T (c, 4) (32 / 8)
				for (c363 = c364, c363_p_0 = 0;
					c363 < c364 + 32;
					c363 += 8, c363_p_0 += 8){
					// y = 4, x = 4, h = 3, w = 3, c = 8, f = 64
					// T (h, 3) (3 / 1)
					for (h = h201, hp_0 = 0;
						h < h201 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 4, h = 1, w = 3, c = 8, f = 64
						// T (x, 4) (4 / 1)
						for (x = x439, xp_2 = x439_p_1, xp_1 = x439_p_0, xp_0 = 0;
							x < x439 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_3177 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3178 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3179 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3180 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_3185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_3188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_3189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_3192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 1, w = 3, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c363, cp_1 = c363_p_0, cp_0 = 0;
										c < c363 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3177);
										mem_vec_3177 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3178);
										mem_vec_3178 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3179);
										mem_vec_3179 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3180);
										mem_vec_3180 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3181);
										mem_vec_3181 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3182);
										mem_vec_3182 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3183);
										mem_vec_3183 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3184);
										mem_vec_3184 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3185);
										mem_vec_3185 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3186);
										mem_vec_3186 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3187);
										mem_vec_3187 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3188);
										mem_vec_3188 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3189);
										mem_vec_3189 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3190);
										mem_vec_3190 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3191);
										mem_vec_3191 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3192);
										mem_vec_3192 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_3177);
										mem_vec_3177 = vec_24;

										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_3178);
										mem_vec_3178 = vec_27;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_3179);
										mem_vec_3179 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_3180);
										mem_vec_3180 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_3181);
										mem_vec_3181 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_3182);
										mem_vec_3182 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_3183);
										mem_vec_3183 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_3184);
										mem_vec_3184 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_3185);
										mem_vec_3185 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_3186);
										mem_vec_3186 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_3187);
										mem_vec_3187 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_3188);
										mem_vec_3188 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_3189);
										mem_vec_3189 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_3190);
										mem_vec_3190 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_3191);
										mem_vec_3191 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_3192);
										mem_vec_3192 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_3177);
										mem_vec_3177 = vec_48;

										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_3178);
										mem_vec_3178 = vec_51;

										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_3179);
										mem_vec_3179 = vec_53;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_3180);
										mem_vec_3180 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_9);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_3181);
										mem_vec_3181 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_3182);
										mem_vec_3182 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_3183);
										mem_vec_3183 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_3184);
										mem_vec_3184 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_63 = _mm512_set1_ps(scal_10);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_3185);
										mem_vec_3185 = vec_62;



										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_3186);
										mem_vec_3186 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_3187);
										mem_vec_3187 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_3188);
										mem_vec_3188 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_3189);
										mem_vec_3189 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_3190);
										mem_vec_3190 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_3191);
										mem_vec_3191 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_3192);
										mem_vec_3192 = vec_71;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3179);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3180);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3181);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3182);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3183);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3184);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3185);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3186);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3187);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3188);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3189);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3190);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3191);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3192);
						}
					}
				}
			}
		}
	}
}


}