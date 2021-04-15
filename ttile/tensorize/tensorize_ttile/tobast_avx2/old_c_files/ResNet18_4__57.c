#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (32, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (7, x)]
*/
IND_TYPE c, cp_0, c1136_p_0, cp_1, c1136, f, fp_0, w, wp_0, x, xp_0, x1342_p_0, x1343_p_0, xp_1, x1342_p_1, xp_2, x1342, x1343, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y708 = 0;
IND_TYPE x1344 = 0;
IND_TYPE h = 0;
IND_TYPE w572 = 0;
IND_TYPE c1137 = 0;
IND_TYPE f782 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10436 ,mem_vec_10437 ,mem_vec_10438 ,mem_vec_10439 ,mem_vec_10440 ,mem_vec_10441 ,mem_vec_10442 ,mem_vec_10443 ,mem_vec_10444 ,mem_vec_10445 ,mem_vec_10446 ,mem_vec_10447 ,mem_vec_10448 ,mem_vec_10449 ,mem_vec_10450 ,mem_vec_10451 ,mem_vec_10452 ,mem_vec_10453 ,mem_vec_10454 ,mem_vec_10455 ,mem_vec_10456 ,mem_vec_10457 ,mem_vec_10458 ,mem_vec_10459 ,mem_vec_10460 ,mem_vec_10461 ,mem_vec_10462 ,mem_vec_10463 ,mem_vec_10464 ,mem_vec_10465 ,mem_vec_10466 ,mem_vec_10467 ,mem_vec_10468 ,mem_vec_10469 ,mem_vec_10470 ,mem_vec_10471 ,mem_vec_10472 ,mem_vec_10473 ,mem_vec_10474 ,mem_vec_10475 ,mem_vec_10476 ,mem_vec_10477 ,mem_vec_10478 ,mem_vec_10479 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (x, 7) (28 / 4)
for (x1343 = x1344, x1343_p_0 = 0;
	x1343 < x1344 + 28;
	x1343 += 4, x1343_p_0 += 4){
	// y = 28, x = 4, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f = f782, fp_0 = 0;
		f < f782 + 128;
		f += 32, fp_0 += 32){
			for (y = y708, yp_0 = 0;
				y < y708 + 10;
				y += 5, yp_0 += 5){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (x, 2) (4 / 2)
				for (x1342 = x1343, x1342_p_1 = x1343_p_0, x1342_p_0 = 0;
					x1342 < x1343 + 4;
					x1342 += 2, x1342_p_1 += 2, x1342_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
					// T (c, 32) (64 / 2)
					for (c1136 = c1137, c1136_p_0 = 0;
						c1136 < c1137 + 64;
						c1136 += 2, c1136_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w572, wp_0 = 0;
							w < w572 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 2, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1342, xp_2 = x1342_p_1, xp_1 = x1342_p_0, xp_0 = 0;
								x < x1342 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10436 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10437 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_10438 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10439 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_10440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_10442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_10444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_10446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_10448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_10450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_10452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_10454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c1136, cp_1 = c1136_p_0, cp_0 = 0;
											c < c1136 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10436);
											mem_vec_10436 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10437);
											mem_vec_10437 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10438);
											mem_vec_10438 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10439);
											mem_vec_10439 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10440);
											mem_vec_10440 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10441);
											mem_vec_10441 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10442);
											mem_vec_10442 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10443);
											mem_vec_10443 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10444);
											mem_vec_10444 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10445);
											mem_vec_10445 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10446);
											mem_vec_10446 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10447);
											mem_vec_10447 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10448);
											mem_vec_10448 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10449);
											mem_vec_10449 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10450);
											mem_vec_10450 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10451);
											mem_vec_10451 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10452);
											mem_vec_10452 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10453);
											mem_vec_10453 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10454);
											mem_vec_10454 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10455);
											mem_vec_10455 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_10436);
											mem_vec_10436 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_10437);
											mem_vec_10437 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_10438);
											mem_vec_10438 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_10439);
											mem_vec_10439 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_10440);
											mem_vec_10440 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_10441);
											mem_vec_10441 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_10442);
											mem_vec_10442 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_10443);
											mem_vec_10443 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_10444);
											mem_vec_10444 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_10445);
											mem_vec_10445 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_10446);
											mem_vec_10446 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_10447);
											mem_vec_10447 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_10448);
											mem_vec_10448 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_10449);
											mem_vec_10449 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_10450);
											mem_vec_10450 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_10451);
											mem_vec_10451 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_10452);
											mem_vec_10452 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_10453);
											mem_vec_10453 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_10454);
											mem_vec_10454 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_10455);
											mem_vec_10455 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_10436);
											mem_vec_10436 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_10437);
											mem_vec_10437 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_10438);
											mem_vec_10438 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_10439);
											mem_vec_10439 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_10440);
											mem_vec_10440 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_10441);
											mem_vec_10441 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_10442);
											mem_vec_10442 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_10443);
											mem_vec_10443 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_10444);
											mem_vec_10444 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_10445);
											mem_vec_10445 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_10446);
											mem_vec_10446 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_10447);
											mem_vec_10447 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_10448);
											mem_vec_10448 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_10449);
											mem_vec_10449 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_10450);
											mem_vec_10450 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_10451);
											mem_vec_10451 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_10452);
											mem_vec_10452 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_10453);
											mem_vec_10453 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_10454);
											mem_vec_10454 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_10455);
											mem_vec_10455 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10436);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10437);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10438);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10439);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10440);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10441);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10442);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10443);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10444);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10445);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10446);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10447);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10448);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10449);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10450);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10451);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10452);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10453);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10454);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10455);
							}
						}
					}
				}
			}
			for (y = y708 + 10, yp_0 = 0;
				y < y708 + 10 + 18;
				y += 6, yp_0 += 6){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (x, 2) (4 / 2)
				for (x1342 = x1343, x1342_p_1 = x1343_p_0, x1342_p_0 = 0;
					x1342 < x1343 + 4;
					x1342 += 2, x1342_p_1 += 2, x1342_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
					// T (c, 32) (64 / 2)
					for (c1136 = c1137, c1136_p_0 = 0;
						c1136 < c1137 + 64;
						c1136 += 2, c1136_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
						// T (w, 3) (3 / 1)
						for (w = w572, wp_0 = 0;
							w < w572 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 2, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1342, xp_2 = x1342_p_1, xp_1 = x1342_p_0, xp_0 = 0;
								x < x1342 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10456 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10457 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_10458 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10459 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_10460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_10462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_10464 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10465 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_10466 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10467 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_10468 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10469 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_10470 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10471 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_10472 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10473 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_10474 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10475 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_10476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_10478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
										// T (c, 2) (2 / 1)
										for (c = c1136, cp_1 = c1136_p_0, cp_0 = 0;
											c < c1136 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10456);
											mem_vec_10456 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10457);
											mem_vec_10457 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10458);
											mem_vec_10458 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10459);
											mem_vec_10459 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10460);
											mem_vec_10460 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10461);
											mem_vec_10461 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10462);
											mem_vec_10462 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10463);
											mem_vec_10463 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10464);
											mem_vec_10464 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10465);
											mem_vec_10465 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10466);
											mem_vec_10466 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10467);
											mem_vec_10467 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10468);
											mem_vec_10468 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10469);
											mem_vec_10469 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10470);
											mem_vec_10470 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10471);
											mem_vec_10471 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10472);
											mem_vec_10472 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10473);
											mem_vec_10473 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10474);
											mem_vec_10474 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10475);
											mem_vec_10475 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10476);
											mem_vec_10476 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10477);
											mem_vec_10477 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10478);
											mem_vec_10478 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10479);
											mem_vec_10479 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_10456);
											mem_vec_10456 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_10457);
											mem_vec_10457 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_10458);
											mem_vec_10458 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_10459);
											mem_vec_10459 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_10460);
											mem_vec_10460 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_10461);
											mem_vec_10461 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_10462);
											mem_vec_10462 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_10463);
											mem_vec_10463 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_10464);
											mem_vec_10464 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_10465);
											mem_vec_10465 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_10466);
											mem_vec_10466 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_10467);
											mem_vec_10467 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_10468);
											mem_vec_10468 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_10469);
											mem_vec_10469 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_10470);
											mem_vec_10470 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_10471);
											mem_vec_10471 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_10472);
											mem_vec_10472 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_10473);
											mem_vec_10473 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_10474);
											mem_vec_10474 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_10475);
											mem_vec_10475 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_10476);
											mem_vec_10476 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_10477);
											mem_vec_10477 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_10478);
											mem_vec_10478 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_10479);
											mem_vec_10479 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_10456);
											mem_vec_10456 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_10457);
											mem_vec_10457 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_10458);
											mem_vec_10458 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_10459);
											mem_vec_10459 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_10460);
											mem_vec_10460 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_10461);
											mem_vec_10461 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_10462);
											mem_vec_10462 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_10463);
											mem_vec_10463 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_10464);
											mem_vec_10464 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_10465);
											mem_vec_10465 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_10466);
											mem_vec_10466 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_10467);
											mem_vec_10467 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_10468);
											mem_vec_10468 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_10469);
											mem_vec_10469 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_10470);
											mem_vec_10470 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_10471);
											mem_vec_10471 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_10472);
											mem_vec_10472 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_10473);
											mem_vec_10473 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_10474);
											mem_vec_10474 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_10475);
											mem_vec_10475 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_10476);
											mem_vec_10476 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_10477);
											mem_vec_10477 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_10478);
											mem_vec_10478 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_10479);
											mem_vec_10479 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10456);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10457);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10458);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10459);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10460);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10461);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10462);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10463);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10464);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10465);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10466);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10467);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10468);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10469);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10470);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10471);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10472);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10473);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10474);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10475);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10476);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10477);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10478);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10479);
							}
						}
					}
				}
			}
	}
}


}