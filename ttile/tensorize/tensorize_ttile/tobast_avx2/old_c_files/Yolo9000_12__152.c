#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (1, c);
  T (32, f); T (34, x); T (64, c)]
*/
IND_TYPE c, cp_0, c310_p_0, c311_p_0, c312_p_0, cp_1, c310_p_1, c311_p_1, cp_2, c310_p_2, cp_3, c310, c311, c312, f, fp_0, w, wp_0, x, xp_0, x248_p_0, x249_p_0, xp_1, x248_p_1, xp_2, x248, x249, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y124 = 0;
IND_TYPE x250 = 0;
IND_TYPE h = 0;
IND_TYPE w124 = 0;
IND_TYPE c313 = 0;
IND_TYPE f124 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_2232 ,mem_vec_2233 ,mem_vec_2234 ,mem_vec_2235 ,mem_vec_2236 ,mem_vec_2237 ,mem_vec_2238 ,mem_vec_2239 ,mem_vec_2240 ,mem_vec_2241 ,mem_vec_2242 ,mem_vec_2243 ,mem_vec_2244 ,mem_vec_2245 ,mem_vec_2246 ,mem_vec_2247 ,mem_vec_2248 ,mem_vec_2249 ,mem_vec_2250 ,mem_vec_2251 ,mem_vec_2252 ,mem_vec_2253 ,mem_vec_2254 ,mem_vec_2255 ,mem_vec_2256 ,mem_vec_2257 ,mem_vec_2258 ,mem_vec_2259 ,mem_vec_2260 ,mem_vec_2261 ,mem_vec_2262 ,mem_vec_2263 ,mem_vec_2264 ,mem_vec_2265 ,mem_vec_2266 ,mem_vec_2267 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 64) (256 / 4)
for (c312 = c313, c312_p_0 = 0;
	c312 < c313 + 256;
	c312 += 4, c312_p_0 += 4){
	// y = 34, x = 34, h = 3, w = 3, c = 4, f = 512
	// T (x, 34) (34 / 1)
	for (x249 = x250, x249_p_0 = 0;
		x249 < x250 + 34;
		x249 += 1, x249_p_0 += 1){
		// y = 34, x = 1, h = 3, w = 3, c = 4, f = 512
		// T (f, 32) (512 / 16)
		for (f = f124, fp_0 = 0;
			f < f124 + 512;
			f += 16, fp_0 += 16){
			// y = 34, x = 1, h = 3, w = 3, c = 4, f = 16
			// T (c, 1) (4 / 4)
			for (c311 = c312, c311_p_1 = c312_p_0, c311_p_0 = 0;
				c311 < c312 + 4;
				c311 += 4, c311_p_1 += 4, c311_p_0 += 4){
					for (y = y124, yp_0 = 0;
						y < y124 + 24;
						y += 8, yp_0 += 8){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 16
						// T (x, 1) (1 / 1)
						for (x248 = x249, x248_p_1 = x249_p_0, x248_p_0 = 0;
							x248 < x249 + 1;
							x248 += 1, x248_p_1 += 1, x248_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 16
							// T (c, 2) (4 / 2)
							for (c310 = c311, c310_p_2 = c311_p_1, c310_p_1 = c311_p_0, c310_p_0 = 0;
								c310 < c311 + 4;
								c310 += 2, c310_p_2 += 2, c310_p_1 += 2, c310_p_0 += 2){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
								// T (w, 3) (3 / 1)
								for (w = w124, wp_0 = 0;
									w < w124 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
									// T (x, 1) (1 / 1)
									for (x = x248, xp_2 = x248_p_1, xp_1 = x248_p_0, xp_0 = 0;
										x < x248 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2232 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2233 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_2242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_2244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_2246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
												// T (c, 2) (2 / 1)
												for (c = c310, cp_3 = c310_p_2, cp_2 = c310_p_1, cp_1 = c310_p_0, cp_0 = 0;
													c < c310 + 2;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2232);
													mem_vec_2232 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2233);
													mem_vec_2233 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2234);
													mem_vec_2234 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_2235);
													mem_vec_2235 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_2236);
													mem_vec_2236 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_2237);
													mem_vec_2237 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_2238);
													mem_vec_2238 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_2239);
													mem_vec_2239 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2240);
													mem_vec_2240 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2241);
													mem_vec_2241 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_2242);
													mem_vec_2242 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_2243);
													mem_vec_2243 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_2244);
													mem_vec_2244 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_2245);
													mem_vec_2245 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_2246);
													mem_vec_2246 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_2247);
													mem_vec_2247 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_27 = _mm256_set1_ps(scal_8);
													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_2232);
													mem_vec_2232 = vec_26;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_2233);
													mem_vec_2233 = vec_29;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_32 = _mm256_set1_ps(scal_9);


													vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_2234);
													mem_vec_2234 = vec_31;



													vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_2235);
													mem_vec_2235 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_10);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_2236);
													mem_vec_2236 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_2237);
													mem_vec_2237 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_2238);
													mem_vec_2238 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_2239);
													mem_vec_2239 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_2240);
													mem_vec_2240 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_2241);
													mem_vec_2241 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_2242);
													mem_vec_2242 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_2243);
													mem_vec_2243 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_2244);
													mem_vec_2244 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_2245);
													mem_vec_2245 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_2246);
													mem_vec_2246 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_2247);
													mem_vec_2247 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_53 = _mm256_set1_ps(scal_16);
													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_2232);
													mem_vec_2232 = vec_52;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_2233);
													mem_vec_2233 = vec_55;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_17);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_2234);
													mem_vec_2234 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_2235);
													mem_vec_2235 = vec_59;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_61 = _mm256_set1_ps(scal_18);


													vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_2236);
													mem_vec_2236 = vec_60;



													vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_2237);
													mem_vec_2237 = vec_62;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_64 = _mm256_set1_ps(scal_19);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_2238);
													mem_vec_2238 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_2239);
													mem_vec_2239 = vec_65;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_67 = _mm256_set1_ps(scal_20);


													vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_2240);
													mem_vec_2240 = vec_66;



													vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_2241);
													mem_vec_2241 = vec_68;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_2242);
													mem_vec_2242 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_2243);
													mem_vec_2243 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_2244);
													mem_vec_2244 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_2245);
													mem_vec_2245 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_2246);
													mem_vec_2246 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_2247);
													mem_vec_2247 = vec_77;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2232);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2233);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2234);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2235);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2236);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2237);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2238);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2239);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2240);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2241);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2242);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2243);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2244);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2245);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2246);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_2247);
									}
								}
							}
						}
					}
					for (y = y124 + 24, yp_0 = 0;
						y < y124 + 24 + 10;
						y += 10, yp_0 += 10){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 16
						// T (x, 1) (1 / 1)
						for (x248 = x249, x248_p_1 = x249_p_0, x248_p_0 = 0;
							x248 < x249 + 1;
							x248 += 1, x248_p_1 += 1, x248_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 16
							// T (c, 2) (4 / 2)
							for (c310 = c311, c310_p_2 = c311_p_1, c310_p_1 = c311_p_0, c310_p_0 = 0;
								c310 < c311 + 4;
								c310 += 2, c310_p_2 += 2, c310_p_1 += 2, c310_p_0 += 2){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
								// T (w, 3) (3 / 1)
								for (w = w124, wp_0 = 0;
									w < w124 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
									// T (x, 1) (1 / 1)
									for (x = x248, xp_2 = x248_p_1, xp_1 = x248_p_0, xp_0 = 0;
										x < x248 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2248 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2249 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_2250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_2252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_2254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_2256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_2258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_2260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_2262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_2264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_2265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_2266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_2267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 16
												// T (c, 2) (2 / 1)
												for (c = c310, cp_3 = c310_p_2, cp_2 = c310_p_1, cp_1 = c310_p_0, cp_0 = 0;
													c < c310 + 2;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_2248);
													mem_vec_2248 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_2249);
													mem_vec_2249 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_2250);
													mem_vec_2250 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_2251);
													mem_vec_2251 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_2252);
													mem_vec_2252 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_2253);
													mem_vec_2253 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_2254);
													mem_vec_2254 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_2255);
													mem_vec_2255 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_2256);
													mem_vec_2256 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_2257);
													mem_vec_2257 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_2258);
													mem_vec_2258 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_2259);
													mem_vec_2259 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_2260);
													mem_vec_2260 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_2261);
													mem_vec_2261 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_2262);
													mem_vec_2262 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_2263);
													mem_vec_2263 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_2264);
													mem_vec_2264 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_2265);
													mem_vec_2265 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_2266);
													mem_vec_2266 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_2267);
													mem_vec_2267 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_33 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_2248);
													mem_vec_2248 = vec_32;

													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_2249);
													mem_vec_2249 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_2250);
													mem_vec_2250 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_2251);
													mem_vec_2251 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_2252);
													mem_vec_2252 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_2253);
													mem_vec_2253 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_2254);
													mem_vec_2254 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_2255);
													mem_vec_2255 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_2256);
													mem_vec_2256 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_2257);
													mem_vec_2257 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_2258);
													mem_vec_2258 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_2259);
													mem_vec_2259 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_2260);
													mem_vec_2260 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_2261);
													mem_vec_2261 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_2262);
													mem_vec_2262 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_2263);
													mem_vec_2263 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_2264);
													mem_vec_2264 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_2265);
													mem_vec_2265 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_2266);
													mem_vec_2266 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_2267);
													mem_vec_2267 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_65 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_2248);
													mem_vec_2248 = vec_64;

													vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_2249);
													mem_vec_2249 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_2250);
													mem_vec_2250 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_2251);
													mem_vec_2251 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_2252);
													mem_vec_2252 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_2253);
													mem_vec_2253 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_2254);
													mem_vec_2254 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_2255);
													mem_vec_2255 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_2256);
													mem_vec_2256 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_2257);
													mem_vec_2257 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_2258);
													mem_vec_2258 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_2259);
													mem_vec_2259 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_2260);
													mem_vec_2260 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_2261);
													mem_vec_2261 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_2262);
													mem_vec_2262 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_2263);
													mem_vec_2263 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_2264);
													mem_vec_2264 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_2265);
													mem_vec_2265 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_2266);
													mem_vec_2266 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_2267);
													mem_vec_2267 = vec_95;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2248);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_2249);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2250);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_2251);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2252);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_2253);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2254);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_2255);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2256);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_2257);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2258);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_2259);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2260);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_2261);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2262);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_2263);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2264);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_2265);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2266);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_2267);
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