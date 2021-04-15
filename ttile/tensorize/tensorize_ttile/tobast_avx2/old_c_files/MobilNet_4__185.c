#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f);
  T (32, c); T (28, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1214_p_0, cp_1, c1214, f, fp_0, f1216_p_0, f1217_p_0, fp_1, f1216_p_1, fp_2, f1216, f1217, w, wp_0, x, xp_0, x1480_p_0, x1481_p_0, xp_1, x1480_p_1, xp_2, x1480, x1481, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y732 = 0;
IND_TYPE x1482 = 0;
IND_TYPE h = 0;
IND_TYPE w628 = 0;
IND_TYPE c1215 = 0;
IND_TYPE f1218 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10328 ,mem_vec_10329 ,mem_vec_10330 ,mem_vec_10331 ,mem_vec_10332 ,mem_vec_10333 ,mem_vec_10334 ,mem_vec_10335 ,mem_vec_10336 ,mem_vec_10337 ,mem_vec_10338 ,mem_vec_10339 ,mem_vec_10340 ,mem_vec_10341 ,mem_vec_10342 ,mem_vec_10343 ,mem_vec_10344 ,mem_vec_10345 ,mem_vec_10346 ,mem_vec_10347 ,mem_vec_10348 ,mem_vec_10349 ,mem_vec_10350 ,mem_vec_10351 ,mem_vec_10352 ,mem_vec_10353 ,mem_vec_10354 ,mem_vec_10355 ,mem_vec_10356 ,mem_vec_10357 ,mem_vec_10358 ,mem_vec_10359 ,mem_vec_10360 ,mem_vec_10361 ,mem_vec_10362 ,mem_vec_10363 ,mem_vec_10364 ,mem_vec_10365 ,mem_vec_10366 ,mem_vec_10367 ,mem_vec_10368 ,mem_vec_10369 ,mem_vec_10370 ,mem_vec_10371 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f1217 = f1218, f1217_p_0 = 0;
	f1217 < f1218 + 128;
	f1217 += 64, f1217_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (x, 28) (28 / 1)
	for (x1481 = x1482, x1481_p_0 = 0;
		x1481 < x1482 + 28;
		x1481 += 1, x1481_p_0 += 1){
		// y = 28, x = 1, h = 3, w = 3, c = 128, f = 64
		// T (c, 32) (128 / 4)
		for (c1214 = c1215, c1214_p_0 = 0;
			c1214 < c1215 + 128;
			c1214 += 4, c1214_p_0 += 4){
			// y = 28, x = 1, h = 3, w = 3, c = 4, f = 64
			// T (f, 1) (64 / 64)
			for (f1216 = f1217, f1216_p_1 = f1217_p_0, f1216_p_0 = 0;
				f1216 < f1217 + 64;
				f1216 += 64, f1216_p_1 += 64, f1216_p_0 += 64){
					for (y = y732, yp_0 = 0;
						y < y732 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (x, 1) (1 / 1)
						for (x1480 = x1481, x1480_p_1 = x1481_p_0, x1480_p_0 = 0;
							x1480 < x1481 + 1;
							x1480 += 1, x1480_p_1 += 1, x1480_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1216, fp_2 = f1216_p_1, fp_1 = f1216_p_0, fp_0 = 0;
								f < f1216 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w628, wp_0 = 0;
									w < w628 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1480, xp_2 = x1480_p_1, xp_1 = x1480_p_0, xp_0 = 0;
										x < x1480 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10328 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10329 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10330 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10331 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10332 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10333 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10334 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10335 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10336 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10337 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10338 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10339 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10340 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10341 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10342 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10343 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10344 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10345 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10346 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10347 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1214, cp_1 = c1214_p_0, cp_0 = 0;
													c < c1214 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10328);
													mem_vec_10328 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10329);
													mem_vec_10329 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10330);
													mem_vec_10330 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10331);
													mem_vec_10331 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10332);
													mem_vec_10332 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10333);
													mem_vec_10333 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10334);
													mem_vec_10334 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10335);
													mem_vec_10335 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10336);
													mem_vec_10336 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10337);
													mem_vec_10337 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10338);
													mem_vec_10338 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10339);
													mem_vec_10339 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10340);
													mem_vec_10340 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10341);
													mem_vec_10341 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10342);
													mem_vec_10342 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10343);
													mem_vec_10343 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10344);
													mem_vec_10344 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10345);
													mem_vec_10345 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10346);
													mem_vec_10346 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10347);
													mem_vec_10347 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_10328);
													mem_vec_10328 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_10329);
													mem_vec_10329 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_10330);
													mem_vec_10330 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_10331);
													mem_vec_10331 = vec_36;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_10332);
													mem_vec_10332 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_10333);
													mem_vec_10333 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_10334);
													mem_vec_10334 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_10335);
													mem_vec_10335 = vec_42;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_10336);
													mem_vec_10336 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_10337);
													mem_vec_10337 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_10338);
													mem_vec_10338 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10339);
													mem_vec_10339 = vec_47;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_10340);
													mem_vec_10340 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_10341);
													mem_vec_10341 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_10342);
													mem_vec_10342 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_10343);
													mem_vec_10343 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_10344);
													mem_vec_10344 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_10345);
													mem_vec_10345 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_10346);
													mem_vec_10346 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_10347);
													mem_vec_10347 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_10328);
													mem_vec_10328 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_10329);
													mem_vec_10329 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_10330);
													mem_vec_10330 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_10331);
													mem_vec_10331 = vec_65;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_10332);
													mem_vec_10332 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_10333);
													mem_vec_10333 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_10334);
													mem_vec_10334 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_10335);
													mem_vec_10335 = vec_71;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_10336);
													mem_vec_10336 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_10337);
													mem_vec_10337 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_10338);
													mem_vec_10338 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_10339);
													mem_vec_10339 = vec_76;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_10340);
													mem_vec_10340 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_10341);
													mem_vec_10341 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_10342);
													mem_vec_10342 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_10343);
													mem_vec_10343 = vec_81;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_10344);
													mem_vec_10344 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_10345);
													mem_vec_10345 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_10346);
													mem_vec_10346 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_10347);
													mem_vec_10347 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10328);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10329);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10330);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10331);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10332);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10333);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10334);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10335);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10336);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10337);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10338);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10339);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10340);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10341);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10342);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10343);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10344);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10345);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10346);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10347);
									}
								}
							}
						}
					}
					for (y = y732 + 10, yp_0 = 0;
						y < y732 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (x, 1) (1 / 1)
						for (x1480 = x1481, x1480_p_1 = x1481_p_0, x1480_p_0 = 0;
							x1480 < x1481 + 1;
							x1480 += 1, x1480_p_1 += 1, x1480_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1216, fp_2 = f1216_p_1, fp_1 = f1216_p_0, fp_0 = 0;
								f < f1216 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w628, wp_0 = 0;
									w < w628 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1480, xp_2 = x1480_p_1, xp_1 = x1480_p_0, xp_0 = 0;
										x < x1480 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10348 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10349 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10350 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10351 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10352 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10353 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10354 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10355 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10356 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10357 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10358 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10359 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10360 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10361 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10362 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10363 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10364 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10365 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10366 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10367 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_10368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_10370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1214, cp_1 = c1214_p_0, cp_0 = 0;
													c < c1214 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10348);
													mem_vec_10348 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10349);
													mem_vec_10349 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10350);
													mem_vec_10350 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10351);
													mem_vec_10351 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10352);
													mem_vec_10352 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10353);
													mem_vec_10353 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10354);
													mem_vec_10354 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10355);
													mem_vec_10355 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10356);
													mem_vec_10356 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10357);
													mem_vec_10357 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10358);
													mem_vec_10358 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10359);
													mem_vec_10359 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10360);
													mem_vec_10360 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10361);
													mem_vec_10361 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10362);
													mem_vec_10362 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10363);
													mem_vec_10363 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10364);
													mem_vec_10364 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10365);
													mem_vec_10365 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10366);
													mem_vec_10366 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10367);
													mem_vec_10367 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10368);
													mem_vec_10368 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10369);
													mem_vec_10369 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10370);
													mem_vec_10370 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10371);
													mem_vec_10371 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_10348);
													mem_vec_10348 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_10349);
													mem_vec_10349 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_10350);
													mem_vec_10350 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_10351);
													mem_vec_10351 = vec_41;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_10352);
													mem_vec_10352 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_10353);
													mem_vec_10353 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_10354);
													mem_vec_10354 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_10355);
													mem_vec_10355 = vec_47;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_10356);
													mem_vec_10356 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_10357);
													mem_vec_10357 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_10358);
													mem_vec_10358 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_10359);
													mem_vec_10359 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_10360);
													mem_vec_10360 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_10361);
													mem_vec_10361 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_10362);
													mem_vec_10362 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_10363);
													mem_vec_10363 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_10364);
													mem_vec_10364 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_10365);
													mem_vec_10365 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_10366);
													mem_vec_10366 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_10367);
													mem_vec_10367 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_10368);
													mem_vec_10368 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_10369);
													mem_vec_10369 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_10370);
													mem_vec_10370 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_10371);
													mem_vec_10371 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_10348);
													mem_vec_10348 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_10349);
													mem_vec_10349 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_10350);
													mem_vec_10350 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_10351);
													mem_vec_10351 = vec_75;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_10352);
													mem_vec_10352 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_10353);
													mem_vec_10353 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_10354);
													mem_vec_10354 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_10355);
													mem_vec_10355 = vec_81;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_10356);
													mem_vec_10356 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_10357);
													mem_vec_10357 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_10358);
													mem_vec_10358 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_10359);
													mem_vec_10359 = vec_86;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_10360);
													mem_vec_10360 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10361);
													mem_vec_10361 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10362);
													mem_vec_10362 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_10363);
													mem_vec_10363 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_10364);
													mem_vec_10364 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_10365);
													mem_vec_10365 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_10366);
													mem_vec_10366 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_10367);
													mem_vec_10367 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_10368);
													mem_vec_10368 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_10369);
													mem_vec_10369 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_10370);
													mem_vec_10370 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_10371);
													mem_vec_10371 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10348);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10349);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10350);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10351);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10352);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10353);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10354);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10355);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10356);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10357);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10358);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10359);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10360);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10361);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10362);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10363);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10364);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10365);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10366);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10367);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10368);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10369);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10370);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10371);
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