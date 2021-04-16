#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); U (3, w); T (8, c); Hoist_vars [c]; T (56, x);
  T (3, h); T (16, c); T (8, y); T (1, x); T (1, f); T (1, c); T (4, f)]
*/
IND_TYPE c, cp_0, c580_p_0, c581_p_0, cp_1, c580_p_1, cp_2, c580, c581, f, fp_0, f431_p_0, fp_1, f431, h, hp_0, x, xp_0, x435_p_0, xp_1, x435, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y290 = 0;
IND_TYPE x436 = 0;
IND_TYPE h212 = 0;
IND_TYPE w = 0;
IND_TYPE c582 = 0;
IND_TYPE f432 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6524 ,mem_vec_6525 ,mem_vec_6526 ,mem_vec_6527 ,mem_vec_6528 ,mem_vec_6529 ,mem_vec_6530 ,mem_vec_6531 ,mem_vec_6532 ,mem_vec_6533 ,mem_vec_6534 ,mem_vec_6535 ,mem_vec_6536 ,mem_vec_6537 ,mem_vec_6538 ,mem_vec_6539 ,mem_vec_6540 ,mem_vec_6541 ,mem_vec_6542 ,mem_vec_6543 ,mem_vec_6544 ,mem_vec_6545 ,mem_vec_6546 ,mem_vec_6547 ,mem_vec_6548 ,mem_vec_6549 ,mem_vec_6550 ,mem_vec_6551 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
for (f431 = f432, f431_p_0 = 0;
	f431 < f432 + 128;
	f431 += 32, f431_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 32
	// T (c, 1) (128 / 128)
	for (c581 = c582, c581_p_0 = 0;
		c581 < c582 + 128;
		c581 += 128, c581_p_0 += 128){
		// y = 56, x = 56, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f = f431, fp_1 = f431_p_0, fp_0 = 0;
			f < f431 + 32;
			f += 32, fp_1 += 32, fp_0 += 32){
			// y = 56, x = 56, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (56 / 56)
			for (x435 = x436, x435_p_0 = 0;
				x435 < x436 + 56;
				x435 += 56, x435_p_0 += 56){
				// y = 56, x = 56, h = 3, w = 3, c = 128, f = 32
				// T (y, 8) (56 / 7)
				for (y = y290, yp_0 = 0;
					y < y290 + 56;
					y += 7, yp_0 += 7){
					// y = 7, x = 56, h = 3, w = 3, c = 128, f = 32
					// T (c, 16) (128 / 8)
					for (c580 = c581, c580_p_1 = c581_p_0, c580_p_0 = 0;
						c580 < c581 + 128;
						c580 += 8, c580_p_1 += 8, c580_p_0 += 8){
						// y = 7, x = 56, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h212, hp_0 = 0;
							h < h212 + 3;
							h += 1, hp_0 += 1){
							// y = 7, x = 56, h = 1, w = 3, c = 8, f = 32
							// T (x, 56) (56 / 1)
							for (x = x435, xp_1 = x435_p_0, xp_0 = 0;
								x < x435 + 56;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6524 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6525 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_6526 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6527 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_6528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_6530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_6532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_6534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_6536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_6538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_6540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_6542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_6544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_6546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_6548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_6550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = 7, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c580, cp_2 = c580_p_1, cp_1 = c580_p_0, cp_0 = 0;
											c < c580 + 8;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6524);
											mem_vec_6524 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6525);
											mem_vec_6525 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6526);
											mem_vec_6526 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6527);
											mem_vec_6527 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6528);
											mem_vec_6528 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6529);
											mem_vec_6529 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6530);
											mem_vec_6530 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6531);
											mem_vec_6531 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6532);
											mem_vec_6532 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6533);
											mem_vec_6533 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6534);
											mem_vec_6534 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6535);
											mem_vec_6535 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6536);
											mem_vec_6536 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6537);
											mem_vec_6537 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6538);
											mem_vec_6538 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6539);
											mem_vec_6539 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6540);
											mem_vec_6540 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6541);
											mem_vec_6541 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6542);
											mem_vec_6542 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6543);
											mem_vec_6543 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6544);
											mem_vec_6544 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6545);
											mem_vec_6545 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6546);
											mem_vec_6546 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6547);
											mem_vec_6547 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_6548);
											mem_vec_6548 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_6549);
											mem_vec_6549 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_6550);
											mem_vec_6550 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_6551);
											mem_vec_6551 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_6524);
											mem_vec_6524 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_6525);
											mem_vec_6525 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_6526);
											mem_vec_6526 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_6527);
											mem_vec_6527 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_6528);
											mem_vec_6528 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_6529);
											mem_vec_6529 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_6530);
											mem_vec_6530 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_6531);
											mem_vec_6531 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_6532);
											mem_vec_6532 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_6533);
											mem_vec_6533 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_6534);
											mem_vec_6534 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_6535);
											mem_vec_6535 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_6536);
											mem_vec_6536 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6537);
											mem_vec_6537 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6538);
											mem_vec_6538 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_6539);
											mem_vec_6539 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_6540);
											mem_vec_6540 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_6541);
											mem_vec_6541 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_6542);
											mem_vec_6542 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_6543);
											mem_vec_6543 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_6544);
											mem_vec_6544 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_6545);
											mem_vec_6545 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_6546);
											mem_vec_6546 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_6547);
											mem_vec_6547 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_6548);
											mem_vec_6548 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6549);
											mem_vec_6549 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6550);
											mem_vec_6550 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_6551);
											mem_vec_6551 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_6524);
											mem_vec_6524 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_6525);
											mem_vec_6525 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_6526);
											mem_vec_6526 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_6527);
											mem_vec_6527 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6528);
											mem_vec_6528 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6529);
											mem_vec_6529 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6530);
											mem_vec_6530 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6531);
											mem_vec_6531 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_6532);
											mem_vec_6532 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_6533);
											mem_vec_6533 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_6534);
											mem_vec_6534 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_6535);
											mem_vec_6535 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_6536);
											mem_vec_6536 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_6537);
											mem_vec_6537 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_6538);
											mem_vec_6538 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_6539);
											mem_vec_6539 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6540);
											mem_vec_6540 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_6541);
											mem_vec_6541 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6542);
											mem_vec_6542 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6543);
											mem_vec_6543 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_6544);
											mem_vec_6544 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_6545);
											mem_vec_6545 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_6546);
											mem_vec_6546 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_6547);
											mem_vec_6547 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_6548);
											mem_vec_6548 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_6549);
											mem_vec_6549 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_6550);
											mem_vec_6550 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_6551);
											mem_vec_6551 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6524);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6525);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6526);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6527);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6528);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6529);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6530);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6531);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6532);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6533);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6534);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6535);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6536);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6537);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6538);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6539);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6540);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6541);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6542);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6543);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6544);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6545);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6546);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6547);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6548);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6549);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6550);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_6551);
							}
						}
					}
				}
			}
		}
	}
}


}