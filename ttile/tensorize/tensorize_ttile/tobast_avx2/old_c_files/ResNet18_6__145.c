#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, f); T (7, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f);
  T (4, c); T (4, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1110_p_0, cp_1, c1110, f, fp_0, f1084_p_0, f1085_p_0, fp_1, f1084_p_1, fp_2, f1084, f1085, w, wp_0, x, xp_0, x1372_p_0, x1373_p_0, xp_1, x1372_p_1, xp_2, x1372, x1373, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y668 = 0;
IND_TYPE x1374 = 0;
IND_TYPE h = 0;
IND_TYPE w574 = 0;
IND_TYPE c1111 = 0;
IND_TYPE f1086 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9240 ,mem_vec_9241 ,mem_vec_9242 ,mem_vec_9243 ,mem_vec_9244 ,mem_vec_9245 ,mem_vec_9246 ,mem_vec_9247 ,mem_vec_9248 ,mem_vec_9249 ,mem_vec_9250 ,mem_vec_9251 ,mem_vec_9252 ,mem_vec_9253 ,mem_vec_9254 ,mem_vec_9255 ,mem_vec_9256 ,mem_vec_9257 ,mem_vec_9258 ,mem_vec_9259 ,mem_vec_9260 ,mem_vec_9261 ,mem_vec_9262 ,mem_vec_9263 ,mem_vec_9264 ,mem_vec_9265 ,mem_vec_9266 ,mem_vec_9267 ,mem_vec_9268 ,mem_vec_9269 ,mem_vec_9270 ,mem_vec_9271 ,mem_vec_9272 ,mem_vec_9273 ,mem_vec_9274 ,mem_vec_9275 ,mem_vec_9276 ,mem_vec_9277 ,mem_vec_9278 ,mem_vec_9279 ,mem_vec_9280 ,mem_vec_9281 ,mem_vec_9282 ,mem_vec_9283 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f1085 = f1086, f1085_p_0 = 0;
	f1085 < f1086 + 128;
	f1085 += 64, f1085_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (x, 4) (28 / 7)
	for (x1373 = x1374, x1373_p_0 = 0;
		x1373 < x1374 + 28;
		x1373 += 7, x1373_p_0 += 7){
		// y = 28, x = 7, h = 3, w = 3, c = 128, f = 64
		// T (c, 4) (128 / 32)
		for (c1110 = c1111, c1110_p_0 = 0;
			c1110 < c1111 + 128;
			c1110 += 32, c1110_p_0 += 32){
			// y = 28, x = 7, h = 3, w = 3, c = 32, f = 64
			// T (f, 1) (64 / 64)
			for (f1084 = f1085, f1084_p_1 = f1085_p_0, f1084_p_0 = 0;
				f1084 < f1085 + 64;
				f1084 += 64, f1084_p_1 += 64, f1084_p_0 += 64){
					for (y = y668, yp_0 = 0;
						y < y668 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
						// T (x, 7) (7 / 1)
						for (x1372 = x1373, x1372_p_1 = x1373_p_0, x1372_p_0 = 0;
							x1372 < x1373 + 7;
							x1372 += 1, x1372_p_1 += 1, x1372_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1084, fp_2 = f1084_p_1, fp_1 = f1084_p_0, fp_0 = 0;
								f < f1084 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w574, wp_0 = 0;
									w < w574 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1372, xp_2 = x1372_p_1, xp_1 = x1372_p_0, xp_0 = 0;
										x < x1372 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9240 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9241 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9242 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9243 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_9244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_9248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_9252 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9253 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9254 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9255 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_9256 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9257 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9258 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9259 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c1110, cp_1 = c1110_p_0, cp_0 = 0;
													c < c1110 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9240);
													mem_vec_9240 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9241);
													mem_vec_9241 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9242);
													mem_vec_9242 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9243);
													mem_vec_9243 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9244);
													mem_vec_9244 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9245);
													mem_vec_9245 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9246);
													mem_vec_9246 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9247);
													mem_vec_9247 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9248);
													mem_vec_9248 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9249);
													mem_vec_9249 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9250);
													mem_vec_9250 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9251);
													mem_vec_9251 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9252);
													mem_vec_9252 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9253);
													mem_vec_9253 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9254);
													mem_vec_9254 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9255);
													mem_vec_9255 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9256);
													mem_vec_9256 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9257);
													mem_vec_9257 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9258);
													mem_vec_9258 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9259);
													mem_vec_9259 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_9240);
													mem_vec_9240 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_9241);
													mem_vec_9241 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_9242);
													mem_vec_9242 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_9243);
													mem_vec_9243 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_9244);
													mem_vec_9244 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_9245);
													mem_vec_9245 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_9246);
													mem_vec_9246 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_9247);
													mem_vec_9247 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_9248);
													mem_vec_9248 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_9249);
													mem_vec_9249 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_9250);
													mem_vec_9250 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_9251);
													mem_vec_9251 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_9252);
													mem_vec_9252 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_9253);
													mem_vec_9253 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_9254);
													mem_vec_9254 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_9255);
													mem_vec_9255 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_9256);
													mem_vec_9256 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_9257);
													mem_vec_9257 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_9258);
													mem_vec_9258 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_9259);
													mem_vec_9259 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_9240);
													mem_vec_9240 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_9241);
													mem_vec_9241 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_9242);
													mem_vec_9242 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_9243);
													mem_vec_9243 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_9244);
													mem_vec_9244 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_9245);
													mem_vec_9245 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_9246);
													mem_vec_9246 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_9247);
													mem_vec_9247 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_9248);
													mem_vec_9248 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_9249);
													mem_vec_9249 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_9250);
													mem_vec_9250 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_9251);
													mem_vec_9251 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_9252);
													mem_vec_9252 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_9253);
													mem_vec_9253 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_9254);
													mem_vec_9254 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_9255);
													mem_vec_9255 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_9256);
													mem_vec_9256 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_9257);
													mem_vec_9257 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_9258);
													mem_vec_9258 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_9259);
													mem_vec_9259 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9240);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9241);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9242);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9243);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9244);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9245);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9246);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9247);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9248);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9249);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9250);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9251);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9252);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9253);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9254);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9255);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9256);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9257);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9258);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9259);
									}
								}
							}
						}
					}
					for (y = y668 + 10, yp_0 = 0;
						y < y668 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
						// T (x, 7) (7 / 1)
						for (x1372 = x1373, x1372_p_1 = x1373_p_0, x1372_p_0 = 0;
							x1372 < x1373 + 7;
							x1372 += 1, x1372_p_1 += 1, x1372_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1084, fp_2 = f1084_p_1, fp_1 = f1084_p_0, fp_0 = 0;
								f < f1084 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w574, wp_0 = 0;
									w < w574 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1372, xp_2 = x1372_p_1, xp_1 = x1372_p_0, xp_0 = 0;
										x < x1372 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9260 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9261 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9262 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9263 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_9264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_9268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_9272 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9273 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9274 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9275 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_9276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_9280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_9282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c1110, cp_1 = c1110_p_0, cp_0 = 0;
													c < c1110 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9260);
													mem_vec_9260 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9261);
													mem_vec_9261 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9262);
													mem_vec_9262 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9263);
													mem_vec_9263 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9264);
													mem_vec_9264 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9265);
													mem_vec_9265 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9266);
													mem_vec_9266 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9267);
													mem_vec_9267 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9268);
													mem_vec_9268 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9269);
													mem_vec_9269 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9270);
													mem_vec_9270 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9271);
													mem_vec_9271 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9272);
													mem_vec_9272 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9273);
													mem_vec_9273 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9274);
													mem_vec_9274 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9275);
													mem_vec_9275 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9276);
													mem_vec_9276 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9277);
													mem_vec_9277 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9278);
													mem_vec_9278 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9279);
													mem_vec_9279 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9280);
													mem_vec_9280 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9281);
													mem_vec_9281 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_9282);
													mem_vec_9282 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_9283);
													mem_vec_9283 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_9260);
													mem_vec_9260 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_9261);
													mem_vec_9261 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_9262);
													mem_vec_9262 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_9263);
													mem_vec_9263 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_9264);
													mem_vec_9264 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_9265);
													mem_vec_9265 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_9266);
													mem_vec_9266 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_9267);
													mem_vec_9267 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_9268);
													mem_vec_9268 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_9269);
													mem_vec_9269 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_9270);
													mem_vec_9270 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_9271);
													mem_vec_9271 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_9272);
													mem_vec_9272 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_9273);
													mem_vec_9273 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_9274);
													mem_vec_9274 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_9275);
													mem_vec_9275 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_9276);
													mem_vec_9276 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_9277);
													mem_vec_9277 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_9278);
													mem_vec_9278 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_9279);
													mem_vec_9279 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_9280);
													mem_vec_9280 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_9281);
													mem_vec_9281 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_9282);
													mem_vec_9282 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_9283);
													mem_vec_9283 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_9260);
													mem_vec_9260 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_9261);
													mem_vec_9261 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_9262);
													mem_vec_9262 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_9263);
													mem_vec_9263 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_9264);
													mem_vec_9264 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_9265);
													mem_vec_9265 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_9266);
													mem_vec_9266 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_9267);
													mem_vec_9267 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_9268);
													mem_vec_9268 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_9269);
													mem_vec_9269 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_9270);
													mem_vec_9270 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_9271);
													mem_vec_9271 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_9272);
													mem_vec_9272 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_9273);
													mem_vec_9273 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_9274);
													mem_vec_9274 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_9275);
													mem_vec_9275 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_9276);
													mem_vec_9276 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_9277);
													mem_vec_9277 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_9278);
													mem_vec_9278 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_9279);
													mem_vec_9279 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_9280);
													mem_vec_9280 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_9281);
													mem_vec_9281 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_9282);
													mem_vec_9282 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_9283);
													mem_vec_9283 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9260);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9261);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9262);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9263);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9264);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9265);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9266);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9267);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9268);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9269);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9270);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9271);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9272);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9273);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9274);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9275);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9276);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9277);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9278);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9279);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9280);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9281);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9282);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_9283);
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