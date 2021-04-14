#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (128, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (1, f);
  T (2, c); T (8, f)]
*/
IND_TYPE c, cp_0, c1136_p_0, cp_1, c1136, f, fp_0, f1208_p_0, f1209_p_0, fp_1, f1208_p_1, fp_2, f1208, f1209, h, hp_0, x, xp_0, x1136_p_0, xp_1, x1136, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y696 = 0;
IND_TYPE x1137 = 0;
IND_TYPE h536 = 0;
IND_TYPE w = 0;
IND_TYPE c1137 = 0;
IND_TYPE f1210 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13542 ,mem_vec_13543 ,mem_vec_13544 ,mem_vec_13545 ,mem_vec_13546 ,mem_vec_13547 ,mem_vec_13548 ,mem_vec_13549 ,mem_vec_13550 ,mem_vec_13551 ,mem_vec_13552 ,mem_vec_13553 ,mem_vec_13554 ,mem_vec_13555 ,mem_vec_13556 ,mem_vec_13557 ,mem_vec_13558 ,mem_vec_13559 ,mem_vec_13560 ,mem_vec_13561 ,mem_vec_13562 ,mem_vec_13563 ,mem_vec_13564 ,mem_vec_13565 ,mem_vec_13566 ,mem_vec_13567 ,mem_vec_13568 ,mem_vec_13569 ,mem_vec_13570 ,mem_vec_13571 ,mem_vec_13572 ,mem_vec_13573 ,mem_vec_13574 ,mem_vec_13575 ,mem_vec_13576 ,mem_vec_13577 ,mem_vec_13578 ,mem_vec_13579 ,mem_vec_13580 ,mem_vec_13581 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 8) (512 / 64)
for (f1209 = f1210, f1209_p_0 = 0;
	f1209 < f1210 + 512;
	f1209 += 64, f1209_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 64
	// T (c, 2) (256 / 128)
	for (c1136 = c1137, c1136_p_0 = 0;
		c1136 < c1137 + 256;
		c1136 += 128, c1136_p_0 += 128){
		// y = 34, x = 34, h = 3, w = 3, c = 128, f = 64
		// T (f, 1) (64 / 64)
		for (f1208 = f1209, f1208_p_1 = f1209_p_0, f1208_p_0 = 0;
			f1208 < f1209 + 64;
			f1208 += 64, f1208_p_1 += 64, f1208_p_0 += 64){
				for (y = y696, yp_0 = 0;
					y < y696 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (x, 17) (34 / 2)
					for (x1136 = x1137, x1136_p_0 = 0;
						x1136 < x1137 + 34;
						x1136 += 2, x1136_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
						// T (f, 1) (64 / 64)
						for (f = f1208, fp_2 = f1208_p_1, fp_1 = f1208_p_0, fp_0 = 0;
							f < f1208 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h536, hp_0 = 0;
								h < h536 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 128, f = 64
								// T (x, 2) (2 / 1)
								for (x = x1136, xp_1 = x1136_p_0, xp_0 = 0;
									x < x1136 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13542 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13543 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13544 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_13545 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_13546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_13549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_13550 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13551 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13552 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_13553 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_13554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_13557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c1136, cp_1 = c1136_p_0, cp_0 = 0;
												c < c1136 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13542);
												mem_vec_13542 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13543);
												mem_vec_13543 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13544);
												mem_vec_13544 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13545);
												mem_vec_13545 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13546);
												mem_vec_13546 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13547);
												mem_vec_13547 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13548);
												mem_vec_13548 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13549);
												mem_vec_13549 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13550);
												mem_vec_13550 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13551);
												mem_vec_13551 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13552);
												mem_vec_13552 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13553);
												mem_vec_13553 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13554);
												mem_vec_13554 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13555);
												mem_vec_13555 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13556);
												mem_vec_13556 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13557);
												mem_vec_13557 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_13542);
												mem_vec_13542 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_13543);
												mem_vec_13543 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_13544);
												mem_vec_13544 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_13545);
												mem_vec_13545 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_13546);
												mem_vec_13546 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_13547);
												mem_vec_13547 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_13548);
												mem_vec_13548 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_13549);
												mem_vec_13549 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_13550);
												mem_vec_13550 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_13551);
												mem_vec_13551 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_13552);
												mem_vec_13552 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_13553);
												mem_vec_13553 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_13554);
												mem_vec_13554 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_13555);
												mem_vec_13555 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_13556);
												mem_vec_13556 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_13557);
												mem_vec_13557 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_13542);
												mem_vec_13542 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_13543);
												mem_vec_13543 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_13544);
												mem_vec_13544 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_13545);
												mem_vec_13545 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_13546);
												mem_vec_13546 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_13547);
												mem_vec_13547 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_13548);
												mem_vec_13548 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_13549);
												mem_vec_13549 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_13550);
												mem_vec_13550 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_13551);
												mem_vec_13551 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_13552);
												mem_vec_13552 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_13553);
												mem_vec_13553 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_13554);
												mem_vec_13554 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_13555);
												mem_vec_13555 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_13556);
												mem_vec_13556 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_13557);
												mem_vec_13557 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13542);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13543);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13544);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13545);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13546);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13547);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13548);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13549);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13550);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13551);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13552);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13553);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13554);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13555);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13556);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13557);
								}
							}
						}
					}
				}
				for (y = y696 + 4, yp_0 = 0;
					y < y696 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 64
					// T (x, 17) (34 / 2)
					for (x1136 = x1137, x1136_p_0 = 0;
						x1136 < x1137 + 34;
						x1136 += 2, x1136_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
						// T (f, 1) (64 / 64)
						for (f = f1208, fp_2 = f1208_p_1, fp_1 = f1208_p_0, fp_0 = 0;
							f < f1208 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 64
							// T (h, 3) (3 / 1)
							for (h = h536, hp_0 = 0;
								h < h536 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 3, c = 128, f = 64
								// T (x, 2) (2 / 1)
								for (x = x1136, xp_1 = x1136_p_0, xp_0 = 0;
									x < x1136 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13558 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13559 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13560 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_13561 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_13562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_13565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_13566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_13569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_13570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_13573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_13574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_13575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_13576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_13577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_13578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_13579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_13580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_13581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 128, f = 64
											// T (c, 128) (128 / 1)
											for (c = c1136, cp_1 = c1136_p_0, cp_0 = 0;
												c < c1136 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13558);
												mem_vec_13558 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13559);
												mem_vec_13559 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13560);
												mem_vec_13560 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13561);
												mem_vec_13561 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13562);
												mem_vec_13562 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13563);
												mem_vec_13563 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13564);
												mem_vec_13564 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13565);
												mem_vec_13565 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13566);
												mem_vec_13566 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13567);
												mem_vec_13567 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13568);
												mem_vec_13568 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13569);
												mem_vec_13569 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13570);
												mem_vec_13570 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13571);
												mem_vec_13571 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13572);
												mem_vec_13572 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13573);
												mem_vec_13573 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13574);
												mem_vec_13574 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13575);
												mem_vec_13575 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13576);
												mem_vec_13576 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13577);
												mem_vec_13577 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13578);
												mem_vec_13578 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13579);
												mem_vec_13579 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13580);
												mem_vec_13580 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13581);
												mem_vec_13581 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_13558);
												mem_vec_13558 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_13559);
												mem_vec_13559 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_13560);
												mem_vec_13560 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_13561);
												mem_vec_13561 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_13562);
												mem_vec_13562 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_13563);
												mem_vec_13563 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_13564);
												mem_vec_13564 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_13565);
												mem_vec_13565 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_13566);
												mem_vec_13566 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_13567);
												mem_vec_13567 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_13568);
												mem_vec_13568 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_13569);
												mem_vec_13569 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_13570);
												mem_vec_13570 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_13571);
												mem_vec_13571 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_13572);
												mem_vec_13572 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_13573);
												mem_vec_13573 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_13574);
												mem_vec_13574 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_13575);
												mem_vec_13575 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_13576);
												mem_vec_13576 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_13577);
												mem_vec_13577 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_13578);
												mem_vec_13578 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_13579);
												mem_vec_13579 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_13580);
												mem_vec_13580 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_13581);
												mem_vec_13581 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_13558);
												mem_vec_13558 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_13559);
												mem_vec_13559 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_13560);
												mem_vec_13560 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_13561);
												mem_vec_13561 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_13562);
												mem_vec_13562 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_13563);
												mem_vec_13563 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_13564);
												mem_vec_13564 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_13565);
												mem_vec_13565 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_13566);
												mem_vec_13566 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_13567);
												mem_vec_13567 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_13568);
												mem_vec_13568 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_13569);
												mem_vec_13569 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_13570);
												mem_vec_13570 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_13571);
												mem_vec_13571 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_13572);
												mem_vec_13572 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_13573);
												mem_vec_13573 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_13574);
												mem_vec_13574 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_13575);
												mem_vec_13575 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_13576);
												mem_vec_13576 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_13577);
												mem_vec_13577 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_13578);
												mem_vec_13578 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_13579);
												mem_vec_13579 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_13580);
												mem_vec_13580 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_13581);
												mem_vec_13581 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13558);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13559);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_13560);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_13561);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13562);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13563);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_13564);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_13565);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13566);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13567);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_13568);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_13569);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13570);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13571);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_13572);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_13573);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13574);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13575);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_13576);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_13577);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13578);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13579);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_13580);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_13581);
								}
							}
						}
					}
				}
		}
	}
}


}