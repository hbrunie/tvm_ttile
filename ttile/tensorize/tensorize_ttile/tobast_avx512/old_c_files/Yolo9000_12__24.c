#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (8, f); T (2, x);
  Lambda_apply y [((Iter 3), (Arg 7)); ((Iter 1), (Arg 13))]; T (2, f);
  T (256, c); T (1, f)]
*/
IND_TYPE c, cp_0, c692_p_0, cp_1, c692, f, fp_0, f736_p_0, f737_p_0, fp_1, f736_p_1, fp_2, f736, f737, h, hp_0, x, xp_0, x692_p_0, xp_1, x692, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y424 = 0;
IND_TYPE x693 = 0;
IND_TYPE h310 = 0;
IND_TYPE w = 0;
IND_TYPE c693 = 0;
IND_TYPE f738 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6424 ,mem_vec_6425 ,mem_vec_6426 ,mem_vec_6427 ,mem_vec_6428 ,mem_vec_6429 ,mem_vec_6430 ,mem_vec_6431 ,mem_vec_6432 ,mem_vec_6433 ,mem_vec_6434 ,mem_vec_6435 ,mem_vec_6436 ,mem_vec_6437 ,mem_vec_6438 ,mem_vec_6439 ,mem_vec_6440 ,mem_vec_6441 ,mem_vec_6442 ,mem_vec_6443 ,mem_vec_6444 ,mem_vec_6445 ,mem_vec_6446 ,mem_vec_6447 ,mem_vec_6448 ,mem_vec_6449 ,mem_vec_6450 ,mem_vec_6451 ,mem_vec_6452 ,mem_vec_6453 ,mem_vec_6454 ,mem_vec_6455 ,mem_vec_6456 ,mem_vec_6457 ,mem_vec_6458 ,mem_vec_6459 ,mem_vec_6460 ,mem_vec_6461 ,mem_vec_6462 ,mem_vec_6463 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f737 = f738, f737_p_0 = 0;
	f737 < f738 + 512;
	f737 += 512, f737_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 256) (256 / 1)
	for (c692 = c693, c692_p_0 = 0;
		c692 < c693 + 256;
		c692 += 1, c692_p_0 += 1){
		// y = 34, x = 34, h = 3, w = 3, c = 1, f = 512
		// T (f, 2) (512 / 256)
		for (f736 = f737, f736_p_1 = f737_p_0, f736_p_0 = 0;
			f736 < f737 + 512;
			f736 += 256, f736_p_1 += 256, f736_p_0 += 256){
				for (y = y424, yp_0 = 0;
					y < y424 + 21;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 256
					// T (x, 2) (34 / 17)
					for (x692 = x693, x692_p_0 = 0;
						x692 < x693 + 34;
						x692 += 17, x692_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 256
						// T (f, 8) (256 / 32)
						for (f = f736, fp_2 = f736_p_1, fp_1 = f736_p_0, fp_0 = 0;
							f < f736 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h310, hp_0 = 0;
								h < h310 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 1, f = 32
								// T (x, 17) (17 / 1)
								for (x = x692, xp_1 = x692_p_0, xp_0 = 0;
									x < x692 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6424 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6425 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c692, cp_1 = c692_p_0, cp_0 = 0;
												c < c692 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6424);
												mem_vec_6424 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6425);
												mem_vec_6425 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6426);
												mem_vec_6426 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6427);
												mem_vec_6427 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6428);
												mem_vec_6428 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6429);
												mem_vec_6429 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6430);
												mem_vec_6430 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6431);
												mem_vec_6431 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6432);
												mem_vec_6432 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6433);
												mem_vec_6433 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6434);
												mem_vec_6434 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6435);
												mem_vec_6435 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6436);
												mem_vec_6436 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6437);
												mem_vec_6437 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);
												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_6424);
												mem_vec_6424 = vec_23;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_6425);
												mem_vec_6425 = vec_26;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_29 = _mm512_set1_ps(scal_8);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6426);
												mem_vec_6426 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6427);
												mem_vec_6427 = vec_30;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_32 = _mm512_set1_ps(scal_9);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_6428);
												mem_vec_6428 = vec_31;



												vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_6429);
												mem_vec_6429 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_6430);
												mem_vec_6430 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_6431);
												mem_vec_6431 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_6432);
												mem_vec_6432 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_6433);
												mem_vec_6433 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_6434);
												mem_vec_6434 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_6435);
												mem_vec_6435 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_6436);
												mem_vec_6436 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_6437);
												mem_vec_6437 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_47 = _mm512_set1_ps(scal_14);
												vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_6424);
												mem_vec_6424 = vec_46;

												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_6425);
												mem_vec_6425 = vec_49;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_52 = _mm512_set1_ps(scal_15);


												vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_6426);
												mem_vec_6426 = vec_51;



												vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_6427);
												mem_vec_6427 = vec_53;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_55 = _mm512_set1_ps(scal_16);


												vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_6428);
												mem_vec_6428 = vec_54;



												vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_6429);
												mem_vec_6429 = vec_56;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_58 = _mm512_set1_ps(scal_17);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_6430);
												mem_vec_6430 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_6431);
												mem_vec_6431 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_61 = _mm512_set1_ps(scal_18);


												vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_6432);
												mem_vec_6432 = vec_60;



												vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_6433);
												mem_vec_6433 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_19);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_6434);
												mem_vec_6434 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_6435);
												mem_vec_6435 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_67 = _mm512_set1_ps(scal_20);


												vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_6436);
												mem_vec_6436 = vec_66;



												vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_6437);
												mem_vec_6437 = vec_68;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6424);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6425);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6426);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6427);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6428);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6429);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6430);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6431);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6432);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6433);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6434);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6435);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6436);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6437);
								}
							}
						}
					}
				}
				for (y = y424 + 21, yp_0 = 0;
					y < y424 + 21 + 13;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 3, w = 3, c = 1, f = 256
					// T (x, 2) (34 / 17)
					for (x692 = x693, x692_p_0 = 0;
						x692 < x693 + 34;
						x692 += 17, x692_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 256
						// T (f, 8) (256 / 32)
						for (f = f736, fp_2 = f736_p_1, fp_1 = f736_p_0, fp_0 = 0;
							f < f736 + 256;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 1, f = 32
							// T (h, 3) (3 / 1)
							for (h = h310, hp_0 = 0;
								h < h310 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 1, f = 32
								// T (x, 17) (17 / 1)
								for (x = x692, xp_1 = x692_p_0, xp_0 = 0;
									x < x692 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6438 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6439 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_6458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_6459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_6460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_6461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_6462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_6463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c692, cp_1 = c692_p_0, cp_0 = 0;
												c < c692 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6438);
												mem_vec_6438 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6439);
												mem_vec_6439 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6440);
												mem_vec_6440 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6441);
												mem_vec_6441 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6442);
												mem_vec_6442 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6443);
												mem_vec_6443 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6444);
												mem_vec_6444 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6445);
												mem_vec_6445 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6446);
												mem_vec_6446 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6447);
												mem_vec_6447 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6448);
												mem_vec_6448 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6449);
												mem_vec_6449 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6450);
												mem_vec_6450 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6451);
												mem_vec_6451 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6452);
												mem_vec_6452 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6453);
												mem_vec_6453 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6454);
												mem_vec_6454 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6455);
												mem_vec_6455 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6456);
												mem_vec_6456 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6457);
												mem_vec_6457 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6458);
												mem_vec_6458 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6459);
												mem_vec_6459 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6460);
												mem_vec_6460 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6461);
												mem_vec_6461 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_6462);
												mem_vec_6462 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_6463);
												mem_vec_6463 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);
												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_41 = _mm512_fmadd_ps(vec_42, vec_43, mem_vec_6438);
												mem_vec_6438 = vec_41;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_44 = _mm512_fmadd_ps(vec_42, vec_45, mem_vec_6439);
												mem_vec_6439 = vec_44;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_43, mem_vec_6440);
												mem_vec_6440 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_45, mem_vec_6441);
												mem_vec_6441 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_43, mem_vec_6442);
												mem_vec_6442 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_45, mem_vec_6443);
												mem_vec_6443 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_6444);
												mem_vec_6444 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_6445);
												mem_vec_6445 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_43, mem_vec_6446);
												mem_vec_6446 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_45, mem_vec_6447);
												mem_vec_6447 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_6448);
												mem_vec_6448 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_6449);
												mem_vec_6449 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_6450);
												mem_vec_6450 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_6451);
												mem_vec_6451 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
												vec_65 = _mm512_set1_ps(scal_20);


												vec_64 = _mm512_fmadd_ps(vec_65, vec_43, mem_vec_6452);
												mem_vec_6452 = vec_64;



												vec_66 = _mm512_fmadd_ps(vec_65, vec_45, mem_vec_6453);
												mem_vec_6453 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
												vec_68 = _mm512_set1_ps(scal_21);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_43, mem_vec_6454);
												mem_vec_6454 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_45, mem_vec_6455);
												mem_vec_6455 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
												vec_71 = _mm512_set1_ps(scal_22);


												vec_70 = _mm512_fmadd_ps(vec_71, vec_43, mem_vec_6456);
												mem_vec_6456 = vec_70;



												vec_72 = _mm512_fmadd_ps(vec_71, vec_45, mem_vec_6457);
												mem_vec_6457 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
												vec_74 = _mm512_set1_ps(scal_23);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_6458);
												mem_vec_6458 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_6459);
												mem_vec_6459 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
												vec_77 = _mm512_set1_ps(scal_24);


												vec_76 = _mm512_fmadd_ps(vec_77, vec_43, mem_vec_6460);
												mem_vec_6460 = vec_76;



												vec_78 = _mm512_fmadd_ps(vec_77, vec_45, mem_vec_6461);
												mem_vec_6461 = vec_78;
												scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h) + c];
												vec_80 = _mm512_set1_ps(scal_25);


												vec_79 = _mm512_fmadd_ps(vec_80, vec_43, mem_vec_6462);
												mem_vec_6462 = vec_79;



												vec_81 = _mm512_fmadd_ps(vec_80, vec_45, mem_vec_6463);
												mem_vec_6463 = vec_81;
												scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_83 = _mm512_set1_ps(scal_26);
												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_82 = _mm512_fmadd_ps(vec_83, vec_84, mem_vec_6438);
												mem_vec_6438 = vec_82;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_85 = _mm512_fmadd_ps(vec_83, vec_86, mem_vec_6439);
												mem_vec_6439 = vec_85;
												scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_6440);
												mem_vec_6440 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_6441);
												mem_vec_6441 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_84, mem_vec_6442);
												mem_vec_6442 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_86, mem_vec_6443);
												mem_vec_6443 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_84, mem_vec_6444);
												mem_vec_6444 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_86, mem_vec_6445);
												mem_vec_6445 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_97 = _mm512_set1_ps(scal_30);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_6446);
												mem_vec_6446 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_6447);
												mem_vec_6447 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_100 = _mm512_set1_ps(scal_31);


												vec_99 = _mm512_fmadd_ps(vec_100, vec_84, mem_vec_6448);
												mem_vec_6448 = vec_99;



												vec_101 = _mm512_fmadd_ps(vec_100, vec_86, mem_vec_6449);
												mem_vec_6449 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_103 = _mm512_set1_ps(scal_32);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_6450);
												mem_vec_6450 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_6451);
												mem_vec_6451 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
												vec_106 = _mm512_set1_ps(scal_33);


												vec_105 = _mm512_fmadd_ps(vec_106, vec_84, mem_vec_6452);
												mem_vec_6452 = vec_105;



												vec_107 = _mm512_fmadd_ps(vec_106, vec_86, mem_vec_6453);
												mem_vec_6453 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
												vec_109 = _mm512_set1_ps(scal_34);


												vec_108 = _mm512_fmadd_ps(vec_109, vec_84, mem_vec_6454);
												mem_vec_6454 = vec_108;



												vec_110 = _mm512_fmadd_ps(vec_109, vec_86, mem_vec_6455);
												mem_vec_6455 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
												vec_112 = _mm512_set1_ps(scal_35);


												vec_111 = _mm512_fmadd_ps(vec_112, vec_84, mem_vec_6456);
												mem_vec_6456 = vec_111;



												vec_113 = _mm512_fmadd_ps(vec_112, vec_86, mem_vec_6457);
												mem_vec_6457 = vec_113;
												scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
												vec_115 = _mm512_set1_ps(scal_36);


												vec_114 = _mm512_fmadd_ps(vec_115, vec_84, mem_vec_6458);
												mem_vec_6458 = vec_114;



												vec_116 = _mm512_fmadd_ps(vec_115, vec_86, mem_vec_6459);
												mem_vec_6459 = vec_116;
												scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
												vec_118 = _mm512_set1_ps(scal_37);


												vec_117 = _mm512_fmadd_ps(vec_118, vec_84, mem_vec_6460);
												mem_vec_6460 = vec_117;



												vec_119 = _mm512_fmadd_ps(vec_118, vec_86, mem_vec_6461);
												mem_vec_6461 = vec_119;
												scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h) + c];
												vec_121 = _mm512_set1_ps(scal_38);


												vec_120 = _mm512_fmadd_ps(vec_121, vec_84, mem_vec_6462);
												mem_vec_6462 = vec_120;



												vec_122 = _mm512_fmadd_ps(vec_121, vec_86, mem_vec_6463);
												mem_vec_6463 = vec_122;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6438);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6439);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6440);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6441);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6442);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6443);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6444);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6445);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6446);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6447);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6448);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6449);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6450);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6451);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6452);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6453);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6454);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6455);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6456);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6457);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6458);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6459);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6460);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6461);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6462);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_6463);
								}
							}
						}
					}
				}
		}
	}
}


}