#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (1, c); T (4, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (256, c);
  T (2, f); T (4, c)]
*/
IND_TYPE c, cp_0, c1898_p_0, c1899_p_0, c1900_p_0, cp_1, c1898_p_1, c1899_p_1, cp_2, c1898_p_2, cp_3, c1898, c1899, c1900, f, fp_0, f1254_p_0, fp_1, f1254, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y642 = 0;
IND_TYPE x788 = 0;
IND_TYPE h606 = 0;
IND_TYPE w = 0;
IND_TYPE c1901 = 0;
IND_TYPE f1255 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_7836 ,mem_vec_7837 ,mem_vec_7838 ,mem_vec_7839 ,mem_vec_7840 ,mem_vec_7841 ,mem_vec_7842 ,mem_vec_7843 ,mem_vec_7844 ,mem_vec_7845 ,mem_vec_7846 ,mem_vec_7847 ,mem_vec_7848 ,mem_vec_7849 ,mem_vec_7850 ,mem_vec_7851 ,mem_vec_7852 ,mem_vec_7853 ,mem_vec_7854 ,mem_vec_7855 ,mem_vec_7856 ,mem_vec_7857 ,mem_vec_7858 ,mem_vec_7859 ,mem_vec_7860 ,mem_vec_7861 ,mem_vec_7862 ,mem_vec_7863 ,mem_vec_7864 ,mem_vec_7865 ,mem_vec_7866 ,mem_vec_7867 ,mem_vec_7868 ,mem_vec_7869 ,mem_vec_7870 ,mem_vec_7871 ,mem_vec_7872 ,mem_vec_7873 ,mem_vec_7874 ,mem_vec_7875 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 4) (1024 / 256)
for (c1900 = c1901, c1900_p_0 = 0;
	c1900 < c1901 + 1024;
	c1900 += 256, c1900_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 256, f = 1024
	// T (f, 2) (1024 / 512)
	for (f1254 = f1255, f1254_p_0 = 0;
		f1254 < f1255 + 1024;
		f1254 += 512, f1254_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 256, f = 512
		// T (c, 256) (256 / 1)
		for (c1899 = c1900, c1899_p_1 = c1900_p_0, c1899_p_0 = 0;
			c1899 < c1900 + 256;
			c1899 += 1, c1899_p_1 += 1, c1899_p_0 += 1){
				for (y = y642, yp_0 = 0;
					y < y642 + 4;
					y += 2, yp_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 512
					// T (f, 4) (512 / 128)
					for (f = f1254, fp_1 = f1254_p_0, fp_0 = 0;
						f < f1254 + 512;
						f += 128, fp_1 += 128, fp_0 += 128){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 128
						// T (c, 1) (1 / 1)
						for (c1898 = c1899, c1898_p_2 = c1899_p_1, c1898_p_1 = c1899_p_0, c1898_p_0 = 0;
							c1898 < c1899 + 1;
							c1898 += 1, c1898_p_2 += 1, c1898_p_1 += 1, c1898_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 128
							// T (h, 3) (3 / 1)
							for (h = h606, hp_0 = 0;
								h < h606 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 128
								// T (x, 7) (7 / 1)
								for (x = x788, xp_0 = 0;
									x < x788 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7836 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7837 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7838 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7839 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7840 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
											mem_vec_7841 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
											mem_vec_7842 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
											mem_vec_7843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
											mem_vec_7844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
											mem_vec_7849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
											mem_vec_7850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
											mem_vec_7851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 128
											// T (c, 1) (1 / 1)
											for (c = c1898, cp_3 = c1898_p_2, cp_2 = c1898_p_1, cp_1 = c1898_p_0, cp_0 = 0;
												c < c1898 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7836);
												mem_vec_7836 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7837);
												mem_vec_7837 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7838);
												mem_vec_7838 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7839);
												mem_vec_7839 = vec_7;

												vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

												vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7840);
												mem_vec_7840 = vec_9;

												vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

												vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7841);
												mem_vec_7841 = vec_11;

												vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

												vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7842);
												mem_vec_7842 = vec_13;

												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

												vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7843);
												mem_vec_7843 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm512_set1_ps(scal_1);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7844);
												mem_vec_7844 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7845);
												mem_vec_7845 = vec_19;



												vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7846);
												mem_vec_7846 = vec_20;



												vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7847);
												mem_vec_7847 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7848);
												mem_vec_7848 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7849);
												mem_vec_7849 = vec_23;



												vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7850);
												mem_vec_7850 = vec_24;



												vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7851);
												mem_vec_7851 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_27 = _mm512_set1_ps(scal_2);
												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_7836);
												mem_vec_7836 = vec_26;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_7837);
												mem_vec_7837 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_7838);
												mem_vec_7838 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_7839);
												mem_vec_7839 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

												vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_7840);
												mem_vec_7840 = vec_35;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

												vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_7841);
												mem_vec_7841 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

												vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_7842);
												mem_vec_7842 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

												vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_7843);
												mem_vec_7843 = vec_41;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_3);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7844);
												mem_vec_7844 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7845);
												mem_vec_7845 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7846);
												mem_vec_7846 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_7847);
												mem_vec_7847 = vec_47;



												vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_7848);
												mem_vec_7848 = vec_48;



												vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_7849);
												mem_vec_7849 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_7850);
												mem_vec_7850 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_7851);
												mem_vec_7851 = vec_51;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_53 = _mm512_set1_ps(scal_4);
												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_7836);
												mem_vec_7836 = vec_52;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_7837);
												mem_vec_7837 = vec_55;

												vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_7838);
												mem_vec_7838 = vec_57;

												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_7839);
												mem_vec_7839 = vec_59;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

												vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_7840);
												mem_vec_7840 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

												vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_7841);
												mem_vec_7841 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

												vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_7842);
												mem_vec_7842 = vec_65;

												vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

												vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_7843);
												mem_vec_7843 = vec_67;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_70 = _mm512_set1_ps(scal_5);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_7844);
												mem_vec_7844 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_7845);
												mem_vec_7845 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_7846);
												mem_vec_7846 = vec_72;



												vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_7847);
												mem_vec_7847 = vec_73;



												vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_7848);
												mem_vec_7848 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_7849);
												mem_vec_7849 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_7850);
												mem_vec_7850 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_7851);
												mem_vec_7851 = vec_77;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7839);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_7840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_7841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_7842);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_7843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_7848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_7849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_7850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_7851);
								}
							}
						}
					}
				}
				for (y = y642 + 4, yp_0 = 0;
					y < y642 + 4 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 512
					// T (f, 4) (512 / 128)
					for (f = f1254, fp_1 = f1254_p_0, fp_0 = 0;
						f < f1254 + 512;
						f += 128, fp_1 += 128, fp_0 += 128){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 128
						// T (c, 1) (1 / 1)
						for (c1898 = c1899, c1898_p_2 = c1899_p_1, c1898_p_1 = c1899_p_0, c1898_p_0 = 0;
							c1898 < c1899 + 1;
							c1898 += 1, c1898_p_2 += 1, c1898_p_1 += 1, c1898_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 128
							// T (h, 3) (3 / 1)
							for (h = h606, hp_0 = 0;
								h < h606 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 128
								// T (x, 7) (7 / 1)
								for (x = x788, xp_0 = 0;
									x < x788 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7852 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7853 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7854 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7855 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7856 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
											mem_vec_7857 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
											mem_vec_7858 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
											mem_vec_7859 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
											mem_vec_7860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
											mem_vec_7865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
											mem_vec_7866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
											mem_vec_7867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
											mem_vec_7868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_7872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64]);
											mem_vec_7873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80]);
											mem_vec_7874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96]);
											mem_vec_7875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 128
											// T (c, 1) (1 / 1)
											for (c = c1898, cp_3 = c1898_p_2, cp_2 = c1898_p_1, cp_1 = c1898_p_0, cp_0 = 0;
												c < c1898 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7852);
												mem_vec_7852 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7853);
												mem_vec_7853 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7854);
												mem_vec_7854 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7855);
												mem_vec_7855 = vec_7;

												vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

												vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_7856);
												mem_vec_7856 = vec_9;

												vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

												vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_7857);
												mem_vec_7857 = vec_11;

												vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

												vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_7858);
												mem_vec_7858 = vec_13;

												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

												vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_7859);
												mem_vec_7859 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm512_set1_ps(scal_1);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7860);
												mem_vec_7860 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7861);
												mem_vec_7861 = vec_19;



												vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_7862);
												mem_vec_7862 = vec_20;



												vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_7863);
												mem_vec_7863 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_7864);
												mem_vec_7864 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_7865);
												mem_vec_7865 = vec_23;



												vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_7866);
												mem_vec_7866 = vec_24;



												vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_7867);
												mem_vec_7867 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm512_set1_ps(scal_2);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7868);
												mem_vec_7868 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7869);
												mem_vec_7869 = vec_28;



												vec_29 = _mm512_fmadd_ps(vec_27, vec_6, mem_vec_7870);
												mem_vec_7870 = vec_29;



												vec_30 = _mm512_fmadd_ps(vec_27, vec_8, mem_vec_7871);
												mem_vec_7871 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_27, vec_10, mem_vec_7872);
												mem_vec_7872 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_27, vec_12, mem_vec_7873);
												mem_vec_7873 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_27, vec_14, mem_vec_7874);
												mem_vec_7874 = vec_33;



												vec_34 = _mm512_fmadd_ps(vec_27, vec_16, mem_vec_7875);
												mem_vec_7875 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm512_set1_ps(scal_3);
												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_7852);
												mem_vec_7852 = vec_35;

												vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_7853);
												mem_vec_7853 = vec_38;

												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_40 = _mm512_fmadd_ps(vec_36, vec_41, mem_vec_7854);
												mem_vec_7854 = vec_40;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_42 = _mm512_fmadd_ps(vec_36, vec_43, mem_vec_7855);
												mem_vec_7855 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

												vec_44 = _mm512_fmadd_ps(vec_36, vec_45, mem_vec_7856);
												mem_vec_7856 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

												vec_46 = _mm512_fmadd_ps(vec_36, vec_47, mem_vec_7857);
												mem_vec_7857 = vec_46;

												vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

												vec_48 = _mm512_fmadd_ps(vec_36, vec_49, mem_vec_7858);
												mem_vec_7858 = vec_48;

												vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

												vec_50 = _mm512_fmadd_ps(vec_36, vec_51, mem_vec_7859);
												mem_vec_7859 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm512_set1_ps(scal_4);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_7860);
												mem_vec_7860 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_7861);
												mem_vec_7861 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_41, mem_vec_7862);
												mem_vec_7862 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_7863);
												mem_vec_7863 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_7864);
												mem_vec_7864 = vec_57;



												vec_58 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_7865);
												mem_vec_7865 = vec_58;



												vec_59 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_7866);
												mem_vec_7866 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_7867);
												mem_vec_7867 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm512_set1_ps(scal_5);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_7868);
												mem_vec_7868 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_7869);
												mem_vec_7869 = vec_63;



												vec_64 = _mm512_fmadd_ps(vec_62, vec_41, mem_vec_7870);
												mem_vec_7870 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_7871);
												mem_vec_7871 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_7872);
												mem_vec_7872 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_62, vec_47, mem_vec_7873);
												mem_vec_7873 = vec_67;



												vec_68 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_7874);
												mem_vec_7874 = vec_68;



												vec_69 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_7875);
												mem_vec_7875 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm512_set1_ps(scal_6);
												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_7852);
												mem_vec_7852 = vec_70;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_7853);
												mem_vec_7853 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_75 = _mm512_fmadd_ps(vec_71, vec_76, mem_vec_7854);
												mem_vec_7854 = vec_75;

												vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_77 = _mm512_fmadd_ps(vec_71, vec_78, mem_vec_7855);
												mem_vec_7855 = vec_77;

												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

												vec_79 = _mm512_fmadd_ps(vec_71, vec_80, mem_vec_7856);
												mem_vec_7856 = vec_79;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

												vec_81 = _mm512_fmadd_ps(vec_71, vec_82, mem_vec_7857);
												mem_vec_7857 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

												vec_83 = _mm512_fmadd_ps(vec_71, vec_84, mem_vec_7858);
												mem_vec_7858 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

												vec_85 = _mm512_fmadd_ps(vec_71, vec_86, mem_vec_7859);
												mem_vec_7859 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_7);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_7860);
												mem_vec_7860 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_7861);
												mem_vec_7861 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_7862);
												mem_vec_7862 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_7863);
												mem_vec_7863 = vec_91;



												vec_92 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_7864);
												mem_vec_7864 = vec_92;



												vec_93 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_7865);
												mem_vec_7865 = vec_93;



												vec_94 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_7866);
												mem_vec_7866 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_7867);
												mem_vec_7867 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm512_set1_ps(scal_8);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_7868);
												mem_vec_7868 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_7869);
												mem_vec_7869 = vec_98;



												vec_99 = _mm512_fmadd_ps(vec_97, vec_76, mem_vec_7870);
												mem_vec_7870 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_7871);
												mem_vec_7871 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_7872);
												mem_vec_7872 = vec_101;



												vec_102 = _mm512_fmadd_ps(vec_97, vec_82, mem_vec_7873);
												mem_vec_7873 = vec_102;



												vec_103 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_7874);
												mem_vec_7874 = vec_103;



												vec_104 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_7875);
												mem_vec_7875 = vec_104;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_7856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_7857);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_7858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_7859);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7860);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7861);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7862);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7863);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_7864);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_7865);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_7866);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_7867);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7868);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7869);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7870);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7871);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64], mem_vec_7872);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80], mem_vec_7873);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96], mem_vec_7874);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112], mem_vec_7875);
								}
							}
						}
					}
				}
		}
	}
}


}