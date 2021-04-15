#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (4, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (64, c);
  T (16, f); T (1, c)]
*/
IND_TYPE c, cp_0, c858_p_0, c859_p_0, c860_p_0, cp_1, c858_p_1, c859_p_1, cp_2, c858_p_2, cp_3, c858, c859, c860, f, fp_0, f606_p_0, fp_1, f606, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y404 = 0;
IND_TYPE x404 = 0;
IND_TYPE h330 = 0;
IND_TYPE w = 0;
IND_TYPE c861 = 0;
IND_TYPE f607 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7056 ,mem_vec_7057 ,mem_vec_7058 ,mem_vec_7059 ,mem_vec_7060 ,mem_vec_7061 ,mem_vec_7062 ,mem_vec_7063 ,mem_vec_7064 ,mem_vec_7065 ,mem_vec_7066 ,mem_vec_7067 ,mem_vec_7068 ,mem_vec_7069 ,mem_vec_7070 ,mem_vec_7071 ,mem_vec_7072 ,mem_vec_7073 ,mem_vec_7074 ,mem_vec_7075 ,mem_vec_7076 ,mem_vec_7077 ,mem_vec_7078 ,mem_vec_7079 ,mem_vec_7080 ,mem_vec_7081 ,mem_vec_7082 ,mem_vec_7083 ,mem_vec_7084 ,mem_vec_7085 ,mem_vec_7086 ,mem_vec_7087 ,mem_vec_7088 ,mem_vec_7089 ,mem_vec_7090 ,mem_vec_7091 ,mem_vec_7092 ,mem_vec_7093 ,mem_vec_7094 ,mem_vec_7095 ,mem_vec_7096 ,mem_vec_7097 ,mem_vec_7098 ,mem_vec_7099 ,mem_vec_7100 ,mem_vec_7101 ,mem_vec_7102 ,mem_vec_7103 ,mem_vec_7104 ,mem_vec_7105 ,mem_vec_7106 ,mem_vec_7107 ,mem_vec_7108 ,mem_vec_7109 ,mem_vec_7110 ,mem_vec_7111 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 1) (1024 / 1024)
for (c860 = c861, c860_p_0 = 0;
	c860 < c861 + 1024;
	c860 += 1024, c860_p_0 += 1024){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
	// T (f, 16) (1024 / 64)
	for (f606 = f607, f606_p_0 = 0;
		f606 < f607 + 1024;
		f606 += 64, f606_p_0 += 64){
		// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 64
		// T (c, 64) (1024 / 16)
		for (c859 = c860, c859_p_1 = c860_p_0, c859_p_0 = 0;
			c859 < c860 + 1024;
			c859 += 16, c859_p_1 += 16, c859_p_0 += 16){
				for (y = y404, yp_0 = 0;
					y < y404 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
					// T (f, 1) (64 / 64)
					for (f = f606, fp_1 = f606_p_0, fp_0 = 0;
						f < f606 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (c, 4) (16 / 4)
						for (c858 = c859, c858_p_2 = c859_p_1, c858_p_1 = c859_p_0, c858_p_0 = 0;
							c858 < c859 + 16;
							c858 += 4, c858_p_2 += 4, c858_p_1 += 4, c858_p_0 += 4){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h330, hp_0 = 0;
								h < h330 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 64
								// T (x, 7) (7 / 1)
								for (x = x404, xp_0 = 0;
									x < x404 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7056 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7057 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7058 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7059 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7060 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7061 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_7062 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7063 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_7064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_7070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_7072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_7078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_7079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c858, cp_3 = c858_p_2, cp_2 = c858_p_1, cp_1 = c858_p_0, cp_0 = 0;
												c < c858 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7056);
												mem_vec_7056 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7057);
												mem_vec_7057 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7058);
												mem_vec_7058 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7059);
												mem_vec_7059 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_7060);
												mem_vec_7060 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_7061);
												mem_vec_7061 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_7062);
												mem_vec_7062 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_7063);
												mem_vec_7063 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_7064);
												mem_vec_7064 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_7065);
												mem_vec_7065 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_7066);
												mem_vec_7066 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_7067);
												mem_vec_7067 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_7068);
												mem_vec_7068 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_7069);
												mem_vec_7069 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_7070);
												mem_vec_7070 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_7071);
												mem_vec_7071 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_7072);
												mem_vec_7072 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_7073);
												mem_vec_7073 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_7074);
												mem_vec_7074 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_7075);
												mem_vec_7075 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_7076);
												mem_vec_7076 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_7077);
												mem_vec_7077 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_7078);
												mem_vec_7078 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_7079);
												mem_vec_7079 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_7056);
												mem_vec_7056 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_7057);
												mem_vec_7057 = vec_38;

												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_7058);
												mem_vec_7058 = vec_40;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_7059);
												mem_vec_7059 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_7060);
												mem_vec_7060 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_7061);
												mem_vec_7061 = vec_46;

												vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_7062);
												mem_vec_7062 = vec_48;

												vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_7063);
												mem_vec_7063 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm256_set1_ps(scal_4);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_7064);
												mem_vec_7064 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_7065);
												mem_vec_7065 = vec_54;



												vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_7066);
												mem_vec_7066 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_7067);
												mem_vec_7067 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_7068);
												mem_vec_7068 = vec_57;



												vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_7069);
												mem_vec_7069 = vec_58;



												vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_7070);
												mem_vec_7070 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_7071);
												mem_vec_7071 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_7072);
												mem_vec_7072 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_7073);
												mem_vec_7073 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_7074);
												mem_vec_7074 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_7075);
												mem_vec_7075 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_7076);
												mem_vec_7076 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_7077);
												mem_vec_7077 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_7078);
												mem_vec_7078 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_7079);
												mem_vec_7079 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_7056);
												mem_vec_7056 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_7057);
												mem_vec_7057 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_7058);
												mem_vec_7058 = vec_75;

												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_7059);
												mem_vec_7059 = vec_77;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_7060);
												mem_vec_7060 = vec_79;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_7061);
												mem_vec_7061 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_7062);
												mem_vec_7062 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_7063);
												mem_vec_7063 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_7);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_7064);
												mem_vec_7064 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_7065);
												mem_vec_7065 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_7066);
												mem_vec_7066 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_7067);
												mem_vec_7067 = vec_91;



												vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_7068);
												mem_vec_7068 = vec_92;



												vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_7069);
												mem_vec_7069 = vec_93;



												vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_7070);
												mem_vec_7070 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_7071);
												mem_vec_7071 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm256_set1_ps(scal_8);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_7072);
												mem_vec_7072 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_7073);
												mem_vec_7073 = vec_98;



												vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_7074);
												mem_vec_7074 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_7075);
												mem_vec_7075 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_7076);
												mem_vec_7076 = vec_101;



												vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_7077);
												mem_vec_7077 = vec_102;



												vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_7078);
												mem_vec_7078 = vec_103;



												vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_7079);
												mem_vec_7079 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7056);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7057);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7058);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7059);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7060);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_7061);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7062);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_7063);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7064);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7065);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7066);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7067);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7068);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_7069);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7070);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_7071);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7072);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7073);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7074);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7075);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7076);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_7077);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7078);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_7079);
								}
							}
						}
					}
				}
				for (y = y404 + 3, yp_0 = 0;
					y < y404 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
					// T (f, 1) (64 / 64)
					for (f = f606, fp_1 = f606_p_0, fp_0 = 0;
						f < f606 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 16, f = 64
						// T (c, 4) (16 / 4)
						for (c858 = c859, c858_p_2 = c859_p_1, c858_p_1 = c859_p_0, c858_p_0 = 0;
							c858 < c859 + 16;
							c858 += 4, c858_p_2 += 4, c858_p_1 += 4, c858_p_0 += 4){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h330, hp_0 = 0;
								h < h330 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 64
								// T (x, 7) (7 / 1)
								for (x = x404, xp_0 = 0;
									x < x404 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7080 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7081 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_7082 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7083 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_7084 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7085 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_7086 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7087 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_7088 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7089 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_7090 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7091 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_7092 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7093 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_7094 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7095 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_7096 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7097 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_7098 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7099 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_7100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_7102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_7103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											mem_vec_7104 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7105 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_7106 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7107 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_7108 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_7109 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
											mem_vec_7110 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_7111 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c858, cp_3 = c858_p_2, cp_2 = c858_p_1, cp_1 = c858_p_0, cp_0 = 0;
												c < c858 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7080);
												mem_vec_7080 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7081);
												mem_vec_7081 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7082);
												mem_vec_7082 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7083);
												mem_vec_7083 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_7084);
												mem_vec_7084 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_7085);
												mem_vec_7085 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_7086);
												mem_vec_7086 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_7087);
												mem_vec_7087 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_7088);
												mem_vec_7088 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_7089);
												mem_vec_7089 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_7090);
												mem_vec_7090 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_7091);
												mem_vec_7091 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_7092);
												mem_vec_7092 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_7093);
												mem_vec_7093 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_7094);
												mem_vec_7094 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_7095);
												mem_vec_7095 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_7096);
												mem_vec_7096 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_7097);
												mem_vec_7097 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_7098);
												mem_vec_7098 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_7099);
												mem_vec_7099 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_7100);
												mem_vec_7100 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_7101);
												mem_vec_7101 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_7102);
												mem_vec_7102 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_7103);
												mem_vec_7103 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_7104);
												mem_vec_7104 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_7105);
												mem_vec_7105 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_7106);
												mem_vec_7106 = vec_38;



												vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_7107);
												mem_vec_7107 = vec_39;



												vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_7108);
												mem_vec_7108 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_7109);
												mem_vec_7109 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_7110);
												mem_vec_7110 = vec_42;



												vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_7111);
												mem_vec_7111 = vec_43;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_45 = _mm256_set1_ps(scal_4);
												vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_7080);
												mem_vec_7080 = vec_44;

												vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_7081);
												mem_vec_7081 = vec_47;

												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_7082);
												mem_vec_7082 = vec_49;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_7083);
												mem_vec_7083 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_7084);
												mem_vec_7084 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_7085);
												mem_vec_7085 = vec_55;

												vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_7086);
												mem_vec_7086 = vec_57;

												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_7087);
												mem_vec_7087 = vec_59;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_7088);
												mem_vec_7088 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_7089);
												mem_vec_7089 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_7090);
												mem_vec_7090 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_7091);
												mem_vec_7091 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_7092);
												mem_vec_7092 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_7093);
												mem_vec_7093 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_7094);
												mem_vec_7094 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_7095);
												mem_vec_7095 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_7096);
												mem_vec_7096 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_7097);
												mem_vec_7097 = vec_72;



												vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_7098);
												mem_vec_7098 = vec_73;



												vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_7099);
												mem_vec_7099 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_7100);
												mem_vec_7100 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_7101);
												mem_vec_7101 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_7102);
												mem_vec_7102 = vec_77;



												vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_7103);
												mem_vec_7103 = vec_78;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_80 = _mm256_set1_ps(scal_7);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_7104);
												mem_vec_7104 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_7105);
												mem_vec_7105 = vec_81;



												vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_7106);
												mem_vec_7106 = vec_82;



												vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_7107);
												mem_vec_7107 = vec_83;



												vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_7108);
												mem_vec_7108 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_7109);
												mem_vec_7109 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_7110);
												mem_vec_7110 = vec_86;



												vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_7111);
												mem_vec_7111 = vec_87;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_89 = _mm256_set1_ps(scal_8);
												vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_7080);
												mem_vec_7080 = vec_88;

												vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_7081);
												mem_vec_7081 = vec_91;

												vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_7082);
												mem_vec_7082 = vec_93;

												vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_7083);
												mem_vec_7083 = vec_95;

												vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_7084);
												mem_vec_7084 = vec_97;

												vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_7085);
												mem_vec_7085 = vec_99;

												vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_7086);
												mem_vec_7086 = vec_101;

												vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_7087);
												mem_vec_7087 = vec_103;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_106 = _mm256_set1_ps(scal_9);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_7088);
												mem_vec_7088 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_7089);
												mem_vec_7089 = vec_107;



												vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_7090);
												mem_vec_7090 = vec_108;



												vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_7091);
												mem_vec_7091 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_7092);
												mem_vec_7092 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_7093);
												mem_vec_7093 = vec_111;



												vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_7094);
												mem_vec_7094 = vec_112;



												vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_7095);
												mem_vec_7095 = vec_113;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_115 = _mm256_set1_ps(scal_10);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_7096);
												mem_vec_7096 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_7097);
												mem_vec_7097 = vec_116;



												vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_7098);
												mem_vec_7098 = vec_117;



												vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_7099);
												mem_vec_7099 = vec_118;



												vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_7100);
												mem_vec_7100 = vec_119;



												vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_7101);
												mem_vec_7101 = vec_120;



												vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_7102);
												mem_vec_7102 = vec_121;



												vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_7103);
												mem_vec_7103 = vec_122;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_124 = _mm256_set1_ps(scal_11);


												vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_7104);
												mem_vec_7104 = vec_123;



												vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_7105);
												mem_vec_7105 = vec_125;



												vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_7106);
												mem_vec_7106 = vec_126;



												vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_7107);
												mem_vec_7107 = vec_127;



												vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_7108);
												mem_vec_7108 = vec_128;



												vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_7109);
												mem_vec_7109 = vec_129;



												vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_7110);
												mem_vec_7110 = vec_130;



												vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_7111);
												mem_vec_7111 = vec_131;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7080);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7081);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7082);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7083);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7084);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_7085);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7086);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_7087);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7088);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7089);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7090);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7091);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7092);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_7093);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7094);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_7095);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7096);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7097);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7098);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7099);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7100);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_7101);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7102);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_7103);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7104);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7105);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7106);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7107);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7108);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_7109);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7110);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_7111);
								}
							}
						}
					}
				}
		}
	}
}


}