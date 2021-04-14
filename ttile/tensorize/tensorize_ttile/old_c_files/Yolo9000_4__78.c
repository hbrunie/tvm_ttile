#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (68, x);
  T (3, w); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (4, f);
  T (64, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1086_p_0, cp_1, c1086, f, fp_0, w, wp_0, x, xp_0, x1394_p_0, x1395_p_0, xp_1, x1394_p_1, xp_2, x1394, x1395, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y724 = 0;
IND_TYPE x1396 = 0;
IND_TYPE h = 0;
IND_TYPE w694 = 0;
IND_TYPE c1087 = 0;
IND_TYPE f724 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14008 ,mem_vec_14009 ,mem_vec_14010 ,mem_vec_14011 ,mem_vec_14012 ,mem_vec_14013 ,mem_vec_14014 ,mem_vec_14015 ,mem_vec_14016 ,mem_vec_14017 ,mem_vec_14018 ,mem_vec_14019 ,mem_vec_14020 ,mem_vec_14021 ,mem_vec_14022 ,mem_vec_14023 ,mem_vec_14024 ,mem_vec_14025 ,mem_vec_14026 ,mem_vec_14027 ,mem_vec_14028 ,mem_vec_14029 ,mem_vec_14030 ,mem_vec_14031 ,mem_vec_14032 ,mem_vec_14033 ,mem_vec_14034 ,mem_vec_14035 ,mem_vec_14036 ,mem_vec_14037 ,mem_vec_14038 ,mem_vec_14039 ,mem_vec_14040 ,mem_vec_14041 ,mem_vec_14042 ,mem_vec_14043 ,mem_vec_14044 ,mem_vec_14045 ,mem_vec_14046 ,mem_vec_14047 ,mem_vec_14048 ,mem_vec_14049 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x1395 = x1396, x1395_p_0 = 0;
	x1395 < x1396 + 136;
	x1395 += 136, x1395_p_0 += 136){
	// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
	// T (c, 64) (64 / 1)
	for (c1086 = c1087, c1086_p_0 = 0;
		c1086 < c1087 + 64;
		c1086 += 1, c1086_p_0 += 1){
		// y = 136, x = 136, h = 3, w = 3, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f724, fp_0 = 0;
			f < f724 + 128;
			f += 32, fp_0 += 32){
				for (y = y724, yp_0 = 0;
					y < y724 + 70;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 136, h = 3, w = 3, c = 1, f = 32
					// T (x, 2) (136 / 68)
					for (x1394 = x1395, x1394_p_1 = x1395_p_0, x1394_p_0 = 0;
						x1394 < x1395 + 136;
						x1394 += 68, x1394_p_1 += 68, x1394_p_0 += 68){
						// y = ph_y, x = 68, h = 3, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w694, wp_0 = 0;
							w < w694 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 68, h = 3, w = 1, c = 1, f = 32
							// T (x, 68) (68 / 1)
							for (x = x1394, xp_2 = x1394_p_1, xp_1 = x1394_p_0, xp_0 = 0;
								x < x1394 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_14008 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_14009 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_14010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_14011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_14012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_14013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_14014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_14015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_14016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_14017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_14018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_14019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_14020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_14021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_14022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_14023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_14024 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_14025 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_14026 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_14027 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c1086, cp_1 = c1086_p_0, cp_0 = 0;
											c < c1086 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14008);
											mem_vec_14008 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14009);
											mem_vec_14009 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14010);
											mem_vec_14010 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14011);
											mem_vec_14011 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14012);
											mem_vec_14012 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14013);
											mem_vec_14013 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14014);
											mem_vec_14014 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14015);
											mem_vec_14015 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14016);
											mem_vec_14016 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14017);
											mem_vec_14017 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14018);
											mem_vec_14018 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14019);
											mem_vec_14019 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14020);
											mem_vec_14020 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14021);
											mem_vec_14021 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14022);
											mem_vec_14022 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14023);
											mem_vec_14023 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14024);
											mem_vec_14024 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14025);
											mem_vec_14025 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14026);
											mem_vec_14026 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14027);
											mem_vec_14027 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_14008);
											mem_vec_14008 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_14009);
											mem_vec_14009 = vec_35;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_14010);
											mem_vec_14010 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_14011);
											mem_vec_14011 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_14012);
											mem_vec_14012 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_14013);
											mem_vec_14013 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_14014);
											mem_vec_14014 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14015);
											mem_vec_14015 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_14016);
											mem_vec_14016 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_14017);
											mem_vec_14017 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_14018);
											mem_vec_14018 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_14019);
											mem_vec_14019 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_14020);
											mem_vec_14020 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_14021);
											mem_vec_14021 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_14022);
											mem_vec_14022 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_14023);
											mem_vec_14023 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_14024);
											mem_vec_14024 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14025);
											mem_vec_14025 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_14026);
											mem_vec_14026 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_14027);
											mem_vec_14027 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_14008);
											mem_vec_14008 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_14009);
											mem_vec_14009 = vec_67;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_14010);
											mem_vec_14010 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_14011);
											mem_vec_14011 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_14012);
											mem_vec_14012 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_14013);
											mem_vec_14013 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_14014);
											mem_vec_14014 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_14015);
											mem_vec_14015 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_14016);
											mem_vec_14016 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_14017);
											mem_vec_14017 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_14018);
											mem_vec_14018 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_14019);
											mem_vec_14019 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_14020);
											mem_vec_14020 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_14021);
											mem_vec_14021 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_14022);
											mem_vec_14022 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_14023);
											mem_vec_14023 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_14024);
											mem_vec_14024 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_14025);
											mem_vec_14025 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_14026);
											mem_vec_14026 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_14027);
											mem_vec_14027 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14008);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14009);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14010);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14011);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14012);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14013);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14014);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14015);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14016);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14017);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14018);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14019);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14020);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14021);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14022);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14023);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14024);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14025);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14026);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14027);
							}
						}
					}
				}
				for (y = y724 + 70, yp_0 = 0;
					y < y724 + 70 + 66;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 136, h = 3, w = 3, c = 1, f = 32
					// T (x, 2) (136 / 68)
					for (x1394 = x1395, x1394_p_1 = x1395_p_0, x1394_p_0 = 0;
						x1394 < x1395 + 136;
						x1394 += 68, x1394_p_1 += 68, x1394_p_0 += 68){
						// y = ph_y, x = 68, h = 3, w = 3, c = 1, f = 32
						// T (w, 3) (3 / 1)
						for (w = w694, wp_0 = 0;
							w < w694 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 68, h = 3, w = 1, c = 1, f = 32
							// T (x, 68) (68 / 1)
							for (x = x1394, xp_2 = x1394_p_1, xp_1 = x1394_p_0, xp_0 = 0;
								x < x1394 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_14028 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_14029 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_14030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_14031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_14032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_14033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_14034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_14035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_14036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_14037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_14038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_14039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_14040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_14041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_14042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_14043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_14044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_14045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_14046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_14047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_14048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_14049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
										// T (c, 1) (1 / 1)
										for (c = c1086, cp_1 = c1086_p_0, cp_0 = 0;
											c < c1086 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14028);
											mem_vec_14028 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14029);
											mem_vec_14029 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14030);
											mem_vec_14030 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14031);
											mem_vec_14031 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14032);
											mem_vec_14032 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14033);
											mem_vec_14033 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14034);
											mem_vec_14034 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14035);
											mem_vec_14035 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14036);
											mem_vec_14036 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14037);
											mem_vec_14037 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14038);
											mem_vec_14038 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14039);
											mem_vec_14039 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14040);
											mem_vec_14040 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14041);
											mem_vec_14041 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14042);
											mem_vec_14042 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14043);
											mem_vec_14043 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14044);
											mem_vec_14044 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14045);
											mem_vec_14045 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14046);
											mem_vec_14046 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14047);
											mem_vec_14047 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14048);
											mem_vec_14048 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14049);
											mem_vec_14049 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_14028);
											mem_vec_14028 = vec_35;

											vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_14029);
											mem_vec_14029 = vec_38;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_14030);
											mem_vec_14030 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_14031);
											mem_vec_14031 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_14032);
											mem_vec_14032 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_14033);
											mem_vec_14033 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_14034);
											mem_vec_14034 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_14035);
											mem_vec_14035 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_14036);
											mem_vec_14036 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_14037);
											mem_vec_14037 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_14038);
											mem_vec_14038 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_14039);
											mem_vec_14039 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_14040);
											mem_vec_14040 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_14041);
											mem_vec_14041 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_14042);
											mem_vec_14042 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_14043);
											mem_vec_14043 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_14044);
											mem_vec_14044 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_14045);
											mem_vec_14045 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_14046);
											mem_vec_14046 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_14047);
											mem_vec_14047 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_14048);
											mem_vec_14048 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_14049);
											mem_vec_14049 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_14028);
											mem_vec_14028 = vec_70;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_14029);
											mem_vec_14029 = vec_73;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_14030);
											mem_vec_14030 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_14031);
											mem_vec_14031 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_14032);
											mem_vec_14032 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_14033);
											mem_vec_14033 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_14034);
											mem_vec_14034 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_14035);
											mem_vec_14035 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_14036);
											mem_vec_14036 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_14037);
											mem_vec_14037 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_14038);
											mem_vec_14038 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_14039);
											mem_vec_14039 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_14040);
											mem_vec_14040 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_14041);
											mem_vec_14041 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_14042);
											mem_vec_14042 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_14043);
											mem_vec_14043 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_14044);
											mem_vec_14044 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_14045);
											mem_vec_14045 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_14046);
											mem_vec_14046 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_14047);
											mem_vec_14047 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_14048);
											mem_vec_14048 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_14049);
											mem_vec_14049 = vec_104;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14028);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14029);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14030);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14031);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14032);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14033);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14034);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14035);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14036);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14037);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14038);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14039);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14040);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14041);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14042);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14043);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14044);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14045);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14046);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14047);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14048);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14049);
							}
						}
					}
				}
		}
	}
}


}