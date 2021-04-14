#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (4, f); T (8, c); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (1, f)]
*/
IND_TYPE c, cp_0, c954_p_0, cp_1, c954, f, fp_0, f954_p_0, fp_1, f954, h, hp_0, x, xp_0, x954_p_0, xp_1, x954, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y636 = 0;
IND_TYPE x955 = 0;
IND_TYPE h478 = 0;
IND_TYPE w = 0;
IND_TYPE c955 = 0;
IND_TYPE f955 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7596 ,mem_vec_7597 ,mem_vec_7598 ,mem_vec_7599 ,mem_vec_7600 ,mem_vec_7601 ,mem_vec_7602 ,mem_vec_7603 ,mem_vec_7604 ,mem_vec_7605 ,mem_vec_7606 ,mem_vec_7607 ,mem_vec_7608 ,mem_vec_7609 ,mem_vec_7610 ,mem_vec_7611 ,mem_vec_7612 ,mem_vec_7613 ,mem_vec_7614 ,mem_vec_7615 ,mem_vec_7616 ,mem_vec_7617 ,mem_vec_7618 ,mem_vec_7619 ,mem_vec_7620 ,mem_vec_7621 ,mem_vec_7622 ,mem_vec_7623 ,mem_vec_7624 ,mem_vec_7625 ,mem_vec_7626 ,mem_vec_7627 ,mem_vec_7628 ,mem_vec_7629 ,mem_vec_7630 ,mem_vec_7631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f954 = f955, f954_p_0 = 0;
	f954 < f955 + 256;
	f954 += 256, f954_p_0 += 256){
		for (y = y636, yp_0 = 0;
			y < y636 + 4;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (14 / 7)
			for (x954 = x955, x954_p_0 = 0;
				x954 < x955 + 14;
				x954 += 7, x954_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 256
				// T (c, 8) (128 / 16)
				for (c954 = c955, c954_p_0 = 0;
					c954 < c955 + 128;
					c954 += 16, c954_p_0 += 16){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 256
					// T (f, 4) (256 / 64)
					for (f = f954, fp_1 = f954_p_0, fp_0 = 0;
						f < f954 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h478, hp_0 = 0;
							h < h478 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 64
							// T (x, 7) (7 / 1)
							for (x = x954, xp_1 = x954_p_0, xp_0 = 0;
								x < x954 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7596 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7597 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7598 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7599 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c954, cp_1 = c954_p_0, cp_0 = 0;
											c < c954 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7596);
											mem_vec_7596 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7597);
											mem_vec_7597 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7598);
											mem_vec_7598 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7599);
											mem_vec_7599 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7600);
											mem_vec_7600 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7601);
											mem_vec_7601 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7602);
											mem_vec_7602 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7603);
											mem_vec_7603 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7604);
											mem_vec_7604 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7605);
											mem_vec_7605 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7606);
											mem_vec_7606 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7607);
											mem_vec_7607 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7608);
											mem_vec_7608 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7609);
											mem_vec_7609 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7610);
											mem_vec_7610 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7611);
											mem_vec_7611 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_7596);
											mem_vec_7596 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_7597);
											mem_vec_7597 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_7598);
											mem_vec_7598 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_7599);
											mem_vec_7599 = vec_31;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_7600);
											mem_vec_7600 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_7601);
											mem_vec_7601 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_7602);
											mem_vec_7602 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_7603);
											mem_vec_7603 = vec_37;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_7604);
											mem_vec_7604 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_7605);
											mem_vec_7605 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_7606);
											mem_vec_7606 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_7607);
											mem_vec_7607 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_7608);
											mem_vec_7608 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7609);
											mem_vec_7609 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7610);
											mem_vec_7610 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7611);
											mem_vec_7611 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_7596);
											mem_vec_7596 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_7597);
											mem_vec_7597 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_7598);
											mem_vec_7598 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_7599);
											mem_vec_7599 = vec_55;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_7600);
											mem_vec_7600 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_7601);
											mem_vec_7601 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7602);
											mem_vec_7602 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7603);
											mem_vec_7603 = vec_61;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_7604);
											mem_vec_7604 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_7605);
											mem_vec_7605 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_7606);
											mem_vec_7606 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_7607);
											mem_vec_7607 = vec_66;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_7608);
											mem_vec_7608 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_7609);
											mem_vec_7609 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_7610);
											mem_vec_7610 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_7611);
											mem_vec_7611 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7596);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7597);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7598);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7599);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7600);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7601);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7602);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7603);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7604);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7605);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7606);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7607);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7608);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7609);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7610);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7611);
							}
						}
					}
				}
			}
		}
		for (y = y636 + 4, yp_0 = 0;
			y < y636 + 4 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (14 / 7)
			for (x954 = x955, x954_p_0 = 0;
				x954 < x955 + 14;
				x954 += 7, x954_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 256
				// T (c, 8) (128 / 16)
				for (c954 = c955, c954_p_0 = 0;
					c954 < c955 + 128;
					c954 += 16, c954_p_0 += 16){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 256
					// T (f, 4) (256 / 64)
					for (f = f954, fp_1 = f954_p_0, fp_0 = 0;
						f < f954 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (h, 3) (3 / 1)
						for (h = h478, hp_0 = 0;
							h < h478 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 16, f = 64
							// T (x, 7) (7 / 1)
							for (x = x954, xp_1 = x954_p_0, xp_0 = 0;
								x < x954 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7612 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7613 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7614 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_7615 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_7616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_7619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_7620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_7623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_7624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_7627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_7628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_7631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c954, cp_1 = c954_p_0, cp_0 = 0;
											c < c954 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7612);
											mem_vec_7612 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7613);
											mem_vec_7613 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7614);
											mem_vec_7614 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7615);
											mem_vec_7615 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7616);
											mem_vec_7616 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7617);
											mem_vec_7617 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7618);
											mem_vec_7618 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7619);
											mem_vec_7619 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7620);
											mem_vec_7620 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7621);
											mem_vec_7621 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7622);
											mem_vec_7622 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7623);
											mem_vec_7623 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7624);
											mem_vec_7624 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7625);
											mem_vec_7625 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7626);
											mem_vec_7626 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7627);
											mem_vec_7627 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7628);
											mem_vec_7628 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7629);
											mem_vec_7629 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7630);
											mem_vec_7630 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7631);
											mem_vec_7631 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_7612);
											mem_vec_7612 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_7613);
											mem_vec_7613 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_7614);
											mem_vec_7614 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_7615);
											mem_vec_7615 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_7616);
											mem_vec_7616 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_7617);
											mem_vec_7617 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_7618);
											mem_vec_7618 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_7619);
											mem_vec_7619 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_7620);
											mem_vec_7620 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_7621);
											mem_vec_7621 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_7622);
											mem_vec_7622 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_7623);
											mem_vec_7623 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_7624);
											mem_vec_7624 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_7625);
											mem_vec_7625 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_7626);
											mem_vec_7626 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_7627);
											mem_vec_7627 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_7628);
											mem_vec_7628 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_7629);
											mem_vec_7629 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_7630);
											mem_vec_7630 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_7631);
											mem_vec_7631 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_7612);
											mem_vec_7612 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_7613);
											mem_vec_7613 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_7614);
											mem_vec_7614 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_7615);
											mem_vec_7615 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_7616);
											mem_vec_7616 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_7617);
											mem_vec_7617 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_7618);
											mem_vec_7618 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_7619);
											mem_vec_7619 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_7620);
											mem_vec_7620 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_7621);
											mem_vec_7621 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_7622);
											mem_vec_7622 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_7623);
											mem_vec_7623 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_7624);
											mem_vec_7624 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_7625);
											mem_vec_7625 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_7626);
											mem_vec_7626 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_7627);
											mem_vec_7627 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_7628);
											mem_vec_7628 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_7629);
											mem_vec_7629 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_7630);
											mem_vec_7630 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_7631);
											mem_vec_7631 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7612);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7613);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7614);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7615);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7616);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7617);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7618);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7619);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7620);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7621);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7622);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7623);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7624);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7625);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7626);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7627);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7628);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7629);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7630);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7631);
							}
						}
					}
				}
			}
		}
}


}