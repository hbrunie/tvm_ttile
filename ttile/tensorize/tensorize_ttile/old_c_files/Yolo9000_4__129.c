#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (17, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (4, f);
  T (1, c); T (1, x)]
*/
IND_TYPE c, cp_0, c690_p_0, cp_1, c690, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x920_p_0, x921_p_0, xp_1, x920_p_1, xp_2, x920, x921, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y460 = 0;
IND_TYPE x922 = 0;
IND_TYPE h460 = 0;
IND_TYPE w430 = 0;
IND_TYPE c691 = 0;
IND_TYPE f460 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8912 ,mem_vec_8913 ,mem_vec_8914 ,mem_vec_8915 ,mem_vec_8916 ,mem_vec_8917 ,mem_vec_8918 ,mem_vec_8919 ,mem_vec_8920 ,mem_vec_8921 ,mem_vec_8922 ,mem_vec_8923 ,mem_vec_8924 ,mem_vec_8925 ,mem_vec_8926 ,mem_vec_8927 ,mem_vec_8928 ,mem_vec_8929 ,mem_vec_8930 ,mem_vec_8931 ,mem_vec_8932 ,mem_vec_8933 ,mem_vec_8934 ,mem_vec_8935 ,mem_vec_8936 ,mem_vec_8937 ,mem_vec_8938 ,mem_vec_8939 ,mem_vec_8940 ,mem_vec_8941 ,mem_vec_8942 ,mem_vec_8943 ,mem_vec_8944 ,mem_vec_8945 ,mem_vec_8946 ,mem_vec_8947 ,mem_vec_8948 ,mem_vec_8949 ,mem_vec_8950 ,mem_vec_8951 ,mem_vec_8952 ,mem_vec_8953 ,mem_vec_8954 ,mem_vec_8955 ,mem_vec_8956 ,mem_vec_8957 ,mem_vec_8958 ,mem_vec_8959 ,mem_vec_8960 ,mem_vec_8961 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x921 = x922, x921_p_0 = 0;
	x921 < x922 + 136;
	x921 += 136, x921_p_0 += 136){
	// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
	// T (c, 1) (64 / 64)
	for (c690 = c691, c690_p_0 = 0;
		c690 < c691 + 64;
		c690 += 64, c690_p_0 += 64){
		// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
		// T (f, 4) (128 / 32)
		for (f = f460, fp_0 = 0;
			f < f460 + 128;
			f += 32, fp_0 += 32){
				for (y = y460, yp_0 = 0;
					y < y460 + 84;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 32
					// T (x, 17) (136 / 8)
					for (x920 = x921, x920_p_1 = x921_p_0, x920_p_0 = 0;
						x920 < x921 + 136;
						x920 += 8, x920_p_1 += 8, x920_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h460, hp_0 = 0;
							h < h460 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w430, wp_0 = 0;
								w < w430 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 1, w = 1, c = 64, f = 32
								// T (x, 8) (8 / 1)
								for (x = x920, xp_2 = x920_p_1, xp_1 = x920_p_0, xp_0 = 0;
									x < x920 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8912 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8913 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_8926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_8928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_8930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_8932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_8933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_8934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_8935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c690, cp_1 = c690_p_0, cp_0 = 0;
												c < c690 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8912);
												mem_vec_8912 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8913);
												mem_vec_8913 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8914);
												mem_vec_8914 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8915);
												mem_vec_8915 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8916);
												mem_vec_8916 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8917);
												mem_vec_8917 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8918);
												mem_vec_8918 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8919);
												mem_vec_8919 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8920);
												mem_vec_8920 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8921);
												mem_vec_8921 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8922);
												mem_vec_8922 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8923);
												mem_vec_8923 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8924);
												mem_vec_8924 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8925);
												mem_vec_8925 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8926);
												mem_vec_8926 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8927);
												mem_vec_8927 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8928);
												mem_vec_8928 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8929);
												mem_vec_8929 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8930);
												mem_vec_8930 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8931);
												mem_vec_8931 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8932);
												mem_vec_8932 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8933);
												mem_vec_8933 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8934);
												mem_vec_8934 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8935);
												mem_vec_8935 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8912);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8913);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8914);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8915);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8916);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8917);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8918);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8919);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8920);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8921);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8922);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8923);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8924);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8925);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8926);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8927);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8928);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8929);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8930);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8931);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8932);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8933);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8934);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8935);
								}
							}
						}
					}
				}
				for (y = y460 + 84, yp_0 = 0;
					y < y460 + 84 + 52;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 32
					// T (x, 17) (136 / 8)
					for (x920 = x921, x920_p_1 = x921_p_0, x920_p_0 = 0;
						x920 < x921 + 136;
						x920 += 8, x920_p_1 += 8, x920_p_0 += 8){
						// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h460, hp_0 = 0;
							h < h460 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w430, wp_0 = 0;
								w < w430 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 8, h = 1, w = 1, c = 64, f = 32
								// T (x, 8) (8 / 1)
								for (x = x920, xp_2 = x920_p_1, xp_1 = x920_p_0, xp_0 = 0;
									x < x920 + 8;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_8936 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_8937 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_8938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_8939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_8940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_8941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_8942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_8943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_8944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_8945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_8946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_8947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_8948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_8949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_8950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_8951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_8952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_8953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_8954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_8955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_8956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_8957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_8958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_8959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_8960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_8961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c690, cp_1 = c690_p_0, cp_0 = 0;
												c < c690 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8936);
												mem_vec_8936 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8937);
												mem_vec_8937 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8938);
												mem_vec_8938 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8939);
												mem_vec_8939 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8940);
												mem_vec_8940 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8941);
												mem_vec_8941 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8942);
												mem_vec_8942 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8943);
												mem_vec_8943 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8944);
												mem_vec_8944 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8945);
												mem_vec_8945 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8946);
												mem_vec_8946 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8947);
												mem_vec_8947 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8948);
												mem_vec_8948 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8949);
												mem_vec_8949 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8950);
												mem_vec_8950 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8951);
												mem_vec_8951 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8952);
												mem_vec_8952 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8953);
												mem_vec_8953 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8954);
												mem_vec_8954 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8955);
												mem_vec_8955 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8956);
												mem_vec_8956 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8957);
												mem_vec_8957 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8958);
												mem_vec_8958 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8959);
												mem_vec_8959 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8960);
												mem_vec_8960 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8961);
												mem_vec_8961 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8936);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8937);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8938);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8939);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8940);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8941);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8942);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8943);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8944);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8945);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8946);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8947);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8948);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8949);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8950);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8951);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8952);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8953);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8954);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8955);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8956);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8957);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8959);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8961);
								}
							}
						}
					}
				}
		}
	}
}


}