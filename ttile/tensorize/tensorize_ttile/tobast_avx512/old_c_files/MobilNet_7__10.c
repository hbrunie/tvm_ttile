#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (32, c); T (8, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 1), (Arg 5))]; T (4, c)]
*/
IND_TYPE c, cp_0, c1468_p_0, c1469_p_0, cp_1, c1468_p_1, cp_2, c1468, c1469, f, fp_0, h, hp_0, x, xp_0, x1118_p_0, xp_1, x1118, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y748 = 0;
IND_TYPE x1119 = 0;
IND_TYPE h688 = 0;
IND_TYPE w = 0;
IND_TYPE c1470 = 0;
IND_TYPE f1316 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8444 ,mem_vec_8445 ,mem_vec_8446 ,mem_vec_8447 ,mem_vec_8448 ,mem_vec_8449 ,mem_vec_8450 ,mem_vec_8451 ,mem_vec_8452 ,mem_vec_8453 ,mem_vec_8454 ,mem_vec_8455 ,mem_vec_8456 ,mem_vec_8457 ,mem_vec_8458 ,mem_vec_8459 ,mem_vec_8460 ,mem_vec_8461 ,mem_vec_8462 ,mem_vec_8463 ,mem_vec_8464 ,mem_vec_8465 ,mem_vec_8466 ,mem_vec_8467 ,mem_vec_8468 ,mem_vec_8469 ,mem_vec_8470 ,mem_vec_8471 ,mem_vec_8472 ,mem_vec_8473 ,mem_vec_8474 ,mem_vec_8475 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 4) (512 / 128)
for (c1469 = c1470, c1469_p_0 = 0;
	c1469 < c1470 + 512;
	c1469 += 128, c1469_p_0 += 128){
		for (y = y748, yp_0 = 0;
			y < y748 + 9;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 512
			// T (x, 1) (14 / 14)
			for (x1118 = x1119, x1118_p_0 = 0;
				x1118 < x1119 + 14;
				x1118 += 14, x1118_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f1316, fp_0 = 0;
					f < f1316 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 32) (128 / 4)
					for (c1468 = c1469, c1468_p_1 = c1469_p_0, c1468_p_0 = 0;
						c1468 < c1469 + 128;
						c1468 += 4, c1468_p_1 += 4, c1468_p_0 += 4){
						// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 64
						// T (h, 3) (3 / 1)
						for (h = h688, hp_0 = 0;
							h < h688 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 4, f = 64
							// T (x, 14) (14 / 1)
							for (x = x1118, xp_1 = x1118_p_0, xp_0 = 0;
								x < x1118 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8444 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8445 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8446 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8447 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8448 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8449 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8450 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8451 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8452 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8453 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8454 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8455 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1468, cp_2 = c1468_p_1, cp_1 = c1468_p_0, cp_0 = 0;
											c < c1468 + 4;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8444);
											mem_vec_8444 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8445);
											mem_vec_8445 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8446);
											mem_vec_8446 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8447);
											mem_vec_8447 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8448);
											mem_vec_8448 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8449);
											mem_vec_8449 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8450);
											mem_vec_8450 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8451);
											mem_vec_8451 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8452);
											mem_vec_8452 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8453);
											mem_vec_8453 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8454);
											mem_vec_8454 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8455);
											mem_vec_8455 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);
											vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_8444);
											mem_vec_8444 = vec_19;

											vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_8445);
											mem_vec_8445 = vec_22;

											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_8446);
											mem_vec_8446 = vec_24;

											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_8447);
											mem_vec_8447 = vec_26;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_29 = _mm512_set1_ps(scal_4);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_8448);
											mem_vec_8448 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_8449);
											mem_vec_8449 = vec_30;



											vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_8450);
											mem_vec_8450 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_8451);
											mem_vec_8451 = vec_32;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_8452);
											mem_vec_8452 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_8453);
											mem_vec_8453 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_8454);
											mem_vec_8454 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_8455);
											mem_vec_8455 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);
											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_8444);
											mem_vec_8444 = vec_38;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_8445);
											mem_vec_8445 = vec_41;

											vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_8446);
											mem_vec_8446 = vec_43;

											vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_8447);
											mem_vec_8447 = vec_45;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_48 = _mm512_set1_ps(scal_7);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_8448);
											mem_vec_8448 = vec_47;



											vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_8449);
											mem_vec_8449 = vec_49;



											vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_8450);
											mem_vec_8450 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_8451);
											mem_vec_8451 = vec_51;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_53 = _mm512_set1_ps(scal_8);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_8452);
											mem_vec_8452 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_8453);
											mem_vec_8453 = vec_54;



											vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_8454);
											mem_vec_8454 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_8455);
											mem_vec_8455 = vec_56;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8444);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8445);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8446);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8447);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8448);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8449);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8450);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8451);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8452);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8453);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8454);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8455);
							}
						}
					}
				}
			}
		}
		for (y = y748 + 9, yp_0 = 0;
			y < y748 + 9 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 512
			// T (x, 1) (14 / 14)
			for (x1118 = x1119, x1118_p_0 = 0;
				x1118 < x1119 + 14;
				x1118 += 14, x1118_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f1316, fp_0 = 0;
					f < f1316 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 32) (128 / 4)
					for (c1468 = c1469, c1468_p_1 = c1469_p_0, c1468_p_0 = 0;
						c1468 < c1469 + 128;
						c1468 += 4, c1468_p_1 += 4, c1468_p_0 += 4){
						// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 64
						// T (h, 3) (3 / 1)
						for (h = h688, hp_0 = 0;
							h < h688 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 4, f = 64
							// T (x, 14) (14 / 1)
							for (x = x1118, xp_1 = x1118_p_0, xp_0 = 0;
								x < x1118 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8456 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8457 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8458 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8459 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_8472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_8475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1468, cp_2 = c1468_p_1, cp_1 = c1468_p_0, cp_0 = 0;
											c < c1468 + 4;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8456);
											mem_vec_8456 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8457);
											mem_vec_8457 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8458);
											mem_vec_8458 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8459);
											mem_vec_8459 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8460);
											mem_vec_8460 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8461);
											mem_vec_8461 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8462);
											mem_vec_8462 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8463);
											mem_vec_8463 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8464);
											mem_vec_8464 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8465);
											mem_vec_8465 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8466);
											mem_vec_8466 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8467);
											mem_vec_8467 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8468);
											mem_vec_8468 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8469);
											mem_vec_8469 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8470);
											mem_vec_8470 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8471);
											mem_vec_8471 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_8472);
											mem_vec_8472 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_8473);
											mem_vec_8473 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_8474);
											mem_vec_8474 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_8475);
											mem_vec_8475 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_8456);
											mem_vec_8456 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_8457);
											mem_vec_8457 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_8458);
											mem_vec_8458 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_8459);
											mem_vec_8459 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_8460);
											mem_vec_8460 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_8461);
											mem_vec_8461 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_8462);
											mem_vec_8462 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_8463);
											mem_vec_8463 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_8464);
											mem_vec_8464 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_8465);
											mem_vec_8465 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_8466);
											mem_vec_8466 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_8467);
											mem_vec_8467 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_8468);
											mem_vec_8468 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_8469);
											mem_vec_8469 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_8470);
											mem_vec_8470 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_8471);
											mem_vec_8471 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_8472);
											mem_vec_8472 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_8473);
											mem_vec_8473 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_8474);
											mem_vec_8474 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_8475);
											mem_vec_8475 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_8456);
											mem_vec_8456 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_8457);
											mem_vec_8457 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_8458);
											mem_vec_8458 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_8459);
											mem_vec_8459 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_8460);
											mem_vec_8460 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_8461);
											mem_vec_8461 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_8462);
											mem_vec_8462 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_8463);
											mem_vec_8463 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_8464);
											mem_vec_8464 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_8465);
											mem_vec_8465 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_8466);
											mem_vec_8466 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_8467);
											mem_vec_8467 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_8468);
											mem_vec_8468 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_8469);
											mem_vec_8469 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_8470);
											mem_vec_8470 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_8471);
											mem_vec_8471 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_8472);
											mem_vec_8472 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_8473);
											mem_vec_8473 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_8474);
											mem_vec_8474 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_8475);
											mem_vec_8475 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8456);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8457);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8458);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8459);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8460);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8461);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8462);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8463);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8467);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8471);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8473);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_8475);
							}
						}
					}
				}
			}
		}
}


}