#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (8, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (2, c); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 2)); ((Iter 5), (Arg 3))]; T (4, c);
  T (8, f)]
*/
IND_TYPE c, cp_0, c926_p_0, c927_p_0, cp_1, c926_p_1, cp_2, c926, c927, f, fp_0, f1034_p_0, fp_1, f1034, h, hp_0, x, xp_0, x840_p_0, xp_1, x840, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y560 = 0;
IND_TYPE x841 = 0;
IND_TYPE h446 = 0;
IND_TYPE w = 0;
IND_TYPE c928 = 0;
IND_TYPE f1035 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_8030 ,mem_vec_8031 ,mem_vec_8032 ,mem_vec_8033 ,mem_vec_8034 ,mem_vec_8035 ,mem_vec_8036 ,mem_vec_8037 ,mem_vec_8038 ,mem_vec_8039 ,mem_vec_8040 ,mem_vec_8041 ,mem_vec_8042 ,mem_vec_8043 ,mem_vec_8044 ,mem_vec_8045 ,mem_vec_8046 ,mem_vec_8047 ,mem_vec_8048 ,mem_vec_8049 ,mem_vec_8050 ,mem_vec_8051 ,mem_vec_8052 ,mem_vec_8053 ,mem_vec_8054 ,mem_vec_8055 ,mem_vec_8056 ,mem_vec_8057 ,mem_vec_8058 ,mem_vec_8059 ,mem_vec_8060 ,mem_vec_8061 ,mem_vec_8062 ,mem_vec_8063 ,mem_vec_8064 ,mem_vec_8065 ,mem_vec_8066 ,mem_vec_8067 ,mem_vec_8068 ,mem_vec_8069 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 8) (1024 / 128)
for (f1034 = f1035, f1034_p_0 = 0;
	f1034 < f1035 + 1024;
	f1034 += 128, f1034_p_0 += 128){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 128
	// T (c, 4) (512 / 128)
	for (c927 = c928, c927_p_0 = 0;
		c927 < c928 + 512;
		c927 += 128, c927_p_0 += 128){
			for (y = y560, yp_0 = 0;
				y < y560 + 2;
				y += 2, yp_0 += 2){
				// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 128
				// T (x, 17) (17 / 1)
				for (x840 = x841, x840_p_0 = 0;
					x840 < x841 + 17;
					x840 += 1, x840_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 128
					// T (f, 1) (128 / 128)
					for (f = f1034, fp_1 = f1034_p_0, fp_0 = 0;
						f < f1034 + 128;
						f += 128, fp_1 += 128, fp_0 += 128){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 128
						// T (c, 2) (128 / 64)
						for (c926 = c927, c926_p_1 = c927_p_0, c926_p_0 = 0;
							c926 < c927 + 128;
							c926 += 64, c926_p_1 += 64, c926_p_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 128
							// T (h, 3) (3 / 1)
							for (h = h446, hp_0 = 0;
								h < h446 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 128
								// T (x, 1) (1 / 1)
								for (x = x840, xp_1 = x840_p_0, xp_0 = 0;
									x < x840 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8030 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8031 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8032 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_8033 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_8034 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
											mem_vec_8035 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
											mem_vec_8036 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
											mem_vec_8037 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
											mem_vec_8038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_8041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_8042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
											mem_vec_8043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
											mem_vec_8044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
											mem_vec_8045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 128
											// T (c, 64) (64 / 1)
											for (c = c926, cp_2 = c926_p_1, cp_1 = c926_p_0, cp_0 = 0;
												c < c926 + 64;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8030);
												mem_vec_8030 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8031);
												mem_vec_8031 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8032);
												mem_vec_8032 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8033);
												mem_vec_8033 = vec_7;

												vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

												vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_8034);
												mem_vec_8034 = vec_9;

												vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

												vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_8035);
												mem_vec_8035 = vec_11;

												vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

												vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_8036);
												mem_vec_8036 = vec_13;

												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

												vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_8037);
												mem_vec_8037 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm512_set1_ps(scal_1);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8038);
												mem_vec_8038 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8039);
												mem_vec_8039 = vec_19;



												vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_8040);
												mem_vec_8040 = vec_20;



												vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_8041);
												mem_vec_8041 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_8042);
												mem_vec_8042 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_8043);
												mem_vec_8043 = vec_23;



												vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_8044);
												mem_vec_8044 = vec_24;



												vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_8045);
												mem_vec_8045 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_27 = _mm512_set1_ps(scal_2);
												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_8030);
												mem_vec_8030 = vec_26;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_8031);
												mem_vec_8031 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_31 = _mm512_fmadd_ps(vec_27, vec_32, mem_vec_8032);
												mem_vec_8032 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_33 = _mm512_fmadd_ps(vec_27, vec_34, mem_vec_8033);
												mem_vec_8033 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

												vec_35 = _mm512_fmadd_ps(vec_27, vec_36, mem_vec_8034);
												mem_vec_8034 = vec_35;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

												vec_37 = _mm512_fmadd_ps(vec_27, vec_38, mem_vec_8035);
												mem_vec_8035 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

												vec_39 = _mm512_fmadd_ps(vec_27, vec_40, mem_vec_8036);
												mem_vec_8036 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

												vec_41 = _mm512_fmadd_ps(vec_27, vec_42, mem_vec_8037);
												mem_vec_8037 = vec_41;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_3);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_8038);
												mem_vec_8038 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_8039);
												mem_vec_8039 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_8040);
												mem_vec_8040 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_8041);
												mem_vec_8041 = vec_47;



												vec_48 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_8042);
												mem_vec_8042 = vec_48;



												vec_49 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_8043);
												mem_vec_8043 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_8044);
												mem_vec_8044 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_8045);
												mem_vec_8045 = vec_51;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_53 = _mm512_set1_ps(scal_4);
												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_8030);
												mem_vec_8030 = vec_52;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_8031);
												mem_vec_8031 = vec_55;

												vec_58 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_57 = _mm512_fmadd_ps(vec_53, vec_58, mem_vec_8032);
												mem_vec_8032 = vec_57;

												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_59 = _mm512_fmadd_ps(vec_53, vec_60, mem_vec_8033);
												mem_vec_8033 = vec_59;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

												vec_61 = _mm512_fmadd_ps(vec_53, vec_62, mem_vec_8034);
												mem_vec_8034 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

												vec_63 = _mm512_fmadd_ps(vec_53, vec_64, mem_vec_8035);
												mem_vec_8035 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

												vec_65 = _mm512_fmadd_ps(vec_53, vec_66, mem_vec_8036);
												mem_vec_8036 = vec_65;

												vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

												vec_67 = _mm512_fmadd_ps(vec_53, vec_68, mem_vec_8037);
												mem_vec_8037 = vec_67;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_70 = _mm512_set1_ps(scal_5);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_8038);
												mem_vec_8038 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_8039);
												mem_vec_8039 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_70, vec_58, mem_vec_8040);
												mem_vec_8040 = vec_72;



												vec_73 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_8041);
												mem_vec_8041 = vec_73;



												vec_74 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_8042);
												mem_vec_8042 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_70, vec_64, mem_vec_8043);
												mem_vec_8043 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_8044);
												mem_vec_8044 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_8045);
												mem_vec_8045 = vec_77;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8030);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8031);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8032);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8033);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_8034);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_8035);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_8036);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_8037);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8038);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8039);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8040);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8041);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_8042);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_8043);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_8044);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_8045);
								}
							}
						}
					}
				}
			}
			for (y = y560 + 2, yp_0 = 0;
				y < y560 + 2 + 15;
				y += 3, yp_0 += 3){
				// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 128
				// T (x, 17) (17 / 1)
				for (x840 = x841, x840_p_0 = 0;
					x840 < x841 + 17;
					x840 += 1, x840_p_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 128
					// T (f, 1) (128 / 128)
					for (f = f1034, fp_1 = f1034_p_0, fp_0 = 0;
						f < f1034 + 128;
						f += 128, fp_1 += 128, fp_0 += 128){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 128
						// T (c, 2) (128 / 64)
						for (c926 = c927, c926_p_1 = c927_p_0, c926_p_0 = 0;
							c926 < c927 + 128;
							c926 += 64, c926_p_1 += 64, c926_p_0 += 64){
							// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 128
							// T (h, 3) (3 / 1)
							for (h = h446, hp_0 = 0;
								h < h446 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 128
								// T (x, 1) (1 / 1)
								for (x = x840, xp_1 = x840_p_0, xp_0 = 0;
									x < x840 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8046 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8047 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8048 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_8049 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_8050 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 64]);
											mem_vec_8051 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 80]);
											mem_vec_8052 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 96]);
											mem_vec_8053 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 112]);
											mem_vec_8054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_8057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_8058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64]);
											mem_vec_8059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80]);
											mem_vec_8060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96]);
											mem_vec_8061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112]);
											mem_vec_8062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_8065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_8066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64]);
											mem_vec_8067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80]);
											mem_vec_8068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96]);
											mem_vec_8069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 128
											// T (c, 64) (64 / 1)
											for (c = c926, cp_2 = c926_p_1, cp_1 = c926_p_0, cp_0 = 0;
												c < c926 + 64;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8046);
												mem_vec_8046 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8047);
												mem_vec_8047 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8048);
												mem_vec_8048 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_8049);
												mem_vec_8049 = vec_7;

												vec_10 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 64]);

												vec_9 = _mm512_fmadd_ps(vec_1, vec_10, mem_vec_8050);
												mem_vec_8050 = vec_9;

												vec_12 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 80]);

												vec_11 = _mm512_fmadd_ps(vec_1, vec_12, mem_vec_8051);
												mem_vec_8051 = vec_11;

												vec_14 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 96]);

												vec_13 = _mm512_fmadd_ps(vec_1, vec_14, mem_vec_8052);
												mem_vec_8052 = vec_13;

												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 112]);

												vec_15 = _mm512_fmadd_ps(vec_1, vec_16, mem_vec_8053);
												mem_vec_8053 = vec_15;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_18 = _mm512_set1_ps(scal_1);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8054);
												mem_vec_8054 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8055);
												mem_vec_8055 = vec_19;



												vec_20 = _mm512_fmadd_ps(vec_18, vec_6, mem_vec_8056);
												mem_vec_8056 = vec_20;



												vec_21 = _mm512_fmadd_ps(vec_18, vec_8, mem_vec_8057);
												mem_vec_8057 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_18, vec_10, mem_vec_8058);
												mem_vec_8058 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_18, vec_12, mem_vec_8059);
												mem_vec_8059 = vec_23;



												vec_24 = _mm512_fmadd_ps(vec_18, vec_14, mem_vec_8060);
												mem_vec_8060 = vec_24;



												vec_25 = _mm512_fmadd_ps(vec_18, vec_16, mem_vec_8061);
												mem_vec_8061 = vec_25;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_27 = _mm512_set1_ps(scal_2);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8062);
												mem_vec_8062 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8063);
												mem_vec_8063 = vec_28;



												vec_29 = _mm512_fmadd_ps(vec_27, vec_6, mem_vec_8064);
												mem_vec_8064 = vec_29;



												vec_30 = _mm512_fmadd_ps(vec_27, vec_8, mem_vec_8065);
												mem_vec_8065 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_27, vec_10, mem_vec_8066);
												mem_vec_8066 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_27, vec_12, mem_vec_8067);
												mem_vec_8067 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_27, vec_14, mem_vec_8068);
												mem_vec_8068 = vec_33;



												vec_34 = _mm512_fmadd_ps(vec_27, vec_16, mem_vec_8069);
												mem_vec_8069 = vec_34;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_36 = _mm512_set1_ps(scal_3);
												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_35 = _mm512_fmadd_ps(vec_36, vec_37, mem_vec_8046);
												mem_vec_8046 = vec_35;

												vec_39 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_38 = _mm512_fmadd_ps(vec_36, vec_39, mem_vec_8047);
												mem_vec_8047 = vec_38;

												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_40 = _mm512_fmadd_ps(vec_36, vec_41, mem_vec_8048);
												mem_vec_8048 = vec_40;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_42 = _mm512_fmadd_ps(vec_36, vec_43, mem_vec_8049);
												mem_vec_8049 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 64]);

												vec_44 = _mm512_fmadd_ps(vec_36, vec_45, mem_vec_8050);
												mem_vec_8050 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 80]);

												vec_46 = _mm512_fmadd_ps(vec_36, vec_47, mem_vec_8051);
												mem_vec_8051 = vec_46;

												vec_49 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 96]);

												vec_48 = _mm512_fmadd_ps(vec_36, vec_49, mem_vec_8052);
												mem_vec_8052 = vec_48;

												vec_51 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 112]);

												vec_50 = _mm512_fmadd_ps(vec_36, vec_51, mem_vec_8053);
												mem_vec_8053 = vec_50;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_53 = _mm512_set1_ps(scal_4);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_37, mem_vec_8054);
												mem_vec_8054 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_39, mem_vec_8055);
												mem_vec_8055 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_41, mem_vec_8056);
												mem_vec_8056 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_43, mem_vec_8057);
												mem_vec_8057 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_53, vec_45, mem_vec_8058);
												mem_vec_8058 = vec_57;



												vec_58 = _mm512_fmadd_ps(vec_53, vec_47, mem_vec_8059);
												mem_vec_8059 = vec_58;



												vec_59 = _mm512_fmadd_ps(vec_53, vec_49, mem_vec_8060);
												mem_vec_8060 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_53, vec_51, mem_vec_8061);
												mem_vec_8061 = vec_60;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_62 = _mm512_set1_ps(scal_5);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_37, mem_vec_8062);
												mem_vec_8062 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_39, mem_vec_8063);
												mem_vec_8063 = vec_63;



												vec_64 = _mm512_fmadd_ps(vec_62, vec_41, mem_vec_8064);
												mem_vec_8064 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_62, vec_43, mem_vec_8065);
												mem_vec_8065 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_62, vec_45, mem_vec_8066);
												mem_vec_8066 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_62, vec_47, mem_vec_8067);
												mem_vec_8067 = vec_67;



												vec_68 = _mm512_fmadd_ps(vec_62, vec_49, mem_vec_8068);
												mem_vec_8068 = vec_68;



												vec_69 = _mm512_fmadd_ps(vec_62, vec_51, mem_vec_8069);
												mem_vec_8069 = vec_69;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_71 = _mm512_set1_ps(scal_6);
												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_70 = _mm512_fmadd_ps(vec_71, vec_72, mem_vec_8046);
												mem_vec_8046 = vec_70;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_73 = _mm512_fmadd_ps(vec_71, vec_74, mem_vec_8047);
												mem_vec_8047 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_75 = _mm512_fmadd_ps(vec_71, vec_76, mem_vec_8048);
												mem_vec_8048 = vec_75;

												vec_78 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_77 = _mm512_fmadd_ps(vec_71, vec_78, mem_vec_8049);
												mem_vec_8049 = vec_77;

												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 64]);

												vec_79 = _mm512_fmadd_ps(vec_71, vec_80, mem_vec_8050);
												mem_vec_8050 = vec_79;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 80]);

												vec_81 = _mm512_fmadd_ps(vec_71, vec_82, mem_vec_8051);
												mem_vec_8051 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 96]);

												vec_83 = _mm512_fmadd_ps(vec_71, vec_84, mem_vec_8052);
												mem_vec_8052 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 112]);

												vec_85 = _mm512_fmadd_ps(vec_71, vec_86, mem_vec_8053);
												mem_vec_8053 = vec_85;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_7);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_8054);
												mem_vec_8054 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_8055);
												mem_vec_8055 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_8056);
												mem_vec_8056 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_78, mem_vec_8057);
												mem_vec_8057 = vec_91;



												vec_92 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_8058);
												mem_vec_8058 = vec_92;



												vec_93 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_8059);
												mem_vec_8059 = vec_93;



												vec_94 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_8060);
												mem_vec_8060 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_8061);
												mem_vec_8061 = vec_95;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_97 = _mm512_set1_ps(scal_8);


												vec_96 = _mm512_fmadd_ps(vec_97, vec_72, mem_vec_8062);
												mem_vec_8062 = vec_96;



												vec_98 = _mm512_fmadd_ps(vec_97, vec_74, mem_vec_8063);
												mem_vec_8063 = vec_98;



												vec_99 = _mm512_fmadd_ps(vec_97, vec_76, mem_vec_8064);
												mem_vec_8064 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_97, vec_78, mem_vec_8065);
												mem_vec_8065 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_97, vec_80, mem_vec_8066);
												mem_vec_8066 = vec_101;



												vec_102 = _mm512_fmadd_ps(vec_97, vec_82, mem_vec_8067);
												mem_vec_8067 = vec_102;



												vec_103 = _mm512_fmadd_ps(vec_97, vec_84, mem_vec_8068);
												mem_vec_8068 = vec_103;



												vec_104 = _mm512_fmadd_ps(vec_97, vec_86, mem_vec_8069);
												mem_vec_8069 = vec_104;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8046);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8047);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8048);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_8049);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 64], mem_vec_8050);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 80], mem_vec_8051);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 96], mem_vec_8052);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 112], mem_vec_8053);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8054);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8055);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8056);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_8057);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 64], mem_vec_8058);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 80], mem_vec_8059);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 96], mem_vec_8060);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 112], mem_vec_8061);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8062);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8063);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8064);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_8065);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 64], mem_vec_8066);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 80], mem_vec_8067);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 96], mem_vec_8068);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 112], mem_vec_8069);
								}
							}
						}
					}
				}
			}
	}
}


}