#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (1, f); T (64, c); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c1098_p_0, cp_1, c1098, f, fp_0, f1098_p_0, fp_1, f1098, w, wp_0, x, xp_0, x1098_p_0, xp_1, x1098, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y732 = 0;
IND_TYPE x1099 = 0;
IND_TYPE h = 0;
IND_TYPE w702 = 0;
IND_TYPE c1099 = 0;
IND_TYPE f1099 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11532 ,mem_vec_11533 ,mem_vec_11534 ,mem_vec_11535 ,mem_vec_11536 ,mem_vec_11537 ,mem_vec_11538 ,mem_vec_11539 ,mem_vec_11540 ,mem_vec_11541 ,mem_vec_11542 ,mem_vec_11543 ,mem_vec_11544 ,mem_vec_11545 ,mem_vec_11546 ,mem_vec_11547 ,mem_vec_11548 ,mem_vec_11549 ,mem_vec_11550 ,mem_vec_11551 ,mem_vec_11552 ,mem_vec_11553 ,mem_vec_11554 ,mem_vec_11555 ,mem_vec_11556 ,mem_vec_11557 ,mem_vec_11558 ,mem_vec_11559 ,mem_vec_11560 ,mem_vec_11561 ,mem_vec_11562 ,mem_vec_11563 ,mem_vec_11564 ,mem_vec_11565 ,mem_vec_11566 ,mem_vec_11567 ,mem_vec_11568 ,mem_vec_11569 ,mem_vec_11570 ,mem_vec_11571 ,mem_vec_11572 ,mem_vec_11573 ,mem_vec_11574 ,mem_vec_11575 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f1098 = f1099, f1098_p_0 = 0;
	f1098 < f1099 + 128;
	f1098 += 64, f1098_p_0 += 64){
		for (y = y732, yp_0 = 0;
			y < y732 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 4) (28 / 7)
			for (x1098 = x1099, x1098_p_0 = 0;
				x1098 < x1099 + 28;
				x1098 += 7, x1098_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 64
				// T (c, 64) (128 / 2)
				for (c1098 = c1099, c1098_p_0 = 0;
					c1098 < c1099 + 128;
					c1098 += 2, c1098_p_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1098, fp_1 = f1098_p_0, fp_0 = 0;
						f < f1098 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w702, wp_0 = 0;
							w < w702 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 2, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;
								x < x1098 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_11532 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_11533 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_11534 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_11535 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_11536 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_11537 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_11538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_11539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_11540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_11541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_11542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_11543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_11544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_11545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_11546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_11547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_11548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_11549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_11550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_11551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
											c < c1098 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11532);
											mem_vec_11532 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11533);
											mem_vec_11533 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11534);
											mem_vec_11534 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11535);
											mem_vec_11535 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11536);
											mem_vec_11536 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11537);
											mem_vec_11537 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11538);
											mem_vec_11538 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11539);
											mem_vec_11539 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11540);
											mem_vec_11540 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11541);
											mem_vec_11541 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11542);
											mem_vec_11542 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11543);
											mem_vec_11543 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11544);
											mem_vec_11544 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11545);
											mem_vec_11545 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11546);
											mem_vec_11546 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11547);
											mem_vec_11547 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11548);
											mem_vec_11548 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11549);
											mem_vec_11549 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11550);
											mem_vec_11550 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11551);
											mem_vec_11551 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_11532);
											mem_vec_11532 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_11533);
											mem_vec_11533 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_11534);
											mem_vec_11534 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_11535);
											mem_vec_11535 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_11536);
											mem_vec_11536 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_11537);
											mem_vec_11537 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_11538);
											mem_vec_11538 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_11539);
											mem_vec_11539 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_11540);
											mem_vec_11540 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_11541);
											mem_vec_11541 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_11542);
											mem_vec_11542 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_11543);
											mem_vec_11543 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_11544);
											mem_vec_11544 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_11545);
											mem_vec_11545 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_11546);
											mem_vec_11546 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_11547);
											mem_vec_11547 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_11548);
											mem_vec_11548 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_11549);
											mem_vec_11549 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_11550);
											mem_vec_11550 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_11551);
											mem_vec_11551 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_11532);
											mem_vec_11532 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_11533);
											mem_vec_11533 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_11534);
											mem_vec_11534 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_11535);
											mem_vec_11535 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_11536);
											mem_vec_11536 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_11537);
											mem_vec_11537 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_11538);
											mem_vec_11538 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_11539);
											mem_vec_11539 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_11540);
											mem_vec_11540 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_11541);
											mem_vec_11541 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_11542);
											mem_vec_11542 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_11543);
											mem_vec_11543 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_11544);
											mem_vec_11544 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_11545);
											mem_vec_11545 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_11546);
											mem_vec_11546 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_11547);
											mem_vec_11547 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_11548);
											mem_vec_11548 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_11549);
											mem_vec_11549 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_11550);
											mem_vec_11550 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_11551);
											mem_vec_11551 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11532);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11533);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11534);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11535);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11536);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11537);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11538);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11539);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11540);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11541);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11542);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11543);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11544);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11545);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11546);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11547);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11548);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11549);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11550);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11551);
							}
						}
					}
				}
			}
		}
		for (y = y732 + 10, yp_0 = 0;
			y < y732 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 4) (28 / 7)
			for (x1098 = x1099, x1098_p_0 = 0;
				x1098 < x1099 + 28;
				x1098 += 7, x1098_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 64
				// T (c, 64) (128 / 2)
				for (c1098 = c1099, c1098_p_0 = 0;
					c1098 < c1099 + 128;
					c1098 += 2, c1098_p_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1098, fp_1 = f1098_p_0, fp_0 = 0;
						f < f1098 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
						// T (w, 3) (3 / 1)
						for (w = w702, wp_0 = 0;
							w < w702 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 1, c = 2, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;
								x < x1098 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_11552 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_11553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_11554 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_11555 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_11556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_11557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_11558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_11559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_11560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_11561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_11562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_11563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_11564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_11565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_11566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_11567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_11568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_11569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_11570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_11571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_11572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_11573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_11574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_11575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
											c < c1098 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11552);
											mem_vec_11552 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11553);
											mem_vec_11553 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_11554);
											mem_vec_11554 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_11555);
											mem_vec_11555 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_11556);
											mem_vec_11556 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_11557);
											mem_vec_11557 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_11558);
											mem_vec_11558 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_11559);
											mem_vec_11559 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11560);
											mem_vec_11560 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11561);
											mem_vec_11561 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_11562);
											mem_vec_11562 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_11563);
											mem_vec_11563 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_11564);
											mem_vec_11564 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_11565);
											mem_vec_11565 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_11566);
											mem_vec_11566 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_11567);
											mem_vec_11567 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_11568);
											mem_vec_11568 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_11569);
											mem_vec_11569 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_11570);
											mem_vec_11570 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_11571);
											mem_vec_11571 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11572);
											mem_vec_11572 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11573);
											mem_vec_11573 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_11574);
											mem_vec_11574 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_11575);
											mem_vec_11575 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_11552);
											mem_vec_11552 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_11553);
											mem_vec_11553 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_11554);
											mem_vec_11554 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_11555);
											mem_vec_11555 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_11556);
											mem_vec_11556 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_11557);
											mem_vec_11557 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_11558);
											mem_vec_11558 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_11559);
											mem_vec_11559 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_11560);
											mem_vec_11560 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_11561);
											mem_vec_11561 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_11562);
											mem_vec_11562 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_11563);
											mem_vec_11563 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_11564);
											mem_vec_11564 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_11565);
											mem_vec_11565 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_11566);
											mem_vec_11566 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_11567);
											mem_vec_11567 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_11568);
											mem_vec_11568 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_11569);
											mem_vec_11569 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_11570);
											mem_vec_11570 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_11571);
											mem_vec_11571 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_11572);
											mem_vec_11572 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_11573);
											mem_vec_11573 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_11574);
											mem_vec_11574 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_11575);
											mem_vec_11575 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_11552);
											mem_vec_11552 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_11553);
											mem_vec_11553 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_11554);
											mem_vec_11554 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_11555);
											mem_vec_11555 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_11556);
											mem_vec_11556 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_11557);
											mem_vec_11557 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_11558);
											mem_vec_11558 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_11559);
											mem_vec_11559 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_11560);
											mem_vec_11560 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_11561);
											mem_vec_11561 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_11562);
											mem_vec_11562 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_11563);
											mem_vec_11563 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_11564);
											mem_vec_11564 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_11565);
											mem_vec_11565 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_11566);
											mem_vec_11566 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_11567);
											mem_vec_11567 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_11568);
											mem_vec_11568 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_11569);
											mem_vec_11569 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_11570);
											mem_vec_11570 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_11571);
											mem_vec_11571 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_11572);
											mem_vec_11572 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_11573);
											mem_vec_11573 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_11574);
											mem_vec_11574 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_11575);
											mem_vec_11575 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11552);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11553);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_11554);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_11555);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_11558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_11559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_11562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_11563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_11566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_11567);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_11570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_11571);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11572);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11573);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_11574);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_11575);
							}
						}
					}
				}
			}
		}
}


}