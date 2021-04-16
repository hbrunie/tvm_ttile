#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (128, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (2, c); T (32, f); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (1, c)]
*/
IND_TYPE c, cp_0, c289_p_0, c290_p_0, c291_p_0, cp_1, c289_p_1, c290_p_1, cp_2, c289_p_2, cp_3, c289, c290, c291, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y176 = 0;
IND_TYPE x152 = 0;
IND_TYPE h = 0;
IND_TYPE w133 = 0;
IND_TYPE c292 = 0;
IND_TYPE f243 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3236 ,mem_vec_3237 ,mem_vec_3238 ,mem_vec_3239 ,mem_vec_3240 ,mem_vec_3241 ,mem_vec_3242 ,mem_vec_3243 ,mem_vec_3244 ,mem_vec_3245 ,mem_vec_3246 ,mem_vec_3247 ,mem_vec_3248 ,mem_vec_3249 ,mem_vec_3250 ,mem_vec_3251 ,mem_vec_3252 ,mem_vec_3253 ,mem_vec_3254 ,mem_vec_3255 ,mem_vec_3256 ,mem_vec_3257 ,mem_vec_3258 ,mem_vec_3259 ,mem_vec_3260 ,mem_vec_3261 ,mem_vec_3262 ,mem_vec_3263 ,mem_vec_3264 ,mem_vec_3265 ,mem_vec_3266 ,mem_vec_3267 ,mem_vec_3268 ,mem_vec_3269 ,mem_vec_3270 ,mem_vec_3271 ,mem_vec_3272 ,mem_vec_3273 ,mem_vec_3274 ,mem_vec_3275 ,mem_vec_3276 ,mem_vec_3277 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 1) (256 / 256)
for (c291 = c292, c291_p_0 = 0;
	c291 < c292 + 256;
	c291 += 256, c291_p_0 += 256){
		for (y = y176, yp_0 = 0;
			y < y176 + 8;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (c, 1) (256 / 256)
			for (c290 = c291, c290_p_1 = c291_p_0, c290_p_0 = 0;
				c290 < c291 + 256;
				c290 += 256, c290_p_1 += 256, c290_p_0 += 256){
				// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
				// T (f, 32) (512 / 16)
				for (f = f243, fp_0 = 0;
					f < f243 + 512;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 16
					// T (c, 2) (256 / 128)
					for (c289 = c290, c289_p_2 = c290_p_1, c289_p_1 = c290_p_0, c289_p_0 = 0;
						c289 < c290 + 256;
						c289 += 128, c289_p_2 += 128, c289_p_1 += 128, c289_p_0 += 128){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
						// T (x, 34) (34 / 1)
						for (x = x152, xp_0 = 0;
							x < x152 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
							// T (w, 3) (3 / 1)
							for (w = w133, wp_0 = 0;
								w < w133 + 3;
								w += 1, wp_0 += 1){
										mem_vec_3236 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3237 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_3250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
										// T (c, 128) (128 / 1)
										for (c = c289, cp_3 = c289_p_2, cp_2 = c289_p_1, cp_1 = c289_p_0, cp_0 = 0;
											c < c289 + 128;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3236);
											mem_vec_3236 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3237);
											mem_vec_3237 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3238);
											mem_vec_3238 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3239);
											mem_vec_3239 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3240);
											mem_vec_3240 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3241);
											mem_vec_3241 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3242);
											mem_vec_3242 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3243);
											mem_vec_3243 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3244);
											mem_vec_3244 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3245);
											mem_vec_3245 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3246);
											mem_vec_3246 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3247);
											mem_vec_3247 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3248);
											mem_vec_3248 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3249);
											mem_vec_3249 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3250);
											mem_vec_3250 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3251);
											mem_vec_3251 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_27 = _mm256_set1_ps(scal_8);
											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_3236);
											mem_vec_3236 = vec_26;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_3237);
											mem_vec_3237 = vec_29;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_32 = _mm256_set1_ps(scal_9);


											vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_3238);
											mem_vec_3238 = vec_31;



											vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_3239);
											mem_vec_3239 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_10);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_3240);
											mem_vec_3240 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_3241);
											mem_vec_3241 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);


											vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_3242);
											mem_vec_3242 = vec_37;



											vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_3243);
											mem_vec_3243 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_3244);
											mem_vec_3244 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_3245);
											mem_vec_3245 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_3246);
											mem_vec_3246 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_3247);
											mem_vec_3247 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_3248);
											mem_vec_3248 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_3249);
											mem_vec_3249 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_3250);
											mem_vec_3250 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_3251);
											mem_vec_3251 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_53 = _mm256_set1_ps(scal_16);
											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_3236);
											mem_vec_3236 = vec_52;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_3237);
											mem_vec_3237 = vec_55;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm256_set1_ps(scal_17);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_3238);
											mem_vec_3238 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_3239);
											mem_vec_3239 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_61 = _mm256_set1_ps(scal_18);


											vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_3240);
											mem_vec_3240 = vec_60;



											vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_3241);
											mem_vec_3241 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_64 = _mm256_set1_ps(scal_19);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_3242);
											mem_vec_3242 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_3243);
											mem_vec_3243 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_67 = _mm256_set1_ps(scal_20);


											vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_3244);
											mem_vec_3244 = vec_66;



											vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_3245);
											mem_vec_3245 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);


											vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_3246);
											mem_vec_3246 = vec_69;



											vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_3247);
											mem_vec_3247 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_3248);
											mem_vec_3248 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_3249);
											mem_vec_3249 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_3250);
											mem_vec_3250 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_3251);
											mem_vec_3251 = vec_77;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3236);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3237);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3238);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3239);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3240);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3241);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3242);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3243);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3244);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3245);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3246);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3247);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3248);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3249);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3250);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3251);
							}
						}
					}
				}
			}
		}
		for (y = y176 + 8, yp_0 = 0;
			y < y176 + 8 + 26;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (c, 1) (256 / 256)
			for (c290 = c291, c290_p_1 = c291_p_0, c290_p_0 = 0;
				c290 < c291 + 256;
				c290 += 256, c290_p_1 += 256, c290_p_0 += 256){
				// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
				// T (f, 32) (512 / 16)
				for (f = f243, fp_0 = 0;
					f < f243 + 512;
					f += 16, fp_0 += 16){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 16
					// T (c, 2) (256 / 128)
					for (c289 = c290, c289_p_2 = c290_p_1, c289_p_1 = c290_p_0, c289_p_0 = 0;
						c289 < c290 + 256;
						c289 += 128, c289_p_2 += 128, c289_p_1 += 128, c289_p_0 += 128){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
						// T (x, 34) (34 / 1)
						for (x = x152, xp_0 = 0;
							x < x152 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
							// T (w, 3) (3 / 1)
							for (w = w133, wp_0 = 0;
								w < w133 + 3;
								w += 1, wp_0 += 1){
										mem_vec_3252 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3253 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_3266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_3268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_3270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										mem_vec_3272 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3273 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
										mem_vec_3274 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3275 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
										mem_vec_3276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_3277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 128, f = 16
										// T (c, 128) (128 / 1)
										for (c = c289, cp_3 = c289_p_2, cp_2 = c289_p_1, cp_1 = c289_p_0, cp_0 = 0;
											c < c289 + 128;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3252);
											mem_vec_3252 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3253);
											mem_vec_3253 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3254);
											mem_vec_3254 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3255);
											mem_vec_3255 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3256);
											mem_vec_3256 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3257);
											mem_vec_3257 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3258);
											mem_vec_3258 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3259);
											mem_vec_3259 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3260);
											mem_vec_3260 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3261);
											mem_vec_3261 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3262);
											mem_vec_3262 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3263);
											mem_vec_3263 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3264);
											mem_vec_3264 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3265);
											mem_vec_3265 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3266);
											mem_vec_3266 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3267);
											mem_vec_3267 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3268);
											mem_vec_3268 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3269);
											mem_vec_3269 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3270);
											mem_vec_3270 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3271);
											mem_vec_3271 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm256_set1_ps(scal_10);


											vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_3272);
											mem_vec_3272 = vec_32;



											vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_3273);
											mem_vec_3273 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm256_set1_ps(scal_11);


											vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_3274);
											mem_vec_3274 = vec_35;



											vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_3275);
											mem_vec_3275 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm256_set1_ps(scal_12);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_3276);
											mem_vec_3276 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_3277);
											mem_vec_3277 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_42 = _mm256_set1_ps(scal_13);
											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_3252);
											mem_vec_3252 = vec_41;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_3253);
											mem_vec_3253 = vec_44;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_3254);
											mem_vec_3254 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_3255);
											mem_vec_3255 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_3256);
											mem_vec_3256 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_3257);
											mem_vec_3257 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_3258);
											mem_vec_3258 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_3259);
											mem_vec_3259 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_3260);
											mem_vec_3260 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_3261);
											mem_vec_3261 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_3262);
											mem_vec_3262 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_3263);
											mem_vec_3263 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_3264);
											mem_vec_3264 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_3265);
											mem_vec_3265 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_65 = _mm256_set1_ps(scal_20);


											vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_3266);
											mem_vec_3266 = vec_64;



											vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_3267);
											mem_vec_3267 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_68 = _mm256_set1_ps(scal_21);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_3268);
											mem_vec_3268 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_3269);
											mem_vec_3269 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_71 = _mm256_set1_ps(scal_22);


											vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_3270);
											mem_vec_3270 = vec_70;



											vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_3271);
											mem_vec_3271 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_74 = _mm256_set1_ps(scal_23);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_3272);
											mem_vec_3272 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_3273);
											mem_vec_3273 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_77 = _mm256_set1_ps(scal_24);


											vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_3274);
											mem_vec_3274 = vec_76;



											vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_3275);
											mem_vec_3275 = vec_78;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
											vec_80 = _mm256_set1_ps(scal_25);


											vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_3276);
											mem_vec_3276 = vec_79;



											vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_3277);
											mem_vec_3277 = vec_81;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_26);
											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_3252);
											mem_vec_3252 = vec_82;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_3253);
											mem_vec_3253 = vec_85;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_3254);
											mem_vec_3254 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_3255);
											mem_vec_3255 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_3256);
											mem_vec_3256 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_3257);
											mem_vec_3257 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_3258);
											mem_vec_3258 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_3259);
											mem_vec_3259 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_97 = _mm256_set1_ps(scal_30);


											vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_3260);
											mem_vec_3260 = vec_96;



											vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_3261);
											mem_vec_3261 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_100 = _mm256_set1_ps(scal_31);


											vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_3262);
											mem_vec_3262 = vec_99;



											vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_3263);
											mem_vec_3263 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_103 = _mm256_set1_ps(scal_32);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_3264);
											mem_vec_3264 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_3265);
											mem_vec_3265 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_106 = _mm256_set1_ps(scal_33);


											vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_3266);
											mem_vec_3266 = vec_105;



											vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_3267);
											mem_vec_3267 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_109 = _mm256_set1_ps(scal_34);


											vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_3268);
											mem_vec_3268 = vec_108;



											vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_3269);
											mem_vec_3269 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_112 = _mm256_set1_ps(scal_35);


											vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_3270);
											mem_vec_3270 = vec_111;



											vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_3271);
											mem_vec_3271 = vec_113;
											scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_115 = _mm256_set1_ps(scal_36);


											vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_3272);
											mem_vec_3272 = vec_114;



											vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_3273);
											mem_vec_3273 = vec_116;
											scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_118 = _mm256_set1_ps(scal_37);


											vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_3274);
											mem_vec_3274 = vec_117;



											vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_3275);
											mem_vec_3275 = vec_119;
											scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
											vec_121 = _mm256_set1_ps(scal_38);


											vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_3276);
											mem_vec_3276 = vec_120;



											vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_3277);
											mem_vec_3277 = vec_122;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3252);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3253);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3254);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3255);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3256);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3257);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3258);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3259);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3260);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3261);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3262);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3263);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3264);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3265);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3266);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3267);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3268);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3269);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3270);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_3271);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3272);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_3273);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3274);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_3275);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3276);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_3277);
							}
						}
					}
				}
			}
		}
}


}