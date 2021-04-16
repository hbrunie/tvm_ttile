#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (56, x);
  T (3, h); T (4, c); T (2, f); T (1, x); T (1, y);
  Lambda_apply y [((Iter 7), (Arg 6)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c579_p_0, cp_1, c579, f, fp_0, h, hp_0, x, xp_0, x663_p_0, xp_1, x663, y, yp_0, y489_p_0, yp_1, y489;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y490 = 0;
IND_TYPE x664 = 0;
IND_TYPE h288 = 0;
IND_TYPE w = 0;
IND_TYPE c580 = 0;
IND_TYPE f363 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4647 ,mem_vec_4648 ,mem_vec_4649 ,mem_vec_4650 ,mem_vec_4651 ,mem_vec_4652 ,mem_vec_4653 ,mem_vec_4654 ,mem_vec_4655 ,mem_vec_4656 ,mem_vec_4657 ,mem_vec_4658 ,mem_vec_4659 ,mem_vec_4660 ,mem_vec_4661 ,mem_vec_4662 ,mem_vec_4663 ,mem_vec_4664 ,mem_vec_4665 ,mem_vec_4666 ,mem_vec_4667 ,mem_vec_4668 ,mem_vec_4669 ,mem_vec_4670 ,mem_vec_4671 ,mem_vec_4672 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_7 ,vec_8 ,vec_9;
	for (y489 = y490, y489_p_0 = 0;
		y489 < y490 + 42;
		y489 += 6, y489_p_0 += 6){
		// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (y, 1) (ph_y / ph_y)
		for (y = y489, yp_1 = y489_p_0, yp_0 = 0;
			y < y489 + 6;
			y += 6, yp_1 += 6, yp_0 += 6){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (56 / 56)
			for (x663 = x664, x663_p_0 = 0;
				x663 < x664 + 56;
				x663 += 56, x663_p_0 += 56){
				// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f363, fp_0 = 0;
					f < f363 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c579 = c580, c579_p_0 = 0;
						c579 < c580 + 64;
						c579 += 16, c579_p_0 += 16){
						// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h288, hp_0 = 0;
							h < h288 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 3, c = 16, f = 32
							// T (x, 56) (56 / 1)
							for (x = x663, xp_1 = x663_p_0, xp_0 = 0;
								x < x663 + 56;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4647 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4648 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c579, cp_1 = c579_p_0, cp_0 = 0;
											c < c579 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4647);
											mem_vec_4647 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4648);
											mem_vec_4648 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4649);
											mem_vec_4649 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4650);
											mem_vec_4650 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4651);
											mem_vec_4651 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4652);
											mem_vec_4652 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4653);
											mem_vec_4653 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4654);
											mem_vec_4654 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4655);
											mem_vec_4655 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4656);
											mem_vec_4656 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4657);
											mem_vec_4657 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4658);
											mem_vec_4658 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);
											vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_4647);
											mem_vec_4647 = vec_20;

											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_4648);
											mem_vec_4648 = vec_23;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_26 = _mm512_set1_ps(scal_7);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_4649);
											mem_vec_4649 = vec_25;



											vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_4650);
											mem_vec_4650 = vec_27;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_4651);
											mem_vec_4651 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_4652);
											mem_vec_4652 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_4653);
											mem_vec_4653 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_4654);
											mem_vec_4654 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_4655);
											mem_vec_4655 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_4656);
											mem_vec_4656 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_4657);
											mem_vec_4657 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_4658);
											mem_vec_4658 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);
											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_4647);
											mem_vec_4647 = vec_40;

											vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_4648);
											mem_vec_4648 = vec_43;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_46 = _mm512_set1_ps(scal_13);


											vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_4649);
											mem_vec_4649 = vec_45;



											vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_4650);
											mem_vec_4650 = vec_47;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_14);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_4651);
											mem_vec_4651 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_4652);
											mem_vec_4652 = vec_50;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_4653);
											mem_vec_4653 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_4654);
											mem_vec_4654 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_4655);
											mem_vec_4655 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_4656);
											mem_vec_4656 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_4657);
											mem_vec_4657 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_4658);
											mem_vec_4658 = vec_59;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4651);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4656);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4657);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4658);
							}
						}
					}
				}
			}
		}
	}
	for (y489 = y490 + 42, y489_p_0 = 0;
		y489 < y490 + 42 + 14;
		y489 += 7, y489_p_0 += 7){
		// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (y, 1) (ph_y / ph_y)
		for (y = y489, yp_1 = y489_p_0, yp_0 = 0;
			y < y489 + 7;
			y += 7, yp_1 += 7, yp_0 += 7){
			// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (56 / 56)
			for (x663 = x664, x663_p_0 = 0;
				x663 < x664 + 56;
				x663 += 56, x663_p_0 += 56){
				// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f363, fp_0 = 0;
					f < f363 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 56, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c579 = c580, c579_p_0 = 0;
						c579 < c580 + 64;
						c579 += 16, c579_p_0 += 16){
						// y = ph_y, x = 56, h = 3, w = 3, c = 16, f = 32
						// T (h, 3) (3 / 1)
						for (h = h288, hp_0 = 0;
							h < h288 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 56, h = 1, w = 3, c = 16, f = 32
							// T (x, 56) (56 / 1)
							for (x = x663, xp_1 = x663_p_0, xp_0 = 0;
								x < x663 + 56;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4659 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4660 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c579, cp_1 = c579_p_0, cp_0 = 0;
											c < c579 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4659);
											mem_vec_4659 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4660);
											mem_vec_4660 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4661);
											mem_vec_4661 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4662);
											mem_vec_4662 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4663);
											mem_vec_4663 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4664);
											mem_vec_4664 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4665);
											mem_vec_4665 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4666);
											mem_vec_4666 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4667);
											mem_vec_4667 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4668);
											mem_vec_4668 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4669);
											mem_vec_4669 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4670);
											mem_vec_4670 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4671);
											mem_vec_4671 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4672);
											mem_vec_4672 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_4659);
											mem_vec_4659 = vec_23;

											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_4660);
											mem_vec_4660 = vec_26;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_4661);
											mem_vec_4661 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4662);
											mem_vec_4662 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_4663);
											mem_vec_4663 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_4664);
											mem_vec_4664 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_4665);
											mem_vec_4665 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_4666);
											mem_vec_4666 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_4667);
											mem_vec_4667 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_4668);
											mem_vec_4668 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_4669);
											mem_vec_4669 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_4670);
											mem_vec_4670 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_4671);
											mem_vec_4671 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_4672);
											mem_vec_4672 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_4659);
											mem_vec_4659 = vec_46;

											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_4660);
											mem_vec_4660 = vec_49;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_4661);
											mem_vec_4661 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_4662);
											mem_vec_4662 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_4663);
											mem_vec_4663 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_4664);
											mem_vec_4664 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_4665);
											mem_vec_4665 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_4666);
											mem_vec_4666 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_4667);
											mem_vec_4667 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_4668);
											mem_vec_4668 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_4669);
											mem_vec_4669 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_4670);
											mem_vec_4670 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_4671);
											mem_vec_4671 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_4672);
											mem_vec_4672 = vec_68;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4659);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4660);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4661);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4662);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4663);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4664);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4665);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4669);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4670);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4671);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4672);
							}
						}
					}
				}
			}
		}
	}


}