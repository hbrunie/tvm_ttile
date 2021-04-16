#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (4, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (8, f);
  T (2, x); T (8, y); T (4, x)]
*/
IND_TYPE c, cp_0, c558_p_0, cp_1, c558, f, fp_0, w, wp_0, x, xp_0, x744_p_0, x745_p_0, xp_1, x744_p_1, xp_2, x744, x745, y, yp_0, y515_p_0, yp_1, y515;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y516 = 0;
IND_TYPE x746 = 0;
IND_TYPE h = 0;
IND_TYPE w357 = 0;
IND_TYPE c559 = 0;
IND_TYPE f415 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6220 ,mem_vec_6221 ,mem_vec_6222 ,mem_vec_6223 ,mem_vec_6224 ,mem_vec_6225 ,mem_vec_6226 ,mem_vec_6227 ,mem_vec_6228 ,mem_vec_6229 ,mem_vec_6230 ,mem_vec_6231 ,mem_vec_6232 ,mem_vec_6233 ,mem_vec_6234 ,mem_vec_6235 ,mem_vec_6236 ,mem_vec_6237 ,mem_vec_6238 ,mem_vec_6239 ,mem_vec_6240 ,mem_vec_6241 ,mem_vec_6242 ,mem_vec_6243 ,mem_vec_6244 ,mem_vec_6245 ,mem_vec_6246 ,mem_vec_6247 ,mem_vec_6248 ,mem_vec_6249 ,mem_vec_6250 ,mem_vec_6251 ,mem_vec_6252 ,mem_vec_6253 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 4) (136 / 34)
for (x745 = x746, x745_p_0 = 0;
	x745 < x746 + 136;
	x745 += 34, x745_p_0 += 34){
	// y = 136, x = 34, h = 3, w = 3, c = 64, f = 128
	// T (y, 8) (136 / 17)
	for (y515 = y516, y515_p_0 = 0;
		y515 < y516 + 136;
		y515 += 17, y515_p_0 += 17){
		// y = 17, x = 34, h = 3, w = 3, c = 64, f = 128
		// T (x, 2) (34 / 17)
		for (x744 = x745, x744_p_1 = x745_p_0, x744_p_0 = 0;
			x744 < x745 + 34;
			x744 += 17, x744_p_1 += 17, x744_p_0 += 17){
			// y = 17, x = 17, h = 3, w = 3, c = 64, f = 128
			// T (f, 8) (128 / 16)
			for (f = f415, fp_0 = 0;
				f < f415 + 128;
				f += 16, fp_0 += 16){
					for (y = y515, yp_1 = y515_p_0, yp_0 = 0;
						y < y515 + 8;
						y += 8, yp_1 += 8, yp_0 += 8){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 4) (64 / 16)
						for (c558 = c559, c558_p_0 = 0;
							c558 < c559 + 64;
							c558 += 16, c558_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w357, wp_0 = 0;
								w < w357 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 16
								// T (x, 17) (17 / 1)
								for (x = x744, xp_2 = x744_p_1, xp_1 = x744_p_0, xp_0 = 0;
									x < x744 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6220 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6221 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6224 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6225 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6226 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6227 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_6232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_6234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c558, cp_1 = c558_p_0, cp_0 = 0;
												c < c558 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6220);
												mem_vec_6220 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6221);
												mem_vec_6221 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6222);
												mem_vec_6222 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6223);
												mem_vec_6223 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6224);
												mem_vec_6224 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6225);
												mem_vec_6225 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6226);
												mem_vec_6226 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6227);
												mem_vec_6227 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6228);
												mem_vec_6228 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6229);
												mem_vec_6229 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6230);
												mem_vec_6230 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6231);
												mem_vec_6231 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6232);
												mem_vec_6232 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6233);
												mem_vec_6233 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6234);
												mem_vec_6234 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6235);
												mem_vec_6235 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_6220);
												mem_vec_6220 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_6221);
												mem_vec_6221 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_6222);
												mem_vec_6222 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_6223);
												mem_vec_6223 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_6224);
												mem_vec_6224 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_6225);
												mem_vec_6225 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_6226);
												mem_vec_6226 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_6227);
												mem_vec_6227 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_6228);
												mem_vec_6228 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_6229);
												mem_vec_6229 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6230);
												mem_vec_6230 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6231);
												mem_vec_6231 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_6232);
												mem_vec_6232 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_6233);
												mem_vec_6233 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_6234);
												mem_vec_6234 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_6235);
												mem_vec_6235 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_6220);
												mem_vec_6220 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_6221);
												mem_vec_6221 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6222);
												mem_vec_6222 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6223);
												mem_vec_6223 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_6224);
												mem_vec_6224 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_6225);
												mem_vec_6225 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_6226);
												mem_vec_6226 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_6227);
												mem_vec_6227 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_6228);
												mem_vec_6228 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_6229);
												mem_vec_6229 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_6230);
												mem_vec_6230 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_6231);
												mem_vec_6231 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_6232);
												mem_vec_6232 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_6233);
												mem_vec_6233 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_6234);
												mem_vec_6234 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_6235);
												mem_vec_6235 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6220);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6221);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6222);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6223);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6224);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6225);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6226);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6227);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6228);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6229);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6230);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6231);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6232);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6233);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6234);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6235);
								}
							}
						}
					}
					for (y = y515 + 8, yp_1 = y515_p_0, yp_0 = 0;
						y < y515 + 8 + 9;
						y += 9, yp_1 += 9, yp_0 += 9){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 4) (64 / 16)
						for (c558 = c559, c558_p_0 = 0;
							c558 < c559 + 64;
							c558 += 16, c558_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 16
							// T (w, 3) (3 / 1)
							for (w = w357, wp_0 = 0;
								w < w357 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 16
								// T (x, 17) (17 / 1)
								for (x = x744, xp_2 = x744_p_1, xp_1 = x744_p_0, xp_0 = 0;
									x < x744 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6236 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6237 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_6238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_6240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_6242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_6244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_6246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_6248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_6250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_6252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c558, cp_1 = c558_p_0, cp_0 = 0;
												c < c558 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6236);
												mem_vec_6236 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6237);
												mem_vec_6237 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_6238);
												mem_vec_6238 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_6239);
												mem_vec_6239 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_6240);
												mem_vec_6240 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_6241);
												mem_vec_6241 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_6242);
												mem_vec_6242 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_6243);
												mem_vec_6243 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6244);
												mem_vec_6244 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6245);
												mem_vec_6245 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_6246);
												mem_vec_6246 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_6247);
												mem_vec_6247 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_6248);
												mem_vec_6248 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_6249);
												mem_vec_6249 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_6250);
												mem_vec_6250 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_6251);
												mem_vec_6251 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_6252);
												mem_vec_6252 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_6253);
												mem_vec_6253 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_6236);
												mem_vec_6236 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_6237);
												mem_vec_6237 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_6238);
												mem_vec_6238 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_6239);
												mem_vec_6239 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_6240);
												mem_vec_6240 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_6241);
												mem_vec_6241 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_6242);
												mem_vec_6242 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_6243);
												mem_vec_6243 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_6244);
												mem_vec_6244 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_6245);
												mem_vec_6245 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_6246);
												mem_vec_6246 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_6247);
												mem_vec_6247 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_6248);
												mem_vec_6248 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_6249);
												mem_vec_6249 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_6250);
												mem_vec_6250 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_6251);
												mem_vec_6251 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_6252);
												mem_vec_6252 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_6253);
												mem_vec_6253 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_6236);
												mem_vec_6236 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_6237);
												mem_vec_6237 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_6238);
												mem_vec_6238 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_6239);
												mem_vec_6239 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_6240);
												mem_vec_6240 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_6241);
												mem_vec_6241 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_6242);
												mem_vec_6242 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_6243);
												mem_vec_6243 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_6244);
												mem_vec_6244 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_6245);
												mem_vec_6245 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_6246);
												mem_vec_6246 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_6247);
												mem_vec_6247 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_6248);
												mem_vec_6248 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_6249);
												mem_vec_6249 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_6250);
												mem_vec_6250 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_6251);
												mem_vec_6251 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_6252);
												mem_vec_6252 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_6253);
												mem_vec_6253 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6236);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6237);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6238);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6239);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6240);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6241);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6242);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6243);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6244);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6245);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6246);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6247);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6248);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6249);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6250);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_6251);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6252);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_6253);
								}
							}
						}
					}
			}
		}
	}
}


}