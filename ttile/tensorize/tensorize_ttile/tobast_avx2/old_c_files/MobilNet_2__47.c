#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))];
  T (1, f); T (2, c); T (1, f); T (2, c); T (8, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1486_p_0, c1487_p_0, cp_1, c1486_p_1, cp_2, c1486, c1487, f, fp_0, f1412_p_0, f1413_p_0, fp_1, f1412_p_1, fp_2, f1412, f1413, h, hp_0, x, xp_0, x1230_p_0, xp_1, x1230, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y776 = 0;
IND_TYPE x1231 = 0;
IND_TYPE h560 = 0;
IND_TYPE w = 0;
IND_TYPE c1488 = 0;
IND_TYPE f1414 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_14272 ,mem_vec_14273 ,mem_vec_14274 ,mem_vec_14275 ,mem_vec_14276 ,mem_vec_14277 ,mem_vec_14278 ,mem_vec_14279 ,mem_vec_14280 ,mem_vec_14281 ,mem_vec_14282 ,mem_vec_14283 ,mem_vec_14284 ,mem_vec_14285 ,mem_vec_14286 ,mem_vec_14287 ,mem_vec_14288 ,mem_vec_14289 ,mem_vec_14290 ,mem_vec_14291 ,mem_vec_14292 ,mem_vec_14293 ,mem_vec_14294 ,mem_vec_14295 ,mem_vec_14296 ,mem_vec_14297 ,mem_vec_14298 ,mem_vec_14299 ,mem_vec_14300 ,mem_vec_14301 ,mem_vec_14302 ,mem_vec_14303 ,mem_vec_14304 ,mem_vec_14305 ,mem_vec_14306 ,mem_vec_14307 ,mem_vec_14308 ,mem_vec_14309 ,mem_vec_14310 ,mem_vec_14311 ,mem_vec_14312 ,mem_vec_14313 ,mem_vec_14314 ,mem_vec_14315 ,mem_vec_14316 ,mem_vec_14317 ,mem_vec_14318 ,mem_vec_14319 ,mem_vec_14320 ,mem_vec_14321 ,mem_vec_14322 ,mem_vec_14323 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 2) (64 / 32)
for (f1413 = f1414, f1413_p_0 = 0;
	f1413 < f1414 + 64;
	f1413 += 32, f1413_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
	// T (x, 8) (56 / 7)
	for (x1230 = x1231, x1230_p_0 = 0;
		x1230 < x1231 + 56;
		x1230 += 7, x1230_p_0 += 7){
		// y = 56, x = 7, h = 3, w = 3, c = 64, f = 32
		// T (c, 2) (64 / 32)
		for (c1487 = c1488, c1487_p_0 = 0;
			c1487 < c1488 + 64;
			c1487 += 32, c1487_p_0 += 32){
			// y = 56, x = 7, h = 3, w = 3, c = 32, f = 32
			// T (f, 1) (32 / 32)
			for (f1412 = f1413, f1412_p_1 = f1413_p_0, f1412_p_0 = 0;
				f1412 < f1413 + 32;
				f1412 += 32, f1412_p_1 += 32, f1412_p_0 += 32){
				// y = 56, x = 7, h = 3, w = 3, c = 32, f = 32
				// T (c, 2) (32 / 16)
				for (c1486 = c1487, c1486_p_1 = c1487_p_0, c1486_p_0 = 0;
					c1486 < c1487 + 32;
					c1486 += 16, c1486_p_1 += 16, c1486_p_0 += 16){
					// y = 56, x = 7, h = 3, w = 3, c = 16, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1412, fp_2 = f1412_p_1, fp_1 = f1412_p_0, fp_0 = 0;
						f < f1412 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y776, yp_0 = 0;
								y < y776 + 42;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h560, hp_0 = 0;
									h < h560 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
									// T (x, 7) (7 / 1)
									for (x = x1230, xp_1 = x1230_p_0, xp_0 = 0;
										x < x1230 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_14272 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_14273 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_14274 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_14275 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_14276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_14277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_14278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_14279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_14280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_14281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_14282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_14283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_14284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_14285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_14286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_14287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_14288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_14289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_14290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_14291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_14292 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_14293 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_14294 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_14295 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1486, cp_2 = c1486_p_1, cp_1 = c1486_p_0, cp_0 = 0;
													c < c1486 + 16;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14272);
													mem_vec_14272 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14273);
													mem_vec_14273 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14274);
													mem_vec_14274 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14275);
													mem_vec_14275 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14276);
													mem_vec_14276 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14277);
													mem_vec_14277 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14278);
													mem_vec_14278 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14279);
													mem_vec_14279 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14280);
													mem_vec_14280 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14281);
													mem_vec_14281 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14282);
													mem_vec_14282 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14283);
													mem_vec_14283 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14284);
													mem_vec_14284 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14285);
													mem_vec_14285 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14286);
													mem_vec_14286 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14287);
													mem_vec_14287 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14288);
													mem_vec_14288 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14289);
													mem_vec_14289 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14290);
													mem_vec_14290 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14291);
													mem_vec_14291 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_14292);
													mem_vec_14292 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_14293);
													mem_vec_14293 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_14294);
													mem_vec_14294 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_14295);
													mem_vec_14295 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_14272);
													mem_vec_14272 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_14273);
													mem_vec_14273 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_14274);
													mem_vec_14274 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_14275);
													mem_vec_14275 = vec_41;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_14276);
													mem_vec_14276 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_14277);
													mem_vec_14277 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_14278);
													mem_vec_14278 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_14279);
													mem_vec_14279 = vec_47;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_14280);
													mem_vec_14280 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_14281);
													mem_vec_14281 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_14282);
													mem_vec_14282 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_14283);
													mem_vec_14283 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_14284);
													mem_vec_14284 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_14285);
													mem_vec_14285 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_14286);
													mem_vec_14286 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_14287);
													mem_vec_14287 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_14288);
													mem_vec_14288 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_14289);
													mem_vec_14289 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_14290);
													mem_vec_14290 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_14291);
													mem_vec_14291 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_14292);
													mem_vec_14292 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_14293);
													mem_vec_14293 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_14294);
													mem_vec_14294 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_14295);
													mem_vec_14295 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_14272);
													mem_vec_14272 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_14273);
													mem_vec_14273 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_14274);
													mem_vec_14274 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_14275);
													mem_vec_14275 = vec_75;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_14276);
													mem_vec_14276 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_14277);
													mem_vec_14277 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_14278);
													mem_vec_14278 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_14279);
													mem_vec_14279 = vec_81;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_14280);
													mem_vec_14280 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_14281);
													mem_vec_14281 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_14282);
													mem_vec_14282 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_14283);
													mem_vec_14283 = vec_86;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_14284);
													mem_vec_14284 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_14285);
													mem_vec_14285 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_14286);
													mem_vec_14286 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_14287);
													mem_vec_14287 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_14288);
													mem_vec_14288 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_14289);
													mem_vec_14289 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_14290);
													mem_vec_14290 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_14291);
													mem_vec_14291 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_14292);
													mem_vec_14292 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_14293);
													mem_vec_14293 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_14294);
													mem_vec_14294 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_14295);
													mem_vec_14295 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14272);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14273);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14274);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14275);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14276);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14277);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14278);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14279);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14280);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14281);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14282);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14283);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14284);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14285);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14286);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14287);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14288);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14289);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14290);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14291);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14292);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_14293);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14294);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_14295);
									}
								}
							}
							for (y = y776 + 42, yp_0 = 0;
								y < y776 + 42 + 14;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h560, hp_0 = 0;
									h < h560 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 32
									// T (x, 7) (7 / 1)
									for (x = x1230, xp_1 = x1230_p_0, xp_0 = 0;
										x < x1230 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
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
												mem_vec_14320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_14321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_14322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_14323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1486, cp_2 = c1486_p_1, cp_1 = c1486_p_0, cp_0 = 0;
													c < c1486 + 16;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
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
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14300);
													mem_vec_14300 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14301);
													mem_vec_14301 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14302);
													mem_vec_14302 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14303);
													mem_vec_14303 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14304);
													mem_vec_14304 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14305);
													mem_vec_14305 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14306);
													mem_vec_14306 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14307);
													mem_vec_14307 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14308);
													mem_vec_14308 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14309);
													mem_vec_14309 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14310);
													mem_vec_14310 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14311);
													mem_vec_14311 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14312);
													mem_vec_14312 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14313);
													mem_vec_14313 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14314);
													mem_vec_14314 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14315);
													mem_vec_14315 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_14316);
													mem_vec_14316 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_14317);
													mem_vec_14317 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_14318);
													mem_vec_14318 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_14319);
													mem_vec_14319 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_14320);
													mem_vec_14320 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_14321);
													mem_vec_14321 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_14322);
													mem_vec_14322 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_14323);
													mem_vec_14323 = vec_38;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_14296);
													mem_vec_14296 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_14297);
													mem_vec_14297 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_14298);
													mem_vec_14298 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_14299);
													mem_vec_14299 = vec_46;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_14300);
													mem_vec_14300 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_14301);
													mem_vec_14301 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_14302);
													mem_vec_14302 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_14303);
													mem_vec_14303 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_14304);
													mem_vec_14304 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_14305);
													mem_vec_14305 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_14306);
													mem_vec_14306 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_14307);
													mem_vec_14307 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_14308);
													mem_vec_14308 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_14309);
													mem_vec_14309 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_14310);
													mem_vec_14310 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_14311);
													mem_vec_14311 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_14312);
													mem_vec_14312 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_14313);
													mem_vec_14313 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_14314);
													mem_vec_14314 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_14315);
													mem_vec_14315 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_14316);
													mem_vec_14316 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_14317);
													mem_vec_14317 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_14318);
													mem_vec_14318 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_14319);
													mem_vec_14319 = vec_72;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_14320);
													mem_vec_14320 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_14321);
													mem_vec_14321 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_14322);
													mem_vec_14322 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_14323);
													mem_vec_14323 = vec_77;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_14296);
													mem_vec_14296 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_14297);
													mem_vec_14297 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_14298);
													mem_vec_14298 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_14299);
													mem_vec_14299 = vec_85;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_14300);
													mem_vec_14300 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_14301);
													mem_vec_14301 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_14302);
													mem_vec_14302 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_14303);
													mem_vec_14303 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_14304);
													mem_vec_14304 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_14305);
													mem_vec_14305 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_14306);
													mem_vec_14306 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_14307);
													mem_vec_14307 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_14308);
													mem_vec_14308 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_14309);
													mem_vec_14309 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_14310);
													mem_vec_14310 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_14311);
													mem_vec_14311 = vec_101;
													scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_14312);
													mem_vec_14312 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_14313);
													mem_vec_14313 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_14314);
													mem_vec_14314 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_14315);
													mem_vec_14315 = vec_106;
													scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_14316);
													mem_vec_14316 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_14317);
													mem_vec_14317 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_14318);
													mem_vec_14318 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_14319);
													mem_vec_14319 = vec_111;
													scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_14320);
													mem_vec_14320 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_14321);
													mem_vec_14321 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_14322);
													mem_vec_14322 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_14323);
													mem_vec_14323 = vec_116;
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
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14320);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_14321);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14322);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_14323);
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