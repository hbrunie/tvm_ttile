#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, w); T (1, f); T (4, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (8, f)]
*/
IND_TYPE c, cp_0, c990_p_0, cp_1, c990, f, fp_0, f1062_p_0, fp_1, f1062, w, wp_0, x, xp_0, x990_p_0, xp_1, x990, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y660 = 0;
IND_TYPE x991 = 0;
IND_TYPE h = 0;
IND_TYPE w610 = 0;
IND_TYPE c991 = 0;
IND_TYPE f1063 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9396 ,mem_vec_9397 ,mem_vec_9398 ,mem_vec_9399 ,mem_vec_9400 ,mem_vec_9401 ,mem_vec_9402 ,mem_vec_9403 ,mem_vec_9404 ,mem_vec_9405 ,mem_vec_9406 ,mem_vec_9407 ,mem_vec_9408 ,mem_vec_9409 ,mem_vec_9410 ,mem_vec_9411 ,mem_vec_9412 ,mem_vec_9413 ,mem_vec_9414 ,mem_vec_9415 ,mem_vec_9416 ,mem_vec_9417 ,mem_vec_9418 ,mem_vec_9419 ,mem_vec_9420 ,mem_vec_9421 ,mem_vec_9422 ,mem_vec_9423 ,mem_vec_9424 ,mem_vec_9425 ,mem_vec_9426 ,mem_vec_9427 ,mem_vec_9428 ,mem_vec_9429 ,mem_vec_9430 ,mem_vec_9431 ,mem_vec_9432 ,mem_vec_9433 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f1062 = f1063, f1062_p_0 = 0;
	f1062 < f1063 + 256;
	f1062 += 32, f1062_p_0 += 32){
		for (y = y660, yp_0 = 0;
			y < y660 + 18;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 2) (28 / 14)
			for (x990 = x991, x990_p_0 = 0;
				x990 < x991 + 28;
				x990 += 14, x990_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 32
				// T (c, 4) (128 / 32)
				for (c990 = c991, c990_p_0 = 0;
					c990 < c991 + 128;
					c990 += 32, c990_p_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1062, fp_1 = f1062_p_0, fp_0 = 0;
						f < f1062 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w610, wp_0 = 0;
							w < w610 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x990, xp_1 = x990_p_0, xp_0 = 0;
								x < x990 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9396 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9397 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c990, cp_1 = c990_p_0, cp_0 = 0;
											c < c990 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9396);
											mem_vec_9396 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9397);
											mem_vec_9397 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9398);
											mem_vec_9398 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9399);
											mem_vec_9399 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9400);
											mem_vec_9400 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9401);
											mem_vec_9401 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9402);
											mem_vec_9402 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9403);
											mem_vec_9403 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9404);
											mem_vec_9404 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9405);
											mem_vec_9405 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9406);
											mem_vec_9406 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9407);
											mem_vec_9407 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9408);
											mem_vec_9408 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9409);
											mem_vec_9409 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9410);
											mem_vec_9410 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9411);
											mem_vec_9411 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9412);
											mem_vec_9412 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9413);
											mem_vec_9413 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_9396);
											mem_vec_9396 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_9397);
											mem_vec_9397 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_9398);
											mem_vec_9398 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_9399);
											mem_vec_9399 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_9400);
											mem_vec_9400 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_9401);
											mem_vec_9401 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_9402);
											mem_vec_9402 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_9403);
											mem_vec_9403 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_9404);
											mem_vec_9404 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_9405);
											mem_vec_9405 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_9406);
											mem_vec_9406 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_9407);
											mem_vec_9407 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_9408);
											mem_vec_9408 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_9409);
											mem_vec_9409 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_9410);
											mem_vec_9410 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_9411);
											mem_vec_9411 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_9412);
											mem_vec_9412 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_9413);
											mem_vec_9413 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_9396);
											mem_vec_9396 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_9397);
											mem_vec_9397 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_9398);
											mem_vec_9398 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_9399);
											mem_vec_9399 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_9400);
											mem_vec_9400 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_9401);
											mem_vec_9401 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_9402);
											mem_vec_9402 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_9403);
											mem_vec_9403 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_9404);
											mem_vec_9404 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_9405);
											mem_vec_9405 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_9406);
											mem_vec_9406 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_9407);
											mem_vec_9407 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_9408);
											mem_vec_9408 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_9409);
											mem_vec_9409 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_9410);
											mem_vec_9410 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_9411);
											mem_vec_9411 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_9412);
											mem_vec_9412 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_9413);
											mem_vec_9413 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9399);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9400);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9401);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9402);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9403);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9404);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9405);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9406);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9407);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9408);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9409);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9410);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9411);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9412);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9413);
							}
						}
					}
				}
			}
		}
		for (y = y660 + 18, yp_0 = 0;
			y < y660 + 18 + 10;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 2) (28 / 14)
			for (x990 = x991, x990_p_0 = 0;
				x990 < x991 + 28;
				x990 += 14, x990_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 32
				// T (c, 4) (128 / 32)
				for (c990 = c991, c990_p_0 = 0;
					c990 < c991 + 128;
					c990 += 32, c990_p_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1062, fp_1 = f1062_p_0, fp_0 = 0;
						f < f1062 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w610, wp_0 = 0;
							w < w610 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x990, xp_1 = x990_p_0, xp_0 = 0;
								x < x990 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9414 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9415 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9416 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9417 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_9428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_9430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_9432 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9433 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c990, cp_1 = c990_p_0, cp_0 = 0;
											c < c990 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9414);
											mem_vec_9414 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9415);
											mem_vec_9415 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9416);
											mem_vec_9416 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9417);
											mem_vec_9417 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9418);
											mem_vec_9418 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9419);
											mem_vec_9419 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9420);
											mem_vec_9420 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9421);
											mem_vec_9421 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9422);
											mem_vec_9422 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9423);
											mem_vec_9423 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9424);
											mem_vec_9424 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9425);
											mem_vec_9425 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9426);
											mem_vec_9426 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9427);
											mem_vec_9427 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9428);
											mem_vec_9428 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9429);
											mem_vec_9429 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9430);
											mem_vec_9430 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9431);
											mem_vec_9431 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9432);
											mem_vec_9432 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9433);
											mem_vec_9433 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_9414);
											mem_vec_9414 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_9415);
											mem_vec_9415 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_9416);
											mem_vec_9416 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_9417);
											mem_vec_9417 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_9418);
											mem_vec_9418 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_9419);
											mem_vec_9419 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_9420);
											mem_vec_9420 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_9421);
											mem_vec_9421 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_9422);
											mem_vec_9422 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_9423);
											mem_vec_9423 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_9424);
											mem_vec_9424 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_9425);
											mem_vec_9425 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_9426);
											mem_vec_9426 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_9427);
											mem_vec_9427 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_9428);
											mem_vec_9428 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_9429);
											mem_vec_9429 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_9430);
											mem_vec_9430 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_9431);
											mem_vec_9431 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_9432);
											mem_vec_9432 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_9433);
											mem_vec_9433 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_9414);
											mem_vec_9414 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_9415);
											mem_vec_9415 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_9416);
											mem_vec_9416 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_9417);
											mem_vec_9417 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_9418);
											mem_vec_9418 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_9419);
											mem_vec_9419 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_9420);
											mem_vec_9420 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_9421);
											mem_vec_9421 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_9422);
											mem_vec_9422 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_9423);
											mem_vec_9423 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_9424);
											mem_vec_9424 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_9425);
											mem_vec_9425 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_9426);
											mem_vec_9426 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_9427);
											mem_vec_9427 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_9428);
											mem_vec_9428 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_9429);
											mem_vec_9429 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_9430);
											mem_vec_9430 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_9431);
											mem_vec_9431 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_9432);
											mem_vec_9432 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_9433);
											mem_vec_9433 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9414);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9415);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9416);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9417);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9418);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9419);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9420);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9421);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9422);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9423);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9424);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9425);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9426);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9427);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9428);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9429);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9430);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9431);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9432);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9433);
							}
						}
					}
				}
			}
		}
}


}