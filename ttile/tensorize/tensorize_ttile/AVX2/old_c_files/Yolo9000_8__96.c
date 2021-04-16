#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (3, w);
  T (34, x); T (4, c); T (16, f); T (4, c); T (2, x);
  Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))]; T (1, c)]
*/
IND_TYPE c, cp_0, c148_p_0, c149_p_0, c150_p_0, cp_1, c148_p_1, c149_p_1, cp_2, c148_p_2, cp_3, c148, c149, c150, f, fp_0, w, wp_0, x, xp_0, x96_p_0, xp_1, x96, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y64 = 0;
IND_TYPE x97 = 0;
IND_TYPE h = 0;
IND_TYPE w52 = 0;
IND_TYPE c151 = 0;
IND_TYPE f76 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1204 ,mem_vec_1205 ,mem_vec_1206 ,mem_vec_1207 ,mem_vec_1208 ,mem_vec_1209 ,mem_vec_1210 ,mem_vec_1211 ,mem_vec_1212 ,mem_vec_1213 ,mem_vec_1214 ,mem_vec_1215 ,mem_vec_1216 ,mem_vec_1217 ,mem_vec_1218 ,mem_vec_1219 ,mem_vec_1220 ,mem_vec_1221 ,mem_vec_1222 ,mem_vec_1223 ,mem_vec_1224 ,mem_vec_1225 ,mem_vec_1226 ,mem_vec_1227 ,mem_vec_1228 ,mem_vec_1229 ,mem_vec_1230 ,mem_vec_1231 ,mem_vec_1232 ,mem_vec_1233 ,mem_vec_1234 ,mem_vec_1235 ,mem_vec_1236 ,mem_vec_1237 ,mem_vec_1238 ,mem_vec_1239 ,mem_vec_1240 ,mem_vec_1241 ,mem_vec_1242 ,mem_vec_1243 ,mem_vec_1244 ,mem_vec_1245 ,mem_vec_1246 ,mem_vec_1247 ,mem_vec_1248 ,mem_vec_1249 ,mem_vec_1250 ,mem_vec_1251 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_117 ,vec_118 ,vec_119 ,vec_12 ,vec_120 ,vec_121 ,vec_122 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (c, 1) (128 / 128)
for (c150 = c151, c150_p_0 = 0;
	c150 < c151 + 128;
	c150 += 128, c150_p_0 += 128){
		for (y = y64, yp_0 = 0;
			y < y64 + 55;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (68 / 34)
			for (x96 = x97, x96_p_0 = 0;
				x96 < x97 + 68;
				x96 += 34, x96_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 256
				// T (c, 4) (128 / 32)
				for (c149 = c150, c149_p_1 = c150_p_0, c149_p_0 = 0;
					c149 < c150 + 128;
					c149 += 32, c149_p_1 += 32, c149_p_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 256
					// T (f, 16) (256 / 16)
					for (f = f76, fp_0 = 0;
						f < f76 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 16
						// T (c, 4) (32 / 8)
						for (c148 = c149, c148_p_2 = c149_p_1, c148_p_1 = c149_p_0, c148_p_0 = 0;
							c148 < c149 + 32;
							c148 += 8, c148_p_2 += 8, c148_p_1 += 8, c148_p_0 += 8){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 16
							// T (x, 34) (34 / 1)
							for (x = x96, xp_1 = x96_p_0, xp_0 = 0;
								x < x96 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1204 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1205 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1206 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1207 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1208 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1209 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1210 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1211 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1212 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1213 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1214 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1215 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_1216 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1217 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_1218 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_1219 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_1220 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_1221 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_1222 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_1223 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_1224 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_1225 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c148, cp_3 = c148_p_2, cp_2 = c148_p_1, cp_1 = c148_p_0, cp_0 = 0;
												c < c148 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1204);
												mem_vec_1204 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1205);
												mem_vec_1205 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_1206);
												mem_vec_1206 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_1207);
												mem_vec_1207 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_1208);
												mem_vec_1208 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_1209);
												mem_vec_1209 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_1210);
												mem_vec_1210 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_1211);
												mem_vec_1211 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1212);
												mem_vec_1212 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1213);
												mem_vec_1213 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1214);
												mem_vec_1214 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1215);
												mem_vec_1215 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_1216);
												mem_vec_1216 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_1217);
												mem_vec_1217 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_1218);
												mem_vec_1218 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_1219);
												mem_vec_1219 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_1220);
												mem_vec_1220 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_1221);
												mem_vec_1221 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1222);
												mem_vec_1222 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1223);
												mem_vec_1223 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_1224);
												mem_vec_1224 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_1225);
												mem_vec_1225 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_36 = _mm256_set1_ps(scal_11);
												vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_1204);
												mem_vec_1204 = vec_35;

												vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_1205);
												mem_vec_1205 = vec_38;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_41 = _mm256_set1_ps(scal_12);


												vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_1206);
												mem_vec_1206 = vec_40;



												vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_1207);
												mem_vec_1207 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm256_set1_ps(scal_13);


												vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_1208);
												mem_vec_1208 = vec_43;



												vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_1209);
												mem_vec_1209 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_1210);
												mem_vec_1210 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_1211);
												mem_vec_1211 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_1212);
												mem_vec_1212 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_1213);
												mem_vec_1213 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_1214);
												mem_vec_1214 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_1215);
												mem_vec_1215 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_1216);
												mem_vec_1216 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_1217);
												mem_vec_1217 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_1218);
												mem_vec_1218 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_1219);
												mem_vec_1219 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_1220);
												mem_vec_1220 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_1221);
												mem_vec_1221 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_1222);
												mem_vec_1222 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_1223);
												mem_vec_1223 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_1224);
												mem_vec_1224 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_1225);
												mem_vec_1225 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_71 = _mm256_set1_ps(scal_22);
												vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_1204);
												mem_vec_1204 = vec_70;

												vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_1205);
												mem_vec_1205 = vec_73;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_76 = _mm256_set1_ps(scal_23);


												vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_1206);
												mem_vec_1206 = vec_75;



												vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_1207);
												mem_vec_1207 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_79 = _mm256_set1_ps(scal_24);


												vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_1208);
												mem_vec_1208 = vec_78;



												vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_1209);
												mem_vec_1209 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_82 = _mm256_set1_ps(scal_25);


												vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_1210);
												mem_vec_1210 = vec_81;



												vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_1211);
												mem_vec_1211 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_85 = _mm256_set1_ps(scal_26);


												vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_1212);
												mem_vec_1212 = vec_84;



												vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_1213);
												mem_vec_1213 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_1214);
												mem_vec_1214 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_1215);
												mem_vec_1215 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_1216);
												mem_vec_1216 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_1217);
												mem_vec_1217 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_1218);
												mem_vec_1218 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_1219);
												mem_vec_1219 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_1220);
												mem_vec_1220 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_1221);
												mem_vec_1221 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_1222);
												mem_vec_1222 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_1223);
												mem_vec_1223 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_1224);
												mem_vec_1224 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_1225);
												mem_vec_1225 = vec_104;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1204);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1205);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1206);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1207);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1208);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1209);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1210);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1211);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1212);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1213);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1214);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1215);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1216);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1217);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1218);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_1219);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1220);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_1221);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1222);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_1223);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1224);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_1225);
								}
							}
						}
					}
				}
			}
		}
		for (y = y64 + 55, yp_0 = 0;
			y < y64 + 55 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 256
			// T (x, 2) (68 / 34)
			for (x96 = x97, x96_p_0 = 0;
				x96 < x97 + 68;
				x96 += 34, x96_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 256
				// T (c, 4) (128 / 32)
				for (c149 = c150, c149_p_1 = c150_p_0, c149_p_0 = 0;
					c149 < c150 + 128;
					c149 += 32, c149_p_1 += 32, c149_p_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 256
					// T (f, 16) (256 / 16)
					for (f = f76, fp_0 = 0;
						f < f76 + 256;
						f += 16, fp_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 32, f = 16
						// T (c, 4) (32 / 8)
						for (c148 = c149, c148_p_2 = c149_p_1, c148_p_1 = c149_p_0, c148_p_0 = 0;
							c148 < c149 + 32;
							c148 += 8, c148_p_2 += 8, c148_p_1 += 8, c148_p_0 += 8){
							// y = ph_y, x = 34, h = 3, w = 3, c = 8, f = 16
							// T (x, 34) (34 / 1)
							for (x = x96, xp_1 = x96_p_0, xp_0 = 0;
								x < x96 + 34;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 16
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1226 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1227 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_1228 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1229 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_1230 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1231 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_1232 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1233 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_1234 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1235 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_1236 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1237 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
											mem_vec_1238 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1239 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
											mem_vec_1240 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_1241 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
											mem_vec_1242 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_1243 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
											mem_vec_1244 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_1245 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
											mem_vec_1246 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_1247 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
											mem_vec_1248 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_1249 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
											mem_vec_1250 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_1251 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c148, cp_3 = c148_p_2, cp_2 = c148_p_1, cp_1 = c148_p_0, cp_0 = 0;
												c < c148 + 8;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1226);
												mem_vec_1226 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1227);
												mem_vec_1227 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm256_set1_ps(scal_1);


												vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_1228);
												mem_vec_1228 = vec_5;



												vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_1229);
												mem_vec_1229 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm256_set1_ps(scal_2);


												vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_1230);
												mem_vec_1230 = vec_8;



												vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_1231);
												mem_vec_1231 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm256_set1_ps(scal_3);


												vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_1232);
												mem_vec_1232 = vec_11;



												vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_1233);
												mem_vec_1233 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm256_set1_ps(scal_4);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1234);
												mem_vec_1234 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1235);
												mem_vec_1235 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm256_set1_ps(scal_5);


												vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1236);
												mem_vec_1236 = vec_17;



												vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1237);
												mem_vec_1237 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm256_set1_ps(scal_6);


												vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_1238);
												mem_vec_1238 = vec_20;



												vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_1239);
												mem_vec_1239 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm256_set1_ps(scal_7);


												vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_1240);
												mem_vec_1240 = vec_23;



												vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_1241);
												mem_vec_1241 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm256_set1_ps(scal_8);


												vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_1242);
												mem_vec_1242 = vec_26;



												vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_1243);
												mem_vec_1243 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm256_set1_ps(scal_9);


												vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1244);
												mem_vec_1244 = vec_29;



												vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1245);
												mem_vec_1245 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm256_set1_ps(scal_10);


												vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_1246);
												mem_vec_1246 = vec_32;



												vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_1247);
												mem_vec_1247 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm256_set1_ps(scal_11);


												vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_1248);
												mem_vec_1248 = vec_35;



												vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_1249);
												mem_vec_1249 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm256_set1_ps(scal_12);


												vec_38 = _mm256_fmadd_ps(vec_39, vec_2, mem_vec_1250);
												mem_vec_1250 = vec_38;



												vec_40 = _mm256_fmadd_ps(vec_39, vec_4, mem_vec_1251);
												mem_vec_1251 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_42 = _mm256_set1_ps(scal_13);
												vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_41 = _mm256_fmadd_ps(vec_42, vec_43, mem_vec_1226);
												mem_vec_1226 = vec_41;

												vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

												vec_44 = _mm256_fmadd_ps(vec_42, vec_45, mem_vec_1227);
												mem_vec_1227 = vec_44;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_47 = _mm256_set1_ps(scal_14);


												vec_46 = _mm256_fmadd_ps(vec_47, vec_43, mem_vec_1228);
												mem_vec_1228 = vec_46;



												vec_48 = _mm256_fmadd_ps(vec_47, vec_45, mem_vec_1229);
												mem_vec_1229 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_50 = _mm256_set1_ps(scal_15);


												vec_49 = _mm256_fmadd_ps(vec_50, vec_43, mem_vec_1230);
												mem_vec_1230 = vec_49;



												vec_51 = _mm256_fmadd_ps(vec_50, vec_45, mem_vec_1231);
												mem_vec_1231 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_53 = _mm256_set1_ps(scal_16);


												vec_52 = _mm256_fmadd_ps(vec_53, vec_43, mem_vec_1232);
												mem_vec_1232 = vec_52;



												vec_54 = _mm256_fmadd_ps(vec_53, vec_45, mem_vec_1233);
												mem_vec_1233 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_56 = _mm256_set1_ps(scal_17);


												vec_55 = _mm256_fmadd_ps(vec_56, vec_43, mem_vec_1234);
												mem_vec_1234 = vec_55;



												vec_57 = _mm256_fmadd_ps(vec_56, vec_45, mem_vec_1235);
												mem_vec_1235 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_59 = _mm256_set1_ps(scal_18);


												vec_58 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_1236);
												mem_vec_1236 = vec_58;



												vec_60 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_1237);
												mem_vec_1237 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_62 = _mm256_set1_ps(scal_19);


												vec_61 = _mm256_fmadd_ps(vec_62, vec_43, mem_vec_1238);
												mem_vec_1238 = vec_61;



												vec_63 = _mm256_fmadd_ps(vec_62, vec_45, mem_vec_1239);
												mem_vec_1239 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_65 = _mm256_set1_ps(scal_20);


												vec_64 = _mm256_fmadd_ps(vec_65, vec_43, mem_vec_1240);
												mem_vec_1240 = vec_64;



												vec_66 = _mm256_fmadd_ps(vec_65, vec_45, mem_vec_1241);
												mem_vec_1241 = vec_66;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_68 = _mm256_set1_ps(scal_21);


												vec_67 = _mm256_fmadd_ps(vec_68, vec_43, mem_vec_1242);
												mem_vec_1242 = vec_67;



												vec_69 = _mm256_fmadd_ps(vec_68, vec_45, mem_vec_1243);
												mem_vec_1243 = vec_69;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_71 = _mm256_set1_ps(scal_22);


												vec_70 = _mm256_fmadd_ps(vec_71, vec_43, mem_vec_1244);
												mem_vec_1244 = vec_70;



												vec_72 = _mm256_fmadd_ps(vec_71, vec_45, mem_vec_1245);
												mem_vec_1245 = vec_72;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_74 = _mm256_set1_ps(scal_23);


												vec_73 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_1246);
												mem_vec_1246 = vec_73;



												vec_75 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_1247);
												mem_vec_1247 = vec_75;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_77 = _mm256_set1_ps(scal_24);


												vec_76 = _mm256_fmadd_ps(vec_77, vec_43, mem_vec_1248);
												mem_vec_1248 = vec_76;



												vec_78 = _mm256_fmadd_ps(vec_77, vec_45, mem_vec_1249);
												mem_vec_1249 = vec_78;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
												vec_80 = _mm256_set1_ps(scal_25);


												vec_79 = _mm256_fmadd_ps(vec_80, vec_43, mem_vec_1250);
												mem_vec_1250 = vec_79;



												vec_81 = _mm256_fmadd_ps(vec_80, vec_45, mem_vec_1251);
												mem_vec_1251 = vec_81;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_83 = _mm256_set1_ps(scal_26);
												vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_82 = _mm256_fmadd_ps(vec_83, vec_84, mem_vec_1226);
												mem_vec_1226 = vec_82;

												vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

												vec_85 = _mm256_fmadd_ps(vec_83, vec_86, mem_vec_1227);
												mem_vec_1227 = vec_85;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_88 = _mm256_set1_ps(scal_27);


												vec_87 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_1228);
												mem_vec_1228 = vec_87;



												vec_89 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_1229);
												mem_vec_1229 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_91 = _mm256_set1_ps(scal_28);


												vec_90 = _mm256_fmadd_ps(vec_91, vec_84, mem_vec_1230);
												mem_vec_1230 = vec_90;



												vec_92 = _mm256_fmadd_ps(vec_91, vec_86, mem_vec_1231);
												mem_vec_1231 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_94 = _mm256_set1_ps(scal_29);


												vec_93 = _mm256_fmadd_ps(vec_94, vec_84, mem_vec_1232);
												mem_vec_1232 = vec_93;



												vec_95 = _mm256_fmadd_ps(vec_94, vec_86, mem_vec_1233);
												mem_vec_1233 = vec_95;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_97 = _mm256_set1_ps(scal_30);


												vec_96 = _mm256_fmadd_ps(vec_97, vec_84, mem_vec_1234);
												mem_vec_1234 = vec_96;



												vec_98 = _mm256_fmadd_ps(vec_97, vec_86, mem_vec_1235);
												mem_vec_1235 = vec_98;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_100 = _mm256_set1_ps(scal_31);


												vec_99 = _mm256_fmadd_ps(vec_100, vec_84, mem_vec_1236);
												mem_vec_1236 = vec_99;



												vec_101 = _mm256_fmadd_ps(vec_100, vec_86, mem_vec_1237);
												mem_vec_1237 = vec_101;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_103 = _mm256_set1_ps(scal_32);


												vec_102 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_1238);
												mem_vec_1238 = vec_102;



												vec_104 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_1239);
												mem_vec_1239 = vec_104;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_106 = _mm256_set1_ps(scal_33);


												vec_105 = _mm256_fmadd_ps(vec_106, vec_84, mem_vec_1240);
												mem_vec_1240 = vec_105;



												vec_107 = _mm256_fmadd_ps(vec_106, vec_86, mem_vec_1241);
												mem_vec_1241 = vec_107;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_109 = _mm256_set1_ps(scal_34);


												vec_108 = _mm256_fmadd_ps(vec_109, vec_84, mem_vec_1242);
												mem_vec_1242 = vec_108;



												vec_110 = _mm256_fmadd_ps(vec_109, vec_86, mem_vec_1243);
												mem_vec_1243 = vec_110;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_112 = _mm256_set1_ps(scal_35);


												vec_111 = _mm256_fmadd_ps(vec_112, vec_84, mem_vec_1244);
												mem_vec_1244 = vec_111;



												vec_113 = _mm256_fmadd_ps(vec_112, vec_86, mem_vec_1245);
												mem_vec_1245 = vec_113;
												scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_115 = _mm256_set1_ps(scal_36);


												vec_114 = _mm256_fmadd_ps(vec_115, vec_84, mem_vec_1246);
												mem_vec_1246 = vec_114;



												vec_116 = _mm256_fmadd_ps(vec_115, vec_86, mem_vec_1247);
												mem_vec_1247 = vec_116;
												scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_118 = _mm256_set1_ps(scal_37);


												vec_117 = _mm256_fmadd_ps(vec_118, vec_84, mem_vec_1248);
												mem_vec_1248 = vec_117;



												vec_119 = _mm256_fmadd_ps(vec_118, vec_86, mem_vec_1249);
												mem_vec_1249 = vec_119;
												scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
												vec_121 = _mm256_set1_ps(scal_38);


												vec_120 = _mm256_fmadd_ps(vec_121, vec_84, mem_vec_1250);
												mem_vec_1250 = vec_120;



												vec_122 = _mm256_fmadd_ps(vec_121, vec_86, mem_vec_1251);
												mem_vec_1251 = vec_122;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1226);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1227);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1228);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1229);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1230);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1231);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1232);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1233);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1234);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1235);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1236);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1237);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1238);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1239);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1240);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_1241);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1242);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_1243);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1244);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_1245);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1246);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_1247);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1248);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_1249);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1250);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 8], mem_vec_1251);
								}
							}
						}
					}
				}
			}
		}
}


}