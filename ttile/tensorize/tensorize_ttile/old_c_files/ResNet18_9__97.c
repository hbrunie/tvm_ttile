#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, f); T (128, c); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (1, f)]
*/
IND_TYPE c, cp_0, c1014_p_0, cp_1, c1014, f, fp_0, f1014_p_0, fp_1, f1014, h, hp_0, x, xp_0, x1014_p_0, xp_1, x1014, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y676 = 0;
IND_TYPE x1015 = 0;
IND_TYPE h538 = 0;
IND_TYPE w = 0;
IND_TYPE c1015 = 0;
IND_TYPE f1015 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8536 ,mem_vec_8537 ,mem_vec_8538 ,mem_vec_8539 ,mem_vec_8540 ,mem_vec_8541 ,mem_vec_8542 ,mem_vec_8543 ,mem_vec_8544 ,mem_vec_8545 ,mem_vec_8546 ,mem_vec_8547 ,mem_vec_8548 ,mem_vec_8549 ,mem_vec_8550 ,mem_vec_8551 ,mem_vec_8552 ,mem_vec_8553 ,mem_vec_8554 ,mem_vec_8555 ,mem_vec_8556 ,mem_vec_8557 ,mem_vec_8558 ,mem_vec_8559 ,mem_vec_8560 ,mem_vec_8561 ,mem_vec_8562 ,mem_vec_8563 ,mem_vec_8564 ,mem_vec_8565 ,mem_vec_8566 ,mem_vec_8567 ,mem_vec_8568 ,mem_vec_8569 ,mem_vec_8570 ,mem_vec_8571 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1014 = f1015, f1014_p_0 = 0;
	f1014 < f1015 + 256;
	f1014 += 256, f1014_p_0 += 256){
		for (y = y676, yp_0 = 0;
			y < y676 + 4;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 256
			// T (x, 14) (14 / 1)
			for (x1014 = x1015, x1014_p_0 = 0;
				x1014 < x1015 + 14;
				x1014 += 1, x1014_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 256
				// T (c, 128) (256 / 2)
				for (c1014 = c1015, c1014_p_0 = 0;
					c1014 < c1015 + 256;
					c1014 += 2, c1014_p_0 += 2){
					// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 256
					// T (f, 4) (256 / 64)
					for (f = f1014, fp_1 = f1014_p_0, fp_0 = 0;
						f < f1014 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h538, hp_0 = 0;
							h < h538 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
							// T (x, 1) (1 / 1)
							for (x = x1014, xp_1 = x1014_p_0, xp_0 = 0;
								x < x1014 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8536 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8537 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8538 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8539 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1014, cp_1 = c1014_p_0, cp_0 = 0;
											c < c1014 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8536);
											mem_vec_8536 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8537);
											mem_vec_8537 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8538);
											mem_vec_8538 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8539);
											mem_vec_8539 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8540);
											mem_vec_8540 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8541);
											mem_vec_8541 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8542);
											mem_vec_8542 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8543);
											mem_vec_8543 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8544);
											mem_vec_8544 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8545);
											mem_vec_8545 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8546);
											mem_vec_8546 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8547);
											mem_vec_8547 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8548);
											mem_vec_8548 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8549);
											mem_vec_8549 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8550);
											mem_vec_8550 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8551);
											mem_vec_8551 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_8536);
											mem_vec_8536 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_8537);
											mem_vec_8537 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_8538);
											mem_vec_8538 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_8539);
											mem_vec_8539 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_8540);
											mem_vec_8540 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_8541);
											mem_vec_8541 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_8542);
											mem_vec_8542 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_8543);
											mem_vec_8543 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_8544);
											mem_vec_8544 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_8545);
											mem_vec_8545 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_8546);
											mem_vec_8546 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_8547);
											mem_vec_8547 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_8548);
											mem_vec_8548 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_8549);
											mem_vec_8549 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_8550);
											mem_vec_8550 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_8551);
											mem_vec_8551 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_8536);
											mem_vec_8536 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_8537);
											mem_vec_8537 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_8538);
											mem_vec_8538 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_8539);
											mem_vec_8539 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_8540);
											mem_vec_8540 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_8541);
											mem_vec_8541 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_8542);
											mem_vec_8542 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_8543);
											mem_vec_8543 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_8544);
											mem_vec_8544 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_8545);
											mem_vec_8545 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_8546);
											mem_vec_8546 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_8547);
											mem_vec_8547 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_8548);
											mem_vec_8548 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_8549);
											mem_vec_8549 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_8550);
											mem_vec_8550 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_8551);
											mem_vec_8551 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8536);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8537);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8538);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8539);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8540);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8541);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8542);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8543);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8544);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8545);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8546);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8547);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8548);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8549);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8550);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8551);
							}
						}
					}
				}
			}
		}
		for (y = y676 + 4, yp_0 = 0;
			y < y676 + 4 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 256
			// T (x, 14) (14 / 1)
			for (x1014 = x1015, x1014_p_0 = 0;
				x1014 < x1015 + 14;
				x1014 += 1, x1014_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 256
				// T (c, 128) (256 / 2)
				for (c1014 = c1015, c1014_p_0 = 0;
					c1014 < c1015 + 256;
					c1014 += 2, c1014_p_0 += 2){
					// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 256
					// T (f, 4) (256 / 64)
					for (f = f1014, fp_1 = f1014_p_0, fp_0 = 0;
						f < f1014 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 64
						// T (h, 3) (3 / 1)
						for (h = h538, hp_0 = 0;
							h < h538 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
							// T (x, 1) (1 / 1)
							for (x = x1014, xp_1 = x1014_p_0, xp_0 = 0;
								x < x1014 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8552 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8554 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8555 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_8568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_8571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 64
										// T (c, 2) (2 / 1)
										for (c = c1014, cp_1 = c1014_p_0, cp_0 = 0;
											c < c1014 + 2;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8552);
											mem_vec_8552 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8553);
											mem_vec_8553 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8554);
											mem_vec_8554 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8555);
											mem_vec_8555 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8556);
											mem_vec_8556 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8557);
											mem_vec_8557 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8558);
											mem_vec_8558 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8559);
											mem_vec_8559 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8560);
											mem_vec_8560 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8561);
											mem_vec_8561 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8562);
											mem_vec_8562 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8563);
											mem_vec_8563 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8564);
											mem_vec_8564 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8565);
											mem_vec_8565 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8566);
											mem_vec_8566 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8567);
											mem_vec_8567 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_8568);
											mem_vec_8568 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_8569);
											mem_vec_8569 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_8570);
											mem_vec_8570 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_8571);
											mem_vec_8571 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_8552);
											mem_vec_8552 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_8553);
											mem_vec_8553 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_8554);
											mem_vec_8554 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_8555);
											mem_vec_8555 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_8556);
											mem_vec_8556 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_8557);
											mem_vec_8557 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_8558);
											mem_vec_8558 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_8559);
											mem_vec_8559 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_8560);
											mem_vec_8560 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_8561);
											mem_vec_8561 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_8562);
											mem_vec_8562 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_8563);
											mem_vec_8563 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_8564);
											mem_vec_8564 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_8565);
											mem_vec_8565 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_8566);
											mem_vec_8566 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_8567);
											mem_vec_8567 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_8568);
											mem_vec_8568 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_8569);
											mem_vec_8569 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_8570);
											mem_vec_8570 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_8571);
											mem_vec_8571 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_8552);
											mem_vec_8552 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_8553);
											mem_vec_8553 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_8554);
											mem_vec_8554 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_8555);
											mem_vec_8555 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_8556);
											mem_vec_8556 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_8557);
											mem_vec_8557 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_8558);
											mem_vec_8558 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_8559);
											mem_vec_8559 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_8560);
											mem_vec_8560 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_8561);
											mem_vec_8561 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_8562);
											mem_vec_8562 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_8563);
											mem_vec_8563 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_8564);
											mem_vec_8564 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_8565);
											mem_vec_8565 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_8566);
											mem_vec_8566 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_8567);
											mem_vec_8567 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_8568);
											mem_vec_8568 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_8569);
											mem_vec_8569 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_8570);
											mem_vec_8570 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_8571);
											mem_vec_8571 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8552);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8553);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8554);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8555);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8556);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8557);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8558);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8559);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8560);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8561);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8562);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8563);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8564);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8565);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8566);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8567);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8568);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8569);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8570);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_8571);
							}
						}
					}
				}
			}
		}
}


}