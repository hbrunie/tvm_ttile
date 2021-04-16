#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (64, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (1, x); T (7, y); T (2, f); T (1, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c198_p_0, cp_1, c198, f, fp_0, x, xp_0, x330_p_0, x331_p_0, x332_p_0, xp_1, x330_p_1, x331_p_1, xp_2, x330_p_2, xp_3, x330, x331, x332, y, yp_0, y264_p_0, y265_p_0, yp_1, y264_p_1, yp_2, y264, y265;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y266 = 0;
IND_TYPE x333 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c199 = 0;
IND_TYPE f132 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y265 = y266, y265_p_0 = 0;
	y265 < y266 + 56;
	y265 += 56, y265_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x332 = x333, x332_p_0 = 0;
		x332 < x333 + 56;
		x332 += 2, x332_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y264 = y265, y264_p_1 = y265_p_0, y264_p_0 = 0;
			y264 < y265 + 56;
			y264 += 56, y264_p_1 += 56, y264_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x331 = x332, x331_p_1 = x332_p_0, x331_p_0 = 0;
				x331 < x332 + 2;
				x331 += 2, x331_p_1 += 2, x331_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f132, fp_0 = 0;
					f < f132 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 7) (56 / 8)
					for (y = y264, yp_2 = y264_p_1, yp_1 = y264_p_0, yp_0 = 0;
						y < y264 + 56;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x330 = x331, x330_p_2 = x331_p_1, x330_p_1 = x331_p_0, x330_p_0 = 0;
							x330 < x331 + 2;
							x330 += 2, x330_p_2 += 2, x330_p_1 += 2, x330_p_0 += 2){
							// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c198 = c199, c198_p_0 = 0;
								c198 < c199 + 64;
								c198 += 64, c198_p_0 += 64){
								// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
								// T (x, 2) (2 / 1)
								for (x = x330, xp_3 = x330_p_2, xp_2 = x330_p_1, xp_1 = x330_p_0, xp_0 = 0;
									x < x330 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c198, cp_1 = c198_p_0, cp_0 = 0;
												c < c198 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_942);
												mem_vec_942 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_943);
												mem_vec_943 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_944);
												mem_vec_944 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_945);
												mem_vec_945 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_946);
												mem_vec_946 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_947);
												mem_vec_947 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_948);
												mem_vec_948 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_949);
												mem_vec_949 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_950);
												mem_vec_950 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_951);
												mem_vec_951 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_952);
												mem_vec_952 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_953);
												mem_vec_953 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_954);
												mem_vec_954 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_955);
												mem_vec_955 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_956);
												mem_vec_956 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_957);
												mem_vec_957 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_942);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_943);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_944);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_945);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_946);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_947);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_948);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_949);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_950);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_951);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_952);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_953);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_954);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_955);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_956);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_957);
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