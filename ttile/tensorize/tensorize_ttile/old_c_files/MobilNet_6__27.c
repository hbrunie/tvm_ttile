#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, f); T (4, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (4, f)]
*/
IND_TYPE c, cp_0, c1110_p_0, cp_1, c1110, f, fp_0, f1110_p_0, fp_1, f1110, h, hp_0, x, xp_0, x1110_p_0, xp_1, x1110, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y740 = 0;
IND_TYPE x1111 = 0;
IND_TYPE h592 = 0;
IND_TYPE w = 0;
IND_TYPE c1111 = 0;
IND_TYPE f1111 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9584 ,mem_vec_9585 ,mem_vec_9586 ,mem_vec_9587 ,mem_vec_9588 ,mem_vec_9589 ,mem_vec_9590 ,mem_vec_9591 ,mem_vec_9592 ,mem_vec_9593 ,mem_vec_9594 ,mem_vec_9595 ,mem_vec_9596 ,mem_vec_9597 ,mem_vec_9598 ,mem_vec_9599 ,mem_vec_9600 ,mem_vec_9601 ,mem_vec_9602 ,mem_vec_9603 ,mem_vec_9604 ,mem_vec_9605 ,mem_vec_9606 ,mem_vec_9607 ,mem_vec_9608 ,mem_vec_9609 ,mem_vec_9610 ,mem_vec_9611 ,mem_vec_9612 ,mem_vec_9613 ,mem_vec_9614 ,mem_vec_9615 ,mem_vec_9616 ,mem_vec_9617 ,mem_vec_9618 ,mem_vec_9619 ,mem_vec_9620 ,mem_vec_9621 ,mem_vec_9622 ,mem_vec_9623 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f1110 = f1111, f1110_p_0 = 0;
	f1110 < f1111 + 256;
	f1110 += 64, f1110_p_0 += 64){
		for (y = y740, yp_0 = 0;
			y < y740 + 8;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 64
			// T (x, 2) (14 / 7)
			for (x1110 = x1111, x1110_p_0 = 0;
				x1110 < x1111 + 14;
				x1110 += 7, x1110_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
				// T (c, 4) (256 / 64)
				for (c1110 = c1111, c1110_p_0 = 0;
					c1110 < c1111 + 256;
					c1110 += 64, c1110_p_0 += 64){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1110, fp_1 = f1110_p_0, fp_0 = 0;
						f < f1110 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h592, hp_0 = 0;
							h < h592 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1110, xp_1 = x1110_p_0, xp_0 = 0;
								x < x1110 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9584 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9585 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9586 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_9587 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_9588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_9591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_9592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_9595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_9596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_9599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c1110, cp_1 = c1110_p_0, cp_0 = 0;
											c < c1110 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9584);
											mem_vec_9584 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9585);
											mem_vec_9585 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9586);
											mem_vec_9586 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9587);
											mem_vec_9587 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9588);
											mem_vec_9588 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9589);
											mem_vec_9589 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9590);
											mem_vec_9590 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9591);
											mem_vec_9591 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9592);
											mem_vec_9592 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9593);
											mem_vec_9593 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9594);
											mem_vec_9594 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9595);
											mem_vec_9595 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9596);
											mem_vec_9596 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9597);
											mem_vec_9597 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9598);
											mem_vec_9598 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9599);
											mem_vec_9599 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_9584);
											mem_vec_9584 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_9585);
											mem_vec_9585 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_9586);
											mem_vec_9586 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_9587);
											mem_vec_9587 = vec_31;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_9588);
											mem_vec_9588 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_9589);
											mem_vec_9589 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_9590);
											mem_vec_9590 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_9591);
											mem_vec_9591 = vec_37;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_9592);
											mem_vec_9592 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_9593);
											mem_vec_9593 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_9594);
											mem_vec_9594 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_9595);
											mem_vec_9595 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_9596);
											mem_vec_9596 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_9597);
											mem_vec_9597 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_9598);
											mem_vec_9598 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_9599);
											mem_vec_9599 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_9584);
											mem_vec_9584 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_9585);
											mem_vec_9585 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_9586);
											mem_vec_9586 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_9587);
											mem_vec_9587 = vec_55;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_9588);
											mem_vec_9588 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_9589);
											mem_vec_9589 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_9590);
											mem_vec_9590 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_9591);
											mem_vec_9591 = vec_61;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_9592);
											mem_vec_9592 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_9593);
											mem_vec_9593 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_9594);
											mem_vec_9594 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_9595);
											mem_vec_9595 = vec_66;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_9596);
											mem_vec_9596 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_9597);
											mem_vec_9597 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_9598);
											mem_vec_9598 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_9599);
											mem_vec_9599 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9584);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9585);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9586);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9587);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9588);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9589);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9590);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9591);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9592);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9593);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9594);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9595);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9596);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9597);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9598);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9599);
							}
						}
					}
				}
			}
		}
		for (y = y740 + 8, yp_0 = 0;
			y < y740 + 8 + 6;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 64
			// T (x, 2) (14 / 7)
			for (x1110 = x1111, x1110_p_0 = 0;
				x1110 < x1111 + 14;
				x1110 += 7, x1110_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 256, f = 64
				// T (c, 4) (256 / 64)
				for (c1110 = c1111, c1110_p_0 = 0;
					c1110 < c1111 + 256;
					c1110 += 64, c1110_p_0 += 64){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1110, fp_1 = f1110_p_0, fp_0 = 0;
						f < f1110 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
						// T (h, 3) (3 / 1)
						for (h = h592, hp_0 = 0;
							h < h592 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 64, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1110, xp_1 = x1110_p_0, xp_0 = 0;
								x < x1110 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9600 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9601 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9602 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_9603 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_9604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_9607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_9608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_9611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_9612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_9615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_9616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_9619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_9620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_9623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 64
										// T (c, 64) (64 / 1)
										for (c = c1110, cp_1 = c1110_p_0, cp_0 = 0;
											c < c1110 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9600);
											mem_vec_9600 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9601);
											mem_vec_9601 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9602);
											mem_vec_9602 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9603);
											mem_vec_9603 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9604);
											mem_vec_9604 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9605);
											mem_vec_9605 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9606);
											mem_vec_9606 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9607);
											mem_vec_9607 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9608);
											mem_vec_9608 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9609);
											mem_vec_9609 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9610);
											mem_vec_9610 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9611);
											mem_vec_9611 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9612);
											mem_vec_9612 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9613);
											mem_vec_9613 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9614);
											mem_vec_9614 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9615);
											mem_vec_9615 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9616);
											mem_vec_9616 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9617);
											mem_vec_9617 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9618);
											mem_vec_9618 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9619);
											mem_vec_9619 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9620);
											mem_vec_9620 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9621);
											mem_vec_9621 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_9622);
											mem_vec_9622 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_9623);
											mem_vec_9623 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_9600);
											mem_vec_9600 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_9601);
											mem_vec_9601 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_9602);
											mem_vec_9602 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_9603);
											mem_vec_9603 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_9604);
											mem_vec_9604 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_9605);
											mem_vec_9605 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_9606);
											mem_vec_9606 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_9607);
											mem_vec_9607 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_9608);
											mem_vec_9608 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_9609);
											mem_vec_9609 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_9610);
											mem_vec_9610 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_9611);
											mem_vec_9611 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_9612);
											mem_vec_9612 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_9613);
											mem_vec_9613 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_9614);
											mem_vec_9614 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_9615);
											mem_vec_9615 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_9616);
											mem_vec_9616 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_9617);
											mem_vec_9617 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_9618);
											mem_vec_9618 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_9619);
											mem_vec_9619 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_9620);
											mem_vec_9620 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_9621);
											mem_vec_9621 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_9622);
											mem_vec_9622 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_9623);
											mem_vec_9623 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_9600);
											mem_vec_9600 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_9601);
											mem_vec_9601 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_9602);
											mem_vec_9602 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_9603);
											mem_vec_9603 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_9604);
											mem_vec_9604 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_9605);
											mem_vec_9605 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_9606);
											mem_vec_9606 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_9607);
											mem_vec_9607 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_9608);
											mem_vec_9608 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_9609);
											mem_vec_9609 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_9610);
											mem_vec_9610 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_9611);
											mem_vec_9611 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_9612);
											mem_vec_9612 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_9613);
											mem_vec_9613 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_9614);
											mem_vec_9614 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_9615);
											mem_vec_9615 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_9616);
											mem_vec_9616 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_9617);
											mem_vec_9617 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_9618);
											mem_vec_9618 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_9619);
											mem_vec_9619 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_9620);
											mem_vec_9620 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_9621);
											mem_vec_9621 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_9622);
											mem_vec_9622 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_9623);
											mem_vec_9623 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9600);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9601);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9602);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9603);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9604);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9605);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9606);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9607);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9608);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9609);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9610);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9611);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9612);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9613);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9614);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9615);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9616);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9617);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9618);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9619);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9620);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9621);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_9622);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_9623);
							}
						}
					}
				}
			}
		}
}


}