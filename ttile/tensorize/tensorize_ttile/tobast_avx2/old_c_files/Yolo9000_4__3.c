#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (2, c);
  Lambda_apply y [((Iter 11), (Arg 10)); ((Iter 2), (Arg 13))]; T (34, x);
  T (1, y); T (8, f); T (4, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1264_p_0, c1265_p_0, cp_1, c1264_p_1, cp_2, c1264, c1265, f, fp_0, w, wp_0, x, xp_0, x1290_p_0, x1291_p_0, xp_1, x1290_p_1, xp_2, x1290, x1291, y, yp_0, y952_p_0, yp_1, y952;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y953 = 0;
IND_TYPE x1292 = 0;
IND_TYPE h = 0;
IND_TYPE w636 = 0;
IND_TYPE c1266 = 0;
IND_TYPE f692 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11556 ,mem_vec_11557 ,mem_vec_11558 ,mem_vec_11559 ,mem_vec_11560 ,mem_vec_11561 ,mem_vec_11562 ,mem_vec_11563 ,mem_vec_11564 ,mem_vec_11565 ,mem_vec_11566 ,mem_vec_11567 ,mem_vec_11568 ,mem_vec_11569 ,mem_vec_11570 ,mem_vec_11571 ,mem_vec_11572 ,mem_vec_11573 ,mem_vec_11574 ,mem_vec_11575 ,mem_vec_11576 ,mem_vec_11577 ,mem_vec_11578 ,mem_vec_11579 ,mem_vec_11580 ,mem_vec_11581 ,mem_vec_11582 ,mem_vec_11583 ,mem_vec_11584 ,mem_vec_11585 ,mem_vec_11586 ,mem_vec_11587 ,mem_vec_11588 ,mem_vec_11589 ,mem_vec_11590 ,mem_vec_11591 ,mem_vec_11592 ,mem_vec_11593 ,mem_vec_11594 ,mem_vec_11595 ,mem_vec_11596 ,mem_vec_11597 ,mem_vec_11598 ,mem_vec_11599 ,mem_vec_11600 ,mem_vec_11601 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (136 / 68)
for (x1291 = x1292, x1291_p_0 = 0;
	x1291 < x1292 + 136;
	x1291 += 68, x1291_p_0 += 68){
	// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
	// T (c, 4) (64 / 16)
	for (c1265 = c1266, c1265_p_0 = 0;
		c1265 < c1266 + 64;
		c1265 += 16, c1265_p_0 += 16){
		// y = 136, x = 68, h = 3, w = 3, c = 16, f = 128
		// T (f, 8) (128 / 16)
		for (f = f692, fp_0 = 0;
			f < f692 + 128;
			f += 16, fp_0 += 16){
			// y = 136, x = 68, h = 3, w = 3, c = 16, f = 16
			// T (y, 1) (136 / 136)
			for (y952 = y953, y952_p_0 = 0;
				y952 < y953 + 136;
				y952 += 136, y952_p_0 += 136){
				// y = 136, x = 68, h = 3, w = 3, c = 16, f = 16
				// T (x, 34) (68 / 2)
				for (x1290 = x1291, x1290_p_1 = x1291_p_0, x1290_p_0 = 0;
					x1290 < x1291 + 68;
					x1290 += 2, x1290_p_1 += 2, x1290_p_0 += 2){
						for (y = y952, yp_1 = y952_p_0, yp_0 = 0;
							y < y952 + 110;
							y += 10, yp_1 += 10, yp_0 += 10){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 16
							// T (c, 2) (16 / 8)
							for (c1264 = c1265, c1264_p_1 = c1265_p_0, c1264_p_0 = 0;
								c1264 < c1265 + 16;
								c1264 += 8, c1264_p_1 += 8, c1264_p_0 += 8){
								// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 16
								// T (w, 3) (3 / 1)
								for (w = w636, wp_0 = 0;
									w < w636 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 16
									// T (x, 2) (2 / 1)
									for (x = x1290, xp_2 = x1290_p_1, xp_1 = x1290_p_0, xp_0 = 0;
										x < x1290 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11556 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11557 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11568 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11569 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_11570 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_11571 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_11572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_11573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_11574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_11575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
												// T (c, 8) (8 / 1)
												for (c = c1264, cp_2 = c1264_p_1, cp_1 = c1264_p_0, cp_0 = 0;
													c < c1264 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11556);
													mem_vec_11556 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11557);
													mem_vec_11557 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_11558);
													mem_vec_11558 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_11559);
													mem_vec_11559 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_11560);
													mem_vec_11560 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_11561);
													mem_vec_11561 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_11562);
													mem_vec_11562 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_11563);
													mem_vec_11563 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11564);
													mem_vec_11564 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11565);
													mem_vec_11565 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_11566);
													mem_vec_11566 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_11567);
													mem_vec_11567 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_11568);
													mem_vec_11568 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_11569);
													mem_vec_11569 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_11570);
													mem_vec_11570 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_11571);
													mem_vec_11571 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_11572);
													mem_vec_11572 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_11573);
													mem_vec_11573 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11574);
													mem_vec_11574 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11575);
													mem_vec_11575 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_33 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_11556);
													mem_vec_11556 = vec_32;

													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_11557);
													mem_vec_11557 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_11558);
													mem_vec_11558 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_11559);
													mem_vec_11559 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_11560);
													mem_vec_11560 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_11561);
													mem_vec_11561 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_11562);
													mem_vec_11562 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_11563);
													mem_vec_11563 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_11564);
													mem_vec_11564 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_11565);
													mem_vec_11565 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_11566);
													mem_vec_11566 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_11567);
													mem_vec_11567 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_11568);
													mem_vec_11568 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_11569);
													mem_vec_11569 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_11570);
													mem_vec_11570 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_11571);
													mem_vec_11571 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_11572);
													mem_vec_11572 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_11573);
													mem_vec_11573 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_11574);
													mem_vec_11574 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_11575);
													mem_vec_11575 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_65 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_11556);
													mem_vec_11556 = vec_64;

													vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_11557);
													mem_vec_11557 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_11558);
													mem_vec_11558 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_11559);
													mem_vec_11559 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11560);
													mem_vec_11560 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_11561);
													mem_vec_11561 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_11562);
													mem_vec_11562 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_11563);
													mem_vec_11563 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_11564);
													mem_vec_11564 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_11565);
													mem_vec_11565 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_11566);
													mem_vec_11566 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_11567);
													mem_vec_11567 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_11568);
													mem_vec_11568 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_11569);
													mem_vec_11569 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_11570);
													mem_vec_11570 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_11571);
													mem_vec_11571 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_11572);
													mem_vec_11572 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_11573);
													mem_vec_11573 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_11574);
													mem_vec_11574 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_11575);
													mem_vec_11575 = vec_95;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11556);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11557);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11558);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11559);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11560);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11561);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11562);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11563);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11564);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11565);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11566);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11567);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11568);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_11569);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11570);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_11571);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11572);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_11573);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11574);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_11575);
									}
								}
							}
						}
						for (y = y952 + 110, yp_1 = y952_p_0, yp_0 = 0;
							y < y952 + 110 + 26;
							y += 13, yp_1 += 13, yp_0 += 13){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 16
							// T (c, 2) (16 / 8)
							for (c1264 = c1265, c1264_p_1 = c1265_p_0, c1264_p_0 = 0;
								c1264 < c1265 + 16;
								c1264 += 8, c1264_p_1 += 8, c1264_p_0 += 8){
								// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 16
								// T (w, 3) (3 / 1)
								for (w = w636, wp_0 = 0;
									w < w636 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 16
									// T (x, 2) (2 / 1)
									for (x = x1290, xp_2 = x1290_p_1, xp_1 = x1290_p_0, xp_0 = 0;
										x < x1290 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11576 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11577 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11578 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11579 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_11590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_11591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_11592 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_11593 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_11594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_11595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												mem_vec_11596 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_11597 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
												mem_vec_11598 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_11599 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
												mem_vec_11600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_11601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
												// T (c, 8) (8 / 1)
												for (c = c1264, cp_2 = c1264_p_1, cp_1 = c1264_p_0, cp_0 = 0;
													c < c1264 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11576);
													mem_vec_11576 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11577);
													mem_vec_11577 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_11578);
													mem_vec_11578 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_11579);
													mem_vec_11579 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_11580);
													mem_vec_11580 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_11581);
													mem_vec_11581 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_11582);
													mem_vec_11582 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_11583);
													mem_vec_11583 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11584);
													mem_vec_11584 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11585);
													mem_vec_11585 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_11586);
													mem_vec_11586 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_11587);
													mem_vec_11587 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_11588);
													mem_vec_11588 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_11589);
													mem_vec_11589 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_11590);
													mem_vec_11590 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_11591);
													mem_vec_11591 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_11592);
													mem_vec_11592 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_11593);
													mem_vec_11593 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11594);
													mem_vec_11594 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11595);
													mem_vec_11595 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm256_set1_ps(scal_10);


													vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_11596);
													mem_vec_11596 = vec_32;



													vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_11597);
													mem_vec_11597 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm256_set1_ps(scal_11);


													vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_11598);
													mem_vec_11598 = vec_35;



													vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_11599);
													mem_vec_11599 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm256_set1_ps(scal_12);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_11600);
													mem_vec_11600 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_11601);
													mem_vec_11601 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_42 = _mm256_set1_ps(scal_13);
													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_11576);
													mem_vec_11576 = vec_41;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_11577);
													mem_vec_11577 = vec_44;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_11578);
													mem_vec_11578 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_11579);
													mem_vec_11579 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_11580);
													mem_vec_11580 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_11581);
													mem_vec_11581 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_11582);
													mem_vec_11582 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_11583);
													mem_vec_11583 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_11584);
													mem_vec_11584 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_11585);
													mem_vec_11585 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_11586);
													mem_vec_11586 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_11587);
													mem_vec_11587 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_11588);
													mem_vec_11588 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_11589);
													mem_vec_11589 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_65 = _mm256_set1_ps(scal_20);


													vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_11590);
													mem_vec_11590 = vec_64;



													vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_11591);
													mem_vec_11591 = vec_66;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_68 = _mm256_set1_ps(scal_21);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_11592);
													mem_vec_11592 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_11593);
													mem_vec_11593 = vec_69;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_71 = _mm256_set1_ps(scal_22);


													vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_11594);
													mem_vec_11594 = vec_70;



													vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_11595);
													mem_vec_11595 = vec_72;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_23);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_11596);
													mem_vec_11596 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_11597);
													mem_vec_11597 = vec_75;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
													vec_77 = _mm256_set1_ps(scal_24);


													vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_11598);
													mem_vec_11598 = vec_76;



													vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_11599);
													mem_vec_11599 = vec_78;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
													vec_80 = _mm256_set1_ps(scal_25);


													vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_11600);
													mem_vec_11600 = vec_79;



													vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_11601);
													mem_vec_11601 = vec_81;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_26);
													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_11576);
													mem_vec_11576 = vec_82;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_11577);
													mem_vec_11577 = vec_85;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_11578);
													mem_vec_11578 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_11579);
													mem_vec_11579 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_11580);
													mem_vec_11580 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_11581);
													mem_vec_11581 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_11582);
													mem_vec_11582 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_11583);
													mem_vec_11583 = vec_95;
													scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_97 = _mm256_set1_ps(scal_30);


													vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_11584);
													mem_vec_11584 = vec_96;



													vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_11585);
													mem_vec_11585 = vec_98;
													scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_100 = _mm256_set1_ps(scal_31);


													vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_11586);
													mem_vec_11586 = vec_99;



													vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_11587);
													mem_vec_11587 = vec_101;
													scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_32);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_11588);
													mem_vec_11588 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_11589);
													mem_vec_11589 = vec_104;
													scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_106 = _mm256_set1_ps(scal_33);


													vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_11590);
													mem_vec_11590 = vec_105;



													vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_11591);
													mem_vec_11591 = vec_107;
													scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_109 = _mm256_set1_ps(scal_34);


													vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_11592);
													mem_vec_11592 = vec_108;



													vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_11593);
													mem_vec_11593 = vec_110;
													scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_112 = _mm256_set1_ps(scal_35);


													vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_11594);
													mem_vec_11594 = vec_111;



													vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_11595);
													mem_vec_11595 = vec_113;
													scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
													vec_115 = _mm256_set1_ps(scal_36);


													vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_11596);
													mem_vec_11596 = vec_114;



													vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_11597);
													mem_vec_11597 = vec_116;
													scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
													vec_118 = _mm256_set1_ps(scal_37);


													vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_11598);
													mem_vec_11598 = vec_117;



													vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_11599);
													mem_vec_11599 = vec_119;
													scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
													vec_121 = _mm256_set1_ps(scal_38);


													vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_11600);
													mem_vec_11600 = vec_120;



													vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_11601);
													mem_vec_11601 = vec_122;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11576);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11577);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11578);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11579);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11580);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11581);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11582);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11583);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11584);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11585);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11586);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11587);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11588);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_11589);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11590);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_11591);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11592);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_11593);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11594);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_11595);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11596);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_11597);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11598);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_11599);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_11600);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_11601);
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