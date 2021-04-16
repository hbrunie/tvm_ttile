#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (4, c); T (4, f); T (4, x);
  Lambda_apply y [((Iter 11), (Arg 10)); ((Iter 2), (Arg 13))]; T (1, x)]
*/
IND_TYPE c, cp_0, c288_p_0, cp_1, c288, f, fp_0, h, hp_0, x, xp_0, x382_p_0, x383_p_0, xp_1, x382_p_1, xp_2, x382, x383, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y194 = 0;
IND_TYPE x384 = 0;
IND_TYPE h125 = 0;
IND_TYPE w = 0;
IND_TYPE c289 = 0;
IND_TYPE f192 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4536 ,mem_vec_4537 ,mem_vec_4538 ,mem_vec_4539 ,mem_vec_4540 ,mem_vec_4541 ,mem_vec_4542 ,mem_vec_4543 ,mem_vec_4544 ,mem_vec_4545 ,mem_vec_4546 ,mem_vec_4547 ,mem_vec_4548 ,mem_vec_4549 ,mem_vec_4550 ,mem_vec_4551 ,mem_vec_4552 ,mem_vec_4553 ,mem_vec_4554 ,mem_vec_4555 ,mem_vec_4556 ,mem_vec_4557 ,mem_vec_4558 ,mem_vec_4559 ,mem_vec_4560 ,mem_vec_4561 ,mem_vec_4562 ,mem_vec_4563 ,mem_vec_4564 ,mem_vec_4565 ,mem_vec_4566 ,mem_vec_4567 ,mem_vec_4568 ,mem_vec_4569 ,mem_vec_4570 ,mem_vec_4571 ,mem_vec_4572 ,mem_vec_4573 ,mem_vec_4574 ,mem_vec_4575 ,mem_vec_4576 ,mem_vec_4577 ,mem_vec_4578 ,mem_vec_4579 ,mem_vec_4580 ,mem_vec_4581 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x383 = x384, x383_p_0 = 0;
	x383 < x384 + 136;
	x383 += 136, x383_p_0 += 136){
		for (y = y194, yp_0 = 0;
			y < y194 + 110;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x382 = x383, x382_p_1 = x383_p_0, x382_p_0 = 0;
				x382 < x383 + 136;
				x382 += 34, x382_p_1 += 34, x382_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f192, fp_0 = 0;
					f < f192 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c288 = c289, c288_p_0 = 0;
						c288 < c289 + 64;
						c288 += 16, c288_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h125, hp_0 = 0;
							h < h125 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x382, xp_2 = x382_p_1, xp_1 = x382_p_0, xp_0 = 0;
								x < x382 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4536 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4537 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_4552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_4553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_4554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_4555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c288, cp_1 = c288_p_0, cp_0 = 0;
											c < c288 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4536);
											mem_vec_4536 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4537);
											mem_vec_4537 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4538);
											mem_vec_4538 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4539);
											mem_vec_4539 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4540);
											mem_vec_4540 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4541);
											mem_vec_4541 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4542);
											mem_vec_4542 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4543);
											mem_vec_4543 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4544);
											mem_vec_4544 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4545);
											mem_vec_4545 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4546);
											mem_vec_4546 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4547);
											mem_vec_4547 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4548);
											mem_vec_4548 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4549);
											mem_vec_4549 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4550);
											mem_vec_4550 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4551);
											mem_vec_4551 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4552);
											mem_vec_4552 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4553);
											mem_vec_4553 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4554);
											mem_vec_4554 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4555);
											mem_vec_4555 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_4536);
											mem_vec_4536 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_4537);
											mem_vec_4537 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4538);
											mem_vec_4538 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4539);
											mem_vec_4539 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_4540);
											mem_vec_4540 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_4541);
											mem_vec_4541 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_4542);
											mem_vec_4542 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_4543);
											mem_vec_4543 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_4544);
											mem_vec_4544 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_4545);
											mem_vec_4545 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_4546);
											mem_vec_4546 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_4547);
											mem_vec_4547 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_4548);
											mem_vec_4548 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_4549);
											mem_vec_4549 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_4550);
											mem_vec_4550 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_4551);
											mem_vec_4551 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_4552);
											mem_vec_4552 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_4553);
											mem_vec_4553 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_4554);
											mem_vec_4554 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_4555);
											mem_vec_4555 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_4536);
											mem_vec_4536 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_4537);
											mem_vec_4537 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_4538);
											mem_vec_4538 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_4539);
											mem_vec_4539 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_4540);
											mem_vec_4540 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_4541);
											mem_vec_4541 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_4542);
											mem_vec_4542 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_4543);
											mem_vec_4543 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_4544);
											mem_vec_4544 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_4545);
											mem_vec_4545 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_4546);
											mem_vec_4546 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_4547);
											mem_vec_4547 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_4548);
											mem_vec_4548 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_4549);
											mem_vec_4549 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_4550);
											mem_vec_4550 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_4551);
											mem_vec_4551 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_4552);
											mem_vec_4552 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_4553);
											mem_vec_4553 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_4554);
											mem_vec_4554 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_4555);
											mem_vec_4555 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4536);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4537);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4538);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4539);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4540);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4541);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4542);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4543);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4544);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4545);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4546);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4547);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4548);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4549);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4550);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4551);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4552);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4553);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4554);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4555);
							}
						}
					}
				}
			}
		}
		for (y = y194 + 110, yp_0 = 0;
			y < y194 + 110 + 26;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x382 = x383, x382_p_1 = x383_p_0, x382_p_0 = 0;
				x382 < x383 + 136;
				x382 += 34, x382_p_1 += 34, x382_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f192, fp_0 = 0;
					f < f192 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c288 = c289, c288_p_0 = 0;
						c288 < c289 + 64;
						c288 += 16, c288_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h125, hp_0 = 0;
							h < h125 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x382, xp_2 = x382_p_1, xp_1 = x382_p_0, xp_0 = 0;
								x < x382 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4556 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4557 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_4572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_4573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_4574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_4575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_4576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_4577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_4578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_4579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_4580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_4581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c288, cp_1 = c288_p_0, cp_0 = 0;
											c < c288 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4556);
											mem_vec_4556 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4557);
											mem_vec_4557 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4558);
											mem_vec_4558 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4559);
											mem_vec_4559 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4560);
											mem_vec_4560 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4561);
											mem_vec_4561 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4562);
											mem_vec_4562 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4563);
											mem_vec_4563 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4564);
											mem_vec_4564 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4565);
											mem_vec_4565 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4566);
											mem_vec_4566 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4567);
											mem_vec_4567 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4568);
											mem_vec_4568 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4569);
											mem_vec_4569 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4570);
											mem_vec_4570 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4571);
											mem_vec_4571 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4572);
											mem_vec_4572 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4573);
											mem_vec_4573 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4574);
											mem_vec_4574 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4575);
											mem_vec_4575 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4576);
											mem_vec_4576 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4577);
											mem_vec_4577 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4578);
											mem_vec_4578 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4579);
											mem_vec_4579 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4580);
											mem_vec_4580 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4581);
											mem_vec_4581 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_41 = _mm512_fmadd_ps(vec_42, vec_43, mem_vec_4556);
											mem_vec_4556 = vec_41;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_44 = _mm512_fmadd_ps(vec_42, vec_45, mem_vec_4557);
											mem_vec_4557 = vec_44;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_43, mem_vec_4558);
											mem_vec_4558 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_45, mem_vec_4559);
											mem_vec_4559 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_43, mem_vec_4560);
											mem_vec_4560 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_45, mem_vec_4561);
											mem_vec_4561 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_4562);
											mem_vec_4562 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_4563);
											mem_vec_4563 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_43, mem_vec_4564);
											mem_vec_4564 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_45, mem_vec_4565);
											mem_vec_4565 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_4566);
											mem_vec_4566 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_4567);
											mem_vec_4567 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_4568);
											mem_vec_4568 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_4569);
											mem_vec_4569 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_43, mem_vec_4570);
											mem_vec_4570 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_45, mem_vec_4571);
											mem_vec_4571 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_43, mem_vec_4572);
											mem_vec_4572 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_45, mem_vec_4573);
											mem_vec_4573 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 9 + h) + c];
											vec_71 = _mm512_set1_ps(scal_22);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_43, mem_vec_4574);
											mem_vec_4574 = vec_70;



											vec_72 = _mm512_fmadd_ps(vec_71, vec_45, mem_vec_4575);
											mem_vec_4575 = vec_72;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 10 + h) + c];
											vec_74 = _mm512_set1_ps(scal_23);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_4576);
											mem_vec_4576 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_4577);
											mem_vec_4577 = vec_75;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 11 + h) + c];
											vec_77 = _mm512_set1_ps(scal_24);


											vec_76 = _mm512_fmadd_ps(vec_77, vec_43, mem_vec_4578);
											mem_vec_4578 = vec_76;



											vec_78 = _mm512_fmadd_ps(vec_77, vec_45, mem_vec_4579);
											mem_vec_4579 = vec_78;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 12 + h) + c];
											vec_80 = _mm512_set1_ps(scal_25);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_43, mem_vec_4580);
											mem_vec_4580 = vec_79;



											vec_81 = _mm512_fmadd_ps(vec_80, vec_45, mem_vec_4581);
											mem_vec_4581 = vec_81;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_83 = _mm512_set1_ps(scal_26);
											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_82 = _mm512_fmadd_ps(vec_83, vec_84, mem_vec_4556);
											mem_vec_4556 = vec_82;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_85 = _mm512_fmadd_ps(vec_83, vec_86, mem_vec_4557);
											mem_vec_4557 = vec_85;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_4558);
											mem_vec_4558 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_4559);
											mem_vec_4559 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_84, mem_vec_4560);
											mem_vec_4560 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_86, mem_vec_4561);
											mem_vec_4561 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_84, mem_vec_4562);
											mem_vec_4562 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_86, mem_vec_4563);
											mem_vec_4563 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_4564);
											mem_vec_4564 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_4565);
											mem_vec_4565 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_84, mem_vec_4566);
											mem_vec_4566 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_86, mem_vec_4567);
											mem_vec_4567 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_4568);
											mem_vec_4568 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_4569);
											mem_vec_4569 = vec_104;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_106 = _mm512_set1_ps(scal_33);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_84, mem_vec_4570);
											mem_vec_4570 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_86, mem_vec_4571);
											mem_vec_4571 = vec_107;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_109 = _mm512_set1_ps(scal_34);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_84, mem_vec_4572);
											mem_vec_4572 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_86, mem_vec_4573);
											mem_vec_4573 = vec_110;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 9 + h) + c];
											vec_112 = _mm512_set1_ps(scal_35);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_84, mem_vec_4574);
											mem_vec_4574 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_86, mem_vec_4575);
											mem_vec_4575 = vec_113;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 10 + h) + c];
											vec_115 = _mm512_set1_ps(scal_36);


											vec_114 = _mm512_fmadd_ps(vec_115, vec_84, mem_vec_4576);
											mem_vec_4576 = vec_114;



											vec_116 = _mm512_fmadd_ps(vec_115, vec_86, mem_vec_4577);
											mem_vec_4577 = vec_116;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 11 + h) + c];
											vec_118 = _mm512_set1_ps(scal_37);


											vec_117 = _mm512_fmadd_ps(vec_118, vec_84, mem_vec_4578);
											mem_vec_4578 = vec_117;



											vec_119 = _mm512_fmadd_ps(vec_118, vec_86, mem_vec_4579);
											mem_vec_4579 = vec_119;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 12 + h) + c];
											vec_121 = _mm512_set1_ps(scal_38);


											vec_120 = _mm512_fmadd_ps(vec_121, vec_84, mem_vec_4580);
											mem_vec_4580 = vec_120;



											vec_122 = _mm512_fmadd_ps(vec_121, vec_86, mem_vec_4581);
											mem_vec_4581 = vec_122;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4567);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4571);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4575);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4576);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4577);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4578);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4579);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_4580);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_4581);
							}
						}
					}
				}
			}
		}
}


}