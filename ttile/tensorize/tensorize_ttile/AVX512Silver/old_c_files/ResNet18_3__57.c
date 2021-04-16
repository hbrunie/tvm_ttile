#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (2, x); T (8, y); T (2, f); T (1, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c63_p_0, cp_1, c63, f, fp_0, x, xp_0, x105_p_0, x106_p_0, x107_p_0, xp_1, x105_p_1, x106_p_1, xp_2, x105_p_2, xp_3, x105, x106, x107, y, yp_0, y84_p_0, y85_p_0, yp_1, y84_p_1, yp_2, y84, y85;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y86 = 0;
IND_TYPE x108 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c64 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_294 ,mem_vec_295 ,mem_vec_296 ,mem_vec_297 ,mem_vec_298 ,mem_vec_299 ,mem_vec_300 ,mem_vec_301 ,mem_vec_302 ,mem_vec_303 ,mem_vec_304 ,mem_vec_305 ,mem_vec_306 ,mem_vec_307 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y85 = y86, y85_p_0 = 0;
	y85 < y86 + 56;
	y85 += 56, y85_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x107 = x108, x107_p_0 = 0;
		x107 < x108 + 56;
		x107 += 2, x107_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y84 = y85, y84_p_1 = y85_p_0, y84_p_0 = 0;
			y84 < y85 + 56;
			y84 += 56, y84_p_1 += 56, y84_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x106 = x107, x106_p_1 = x107_p_0, x106_p_0 = 0;
				x106 < x107 + 2;
				x106 += 2, x106_p_1 += 2, x106_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f42, fp_0 = 0;
					f < f42 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y84, yp_2 = y84_p_1, yp_1 = y84_p_0, yp_0 = 0;
						y < y84 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x105 = x106, x105_p_2 = x106_p_1, x105_p_1 = x106_p_0, x105_p_0 = 0;
							x105 < x106 + 2;
							x105 += 1, x105_p_2 += 1, x105_p_1 += 1, x105_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c63 = c64, c63_p_0 = 0;
								c63 < c64 + 64;
								c63 += 64, c63_p_0 += 64){
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x105, xp_3 = x105_p_2, xp_2 = x105_p_1, xp_1 = x105_p_0, xp_0 = 0;
									x < x105 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_294 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_295 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
												c < c63 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_294);
												mem_vec_294 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_295);
												mem_vec_295 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_296);
												mem_vec_296 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_297);
												mem_vec_297 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_298);
												mem_vec_298 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_299);
												mem_vec_299 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_300);
												mem_vec_300 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_301);
												mem_vec_301 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_302);
												mem_vec_302 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_303);
												mem_vec_303 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_304);
												mem_vec_304 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_305);
												mem_vec_305 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_306);
												mem_vec_306 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_307);
												mem_vec_307 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_294);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_295);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_296);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_297);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_298);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_299);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_300);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_301);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_302);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_303);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_304);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_305);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_306);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_307);
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