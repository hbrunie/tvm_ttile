#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (2, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (4, x)]
*/
IND_TYPE c, cp_0, c426_p_0, cp_1, c426, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x526_p_0, x527_p_0, xp_1, x526_p_1, xp_2, x526, x527, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y305 = 0;
IND_TYPE x528 = 0;
IND_TYPE h245 = 0;
IND_TYPE w254 = 0;
IND_TYPE c427 = 0;
IND_TYPE f234 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4272 ,mem_vec_4273 ,mem_vec_4274 ,mem_vec_4275 ,mem_vec_4276 ,mem_vec_4277 ,mem_vec_4278 ,mem_vec_4279 ,mem_vec_4280 ,mem_vec_4281 ,mem_vec_4282 ,mem_vec_4283 ,mem_vec_4284 ,mem_vec_4285 ,mem_vec_4286 ,mem_vec_4287 ,mem_vec_4288 ,mem_vec_4289 ,mem_vec_4290 ,mem_vec_4291 ,mem_vec_4292 ,mem_vec_4293 ,mem_vec_4294 ,mem_vec_4295 ,mem_vec_4296 ,mem_vec_4297 ,mem_vec_4298 ,mem_vec_4299 ,mem_vec_4300 ,mem_vec_4301 ,mem_vec_4302 ,mem_vec_4303 ,mem_vec_4304 ,mem_vec_4305 ,mem_vec_4306 ,mem_vec_4307 ,mem_vec_4308 ,mem_vec_4309 ,mem_vec_4310 ,mem_vec_4311 ,mem_vec_4312 ,mem_vec_4313 ,mem_vec_4314 ,mem_vec_4315 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
for (x527 = x528, x527_p_0 = 0;
	x527 < x528 + 56;
	x527 += 14, x527_p_0 += 14){
		for (y = y305, yp_0 = 0;
			y < y305 + 20;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (14 / 14)
			for (x526 = x527, x526_p_1 = x527_p_0, x526_p_0 = 0;
				x526 < x527 + 14;
				x526 += 14, x526_p_1 += 14, x526_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f234, fp_0 = 0;
					f < f234 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c426 = c427, c426_p_0 = 0;
						c426 < c427 + 64;
						c426 += 16, c426_p_0 += 16){
						// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w254, wp_0 = 0;
							w < w254 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 16, f = 32
							// T (x, 14) (14 / 1)
							for (x = x526, xp_2 = x526_p_1, xp_1 = x526_p_0, xp_0 = 0;
								x < x526 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h245, hp_0 = 0;
									h < h245 + 3;
									h += 1, hp_0 += 1){
											mem_vec_4272 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4273 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c426, cp_1 = c426_p_0, cp_0 = 0;
												c < c426 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4272);
												mem_vec_4272 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4273);
												mem_vec_4273 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4274);
												mem_vec_4274 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4275);
												mem_vec_4275 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4276);
												mem_vec_4276 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4277);
												mem_vec_4277 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4278);
												mem_vec_4278 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4279);
												mem_vec_4279 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4280);
												mem_vec_4280 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4281);
												mem_vec_4281 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4282);
												mem_vec_4282 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4283);
												mem_vec_4283 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4284);
												mem_vec_4284 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4285);
												mem_vec_4285 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4286);
												mem_vec_4286 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4287);
												mem_vec_4287 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4288);
												mem_vec_4288 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4289);
												mem_vec_4289 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4290);
												mem_vec_4290 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4291);
												mem_vec_4291 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4272);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4273);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4274);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4275);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4276);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4277);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4278);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4279);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4280);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4281);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4282);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4283);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4284);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4285);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4286);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4287);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4288);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4289);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4290);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4291);
								}
							}
						}
					}
				}
			}
		}
		for (y = y305 + 20, yp_0 = 0;
			y < y305 + 20 + 36;
			y += 12, yp_0 += 12){
			// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
			// T (x, 1) (14 / 14)
			for (x526 = x527, x526_p_1 = x527_p_0, x526_p_0 = 0;
				x526 < x527 + 14;
				x526 += 14, x526_p_1 += 14, x526_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f234, fp_0 = 0;
					f < f234 + 64;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c426 = c427, c426_p_0 = 0;
						c426 < c427 + 64;
						c426 += 16, c426_p_0 += 16){
						// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w254, wp_0 = 0;
							w < w254 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 16, f = 32
							// T (x, 14) (14 / 1)
							for (x = x526, xp_2 = x526_p_1, xp_1 = x526_p_0, xp_0 = 0;
								x < x526 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h245, hp_0 = 0;
									h < h245 + 3;
									h += 1, hp_0 += 1){
											mem_vec_4292 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4293 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_4312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_4313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_4314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_4315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c426, cp_1 = c426_p_0, cp_0 = 0;
												c < c426 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4292);
												mem_vec_4292 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4293);
												mem_vec_4293 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4294);
												mem_vec_4294 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4295);
												mem_vec_4295 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4296);
												mem_vec_4296 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4297);
												mem_vec_4297 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4298);
												mem_vec_4298 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4299);
												mem_vec_4299 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4300);
												mem_vec_4300 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4301);
												mem_vec_4301 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4302);
												mem_vec_4302 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4303);
												mem_vec_4303 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4304);
												mem_vec_4304 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4305);
												mem_vec_4305 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4306);
												mem_vec_4306 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4307);
												mem_vec_4307 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4308);
												mem_vec_4308 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4309);
												mem_vec_4309 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4310);
												mem_vec_4310 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4311);
												mem_vec_4311 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4312);
												mem_vec_4312 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4313);
												mem_vec_4313 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4314);
												mem_vec_4314 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4315);
												mem_vec_4315 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4292);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4293);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4294);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4295);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4296);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4297);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4298);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4299);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4300);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4301);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4302);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4303);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4304);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4305);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4306);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4307);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4308);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4309);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4310);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4311);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4312);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4313);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4314);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4315);
								}
							}
						}
					}
				}
			}
		}
}


}