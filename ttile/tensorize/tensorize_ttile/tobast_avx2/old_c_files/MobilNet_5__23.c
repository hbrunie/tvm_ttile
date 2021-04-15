#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (128, c); T (7, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1236_p_0, cp_1, c1236, f, fp_0, f1388_p_0, f1389_p_0, fp_1, f1388_p_1, fp_2, f1388, f1389, h, hp_0, x, xp_0, x1544_p_0, x1545_p_0, xp_1, x1544_p_1, xp_2, x1544, x1545, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y772 = 0;
IND_TYPE x1546 = 0;
IND_TYPE h556 = 0;
IND_TYPE w = 0;
IND_TYPE c1237 = 0;
IND_TYPE f1390 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11364 ,mem_vec_11365 ,mem_vec_11366 ,mem_vec_11367 ,mem_vec_11368 ,mem_vec_11369 ,mem_vec_11370 ,mem_vec_11371 ,mem_vec_11372 ,mem_vec_11373 ,mem_vec_11374 ,mem_vec_11375 ,mem_vec_11376 ,mem_vec_11377 ,mem_vec_11378 ,mem_vec_11379 ,mem_vec_11380 ,mem_vec_11381 ,mem_vec_11382 ,mem_vec_11383 ,mem_vec_11384 ,mem_vec_11385 ,mem_vec_11386 ,mem_vec_11387 ,mem_vec_11388 ,mem_vec_11389 ,mem_vec_11390 ,mem_vec_11391 ,mem_vec_11392 ,mem_vec_11393 ,mem_vec_11394 ,mem_vec_11395 ,mem_vec_11396 ,mem_vec_11397 ,mem_vec_11398 ,mem_vec_11399 ,mem_vec_11400 ,mem_vec_11401 ,mem_vec_11402 ,mem_vec_11403 ,mem_vec_11404 ,mem_vec_11405 ,mem_vec_11406 ,mem_vec_11407 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f1389 = f1390, f1389_p_0 = 0;
	f1389 < f1390 + 256;
	f1389 += 128, f1389_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
	// T (x, 7) (28 / 4)
	for (x1545 = x1546, x1545_p_0 = 0;
		x1545 < x1546 + 28;
		x1545 += 4, x1545_p_0 += 4){
		// y = 28, x = 4, h = 3, w = 3, c = 256, f = 128
		// T (c, 128) (256 / 2)
		for (c1236 = c1237, c1236_p_0 = 0;
			c1236 < c1237 + 256;
			c1236 += 2, c1236_p_0 += 2){
			// y = 28, x = 4, h = 3, w = 3, c = 2, f = 128
			// T (f, 4) (128 / 32)
			for (f1388 = f1389, f1388_p_1 = f1389_p_0, f1388_p_0 = 0;
				f1388 < f1389 + 128;
				f1388 += 32, f1388_p_1 += 32, f1388_p_0 += 32){
					for (y = y772, yp_0 = 0;
						y < y772 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
						// T (x, 1) (4 / 4)
						for (x1544 = x1545, x1544_p_1 = x1545_p_0, x1544_p_0 = 0;
							x1544 < x1545 + 4;
							x1544 += 4, x1544_p_1 += 4, x1544_p_0 += 4){
							// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1388, fp_2 = f1388_p_1, fp_1 = f1388_p_0, fp_0 = 0;
								f < f1388 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h556, hp_0 = 0;
									h < h556 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 2, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1544, xp_2 = x1544_p_1, xp_1 = x1544_p_0, xp_0 = 0;
										x < x1544 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11364 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11365 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11366 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11367 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1236, cp_1 = c1236_p_0, cp_0 = 0;
													c < c1236 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11364);
													mem_vec_11364 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11365);
													mem_vec_11365 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11366);
													mem_vec_11366 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11367);
													mem_vec_11367 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11368);
													mem_vec_11368 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11369);
													mem_vec_11369 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11370);
													mem_vec_11370 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11371);
													mem_vec_11371 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11372);
													mem_vec_11372 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11373);
													mem_vec_11373 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11374);
													mem_vec_11374 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11375);
													mem_vec_11375 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11376);
													mem_vec_11376 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11377);
													mem_vec_11377 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11378);
													mem_vec_11378 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11379);
													mem_vec_11379 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11380);
													mem_vec_11380 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11381);
													mem_vec_11381 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11382);
													mem_vec_11382 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11383);
													mem_vec_11383 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11364);
													mem_vec_11364 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11365);
													mem_vec_11365 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11366);
													mem_vec_11366 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11367);
													mem_vec_11367 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11368);
													mem_vec_11368 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11369);
													mem_vec_11369 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11370);
													mem_vec_11370 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11371);
													mem_vec_11371 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11372);
													mem_vec_11372 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11373);
													mem_vec_11373 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11374);
													mem_vec_11374 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11375);
													mem_vec_11375 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11376);
													mem_vec_11376 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11377);
													mem_vec_11377 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11378);
													mem_vec_11378 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11379);
													mem_vec_11379 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11380);
													mem_vec_11380 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11381);
													mem_vec_11381 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11382);
													mem_vec_11382 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11383);
													mem_vec_11383 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11364);
													mem_vec_11364 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11365);
													mem_vec_11365 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11366);
													mem_vec_11366 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11367);
													mem_vec_11367 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11368);
													mem_vec_11368 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11369);
													mem_vec_11369 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11370);
													mem_vec_11370 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11371);
													mem_vec_11371 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11372);
													mem_vec_11372 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11373);
													mem_vec_11373 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11374);
													mem_vec_11374 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11375);
													mem_vec_11375 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11376);
													mem_vec_11376 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11377);
													mem_vec_11377 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11378);
													mem_vec_11378 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11379);
													mem_vec_11379 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11380);
													mem_vec_11380 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11381);
													mem_vec_11381 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11382);
													mem_vec_11382 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11383);
													mem_vec_11383 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11364);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11365);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11366);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11367);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11368);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11369);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11370);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11371);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11372);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11373);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11374);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11375);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11376);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11377);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11378);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11379);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11380);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11381);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11382);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11383);
									}
								}
							}
						}
					}
					for (y = y772 + 10, yp_0 = 0;
						y < y772 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
						// T (x, 1) (4 / 4)
						for (x1544 = x1545, x1544_p_1 = x1545_p_0, x1544_p_0 = 0;
							x1544 < x1545 + 4;
							x1544 += 4, x1544_p_1 += 4, x1544_p_0 += 4){
							// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1388, fp_2 = f1388_p_1, fp_1 = f1388_p_0, fp_0 = 0;
								f < f1388 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h556, hp_0 = 0;
									h < h556 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 2, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1544, xp_2 = x1544_p_1, xp_1 = x1544_p_0, xp_0 = 0;
										x < x1544 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11384 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11385 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11386 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11387 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11396 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11397 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11398 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11399 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11400 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11401 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11402 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11403 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_11404 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11405 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11406 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11407 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1236, cp_1 = c1236_p_0, cp_0 = 0;
													c < c1236 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11384);
													mem_vec_11384 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11385);
													mem_vec_11385 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11386);
													mem_vec_11386 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11387);
													mem_vec_11387 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11388);
													mem_vec_11388 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11389);
													mem_vec_11389 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11390);
													mem_vec_11390 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11391);
													mem_vec_11391 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11392);
													mem_vec_11392 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11393);
													mem_vec_11393 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11394);
													mem_vec_11394 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11395);
													mem_vec_11395 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11396);
													mem_vec_11396 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11397);
													mem_vec_11397 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11398);
													mem_vec_11398 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11399);
													mem_vec_11399 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11400);
													mem_vec_11400 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11401);
													mem_vec_11401 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11402);
													mem_vec_11402 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11403);
													mem_vec_11403 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11404);
													mem_vec_11404 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11405);
													mem_vec_11405 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11406);
													mem_vec_11406 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11407);
													mem_vec_11407 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_11384);
													mem_vec_11384 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_11385);
													mem_vec_11385 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_11386);
													mem_vec_11386 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_11387);
													mem_vec_11387 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_11388);
													mem_vec_11388 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_11389);
													mem_vec_11389 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_11390);
													mem_vec_11390 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_11391);
													mem_vec_11391 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_11392);
													mem_vec_11392 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_11393);
													mem_vec_11393 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_11394);
													mem_vec_11394 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_11395);
													mem_vec_11395 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_11396);
													mem_vec_11396 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_11397);
													mem_vec_11397 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_11398);
													mem_vec_11398 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_11399);
													mem_vec_11399 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_11400);
													mem_vec_11400 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_11401);
													mem_vec_11401 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_11402);
													mem_vec_11402 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_11403);
													mem_vec_11403 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_11404);
													mem_vec_11404 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_11405);
													mem_vec_11405 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_11406);
													mem_vec_11406 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_11407);
													mem_vec_11407 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_11384);
													mem_vec_11384 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_11385);
													mem_vec_11385 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_11386);
													mem_vec_11386 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_11387);
													mem_vec_11387 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_11388);
													mem_vec_11388 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_11389);
													mem_vec_11389 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_11390);
													mem_vec_11390 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_11391);
													mem_vec_11391 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_11392);
													mem_vec_11392 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_11393);
													mem_vec_11393 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_11394);
													mem_vec_11394 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_11395);
													mem_vec_11395 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_11396);
													mem_vec_11396 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_11397);
													mem_vec_11397 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_11398);
													mem_vec_11398 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_11399);
													mem_vec_11399 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_11400);
													mem_vec_11400 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_11401);
													mem_vec_11401 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_11402);
													mem_vec_11402 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_11403);
													mem_vec_11403 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_11404);
													mem_vec_11404 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_11405);
													mem_vec_11405 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_11406);
													mem_vec_11406 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_11407);
													mem_vec_11407 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11384);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11385);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11386);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11387);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11388);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11389);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11390);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11391);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11392);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11393);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11394);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11395);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11396);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11397);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11398);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11399);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11400);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11401);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11402);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11403);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11404);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11405);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11406);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11407);
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