#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (4, f);
  T (4, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1104_p_0, cp_1, c1104, f, fp_0, w, wp_0, x, xp_0, x1418_p_0, x1419_p_0, xp_1, x1418_p_1, xp_2, x1418, x1419, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y736 = 0;
IND_TYPE x1420 = 0;
IND_TYPE h = 0;
IND_TYPE w706 = 0;
IND_TYPE c1105 = 0;
IND_TYPE f736 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14260 ,mem_vec_14261 ,mem_vec_14262 ,mem_vec_14263 ,mem_vec_14264 ,mem_vec_14265 ,mem_vec_14266 ,mem_vec_14267 ,mem_vec_14268 ,mem_vec_14269 ,mem_vec_14270 ,mem_vec_14271 ,mem_vec_14272 ,mem_vec_14273 ,mem_vec_14274 ,mem_vec_14275 ,mem_vec_14276 ,mem_vec_14277 ,mem_vec_14278 ,mem_vec_14279 ,mem_vec_14280 ,mem_vec_14281 ,mem_vec_14282 ,mem_vec_14283 ,mem_vec_14284 ,mem_vec_14285 ,mem_vec_14286 ,mem_vec_14287 ,mem_vec_14288 ,mem_vec_14289 ,mem_vec_14290 ,mem_vec_14291 ,mem_vec_14292 ,mem_vec_14293 ,mem_vec_14294 ,mem_vec_14295 ,mem_vec_14296 ,mem_vec_14297 ,mem_vec_14298 ,mem_vec_14299 ,mem_vec_14300 ,mem_vec_14301 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (136 / 68)
for (x1419 = x1420, x1419_p_0 = 0;
	x1419 < x1420 + 136;
	x1419 += 68, x1419_p_0 += 68){
	// y = 136, x = 68, h = 3, w = 3, c = 64, f = 128
	// T (c, 4) (64 / 16)
	for (c1104 = c1105, c1104_p_0 = 0;
		c1104 < c1105 + 64;
		c1104 += 16, c1104_p_0 += 16){
		// y = 136, x = 68, h = 3, w = 3, c = 16, f = 128
		// T (f, 4) (128 / 32)
		for (f = f736, fp_0 = 0;
			f < f736 + 128;
			f += 32, fp_0 += 32){
				for (y = y736, yp_0 = 0;
					y < y736 + 70;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 68, h = 3, w = 3, c = 16, f = 32
					// T (x, 4) (68 / 17)
					for (x1418 = x1419, x1418_p_1 = x1419_p_0, x1418_p_0 = 0;
						x1418 < x1419 + 68;
						x1418 += 17, x1418_p_1 += 17, x1418_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w706, wp_0 = 0;
							w < w706 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
							// T (x, 17) (17 / 1)
							for (x = x1418, xp_2 = x1418_p_1, xp_1 = x1418_p_0, xp_0 = 0;
								x < x1418 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_14260 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_14261 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_14262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_14263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_14264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_14265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_14266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_14267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_14268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_14269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_14270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_14271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_14272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_14273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_14274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_14275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_14276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_14277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_14278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_14279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c1104, cp_1 = c1104_p_0, cp_0 = 0;
											c < c1104 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14260);
											mem_vec_14260 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14261);
											mem_vec_14261 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14262);
											mem_vec_14262 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14263);
											mem_vec_14263 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14264);
											mem_vec_14264 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14265);
											mem_vec_14265 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14266);
											mem_vec_14266 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14267);
											mem_vec_14267 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14268);
											mem_vec_14268 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14269);
											mem_vec_14269 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14270);
											mem_vec_14270 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14271);
											mem_vec_14271 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14272);
											mem_vec_14272 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14273);
											mem_vec_14273 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14274);
											mem_vec_14274 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14275);
											mem_vec_14275 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14276);
											mem_vec_14276 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14277);
											mem_vec_14277 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14278);
											mem_vec_14278 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14279);
											mem_vec_14279 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_14260);
											mem_vec_14260 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_14261);
											mem_vec_14261 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_14262);
											mem_vec_14262 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_14263);
											mem_vec_14263 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_14264);
											mem_vec_14264 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_14265);
											mem_vec_14265 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_14266);
											mem_vec_14266 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14267);
											mem_vec_14267 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_14268);
											mem_vec_14268 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_14269);
											mem_vec_14269 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_14270);
											mem_vec_14270 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_14271);
											mem_vec_14271 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_14272);
											mem_vec_14272 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_14273);
											mem_vec_14273 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_14274);
											mem_vec_14274 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_14275);
											mem_vec_14275 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_14276);
											mem_vec_14276 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14277);
											mem_vec_14277 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_14278);
											mem_vec_14278 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_14279);
											mem_vec_14279 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_14260);
											mem_vec_14260 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_14261);
											mem_vec_14261 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_14262);
											mem_vec_14262 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_14263);
											mem_vec_14263 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_14264);
											mem_vec_14264 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_14265);
											mem_vec_14265 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_14266);
											mem_vec_14266 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_14267);
											mem_vec_14267 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_14268);
											mem_vec_14268 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_14269);
											mem_vec_14269 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_14270);
											mem_vec_14270 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_14271);
											mem_vec_14271 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_14272);
											mem_vec_14272 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_14273);
											mem_vec_14273 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_14274);
											mem_vec_14274 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_14275);
											mem_vec_14275 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_14276);
											mem_vec_14276 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_14277);
											mem_vec_14277 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_14278);
											mem_vec_14278 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_14279);
											mem_vec_14279 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14261);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14262);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14263);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14264);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14265);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14266);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14267);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14268);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14269);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14270);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14271);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14272);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14273);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14274);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14275);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14276);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14277);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14278);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14279);
							}
						}
					}
				}
				for (y = y736 + 70, yp_0 = 0;
					y < y736 + 70 + 66;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 68, h = 3, w = 3, c = 16, f = 32
					// T (x, 4) (68 / 17)
					for (x1418 = x1419, x1418_p_1 = x1419_p_0, x1418_p_0 = 0;
						x1418 < x1419 + 68;
						x1418 += 17, x1418_p_1 += 17, x1418_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w706, wp_0 = 0;
							w < w706 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
							// T (x, 17) (17 / 1)
							for (x = x1418, xp_2 = x1418_p_1, xp_1 = x1418_p_0, xp_0 = 0;
								x < x1418 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_14280 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_14281 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_14282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_14283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_14284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_14285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_14286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_14287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_14288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_14289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_14290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_14291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_14292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_14293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_14294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_14295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_14296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_14297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_14298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_14299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_14300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_14301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c1104, cp_1 = c1104_p_0, cp_0 = 0;
											c < c1104 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14280);
											mem_vec_14280 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14281);
											mem_vec_14281 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14282);
											mem_vec_14282 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14283);
											mem_vec_14283 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14284);
											mem_vec_14284 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14285);
											mem_vec_14285 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14286);
											mem_vec_14286 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14287);
											mem_vec_14287 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14288);
											mem_vec_14288 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14289);
											mem_vec_14289 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14290);
											mem_vec_14290 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14291);
											mem_vec_14291 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14292);
											mem_vec_14292 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14293);
											mem_vec_14293 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14294);
											mem_vec_14294 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14295);
											mem_vec_14295 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14296);
											mem_vec_14296 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14297);
											mem_vec_14297 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14298);
											mem_vec_14298 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14299);
											mem_vec_14299 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14300);
											mem_vec_14300 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14301);
											mem_vec_14301 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_14280);
											mem_vec_14280 = vec_35;

											vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_14281);
											mem_vec_14281 = vec_38;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_14282);
											mem_vec_14282 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_14283);
											mem_vec_14283 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_14284);
											mem_vec_14284 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_14285);
											mem_vec_14285 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_14286);
											mem_vec_14286 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_14287);
											mem_vec_14287 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_14288);
											mem_vec_14288 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_14289);
											mem_vec_14289 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_14290);
											mem_vec_14290 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_14291);
											mem_vec_14291 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_14292);
											mem_vec_14292 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_14293);
											mem_vec_14293 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_14294);
											mem_vec_14294 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_14295);
											mem_vec_14295 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_14296);
											mem_vec_14296 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_14297);
											mem_vec_14297 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_14298);
											mem_vec_14298 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_14299);
											mem_vec_14299 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_14300);
											mem_vec_14300 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_14301);
											mem_vec_14301 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_14280);
											mem_vec_14280 = vec_70;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_14281);
											mem_vec_14281 = vec_73;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_14282);
											mem_vec_14282 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_14283);
											mem_vec_14283 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_14284);
											mem_vec_14284 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_14285);
											mem_vec_14285 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_14286);
											mem_vec_14286 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_14287);
											mem_vec_14287 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_14288);
											mem_vec_14288 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_14289);
											mem_vec_14289 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_14290);
											mem_vec_14290 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_14291);
											mem_vec_14291 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_14292);
											mem_vec_14292 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_14293);
											mem_vec_14293 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_14294);
											mem_vec_14294 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_14295);
											mem_vec_14295 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_14296);
											mem_vec_14296 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_14297);
											mem_vec_14297 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_14298);
											mem_vec_14298 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_14299);
											mem_vec_14299 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_14300);
											mem_vec_14300 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_14301);
											mem_vec_14301 = vec_104;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14280);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14281);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14282);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14283);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14284);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14285);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14286);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14287);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14293);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14294);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14295);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14299);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14300);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14301);
							}
						}
					}
				}
		}
	}
}


}