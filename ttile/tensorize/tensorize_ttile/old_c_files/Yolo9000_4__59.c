#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (68, x);
  Lambda_apply y [((Iter 9), (Arg 9)); ((Iter 5), (Arg 11))]; T (4, f);
  T (16, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1038_p_0, cp_1, c1038, f, fp_0, w, wp_0, x, xp_0, x1330_p_0, x1331_p_0, xp_1, x1330_p_1, xp_2, x1330, x1331, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y692 = 0;
IND_TYPE x1332 = 0;
IND_TYPE h = 0;
IND_TYPE w662 = 0;
IND_TYPE c1039 = 0;
IND_TYPE f692 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13364 ,mem_vec_13365 ,mem_vec_13366 ,mem_vec_13367 ,mem_vec_13368 ,mem_vec_13369 ,mem_vec_13370 ,mem_vec_13371 ,mem_vec_13372 ,mem_vec_13373 ,mem_vec_13374 ,mem_vec_13375 ,mem_vec_13376 ,mem_vec_13377 ,mem_vec_13378 ,mem_vec_13379 ,mem_vec_13380 ,mem_vec_13381 ,mem_vec_13382 ,mem_vec_13383 ,mem_vec_13384 ,mem_vec_13385 ,mem_vec_13386 ,mem_vec_13387 ,mem_vec_13388 ,mem_vec_13389 ,mem_vec_13390 ,mem_vec_13391 ,mem_vec_13392 ,mem_vec_13393 ,mem_vec_13394 ,mem_vec_13395 ,mem_vec_13396 ,mem_vec_13397 ,mem_vec_13398 ,mem_vec_13399 ,mem_vec_13400 ,mem_vec_13401 ,mem_vec_13402 ,mem_vec_13403 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x1331 = x1332, x1331_p_0 = 0;
	x1331 < x1332 + 136;
	x1331 += 136, x1331_p_0 += 136){
	// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
	// T (c, 16) (64 / 4)
	for (c1038 = c1039, c1038_p_0 = 0;
		c1038 < c1039 + 64;
		c1038 += 4, c1038_p_0 += 4){
		// y = 136, x = 136, h = 3, w = 3, c = 4, f = 128
		// T (f, 4) (128 / 32)
		for (f = f692, fp_0 = 0;
			f < f692 + 128;
			f += 32, fp_0 += 32){
				for (y = y692, yp_0 = 0;
					y < y692 + 81;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 136, h = 3, w = 3, c = 4, f = 32
					// T (x, 68) (136 / 2)
					for (x1330 = x1331, x1330_p_1 = x1331_p_0, x1330_p_0 = 0;
						x1330 < x1331 + 136;
						x1330 += 2, x1330_p_1 += 2, x1330_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w662, wp_0 = 0;
							w < w662 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1330, xp_2 = x1330_p_1, xp_1 = x1330_p_0, xp_0 = 0;
								x < x1330 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_13364 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_13365 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_13366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_13367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_13368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_13369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_13370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_13371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_13372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_13373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_13374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_13375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_13376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_13377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_13378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_13379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_13380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_13381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c1038, cp_1 = c1038_p_0, cp_0 = 0;
											c < c1038 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13364);
											mem_vec_13364 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13365);
											mem_vec_13365 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13366);
											mem_vec_13366 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13367);
											mem_vec_13367 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13368);
											mem_vec_13368 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13369);
											mem_vec_13369 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13370);
											mem_vec_13370 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13371);
											mem_vec_13371 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13372);
											mem_vec_13372 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13373);
											mem_vec_13373 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13374);
											mem_vec_13374 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13375);
											mem_vec_13375 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13376);
											mem_vec_13376 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13377);
											mem_vec_13377 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13378);
											mem_vec_13378 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13379);
											mem_vec_13379 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13380);
											mem_vec_13380 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13381);
											mem_vec_13381 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_13364);
											mem_vec_13364 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_13365);
											mem_vec_13365 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_13366);
											mem_vec_13366 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_13367);
											mem_vec_13367 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_13368);
											mem_vec_13368 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_13369);
											mem_vec_13369 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_13370);
											mem_vec_13370 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_13371);
											mem_vec_13371 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_13372);
											mem_vec_13372 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_13373);
											mem_vec_13373 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_13374);
											mem_vec_13374 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_13375);
											mem_vec_13375 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_13376);
											mem_vec_13376 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_13377);
											mem_vec_13377 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_13378);
											mem_vec_13378 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_13379);
											mem_vec_13379 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_13380);
											mem_vec_13380 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_13381);
											mem_vec_13381 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_13364);
											mem_vec_13364 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_13365);
											mem_vec_13365 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_13366);
											mem_vec_13366 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_13367);
											mem_vec_13367 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_13368);
											mem_vec_13368 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_13369);
											mem_vec_13369 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_13370);
											mem_vec_13370 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_13371);
											mem_vec_13371 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_13372);
											mem_vec_13372 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_13373);
											mem_vec_13373 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_13374);
											mem_vec_13374 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_13375);
											mem_vec_13375 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_13376);
											mem_vec_13376 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_13377);
											mem_vec_13377 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_13378);
											mem_vec_13378 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_13379);
											mem_vec_13379 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_13380);
											mem_vec_13380 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_13381);
											mem_vec_13381 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13367);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13368);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13369);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13370);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13371);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13372);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13373);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13374);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13375);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13376);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13377);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13378);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13379);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13381);
							}
						}
					}
				}
				for (y = y692 + 81, yp_0 = 0;
					y < y692 + 81 + 55;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 136, h = 3, w = 3, c = 4, f = 32
					// T (x, 68) (136 / 2)
					for (x1330 = x1331, x1330_p_1 = x1331_p_0, x1330_p_0 = 0;
						x1330 < x1331 + 136;
						x1330 += 2, x1330_p_1 += 2, x1330_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w662, wp_0 = 0;
							w < w662 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 3, w = 1, c = 4, f = 32
							// T (x, 2) (2 / 1)
							for (x = x1330, xp_2 = x1330_p_1, xp_1 = x1330_p_0, xp_0 = 0;
								x < x1330 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_13382 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_13383 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_13384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_13385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_13386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_13387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_13388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_13389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_13390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_13391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_13392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_13393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_13394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_13395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_13396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_13397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_13398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_13399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_13400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_13401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_13402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_13403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c1038, cp_1 = c1038_p_0, cp_0 = 0;
											c < c1038 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13382);
											mem_vec_13382 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13383);
											mem_vec_13383 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13384);
											mem_vec_13384 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13385);
											mem_vec_13385 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13386);
											mem_vec_13386 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13387);
											mem_vec_13387 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13388);
											mem_vec_13388 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13389);
											mem_vec_13389 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13390);
											mem_vec_13390 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13391);
											mem_vec_13391 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13392);
											mem_vec_13392 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13393);
											mem_vec_13393 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13394);
											mem_vec_13394 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13395);
											mem_vec_13395 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13396);
											mem_vec_13396 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13397);
											mem_vec_13397 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13398);
											mem_vec_13398 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13399);
											mem_vec_13399 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13400);
											mem_vec_13400 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13401);
											mem_vec_13401 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13402);
											mem_vec_13402 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13403);
											mem_vec_13403 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_13382);
											mem_vec_13382 = vec_35;

											vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_13383);
											mem_vec_13383 = vec_38;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_13384);
											mem_vec_13384 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_13385);
											mem_vec_13385 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_13386);
											mem_vec_13386 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_13387);
											mem_vec_13387 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_13388);
											mem_vec_13388 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_13389);
											mem_vec_13389 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_13390);
											mem_vec_13390 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_13391);
											mem_vec_13391 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_13392);
											mem_vec_13392 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_13393);
											mem_vec_13393 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_13394);
											mem_vec_13394 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_13395);
											mem_vec_13395 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_13396);
											mem_vec_13396 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_13397);
											mem_vec_13397 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_13398);
											mem_vec_13398 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_13399);
											mem_vec_13399 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_13400);
											mem_vec_13400 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_13401);
											mem_vec_13401 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_13402);
											mem_vec_13402 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_13403);
											mem_vec_13403 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_13382);
											mem_vec_13382 = vec_70;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_13383);
											mem_vec_13383 = vec_73;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_13384);
											mem_vec_13384 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_13385);
											mem_vec_13385 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_13386);
											mem_vec_13386 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_13387);
											mem_vec_13387 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_13388);
											mem_vec_13388 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_13389);
											mem_vec_13389 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_13390);
											mem_vec_13390 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_13391);
											mem_vec_13391 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_13392);
											mem_vec_13392 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_13393);
											mem_vec_13393 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_13394);
											mem_vec_13394 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_13395);
											mem_vec_13395 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_13396);
											mem_vec_13396 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_13397);
											mem_vec_13397 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_13398);
											mem_vec_13398 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_13399);
											mem_vec_13399 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_13400);
											mem_vec_13400 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_13401);
											mem_vec_13401 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_13402);
											mem_vec_13402 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_13403);
											mem_vec_13403 = vec_104;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13387);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13399);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13403);
							}
						}
					}
				}
		}
	}
}


}