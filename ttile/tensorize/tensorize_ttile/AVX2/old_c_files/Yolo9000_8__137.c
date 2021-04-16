#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (3, w);
  T (17, x); T (8, c); T (16, f); T (1, c); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (2, c)]
*/
IND_TYPE c, cp_0, c477_p_0, c478_p_0, c479_p_0, cp_1, c477_p_1, c478_p_1, cp_2, c477_p_2, cp_3, c477, c478, c479, f, fp_0, w, wp_0, x, xp_0, x327_p_0, xp_1, x327, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y218 = 0;
IND_TYPE x328 = 0;
IND_TYPE h = 0;
IND_TYPE w182 = 0;
IND_TYPE c480 = 0;
IND_TYPE f286 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3162 ,mem_vec_3163 ,mem_vec_3164 ,mem_vec_3165 ,mem_vec_3166 ,mem_vec_3167 ,mem_vec_3168 ,mem_vec_3169 ,mem_vec_3170 ,mem_vec_3171 ,mem_vec_3172 ,mem_vec_3173 ,mem_vec_3174 ,mem_vec_3175 ,mem_vec_3176 ,mem_vec_3177 ,mem_vec_3178 ,mem_vec_3179 ,mem_vec_3180 ,mem_vec_3181 ,mem_vec_3182 ,mem_vec_3183 ,mem_vec_3184 ,mem_vec_3185 ,mem_vec_3186 ,mem_vec_3187 ,mem_vec_3188 ,mem_vec_3189 ,mem_vec_3190 ,mem_vec_3191 ,mem_vec_3192 ,mem_vec_3193 ,mem_vec_3194 ,mem_vec_3195 ,mem_vec_3196 ,mem_vec_3197 ,mem_vec_3198 ,mem_vec_3199 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 2) (128 / 64)
for (c479 = c480, c479_p_0 = 0;
	c479 < c480 + 128;
	c479 += 64, c479_p_0 += 64){
		for (y = y218, yp_0 = 0;
			y < y218 + 18;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 256
			// T (x, 4) (68 / 17)
			for (x327 = x328, x327_p_0 = 0;
				x327 < x328 + 68;
				x327 += 17, x327_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 256
				// T (c, 1) (64 / 64)
				for (c478 = c479, c478_p_1 = c479_p_0, c478_p_0 = 0;
					c478 < c479 + 64;
					c478 += 64, c478_p_1 += 64, c478_p_0 += 64){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 256
					// T (f, 16) (256 / 16)
					for (f = f286, fp_0 = 0;
						f < f286 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 8) (64 / 8)
						for (c477 = c478, c477_p_2 = c478_p_1, c477_p_1 = c478_p_0, c477_p_0 = 0;
							c477 < c478 + 64;
							c477 += 8, c477_p_2 += 8, c477_p_1 += 8, c477_p_0 += 8){
							// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
							// T (x, 17) (17 / 1)
							for (x = x327, xp_1 = x327_p_0, xp_0 = 0;
								x < x327 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
								// T (w, 3) (3 / 1)
								for (w = w182, wp_0 = 0;
									w < w182 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3162 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3163 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_3172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_3174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_3176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_3178 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3179 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c477, cp_3 = c477_p_2, cp_2 = c477_p_1, cp_1 = c477_p_0, cp_0 = 0;
												c < c477 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3162);
												mem_vec_3162 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3163);
												mem_vec_3163 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3164);
												mem_vec_3164 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3165);
												mem_vec_3165 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3166);
												mem_vec_3166 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3167);
												mem_vec_3167 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3168);
												mem_vec_3168 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3169);
												mem_vec_3169 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3170);
												mem_vec_3170 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3171);
												mem_vec_3171 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3172);
												mem_vec_3172 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3173);
												mem_vec_3173 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3174);
												mem_vec_3174 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3175);
												mem_vec_3175 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3176);
												mem_vec_3176 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3177);
												mem_vec_3177 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3178);
												mem_vec_3178 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3179);
												mem_vec_3179 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm256_set1_ps(scal_9);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_3162);
												mem_vec_3162 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_3163);
												mem_vec_3163 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_3164);
												mem_vec_3164 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_3165);
												mem_vec_3165 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_3166);
												mem_vec_3166 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_3167);
												mem_vec_3167 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_3168);
												mem_vec_3168 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_3169);
												mem_vec_3169 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_3170);
												mem_vec_3170 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_3171);
												mem_vec_3171 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_3172);
												mem_vec_3172 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_3173);
												mem_vec_3173 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_3174);
												mem_vec_3174 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_3175);
												mem_vec_3175 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_3176);
												mem_vec_3176 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_3177);
												mem_vec_3177 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_3178);
												mem_vec_3178 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_3179);
												mem_vec_3179 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm256_set1_ps(scal_18);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_3162);
												mem_vec_3162 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_3163);
												mem_vec_3163 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_3164);
												mem_vec_3164 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_3165);
												mem_vec_3165 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_3166);
												mem_vec_3166 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_3167);
												mem_vec_3167 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_3168);
												mem_vec_3168 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_3169);
												mem_vec_3169 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_3170);
												mem_vec_3170 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_3171);
												mem_vec_3171 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_3172);
												mem_vec_3172 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_3173);
												mem_vec_3173 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_3174);
												mem_vec_3174 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_3175);
												mem_vec_3175 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_3176);
												mem_vec_3176 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_3177);
												mem_vec_3177 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_3178);
												mem_vec_3178 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_3179);
												mem_vec_3179 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3162);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3163);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3164);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3165);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3166);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3167);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3168);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3169);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3170);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3171);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3172);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3173);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3174);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3175);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3176);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3177);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3178);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3179);
								}
							}
						}
					}
				}
			}
		}
		for (y = y218 + 18, yp_0 = 0;
			y < y218 + 18 + 50;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 256
			// T (x, 4) (68 / 17)
			for (x327 = x328, x327_p_0 = 0;
				x327 < x328 + 68;
				x327 += 17, x327_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 256
				// T (c, 1) (64 / 64)
				for (c478 = c479, c478_p_1 = c479_p_0, c478_p_0 = 0;
					c478 < c479 + 64;
					c478 += 64, c478_p_1 += 64, c478_p_0 += 64){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 256
					// T (f, 16) (256 / 16)
					for (f = f286, fp_0 = 0;
						f < f286 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 16
						// T (c, 8) (64 / 8)
						for (c477 = c478, c477_p_2 = c478_p_1, c477_p_1 = c478_p_0, c477_p_0 = 0;
							c477 < c478 + 64;
							c477 += 8, c477_p_2 += 8, c477_p_1 += 8, c477_p_0 += 8){
							// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
							// T (x, 17) (17 / 1)
							for (x = x327, xp_1 = x327_p_0, xp_0 = 0;
								x < x327 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
								// T (w, 3) (3 / 1)
								for (w = w182, wp_0 = 0;
									w < w182 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3180 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3181 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_3182 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3183 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_3184 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3185 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_3186 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3187 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_3188 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3189 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_3190 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3191 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_3192 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3193 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_3194 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3195 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_3196 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3197 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_3198 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3199 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c477, cp_3 = c477_p_2, cp_2 = c477_p_1, cp_1 = c477_p_0, cp_0 = 0;
												c < c477 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3180);
												mem_vec_3180 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3181);
												mem_vec_3181 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3182);
												mem_vec_3182 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3183);
												mem_vec_3183 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3184);
												mem_vec_3184 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3185);
												mem_vec_3185 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3186);
												mem_vec_3186 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3187);
												mem_vec_3187 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3188);
												mem_vec_3188 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3189);
												mem_vec_3189 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3190);
												mem_vec_3190 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3191);
												mem_vec_3191 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3192);
												mem_vec_3192 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3193);
												mem_vec_3193 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3194);
												mem_vec_3194 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3195);
												mem_vec_3195 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3196);
												mem_vec_3196 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3197);
												mem_vec_3197 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3198);
												mem_vec_3198 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3199);
												mem_vec_3199 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_33 = _mm256_set1_ps(scal_10);
												vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_3180);
												mem_vec_3180 = vec_32;

												vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_3181);
												mem_vec_3181 = vec_35;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_3182);
												mem_vec_3182 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_3183);
												mem_vec_3183 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_3184);
												mem_vec_3184 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_3185);
												mem_vec_3185 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_3186);
												mem_vec_3186 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_3187);
												mem_vec_3187 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_3188);
												mem_vec_3188 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_3189);
												mem_vec_3189 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_3190);
												mem_vec_3190 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_3191);
												mem_vec_3191 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_3192);
												mem_vec_3192 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_3193);
												mem_vec_3193 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_3194);
												mem_vec_3194 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_3195);
												mem_vec_3195 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_3196);
												mem_vec_3196 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_3197);
												mem_vec_3197 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_3198);
												mem_vec_3198 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_3199);
												mem_vec_3199 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_65 = _mm256_set1_ps(scal_20);
												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_3180);
												mem_vec_3180 = vec_64;

												vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_3181);
												mem_vec_3181 = vec_67;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_3182);
												mem_vec_3182 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_3183);
												mem_vec_3183 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_3184);
												mem_vec_3184 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_3185);
												mem_vec_3185 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_3186);
												mem_vec_3186 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_3187);
												mem_vec_3187 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_3188);
												mem_vec_3188 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_3189);
												mem_vec_3189 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_3190);
												mem_vec_3190 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_3191);
												mem_vec_3191 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_3192);
												mem_vec_3192 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_3193);
												mem_vec_3193 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_3194);
												mem_vec_3194 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_3195);
												mem_vec_3195 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_3196);
												mem_vec_3196 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_3197);
												mem_vec_3197 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_3198);
												mem_vec_3198 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_3199);
												mem_vec_3199 = vec_95;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3180);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3181);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3182);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3183);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3184);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3185);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3186);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3187);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3188);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3189);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3190);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3191);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3192);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3193);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3194);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3195);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3196);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3197);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3198);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_3199);
								}
							}
						}
					}
				}
			}
		}
}


}