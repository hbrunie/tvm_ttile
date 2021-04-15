#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); U (3, w); T (128, c); Hoist_vars [c];
  T (17, x); T (2, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (64, f);
  T (2, c); T (1, f)]
*/
IND_TYPE c, cp_0, c1126_p_0, c1127_p_0, cp_1, c1126_p_1, cp_2, c1126, c1127, f, fp_0, f1184_p_0, fp_1, f1184, x, xp_0, x990_p_0, xp_1, x990, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y660 = 0;
IND_TYPE x991 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1128 = 0;
IND_TYPE f1185 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_54 ,scal_55 ,scal_56 ,scal_57 ,scal_58 ,scal_59 ,scal_6 ,scal_60 ,scal_61 ,scal_62 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8862 ,mem_vec_8863 ,mem_vec_8864 ,mem_vec_8865 ,mem_vec_8866 ,mem_vec_8867 ,mem_vec_8868 ,mem_vec_8869 ,mem_vec_8870 ,mem_vec_8871 ,mem_vec_8872 ,mem_vec_8873 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_132 ,vec_133 ,vec_134 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 1) (1024 / 1024)
for (f1184 = f1185, f1184_p_0 = 0;
	f1184 < f1185 + 1024;
	f1184 += 1024, f1184_p_0 += 1024){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 2) (512 / 256)
	for (c1127 = c1128, c1127_p_0 = 0;
		c1127 < c1128 + 512;
		c1127 += 256, c1127_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
		// T (f, 64) (1024 / 16)
		for (f = f1184, fp_1 = f1184_p_0, fp_0 = 0;
			f < f1184 + 1024;
			f += 16, fp_1 += 16, fp_0 += 16){
				for (y = y660, yp_0 = 0;
					y < y660 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
					// T (x, 1) (17 / 17)
					for (x990 = x991, x990_p_0 = 0;
						x990 < x991 + 17;
						x990 += 17, x990_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
						// T (c, 2) (256 / 128)
						for (c1126 = c1127, c1126_p_1 = c1127_p_0, c1126_p_0 = 0;
							c1126 < c1127 + 256;
							c1126 += 128, c1126_p_1 += 128, c1126_p_0 += 128){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 16
							// T (x, 17) (17 / 1)
							for (x = x990, xp_1 = x990_p_0, xp_0 = 0;
								x < x990 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8862 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
										// T (c, 128) (128 / 1)
										for (c = c1126, cp_2 = c1126_p_1, cp_1 = c1126_p_0, cp_0 = 0;
											c < c1126 + 128;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8862);
											mem_vec_8862 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8863);
											mem_vec_8863 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8864);
											mem_vec_8864 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8865);
											mem_vec_8865 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8866);
											mem_vec_8866 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_12 = _mm512_set1_ps(scal_5);
											vec_13 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_11 = _mm512_fmadd_ps(vec_12, vec_13, mem_vec_8862);
											mem_vec_8862 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_13, mem_vec_8863);
											mem_vec_8863 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_13, mem_vec_8864);
											mem_vec_8864 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_13, mem_vec_8865);
											mem_vec_8865 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_13, mem_vec_8866);
											mem_vec_8866 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_23 = _mm512_set1_ps(scal_10);
											vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_22 = _mm512_fmadd_ps(vec_23, vec_24, mem_vec_8862);
											mem_vec_8862 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_8863);
											mem_vec_8863 = vec_25;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_28 = _mm512_set1_ps(scal_12);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_24, mem_vec_8864);
											mem_vec_8864 = vec_27;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_30 = _mm512_set1_ps(scal_13);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_24, mem_vec_8865);
											mem_vec_8865 = vec_29;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_32 = _mm512_set1_ps(scal_14);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_8866);
											mem_vec_8866 = vec_31;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_34 = _mm512_set1_ps(scal_15);
											vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_33 = _mm512_fmadd_ps(vec_34, vec_35, mem_vec_8862);
											mem_vec_8862 = vec_33;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_37 = _mm512_set1_ps(scal_16);


											vec_36 = _mm512_fmadd_ps(vec_37, vec_35, mem_vec_8863);
											mem_vec_8863 = vec_36;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm512_set1_ps(scal_17);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_8864);
											mem_vec_8864 = vec_38;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_41 = _mm512_set1_ps(scal_18);


											vec_40 = _mm512_fmadd_ps(vec_41, vec_35, mem_vec_8865);
											mem_vec_8865 = vec_40;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_43 = _mm512_set1_ps(scal_19);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_35, mem_vec_8866);
											mem_vec_8866 = vec_42;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_45 = _mm512_set1_ps(scal_20);
											vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_44 = _mm512_fmadd_ps(vec_45, vec_46, mem_vec_8862);
											mem_vec_8862 = vec_44;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_48 = _mm512_set1_ps(scal_21);


											vec_47 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_8863);
											mem_vec_8863 = vec_47;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_50 = _mm512_set1_ps(scal_22);


											vec_49 = _mm512_fmadd_ps(vec_50, vec_46, mem_vec_8864);
											mem_vec_8864 = vec_49;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_52 = _mm512_set1_ps(scal_23);


											vec_51 = _mm512_fmadd_ps(vec_52, vec_46, mem_vec_8865);
											mem_vec_8865 = vec_51;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_54 = _mm512_set1_ps(scal_24);


											vec_53 = _mm512_fmadd_ps(vec_54, vec_46, mem_vec_8866);
											mem_vec_8866 = vec_53;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_56 = _mm512_set1_ps(scal_25);
											vec_57 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_55 = _mm512_fmadd_ps(vec_56, vec_57, mem_vec_8862);
											mem_vec_8862 = vec_55;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_59 = _mm512_set1_ps(scal_26);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_57, mem_vec_8863);
											mem_vec_8863 = vec_58;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_61 = _mm512_set1_ps(scal_27);


											vec_60 = _mm512_fmadd_ps(vec_61, vec_57, mem_vec_8864);
											mem_vec_8864 = vec_60;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_63 = _mm512_set1_ps(scal_28);


											vec_62 = _mm512_fmadd_ps(vec_63, vec_57, mem_vec_8865);
											mem_vec_8865 = vec_62;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_65 = _mm512_set1_ps(scal_29);


											vec_64 = _mm512_fmadd_ps(vec_65, vec_57, mem_vec_8866);
											mem_vec_8866 = vec_64;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_67 = _mm512_set1_ps(scal_30);
											vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_66 = _mm512_fmadd_ps(vec_67, vec_68, mem_vec_8862);
											mem_vec_8862 = vec_66;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_70 = _mm512_set1_ps(scal_31);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_8863);
											mem_vec_8863 = vec_69;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_72 = _mm512_set1_ps(scal_32);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_68, mem_vec_8864);
											mem_vec_8864 = vec_71;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_74 = _mm512_set1_ps(scal_33);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_68, mem_vec_8865);
											mem_vec_8865 = vec_73;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_76 = _mm512_set1_ps(scal_34);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_8866);
											mem_vec_8866 = vec_75;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_78 = _mm512_set1_ps(scal_35);
											vec_79 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_77 = _mm512_fmadd_ps(vec_78, vec_79, mem_vec_8862);
											mem_vec_8862 = vec_77;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_81 = _mm512_set1_ps(scal_36);


											vec_80 = _mm512_fmadd_ps(vec_81, vec_79, mem_vec_8863);
											mem_vec_8863 = vec_80;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_83 = _mm512_set1_ps(scal_37);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_79, mem_vec_8864);
											mem_vec_8864 = vec_82;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_85 = _mm512_set1_ps(scal_38);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_79, mem_vec_8865);
											mem_vec_8865 = vec_84;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_87 = _mm512_set1_ps(scal_39);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_79, mem_vec_8866);
											mem_vec_8866 = vec_86;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_89 = _mm512_set1_ps(scal_40);
											vec_90 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_88 = _mm512_fmadd_ps(vec_89, vec_90, mem_vec_8862);
											mem_vec_8862 = vec_88;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_92 = _mm512_set1_ps(scal_41);


											vec_91 = _mm512_fmadd_ps(vec_92, vec_90, mem_vec_8863);
											mem_vec_8863 = vec_91;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_94 = _mm512_set1_ps(scal_42);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_90, mem_vec_8864);
											mem_vec_8864 = vec_93;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_96 = _mm512_set1_ps(scal_43);


											vec_95 = _mm512_fmadd_ps(vec_96, vec_90, mem_vec_8865);
											mem_vec_8865 = vec_95;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_98 = _mm512_set1_ps(scal_44);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_90, mem_vec_8866);
											mem_vec_8866 = vec_97;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8866);
							}
						}
					}
				}
				for (y = y660 + 10, yp_0 = 0;
					y < y660 + 10 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
					// T (x, 1) (17 / 17)
					for (x990 = x991, x990_p_0 = 0;
						x990 < x991 + 17;
						x990 += 17, x990_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 16
						// T (c, 2) (256 / 128)
						for (c1126 = c1127, c1126_p_1 = c1127_p_0, c1126_p_0 = 0;
							c1126 < c1127 + 256;
							c1126 += 128, c1126_p_1 += 128, c1126_p_0 += 128){
							// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 16
							// T (x, 17) (17 / 1)
							for (x = x990, xp_1 = x990_p_0, xp_0 = 0;
								x < x990 + 17;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_8867 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
										// T (c, 128) (128 / 1)
										for (c = c1126, cp_2 = c1126_p_1, cp_1 = c1126_p_0, cp_0 = 0;
											c < c1126 + 128;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8867);
											mem_vec_8867 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_8868);
											mem_vec_8868 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8869);
											mem_vec_8869 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8870);
											mem_vec_8870 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_8871);
											mem_vec_8871 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8872);
											mem_vec_8872 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_14 = _mm512_set1_ps(scal_6);


											vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_8873);
											mem_vec_8873 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_16 = _mm512_set1_ps(scal_7);
											vec_17 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_15 = _mm512_fmadd_ps(vec_16, vec_17, mem_vec_8867);
											mem_vec_8867 = vec_15;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_17, mem_vec_8868);
											mem_vec_8868 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_17, mem_vec_8869);
											mem_vec_8869 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_17, mem_vec_8870);
											mem_vec_8870 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_17, mem_vec_8871);
											mem_vec_8871 = vec_24;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_27 = _mm512_set1_ps(scal_12);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_17, mem_vec_8872);
											mem_vec_8872 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
											vec_29 = _mm512_set1_ps(scal_13);


											vec_28 = _mm512_fmadd_ps(vec_29, vec_17, mem_vec_8873);
											mem_vec_8873 = vec_28;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_31 = _mm512_set1_ps(scal_14);
											vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_30 = _mm512_fmadd_ps(vec_31, vec_32, mem_vec_8867);
											mem_vec_8867 = vec_30;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_34 = _mm512_set1_ps(scal_15);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_8868);
											mem_vec_8868 = vec_33;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_36 = _mm512_set1_ps(scal_16);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_32, mem_vec_8869);
											mem_vec_8869 = vec_35;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_17);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_8870);
											mem_vec_8870 = vec_37;
											scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_40 = _mm512_set1_ps(scal_18);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_8871);
											mem_vec_8871 = vec_39;
											scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_42 = _mm512_set1_ps(scal_19);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_32, mem_vec_8872);
											mem_vec_8872 = vec_41;
											scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
											vec_44 = _mm512_set1_ps(scal_20);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_8873);
											mem_vec_8873 = vec_43;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_46 = _mm512_set1_ps(scal_21);
											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_45 = _mm512_fmadd_ps(vec_46, vec_47, mem_vec_8867);
											mem_vec_8867 = vec_45;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_49 = _mm512_set1_ps(scal_22);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_8868);
											mem_vec_8868 = vec_48;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_51 = _mm512_set1_ps(scal_23);


											vec_50 = _mm512_fmadd_ps(vec_51, vec_47, mem_vec_8869);
											mem_vec_8869 = vec_50;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_53 = _mm512_set1_ps(scal_24);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_8870);
											mem_vec_8870 = vec_52;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_55 = _mm512_set1_ps(scal_25);


											vec_54 = _mm512_fmadd_ps(vec_55, vec_47, mem_vec_8871);
											mem_vec_8871 = vec_54;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_57 = _mm512_set1_ps(scal_26);


											vec_56 = _mm512_fmadd_ps(vec_57, vec_47, mem_vec_8872);
											mem_vec_8872 = vec_56;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
											vec_59 = _mm512_set1_ps(scal_27);


											vec_58 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_8873);
											mem_vec_8873 = vec_58;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_61 = _mm512_set1_ps(scal_28);
											vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_60 = _mm512_fmadd_ps(vec_61, vec_62, mem_vec_8867);
											mem_vec_8867 = vec_60;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_29);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_8868);
											mem_vec_8868 = vec_63;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_66 = _mm512_set1_ps(scal_30);


											vec_65 = _mm512_fmadd_ps(vec_66, vec_62, mem_vec_8869);
											mem_vec_8869 = vec_65;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_68 = _mm512_set1_ps(scal_31);


											vec_67 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_8870);
											mem_vec_8870 = vec_67;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_70 = _mm512_set1_ps(scal_32);


											vec_69 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_8871);
											mem_vec_8871 = vec_69;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_72 = _mm512_set1_ps(scal_33);


											vec_71 = _mm512_fmadd_ps(vec_72, vec_62, mem_vec_8872);
											mem_vec_8872 = vec_71;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 1) + c];
											vec_74 = _mm512_set1_ps(scal_34);


											vec_73 = _mm512_fmadd_ps(vec_74, vec_62, mem_vec_8873);
											mem_vec_8873 = vec_73;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_35);
											vec_77 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_75 = _mm512_fmadd_ps(vec_76, vec_77, mem_vec_8867);
											mem_vec_8867 = vec_75;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_79 = _mm512_set1_ps(scal_36);


											vec_78 = _mm512_fmadd_ps(vec_79, vec_77, mem_vec_8868);
											mem_vec_8868 = vec_78;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_81 = _mm512_set1_ps(scal_37);


											vec_80 = _mm512_fmadd_ps(vec_81, vec_77, mem_vec_8869);
											mem_vec_8869 = vec_80;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_83 = _mm512_set1_ps(scal_38);


											vec_82 = _mm512_fmadd_ps(vec_83, vec_77, mem_vec_8870);
											mem_vec_8870 = vec_82;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_85 = _mm512_set1_ps(scal_39);


											vec_84 = _mm512_fmadd_ps(vec_85, vec_77, mem_vec_8871);
											mem_vec_8871 = vec_84;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_87 = _mm512_set1_ps(scal_40);


											vec_86 = _mm512_fmadd_ps(vec_87, vec_77, mem_vec_8872);
											mem_vec_8872 = vec_86;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h + 2) + c];
											vec_89 = _mm512_set1_ps(scal_41);


											vec_88 = _mm512_fmadd_ps(vec_89, vec_77, mem_vec_8873);
											mem_vec_8873 = vec_88;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_91 = _mm512_set1_ps(scal_42);
											vec_92 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_90 = _mm512_fmadd_ps(vec_91, vec_92, mem_vec_8867);
											mem_vec_8867 = vec_90;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_94 = _mm512_set1_ps(scal_43);


											vec_93 = _mm512_fmadd_ps(vec_94, vec_92, mem_vec_8868);
											mem_vec_8868 = vec_93;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_96 = _mm512_set1_ps(scal_44);


											vec_95 = _mm512_fmadd_ps(vec_96, vec_92, mem_vec_8869);
											mem_vec_8869 = vec_95;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_98 = _mm512_set1_ps(scal_45);


											vec_97 = _mm512_fmadd_ps(vec_98, vec_92, mem_vec_8870);
											mem_vec_8870 = vec_97;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_100 = _mm512_set1_ps(scal_46);


											vec_99 = _mm512_fmadd_ps(vec_100, vec_92, mem_vec_8871);
											mem_vec_8871 = vec_99;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_102 = _mm512_set1_ps(scal_47);


											vec_101 = _mm512_fmadd_ps(vec_102, vec_92, mem_vec_8872);
											mem_vec_8872 = vec_101;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
											vec_104 = _mm512_set1_ps(scal_48);


											vec_103 = _mm512_fmadd_ps(vec_104, vec_92, mem_vec_8873);
											mem_vec_8873 = vec_103;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_106 = _mm512_set1_ps(scal_49);
											vec_107 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_105 = _mm512_fmadd_ps(vec_106, vec_107, mem_vec_8867);
											mem_vec_8867 = vec_105;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_109 = _mm512_set1_ps(scal_50);


											vec_108 = _mm512_fmadd_ps(vec_109, vec_107, mem_vec_8868);
											mem_vec_8868 = vec_108;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_111 = _mm512_set1_ps(scal_51);


											vec_110 = _mm512_fmadd_ps(vec_111, vec_107, mem_vec_8869);
											mem_vec_8869 = vec_110;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_113 = _mm512_set1_ps(scal_52);


											vec_112 = _mm512_fmadd_ps(vec_113, vec_107, mem_vec_8870);
											mem_vec_8870 = vec_112;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_115 = _mm512_set1_ps(scal_53);


											vec_114 = _mm512_fmadd_ps(vec_115, vec_107, mem_vec_8871);
											mem_vec_8871 = vec_114;
											scal_54 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_117 = _mm512_set1_ps(scal_54);


											vec_116 = _mm512_fmadd_ps(vec_117, vec_107, mem_vec_8872);
											mem_vec_8872 = vec_116;
											scal_55 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 1) + c];
											vec_119 = _mm512_set1_ps(scal_55);


											vec_118 = _mm512_fmadd_ps(vec_119, vec_107, mem_vec_8873);
											mem_vec_8873 = vec_118;
											scal_56 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_121 = _mm512_set1_ps(scal_56);
											vec_122 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_120 = _mm512_fmadd_ps(vec_121, vec_122, mem_vec_8867);
											mem_vec_8867 = vec_120;
											scal_57 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_124 = _mm512_set1_ps(scal_57);


											vec_123 = _mm512_fmadd_ps(vec_124, vec_122, mem_vec_8868);
											mem_vec_8868 = vec_123;
											scal_58 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_126 = _mm512_set1_ps(scal_58);


											vec_125 = _mm512_fmadd_ps(vec_126, vec_122, mem_vec_8869);
											mem_vec_8869 = vec_125;
											scal_59 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_128 = _mm512_set1_ps(scal_59);


											vec_127 = _mm512_fmadd_ps(vec_128, vec_122, mem_vec_8870);
											mem_vec_8870 = vec_127;
											scal_60 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_130 = _mm512_set1_ps(scal_60);


											vec_129 = _mm512_fmadd_ps(vec_130, vec_122, mem_vec_8871);
											mem_vec_8871 = vec_129;
											scal_61 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_132 = _mm512_set1_ps(scal_61);


											vec_131 = _mm512_fmadd_ps(vec_132, vec_122, mem_vec_8872);
											mem_vec_8872 = vec_131;
											scal_62 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h + 2) + c];
											vec_134 = _mm512_set1_ps(scal_62);


											vec_133 = _mm512_fmadd_ps(vec_134, vec_122, mem_vec_8873);
											mem_vec_8873 = vec_133;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8867);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8869);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8871);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8872);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8873);
							}
						}
					}
				}
		}
	}
}


}