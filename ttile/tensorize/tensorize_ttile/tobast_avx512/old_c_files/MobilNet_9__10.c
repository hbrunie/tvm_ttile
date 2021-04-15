#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (2, c); T (1, f);
  Lambda_apply y [((Iter 1), (Arg 2)); ((Iter 1), (Arg 5))]; T (1, c);
  T (16, f); T (512, c)]
*/
IND_TYPE c, cp_0, c1758_p_0, c1759_p_0, c1760_p_0, cp_1, c1758_p_1, c1759_p_1, cp_2, c1758_p_2, cp_3, c1758, c1759, c1760, f, fp_0, f1170_p_0, fp_1, f1170, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y586 = 0;
IND_TYPE x732 = 0;
IND_TYPE h550 = 0;
IND_TYPE w = 0;
IND_TYPE c1761 = 0;
IND_TYPE f1171 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7028 ,mem_vec_7029 ,mem_vec_7030 ,mem_vec_7031 ,mem_vec_7032 ,mem_vec_7033 ,mem_vec_7034 ,mem_vec_7035 ,mem_vec_7036 ,mem_vec_7037 ,mem_vec_7038 ,mem_vec_7039 ,mem_vec_7040 ,mem_vec_7041 ,mem_vec_7042 ,mem_vec_7043 ,mem_vec_7044 ,mem_vec_7045 ,mem_vec_7046 ,mem_vec_7047 ,mem_vec_7048 ,mem_vec_7049 ,mem_vec_7050 ,mem_vec_7051 ,mem_vec_7052 ,mem_vec_7053 ,mem_vec_7054 ,mem_vec_7055 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 512) (1024 / 2)
for (c1760 = c1761, c1760_p_0 = 0;
	c1760 < c1761 + 1024;
	c1760 += 2, c1760_p_0 += 2){
	// y = 7, x = 7, h = 3, w = 3, c = 2, f = 1024
	// T (f, 16) (1024 / 64)
	for (f1170 = f1171, f1170_p_0 = 0;
		f1170 < f1171 + 1024;
		f1170 += 64, f1170_p_0 += 64){
		// y = 7, x = 7, h = 3, w = 3, c = 2, f = 64
		// T (c, 1) (2 / 2)
		for (c1759 = c1760, c1759_p_1 = c1760_p_0, c1759_p_0 = 0;
			c1759 < c1760 + 2;
			c1759 += 2, c1759_p_1 += 2, c1759_p_0 += 2){
				for (y = y586, yp_0 = 0;
					y < y586 + 2;
					y += 2, yp_0 += 2){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1170, fp_1 = f1170_p_0, fp_0 = 0;
						f < f1170 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
						// T (c, 2) (2 / 1)
						for (c1758 = c1759, c1758_p_2 = c1759_p_1, c1758_p_1 = c1759_p_0, c1758_p_0 = 0;
							c1758 < c1759 + 2;
							c1758 += 1, c1758_p_2 += 1, c1758_p_1 += 1, c1758_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h550, hp_0 = 0;
								h < h550 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x732, xp_0 = 0;
									x < x732 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7028 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7029 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7030 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7031 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1758, cp_3 = c1758_p_2, cp_2 = c1758_p_1, cp_1 = c1758_p_0, cp_0 = 0;
												c < c1758 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7028);
												mem_vec_7028 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7029);
												mem_vec_7029 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7030);
												mem_vec_7030 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7031);
												mem_vec_7031 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7032);
												mem_vec_7032 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7033);
												mem_vec_7033 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7034);
												mem_vec_7034 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7035);
												mem_vec_7035 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_7028);
												mem_vec_7028 = vec_14;

												vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_7029);
												mem_vec_7029 = vec_17;

												vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_7030);
												mem_vec_7030 = vec_19;

												vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_7031);
												mem_vec_7031 = vec_21;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_24 = _mm512_set1_ps(scal_3);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_7032);
												mem_vec_7032 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_7033);
												mem_vec_7033 = vec_25;



												vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_7034);
												mem_vec_7034 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_7035);
												mem_vec_7035 = vec_27;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_7028);
												mem_vec_7028 = vec_28;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_7029);
												mem_vec_7029 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_7030);
												mem_vec_7030 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_7031);
												mem_vec_7031 = vec_35;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_38 = _mm512_set1_ps(scal_5);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_7032);
												mem_vec_7032 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_7033);
												mem_vec_7033 = vec_39;



												vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_7034);
												mem_vec_7034 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_7035);
												mem_vec_7035 = vec_41;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7028);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7029);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7030);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7031);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7032);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7033);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7034);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7035);
								}
							}
						}
					}
				}
				for (y = y586 + 2, yp_0 = 0;
					y < y586 + 2 + 5;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
					// T (f, 1) (64 / 64)
					for (f = f1170, fp_1 = f1170_p_0, fp_0 = 0;
						f < f1170 + 64;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 64
						// T (c, 2) (2 / 1)
						for (c1758 = c1759, c1758_p_2 = c1759_p_1, c1758_p_1 = c1759_p_0, c1758_p_0 = 0;
							c1758 < c1759 + 2;
							c1758 += 1, c1758_p_2 += 1, c1758_p_1 += 1, c1758_p_0 += 1){
							// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h550, hp_0 = 0;
								h < h550 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 64
								// T (x, 7) (7 / 1)
								for (x = x732, xp_0 = 0;
									x < x732 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7036 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7037 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7038 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7039 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_7048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_7051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_7052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_7055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 64
											// T (c, 1) (1 / 1)
											for (c = c1758, cp_3 = c1758_p_2, cp_2 = c1758_p_1, cp_1 = c1758_p_0, cp_0 = 0;
												c < c1758 + 1;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7036);
												mem_vec_7036 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7037);
												mem_vec_7037 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7038);
												mem_vec_7038 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7039);
												mem_vec_7039 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7040);
												mem_vec_7040 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7041);
												mem_vec_7041 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7042);
												mem_vec_7042 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7043);
												mem_vec_7043 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7044);
												mem_vec_7044 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7045);
												mem_vec_7045 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7046);
												mem_vec_7046 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7047);
												mem_vec_7047 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7048);
												mem_vec_7048 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7049);
												mem_vec_7049 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7050);
												mem_vec_7050 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7051);
												mem_vec_7051 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7052);
												mem_vec_7052 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7053);
												mem_vec_7053 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7054);
												mem_vec_7054 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7055);
												mem_vec_7055 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_7036);
												mem_vec_7036 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_7037);
												mem_vec_7037 = vec_32;

												vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_7038);
												mem_vec_7038 = vec_34;

												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_7039);
												mem_vec_7039 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_7040);
												mem_vec_7040 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_7041);
												mem_vec_7041 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_7042);
												mem_vec_7042 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_7043);
												mem_vec_7043 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_7044);
												mem_vec_7044 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_7045);
												mem_vec_7045 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_7046);
												mem_vec_7046 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_7047);
												mem_vec_7047 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_7048);
												mem_vec_7048 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_7049);
												mem_vec_7049 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_7050);
												mem_vec_7050 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_7051);
												mem_vec_7051 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_7052);
												mem_vec_7052 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_7053);
												mem_vec_7053 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_7054);
												mem_vec_7054 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_7055);
												mem_vec_7055 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_7036);
												mem_vec_7036 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_7037);
												mem_vec_7037 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_7038);
												mem_vec_7038 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_7039);
												mem_vec_7039 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_7040);
												mem_vec_7040 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_7041);
												mem_vec_7041 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_7042);
												mem_vec_7042 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_7043);
												mem_vec_7043 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm512_set1_ps(scal_12);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_7044);
												mem_vec_7044 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_7045);
												mem_vec_7045 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_7046);
												mem_vec_7046 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_7047);
												mem_vec_7047 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_7048);
												mem_vec_7048 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_7049);
												mem_vec_7049 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_7050);
												mem_vec_7050 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_7051);
												mem_vec_7051 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_7052);
												mem_vec_7052 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_7053);
												mem_vec_7053 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_7054);
												mem_vec_7054 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_7055);
												mem_vec_7055 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7036);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7037);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7038);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7039);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7040);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7041);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7042);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7043);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7044);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7045);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7046);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7047);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7048);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7049);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7050);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7051);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7052);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7053);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7054);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7055);
								}
							}
						}
					}
				}
		}
	}
}


}