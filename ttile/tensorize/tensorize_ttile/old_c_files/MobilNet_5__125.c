#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))];
  T (1, f); T (2, c); T (1, f); T (32, c); T (14, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1428_p_0, c1429_p_0, cp_1, c1428_p_1, cp_2, c1428, c1429, f, fp_0, f1268_p_0, f1269_p_0, fp_1, f1268_p_1, fp_2, f1268, f1269, w, wp_0, x, xp_0, x1116_p_0, xp_1, x1116, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y744 = 0;
IND_TYPE x1117 = 0;
IND_TYPE h = 0;
IND_TYPE w716 = 0;
IND_TYPE c1430 = 0;
IND_TYPE f1270 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11398 ,mem_vec_11399 ,mem_vec_11400 ,mem_vec_11401 ,mem_vec_11402 ,mem_vec_11403 ,mem_vec_11404 ,mem_vec_11405 ,mem_vec_11406 ,mem_vec_11407 ,mem_vec_11408 ,mem_vec_11409 ,mem_vec_11410 ,mem_vec_11411 ,mem_vec_11412 ,mem_vec_11413 ,mem_vec_11414 ,mem_vec_11415 ,mem_vec_11416 ,mem_vec_11417 ,mem_vec_11418 ,mem_vec_11419 ,mem_vec_11420 ,mem_vec_11421 ,mem_vec_11422 ,mem_vec_11423 ,mem_vec_11424 ,mem_vec_11425 ,mem_vec_11426 ,mem_vec_11427 ,mem_vec_11428 ,mem_vec_11429 ,mem_vec_11430 ,mem_vec_11431 ,mem_vec_11432 ,mem_vec_11433 ,mem_vec_11434 ,mem_vec_11435 ,mem_vec_11436 ,mem_vec_11437 ,mem_vec_11438 ,mem_vec_11439 ,mem_vec_11440 ,mem_vec_11441 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f1269 = f1270, f1269_p_0 = 0;
	f1269 < f1270 + 256;
	f1269 += 64, f1269_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (x, 14) (28 / 2)
	for (x1116 = x1117, x1116_p_0 = 0;
		x1116 < x1117 + 28;
		x1116 += 2, x1116_p_0 += 2){
		// y = 28, x = 2, h = 3, w = 3, c = 256, f = 64
		// T (c, 32) (256 / 8)
		for (c1429 = c1430, c1429_p_0 = 0;
			c1429 < c1430 + 256;
			c1429 += 8, c1429_p_0 += 8){
			// y = 28, x = 2, h = 3, w = 3, c = 8, f = 64
			// T (f, 1) (64 / 64)
			for (f1268 = f1269, f1268_p_1 = f1269_p_0, f1268_p_0 = 0;
				f1268 < f1269 + 64;
				f1268 += 64, f1268_p_1 += 64, f1268_p_0 += 64){
				// y = 28, x = 2, h = 3, w = 3, c = 8, f = 64
				// T (c, 2) (8 / 4)
				for (c1428 = c1429, c1428_p_1 = c1429_p_0, c1428_p_0 = 0;
					c1428 < c1429 + 8;
					c1428 += 4, c1428_p_1 += 4, c1428_p_0 += 4){
					// y = 28, x = 2, h = 3, w = 3, c = 4, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1268, fp_2 = f1268_p_1, fp_1 = f1268_p_0, fp_0 = 0;
						f < f1268 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							for (y = y744, yp_0 = 0;
								y < y744 + 10;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w716, wp_0 = 0;
									w < w716 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 64
									// T (x, 2) (2 / 1)
									for (x = x1116, xp_1 = x1116_p_0, xp_0 = 0;
										x < x1116 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11398 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11399 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11400 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_11401 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_11402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_11405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_11406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_11409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_11410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_11413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_11414 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11415 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_11417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c1428, cp_2 = c1428_p_1, cp_1 = c1428_p_0, cp_0 = 0;
													c < c1428 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11398);
													mem_vec_11398 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11399);
													mem_vec_11399 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11400);
													mem_vec_11400 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11401);
													mem_vec_11401 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11402);
													mem_vec_11402 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11403);
													mem_vec_11403 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11404);
													mem_vec_11404 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11405);
													mem_vec_11405 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11406);
													mem_vec_11406 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11407);
													mem_vec_11407 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11408);
													mem_vec_11408 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11409);
													mem_vec_11409 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11410);
													mem_vec_11410 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11411);
													mem_vec_11411 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11412);
													mem_vec_11412 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11413);
													mem_vec_11413 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11414);
													mem_vec_11414 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11415);
													mem_vec_11415 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11416);
													mem_vec_11416 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11417);
													mem_vec_11417 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_11398);
													mem_vec_11398 = vec_29;

													vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_11399);
													mem_vec_11399 = vec_32;

													vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_11400);
													mem_vec_11400 = vec_34;

													vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_11401);
													mem_vec_11401 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm512_set1_ps(scal_6);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_11402);
													mem_vec_11402 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_11403);
													mem_vec_11403 = vec_40;



													vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_11404);
													mem_vec_11404 = vec_41;



													vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_11405);
													mem_vec_11405 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_11406);
													mem_vec_11406 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_11407);
													mem_vec_11407 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_11408);
													mem_vec_11408 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_11409);
													mem_vec_11409 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_11410);
													mem_vec_11410 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_11411);
													mem_vec_11411 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_11412);
													mem_vec_11412 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_11413);
													mem_vec_11413 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_11414);
													mem_vec_11414 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_11415);
													mem_vec_11415 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_11416);
													mem_vec_11416 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_11417);
													mem_vec_11417 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm512_set1_ps(scal_10);
													vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_11398);
													mem_vec_11398 = vec_58;

													vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_11399);
													mem_vec_11399 = vec_61;

													vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_11400);
													mem_vec_11400 = vec_63;

													vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_11401);
													mem_vec_11401 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm512_set1_ps(scal_11);


													vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_11402);
													mem_vec_11402 = vec_67;



													vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_11403);
													mem_vec_11403 = vec_69;



													vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_11404);
													mem_vec_11404 = vec_70;



													vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_11405);
													mem_vec_11405 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm512_set1_ps(scal_12);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_11406);
													mem_vec_11406 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_11407);
													mem_vec_11407 = vec_74;



													vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_11408);
													mem_vec_11408 = vec_75;



													vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_11409);
													mem_vec_11409 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_11410);
													mem_vec_11410 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_11411);
													mem_vec_11411 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_11412);
													mem_vec_11412 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_11413);
													mem_vec_11413 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_11414);
													mem_vec_11414 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_11415);
													mem_vec_11415 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_11416);
													mem_vec_11416 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_11417);
													mem_vec_11417 = vec_86;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11398);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11399);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11400);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11401);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11402);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11403);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11404);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11405);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11406);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11407);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11408);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11409);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11410);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11411);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11412);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11413);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11414);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11415);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11416);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11417);
									}
								}
							}
							for (y = y744 + 10, yp_0 = 0;
								y < y744 + 10 + 18;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 64
								// T (w, 3) (3 / 1)
								for (w = w716, wp_0 = 0;
									w < w716 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 64
									// T (x, 2) (2 / 1)
									for (x = x1116, xp_1 = x1116_p_0, xp_0 = 0;
										x < x1116 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11418 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11419 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11420 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_11421 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_11422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_11425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_11426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_11429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_11430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_11433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_11434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_11437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_11438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_11441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
												// T (c, 4) (4 / 1)
												for (c = c1428, cp_2 = c1428_p_1, cp_1 = c1428_p_0, cp_0 = 0;
													c < c1428 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11418);
													mem_vec_11418 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11419);
													mem_vec_11419 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11420);
													mem_vec_11420 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11421);
													mem_vec_11421 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11422);
													mem_vec_11422 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11423);
													mem_vec_11423 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11424);
													mem_vec_11424 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11425);
													mem_vec_11425 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11426);
													mem_vec_11426 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11427);
													mem_vec_11427 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11428);
													mem_vec_11428 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11429);
													mem_vec_11429 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11430);
													mem_vec_11430 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11431);
													mem_vec_11431 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11432);
													mem_vec_11432 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11433);
													mem_vec_11433 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11434);
													mem_vec_11434 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11435);
													mem_vec_11435 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11436);
													mem_vec_11436 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11437);
													mem_vec_11437 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11438);
													mem_vec_11438 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11439);
													mem_vec_11439 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11440);
													mem_vec_11440 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11441);
													mem_vec_11441 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_11418);
													mem_vec_11418 = vec_34;

													vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_11419);
													mem_vec_11419 = vec_37;

													vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_11420);
													mem_vec_11420 = vec_39;

													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_11421);
													mem_vec_11421 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_11422);
													mem_vec_11422 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_11423);
													mem_vec_11423 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_11424);
													mem_vec_11424 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_11425);
													mem_vec_11425 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_11426);
													mem_vec_11426 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_11427);
													mem_vec_11427 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_11428);
													mem_vec_11428 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_11429);
													mem_vec_11429 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_11430);
													mem_vec_11430 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_11431);
													mem_vec_11431 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_11432);
													mem_vec_11432 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_11433);
													mem_vec_11433 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm512_set1_ps(scal_10);


													vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_11434);
													mem_vec_11434 = vec_58;



													vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_11435);
													mem_vec_11435 = vec_60;



													vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_11436);
													mem_vec_11436 = vec_61;



													vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_11437);
													mem_vec_11437 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm512_set1_ps(scal_11);


													vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_11438);
													mem_vec_11438 = vec_63;



													vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_11439);
													mem_vec_11439 = vec_65;



													vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_11440);
													mem_vec_11440 = vec_66;



													vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_11441);
													mem_vec_11441 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm512_set1_ps(scal_12);
													vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_11418);
													mem_vec_11418 = vec_68;

													vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_11419);
													mem_vec_11419 = vec_71;

													vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_11420);
													mem_vec_11420 = vec_73;

													vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_11421);
													mem_vec_11421 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_11422);
													mem_vec_11422 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_11423);
													mem_vec_11423 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_11424);
													mem_vec_11424 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_11425);
													mem_vec_11425 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_11426);
													mem_vec_11426 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_11427);
													mem_vec_11427 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_11428);
													mem_vec_11428 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_11429);
													mem_vec_11429 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm512_set1_ps(scal_15);


													vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_11430);
													mem_vec_11430 = vec_87;



													vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_11431);
													mem_vec_11431 = vec_89;



													vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_11432);
													mem_vec_11432 = vec_90;



													vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_11433);
													mem_vec_11433 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm512_set1_ps(scal_16);


													vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_11434);
													mem_vec_11434 = vec_92;



													vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_11435);
													mem_vec_11435 = vec_94;



													vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_11436);
													mem_vec_11436 = vec_95;



													vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_11437);
													mem_vec_11437 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm512_set1_ps(scal_17);


													vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_11438);
													mem_vec_11438 = vec_97;



													vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_11439);
													mem_vec_11439 = vec_99;



													vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_11440);
													mem_vec_11440 = vec_100;



													vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_11441);
													mem_vec_11441 = vec_101;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11418);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11419);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11420);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11421);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11422);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11423);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11424);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11425);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11426);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11427);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11428);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11429);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11430);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11431);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11432);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11433);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11434);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11435);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11436);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11437);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11438);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11439);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_11440);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_11441);
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