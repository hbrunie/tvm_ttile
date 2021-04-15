#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (2, f); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f);
  T (32, c); T (1, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1194_p_0, cp_1, c1194, f, fp_0, f1196_p_0, f1197_p_0, fp_1, f1196_p_1, fp_2, f1196, f1197, h, hp_0, x, xp_0, x1484_p_0, x1485_p_0, xp_1, x1484_p_1, xp_2, x1484, x1485, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y724 = 0;
IND_TYPE x1486 = 0;
IND_TYPE h514 = 0;
IND_TYPE w = 0;
IND_TYPE c1195 = 0;
IND_TYPE f1198 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10472 ,mem_vec_10473 ,mem_vec_10474 ,mem_vec_10475 ,mem_vec_10476 ,mem_vec_10477 ,mem_vec_10478 ,mem_vec_10479 ,mem_vec_10480 ,mem_vec_10481 ,mem_vec_10482 ,mem_vec_10483 ,mem_vec_10484 ,mem_vec_10485 ,mem_vec_10486 ,mem_vec_10487 ,mem_vec_10488 ,mem_vec_10489 ,mem_vec_10490 ,mem_vec_10491 ,mem_vec_10492 ,mem_vec_10493 ,mem_vec_10494 ,mem_vec_10495 ,mem_vec_10496 ,mem_vec_10497 ,mem_vec_10498 ,mem_vec_10499 ,mem_vec_10500 ,mem_vec_10501 ,mem_vec_10502 ,mem_vec_10503 ,mem_vec_10504 ,mem_vec_10505 ,mem_vec_10506 ,mem_vec_10507 ,mem_vec_10508 ,mem_vec_10509 ,mem_vec_10510 ,mem_vec_10511 ,mem_vec_10512 ,mem_vec_10513 ,mem_vec_10514 ,mem_vec_10515 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f1197 = f1198, f1197_p_0 = 0;
	f1197 < f1198 + 128;
	f1197 += 64, f1197_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (x, 1) (28 / 28)
	for (x1485 = x1486, x1485_p_0 = 0;
		x1485 < x1486 + 28;
		x1485 += 28, x1485_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (c, 32) (128 / 4)
		for (c1194 = c1195, c1194_p_0 = 0;
			c1194 < c1195 + 128;
			c1194 += 4, c1194_p_0 += 4){
			// y = 28, x = 28, h = 3, w = 3, c = 4, f = 64
			// T (f, 1) (64 / 64)
			for (f1196 = f1197, f1196_p_1 = f1197_p_0, f1196_p_0 = 0;
				f1196 < f1197 + 64;
				f1196 += 64, f1196_p_1 += 64, f1196_p_0 += 64){
					for (y = y724, yp_0 = 0;
						y < y724 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 28, h = 3, w = 3, c = 4, f = 64
						// T (x, 4) (28 / 7)
						for (x1484 = x1485, x1484_p_1 = x1485_p_0, x1484_p_0 = 0;
							x1484 < x1485 + 28;
							x1484 += 7, x1484_p_1 += 7, x1484_p_0 += 7){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1196, fp_2 = f1196_p_1, fp_1 = f1196_p_0, fp_0 = 0;
								f < f1196 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h514, hp_0 = 0;
									h < h514 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 32
									// T (x, 7) (7 / 1)
									for (x = x1484, xp_2 = x1484_p_1, xp_1 = x1484_p_0, xp_0 = 0;
										x < x1484 + 7;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10472 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10473 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10474 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10475 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10488 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10489 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10490 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10491 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
													c < c1194 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10472);
													mem_vec_10472 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10473);
													mem_vec_10473 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10474);
													mem_vec_10474 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10475);
													mem_vec_10475 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10476);
													mem_vec_10476 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10477);
													mem_vec_10477 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10478);
													mem_vec_10478 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10479);
													mem_vec_10479 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10480);
													mem_vec_10480 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10481);
													mem_vec_10481 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10482);
													mem_vec_10482 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10483);
													mem_vec_10483 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10484);
													mem_vec_10484 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10485);
													mem_vec_10485 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10486);
													mem_vec_10486 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10487);
													mem_vec_10487 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10488);
													mem_vec_10488 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10489);
													mem_vec_10489 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10490);
													mem_vec_10490 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10491);
													mem_vec_10491 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_10472);
													mem_vec_10472 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_10473);
													mem_vec_10473 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_10474);
													mem_vec_10474 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_10475);
													mem_vec_10475 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_10476);
													mem_vec_10476 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_10477);
													mem_vec_10477 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_10478);
													mem_vec_10478 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_10479);
													mem_vec_10479 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_10480);
													mem_vec_10480 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_10481);
													mem_vec_10481 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_10482);
													mem_vec_10482 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10483);
													mem_vec_10483 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_10484);
													mem_vec_10484 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_10485);
													mem_vec_10485 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_10486);
													mem_vec_10486 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_10487);
													mem_vec_10487 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_10488);
													mem_vec_10488 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_10489);
													mem_vec_10489 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_10490);
													mem_vec_10490 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_10491);
													mem_vec_10491 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_10472);
													mem_vec_10472 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_10473);
													mem_vec_10473 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_10474);
													mem_vec_10474 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_10475);
													mem_vec_10475 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_10476);
													mem_vec_10476 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_10477);
													mem_vec_10477 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_10478);
													mem_vec_10478 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_10479);
													mem_vec_10479 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_10480);
													mem_vec_10480 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_10481);
													mem_vec_10481 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_10482);
													mem_vec_10482 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_10483);
													mem_vec_10483 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_10484);
													mem_vec_10484 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_10485);
													mem_vec_10485 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_10486);
													mem_vec_10486 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_10487);
													mem_vec_10487 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_10488);
													mem_vec_10488 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_10489);
													mem_vec_10489 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_10490);
													mem_vec_10490 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_10491);
													mem_vec_10491 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10472);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10473);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10474);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10475);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10476);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10477);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10478);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10479);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10480);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10481);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10482);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10483);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10484);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10485);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10486);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10487);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10488);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10489);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10490);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10491);
									}
								}
							}
						}
					}
					for (y = y724 + 10, yp_0 = 0;
						y < y724 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 28, h = 3, w = 3, c = 4, f = 64
						// T (x, 4) (28 / 7)
						for (x1484 = x1485, x1484_p_1 = x1485_p_0, x1484_p_0 = 0;
							x1484 < x1485 + 28;
							x1484 += 7, x1484_p_1 += 7, x1484_p_0 += 7){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1196, fp_2 = f1196_p_1, fp_1 = f1196_p_0, fp_0 = 0;
								f < f1196 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h514, hp_0 = 0;
									h < h514 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 32
									// T (x, 7) (7 / 1)
									for (x = x1484, xp_2 = x1484_p_1, xp_1 = x1484_p_0, xp_0 = 0;
										x < x1484 + 7;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10492 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10493 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10494 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10495 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_10512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_10514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;
													c < c1194 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10492);
													mem_vec_10492 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10493);
													mem_vec_10493 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10494);
													mem_vec_10494 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10495);
													mem_vec_10495 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10496);
													mem_vec_10496 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10497);
													mem_vec_10497 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10498);
													mem_vec_10498 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10499);
													mem_vec_10499 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10500);
													mem_vec_10500 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10501);
													mem_vec_10501 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10502);
													mem_vec_10502 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10503);
													mem_vec_10503 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10504);
													mem_vec_10504 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10505);
													mem_vec_10505 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10506);
													mem_vec_10506 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10507);
													mem_vec_10507 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10508);
													mem_vec_10508 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10509);
													mem_vec_10509 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10510);
													mem_vec_10510 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10511);
													mem_vec_10511 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10512);
													mem_vec_10512 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10513);
													mem_vec_10513 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10514);
													mem_vec_10514 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10515);
													mem_vec_10515 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_10492);
													mem_vec_10492 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_10493);
													mem_vec_10493 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_10494);
													mem_vec_10494 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_10495);
													mem_vec_10495 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_10496);
													mem_vec_10496 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_10497);
													mem_vec_10497 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_10498);
													mem_vec_10498 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_10499);
													mem_vec_10499 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_10500);
													mem_vec_10500 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_10501);
													mem_vec_10501 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_10502);
													mem_vec_10502 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_10503);
													mem_vec_10503 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_10504);
													mem_vec_10504 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_10505);
													mem_vec_10505 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_10506);
													mem_vec_10506 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_10507);
													mem_vec_10507 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_10508);
													mem_vec_10508 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_10509);
													mem_vec_10509 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_10510);
													mem_vec_10510 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_10511);
													mem_vec_10511 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_10512);
													mem_vec_10512 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_10513);
													mem_vec_10513 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_10514);
													mem_vec_10514 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_10515);
													mem_vec_10515 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_10492);
													mem_vec_10492 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_10493);
													mem_vec_10493 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_10494);
													mem_vec_10494 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_10495);
													mem_vec_10495 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_10496);
													mem_vec_10496 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_10497);
													mem_vec_10497 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_10498);
													mem_vec_10498 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_10499);
													mem_vec_10499 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_10500);
													mem_vec_10500 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_10501);
													mem_vec_10501 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_10502);
													mem_vec_10502 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_10503);
													mem_vec_10503 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_10504);
													mem_vec_10504 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10505);
													mem_vec_10505 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10506);
													mem_vec_10506 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_10507);
													mem_vec_10507 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_10508);
													mem_vec_10508 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_10509);
													mem_vec_10509 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_10510);
													mem_vec_10510 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_10511);
													mem_vec_10511 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_10512);
													mem_vec_10512 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_10513);
													mem_vec_10513 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_10514);
													mem_vec_10514 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_10515);
													mem_vec_10515 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10492);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10493);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10494);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10495);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10496);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10497);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10498);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10499);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10500);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10501);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10502);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10503);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10504);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10505);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10506);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10507);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10508);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10509);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10510);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10511);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10512);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10513);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10514);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10515);
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