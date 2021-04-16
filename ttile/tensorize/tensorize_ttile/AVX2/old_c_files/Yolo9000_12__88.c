#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (3, h);
  T (34, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (8, f);
  T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c308_p_0, c309_p_0, cp_1, c308_p_1, cp_2, c308, c309, f, fp_0, f252_p_0, fp_1, f252, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y184 = 0;
IND_TYPE x160 = 0;
IND_TYPE h123 = 0;
IND_TYPE w = 0;
IND_TYPE c310 = 0;
IND_TYPE f253 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3420 ,mem_vec_3421 ,mem_vec_3422 ,mem_vec_3423 ,mem_vec_3424 ,mem_vec_3425 ,mem_vec_3426 ,mem_vec_3427 ,mem_vec_3428 ,mem_vec_3429 ,mem_vec_3430 ,mem_vec_3431 ,mem_vec_3432 ,mem_vec_3433 ,mem_vec_3434 ,mem_vec_3435 ,mem_vec_3436 ,mem_vec_3437 ,mem_vec_3438 ,mem_vec_3439 ,mem_vec_3440 ,mem_vec_3441 ,mem_vec_3442 ,mem_vec_3443 ,mem_vec_3444 ,mem_vec_3445 ,mem_vec_3446 ,mem_vec_3447 ,mem_vec_3448 ,mem_vec_3449 ,mem_vec_3450 ,mem_vec_3451 ,mem_vec_3452 ,mem_vec_3453 ,mem_vec_3454 ,mem_vec_3455 ,mem_vec_3456 ,mem_vec_3457 ,mem_vec_3458 ,mem_vec_3459 ,mem_vec_3460 ,mem_vec_3461 ,mem_vec_3462 ,mem_vec_3463 ,mem_vec_3464 ,mem_vec_3465 ,mem_vec_3466 ,mem_vec_3467 ,mem_vec_3468 ,mem_vec_3469 ,mem_vec_3470 ,mem_vec_3471 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f252 = f253, f252_p_0 = 0;
	f252 < f253 + 512;
	f252 += 256, f252_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (c, 2) (256 / 128)
	for (c309 = c310, c309_p_0 = 0;
		c309 < c310 + 256;
		c309 += 128, c309_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 256
		// T (f, 8) (256 / 32)
		for (f = f252, fp_1 = f252_p_0, fp_0 = 0;
			f < f252 + 256;
			f += 32, fp_1 += 32, fp_0 += 32){
				for (y = y184, yp_0 = 0;
					y < y184 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 2) (128 / 64)
					for (c308 = c309, c308_p_1 = c309_p_0, c308_p_0 = 0;
						c308 < c309 + 128;
						c308 += 64, c308_p_1 += 64, c308_p_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
						// T (x, 34) (34 / 1)
						for (x = x160, xp_0 = 0;
							x < x160 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h123, hp_0 = 0;
								h < h123 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3420 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3421 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3422 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3423 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_3424 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3425 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3426 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3427 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_3428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_3432 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3433 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3434 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3435 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_3436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_3440 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3441 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3442 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3443 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c308, cp_2 = c308_p_1, cp_1 = c308_p_0, cp_0 = 0;
											c < c308 + 64;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3420);
											mem_vec_3420 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3421);
											mem_vec_3421 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3422);
											mem_vec_3422 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3423);
											mem_vec_3423 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3424);
											mem_vec_3424 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3425);
											mem_vec_3425 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3426);
											mem_vec_3426 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3427);
											mem_vec_3427 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3428);
											mem_vec_3428 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3429);
											mem_vec_3429 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3430);
											mem_vec_3430 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3431);
											mem_vec_3431 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3432);
											mem_vec_3432 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3433);
											mem_vec_3433 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3434);
											mem_vec_3434 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3435);
											mem_vec_3435 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3436);
											mem_vec_3436 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3437);
											mem_vec_3437 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3438);
											mem_vec_3438 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3439);
											mem_vec_3439 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3440);
											mem_vec_3440 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3441);
											mem_vec_3441 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_3442);
											mem_vec_3442 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_3443);
											mem_vec_3443 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_3420);
											mem_vec_3420 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_3421);
											mem_vec_3421 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_3422);
											mem_vec_3422 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_3423);
											mem_vec_3423 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_3424);
											mem_vec_3424 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_3425);
											mem_vec_3425 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_3426);
											mem_vec_3426 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_3427);
											mem_vec_3427 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_3428);
											mem_vec_3428 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_3429);
											mem_vec_3429 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_3430);
											mem_vec_3430 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_3431);
											mem_vec_3431 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_3432);
											mem_vec_3432 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_3433);
											mem_vec_3433 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_3434);
											mem_vec_3434 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_3435);
											mem_vec_3435 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_3436);
											mem_vec_3436 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_3437);
											mem_vec_3437 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_3438);
											mem_vec_3438 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_3439);
											mem_vec_3439 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_3440);
											mem_vec_3440 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_3441);
											mem_vec_3441 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_3442);
											mem_vec_3442 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_3443);
											mem_vec_3443 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_3420);
											mem_vec_3420 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_3421);
											mem_vec_3421 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_3422);
											mem_vec_3422 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_3423);
											mem_vec_3423 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_3424);
											mem_vec_3424 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_3425);
											mem_vec_3425 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_3426);
											mem_vec_3426 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_3427);
											mem_vec_3427 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_3428);
											mem_vec_3428 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_3429);
											mem_vec_3429 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_3430);
											mem_vec_3430 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_3431);
											mem_vec_3431 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_3432);
											mem_vec_3432 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_3433);
											mem_vec_3433 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_3434);
											mem_vec_3434 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_3435);
											mem_vec_3435 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_3436);
											mem_vec_3436 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_3437);
											mem_vec_3437 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_3438);
											mem_vec_3438 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_3439);
											mem_vec_3439 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_3440);
											mem_vec_3440 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_3441);
											mem_vec_3441 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_3442);
											mem_vec_3442 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_3443);
											mem_vec_3443 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3420);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3421);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3422);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3423);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3424);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3425);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3426);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3427);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3428);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3429);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3430);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3431);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3432);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3433);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3434);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3435);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3436);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3437);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3438);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3439);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3440);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3441);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3442);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_3443);
							}
						}
					}
				}
				for (y = y184 + 6, yp_0 = 0;
					y < y184 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
					// T (c, 2) (128 / 64)
					for (c308 = c309, c308_p_1 = c309_p_0, c308_p_0 = 0;
						c308 < c309 + 128;
						c308 += 64, c308_p_1 += 64, c308_p_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
						// T (x, 34) (34 / 1)
						for (x = x160, xp_0 = 0;
							x < x160 + 34;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h123, hp_0 = 0;
								h < h123 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3444 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3445 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_3446 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3447 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_3448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_3450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_3452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_3454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_3456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_3458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_3460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_3462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_3464 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3465 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_3466 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3467 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										mem_vec_3468 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3469 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
										mem_vec_3470 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3471 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c308, cp_2 = c308_p_1, cp_1 = c308_p_0, cp_0 = 0;
											c < c308 + 64;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3444);
											mem_vec_3444 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3445);
											mem_vec_3445 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3446);
											mem_vec_3446 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3447);
											mem_vec_3447 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3448);
											mem_vec_3448 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3449);
											mem_vec_3449 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3450);
											mem_vec_3450 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3451);
											mem_vec_3451 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3452);
											mem_vec_3452 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3453);
											mem_vec_3453 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3454);
											mem_vec_3454 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3455);
											mem_vec_3455 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3456);
											mem_vec_3456 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3457);
											mem_vec_3457 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3458);
											mem_vec_3458 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3459);
											mem_vec_3459 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_3460);
											mem_vec_3460 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_3461);
											mem_vec_3461 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_3462);
											mem_vec_3462 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_3463);
											mem_vec_3463 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3464);
											mem_vec_3464 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3465);
											mem_vec_3465 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_3466);
											mem_vec_3466 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_3467);
											mem_vec_3467 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);


											vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_3468);
											mem_vec_3468 = vec_34;



											vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_3469);
											mem_vec_3469 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_3470);
											mem_vec_3470 = vec_37;



											vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_3471);
											mem_vec_3471 = vec_38;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_40 = _mm256_set1_ps(scal_7);
											vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_3444);
											mem_vec_3444 = vec_39;

											vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_3445);
											mem_vec_3445 = vec_42;

											vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_3446);
											mem_vec_3446 = vec_44;

											vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_3447);
											mem_vec_3447 = vec_46;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_3448);
											mem_vec_3448 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_3449);
											mem_vec_3449 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_3450);
											mem_vec_3450 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_3451);
											mem_vec_3451 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_3452);
											mem_vec_3452 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_3453);
											mem_vec_3453 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_3454);
											mem_vec_3454 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_3455);
											mem_vec_3455 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_3456);
											mem_vec_3456 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_3457);
											mem_vec_3457 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_3458);
											mem_vec_3458 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_3459);
											mem_vec_3459 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_3460);
											mem_vec_3460 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_3461);
											mem_vec_3461 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_3462);
											mem_vec_3462 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_3463);
											mem_vec_3463 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);


											vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_3464);
											mem_vec_3464 = vec_68;



											vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_3465);
											mem_vec_3465 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_3466);
											mem_vec_3466 = vec_71;



											vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_3467);
											mem_vec_3467 = vec_72;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_74 = _mm256_set1_ps(scal_13);


											vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_3468);
											mem_vec_3468 = vec_73;



											vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_3469);
											mem_vec_3469 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_3470);
											mem_vec_3470 = vec_76;



											vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_3471);
											mem_vec_3471 = vec_77;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_79 = _mm256_set1_ps(scal_14);
											vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_3444);
											mem_vec_3444 = vec_78;

											vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_3445);
											mem_vec_3445 = vec_81;

											vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_3446);
											mem_vec_3446 = vec_83;

											vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_3447);
											mem_vec_3447 = vec_85;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_3448);
											mem_vec_3448 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_3449);
											mem_vec_3449 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_3450);
											mem_vec_3450 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_3451);
											mem_vec_3451 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_3452);
											mem_vec_3452 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_3453);
											mem_vec_3453 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_3454);
											mem_vec_3454 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_3455);
											mem_vec_3455 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_3456);
											mem_vec_3456 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_3457);
											mem_vec_3457 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_3458);
											mem_vec_3458 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_3459);
											mem_vec_3459 = vec_101;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_103 = _mm256_set1_ps(scal_18);


											vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_3460);
											mem_vec_3460 = vec_102;



											vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_3461);
											mem_vec_3461 = vec_104;



											vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_3462);
											mem_vec_3462 = vec_105;



											vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_3463);
											mem_vec_3463 = vec_106;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_108 = _mm256_set1_ps(scal_19);


											vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_3464);
											mem_vec_3464 = vec_107;



											vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_3465);
											mem_vec_3465 = vec_109;



											vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_3466);
											mem_vec_3466 = vec_110;



											vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_3467);
											mem_vec_3467 = vec_111;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_113 = _mm256_set1_ps(scal_20);


											vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_3468);
											mem_vec_3468 = vec_112;



											vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_3469);
											mem_vec_3469 = vec_114;



											vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_3470);
											mem_vec_3470 = vec_115;



											vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_3471);
											mem_vec_3471 = vec_116;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3444);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3445);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3446);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3447);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3448);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3449);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3450);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3451);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3452);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3453);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3454);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3455);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3456);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3457);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3458);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3459);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3460);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3461);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3462);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_3463);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3464);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3465);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3466);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_3467);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3468);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3469);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3470);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_3471);
							}
						}
					}
				}
		}
	}
}


}