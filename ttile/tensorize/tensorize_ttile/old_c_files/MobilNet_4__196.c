#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (28, x); T (3, w);
  T (3, h); T (1, f); T (16, c); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 1), (Arg 10))]; T (4, f)]
*/
IND_TYPE c, cp_0, c660_p_0, cp_1, c660, f, fp_0, f660_p_0, fp_1, f660, h, hp_0, w, wp_0, x, xp_0, x660_p_0, xp_1, x660, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y440 = 0;
IND_TYPE x661 = 0;
IND_TYPE h372 = 0;
IND_TYPE w410 = 0;
IND_TYPE c661 = 0;
IND_TYPE f661 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6188 ,mem_vec_6189 ,mem_vec_6190 ,mem_vec_6191 ,mem_vec_6192 ,mem_vec_6193 ,mem_vec_6194 ,mem_vec_6195 ,mem_vec_6196 ,mem_vec_6197 ,mem_vec_6198 ,mem_vec_6199 ,mem_vec_6200 ,mem_vec_6201 ,mem_vec_6202 ,mem_vec_6203 ,mem_vec_6204 ,mem_vec_6205 ,mem_vec_6206 ,mem_vec_6207 ,mem_vec_6208 ,mem_vec_6209 ,mem_vec_6210 ,mem_vec_6211 ,mem_vec_6212 ,mem_vec_6213 ,mem_vec_6214 ,mem_vec_6215 ,mem_vec_6216 ,mem_vec_6217 ,mem_vec_6218 ,mem_vec_6219 ,mem_vec_6220 ,mem_vec_6221 ,mem_vec_6222 ,mem_vec_6223 ,mem_vec_6224 ,mem_vec_6225 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
for (f660 = f661, f660_p_0 = 0;
	f660 < f661 + 128;
	f660 += 32, f660_p_0 += 32){
		for (y = y440, yp_0 = 0;
			y < y440 + 18;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (28 / 28)
			for (x660 = x661, x660_p_0 = 0;
				x660 < x661 + 28;
				x660 += 28, x660_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 16) (128 / 8)
				for (c660 = c661, c660_p_0 = 0;
					c660 < c661 + 128;
					c660 += 8, c660_p_0 += 8){
					// y = ph_y, x = 28, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f660, fp_1 = f660_p_0, fp_0 = 0;
						f < f660 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h372, hp_0 = 0;
							h < h372 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w410, wp_0 = 0;
								w < w410 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 8, f = 32
								// T (x, 28) (28 / 1)
								for (x = x660, xp_1 = x660_p_0, xp_0 = 0;
									x < x660 + 28;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6188 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6189 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c660, cp_1 = c660_p_0, cp_0 = 0;
												c < c660 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6188);
												mem_vec_6188 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6189);
												mem_vec_6189 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6190);
												mem_vec_6190 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6191);
												mem_vec_6191 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6192);
												mem_vec_6192 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6193);
												mem_vec_6193 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6194);
												mem_vec_6194 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6195);
												mem_vec_6195 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6196);
												mem_vec_6196 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6197);
												mem_vec_6197 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6198);
												mem_vec_6198 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6199);
												mem_vec_6199 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6200);
												mem_vec_6200 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6201);
												mem_vec_6201 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6202);
												mem_vec_6202 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6203);
												mem_vec_6203 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6204);
												mem_vec_6204 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6205);
												mem_vec_6205 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6188);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6189);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6190);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6191);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6192);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6193);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6194);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6195);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6196);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6197);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6198);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6199);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6200);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6201);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6202);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6203);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6204);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6205);
								}
							}
						}
					}
				}
			}
		}
		for (y = y440 + 18, yp_0 = 0;
			y < y440 + 18 + 10;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 1) (28 / 28)
			for (x660 = x661, x660_p_0 = 0;
				x660 < x661 + 28;
				x660 += 28, x660_p_0 += 28){
				// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 16) (128 / 8)
				for (c660 = c661, c660_p_0 = 0;
					c660 < c661 + 128;
					c660 += 8, c660_p_0 += 8){
					// y = ph_y, x = 28, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f660, fp_1 = f660_p_0, fp_0 = 0;
						f < f660 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 28, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h372, hp_0 = 0;
							h < h372 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 28, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w410, wp_0 = 0;
								w < w410 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 28, h = 1, w = 1, c = 8, f = 32
								// T (x, 28) (28 / 1)
								for (x = x660, xp_1 = x660_p_0, xp_0 = 0;
									x < x660 + 28;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6206 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6207 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c660, cp_1 = c660_p_0, cp_0 = 0;
												c < c660 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6206);
												mem_vec_6206 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6207);
												mem_vec_6207 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6208);
												mem_vec_6208 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6209);
												mem_vec_6209 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6210);
												mem_vec_6210 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6211);
												mem_vec_6211 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6212);
												mem_vec_6212 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6213);
												mem_vec_6213 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6214);
												mem_vec_6214 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6215);
												mem_vec_6215 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6216);
												mem_vec_6216 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6217);
												mem_vec_6217 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6218);
												mem_vec_6218 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6219);
												mem_vec_6219 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6220);
												mem_vec_6220 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6221);
												mem_vec_6221 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6222);
												mem_vec_6222 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6223);
												mem_vec_6223 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6224);
												mem_vec_6224 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6225);
												mem_vec_6225 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6206);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6207);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6208);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6209);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6210);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6211);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6212);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6213);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6214);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6215);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6216);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6217);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6218);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6219);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6220);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6221);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6222);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6223);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6224);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6225);
								}
							}
						}
					}
				}
			}
		}
}


}