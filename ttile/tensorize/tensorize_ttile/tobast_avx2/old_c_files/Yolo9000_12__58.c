#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (8, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (2, c);
  T (32, f); T (34, x); T (1, c)]
*/
IND_TYPE c, cp_0, c1030_p_0, c1031_p_0, c1032_p_0, cp_1, c1030_p_1, c1031_p_1, cp_2, c1030_p_2, cp_3, c1030, c1031, c1032, f, fp_0, w, wp_0, x, xp_0, x824_p_0, x825_p_0, xp_1, x824_p_1, xp_2, x824, x825, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y412 = 0;
IND_TYPE x826 = 0;
IND_TYPE h = 0;
IND_TYPE w412 = 0;
IND_TYPE c1033 = 0;
IND_TYPE f412 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8556 ,mem_vec_8557 ,mem_vec_8558 ,mem_vec_8559 ,mem_vec_8560 ,mem_vec_8561 ,mem_vec_8562 ,mem_vec_8563 ,mem_vec_8564 ,mem_vec_8565 ,mem_vec_8566 ,mem_vec_8567 ,mem_vec_8568 ,mem_vec_8569 ,mem_vec_8570 ,mem_vec_8571 ,mem_vec_8572 ,mem_vec_8573 ,mem_vec_8574 ,mem_vec_8575 ,mem_vec_8576 ,mem_vec_8577 ,mem_vec_8578 ,mem_vec_8579 ,mem_vec_8580 ,mem_vec_8581 ,mem_vec_8582 ,mem_vec_8583 ,mem_vec_8584 ,mem_vec_8585 ,mem_vec_8586 ,mem_vec_8587 ,mem_vec_8588 ,mem_vec_8589 ,mem_vec_8590 ,mem_vec_8591 ,mem_vec_8592 ,mem_vec_8593 ,mem_vec_8594 ,mem_vec_8595 ,mem_vec_8596 ,mem_vec_8597 ,mem_vec_8598 ,mem_vec_8599 ,mem_vec_8600 ,mem_vec_8601 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 1) (256 / 256)
for (c1032 = c1033, c1032_p_0 = 0;
	c1032 < c1033 + 256;
	c1032 += 256, c1032_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 34) (34 / 1)
	for (x825 = x826, x825_p_0 = 0;
		x825 < x826 + 34;
		x825 += 1, x825_p_0 += 1){
		// y = 34, x = 1, h = 3, w = 3, c = 256, f = 512
		// T (f, 32) (512 / 16)
		for (f = f412, fp_0 = 0;
			f < f412 + 512;
			f += 16, fp_0 += 16){
			// y = 34, x = 1, h = 3, w = 3, c = 256, f = 16
			// T (c, 2) (256 / 128)
			for (c1031 = c1032, c1031_p_1 = c1032_p_0, c1031_p_0 = 0;
				c1031 < c1032 + 256;
				c1031 += 128, c1031_p_1 += 128, c1031_p_0 += 128){
					for (y = y412, yp_0 = 0;
						y < y412 + 22;
						y += 11, yp_0 += 11){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
						// T (x, 1) (1 / 1)
						for (x824 = x825, x824_p_1 = x825_p_0, x824_p_0 = 0;
							x824 < x825 + 1;
							x824 += 1, x824_p_1 += 1, x824_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
							// T (c, 8) (128 / 16)
							for (c1030 = c1031, c1030_p_2 = c1031_p_1, c1030_p_1 = c1031_p_0, c1030_p_0 = 0;
								c1030 < c1031 + 128;
								c1030 += 16, c1030_p_2 += 16, c1030_p_1 += 16, c1030_p_0 += 16){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
								// T (w, 3) (3 / 1)
								for (w = w412, wp_0 = 0;
									w < w412 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
									// T (x, 1) (1 / 1)
									for (x = x824, xp_2 = x824_p_1, xp_1 = x824_p_0, xp_0 = 0;
										x < x824 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8556 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8557 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_8568 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8569 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_8570 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8571 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_8572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_8574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_8575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												mem_vec_8576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_8577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
												// T (c, 16) (16 / 1)
												for (c = c1030, cp_3 = c1030_p_2, cp_2 = c1030_p_1, cp_1 = c1030_p_0, cp_0 = 0;
													c < c1030 + 16;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8556);
													mem_vec_8556 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8557);
													mem_vec_8557 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8558);
													mem_vec_8558 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8559);
													mem_vec_8559 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8560);
													mem_vec_8560 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8561);
													mem_vec_8561 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8562);
													mem_vec_8562 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8563);
													mem_vec_8563 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8564);
													mem_vec_8564 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8565);
													mem_vec_8565 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8566);
													mem_vec_8566 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8567);
													mem_vec_8567 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8568);
													mem_vec_8568 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8569);
													mem_vec_8569 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8570);
													mem_vec_8570 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8571);
													mem_vec_8571 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8572);
													mem_vec_8572 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8573);
													mem_vec_8573 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8574);
													mem_vec_8574 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8575);
													mem_vec_8575 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm256_set1_ps(scal_10);


													vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_8576);
													mem_vec_8576 = vec_32;



													vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_8577);
													mem_vec_8577 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_36 = _mm256_set1_ps(scal_11);
													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_8556);
													mem_vec_8556 = vec_35;

													vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_8557);
													mem_vec_8557 = vec_38;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_8558);
													mem_vec_8558 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_8559);
													mem_vec_8559 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_8560);
													mem_vec_8560 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_8561);
													mem_vec_8561 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_8562);
													mem_vec_8562 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_8563);
													mem_vec_8563 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_8564);
													mem_vec_8564 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_8565);
													mem_vec_8565 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_8566);
													mem_vec_8566 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_8567);
													mem_vec_8567 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_8568);
													mem_vec_8568 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_8569);
													mem_vec_8569 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_8570);
													mem_vec_8570 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_8571);
													mem_vec_8571 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_8572);
													mem_vec_8572 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_8573);
													mem_vec_8573 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_65 = _mm256_set1_ps(scal_20);


													vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_8574);
													mem_vec_8574 = vec_64;



													vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_8575);
													mem_vec_8575 = vec_66;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
													vec_68 = _mm256_set1_ps(scal_21);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_8576);
													mem_vec_8576 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_8577);
													mem_vec_8577 = vec_69;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_71 = _mm256_set1_ps(scal_22);
													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_8556);
													mem_vec_8556 = vec_70;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_8557);
													mem_vec_8557 = vec_73;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_8558);
													mem_vec_8558 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_8559);
													mem_vec_8559 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_8560);
													mem_vec_8560 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_8561);
													mem_vec_8561 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_8562);
													mem_vec_8562 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_8563);
													mem_vec_8563 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_8564);
													mem_vec_8564 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_8565);
													mem_vec_8565 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8566);
													mem_vec_8566 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8567);
													mem_vec_8567 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_8568);
													mem_vec_8568 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_8569);
													mem_vec_8569 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_8570);
													mem_vec_8570 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_8571);
													mem_vec_8571 = vec_95;
													scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_97 = _mm256_set1_ps(scal_30);


													vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_8572);
													mem_vec_8572 = vec_96;



													vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_8573);
													mem_vec_8573 = vec_98;
													scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_100 = _mm256_set1_ps(scal_31);


													vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_8574);
													mem_vec_8574 = vec_99;



													vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_8575);
													mem_vec_8575 = vec_101;
													scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_32);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_8576);
													mem_vec_8576 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_8577);
													mem_vec_8577 = vec_104;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8556);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8557);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8558);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8559);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8560);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8561);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8562);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8563);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8564);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8565);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8566);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8567);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8568);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8569);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8570);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8571);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8572);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8573);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8574);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8575);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8576);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_8577);
									}
								}
							}
						}
					}
					for (y = y412 + 22, yp_0 = 0;
						y < y412 + 22 + 12;
						y += 12, yp_0 += 12){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
						// T (x, 1) (1 / 1)
						for (x824 = x825, x824_p_1 = x825_p_0, x824_p_0 = 0;
							x824 < x825 + 1;
							x824 += 1, x824_p_1 += 1, x824_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
							// T (c, 8) (128 / 16)
							for (c1030 = c1031, c1030_p_2 = c1031_p_1, c1030_p_1 = c1031_p_0, c1030_p_0 = 0;
								c1030 < c1031 + 128;
								c1030 += 16, c1030_p_2 += 16, c1030_p_1 += 16, c1030_p_0 += 16){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
								// T (w, 3) (3 / 1)
								for (w = w412, wp_0 = 0;
									w < w412 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
									// T (x, 1) (1 / 1)
									for (x = x824, xp_2 = x824_p_1, xp_1 = x824_p_0, xp_0 = 0;
										x < x824 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8578 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8579 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_8590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_8591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_8592 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_8593 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_8594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_8595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_8596 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_8597 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												mem_vec_8598 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_8599 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
												mem_vec_8600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_8601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
												// T (c, 16) (16 / 1)
												for (c = c1030, cp_3 = c1030_p_2, cp_2 = c1030_p_1, cp_1 = c1030_p_0, cp_0 = 0;
													c < c1030 + 16;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8578);
													mem_vec_8578 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8579);
													mem_vec_8579 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_8580);
													mem_vec_8580 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_8581);
													mem_vec_8581 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_8582);
													mem_vec_8582 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_8583);
													mem_vec_8583 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_8584);
													mem_vec_8584 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_8585);
													mem_vec_8585 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8586);
													mem_vec_8586 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8587);
													mem_vec_8587 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_8588);
													mem_vec_8588 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_8589);
													mem_vec_8589 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_8590);
													mem_vec_8590 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_8591);
													mem_vec_8591 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_8592);
													mem_vec_8592 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_8593);
													mem_vec_8593 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_8594);
													mem_vec_8594 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_8595);
													mem_vec_8595 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8596);
													mem_vec_8596 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8597);
													mem_vec_8597 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm256_set1_ps(scal_10);


													vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_8598);
													mem_vec_8598 = vec_32;



													vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_8599);
													mem_vec_8599 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm256_set1_ps(scal_11);


													vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_8600);
													mem_vec_8600 = vec_35;



													vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_8601);
													mem_vec_8601 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_12);
													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_8578);
													mem_vec_8578 = vec_38;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_8579);
													mem_vec_8579 = vec_41;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_8580);
													mem_vec_8580 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_8581);
													mem_vec_8581 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_8582);
													mem_vec_8582 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_8583);
													mem_vec_8583 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_8584);
													mem_vec_8584 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_8585);
													mem_vec_8585 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_8586);
													mem_vec_8586 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_8587);
													mem_vec_8587 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_8588);
													mem_vec_8588 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_8589);
													mem_vec_8589 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_8590);
													mem_vec_8590 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_8591);
													mem_vec_8591 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_8592);
													mem_vec_8592 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_8593);
													mem_vec_8593 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_65 = _mm256_set1_ps(scal_20);


													vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_8594);
													mem_vec_8594 = vec_64;



													vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_8595);
													mem_vec_8595 = vec_66;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_68 = _mm256_set1_ps(scal_21);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_8596);
													mem_vec_8596 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_8597);
													mem_vec_8597 = vec_69;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
													vec_71 = _mm256_set1_ps(scal_22);


													vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_8598);
													mem_vec_8598 = vec_70;



													vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_8599);
													mem_vec_8599 = vec_72;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_23);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_8600);
													mem_vec_8600 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_8601);
													mem_vec_8601 = vec_75;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_77 = _mm256_set1_ps(scal_24);
													vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_8578);
													mem_vec_8578 = vec_76;

													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_8579);
													mem_vec_8579 = vec_79;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_8580);
													mem_vec_8580 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_8581);
													mem_vec_8581 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_8582);
													mem_vec_8582 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_8583);
													mem_vec_8583 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_8584);
													mem_vec_8584 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_8585);
													mem_vec_8585 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_8586);
													mem_vec_8586 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_8587);
													mem_vec_8587 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_8588);
													mem_vec_8588 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_8589);
													mem_vec_8589 = vec_95;
													scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_97 = _mm256_set1_ps(scal_30);


													vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_8590);
													mem_vec_8590 = vec_96;



													vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_8591);
													mem_vec_8591 = vec_98;
													scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_100 = _mm256_set1_ps(scal_31);


													vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_8592);
													mem_vec_8592 = vec_99;



													vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_8593);
													mem_vec_8593 = vec_101;
													scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_32);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_8594);
													mem_vec_8594 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_8595);
													mem_vec_8595 = vec_104;
													scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_106 = _mm256_set1_ps(scal_33);


													vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_8596);
													mem_vec_8596 = vec_105;



													vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_8597);
													mem_vec_8597 = vec_107;
													scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
													vec_109 = _mm256_set1_ps(scal_34);


													vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_8598);
													mem_vec_8598 = vec_108;



													vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_8599);
													mem_vec_8599 = vec_110;
													scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
													vec_112 = _mm256_set1_ps(scal_35);


													vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_8600);
													mem_vec_8600 = vec_111;



													vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_8601);
													mem_vec_8601 = vec_113;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8578);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8579);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8580);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8581);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8582);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8583);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8584);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8585);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8586);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8587);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8588);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8589);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8590);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_8591);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8592);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_8593);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8594);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_8595);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8596);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_8597);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8598);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_8599);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8600);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_8601);
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