#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))];
  T (1, f); T (4, c); T (1, f); T (2, c); T (56, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1246_p_0, c1247_p_0, cp_1, c1246_p_1, cp_2, c1246, c1247, f, fp_0, f1172_p_0, f1173_p_0, fp_1, f1172_p_1, fp_2, f1172, f1173, h, hp_0, x, xp_0, x1050_p_0, xp_1, x1050, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y656 = 0;
IND_TYPE x1051 = 0;
IND_TYPE h440 = 0;
IND_TYPE w = 0;
IND_TYPE c1248 = 0;
IND_TYPE f1174 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11288 ,mem_vec_11289 ,mem_vec_11290 ,mem_vec_11291 ,mem_vec_11292 ,mem_vec_11293 ,mem_vec_11294 ,mem_vec_11295 ,mem_vec_11296 ,mem_vec_11297 ,mem_vec_11298 ,mem_vec_11299 ,mem_vec_11300 ,mem_vec_11301 ,mem_vec_11302 ,mem_vec_11303 ,mem_vec_11304 ,mem_vec_11305 ,mem_vec_11306 ,mem_vec_11307 ,mem_vec_11308 ,mem_vec_11309 ,mem_vec_11310 ,mem_vec_11311 ,mem_vec_11312 ,mem_vec_11313 ,mem_vec_11314 ,mem_vec_11315 ,mem_vec_11316 ,mem_vec_11317 ,mem_vec_11318 ,mem_vec_11319 ,mem_vec_11320 ,mem_vec_11321 ,mem_vec_11322 ,mem_vec_11323 ,mem_vec_11324 ,mem_vec_11325 ,mem_vec_11326 ,mem_vec_11327 ,mem_vec_11328 ,mem_vec_11329 ,mem_vec_11330 ,mem_vec_11331 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 2) (64 / 32)
for (f1173 = f1174, f1173_p_0 = 0;
	f1173 < f1174 + 64;
	f1173 += 32, f1173_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
	// T (x, 56) (56 / 1)
	for (x1050 = x1051, x1050_p_0 = 0;
		x1050 < x1051 + 56;
		x1050 += 1, x1050_p_0 += 1){
		// y = 56, x = 1, h = 3, w = 3, c = 64, f = 32
		// T (c, 2) (64 / 32)
		for (c1247 = c1248, c1247_p_0 = 0;
			c1247 < c1248 + 64;
			c1247 += 32, c1247_p_0 += 32){
			// y = 56, x = 1, h = 3, w = 3, c = 32, f = 32
			// T (f, 1) (32 / 32)
			for (f1172 = f1173, f1172_p_1 = f1173_p_0, f1172_p_0 = 0;
				f1172 < f1173 + 32;
				f1172 += 32, f1172_p_1 += 32, f1172_p_0 += 32){
				// y = 56, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (c, 4) (32 / 8)
				for (c1246 = c1247, c1246_p_1 = c1247_p_0, c1246_p_0 = 0;
					c1246 < c1247 + 32;
					c1246 += 8, c1246_p_1 += 8, c1246_p_0 += 8){
					// y = 56, x = 1, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1172, fp_2 = f1172_p_1, fp_1 = f1172_p_0, fp_0 = 0;
						f < f1172 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y656, yp_0 = 0;
								y < y656 + 28;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h440, hp_0 = 0;
									h < h440 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1050, xp_1 = x1050_p_0, xp_0 = 0;
										x < x1050 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11288 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11289 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11290 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11291 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11296 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11297 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11298 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11299 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1246, cp_2 = c1246_p_1, cp_1 = c1246_p_0, cp_0 = 0;
													c < c1246 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11288);
													mem_vec_11288 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11289);
													mem_vec_11289 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11290);
													mem_vec_11290 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11291);
													mem_vec_11291 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11292);
													mem_vec_11292 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11293);
													mem_vec_11293 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11294);
													mem_vec_11294 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11295);
													mem_vec_11295 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11296);
													mem_vec_11296 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11297);
													mem_vec_11297 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11298);
													mem_vec_11298 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11299);
													mem_vec_11299 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11300);
													mem_vec_11300 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11301);
													mem_vec_11301 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11302);
													mem_vec_11302 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11303);
													mem_vec_11303 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11288);
													mem_vec_11288 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11289);
													mem_vec_11289 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11290);
													mem_vec_11290 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11291);
													mem_vec_11291 = vec_31;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11292);
													mem_vec_11292 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11293);
													mem_vec_11293 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11294);
													mem_vec_11294 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11295);
													mem_vec_11295 = vec_37;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11296);
													mem_vec_11296 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11297);
													mem_vec_11297 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11298);
													mem_vec_11298 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11299);
													mem_vec_11299 = vec_42;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11300);
													mem_vec_11300 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11301);
													mem_vec_11301 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11302);
													mem_vec_11302 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11303);
													mem_vec_11303 = vec_47;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11288);
													mem_vec_11288 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11289);
													mem_vec_11289 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11290);
													mem_vec_11290 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11291);
													mem_vec_11291 = vec_55;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11292);
													mem_vec_11292 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11293);
													mem_vec_11293 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11294);
													mem_vec_11294 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11295);
													mem_vec_11295 = vec_61;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11296);
													mem_vec_11296 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11297);
													mem_vec_11297 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11298);
													mem_vec_11298 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11299);
													mem_vec_11299 = vec_66;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11300);
													mem_vec_11300 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11301);
													mem_vec_11301 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11302);
													mem_vec_11302 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11303);
													mem_vec_11303 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11288);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11289);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11290);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11291);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11292);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11293);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11294);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11295);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11296);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11297);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11298);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11299);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11300);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11301);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11302);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11303);
									}
								}
							}
							for (y = y656 + 28, yp_0 = 0;
								y < y656 + 28 + 28;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h440, hp_0 = 0;
									h < h440 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1050, xp_1 = x1050_p_0, xp_0 = 0;
										x < x1050 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11304 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11305 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11306 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11307 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_11324 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11325 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11326 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11327 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_11328 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11329 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_11330 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11331 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1246, cp_2 = c1246_p_1, cp_1 = c1246_p_0, cp_0 = 0;
													c < c1246 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11304);
													mem_vec_11304 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11305);
													mem_vec_11305 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11306);
													mem_vec_11306 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11307);
													mem_vec_11307 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11308);
													mem_vec_11308 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11309);
													mem_vec_11309 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11310);
													mem_vec_11310 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11311);
													mem_vec_11311 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11312);
													mem_vec_11312 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11313);
													mem_vec_11313 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11314);
													mem_vec_11314 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11315);
													mem_vec_11315 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11316);
													mem_vec_11316 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11317);
													mem_vec_11317 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11318);
													mem_vec_11318 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11319);
													mem_vec_11319 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11320);
													mem_vec_11320 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11321);
													mem_vec_11321 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11322);
													mem_vec_11322 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11323);
													mem_vec_11323 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11324);
													mem_vec_11324 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11325);
													mem_vec_11325 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11326);
													mem_vec_11326 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11327);
													mem_vec_11327 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_11328);
													mem_vec_11328 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_11329);
													mem_vec_11329 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_11330);
													mem_vec_11330 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_11331);
													mem_vec_11331 = vec_38;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_11304);
													mem_vec_11304 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_11305);
													mem_vec_11305 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_11306);
													mem_vec_11306 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_11307);
													mem_vec_11307 = vec_46;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_11308);
													mem_vec_11308 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_11309);
													mem_vec_11309 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_11310);
													mem_vec_11310 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_11311);
													mem_vec_11311 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_11312);
													mem_vec_11312 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_11313);
													mem_vec_11313 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_11314);
													mem_vec_11314 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_11315);
													mem_vec_11315 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_11316);
													mem_vec_11316 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_11317);
													mem_vec_11317 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_11318);
													mem_vec_11318 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_11319);
													mem_vec_11319 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_11320);
													mem_vec_11320 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_11321);
													mem_vec_11321 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_11322);
													mem_vec_11322 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_11323);
													mem_vec_11323 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_11324);
													mem_vec_11324 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_11325);
													mem_vec_11325 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_11326);
													mem_vec_11326 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_11327);
													mem_vec_11327 = vec_72;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_11328);
													mem_vec_11328 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_11329);
													mem_vec_11329 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_11330);
													mem_vec_11330 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_11331);
													mem_vec_11331 = vec_77;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_11304);
													mem_vec_11304 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_11305);
													mem_vec_11305 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_11306);
													mem_vec_11306 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_11307);
													mem_vec_11307 = vec_85;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_11308);
													mem_vec_11308 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_11309);
													mem_vec_11309 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_11310);
													mem_vec_11310 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_11311);
													mem_vec_11311 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_11312);
													mem_vec_11312 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_11313);
													mem_vec_11313 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_11314);
													mem_vec_11314 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_11315);
													mem_vec_11315 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_11316);
													mem_vec_11316 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_11317);
													mem_vec_11317 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_11318);
													mem_vec_11318 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_11319);
													mem_vec_11319 = vec_101;
													scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_11320);
													mem_vec_11320 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_11321);
													mem_vec_11321 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_11322);
													mem_vec_11322 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_11323);
													mem_vec_11323 = vec_106;
													scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_11324);
													mem_vec_11324 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_11325);
													mem_vec_11325 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_11326);
													mem_vec_11326 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_11327);
													mem_vec_11327 = vec_111;
													scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_11328);
													mem_vec_11328 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_11329);
													mem_vec_11329 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_11330);
													mem_vec_11330 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_11331);
													mem_vec_11331 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11304);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11305);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11306);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11307);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11308);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11309);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11310);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11311);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11312);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11313);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11314);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11315);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11316);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11317);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11318);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11319);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11320);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11321);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11322);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11323);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11324);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11325);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11326);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11327);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11328);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_11329);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11330);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_11331);
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