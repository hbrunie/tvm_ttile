#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (4, c); T (2, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c549_p_0, cp_1, c549, f, fp_0, f549_p_0, fp_1, f549, h, hp_0, x, xp_0, x514_p_0, xp_1, x514, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y366 = 0;
IND_TYPE x515 = 0;
IND_TYPE h309 = 0;
IND_TYPE w = 0;
IND_TYPE c550 = 0;
IND_TYPE f550 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5357 ,mem_vec_5358 ,mem_vec_5359 ,mem_vec_5360 ,mem_vec_5361 ,mem_vec_5362 ,mem_vec_5363 ,mem_vec_5364 ,mem_vec_5365 ,mem_vec_5366 ,mem_vec_5367 ,mem_vec_5368 ,mem_vec_5369 ,mem_vec_5370 ,mem_vec_5371 ,mem_vec_5372 ,mem_vec_5373 ,mem_vec_5374 ,mem_vec_5375 ,mem_vec_5376 ,mem_vec_5377 ,mem_vec_5378 ,mem_vec_5379 ,mem_vec_5380 ,mem_vec_5381 ,mem_vec_5382 ,mem_vec_5383 ,mem_vec_5384 ,mem_vec_5385 ,mem_vec_5386 ,mem_vec_5387 ,mem_vec_5388 ,mem_vec_5389 ,mem_vec_5390 ,mem_vec_5391 ,mem_vec_5392 ,mem_vec_5393 ,mem_vec_5394 ,mem_vec_5395 ,mem_vec_5396 ,mem_vec_5397 ,mem_vec_5398 ,mem_vec_5399 ,mem_vec_5400 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f549 = f550, f549_p_0 = 0;
	f549 < f550 + 256;
	f549 += 128, f549_p_0 += 128){
		for (y = y366, yp_0 = 0;
			y < y366 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (28 / 14)
			for (x514 = x515, x514_p_0 = 0;
				x514 < x515 + 28;
				x514 += 14, x514_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
				// T (f, 2) (128 / 64)
				for (f = f549, fp_1 = f549_p_0, fp_0 = 0;
					f < f549 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c549 = c550, c549_p_0 = 0;
						c549 < c550 + 128;
						c549 += 32, c549_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h309, hp_0 = 0;
							h < h309 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x514, xp_1 = x514_p_0, xp_0 = 0;
								x < x514 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5357 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5358 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5359 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5360 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5361 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5362 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5363 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5364 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5365 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5366 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5367 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5368 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5369 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5370 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5371 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5372 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5373 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5374 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5375 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5376 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c549, cp_1 = c549_p_0, cp_0 = 0;
											c < c549 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5357);
											mem_vec_5357 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5358);
											mem_vec_5358 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5359);
											mem_vec_5359 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5360);
											mem_vec_5360 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5361);
											mem_vec_5361 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5362);
											mem_vec_5362 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5363);
											mem_vec_5363 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5364);
											mem_vec_5364 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5365);
											mem_vec_5365 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5366);
											mem_vec_5366 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5367);
											mem_vec_5367 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5368);
											mem_vec_5368 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5369);
											mem_vec_5369 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5370);
											mem_vec_5370 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5371);
											mem_vec_5371 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5372);
											mem_vec_5372 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5373);
											mem_vec_5373 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5374);
											mem_vec_5374 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5375);
											mem_vec_5375 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5376);
											mem_vec_5376 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_5357);
											mem_vec_5357 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_5358);
											mem_vec_5358 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_5359);
											mem_vec_5359 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_5360);
											mem_vec_5360 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_5361);
											mem_vec_5361 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_5362);
											mem_vec_5362 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_5363);
											mem_vec_5363 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_5364);
											mem_vec_5364 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_5365);
											mem_vec_5365 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_5366);
											mem_vec_5366 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_5367);
											mem_vec_5367 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_5368);
											mem_vec_5368 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_5369);
											mem_vec_5369 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_5370);
											mem_vec_5370 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_5371);
											mem_vec_5371 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_5372);
											mem_vec_5372 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_5373);
											mem_vec_5373 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_5374);
											mem_vec_5374 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_5375);
											mem_vec_5375 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_5376);
											mem_vec_5376 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_5357);
											mem_vec_5357 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_5358);
											mem_vec_5358 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_5359);
											mem_vec_5359 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_5360);
											mem_vec_5360 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_5361);
											mem_vec_5361 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_5362);
											mem_vec_5362 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_5363);
											mem_vec_5363 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_5364);
											mem_vec_5364 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_5365);
											mem_vec_5365 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_5366);
											mem_vec_5366 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_5367);
											mem_vec_5367 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_5368);
											mem_vec_5368 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_5369);
											mem_vec_5369 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_5370);
											mem_vec_5370 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_5371);
											mem_vec_5371 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_5372);
											mem_vec_5372 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_5373);
											mem_vec_5373 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_5374);
											mem_vec_5374 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_5375);
											mem_vec_5375 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_5376);
											mem_vec_5376 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5357);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5358);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5359);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5360);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5361);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5362);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5363);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5364);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5365);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5366);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5367);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5368);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5369);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5370);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5371);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5372);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5373);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5374);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5375);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5376);
							}
						}
					}
				}
			}
		}
		for (y = y366 + 10, yp_0 = 0;
			y < y366 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (28 / 14)
			for (x514 = x515, x514_p_0 = 0;
				x514 < x515 + 28;
				x514 += 14, x514_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
				// T (f, 2) (128 / 64)
				for (f = f549, fp_1 = f549_p_0, fp_0 = 0;
					f < f549 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c549 = c550, c549_p_0 = 0;
						c549 < c550 + 128;
						c549 += 32, c549_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h309, hp_0 = 0;
							h < h309 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x514, xp_1 = x514_p_0, xp_0 = 0;
								x < x514 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5377 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5378 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5379 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5380 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5381 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5382 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5383 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5384 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5385 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5386 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5387 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5388 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5389 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_5397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_5400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c549, cp_1 = c549_p_0, cp_0 = 0;
											c < c549 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5377);
											mem_vec_5377 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5378);
											mem_vec_5378 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5379);
											mem_vec_5379 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5380);
											mem_vec_5380 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5381);
											mem_vec_5381 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5382);
											mem_vec_5382 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5383);
											mem_vec_5383 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5384);
											mem_vec_5384 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5385);
											mem_vec_5385 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5386);
											mem_vec_5386 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5387);
											mem_vec_5387 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5388);
											mem_vec_5388 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5389);
											mem_vec_5389 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5390);
											mem_vec_5390 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5391);
											mem_vec_5391 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5392);
											mem_vec_5392 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5393);
											mem_vec_5393 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5394);
											mem_vec_5394 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5395);
											mem_vec_5395 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5396);
											mem_vec_5396 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5397);
											mem_vec_5397 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5398);
											mem_vec_5398 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5399);
											mem_vec_5399 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5400);
											mem_vec_5400 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5377);
											mem_vec_5377 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5378);
											mem_vec_5378 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_5379);
											mem_vec_5379 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_5380);
											mem_vec_5380 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5381);
											mem_vec_5381 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_5382);
											mem_vec_5382 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5383);
											mem_vec_5383 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_5384);
											mem_vec_5384 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5385);
											mem_vec_5385 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5386);
											mem_vec_5386 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_5387);
											mem_vec_5387 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5388);
											mem_vec_5388 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_5389);
											mem_vec_5389 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_5390);
											mem_vec_5390 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5391);
											mem_vec_5391 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_5392);
											mem_vec_5392 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5393);
											mem_vec_5393 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_5394);
											mem_vec_5394 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_5395);
											mem_vec_5395 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_5396);
											mem_vec_5396 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_5397);
											mem_vec_5397 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_5398);
											mem_vec_5398 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_5399);
											mem_vec_5399 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_5400);
											mem_vec_5400 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_5377);
											mem_vec_5377 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_5378);
											mem_vec_5378 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_5379);
											mem_vec_5379 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_5380);
											mem_vec_5380 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_5381);
											mem_vec_5381 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_5382);
											mem_vec_5382 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_5383);
											mem_vec_5383 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_5384);
											mem_vec_5384 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_5385);
											mem_vec_5385 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_5386);
											mem_vec_5386 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_5387);
											mem_vec_5387 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_5388);
											mem_vec_5388 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_5389);
											mem_vec_5389 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_5390);
											mem_vec_5390 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_5391);
											mem_vec_5391 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_5392);
											mem_vec_5392 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_5393);
											mem_vec_5393 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_5394);
											mem_vec_5394 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_5395);
											mem_vec_5395 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_5396);
											mem_vec_5396 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_5397);
											mem_vec_5397 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_5398);
											mem_vec_5398 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_5399);
											mem_vec_5399 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_5400);
											mem_vec_5400 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5377);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5378);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5379);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5380);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5381);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5382);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5383);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5384);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5385);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5386);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5387);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5388);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5389);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5390);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5391);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5392);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5393);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5394);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5395);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5396);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5397);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5398);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5399);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5400);
							}
						}
					}
				}
			}
		}
}


}