#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (4, f); T (16, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (1, f)]
*/
IND_TYPE c, cp_0, c1098_p_0, cp_1, c1098, f, fp_0, f1098_p_0, fp_1, f1098, h, hp_0, x, xp_0, x1098_p_0, xp_1, x1098, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y732 = 0;
IND_TYPE x1099 = 0;
IND_TYPE h574 = 0;
IND_TYPE w = 0;
IND_TYPE c1099 = 0;
IND_TYPE f1099 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9372 ,mem_vec_9373 ,mem_vec_9374 ,mem_vec_9375 ,mem_vec_9376 ,mem_vec_9377 ,mem_vec_9378 ,mem_vec_9379 ,mem_vec_9380 ,mem_vec_9381 ,mem_vec_9382 ,mem_vec_9383 ,mem_vec_9384 ,mem_vec_9385 ,mem_vec_9386 ,mem_vec_9387 ,mem_vec_9388 ,mem_vec_9389 ,mem_vec_9390 ,mem_vec_9391 ,mem_vec_9392 ,mem_vec_9393 ,mem_vec_9394 ,mem_vec_9395 ,mem_vec_9396 ,mem_vec_9397 ,mem_vec_9398 ,mem_vec_9399 ,mem_vec_9400 ,mem_vec_9401 ,mem_vec_9402 ,mem_vec_9403 ,mem_vec_9404 ,mem_vec_9405 ,mem_vec_9406 ,mem_vec_9407 ,mem_vec_9408 ,mem_vec_9409 ,mem_vec_9410 ,mem_vec_9411 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1098 = f1099, f1098_p_0 = 0;
	f1098 < f1099 + 256;
	f1098 += 256, f1098_p_0 += 256){
		for (y = y732, yp_0 = 0;
			y < y732 + 8;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (14 / 7)
			for (x1098 = x1099, x1098_p_0 = 0;
				x1098 < x1099 + 14;
				x1098 += 7, x1098_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 256
				// T (c, 16) (128 / 8)
				for (c1098 = c1099, c1098_p_0 = 0;
					c1098 < c1099 + 128;
					c1098 += 8, c1098_p_0 += 8){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 256
					// T (f, 4) (256 / 64)
					for (f = f1098, fp_1 = f1098_p_0, fp_0 = 0;
						f < f1098 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
						// T (h, 3) (3 / 1)
						for (h = h574, hp_0 = 0;
							h < h574 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;
								x < x1098 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9372 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9373 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9374 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_9375 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_9376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9377 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9378 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_9379 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_9380 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_9383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_9384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_9387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
											c < c1098 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9372);
											mem_vec_9372 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9373);
											mem_vec_9373 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9374);
											mem_vec_9374 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9375);
											mem_vec_9375 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9376);
											mem_vec_9376 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9377);
											mem_vec_9377 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9378);
											mem_vec_9378 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9379);
											mem_vec_9379 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9380);
											mem_vec_9380 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9381);
											mem_vec_9381 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9382);
											mem_vec_9382 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9383);
											mem_vec_9383 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9384);
											mem_vec_9384 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9385);
											mem_vec_9385 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9386);
											mem_vec_9386 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9387);
											mem_vec_9387 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_9372);
											mem_vec_9372 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_9373);
											mem_vec_9373 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_9374);
											mem_vec_9374 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_9375);
											mem_vec_9375 = vec_31;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_9376);
											mem_vec_9376 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_9377);
											mem_vec_9377 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_9378);
											mem_vec_9378 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_9379);
											mem_vec_9379 = vec_37;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_9380);
											mem_vec_9380 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_9381);
											mem_vec_9381 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_9382);
											mem_vec_9382 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_9383);
											mem_vec_9383 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_9384);
											mem_vec_9384 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_9385);
											mem_vec_9385 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_9386);
											mem_vec_9386 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_9387);
											mem_vec_9387 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_9372);
											mem_vec_9372 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_9373);
											mem_vec_9373 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_9374);
											mem_vec_9374 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_9375);
											mem_vec_9375 = vec_55;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_9376);
											mem_vec_9376 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_9377);
											mem_vec_9377 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_9378);
											mem_vec_9378 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_9379);
											mem_vec_9379 = vec_61;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_9380);
											mem_vec_9380 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_9381);
											mem_vec_9381 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_9382);
											mem_vec_9382 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_9383);
											mem_vec_9383 = vec_66;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_9384);
											mem_vec_9384 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_9385);
											mem_vec_9385 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_9386);
											mem_vec_9386 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_9387);
											mem_vec_9387 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9372);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9373);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9374);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9375);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9376);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9377);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9378);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9379);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9381);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9387);
							}
						}
					}
				}
			}
		}
		for (y = y732 + 8, yp_0 = 0;
			y < y732 + 8 + 6;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (14 / 7)
			for (x1098 = x1099, x1098_p_0 = 0;
				x1098 < x1099 + 14;
				x1098 += 7, x1098_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 256
				// T (c, 16) (128 / 8)
				for (c1098 = c1099, c1098_p_0 = 0;
					c1098 < c1099 + 128;
					c1098 += 8, c1098_p_0 += 8){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 256
					// T (f, 4) (256 / 64)
					for (f = f1098, fp_1 = f1098_p_0, fp_0 = 0;
						f < f1098 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
						// T (h, 3) (3 / 1)
						for (h = h574, hp_0 = 0;
							h < h574 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 8, f = 64
							// T (x, 7) (7 / 1)
							for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;
								x < x1098 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9388 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9389 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9390 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_9391 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_9392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_9395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_9396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_9399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_9400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_9403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_9404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_9407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_9408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_9411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
											c < c1098 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9388);
											mem_vec_9388 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9389);
											mem_vec_9389 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9390);
											mem_vec_9390 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9391);
											mem_vec_9391 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9392);
											mem_vec_9392 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9393);
											mem_vec_9393 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9394);
											mem_vec_9394 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9395);
											mem_vec_9395 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9396);
											mem_vec_9396 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9397);
											mem_vec_9397 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9398);
											mem_vec_9398 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9399);
											mem_vec_9399 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9400);
											mem_vec_9400 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9401);
											mem_vec_9401 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9402);
											mem_vec_9402 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9403);
											mem_vec_9403 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9404);
											mem_vec_9404 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9405);
											mem_vec_9405 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9406);
											mem_vec_9406 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9407);
											mem_vec_9407 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9408);
											mem_vec_9408 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9409);
											mem_vec_9409 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_9410);
											mem_vec_9410 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_9411);
											mem_vec_9411 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_9388);
											mem_vec_9388 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_9389);
											mem_vec_9389 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_9390);
											mem_vec_9390 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_9391);
											mem_vec_9391 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_9392);
											mem_vec_9392 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_9393);
											mem_vec_9393 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_9394);
											mem_vec_9394 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_9395);
											mem_vec_9395 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_9396);
											mem_vec_9396 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_9397);
											mem_vec_9397 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_9398);
											mem_vec_9398 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_9399);
											mem_vec_9399 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_9400);
											mem_vec_9400 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_9401);
											mem_vec_9401 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_9402);
											mem_vec_9402 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_9403);
											mem_vec_9403 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_9404);
											mem_vec_9404 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_9405);
											mem_vec_9405 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_9406);
											mem_vec_9406 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_9407);
											mem_vec_9407 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_9408);
											mem_vec_9408 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_9409);
											mem_vec_9409 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_9410);
											mem_vec_9410 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_9411);
											mem_vec_9411 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_9388);
											mem_vec_9388 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_9389);
											mem_vec_9389 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_9390);
											mem_vec_9390 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_9391);
											mem_vec_9391 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_9392);
											mem_vec_9392 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_9393);
											mem_vec_9393 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_9394);
											mem_vec_9394 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_9395);
											mem_vec_9395 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_9396);
											mem_vec_9396 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_9397);
											mem_vec_9397 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_9398);
											mem_vec_9398 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_9399);
											mem_vec_9399 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_9400);
											mem_vec_9400 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_9401);
											mem_vec_9401 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_9402);
											mem_vec_9402 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_9403);
											mem_vec_9403 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_9404);
											mem_vec_9404 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_9405);
											mem_vec_9405 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_9406);
											mem_vec_9406 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_9407);
											mem_vec_9407 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_9408);
											mem_vec_9408 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_9409);
											mem_vec_9409 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_9410);
											mem_vec_9410 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_9411);
											mem_vec_9411 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9399);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9403);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9404);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9405);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9406);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9407);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9408);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9409);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_9410);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_9411);
							}
						}
					}
				}
			}
		}
}


}