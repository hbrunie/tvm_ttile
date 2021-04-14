#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, f); T (4, c); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 8)); ((Iter 1), (Arg 12))]; T (8, f)]
*/
IND_TYPE c, cp_0, c708_p_0, cp_1, c708, f, fp_0, f780_p_0, fp_1, f780, h, hp_0, w, wp_0, x, xp_0, x708_p_0, xp_1, x708, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y472 = 0;
IND_TYPE x709 = 0;
IND_TYPE h398 = 0;
IND_TYPE w422 = 0;
IND_TYPE c709 = 0;
IND_TYPE f781 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6164 ,mem_vec_6165 ,mem_vec_6166 ,mem_vec_6167 ,mem_vec_6168 ,mem_vec_6169 ,mem_vec_6170 ,mem_vec_6171 ,mem_vec_6172 ,mem_vec_6173 ,mem_vec_6174 ,mem_vec_6175 ,mem_vec_6176 ,mem_vec_6177 ,mem_vec_6178 ,mem_vec_6179 ,mem_vec_6180 ,mem_vec_6181 ,mem_vec_6182 ,mem_vec_6183 ,mem_vec_6184 ,mem_vec_6185 ,mem_vec_6186 ,mem_vec_6187 ,mem_vec_6188 ,mem_vec_6189 ,mem_vec_6190 ,mem_vec_6191 ,mem_vec_6192 ,mem_vec_6193 ,mem_vec_6194 ,mem_vec_6195 ,mem_vec_6196 ,mem_vec_6197 ,mem_vec_6198 ,mem_vec_6199 ,mem_vec_6200 ,mem_vec_6201 ,mem_vec_6202 ,mem_vec_6203 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f780 = f781, f780_p_0 = 0;
	f780 < f781 + 256;
	f780 += 32, f780_p_0 += 32){
		for (y = y472, yp_0 = 0;
			y < y472 + 16;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 2) (28 / 14)
			for (x708 = x709, x708_p_0 = 0;
				x708 < x709 + 28;
				x708 += 14, x708_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 32
				// T (c, 4) (128 / 32)
				for (c708 = c709, c708_p_0 = 0;
					c708 < c709 + 128;
					c708 += 32, c708_p_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f780, fp_1 = f780_p_0, fp_0 = 0;
						f < f780 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h398, hp_0 = 0;
							h < h398 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w422, wp_0 = 0;
								w < w422 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x708, xp_1 = x708_p_0, xp_0 = 0;
									x < x708 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6164 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6165 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c708, cp_1 = c708_p_0, cp_0 = 0;
												c < c708 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6164);
												mem_vec_6164 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6165);
												mem_vec_6165 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6166);
												mem_vec_6166 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6167);
												mem_vec_6167 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6168);
												mem_vec_6168 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6169);
												mem_vec_6169 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6170);
												mem_vec_6170 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6171);
												mem_vec_6171 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6172);
												mem_vec_6172 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6173);
												mem_vec_6173 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6174);
												mem_vec_6174 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6175);
												mem_vec_6175 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6176);
												mem_vec_6176 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6177);
												mem_vec_6177 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6178);
												mem_vec_6178 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6179);
												mem_vec_6179 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6164);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6165);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6166);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6167);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6168);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6169);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6170);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6171);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6172);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6173);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6174);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6175);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6176);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6177);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6178);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6179);
								}
							}
						}
					}
				}
			}
		}
		for (y = y472 + 16, yp_0 = 0;
			y < y472 + 16 + 12;
			y += 12, yp_0 += 12){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 2) (28 / 14)
			for (x708 = x709, x708_p_0 = 0;
				x708 < x709 + 28;
				x708 += 14, x708_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 32
				// T (c, 4) (128 / 32)
				for (c708 = c709, c708_p_0 = 0;
					c708 < c709 + 128;
					c708 += 32, c708_p_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
					// T (f, 1) (32 / 32)
					for (f = f780, fp_1 = f780_p_0, fp_0 = 0;
						f < f780 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h398, hp_0 = 0;
							h < h398 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w422, wp_0 = 0;
								w < w422 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x708, xp_1 = x708_p_0, xp_0 = 0;
									x < x708 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_6180 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_6181 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_6182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_6183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_6184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_6185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_6186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_6187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_6188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_6189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_6190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_6191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_6192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_6193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_6194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_6195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_6196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_6197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_6198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_6199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_6200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_6201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_6202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_6203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c708, cp_1 = c708_p_0, cp_0 = 0;
												c < c708 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6180);
												mem_vec_6180 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6181);
												mem_vec_6181 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6182);
												mem_vec_6182 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6183);
												mem_vec_6183 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6184);
												mem_vec_6184 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6185);
												mem_vec_6185 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6186);
												mem_vec_6186 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6187);
												mem_vec_6187 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6188);
												mem_vec_6188 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6189);
												mem_vec_6189 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6190);
												mem_vec_6190 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6191);
												mem_vec_6191 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6192);
												mem_vec_6192 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6193);
												mem_vec_6193 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6194);
												mem_vec_6194 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6195);
												mem_vec_6195 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6196);
												mem_vec_6196 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6197);
												mem_vec_6197 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6198);
												mem_vec_6198 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6199);
												mem_vec_6199 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6200);
												mem_vec_6200 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6201);
												mem_vec_6201 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6202);
												mem_vec_6202 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6203);
												mem_vec_6203 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6180);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6181);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6182);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6183);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6184);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6185);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6186);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6187);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6188);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6189);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6190);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6191);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6192);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6193);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6194);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6195);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6196);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6197);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6198);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6199);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6200);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6201);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6202);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6203);
								}
							}
						}
					}
				}
			}
		}
}


}