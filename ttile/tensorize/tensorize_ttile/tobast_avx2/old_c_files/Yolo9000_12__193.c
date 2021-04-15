#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (2, c); T (2, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (1, c);
  T (32, f); T (1, x); T (2, c)]
*/
IND_TYPE c, cp_0, c50_p_0, c51_p_0, c52_p_0, cp_1, c50_p_1, c51_p_1, cp_2, c50_p_2, cp_3, c50, c51, c52, f, fp_0, w, wp_0, x, xp_0, x40_p_0, x41_p_0, xp_1, x40_p_1, xp_2, x40, x41, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y20 = 0;
IND_TYPE x42 = 0;
IND_TYPE h = 0;
IND_TYPE w20 = 0;
IND_TYPE c53 = 0;
IND_TYPE f20 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_360 ,mem_vec_361 ,mem_vec_362 ,mem_vec_363 ,mem_vec_364 ,mem_vec_365 ,mem_vec_366 ,mem_vec_367 ,mem_vec_368 ,mem_vec_369 ,mem_vec_370 ,mem_vec_371 ,mem_vec_372 ,mem_vec_373 ,mem_vec_374 ,mem_vec_375 ,mem_vec_376 ,mem_vec_377 ,mem_vec_378 ,mem_vec_379 ,mem_vec_380 ,mem_vec_381 ,mem_vec_382 ,mem_vec_383 ,mem_vec_384 ,mem_vec_385 ,mem_vec_386 ,mem_vec_387 ,mem_vec_388 ,mem_vec_389 ,mem_vec_390 ,mem_vec_391 ,mem_vec_392 ,mem_vec_393 ,mem_vec_394 ,mem_vec_395 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 2) (256 / 128)
for (c52 = c53, c52_p_0 = 0;
	c52 < c53 + 256;
	c52 += 128, c52_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 128, f = 512
	// T (x, 1) (34 / 34)
	for (x41 = x42, x41_p_0 = 0;
		x41 < x42 + 34;
		x41 += 34, x41_p_0 += 34){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 512
		// T (f, 32) (512 / 16)
		for (f = f20, fp_0 = 0;
			f < f20 + 512;
			f += 16, fp_0 += 16){
			// y = 34, x = 34, h = 3, w = 3, c = 128, f = 16
			// T (c, 1) (128 / 128)
			for (c51 = c52, c51_p_1 = c52_p_0, c51_p_0 = 0;
				c51 < c52 + 128;
				c51 += 128, c51_p_1 += 128, c51_p_0 += 128){
					for (y = y20, yp_0 = 0;
						y < y20 + 24;
						y += 8, yp_0 += 8){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
						// T (x, 2) (34 / 17)
						for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
							x40 < x41 + 34;
							x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 16
							// T (c, 2) (128 / 64)
							for (c50 = c51, c50_p_2 = c51_p_1, c50_p_1 = c51_p_0, c50_p_0 = 0;
								c50 < c51 + 128;
								c50 += 64, c50_p_2 += 64, c50_p_1 += 64, c50_p_0 += 64){
								// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
								// T (w, 3) (3 / 1)
								for (w = w20, wp_0 = 0;
									w < w20 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 3, w = 1, c = 64, f = 16
									// T (x, 17) (17 / 1)
									for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
										x < x40 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_360 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_361 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
												// T (c, 64) (64 / 1)
												for (c = c50, cp_3 = c50_p_2, cp_2 = c50_p_1, cp_1 = c50_p_0, cp_0 = 0;
													c < c50 + 64;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_360);
													mem_vec_360 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_361);
													mem_vec_361 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_362);
													mem_vec_362 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_363);
													mem_vec_363 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_364);
													mem_vec_364 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_365);
													mem_vec_365 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_366);
													mem_vec_366 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_367);
													mem_vec_367 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_368);
													mem_vec_368 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_369);
													mem_vec_369 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_370);
													mem_vec_370 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_371);
													mem_vec_371 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_372);
													mem_vec_372 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_373);
													mem_vec_373 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_374);
													mem_vec_374 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_375);
													mem_vec_375 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_27 = _mm256_set1_ps(scal_8);
													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_360);
													mem_vec_360 = vec_26;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_361);
													mem_vec_361 = vec_29;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_32 = _mm256_set1_ps(scal_9);


													vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_362);
													mem_vec_362 = vec_31;



													vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_363);
													mem_vec_363 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_10);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_364);
													mem_vec_364 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_365);
													mem_vec_365 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_366);
													mem_vec_366 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_367);
													mem_vec_367 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_368);
													mem_vec_368 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_369);
													mem_vec_369 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_370);
													mem_vec_370 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_371);
													mem_vec_371 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_372);
													mem_vec_372 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_373);
													mem_vec_373 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_374);
													mem_vec_374 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_375);
													mem_vec_375 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_53 = _mm256_set1_ps(scal_16);
													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_360);
													mem_vec_360 = vec_52;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_361);
													mem_vec_361 = vec_55;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_17);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_362);
													mem_vec_362 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_363);
													mem_vec_363 = vec_59;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_61 = _mm256_set1_ps(scal_18);


													vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_364);
													mem_vec_364 = vec_60;



													vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_365);
													mem_vec_365 = vec_62;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_64 = _mm256_set1_ps(scal_19);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_366);
													mem_vec_366 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_367);
													mem_vec_367 = vec_65;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_67 = _mm256_set1_ps(scal_20);


													vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_368);
													mem_vec_368 = vec_66;



													vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_369);
													mem_vec_369 = vec_68;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_370);
													mem_vec_370 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_371);
													mem_vec_371 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_372);
													mem_vec_372 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_373);
													mem_vec_373 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_374);
													mem_vec_374 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_375);
													mem_vec_375 = vec_77;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_360);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_361);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_362);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_363);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_364);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_365);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_366);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_367);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_368);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_369);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_370);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_371);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_372);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_373);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_374);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_375);
									}
								}
							}
						}
					}
					for (y = y20 + 24, yp_0 = 0;
						y < y20 + 24 + 10;
						y += 10, yp_0 += 10){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
						// T (x, 2) (34 / 17)
						for (x40 = x41, x40_p_1 = x41_p_0, x40_p_0 = 0;
							x40 < x41 + 34;
							x40 += 17, x40_p_1 += 17, x40_p_0 += 17){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 16
							// T (c, 2) (128 / 64)
							for (c50 = c51, c50_p_2 = c51_p_1, c50_p_1 = c51_p_0, c50_p_0 = 0;
								c50 < c51 + 128;
								c50 += 64, c50_p_2 += 64, c50_p_1 += 64, c50_p_0 += 64){
								// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
								// T (w, 3) (3 / 1)
								for (w = w20, wp_0 = 0;
									w < w20 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 3, w = 1, c = 64, f = 16
									// T (x, 17) (17 / 1)
									for (x = x40, xp_2 = x40_p_1, xp_1 = x40_p_0, xp_0 = 0;
										x < x40 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_376 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_377 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 16
												// T (c, 64) (64 / 1)
												for (c = c50, cp_3 = c50_p_2, cp_2 = c50_p_1, cp_1 = c50_p_0, cp_0 = 0;
													c < c50 + 64;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_376);
													mem_vec_376 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_377);
													mem_vec_377 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_378);
													mem_vec_378 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_379);
													mem_vec_379 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_380);
													mem_vec_380 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_381);
													mem_vec_381 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_382);
													mem_vec_382 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_383);
													mem_vec_383 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_384);
													mem_vec_384 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_385);
													mem_vec_385 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_386);
													mem_vec_386 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_387);
													mem_vec_387 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_388);
													mem_vec_388 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_389);
													mem_vec_389 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_390);
													mem_vec_390 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_391);
													mem_vec_391 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_392);
													mem_vec_392 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_393);
													mem_vec_393 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_394);
													mem_vec_394 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_395);
													mem_vec_395 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_33 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_376);
													mem_vec_376 = vec_32;

													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_377);
													mem_vec_377 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_378);
													mem_vec_378 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_379);
													mem_vec_379 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_380);
													mem_vec_380 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_381);
													mem_vec_381 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_382);
													mem_vec_382 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_383);
													mem_vec_383 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_384);
													mem_vec_384 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_385);
													mem_vec_385 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_386);
													mem_vec_386 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_387);
													mem_vec_387 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_388);
													mem_vec_388 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_389);
													mem_vec_389 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_390);
													mem_vec_390 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_391);
													mem_vec_391 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_392);
													mem_vec_392 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_393);
													mem_vec_393 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_394);
													mem_vec_394 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_395);
													mem_vec_395 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_65 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_376);
													mem_vec_376 = vec_64;

													vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_377);
													mem_vec_377 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_378);
													mem_vec_378 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_379);
													mem_vec_379 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_380);
													mem_vec_380 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_381);
													mem_vec_381 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_382);
													mem_vec_382 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_383);
													mem_vec_383 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_384);
													mem_vec_384 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_385);
													mem_vec_385 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_386);
													mem_vec_386 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_387);
													mem_vec_387 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_388);
													mem_vec_388 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_389);
													mem_vec_389 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_390);
													mem_vec_390 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_391);
													mem_vec_391 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_392);
													mem_vec_392 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_393);
													mem_vec_393 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_394);
													mem_vec_394 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_395);
													mem_vec_395 = vec_95;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_376);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_377);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_378);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_379);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_380);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_381);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_382);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_383);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_384);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_385);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_386);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_387);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_388);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_389);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_390);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_391);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_392);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_393);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_394);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_395);
									}
								}
							}
						}
					}
			}
		}
	}
}


}