#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (8, f); T (16, c); T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c81_p_0, cp_1, c81, f, fp_0, f108_p_0, f109_p_0, fp_1, f108_p_1, fp_2, f108, f109, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y54 = 0;
IND_TYPE x54 = 0;
IND_TYPE h42 = 0;
IND_TYPE w46 = 0;
IND_TYPE c82 = 0;
IND_TYPE f110 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1060 ,mem_vec_1061 ,mem_vec_1062 ,mem_vec_1063 ,mem_vec_1064 ,mem_vec_1065 ,mem_vec_1066 ,mem_vec_1067 ,mem_vec_1068 ,mem_vec_1069 ,mem_vec_1070 ,mem_vec_1071 ,mem_vec_1072 ,mem_vec_1073 ,mem_vec_1074 ,mem_vec_1075 ,mem_vec_1076 ,mem_vec_1077 ,mem_vec_1078 ,mem_vec_1079 ,mem_vec_1080 ,mem_vec_1081 ,mem_vec_1082 ,mem_vec_1083 ,mem_vec_1084 ,mem_vec_1085 ,mem_vec_1086 ,mem_vec_1087 ,mem_vec_1088 ,mem_vec_1089 ,mem_vec_1090 ,mem_vec_1091 ,mem_vec_1092 ,mem_vec_1093 ,mem_vec_1094 ,mem_vec_1095 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 4) (1024 / 256)
for (f109 = f110, f109_p_0 = 0;
	f109 < f110 + 1024;
	f109 += 256, f109_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
	// T (f, 1) (256 / 256)
	for (f108 = f109, f108_p_1 = f109_p_0, f108_p_0 = 0;
		f108 < f109 + 256;
		f108 += 256, f108_p_1 += 256, f108_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 256
		// T (c, 16) (512 / 32)
		for (c81 = c82, c81_p_0 = 0;
			c81 < c82 + 512;
			c81 += 32, c81_p_0 += 32){
			// y = 17, x = 17, h = 3, w = 3, c = 32, f = 256
			// T (f, 8) (256 / 32)
			for (f = f108, fp_2 = f108_p_1, fp_1 = f108_p_0, fp_0 = 0;
				f < f108 + 256;
				f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					for (y = y54, yp_0 = 0;
						y < y54 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x54, xp_0 = 0;
							x < x54 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h42, hp_0 = 0;
								h < h42 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w46, wp_0 = 0;
									w < w46 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1060 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1061 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1062 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1063 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
												c < c81 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1060);
												mem_vec_1060 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1061);
												mem_vec_1061 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1062);
												mem_vec_1062 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1063);
												mem_vec_1063 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1064);
												mem_vec_1064 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1065);
												mem_vec_1065 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1066);
												mem_vec_1066 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1067);
												mem_vec_1067 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1068);
												mem_vec_1068 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1069);
												mem_vec_1069 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1070);
												mem_vec_1070 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1071);
												mem_vec_1071 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1072);
												mem_vec_1072 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1073);
												mem_vec_1073 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1074);
												mem_vec_1074 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1075);
												mem_vec_1075 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1060);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1061);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1062);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1063);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1064);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1065);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1066);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1067);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1068);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1069);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1070);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1071);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1072);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1073);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1074);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1075);
								}
							}
						}
					}
					for (y = y54 + 12, yp_0 = 0;
						y < y54 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x54, xp_0 = 0;
							x < x54 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h42, hp_0 = 0;
								h < h42 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w46, wp_0 = 0;
									w < w46 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1076 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1077 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1078 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1079 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_1080 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1081 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1082 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1083 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_1084 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1085 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1086 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1087 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_1088 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1089 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1090 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1091 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_1092 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1093 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1094 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1095 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c81, cp_1 = c81_p_0, cp_0 = 0;
												c < c81 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1076);
												mem_vec_1076 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1077);
												mem_vec_1077 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1078);
												mem_vec_1078 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1079);
												mem_vec_1079 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1080);
												mem_vec_1080 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1081);
												mem_vec_1081 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1082);
												mem_vec_1082 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1083);
												mem_vec_1083 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1084);
												mem_vec_1084 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1085);
												mem_vec_1085 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1086);
												mem_vec_1086 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1087);
												mem_vec_1087 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1088);
												mem_vec_1088 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1089);
												mem_vec_1089 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1090);
												mem_vec_1090 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1091);
												mem_vec_1091 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1092);
												mem_vec_1092 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1093);
												mem_vec_1093 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1094);
												mem_vec_1094 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1095);
												mem_vec_1095 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1076);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1077);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1078);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1079);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1080);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1081);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1082);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1083);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1084);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1085);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1086);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1087);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1088);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1089);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1090);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1091);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1092);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1093);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1094);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1095);
								}
							}
						}
					}
			}
		}
	}
}


}