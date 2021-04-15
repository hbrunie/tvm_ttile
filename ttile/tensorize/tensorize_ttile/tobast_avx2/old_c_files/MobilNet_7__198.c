#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (8, f);
  T (32, c); T (2, f)]
*/
IND_TYPE c, cp_0, c960_p_0, cp_1, c960, f, fp_0, f1280_p_0, f1281_p_0, fp_1, f1280_p_1, fp_2, f1280, f1281, h, hp_0, x, xp_0, x960_p_0, xp_1, x960, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y640 = 0;
IND_TYPE x961 = 0;
IND_TYPE h454 = 0;
IND_TYPE w = 0;
IND_TYPE c961 = 0;
IND_TYPE f1282 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11024 ,mem_vec_11025 ,mem_vec_11026 ,mem_vec_11027 ,mem_vec_11028 ,mem_vec_11029 ,mem_vec_11030 ,mem_vec_11031 ,mem_vec_11032 ,mem_vec_11033 ,mem_vec_11034 ,mem_vec_11035 ,mem_vec_11036 ,mem_vec_11037 ,mem_vec_11038 ,mem_vec_11039 ,mem_vec_11040 ,mem_vec_11041 ,mem_vec_11042 ,mem_vec_11043 ,mem_vec_11044 ,mem_vec_11045 ,mem_vec_11046 ,mem_vec_11047 ,mem_vec_11048 ,mem_vec_11049 ,mem_vec_11050 ,mem_vec_11051 ,mem_vec_11052 ,mem_vec_11053 ,mem_vec_11054 ,mem_vec_11055 ,mem_vec_11056 ,mem_vec_11057 ,mem_vec_11058 ,mem_vec_11059 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 2) (512 / 256)
for (f1281 = f1282, f1281_p_0 = 0;
	f1281 < f1282 + 512;
	f1281 += 256, f1281_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 256
	// T (c, 32) (512 / 16)
	for (c960 = c961, c960_p_0 = 0;
		c960 < c961 + 512;
		c960 += 16, c960_p_0 += 16){
		// y = 14, x = 14, h = 3, w = 3, c = 16, f = 256
		// T (f, 8) (256 / 32)
		for (f1280 = f1281, f1280_p_1 = f1281_p_0, f1280_p_0 = 0;
			f1280 < f1281 + 256;
			f1280 += 32, f1280_p_1 += 32, f1280_p_0 += 32){
				for (y = y640, yp_0 = 0;
					y < y640 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 14) (14 / 1)
					for (x960 = x961, x960_p_0 = 0;
						x960 < x961 + 14;
						x960 += 1, x960_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1280, fp_2 = f1280_p_1, fp_1 = f1280_p_0, fp_0 = 0;
							f < f1280 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h454, hp_0 = 0;
								h < h454 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x960, xp_1 = x960_p_0, xp_0 = 0;
									x < x960 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11024 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11025 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11026 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11027 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11028 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11029 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11030 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11031 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11032 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11033 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11034 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11035 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11036 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11037 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11038 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11039 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c960, cp_1 = c960_p_0, cp_0 = 0;
												c < c960 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11024);
												mem_vec_11024 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11025);
												mem_vec_11025 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11026);
												mem_vec_11026 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11027);
												mem_vec_11027 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11028);
												mem_vec_11028 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11029);
												mem_vec_11029 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11030);
												mem_vec_11030 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11031);
												mem_vec_11031 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11032);
												mem_vec_11032 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11033);
												mem_vec_11033 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11034);
												mem_vec_11034 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11035);
												mem_vec_11035 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11036);
												mem_vec_11036 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11037);
												mem_vec_11037 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11038);
												mem_vec_11038 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11039);
												mem_vec_11039 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);
												vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11024);
												mem_vec_11024 = vec_24;

												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11025);
												mem_vec_11025 = vec_27;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11026);
												mem_vec_11026 = vec_29;

												vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11027);
												mem_vec_11027 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm256_set1_ps(scal_5);


												vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11028);
												mem_vec_11028 = vec_33;



												vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11029);
												mem_vec_11029 = vec_35;



												vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11030);
												mem_vec_11030 = vec_36;



												vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11031);
												mem_vec_11031 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11032);
												mem_vec_11032 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11033);
												mem_vec_11033 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11034);
												mem_vec_11034 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11035);
												mem_vec_11035 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11036);
												mem_vec_11036 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11037);
												mem_vec_11037 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11038);
												mem_vec_11038 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11039);
												mem_vec_11039 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);
												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11024);
												mem_vec_11024 = vec_48;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11025);
												mem_vec_11025 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11026);
												mem_vec_11026 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11027);
												mem_vec_11027 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm256_set1_ps(scal_9);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11028);
												mem_vec_11028 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11029);
												mem_vec_11029 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11030);
												mem_vec_11030 = vec_60;



												vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11031);
												mem_vec_11031 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm256_set1_ps(scal_10);


												vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11032);
												mem_vec_11032 = vec_62;



												vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11033);
												mem_vec_11033 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11034);
												mem_vec_11034 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11035);
												mem_vec_11035 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11036);
												mem_vec_11036 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11037);
												mem_vec_11037 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11038);
												mem_vec_11038 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11039);
												mem_vec_11039 = vec_71;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11024);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11025);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11026);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11027);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11028);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11029);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11030);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11031);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11032);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11033);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11034);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11035);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11036);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11037);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11038);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11039);
								}
							}
						}
					}
				}
				for (y = y640 + 4, yp_0 = 0;
					y < y640 + 4 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (x, 14) (14 / 1)
					for (x960 = x961, x960_p_0 = 0;
						x960 < x961 + 14;
						x960 += 1, x960_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (f, 1) (32 / 32)
						for (f = f1280, fp_2 = f1280_p_1, fp_1 = f1280_p_0, fp_0 = 0;
							f < f1280 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h454, hp_0 = 0;
								h < h454 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x960, xp_1 = x960_p_0, xp_0 = 0;
									x < x960 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11040 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11041 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_11042 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11043 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_11044 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11045 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_11046 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11047 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_11048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_11050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_11052 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11053 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_11054 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11055 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_11056 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11057 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_11058 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11059 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c960, cp_1 = c960_p_0, cp_0 = 0;
												c < c960 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11040);
												mem_vec_11040 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11041);
												mem_vec_11041 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11042);
												mem_vec_11042 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11043);
												mem_vec_11043 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11044);
												mem_vec_11044 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11045);
												mem_vec_11045 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11046);
												mem_vec_11046 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11047);
												mem_vec_11047 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11048);
												mem_vec_11048 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11049);
												mem_vec_11049 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11050);
												mem_vec_11050 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11051);
												mem_vec_11051 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11052);
												mem_vec_11052 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11053);
												mem_vec_11053 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11054);
												mem_vec_11054 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11055);
												mem_vec_11055 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11056);
												mem_vec_11056 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11057);
												mem_vec_11057 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11058);
												mem_vec_11058 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11059);
												mem_vec_11059 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm256_set1_ps(scal_5);
												vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11040);
												mem_vec_11040 = vec_29;

												vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11041);
												mem_vec_11041 = vec_32;

												vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11042);
												mem_vec_11042 = vec_34;

												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11043);
												mem_vec_11043 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm256_set1_ps(scal_6);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11044);
												mem_vec_11044 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11045);
												mem_vec_11045 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11046);
												mem_vec_11046 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11047);
												mem_vec_11047 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm256_set1_ps(scal_7);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11048);
												mem_vec_11048 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11049);
												mem_vec_11049 = vec_45;



												vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11050);
												mem_vec_11050 = vec_46;



												vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11051);
												mem_vec_11051 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm256_set1_ps(scal_8);


												vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11052);
												mem_vec_11052 = vec_48;



												vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11053);
												mem_vec_11053 = vec_50;



												vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11054);
												mem_vec_11054 = vec_51;



												vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11055);
												mem_vec_11055 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm256_set1_ps(scal_9);


												vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11056);
												mem_vec_11056 = vec_53;



												vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11057);
												mem_vec_11057 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11058);
												mem_vec_11058 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11059);
												mem_vec_11059 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm256_set1_ps(scal_10);
												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11040);
												mem_vec_11040 = vec_58;

												vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11041);
												mem_vec_11041 = vec_61;

												vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11042);
												mem_vec_11042 = vec_63;

												vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11043);
												mem_vec_11043 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm256_set1_ps(scal_11);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11044);
												mem_vec_11044 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11045);
												mem_vec_11045 = vec_69;



												vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11046);
												mem_vec_11046 = vec_70;



												vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11047);
												mem_vec_11047 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm256_set1_ps(scal_12);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11048);
												mem_vec_11048 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11049);
												mem_vec_11049 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11050);
												mem_vec_11050 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11051);
												mem_vec_11051 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm256_set1_ps(scal_13);


												vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11052);
												mem_vec_11052 = vec_77;



												vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11053);
												mem_vec_11053 = vec_79;



												vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11054);
												mem_vec_11054 = vec_80;



												vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11055);
												mem_vec_11055 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm256_set1_ps(scal_14);


												vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11056);
												mem_vec_11056 = vec_82;



												vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11057);
												mem_vec_11057 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11058);
												mem_vec_11058 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11059);
												mem_vec_11059 = vec_86;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11040);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11041);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11042);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11043);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11044);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11045);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11046);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11047);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11048);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11049);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11050);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11051);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11052);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11053);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11054);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11055);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11056);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11057);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11058);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11059);
								}
							}
						}
					}
				}
		}
	}
}


}