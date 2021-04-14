#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (7, x);
  Lambda_apply y [((Iter 4), (Arg 11)); ((Iter 1), (Arg 12))]; T (2, f);
  T (8, c); T (8, x)]
*/
IND_TYPE c, cp_0, c626_p_0, cp_1, c626, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x690_p_0, x691_p_0, xp_1, x690_p_1, xp_2, x690, x691, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y376 = 0;
IND_TYPE x692 = 0;
IND_TYPE h340 = 0;
IND_TYPE w352 = 0;
IND_TYPE c627 = 0;
IND_TYPE f314 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5948 ,mem_vec_5949 ,mem_vec_5950 ,mem_vec_5951 ,mem_vec_5952 ,mem_vec_5953 ,mem_vec_5954 ,mem_vec_5955 ,mem_vec_5956 ,mem_vec_5957 ,mem_vec_5958 ,mem_vec_5959 ,mem_vec_5960 ,mem_vec_5961 ,mem_vec_5962 ,mem_vec_5963 ,mem_vec_5964 ,mem_vec_5965 ,mem_vec_5966 ,mem_vec_5967 ,mem_vec_5968 ,mem_vec_5969 ,mem_vec_5970 ,mem_vec_5971 ,mem_vec_5972 ,mem_vec_5973 ,mem_vec_5974 ,mem_vec_5975 ,mem_vec_5976 ,mem_vec_5977 ,mem_vec_5978 ,mem_vec_5979 ,mem_vec_5980 ,mem_vec_5981 ,mem_vec_5982 ,mem_vec_5983 ,mem_vec_5984 ,mem_vec_5985 ,mem_vec_5986 ,mem_vec_5987 ,mem_vec_5988 ,mem_vec_5989 ,mem_vec_5990 ,mem_vec_5991 ,mem_vec_5992 ,mem_vec_5993 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 8) (56 / 7)
for (x691 = x692, x691_p_0 = 0;
	x691 < x692 + 56;
	x691 += 7, x691_p_0 += 7){
	// y = 56, x = 7, h = 3, w = 3, c = 64, f = 64
	// T (c, 8) (64 / 8)
	for (c626 = c627, c626_p_0 = 0;
		c626 < c627 + 64;
		c626 += 8, c626_p_0 += 8){
		// y = 56, x = 7, h = 3, w = 3, c = 8, f = 64
		// T (f, 2) (64 / 32)
		for (f = f314, fp_0 = 0;
			f < f314 + 64;
			f += 32, fp_0 += 32){
				for (y = y376, yp_0 = 0;
					y < y376 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 32
					// T (x, 7) (7 / 1)
					for (x690 = x691, x690_p_1 = x691_p_0, x690_p_0 = 0;
						x690 < x691 + 7;
						x690 += 1, x690_p_1 += 1, x690_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h340, hp_0 = 0;
							h < h340 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w352, wp_0 = 0;
								w < w352 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x690, xp_2 = x690_p_1, xp_1 = x690_p_0, xp_0 = 0;
									x < x690 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5948 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5949 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_5964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_5966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_5968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_5969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c626, cp_1 = c626_p_0, cp_0 = 0;
												c < c626 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5948);
												mem_vec_5948 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5949);
												mem_vec_5949 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5950);
												mem_vec_5950 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5951);
												mem_vec_5951 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5952);
												mem_vec_5952 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5953);
												mem_vec_5953 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5954);
												mem_vec_5954 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5955);
												mem_vec_5955 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5956);
												mem_vec_5956 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5957);
												mem_vec_5957 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5958);
												mem_vec_5958 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5959);
												mem_vec_5959 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5960);
												mem_vec_5960 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5961);
												mem_vec_5961 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5962);
												mem_vec_5962 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5963);
												mem_vec_5963 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5964);
												mem_vec_5964 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5965);
												mem_vec_5965 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5966);
												mem_vec_5966 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5967);
												mem_vec_5967 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5968);
												mem_vec_5968 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5969);
												mem_vec_5969 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5948);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5949);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5950);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5951);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5952);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5953);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5954);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5955);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5956);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5957);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5959);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5961);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5962);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5963);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5964);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5965);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5966);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5967);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5968);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5969);
								}
							}
						}
					}
				}
				for (y = y376 + 44, yp_0 = 0;
					y < y376 + 44 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 32
					// T (x, 7) (7 / 1)
					for (x690 = x691, x690_p_1 = x691_p_0, x690_p_0 = 0;
						x690 < x691 + 7;
						x690 += 1, x690_p_1 += 1, x690_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h340, hp_0 = 0;
							h < h340 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w352, wp_0 = 0;
								w < w352 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
								// T (x, 1) (1 / 1)
								for (x = x690, xp_2 = x690_p_1, xp_1 = x690_p_0, xp_0 = 0;
									x < x690 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_5970 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_5971 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_5972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_5973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_5974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_5975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_5976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_5977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_5978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_5979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_5980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_5981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_5982 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_5983 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_5984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_5985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_5986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_5987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_5988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_5989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_5990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_5991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_5992 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_5993 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c626, cp_1 = c626_p_0, cp_0 = 0;
												c < c626 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5970);
												mem_vec_5970 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5971);
												mem_vec_5971 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5972);
												mem_vec_5972 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5973);
												mem_vec_5973 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5974);
												mem_vec_5974 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5975);
												mem_vec_5975 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5976);
												mem_vec_5976 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5977);
												mem_vec_5977 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5978);
												mem_vec_5978 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5979);
												mem_vec_5979 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5980);
												mem_vec_5980 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5981);
												mem_vec_5981 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5982);
												mem_vec_5982 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5983);
												mem_vec_5983 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5984);
												mem_vec_5984 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5985);
												mem_vec_5985 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5986);
												mem_vec_5986 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5987);
												mem_vec_5987 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5988);
												mem_vec_5988 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5989);
												mem_vec_5989 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5990);
												mem_vec_5990 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5991);
												mem_vec_5991 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5992);
												mem_vec_5992 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5993);
												mem_vec_5993 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5970);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5971);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5972);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5973);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5974);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5975);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5976);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5977);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5978);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5979);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5980);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5981);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5982);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5983);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5984);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5985);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5986);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5987);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5988);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5989);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5990);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5991);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5992);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5993);
								}
							}
						}
					}
				}
		}
	}
}


}