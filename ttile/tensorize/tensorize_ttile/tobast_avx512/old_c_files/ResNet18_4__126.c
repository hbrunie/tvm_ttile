#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (4, f); T (1, c); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 5)); ((Iter 1), (Arg 13))]; T (1, f)]
*/
IND_TYPE c, cp_0, c804_p_0, cp_1, c804, f, fp_0, f800_p_0, fp_1, f800, h, hp_0, x, xp_0, x804_p_0, xp_1, x804, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y536 = 0;
IND_TYPE x805 = 0;
IND_TYPE h390 = 0;
IND_TYPE w = 0;
IND_TYPE c805 = 0;
IND_TYPE f801 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6414 ,mem_vec_6415 ,mem_vec_6416 ,mem_vec_6417 ,mem_vec_6418 ,mem_vec_6419 ,mem_vec_6420 ,mem_vec_6421 ,mem_vec_6422 ,mem_vec_6423 ,mem_vec_6424 ,mem_vec_6425 ,mem_vec_6426 ,mem_vec_6427 ,mem_vec_6428 ,mem_vec_6429 ,mem_vec_6430 ,mem_vec_6431 ,mem_vec_6432 ,mem_vec_6433 ,mem_vec_6434 ,mem_vec_6435 ,mem_vec_6436 ,mem_vec_6437 ,mem_vec_6438 ,mem_vec_6439 ,mem_vec_6440 ,mem_vec_6441 ,mem_vec_6442 ,mem_vec_6443 ,mem_vec_6444 ,mem_vec_6445 ,mem_vec_6446 ,mem_vec_6447 ,mem_vec_6448 ,mem_vec_6449 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f800 = f801, f800_p_0 = 0;
	f800 < f801 + 128;
	f800 += 128, f800_p_0 += 128){
		for (y = y536, yp_0 = 0;
			y < y536 + 15;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 128
			// T (x, 1) (28 / 28)
			for (x804 = x805, x804_p_0 = 0;
				x804 < x805 + 28;
				x804 += 28, x804_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 128
				// T (c, 1) (64 / 64)
				for (c804 = c805, c804_p_0 = 0;
					c804 < c805 + 64;
					c804 += 64, c804_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 128
					// T (f, 4) (128 / 32)
					for (f = f800, fp_1 = f800_p_0, fp_0 = 0;
						f < f800 + 128;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h390, hp_0 = 0;
							h < h390 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 64, f = 32
							// T (x, 28) (28 / 1)
							for (x = x804, xp_1 = x804_p_0, xp_0 = 0;
								x < x804 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6414 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6415 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c804, cp_1 = c804_p_0, cp_0 = 0;
											c < c804 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6414);
											mem_vec_6414 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6415);
											mem_vec_6415 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6416);
											mem_vec_6416 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6417);
											mem_vec_6417 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6418);
											mem_vec_6418 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6419);
											mem_vec_6419 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6420);
											mem_vec_6420 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6421);
											mem_vec_6421 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6422);
											mem_vec_6422 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6423);
											mem_vec_6423 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);
											vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_6414);
											mem_vec_6414 = vec_17;

											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_6415);
											mem_vec_6415 = vec_20;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_23 = _mm512_set1_ps(scal_6);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_6416);
											mem_vec_6416 = vec_22;



											vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_6417);
											mem_vec_6417 = vec_24;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_6418);
											mem_vec_6418 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_6419);
											mem_vec_6419 = vec_27;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_6420);
											mem_vec_6420 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_6421);
											mem_vec_6421 = vec_30;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_6422);
											mem_vec_6422 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_6423);
											mem_vec_6423 = vec_33;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_6414);
											mem_vec_6414 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_6415);
											mem_vec_6415 = vec_37;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_40 = _mm512_set1_ps(scal_11);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_6416);
											mem_vec_6416 = vec_39;



											vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_6417);
											mem_vec_6417 = vec_41;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_43 = _mm512_set1_ps(scal_12);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_6418);
											mem_vec_6418 = vec_42;



											vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_6419);
											mem_vec_6419 = vec_44;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_46 = _mm512_set1_ps(scal_13);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_6420);
											mem_vec_6420 = vec_45;



											vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_6421);
											mem_vec_6421 = vec_47;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_49 = _mm512_set1_ps(scal_14);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_6422);
											mem_vec_6422 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_6423);
											mem_vec_6423 = vec_50;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6414);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6415);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6416);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6417);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6418);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6419);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6420);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6421);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6422);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6423);
							}
						}
					}
				}
			}
		}
		for (y = y536 + 15, yp_0 = 0;
			y < y536 + 15 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 128
			// T (x, 1) (28 / 28)
			for (x804 = x805, x804_p_0 = 0;
				x804 < x805 + 28;
				x804 += 28, x804_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 128
				// T (c, 1) (64 / 64)
				for (c804 = c805, c804_p_0 = 0;
					c804 < c805 + 64;
					c804 += 64, c804_p_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 128
					// T (f, 4) (128 / 32)
					for (f = f800, fp_1 = f800_p_0, fp_0 = 0;
						f < f800 + 128;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h390, hp_0 = 0;
							h < h390 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 64, f = 32
							// T (x, 28) (28 / 1)
							for (x = x804, xp_1 = x804_p_0, xp_0 = 0;
								x < x804 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6424 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6425 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6434 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6435 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6436 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6437 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6438 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6439 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_6440 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6441 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_6442 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_6443 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_6444 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_6445 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_6446 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_6447 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_6448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_6449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c804, cp_1 = c804_p_0, cp_0 = 0;
											c < c804 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6424);
											mem_vec_6424 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6425);
											mem_vec_6425 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6426);
											mem_vec_6426 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6427);
											mem_vec_6427 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6428);
											mem_vec_6428 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6429);
											mem_vec_6429 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6430);
											mem_vec_6430 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6431);
											mem_vec_6431 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6432);
											mem_vec_6432 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6433);
											mem_vec_6433 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6434);
											mem_vec_6434 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6435);
											mem_vec_6435 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6436);
											mem_vec_6436 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6437);
											mem_vec_6437 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6438);
											mem_vec_6438 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6439);
											mem_vec_6439 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6440);
											mem_vec_6440 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6441);
											mem_vec_6441 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6442);
											mem_vec_6442 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6443);
											mem_vec_6443 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6444);
											mem_vec_6444 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6445);
											mem_vec_6445 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6446);
											mem_vec_6446 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6447);
											mem_vec_6447 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_6448);
											mem_vec_6448 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_6449);
											mem_vec_6449 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);
											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_41 = _mm512_fmadd_ps(vec_42, vec_43, mem_vec_6424);
											mem_vec_6424 = vec_41;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_44 = _mm512_fmadd_ps(vec_42, vec_45, mem_vec_6425);
											mem_vec_6425 = vec_44;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_43, mem_vec_6426);
											mem_vec_6426 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_45, mem_vec_6427);
											mem_vec_6427 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_43, mem_vec_6428);
											mem_vec_6428 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_45, mem_vec_6429);
											mem_vec_6429 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_6430);
											mem_vec_6430 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_6431);
											mem_vec_6431 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_43, mem_vec_6432);
											mem_vec_6432 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_45, mem_vec_6433);
											mem_vec_6433 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_6434);
											mem_vec_6434 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_6435);
											mem_vec_6435 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_6436);
											mem_vec_6436 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_6437);
											mem_vec_6437 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 7) + h) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_43, mem_vec_6438);
											mem_vec_6438 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_45, mem_vec_6439);
											mem_vec_6439 = vec_66;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 8) + h) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_43, mem_vec_6440);
											mem_vec_6440 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_45, mem_vec_6441);
											mem_vec_6441 = vec_69;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 9) + h) + c];
											vec_71 = _mm512_set1_ps(scal_22);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_43, mem_vec_6442);
											mem_vec_6442 = vec_70;



											vec_72 = _mm512_fmadd_ps(vec_71, vec_45, mem_vec_6443);
											mem_vec_6443 = vec_72;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 10) + h) + c];
											vec_74 = _mm512_set1_ps(scal_23);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_6444);
											mem_vec_6444 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_6445);
											mem_vec_6445 = vec_75;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 11) + h) + c];
											vec_77 = _mm512_set1_ps(scal_24);


											vec_76 = _mm512_fmadd_ps(vec_77, vec_43, mem_vec_6446);
											mem_vec_6446 = vec_76;



											vec_78 = _mm512_fmadd_ps(vec_77, vec_45, mem_vec_6447);
											mem_vec_6447 = vec_78;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 12) + h) + c];
											vec_80 = _mm512_set1_ps(scal_25);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_43, mem_vec_6448);
											mem_vec_6448 = vec_79;



											vec_81 = _mm512_fmadd_ps(vec_80, vec_45, mem_vec_6449);
											mem_vec_6449 = vec_81;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_83 = _mm512_set1_ps(scal_26);
											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_82 = _mm512_fmadd_ps(vec_83, vec_84, mem_vec_6424);
											mem_vec_6424 = vec_82;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_85 = _mm512_fmadd_ps(vec_83, vec_86, mem_vec_6425);
											mem_vec_6425 = vec_85;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_6426);
											mem_vec_6426 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_6427);
											mem_vec_6427 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_84, mem_vec_6428);
											mem_vec_6428 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_86, mem_vec_6429);
											mem_vec_6429 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_84, mem_vec_6430);
											mem_vec_6430 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_86, mem_vec_6431);
											mem_vec_6431 = vec_95;
											scal_30 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_6432);
											mem_vec_6432 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_6433);
											mem_vec_6433 = vec_98;
											scal_31 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_84, mem_vec_6434);
											mem_vec_6434 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_86, mem_vec_6435);
											mem_vec_6435 = vec_101;
											scal_32 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_6436);
											mem_vec_6436 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_6437);
											mem_vec_6437 = vec_104;
											scal_33 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 7) + h) + c];
											vec_106 = _mm512_set1_ps(scal_33);


											vec_105 = _mm512_fmadd_ps(vec_106, vec_84, mem_vec_6438);
											mem_vec_6438 = vec_105;



											vec_107 = _mm512_fmadd_ps(vec_106, vec_86, mem_vec_6439);
											mem_vec_6439 = vec_107;
											scal_34 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 8) + h) + c];
											vec_109 = _mm512_set1_ps(scal_34);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_84, mem_vec_6440);
											mem_vec_6440 = vec_108;



											vec_110 = _mm512_fmadd_ps(vec_109, vec_86, mem_vec_6441);
											mem_vec_6441 = vec_110;
											scal_35 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 9) + h) + c];
											vec_112 = _mm512_set1_ps(scal_35);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_84, mem_vec_6442);
											mem_vec_6442 = vec_111;



											vec_113 = _mm512_fmadd_ps(vec_112, vec_86, mem_vec_6443);
											mem_vec_6443 = vec_113;
											scal_36 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 10) + h) + c];
											vec_115 = _mm512_set1_ps(scal_36);


											vec_114 = _mm512_fmadd_ps(vec_115, vec_84, mem_vec_6444);
											mem_vec_6444 = vec_114;



											vec_116 = _mm512_fmadd_ps(vec_115, vec_86, mem_vec_6445);
											mem_vec_6445 = vec_116;
											scal_37 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 11) + h) + c];
											vec_118 = _mm512_set1_ps(scal_37);


											vec_117 = _mm512_fmadd_ps(vec_118, vec_84, mem_vec_6446);
											mem_vec_6446 = vec_117;



											vec_119 = _mm512_fmadd_ps(vec_118, vec_86, mem_vec_6447);
											mem_vec_6447 = vec_119;
											scal_38 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 12) + h) + c];
											vec_121 = _mm512_set1_ps(scal_38);


											vec_120 = _mm512_fmadd_ps(vec_121, vec_84, mem_vec_6448);
											mem_vec_6448 = vec_120;



											vec_122 = _mm512_fmadd_ps(vec_121, vec_86, mem_vec_6449);
											mem_vec_6449 = vec_122;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6424);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6425);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6426);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6427);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6428);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6429);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6430);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6431);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6432);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6433);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6434);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6435);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6436);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6437);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6438);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6439);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6440);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6441);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6442);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6443);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6444);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6445);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6446);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6447);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_6448);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_6449);
							}
						}
					}
				}
			}
		}
}


}