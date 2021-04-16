#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (2, x); T (2, c);
  T (1, x); T (7, y); T (2, f); T (1, x); T (1, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c201_p_0, cp_1, c201, f, fp_0, x, xp_0, x335_p_0, x336_p_0, x337_p_0, xp_1, x335_p_1, x336_p_1, xp_2, x335_p_2, xp_3, x335, x336, x337, y, yp_0, y268_p_0, y269_p_0, yp_1, y268_p_1, yp_2, y268, y269;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y270 = 0;
IND_TYPE x338 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c202 = 0;
IND_TYPE f134 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y269 = y270, y269_p_0 = 0;
	y269 < y270 + 56;
	y269 += 56, y269_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x337 = x338, x337_p_0 = 0;
		x337 < x338 + 56;
		x337 += 2, x337_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y268 = y269, y268_p_1 = y269_p_0, y268_p_0 = 0;
			y268 < y269 + 56;
			y268 += 56, y268_p_1 += 56, y268_p_0 += 56){
			// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x336 = x337, x336_p_1 = x337_p_0, x336_p_0 = 0;
				x336 < x337 + 2;
				x336 += 2, x336_p_1 += 2, x336_p_0 += 2){
				// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f134, fp_0 = 0;
					f < f134 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 7) (56 / 8)
					for (y = y268, yp_2 = y268_p_1, yp_1 = y268_p_0, yp_0 = 0;
						y < y268 + 56;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x335 = x336, x335_p_2 = x336_p_1, x335_p_1 = x336_p_0, x335_p_0 = 0;
							x335 < x336 + 2;
							x335 += 2, x335_p_2 += 2, x335_p_1 += 2, x335_p_0 += 2){
							// y = 8, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c201 = c202, c201_p_0 = 0;
								c201 < c202 + 64;
								c201 += 32, c201_p_0 += 32){
								// y = 8, x = 2, h = 1, w = 1, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x335, xp_3 = x335_p_2, xp_2 = x335_p_1, xp_1 = x335_p_0, xp_0 = 0;
									x < x335 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c201, cp_1 = c201_p_0, cp_0 = 0;
												c < c201 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_958);
												mem_vec_958 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_959);
												mem_vec_959 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_960);
												mem_vec_960 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_961);
												mem_vec_961 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_962);
												mem_vec_962 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_963);
												mem_vec_963 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_964);
												mem_vec_964 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_965);
												mem_vec_965 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_966);
												mem_vec_966 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_967);
												mem_vec_967 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_968);
												mem_vec_968 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_969);
												mem_vec_969 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_970);
												mem_vec_970 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_971);
												mem_vec_971 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_972);
												mem_vec_972 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_973);
												mem_vec_973 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_959);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_961);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_962);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_963);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_964);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_965);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_966);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_967);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_968);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_969);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_970);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_971);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_972);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_973);
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