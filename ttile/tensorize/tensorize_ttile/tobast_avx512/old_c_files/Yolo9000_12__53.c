#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); U (3, w); T (2, c); Hoist_vars [c];
  T (1, x); T (4, c); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (32, f);
  T (32, c); T (2, x)]
*/
IND_TYPE c, cp_0, c814_p_0, c815_p_0, cp_1, c814_p_1, cp_2, c814, c815, f, fp_0, x, xp_0, x814_p_0, x815_p_0, xp_1, x814_p_1, xp_2, x814, x815, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y504 = 0;
IND_TYPE x816 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c816 = 0;
IND_TYPE f892 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_39 ,scal_4 ,scal_40 ,scal_41 ,scal_42 ,scal_43 ,scal_44 ,scal_45 ,scal_46 ,scal_47 ,scal_48 ,scal_49 ,scal_5 ,scal_50 ,scal_51 ,scal_52 ,scal_53 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7884 ,mem_vec_7885 ,mem_vec_7886 ,mem_vec_7887 ,mem_vec_7888 ,mem_vec_7889 ,mem_vec_7890 ,mem_vec_7891 ,mem_vec_7892 ,mem_vec_7893 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (x, 2) (34 / 17)
for (x815 = x816, x815_p_0 = 0;
	x815 < x816 + 34;
	x815 += 17, x815_p_0 += 17){
	// y = 34, x = 17, h = 3, w = 3, c = 256, f = 512
	// T (c, 32) (256 / 8)
	for (c815 = c816, c815_p_0 = 0;
		c815 < c816 + 256;
		c815 += 8, c815_p_0 += 8){
		// y = 34, x = 17, h = 3, w = 3, c = 8, f = 512
		// T (f, 32) (512 / 16)
		for (f = f892, fp_0 = 0;
			f < f892 + 512;
			f += 16, fp_0 += 16){
				for (y = y504, yp_0 = 0;
					y < y504 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
					// T (x, 17) (17 / 1)
					for (x814 = x815, x814_p_1 = x815_p_0, x814_p_0 = 0;
						x814 < x815 + 17;
						x814 += 1, x814_p_1 += 1, x814_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
						// T (c, 4) (8 / 2)
						for (c814 = c815, c814_p_1 = c815_p_0, c814_p_0 = 0;
							c814 < c815 + 8;
							c814 += 2, c814_p_1 += 2, c814_p_0 += 2){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
							// T (x, 1) (1 / 1)
							for (x = x814, xp_2 = x814_p_1, xp_1 = x814_p_0, xp_0 = 0;
								x < x814 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7884 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
										// T (c, 2) (2 / 1)
										for (c = c814, cp_2 = c814_p_1, cp_1 = c814_p_0, cp_0 = 0;
											c < c814 + 2;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7884);
											mem_vec_7884 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_7885);
											mem_vec_7885 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7886);
											mem_vec_7886 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_7887);
											mem_vec_7887 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_7884);
											mem_vec_7884 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_13 = _mm512_set1_ps(scal_5);


											vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_7885);
											mem_vec_7885 = vec_12;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_7886);
											mem_vec_7886 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_7887);
											mem_vec_7887 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_19 = _mm512_set1_ps(scal_8);
											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_7884);
											mem_vec_7884 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_22 = _mm512_set1_ps(scal_9);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_7885);
											mem_vec_7885 = vec_21;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_24 = _mm512_set1_ps(scal_10);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_7886);
											mem_vec_7886 = vec_23;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_7887);
											mem_vec_7887 = vec_25;
											scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_28 = _mm512_set1_ps(scal_12);
											vec_29 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_27 = _mm512_fmadd_ps(vec_28, vec_29, mem_vec_7884);
											mem_vec_7884 = vec_27;
											scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_31 = _mm512_set1_ps(scal_13);


											vec_30 = _mm512_fmadd_ps(vec_31, vec_29, mem_vec_7885);
											mem_vec_7885 = vec_30;
											scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_33 = _mm512_set1_ps(scal_14);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_29, mem_vec_7886);
											mem_vec_7886 = vec_32;
											scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_35 = _mm512_set1_ps(scal_15);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_29, mem_vec_7887);
											mem_vec_7887 = vec_34;
											scal_16 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_37 = _mm512_set1_ps(scal_16);
											vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_36 = _mm512_fmadd_ps(vec_37, vec_38, mem_vec_7884);
											mem_vec_7884 = vec_36;
											scal_17 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_40 = _mm512_set1_ps(scal_17);


											vec_39 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_7885);
											mem_vec_7885 = vec_39;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_42 = _mm512_set1_ps(scal_18);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_38, mem_vec_7886);
											mem_vec_7886 = vec_41;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_44 = _mm512_set1_ps(scal_19);


											vec_43 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_7887);
											mem_vec_7887 = vec_43;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_46 = _mm512_set1_ps(scal_20);
											vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_45 = _mm512_fmadd_ps(vec_46, vec_47, mem_vec_7884);
											mem_vec_7884 = vec_45;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_49 = _mm512_set1_ps(scal_21);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_7885);
											mem_vec_7885 = vec_48;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_51 = _mm512_set1_ps(scal_22);


											vec_50 = _mm512_fmadd_ps(vec_51, vec_47, mem_vec_7886);
											mem_vec_7886 = vec_50;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_53 = _mm512_set1_ps(scal_23);


											vec_52 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_7887);
											mem_vec_7887 = vec_52;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_55 = _mm512_set1_ps(scal_24);
											vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_54 = _mm512_fmadd_ps(vec_55, vec_56, mem_vec_7884);
											mem_vec_7884 = vec_54;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm512_set1_ps(scal_25);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7885);
											mem_vec_7885 = vec_57;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_60 = _mm512_set1_ps(scal_26);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_56, mem_vec_7886);
											mem_vec_7886 = vec_59;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_62 = _mm512_set1_ps(scal_27);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_56, mem_vec_7887);
											mem_vec_7887 = vec_61;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_28);
											vec_65 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_63 = _mm512_fmadd_ps(vec_64, vec_65, mem_vec_7884);
											mem_vec_7884 = vec_63;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_67 = _mm512_set1_ps(scal_29);


											vec_66 = _mm512_fmadd_ps(vec_67, vec_65, mem_vec_7885);
											mem_vec_7885 = vec_66;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_69 = _mm512_set1_ps(scal_30);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_65, mem_vec_7886);
											mem_vec_7886 = vec_68;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_71 = _mm512_set1_ps(scal_31);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_65, mem_vec_7887);
											mem_vec_7887 = vec_70;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_32);
											vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_72 = _mm512_fmadd_ps(vec_73, vec_74, mem_vec_7884);
											mem_vec_7884 = vec_72;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_76 = _mm512_set1_ps(scal_33);


											vec_75 = _mm512_fmadd_ps(vec_76, vec_74, mem_vec_7885);
											mem_vec_7885 = vec_75;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_78 = _mm512_set1_ps(scal_34);


											vec_77 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_7886);
											mem_vec_7886 = vec_77;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_80 = _mm512_set1_ps(scal_35);


											vec_79 = _mm512_fmadd_ps(vec_80, vec_74, mem_vec_7887);
											mem_vec_7887 = vec_79;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7884);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7885);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7886);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7887);
							}
						}
					}
				}
				for (y = y504 + 4, yp_0 = 0;
					y < y504 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 8, f = 16
					// T (x, 17) (17 / 1)
					for (x814 = x815, x814_p_1 = x815_p_0, x814_p_0 = 0;
						x814 < x815 + 17;
						x814 += 1, x814_p_1 += 1, x814_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
						// T (c, 4) (8 / 2)
						for (c814 = c815, c814_p_1 = c815_p_0, c814_p_0 = 0;
							c814 < c815 + 8;
							c814 += 2, c814_p_1 += 2, c814_p_0 += 2){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
							// T (x, 1) (1 / 1)
							for (x = x814, xp_2 = x814_p_1, xp_1 = x814_p_0, xp_0 = 0;
								x < x814 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7888 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 16
										// T (c, 2) (2 / 1)
										for (c = c814, cp_2 = c814_p_1, cp_1 = c814_p_0, cp_0 = 0;
											c < c814 + 2;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7888);
											mem_vec_7888 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_7889);
											mem_vec_7889 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7890);
											mem_vec_7890 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_7891);
											mem_vec_7891 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7892);
											mem_vec_7892 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_12 = _mm512_set1_ps(scal_5);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7893);
											mem_vec_7893 = vec_11;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
											vec_14 = _mm512_set1_ps(scal_6);
											vec_15 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

											vec_13 = _mm512_fmadd_ps(vec_14, vec_15, mem_vec_7888);
											mem_vec_7888 = vec_13;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_15, mem_vec_7889);
											mem_vec_7889 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
											vec_19 = _mm512_set1_ps(scal_8);


											vec_18 = _mm512_fmadd_ps(vec_19, vec_15, mem_vec_7890);
											mem_vec_7890 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
											vec_21 = _mm512_set1_ps(scal_9);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_15, mem_vec_7891);
											mem_vec_7891 = vec_20;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
											vec_23 = _mm512_set1_ps(scal_10);


											vec_22 = _mm512_fmadd_ps(vec_23, vec_15, mem_vec_7892);
											mem_vec_7892 = vec_22;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
											vec_25 = _mm512_set1_ps(scal_11);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_15, mem_vec_7893);
											mem_vec_7893 = vec_24;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
											vec_27 = _mm512_set1_ps(scal_12);
											vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

											vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7888);
											mem_vec_7888 = vec_26;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
											vec_30 = _mm512_set1_ps(scal_13);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_28, mem_vec_7889);
											mem_vec_7889 = vec_29;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
											vec_32 = _mm512_set1_ps(scal_14);


											vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_7890);
											mem_vec_7890 = vec_31;
											scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
											vec_34 = _mm512_set1_ps(scal_15);


											vec_33 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_7891);
											mem_vec_7891 = vec_33;
											scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
											vec_36 = _mm512_set1_ps(scal_16);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_28, mem_vec_7892);
											mem_vec_7892 = vec_35;
											scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
											vec_38 = _mm512_set1_ps(scal_17);


											vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_7893);
											mem_vec_7893 = vec_37;
											scal_18 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_40 = _mm512_set1_ps(scal_18);
											vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_7888);
											mem_vec_7888 = vec_39;
											scal_19 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_43 = _mm512_set1_ps(scal_19);


											vec_42 = _mm512_fmadd_ps(vec_43, vec_41, mem_vec_7889);
											mem_vec_7889 = vec_42;
											scal_20 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_45 = _mm512_set1_ps(scal_20);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_41, mem_vec_7890);
											mem_vec_7890 = vec_44;
											scal_21 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_47 = _mm512_set1_ps(scal_21);


											vec_46 = _mm512_fmadd_ps(vec_47, vec_41, mem_vec_7891);
											mem_vec_7891 = vec_46;
											scal_22 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
											vec_49 = _mm512_set1_ps(scal_22);


											vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_7892);
											mem_vec_7892 = vec_48;
											scal_23 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
											vec_51 = _mm512_set1_ps(scal_23);


											vec_50 = _mm512_fmadd_ps(vec_51, vec_41, mem_vec_7893);
											mem_vec_7893 = vec_50;
											scal_24 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 1) + c];
											vec_53 = _mm512_set1_ps(scal_24);
											vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 1) + F * c + f]);

											vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7888);
											mem_vec_7888 = vec_52;
											scal_25 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 1) + c];
											vec_56 = _mm512_set1_ps(scal_25);


											vec_55 = _mm512_fmadd_ps(vec_56, vec_54, mem_vec_7889);
											mem_vec_7889 = vec_55;
											scal_26 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 1) + c];
											vec_58 = _mm512_set1_ps(scal_26);


											vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7890);
											mem_vec_7890 = vec_57;
											scal_27 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 1) + c];
											vec_60 = _mm512_set1_ps(scal_27);


											vec_59 = _mm512_fmadd_ps(vec_60, vec_54, mem_vec_7891);
											mem_vec_7891 = vec_59;
											scal_28 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 1) + c];
											vec_62 = _mm512_set1_ps(scal_28);


											vec_61 = _mm512_fmadd_ps(vec_62, vec_54, mem_vec_7892);
											mem_vec_7892 = vec_61;
											scal_29 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 1) + c];
											vec_64 = _mm512_set1_ps(scal_29);


											vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_7893);
											mem_vec_7893 = vec_63;
											scal_30 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h + 2) + c];
											vec_66 = _mm512_set1_ps(scal_30);
											vec_67 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * (h + 2) + F * c + f]);

											vec_65 = _mm512_fmadd_ps(vec_66, vec_67, mem_vec_7888);
											mem_vec_7888 = vec_65;
											scal_31 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h + 2) + c];
											vec_69 = _mm512_set1_ps(scal_31);


											vec_68 = _mm512_fmadd_ps(vec_69, vec_67, mem_vec_7889);
											mem_vec_7889 = vec_68;
											scal_32 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h + 2) + c];
											vec_71 = _mm512_set1_ps(scal_32);


											vec_70 = _mm512_fmadd_ps(vec_71, vec_67, mem_vec_7890);
											mem_vec_7890 = vec_70;
											scal_33 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h + 2) + c];
											vec_73 = _mm512_set1_ps(scal_33);


											vec_72 = _mm512_fmadd_ps(vec_73, vec_67, mem_vec_7891);
											mem_vec_7891 = vec_72;
											scal_34 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h + 2) + c];
											vec_75 = _mm512_set1_ps(scal_34);


											vec_74 = _mm512_fmadd_ps(vec_75, vec_67, mem_vec_7892);
											mem_vec_7892 = vec_74;
											scal_35 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h + 2) + c];
											vec_77 = _mm512_set1_ps(scal_35);


											vec_76 = _mm512_fmadd_ps(vec_77, vec_67, mem_vec_7893);
											mem_vec_7893 = vec_76;
											scal_36 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_79 = _mm512_set1_ps(scal_36);
											vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_7888);
											mem_vec_7888 = vec_78;
											scal_37 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_82 = _mm512_set1_ps(scal_37);


											vec_81 = _mm512_fmadd_ps(vec_82, vec_80, mem_vec_7889);
											mem_vec_7889 = vec_81;
											scal_38 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_84 = _mm512_set1_ps(scal_38);


											vec_83 = _mm512_fmadd_ps(vec_84, vec_80, mem_vec_7890);
											mem_vec_7890 = vec_83;
											scal_39 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_86 = _mm512_set1_ps(scal_39);


											vec_85 = _mm512_fmadd_ps(vec_86, vec_80, mem_vec_7891);
											mem_vec_7891 = vec_85;
											scal_40 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
											vec_88 = _mm512_set1_ps(scal_40);


											vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_7892);
											mem_vec_7892 = vec_87;
											scal_41 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
											vec_90 = _mm512_set1_ps(scal_41);


											vec_89 = _mm512_fmadd_ps(vec_90, vec_80, mem_vec_7893);
											mem_vec_7893 = vec_89;
											scal_42 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 1) + c];
											vec_92 = _mm512_set1_ps(scal_42);
											vec_93 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 1) + F * c + f]);

											vec_91 = _mm512_fmadd_ps(vec_92, vec_93, mem_vec_7888);
											mem_vec_7888 = vec_91;
											scal_43 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 1) + c];
											vec_95 = _mm512_set1_ps(scal_43);


											vec_94 = _mm512_fmadd_ps(vec_95, vec_93, mem_vec_7889);
											mem_vec_7889 = vec_94;
											scal_44 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 1) + c];
											vec_97 = _mm512_set1_ps(scal_44);


											vec_96 = _mm512_fmadd_ps(vec_97, vec_93, mem_vec_7890);
											mem_vec_7890 = vec_96;
											scal_45 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 1) + c];
											vec_99 = _mm512_set1_ps(scal_45);


											vec_98 = _mm512_fmadd_ps(vec_99, vec_93, mem_vec_7891);
											mem_vec_7891 = vec_98;
											scal_46 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 1) + c];
											vec_101 = _mm512_set1_ps(scal_46);


											vec_100 = _mm512_fmadd_ps(vec_101, vec_93, mem_vec_7892);
											mem_vec_7892 = vec_100;
											scal_47 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 1) + c];
											vec_103 = _mm512_set1_ps(scal_47);


											vec_102 = _mm512_fmadd_ps(vec_103, vec_93, mem_vec_7893);
											mem_vec_7893 = vec_102;
											scal_48 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h + 2) + c];
											vec_105 = _mm512_set1_ps(scal_48);
											vec_106 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * (h + 2) + F * c + f]);

											vec_104 = _mm512_fmadd_ps(vec_105, vec_106, mem_vec_7888);
											mem_vec_7888 = vec_104;
											scal_49 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h + 2) + c];
											vec_108 = _mm512_set1_ps(scal_49);


											vec_107 = _mm512_fmadd_ps(vec_108, vec_106, mem_vec_7889);
											mem_vec_7889 = vec_107;
											scal_50 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h + 2) + c];
											vec_110 = _mm512_set1_ps(scal_50);


											vec_109 = _mm512_fmadd_ps(vec_110, vec_106, mem_vec_7890);
											mem_vec_7890 = vec_109;
											scal_51 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h + 2) + c];
											vec_112 = _mm512_set1_ps(scal_51);


											vec_111 = _mm512_fmadd_ps(vec_112, vec_106, mem_vec_7891);
											mem_vec_7891 = vec_111;
											scal_52 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h + 2) + c];
											vec_114 = _mm512_set1_ps(scal_52);


											vec_113 = _mm512_fmadd_ps(vec_114, vec_106, mem_vec_7892);
											mem_vec_7892 = vec_113;
											scal_53 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h + 2) + c];
											vec_116 = _mm512_set1_ps(scal_53);


											vec_115 = _mm512_fmadd_ps(vec_116, vec_106, mem_vec_7893);
											mem_vec_7893 = vec_115;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7888);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7889);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7890);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7891);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7892);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7893);
							}
						}
					}
				}
		}
	}
}


}