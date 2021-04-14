#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (2, f); T (64, c); T (14, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))]; T (2, f)]
*/
IND_TYPE c, cp_0, c1008_p_0, cp_1, c1008, f, fp_0, f1008_p_0, fp_1, f1008, h, hp_0, x, xp_0, x1008_p_0, xp_1, x1008, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y672 = 0;
IND_TYPE x1009 = 0;
IND_TYPE h534 = 0;
IND_TYPE w = 0;
IND_TYPE c1009 = 0;
IND_TYPE f1009 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8464 ,mem_vec_8465 ,mem_vec_8466 ,mem_vec_8467 ,mem_vec_8468 ,mem_vec_8469 ,mem_vec_8470 ,mem_vec_8471 ,mem_vec_8472 ,mem_vec_8473 ,mem_vec_8474 ,mem_vec_8475 ,mem_vec_8476 ,mem_vec_8477 ,mem_vec_8478 ,mem_vec_8479 ,mem_vec_8480 ,mem_vec_8481 ,mem_vec_8482 ,mem_vec_8483 ,mem_vec_8484 ,mem_vec_8485 ,mem_vec_8486 ,mem_vec_8487 ,mem_vec_8488 ,mem_vec_8489 ,mem_vec_8490 ,mem_vec_8491 ,mem_vec_8492 ,mem_vec_8493 ,mem_vec_8494 ,mem_vec_8495 ,mem_vec_8496 ,mem_vec_8497 ,mem_vec_8498 ,mem_vec_8499 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f1008 = f1009, f1008_p_0 = 0;
	f1008 < f1009 + 256;
	f1008 += 128, f1008_p_0 += 128){
		for (y = y672, yp_0 = 0;
			y < y672 + 4;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
			// T (x, 14) (14 / 1)
			for (x1008 = x1009, x1008_p_0 = 0;
				x1008 < x1009 + 14;
				x1008 += 1, x1008_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 128
				// T (c, 64) (256 / 4)
				for (c1008 = c1009, c1008_p_0 = 0;
					c1008 < c1009 + 256;
					c1008 += 4, c1008_p_0 += 4){
					// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 128
					// T (f, 2) (128 / 64)
					for (f = f1008, fp_1 = f1008_p_0, fp_0 = 0;
						f < f1008 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (h, 3) (3 / 1)
						for (h = h534, hp_0 = 0;
							h < h534 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
							// T (x, 1) (1 / 1)
							for (x = x1008, xp_1 = x1008_p_0, xp_0 = 0;
								x < x1008 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8464 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8465 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8466 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8467 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1008, cp_1 = c1008_p_0, cp_0 = 0;
											c < c1008 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8464);
											mem_vec_8464 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8465);
											mem_vec_8465 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8466);
											mem_vec_8466 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8467);
											mem_vec_8467 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8468);
											mem_vec_8468 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8469);
											mem_vec_8469 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8470);
											mem_vec_8470 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8471);
											mem_vec_8471 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8472);
											mem_vec_8472 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8473);
											mem_vec_8473 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8474);
											mem_vec_8474 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8475);
											mem_vec_8475 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8476);
											mem_vec_8476 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8477);
											mem_vec_8477 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8478);
											mem_vec_8478 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8479);
											mem_vec_8479 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_8464);
											mem_vec_8464 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_8465);
											mem_vec_8465 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_8466);
											mem_vec_8466 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_8467);
											mem_vec_8467 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_8468);
											mem_vec_8468 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_8469);
											mem_vec_8469 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_8470);
											mem_vec_8470 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_8471);
											mem_vec_8471 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_8472);
											mem_vec_8472 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_8473);
											mem_vec_8473 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_8474);
											mem_vec_8474 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_8475);
											mem_vec_8475 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_8476);
											mem_vec_8476 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_8477);
											mem_vec_8477 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_8478);
											mem_vec_8478 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_8479);
											mem_vec_8479 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_8464);
											mem_vec_8464 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_8465);
											mem_vec_8465 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_8466);
											mem_vec_8466 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_8467);
											mem_vec_8467 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_8468);
											mem_vec_8468 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_8469);
											mem_vec_8469 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_8470);
											mem_vec_8470 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_8471);
											mem_vec_8471 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_8472);
											mem_vec_8472 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_8473);
											mem_vec_8473 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_8474);
											mem_vec_8474 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_8475);
											mem_vec_8475 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_8476);
											mem_vec_8476 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_8477);
											mem_vec_8477 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_8478);
											mem_vec_8478 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_8479);
											mem_vec_8479 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8464);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8465);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8466);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8467);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8468);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8469);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8470);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8471);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8472);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8473);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8474);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8475);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8476);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8477);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8478);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8479);
							}
						}
					}
				}
			}
		}
		for (y = y672 + 4, yp_0 = 0;
			y < y672 + 4 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
			// T (x, 14) (14 / 1)
			for (x1008 = x1009, x1008_p_0 = 0;
				x1008 < x1009 + 14;
				x1008 += 1, x1008_p_0 += 1){
				// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 128
				// T (c, 64) (256 / 4)
				for (c1008 = c1009, c1008_p_0 = 0;
					c1008 < c1009 + 256;
					c1008 += 4, c1008_p_0 += 4){
					// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 128
					// T (f, 2) (128 / 64)
					for (f = f1008, fp_1 = f1008_p_0, fp_0 = 0;
						f < f1008 + 128;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (h, 3) (3 / 1)
						for (h = h534, hp_0 = 0;
							h < h534 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
							// T (x, 1) (1 / 1)
							for (x = x1008, xp_1 = x1008_p_0, xp_0 = 0;
								x < x1008 + 1;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8480 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8481 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8482 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8483 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_8484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_8488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_8492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_8496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_8499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1008, cp_1 = c1008_p_0, cp_0 = 0;
											c < c1008 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8480);
											mem_vec_8480 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8481);
											mem_vec_8481 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8482);
											mem_vec_8482 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8483);
											mem_vec_8483 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8484);
											mem_vec_8484 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_8485);
											mem_vec_8485 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_8486);
											mem_vec_8486 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_8487);
											mem_vec_8487 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8488);
											mem_vec_8488 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8489);
											mem_vec_8489 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_8490);
											mem_vec_8490 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_8491);
											mem_vec_8491 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8492);
											mem_vec_8492 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8493);
											mem_vec_8493 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8494);
											mem_vec_8494 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_8495);
											mem_vec_8495 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_8496);
											mem_vec_8496 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_8497);
											mem_vec_8497 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_8498);
											mem_vec_8498 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_8499);
											mem_vec_8499 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_8480);
											mem_vec_8480 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_8481);
											mem_vec_8481 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_8482);
											mem_vec_8482 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_8483);
											mem_vec_8483 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_8484);
											mem_vec_8484 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_8485);
											mem_vec_8485 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_8486);
											mem_vec_8486 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_8487);
											mem_vec_8487 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_8488);
											mem_vec_8488 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_8489);
											mem_vec_8489 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_8490);
											mem_vec_8490 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_8491);
											mem_vec_8491 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_8492);
											mem_vec_8492 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_8493);
											mem_vec_8493 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_8494);
											mem_vec_8494 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_8495);
											mem_vec_8495 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_8496);
											mem_vec_8496 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_8497);
											mem_vec_8497 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_8498);
											mem_vec_8498 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_8499);
											mem_vec_8499 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_8480);
											mem_vec_8480 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_8481);
											mem_vec_8481 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_8482);
											mem_vec_8482 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_8483);
											mem_vec_8483 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_8484);
											mem_vec_8484 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_8485);
											mem_vec_8485 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_8486);
											mem_vec_8486 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_8487);
											mem_vec_8487 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_8488);
											mem_vec_8488 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_8489);
											mem_vec_8489 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_8490);
											mem_vec_8490 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_8491);
											mem_vec_8491 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_8492);
											mem_vec_8492 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_8493);
											mem_vec_8493 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_8494);
											mem_vec_8494 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_8495);
											mem_vec_8495 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_8496);
											mem_vec_8496 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_8497);
											mem_vec_8497 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_8498);
											mem_vec_8498 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_8499);
											mem_vec_8499 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8480);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8481);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8482);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8483);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8484);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8485);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8486);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8487);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8488);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8489);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8490);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8491);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8492);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8493);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8494);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_8495);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8496);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8497);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8498);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_8499);
							}
						}
					}
				}
			}
		}
}


}