#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (16, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, f);
  T (128, c); T (1, f)]
*/
IND_TYPE c, cp_0, c444_p_0, cp_1, c444, f, fp_0, f592_p_0, f593_p_0, fp_1, f592_p_1, fp_2, f592, f593, w, wp_0, x, xp_0, x444_p_0, xp_1, x444, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y296 = 0;
IND_TYPE x445 = 0;
IND_TYPE h = 0;
IND_TYPE w296 = 0;
IND_TYPE c445 = 0;
IND_TYPE f594 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_5188 ,mem_vec_5189 ,mem_vec_5190 ,mem_vec_5191 ,mem_vec_5192 ,mem_vec_5193 ,mem_vec_5194 ,mem_vec_5195 ,mem_vec_5196 ,mem_vec_5197 ,mem_vec_5198 ,mem_vec_5199 ,mem_vec_5200 ,mem_vec_5201 ,mem_vec_5202 ,mem_vec_5203 ,mem_vec_5204 ,mem_vec_5205 ,mem_vec_5206 ,mem_vec_5207 ,mem_vec_5208 ,mem_vec_5209 ,mem_vec_5210 ,mem_vec_5211 ,mem_vec_5212 ,mem_vec_5213 ,mem_vec_5214 ,mem_vec_5215 ,mem_vec_5216 ,mem_vec_5217 ,mem_vec_5218 ,mem_vec_5219 ,mem_vec_5220 ,mem_vec_5221 ,mem_vec_5222 ,mem_vec_5223 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f593 = f594, f593_p_0 = 0;
	f593 < f594 + 1024;
	f593 += 1024, f593_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 128) (512 / 4)
	for (c444 = c445, c444_p_0 = 0;
		c444 < c445 + 512;
		c444 += 4, c444_p_0 += 4){
		// y = 17, x = 17, h = 3, w = 3, c = 4, f = 1024
		// T (f, 2) (1024 / 512)
		for (f592 = f593, f592_p_1 = f593_p_0, f592_p_0 = 0;
			f592 < f593 + 1024;
			f592 += 512, f592_p_1 += 512, f592_p_0 += 512){
				for (y = y296, yp_0 = 0;
					y < y296 + 12;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 512
					// T (x, 17) (17 / 1)
					for (x444 = x445, x444_p_0 = 0;
						x444 < x445 + 17;
						x444 += 1, x444_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 512
						// T (f, 16) (512 / 32)
						for (f = f592, fp_2 = f592_p_1, fp_1 = f592_p_0, fp_0 = 0;
							f < f592 + 512;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w296, wp_0 = 0;
								w < w296 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
								// T (x, 1) (1 / 1)
								for (x = x444, xp_1 = x444_p_0, xp_0 = 0;
									x < x444 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5188 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5189 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5190 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5191 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5192 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5193 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5194 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5195 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5196 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5197 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5198 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5199 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5200 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5201 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5202 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5203 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c444, cp_1 = c444_p_0, cp_0 = 0;
												c < c444 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5188);
												mem_vec_5188 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5189);
												mem_vec_5189 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5190);
												mem_vec_5190 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5191);
												mem_vec_5191 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5192);
												mem_vec_5192 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5193);
												mem_vec_5193 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5194);
												mem_vec_5194 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5195);
												mem_vec_5195 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5196);
												mem_vec_5196 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5197);
												mem_vec_5197 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5198);
												mem_vec_5198 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5199);
												mem_vec_5199 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5200);
												mem_vec_5200 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5201);
												mem_vec_5201 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5202);
												mem_vec_5202 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5203);
												mem_vec_5203 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_5188);
												mem_vec_5188 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_5189);
												mem_vec_5189 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_5190);
												mem_vec_5190 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_5191);
												mem_vec_5191 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_5192);
												mem_vec_5192 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_5193);
												mem_vec_5193 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_5194);
												mem_vec_5194 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_5195);
												mem_vec_5195 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_5196);
												mem_vec_5196 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_5197);
												mem_vec_5197 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_5198);
												mem_vec_5198 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_5199);
												mem_vec_5199 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_5200);
												mem_vec_5200 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_5201);
												mem_vec_5201 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_5202);
												mem_vec_5202 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_5203);
												mem_vec_5203 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_5188);
												mem_vec_5188 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_5189);
												mem_vec_5189 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_5190);
												mem_vec_5190 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_5191);
												mem_vec_5191 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_5192);
												mem_vec_5192 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_5193);
												mem_vec_5193 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_5194);
												mem_vec_5194 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_5195);
												mem_vec_5195 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_5196);
												mem_vec_5196 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_5197);
												mem_vec_5197 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_5198);
												mem_vec_5198 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_5199);
												mem_vec_5199 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_5200);
												mem_vec_5200 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_5201);
												mem_vec_5201 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_5202);
												mem_vec_5202 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_5203);
												mem_vec_5203 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5188);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5189);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5190);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5191);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5192);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5193);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5194);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5195);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5196);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5197);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5198);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5199);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5200);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5201);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5202);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5203);
								}
							}
						}
					}
				}
				for (y = y296 + 12, yp_0 = 0;
					y < y296 + 12 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 512
					// T (x, 17) (17 / 1)
					for (x444 = x445, x444_p_0 = 0;
						x444 < x445 + 17;
						x444 += 1, x444_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 512
						// T (f, 16) (512 / 32)
						for (f = f592, fp_2 = f592_p_1, fp_1 = f592_p_0, fp_0 = 0;
							f < f592 + 512;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w296, wp_0 = 0;
								w < w296 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
								// T (x, 1) (1 / 1)
								for (x = x444, xp_1 = x444_p_0, xp_0 = 0;
									x < x444 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5204 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5205 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_5206 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5207 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_5208 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5209 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_5210 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5211 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_5212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_5214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_5216 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5217 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_5218 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5219 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_5220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_5222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c444, cp_1 = c444_p_0, cp_0 = 0;
												c < c444 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_5204);
												mem_vec_5204 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_5205);
												mem_vec_5205 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_5206);
												mem_vec_5206 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_5207);
												mem_vec_5207 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_5208);
												mem_vec_5208 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_5209);
												mem_vec_5209 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_5210);
												mem_vec_5210 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_5211);
												mem_vec_5211 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_5212);
												mem_vec_5212 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_5213);
												mem_vec_5213 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_5214);
												mem_vec_5214 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_5215);
												mem_vec_5215 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_5216);
												mem_vec_5216 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_5217);
												mem_vec_5217 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_5218);
												mem_vec_5218 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_5219);
												mem_vec_5219 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_5220);
												mem_vec_5220 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_5221);
												mem_vec_5221 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_5222);
												mem_vec_5222 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_5223);
												mem_vec_5223 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_5204);
												mem_vec_5204 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_5205);
												mem_vec_5205 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_5206);
												mem_vec_5206 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_5207);
												mem_vec_5207 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_5208);
												mem_vec_5208 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_5209);
												mem_vec_5209 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_5210);
												mem_vec_5210 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_5211);
												mem_vec_5211 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_5212);
												mem_vec_5212 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_5213);
												mem_vec_5213 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_5214);
												mem_vec_5214 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_5215);
												mem_vec_5215 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_5216);
												mem_vec_5216 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_5217);
												mem_vec_5217 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_5218);
												mem_vec_5218 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_5219);
												mem_vec_5219 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_5220);
												mem_vec_5220 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_5221);
												mem_vec_5221 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_5222);
												mem_vec_5222 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_5223);
												mem_vec_5223 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_5204);
												mem_vec_5204 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_5205);
												mem_vec_5205 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_5206);
												mem_vec_5206 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_5207);
												mem_vec_5207 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_5208);
												mem_vec_5208 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_5209);
												mem_vec_5209 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_5210);
												mem_vec_5210 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_5211);
												mem_vec_5211 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_5212);
												mem_vec_5212 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_5213);
												mem_vec_5213 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_5214);
												mem_vec_5214 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_5215);
												mem_vec_5215 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_5216);
												mem_vec_5216 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_5217);
												mem_vec_5217 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_5218);
												mem_vec_5218 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_5219);
												mem_vec_5219 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_5220);
												mem_vec_5220 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_5221);
												mem_vec_5221 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_5222);
												mem_vec_5222 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_5223);
												mem_vec_5223 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5204);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_5205);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5206);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_5207);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5208);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_5209);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5210);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_5211);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5212);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_5213);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5214);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_5215);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5216);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_5217);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5218);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_5219);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5220);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_5221);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5222);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_5223);
								}
							}
						}
					}
				}
		}
	}
}


}