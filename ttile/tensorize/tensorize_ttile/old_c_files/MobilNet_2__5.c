#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (28, x);
  T (3, w); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (2, f);
  T (16, c); T (1, x)]
*/
IND_TYPE c, cp_0, c974_p_0, cp_1, c974, f, fp_0, w, wp_0, x, xp_0, x1112_p_0, x1113_p_0, xp_1, x1112_p_1, xp_2, x1112, x1113, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y596 = 0;
IND_TYPE x1114 = 0;
IND_TYPE h = 0;
IND_TYPE w572 = 0;
IND_TYPE c975 = 0;
IND_TYPE f516 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9492 ,mem_vec_9493 ,mem_vec_9494 ,mem_vec_9495 ,mem_vec_9496 ,mem_vec_9497 ,mem_vec_9498 ,mem_vec_9499 ,mem_vec_9500 ,mem_vec_9501 ,mem_vec_9502 ,mem_vec_9503 ,mem_vec_9504 ,mem_vec_9505 ,mem_vec_9506 ,mem_vec_9507 ,mem_vec_9508 ,mem_vec_9509 ,mem_vec_9510 ,mem_vec_9511 ,mem_vec_9512 ,mem_vec_9513 ,mem_vec_9514 ,mem_vec_9515 ,mem_vec_9516 ,mem_vec_9517 ,mem_vec_9518 ,mem_vec_9519 ,mem_vec_9520 ,mem_vec_9521 ,mem_vec_9522 ,mem_vec_9523 ,mem_vec_9524 ,mem_vec_9525 ,mem_vec_9526 ,mem_vec_9527 ,mem_vec_9528 ,mem_vec_9529 ,mem_vec_9530 ,mem_vec_9531 ,mem_vec_9532 ,mem_vec_9533 ,mem_vec_9534 ,mem_vec_9535 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x1113 = x1114, x1113_p_0 = 0;
	x1113 < x1114 + 56;
	x1113 += 56, x1113_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (c, 16) (64 / 4)
	for (c974 = c975, c974_p_0 = 0;
		c974 < c975 + 64;
		c974 += 4, c974_p_0 += 4){
		// y = 56, x = 56, h = 3, w = 3, c = 4, f = 64
		// T (f, 2) (64 / 32)
		for (f = f516, fp_0 = 0;
			f < f516 + 64;
			f += 32, fp_0 += 32){
				for (y = y596, yp_0 = 0;
					y < y596 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 56, h = 3, w = 3, c = 4, f = 32
					// T (x, 2) (56 / 28)
					for (x1112 = x1113, x1112_p_1 = x1113_p_0, x1112_p_0 = 0;
						x1112 < x1113 + 56;
						x1112 += 28, x1112_p_1 += 28, x1112_p_0 += 28){
						// y = ph_y, x = 28, h = 3, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w572, wp_0 = 0;
							w < w572 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 3, w = 1, c = 4, f = 32
							// T (x, 28) (28 / 1)
							for (x = x1112, xp_2 = x1112_p_1, xp_1 = x1112_p_0, xp_0 = 0;
								x < x1112 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9492 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9493 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c974, cp_1 = c974_p_0, cp_0 = 0;
											c < c974 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9492);
											mem_vec_9492 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9493);
											mem_vec_9493 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9494);
											mem_vec_9494 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9495);
											mem_vec_9495 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9496);
											mem_vec_9496 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9497);
											mem_vec_9497 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9498);
											mem_vec_9498 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9499);
											mem_vec_9499 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9500);
											mem_vec_9500 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9501);
											mem_vec_9501 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9502);
											mem_vec_9502 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9503);
											mem_vec_9503 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9504);
											mem_vec_9504 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9505);
											mem_vec_9505 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9506);
											mem_vec_9506 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9507);
											mem_vec_9507 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9508);
											mem_vec_9508 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9509);
											mem_vec_9509 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9510);
											mem_vec_9510 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9511);
											mem_vec_9511 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_9492);
											mem_vec_9492 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_9493);
											mem_vec_9493 = vec_35;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_9494);
											mem_vec_9494 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_9495);
											mem_vec_9495 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_9496);
											mem_vec_9496 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_9497);
											mem_vec_9497 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_9498);
											mem_vec_9498 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_9499);
											mem_vec_9499 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_9500);
											mem_vec_9500 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_9501);
											mem_vec_9501 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_9502);
											mem_vec_9502 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_9503);
											mem_vec_9503 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_9504);
											mem_vec_9504 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_9505);
											mem_vec_9505 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_9506);
											mem_vec_9506 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_9507);
											mem_vec_9507 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_9508);
											mem_vec_9508 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_9509);
											mem_vec_9509 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_9510);
											mem_vec_9510 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_9511);
											mem_vec_9511 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_9492);
											mem_vec_9492 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_9493);
											mem_vec_9493 = vec_67;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_9494);
											mem_vec_9494 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_9495);
											mem_vec_9495 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_9496);
											mem_vec_9496 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_9497);
											mem_vec_9497 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_9498);
											mem_vec_9498 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_9499);
											mem_vec_9499 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_9500);
											mem_vec_9500 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_9501);
											mem_vec_9501 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_9502);
											mem_vec_9502 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_9503);
											mem_vec_9503 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_9504);
											mem_vec_9504 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_9505);
											mem_vec_9505 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_9506);
											mem_vec_9506 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_9507);
											mem_vec_9507 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_9508);
											mem_vec_9508 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_9509);
											mem_vec_9509 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_9510);
											mem_vec_9510 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_9511);
											mem_vec_9511 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9492);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9493);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9494);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9495);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9496);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9497);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9498);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9499);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9500);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9501);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9502);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9503);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9504);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9505);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9506);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9507);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9508);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9509);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9510);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9511);
							}
						}
					}
				}
				for (y = y596 + 20, yp_0 = 0;
					y < y596 + 20 + 36;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 56, h = 3, w = 3, c = 4, f = 32
					// T (x, 2) (56 / 28)
					for (x1112 = x1113, x1112_p_1 = x1113_p_0, x1112_p_0 = 0;
						x1112 < x1113 + 56;
						x1112 += 28, x1112_p_1 += 28, x1112_p_0 += 28){
						// y = ph_y, x = 28, h = 3, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w572, wp_0 = 0;
							w < w572 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 28, h = 3, w = 1, c = 4, f = 32
							// T (x, 28) (28 / 1)
							for (x = x1112, xp_2 = x1112_p_1, xp_1 = x1112_p_0, xp_0 = 0;
								x < x1112 + 28;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9512 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9513 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_9532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_9533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_9534 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_9535 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c974, cp_1 = c974_p_0, cp_0 = 0;
											c < c974 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9512);
											mem_vec_9512 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9513);
											mem_vec_9513 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9514);
											mem_vec_9514 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9515);
											mem_vec_9515 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9516);
											mem_vec_9516 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9517);
											mem_vec_9517 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9518);
											mem_vec_9518 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9519);
											mem_vec_9519 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9520);
											mem_vec_9520 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9521);
											mem_vec_9521 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9522);
											mem_vec_9522 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9523);
											mem_vec_9523 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9524);
											mem_vec_9524 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9525);
											mem_vec_9525 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9526);
											mem_vec_9526 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9527);
											mem_vec_9527 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9528);
											mem_vec_9528 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9529);
											mem_vec_9529 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9530);
											mem_vec_9530 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9531);
											mem_vec_9531 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9532);
											mem_vec_9532 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9533);
											mem_vec_9533 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9534);
											mem_vec_9534 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9535);
											mem_vec_9535 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_12);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_9512);
											mem_vec_9512 = vec_38;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_9513);
											mem_vec_9513 = vec_41;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_9514);
											mem_vec_9514 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_9515);
											mem_vec_9515 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_40, mem_vec_9516);
											mem_vec_9516 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_42, mem_vec_9517);
											mem_vec_9517 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_40, mem_vec_9518);
											mem_vec_9518 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_42, mem_vec_9519);
											mem_vec_9519 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_9520);
											mem_vec_9520 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_9521);
											mem_vec_9521 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_40, mem_vec_9522);
											mem_vec_9522 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_42, mem_vec_9523);
											mem_vec_9523 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_9524);
											mem_vec_9524 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_9525);
											mem_vec_9525 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_40, mem_vec_9526);
											mem_vec_9526 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_42, mem_vec_9527);
											mem_vec_9527 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_40, mem_vec_9528);
											mem_vec_9528 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_42, mem_vec_9529);
											mem_vec_9529 = vec_66;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_40, mem_vec_9530);
											mem_vec_9530 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_42, mem_vec_9531);
											mem_vec_9531 = vec_69;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 1) + c];
											vec_71 = _mm512_set1_ps(scal_22);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_40, mem_vec_9532);
											mem_vec_9532 = vec_70;



											vec_72 = _mm512_fmadd_ps(vec_71, vec_42, mem_vec_9533);
											mem_vec_9533 = vec_72;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_23);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_40, mem_vec_9534);
											mem_vec_9534 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_42, mem_vec_9535);
											mem_vec_9535 = vec_75;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_77 = _mm512_set1_ps(scal_24);
											vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_76 = _mm512_fmadd_ps(vec_77, vec_78, mem_vec_9512);
											mem_vec_9512 = vec_76;

											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_79 = _mm512_fmadd_ps(vec_77, vec_80, mem_vec_9513);
											mem_vec_9513 = vec_79;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_78, mem_vec_9514);
											mem_vec_9514 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_9515);
											mem_vec_9515 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_78, mem_vec_9516);
											mem_vec_9516 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_80, mem_vec_9517);
											mem_vec_9517 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_9518);
											mem_vec_9518 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_9519);
											mem_vec_9519 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_78, mem_vec_9520);
											mem_vec_9520 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_80, mem_vec_9521);
											mem_vec_9521 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_78, mem_vec_9522);
											mem_vec_9522 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_80, mem_vec_9523);
											mem_vec_9523 = vec_95;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_9524);
											mem_vec_9524 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_9525);
											mem_vec_9525 = vec_98;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_78, mem_vec_9526);
											mem_vec_9526 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_80, mem_vec_9527);
											mem_vec_9527 = vec_101;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_78, mem_vec_9528);
											mem_vec_9528 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_9529);
											mem_vec_9529 = vec_104;
											scal_33 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_106 = _mm512_set1_ps(scal_33);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_78, mem_vec_9530);
											mem_vec_9530 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_80, mem_vec_9531);
											mem_vec_9531 = vec_107;
											scal_34 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h + 2) + c];
											vec_109 = _mm512_set1_ps(scal_34);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_78, mem_vec_9532);
											mem_vec_9532 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_80, mem_vec_9533);
											mem_vec_9533 = vec_110;
											scal_35 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h + 2) + c];
											vec_112 = _mm512_set1_ps(scal_35);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_78, mem_vec_9534);
											mem_vec_9534 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_80, mem_vec_9535);
											mem_vec_9535 = vec_113;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9512);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9513);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9514);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9515);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9516);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9517);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9518);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9519);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9520);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9521);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9522);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9523);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9524);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9525);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9526);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9527);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9528);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9529);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9530);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9531);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9532);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9533);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9534);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9535);
							}
						}
					}
				}
		}
	}
}


}