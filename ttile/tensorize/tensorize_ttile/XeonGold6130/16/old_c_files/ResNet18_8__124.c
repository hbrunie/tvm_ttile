#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (4, c); T (4, f); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f)]
*/
IND_TYPE c, cp_0, c546_p_0, cp_1, c546, f, fp_0, f546_p_0, fp_1, f546, h, hp_0, x, xp_0, x511_p_0, xp_1, x511, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y364 = 0;
IND_TYPE x512 = 0;
IND_TYPE h307 = 0;
IND_TYPE w = 0;
IND_TYPE c547 = 0;
IND_TYPE f547 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5313 ,mem_vec_5314 ,mem_vec_5315 ,mem_vec_5316 ,mem_vec_5317 ,mem_vec_5318 ,mem_vec_5319 ,mem_vec_5320 ,mem_vec_5321 ,mem_vec_5322 ,mem_vec_5323 ,mem_vec_5324 ,mem_vec_5325 ,mem_vec_5326 ,mem_vec_5327 ,mem_vec_5328 ,mem_vec_5329 ,mem_vec_5330 ,mem_vec_5331 ,mem_vec_5332 ,mem_vec_5333 ,mem_vec_5334 ,mem_vec_5335 ,mem_vec_5336 ,mem_vec_5337 ,mem_vec_5338 ,mem_vec_5339 ,mem_vec_5340 ,mem_vec_5341 ,mem_vec_5342 ,mem_vec_5343 ,mem_vec_5344 ,mem_vec_5345 ,mem_vec_5346 ,mem_vec_5347 ,mem_vec_5348 ,mem_vec_5349 ,mem_vec_5350 ,mem_vec_5351 ,mem_vec_5352 ,mem_vec_5353 ,mem_vec_5354 ,mem_vec_5355 ,mem_vec_5356 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f546 = f547, f546_p_0 = 0;
	f546 < f547 + 256;
	f546 += 256, f546_p_0 += 256){
		for (y = y364, yp_0 = 0;
			y < y364 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (28 / 14)
			for (x511 = x512, x511_p_0 = 0;
				x511 < x512 + 28;
				x511 += 14, x511_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
				// T (f, 4) (256 / 64)
				for (f = f546, fp_1 = f546_p_0, fp_0 = 0;
					f < f546 + 256;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c546 = c547, c546_p_0 = 0;
						c546 < c547 + 128;
						c546 += 32, c546_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h307, hp_0 = 0;
							h < h307 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x511, xp_1 = x511_p_0, xp_0 = 0;
								x < x511 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5313 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5314 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5315 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5316 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
											c < c546 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5313);
											mem_vec_5313 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5314);
											mem_vec_5314 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5315);
											mem_vec_5315 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5316);
											mem_vec_5316 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5317);
											mem_vec_5317 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5318);
											mem_vec_5318 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5319);
											mem_vec_5319 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5320);
											mem_vec_5320 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5321);
											mem_vec_5321 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5322);
											mem_vec_5322 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5323);
											mem_vec_5323 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5324);
											mem_vec_5324 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5325);
											mem_vec_5325 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5326);
											mem_vec_5326 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5327);
											mem_vec_5327 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5328);
											mem_vec_5328 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5329);
											mem_vec_5329 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5330);
											mem_vec_5330 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5331);
											mem_vec_5331 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5332);
											mem_vec_5332 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_5313);
											mem_vec_5313 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_5314);
											mem_vec_5314 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_5315);
											mem_vec_5315 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_5316);
											mem_vec_5316 = vec_36;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_5317);
											mem_vec_5317 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_5318);
											mem_vec_5318 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_5319);
											mem_vec_5319 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_5320);
											mem_vec_5320 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_5321);
											mem_vec_5321 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_5322);
											mem_vec_5322 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_5323);
											mem_vec_5323 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_5324);
											mem_vec_5324 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_5325);
											mem_vec_5325 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_5326);
											mem_vec_5326 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_5327);
											mem_vec_5327 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_5328);
											mem_vec_5328 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_5329);
											mem_vec_5329 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_5330);
											mem_vec_5330 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_5331);
											mem_vec_5331 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_5332);
											mem_vec_5332 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_5313);
											mem_vec_5313 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_5314);
											mem_vec_5314 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_5315);
											mem_vec_5315 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_5316);
											mem_vec_5316 = vec_65;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_5317);
											mem_vec_5317 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_5318);
											mem_vec_5318 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_5319);
											mem_vec_5319 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_5320);
											mem_vec_5320 = vec_71;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_5321);
											mem_vec_5321 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_5322);
											mem_vec_5322 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_5323);
											mem_vec_5323 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_5324);
											mem_vec_5324 = vec_76;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_5325);
											mem_vec_5325 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_5326);
											mem_vec_5326 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_5327);
											mem_vec_5327 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_5328);
											mem_vec_5328 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_5329);
											mem_vec_5329 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_5330);
											mem_vec_5330 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_5331);
											mem_vec_5331 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_5332);
											mem_vec_5332 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5315);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5316);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5317);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5318);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5319);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5327);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5329);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5330);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5331);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5332);
							}
						}
					}
				}
			}
		}
		for (y = y364 + 10, yp_0 = 0;
			y < y364 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (28 / 14)
			for (x511 = x512, x511_p_0 = 0;
				x511 < x512 + 28;
				x511 += 14, x511_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
				// T (f, 4) (256 / 64)
				for (f = f546, fp_1 = f546_p_0, fp_0 = 0;
					f < f546 + 256;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 64
					// T (c, 4) (128 / 32)
					for (c546 = c547, c546_p_0 = 0;
						c546 < c547 + 128;
						c546 += 32, c546_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h307, hp_0 = 0;
							h < h307 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 64
							// T (x, 14) (14 / 1)
							for (x = x511, xp_1 = x511_p_0, xp_0 = 0;
								x < x511 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_5333 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_5334 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_5335 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_5336 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_5337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_5338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_5339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_5340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_5341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_5342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_5343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_5344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_5345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_5346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_5347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_5348 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_5349 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_5350 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_5351 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_5352 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_5353 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_5354 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_5355 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_5356 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
											c < c546 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5333);
											mem_vec_5333 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5334);
											mem_vec_5334 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5335);
											mem_vec_5335 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5336);
											mem_vec_5336 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5337);
											mem_vec_5337 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5338);
											mem_vec_5338 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5339);
											mem_vec_5339 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5340);
											mem_vec_5340 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5341);
											mem_vec_5341 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5342);
											mem_vec_5342 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5343);
											mem_vec_5343 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5344);
											mem_vec_5344 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5345);
											mem_vec_5345 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5346);
											mem_vec_5346 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5347);
											mem_vec_5347 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5348);
											mem_vec_5348 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5349);
											mem_vec_5349 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5350);
											mem_vec_5350 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5351);
											mem_vec_5351 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5352);
											mem_vec_5352 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5353);
											mem_vec_5353 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5354);
											mem_vec_5354 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5355);
											mem_vec_5355 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5356);
											mem_vec_5356 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_5333);
											mem_vec_5333 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_5334);
											mem_vec_5334 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_5335);
											mem_vec_5335 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_5336);
											mem_vec_5336 = vec_41;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_5337);
											mem_vec_5337 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_5338);
											mem_vec_5338 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_5339);
											mem_vec_5339 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_5340);
											mem_vec_5340 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_5341);
											mem_vec_5341 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_5342);
											mem_vec_5342 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_5343);
											mem_vec_5343 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_5344);
											mem_vec_5344 = vec_52;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_5345);
											mem_vec_5345 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_5346);
											mem_vec_5346 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_5347);
											mem_vec_5347 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_5348);
											mem_vec_5348 = vec_57;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_5349);
											mem_vec_5349 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_5350);
											mem_vec_5350 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_5351);
											mem_vec_5351 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_5352);
											mem_vec_5352 = vec_62;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_5353);
											mem_vec_5353 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_5354);
											mem_vec_5354 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_5355);
											mem_vec_5355 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_5356);
											mem_vec_5356 = vec_67;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_5333);
											mem_vec_5333 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_5334);
											mem_vec_5334 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_5335);
											mem_vec_5335 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_5336);
											mem_vec_5336 = vec_75;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_5337);
											mem_vec_5337 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_5338);
											mem_vec_5338 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_5339);
											mem_vec_5339 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_5340);
											mem_vec_5340 = vec_81;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_5341);
											mem_vec_5341 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_5342);
											mem_vec_5342 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_5343);
											mem_vec_5343 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_5344);
											mem_vec_5344 = vec_86;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_5345);
											mem_vec_5345 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_5346);
											mem_vec_5346 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_5347);
											mem_vec_5347 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_5348);
											mem_vec_5348 = vec_91;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_5349);
											mem_vec_5349 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_5350);
											mem_vec_5350 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_5351);
											mem_vec_5351 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_5352);
											mem_vec_5352 = vec_96;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_5353);
											mem_vec_5353 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_5354);
											mem_vec_5354 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_5355);
											mem_vec_5355 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_5356);
											mem_vec_5356 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5335);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5336);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5337);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5338);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5339);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5340);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5341);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5342);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5343);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5344);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5345);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5346);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5347);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5348);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5349);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5350);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5351);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5352);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5353);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5354);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5355);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5356);
							}
						}
					}
				}
			}
		}
}


}