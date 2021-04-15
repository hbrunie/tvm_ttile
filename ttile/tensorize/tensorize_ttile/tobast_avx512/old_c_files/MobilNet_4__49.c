#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); U (3, h); T (1, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (4, f); T (128, c); T (2, x); T (4, y); T (1, f)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, f, fp_0, f66_p_0, fp_1, f66, w, wp_0, x, xp_0, x66_p_0, xp_1, x66, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y44 = 0;
IND_TYPE x67 = 0;
IND_TYPE h = 0;
IND_TYPE w44 = 0;
IND_TYPE c67 = 0;
IND_TYPE f67 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_320 ,mem_vec_321 ,mem_vec_322 ,mem_vec_323 ,mem_vec_324 ,mem_vec_325 ,mem_vec_326 ,mem_vec_327 ,mem_vec_328 ,mem_vec_329 ,mem_vec_330 ,mem_vec_331 ,mem_vec_332 ,mem_vec_333 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f66 = f67, f66_p_0 = 0;
	f66 < f67 + 128;
	f66 += 128, f66_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 4) (28 / 7)
	for (y = y44, yp_0 = 0;
		y < y44 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 2) (28 / 14)
		for (x66 = x67, x66_p_0 = 0;
			x66 < x67 + 28;
			x66 += 14, x66_p_0 += 14){
			// y = 7, x = 14, h = 3, w = 3, c = 128, f = 128
			// T (c, 128) (128 / 1)
			for (c66 = c67, c66_p_0 = 0;
				c66 < c67 + 128;
				c66 += 1, c66_p_0 += 1){
				// y = 7, x = 14, h = 3, w = 3, c = 1, f = 128
				// T (f, 4) (128 / 32)
				for (f = f66, fp_1 = f66_p_0, fp_0 = 0;
					f < f66 + 128;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 7, x = 14, h = 3, w = 3, c = 1, f = 32
					// T (w, 3) (3 / 1)
					for (w = w44, wp_0 = 0;
						w < w44 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 14, h = 3, w = 1, c = 1, f = 32
						// T (x, 14) (14 / 1)
						for (x = x66, xp_1 = x66_p_0, xp_0 = 0;
							x < x66 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_320 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_321 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = 7, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
										c < c66 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_320);
										mem_vec_320 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_321);
										mem_vec_321 = vec_3;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_322);
										mem_vec_322 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_323);
										mem_vec_323 = vec_7;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_324);
										mem_vec_324 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_325);
										mem_vec_325 = vec_10;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_326);
										mem_vec_326 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_327);
										mem_vec_327 = vec_13;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_328);
										mem_vec_328 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_329);
										mem_vec_329 = vec_16;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_330);
										mem_vec_330 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_331);
										mem_vec_331 = vec_19;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_332);
										mem_vec_332 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_333);
										mem_vec_333 = vec_22;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_7);
										vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_320);
										mem_vec_320 = vec_23;

										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_321);
										mem_vec_321 = vec_26;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_8);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_322);
										mem_vec_322 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_323);
										mem_vec_323 = vec_30;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_32 = _mm512_set1_ps(scal_9);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_324);
										mem_vec_324 = vec_31;



										vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_325);
										mem_vec_325 = vec_33;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_35 = _mm512_set1_ps(scal_10);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_326);
										mem_vec_326 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_327);
										mem_vec_327 = vec_36;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_38 = _mm512_set1_ps(scal_11);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_328);
										mem_vec_328 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_329);
										mem_vec_329 = vec_39;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_41 = _mm512_set1_ps(scal_12);


										vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_330);
										mem_vec_330 = vec_40;



										vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_331);
										mem_vec_331 = vec_42;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
										vec_44 = _mm512_set1_ps(scal_13);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_332);
										mem_vec_332 = vec_43;



										vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_333);
										mem_vec_333 = vec_45;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_47 = _mm512_set1_ps(scal_14);
										vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_320);
										mem_vec_320 = vec_46;

										vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_321);
										mem_vec_321 = vec_49;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_52 = _mm512_set1_ps(scal_15);


										vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_322);
										mem_vec_322 = vec_51;



										vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_323);
										mem_vec_323 = vec_53;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_55 = _mm512_set1_ps(scal_16);


										vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_324);
										mem_vec_324 = vec_54;



										vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_325);
										mem_vec_325 = vec_56;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_58 = _mm512_set1_ps(scal_17);


										vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_326);
										mem_vec_326 = vec_57;



										vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_327);
										mem_vec_327 = vec_59;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_61 = _mm512_set1_ps(scal_18);


										vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_328);
										mem_vec_328 = vec_60;



										vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_329);
										mem_vec_329 = vec_62;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_64 = _mm512_set1_ps(scal_19);


										vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_330);
										mem_vec_330 = vec_63;



										vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_331);
										mem_vec_331 = vec_65;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
										vec_67 = _mm512_set1_ps(scal_20);


										vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_332);
										mem_vec_332 = vec_66;



										vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_333);
										mem_vec_333 = vec_68;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_320);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_321);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_322);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_323);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_324);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_325);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_326);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_327);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_328);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_329);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_330);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_331);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_332);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_333);
						}
					}
				}
			}
		}
	}
}


}