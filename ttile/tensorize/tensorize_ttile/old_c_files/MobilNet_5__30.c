#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (14, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))];
  T (1, f); T (1, c); T (1, f); T (128, c); T (2, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1332_p_0, c1333_p_0, cp_1, c1332_p_1, cp_2, c1332, c1333, f, fp_0, f1172_p_0, f1173_p_0, fp_1, f1172_p_1, fp_2, f1172, f1173, w, wp_0, x, xp_0, x1044_p_0, xp_1, x1044, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y696 = 0;
IND_TYPE x1045 = 0;
IND_TYPE h = 0;
IND_TYPE w668 = 0;
IND_TYPE c1334 = 0;
IND_TYPE f1174 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10342 ,mem_vec_10343 ,mem_vec_10344 ,mem_vec_10345 ,mem_vec_10346 ,mem_vec_10347 ,mem_vec_10348 ,mem_vec_10349 ,mem_vec_10350 ,mem_vec_10351 ,mem_vec_10352 ,mem_vec_10353 ,mem_vec_10354 ,mem_vec_10355 ,mem_vec_10356 ,mem_vec_10357 ,mem_vec_10358 ,mem_vec_10359 ,mem_vec_10360 ,mem_vec_10361 ,mem_vec_10362 ,mem_vec_10363 ,mem_vec_10364 ,mem_vec_10365 ,mem_vec_10366 ,mem_vec_10367 ,mem_vec_10368 ,mem_vec_10369 ,mem_vec_10370 ,mem_vec_10371 ,mem_vec_10372 ,mem_vec_10373 ,mem_vec_10374 ,mem_vec_10375 ,mem_vec_10376 ,mem_vec_10377 ,mem_vec_10378 ,mem_vec_10379 ,mem_vec_10380 ,mem_vec_10381 ,mem_vec_10382 ,mem_vec_10383 ,mem_vec_10384 ,mem_vec_10385 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f1173 = f1174, f1173_p_0 = 0;
	f1173 < f1174 + 256;
	f1173 += 64, f1173_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (x, 2) (28 / 14)
	for (x1044 = x1045, x1044_p_0 = 0;
		x1044 < x1045 + 28;
		x1044 += 14, x1044_p_0 += 14){
		// y = 28, x = 14, h = 3, w = 3, c = 256, f = 64
		// T (c, 128) (256 / 2)
		for (c1333 = c1334, c1333_p_0 = 0;
			c1333 < c1334 + 256;
			c1333 += 2, c1333_p_0 += 2){
			// y = 28, x = 14, h = 3, w = 3, c = 2, f = 64
			// T (f, 1) (64 / 64)
			for (f1172 = f1173, f1172_p_1 = f1173_p_0, f1172_p_0 = 0;
				f1172 < f1173 + 64;
				f1172 += 64, f1172_p_1 += 64, f1172_p_0 += 64){
				// y = 28, x = 14, h = 3, w = 3, c = 2, f = 64
				// T (c, 1) (2 / 2)
				for (c1332 = c1333, c1332_p_1 = c1333_p_0, c1332_p_0 = 0;
					c1332 < c1333 + 2;
					c1332 += 2, c1332_p_1 += 2, c1332_p_0 += 2){
					// y = 28, x = 14, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1172, fp_2 = f1172_p_1, fp_1 = f1172_p_0, fp_0 = 0;
						f < f1172 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							for (y = y696, yp_0 = 0;
								y < y696 + 10;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 64
								// T (w, 3) (3 / 1)
								for (w = w668, wp_0 = 0;
									w < w668 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 14, h = 3, w = 1, c = 2, f = 64
									// T (x, 14) (14 / 1)
									for (x = x1044, xp_1 = x1044_p_0, xp_0 = 0;
										x < x1044 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10342 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10343 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10344 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_10345 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_10346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_10349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_10350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_10353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_10354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_10357 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_10358 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10359 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10360 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_10361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
												// T (c, 2) (2 / 1)
												for (c = c1332, cp_2 = c1332_p_1, cp_1 = c1332_p_0, cp_0 = 0;
													c < c1332 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10342);
													mem_vec_10342 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10343);
													mem_vec_10343 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10344);
													mem_vec_10344 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10345);
													mem_vec_10345 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10346);
													mem_vec_10346 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10347);
													mem_vec_10347 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10348);
													mem_vec_10348 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10349);
													mem_vec_10349 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10350);
													mem_vec_10350 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10351);
													mem_vec_10351 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10352);
													mem_vec_10352 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10353);
													mem_vec_10353 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10354);
													mem_vec_10354 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10355);
													mem_vec_10355 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10356);
													mem_vec_10356 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10357);
													mem_vec_10357 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10358);
													mem_vec_10358 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10359);
													mem_vec_10359 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10360);
													mem_vec_10360 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10361);
													mem_vec_10361 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_10342);
													mem_vec_10342 = vec_29;

													vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_10343);
													mem_vec_10343 = vec_32;

													vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_10344);
													mem_vec_10344 = vec_34;

													vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_10345);
													mem_vec_10345 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm512_set1_ps(scal_6);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_10346);
													mem_vec_10346 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_10347);
													mem_vec_10347 = vec_40;



													vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_10348);
													mem_vec_10348 = vec_41;



													vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_10349);
													mem_vec_10349 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_10350);
													mem_vec_10350 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_10351);
													mem_vec_10351 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_10352);
													mem_vec_10352 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_10353);
													mem_vec_10353 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_10354);
													mem_vec_10354 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_10355);
													mem_vec_10355 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_10356);
													mem_vec_10356 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_10357);
													mem_vec_10357 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_10358);
													mem_vec_10358 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_10359);
													mem_vec_10359 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_10360);
													mem_vec_10360 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_10361);
													mem_vec_10361 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm512_set1_ps(scal_10);
													vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_10342);
													mem_vec_10342 = vec_58;

													vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_10343);
													mem_vec_10343 = vec_61;

													vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_10344);
													mem_vec_10344 = vec_63;

													vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_10345);
													mem_vec_10345 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm512_set1_ps(scal_11);


													vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_10346);
													mem_vec_10346 = vec_67;



													vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_10347);
													mem_vec_10347 = vec_69;



													vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_10348);
													mem_vec_10348 = vec_70;



													vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_10349);
													mem_vec_10349 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm512_set1_ps(scal_12);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_10350);
													mem_vec_10350 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_10351);
													mem_vec_10351 = vec_74;



													vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_10352);
													mem_vec_10352 = vec_75;



													vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_10353);
													mem_vec_10353 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_10354);
													mem_vec_10354 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_10355);
													mem_vec_10355 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_10356);
													mem_vec_10356 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_10357);
													mem_vec_10357 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_10358);
													mem_vec_10358 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_10359);
													mem_vec_10359 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_10360);
													mem_vec_10360 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_10361);
													mem_vec_10361 = vec_86;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10342);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10343);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10344);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10345);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10346);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10347);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10348);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10349);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10350);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10351);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10352);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10353);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10354);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10355);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10356);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10357);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10358);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10359);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10360);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10361);
									}
								}
							}
							for (y = y696 + 10, yp_0 = 0;
								y < y696 + 10 + 18;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 64
								// T (w, 3) (3 / 1)
								for (w = w668, wp_0 = 0;
									w < w668 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 14, h = 3, w = 1, c = 2, f = 64
									// T (x, 14) (14 / 1)
									for (x = x1044, xp_1 = x1044_p_0, xp_0 = 0;
										x < x1044 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10362 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10363 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10364 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_10365 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_10366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_10369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_10370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_10373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_10374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_10377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_10378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_10381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_10382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_10385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
												// T (c, 2) (2 / 1)
												for (c = c1332, cp_2 = c1332_p_1, cp_1 = c1332_p_0, cp_0 = 0;
													c < c1332 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10362);
													mem_vec_10362 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10363);
													mem_vec_10363 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10364);
													mem_vec_10364 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10365);
													mem_vec_10365 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10366);
													mem_vec_10366 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10367);
													mem_vec_10367 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10368);
													mem_vec_10368 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10369);
													mem_vec_10369 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10370);
													mem_vec_10370 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10371);
													mem_vec_10371 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10372);
													mem_vec_10372 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10373);
													mem_vec_10373 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10374);
													mem_vec_10374 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10375);
													mem_vec_10375 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10376);
													mem_vec_10376 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10377);
													mem_vec_10377 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10378);
													mem_vec_10378 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10379);
													mem_vec_10379 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10380);
													mem_vec_10380 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10381);
													mem_vec_10381 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10382);
													mem_vec_10382 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10383);
													mem_vec_10383 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_10384);
													mem_vec_10384 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_10385);
													mem_vec_10385 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_10362);
													mem_vec_10362 = vec_34;

													vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_10363);
													mem_vec_10363 = vec_37;

													vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_10364);
													mem_vec_10364 = vec_39;

													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_10365);
													mem_vec_10365 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_10366);
													mem_vec_10366 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_10367);
													mem_vec_10367 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_10368);
													mem_vec_10368 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_10369);
													mem_vec_10369 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_10370);
													mem_vec_10370 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_10371);
													mem_vec_10371 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_10372);
													mem_vec_10372 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_10373);
													mem_vec_10373 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_10374);
													mem_vec_10374 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_10375);
													mem_vec_10375 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_10376);
													mem_vec_10376 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_10377);
													mem_vec_10377 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm512_set1_ps(scal_10);


													vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_10378);
													mem_vec_10378 = vec_58;



													vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_10379);
													mem_vec_10379 = vec_60;



													vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_10380);
													mem_vec_10380 = vec_61;



													vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_10381);
													mem_vec_10381 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm512_set1_ps(scal_11);


													vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_10382);
													mem_vec_10382 = vec_63;



													vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_10383);
													mem_vec_10383 = vec_65;



													vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_10384);
													mem_vec_10384 = vec_66;



													vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_10385);
													mem_vec_10385 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm512_set1_ps(scal_12);
													vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_10362);
													mem_vec_10362 = vec_68;

													vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_10363);
													mem_vec_10363 = vec_71;

													vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_10364);
													mem_vec_10364 = vec_73;

													vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_10365);
													mem_vec_10365 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_10366);
													mem_vec_10366 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_10367);
													mem_vec_10367 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_10368);
													mem_vec_10368 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_10369);
													mem_vec_10369 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_10370);
													mem_vec_10370 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_10371);
													mem_vec_10371 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_10372);
													mem_vec_10372 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_10373);
													mem_vec_10373 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm512_set1_ps(scal_15);


													vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_10374);
													mem_vec_10374 = vec_87;



													vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_10375);
													mem_vec_10375 = vec_89;



													vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_10376);
													mem_vec_10376 = vec_90;



													vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_10377);
													mem_vec_10377 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm512_set1_ps(scal_16);


													vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_10378);
													mem_vec_10378 = vec_92;



													vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_10379);
													mem_vec_10379 = vec_94;



													vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_10380);
													mem_vec_10380 = vec_95;



													vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_10381);
													mem_vec_10381 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm512_set1_ps(scal_17);


													vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_10382);
													mem_vec_10382 = vec_97;



													vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_10383);
													mem_vec_10383 = vec_99;



													vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_10384);
													mem_vec_10384 = vec_100;



													vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_10385);
													mem_vec_10385 = vec_101;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10362);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10363);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10364);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10365);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10366);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10367);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10368);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10369);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10370);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10371);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10372);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10373);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10374);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10375);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10376);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10377);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10378);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10379);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10380);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10381);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10382);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10383);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_10384);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_10385);
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