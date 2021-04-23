#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (32, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (2, c); T (1, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, f)]
*/
IND_TYPE c, cp_0, c546_p_0, cp_1, c546, f, fp_0, f546_p_0, fp_1, f546, h, hp_0, x, xp_0, x528_p_0, xp_1, x528, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y364 = 0;
IND_TYPE x529 = 0;
IND_TYPE h326 = 0;
IND_TYPE w = 0;
IND_TYPE c547 = 0;
IND_TYPE f547 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6286 ,mem_vec_6287 ,mem_vec_6288 ,mem_vec_6289 ,mem_vec_6290 ,mem_vec_6291 ,mem_vec_6292 ,mem_vec_6293 ,mem_vec_6294 ,mem_vec_6295 ,mem_vec_6296 ,mem_vec_6297 ,mem_vec_6298 ,mem_vec_6299 ,mem_vec_6300 ,mem_vec_6301 ,mem_vec_6302 ,mem_vec_6303 ,mem_vec_6304 ,mem_vec_6305 ,mem_vec_6306 ,mem_vec_6307 ,mem_vec_6308 ,mem_vec_6309 ,mem_vec_6310 ,mem_vec_6311 ,mem_vec_6312 ,mem_vec_6313 ,mem_vec_6314 ,mem_vec_6315 ,mem_vec_6316 ,mem_vec_6317 ,mem_vec_6318 ,mem_vec_6319 ,mem_vec_6320 ,mem_vec_6321 ,mem_vec_6322 ,mem_vec_6323 ,mem_vec_6324 ,mem_vec_6325 ,mem_vec_6326 ,mem_vec_6327 ,mem_vec_6328 ,mem_vec_6329 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f546 = f547, f546_p_0 = 0;
	f546 < f547 + 128;
	f546 += 64, f546_p_0 += 64){
		for (y = y364, yp_0 = 0;
			y < y364 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (28 / 28)
			for (x528 = x529, x528_p_0 = 0;
				x528 < x529 + 28;
				x528 += 28, x528_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (f, 1) (64 / 64)
				for (f = f546, fp_1 = f546_p_0, fp_0 = 0;
					f < f546 + 64;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
					// T (c, 2) (64 / 32)
					for (c546 = c547, c546_p_0 = 0;
						c546 < c547 + 64;
						c546 += 32, c546_p_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h326, hp_0 = 0;
							h < h326 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 32, f = 64
							// T (x, 28) (28 / 1)
							for (x = x528, xp_1 = x528_p_0, xp_0 = 0;
								x < x528 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6286 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6287 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6288 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6289 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_6290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_6294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_6298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_6302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
											c < c546 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6286);
											mem_vec_6286 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6287);
											mem_vec_6287 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6288);
											mem_vec_6288 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6289);
											mem_vec_6289 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6290);
											mem_vec_6290 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6291);
											mem_vec_6291 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6292);
											mem_vec_6292 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6293);
											mem_vec_6293 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6294);
											mem_vec_6294 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6295);
											mem_vec_6295 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6296);
											mem_vec_6296 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6297);
											mem_vec_6297 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6298);
											mem_vec_6298 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6299);
											mem_vec_6299 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6300);
											mem_vec_6300 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6301);
											mem_vec_6301 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6302);
											mem_vec_6302 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6303);
											mem_vec_6303 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6304);
											mem_vec_6304 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6305);
											mem_vec_6305 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6286);
											mem_vec_6286 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_6287);
											mem_vec_6287 = vec_32;

											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_6288);
											mem_vec_6288 = vec_34;

											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_6289);
											mem_vec_6289 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_6290);
											mem_vec_6290 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_6291);
											mem_vec_6291 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_6292);
											mem_vec_6292 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_6293);
											mem_vec_6293 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_6294);
											mem_vec_6294 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_6295);
											mem_vec_6295 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_6296);
											mem_vec_6296 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_6297);
											mem_vec_6297 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_6298);
											mem_vec_6298 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_6299);
											mem_vec_6299 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_6300);
											mem_vec_6300 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_6301);
											mem_vec_6301 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_6302);
											mem_vec_6302 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_6303);
											mem_vec_6303 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_6304);
											mem_vec_6304 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_6305);
											mem_vec_6305 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6286);
											mem_vec_6286 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_6287);
											mem_vec_6287 = vec_61;

											vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_6288);
											mem_vec_6288 = vec_63;

											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_6289);
											mem_vec_6289 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_6290);
											mem_vec_6290 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_6291);
											mem_vec_6291 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_6292);
											mem_vec_6292 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_6293);
											mem_vec_6293 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_73 = _mm512_set1_ps(scal_12);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_6294);
											mem_vec_6294 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_6295);
											mem_vec_6295 = vec_74;



											vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_6296);
											mem_vec_6296 = vec_75;



											vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_6297);
											mem_vec_6297 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_6298);
											mem_vec_6298 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_6299);
											mem_vec_6299 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_6300);
											mem_vec_6300 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_6301);
											mem_vec_6301 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_6302);
											mem_vec_6302 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_6303);
											mem_vec_6303 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_6304);
											mem_vec_6304 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_6305);
											mem_vec_6305 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6286);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6287);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6293);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6294);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6295);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6299);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6300);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6301);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6302);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6303);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6304);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6305);
							}
						}
					}
				}
			}
		}
		for (y = y364 + 10, yp_0 = 0;
			y < y364 + 10 + 18;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (28 / 28)
			for (x528 = x529, x528_p_0 = 0;
				x528 < x529 + 28;
				x528 += 28, x528_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (f, 1) (64 / 64)
				for (f = f546, fp_1 = f546_p_0, fp_0 = 0;
					f < f546 + 64;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 64
					// T (c, 2) (64 / 32)
					for (c546 = c547, c546_p_0 = 0;
						c546 < c547 + 64;
						c546 += 32, c546_p_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h326, hp_0 = 0;
							h < h326 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 32, f = 64
							// T (x, 28) (28 / 1)
							for (x = x528, xp_1 = x528_p_0, xp_0 = 0;
								x < x528 + 28;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_6306 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_6307 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_6308 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_6309 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_6310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_6311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_6312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_6313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_6314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_6315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_6316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_6317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_6318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_6319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_6320 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_6321 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_6322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_6323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_6324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_6325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_6326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_6327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_6328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_6329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c546, cp_1 = c546_p_0, cp_0 = 0;
											c < c546 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6306);
											mem_vec_6306 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6307);
											mem_vec_6307 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6308);
											mem_vec_6308 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6309);
											mem_vec_6309 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6310);
											mem_vec_6310 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6311);
											mem_vec_6311 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6312);
											mem_vec_6312 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6313);
											mem_vec_6313 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6314);
											mem_vec_6314 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6315);
											mem_vec_6315 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6316);
											mem_vec_6316 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6317);
											mem_vec_6317 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6318);
											mem_vec_6318 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6319);
											mem_vec_6319 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6320);
											mem_vec_6320 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6321);
											mem_vec_6321 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6322);
											mem_vec_6322 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6323);
											mem_vec_6323 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6324);
											mem_vec_6324 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6325);
											mem_vec_6325 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6326);
											mem_vec_6326 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6327);
											mem_vec_6327 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_6328);
											mem_vec_6328 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_6329);
											mem_vec_6329 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_6306);
											mem_vec_6306 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_6307);
											mem_vec_6307 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_6308);
											mem_vec_6308 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_6309);
											mem_vec_6309 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_6310);
											mem_vec_6310 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_6311);
											mem_vec_6311 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_6312);
											mem_vec_6312 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_6313);
											mem_vec_6313 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_6314);
											mem_vec_6314 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_6315);
											mem_vec_6315 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_6316);
											mem_vec_6316 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_6317);
											mem_vec_6317 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_6318);
											mem_vec_6318 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_6319);
											mem_vec_6319 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_6320);
											mem_vec_6320 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_6321);
											mem_vec_6321 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_6322);
											mem_vec_6322 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_6323);
											mem_vec_6323 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_6324);
											mem_vec_6324 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_6325);
											mem_vec_6325 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_6326);
											mem_vec_6326 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_6327);
											mem_vec_6327 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_6328);
											mem_vec_6328 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_6329);
											mem_vec_6329 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_6306);
											mem_vec_6306 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_6307);
											mem_vec_6307 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_6308);
											mem_vec_6308 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_6309);
											mem_vec_6309 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_6310);
											mem_vec_6310 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_6311);
											mem_vec_6311 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_6312);
											mem_vec_6312 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_6313);
											mem_vec_6313 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_6314);
											mem_vec_6314 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_6315);
											mem_vec_6315 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_6316);
											mem_vec_6316 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_6317);
											mem_vec_6317 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_6318);
											mem_vec_6318 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_6319);
											mem_vec_6319 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_6320);
											mem_vec_6320 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_6321);
											mem_vec_6321 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_6322);
											mem_vec_6322 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_6323);
											mem_vec_6323 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_6324);
											mem_vec_6324 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_6325);
											mem_vec_6325 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_6326);
											mem_vec_6326 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_6327);
											mem_vec_6327 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_6328);
											mem_vec_6328 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_6329);
											mem_vec_6329 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6306);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6307);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6308);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6309);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6310);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6311);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6312);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6315);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6316);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6317);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6318);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6319);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6327);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_6328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_6329);
							}
						}
					}
				}
			}
		}
}


}