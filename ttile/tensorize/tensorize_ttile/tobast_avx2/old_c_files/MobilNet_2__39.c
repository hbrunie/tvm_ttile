#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, w); Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))];
  T (1, f); T (4, c); T (2, f); T (8, c); T (56, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1014_p_0, c1015_p_0, cp_1, c1014_p_1, cp_2, c1014, c1015, f, fp_0, f940_p_0, f941_p_0, fp_1, f940_p_1, fp_2, f940, f941, w, wp_0, x, xp_0, x876_p_0, xp_1, x876, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y540 = 0;
IND_TYPE x877 = 0;
IND_TYPE h = 0;
IND_TYPE w462 = 0;
IND_TYPE c1016 = 0;
IND_TYPE f942 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8480 ,mem_vec_8481 ,mem_vec_8482 ,mem_vec_8483 ,mem_vec_8484 ,mem_vec_8485 ,mem_vec_8486 ,mem_vec_8487 ,mem_vec_8488 ,mem_vec_8489 ,mem_vec_8490 ,mem_vec_8491 ,mem_vec_8492 ,mem_vec_8493 ,mem_vec_8494 ,mem_vec_8495 ,mem_vec_8496 ,mem_vec_8497 ,mem_vec_8498 ,mem_vec_8499 ,mem_vec_8500 ,mem_vec_8501 ,mem_vec_8502 ,mem_vec_8503 ,mem_vec_8504 ,mem_vec_8505 ,mem_vec_8506 ,mem_vec_8507 ,mem_vec_8508 ,mem_vec_8509 ,mem_vec_8510 ,mem_vec_8511 ,mem_vec_8512 ,mem_vec_8513 ,mem_vec_8514 ,mem_vec_8515 ,mem_vec_8516 ,mem_vec_8517 ,mem_vec_8518 ,mem_vec_8519 ,mem_vec_8520 ,mem_vec_8521 ,mem_vec_8522 ,mem_vec_8523 ,mem_vec_8524 ,mem_vec_8525 ,mem_vec_8526 ,mem_vec_8527 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f941 = f942, f941_p_0 = 0;
	f941 < f942 + 64;
	f941 += 64, f941_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x876 = x877, x876_p_0 = 0;
		x876 < x877 + 56;
		x876 += 1, x876_p_0 += 1){
		// y = 56, x = 1, h = 3, w = 3, c = 64, f = 64
		// T (c, 8) (64 / 8)
		for (c1015 = c1016, c1015_p_0 = 0;
			c1015 < c1016 + 64;
			c1015 += 8, c1015_p_0 += 8){
			// y = 56, x = 1, h = 3, w = 3, c = 8, f = 64
			// T (f, 2) (64 / 32)
			for (f940 = f941, f940_p_1 = f941_p_0, f940_p_0 = 0;
				f940 < f941 + 64;
				f940 += 32, f940_p_1 += 32, f940_p_0 += 32){
				// y = 56, x = 1, h = 3, w = 3, c = 8, f = 32
				// T (c, 4) (8 / 2)
				for (c1014 = c1015, c1014_p_1 = c1015_p_0, c1014_p_0 = 0;
					c1014 < c1015 + 8;
					c1014 += 2, c1014_p_1 += 2, c1014_p_0 += 2){
					// y = 56, x = 1, h = 3, w = 3, c = 2, f = 32
					// T (f, 1) (32 / 32)
					for (f = f940, fp_2 = f940_p_1, fp_1 = f940_p_0, fp_0 = 0;
						f < f940 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y540, yp_0 = 0;
								y < y540 + 35;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w462, wp_0 = 0;
									w < w462 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x876, xp_1 = x876_p_0, xp_0 = 0;
										x < x876 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8480 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8481 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8482 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8483 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8488 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8489 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8490 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8491 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1014, cp_2 = c1014_p_1, cp_1 = c1014_p_0, cp_0 = 0;
													c < c1014 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8480);
													mem_vec_8480 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8481);
													mem_vec_8481 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8482);
													mem_vec_8482 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8483);
													mem_vec_8483 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8484);
													mem_vec_8484 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8485);
													mem_vec_8485 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8486);
													mem_vec_8486 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8487);
													mem_vec_8487 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8488);
													mem_vec_8488 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8489);
													mem_vec_8489 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8490);
													mem_vec_8490 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8491);
													mem_vec_8491 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8492);
													mem_vec_8492 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8493);
													mem_vec_8493 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8494);
													mem_vec_8494 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8495);
													mem_vec_8495 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8496);
													mem_vec_8496 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8497);
													mem_vec_8497 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8498);
													mem_vec_8498 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8499);
													mem_vec_8499 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_8480);
													mem_vec_8480 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_8481);
													mem_vec_8481 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_8482);
													mem_vec_8482 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_8483);
													mem_vec_8483 = vec_36;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_8484);
													mem_vec_8484 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_8485);
													mem_vec_8485 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_8486);
													mem_vec_8486 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_8487);
													mem_vec_8487 = vec_42;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_8488);
													mem_vec_8488 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_8489);
													mem_vec_8489 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_8490);
													mem_vec_8490 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_8491);
													mem_vec_8491 = vec_47;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_8492);
													mem_vec_8492 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_8493);
													mem_vec_8493 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_8494);
													mem_vec_8494 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_8495);
													mem_vec_8495 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_8496);
													mem_vec_8496 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_8497);
													mem_vec_8497 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_8498);
													mem_vec_8498 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_8499);
													mem_vec_8499 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_8480);
													mem_vec_8480 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_8481);
													mem_vec_8481 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_8482);
													mem_vec_8482 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_8483);
													mem_vec_8483 = vec_65;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_8484);
													mem_vec_8484 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_8485);
													mem_vec_8485 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_8486);
													mem_vec_8486 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_8487);
													mem_vec_8487 = vec_71;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_8488);
													mem_vec_8488 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_8489);
													mem_vec_8489 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_8490);
													mem_vec_8490 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8491);
													mem_vec_8491 = vec_76;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_8492);
													mem_vec_8492 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_8493);
													mem_vec_8493 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_8494);
													mem_vec_8494 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_8495);
													mem_vec_8495 = vec_81;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_8496);
													mem_vec_8496 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_8497);
													mem_vec_8497 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_8498);
													mem_vec_8498 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_8499);
													mem_vec_8499 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8480);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8481);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8482);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8483);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8484);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8485);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8486);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8487);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8488);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8489);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8490);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8491);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8492);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8493);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8494);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8495);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8496);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8497);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8498);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8499);
									}
								}
							}
							for (y = y540 + 35, yp_0 = 0;
								y < y540 + 35 + 21;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w462, wp_0 = 0;
									w < w462 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x876, xp_1 = x876_p_0, xp_0 = 0;
										x < x876 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8500 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8501 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8502 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8503 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_8520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_8522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_8524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_8526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_8527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1014, cp_2 = c1014_p_1, cp_1 = c1014_p_0, cp_0 = 0;
													c < c1014 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8500);
													mem_vec_8500 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8501);
													mem_vec_8501 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8502);
													mem_vec_8502 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8503);
													mem_vec_8503 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8504);
													mem_vec_8504 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8505);
													mem_vec_8505 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8506);
													mem_vec_8506 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8507);
													mem_vec_8507 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8508);
													mem_vec_8508 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8509);
													mem_vec_8509 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8510);
													mem_vec_8510 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8511);
													mem_vec_8511 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8512);
													mem_vec_8512 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8513);
													mem_vec_8513 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8514);
													mem_vec_8514 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8515);
													mem_vec_8515 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8516);
													mem_vec_8516 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8517);
													mem_vec_8517 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8518);
													mem_vec_8518 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8519);
													mem_vec_8519 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8520);
													mem_vec_8520 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8521);
													mem_vec_8521 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_8522);
													mem_vec_8522 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_8523);
													mem_vec_8523 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_8524);
													mem_vec_8524 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_8525);
													mem_vec_8525 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_8526);
													mem_vec_8526 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_8527);
													mem_vec_8527 = vec_38;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_8500);
													mem_vec_8500 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_8501);
													mem_vec_8501 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_8502);
													mem_vec_8502 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_8503);
													mem_vec_8503 = vec_46;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_8504);
													mem_vec_8504 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_8505);
													mem_vec_8505 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_8506);
													mem_vec_8506 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_8507);
													mem_vec_8507 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_8508);
													mem_vec_8508 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_8509);
													mem_vec_8509 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_8510);
													mem_vec_8510 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_8511);
													mem_vec_8511 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_8512);
													mem_vec_8512 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_8513);
													mem_vec_8513 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_8514);
													mem_vec_8514 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_8515);
													mem_vec_8515 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_8516);
													mem_vec_8516 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_8517);
													mem_vec_8517 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_8518);
													mem_vec_8518 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_8519);
													mem_vec_8519 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_8520);
													mem_vec_8520 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_8521);
													mem_vec_8521 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_8522);
													mem_vec_8522 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_8523);
													mem_vec_8523 = vec_72;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_8524);
													mem_vec_8524 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_8525);
													mem_vec_8525 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_8526);
													mem_vec_8526 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_8527);
													mem_vec_8527 = vec_77;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_8500);
													mem_vec_8500 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_8501);
													mem_vec_8501 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_8502);
													mem_vec_8502 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_8503);
													mem_vec_8503 = vec_85;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_8504);
													mem_vec_8504 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_8505);
													mem_vec_8505 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_8506);
													mem_vec_8506 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_8507);
													mem_vec_8507 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_8508);
													mem_vec_8508 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_8509);
													mem_vec_8509 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_8510);
													mem_vec_8510 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_8511);
													mem_vec_8511 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_8512);
													mem_vec_8512 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_8513);
													mem_vec_8513 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_8514);
													mem_vec_8514 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_8515);
													mem_vec_8515 = vec_101;
													scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_8516);
													mem_vec_8516 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_8517);
													mem_vec_8517 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_8518);
													mem_vec_8518 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_8519);
													mem_vec_8519 = vec_106;
													scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_8520);
													mem_vec_8520 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_8521);
													mem_vec_8521 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_8522);
													mem_vec_8522 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_8523);
													mem_vec_8523 = vec_111;
													scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_8524);
													mem_vec_8524 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_8525);
													mem_vec_8525 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_8526);
													mem_vec_8526 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_8527);
													mem_vec_8527 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8500);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8501);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8502);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8503);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8504);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8505);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8506);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8507);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8508);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8509);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8510);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8511);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8512);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8513);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8514);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8515);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8516);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8517);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8518);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8519);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8520);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8521);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8522);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_8523);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8524);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8525);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8526);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_8527);
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