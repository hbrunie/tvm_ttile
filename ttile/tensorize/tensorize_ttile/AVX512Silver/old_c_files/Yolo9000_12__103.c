#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (8, c); T (1, y); T (16, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]]
*/
IND_TYPE c, cp_0, c541_p_0, cp_1, c541, f, fp_0, h, hp_0, x, xp_0, x540_p_0, xp_1, x540, y, yp_0, y408_p_0, yp_1, y408;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y409 = 0;
IND_TYPE x541 = 0;
IND_TYPE h324 = 0;
IND_TYPE w = 0;
IND_TYPE c542 = 0;
IND_TYPE f600 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6666 ,mem_vec_6667 ,mem_vec_6668 ,mem_vec_6669 ,mem_vec_6670 ,mem_vec_6671 ,mem_vec_6672 ,mem_vec_6673 ,mem_vec_6674 ,mem_vec_6675 ,mem_vec_6676 ,mem_vec_6677 ,mem_vec_6678 ,mem_vec_6679 ,mem_vec_6680 ,mem_vec_6681 ,mem_vec_6682 ,mem_vec_6683 ,mem_vec_6684 ,mem_vec_6685 ,mem_vec_6686 ,mem_vec_6687 ,mem_vec_6688 ,mem_vec_6689 ,mem_vec_6690 ,mem_vec_6691 ,mem_vec_6692 ,mem_vec_6693 ,mem_vec_6694 ,mem_vec_6695 ,mem_vec_6696 ,mem_vec_6697 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
	for (y408 = y409, y408_p_0 = 0;
		y408 < y409 + 7;
		y408 += 7, y408_p_0 += 7){
		// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (x, 1) (34 / 34)
		for (x540 = x541, x540_p_0 = 0;
			x540 < x541 + 34;
			x540 += 34, x540_p_0 += 34){
			// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (f, 16) (512 / 32)
			for (f = f600, fp_0 = 0;
				f < f600 + 512;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y408, yp_1 = y408_p_0, yp_0 = 0;
					y < y408 + 7;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c541 = c542, c541_p_0 = 0;
						c541 < c542 + 256;
						c541 += 32, c541_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h324, hp_0 = 0;
							h < h324 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 32, f = 32
							// T (x, 34) (34 / 1)
							for (x = x540, xp_1 = x540_p_0, xp_0 = 0;
								x < x540 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6666 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6667 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c541, cp_1 = c541_p_0, cp_0 = 0;
											c < c541 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6666);
											mem_vec_6666 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6667);
											mem_vec_6667 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6668);
											mem_vec_6668 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6669);
											mem_vec_6669 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6670);
											mem_vec_6670 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6671);
											mem_vec_6671 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6672);
											mem_vec_6672 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6673);
											mem_vec_6673 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6674);
											mem_vec_6674 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6675);
											mem_vec_6675 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6676);
											mem_vec_6676 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6677);
											mem_vec_6677 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6678);
											mem_vec_6678 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6679);
											mem_vec_6679 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);
											vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_23 = _mm512_fmadd_ps(vec_24, vec_25, mem_vec_6666);
											mem_vec_6666 = vec_23;

											vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_26 = _mm512_fmadd_ps(vec_24, vec_27, mem_vec_6667);
											mem_vec_6667 = vec_26;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_29 = _mm512_set1_ps(scal_8);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_6668);
											mem_vec_6668 = vec_28;



											vec_30 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_6669);
											mem_vec_6669 = vec_30;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_32 = _mm512_set1_ps(scal_9);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_25, mem_vec_6670);
											mem_vec_6670 = vec_31;



											vec_33 = _mm512_fmadd_ps(vec_32, vec_27, mem_vec_6671);
											mem_vec_6671 = vec_33;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_25, mem_vec_6672);
											mem_vec_6672 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_27, mem_vec_6673);
											mem_vec_6673 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_25, mem_vec_6674);
											mem_vec_6674 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_27, mem_vec_6675);
											mem_vec_6675 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_25, mem_vec_6676);
											mem_vec_6676 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_27, mem_vec_6677);
											mem_vec_6677 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_25, mem_vec_6678);
											mem_vec_6678 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_27, mem_vec_6679);
											mem_vec_6679 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);
											vec_48 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_46 = _mm512_fmadd_ps(vec_47, vec_48, mem_vec_6666);
											mem_vec_6666 = vec_46;

											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_49 = _mm512_fmadd_ps(vec_47, vec_50, mem_vec_6667);
											mem_vec_6667 = vec_49;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_52 = _mm512_set1_ps(scal_15);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_48, mem_vec_6668);
											mem_vec_6668 = vec_51;



											vec_53 = _mm512_fmadd_ps(vec_52, vec_50, mem_vec_6669);
											mem_vec_6669 = vec_53;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_55 = _mm512_set1_ps(scal_16);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_48, mem_vec_6670);
											mem_vec_6670 = vec_54;



											vec_56 = _mm512_fmadd_ps(vec_55, vec_50, mem_vec_6671);
											mem_vec_6671 = vec_56;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_58 = _mm512_set1_ps(scal_17);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_48, mem_vec_6672);
											mem_vec_6672 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_6673);
											mem_vec_6673 = vec_59;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_61 = _mm512_set1_ps(scal_18);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_48, mem_vec_6674);
											mem_vec_6674 = vec_60;



											vec_62 = _mm512_fmadd_ps(vec_61, vec_50, mem_vec_6675);
											mem_vec_6675 = vec_62;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_48, mem_vec_6676);
											mem_vec_6676 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_50, mem_vec_6677);
											mem_vec_6677 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_48, mem_vec_6678);
											mem_vec_6678 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_50, mem_vec_6679);
											mem_vec_6679 = vec_68;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6669);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6670);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6671);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6672);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6673);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6674);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6675);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6676);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6677);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6678);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6679);
							}
						}
					}
				}
			}
		}
	}
	for (y408 = y409 + 7, y408_p_0 = 0;
		y408 < y409 + 7 + 27;
		y408 += 9, y408_p_0 += 9){
		// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (x, 1) (34 / 34)
		for (x540 = x541, x540_p_0 = 0;
			x540 < x541 + 34;
			x540 += 34, x540_p_0 += 34){
			// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 512
			// T (f, 16) (512 / 32)
			for (f = f600, fp_0 = 0;
				f < f600 + 512;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y408, yp_1 = y408_p_0, yp_0 = 0;
					y < y408 + 9;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c541 = c542, c541_p_0 = 0;
						c541 < c542 + 256;
						c541 += 32, c541_p_0 += 32){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h324, hp_0 = 0;
							h < h324 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 34, h = 1, w = 3, c = 32, f = 32
							// T (x, 34) (34 / 1)
							for (x = x540, xp_1 = x540_p_0, xp_0 = 0;
								x < x540 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6680 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6681 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_6693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_6694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_6695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_6696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_6697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c541, cp_1 = c541_p_0, cp_0 = 0;
											c < c541 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6680);
											mem_vec_6680 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6681);
											mem_vec_6681 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6682);
											mem_vec_6682 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6683);
											mem_vec_6683 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6684);
											mem_vec_6684 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6685);
											mem_vec_6685 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6686);
											mem_vec_6686 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6687);
											mem_vec_6687 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6688);
											mem_vec_6688 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6689);
											mem_vec_6689 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6690);
											mem_vec_6690 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6691);
											mem_vec_6691 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6692);
											mem_vec_6692 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6693);
											mem_vec_6693 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6694);
											mem_vec_6694 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6695);
											mem_vec_6695 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6696);
											mem_vec_6696 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6697);
											mem_vec_6697 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6680);
											mem_vec_6680 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_6681);
											mem_vec_6681 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_6682);
											mem_vec_6682 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_6683);
											mem_vec_6683 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_6684);
											mem_vec_6684 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_6685);
											mem_vec_6685 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_6686);
											mem_vec_6686 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_6687);
											mem_vec_6687 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_6688);
											mem_vec_6688 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_6689);
											mem_vec_6689 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_6690);
											mem_vec_6690 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_6691);
											mem_vec_6691 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_6692);
											mem_vec_6692 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_6693);
											mem_vec_6693 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_6694);
											mem_vec_6694 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_6695);
											mem_vec_6695 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 8 + h) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_6696);
											mem_vec_6696 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_6697);
											mem_vec_6697 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6680);
											mem_vec_6680 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_6681);
											mem_vec_6681 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_6682);
											mem_vec_6682 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_6683);
											mem_vec_6683 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_6684);
											mem_vec_6684 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_6685);
											mem_vec_6685 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_6686);
											mem_vec_6686 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_6687);
											mem_vec_6687 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_6688);
											mem_vec_6688 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_6689);
											mem_vec_6689 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_6690);
											mem_vec_6690 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_6691);
											mem_vec_6691 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_6692);
											mem_vec_6692 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_6693);
											mem_vec_6693 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_6694);
											mem_vec_6694 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_6695);
											mem_vec_6695 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 8 + h) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_6696);
											mem_vec_6696 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_6697);
											mem_vec_6697 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6680);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6681);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6682);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6683);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6684);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6685);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6686);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6687);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6688);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6689);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6690);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6691);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6692);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6693);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6694);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6695);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6696);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6697);
							}
						}
					}
				}
			}
		}
	}


}