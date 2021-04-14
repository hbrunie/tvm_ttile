#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (4, f); T (32, c); T (7, x);
  Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))]; T (1, f)]
*/
IND_TYPE c, cp_0, c1134_p_0, cp_1, c1134, f, fp_0, f1134_p_0, fp_1, f1134, h, hp_0, x, xp_0, x1134_p_0, xp_1, x1134, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y756 = 0;
IND_TYPE x1135 = 0;
IND_TYPE h598 = 0;
IND_TYPE w = 0;
IND_TYPE c1135 = 0;
IND_TYPE f1135 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9852 ,mem_vec_9853 ,mem_vec_9854 ,mem_vec_9855 ,mem_vec_9856 ,mem_vec_9857 ,mem_vec_9858 ,mem_vec_9859 ,mem_vec_9860 ,mem_vec_9861 ,mem_vec_9862 ,mem_vec_9863 ,mem_vec_9864 ,mem_vec_9865 ,mem_vec_9866 ,mem_vec_9867 ,mem_vec_9868 ,mem_vec_9869 ,mem_vec_9870 ,mem_vec_9871 ,mem_vec_9872 ,mem_vec_9873 ,mem_vec_9874 ,mem_vec_9875 ,mem_vec_9876 ,mem_vec_9877 ,mem_vec_9878 ,mem_vec_9879 ,mem_vec_9880 ,mem_vec_9881 ,mem_vec_9882 ,mem_vec_9883 ,mem_vec_9884 ,mem_vec_9885 ,mem_vec_9886 ,mem_vec_9887 ,mem_vec_9888 ,mem_vec_9889 ,mem_vec_9890 ,mem_vec_9891 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1134 = f1135, f1134_p_0 = 0;
	f1134 < f1135 + 256;
	f1134 += 256, f1134_p_0 += 256){
		for (y = y756, yp_0 = 0;
			y < y756 + 8;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
			// T (x, 7) (14 / 2)
			for (x1134 = x1135, x1134_p_0 = 0;
				x1134 < x1135 + 14;
				x1134 += 2, x1134_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 256
				// T (c, 32) (128 / 4)
				for (c1134 = c1135, c1134_p_0 = 0;
					c1134 < c1135 + 128;
					c1134 += 4, c1134_p_0 += 4){
					// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 256
					// T (f, 4) (256 / 64)
					for (f = f1134, fp_1 = f1134_p_0, fp_0 = 0;
						f < f1134 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 64
						// T (h, 3) (3 / 1)
						for (h = h598, hp_0 = 0;
							h < h598 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 64
							// T (x, 2) (2 / 1)
							for (x = x1134, xp_1 = x1134_p_0, xp_0 = 0;
								x < x1134 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9852 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9853 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9854 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_9855 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_9856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_9859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_9860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_9863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_9864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_9867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1134, cp_1 = c1134_p_0, cp_0 = 0;
											c < c1134 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9852);
											mem_vec_9852 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9853);
											mem_vec_9853 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9854);
											mem_vec_9854 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9855);
											mem_vec_9855 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9856);
											mem_vec_9856 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9857);
											mem_vec_9857 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9858);
											mem_vec_9858 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9859);
											mem_vec_9859 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9860);
											mem_vec_9860 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9861);
											mem_vec_9861 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9862);
											mem_vec_9862 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9863);
											mem_vec_9863 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9864);
											mem_vec_9864 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9865);
											mem_vec_9865 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9866);
											mem_vec_9866 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9867);
											mem_vec_9867 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);
											vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_9852);
											mem_vec_9852 = vec_24;

											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_9853);
											mem_vec_9853 = vec_27;

											vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_9854);
											mem_vec_9854 = vec_29;

											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_9855);
											mem_vec_9855 = vec_31;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_34 = _mm512_set1_ps(scal_5);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_9856);
											mem_vec_9856 = vec_33;



											vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_9857);
											mem_vec_9857 = vec_35;



											vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_9858);
											mem_vec_9858 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_9859);
											mem_vec_9859 = vec_37;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_39 = _mm512_set1_ps(scal_6);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_9860);
											mem_vec_9860 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_9861);
											mem_vec_9861 = vec_40;



											vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_9862);
											mem_vec_9862 = vec_41;



											vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_9863);
											mem_vec_9863 = vec_42;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_9864);
											mem_vec_9864 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_9865);
											mem_vec_9865 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_9866);
											mem_vec_9866 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_9867);
											mem_vec_9867 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);
											vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_9852);
											mem_vec_9852 = vec_48;

											vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_9853);
											mem_vec_9853 = vec_51;

											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_9854);
											mem_vec_9854 = vec_53;

											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_9855);
											mem_vec_9855 = vec_55;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_58 = _mm512_set1_ps(scal_9);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_9856);
											mem_vec_9856 = vec_57;



											vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_9857);
											mem_vec_9857 = vec_59;



											vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_9858);
											mem_vec_9858 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_9859);
											mem_vec_9859 = vec_61;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_63 = _mm512_set1_ps(scal_10);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_9860);
											mem_vec_9860 = vec_62;



											vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_9861);
											mem_vec_9861 = vec_64;



											vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_9862);
											mem_vec_9862 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_9863);
											mem_vec_9863 = vec_66;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_68 = _mm512_set1_ps(scal_11);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_9864);
											mem_vec_9864 = vec_67;



											vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_9865);
											mem_vec_9865 = vec_69;



											vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_9866);
											mem_vec_9866 = vec_70;



											vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_9867);
											mem_vec_9867 = vec_71;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9867);
							}
						}
					}
				}
			}
		}
		for (y = y756 + 8, yp_0 = 0;
			y < y756 + 8 + 6;
			y += 6, yp_0 += 6){
			// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 256
			// T (x, 7) (14 / 2)
			for (x1134 = x1135, x1134_p_0 = 0;
				x1134 < x1135 + 14;
				x1134 += 2, x1134_p_0 += 2){
				// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 256
				// T (c, 32) (128 / 4)
				for (c1134 = c1135, c1134_p_0 = 0;
					c1134 < c1135 + 128;
					c1134 += 4, c1134_p_0 += 4){
					// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 256
					// T (f, 4) (256 / 64)
					for (f = f1134, fp_1 = f1134_p_0, fp_0 = 0;
						f < f1134 + 256;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 64
						// T (h, 3) (3 / 1)
						for (h = h598, hp_0 = 0;
							h < h598 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 64
							// T (x, 2) (2 / 1)
							for (x = x1134, xp_1 = x1134_p_0, xp_0 = 0;
								x < x1134 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_9868 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_9869 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_9870 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_9871 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_9872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_9873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_9874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_9875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_9876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_9877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_9878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_9879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_9880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_9881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_9882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_9883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_9884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_9885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_9886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_9887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_9888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_9889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_9890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_9891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
										// T (c, 4) (4 / 1)
										for (c = c1134, cp_1 = c1134_p_0, cp_0 = 0;
											c < c1134 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9868);
											mem_vec_9868 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9869);
											mem_vec_9869 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9870);
											mem_vec_9870 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9871);
											mem_vec_9871 = vec_7;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9872);
											mem_vec_9872 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9873);
											mem_vec_9873 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9874);
											mem_vec_9874 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9875);
											mem_vec_9875 = vec_13;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9876);
											mem_vec_9876 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9877);
											mem_vec_9877 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9878);
											mem_vec_9878 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9879);
											mem_vec_9879 = vec_18;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9880);
											mem_vec_9880 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9881);
											mem_vec_9881 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9882);
											mem_vec_9882 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9883);
											mem_vec_9883 = vec_23;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9884);
											mem_vec_9884 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9885);
											mem_vec_9885 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9886);
											mem_vec_9886 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9887);
											mem_vec_9887 = vec_28;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9888);
											mem_vec_9888 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9889);
											mem_vec_9889 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_9890);
											mem_vec_9890 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_9891);
											mem_vec_9891 = vec_33;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);
											vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_9868);
											mem_vec_9868 = vec_34;

											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_9869);
											mem_vec_9869 = vec_37;

											vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

											vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_9870);
											mem_vec_9870 = vec_39;

											vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

											vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_9871);
											mem_vec_9871 = vec_41;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
											vec_44 = _mm512_set1_ps(scal_7);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_9872);
											mem_vec_9872 = vec_43;



											vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_9873);
											mem_vec_9873 = vec_45;



											vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_9874);
											mem_vec_9874 = vec_46;



											vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_9875);
											mem_vec_9875 = vec_47;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
											vec_49 = _mm512_set1_ps(scal_8);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_9876);
											mem_vec_9876 = vec_48;



											vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_9877);
											mem_vec_9877 = vec_50;



											vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_9878);
											mem_vec_9878 = vec_51;



											vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_9879);
											mem_vec_9879 = vec_52;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
											vec_54 = _mm512_set1_ps(scal_9);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_9880);
											mem_vec_9880 = vec_53;



											vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_9881);
											mem_vec_9881 = vec_55;



											vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_9882);
											mem_vec_9882 = vec_56;



											vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_9883);
											mem_vec_9883 = vec_57;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
											vec_59 = _mm512_set1_ps(scal_10);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_9884);
											mem_vec_9884 = vec_58;



											vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_9885);
											mem_vec_9885 = vec_60;



											vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_9886);
											mem_vec_9886 = vec_61;



											vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_9887);
											mem_vec_9887 = vec_62;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
											vec_64 = _mm512_set1_ps(scal_11);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_9888);
											mem_vec_9888 = vec_63;



											vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_9889);
											mem_vec_9889 = vec_65;



											vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_9890);
											mem_vec_9890 = vec_66;



											vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_9891);
											mem_vec_9891 = vec_67;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
											vec_69 = _mm512_set1_ps(scal_12);
											vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_9868);
											mem_vec_9868 = vec_68;

											vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_9869);
											mem_vec_9869 = vec_71;

											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

											vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_9870);
											mem_vec_9870 = vec_73;

											vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

											vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_9871);
											mem_vec_9871 = vec_75;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
											vec_78 = _mm512_set1_ps(scal_13);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_9872);
											mem_vec_9872 = vec_77;



											vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_9873);
											mem_vec_9873 = vec_79;



											vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_9874);
											mem_vec_9874 = vec_80;



											vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_9875);
											mem_vec_9875 = vec_81;
											scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
											vec_83 = _mm512_set1_ps(scal_14);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_9876);
											mem_vec_9876 = vec_82;



											vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_9877);
											mem_vec_9877 = vec_84;



											vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_9878);
											mem_vec_9878 = vec_85;



											vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_9879);
											mem_vec_9879 = vec_86;
											scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
											vec_88 = _mm512_set1_ps(scal_15);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_9880);
											mem_vec_9880 = vec_87;



											vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_9881);
											mem_vec_9881 = vec_89;



											vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_9882);
											mem_vec_9882 = vec_90;



											vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_9883);
											mem_vec_9883 = vec_91;
											scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
											vec_93 = _mm512_set1_ps(scal_16);


											vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_9884);
											mem_vec_9884 = vec_92;



											vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_9885);
											mem_vec_9885 = vec_94;



											vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_9886);
											mem_vec_9886 = vec_95;



											vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_9887);
											mem_vec_9887 = vec_96;
											scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
											vec_98 = _mm512_set1_ps(scal_17);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_9888);
											mem_vec_9888 = vec_97;



											vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_9889);
											mem_vec_9889 = vec_99;



											vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_9890);
											mem_vec_9890 = vec_100;



											vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_9891);
											mem_vec_9891 = vec_101;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9869);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9871);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9872);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9873);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9874);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9875);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9876);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9877);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9878);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9879);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9880);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9881);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9882);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9883);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9884);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9885);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9886);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9887);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9888);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9889);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_9890);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_9891);
							}
						}
					}
				}
			}
		}
}


}