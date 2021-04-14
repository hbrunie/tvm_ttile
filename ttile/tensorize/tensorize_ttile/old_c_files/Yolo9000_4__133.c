#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (136, x);
  T (3, h); T (1, x); T (34, y); T (2, f); T (8, c); T (1, x)]
*/
IND_TYPE c, cp_0, c72_p_0, cp_1, c72, f, fp_0, h, hp_0, x, xp_0, x96_p_0, x97_p_0, xp_1, x96_p_1, xp_2, x96, x97, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y48 = 0;
IND_TYPE x98 = 0;
IND_TYPE h48 = 0;
IND_TYPE w = 0;
IND_TYPE c73 = 0;
IND_TYPE f48 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,mem_vec_396 ,mem_vec_397 ,mem_vec_398 ,mem_vec_399 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x97 = x98, x97_p_0 = 0;
	x97 < x98 + 136;
	x97 += 136, x97_p_0 += 136){
	// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
	// T (c, 8) (64 / 8)
	for (c72 = c73, c72_p_0 = 0;
		c72 < c73 + 64;
		c72 += 8, c72_p_0 += 8){
		// y = 136, x = 136, h = 3, w = 3, c = 8, f = 128
		// T (f, 2) (128 / 64)
		for (f = f48, fp_0 = 0;
			f < f48 + 128;
			f += 64, fp_0 += 64){
			// y = 136, x = 136, h = 3, w = 3, c = 8, f = 64
			// T (y, 34) (136 / 4)
			for (y = y48, yp_0 = 0;
				y < y48 + 136;
				y += 4, yp_0 += 4){
				// y = 4, x = 136, h = 3, w = 3, c = 8, f = 64
				// T (x, 1) (136 / 136)
				for (x96 = x97, x96_p_1 = x97_p_0, x96_p_0 = 0;
					x96 < x97 + 136;
					x96 += 136, x96_p_1 += 136, x96_p_0 += 136){
					// y = 4, x = 136, h = 3, w = 3, c = 8, f = 64
					// T (h, 3) (3 / 1)
					for (h = h48, hp_0 = 0;
						h < h48 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 136, h = 1, w = 3, c = 8, f = 64
						// T (x, 136) (136 / 1)
						for (x = x96, xp_2 = x96_p_1, xp_1 = x96_p_0, xp_0 = 0;
							x < x96 + 136;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_384 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_385 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_386 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_387 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = 4, x = 1, h = 1, w = 3, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
										c < c72 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_384);
										mem_vec_384 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_385);
										mem_vec_385 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_386);
										mem_vec_386 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_387);
										mem_vec_387 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_388);
										mem_vec_388 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_389);
										mem_vec_389 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_390);
										mem_vec_390 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_391);
										mem_vec_391 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_392);
										mem_vec_392 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_393);
										mem_vec_393 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_394);
										mem_vec_394 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_395);
										mem_vec_395 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_396);
										mem_vec_396 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_397);
										mem_vec_397 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_398);
										mem_vec_398 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_399);
										mem_vec_399 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_384);
										mem_vec_384 = vec_24;

										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_385);
										mem_vec_385 = vec_27;

										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_386);
										mem_vec_386 = vec_29;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_387);
										mem_vec_387 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_388);
										mem_vec_388 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_389);
										mem_vec_389 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_390);
										mem_vec_390 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_391);
										mem_vec_391 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_39 = _mm512_set1_ps(scal_6);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_392);
										mem_vec_392 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_393);
										mem_vec_393 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_394);
										mem_vec_394 = vec_41;



										vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_395);
										mem_vec_395 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_44 = _mm512_set1_ps(scal_7);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_396);
										mem_vec_396 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_397);
										mem_vec_397 = vec_45;



										vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_398);
										mem_vec_398 = vec_46;



										vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_399);
										mem_vec_399 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_49 = _mm512_set1_ps(scal_8);
										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_384);
										mem_vec_384 = vec_48;

										vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_385);
										mem_vec_385 = vec_51;

										vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_386);
										mem_vec_386 = vec_53;

										vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_387);
										mem_vec_387 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm512_set1_ps(scal_9);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_388);
										mem_vec_388 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_389);
										mem_vec_389 = vec_59;



										vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_390);
										mem_vec_390 = vec_60;



										vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_391);
										mem_vec_391 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_63 = _mm512_set1_ps(scal_10);


										vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_392);
										mem_vec_392 = vec_62;



										vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_393);
										mem_vec_393 = vec_64;



										vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_394);
										mem_vec_394 = vec_65;



										vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_395);
										mem_vec_395 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_68 = _mm512_set1_ps(scal_11);


										vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_396);
										mem_vec_396 = vec_67;



										vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_397);
										mem_vec_397 = vec_69;



										vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_398);
										mem_vec_398 = vec_70;



										vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_399);
										mem_vec_399 = vec_71;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_384);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_385);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_391);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_392);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_393);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_394);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_395);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_396);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_397);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_398);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_399);
						}
					}
				}
			}
		}
	}
}


}