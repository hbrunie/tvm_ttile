#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (1, x); T (8, y); T (2, f); T (1, x); T (1, y); T (56, x); T (1, y)]
*/
IND_TYPE c, cp_0, c135_p_0, cp_1, c135, f, fp_0, x, xp_0, x225_p_0, x226_p_0, x227_p_0, xp_1, x225_p_1, x226_p_1, xp_2, x225_p_2, xp_3, x225, x226, x227, y, yp_0, y180_p_0, y181_p_0, yp_1, y180_p_1, yp_2, y180, y181;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y182 = 0;
IND_TYPE x228 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c136 = 0;
IND_TYPE f90 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y181 = y182, y181_p_0 = 0;
	y181 < y182 + 56;
	y181 += 56, y181_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 56) (56 / 1)
	for (x227 = x228, x227_p_0 = 0;
		x227 < x228 + 56;
		x227 += 1, x227_p_0 += 1){
		// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y180 = y181, y180_p_1 = y181_p_0, y180_p_0 = 0;
			y180 < y181 + 56;
			y180 += 56, y180_p_1 += 56, y180_p_0 += 56){
			// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (1 / 1)
			for (x226 = x227, x226_p_1 = x227_p_0, x226_p_0 = 0;
				x226 < x227 + 1;
				x226 += 1, x226_p_1 += 1, x226_p_0 += 1){
				// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f90, fp_0 = 0;
					f < f90 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 8) (56 / 7)
					for (y = y180, yp_2 = y180_p_1, yp_1 = y180_p_0, yp_0 = 0;
						y < y180 + 56;
						y += 7, yp_2 += 7, yp_1 += 7, yp_0 += 7){
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x225 = x226, x225_p_2 = x226_p_1, x225_p_1 = x226_p_0, x225_p_0 = 0;
							x225 < x226 + 1;
							x225 += 1, x225_p_2 += 1, x225_p_1 += 1, x225_p_0 += 1){
							// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c135 = c136, c135_p_0 = 0;
								c135 < c136 + 64;
								c135 += 64, c135_p_0 += 64){
								// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
								// T (x, 1) (1 / 1)
								for (x = x225, xp_3 = x225_p_2, xp_2 = x225_p_1, xp_1 = x225_p_0, xp_0 = 0;
									x < x225 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c135, cp_1 = c135_p_0, cp_0 = 0;
												c < c135 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_630);
												mem_vec_630 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_631);
												mem_vec_631 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_632);
												mem_vec_632 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_633);
												mem_vec_633 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_634);
												mem_vec_634 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_635);
												mem_vec_635 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_636);
												mem_vec_636 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_637);
												mem_vec_637 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_638);
												mem_vec_638 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_639);
												mem_vec_639 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_640);
												mem_vec_640 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_641);
												mem_vec_641 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_642);
												mem_vec_642 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_643);
												mem_vec_643 = vec_22;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_630);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_631);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_632);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_633);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_634);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_635);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_636);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_637);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_638);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_639);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_640);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_641);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_642);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_643);
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