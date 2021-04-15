#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (2, x); T (1, y); T (2, f); T (1, x); T (7, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, f, fp_0, x, xp_0, x95_p_0, x96_p_0, x97_p_0, xp_1, x95_p_1, x96_p_1, xp_2, x95_p_2, xp_3, x95, x96, x97, y, yp_0, y76_p_0, y77_p_0, yp_1, y76_p_1, yp_2, y76, y77;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y78 = 0;
IND_TYPE x98 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c58 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,mem_vec_308 ,mem_vec_309 ,mem_vec_310 ,mem_vec_311 ,mem_vec_312 ,mem_vec_313 ,mem_vec_314 ,mem_vec_315 ,mem_vec_316 ,mem_vec_317 ,mem_vec_318 ,mem_vec_319 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y77 = y78, y77_p_0 = 0;
	y77 < y78 + 56;
	y77 += 56, y77_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x97 = x98, x97_p_0 = 0;
		x97 < x98 + 56;
		x97 += 2, x97_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (56 / 8)
		for (y76 = y77, y76_p_1 = y77_p_0, y76_p_0 = 0;
			y76 < y77 + 56;
			y76 += 8, y76_p_1 += 8, y76_p_0 += 8){
			// y = 8, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x96 = x97, x96_p_1 = x97_p_0, x96_p_0 = 0;
				x96 < x97 + 2;
				x96 += 2, x96_p_1 += 2, x96_p_0 += 2){
				// y = 8, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f38, fp_0 = 0;
					f < f38 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 1) (8 / 8)
					for (y = y76, yp_2 = y76_p_1, yp_1 = y76_p_0, yp_0 = 0;
						y < y76 + 8;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x95 = x96, x95_p_2 = x96_p_1, x95_p_1 = x96_p_0, x95_p_0 = 0;
							x95 < x96 + 2;
							x95 += 1, x95_p_2 += 1, x95_p_1 += 1, x95_p_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c57 = c58, c57_p_0 = 0;
								c57 < c58 + 64;
								c57 += 32, c57_p_0 += 32){
								// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x95, xp_3 = x95_p_2, xp_2 = x95_p_1, xp_1 = x95_p_0, xp_0 = 0;
									x < x95 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
												c < c57 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_304);
												mem_vec_304 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_305);
												mem_vec_305 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_306);
												mem_vec_306 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_307);
												mem_vec_307 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_308);
												mem_vec_308 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_309);
												mem_vec_309 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_310);
												mem_vec_310 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_311);
												mem_vec_311 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_312);
												mem_vec_312 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_313);
												mem_vec_313 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_314);
												mem_vec_314 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_315);
												mem_vec_315 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_316);
												mem_vec_316 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_317);
												mem_vec_317 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_318);
												mem_vec_318 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_319);
												mem_vec_319 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_304);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_305);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_306);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_307);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_308);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_309);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_310);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_311);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_312);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_313);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_314);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_315);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_316);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_317);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_318);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_319);
								}
							}
						}
					}
				}
			}
		}
	}
}


}