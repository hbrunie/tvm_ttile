#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (3, w); T (3, h);
  Lambda_apply y [((Iter 13), (Arg 14)); ((Iter 6), (Arg 15))]; T (1, x);
  T (544, x); T (2, y)]
*/
IND_TYPE c, cp_0, c282_p_0, cp_1, c282, h, hp_0, w, wp_0, x, xp_0, x424_p_0, x425_p_0, xp_1, x424_p_1, xp_2, x424, x425, y, yp_0, y354_p_0, yp_1, y354;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y355 = 0;
IND_TYPE x426 = 0;
IND_TYPE h176 = 0;
IND_TYPE w212 = 0;
IND_TYPE c283 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3196 ,mem_vec_3197 ,mem_vec_3198 ,mem_vec_3199 ,mem_vec_3200 ,mem_vec_3201 ,mem_vec_3202 ,mem_vec_3203 ,mem_vec_3204 ,mem_vec_3205 ,mem_vec_3206 ,mem_vec_3207 ,mem_vec_3208 ,mem_vec_3209 ,mem_vec_3210 ,mem_vec_3211 ,mem_vec_3212 ,mem_vec_3213 ,mem_vec_3214 ,mem_vec_3215 ,mem_vec_3216 ,mem_vec_3217 ,mem_vec_3218 ,mem_vec_3219 ,mem_vec_3220 ,mem_vec_3221 ,mem_vec_3222 ,mem_vec_3223 ,mem_vec_3224 ,mem_vec_3225 ,mem_vec_3226 ,mem_vec_3227 ,mem_vec_3228 ,mem_vec_3229 ,mem_vec_3230 ,mem_vec_3231 ,mem_vec_3232 ,mem_vec_3233 ,mem_vec_3234 ,mem_vec_3235 ,mem_vec_3236 ,mem_vec_3237 ,mem_vec_3238 ,mem_vec_3239 ,mem_vec_3240 ,mem_vec_3241 ,mem_vec_3242 ,mem_vec_3243 ,mem_vec_3244 ,mem_vec_3245 ,mem_vec_3246 ,mem_vec_3247 ,mem_vec_3248 ,mem_vec_3249 ,mem_vec_3250 ,mem_vec_3251 ,mem_vec_3252 ,mem_vec_3253 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
for (y354 = y355, y354_p_0 = 0;
	y354 < y355 + 544;
	y354 += 272, y354_p_0 += 272){
	// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 544) (544 / 1)
	for (x425 = x426, x425_p_0 = 0;
		x425 < x426 + 544;
		x425 += 1, x425_p_0 += 1){
		// y = 272, x = 1, h = 3, w = 3, c = 3, f = 32
		// T (x, 1) (1 / 1)
		for (x424 = x425, x424_p_1 = x425_p_0, x424_p_0 = 0;
			x424 < x425 + 1;
			x424 += 1, x424_p_1 += 1, x424_p_0 += 1){
				for (y = y354, yp_1 = y354_p_0, yp_0 = 0;
					y < y354 + 182;
					y += 14, yp_1 += 14, yp_0 += 14){
					// y = ph_y, x = 1, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h176, hp_0 = 0;
						h < h176 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w212, wp_0 = 0;
							w < w212 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c282 = c283, c282_p_0 = 0;
								c282 < c283 + 3;
								c282 += 3, c282_p_0 += 3){
								// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
								// T (x, 1) (1 / 1)
								for (x = x424, xp_2 = x424_p_1, xp_1 = x424_p_0, xp_0 = 0;
									x < x424 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3196 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3197 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_3216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_3217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_3218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_3219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_3220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_3221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_3222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_3223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c282, cp_1 = c282_p_0, cp_0 = 0;
												c < c282 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3196);
												mem_vec_3196 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3197);
												mem_vec_3197 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3198);
												mem_vec_3198 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3199);
												mem_vec_3199 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3200);
												mem_vec_3200 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3201);
												mem_vec_3201 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3202);
												mem_vec_3202 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3203);
												mem_vec_3203 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3204);
												mem_vec_3204 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3205);
												mem_vec_3205 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3206);
												mem_vec_3206 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3207);
												mem_vec_3207 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3208);
												mem_vec_3208 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3209);
												mem_vec_3209 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3210);
												mem_vec_3210 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3211);
												mem_vec_3211 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3212);
												mem_vec_3212 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3213);
												mem_vec_3213 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3214);
												mem_vec_3214 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3215);
												mem_vec_3215 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3216);
												mem_vec_3216 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3217);
												mem_vec_3217 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3218);
												mem_vec_3218 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3219);
												mem_vec_3219 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3220);
												mem_vec_3220 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3221);
												mem_vec_3221 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3222);
												mem_vec_3222 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3223);
												mem_vec_3223 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3196);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3197);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3198);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3199);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3200);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3201);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3202);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3203);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3204);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3205);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3206);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3207);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3208);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3209);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3210);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3211);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3212);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3213);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3214);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3215);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3216);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3217);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3218);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3219);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3220);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3221);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3222);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3223);
								}
							}
						}
					}
				}
				for (y = y354 + 182, yp_1 = y354_p_0, yp_0 = 0;
					y < y354 + 182 + 90;
					y += 15, yp_1 += 15, yp_0 += 15){
					// y = ph_y, x = 1, h = 3, w = 3, c = 3, f = 32
					// T (h, 3) (3 / 1)
					for (h = h176, hp_0 = 0;
						h < h176 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 3, f = 32
						// T (w, 3) (3 / 1)
						for (w = w212, wp_0 = 0;
							w < w212 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (c, 1) (3 / 3)
							for (c282 = c283, c282_p_0 = 0;
								c282 < c283 + 3;
								c282 += 3, c282_p_0 += 3){
								// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
								// T (x, 1) (1 / 1)
								for (x = x424, xp_2 = x424_p_1, xp_1 = x424_p_0, xp_0 = 0;
									x < x424 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3224 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3225 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_3244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_3245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_3246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_3247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_3248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_3249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_3250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_3251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_3252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_3253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 3, f = 32
											// T (c, 3) (3 / 1)
											for (c = c282, cp_1 = c282_p_0, cp_0 = 0;
												c < c282 + 3;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3224);
												mem_vec_3224 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3225);
												mem_vec_3225 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3226);
												mem_vec_3226 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3227);
												mem_vec_3227 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3228);
												mem_vec_3228 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3229);
												mem_vec_3229 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3230);
												mem_vec_3230 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3231);
												mem_vec_3231 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3232);
												mem_vec_3232 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3233);
												mem_vec_3233 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3234);
												mem_vec_3234 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3235);
												mem_vec_3235 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3236);
												mem_vec_3236 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3237);
												mem_vec_3237 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3238);
												mem_vec_3238 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3239);
												mem_vec_3239 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3240);
												mem_vec_3240 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3241);
												mem_vec_3241 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3242);
												mem_vec_3242 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3243);
												mem_vec_3243 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3244);
												mem_vec_3244 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3245);
												mem_vec_3245 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3246);
												mem_vec_3246 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3247);
												mem_vec_3247 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3248);
												mem_vec_3248 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3249);
												mem_vec_3249 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3250);
												mem_vec_3250 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3251);
												mem_vec_3251 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_3252);
												mem_vec_3252 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_3253);
												mem_vec_3253 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3224);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3225);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3226);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3227);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3228);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3229);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3230);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3231);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3232);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3233);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3234);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3235);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3236);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3237);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3238);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3239);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3240);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3241);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3242);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3243);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3244);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3245);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3246);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3247);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3248);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3249);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3250);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3251);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_3252);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_3253);
								}
							}
						}
					}
				}
		}
	}
}


}