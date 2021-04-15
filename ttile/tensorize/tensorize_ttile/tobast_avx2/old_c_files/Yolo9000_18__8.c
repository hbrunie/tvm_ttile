#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (512, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]; T (2, f);
  T (1, c); T (2, f)]
*/
IND_TYPE c, cp_0, c1176_p_0, cp_1, c1176, f, fp_0, f1568_p_0, f1569_p_0, fp_1, f1568_p_1, fp_2, f1568, f1569, h, hp_0, x, xp_0, x1176_p_0, xp_1, x1176, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y784 = 0;
IND_TYPE x1177 = 0;
IND_TYPE h584 = 0;
IND_TYPE w = 0;
IND_TYPE c1177 = 0;
IND_TYPE f1570 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_16052 ,mem_vec_16053 ,mem_vec_16054 ,mem_vec_16055 ,mem_vec_16056 ,mem_vec_16057 ,mem_vec_16058 ,mem_vec_16059 ,mem_vec_16060 ,mem_vec_16061 ,mem_vec_16062 ,mem_vec_16063 ,mem_vec_16064 ,mem_vec_16065 ,mem_vec_16066 ,mem_vec_16067 ,mem_vec_16068 ,mem_vec_16069 ,mem_vec_16070 ,mem_vec_16071 ,mem_vec_16072 ,mem_vec_16073 ,mem_vec_16074 ,mem_vec_16075 ,mem_vec_16076 ,mem_vec_16077 ,mem_vec_16078 ,mem_vec_16079 ,mem_vec_16080 ,mem_vec_16081 ,mem_vec_16082 ,mem_vec_16083 ,mem_vec_16084 ,mem_vec_16085 ,mem_vec_16086 ,mem_vec_16087 ,mem_vec_16088 ,mem_vec_16089 ,mem_vec_16090 ,mem_vec_16091 ,mem_vec_16092 ,mem_vec_16093 ,mem_vec_16094 ,mem_vec_16095 ,mem_vec_16096 ,mem_vec_16097 ,mem_vec_16098 ,mem_vec_16099 ,mem_vec_16100 ,mem_vec_16101 ,mem_vec_16102 ,mem_vec_16103 ,mem_vec_16104 ,mem_vec_16105 ,mem_vec_16106 ,mem_vec_16107 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_123 ,vec_124 ,vec_125 ,vec_126 ,vec_127 ,vec_128 ,vec_129 ,vec_13 ,vec_130 ,vec_131 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 2) (1024 / 512)
for (f1569 = f1570, f1569_p_0 = 0;
	f1569 < f1570 + 1024;
	f1569 += 512, f1569_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
	// T (c, 1) (512 / 512)
	for (c1176 = c1177, c1176_p_0 = 0;
		c1176 < c1177 + 512;
		c1176 += 512, c1176_p_0 += 512){
		// y = 17, x = 17, h = 3, w = 3, c = 512, f = 512
		// T (f, 2) (512 / 256)
		for (f1568 = f1569, f1568_p_1 = f1569_p_0, f1568_p_0 = 0;
			f1568 < f1569 + 512;
			f1568 += 256, f1568_p_1 += 256, f1568_p_0 += 256){
				for (y = y784, yp_0 = 0;
					y < y784 + 9;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 256
					// T (x, 17) (17 / 1)
					for (x1176 = x1177, x1176_p_0 = 0;
						x1176 < x1177 + 17;
						x1176 += 1, x1176_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 512, f = 256
						// T (f, 4) (256 / 64)
						for (f = f1568, fp_2 = f1568_p_1, fp_1 = f1568_p_0, fp_0 = 0;
							f < f1568 + 256;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 512, f = 64
							// T (h, 3) (3 / 1)
							for (h = h584, hp_0 = 0;
								h < h584 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 512, f = 64
								// T (x, 1) (1 / 1)
								for (x = x1176, xp_1 = x1176_p_0, xp_0 = 0;
									x < x1176 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_16052 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_16053 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_16054 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_16055 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_16056 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_16057 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_16058 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_16059 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_16060 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_16061 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_16062 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_16063 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_16064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_16065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_16066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_16067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_16068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_16069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_16070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_16071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_16072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_16073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_16074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_16075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 512, f = 64
											// T (c, 512) (512 / 1)
											for (c = c1176, cp_1 = c1176_p_0, cp_0 = 0;
												c < c1176 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_16052);
												mem_vec_16052 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_16053);
												mem_vec_16053 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_16054);
												mem_vec_16054 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_16055);
												mem_vec_16055 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_16056);
												mem_vec_16056 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_16057);
												mem_vec_16057 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_16058);
												mem_vec_16058 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_16059);
												mem_vec_16059 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_16060);
												mem_vec_16060 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_16061);
												mem_vec_16061 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_16062);
												mem_vec_16062 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_16063);
												mem_vec_16063 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_16064);
												mem_vec_16064 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_16065);
												mem_vec_16065 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_16066);
												mem_vec_16066 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_16067);
												mem_vec_16067 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_16068);
												mem_vec_16068 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_16069);
												mem_vec_16069 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_16070);
												mem_vec_16070 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_16071);
												mem_vec_16071 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_16072);
												mem_vec_16072 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_16073);
												mem_vec_16073 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_16074);
												mem_vec_16074 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_16075);
												mem_vec_16075 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_16052);
												mem_vec_16052 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_16053);
												mem_vec_16053 = vec_38;

												vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_40 = _mm256_fmadd_ps(vec_36, vec_41, mem_vec_16054);
												mem_vec_16054 = vec_40;

												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_42 = _mm256_fmadd_ps(vec_36, vec_43, mem_vec_16055);
												mem_vec_16055 = vec_42;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm256_fmadd_ps(vec_36, vec_45, mem_vec_16056);
												mem_vec_16056 = vec_44;

												vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_46 = _mm256_fmadd_ps(vec_36, vec_47, mem_vec_16057);
												mem_vec_16057 = vec_46;

												vec_49 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_48 = _mm256_fmadd_ps(vec_36, vec_49, mem_vec_16058);
												mem_vec_16058 = vec_48;

												vec_51 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_50 = _mm256_fmadd_ps(vec_36, vec_51, mem_vec_16059);
												mem_vec_16059 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm256_set1_ps(scal_4);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_16060);
												mem_vec_16060 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_16061);
												mem_vec_16061 = vec_54;



												vec_55 = _mm256_fmadd_ps(vec_53, vec_41, mem_vec_16062);
												mem_vec_16062 = vec_55;



												vec_56 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_16063);
												mem_vec_16063 = vec_56;



												vec_57 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_16064);
												mem_vec_16064 = vec_57;



												vec_58 = _mm256_fmadd_ps(vec_53, vec_47, mem_vec_16065);
												mem_vec_16065 = vec_58;



												vec_59 = _mm256_fmadd_ps(vec_53, vec_49, mem_vec_16066);
												mem_vec_16066 = vec_59;



												vec_60 = _mm256_fmadd_ps(vec_53, vec_51, mem_vec_16067);
												mem_vec_16067 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_16068);
												mem_vec_16068 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_16069);
												mem_vec_16069 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_41, mem_vec_16070);
												mem_vec_16070 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_16071);
												mem_vec_16071 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_16072);
												mem_vec_16072 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_47, mem_vec_16073);
												mem_vec_16073 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_49, mem_vec_16074);
												mem_vec_16074 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_51, mem_vec_16075);
												mem_vec_16075 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_16052);
												mem_vec_16052 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_16053);
												mem_vec_16053 = vec_73;

												vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_75 = _mm256_fmadd_ps(vec_71, vec_76, mem_vec_16054);
												mem_vec_16054 = vec_75;

												vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_77 = _mm256_fmadd_ps(vec_71, vec_78, mem_vec_16055);
												mem_vec_16055 = vec_77;

												vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_79 = _mm256_fmadd_ps(vec_71, vec_80, mem_vec_16056);
												mem_vec_16056 = vec_79;

												vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_81 = _mm256_fmadd_ps(vec_71, vec_82, mem_vec_16057);
												mem_vec_16057 = vec_81;

												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_83 = _mm256_fmadd_ps(vec_71, vec_84, mem_vec_16058);
												mem_vec_16058 = vec_83;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_85 = _mm256_fmadd_ps(vec_71, vec_86, mem_vec_16059);
												mem_vec_16059 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm256_set1_ps(scal_7);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_16060);
												mem_vec_16060 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_16061);
												mem_vec_16061 = vec_89;



												vec_90 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_16062);
												mem_vec_16062 = vec_90;



												vec_91 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_16063);
												mem_vec_16063 = vec_91;



												vec_92 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_16064);
												mem_vec_16064 = vec_92;



												vec_93 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_16065);
												mem_vec_16065 = vec_93;



												vec_94 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_16066);
												mem_vec_16066 = vec_94;



												vec_95 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_16067);
												mem_vec_16067 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm256_set1_ps(scal_8);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_16068);
												mem_vec_16068 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_16069);
												mem_vec_16069 = vec_98;



												vec_99 = _mm256_fmadd_ps(vec_97, vec_76, mem_vec_16070);
												mem_vec_16070 = vec_99;



												vec_100 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_16071);
												mem_vec_16071 = vec_100;



												vec_101 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_16072);
												mem_vec_16072 = vec_101;



												vec_102 = _mm256_fmadd_ps(vec_97, vec_82, mem_vec_16073);
												mem_vec_16073 = vec_102;



												vec_103 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_16074);
												mem_vec_16074 = vec_103;



												vec_104 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_16075);
												mem_vec_16075 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16052);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_16053);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16054);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_16055);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16056);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_16057);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16058);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_16059);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16060);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_16061);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16062);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_16063);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16064);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_16065);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16066);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_16067);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16068);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_16069);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16070);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_16071);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16072);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_16073);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16074);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_16075);
								}
							}
						}
					}
				}
				for (y = y784 + 9, yp_0 = 0;
					y < y784 + 9 + 8;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 512, f = 256
					// T (x, 17) (17 / 1)
					for (x1176 = x1177, x1176_p_0 = 0;
						x1176 < x1177 + 17;
						x1176 += 1, x1176_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 512, f = 256
						// T (f, 4) (256 / 64)
						for (f = f1568, fp_2 = f1568_p_1, fp_1 = f1568_p_0, fp_0 = 0;
							f < f1568 + 256;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 512, f = 64
							// T (h, 3) (3 / 1)
							for (h = h584, hp_0 = 0;
								h < h584 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 512, f = 64
								// T (x, 1) (1 / 1)
								for (x = x1176, xp_1 = x1176_p_0, xp_0 = 0;
									x < x1176 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_16076 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_16077 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_16078 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_16079 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_16080 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_16081 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 40]);
											mem_vec_16082 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_16083 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 56]);
											mem_vec_16084 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_16085 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_16086 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_16087 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_16088 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_16089 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40]);
											mem_vec_16090 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_16091 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56]);
											mem_vec_16092 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_16093 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_16094 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_16095 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_16096 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_16097 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40]);
											mem_vec_16098 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_16099 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56]);
											mem_vec_16100 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_16101 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_16102 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_16103 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_16104 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_16105 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40]);
											mem_vec_16106 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_16107 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 512, f = 64
											// T (c, 512) (512 / 1)
											for (c = c1176, cp_1 = c1176_p_0, cp_0 = 0;
												c < c1176 + 512;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_16076);
												mem_vec_16076 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_16077);
												mem_vec_16077 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_16078);
												mem_vec_16078 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_16079);
												mem_vec_16079 = vec_7;

												vec_10 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_16080);
												mem_vec_16080 = vec_9;

												vec_12 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 40]);

												vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_16081);
												mem_vec_16081 = vec_11;

												vec_14 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_16082);
												mem_vec_16082 = vec_13;

												vec_16 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 56]);

												vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_16083);
												mem_vec_16083 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm256_set1_ps(scal_1);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_16084);
												mem_vec_16084 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_16085);
												mem_vec_16085 = vec_19;



												vec_20 = _mm256_fmadd_ps(vec_18, vec_6, mem_vec_16086);
												mem_vec_16086 = vec_20;



												vec_21 = _mm256_fmadd_ps(vec_18, vec_8, mem_vec_16087);
												mem_vec_16087 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_18, vec_10, mem_vec_16088);
												mem_vec_16088 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_18, vec_12, mem_vec_16089);
												mem_vec_16089 = vec_23;



												vec_24 = _mm256_fmadd_ps(vec_18, vec_14, mem_vec_16090);
												mem_vec_16090 = vec_24;



												vec_25 = _mm256_fmadd_ps(vec_18, vec_16, mem_vec_16091);
												mem_vec_16091 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm256_set1_ps(scal_2);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_16092);
												mem_vec_16092 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_16093);
												mem_vec_16093 = vec_28;



												vec_29 = _mm256_fmadd_ps(vec_27, vec_6, mem_vec_16094);
												mem_vec_16094 = vec_29;



												vec_30 = _mm256_fmadd_ps(vec_27, vec_8, mem_vec_16095);
												mem_vec_16095 = vec_30;



												vec_31 = _mm256_fmadd_ps(vec_27, vec_10, mem_vec_16096);
												mem_vec_16096 = vec_31;



												vec_32 = _mm256_fmadd_ps(vec_27, vec_12, mem_vec_16097);
												mem_vec_16097 = vec_32;



												vec_33 = _mm256_fmadd_ps(vec_27, vec_14, mem_vec_16098);
												mem_vec_16098 = vec_33;



												vec_34 = _mm256_fmadd_ps(vec_27, vec_16, mem_vec_16099);
												mem_vec_16099 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_36 = _mm256_set1_ps(scal_3);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_16100);
												mem_vec_16100 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_16101);
												mem_vec_16101 = vec_37;



												vec_38 = _mm256_fmadd_ps(vec_36, vec_6, mem_vec_16102);
												mem_vec_16102 = vec_38;



												vec_39 = _mm256_fmadd_ps(vec_36, vec_8, mem_vec_16103);
												mem_vec_16103 = vec_39;



												vec_40 = _mm256_fmadd_ps(vec_36, vec_10, mem_vec_16104);
												mem_vec_16104 = vec_40;



												vec_41 = _mm256_fmadd_ps(vec_36, vec_12, mem_vec_16105);
												mem_vec_16105 = vec_41;



												vec_42 = _mm256_fmadd_ps(vec_36, vec_14, mem_vec_16106);
												mem_vec_16106 = vec_42;



												vec_43 = _mm256_fmadd_ps(vec_36, vec_16, mem_vec_16107);
												mem_vec_16107 = vec_43;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_45 = _mm256_set1_ps(scal_4);
												vec_46 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_44 = _mm256_fmadd_ps(vec_45, vec_46, mem_vec_16076);
												mem_vec_16076 = vec_44;

												vec_48 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

												vec_47 = _mm256_fmadd_ps(vec_45, vec_48, mem_vec_16077);
												mem_vec_16077 = vec_47;

												vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_49 = _mm256_fmadd_ps(vec_45, vec_50, mem_vec_16078);
												mem_vec_16078 = vec_49;

												vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

												vec_51 = _mm256_fmadd_ps(vec_45, vec_52, mem_vec_16079);
												mem_vec_16079 = vec_51;

												vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm256_fmadd_ps(vec_45, vec_54, mem_vec_16080);
												mem_vec_16080 = vec_53;

												vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 40]);

												vec_55 = _mm256_fmadd_ps(vec_45, vec_56, mem_vec_16081);
												mem_vec_16081 = vec_55;

												vec_58 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_57 = _mm256_fmadd_ps(vec_45, vec_58, mem_vec_16082);
												mem_vec_16082 = vec_57;

												vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 56]);

												vec_59 = _mm256_fmadd_ps(vec_45, vec_60, mem_vec_16083);
												mem_vec_16083 = vec_59;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_62 = _mm256_set1_ps(scal_5);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_46, mem_vec_16084);
												mem_vec_16084 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_48, mem_vec_16085);
												mem_vec_16085 = vec_63;



												vec_64 = _mm256_fmadd_ps(vec_62, vec_50, mem_vec_16086);
												mem_vec_16086 = vec_64;



												vec_65 = _mm256_fmadd_ps(vec_62, vec_52, mem_vec_16087);
												mem_vec_16087 = vec_65;



												vec_66 = _mm256_fmadd_ps(vec_62, vec_54, mem_vec_16088);
												mem_vec_16088 = vec_66;



												vec_67 = _mm256_fmadd_ps(vec_62, vec_56, mem_vec_16089);
												mem_vec_16089 = vec_67;



												vec_68 = _mm256_fmadd_ps(vec_62, vec_58, mem_vec_16090);
												mem_vec_16090 = vec_68;



												vec_69 = _mm256_fmadd_ps(vec_62, vec_60, mem_vec_16091);
												mem_vec_16091 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_71 = _mm256_set1_ps(scal_6);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_46, mem_vec_16092);
												mem_vec_16092 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_48, mem_vec_16093);
												mem_vec_16093 = vec_72;



												vec_73 = _mm256_fmadd_ps(vec_71, vec_50, mem_vec_16094);
												mem_vec_16094 = vec_73;



												vec_74 = _mm256_fmadd_ps(vec_71, vec_52, mem_vec_16095);
												mem_vec_16095 = vec_74;



												vec_75 = _mm256_fmadd_ps(vec_71, vec_54, mem_vec_16096);
												mem_vec_16096 = vec_75;



												vec_76 = _mm256_fmadd_ps(vec_71, vec_56, mem_vec_16097);
												mem_vec_16097 = vec_76;



												vec_77 = _mm256_fmadd_ps(vec_71, vec_58, mem_vec_16098);
												mem_vec_16098 = vec_77;



												vec_78 = _mm256_fmadd_ps(vec_71, vec_60, mem_vec_16099);
												mem_vec_16099 = vec_78;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_80 = _mm256_set1_ps(scal_7);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_46, mem_vec_16100);
												mem_vec_16100 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_48, mem_vec_16101);
												mem_vec_16101 = vec_81;



												vec_82 = _mm256_fmadd_ps(vec_80, vec_50, mem_vec_16102);
												mem_vec_16102 = vec_82;



												vec_83 = _mm256_fmadd_ps(vec_80, vec_52, mem_vec_16103);
												mem_vec_16103 = vec_83;



												vec_84 = _mm256_fmadd_ps(vec_80, vec_54, mem_vec_16104);
												mem_vec_16104 = vec_84;



												vec_85 = _mm256_fmadd_ps(vec_80, vec_56, mem_vec_16105);
												mem_vec_16105 = vec_85;



												vec_86 = _mm256_fmadd_ps(vec_80, vec_58, mem_vec_16106);
												mem_vec_16106 = vec_86;



												vec_87 = _mm256_fmadd_ps(vec_80, vec_60, mem_vec_16107);
												mem_vec_16107 = vec_87;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_89 = _mm256_set1_ps(scal_8);
												vec_90 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_88 = _mm256_fmadd_ps(vec_89, vec_90, mem_vec_16076);
												mem_vec_16076 = vec_88;

												vec_92 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

												vec_91 = _mm256_fmadd_ps(vec_89, vec_92, mem_vec_16077);
												mem_vec_16077 = vec_91;

												vec_94 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_93 = _mm256_fmadd_ps(vec_89, vec_94, mem_vec_16078);
												mem_vec_16078 = vec_93;

												vec_96 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

												vec_95 = _mm256_fmadd_ps(vec_89, vec_96, mem_vec_16079);
												mem_vec_16079 = vec_95;

												vec_98 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_97 = _mm256_fmadd_ps(vec_89, vec_98, mem_vec_16080);
												mem_vec_16080 = vec_97;

												vec_100 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 40]);

												vec_99 = _mm256_fmadd_ps(vec_89, vec_100, mem_vec_16081);
												mem_vec_16081 = vec_99;

												vec_102 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_101 = _mm256_fmadd_ps(vec_89, vec_102, mem_vec_16082);
												mem_vec_16082 = vec_101;

												vec_104 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 56]);

												vec_103 = _mm256_fmadd_ps(vec_89, vec_104, mem_vec_16083);
												mem_vec_16083 = vec_103;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_106 = _mm256_set1_ps(scal_9);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_90, mem_vec_16084);
												mem_vec_16084 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_92, mem_vec_16085);
												mem_vec_16085 = vec_107;



												vec_108 = _mm256_fmadd_ps(vec_106, vec_94, mem_vec_16086);
												mem_vec_16086 = vec_108;



												vec_109 = _mm256_fmadd_ps(vec_106, vec_96, mem_vec_16087);
												mem_vec_16087 = vec_109;



												vec_110 = _mm256_fmadd_ps(vec_106, vec_98, mem_vec_16088);
												mem_vec_16088 = vec_110;



												vec_111 = _mm256_fmadd_ps(vec_106, vec_100, mem_vec_16089);
												mem_vec_16089 = vec_111;



												vec_112 = _mm256_fmadd_ps(vec_106, vec_102, mem_vec_16090);
												mem_vec_16090 = vec_112;



												vec_113 = _mm256_fmadd_ps(vec_106, vec_104, mem_vec_16091);
												mem_vec_16091 = vec_113;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_115 = _mm256_set1_ps(scal_10);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_90, mem_vec_16092);
												mem_vec_16092 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_92, mem_vec_16093);
												mem_vec_16093 = vec_116;



												vec_117 = _mm256_fmadd_ps(vec_115, vec_94, mem_vec_16094);
												mem_vec_16094 = vec_117;



												vec_118 = _mm256_fmadd_ps(vec_115, vec_96, mem_vec_16095);
												mem_vec_16095 = vec_118;



												vec_119 = _mm256_fmadd_ps(vec_115, vec_98, mem_vec_16096);
												mem_vec_16096 = vec_119;



												vec_120 = _mm256_fmadd_ps(vec_115, vec_100, mem_vec_16097);
												mem_vec_16097 = vec_120;



												vec_121 = _mm256_fmadd_ps(vec_115, vec_102, mem_vec_16098);
												mem_vec_16098 = vec_121;



												vec_122 = _mm256_fmadd_ps(vec_115, vec_104, mem_vec_16099);
												mem_vec_16099 = vec_122;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_124 = _mm256_set1_ps(scal_11);


												vec_123 = _mm256_fmadd_ps(vec_124, vec_90, mem_vec_16100);
												mem_vec_16100 = vec_123;



												vec_125 = _mm256_fmadd_ps(vec_124, vec_92, mem_vec_16101);
												mem_vec_16101 = vec_125;



												vec_126 = _mm256_fmadd_ps(vec_124, vec_94, mem_vec_16102);
												mem_vec_16102 = vec_126;



												vec_127 = _mm256_fmadd_ps(vec_124, vec_96, mem_vec_16103);
												mem_vec_16103 = vec_127;



												vec_128 = _mm256_fmadd_ps(vec_124, vec_98, mem_vec_16104);
												mem_vec_16104 = vec_128;



												vec_129 = _mm256_fmadd_ps(vec_124, vec_100, mem_vec_16105);
												mem_vec_16105 = vec_129;



												vec_130 = _mm256_fmadd_ps(vec_124, vec_102, mem_vec_16106);
												mem_vec_16106 = vec_130;



												vec_131 = _mm256_fmadd_ps(vec_124, vec_104, mem_vec_16107);
												mem_vec_16107 = vec_131;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16076);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_16077);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16078);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_16079);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16080);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_16081);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16082);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_16083);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16084);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_16085);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16086);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_16087);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16088);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 40], mem_vec_16089);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16090);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 56], mem_vec_16091);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16092);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_16093);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16094);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_16095);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16096);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 40], mem_vec_16097);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16098);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 56], mem_vec_16099);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16100);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_16101);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16102);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_16103);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16104);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 40], mem_vec_16105);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16106);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 56], mem_vec_16107);
								}
							}
						}
					}
				}
		}
	}
}


}