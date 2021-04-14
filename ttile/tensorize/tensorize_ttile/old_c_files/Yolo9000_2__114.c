#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (4, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (17, x); T (34, y); T (2, f); T (8, c); T (2, x); T (2, x)]
*/
IND_TYPE c, cp_0, c180_p_0, cp_1, c180, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x300_p_0, x301_p_0, x302_p_0, xp_1, x300_p_1, x301_p_1, xp_2, x300_p_2, xp_3, x300, x301, x302, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y120 = 0;
IND_TYPE x303 = 0;
IND_TYPE h120 = 0;
IND_TYPE w120 = 0;
IND_TYPE c181 = 0;
IND_TYPE f120 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_960 ,mem_vec_961 ,mem_vec_962 ,mem_vec_963 ,mem_vec_964 ,mem_vec_965 ,mem_vec_966 ,mem_vec_967 ,mem_vec_968 ,mem_vec_969 ,mem_vec_970 ,mem_vec_971 ,mem_vec_972 ,mem_vec_973 ,mem_vec_974 ,mem_vec_975 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x302 = x303, x302_p_0 = 0;
	x302 < x303 + 272;
	x302 += 136, x302_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (136 / 68)
	for (x301 = x302, x301_p_1 = x302_p_0, x301_p_0 = 0;
		x301 < x302 + 136;
		x301 += 68, x301_p_1 += 68, x301_p_0 += 68){
		// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
		// T (c, 8) (32 / 4)
		for (c180 = c181, c180_p_0 = 0;
			c180 < c181 + 32;
			c180 += 4, c180_p_0 += 4){
			// y = 272, x = 68, h = 3, w = 3, c = 4, f = 64
			// T (f, 2) (64 / 32)
			for (f = f120, fp_0 = 0;
				f < f120 + 64;
				f += 32, fp_0 += 32){
				// y = 272, x = 68, h = 3, w = 3, c = 4, f = 32
				// T (y, 34) (272 / 8)
				for (y = y120, yp_0 = 0;
					y < y120 + 272;
					y += 8, yp_0 += 8){
					// y = 8, x = 68, h = 3, w = 3, c = 4, f = 32
					// T (x, 17) (68 / 4)
					for (x300 = x301, x300_p_2 = x301_p_1, x300_p_1 = x301_p_0, x300_p_0 = 0;
						x300 < x301 + 68;
						x300 += 4, x300_p_2 += 4, x300_p_1 += 4, x300_p_0 += 4){
						// y = 8, x = 4, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h120, hp_0 = 0;
							h < h120 + 3;
							h += 1, hp_0 += 1){
							// y = 8, x = 4, h = 1, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w120, wp_0 = 0;
								w < w120 + 3;
								w += 1, wp_0 += 1){
								// y = 8, x = 4, h = 1, w = 1, c = 4, f = 32
								// T (x, 4) (4 / 1)
								for (x = x300, xp_3 = x300_p_2, xp_2 = x300_p_1, xp_1 = x300_p_0, xp_0 = 0;
									x < x300 + 4;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c180, cp_1 = c180_p_0, cp_0 = 0;
												c < c180 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_960);
												mem_vec_960 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_961);
												mem_vec_961 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_962);
												mem_vec_962 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_963);
												mem_vec_963 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_964);
												mem_vec_964 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_965);
												mem_vec_965 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_966);
												mem_vec_966 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_967);
												mem_vec_967 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_968);
												mem_vec_968 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_969);
												mem_vec_969 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_970);
												mem_vec_970 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_971);
												mem_vec_971 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_972);
												mem_vec_972 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_973);
												mem_vec_973 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_974);
												mem_vec_974 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_975);
												mem_vec_975 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_961);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_962);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_963);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_964);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_965);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_966);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_967);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_968);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_969);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_970);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_971);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_972);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_973);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_974);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_975);
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