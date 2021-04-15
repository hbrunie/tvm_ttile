#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (28, x)]
*/
IND_TYPE c, cp_0, c1268_p_0, cp_1, c1268, f, fp_0, h, hp_0, x, xp_0, x1518_p_0, x1519_p_0, xp_1, x1518_p_1, xp_2, x1518, x1519, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y796 = 0;
IND_TYPE x1520 = 0;
IND_TYPE h594 = 0;
IND_TYPE w = 0;
IND_TYPE c1269 = 0;
IND_TYPE f870 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_12372 ,mem_vec_12373 ,mem_vec_12374 ,mem_vec_12375 ,mem_vec_12376 ,mem_vec_12377 ,mem_vec_12378 ,mem_vec_12379 ,mem_vec_12380 ,mem_vec_12381 ,mem_vec_12382 ,mem_vec_12383 ,mem_vec_12384 ,mem_vec_12385 ,mem_vec_12386 ,mem_vec_12387 ,mem_vec_12388 ,mem_vec_12389 ,mem_vec_12390 ,mem_vec_12391 ,mem_vec_12392 ,mem_vec_12393 ,mem_vec_12394 ,mem_vec_12395 ,mem_vec_12396 ,mem_vec_12397 ,mem_vec_12398 ,mem_vec_12399 ,mem_vec_12400 ,mem_vec_12401 ,mem_vec_12402 ,mem_vec_12403 ,mem_vec_12404 ,mem_vec_12405 ,mem_vec_12406 ,mem_vec_12407 ,mem_vec_12408 ,mem_vec_12409 ,mem_vec_12410 ,mem_vec_12411 ,mem_vec_12412 ,mem_vec_12413 ,mem_vec_12414 ,mem_vec_12415 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (x, 28) (28 / 1)
for (x1519 = x1520, x1519_p_0 = 0;
	x1519 < x1520 + 28;
	x1519 += 1, x1519_p_0 += 1){
	// y = 28, x = 1, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f = f870, fp_0 = 0;
		f < f870 + 128;
		f += 32, fp_0 += 32){
			for (y = y796, yp_0 = 0;
				y < y796 + 10;
				y += 5, yp_0 += 5){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (x, 1) (1 / 1)
				for (x1518 = x1519, x1518_p_1 = x1519_p_0, x1518_p_0 = 0;
					x1518 < x1519 + 1;
					x1518 += 1, x1518_p_1 += 1, x1518_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c1268 = c1269, c1268_p_0 = 0;
						c1268 < c1269 + 64;
						c1268 += 64, c1268_p_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h594, hp_0 = 0;
							h < h594 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
							// T (x, 1) (1 / 1)
							for (x = x1518, xp_2 = x1518_p_1, xp_1 = x1518_p_0, xp_0 = 0;
								x < x1518 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_12372 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_12373 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_12374 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_12375 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_12376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_12377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_12378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_12379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_12380 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_12381 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_12382 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_12383 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_12384 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_12385 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_12386 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_12387 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_12388 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_12389 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_12390 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_12391 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c1268, cp_1 = c1268_p_0, cp_0 = 0;
											c < c1268 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12372);
											mem_vec_12372 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12373);
											mem_vec_12373 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12374);
											mem_vec_12374 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12375);
											mem_vec_12375 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12376);
											mem_vec_12376 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12377);
											mem_vec_12377 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12378);
											mem_vec_12378 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12379);
											mem_vec_12379 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12380);
											mem_vec_12380 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12381);
											mem_vec_12381 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12382);
											mem_vec_12382 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12383);
											mem_vec_12383 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12384);
											mem_vec_12384 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12385);
											mem_vec_12385 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12386);
											mem_vec_12386 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12387);
											mem_vec_12387 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12388);
											mem_vec_12388 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12389);
											mem_vec_12389 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12390);
											mem_vec_12390 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12391);
											mem_vec_12391 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_12372);
											mem_vec_12372 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_12373);
											mem_vec_12373 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_12374);
											mem_vec_12374 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_12375);
											mem_vec_12375 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_12376);
											mem_vec_12376 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_12377);
											mem_vec_12377 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_12378);
											mem_vec_12378 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_12379);
											mem_vec_12379 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_12380);
											mem_vec_12380 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_12381);
											mem_vec_12381 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_12382);
											mem_vec_12382 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_12383);
											mem_vec_12383 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_12384);
											mem_vec_12384 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_12385);
											mem_vec_12385 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_12386);
											mem_vec_12386 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_12387);
											mem_vec_12387 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_12388);
											mem_vec_12388 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_12389);
											mem_vec_12389 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_12390);
											mem_vec_12390 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_12391);
											mem_vec_12391 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_12372);
											mem_vec_12372 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_12373);
											mem_vec_12373 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_12374);
											mem_vec_12374 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_12375);
											mem_vec_12375 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_12376);
											mem_vec_12376 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_12377);
											mem_vec_12377 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_12378);
											mem_vec_12378 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_12379);
											mem_vec_12379 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_12380);
											mem_vec_12380 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_12381);
											mem_vec_12381 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_12382);
											mem_vec_12382 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_12383);
											mem_vec_12383 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_12384);
											mem_vec_12384 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_12385);
											mem_vec_12385 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_12386);
											mem_vec_12386 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_12387);
											mem_vec_12387 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_12388);
											mem_vec_12388 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_12389);
											mem_vec_12389 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_12390);
											mem_vec_12390 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_12391);
											mem_vec_12391 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12372);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12373);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12374);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12375);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12376);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12377);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12378);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12379);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12380);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12381);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12382);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12383);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12384);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12385);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12386);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12387);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12388);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12389);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12390);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12391);
							}
						}
					}
				}
			}
			for (y = y796 + 10, yp_0 = 0;
				y < y796 + 10 + 18;
				y += 6, yp_0 += 6){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
				// T (x, 1) (1 / 1)
				for (x1518 = x1519, x1518_p_1 = x1519_p_0, x1518_p_0 = 0;
					x1518 < x1519 + 1;
					x1518 += 1, x1518_p_1 += 1, x1518_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c1268 = c1269, c1268_p_0 = 0;
						c1268 < c1269 + 64;
						c1268 += 64, c1268_p_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h594, hp_0 = 0;
							h < h594 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
							// T (x, 1) (1 / 1)
							for (x = x1518, xp_2 = x1518_p_1, xp_1 = x1518_p_0, xp_0 = 0;
								x < x1518 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_12392 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_12393 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_12394 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_12395 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_12396 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_12397 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_12398 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_12399 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_12400 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_12401 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_12402 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_12403 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_12404 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_12405 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_12406 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_12407 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_12408 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_12409 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_12410 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_12411 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_12412 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_12413 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_12414 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_12415 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c1268, cp_1 = c1268_p_0, cp_0 = 0;
											c < c1268 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12392);
											mem_vec_12392 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12393);
											mem_vec_12393 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12394);
											mem_vec_12394 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12395);
											mem_vec_12395 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12396);
											mem_vec_12396 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12397);
											mem_vec_12397 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12398);
											mem_vec_12398 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12399);
											mem_vec_12399 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12400);
											mem_vec_12400 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12401);
											mem_vec_12401 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12402);
											mem_vec_12402 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12403);
											mem_vec_12403 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12404);
											mem_vec_12404 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12405);
											mem_vec_12405 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12406);
											mem_vec_12406 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12407);
											mem_vec_12407 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12408);
											mem_vec_12408 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12409);
											mem_vec_12409 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12410);
											mem_vec_12410 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12411);
											mem_vec_12411 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_12412);
											mem_vec_12412 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_12413);
											mem_vec_12413 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_12414);
											mem_vec_12414 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_12415);
											mem_vec_12415 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_12392);
											mem_vec_12392 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_12393);
											mem_vec_12393 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_12394);
											mem_vec_12394 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_12395);
											mem_vec_12395 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_12396);
											mem_vec_12396 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_12397);
											mem_vec_12397 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_12398);
											mem_vec_12398 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_12399);
											mem_vec_12399 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_12400);
											mem_vec_12400 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_12401);
											mem_vec_12401 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_12402);
											mem_vec_12402 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_12403);
											mem_vec_12403 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_12404);
											mem_vec_12404 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_12405);
											mem_vec_12405 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_12406);
											mem_vec_12406 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_12407);
											mem_vec_12407 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_12408);
											mem_vec_12408 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_12409);
											mem_vec_12409 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_12410);
											mem_vec_12410 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_12411);
											mem_vec_12411 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_12412);
											mem_vec_12412 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_12413);
											mem_vec_12413 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_12414);
											mem_vec_12414 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_12415);
											mem_vec_12415 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_12392);
											mem_vec_12392 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_12393);
											mem_vec_12393 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_12394);
											mem_vec_12394 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_12395);
											mem_vec_12395 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_12396);
											mem_vec_12396 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_12397);
											mem_vec_12397 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_12398);
											mem_vec_12398 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_12399);
											mem_vec_12399 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_12400);
											mem_vec_12400 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_12401);
											mem_vec_12401 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_12402);
											mem_vec_12402 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_12403);
											mem_vec_12403 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_12404);
											mem_vec_12404 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_12405);
											mem_vec_12405 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_12406);
											mem_vec_12406 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_12407);
											mem_vec_12407 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_12408);
											mem_vec_12408 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_12409);
											mem_vec_12409 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_12410);
											mem_vec_12410 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_12411);
											mem_vec_12411 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_12412);
											mem_vec_12412 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_12413);
											mem_vec_12413 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_12414);
											mem_vec_12414 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_12415);
											mem_vec_12415 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12392);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12393);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12394);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12395);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12396);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12397);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12398);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12399);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12400);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12401);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12402);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12403);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12404);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12405);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12406);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12407);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12408);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12409);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12410);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12411);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12412);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_12413);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12414);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_12415);
							}
						}
					}
				}
			}
	}
}


}