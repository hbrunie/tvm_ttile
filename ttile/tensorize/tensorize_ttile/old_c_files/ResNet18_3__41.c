#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (16, c); Hoist_vars [c]; T (1, x); T (4, c);
  T (1, x); T (1, y); T (2, f); T (2, x); T (7, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, x, xp_0, x130_p_0, x131_p_0, x132_p_0, xp_1, x130_p_1, x131_p_1, xp_2, x130_p_2, xp_3, x130, x131, x132, y, yp_0, y104_p_0, y105_p_0, yp_1, y104_p_1, yp_2, y104, y105;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y106 = 0;
IND_TYPE x133 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c79 = 0;
IND_TYPE f52 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_416 ,mem_vec_417 ,mem_vec_418 ,mem_vec_419 ,mem_vec_420 ,mem_vec_421 ,mem_vec_422 ,mem_vec_423 ,mem_vec_424 ,mem_vec_425 ,mem_vec_426 ,mem_vec_427 ,mem_vec_428 ,mem_vec_429 ,mem_vec_430 ,mem_vec_431 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y105 = y106, y105_p_0 = 0;
	y105 < y106 + 56;
	y105 += 56, y105_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x132 = x133, x132_p_0 = 0;
		x132 < x133 + 56;
		x132 += 2, x132_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 7) (56 / 8)
		for (y104 = y105, y104_p_1 = y105_p_0, y104_p_0 = 0;
			y104 < y105 + 56;
			y104 += 8, y104_p_1 += 8, y104_p_0 += 8){
			// y = 8, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (2 / 1)
			for (x131 = x132, x131_p_1 = x132_p_0, x131_p_0 = 0;
				x131 < x132 + 2;
				x131 += 1, x131_p_1 += 1, x131_p_0 += 1){
				// y = 8, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f52, fp_0 = 0;
					f < f52 + 64;
					f += 32, fp_0 += 32){
					// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 1) (8 / 8)
					for (y = y104, yp_2 = y104_p_1, yp_1 = y104_p_0, yp_0 = 0;
						y < y104 + 8;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x130 = x131, x130_p_2 = x131_p_1, x130_p_1 = x131_p_0, x130_p_0 = 0;
							x130 < x131 + 1;
							x130 += 1, x130_p_2 += 1, x130_p_1 += 1, x130_p_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 4) (64 / 16)
							for (c78 = c79, c78_p_0 = 0;
								c78 < c79 + 64;
								c78 += 16, c78_p_0 += 16){
								// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
								// T (x, 1) (1 / 1)
								for (x = x130, xp_3 = x130_p_2, xp_2 = x130_p_1, xp_1 = x130_p_0, xp_0 = 0;
									x < x130 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_416 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_417 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_418 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_419 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_420 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_421 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_422 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_423 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_424 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_425 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_426 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_427 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_428 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_429 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_430 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_431 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
												c < c78 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_416);
												mem_vec_416 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_417);
												mem_vec_417 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_418);
												mem_vec_418 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_419);
												mem_vec_419 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_420);
												mem_vec_420 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_421);
												mem_vec_421 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_422);
												mem_vec_422 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_423);
												mem_vec_423 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_424);
												mem_vec_424 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_425);
												mem_vec_425 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_426);
												mem_vec_426 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_427);
												mem_vec_427 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_428);
												mem_vec_428 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_429);
												mem_vec_429 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_430);
												mem_vec_430 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_431);
												mem_vec_431 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_416);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_417);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_418);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_419);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_420);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_421);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_422);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_423);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_424);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_425);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_426);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_427);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_428);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_429);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_430);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_431);
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