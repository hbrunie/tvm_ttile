#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, f); T (32, c); T (28, x);
  Lambda_apply y [((Iter 7), (Arg 3)); ((Iter 1), (Arg 7))]; T (1, f)]
*/
IND_TYPE c, cp_0, c678_p_0, cp_1, c678, f, fp_0, f674_p_0, fp_1, f674, w, wp_0, x, xp_0, x678_p_0, xp_1, x678, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y452 = 0;
IND_TYPE x679 = 0;
IND_TYPE h = 0;
IND_TYPE w382 = 0;
IND_TYPE c679 = 0;
IND_TYPE f675 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5448 ,mem_vec_5449 ,mem_vec_5450 ,mem_vec_5451 ,mem_vec_5452 ,mem_vec_5453 ,mem_vec_5454 ,mem_vec_5455 ,mem_vec_5456 ,mem_vec_5457 ,mem_vec_5458 ,mem_vec_5459 ,mem_vec_5460 ,mem_vec_5461 ,mem_vec_5462 ,mem_vec_5463 ,mem_vec_5464 ,mem_vec_5465 ,mem_vec_5466 ,mem_vec_5467 ,mem_vec_5468 ,mem_vec_5469 ,mem_vec_5470 ,mem_vec_5471 ,mem_vec_5472 ,mem_vec_5473 ,mem_vec_5474 ,mem_vec_5475 ,mem_vec_5476 ,mem_vec_5477 ,mem_vec_5478 ,mem_vec_5479 ,mem_vec_5480 ,mem_vec_5481 ,mem_vec_5482 ,mem_vec_5483 ,mem_vec_5484 ,mem_vec_5485 ,mem_vec_5486 ,mem_vec_5487 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 1) (128 / 128)
for (f674 = f675, f674_p_0 = 0;
	f674 < f675 + 128;
	f674 += 128, f674_p_0 += 128){
		for (y = y452, yp_0 = 0;
			y < y452 + 21;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 128
			// T (x, 28) (28 / 1)
			for (x678 = x679, x678_p_0 = 0;
				x678 < x679 + 28;
				x678 += 1, x678_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 128
				// T (c, 32) (64 / 2)
				for (c678 = c679, c678_p_0 = 0;
					c678 < c679 + 64;
					c678 += 2, c678_p_0 += 2){
					// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 128
					// T (f, 2) (128 / 64)
					for (f = f674, fp_1 = f674_p_0, fp_0 = 0;
						f < f674 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w382, wp_0 = 0;
							w < w382 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
							// T (x, 1) (1 / 1)
							for (x = x678, xp_1 = x678_p_0, xp_0 = 0;
								x < x678 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5448 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5449 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5450 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5451 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5456 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5457 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5458 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5459 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c678, cp_1 = c678_p_0, cp_0 = 0;
											c < c678 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5448);
											mem_vec_5448 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5449);
											mem_vec_5449 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5450);
											mem_vec_5450 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5451);
											mem_vec_5451 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5452);
											mem_vec_5452 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5453);
											mem_vec_5453 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5454);
											mem_vec_5454 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5455);
											mem_vec_5455 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5456);
											mem_vec_5456 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5457);
											mem_vec_5457 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5458);
											mem_vec_5458 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5459);
											mem_vec_5459 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_5448);
											mem_vec_5448 = vec_19;

											vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_5449);
											mem_vec_5449 = vec_22;

											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_5450);
											mem_vec_5450 = vec_24;

											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_5451);
											mem_vec_5451 = vec_26;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_4);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_5452);
											mem_vec_5452 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_5453);
											mem_vec_5453 = vec_30;



											vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_5454);
											mem_vec_5454 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_5455);
											mem_vec_5455 = vec_32;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_5456);
											mem_vec_5456 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_5457);
											mem_vec_5457 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_5458);
											mem_vec_5458 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_5459);
											mem_vec_5459 = vec_37;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_5448);
											mem_vec_5448 = vec_38;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_5449);
											mem_vec_5449 = vec_41;

											vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_5450);
											mem_vec_5450 = vec_43;

											vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_5451);
											mem_vec_5451 = vec_45;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_48 = _mm512_set1_ps(scal_7);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_5452);
											mem_vec_5452 = vec_47;



											vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_5453);
											mem_vec_5453 = vec_49;



											vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_5454);
											mem_vec_5454 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_5455);
											mem_vec_5455 = vec_51;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_53 = _mm512_set1_ps(scal_8);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_5456);
											mem_vec_5456 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_5457);
											mem_vec_5457 = vec_54;



											vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_5458);
											mem_vec_5458 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_5459);
											mem_vec_5459 = vec_56;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5448);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5449);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5450);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5451);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5452);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5453);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5454);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5455);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5456);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5457);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5458);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5459);
							}
						}
					}
				}
			}
		}
		for (y = y452 + 21, yp_0 = 0;
			y < y452 + 21 + 7;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 128
			// T (x, 28) (28 / 1)
			for (x678 = x679, x678_p_0 = 0;
				x678 < x679 + 28;
				x678 += 1, x678_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 128
				// T (c, 32) (64 / 2)
				for (c678 = c679, c678_p_0 = 0;
					c678 < c679 + 64;
					c678 += 2, c678_p_0 += 2){
					// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 128
					// T (f, 2) (128 / 64)
					for (f = f674, fp_1 = f674_p_0, fp_0 = 0;
						f < f674 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w382, wp_0 = 0;
							w < w382 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
							// T (x, 1) (1 / 1)
							for (x = x678, xp_1 = x678_p_0, xp_0 = 0;
								x < x678 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5460 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5461 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5462 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5463 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_5480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_5483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_5484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_5485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_5486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_5487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c678, cp_1 = c678_p_0, cp_0 = 0;
											c < c678 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5460);
											mem_vec_5460 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5461);
											mem_vec_5461 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5462);
											mem_vec_5462 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5463);
											mem_vec_5463 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5464);
											mem_vec_5464 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5465);
											mem_vec_5465 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5466);
											mem_vec_5466 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5467);
											mem_vec_5467 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5468);
											mem_vec_5468 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5469);
											mem_vec_5469 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5470);
											mem_vec_5470 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5471);
											mem_vec_5471 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5472);
											mem_vec_5472 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5473);
											mem_vec_5473 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5474);
											mem_vec_5474 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5475);
											mem_vec_5475 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5476);
											mem_vec_5476 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5477);
											mem_vec_5477 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5478);
											mem_vec_5478 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5479);
											mem_vec_5479 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5480);
											mem_vec_5480 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5481);
											mem_vec_5481 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5482);
											mem_vec_5482 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5483);
											mem_vec_5483 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_5484);
											mem_vec_5484 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_5485);
											mem_vec_5485 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_5486);
											mem_vec_5486 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_5487);
											mem_vec_5487 = vec_38;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_40 = _mm512_set1_ps(scal_7);
											vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_5460);
											mem_vec_5460 = vec_39;

											vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_5461);
											mem_vec_5461 = vec_42;

											vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_5462);
											mem_vec_5462 = vec_44;

											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_5463);
											mem_vec_5463 = vec_46;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_5464);
											mem_vec_5464 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_5465);
											mem_vec_5465 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_5466);
											mem_vec_5466 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_5467);
											mem_vec_5467 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_5468);
											mem_vec_5468 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_5469);
											mem_vec_5469 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_5470);
											mem_vec_5470 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_5471);
											mem_vec_5471 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_5472);
											mem_vec_5472 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_5473);
											mem_vec_5473 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_5474);
											mem_vec_5474 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_5475);
											mem_vec_5475 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_5476);
											mem_vec_5476 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_5477);
											mem_vec_5477 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_5478);
											mem_vec_5478 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_5479);
											mem_vec_5479 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_69 = _mm512_set1_ps(scal_12);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_5480);
											mem_vec_5480 = vec_68;



											vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_5481);
											mem_vec_5481 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_5482);
											mem_vec_5482 = vec_71;



											vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_5483);
											mem_vec_5483 = vec_72;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_13);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_5484);
											mem_vec_5484 = vec_73;



											vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_5485);
											mem_vec_5485 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_5486);
											mem_vec_5486 = vec_76;



											vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_5487);
											mem_vec_5487 = vec_77;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_14);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_5460);
											mem_vec_5460 = vec_78;

											vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_5461);
											mem_vec_5461 = vec_81;

											vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_5462);
											mem_vec_5462 = vec_83;

											vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_5463);
											mem_vec_5463 = vec_85;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_5464);
											mem_vec_5464 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_5465);
											mem_vec_5465 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_5466);
											mem_vec_5466 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_5467);
											mem_vec_5467 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_5468);
											mem_vec_5468 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_5469);
											mem_vec_5469 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_5470);
											mem_vec_5470 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_5471);
											mem_vec_5471 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_5472);
											mem_vec_5472 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_5473);
											mem_vec_5473 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_5474);
											mem_vec_5474 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_5475);
											mem_vec_5475 = vec_101;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_18);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_5476);
											mem_vec_5476 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_5477);
											mem_vec_5477 = vec_104;



											vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_5478);
											mem_vec_5478 = vec_105;



											vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_5479);
											mem_vec_5479 = vec_106;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_108 = _mm512_set1_ps(scal_19);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_5480);
											mem_vec_5480 = vec_107;



											vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_5481);
											mem_vec_5481 = vec_109;



											vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_5482);
											mem_vec_5482 = vec_110;



											vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_5483);
											mem_vec_5483 = vec_111;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_113 = _mm512_set1_ps(scal_20);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_5484);
											mem_vec_5484 = vec_112;



											vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_5485);
											mem_vec_5485 = vec_114;



											vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_5486);
											mem_vec_5486 = vec_115;



											vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_5487);
											mem_vec_5487 = vec_116;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5460);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5461);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5463);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5467);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5471);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5473);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5475);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5476);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5477);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5478);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5479);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5483);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_5486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_5487);
							}
						}
					}
				}
			}
		}
}


}