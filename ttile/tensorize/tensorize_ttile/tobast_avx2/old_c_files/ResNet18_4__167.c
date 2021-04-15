#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (8, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (2, x)]
*/
IND_TYPE c, cp_0, c1202_p_0, cp_1, c1202, f, fp_0, h, hp_0, x, xp_0, x1430_p_0, x1431_p_0, xp_1, x1430_p_1, xp_2, x1430, x1431, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y752 = 0;
IND_TYPE x1432 = 0;
IND_TYPE h550 = 0;
IND_TYPE w = 0;
IND_TYPE c1203 = 0;
IND_TYPE f826 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11404 ,mem_vec_11405 ,mem_vec_11406 ,mem_vec_11407 ,mem_vec_11408 ,mem_vec_11409 ,mem_vec_11410 ,mem_vec_11411 ,mem_vec_11412 ,mem_vec_11413 ,mem_vec_11414 ,mem_vec_11415 ,mem_vec_11416 ,mem_vec_11417 ,mem_vec_11418 ,mem_vec_11419 ,mem_vec_11420 ,mem_vec_11421 ,mem_vec_11422 ,mem_vec_11423 ,mem_vec_11424 ,mem_vec_11425 ,mem_vec_11426 ,mem_vec_11427 ,mem_vec_11428 ,mem_vec_11429 ,mem_vec_11430 ,mem_vec_11431 ,mem_vec_11432 ,mem_vec_11433 ,mem_vec_11434 ,mem_vec_11435 ,mem_vec_11436 ,mem_vec_11437 ,mem_vec_11438 ,mem_vec_11439 ,mem_vec_11440 ,mem_vec_11441 ,mem_vec_11442 ,mem_vec_11443 ,mem_vec_11444 ,mem_vec_11445 ,mem_vec_11446 ,mem_vec_11447 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (28 / 14)
for (x1431 = x1432, x1431_p_0 = 0;
	x1431 < x1432 + 28;
	x1431 += 14, x1431_p_0 += 14){
	// y = 28, x = 14, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f = f826, fp_0 = 0;
		f < f826 + 128;
		f += 32, fp_0 += 32){
			for (y = y752, yp_0 = 0;
				y < y752 + 10;
				y += 5, yp_0 += 5){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
				// T (x, 1) (14 / 14)
				for (x1430 = x1431, x1430_p_1 = x1431_p_0, x1430_p_0 = 0;
					x1430 < x1431 + 14;
					x1430 += 14, x1430_p_1 += 14, x1430_p_0 += 14){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (c, 8) (64 / 8)
					for (c1202 = c1203, c1202_p_0 = 0;
						c1202 < c1203 + 64;
						c1202 += 8, c1202_p_0 += 8){
						// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h550, hp_0 = 0;
							h < h550 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
							// T (x, 14) (14 / 1)
							for (x = x1430, xp_2 = x1430_p_1, xp_1 = x1430_p_0, xp_0 = 0;
								x < x1430 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_11404 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_11405 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_11406 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_11407 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_11408 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_11409 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_11410 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_11411 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_11412 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_11413 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_11414 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_11415 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_11416 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_11417 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_11418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_11419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_11420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_11421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_11422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_11423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1202, cp_1 = c1202_p_0, cp_0 = 0;
											c < c1202 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11404);
											mem_vec_11404 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11405);
											mem_vec_11405 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11406);
											mem_vec_11406 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11407);
											mem_vec_11407 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11408);
											mem_vec_11408 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11409);
											mem_vec_11409 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11410);
											mem_vec_11410 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11411);
											mem_vec_11411 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11412);
											mem_vec_11412 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11413);
											mem_vec_11413 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11414);
											mem_vec_11414 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11415);
											mem_vec_11415 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11416);
											mem_vec_11416 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11417);
											mem_vec_11417 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11418);
											mem_vec_11418 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11419);
											mem_vec_11419 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11420);
											mem_vec_11420 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11421);
											mem_vec_11421 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11422);
											mem_vec_11422 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11423);
											mem_vec_11423 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11404);
											mem_vec_11404 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11405);
											mem_vec_11405 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11406);
											mem_vec_11406 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11407);
											mem_vec_11407 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11408);
											mem_vec_11408 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11409);
											mem_vec_11409 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11410);
											mem_vec_11410 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11411);
											mem_vec_11411 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11412);
											mem_vec_11412 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11413);
											mem_vec_11413 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11414);
											mem_vec_11414 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11415);
											mem_vec_11415 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11416);
											mem_vec_11416 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11417);
											mem_vec_11417 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11418);
											mem_vec_11418 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11419);
											mem_vec_11419 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11420);
											mem_vec_11420 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11421);
											mem_vec_11421 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11422);
											mem_vec_11422 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11423);
											mem_vec_11423 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11404);
											mem_vec_11404 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11405);
											mem_vec_11405 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11406);
											mem_vec_11406 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11407);
											mem_vec_11407 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11408);
											mem_vec_11408 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11409);
											mem_vec_11409 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11410);
											mem_vec_11410 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11411);
											mem_vec_11411 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11412);
											mem_vec_11412 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11413);
											mem_vec_11413 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11414);
											mem_vec_11414 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11415);
											mem_vec_11415 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11416);
											mem_vec_11416 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11417);
											mem_vec_11417 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11418);
											mem_vec_11418 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11419);
											mem_vec_11419 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11420);
											mem_vec_11420 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11421);
											mem_vec_11421 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11422);
											mem_vec_11422 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11423);
											mem_vec_11423 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11404);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11405);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11406);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11407);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11408);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11409);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11410);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11411);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11412);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11413);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11414);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11415);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11416);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11417);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11418);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11419);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11420);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11421);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11422);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11423);
							}
						}
					}
				}
			}
			for (y = y752 + 10, yp_0 = 0;
				y < y752 + 10 + 18;
				y += 6, yp_0 += 6){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
				// T (x, 1) (14 / 14)
				for (x1430 = x1431, x1430_p_1 = x1431_p_0, x1430_p_0 = 0;
					x1430 < x1431 + 14;
					x1430 += 14, x1430_p_1 += 14, x1430_p_0 += 14){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (c, 8) (64 / 8)
					for (c1202 = c1203, c1202_p_0 = 0;
						c1202 < c1203 + 64;
						c1202 += 8, c1202_p_0 += 8){
						// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h550, hp_0 = 0;
							h < h550 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
							// T (x, 14) (14 / 1)
							for (x = x1430, xp_2 = x1430_p_1, xp_1 = x1430_p_0, xp_0 = 0;
								x < x1430 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_11424 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_11425 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_11426 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_11427 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_11428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_11429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_11430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_11431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_11432 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_11433 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_11434 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_11435 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_11436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_11437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_11438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_11439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_11440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_11441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_11442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_11443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_11444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_11445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_11446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_11447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1202, cp_1 = c1202_p_0, cp_0 = 0;
											c < c1202 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11424);
											mem_vec_11424 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11425);
											mem_vec_11425 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11426);
											mem_vec_11426 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11427);
											mem_vec_11427 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11428);
											mem_vec_11428 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11429);
											mem_vec_11429 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11430);
											mem_vec_11430 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11431);
											mem_vec_11431 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11432);
											mem_vec_11432 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11433);
											mem_vec_11433 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11434);
											mem_vec_11434 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11435);
											mem_vec_11435 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11436);
											mem_vec_11436 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11437);
											mem_vec_11437 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11438);
											mem_vec_11438 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11439);
											mem_vec_11439 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11440);
											mem_vec_11440 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11441);
											mem_vec_11441 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11442);
											mem_vec_11442 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11443);
											mem_vec_11443 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11444);
											mem_vec_11444 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11445);
											mem_vec_11445 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11446);
											mem_vec_11446 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11447);
											mem_vec_11447 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_11424);
											mem_vec_11424 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_11425);
											mem_vec_11425 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_11426);
											mem_vec_11426 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_11427);
											mem_vec_11427 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_11428);
											mem_vec_11428 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_11429);
											mem_vec_11429 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_11430);
											mem_vec_11430 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_11431);
											mem_vec_11431 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_11432);
											mem_vec_11432 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_11433);
											mem_vec_11433 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_11434);
											mem_vec_11434 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_11435);
											mem_vec_11435 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_11436);
											mem_vec_11436 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_11437);
											mem_vec_11437 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_11438);
											mem_vec_11438 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_11439);
											mem_vec_11439 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_11440);
											mem_vec_11440 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_11441);
											mem_vec_11441 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_11442);
											mem_vec_11442 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_11443);
											mem_vec_11443 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_11444);
											mem_vec_11444 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_11445);
											mem_vec_11445 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_11446);
											mem_vec_11446 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_11447);
											mem_vec_11447 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_11424);
											mem_vec_11424 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_11425);
											mem_vec_11425 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_11426);
											mem_vec_11426 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_11427);
											mem_vec_11427 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_11428);
											mem_vec_11428 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_11429);
											mem_vec_11429 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_11430);
											mem_vec_11430 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_11431);
											mem_vec_11431 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_11432);
											mem_vec_11432 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_11433);
											mem_vec_11433 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_11434);
											mem_vec_11434 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_11435);
											mem_vec_11435 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_11436);
											mem_vec_11436 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_11437);
											mem_vec_11437 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_11438);
											mem_vec_11438 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_11439);
											mem_vec_11439 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_11440);
											mem_vec_11440 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_11441);
											mem_vec_11441 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_11442);
											mem_vec_11442 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_11443);
											mem_vec_11443 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_11444);
											mem_vec_11444 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_11445);
											mem_vec_11445 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_11446);
											mem_vec_11446 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_11447);
											mem_vec_11447 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11424);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11425);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11426);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11427);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11428);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11429);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11430);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11431);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11432);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11433);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11434);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11435);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11436);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11437);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11438);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11439);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11440);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11441);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11442);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11443);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11444);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11445);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11446);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11447);
							}
						}
					}
				}
			}
	}
}


}