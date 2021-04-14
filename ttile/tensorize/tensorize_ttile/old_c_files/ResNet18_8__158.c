#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (8, f); T (32, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (1, f)]
*/
IND_TYPE c, cp_0, c996_p_0, cp_1, c996, f, fp_0, f1068_p_0, fp_1, f1068, w, wp_0, x, xp_0, x996_p_0, xp_1, x996, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y664 = 0;
IND_TYPE x997 = 0;
IND_TYPE h = 0;
IND_TYPE w614 = 0;
IND_TYPE c997 = 0;
IND_TYPE f1069 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9472 ,mem_vec_9473 ,mem_vec_9474 ,mem_vec_9475 ,mem_vec_9476 ,mem_vec_9477 ,mem_vec_9478 ,mem_vec_9479 ,mem_vec_9480 ,mem_vec_9481 ,mem_vec_9482 ,mem_vec_9483 ,mem_vec_9484 ,mem_vec_9485 ,mem_vec_9486 ,mem_vec_9487 ,mem_vec_9488 ,mem_vec_9489 ,mem_vec_9490 ,mem_vec_9491 ,mem_vec_9492 ,mem_vec_9493 ,mem_vec_9494 ,mem_vec_9495 ,mem_vec_9496 ,mem_vec_9497 ,mem_vec_9498 ,mem_vec_9499 ,mem_vec_9500 ,mem_vec_9501 ,mem_vec_9502 ,mem_vec_9503 ,mem_vec_9504 ,mem_vec_9505 ,mem_vec_9506 ,mem_vec_9507 ,mem_vec_9508 ,mem_vec_9509 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1068 = f1069, f1068_p_0 = 0;
	f1068 < f1069 + 256;
	f1068 += 256, f1068_p_0 += 256){
		for (y = y664, yp_0 = 0;
			y < y664 + 18;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (28 / 14)
			for (x996 = x997, x996_p_0 = 0;
				x996 < x997 + 28;
				x996 += 14, x996_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
				// T (c, 32) (128 / 4)
				for (c996 = c997, c996_p_0 = 0;
					c996 < c997 + 128;
					c996 += 4, c996_p_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 256
					// T (f, 8) (256 / 32)
					for (f = f1068, fp_1 = f1068_p_0, fp_0 = 0;
						f < f1068 + 256;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w614, wp_0 = 0;
							w < w614 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 4, f = 32
							// T (x, 14) (14 / 1)
							for (x = x996, xp_1 = x996_p_0, xp_0 = 0;
								x < x996 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9472 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9473 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c996, cp_1 = c996_p_0, cp_0 = 0;
											c < c996 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9472);
											mem_vec_9472 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9473);
											mem_vec_9473 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9474);
											mem_vec_9474 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9475);
											mem_vec_9475 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9476);
											mem_vec_9476 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9477);
											mem_vec_9477 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9478);
											mem_vec_9478 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9479);
											mem_vec_9479 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9480);
											mem_vec_9480 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9481);
											mem_vec_9481 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9482);
											mem_vec_9482 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9483);
											mem_vec_9483 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9484);
											mem_vec_9484 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9485);
											mem_vec_9485 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9486);
											mem_vec_9486 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9487);
											mem_vec_9487 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9488);
											mem_vec_9488 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9489);
											mem_vec_9489 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_9472);
											mem_vec_9472 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_9473);
											mem_vec_9473 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_9474);
											mem_vec_9474 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_9475);
											mem_vec_9475 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_9476);
											mem_vec_9476 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_9477);
											mem_vec_9477 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_9478);
											mem_vec_9478 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_9479);
											mem_vec_9479 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_9480);
											mem_vec_9480 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_9481);
											mem_vec_9481 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_9482);
											mem_vec_9482 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_9483);
											mem_vec_9483 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_9484);
											mem_vec_9484 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_9485);
											mem_vec_9485 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_9486);
											mem_vec_9486 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_9487);
											mem_vec_9487 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_9488);
											mem_vec_9488 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_9489);
											mem_vec_9489 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_9472);
											mem_vec_9472 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_9473);
											mem_vec_9473 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_9474);
											mem_vec_9474 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_9475);
											mem_vec_9475 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_9476);
											mem_vec_9476 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_9477);
											mem_vec_9477 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_9478);
											mem_vec_9478 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_9479);
											mem_vec_9479 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_9480);
											mem_vec_9480 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_9481);
											mem_vec_9481 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_9482);
											mem_vec_9482 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_9483);
											mem_vec_9483 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_9484);
											mem_vec_9484 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_9485);
											mem_vec_9485 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_9486);
											mem_vec_9486 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_9487);
											mem_vec_9487 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_9488);
											mem_vec_9488 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_9489);
											mem_vec_9489 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9473);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9475);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9476);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9477);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9478);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9479);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9483);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9487);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9488);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9489);
							}
						}
					}
				}
			}
		}
		for (y = y664 + 18, yp_0 = 0;
			y < y664 + 18 + 10;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (28 / 14)
			for (x996 = x997, x996_p_0 = 0;
				x996 < x997 + 28;
				x996 += 14, x996_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
				// T (c, 32) (128 / 4)
				for (c996 = c997, c996_p_0 = 0;
					c996 < c997 + 128;
					c996 += 4, c996_p_0 += 4){
					// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 256
					// T (f, 8) (256 / 32)
					for (f = f1068, fp_1 = f1068_p_0, fp_0 = 0;
						f < f1068 + 256;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w614, wp_0 = 0;
							w < w614 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 4, f = 32
							// T (x, 14) (14 / 1)
							for (x = x996, xp_1 = x996_p_0, xp_0 = 0;
								x < x996 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9490 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9491 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c996, cp_1 = c996_p_0, cp_0 = 0;
											c < c996 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9490);
											mem_vec_9490 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9491);
											mem_vec_9491 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9492);
											mem_vec_9492 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9493);
											mem_vec_9493 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9494);
											mem_vec_9494 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9495);
											mem_vec_9495 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9496);
											mem_vec_9496 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9497);
											mem_vec_9497 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9498);
											mem_vec_9498 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9499);
											mem_vec_9499 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9500);
											mem_vec_9500 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9501);
											mem_vec_9501 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9502);
											mem_vec_9502 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9503);
											mem_vec_9503 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9504);
											mem_vec_9504 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9505);
											mem_vec_9505 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9506);
											mem_vec_9506 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9507);
											mem_vec_9507 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9508);
											mem_vec_9508 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9509);
											mem_vec_9509 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_9490);
											mem_vec_9490 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_9491);
											mem_vec_9491 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_9492);
											mem_vec_9492 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_9493);
											mem_vec_9493 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_9494);
											mem_vec_9494 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_9495);
											mem_vec_9495 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_9496);
											mem_vec_9496 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_9497);
											mem_vec_9497 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_9498);
											mem_vec_9498 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_9499);
											mem_vec_9499 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_9500);
											mem_vec_9500 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_9501);
											mem_vec_9501 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_9502);
											mem_vec_9502 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_9503);
											mem_vec_9503 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_9504);
											mem_vec_9504 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_9505);
											mem_vec_9505 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_9506);
											mem_vec_9506 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_9507);
											mem_vec_9507 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_9508);
											mem_vec_9508 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_9509);
											mem_vec_9509 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_9490);
											mem_vec_9490 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_9491);
											mem_vec_9491 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_9492);
											mem_vec_9492 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_9493);
											mem_vec_9493 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_9494);
											mem_vec_9494 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_9495);
											mem_vec_9495 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_9496);
											mem_vec_9496 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_9497);
											mem_vec_9497 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_9498);
											mem_vec_9498 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_9499);
											mem_vec_9499 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_9500);
											mem_vec_9500 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_9501);
											mem_vec_9501 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_9502);
											mem_vec_9502 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_9503);
											mem_vec_9503 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_9504);
											mem_vec_9504 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_9505);
											mem_vec_9505 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_9506);
											mem_vec_9506 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_9507);
											mem_vec_9507 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_9508);
											mem_vec_9508 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_9509);
											mem_vec_9509 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9490);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9491);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9492);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9493);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9494);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9495);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9496);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9497);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9498);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9499);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9500);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9501);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9502);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9503);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9504);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9505);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9506);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9507);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9508);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9509);
							}
						}
					}
				}
			}
		}
}


}