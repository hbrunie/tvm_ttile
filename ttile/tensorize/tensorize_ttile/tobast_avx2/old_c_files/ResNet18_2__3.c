#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (8, x);
  T (3, w); Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))];
  T (1, f); T (1, c); T (1, f); T (4, c); T (7, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1108_p_0, c1109_p_0, cp_1, c1108_p_1, cp_2, c1108, c1109, f, fp_0, f1012_p_0, f1013_p_0, fp_1, f1012_p_1, fp_2, f1012, f1013, w, wp_0, x, xp_0, x978_p_0, xp_1, x978, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y596 = 0;
IND_TYPE x979 = 0;
IND_TYPE h = 0;
IND_TYPE w510 = 0;
IND_TYPE c1110 = 0;
IND_TYPE f1014 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9576 ,mem_vec_9577 ,mem_vec_9578 ,mem_vec_9579 ,mem_vec_9580 ,mem_vec_9581 ,mem_vec_9582 ,mem_vec_9583 ,mem_vec_9584 ,mem_vec_9585 ,mem_vec_9586 ,mem_vec_9587 ,mem_vec_9588 ,mem_vec_9589 ,mem_vec_9590 ,mem_vec_9591 ,mem_vec_9592 ,mem_vec_9593 ,mem_vec_9594 ,mem_vec_9595 ,mem_vec_9596 ,mem_vec_9597 ,mem_vec_9598 ,mem_vec_9599 ,mem_vec_9600 ,mem_vec_9601 ,mem_vec_9602 ,mem_vec_9603 ,mem_vec_9604 ,mem_vec_9605 ,mem_vec_9606 ,mem_vec_9607 ,mem_vec_9608 ,mem_vec_9609 ,mem_vec_9610 ,mem_vec_9611 ,mem_vec_9612 ,mem_vec_9613 ,mem_vec_9614 ,mem_vec_9615 ,mem_vec_9616 ,mem_vec_9617 ,mem_vec_9618 ,mem_vec_9619 ,mem_vec_9620 ,mem_vec_9621 ,mem_vec_9622 ,mem_vec_9623 ,mem_vec_9624 ,mem_vec_9625 ,mem_vec_9626 ,mem_vec_9627 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 2) (64 / 32)
for (f1013 = f1014, f1013_p_0 = 0;
	f1013 < f1014 + 64;
	f1013 += 32, f1013_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
	// T (x, 7) (56 / 8)
	for (x978 = x979, x978_p_0 = 0;
		x978 < x979 + 56;
		x978 += 8, x978_p_0 += 8){
		// y = 56, x = 8, h = 3, w = 3, c = 64, f = 32
		// T (c, 4) (64 / 16)
		for (c1109 = c1110, c1109_p_0 = 0;
			c1109 < c1110 + 64;
			c1109 += 16, c1109_p_0 += 16){
			// y = 56, x = 8, h = 3, w = 3, c = 16, f = 32
			// T (f, 1) (32 / 32)
			for (f1012 = f1013, f1012_p_1 = f1013_p_0, f1012_p_0 = 0;
				f1012 < f1013 + 32;
				f1012 += 32, f1012_p_1 += 32, f1012_p_0 += 32){
				// y = 56, x = 8, h = 3, w = 3, c = 16, f = 32
				// T (c, 1) (16 / 16)
				for (c1108 = c1109, c1108_p_1 = c1109_p_0, c1108_p_0 = 0;
					c1108 < c1109 + 16;
					c1108 += 16, c1108_p_1 += 16, c1108_p_0 += 16){
					// y = 56, x = 8, h = 3, w = 3, c = 16, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1012, fp_2 = f1012_p_1, fp_1 = f1012_p_0, fp_0 = 0;
						f < f1012 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y596, yp_0 = 0;
								y < y596 + 42;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w510, wp_0 = 0;
									w < w510 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 8, h = 3, w = 1, c = 16, f = 32
									// T (x, 8) (8 / 1)
									for (x = x978, xp_1 = x978_p_0, xp_0 = 0;
										x < x978 + 8;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9576 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9577 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9578 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9579 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_9580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_9584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_9588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_9592 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9593 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_9596 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9597 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_9598 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9599 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1108, cp_2 = c1108_p_1, cp_1 = c1108_p_0, cp_0 = 0;
													c < c1108 + 16;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9576);
													mem_vec_9576 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9577);
													mem_vec_9577 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9578);
													mem_vec_9578 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9579);
													mem_vec_9579 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9580);
													mem_vec_9580 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9581);
													mem_vec_9581 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9582);
													mem_vec_9582 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9583);
													mem_vec_9583 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9584);
													mem_vec_9584 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9585);
													mem_vec_9585 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9586);
													mem_vec_9586 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9587);
													mem_vec_9587 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9588);
													mem_vec_9588 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9589);
													mem_vec_9589 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9590);
													mem_vec_9590 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9591);
													mem_vec_9591 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9592);
													mem_vec_9592 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9593);
													mem_vec_9593 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9594);
													mem_vec_9594 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9595);
													mem_vec_9595 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9596);
													mem_vec_9596 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9597);
													mem_vec_9597 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_9598);
													mem_vec_9598 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_9599);
													mem_vec_9599 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_9576);
													mem_vec_9576 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_9577);
													mem_vec_9577 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_9578);
													mem_vec_9578 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_9579);
													mem_vec_9579 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_9580);
													mem_vec_9580 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_9581);
													mem_vec_9581 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_9582);
													mem_vec_9582 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_9583);
													mem_vec_9583 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_9584);
													mem_vec_9584 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_9585);
													mem_vec_9585 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_9586);
													mem_vec_9586 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_9587);
													mem_vec_9587 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_9588);
													mem_vec_9588 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_9589);
													mem_vec_9589 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_9590);
													mem_vec_9590 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_9591);
													mem_vec_9591 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_9592);
													mem_vec_9592 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_9593);
													mem_vec_9593 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_9594);
													mem_vec_9594 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_9595);
													mem_vec_9595 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_9596);
													mem_vec_9596 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_9597);
													mem_vec_9597 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_9598);
													mem_vec_9598 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_9599);
													mem_vec_9599 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_9576);
													mem_vec_9576 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_9577);
													mem_vec_9577 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_9578);
													mem_vec_9578 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_9579);
													mem_vec_9579 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_9580);
													mem_vec_9580 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_9581);
													mem_vec_9581 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_9582);
													mem_vec_9582 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_9583);
													mem_vec_9583 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_9584);
													mem_vec_9584 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_9585);
													mem_vec_9585 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_9586);
													mem_vec_9586 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_9587);
													mem_vec_9587 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_9588);
													mem_vec_9588 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_9589);
													mem_vec_9589 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_9590);
													mem_vec_9590 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_9591);
													mem_vec_9591 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_9592);
													mem_vec_9592 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_9593);
													mem_vec_9593 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_9594);
													mem_vec_9594 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_9595);
													mem_vec_9595 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_9596);
													mem_vec_9596 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_9597);
													mem_vec_9597 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_9598);
													mem_vec_9598 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_9599);
													mem_vec_9599 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9576);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9577);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9578);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9579);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9580);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9581);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9582);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9583);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9584);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9585);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9586);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9587);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9588);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9589);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9590);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9591);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9592);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9593);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9594);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9595);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9596);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9597);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9598);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_9599);
									}
								}
							}
							for (y = y596 + 42, yp_0 = 0;
								y < y596 + 42 + 14;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 8, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w510, wp_0 = 0;
									w < w510 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 8, h = 3, w = 1, c = 16, f = 32
									// T (x, 8) (8 / 1)
									for (x = x978, xp_1 = x978_p_0, xp_0 = 0;
										x < x978 + 8;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9600 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9601 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9602 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9603 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_9604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_9608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_9612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_9616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_9620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_9622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_9624 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9625 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_9626 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9627 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1108, cp_2 = c1108_p_1, cp_1 = c1108_p_0, cp_0 = 0;
													c < c1108 + 16;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9600);
													mem_vec_9600 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9601);
													mem_vec_9601 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9602);
													mem_vec_9602 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9603);
													mem_vec_9603 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9604);
													mem_vec_9604 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9605);
													mem_vec_9605 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9606);
													mem_vec_9606 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9607);
													mem_vec_9607 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9608);
													mem_vec_9608 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9609);
													mem_vec_9609 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9610);
													mem_vec_9610 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9611);
													mem_vec_9611 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9612);
													mem_vec_9612 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9613);
													mem_vec_9613 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9614);
													mem_vec_9614 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9615);
													mem_vec_9615 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9616);
													mem_vec_9616 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9617);
													mem_vec_9617 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9618);
													mem_vec_9618 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9619);
													mem_vec_9619 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9620);
													mem_vec_9620 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9621);
													mem_vec_9621 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_9622);
													mem_vec_9622 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_9623);
													mem_vec_9623 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_9624);
													mem_vec_9624 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_9625);
													mem_vec_9625 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_9626);
													mem_vec_9626 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_9627);
													mem_vec_9627 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_9600);
													mem_vec_9600 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_9601);
													mem_vec_9601 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_9602);
													mem_vec_9602 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_9603);
													mem_vec_9603 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_9604);
													mem_vec_9604 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_9605);
													mem_vec_9605 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_9606);
													mem_vec_9606 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_9607);
													mem_vec_9607 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_9608);
													mem_vec_9608 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_9609);
													mem_vec_9609 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_9610);
													mem_vec_9610 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_9611);
													mem_vec_9611 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_9612);
													mem_vec_9612 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_9613);
													mem_vec_9613 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_9614);
													mem_vec_9614 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_9615);
													mem_vec_9615 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_9616);
													mem_vec_9616 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_9617);
													mem_vec_9617 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_9618);
													mem_vec_9618 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_9619);
													mem_vec_9619 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_9620);
													mem_vec_9620 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_9621);
													mem_vec_9621 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_9622);
													mem_vec_9622 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_9623);
													mem_vec_9623 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_9624);
													mem_vec_9624 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_9625);
													mem_vec_9625 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_9626);
													mem_vec_9626 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_9627);
													mem_vec_9627 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_9600);
													mem_vec_9600 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_9601);
													mem_vec_9601 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_9602);
													mem_vec_9602 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_9603);
													mem_vec_9603 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_9604);
													mem_vec_9604 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_9605);
													mem_vec_9605 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_9606);
													mem_vec_9606 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_9607);
													mem_vec_9607 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_9608);
													mem_vec_9608 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_9609);
													mem_vec_9609 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_9610);
													mem_vec_9610 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_9611);
													mem_vec_9611 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_9612);
													mem_vec_9612 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_9613);
													mem_vec_9613 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_9614);
													mem_vec_9614 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_9615);
													mem_vec_9615 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_9616);
													mem_vec_9616 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_9617);
													mem_vec_9617 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_9618);
													mem_vec_9618 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_9619);
													mem_vec_9619 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_9620);
													mem_vec_9620 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_9621);
													mem_vec_9621 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_9622);
													mem_vec_9622 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_9623);
													mem_vec_9623 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_9624);
													mem_vec_9624 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_9625);
													mem_vec_9625 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_9626);
													mem_vec_9626 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_9627);
													mem_vec_9627 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9600);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9601);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9602);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9603);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9604);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9605);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9606);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9607);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9608);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9609);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9610);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9611);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9612);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9613);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9614);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9615);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9616);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9617);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9618);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9619);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9620);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9621);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9622);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_9623);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9624);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_9625);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9626);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_9627);
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