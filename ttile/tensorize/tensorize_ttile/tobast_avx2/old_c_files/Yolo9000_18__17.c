#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (512, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (4, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (8, f);
  T (1, c); T (1, f)]
*/
IND_TYPE c, cp_0, c762_p_0, cp_1, c762, f, fp_0, f1016_p_0, f1017_p_0, fp_1, f1016_p_1, fp_2, f1016, f1017, h, hp_0, x, xp_0, x762_p_0, xp_1, x762, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y508 = 0;
IND_TYPE x763 = 0;
IND_TYPE h308 = 0;
IND_TYPE w = 0;
IND_TYPE c763 = 0;
IND_TYPE f1018 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10000 ,mem_vec_10001 ,mem_vec_10002 ,mem_vec_10003 ,mem_vec_10004 ,mem_vec_10005 ,mem_vec_10006 ,mem_vec_10007 ,mem_vec_10008 ,mem_vec_10009 ,mem_vec_10010 ,mem_vec_10011 ,mem_vec_10012 ,mem_vec_10013 ,mem_vec_10014 ,mem_vec_10015 ,mem_vec_10016 ,mem_vec_10017 ,mem_vec_10018 ,mem_vec_10019 ,mem_vec_10020 ,mem_vec_10021 ,mem_vec_10022 ,mem_vec_10023 ,mem_vec_9988 ,mem_vec_9989 ,mem_vec_9990 ,mem_vec_9991 ,mem_vec_9992 ,mem_vec_9993 ,mem_vec_9994 ,mem_vec_9995 ,mem_vec_9996 ,mem_vec_9997 ,mem_vec_9998 ,mem_vec_9999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f1017 = f1018, f1017_p_0 = 0;
	f1017 < f1018 + 1024;
	f1017 += 1024, f1017_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 1) (512 / 512)
	for (c762 = c763, c762_p_0 = 0;
		c762 < c763 + 512;
		c762 += 512, c762_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
		// T (f, 8) (1024 / 128)
		for (f1016 = f1017, f1016_p_1 = f1017_p_0, f1016_p_0 = 0;
			f1016 < f1017 + 1024;
			f1016 += 128, f1016_p_1 += 128, f1016_p_0 += 128){
				for (y = y508, yp_0 = 0;
					y < y508 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 128
					// T (x, 1) (17 / 17)
					for (x762 = x763, x762_p_0 = 0;
						x762 < x763 + 17;
						x762 += 17, x762_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1016, fp_2 = f1016_p_1, fp_1 = f1016_p_0, fp_0 = 0;
							f < f1016 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
							// T (h, 3) (3 / 1)
							for (h = h308, hp_0 = 0;
								h < h308 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 512, f = 32
								// T (x, 17) (17 / 1)
								for (x = x762, xp_1 = x762_p_0, xp_0 = 0;
									x < x762 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9988 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9989 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_9990 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9991 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_9992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_9994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_9996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_9998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_10000 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10001 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_10002 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_10003 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
												c < c762 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9988);
												mem_vec_9988 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9989);
												mem_vec_9989 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9990);
												mem_vec_9990 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9991);
												mem_vec_9991 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9992);
												mem_vec_9992 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9993);
												mem_vec_9993 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9994);
												mem_vec_9994 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9995);
												mem_vec_9995 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9996);
												mem_vec_9996 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9997);
												mem_vec_9997 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9998);
												mem_vec_9998 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9999);
												mem_vec_9999 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10000);
												mem_vec_10000 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10001);
												mem_vec_10001 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10002);
												mem_vec_10002 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10003);
												mem_vec_10003 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_9988);
												mem_vec_9988 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_9989);
												mem_vec_9989 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_9990);
												mem_vec_9990 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_9991);
												mem_vec_9991 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_9992);
												mem_vec_9992 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_9993);
												mem_vec_9993 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_9994);
												mem_vec_9994 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_9995);
												mem_vec_9995 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_9996);
												mem_vec_9996 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_9997);
												mem_vec_9997 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_9998);
												mem_vec_9998 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_9999);
												mem_vec_9999 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_10000);
												mem_vec_10000 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_10001);
												mem_vec_10001 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_10002);
												mem_vec_10002 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_10003);
												mem_vec_10003 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_9988);
												mem_vec_9988 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_9989);
												mem_vec_9989 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_9990);
												mem_vec_9990 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_9991);
												mem_vec_9991 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_9992);
												mem_vec_9992 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_9993);
												mem_vec_9993 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_9994);
												mem_vec_9994 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_9995);
												mem_vec_9995 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_9996);
												mem_vec_9996 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_9997);
												mem_vec_9997 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_9998);
												mem_vec_9998 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_9999);
												mem_vec_9999 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_10000);
												mem_vec_10000 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_10001);
												mem_vec_10001 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_10002);
												mem_vec_10002 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_10003);
												mem_vec_10003 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9988);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9989);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9990);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9991);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9992);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9993);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9994);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9995);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9996);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9997);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9998);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9999);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10000);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10001);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10002);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10003);
								}
							}
						}
					}
				}
				for (y = y508 + 12, yp_0 = 0;
					y < y508 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 128
					// T (x, 1) (17 / 17)
					for (x762 = x763, x762_p_0 = 0;
						x762 < x763 + 17;
						x762 += 17, x762_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 128
						// T (f, 4) (128 / 32)
						for (f = f1016, fp_2 = f1016_p_1, fp_1 = f1016_p_0, fp_0 = 0;
							f < f1016 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 32
							// T (h, 3) (3 / 1)
							for (h = h308, hp_0 = 0;
								h < h308 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 512, f = 32
								// T (x, 17) (17 / 1)
								for (x = x762, xp_1 = x762_p_0, xp_0 = 0;
									x < x762 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_10004 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_10005 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_10006 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_10007 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_10008 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_10009 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_10010 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_10011 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_10012 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_10013 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_10014 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_10015 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_10016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_10017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_10018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_10019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_10020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_10021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_10022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_10023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 512, f = 32
											// T (c, 512) (512 / 1)
											for (c = c762, cp_1 = c762_p_0, cp_0 = 0;
												c < c762 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10004);
												mem_vec_10004 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10005);
												mem_vec_10005 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10006);
												mem_vec_10006 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10007);
												mem_vec_10007 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10008);
												mem_vec_10008 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10009);
												mem_vec_10009 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10010);
												mem_vec_10010 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10011);
												mem_vec_10011 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10012);
												mem_vec_10012 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10013);
												mem_vec_10013 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10014);
												mem_vec_10014 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10015);
												mem_vec_10015 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10016);
												mem_vec_10016 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10017);
												mem_vec_10017 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10018);
												mem_vec_10018 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10019);
												mem_vec_10019 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10020);
												mem_vec_10020 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10021);
												mem_vec_10021 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10022);
												mem_vec_10022 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10023);
												mem_vec_10023 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_10004);
												mem_vec_10004 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_10005);
												mem_vec_10005 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_10006);
												mem_vec_10006 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_10007);
												mem_vec_10007 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_10008);
												mem_vec_10008 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_10009);
												mem_vec_10009 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_10010);
												mem_vec_10010 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_10011);
												mem_vec_10011 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_10012);
												mem_vec_10012 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_10013);
												mem_vec_10013 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_10014);
												mem_vec_10014 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10015);
												mem_vec_10015 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_10016);
												mem_vec_10016 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_10017);
												mem_vec_10017 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_10018);
												mem_vec_10018 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_10019);
												mem_vec_10019 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_10020);
												mem_vec_10020 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_10021);
												mem_vec_10021 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_10022);
												mem_vec_10022 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_10023);
												mem_vec_10023 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_10004);
												mem_vec_10004 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_10005);
												mem_vec_10005 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_10006);
												mem_vec_10006 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_10007);
												mem_vec_10007 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_10008);
												mem_vec_10008 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_10009);
												mem_vec_10009 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_10010);
												mem_vec_10010 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_10011);
												mem_vec_10011 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_10012);
												mem_vec_10012 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_10013);
												mem_vec_10013 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_10014);
												mem_vec_10014 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_10015);
												mem_vec_10015 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_10016);
												mem_vec_10016 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_10017);
												mem_vec_10017 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_10018);
												mem_vec_10018 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_10019);
												mem_vec_10019 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_10020);
												mem_vec_10020 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_10021);
												mem_vec_10021 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_10022);
												mem_vec_10022 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_10023);
												mem_vec_10023 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10004);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10005);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10006);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10007);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10008);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10009);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10010);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10011);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10012);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10013);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10014);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10015);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10016);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10017);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10018);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10019);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10020);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10021);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10022);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10023);
								}
							}
						}
					}
				}
		}
	}
}


}