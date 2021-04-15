#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (1, f);
  T (256, c); T (34, x); T (8, f)]
*/
IND_TYPE c, cp_0, c1424_p_0, cp_1, c1424, f, fp_0, f928_p_0, f929_p_0, fp_1, f928_p_1, fp_2, f928, f929, h, hp_0, x, xp_0, x1344_p_0, x1345_p_0, xp_1, x1344_p_1, xp_2, x1344, x1345, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y672 = 0;
IND_TYPE x1346 = 0;
IND_TYPE h362 = 0;
IND_TYPE w = 0;
IND_TYPE c1425 = 0;
IND_TYPE f930 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_14280 ,mem_vec_14281 ,mem_vec_14282 ,mem_vec_14283 ,mem_vec_14284 ,mem_vec_14285 ,mem_vec_14286 ,mem_vec_14287 ,mem_vec_14288 ,mem_vec_14289 ,mem_vec_14290 ,mem_vec_14291 ,mem_vec_14292 ,mem_vec_14293 ,mem_vec_14294 ,mem_vec_14295 ,mem_vec_14296 ,mem_vec_14297 ,mem_vec_14298 ,mem_vec_14299 ,mem_vec_14300 ,mem_vec_14301 ,mem_vec_14302 ,mem_vec_14303 ,mem_vec_14304 ,mem_vec_14305 ,mem_vec_14306 ,mem_vec_14307 ,mem_vec_14308 ,mem_vec_14309 ,mem_vec_14310 ,mem_vec_14311 ,mem_vec_14312 ,mem_vec_14313 ,mem_vec_14314 ,mem_vec_14315 ,mem_vec_14316 ,mem_vec_14317 ,mem_vec_14318 ,mem_vec_14319 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f929 = f930, f929_p_0 = 0;
	f929 < f930 + 512;
	f929 += 64, f929_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
	// T (x, 34) (34 / 1)
	for (x1345 = x1346, x1345_p_0 = 0;
		x1345 < x1346 + 34;
		x1345 += 1, x1345_p_0 += 1){
		// y = 34, x = 1, h = 3, w = 3, c = 256, f = 64
		// T (c, 256) (256 / 1)
		for (c1424 = c1425, c1424_p_0 = 0;
			c1424 < c1425 + 256;
			c1424 += 1, c1424_p_0 += 1){
			// y = 34, x = 1, h = 3, w = 3, c = 1, f = 64
			// T (f, 1) (64 / 64)
			for (f928 = f929, f928_p_1 = f929_p_0, f928_p_0 = 0;
				f928 < f929 + 64;
				f928 += 64, f928_p_1 += 64, f928_p_0 += 64){
					for (y = y672, yp_0 = 0;
						y < y672 + 4;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x1344 = x1345, x1344_p_1 = x1345_p_0, x1344_p_0 = 0;
							x1344 < x1345 + 1;
							x1344 += 1, x1344_p_1 += 1, x1344_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 64
							// T (f, 2) (64 / 32)
							for (f = f928, fp_2 = f928_p_1, fp_1 = f928_p_0, fp_0 = 0;
								f < f928 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h362, hp_0 = 0;
									h < h362 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1344, xp_2 = x1344_p_1, xp_1 = x1344_p_0, xp_0 = 0;
										x < x1344 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_14280 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_14281 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_14282 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_14283 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_14284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_14285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_14286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_14287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_14288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_14289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_14290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_14291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_14292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_14293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_14294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_14295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1424, cp_1 = c1424_p_0, cp_0 = 0;
													c < c1424 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14280);
													mem_vec_14280 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14281);
													mem_vec_14281 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14282);
													mem_vec_14282 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14283);
													mem_vec_14283 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14284);
													mem_vec_14284 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14285);
													mem_vec_14285 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14286);
													mem_vec_14286 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14287);
													mem_vec_14287 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14288);
													mem_vec_14288 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14289);
													mem_vec_14289 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14290);
													mem_vec_14290 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14291);
													mem_vec_14291 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14292);
													mem_vec_14292 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14293);
													mem_vec_14293 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14294);
													mem_vec_14294 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14295);
													mem_vec_14295 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_14280);
													mem_vec_14280 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_14281);
													mem_vec_14281 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_14282);
													mem_vec_14282 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_14283);
													mem_vec_14283 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_14284);
													mem_vec_14284 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_14285);
													mem_vec_14285 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_14286);
													mem_vec_14286 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_14287);
													mem_vec_14287 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_14288);
													mem_vec_14288 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_14289);
													mem_vec_14289 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_14290);
													mem_vec_14290 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_14291);
													mem_vec_14291 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_14292);
													mem_vec_14292 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_14293);
													mem_vec_14293 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_14294);
													mem_vec_14294 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_14295);
													mem_vec_14295 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_14280);
													mem_vec_14280 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_14281);
													mem_vec_14281 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_14282);
													mem_vec_14282 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_14283);
													mem_vec_14283 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_14284);
													mem_vec_14284 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_14285);
													mem_vec_14285 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_14286);
													mem_vec_14286 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_14287);
													mem_vec_14287 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_14288);
													mem_vec_14288 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_14289);
													mem_vec_14289 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_14290);
													mem_vec_14290 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_14291);
													mem_vec_14291 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_14292);
													mem_vec_14292 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_14293);
													mem_vec_14293 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_14294);
													mem_vec_14294 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_14295);
													mem_vec_14295 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14280);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14281);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14282);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14283);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14284);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14285);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14286);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14287);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14288);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14289);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14290);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14291);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14292);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14293);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14294);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14295);
									}
								}
							}
						}
					}
					for (y = y672 + 4, yp_0 = 0;
						y < y672 + 4 + 30;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x1344 = x1345, x1344_p_1 = x1345_p_0, x1344_p_0 = 0;
							x1344 < x1345 + 1;
							x1344 += 1, x1344_p_1 += 1, x1344_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 64
							// T (f, 2) (64 / 32)
							for (f = f928, fp_2 = f928_p_1, fp_1 = f928_p_0, fp_0 = 0;
								f < f928 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h362, hp_0 = 0;
									h < h362 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1344, xp_2 = x1344_p_1, xp_1 = x1344_p_0, xp_0 = 0;
										x < x1344 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_14296 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_14297 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_14298 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_14299 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_14300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_14301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_14302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_14303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_14304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_14305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_14306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_14307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_14308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_14309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_14310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_14311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_14312 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_14313 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_14314 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_14315 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_14316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_14317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_14318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_14319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c1424, cp_1 = c1424_p_0, cp_0 = 0;
													c < c1424 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14296);
													mem_vec_14296 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14297);
													mem_vec_14297 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14298);
													mem_vec_14298 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14299);
													mem_vec_14299 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14300);
													mem_vec_14300 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14301);
													mem_vec_14301 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14302);
													mem_vec_14302 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14303);
													mem_vec_14303 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14304);
													mem_vec_14304 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14305);
													mem_vec_14305 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14306);
													mem_vec_14306 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14307);
													mem_vec_14307 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14308);
													mem_vec_14308 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14309);
													mem_vec_14309 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14310);
													mem_vec_14310 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14311);
													mem_vec_14311 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14312);
													mem_vec_14312 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14313);
													mem_vec_14313 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14314);
													mem_vec_14314 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14315);
													mem_vec_14315 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_14316);
													mem_vec_14316 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_14317);
													mem_vec_14317 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_14318);
													mem_vec_14318 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_14319);
													mem_vec_14319 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_14296);
													mem_vec_14296 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_14297);
													mem_vec_14297 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_14298);
													mem_vec_14298 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_14299);
													mem_vec_14299 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_14300);
													mem_vec_14300 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_14301);
													mem_vec_14301 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_14302);
													mem_vec_14302 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_14303);
													mem_vec_14303 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_14304);
													mem_vec_14304 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_14305);
													mem_vec_14305 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_14306);
													mem_vec_14306 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_14307);
													mem_vec_14307 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_14308);
													mem_vec_14308 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_14309);
													mem_vec_14309 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_14310);
													mem_vec_14310 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_14311);
													mem_vec_14311 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_14312);
													mem_vec_14312 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_14313);
													mem_vec_14313 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_14314);
													mem_vec_14314 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_14315);
													mem_vec_14315 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_14316);
													mem_vec_14316 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_14317);
													mem_vec_14317 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_14318);
													mem_vec_14318 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_14319);
													mem_vec_14319 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_14296);
													mem_vec_14296 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_14297);
													mem_vec_14297 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_14298);
													mem_vec_14298 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_14299);
													mem_vec_14299 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_14300);
													mem_vec_14300 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_14301);
													mem_vec_14301 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_14302);
													mem_vec_14302 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_14303);
													mem_vec_14303 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_14304);
													mem_vec_14304 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_14305);
													mem_vec_14305 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_14306);
													mem_vec_14306 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_14307);
													mem_vec_14307 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_14308);
													mem_vec_14308 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_14309);
													mem_vec_14309 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_14310);
													mem_vec_14310 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_14311);
													mem_vec_14311 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_14312);
													mem_vec_14312 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_14313);
													mem_vec_14313 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_14314);
													mem_vec_14314 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_14315);
													mem_vec_14315 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_14316);
													mem_vec_14316 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_14317);
													mem_vec_14317 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_14318);
													mem_vec_14318 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_14319);
													mem_vec_14319 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14296);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14297);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14298);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14299);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14300);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14301);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14302);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14303);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14304);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14305);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14306);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14307);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14308);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14309);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14310);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14311);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14312);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14313);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14314);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14315);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14316);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_14317);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14318);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_14319);
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