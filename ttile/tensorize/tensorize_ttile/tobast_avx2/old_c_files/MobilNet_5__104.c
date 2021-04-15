#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (2, f); T (7, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (16, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1044_p_0, cp_1, c1044, f, fp_0, f1132_p_0, f1133_p_0, fp_1, f1132_p_1, fp_2, f1132, f1133, w, wp_0, x, xp_0, x1288_p_0, x1289_p_0, xp_1, x1288_p_1, xp_2, x1288, x1289, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y644 = 0;
IND_TYPE x1290 = 0;
IND_TYPE h = 0;
IND_TYPE w540 = 0;
IND_TYPE c1045 = 0;
IND_TYPE f1134 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8548 ,mem_vec_8549 ,mem_vec_8550 ,mem_vec_8551 ,mem_vec_8552 ,mem_vec_8553 ,mem_vec_8554 ,mem_vec_8555 ,mem_vec_8556 ,mem_vec_8557 ,mem_vec_8558 ,mem_vec_8559 ,mem_vec_8560 ,mem_vec_8561 ,mem_vec_8562 ,mem_vec_8563 ,mem_vec_8564 ,mem_vec_8565 ,mem_vec_8566 ,mem_vec_8567 ,mem_vec_8568 ,mem_vec_8569 ,mem_vec_8570 ,mem_vec_8571 ,mem_vec_8572 ,mem_vec_8573 ,mem_vec_8574 ,mem_vec_8575 ,mem_vec_8576 ,mem_vec_8577 ,mem_vec_8578 ,mem_vec_8579 ,mem_vec_8580 ,mem_vec_8581 ,mem_vec_8582 ,mem_vec_8583 ,mem_vec_8584 ,mem_vec_8585 ,mem_vec_8586 ,mem_vec_8587 ,mem_vec_8588 ,mem_vec_8589 ,mem_vec_8590 ,mem_vec_8591 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1133 = f1134, f1133_p_0 = 0;
	f1133 < f1134 + 256;
	f1133 += 256, f1133_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 1) (28 / 28)
	for (x1289 = x1290, x1289_p_0 = 0;
		x1289 < x1290 + 28;
		x1289 += 28, x1289_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (c, 16) (256 / 16)
		for (c1044 = c1045, c1044_p_0 = 0;
			c1044 < c1045 + 256;
			c1044 += 16, c1044_p_0 += 16){
			// y = 28, x = 28, h = 3, w = 3, c = 16, f = 256
			// T (f, 4) (256 / 64)
			for (f1132 = f1133, f1132_p_1 = f1133_p_0, f1132_p_0 = 0;
				f1132 < f1133 + 256;
				f1132 += 64, f1132_p_1 += 64, f1132_p_0 += 64){
					for (y = y644, yp_0 = 0;
						y < y644 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 64
						// T (x, 7) (28 / 4)
						for (x1288 = x1289, x1288_p_1 = x1289_p_0, x1288_p_0 = 0;
							x1288 < x1289 + 28;
							x1288 += 4, x1288_p_1 += 4, x1288_p_0 += 4){
							// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1132, fp_2 = f1132_p_1, fp_1 = f1132_p_0, fp_0 = 0;
								f < f1132 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w540, wp_0 = 0;
									w < w540 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 16, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1288, xp_2 = x1288_p_1, xp_1 = x1288_p_0, xp_0 = 0;
										x < x1288 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8548 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8549 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8550 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8551 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8552 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8553 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8554 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8555 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1044, cp_1 = c1044_p_0, cp_0 = 0;
													c < c1044 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8548);
													mem_vec_8548 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8549);
													mem_vec_8549 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8550);
													mem_vec_8550 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8551);
													mem_vec_8551 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8552);
													mem_vec_8552 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8553);
													mem_vec_8553 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8554);
													mem_vec_8554 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8555);
													mem_vec_8555 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8556);
													mem_vec_8556 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8557);
													mem_vec_8557 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8558);
													mem_vec_8558 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8559);
													mem_vec_8559 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8560);
													mem_vec_8560 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8561);
													mem_vec_8561 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8562);
													mem_vec_8562 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8563);
													mem_vec_8563 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8564);
													mem_vec_8564 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8565);
													mem_vec_8565 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8566);
													mem_vec_8566 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8567);
													mem_vec_8567 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_8548);
													mem_vec_8548 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_8549);
													mem_vec_8549 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_8550);
													mem_vec_8550 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_8551);
													mem_vec_8551 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_8552);
													mem_vec_8552 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_8553);
													mem_vec_8553 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_8554);
													mem_vec_8554 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_8555);
													mem_vec_8555 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_8556);
													mem_vec_8556 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_8557);
													mem_vec_8557 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_8558);
													mem_vec_8558 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_8559);
													mem_vec_8559 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_8560);
													mem_vec_8560 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_8561);
													mem_vec_8561 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_8562);
													mem_vec_8562 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_8563);
													mem_vec_8563 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_8564);
													mem_vec_8564 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_8565);
													mem_vec_8565 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_8566);
													mem_vec_8566 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_8567);
													mem_vec_8567 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_8548);
													mem_vec_8548 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_8549);
													mem_vec_8549 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_8550);
													mem_vec_8550 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_8551);
													mem_vec_8551 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_8552);
													mem_vec_8552 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_8553);
													mem_vec_8553 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_8554);
													mem_vec_8554 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_8555);
													mem_vec_8555 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_8556);
													mem_vec_8556 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_8557);
													mem_vec_8557 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_8558);
													mem_vec_8558 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8559);
													mem_vec_8559 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_8560);
													mem_vec_8560 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_8561);
													mem_vec_8561 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_8562);
													mem_vec_8562 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_8563);
													mem_vec_8563 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_8564);
													mem_vec_8564 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_8565);
													mem_vec_8565 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_8566);
													mem_vec_8566 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_8567);
													mem_vec_8567 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8548);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8549);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8550);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8551);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8552);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8553);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8554);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8555);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8556);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8557);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8558);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8559);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8560);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8561);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8562);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8563);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8564);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8565);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8566);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8567);
									}
								}
							}
						}
					}
					for (y = y644 + 10, yp_0 = 0;
						y < y644 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 64
						// T (x, 7) (28 / 4)
						for (x1288 = x1289, x1288_p_1 = x1289_p_0, x1288_p_0 = 0;
							x1288 < x1289 + 28;
							x1288 += 4, x1288_p_1 += 4, x1288_p_0 += 4){
							// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1132, fp_2 = f1132_p_1, fp_1 = f1132_p_0, fp_0 = 0;
								f < f1132 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w540, wp_0 = 0;
									w < w540 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 16, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1288, xp_2 = x1288_p_1, xp_1 = x1288_p_0, xp_0 = 0;
										x < x1288 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8568 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8569 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8570 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8571 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8578 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8579 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8580 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8581 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8582 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8583 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_8588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_8590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1044, cp_1 = c1044_p_0, cp_0 = 0;
													c < c1044 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8568);
													mem_vec_8568 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8569);
													mem_vec_8569 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8570);
													mem_vec_8570 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8571);
													mem_vec_8571 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8572);
													mem_vec_8572 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8573);
													mem_vec_8573 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8574);
													mem_vec_8574 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8575);
													mem_vec_8575 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8576);
													mem_vec_8576 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8577);
													mem_vec_8577 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8578);
													mem_vec_8578 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8579);
													mem_vec_8579 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8580);
													mem_vec_8580 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8581);
													mem_vec_8581 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8582);
													mem_vec_8582 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8583);
													mem_vec_8583 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8584);
													mem_vec_8584 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8585);
													mem_vec_8585 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8586);
													mem_vec_8586 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8587);
													mem_vec_8587 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8588);
													mem_vec_8588 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8589);
													mem_vec_8589 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_8590);
													mem_vec_8590 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_8591);
													mem_vec_8591 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_8568);
													mem_vec_8568 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_8569);
													mem_vec_8569 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_8570);
													mem_vec_8570 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_8571);
													mem_vec_8571 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8572);
													mem_vec_8572 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_8573);
													mem_vec_8573 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_8574);
													mem_vec_8574 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_8575);
													mem_vec_8575 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_8576);
													mem_vec_8576 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_8577);
													mem_vec_8577 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_8578);
													mem_vec_8578 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_8579);
													mem_vec_8579 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_8580);
													mem_vec_8580 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_8581);
													mem_vec_8581 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_8582);
													mem_vec_8582 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_8583);
													mem_vec_8583 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8584);
													mem_vec_8584 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_8585);
													mem_vec_8585 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_8586);
													mem_vec_8586 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_8587);
													mem_vec_8587 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_8588);
													mem_vec_8588 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_8589);
													mem_vec_8589 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_8590);
													mem_vec_8590 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_8591);
													mem_vec_8591 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_8568);
													mem_vec_8568 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_8569);
													mem_vec_8569 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_8570);
													mem_vec_8570 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_8571);
													mem_vec_8571 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_8572);
													mem_vec_8572 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_8573);
													mem_vec_8573 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_8574);
													mem_vec_8574 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_8575);
													mem_vec_8575 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_8576);
													mem_vec_8576 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_8577);
													mem_vec_8577 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_8578);
													mem_vec_8578 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_8579);
													mem_vec_8579 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_8580);
													mem_vec_8580 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8581);
													mem_vec_8581 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8582);
													mem_vec_8582 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_8583);
													mem_vec_8583 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_8584);
													mem_vec_8584 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_8585);
													mem_vec_8585 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_8586);
													mem_vec_8586 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_8587);
													mem_vec_8587 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_8588);
													mem_vec_8588 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_8589);
													mem_vec_8589 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_8590);
													mem_vec_8590 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_8591);
													mem_vec_8591 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8568);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8569);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8570);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8571);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8572);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8573);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8574);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8575);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8576);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8577);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8578);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8579);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8580);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8581);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8582);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8583);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8584);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8585);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8586);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8587);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8588);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8589);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8590);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_8591);
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