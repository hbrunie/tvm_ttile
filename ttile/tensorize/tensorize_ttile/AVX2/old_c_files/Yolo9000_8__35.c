#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (68, x); T (8, c); T (16, f); T (1, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (1, c)]
*/
IND_TYPE c, cp_0, c78_p_0, c79_p_0, c80_p_0, cp_1, c78_p_1, c79_p_1, cp_2, c78_p_2, cp_3, c78, c79, c80, f, fp_0, w, wp_0, x, xp_0, x54_p_0, xp_1, x54, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y36 = 0;
IND_TYPE x55 = 0;
IND_TYPE h = 0;
IND_TYPE w24 = 0;
IND_TYPE c81 = 0;
IND_TYPE f48 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
for (c80 = c81, c80_p_0 = 0;
	c80 < c81 + 128;
	c80 += 128, c80_p_0 += 128){
		for (y = y36, yp_0 = 0;
			y < y36 + 24;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 1) (68 / 68)
			for (x54 = x55, x54_p_0 = 0;
				x54 < x55 + 68;
				x54 += 68, x54_p_0 += 68){
				// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c79 = c80, c79_p_1 = c80_p_0, c79_p_0 = 0;
					c79 < c80 + 128;
					c79 += 128, c79_p_1 += 128, c79_p_0 += 128){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
					// T (f, 16) (256 / 16)
					for (f = f48, fp_0 = 0;
						f < f48 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 16
						// T (c, 8) (128 / 16)
						for (c78 = c79, c78_p_2 = c79_p_1, c78_p_1 = c79_p_0, c78_p_0 = 0;
							c78 < c79 + 128;
							c78 += 16, c78_p_2 += 16, c78_p_1 += 16, c78_p_0 += 16){
							// y = ph_y, x = 68, h = 3, w = 3, c = 16, f = 16
							// T (x, 68) (68 / 1)
							for (x = x54, xp_1 = x54_p_0, xp_0 = 0;
								x < x54 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
								// T (w, 3) (3 / 1)
								for (w = w24, wp_0 = 0;
									w < w24 + 3;
									w += 1, wp_0 += 1){
											mem_vec_638 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_639 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_648 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_649 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_650 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_651 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_652 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_653 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c78, cp_3 = c78_p_2, cp_2 = c78_p_1, cp_1 = c78_p_0, cp_0 = 0;
												c < c78 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_638);
												mem_vec_638 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_639);
												mem_vec_639 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_640);
												mem_vec_640 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_641);
												mem_vec_641 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_642);
												mem_vec_642 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_643);
												mem_vec_643 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_644);
												mem_vec_644 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_645);
												mem_vec_645 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_646);
												mem_vec_646 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_647);
												mem_vec_647 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_648);
												mem_vec_648 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_649);
												mem_vec_649 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_650);
												mem_vec_650 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_651);
												mem_vec_651 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_652);
												mem_vec_652 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_653);
												mem_vec_653 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_638);
												mem_vec_638 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_639);
												mem_vec_639 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_640);
												mem_vec_640 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_641);
												mem_vec_641 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_642);
												mem_vec_642 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_643);
												mem_vec_643 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_644);
												mem_vec_644 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_645);
												mem_vec_645 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_646);
												mem_vec_646 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_647);
												mem_vec_647 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_648);
												mem_vec_648 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_649);
												mem_vec_649 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_650);
												mem_vec_650 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_651);
												mem_vec_651 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_652);
												mem_vec_652 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_653);
												mem_vec_653 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_638);
												mem_vec_638 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_639);
												mem_vec_639 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_640);
												mem_vec_640 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_641);
												mem_vec_641 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_642);
												mem_vec_642 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_643);
												mem_vec_643 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_644);
												mem_vec_644 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_645);
												mem_vec_645 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_646);
												mem_vec_646 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_647);
												mem_vec_647 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_648);
												mem_vec_648 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_649);
												mem_vec_649 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_650);
												mem_vec_650 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_651);
												mem_vec_651 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_652);
												mem_vec_652 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_653);
												mem_vec_653 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_638);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_639);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_640);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_641);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_642);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_643);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_644);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_645);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_646);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_647);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_648);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_649);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_650);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_651);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_652);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_653);
								}
							}
						}
					}
				}
			}
		}
		for (y = y36 + 24, yp_0 = 0;
			y < y36 + 24 + 44;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 1) (68 / 68)
			for (x54 = x55, x54_p_0 = 0;
				x54 < x55 + 68;
				x54 += 68, x54_p_0 += 68){
				// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c79 = c80, c79_p_1 = c80_p_0, c79_p_0 = 0;
					c79 < c80 + 128;
					c79 += 128, c79_p_1 += 128, c79_p_0 += 128){
					// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
					// T (f, 16) (256 / 16)
					for (f = f48, fp_0 = 0;
						f < f48 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 16
						// T (c, 8) (128 / 16)
						for (c78 = c79, c78_p_2 = c79_p_1, c78_p_1 = c79_p_0, c78_p_0 = 0;
							c78 < c79 + 128;
							c78 += 16, c78_p_2 += 16, c78_p_1 += 16, c78_p_0 += 16){
							// y = ph_y, x = 68, h = 3, w = 3, c = 16, f = 16
							// T (x, 68) (68 / 1)
							for (x = x54, xp_1 = x54_p_0, xp_0 = 0;
								x < x54 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
								// T (w, 3) (3 / 1)
								for (w = w24, wp_0 = 0;
									w < w24 + 3;
									w += 1, wp_0 += 1){
											mem_vec_654 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_655 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_656 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_657 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_658 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_659 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_660 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_661 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_662 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_663 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_664 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_665 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_666 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_667 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_668 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_669 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_670 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_671 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_672 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_673 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_674 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_675 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c78, cp_3 = c78_p_2, cp_2 = c78_p_1, cp_1 = c78_p_0, cp_0 = 0;
												c < c78 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_654);
												mem_vec_654 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_655);
												mem_vec_655 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_656);
												mem_vec_656 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_657);
												mem_vec_657 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_658);
												mem_vec_658 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_659);
												mem_vec_659 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_660);
												mem_vec_660 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_661);
												mem_vec_661 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_662);
												mem_vec_662 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_663);
												mem_vec_663 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_664);
												mem_vec_664 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_665);
												mem_vec_665 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_666);
												mem_vec_666 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_667);
												mem_vec_667 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_668);
												mem_vec_668 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_669);
												mem_vec_669 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_670);
												mem_vec_670 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_671);
												mem_vec_671 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_672);
												mem_vec_672 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_673);
												mem_vec_673 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_674);
												mem_vec_674 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_675);
												mem_vec_675 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_654);
												mem_vec_654 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_655);
												mem_vec_655 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_656);
												mem_vec_656 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_657);
												mem_vec_657 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_658);
												mem_vec_658 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_659);
												mem_vec_659 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_660);
												mem_vec_660 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_661);
												mem_vec_661 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_662);
												mem_vec_662 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_663);
												mem_vec_663 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_664);
												mem_vec_664 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_665);
												mem_vec_665 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_666);
												mem_vec_666 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_667);
												mem_vec_667 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_668);
												mem_vec_668 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_669);
												mem_vec_669 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_670);
												mem_vec_670 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_671);
												mem_vec_671 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_672);
												mem_vec_672 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_673);
												mem_vec_673 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_674);
												mem_vec_674 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_675);
												mem_vec_675 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_654);
												mem_vec_654 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_655);
												mem_vec_655 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_656);
												mem_vec_656 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_657);
												mem_vec_657 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_658);
												mem_vec_658 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_659);
												mem_vec_659 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_660);
												mem_vec_660 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_661);
												mem_vec_661 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_662);
												mem_vec_662 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_663);
												mem_vec_663 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_664);
												mem_vec_664 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_665);
												mem_vec_665 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_666);
												mem_vec_666 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_667);
												mem_vec_667 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_668);
												mem_vec_668 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_669);
												mem_vec_669 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_670);
												mem_vec_670 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_671);
												mem_vec_671 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_672);
												mem_vec_672 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_673);
												mem_vec_673 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_674);
												mem_vec_674 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_675);
												mem_vec_675 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_654);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_655);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_656);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_657);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_658);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_659);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_660);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_661);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_662);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_663);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_664);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_665);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_666);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_667);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_668);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_669);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_670);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_671);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_672);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_673);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_674);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_675);
								}
							}
						}
					}
				}
			}
		}
}


}