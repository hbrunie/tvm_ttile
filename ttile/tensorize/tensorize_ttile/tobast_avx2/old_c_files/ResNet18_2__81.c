#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (1, x);
  T (3, w); Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))];
  T (1, f); T (64, c); T (2, f); T (1, c); T (56, x); T (1, f)]
*/
IND_TYPE c, cp_0, c916_p_0, c917_p_0, cp_1, c916_p_1, cp_2, c916, c917, f, fp_0, f820_p_0, f821_p_0, fp_1, f820_p_1, fp_2, f820, f821, w, wp_0, x, xp_0, x834_p_0, xp_1, x834, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y500 = 0;
IND_TYPE x835 = 0;
IND_TYPE h = 0;
IND_TYPE w414 = 0;
IND_TYPE c918 = 0;
IND_TYPE f822 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7216 ,mem_vec_7217 ,mem_vec_7218 ,mem_vec_7219 ,mem_vec_7220 ,mem_vec_7221 ,mem_vec_7222 ,mem_vec_7223 ,mem_vec_7224 ,mem_vec_7225 ,mem_vec_7226 ,mem_vec_7227 ,mem_vec_7228 ,mem_vec_7229 ,mem_vec_7230 ,mem_vec_7231 ,mem_vec_7232 ,mem_vec_7233 ,mem_vec_7234 ,mem_vec_7235 ,mem_vec_7236 ,mem_vec_7237 ,mem_vec_7238 ,mem_vec_7239 ,mem_vec_7240 ,mem_vec_7241 ,mem_vec_7242 ,mem_vec_7243 ,mem_vec_7244 ,mem_vec_7245 ,mem_vec_7246 ,mem_vec_7247 ,mem_vec_7248 ,mem_vec_7249 ,mem_vec_7250 ,mem_vec_7251 ,mem_vec_7252 ,mem_vec_7253 ,mem_vec_7254 ,mem_vec_7255 ,mem_vec_7256 ,mem_vec_7257 ,mem_vec_7258 ,mem_vec_7259 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f821 = f822, f821_p_0 = 0;
	f821 < f822 + 64;
	f821 += 64, f821_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x834 = x835, x834_p_0 = 0;
		x834 < x835 + 56;
		x834 += 1, x834_p_0 += 1){
		// y = 56, x = 1, h = 3, w = 3, c = 64, f = 64
		// T (c, 1) (64 / 64)
		for (c917 = c918, c917_p_0 = 0;
			c917 < c918 + 64;
			c917 += 64, c917_p_0 += 64){
			// y = 56, x = 1, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f820 = f821, f820_p_1 = f821_p_0, f820_p_0 = 0;
				f820 < f821 + 64;
				f820 += 32, f820_p_1 += 32, f820_p_0 += 32){
				// y = 56, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (c, 64) (64 / 1)
				for (c916 = c917, c916_p_1 = c917_p_0, c916_p_0 = 0;
					c916 < c917 + 64;
					c916 += 1, c916_p_1 += 1, c916_p_0 += 1){
					// y = 56, x = 1, h = 3, w = 3, c = 1, f = 32
					// T (f, 1) (32 / 32)
					for (f = f820, fp_2 = f820_p_1, fp_1 = f820_p_0, fp_0 = 0;
						f < f820 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y500, yp_0 = 0;
								y < y500 + 28;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w414, wp_0 = 0;
									w < w414 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x834, xp_1 = x834_p_0, xp_0 = 0;
										x < x834 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7216 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7217 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_7218 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7219 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_7220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_7222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_7224 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7225 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_7226 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7227 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_7228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_7230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c916, cp_2 = c916_p_1, cp_1 = c916_p_0, cp_0 = 0;
													c < c916 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7216);
													mem_vec_7216 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7217);
													mem_vec_7217 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7218);
													mem_vec_7218 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7219);
													mem_vec_7219 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7220);
													mem_vec_7220 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7221);
													mem_vec_7221 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7222);
													mem_vec_7222 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7223);
													mem_vec_7223 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7224);
													mem_vec_7224 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7225);
													mem_vec_7225 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7226);
													mem_vec_7226 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7227);
													mem_vec_7227 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7228);
													mem_vec_7228 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7229);
													mem_vec_7229 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7230);
													mem_vec_7230 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7231);
													mem_vec_7231 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_7216);
													mem_vec_7216 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_7217);
													mem_vec_7217 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_7218);
													mem_vec_7218 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_7219);
													mem_vec_7219 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_7220);
													mem_vec_7220 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_7221);
													mem_vec_7221 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_7222);
													mem_vec_7222 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_7223);
													mem_vec_7223 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_7224);
													mem_vec_7224 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_7225);
													mem_vec_7225 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_7226);
													mem_vec_7226 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_7227);
													mem_vec_7227 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_7228);
													mem_vec_7228 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7229);
													mem_vec_7229 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7230);
													mem_vec_7230 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_7231);
													mem_vec_7231 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_7216);
													mem_vec_7216 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_7217);
													mem_vec_7217 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_7218);
													mem_vec_7218 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_7219);
													mem_vec_7219 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_7220);
													mem_vec_7220 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_7221);
													mem_vec_7221 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7222);
													mem_vec_7222 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7223);
													mem_vec_7223 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_7224);
													mem_vec_7224 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_7225);
													mem_vec_7225 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_7226);
													mem_vec_7226 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_7227);
													mem_vec_7227 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_7228);
													mem_vec_7228 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_7229);
													mem_vec_7229 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_7230);
													mem_vec_7230 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_7231);
													mem_vec_7231 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7216);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7217);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7218);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7219);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7220);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7221);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7222);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7223);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7224);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7225);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7226);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7227);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7228);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7229);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7230);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7231);
									}
								}
							}
							for (y = y500 + 28, yp_0 = 0;
								y < y500 + 28 + 28;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 1, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w414, wp_0 = 0;
									w < w414 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
									// T (x, 1) (1 / 1)
									for (x = x834, xp_1 = x834_p_0, xp_0 = 0;
										x < x834 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7232 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7233 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_7234 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7235 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_7236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_7238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_7240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_7242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_7244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_7246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_7248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_7249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_7250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_7251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_7252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_7253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_7254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_7255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_7256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_7257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_7258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_7259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c916, cp_2 = c916_p_1, cp_1 = c916_p_0, cp_0 = 0;
													c < c916 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7232);
													mem_vec_7232 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7233);
													mem_vec_7233 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7234);
													mem_vec_7234 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7235);
													mem_vec_7235 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7236);
													mem_vec_7236 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7237);
													mem_vec_7237 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7238);
													mem_vec_7238 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7239);
													mem_vec_7239 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7240);
													mem_vec_7240 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7241);
													mem_vec_7241 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7242);
													mem_vec_7242 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7243);
													mem_vec_7243 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7244);
													mem_vec_7244 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7245);
													mem_vec_7245 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7246);
													mem_vec_7246 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7247);
													mem_vec_7247 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7248);
													mem_vec_7248 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7249);
													mem_vec_7249 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7250);
													mem_vec_7250 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7251);
													mem_vec_7251 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7252);
													mem_vec_7252 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7253);
													mem_vec_7253 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_7254);
													mem_vec_7254 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_7255);
													mem_vec_7255 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_7256);
													mem_vec_7256 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_7257);
													mem_vec_7257 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_7258);
													mem_vec_7258 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_7259);
													mem_vec_7259 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_7232);
													mem_vec_7232 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_7233);
													mem_vec_7233 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_7234);
													mem_vec_7234 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_7235);
													mem_vec_7235 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_7236);
													mem_vec_7236 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_7237);
													mem_vec_7237 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_7238);
													mem_vec_7238 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_7239);
													mem_vec_7239 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_7240);
													mem_vec_7240 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_7241);
													mem_vec_7241 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_7242);
													mem_vec_7242 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_7243);
													mem_vec_7243 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_7244);
													mem_vec_7244 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_7245);
													mem_vec_7245 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_7246);
													mem_vec_7246 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_7247);
													mem_vec_7247 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_7248);
													mem_vec_7248 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_7249);
													mem_vec_7249 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_7250);
													mem_vec_7250 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_7251);
													mem_vec_7251 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_7252);
													mem_vec_7252 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_7253);
													mem_vec_7253 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_7254);
													mem_vec_7254 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_7255);
													mem_vec_7255 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_7256);
													mem_vec_7256 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_7257);
													mem_vec_7257 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_7258);
													mem_vec_7258 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_7259);
													mem_vec_7259 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_7232);
													mem_vec_7232 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_7233);
													mem_vec_7233 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_7234);
													mem_vec_7234 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_7235);
													mem_vec_7235 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_7236);
													mem_vec_7236 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_7237);
													mem_vec_7237 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_7238);
													mem_vec_7238 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_7239);
													mem_vec_7239 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_7240);
													mem_vec_7240 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_7241);
													mem_vec_7241 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_7242);
													mem_vec_7242 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_7243);
													mem_vec_7243 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_7244);
													mem_vec_7244 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_7245);
													mem_vec_7245 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_7246);
													mem_vec_7246 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_7247);
													mem_vec_7247 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_7248);
													mem_vec_7248 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_7249);
													mem_vec_7249 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_7250);
													mem_vec_7250 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_7251);
													mem_vec_7251 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_7252);
													mem_vec_7252 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_7253);
													mem_vec_7253 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_7254);
													mem_vec_7254 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_7255);
													mem_vec_7255 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_7256);
													mem_vec_7256 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_7257);
													mem_vec_7257 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_7258);
													mem_vec_7258 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_7259);
													mem_vec_7259 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7232);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7233);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7234);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7235);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7236);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7237);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7238);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7239);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7240);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7241);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7242);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7243);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7244);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7245);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7246);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7247);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7248);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7249);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7250);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7251);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7252);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7253);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7254);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_7255);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7256);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_7257);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7258);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_7259);
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