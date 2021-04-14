#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (4, x);
  Lambda_apply y [((Iter 9), (Arg 9)); ((Iter 5), (Arg 11))]; T (4, f);
  T (1, c); T (34, x)]
*/
IND_TYPE c, cp_0, c1074_p_0, cp_1, c1074, f, fp_0, w, wp_0, x, xp_0, x1378_p_0, x1379_p_0, xp_1, x1378_p_1, xp_2, x1378, x1379, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y716 = 0;
IND_TYPE x1380 = 0;
IND_TYPE h = 0;
IND_TYPE w686 = 0;
IND_TYPE c1075 = 0;
IND_TYPE f716 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13844 ,mem_vec_13845 ,mem_vec_13846 ,mem_vec_13847 ,mem_vec_13848 ,mem_vec_13849 ,mem_vec_13850 ,mem_vec_13851 ,mem_vec_13852 ,mem_vec_13853 ,mem_vec_13854 ,mem_vec_13855 ,mem_vec_13856 ,mem_vec_13857 ,mem_vec_13858 ,mem_vec_13859 ,mem_vec_13860 ,mem_vec_13861 ,mem_vec_13862 ,mem_vec_13863 ,mem_vec_13864 ,mem_vec_13865 ,mem_vec_13866 ,mem_vec_13867 ,mem_vec_13868 ,mem_vec_13869 ,mem_vec_13870 ,mem_vec_13871 ,mem_vec_13872 ,mem_vec_13873 ,mem_vec_13874 ,mem_vec_13875 ,mem_vec_13876 ,mem_vec_13877 ,mem_vec_13878 ,mem_vec_13879 ,mem_vec_13880 ,mem_vec_13881 ,mem_vec_13882 ,mem_vec_13883 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 34) (136 / 4)
for (x1379 = x1380, x1379_p_0 = 0;
	x1379 < x1380 + 136;
	x1379 += 4, x1379_p_0 += 4){
	// y = 136, x = 4, h = 3, w = 3, c = 64, f = 128
	// T (c, 1) (64 / 64)
	for (c1074 = c1075, c1074_p_0 = 0;
		c1074 < c1075 + 64;
		c1074 += 64, c1074_p_0 += 64){
		// y = 136, x = 4, h = 3, w = 3, c = 64, f = 128
		// T (f, 4) (128 / 32)
		for (f = f716, fp_0 = 0;
			f < f716 + 128;
			f += 32, fp_0 += 32){
				for (y = y716, yp_0 = 0;
					y < y716 + 81;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (x, 4) (4 / 1)
					for (x1378 = x1379, x1378_p_1 = x1379_p_0, x1378_p_0 = 0;
						x1378 < x1379 + 4;
						x1378 += 1, x1378_p_1 += 1, x1378_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w686, wp_0 = 0;
							w < w686 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
							// T (x, 1) (1 / 1)
							for (x = x1378, xp_2 = x1378_p_1, xp_1 = x1378_p_0, xp_0 = 0;
								x < x1378 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_13844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_13845 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_13846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_13847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_13848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_13849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_13850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_13851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_13852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_13853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_13854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_13855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_13856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_13857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_13858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_13859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_13860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_13861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c1074, cp_1 = c1074_p_0, cp_0 = 0;
											c < c1074 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13844);
											mem_vec_13844 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13845);
											mem_vec_13845 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13846);
											mem_vec_13846 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13847);
											mem_vec_13847 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13848);
											mem_vec_13848 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13849);
											mem_vec_13849 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13850);
											mem_vec_13850 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13851);
											mem_vec_13851 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13852);
											mem_vec_13852 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13853);
											mem_vec_13853 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13854);
											mem_vec_13854 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13855);
											mem_vec_13855 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13856);
											mem_vec_13856 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13857);
											mem_vec_13857 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13858);
											mem_vec_13858 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13859);
											mem_vec_13859 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13860);
											mem_vec_13860 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13861);
											mem_vec_13861 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_13844);
											mem_vec_13844 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_13845);
											mem_vec_13845 = vec_32;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_13846);
											mem_vec_13846 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_13847);
											mem_vec_13847 = vec_36;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_13848);
											mem_vec_13848 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_13849);
											mem_vec_13849 = vec_39;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_13850);
											mem_vec_13850 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_13851);
											mem_vec_13851 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_13852);
											mem_vec_13852 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_13853);
											mem_vec_13853 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_13854);
											mem_vec_13854 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_13855);
											mem_vec_13855 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_13856);
											mem_vec_13856 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_13857);
											mem_vec_13857 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_13858);
											mem_vec_13858 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_13859);
											mem_vec_13859 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_13860);
											mem_vec_13860 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_13861);
											mem_vec_13861 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_13844);
											mem_vec_13844 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_13845);
											mem_vec_13845 = vec_61;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_13846);
											mem_vec_13846 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_13847);
											mem_vec_13847 = vec_65;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_13848);
											mem_vec_13848 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_13849);
											mem_vec_13849 = vec_68;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_13850);
											mem_vec_13850 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_13851);
											mem_vec_13851 = vec_71;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_13852);
											mem_vec_13852 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_13853);
											mem_vec_13853 = vec_74;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_13854);
											mem_vec_13854 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_13855);
											mem_vec_13855 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_13856);
											mem_vec_13856 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_13857);
											mem_vec_13857 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_13858);
											mem_vec_13858 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_13859);
											mem_vec_13859 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_13860);
											mem_vec_13860 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_13861);
											mem_vec_13861 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13861);
							}
						}
					}
				}
				for (y = y716 + 81, yp_0 = 0;
					y < y716 + 81 + 55;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (x, 4) (4 / 1)
					for (x1378 = x1379, x1378_p_1 = x1379_p_0, x1378_p_0 = 0;
						x1378 < x1379 + 4;
						x1378 += 1, x1378_p_1 += 1, x1378_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w686, wp_0 = 0;
							w < w686 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
							// T (x, 1) (1 / 1)
							for (x = x1378, xp_2 = x1378_p_1, xp_1 = x1378_p_0, xp_0 = 0;
								x < x1378 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_13862 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_13863 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_13864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_13865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_13866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_13867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_13868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_13869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_13870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_13871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_13872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_13873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_13874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_13875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_13876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_13877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_13878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_13879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_13880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_13881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_13882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_13883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c1074, cp_1 = c1074_p_0, cp_0 = 0;
											c < c1074 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13862);
											mem_vec_13862 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13863);
											mem_vec_13863 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13864);
											mem_vec_13864 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13865);
											mem_vec_13865 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13866);
											mem_vec_13866 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13867);
											mem_vec_13867 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13868);
											mem_vec_13868 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13869);
											mem_vec_13869 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13870);
											mem_vec_13870 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13871);
											mem_vec_13871 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13872);
											mem_vec_13872 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13873);
											mem_vec_13873 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13874);
											mem_vec_13874 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13875);
											mem_vec_13875 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13876);
											mem_vec_13876 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13877);
											mem_vec_13877 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13878);
											mem_vec_13878 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13879);
											mem_vec_13879 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13880);
											mem_vec_13880 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13881);
											mem_vec_13881 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13882);
											mem_vec_13882 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13883);
											mem_vec_13883 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_36 = _mm512_set1_ps(scal_11);
											vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_13862);
											mem_vec_13862 = vec_35;

											vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_13863);
											mem_vec_13863 = vec_38;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_37, mem_vec_13864);
											mem_vec_13864 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_39, mem_vec_13865);
											mem_vec_13865 = vec_42;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_13866);
											mem_vec_13866 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_39, mem_vec_13867);
											mem_vec_13867 = vec_45;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_37, mem_vec_13868);
											mem_vec_13868 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_39, mem_vec_13869);
											mem_vec_13869 = vec_48;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_37, mem_vec_13870);
											mem_vec_13870 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_39, mem_vec_13871);
											mem_vec_13871 = vec_51;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_13872);
											mem_vec_13872 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_13873);
											mem_vec_13873 = vec_54;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_37, mem_vec_13874);
											mem_vec_13874 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_39, mem_vec_13875);
											mem_vec_13875 = vec_57;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_37, mem_vec_13876);
											mem_vec_13876 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_39, mem_vec_13877);
											mem_vec_13877 = vec_60;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_13878);
											mem_vec_13878 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_13879);
											mem_vec_13879 = vec_63;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
											vec_65 = _mm512_set1_ps(scal_20);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_37, mem_vec_13880);
											mem_vec_13880 = vec_64;



											vec_66 = _mm512_fmadd_ps(vec_65, vec_39, mem_vec_13881);
											mem_vec_13881 = vec_66;
											scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_21);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_37, mem_vec_13882);
											mem_vec_13882 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_39, mem_vec_13883);
											mem_vec_13883 = vec_69;
											scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_22);
											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_13862);
											mem_vec_13862 = vec_70;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_13863);
											mem_vec_13863 = vec_73;
											scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_72, mem_vec_13864);
											mem_vec_13864 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_13865);
											mem_vec_13865 = vec_77;
											scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_72, mem_vec_13866);
											mem_vec_13866 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_74, mem_vec_13867);
											mem_vec_13867 = vec_80;
											scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_72, mem_vec_13868);
											mem_vec_13868 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_74, mem_vec_13869);
											mem_vec_13869 = vec_83;
											scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_72, mem_vec_13870);
											mem_vec_13870 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_74, mem_vec_13871);
											mem_vec_13871 = vec_86;
											scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_13872);
											mem_vec_13872 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_13873);
											mem_vec_13873 = vec_89;
											scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_72, mem_vec_13874);
											mem_vec_13874 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_74, mem_vec_13875);
											mem_vec_13875 = vec_92;
											scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_72, mem_vec_13876);
											mem_vec_13876 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_74, mem_vec_13877);
											mem_vec_13877 = vec_95;
											scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
											vec_97 = _mm512_set1_ps(scal_30);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_13878);
											mem_vec_13878 = vec_96;



											vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_13879);
											mem_vec_13879 = vec_98;
											scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
											vec_100 = _mm512_set1_ps(scal_31);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_72, mem_vec_13880);
											mem_vec_13880 = vec_99;



											vec_101 = _mm512_fmadd_ps(vec_100, vec_74, mem_vec_13881);
											mem_vec_13881 = vec_101;
											scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
											vec_103 = _mm512_set1_ps(scal_32);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_72, mem_vec_13882);
											mem_vec_13882 = vec_102;



											vec_104 = _mm512_fmadd_ps(vec_103, vec_74, mem_vec_13883);
											mem_vec_13883 = vec_104;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13867);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13869);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13871);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13872);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13873);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13874);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13875);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13876);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13877);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13878);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13879);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13880);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13881);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13882);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13883);
							}
						}
					}
				}
		}
	}
}


}