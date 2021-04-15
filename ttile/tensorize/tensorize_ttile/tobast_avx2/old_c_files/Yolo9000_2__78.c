#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (16, y); T (1, f); T (32, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (2, f);
  T (68, x)]
*/
IND_TYPE c, cp_0, c918_p_0, cp_1, c918, f, fp_0, f790_p_0, fp_1, f790, w, wp_0, x, xp_0, x1224_p_0, x1225_p_0, xp_1, x1224_p_1, xp_2, x1224, x1225, y, yp_0, y918_p_0, yp_1, y918;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y919 = 0;
IND_TYPE x1226 = 0;
IND_TYPE h = 0;
IND_TYPE w562 = 0;
IND_TYPE c919 = 0;
IND_TYPE f791 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9328 ,mem_vec_9329 ,mem_vec_9330 ,mem_vec_9331 ,mem_vec_9332 ,mem_vec_9333 ,mem_vec_9334 ,mem_vec_9335 ,mem_vec_9336 ,mem_vec_9337 ,mem_vec_9338 ,mem_vec_9339 ,mem_vec_9340 ,mem_vec_9341 ,mem_vec_9342 ,mem_vec_9343 ,mem_vec_9344 ,mem_vec_9345 ,mem_vec_9346 ,mem_vec_9347 ,mem_vec_9348 ,mem_vec_9349 ,mem_vec_9350 ,mem_vec_9351 ,mem_vec_9352 ,mem_vec_9353 ,mem_vec_9354 ,mem_vec_9355 ,mem_vec_9356 ,mem_vec_9357 ,mem_vec_9358 ,mem_vec_9359 ,mem_vec_9360 ,mem_vec_9361 ,mem_vec_9362 ,mem_vec_9363 ,mem_vec_9364 ,mem_vec_9365 ,mem_vec_9366 ,mem_vec_9367 ,mem_vec_9368 ,mem_vec_9369 ,mem_vec_9370 ,mem_vec_9371 ,mem_vec_9372 ,mem_vec_9373 ,mem_vec_9374 ,mem_vec_9375 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 68) (272 / 4)
for (x1225 = x1226, x1225_p_0 = 0;
	x1225 < x1226 + 272;
	x1225 += 4, x1225_p_0 += 4){
	// y = 272, x = 4, h = 3, w = 3, c = 32, f = 64
	// T (f, 2) (64 / 32)
	for (f790 = f791, f790_p_0 = 0;
		f790 < f791 + 64;
		f790 += 32, f790_p_0 += 32){
			for (y918 = y919, y918_p_0 = 0;
				y918 < y919 + 160;
				y918 += 80, y918_p_0 += 80){
				// y = 16 * ph_y, x = 4, h = 3, w = 3, c = 32, f = 32
				// T (x, 1) (4 / 4)
				for (x1224 = x1225, x1224_p_1 = x1225_p_0, x1224_p_0 = 0;
					x1224 < x1225 + 4;
					x1224 += 4, x1224_p_1 += 4, x1224_p_0 += 4){
					// y = 16 * ph_y, x = 4, h = 3, w = 3, c = 32, f = 32
					// T (c, 32) (32 / 1)
					for (c918 = c919, c918_p_0 = 0;
						c918 < c919 + 32;
						c918 += 1, c918_p_0 += 1){
						// y = 16 * ph_y, x = 4, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f790, fp_1 = f790_p_0, fp_0 = 0;
							f < f790 + 32;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 16 * ph_y, x = 4, h = 3, w = 3, c = 1, f = 32
							// T (y, 16) (16 * ph_y / ph_y)
							for (y = y918, yp_1 = y918_p_0, yp_0 = 0;
								y < y918 + 80;
								y += 5, yp_1 += 5, yp_0 += 5){
								// y = ph_y, x = 4, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w562, wp_0 = 0;
									w < w562 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 1, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1224, xp_2 = x1224_p_1, xp_1 = x1224_p_0, xp_0 = 0;
										x < x1224 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9328 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9329 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9330 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9331 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_9332 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9333 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9334 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9335 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_9336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_9340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_9344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c918, cp_1 = c918_p_0, cp_0 = 0;
													c < c918 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9328);
													mem_vec_9328 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9329);
													mem_vec_9329 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9330);
													mem_vec_9330 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9331);
													mem_vec_9331 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9332);
													mem_vec_9332 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9333);
													mem_vec_9333 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9334);
													mem_vec_9334 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9335);
													mem_vec_9335 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9336);
													mem_vec_9336 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9337);
													mem_vec_9337 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9338);
													mem_vec_9338 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9339);
													mem_vec_9339 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9340);
													mem_vec_9340 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9341);
													mem_vec_9341 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9342);
													mem_vec_9342 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9343);
													mem_vec_9343 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9344);
													mem_vec_9344 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9345);
													mem_vec_9345 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9346);
													mem_vec_9346 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9347);
													mem_vec_9347 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_9328);
													mem_vec_9328 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_9329);
													mem_vec_9329 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_9330);
													mem_vec_9330 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_9331);
													mem_vec_9331 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_9332);
													mem_vec_9332 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_9333);
													mem_vec_9333 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_9334);
													mem_vec_9334 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_9335);
													mem_vec_9335 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_9336);
													mem_vec_9336 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_9337);
													mem_vec_9337 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_9338);
													mem_vec_9338 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_9339);
													mem_vec_9339 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_9340);
													mem_vec_9340 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_9341);
													mem_vec_9341 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_9342);
													mem_vec_9342 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_9343);
													mem_vec_9343 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_9344);
													mem_vec_9344 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_9345);
													mem_vec_9345 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_9346);
													mem_vec_9346 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_9347);
													mem_vec_9347 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_9328);
													mem_vec_9328 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_9329);
													mem_vec_9329 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_9330);
													mem_vec_9330 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_9331);
													mem_vec_9331 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_9332);
													mem_vec_9332 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_9333);
													mem_vec_9333 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_9334);
													mem_vec_9334 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_9335);
													mem_vec_9335 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_9336);
													mem_vec_9336 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_9337);
													mem_vec_9337 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_9338);
													mem_vec_9338 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_9339);
													mem_vec_9339 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_9340);
													mem_vec_9340 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_9341);
													mem_vec_9341 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_9342);
													mem_vec_9342 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_9343);
													mem_vec_9343 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_9344);
													mem_vec_9344 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_9345);
													mem_vec_9345 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_9346);
													mem_vec_9346 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_9347);
													mem_vec_9347 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9328);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9329);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9330);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9331);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9332);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9333);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9334);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9335);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9336);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9337);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9338);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9339);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9340);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9341);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9342);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9343);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9344);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9345);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9346);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9347);
									}
								}
							}
						}
					}
				}
			}
			for (y918 = y919 + 160, y918_p_0 = 0;
				y918 < y919 + 160 + 112;
				y918 += 112, y918_p_0 += 112){
				// y = 16 * ph_y, x = 4, h = 3, w = 3, c = 32, f = 32
				// T (x, 1) (4 / 4)
				for (x1224 = x1225, x1224_p_1 = x1225_p_0, x1224_p_0 = 0;
					x1224 < x1225 + 4;
					x1224 += 4, x1224_p_1 += 4, x1224_p_0 += 4){
					// y = 16 * ph_y, x = 4, h = 3, w = 3, c = 32, f = 32
					// T (c, 32) (32 / 1)
					for (c918 = c919, c918_p_0 = 0;
						c918 < c919 + 32;
						c918 += 1, c918_p_0 += 1){
						// y = 16 * ph_y, x = 4, h = 3, w = 3, c = 1, f = 32
						// T (f, 1) (32 / 32)
						for (f = f790, fp_1 = f790_p_0, fp_0 = 0;
							f < f790 + 32;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 16 * ph_y, x = 4, h = 3, w = 3, c = 1, f = 32
							// T (y, 16) (16 * ph_y / ph_y)
							for (y = y918, yp_1 = y918_p_0, yp_0 = 0;
								y < y918 + 112;
								y += 7, yp_1 += 7, yp_0 += 7){
								// y = ph_y, x = 4, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w562, wp_0 = 0;
									w < w562 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 1, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1224, xp_2 = x1224_p_1, xp_1 = x1224_p_0, xp_0 = 0;
										x < x1224 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9348 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9349 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9350 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9351 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_9352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_9356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_9360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_9364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_9368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_9370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_9372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_9374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c918, cp_1 = c918_p_0, cp_0 = 0;
													c < c918 + 1;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9348);
													mem_vec_9348 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9349);
													mem_vec_9349 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9350);
													mem_vec_9350 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9351);
													mem_vec_9351 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9352);
													mem_vec_9352 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9353);
													mem_vec_9353 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9354);
													mem_vec_9354 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9355);
													mem_vec_9355 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9356);
													mem_vec_9356 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9357);
													mem_vec_9357 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9358);
													mem_vec_9358 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9359);
													mem_vec_9359 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9360);
													mem_vec_9360 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9361);
													mem_vec_9361 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9362);
													mem_vec_9362 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9363);
													mem_vec_9363 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9364);
													mem_vec_9364 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9365);
													mem_vec_9365 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9366);
													mem_vec_9366 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9367);
													mem_vec_9367 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9368);
													mem_vec_9368 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9369);
													mem_vec_9369 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_9370);
													mem_vec_9370 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_9371);
													mem_vec_9371 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_9372);
													mem_vec_9372 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_9373);
													mem_vec_9373 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_9374);
													mem_vec_9374 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_9375);
													mem_vec_9375 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_9348);
													mem_vec_9348 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_9349);
													mem_vec_9349 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_9350);
													mem_vec_9350 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_9351);
													mem_vec_9351 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_9352);
													mem_vec_9352 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_9353);
													mem_vec_9353 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_9354);
													mem_vec_9354 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_9355);
													mem_vec_9355 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_9356);
													mem_vec_9356 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_9357);
													mem_vec_9357 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_9358);
													mem_vec_9358 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_9359);
													mem_vec_9359 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_9360);
													mem_vec_9360 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_9361);
													mem_vec_9361 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_9362);
													mem_vec_9362 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_9363);
													mem_vec_9363 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_9364);
													mem_vec_9364 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_9365);
													mem_vec_9365 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_9366);
													mem_vec_9366 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_9367);
													mem_vec_9367 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_9368);
													mem_vec_9368 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_9369);
													mem_vec_9369 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_9370);
													mem_vec_9370 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_9371);
													mem_vec_9371 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_9372);
													mem_vec_9372 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_9373);
													mem_vec_9373 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_9374);
													mem_vec_9374 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_9375);
													mem_vec_9375 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_9348);
													mem_vec_9348 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_9349);
													mem_vec_9349 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_9350);
													mem_vec_9350 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_9351);
													mem_vec_9351 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_9352);
													mem_vec_9352 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_9353);
													mem_vec_9353 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_9354);
													mem_vec_9354 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_9355);
													mem_vec_9355 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_9356);
													mem_vec_9356 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_9357);
													mem_vec_9357 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_9358);
													mem_vec_9358 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_9359);
													mem_vec_9359 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_9360);
													mem_vec_9360 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_9361);
													mem_vec_9361 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_9362);
													mem_vec_9362 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_9363);
													mem_vec_9363 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_9364);
													mem_vec_9364 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_9365);
													mem_vec_9365 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_9366);
													mem_vec_9366 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_9367);
													mem_vec_9367 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_9368);
													mem_vec_9368 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_9369);
													mem_vec_9369 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_9370);
													mem_vec_9370 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_9371);
													mem_vec_9371 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_9372);
													mem_vec_9372 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_9373);
													mem_vec_9373 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_9374);
													mem_vec_9374 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_9375);
													mem_vec_9375 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9348);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9349);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9350);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9351);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9352);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9353);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9354);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9355);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9356);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9357);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9358);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9359);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9360);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9361);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9362);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9363);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9364);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9365);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9366);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9367);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9368);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9369);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9370);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_9371);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9372);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_9373);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9374);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_9375);
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