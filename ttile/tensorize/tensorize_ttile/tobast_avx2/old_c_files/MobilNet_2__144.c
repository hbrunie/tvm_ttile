#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (4, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))];
  T (1, f); T (8, c); T (2, f); T (4, c); T (14, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1494_p_0, c1495_p_0, cp_1, c1494_p_1, cp_2, c1494, c1495, f, fp_0, f1420_p_0, f1421_p_0, fp_1, f1420_p_1, fp_2, f1420, f1421, h, hp_0, x, xp_0, x1236_p_0, xp_1, x1236, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y780 = 0;
IND_TYPE x1237 = 0;
IND_TYPE h564 = 0;
IND_TYPE w = 0;
IND_TYPE c1496 = 0;
IND_TYPE f1422 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_14376 ,mem_vec_14377 ,mem_vec_14378 ,mem_vec_14379 ,mem_vec_14380 ,mem_vec_14381 ,mem_vec_14382 ,mem_vec_14383 ,mem_vec_14384 ,mem_vec_14385 ,mem_vec_14386 ,mem_vec_14387 ,mem_vec_14388 ,mem_vec_14389 ,mem_vec_14390 ,mem_vec_14391 ,mem_vec_14392 ,mem_vec_14393 ,mem_vec_14394 ,mem_vec_14395 ,mem_vec_14396 ,mem_vec_14397 ,mem_vec_14398 ,mem_vec_14399 ,mem_vec_14400 ,mem_vec_14401 ,mem_vec_14402 ,mem_vec_14403 ,mem_vec_14404 ,mem_vec_14405 ,mem_vec_14406 ,mem_vec_14407 ,mem_vec_14408 ,mem_vec_14409 ,mem_vec_14410 ,mem_vec_14411 ,mem_vec_14412 ,mem_vec_14413 ,mem_vec_14414 ,mem_vec_14415 ,mem_vec_14416 ,mem_vec_14417 ,mem_vec_14418 ,mem_vec_14419 ,mem_vec_14420 ,mem_vec_14421 ,mem_vec_14422 ,mem_vec_14423 ,mem_vec_14424 ,mem_vec_14425 ,mem_vec_14426 ,mem_vec_14427 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f1421 = f1422, f1421_p_0 = 0;
	f1421 < f1422 + 64;
	f1421 += 64, f1421_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 14) (56 / 4)
	for (x1236 = x1237, x1236_p_0 = 0;
		x1236 < x1237 + 56;
		x1236 += 4, x1236_p_0 += 4){
		// y = 56, x = 4, h = 3, w = 3, c = 64, f = 64
		// T (c, 4) (64 / 16)
		for (c1495 = c1496, c1495_p_0 = 0;
			c1495 < c1496 + 64;
			c1495 += 16, c1495_p_0 += 16){
			// y = 56, x = 4, h = 3, w = 3, c = 16, f = 64
			// T (f, 2) (64 / 32)
			for (f1420 = f1421, f1420_p_1 = f1421_p_0, f1420_p_0 = 0;
				f1420 < f1421 + 64;
				f1420 += 32, f1420_p_1 += 32, f1420_p_0 += 32){
				// y = 56, x = 4, h = 3, w = 3, c = 16, f = 32
				// T (c, 8) (16 / 2)
				for (c1494 = c1495, c1494_p_1 = c1495_p_0, c1494_p_0 = 0;
					c1494 < c1495 + 16;
					c1494 += 2, c1494_p_1 += 2, c1494_p_0 += 2){
					// y = 56, x = 4, h = 3, w = 3, c = 2, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1420, fp_2 = f1420_p_1, fp_1 = f1420_p_0, fp_0 = 0;
						f < f1420 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y780, yp_0 = 0;
								y < y780 + 42;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h564, hp_0 = 0;
									h < h564 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 2, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1236, xp_1 = x1236_p_0, xp_0 = 0;
										x < x1236 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_14376 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_14377 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_14378 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_14379 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_14380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_14381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_14382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_14383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_14384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_14385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_14386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_14387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_14388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_14389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_14390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_14391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_14392 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_14393 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_14394 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_14395 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_14396 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_14397 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_14398 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_14399 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1494, cp_2 = c1494_p_1, cp_1 = c1494_p_0, cp_0 = 0;
													c < c1494 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14376);
													mem_vec_14376 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14377);
													mem_vec_14377 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14378);
													mem_vec_14378 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14379);
													mem_vec_14379 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14380);
													mem_vec_14380 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14381);
													mem_vec_14381 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14382);
													mem_vec_14382 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14383);
													mem_vec_14383 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14384);
													mem_vec_14384 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14385);
													mem_vec_14385 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14386);
													mem_vec_14386 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14387);
													mem_vec_14387 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14388);
													mem_vec_14388 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14389);
													mem_vec_14389 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14390);
													mem_vec_14390 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14391);
													mem_vec_14391 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14392);
													mem_vec_14392 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14393);
													mem_vec_14393 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14394);
													mem_vec_14394 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14395);
													mem_vec_14395 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_14396);
													mem_vec_14396 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_14397);
													mem_vec_14397 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_14398);
													mem_vec_14398 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_14399);
													mem_vec_14399 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_14376);
													mem_vec_14376 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_14377);
													mem_vec_14377 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_14378);
													mem_vec_14378 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_14379);
													mem_vec_14379 = vec_41;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_14380);
													mem_vec_14380 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_14381);
													mem_vec_14381 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_14382);
													mem_vec_14382 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_14383);
													mem_vec_14383 = vec_47;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_14384);
													mem_vec_14384 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_14385);
													mem_vec_14385 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_14386);
													mem_vec_14386 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_14387);
													mem_vec_14387 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_14388);
													mem_vec_14388 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_14389);
													mem_vec_14389 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_14390);
													mem_vec_14390 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_14391);
													mem_vec_14391 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_14392);
													mem_vec_14392 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_14393);
													mem_vec_14393 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_14394);
													mem_vec_14394 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_14395);
													mem_vec_14395 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_14396);
													mem_vec_14396 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_14397);
													mem_vec_14397 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_14398);
													mem_vec_14398 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_14399);
													mem_vec_14399 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_14376);
													mem_vec_14376 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_14377);
													mem_vec_14377 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_14378);
													mem_vec_14378 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_14379);
													mem_vec_14379 = vec_75;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_14380);
													mem_vec_14380 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_14381);
													mem_vec_14381 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_14382);
													mem_vec_14382 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_14383);
													mem_vec_14383 = vec_81;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_14384);
													mem_vec_14384 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_14385);
													mem_vec_14385 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_14386);
													mem_vec_14386 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_14387);
													mem_vec_14387 = vec_86;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_14388);
													mem_vec_14388 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_14389);
													mem_vec_14389 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_14390);
													mem_vec_14390 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_14391);
													mem_vec_14391 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_14392);
													mem_vec_14392 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_14393);
													mem_vec_14393 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_14394);
													mem_vec_14394 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_14395);
													mem_vec_14395 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_14396);
													mem_vec_14396 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_14397);
													mem_vec_14397 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_14398);
													mem_vec_14398 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_14399);
													mem_vec_14399 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14376);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14377);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14378);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14379);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14380);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14381);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14382);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14383);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14384);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14385);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14386);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14387);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14388);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14389);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14390);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14391);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14392);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14393);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14394);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14395);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14396);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_14397);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14398);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_14399);
									}
								}
							}
							for (y = y780 + 42, yp_0 = 0;
								y < y780 + 42 + 14;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h564, hp_0 = 0;
									h < h564 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 2, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1236, xp_1 = x1236_p_0, xp_0 = 0;
										x < x1236 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_14400 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_14401 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_14402 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_14403 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_14404 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_14405 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_14406 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_14407 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_14408 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_14409 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_14410 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_14411 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_14412 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_14413 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_14414 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_14415 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_14416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_14417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_14418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_14419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_14420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_14421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_14422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_14423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_14424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_14425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_14426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_14427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1494, cp_2 = c1494_p_1, cp_1 = c1494_p_0, cp_0 = 0;
													c < c1494 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14400);
													mem_vec_14400 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14401);
													mem_vec_14401 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14402);
													mem_vec_14402 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14403);
													mem_vec_14403 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14404);
													mem_vec_14404 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14405);
													mem_vec_14405 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14406);
													mem_vec_14406 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14407);
													mem_vec_14407 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14408);
													mem_vec_14408 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14409);
													mem_vec_14409 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14410);
													mem_vec_14410 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14411);
													mem_vec_14411 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14412);
													mem_vec_14412 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14413);
													mem_vec_14413 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14414);
													mem_vec_14414 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14415);
													mem_vec_14415 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14416);
													mem_vec_14416 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14417);
													mem_vec_14417 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14418);
													mem_vec_14418 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14419);
													mem_vec_14419 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_14420);
													mem_vec_14420 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_14421);
													mem_vec_14421 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_14422);
													mem_vec_14422 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_14423);
													mem_vec_14423 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_14424);
													mem_vec_14424 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_14425);
													mem_vec_14425 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_14426);
													mem_vec_14426 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_14427);
													mem_vec_14427 = vec_38;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_14400);
													mem_vec_14400 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_14401);
													mem_vec_14401 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_14402);
													mem_vec_14402 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_14403);
													mem_vec_14403 = vec_46;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_14404);
													mem_vec_14404 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_14405);
													mem_vec_14405 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_14406);
													mem_vec_14406 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_14407);
													mem_vec_14407 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_14408);
													mem_vec_14408 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_14409);
													mem_vec_14409 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_14410);
													mem_vec_14410 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_14411);
													mem_vec_14411 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_14412);
													mem_vec_14412 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_14413);
													mem_vec_14413 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_14414);
													mem_vec_14414 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_14415);
													mem_vec_14415 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_14416);
													mem_vec_14416 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_14417);
													mem_vec_14417 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_14418);
													mem_vec_14418 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_14419);
													mem_vec_14419 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_14420);
													mem_vec_14420 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_14421);
													mem_vec_14421 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_14422);
													mem_vec_14422 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_14423);
													mem_vec_14423 = vec_72;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_14424);
													mem_vec_14424 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_14425);
													mem_vec_14425 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_14426);
													mem_vec_14426 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_14427);
													mem_vec_14427 = vec_77;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_14400);
													mem_vec_14400 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_14401);
													mem_vec_14401 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_14402);
													mem_vec_14402 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_14403);
													mem_vec_14403 = vec_85;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_14404);
													mem_vec_14404 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_14405);
													mem_vec_14405 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_14406);
													mem_vec_14406 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_14407);
													mem_vec_14407 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_14408);
													mem_vec_14408 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_14409);
													mem_vec_14409 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_14410);
													mem_vec_14410 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_14411);
													mem_vec_14411 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_14412);
													mem_vec_14412 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_14413);
													mem_vec_14413 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_14414);
													mem_vec_14414 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_14415);
													mem_vec_14415 = vec_101;
													scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_14416);
													mem_vec_14416 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_14417);
													mem_vec_14417 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_14418);
													mem_vec_14418 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_14419);
													mem_vec_14419 = vec_106;
													scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_14420);
													mem_vec_14420 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_14421);
													mem_vec_14421 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_14422);
													mem_vec_14422 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_14423);
													mem_vec_14423 = vec_111;
													scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_14424);
													mem_vec_14424 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_14425);
													mem_vec_14425 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_14426);
													mem_vec_14426 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_14427);
													mem_vec_14427 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14400);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14401);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14402);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14403);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14404);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14405);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14406);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14407);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14408);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14409);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14410);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14411);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14412);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14413);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14414);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14415);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14416);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14417);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14418);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14419);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14420);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_14421);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14422);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_14423);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14424);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_14425);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14426);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_14427);
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