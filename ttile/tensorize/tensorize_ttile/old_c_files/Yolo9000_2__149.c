#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (1, c); Hoist_vars [c]; T (68, x); T (3, w);
  T (3, h); T (1, x); T (34, y); T (2, f); T (32, c); T (2, x); T (2, x)]
*/
IND_TYPE c, cp_0, c174_p_0, cp_1, c174, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x290_p_0, x291_p_0, x292_p_0, xp_1, x290_p_1, x291_p_1, xp_2, x290_p_2, xp_3, x290, x291, x292, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y116 = 0;
IND_TYPE x293 = 0;
IND_TYPE h116 = 0;
IND_TYPE w116 = 0;
IND_TYPE c175 = 0;
IND_TYPE f116 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x292 = x293, x292_p_0 = 0;
	x292 < x293 + 272;
	x292 += 136, x292_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (x, 2) (136 / 68)
	for (x291 = x292, x291_p_1 = x292_p_0, x291_p_0 = 0;
		x291 < x292 + 136;
		x291 += 68, x291_p_1 += 68, x291_p_0 += 68){
		// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
		// T (c, 32) (32 / 1)
		for (c174 = c175, c174_p_0 = 0;
			c174 < c175 + 32;
			c174 += 1, c174_p_0 += 1){
			// y = 272, x = 68, h = 3, w = 3, c = 1, f = 64
			// T (f, 2) (64 / 32)
			for (f = f116, fp_0 = 0;
				f < f116 + 64;
				f += 32, fp_0 += 32){
				// y = 272, x = 68, h = 3, w = 3, c = 1, f = 32
				// T (y, 34) (272 / 8)
				for (y = y116, yp_0 = 0;
					y < y116 + 272;
					y += 8, yp_0 += 8){
					// y = 8, x = 68, h = 3, w = 3, c = 1, f = 32
					// T (x, 1) (68 / 68)
					for (x290 = x291, x290_p_2 = x291_p_1, x290_p_1 = x291_p_0, x290_p_0 = 0;
						x290 < x291 + 68;
						x290 += 68, x290_p_2 += 68, x290_p_1 += 68, x290_p_0 += 68){
						// y = 8, x = 68, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h116, hp_0 = 0;
							h < h116 + 3;
							h += 1, hp_0 += 1){
							// y = 8, x = 68, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w116, wp_0 = 0;
								w < w116 + 3;
								w += 1, wp_0 += 1){
								// y = 8, x = 68, h = 1, w = 1, c = 1, f = 32
								// T (x, 68) (68 / 1)
								for (x = x290, xp_3 = x290_p_2, xp_2 = x290_p_1, xp_1 = x290_p_0, xp_0 = 0;
									x < x290 + 68;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c174, cp_1 = c174_p_0, cp_0 = 0;
												c < c174 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_928);
												mem_vec_928 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_929);
												mem_vec_929 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_930);
												mem_vec_930 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_931);
												mem_vec_931 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_932);
												mem_vec_932 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_933);
												mem_vec_933 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_934);
												mem_vec_934 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_935);
												mem_vec_935 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_936);
												mem_vec_936 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_937);
												mem_vec_937 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_938);
												mem_vec_938 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_939);
												mem_vec_939 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_940);
												mem_vec_940 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_941);
												mem_vec_941 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_942);
												mem_vec_942 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_943);
												mem_vec_943 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_928);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_929);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_930);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_931);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_932);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_933);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_934);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_935);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_936);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_937);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_938);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_939);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_940);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_941);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_942);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_943);
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