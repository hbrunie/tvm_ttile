#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (17, x);
  T (3, h); T (1, c); T (4, f);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (2, x);
  T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c354_p_0, cp_1, c354, f, fp_0, f394_p_0, f395_p_0, fp_1, f394_p_1, fp_2, f394, f395, h, hp_0, x, xp_0, x354_p_0, xp_1, x354, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y264 = 0;
IND_TYPE x355 = 0;
IND_TYPE h217 = 0;
IND_TYPE w = 0;
IND_TYPE c355 = 0;
IND_TYPE f396 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4096 ,mem_vec_4097 ,mem_vec_4098 ,mem_vec_4099 ,mem_vec_4100 ,mem_vec_4101 ,mem_vec_4102 ,mem_vec_4103 ,mem_vec_4104 ,mem_vec_4105 ,mem_vec_4106 ,mem_vec_4107 ,mem_vec_4108 ,mem_vec_4109 ,mem_vec_4110 ,mem_vec_4111 ,mem_vec_4112 ,mem_vec_4113 ,mem_vec_4114 ,mem_vec_4115 ,mem_vec_4116 ,mem_vec_4117 ,mem_vec_4118 ,mem_vec_4119 ,mem_vec_4120 ,mem_vec_4121 ,mem_vec_4122 ,mem_vec_4123 ,mem_vec_4124 ,mem_vec_4125 ,mem_vec_4126 ,mem_vec_4127 ,mem_vec_4128 ,mem_vec_4129 ,mem_vec_4130 ,mem_vec_4131 ,mem_vec_4132 ,mem_vec_4133 ,mem_vec_4134 ,mem_vec_4135 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f395 = f396, f395_p_0 = 0;
	f395 < f396 + 512;
	f395 += 256, f395_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (f, 1) (256 / 256)
	for (f394 = f395, f394_p_1 = f395_p_0, f394_p_0 = 0;
		f394 < f395 + 256;
		f394 += 256, f394_p_1 += 256, f394_p_0 += 256){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
		// T (x, 2) (34 / 17)
		for (x354 = x355, x354_p_0 = 0;
			x354 < x355 + 34;
			x354 += 17, x354_p_0 += 17){
				for (y = y264, yp_0 = 0;
					y < y264 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 256
					// T (f, 4) (256 / 64)
					for (f = f394, fp_2 = f394_p_1, fp_1 = f394_p_0, fp_0 = 0;
						f < f394 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c354 = c355, c354_p_0 = 0;
							c354 < c355 + 256;
							c354 += 256, c354_p_0 += 256){
							// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h217, hp_0 = 0;
								h < h217 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x354, xp_1 = x354_p_0, xp_0 = 0;
									x < x354 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4096 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4097 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4098 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_4099 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_4100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_4103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_4104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_4107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_4108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_4111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c354, cp_1 = c354_p_0, cp_0 = 0;
												c < c354 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4096);
												mem_vec_4096 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4097);
												mem_vec_4097 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4098);
												mem_vec_4098 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4099);
												mem_vec_4099 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4100);
												mem_vec_4100 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4101);
												mem_vec_4101 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4102);
												mem_vec_4102 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4103);
												mem_vec_4103 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4104);
												mem_vec_4104 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4105);
												mem_vec_4105 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4106);
												mem_vec_4106 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4107);
												mem_vec_4107 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4108);
												mem_vec_4108 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4109);
												mem_vec_4109 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4110);
												mem_vec_4110 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4111);
												mem_vec_4111 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_4096);
												mem_vec_4096 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_4097);
												mem_vec_4097 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_4098);
												mem_vec_4098 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_4099);
												mem_vec_4099 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_4100);
												mem_vec_4100 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_4101);
												mem_vec_4101 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_4102);
												mem_vec_4102 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_4103);
												mem_vec_4103 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_4104);
												mem_vec_4104 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_4105);
												mem_vec_4105 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_4106);
												mem_vec_4106 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_4107);
												mem_vec_4107 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_4108);
												mem_vec_4108 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_4109);
												mem_vec_4109 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_4110);
												mem_vec_4110 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_4111);
												mem_vec_4111 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_4096);
												mem_vec_4096 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_4097);
												mem_vec_4097 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_4098);
												mem_vec_4098 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_4099);
												mem_vec_4099 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_4100);
												mem_vec_4100 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_4101);
												mem_vec_4101 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_4102);
												mem_vec_4102 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_4103);
												mem_vec_4103 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_4104);
												mem_vec_4104 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_4105);
												mem_vec_4105 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_4106);
												mem_vec_4106 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_4107);
												mem_vec_4107 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_4108);
												mem_vec_4108 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_4109);
												mem_vec_4109 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_4110);
												mem_vec_4110 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_4111);
												mem_vec_4111 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4096);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4097);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4098);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4099);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4100);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4101);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4102);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4103);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4104);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4105);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4106);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4107);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4108);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4109);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4110);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4111);
								}
							}
						}
					}
				}
				for (y = y264 + 4, yp_0 = 0;
					y < y264 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 256
					// T (f, 4) (256 / 64)
					for (f = f394, fp_2 = f394_p_1, fp_1 = f394_p_0, fp_0 = 0;
						f < f394 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c354 = c355, c354_p_0 = 0;
							c354 < c355 + 256;
							c354 += 256, c354_p_0 += 256){
							// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h217, hp_0 = 0;
								h < h217 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 256, f = 64
								// T (x, 17) (17 / 1)
								for (x = x354, xp_1 = x354_p_0, xp_0 = 0;
									x < x354 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_4112 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4113 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4114 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_4115 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_4116 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4117 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4118 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_4119 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_4120 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4121 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4122 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_4123 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_4124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_4127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_4128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_4131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_4132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_4135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c354, cp_1 = c354_p_0, cp_0 = 0;
												c < c354 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4112);
												mem_vec_4112 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4113);
												mem_vec_4113 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4114);
												mem_vec_4114 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4115);
												mem_vec_4115 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4116);
												mem_vec_4116 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4117);
												mem_vec_4117 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4118);
												mem_vec_4118 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4119);
												mem_vec_4119 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4120);
												mem_vec_4120 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4121);
												mem_vec_4121 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4122);
												mem_vec_4122 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4123);
												mem_vec_4123 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4124);
												mem_vec_4124 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4125);
												mem_vec_4125 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4126);
												mem_vec_4126 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4127);
												mem_vec_4127 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4128);
												mem_vec_4128 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4129);
												mem_vec_4129 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4130);
												mem_vec_4130 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4131);
												mem_vec_4131 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4132);
												mem_vec_4132 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4133);
												mem_vec_4133 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4134);
												mem_vec_4134 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4135);
												mem_vec_4135 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_4112);
												mem_vec_4112 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_4113);
												mem_vec_4113 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_4114);
												mem_vec_4114 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_4115);
												mem_vec_4115 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_4116);
												mem_vec_4116 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_4117);
												mem_vec_4117 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_4118);
												mem_vec_4118 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_4119);
												mem_vec_4119 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_4120);
												mem_vec_4120 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_4121);
												mem_vec_4121 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_4122);
												mem_vec_4122 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_4123);
												mem_vec_4123 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_4124);
												mem_vec_4124 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_4125);
												mem_vec_4125 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_4126);
												mem_vec_4126 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_4127);
												mem_vec_4127 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_4128);
												mem_vec_4128 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_4129);
												mem_vec_4129 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_4130);
												mem_vec_4130 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_4131);
												mem_vec_4131 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_4132);
												mem_vec_4132 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_4133);
												mem_vec_4133 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_4134);
												mem_vec_4134 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_4135);
												mem_vec_4135 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_4112);
												mem_vec_4112 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_4113);
												mem_vec_4113 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_4114);
												mem_vec_4114 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_4115);
												mem_vec_4115 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_4116);
												mem_vec_4116 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_4117);
												mem_vec_4117 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_4118);
												mem_vec_4118 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_4119);
												mem_vec_4119 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_4120);
												mem_vec_4120 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_4121);
												mem_vec_4121 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_4122);
												mem_vec_4122 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_4123);
												mem_vec_4123 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_4124);
												mem_vec_4124 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_4125);
												mem_vec_4125 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_4126);
												mem_vec_4126 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_4127);
												mem_vec_4127 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_4128);
												mem_vec_4128 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_4129);
												mem_vec_4129 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_4130);
												mem_vec_4130 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_4131);
												mem_vec_4131 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_4132);
												mem_vec_4132 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_4133);
												mem_vec_4133 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_4134);
												mem_vec_4134 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_4135);
												mem_vec_4135 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4112);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4113);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4114);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4115);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4116);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4117);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4118);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4119);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4120);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4121);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4122);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4123);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4124);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4125);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4126);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4127);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4128);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4129);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4130);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4131);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4132);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4133);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_4134);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_4135);
								}
							}
						}
					}
				}
		}
	}
}


}