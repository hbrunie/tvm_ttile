#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (64, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (1, c); T (1, f); T (7, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (4, f)]
*/
IND_TYPE c, cp_0, c438_p_0, cp_1, c438, f, fp_0, f438_p_0, fp_1, f438, w, wp_0, x, xp_0, x423_p_0, xp_1, x423, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y292 = 0;
IND_TYPE x424 = 0;
IND_TYPE h = 0;
IND_TYPE w274 = 0;
IND_TYPE c439 = 0;
IND_TYPE f439 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4825 ,mem_vec_4826 ,mem_vec_4827 ,mem_vec_4828 ,mem_vec_4829 ,mem_vec_4830 ,mem_vec_4831 ,mem_vec_4832 ,mem_vec_4833 ,mem_vec_4834 ,mem_vec_4835 ,mem_vec_4836 ,mem_vec_4837 ,mem_vec_4838 ,mem_vec_4839 ,mem_vec_4840 ,mem_vec_4841 ,mem_vec_4842 ,mem_vec_4843 ,mem_vec_4844 ,mem_vec_4845 ,mem_vec_4846 ,mem_vec_4847 ,mem_vec_4848 ,mem_vec_4849 ,mem_vec_4850 ,mem_vec_4851 ,mem_vec_4852 ,mem_vec_4853 ,mem_vec_4854 ,mem_vec_4855 ,mem_vec_4856 ,mem_vec_4857 ,mem_vec_4858 ,mem_vec_4859 ,mem_vec_4860 ,mem_vec_4861 ,mem_vec_4862 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 28, x = 28, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
for (f438 = f439, f438_p_0 = 0;
	f438 < f439 + 128;
	f438 += 32, f438_p_0 += 32){
		for (y = y292, yp_0 = 0;
			y < y292 + 18;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
			// T (x, 7) (28 / 4)
			for (x423 = x424, x423_p_0 = 0;
				x423 < x424 + 28;
				x423 += 4, x423_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f438, fp_1 = f438_p_0, fp_0 = 0;
					f < f438 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c438 = c439, c438_p_0 = 0;
						c438 < c439 + 64;
						c438 += 64, c438_p_0 += 64){
						// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w274, wp_0 = 0;
							w < w274 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 3, w = 1, c = 64, f = 32
							// T (x, 4) (4 / 1)
							for (x = x423, xp_1 = x423_p_0, xp_0 = 0;
								x < x423 + 4;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4825 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4826 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_4841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_4842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c438, cp_1 = c438_p_0, cp_0 = 0;
											c < c438 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4825);
											mem_vec_4825 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4826);
											mem_vec_4826 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4827);
											mem_vec_4827 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4828);
											mem_vec_4828 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4829);
											mem_vec_4829 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4830);
											mem_vec_4830 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4831);
											mem_vec_4831 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4832);
											mem_vec_4832 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4833);
											mem_vec_4833 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4834);
											mem_vec_4834 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4835);
											mem_vec_4835 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4836);
											mem_vec_4836 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4837);
											mem_vec_4837 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4838);
											mem_vec_4838 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4839);
											mem_vec_4839 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4840);
											mem_vec_4840 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4841);
											mem_vec_4841 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4842);
											mem_vec_4842 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_30 = _mm512_set1_ps(scal_9);
											vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_4825);
											mem_vec_4825 = vec_29;

											vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_4826);
											mem_vec_4826 = vec_32;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_35 = _mm512_set1_ps(scal_10);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_4827);
											mem_vec_4827 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_4828);
											mem_vec_4828 = vec_36;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_4829);
											mem_vec_4829 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_4830);
											mem_vec_4830 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_4831);
											mem_vec_4831 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_4832);
											mem_vec_4832 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_4833);
											mem_vec_4833 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_4834);
											mem_vec_4834 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_4835);
											mem_vec_4835 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_4836);
											mem_vec_4836 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_4837);
											mem_vec_4837 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_4838);
											mem_vec_4838 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_4839);
											mem_vec_4839 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_4840);
											mem_vec_4840 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_4841);
											mem_vec_4841 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_4842);
											mem_vec_4842 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_18);
											vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_4825);
											mem_vec_4825 = vec_58;

											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_4826);
											mem_vec_4826 = vec_61;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_64 = _mm512_set1_ps(scal_19);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_4827);
											mem_vec_4827 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_4828);
											mem_vec_4828 = vec_65;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_67 = _mm512_set1_ps(scal_20);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_4829);
											mem_vec_4829 = vec_66;



											vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_4830);
											mem_vec_4830 = vec_68;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_4831);
											mem_vec_4831 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_4832);
											mem_vec_4832 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_4833);
											mem_vec_4833 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_4834);
											mem_vec_4834 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_4835);
											mem_vec_4835 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_4836);
											mem_vec_4836 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_4837);
											mem_vec_4837 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_4838);
											mem_vec_4838 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_4839);
											mem_vec_4839 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_4840);
											mem_vec_4840 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_4841);
											mem_vec_4841 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_4842);
											mem_vec_4842 = vec_86;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4825);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4826);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4827);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4829);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4830);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4831);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4832);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4833);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4834);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4835);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4836);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4837);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4838);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4839);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4841);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4842);
							}
						}
					}
				}
			}
		}
		for (y = y292 + 18, yp_0 = 0;
			y < y292 + 18 + 10;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 64, f = 32
			// T (x, 7) (28 / 4)
			for (x423 = x424, x423_p_0 = 0;
				x423 < x424 + 28;
				x423 += 4, x423_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f438, fp_1 = f438_p_0, fp_0 = 0;
					f < f438 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c438 = c439, c438_p_0 = 0;
						c438 < c439 + 64;
						c438 += 64, c438_p_0 += 64){
						// y = ph_y, x = 4, h = 3, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w274, wp_0 = 0;
							w < w274 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 4, h = 3, w = 1, c = 64, f = 32
							// T (x, 4) (4 / 1)
							for (x = x423, xp_1 = x423_p_0, xp_0 = 0;
								x < x423 + 4;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_4843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_4858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_4859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_4860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_4861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_4862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 3, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c438, cp_1 = c438_p_0, cp_0 = 0;
											c < c438 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4843);
											mem_vec_4843 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4844);
											mem_vec_4844 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4845);
											mem_vec_4845 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4846);
											mem_vec_4846 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4847);
											mem_vec_4847 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4848);
											mem_vec_4848 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4849);
											mem_vec_4849 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4850);
											mem_vec_4850 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4851);
											mem_vec_4851 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4852);
											mem_vec_4852 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4853);
											mem_vec_4853 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4854);
											mem_vec_4854 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4855);
											mem_vec_4855 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4856);
											mem_vec_4856 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4857);
											mem_vec_4857 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4858);
											mem_vec_4858 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4859);
											mem_vec_4859 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4860);
											mem_vec_4860 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4861);
											mem_vec_4861 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4862);
											mem_vec_4862 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
											vec_33 = _mm512_set1_ps(scal_10);
											vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_4843);
											mem_vec_4843 = vec_32;

											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

											vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_4844);
											mem_vec_4844 = vec_35;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
											vec_38 = _mm512_set1_ps(scal_11);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4845);
											mem_vec_4845 = vec_37;



											vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4846);
											mem_vec_4846 = vec_39;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
											vec_41 = _mm512_set1_ps(scal_12);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_4847);
											mem_vec_4847 = vec_40;



											vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_4848);
											mem_vec_4848 = vec_42;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_13);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_4849);
											mem_vec_4849 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_4850);
											mem_vec_4850 = vec_45;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
											vec_47 = _mm512_set1_ps(scal_14);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_4851);
											mem_vec_4851 = vec_46;



											vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_4852);
											mem_vec_4852 = vec_48;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_15);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_4853);
											mem_vec_4853 = vec_49;



											vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_4854);
											mem_vec_4854 = vec_51;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_16);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_4855);
											mem_vec_4855 = vec_52;



											vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_4856);
											mem_vec_4856 = vec_54;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_17);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_4857);
											mem_vec_4857 = vec_55;



											vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_4858);
											mem_vec_4858 = vec_57;
											scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 1) + c];
											vec_59 = _mm512_set1_ps(scal_18);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_4859);
											mem_vec_4859 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_4860);
											mem_vec_4860 = vec_60;
											scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_19);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_4861);
											mem_vec_4861 = vec_61;



											vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_4862);
											mem_vec_4862 = vec_63;
											scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_20);
											vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_4843);
											mem_vec_4843 = vec_64;

											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

											vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_4844);
											mem_vec_4844 = vec_67;
											scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
											vec_70 = _mm512_set1_ps(scal_21);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_4845);
											mem_vec_4845 = vec_69;



											vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_4846);
											mem_vec_4846 = vec_71;
											scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_22);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_4847);
											mem_vec_4847 = vec_72;



											vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_4848);
											mem_vec_4848 = vec_74;
											scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_23);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_4849);
											mem_vec_4849 = vec_75;



											vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_4850);
											mem_vec_4850 = vec_77;
											scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_24);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_4851);
											mem_vec_4851 = vec_78;



											vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_4852);
											mem_vec_4852 = vec_80;
											scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
											vec_82 = _mm512_set1_ps(scal_25);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_4853);
											mem_vec_4853 = vec_81;



											vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_4854);
											mem_vec_4854 = vec_83;
											scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_26);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_4855);
											mem_vec_4855 = vec_84;



											vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_4856);
											mem_vec_4856 = vec_86;
											scal_27 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
											vec_88 = _mm512_set1_ps(scal_27);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_4857);
											mem_vec_4857 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_4858);
											mem_vec_4858 = vec_89;
											scal_28 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h + 2) + c];
											vec_91 = _mm512_set1_ps(scal_28);


											vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_4859);
											mem_vec_4859 = vec_90;



											vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_4860);
											mem_vec_4860 = vec_92;
											scal_29 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_29);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_4861);
											mem_vec_4861 = vec_93;



											vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_4862);
											mem_vec_4862 = vec_95;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4862);
							}
						}
					}
				}
			}
		}
}


}