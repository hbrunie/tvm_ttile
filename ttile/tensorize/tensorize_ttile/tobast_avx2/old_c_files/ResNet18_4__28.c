#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (8, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (8, f);
  T (14, x)]
*/
IND_TYPE c, cp_0, c1064_p_0, cp_1, c1064, f, fp_0, w, wp_0, x, xp_0, x1246_p_0, x1247_p_0, xp_1, x1246_p_1, xp_2, x1246, x1247, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y660 = 0;
IND_TYPE x1248 = 0;
IND_TYPE h = 0;
IND_TYPE w524 = 0;
IND_TYPE c1065 = 0;
IND_TYPE f734 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9416 ,mem_vec_9417 ,mem_vec_9418 ,mem_vec_9419 ,mem_vec_9420 ,mem_vec_9421 ,mem_vec_9422 ,mem_vec_9423 ,mem_vec_9424 ,mem_vec_9425 ,mem_vec_9426 ,mem_vec_9427 ,mem_vec_9428 ,mem_vec_9429 ,mem_vec_9430 ,mem_vec_9431 ,mem_vec_9432 ,mem_vec_9433 ,mem_vec_9434 ,mem_vec_9435 ,mem_vec_9436 ,mem_vec_9437 ,mem_vec_9438 ,mem_vec_9439 ,mem_vec_9440 ,mem_vec_9441 ,mem_vec_9442 ,mem_vec_9443 ,mem_vec_9444 ,mem_vec_9445 ,mem_vec_9446 ,mem_vec_9447 ,mem_vec_9448 ,mem_vec_9449 ,mem_vec_9450 ,mem_vec_9451 ,mem_vec_9452 ,mem_vec_9453 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (x, 14) (28 / 2)
for (x1247 = x1248, x1247_p_0 = 0;
	x1247 < x1248 + 28;
	x1247 += 2, x1247_p_0 += 2){
	// y = 28, x = 2, h = 3, w = 3, c = 64, f = 128
	// T (f, 8) (128 / 16)
	for (f = f734, fp_0 = 0;
		f < f734 + 128;
		f += 16, fp_0 += 16){
			for (y = y660, yp_0 = 0;
				y < y660 + 18;
				y += 9, yp_0 += 9){
				// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 16
				// T (x, 2) (2 / 1)
				for (x1246 = x1247, x1246_p_1 = x1247_p_0, x1246_p_0 = 0;
					x1246 < x1247 + 2;
					x1246 += 1, x1246_p_1 += 1, x1246_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
					// T (c, 8) (64 / 8)
					for (c1064 = c1065, c1064_p_0 = 0;
						c1064 < c1065 + 64;
						c1064 += 8, c1064_p_0 += 8){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
						// T (w, 3) (3 / 1)
						for (w = w524, wp_0 = 0;
							w < w524 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
							// T (x, 1) (1 / 1)
							for (x = x1246, xp_2 = x1246_p_1, xp_1 = x1246_p_0, xp_0 = 0;
								x < x1246 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9416 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9417 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_9418 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9419 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_9420 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9421 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_9422 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9423 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_9424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_9426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_9428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_9430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_9432 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9433 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
										// T (c, 8) (8 / 1)
										for (c = c1064, cp_1 = c1064_p_0, cp_0 = 0;
											c < c1064 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9416);
											mem_vec_9416 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9417);
											mem_vec_9417 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_9418);
											mem_vec_9418 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_9419);
											mem_vec_9419 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_9420);
											mem_vec_9420 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_9421);
											mem_vec_9421 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_9422);
											mem_vec_9422 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_9423);
											mem_vec_9423 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9424);
											mem_vec_9424 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9425);
											mem_vec_9425 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_9426);
											mem_vec_9426 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_9427);
											mem_vec_9427 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_9428);
											mem_vec_9428 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_9429);
											mem_vec_9429 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_9430);
											mem_vec_9430 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_9431);
											mem_vec_9431 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_9432);
											mem_vec_9432 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_9433);
											mem_vec_9433 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_30 = _mm256_set1_ps(scal_9);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_9416);
											mem_vec_9416 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_9417);
											mem_vec_9417 = vec_32;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_35 = _mm256_set1_ps(scal_10);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_31, mem_vec_9418);
											mem_vec_9418 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_33, mem_vec_9419);
											mem_vec_9419 = vec_36;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);


											vec_37 = _mm256_fmadd_ps(vec_38, vec_31, mem_vec_9420);
											mem_vec_9420 = vec_37;



											vec_39 = _mm256_fmadd_ps(vec_38, vec_33, mem_vec_9421);
											mem_vec_9421 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_31, mem_vec_9422);
											mem_vec_9422 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_33, mem_vec_9423);
											mem_vec_9423 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_9424);
											mem_vec_9424 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_9425);
											mem_vec_9425 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_31, mem_vec_9426);
											mem_vec_9426 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_33, mem_vec_9427);
											mem_vec_9427 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_31, mem_vec_9428);
											mem_vec_9428 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_33, mem_vec_9429);
											mem_vec_9429 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_31, mem_vec_9430);
											mem_vec_9430 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_33, mem_vec_9431);
											mem_vec_9431 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_31, mem_vec_9432);
											mem_vec_9432 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_33, mem_vec_9433);
											mem_vec_9433 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_59 = _mm256_set1_ps(scal_18);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_9416);
											mem_vec_9416 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_9417);
											mem_vec_9417 = vec_61;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_64 = _mm256_set1_ps(scal_19);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_60, mem_vec_9418);
											mem_vec_9418 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_62, mem_vec_9419);
											mem_vec_9419 = vec_65;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_67 = _mm256_set1_ps(scal_20);


											vec_66 = _mm256_fmadd_ps(vec_67, vec_60, mem_vec_9420);
											mem_vec_9420 = vec_66;



											vec_68 = _mm256_fmadd_ps(vec_67, vec_62, mem_vec_9421);
											mem_vec_9421 = vec_68;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);


											vec_69 = _mm256_fmadd_ps(vec_70, vec_60, mem_vec_9422);
											mem_vec_9422 = vec_69;



											vec_71 = _mm256_fmadd_ps(vec_70, vec_62, mem_vec_9423);
											mem_vec_9423 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_9424);
											mem_vec_9424 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_9425);
											mem_vec_9425 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_60, mem_vec_9426);
											mem_vec_9426 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_62, mem_vec_9427);
											mem_vec_9427 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_60, mem_vec_9428);
											mem_vec_9428 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_62, mem_vec_9429);
											mem_vec_9429 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_60, mem_vec_9430);
											mem_vec_9430 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_62, mem_vec_9431);
											mem_vec_9431 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_60, mem_vec_9432);
											mem_vec_9432 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_62, mem_vec_9433);
											mem_vec_9433 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9416);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9417);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9418);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9419);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9420);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9421);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9422);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9423);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9424);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9425);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9426);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9427);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9428);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_9429);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9430);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_9431);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9432);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_9433);
							}
						}
					}
				}
			}
			for (y = y660 + 18, yp_0 = 0;
				y < y660 + 18 + 10;
				y += 10, yp_0 += 10){
				// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 16
				// T (x, 2) (2 / 1)
				for (x1246 = x1247, x1246_p_1 = x1247_p_0, x1246_p_0 = 0;
					x1246 < x1247 + 2;
					x1246 += 1, x1246_p_1 += 1, x1246_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
					// T (c, 8) (64 / 8)
					for (c1064 = c1065, c1064_p_0 = 0;
						c1064 < c1065 + 64;
						c1064 += 8, c1064_p_0 += 8){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
						// T (w, 3) (3 / 1)
						for (w = w524, wp_0 = 0;
							w < w524 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
							// T (x, 1) (1 / 1)
							for (x = x1246, xp_2 = x1246_p_1, xp_1 = x1246_p_0, xp_0 = 0;
								x < x1246 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9434 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9435 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_9436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_9438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_9440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_9442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_9444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_9446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_9447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_9448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_9449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
										mem_vec_9450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_9451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
										mem_vec_9452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_9453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
										// T (c, 8) (8 / 1)
										for (c = c1064, cp_1 = c1064_p_0, cp_0 = 0;
											c < c1064 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9434);
											mem_vec_9434 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9435);
											mem_vec_9435 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm256_set1_ps(scal_1);


											vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_9436);
											mem_vec_9436 = vec_5;



											vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_9437);
											mem_vec_9437 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm256_set1_ps(scal_2);


											vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_9438);
											mem_vec_9438 = vec_8;



											vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_9439);
											mem_vec_9439 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm256_set1_ps(scal_3);


											vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_9440);
											mem_vec_9440 = vec_11;



											vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_9441);
											mem_vec_9441 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm256_set1_ps(scal_4);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9442);
											mem_vec_9442 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9443);
											mem_vec_9443 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm256_set1_ps(scal_5);


											vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_9444);
											mem_vec_9444 = vec_17;



											vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_9445);
											mem_vec_9445 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm256_set1_ps(scal_6);


											vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_9446);
											mem_vec_9446 = vec_20;



											vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_9447);
											mem_vec_9447 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm256_set1_ps(scal_7);


											vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_9448);
											mem_vec_9448 = vec_23;



											vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_9449);
											mem_vec_9449 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm256_set1_ps(scal_8);


											vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_9450);
											mem_vec_9450 = vec_26;



											vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_9451);
											mem_vec_9451 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm256_set1_ps(scal_9);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9452);
											mem_vec_9452 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9453);
											mem_vec_9453 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_33 = _mm256_set1_ps(scal_10);
											vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_9434);
											mem_vec_9434 = vec_32;

											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

											vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_9435);
											mem_vec_9435 = vec_35;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_38 = _mm256_set1_ps(scal_11);


											vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_9436);
											mem_vec_9436 = vec_37;



											vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_9437);
											mem_vec_9437 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_41 = _mm256_set1_ps(scal_12);


											vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_9438);
											mem_vec_9438 = vec_40;



											vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_9439);
											mem_vec_9439 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_44 = _mm256_set1_ps(scal_13);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_9440);
											mem_vec_9440 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_9441);
											mem_vec_9441 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_47 = _mm256_set1_ps(scal_14);


											vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_9442);
											mem_vec_9442 = vec_46;



											vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_9443);
											mem_vec_9443 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_50 = _mm256_set1_ps(scal_15);


											vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_9444);
											mem_vec_9444 = vec_49;



											vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_9445);
											mem_vec_9445 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_53 = _mm256_set1_ps(scal_16);


											vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_9446);
											mem_vec_9446 = vec_52;



											vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_9447);
											mem_vec_9447 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_56 = _mm256_set1_ps(scal_17);


											vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_9448);
											mem_vec_9448 = vec_55;



											vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_9449);
											mem_vec_9449 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_59 = _mm256_set1_ps(scal_18);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_9450);
											mem_vec_9450 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_9451);
											mem_vec_9451 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_62 = _mm256_set1_ps(scal_19);


											vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_9452);
											mem_vec_9452 = vec_61;



											vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_9453);
											mem_vec_9453 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_65 = _mm256_set1_ps(scal_20);
											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_9434);
											mem_vec_9434 = vec_64;

											vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

											vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_9435);
											mem_vec_9435 = vec_67;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_70 = _mm256_set1_ps(scal_21);


											vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_9436);
											mem_vec_9436 = vec_69;



											vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_9437);
											mem_vec_9437 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm256_set1_ps(scal_22);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_9438);
											mem_vec_9438 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_9439);
											mem_vec_9439 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_76 = _mm256_set1_ps(scal_23);


											vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_9440);
											mem_vec_9440 = vec_75;



											vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_9441);
											mem_vec_9441 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_79 = _mm256_set1_ps(scal_24);


											vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_9442);
											mem_vec_9442 = vec_78;



											vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_9443);
											mem_vec_9443 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_82 = _mm256_set1_ps(scal_25);


											vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_9444);
											mem_vec_9444 = vec_81;



											vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_9445);
											mem_vec_9445 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_85 = _mm256_set1_ps(scal_26);


											vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_9446);
											mem_vec_9446 = vec_84;



											vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_9447);
											mem_vec_9447 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_88 = _mm256_set1_ps(scal_27);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_9448);
											mem_vec_9448 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_9449);
											mem_vec_9449 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_91 = _mm256_set1_ps(scal_28);


											vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_9450);
											mem_vec_9450 = vec_90;



											vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_9451);
											mem_vec_9451 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_94 = _mm256_set1_ps(scal_29);


											vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_9452);
											mem_vec_9452 = vec_93;



											vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_9453);
											mem_vec_9453 = vec_95;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9434);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9435);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9436);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9437);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9438);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9439);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9440);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9441);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9442);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9443);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9444);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9445);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9446);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_9447);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9448);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_9449);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9450);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_9451);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9452);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_9453);
							}
						}
					}
				}
			}
	}
}


}