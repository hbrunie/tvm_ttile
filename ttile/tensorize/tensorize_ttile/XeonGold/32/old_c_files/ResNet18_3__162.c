#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (7, y); T (2, f); T (28, x); T (1, y); T (2, x); T (1, y)]
*/
IND_TYPE c, cp_0, c282_p_0, cp_1, c282, f, fp_0, x, xp_0, x461_p_0, x462_p_0, x463_p_0, xp_1, x461_p_1, x462_p_1, xp_2, x461_p_2, xp_3, x461, x462, x463, y, yp_0, y367_p_0, y368_p_0, yp_1, y367_p_1, yp_2, y367, y368;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y369 = 0;
IND_TYPE x464 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c283 = 0;
IND_TYPE f179 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_2152 ,mem_vec_2153 ,mem_vec_2154 ,mem_vec_2155 ,mem_vec_2156 ,mem_vec_2157 ,mem_vec_2158 ,mem_vec_2159 ,mem_vec_2160 ,mem_vec_2161 ,mem_vec_2162 ,mem_vec_2163 ,mem_vec_2164 ,mem_vec_2165 ,mem_vec_2166 ,mem_vec_2167 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y368 = y369, y368_p_0 = 0;
	y368 < y369 + 56;
	y368 += 56, y368_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 2) (56 / 28)
	for (x463 = x464, x463_p_0 = 0;
		x463 < x464 + 56;
		x463 += 28, x463_p_0 += 28){
		// y = 56, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y367 = y368, y367_p_1 = y368_p_0, y367_p_0 = 0;
			y367 < y368 + 56;
			y367 += 56, y367_p_1 += 56, y367_p_0 += 56){
			// y = 56, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 28) (28 / 1)
			for (x462 = x463, x462_p_1 = x463_p_0, x462_p_0 = 0;
				x462 < x463 + 28;
				x462 += 1, x462_p_1 += 1, x462_p_0 += 1){
				// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f179, fp_0 = 0;
					f < f179 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 7) (56 / 8)
					for (y = y367, yp_2 = y367_p_1, yp_1 = y367_p_0, yp_0 = 0;
						y < y367 + 56;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x461 = x462, x461_p_2 = x462_p_1, x461_p_1 = x462_p_0, x461_p_0 = 0;
							x461 < x462 + 1;
							x461 += 1, x461_p_2 += 1, x461_p_1 += 1, x461_p_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c282 = c283, c282_p_0 = 0;
								c282 < c283 + 64;
								c282 += 32, c282_p_0 += 32){
								// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x461, xp_3 = x461_p_2, xp_2 = x461_p_1, xp_1 = x461_p_0, xp_0 = 0;
									x < x461 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2152 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c282, cp_1 = c282_p_0, cp_0 = 0;
												c < c282 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2152);
												mem_vec_2152 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2153);
												mem_vec_2153 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2154);
												mem_vec_2154 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2155);
												mem_vec_2155 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2156);
												mem_vec_2156 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2157);
												mem_vec_2157 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2158);
												mem_vec_2158 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2159);
												mem_vec_2159 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2160);
												mem_vec_2160 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2161);
												mem_vec_2161 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2162);
												mem_vec_2162 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2163);
												mem_vec_2163 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2164);
												mem_vec_2164 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2165);
												mem_vec_2165 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2166);
												mem_vec_2166 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2167);
												mem_vec_2167 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2152);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2153);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2154);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2155);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2156);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2157);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2158);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2159);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2160);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2161);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2162);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2163);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2164);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2165);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2166);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2167);
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