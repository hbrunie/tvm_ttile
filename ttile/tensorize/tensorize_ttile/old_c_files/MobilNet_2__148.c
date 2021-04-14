#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (2, x);
  Lambda_apply y [((Iter 4), (Arg 11)); ((Iter 1), (Arg 12))]; T (2, f);
  T (1, c); T (4, x)]
*/
IND_TYPE c, cp_0, c1040_p_0, cp_1, c1040, f, fp_0, w, wp_0, x, xp_0, x1200_p_0, x1201_p_0, xp_1, x1200_p_1, xp_2, x1200, x1201, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y640 = 0;
IND_TYPE x1202 = 0;
IND_TYPE h = 0;
IND_TYPE w616 = 0;
IND_TYPE c1041 = 0;
IND_TYPE f560 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10476 ,mem_vec_10477 ,mem_vec_10478 ,mem_vec_10479 ,mem_vec_10480 ,mem_vec_10481 ,mem_vec_10482 ,mem_vec_10483 ,mem_vec_10484 ,mem_vec_10485 ,mem_vec_10486 ,mem_vec_10487 ,mem_vec_10488 ,mem_vec_10489 ,mem_vec_10490 ,mem_vec_10491 ,mem_vec_10492 ,mem_vec_10493 ,mem_vec_10494 ,mem_vec_10495 ,mem_vec_10496 ,mem_vec_10497 ,mem_vec_10498 ,mem_vec_10499 ,mem_vec_10500 ,mem_vec_10501 ,mem_vec_10502 ,mem_vec_10503 ,mem_vec_10504 ,mem_vec_10505 ,mem_vec_10506 ,mem_vec_10507 ,mem_vec_10508 ,mem_vec_10509 ,mem_vec_10510 ,mem_vec_10511 ,mem_vec_10512 ,mem_vec_10513 ,mem_vec_10514 ,mem_vec_10515 ,mem_vec_10516 ,mem_vec_10517 ,mem_vec_10518 ,mem_vec_10519 ,mem_vec_10520 ,mem_vec_10521 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
for (x1201 = x1202, x1201_p_0 = 0;
	x1201 < x1202 + 56;
	x1201 += 14, x1201_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 64, f = 64
	// T (c, 1) (64 / 64)
	for (c1040 = c1041, c1040_p_0 = 0;
		c1040 < c1041 + 64;
		c1040 += 64, c1040_p_0 += 64){
		// y = 56, x = 14, h = 3, w = 3, c = 64, f = 64
		// T (f, 2) (64 / 32)
		for (f = f560, fp_0 = 0;
			f < f560 + 64;
			f += 32, fp_0 += 32){
				for (y = y640, yp_0 = 0;
					y < y640 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (x, 2) (14 / 7)
					for (x1200 = x1201, x1200_p_1 = x1201_p_0, x1200_p_0 = 0;
						x1200 < x1201 + 14;
						x1200 += 7, x1200_p_1 += 7, x1200_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w616, wp_0 = 0;
							w < w616 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 64, f = 32
							// T (x, 7) (7 / 1)
							for (x = x1200, xp_2 = x1200_p_1, xp_1 = x1200_p_0, xp_0 = 0;
								x < x1200 + 7;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10476 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10477 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_10489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_10490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_10491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_10492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_10493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_10494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_10495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_10496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_10497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c1040, cp_1 = c1040_p_0, cp_0 = 0;
											c < c1040 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10476);
											mem_vec_10476 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10477);
											mem_vec_10477 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10478);
											mem_vec_10478 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10479);
											mem_vec_10479 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10480);
											mem_vec_10480 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10481);
											mem_vec_10481 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10482);
											mem_vec_10482 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10483);
											mem_vec_10483 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10484);
											mem_vec_10484 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10485);
											mem_vec_10485 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10486);
											mem_vec_10486 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10487);
											mem_vec_10487 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10488);
											mem_vec_10488 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10489);
											mem_vec_10489 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10490);
											mem_vec_10490 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10491);
											mem_vec_10491 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10492);
											mem_vec_10492 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10493);
											mem_vec_10493 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10494);
											mem_vec_10494 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10495);
											mem_vec_10495 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10496);
											mem_vec_10496 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10497);
											mem_vec_10497 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_10476);
											mem_vec_10476 = vec_35;

											vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_10477);
											mem_vec_10477 = vec_38;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_10478);
											mem_vec_10478 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_10479);
											mem_vec_10479 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_10480);
											mem_vec_10480 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_10481);
											mem_vec_10481 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_10482);
											mem_vec_10482 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_10483);
											mem_vec_10483 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_10484);
											mem_vec_10484 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_10485);
											mem_vec_10485 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_10486);
											mem_vec_10486 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_10487);
											mem_vec_10487 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_10488);
											mem_vec_10488 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_10489);
											mem_vec_10489 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_10490);
											mem_vec_10490 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_10491);
											mem_vec_10491 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_10492);
											mem_vec_10492 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_10493);
											mem_vec_10493 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_10494);
											mem_vec_10494 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_10495);
											mem_vec_10495 = vec_66;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_10496);
											mem_vec_10496 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_10497);
											mem_vec_10497 = vec_69;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_10476);
											mem_vec_10476 = vec_70;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_10477);
											mem_vec_10477 = vec_73;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_10478);
											mem_vec_10478 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_10479);
											mem_vec_10479 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_10480);
											mem_vec_10480 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_10481);
											mem_vec_10481 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_10482);
											mem_vec_10482 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_10483);
											mem_vec_10483 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_10484);
											mem_vec_10484 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_10485);
											mem_vec_10485 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_10486);
											mem_vec_10486 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_10487);
											mem_vec_10487 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_10488);
											mem_vec_10488 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_10489);
											mem_vec_10489 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_10490);
											mem_vec_10490 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_10491);
											mem_vec_10491 = vec_95;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_10492);
											mem_vec_10492 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_10493);
											mem_vec_10493 = vec_98;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_10494);
											mem_vec_10494 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_10495);
											mem_vec_10495 = vec_101;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_10496);
											mem_vec_10496 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_10497);
											mem_vec_10497 = vec_104;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10476);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10477);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10478);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10479);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10483);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10487);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10488);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10489);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10490);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10491);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10492);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10493);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10494);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10495);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10496);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10497);
							}
						}
					}
				}
				for (y = y640 + 44, yp_0 = 0;
					y < y640 + 44 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (x, 2) (14 / 7)
					for (x1200 = x1201, x1200_p_1 = x1201_p_0, x1200_p_0 = 0;
						x1200 < x1201 + 14;
						x1200 += 7, x1200_p_1 += 7, x1200_p_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w616, wp_0 = 0;
							w < w616 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 64, f = 32
							// T (x, 7) (7 / 1)
							for (x = x1200, xp_2 = x1200_p_1, xp_1 = x1200_p_0, xp_0 = 0;
								x < x1200 + 7;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_10498 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_10499 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_10500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_10501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_10502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_10503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_10504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_10505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_10506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_10507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_10508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_10509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_10510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_10511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_10512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_10513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_10514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_10515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_10516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_10517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_10518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_10519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_10520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_10521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c1040, cp_1 = c1040_p_0, cp_0 = 0;
											c < c1040 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10498);
											mem_vec_10498 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10499);
											mem_vec_10499 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10500);
											mem_vec_10500 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10501);
											mem_vec_10501 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10502);
											mem_vec_10502 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10503);
											mem_vec_10503 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10504);
											mem_vec_10504 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10505);
											mem_vec_10505 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10506);
											mem_vec_10506 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10507);
											mem_vec_10507 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10508);
											mem_vec_10508 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10509);
											mem_vec_10509 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10510);
											mem_vec_10510 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10511);
											mem_vec_10511 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10512);
											mem_vec_10512 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10513);
											mem_vec_10513 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10514);
											mem_vec_10514 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10515);
											mem_vec_10515 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10516);
											mem_vec_10516 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10517);
											mem_vec_10517 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10518);
											mem_vec_10518 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10519);
											mem_vec_10519 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10520);
											mem_vec_10520 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10521);
											mem_vec_10521 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_10498);
											mem_vec_10498 = vec_38;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_10499);
											mem_vec_10499 = vec_41;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_10500);
											mem_vec_10500 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_10501);
											mem_vec_10501 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_10502);
											mem_vec_10502 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_10503);
											mem_vec_10503 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_10504);
											mem_vec_10504 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_10505);
											mem_vec_10505 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_10506);
											mem_vec_10506 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_10507);
											mem_vec_10507 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_10508);
											mem_vec_10508 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_10509);
											mem_vec_10509 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_10510);
											mem_vec_10510 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_10511);
											mem_vec_10511 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_10512);
											mem_vec_10512 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_10513);
											mem_vec_10513 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_10514);
											mem_vec_10514 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_10515);
											mem_vec_10515 = vec_66;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_10516);
											mem_vec_10516 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_10517);
											mem_vec_10517 = vec_69;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
											vec_71 = _mm512_set1_ps(scal_22);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_10518);
											mem_vec_10518 = vec_70;



											vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_10519);
											mem_vec_10519 = vec_72;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_23);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_10520);
											mem_vec_10520 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_10521);
											mem_vec_10521 = vec_75;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_77 = _mm512_set1_ps(scal_24);
											vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_10498);
											mem_vec_10498 = vec_76;

											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_10499);
											mem_vec_10499 = vec_79;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_10500);
											mem_vec_10500 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_10501);
											mem_vec_10501 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_10502);
											mem_vec_10502 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_10503);
											mem_vec_10503 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_10504);
											mem_vec_10504 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_10505);
											mem_vec_10505 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_10506);
											mem_vec_10506 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_10507);
											mem_vec_10507 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_10508);
											mem_vec_10508 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_10509);
											mem_vec_10509 = vec_95;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_10510);
											mem_vec_10510 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_10511);
											mem_vec_10511 = vec_98;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_10512);
											mem_vec_10512 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_10513);
											mem_vec_10513 = vec_101;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_10514);
											mem_vec_10514 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_10515);
											mem_vec_10515 = vec_104;
											scal_33 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_106 = _mm512_set1_ps(scal_33);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_10516);
											mem_vec_10516 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_10517);
											mem_vec_10517 = vec_107;
											scal_34 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
											vec_109 = _mm512_set1_ps(scal_34);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_10518);
											mem_vec_10518 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_10519);
											mem_vec_10519 = vec_110;
											scal_35 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 2) + c];
											vec_112 = _mm512_set1_ps(scal_35);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_10520);
											mem_vec_10520 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_10521);
											mem_vec_10521 = vec_113;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10498);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10499);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10500);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10501);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10502);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10503);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10504);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10505);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10506);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10507);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10508);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10509);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10510);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10511);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10512);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10513);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10514);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10515);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10516);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10517);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10518);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10519);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10520);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10521);
							}
						}
					}
				}
		}
	}
}


}