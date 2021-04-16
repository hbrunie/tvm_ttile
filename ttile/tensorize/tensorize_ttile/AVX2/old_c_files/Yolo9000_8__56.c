#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (8, c); T (16, f); T (1, c); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (1, c)]
*/
IND_TYPE c, cp_0, c726_p_0, c727_p_0, c728_p_0, cp_1, c726_p_1, c727_p_1, cp_2, c726_p_2, cp_3, c726, c727, c728, f, fp_0, w, wp_0, x, xp_0, x510_p_0, xp_1, x510, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y340 = 0;
IND_TYPE x511 = 0;
IND_TYPE h = 0;
IND_TYPE w288 = 0;
IND_TYPE c729 = 0;
IND_TYPE f464 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4252 ,mem_vec_4253 ,mem_vec_4254 ,mem_vec_4255 ,mem_vec_4256 ,mem_vec_4257 ,mem_vec_4258 ,mem_vec_4259 ,mem_vec_4260 ,mem_vec_4261 ,mem_vec_4262 ,mem_vec_4263 ,mem_vec_4264 ,mem_vec_4265 ,mem_vec_4266 ,mem_vec_4267 ,mem_vec_4268 ,mem_vec_4269 ,mem_vec_4270 ,mem_vec_4271 ,mem_vec_4272 ,mem_vec_4273 ,mem_vec_4274 ,mem_vec_4275 ,mem_vec_4276 ,mem_vec_4277 ,mem_vec_4278 ,mem_vec_4279 ,mem_vec_4280 ,mem_vec_4281 ,mem_vec_4282 ,mem_vec_4283 ,mem_vec_4284 ,mem_vec_4285 ,mem_vec_4286 ,mem_vec_4287 ,mem_vec_4288 ,mem_vec_4289 ,mem_vec_4290 ,mem_vec_4291 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
for (c728 = c729, c728_p_0 = 0;
	c728 < c729 + 128;
	c728 += 128, c728_p_0 += 128){
		for (y = y340, yp_0 = 0;
			y < y340 + 8;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (68 / 34)
			for (x510 = x511, x510_p_0 = 0;
				x510 < x511 + 68;
				x510 += 34, x510_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c727 = c728, c727_p_1 = c728_p_0, c727_p_0 = 0;
					c727 < c728 + 128;
					c727 += 128, c727_p_1 += 128, c727_p_0 += 128){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 256
					// T (f, 16) (256 / 16)
					for (f = f464, fp_0 = 0;
						f < f464 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
						// T (c, 8) (128 / 16)
						for (c726 = c727, c726_p_2 = c727_p_1, c726_p_1 = c727_p_0, c726_p_0 = 0;
							c726 < c727 + 128;
							c726 += 16, c726_p_2 += 16, c726_p_1 += 16, c726_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 16
							// T (x, 34) (34 / 1)
							for (x = x510, xp_1 = x510_p_0, xp_0 = 0;
								x < x510 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
								// T (w, 3) (3 / 1)
								for (w = w288, wp_0 = 0;
									w < w288 + 3;
									w += 1, wp_0 += 1){
											mem_vec_4252 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4253 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_4262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_4264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_4266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c726, cp_3 = c726_p_2, cp_2 = c726_p_1, cp_1 = c726_p_0, cp_0 = 0;
												c < c726 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4252);
												mem_vec_4252 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4253);
												mem_vec_4253 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_4254);
												mem_vec_4254 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_4255);
												mem_vec_4255 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_4256);
												mem_vec_4256 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_4257);
												mem_vec_4257 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_4258);
												mem_vec_4258 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_4259);
												mem_vec_4259 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4260);
												mem_vec_4260 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4261);
												mem_vec_4261 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4262);
												mem_vec_4262 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4263);
												mem_vec_4263 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_4264);
												mem_vec_4264 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_4265);
												mem_vec_4265 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_4266);
												mem_vec_4266 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_4267);
												mem_vec_4267 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_27 = _mm256_set1_ps(scal_8);
												vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_4252);
												mem_vec_4252 = vec_26;

												vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_4253);
												mem_vec_4253 = vec_29;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_32 = _mm256_set1_ps(scal_9);


												vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_4254);
												mem_vec_4254 = vec_31;



												vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_4255);
												mem_vec_4255 = vec_33;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_35 = _mm256_set1_ps(scal_10);


												vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_4256);
												mem_vec_4256 = vec_34;



												vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_4257);
												mem_vec_4257 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_38 = _mm256_set1_ps(scal_11);


												vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_4258);
												mem_vec_4258 = vec_37;



												vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_4259);
												mem_vec_4259 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_4260);
												mem_vec_4260 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_4261);
												mem_vec_4261 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_4262);
												mem_vec_4262 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_4263);
												mem_vec_4263 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_4264);
												mem_vec_4264 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_4265);
												mem_vec_4265 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_4266);
												mem_vec_4266 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_4267);
												mem_vec_4267 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_53 = _mm256_set1_ps(scal_16);
												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_4252);
												mem_vec_4252 = vec_52;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_4253);
												mem_vec_4253 = vec_55;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm256_set1_ps(scal_17);


												vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_4254);
												mem_vec_4254 = vec_57;



												vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_4255);
												mem_vec_4255 = vec_59;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_61 = _mm256_set1_ps(scal_18);


												vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_4256);
												mem_vec_4256 = vec_60;



												vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_4257);
												mem_vec_4257 = vec_62;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_64 = _mm256_set1_ps(scal_19);


												vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_4258);
												mem_vec_4258 = vec_63;



												vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_4259);
												mem_vec_4259 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_67 = _mm256_set1_ps(scal_20);


												vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_4260);
												mem_vec_4260 = vec_66;



												vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_4261);
												mem_vec_4261 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_70 = _mm256_set1_ps(scal_21);


												vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_4262);
												mem_vec_4262 = vec_69;



												vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_4263);
												mem_vec_4263 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_73 = _mm256_set1_ps(scal_22);


												vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_4264);
												mem_vec_4264 = vec_72;



												vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_4265);
												mem_vec_4265 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_4266);
												mem_vec_4266 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_4267);
												mem_vec_4267 = vec_77;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4252);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4253);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4254);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4255);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4256);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4257);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4258);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4259);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4260);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4261);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4262);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_4263);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4264);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_4265);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4266);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_4267);
								}
							}
						}
					}
				}
			}
		}
		for (y = y340 + 8, yp_0 = 0;
			y < y340 + 8 + 60;
			y += 12, yp_0 += 12){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (68 / 34)
			for (x510 = x511, x510_p_0 = 0;
				x510 < x511 + 68;
				x510 += 34, x510_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 256
				// T (c, 1) (128 / 128)
				for (c727 = c728, c727_p_1 = c728_p_0, c727_p_0 = 0;
					c727 < c728 + 128;
					c727 += 128, c727_p_1 += 128, c727_p_0 += 128){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 256
					// T (f, 16) (256 / 16)
					for (f = f464, fp_0 = 0;
						f < f464 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 16
						// T (c, 8) (128 / 16)
						for (c726 = c727, c726_p_2 = c727_p_1, c726_p_1 = c727_p_0, c726_p_0 = 0;
							c726 < c727 + 128;
							c726 += 16, c726_p_2 += 16, c726_p_1 += 16, c726_p_0 += 16){
							// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 16
							// T (x, 34) (34 / 1)
							for (x = x510, xp_1 = x510_p_0, xp_0 = 0;
								x < x510 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
								// T (w, 3) (3 / 1)
								for (w = w288, wp_0 = 0;
									w < w288 + 3;
									w += 1, wp_0 += 1){
											mem_vec_4268 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4269 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_4270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_4272 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4273 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_4274 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4275 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_4276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_4278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_4280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_4282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_4284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_4286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_4288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_4289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_4290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_4291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
											// T (c, 16) (16 / 1)
											for (c = c726, cp_3 = c726_p_2, cp_2 = c726_p_1, cp_1 = c726_p_0, cp_0 = 0;
												c < c726 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4268);
												mem_vec_4268 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4269);
												mem_vec_4269 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_4270);
												mem_vec_4270 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_4271);
												mem_vec_4271 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_4272);
												mem_vec_4272 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_4273);
												mem_vec_4273 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_4274);
												mem_vec_4274 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_4275);
												mem_vec_4275 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4276);
												mem_vec_4276 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4277);
												mem_vec_4277 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_4278);
												mem_vec_4278 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_4279);
												mem_vec_4279 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_4280);
												mem_vec_4280 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_4281);
												mem_vec_4281 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_4282);
												mem_vec_4282 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_4283);
												mem_vec_4283 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_4284);
												mem_vec_4284 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_4285);
												mem_vec_4285 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_4286);
												mem_vec_4286 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_4287);
												mem_vec_4287 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_4288);
												mem_vec_4288 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_4289);
												mem_vec_4289 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_4290);
												mem_vec_4290 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_4291);
												mem_vec_4291 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_39 = _mm256_set1_ps(scal_12);
												vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_4268);
												mem_vec_4268 = vec_38;

												vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_4269);
												mem_vec_4269 = vec_41;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_4270);
												mem_vec_4270 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_4271);
												mem_vec_4271 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_4272);
												mem_vec_4272 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_4273);
												mem_vec_4273 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_4274);
												mem_vec_4274 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_4275);
												mem_vec_4275 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_4276);
												mem_vec_4276 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_4277);
												mem_vec_4277 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_4278);
												mem_vec_4278 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_4279);
												mem_vec_4279 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_4280);
												mem_vec_4280 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_4281);
												mem_vec_4281 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_4282);
												mem_vec_4282 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_4283);
												mem_vec_4283 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_4284);
												mem_vec_4284 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_4285);
												mem_vec_4285 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_4286);
												mem_vec_4286 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_4287);
												mem_vec_4287 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_4288);
												mem_vec_4288 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_4289);
												mem_vec_4289 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_4290);
												mem_vec_4290 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_4291);
												mem_vec_4291 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_77 = _mm256_set1_ps(scal_24);
												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_4268);
												mem_vec_4268 = vec_76;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_4269);
												mem_vec_4269 = vec_79;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_4270);
												mem_vec_4270 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_4271);
												mem_vec_4271 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_4272);
												mem_vec_4272 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_4273);
												mem_vec_4273 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_4274);
												mem_vec_4274 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_4275);
												mem_vec_4275 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_4276);
												mem_vec_4276 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_4277);
												mem_vec_4277 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_4278);
												mem_vec_4278 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_4279);
												mem_vec_4279 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_4280);
												mem_vec_4280 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_4281);
												mem_vec_4281 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_4282);
												mem_vec_4282 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_4283);
												mem_vec_4283 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_4284);
												mem_vec_4284 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_4285);
												mem_vec_4285 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_4286);
												mem_vec_4286 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_4287);
												mem_vec_4287 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_4288);
												mem_vec_4288 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_4289);
												mem_vec_4289 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_4290);
												mem_vec_4290 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_4291);
												mem_vec_4291 = vec_113;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4268);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4269);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4270);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4271);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4272);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4273);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4274);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4275);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4276);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4277);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4278);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_4279);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4280);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_4281);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4282);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_4283);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4284);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_4285);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4286);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_4287);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4288);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_4289);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4290);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_4291);
								}
							}
						}
					}
				}
			}
		}
}


}