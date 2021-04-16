#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (28, x);
  T (2, c); T (3, w); T (4, x);
  Lambda_apply y [((Iter 5), (Arg 12)); ((Iter 4), (Arg 13))]; T (2, f);
  T (1, y)]
*/
IND_TYPE c, cp_0, c459_p_0, cp_1, c459, f, fp_0, w, wp_0, x, xp_0, x403_p_0, xp_1, x403, y, yp_0, y459_p_0, yp_1, y459;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y460 = 0;
IND_TYPE x404 = 0;
IND_TYPE h = 0;
IND_TYPE w306 = 0;
IND_TYPE c460 = 0;
IND_TYPE f250 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3645 ,mem_vec_3646 ,mem_vec_3647 ,mem_vec_3648 ,mem_vec_3649 ,mem_vec_3650 ,mem_vec_3651 ,mem_vec_3652 ,mem_vec_3653 ,mem_vec_3654 ,mem_vec_3655 ,mem_vec_3656 ,mem_vec_3657 ,mem_vec_3658 ,mem_vec_3659 ,mem_vec_3660 ,mem_vec_3661 ,mem_vec_3662 ,mem_vec_3663 ,mem_vec_3664 ,mem_vec_3665 ,mem_vec_3666 ,mem_vec_3667 ,mem_vec_3668 ,mem_vec_3669 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (y, 1) (112 / 112)
for (y459 = y460, y459_p_0 = 0;
	y459 < y460 + 112;
	y459 += 112, y459_p_0 += 112){
	// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (f, 2) (32 / 16)
	for (f = f250, fp_0 = 0;
		f < f250 + 32;
		f += 16, fp_0 += 16){
			for (y = y459, yp_1 = y459_p_0, yp_0 = 0;
				y < y459 + 60;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 16
				// T (x, 4) (112 / 28)
				for (x403 = x404, x403_p_0 = 0;
					x403 < x404 + 112;
					x403 += 28, x403_p_0 += 28){
					// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 16
					// T (w, 3) (3 / 1)
					for (w = w306, wp_0 = 0;
						w < w306 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 28, h = 3, w = 1, c = 32, f = 16
						// T (c, 2) (32 / 16)
						for (c459 = c460, c459_p_0 = 0;
							c459 < c460 + 32;
							c459 += 16, c459_p_0 += 16){
							// y = ph_y, x = 28, h = 3, w = 1, c = 16, f = 16
							// T (x, 28) (28 / 1)
							for (x = x403, xp_1 = x403_p_0, xp_0 = 0;
								x < x403 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3645 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c459, cp_1 = c459_p_0, cp_0 = 0;
											c < c459 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3645);
											mem_vec_3645 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3646);
											mem_vec_3646 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3647);
											mem_vec_3647 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3648);
											mem_vec_3648 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3649);
											mem_vec_3649 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3650);
											mem_vec_3650 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_3651);
											mem_vec_3651 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_3652);
											mem_vec_3652 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3653);
											mem_vec_3653 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3654);
											mem_vec_3654 = vec_19;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_3655);
											mem_vec_3655 = vec_21;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3656);
											mem_vec_3656 = vec_23;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_26 = _mm512_set1_ps(scal_12);
											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_25 = _mm512_fmadd_ps(vec_26, vec_27, mem_vec_3645);
											mem_vec_3645 = vec_25;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_3646);
											mem_vec_3646 = vec_28;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_27, mem_vec_3647);
											mem_vec_3647 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_27, mem_vec_3648);
											mem_vec_3648 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_3649);
											mem_vec_3649 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_27, mem_vec_3650);
											mem_vec_3650 = vec_36;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_27, mem_vec_3651);
											mem_vec_3651 = vec_38;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_3652);
											mem_vec_3652 = vec_40;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_27, mem_vec_3653);
											mem_vec_3653 = vec_42;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_27, mem_vec_3654);
											mem_vec_3654 = vec_44;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_27, mem_vec_3655);
											mem_vec_3655 = vec_46;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_27, mem_vec_3656);
											mem_vec_3656 = vec_48;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_51 = _mm512_set1_ps(scal_24);
											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_50 = _mm512_fmadd_ps(vec_51, vec_52, mem_vec_3645);
											mem_vec_3645 = vec_50;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_54 = _mm512_set1_ps(scal_25);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_52, mem_vec_3646);
											mem_vec_3646 = vec_53;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_26);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_52, mem_vec_3647);
											mem_vec_3647 = vec_55;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_3648);
											mem_vec_3648 = vec_57;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_52, mem_vec_3649);
											mem_vec_3649 = vec_59;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_52, mem_vec_3650);
											mem_vec_3650 = vec_61;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_52, mem_vec_3651);
											mem_vec_3651 = vec_63;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_52, mem_vec_3652);
											mem_vec_3652 = vec_65;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_3653);
											mem_vec_3653 = vec_67;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_52, mem_vec_3654);
											mem_vec_3654 = vec_69;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_52, mem_vec_3655);
											mem_vec_3655 = vec_71;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_52, mem_vec_3656);
											mem_vec_3656 = vec_73;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3645);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3651);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3656);
							}
						}
					}
				}
			}
			for (y = y459 + 60, yp_1 = y459_p_0, yp_0 = 0;
				y < y459 + 60 + 52;
				y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 16
				// T (x, 4) (112 / 28)
				for (x403 = x404, x403_p_0 = 0;
					x403 < x404 + 112;
					x403 += 28, x403_p_0 += 28){
					// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 16
					// T (w, 3) (3 / 1)
					for (w = w306, wp_0 = 0;
						w < w306 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 28, h = 3, w = 1, c = 32, f = 16
						// T (c, 2) (32 / 16)
						for (c459 = c460, c459_p_0 = 0;
							c459 < c460 + 32;
							c459 += 16, c459_p_0 += 16){
							// y = ph_y, x = 28, h = 3, w = 1, c = 16, f = 16
							// T (x, 28) (28 / 1)
							for (x = x403, xp_1 = x403_p_0, xp_0 = 0;
								x < x403 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_3657 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
										// T (c, 16) (16 / 1)
										for (c = c459, cp_1 = c459_p_0, cp_0 = 0;
											c < c459 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3657);
											mem_vec_3657 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_3658);
											mem_vec_3658 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3659);
											mem_vec_3659 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_3660);
											mem_vec_3660 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3661);
											mem_vec_3661 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3662);
											mem_vec_3662 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_3663);
											mem_vec_3663 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_16 = _mm512_set1_ps(scal_7);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_3664);
											mem_vec_3664 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_18 = _mm512_set1_ps(scal_8);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3665);
											mem_vec_3665 = vec_17;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_20 = _mm512_set1_ps(scal_9);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3666);
											mem_vec_3666 = vec_19;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_22 = _mm512_set1_ps(scal_10);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_3667);
											mem_vec_3667 = vec_21;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_24 = _mm512_set1_ps(scal_11);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3668);
											mem_vec_3668 = vec_23;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_26 = _mm512_set1_ps(scal_12);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_2, mem_vec_3669);
											mem_vec_3669 = vec_25;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_28 = _mm512_set1_ps(scal_13);
											vec_29 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_27 = _mm512_fmadd_ps(vec_28, vec_29, mem_vec_3657);
											mem_vec_3657 = vec_27;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_31 = _mm512_set1_ps(scal_14);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_29, mem_vec_3658);
											mem_vec_3658 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_15);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_29, mem_vec_3659);
											mem_vec_3659 = vec_32;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_16);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_29, mem_vec_3660);
											mem_vec_3660 = vec_34;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_17);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_29, mem_vec_3661);
											mem_vec_3661 = vec_36;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_39 = _mm512_set1_ps(scal_18);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_29, mem_vec_3662);
											mem_vec_3662 = vec_38;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_19);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_29, mem_vec_3663);
											mem_vec_3663 = vec_40;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_43 = _mm512_set1_ps(scal_20);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_29, mem_vec_3664);
											mem_vec_3664 = vec_42;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_21);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_29, mem_vec_3665);
											mem_vec_3665 = vec_44;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_22);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_29, mem_vec_3666);
											mem_vec_3666 = vec_46;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_49 = _mm512_set1_ps(scal_23);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_29, mem_vec_3667);
											mem_vec_3667 = vec_48;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
											vec_51 = _mm512_set1_ps(scal_24);


											vec_50 = _mm512_fmadd_ps(vec_51, vec_29, mem_vec_3668);
											mem_vec_3668 = vec_50;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_25);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_29, mem_vec_3669);
											mem_vec_3669 = vec_52;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_55 = _mm512_set1_ps(scal_26);
											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_54 = _mm512_fmadd_ps(vec_55, vec_56, mem_vec_3657);
											mem_vec_3657 = vec_54;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_58 = _mm512_set1_ps(scal_27);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_3658);
											mem_vec_3658 = vec_57;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_60 = _mm512_set1_ps(scal_28);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_56, mem_vec_3659);
											mem_vec_3659 = vec_59;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_62 = _mm512_set1_ps(scal_29);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_56, mem_vec_3660);
											mem_vec_3660 = vec_61;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_30);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_3661);
											mem_vec_3661 = vec_63;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_31);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_56, mem_vec_3662);
											mem_vec_3662 = vec_65;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_68 = _mm512_set1_ps(scal_32);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_3663);
											mem_vec_3663 = vec_67;
											scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_33);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_3664);
											mem_vec_3664 = vec_69;
											scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_72 = _mm512_set1_ps(scal_34);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_56, mem_vec_3665);
											mem_vec_3665 = vec_71;
											scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_74 = _mm512_set1_ps(scal_35);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_56, mem_vec_3666);
											mem_vec_3666 = vec_73;
											scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_36);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_3667);
											mem_vec_3667 = vec_75;
											scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_37);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_56, mem_vec_3668);
											mem_vec_3668 = vec_77;
											scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
											vec_80 = _mm512_set1_ps(scal_38);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_56, mem_vec_3669);
											mem_vec_3669 = vec_79;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3657);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3658);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3659);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3660);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3661);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3662);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3663);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3664);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3665);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3669);
							}
						}
					}
				}
			}
	}
}


}