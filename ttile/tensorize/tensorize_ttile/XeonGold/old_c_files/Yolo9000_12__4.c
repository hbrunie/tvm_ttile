#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (1, x);
  T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c75_p_0, cp_1, c75, f, fp_0, f98_p_0, f99_p_0, fp_1, f98_p_1, fp_2, f98, f99, h, hp_0, x, xp_0, x76_p_0, xp_1, x76, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y51 = 0;
IND_TYPE x77 = 0;
IND_TYPE h50 = 0;
IND_TYPE w = 0;
IND_TYPE c76 = 0;
IND_TYPE f100 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1138 ,mem_vec_1139 ,mem_vec_1140 ,mem_vec_1141 ,mem_vec_1142 ,mem_vec_1143 ,mem_vec_1144 ,mem_vec_1145 ,mem_vec_1146 ,mem_vec_1147 ,mem_vec_1148 ,mem_vec_1149 ,mem_vec_1150 ,mem_vec_1151 ,mem_vec_1152 ,mem_vec_1153 ,mem_vec_1154 ,mem_vec_1155 ,mem_vec_1156 ,mem_vec_1157 ,mem_vec_1158 ,mem_vec_1159 ,mem_vec_1160 ,mem_vec_1161 ,mem_vec_1162 ,mem_vec_1163 ,mem_vec_1164 ,mem_vec_1165 ,mem_vec_1166 ,mem_vec_1167 ,mem_vec_1168 ,mem_vec_1169 ,mem_vec_1170 ,mem_vec_1171 ,mem_vec_1172 ,mem_vec_1173 ,mem_vec_1174 ,mem_vec_1175 ,mem_vec_1176 ,mem_vec_1177 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f99 = f100, f99_p_0 = 0;
	f99 < f100 + 512;
	f99 += 256, f99_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (f, 1) (256 / 256)
	for (f98 = f99, f98_p_1 = f99_p_0, f98_p_0 = 0;
		f98 < f99 + 256;
		f98 += 256, f98_p_1 += 256, f98_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (x, 1) (34 / 34)
		for (x76 = x77, x76_p_0 = 0;
			x76 < x77 + 34;
			x76 += 34, x76_p_0 += 34){
				for (y = y51, yp_0 = 0;
					y < y51 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 256
					// T (f, 4) (256 / 64)
					for (f = f98, fp_2 = f98_p_1, fp_1 = f98_p_0, fp_0 = 0;
						f < f98 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c75 = c76, c75_p_0 = 0;
							c75 < c76 + 256;
							c75 += 256, c75_p_0 += 256){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h50, hp_0 = 0;
								h < h50 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x76, xp_1 = x76_p_0, xp_0 = 0;
									x < x76 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1138 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1139 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_1141 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_1142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_1145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_1146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_1149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_1150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_1153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c75, cp_1 = c75_p_0, cp_0 = 0;
												c < c75 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1138);
												mem_vec_1138 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1139);
												mem_vec_1139 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1140);
												mem_vec_1140 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1141);
												mem_vec_1141 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1142);
												mem_vec_1142 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1143);
												mem_vec_1143 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1144);
												mem_vec_1144 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1145);
												mem_vec_1145 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1146);
												mem_vec_1146 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1147);
												mem_vec_1147 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1148);
												mem_vec_1148 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1149);
												mem_vec_1149 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1150);
												mem_vec_1150 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1151);
												mem_vec_1151 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1152);
												mem_vec_1152 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1153);
												mem_vec_1153 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_1138);
												mem_vec_1138 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_1139);
												mem_vec_1139 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_1140);
												mem_vec_1140 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_1141);
												mem_vec_1141 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_1142);
												mem_vec_1142 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_1143);
												mem_vec_1143 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_1144);
												mem_vec_1144 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_1145);
												mem_vec_1145 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_1146);
												mem_vec_1146 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_1147);
												mem_vec_1147 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_1148);
												mem_vec_1148 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_1149);
												mem_vec_1149 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_1150);
												mem_vec_1150 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_1151);
												mem_vec_1151 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_1152);
												mem_vec_1152 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_1153);
												mem_vec_1153 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_1138);
												mem_vec_1138 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_1139);
												mem_vec_1139 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_1140);
												mem_vec_1140 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_1141);
												mem_vec_1141 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_1142);
												mem_vec_1142 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_1143);
												mem_vec_1143 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_1144);
												mem_vec_1144 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_1145);
												mem_vec_1145 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_1146);
												mem_vec_1146 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_1147);
												mem_vec_1147 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_1148);
												mem_vec_1148 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_1149);
												mem_vec_1149 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_1150);
												mem_vec_1150 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_1151);
												mem_vec_1151 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_1152);
												mem_vec_1152 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_1153);
												mem_vec_1153 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1138);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1139);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1140);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1141);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1142);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1143);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1144);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1145);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1146);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1147);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1148);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1149);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1150);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1151);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1152);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1153);
								}
							}
						}
					}
				}
				for (y = y51 + 4, yp_0 = 0;
					y < y51 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 256
					// T (f, 4) (256 / 64)
					for (f = f98, fp_2 = f98_p_1, fp_1 = f98_p_0, fp_0 = 0;
						f < f98 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c75 = c76, c75_p_0 = 0;
							c75 < c76 + 256;
							c75 += 256, c75_p_0 += 256){
							// y = ph_y, x = 34, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h50, hp_0 = 0;
								h < h50 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 256, f = 64
								// T (x, 34) (34 / 1)
								for (x = x76, xp_1 = x76_p_0, xp_0 = 0;
									x < x76 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1154 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1155 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1156 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_1157 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_1158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_1161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_1162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_1165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_1166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_1169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_1170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_1173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_1174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_1177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c75, cp_1 = c75_p_0, cp_0 = 0;
												c < c75 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1154);
												mem_vec_1154 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1155);
												mem_vec_1155 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1156);
												mem_vec_1156 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1157);
												mem_vec_1157 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1158);
												mem_vec_1158 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1159);
												mem_vec_1159 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1160);
												mem_vec_1160 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1161);
												mem_vec_1161 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1162);
												mem_vec_1162 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1163);
												mem_vec_1163 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1164);
												mem_vec_1164 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1165);
												mem_vec_1165 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1166);
												mem_vec_1166 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1167);
												mem_vec_1167 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1168);
												mem_vec_1168 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1169);
												mem_vec_1169 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1170);
												mem_vec_1170 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1171);
												mem_vec_1171 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1172);
												mem_vec_1172 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1173);
												mem_vec_1173 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1174);
												mem_vec_1174 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1175);
												mem_vec_1175 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1176);
												mem_vec_1176 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1177);
												mem_vec_1177 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_1154);
												mem_vec_1154 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_1155);
												mem_vec_1155 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_1156);
												mem_vec_1156 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_1157);
												mem_vec_1157 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_1158);
												mem_vec_1158 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_1159);
												mem_vec_1159 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_1160);
												mem_vec_1160 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_1161);
												mem_vec_1161 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_1162);
												mem_vec_1162 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_1163);
												mem_vec_1163 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_1164);
												mem_vec_1164 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_1165);
												mem_vec_1165 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_1166);
												mem_vec_1166 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_1167);
												mem_vec_1167 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_1168);
												mem_vec_1168 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_1169);
												mem_vec_1169 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_1170);
												mem_vec_1170 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_1171);
												mem_vec_1171 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_1172);
												mem_vec_1172 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_1173);
												mem_vec_1173 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_1174);
												mem_vec_1174 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_1175);
												mem_vec_1175 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_1176);
												mem_vec_1176 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_1177);
												mem_vec_1177 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_1154);
												mem_vec_1154 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_1155);
												mem_vec_1155 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_1156);
												mem_vec_1156 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_1157);
												mem_vec_1157 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_1158);
												mem_vec_1158 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_1159);
												mem_vec_1159 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_1160);
												mem_vec_1160 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_1161);
												mem_vec_1161 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_1162);
												mem_vec_1162 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_1163);
												mem_vec_1163 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_1164);
												mem_vec_1164 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_1165);
												mem_vec_1165 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_1166);
												mem_vec_1166 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_1167);
												mem_vec_1167 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_1168);
												mem_vec_1168 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_1169);
												mem_vec_1169 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_1170);
												mem_vec_1170 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_1171);
												mem_vec_1171 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_1172);
												mem_vec_1172 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_1173);
												mem_vec_1173 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_1174);
												mem_vec_1174 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_1175);
												mem_vec_1175 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_1176);
												mem_vec_1176 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_1177);
												mem_vec_1177 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1154);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1155);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1156);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1157);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1158);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1159);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1160);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1161);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1162);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1163);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1164);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1165);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1166);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1167);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1168);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1169);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1170);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1171);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1172);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1173);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1174);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1175);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1176);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1177);
								}
							}
						}
					}
				}
		}
	}
}


}