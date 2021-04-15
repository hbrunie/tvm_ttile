#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (16, c); T (8, f);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 1), (Arg 4))]; T (8, c);
  T (2, f); T (2, c)]
*/
IND_TYPE c, cp_0, c1798_p_0, c1799_p_0, c1800_p_0, cp_1, c1798_p_1, c1799_p_1, cp_2, c1798_p_2, cp_3, c1798, c1799, c1800, f, fp_0, f1194_p_0, fp_1, f1194, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y602 = 0;
IND_TYPE x748 = 0;
IND_TYPE h566 = 0;
IND_TYPE w = 0;
IND_TYPE c1801 = 0;
IND_TYPE f1195 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7252 ,mem_vec_7253 ,mem_vec_7254 ,mem_vec_7255 ,mem_vec_7256 ,mem_vec_7257 ,mem_vec_7258 ,mem_vec_7259 ,mem_vec_7260 ,mem_vec_7261 ,mem_vec_7262 ,mem_vec_7263 ,mem_vec_7264 ,mem_vec_7265 ,mem_vec_7266 ,mem_vec_7267 ,mem_vec_7268 ,mem_vec_7269 ,mem_vec_7270 ,mem_vec_7271 ,mem_vec_7272 ,mem_vec_7273 ,mem_vec_7274 ,mem_vec_7275 ,mem_vec_7276 ,mem_vec_7277 ,mem_vec_7278 ,mem_vec_7279 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 2) (1024 / 512)
for (c1800 = c1801, c1800_p_0 = 0;
	c1800 < c1801 + 1024;
	c1800 += 512, c1800_p_0 += 512){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 1024
	// T (f, 2) (1024 / 512)
	for (f1194 = f1195, f1194_p_0 = 0;
		f1194 < f1195 + 1024;
		f1194 += 512, f1194_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
		// T (c, 8) (512 / 64)
		for (c1799 = c1800, c1799_p_1 = c1800_p_0, c1799_p_0 = 0;
			c1799 < c1800 + 512;
			c1799 += 64, c1799_p_1 += 64, c1799_p_0 += 64){
				for (y = y602, yp_0 = 0;
					y < y602 + 3;
					y += 3, yp_0 += 3){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 512
					// T (f, 8) (512 / 64)
					for (f = f1194, fp_1 = f1194_p_0, fp_0 = 0;
						f < f1194 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
						// T (c, 16) (64 / 4)
						for (c1798 = c1799, c1798_p_2 = c1799_p_1, c1798_p_1 = c1799_p_0, c1798_p_0 = 0;
							c1798 < c1799 + 64;
							c1798 += 4, c1798_p_2 += 4, c1798_p_1 += 4, c1798_p_0 += 4){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h566, hp_0 = 0;
								h < h566 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 64
								// T (x, 7) (7 / 1)
								for (x = x748, xp_0 = 0;
									x < x748 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7254 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7255 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c1798, cp_3 = c1798_p_2, cp_2 = c1798_p_1, cp_1 = c1798_p_0, cp_0 = 0;
												c < c1798 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7252);
												mem_vec_7252 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7253);
												mem_vec_7253 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7254);
												mem_vec_7254 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7255);
												mem_vec_7255 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7256);
												mem_vec_7256 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7257);
												mem_vec_7257 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7258);
												mem_vec_7258 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7259);
												mem_vec_7259 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7260);
												mem_vec_7260 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7261);
												mem_vec_7261 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7262);
												mem_vec_7262 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7263);
												mem_vec_7263 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);
												vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_7252);
												mem_vec_7252 = vec_19;

												vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_7253);
												mem_vec_7253 = vec_22;

												vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_7254);
												mem_vec_7254 = vec_24;

												vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_7255);
												mem_vec_7255 = vec_26;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_29 = _mm512_set1_ps(scal_4);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_7256);
												mem_vec_7256 = vec_28;



												vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_7257);
												mem_vec_7257 = vec_30;



												vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_7258);
												mem_vec_7258 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_7259);
												mem_vec_7259 = vec_32;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_7260);
												mem_vec_7260 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_7261);
												mem_vec_7261 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_7262);
												mem_vec_7262 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_7263);
												mem_vec_7263 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);
												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_7252);
												mem_vec_7252 = vec_38;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_7253);
												mem_vec_7253 = vec_41;

												vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_7254);
												mem_vec_7254 = vec_43;

												vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_7255);
												mem_vec_7255 = vec_45;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_48 = _mm512_set1_ps(scal_7);


												vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_7256);
												mem_vec_7256 = vec_47;



												vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_7257);
												mem_vec_7257 = vec_49;



												vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_7258);
												mem_vec_7258 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_7259);
												mem_vec_7259 = vec_51;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_53 = _mm512_set1_ps(scal_8);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_7260);
												mem_vec_7260 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_7261);
												mem_vec_7261 = vec_54;



												vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_7262);
												mem_vec_7262 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_7263);
												mem_vec_7263 = vec_56;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7252);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7253);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7254);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7255);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7256);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7257);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7258);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7259);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7260);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7261);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7262);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7263);
								}
							}
						}
					}
				}
				for (y = y602 + 3, yp_0 = 0;
					y < y602 + 3 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 512
					// T (f, 8) (512 / 64)
					for (f = f1194, fp_1 = f1194_p_0, fp_0 = 0;
						f < f1194 + 512;
						f += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 7, h = 3, w = 3, c = 64, f = 64
						// T (c, 16) (64 / 4)
						for (c1798 = c1799, c1798_p_2 = c1799_p_1, c1798_p_1 = c1799_p_0, c1798_p_0 = 0;
							c1798 < c1799 + 64;
							c1798 += 4, c1798_p_2 += 4, c1798_p_1 += 4, c1798_p_0 += 4){
							// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h566, hp_0 = 0;
								h < h566 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 3, c = 4, f = 64
								// T (x, 7) (7 / 1)
								for (x = x748, xp_0 = 0;
									x < x748 + 7;
									x += 1, xp_0 += 1){
											mem_vec_7264 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7265 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7266 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_7267 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_7268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_7271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_7272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_7275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_7276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_7279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c1798, cp_3 = c1798_p_2, cp_2 = c1798_p_1, cp_1 = c1798_p_0, cp_0 = 0;
												c < c1798 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7264);
												mem_vec_7264 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7265);
												mem_vec_7265 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7266);
												mem_vec_7266 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7267);
												mem_vec_7267 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7268);
												mem_vec_7268 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7269);
												mem_vec_7269 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7270);
												mem_vec_7270 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7271);
												mem_vec_7271 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7272);
												mem_vec_7272 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7273);
												mem_vec_7273 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7274);
												mem_vec_7274 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7275);
												mem_vec_7275 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7276);
												mem_vec_7276 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7277);
												mem_vec_7277 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7278);
												mem_vec_7278 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7279);
												mem_vec_7279 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);
												vec_26 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_24 = _mm512_fmadd_ps(vec_25, vec_26, mem_vec_7264);
												mem_vec_7264 = vec_24;

												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_27 = _mm512_fmadd_ps(vec_25, vec_28, mem_vec_7265);
												mem_vec_7265 = vec_27;

												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_29 = _mm512_fmadd_ps(vec_25, vec_30, mem_vec_7266);
												mem_vec_7266 = vec_29;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_31 = _mm512_fmadd_ps(vec_25, vec_32, mem_vec_7267);
												mem_vec_7267 = vec_31;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_34 = _mm512_set1_ps(scal_5);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_26, mem_vec_7268);
												mem_vec_7268 = vec_33;



												vec_35 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_7269);
												mem_vec_7269 = vec_35;



												vec_36 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_7270);
												mem_vec_7270 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_7271);
												mem_vec_7271 = vec_37;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_26, mem_vec_7272);
												mem_vec_7272 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_28, mem_vec_7273);
												mem_vec_7273 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_30, mem_vec_7274);
												mem_vec_7274 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_32, mem_vec_7275);
												mem_vec_7275 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_26, mem_vec_7276);
												mem_vec_7276 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_7277);
												mem_vec_7277 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_7278);
												mem_vec_7278 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_7279);
												mem_vec_7279 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);
												vec_50 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_48 = _mm512_fmadd_ps(vec_49, vec_50, mem_vec_7264);
												mem_vec_7264 = vec_48;

												vec_52 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_51 = _mm512_fmadd_ps(vec_49, vec_52, mem_vec_7265);
												mem_vec_7265 = vec_51;

												vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_53 = _mm512_fmadd_ps(vec_49, vec_54, mem_vec_7266);
												mem_vec_7266 = vec_53;

												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_55 = _mm512_fmadd_ps(vec_49, vec_56, mem_vec_7267);
												mem_vec_7267 = vec_55;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_58 = _mm512_set1_ps(scal_9);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_50, mem_vec_7268);
												mem_vec_7268 = vec_57;



												vec_59 = _mm512_fmadd_ps(vec_58, vec_52, mem_vec_7269);
												mem_vec_7269 = vec_59;



												vec_60 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_7270);
												mem_vec_7270 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_7271);
												mem_vec_7271 = vec_61;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_63 = _mm512_set1_ps(scal_10);


												vec_62 = _mm512_fmadd_ps(vec_63, vec_50, mem_vec_7272);
												mem_vec_7272 = vec_62;



												vec_64 = _mm512_fmadd_ps(vec_63, vec_52, mem_vec_7273);
												mem_vec_7273 = vec_64;



												vec_65 = _mm512_fmadd_ps(vec_63, vec_54, mem_vec_7274);
												mem_vec_7274 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_63, vec_56, mem_vec_7275);
												mem_vec_7275 = vec_66;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_50, mem_vec_7276);
												mem_vec_7276 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_52, mem_vec_7277);
												mem_vec_7277 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_54, mem_vec_7278);
												mem_vec_7278 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_7279);
												mem_vec_7279 = vec_71;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7264);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7265);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7266);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7267);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7268);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7269);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7270);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7271);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7272);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7273);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7274);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7275);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7276);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7277);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7278);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7279);
								}
							}
						}
					}
				}
		}
	}
}


}