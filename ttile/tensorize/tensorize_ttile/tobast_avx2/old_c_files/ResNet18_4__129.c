#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (8, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (4, f);
  T (7, x)]
*/
IND_TYPE c, cp_0, c1232_p_0, cp_1, c1232, f, fp_0, h, hp_0, x, xp_0, x1470_p_0, x1471_p_0, xp_1, x1470_p_1, xp_2, x1470, x1471, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y772 = 0;
IND_TYPE x1472 = 0;
IND_TYPE h570 = 0;
IND_TYPE w = 0;
IND_TYPE c1233 = 0;
IND_TYPE f846 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11844 ,mem_vec_11845 ,mem_vec_11846 ,mem_vec_11847 ,mem_vec_11848 ,mem_vec_11849 ,mem_vec_11850 ,mem_vec_11851 ,mem_vec_11852 ,mem_vec_11853 ,mem_vec_11854 ,mem_vec_11855 ,mem_vec_11856 ,mem_vec_11857 ,mem_vec_11858 ,mem_vec_11859 ,mem_vec_11860 ,mem_vec_11861 ,mem_vec_11862 ,mem_vec_11863 ,mem_vec_11864 ,mem_vec_11865 ,mem_vec_11866 ,mem_vec_11867 ,mem_vec_11868 ,mem_vec_11869 ,mem_vec_11870 ,mem_vec_11871 ,mem_vec_11872 ,mem_vec_11873 ,mem_vec_11874 ,mem_vec_11875 ,mem_vec_11876 ,mem_vec_11877 ,mem_vec_11878 ,mem_vec_11879 ,mem_vec_11880 ,mem_vec_11881 ,mem_vec_11882 ,mem_vec_11883 ,mem_vec_11884 ,mem_vec_11885 ,mem_vec_11886 ,mem_vec_11887 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (x, 7) (28 / 4)
for (x1471 = x1472, x1471_p_0 = 0;
	x1471 < x1472 + 28;
	x1471 += 4, x1471_p_0 += 4){
	// y = 28, x = 4, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f = f846, fp_0 = 0;
		f < f846 + 128;
		f += 32, fp_0 += 32){
			for (y = y772, yp_0 = 0;
				y < y772 + 10;
				y += 5, yp_0 += 5){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (x, 1) (4 / 4)
				for (x1470 = x1471, x1470_p_1 = x1471_p_0, x1470_p_0 = 0;
					x1470 < x1471 + 4;
					x1470 += 4, x1470_p_1 += 4, x1470_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 8) (64 / 8)
					for (c1232 = c1233, c1232_p_0 = 0;
						c1232 < c1233 + 64;
						c1232 += 8, c1232_p_0 += 8){
						// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h570, hp_0 = 0;
							h < h570 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
							// T (x, 4) (4 / 1)
							for (x = x1470, xp_2 = x1470_p_1, xp_1 = x1470_p_0, xp_0 = 0;
								x < x1470 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_11844 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_11845 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_11846 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_11847 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_11848 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_11849 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_11850 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_11851 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_11852 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_11853 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_11854 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_11855 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_11856 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_11857 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_11858 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_11859 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_11860 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_11861 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_11862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_11863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1232, cp_1 = c1232_p_0, cp_0 = 0;
											c < c1232 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11844);
											mem_vec_11844 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11845);
											mem_vec_11845 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11846);
											mem_vec_11846 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11847);
											mem_vec_11847 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11848);
											mem_vec_11848 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11849);
											mem_vec_11849 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11850);
											mem_vec_11850 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11851);
											mem_vec_11851 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11852);
											mem_vec_11852 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11853);
											mem_vec_11853 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11854);
											mem_vec_11854 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11855);
											mem_vec_11855 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11856);
											mem_vec_11856 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11857);
											mem_vec_11857 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11858);
											mem_vec_11858 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11859);
											mem_vec_11859 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11860);
											mem_vec_11860 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11861);
											mem_vec_11861 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11862);
											mem_vec_11862 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11863);
											mem_vec_11863 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);
											vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11844);
											mem_vec_11844 = vec_29;

											vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11845);
											mem_vec_11845 = vec_32;

											vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11846);
											mem_vec_11846 = vec_34;

											vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11847);
											mem_vec_11847 = vec_36;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11848);
											mem_vec_11848 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11849);
											mem_vec_11849 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11850);
											mem_vec_11850 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11851);
											mem_vec_11851 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11852);
											mem_vec_11852 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11853);
											mem_vec_11853 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11854);
											mem_vec_11854 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11855);
											mem_vec_11855 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11856);
											mem_vec_11856 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11857);
											mem_vec_11857 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11858);
											mem_vec_11858 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11859);
											mem_vec_11859 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11860);
											mem_vec_11860 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11861);
											mem_vec_11861 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11862);
											mem_vec_11862 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11863);
											mem_vec_11863 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);
											vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11844);
											mem_vec_11844 = vec_58;

											vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11845);
											mem_vec_11845 = vec_61;

											vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11846);
											mem_vec_11846 = vec_63;

											vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11847);
											mem_vec_11847 = vec_65;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11848);
											mem_vec_11848 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11849);
											mem_vec_11849 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11850);
											mem_vec_11850 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11851);
											mem_vec_11851 = vec_71;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_73 = _mm256_set1_ps(scal_12);


											vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11852);
											mem_vec_11852 = vec_72;



											vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11853);
											mem_vec_11853 = vec_74;



											vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11854);
											mem_vec_11854 = vec_75;



											vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11855);
											mem_vec_11855 = vec_76;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11856);
											mem_vec_11856 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11857);
											mem_vec_11857 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11858);
											mem_vec_11858 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11859);
											mem_vec_11859 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11860);
											mem_vec_11860 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11861);
											mem_vec_11861 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11862);
											mem_vec_11862 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11863);
											mem_vec_11863 = vec_86;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11844);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11845);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11846);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11847);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11848);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11849);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11850);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11851);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11852);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11853);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11854);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11855);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11856);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11857);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11858);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11859);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11860);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11861);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11862);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11863);
							}
						}
					}
				}
			}
			for (y = y772 + 10, yp_0 = 0;
				y < y772 + 10 + 18;
				y += 6, yp_0 += 6){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (x, 1) (4 / 4)
				for (x1470 = x1471, x1470_p_1 = x1471_p_0, x1470_p_0 = 0;
					x1470 < x1471 + 4;
					x1470 += 4, x1470_p_1 += 4, x1470_p_0 += 4){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 8) (64 / 8)
					for (c1232 = c1233, c1232_p_0 = 0;
						c1232 < c1233 + 64;
						c1232 += 8, c1232_p_0 += 8){
						// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h570, hp_0 = 0;
							h < h570 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
							// T (x, 4) (4 / 1)
							for (x = x1470, xp_2 = x1470_p_1, xp_1 = x1470_p_0, xp_0 = 0;
								x < x1470 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_11864 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_11865 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_11866 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_11867 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_11868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_11869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_11870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_11871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_11872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_11873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_11874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_11875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_11876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_11877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_11878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_11879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										mem_vec_11880 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_11881 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
										mem_vec_11882 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_11883 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
										mem_vec_11884 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_11885 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
										mem_vec_11886 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_11887 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
										// T (c, 8) (8 / 1)
										for (c = c1232, cp_1 = c1232_p_0, cp_0 = 0;
											c < c1232 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11864);
											mem_vec_11864 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11865);
											mem_vec_11865 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11866);
											mem_vec_11866 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11867);
											mem_vec_11867 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11868);
											mem_vec_11868 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11869);
											mem_vec_11869 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11870);
											mem_vec_11870 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11871);
											mem_vec_11871 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11872);
											mem_vec_11872 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11873);
											mem_vec_11873 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11874);
											mem_vec_11874 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11875);
											mem_vec_11875 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11876);
											mem_vec_11876 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11877);
											mem_vec_11877 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11878);
											mem_vec_11878 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11879);
											mem_vec_11879 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);


											vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11880);
											mem_vec_11880 = vec_24;



											vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11881);
											mem_vec_11881 = vec_26;



											vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11882);
											mem_vec_11882 = vec_27;



											vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11883);
											mem_vec_11883 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm256_set1_ps(scal_5);


											vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11884);
											mem_vec_11884 = vec_29;



											vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11885);
											mem_vec_11885 = vec_31;



											vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11886);
											mem_vec_11886 = vec_32;



											vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11887);
											mem_vec_11887 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_35 = _mm256_set1_ps(scal_6);
											vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_11864);
											mem_vec_11864 = vec_34;

											vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_11865);
											mem_vec_11865 = vec_37;

											vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_11866);
											mem_vec_11866 = vec_39;

											vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_11867);
											mem_vec_11867 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_11868);
											mem_vec_11868 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_11869);
											mem_vec_11869 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_11870);
											mem_vec_11870 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_11871);
											mem_vec_11871 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);


											vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_11872);
											mem_vec_11872 = vec_48;



											vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_11873);
											mem_vec_11873 = vec_50;



											vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_11874);
											mem_vec_11874 = vec_51;



											vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_11875);
											mem_vec_11875 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_54 = _mm256_set1_ps(scal_9);


											vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_11876);
											mem_vec_11876 = vec_53;



											vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_11877);
											mem_vec_11877 = vec_55;



											vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_11878);
											mem_vec_11878 = vec_56;



											vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_11879);
											mem_vec_11879 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_59 = _mm256_set1_ps(scal_10);


											vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_11880);
											mem_vec_11880 = vec_58;



											vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_11881);
											mem_vec_11881 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_11882);
											mem_vec_11882 = vec_61;



											vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_11883);
											mem_vec_11883 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_64 = _mm256_set1_ps(scal_11);


											vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_11884);
											mem_vec_11884 = vec_63;



											vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_11885);
											mem_vec_11885 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_11886);
											mem_vec_11886 = vec_66;



											vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_11887);
											mem_vec_11887 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_69 = _mm256_set1_ps(scal_12);
											vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_11864);
											mem_vec_11864 = vec_68;

											vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_11865);
											mem_vec_11865 = vec_71;

											vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_11866);
											mem_vec_11866 = vec_73;

											vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_11867);
											mem_vec_11867 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_78 = _mm256_set1_ps(scal_13);


											vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_11868);
											mem_vec_11868 = vec_77;



											vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_11869);
											mem_vec_11869 = vec_79;



											vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_11870);
											mem_vec_11870 = vec_80;



											vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_11871);
											mem_vec_11871 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_83 = _mm256_set1_ps(scal_14);


											vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_11872);
											mem_vec_11872 = vec_82;



											vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_11873);
											mem_vec_11873 = vec_84;



											vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_11874);
											mem_vec_11874 = vec_85;



											vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_11875);
											mem_vec_11875 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_88 = _mm256_set1_ps(scal_15);


											vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_11876);
											mem_vec_11876 = vec_87;



											vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_11877);
											mem_vec_11877 = vec_89;



											vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_11878);
											mem_vec_11878 = vec_90;



											vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_11879);
											mem_vec_11879 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_93 = _mm256_set1_ps(scal_16);


											vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_11880);
											mem_vec_11880 = vec_92;



											vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_11881);
											mem_vec_11881 = vec_94;



											vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_11882);
											mem_vec_11882 = vec_95;



											vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_11883);
											mem_vec_11883 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_98 = _mm256_set1_ps(scal_17);


											vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_11884);
											mem_vec_11884 = vec_97;



											vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_11885);
											mem_vec_11885 = vec_99;



											vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_11886);
											mem_vec_11886 = vec_100;



											vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_11887);
											mem_vec_11887 = vec_101;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11864);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11865);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11866);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11867);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11868);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11869);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11870);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11871);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11872);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11873);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11874);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11875);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11876);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11877);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11878);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11879);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11880);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11881);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11882);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11883);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11884);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11885);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11886);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11887);
							}
						}
					}
				}
			}
	}
}


}