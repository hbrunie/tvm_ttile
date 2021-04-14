#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 3), (Arg 12))]; T (4, f);
  T (2, c); T (7, x)]
*/
IND_TYPE c, cp_0, c378_p_0, cp_1, c378, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x472_p_0, x473_p_0, xp_1, x472_p_1, xp_2, x472, x473, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y252 = 0;
IND_TYPE x474 = 0;
IND_TYPE h204 = 0;
IND_TYPE w222 = 0;
IND_TYPE c379 = 0;
IND_TYPE f316 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2896 ,mem_vec_2897 ,mem_vec_2898 ,mem_vec_2899 ,mem_vec_2900 ,mem_vec_2901 ,mem_vec_2902 ,mem_vec_2903 ,mem_vec_2904 ,mem_vec_2905 ,mem_vec_2906 ,mem_vec_2907 ,mem_vec_2908 ,mem_vec_2909 ,mem_vec_2910 ,mem_vec_2911 ,mem_vec_2912 ,mem_vec_2913 ,mem_vec_2914 ,mem_vec_2915 ,mem_vec_2916 ,mem_vec_2917 ,mem_vec_2918 ,mem_vec_2919 ,mem_vec_2920 ,mem_vec_2921 ,mem_vec_2922 ,mem_vec_2923 ,mem_vec_2924 ,mem_vec_2925 ,mem_vec_2926 ,mem_vec_2927 ,mem_vec_2928 ,mem_vec_2929 ,mem_vec_2930 ,mem_vec_2931 ,mem_vec_2932 ,mem_vec_2933 ,mem_vec_2934 ,mem_vec_2935 ,mem_vec_2936 ,mem_vec_2937 ,mem_vec_2938 ,mem_vec_2939 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 7) (56 / 8)
for (x473 = x474, x473_p_0 = 0;
	x473 < x474 + 56;
	x473 += 8, x473_p_0 += 8){
	// y = 56, x = 8, h = 3, w = 3, c = 128, f = 128
	// T (c, 2) (128 / 64)
	for (c378 = c379, c378_p_0 = 0;
		c378 < c379 + 128;
		c378 += 64, c378_p_0 += 64){
		// y = 56, x = 8, h = 3, w = 3, c = 64, f = 128
		// T (f, 4) (128 / 32)
		for (f = f316, fp_0 = 0;
			f < f316 + 128;
			f += 32, fp_0 += 32){
				for (y = y252, yp_0 = 0;
					y < y252 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
					// T (x, 4) (8 / 2)
					for (x472 = x473, x472_p_1 = x473_p_0, x472_p_0 = 0;
						x472 < x473 + 8;
						x472 += 2, x472_p_1 += 2, x472_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h204, hp_0 = 0;
							h < h204 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w222, wp_0 = 0;
								w < w222 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
								// T (x, 2) (2 / 1)
								for (x = x472, xp_2 = x472_p_1, xp_1 = x472_p_0, xp_0 = 0;
									x < x472 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2896 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2897 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_2914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c378, cp_1 = c378_p_0, cp_0 = 0;
												c < c378 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2896);
												mem_vec_2896 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2897);
												mem_vec_2897 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2898);
												mem_vec_2898 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2899);
												mem_vec_2899 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2900);
												mem_vec_2900 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2901);
												mem_vec_2901 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2902);
												mem_vec_2902 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2903);
												mem_vec_2903 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2904);
												mem_vec_2904 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2905);
												mem_vec_2905 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2906);
												mem_vec_2906 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2907);
												mem_vec_2907 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2908);
												mem_vec_2908 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2909);
												mem_vec_2909 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2910);
												mem_vec_2910 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2911);
												mem_vec_2911 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2912);
												mem_vec_2912 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2913);
												mem_vec_2913 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2914);
												mem_vec_2914 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2915);
												mem_vec_2915 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2896);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2897);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2898);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2899);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2900);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2901);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2902);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2903);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2904);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2905);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2906);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2907);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2908);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2909);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2910);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2911);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2912);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2913);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2914);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2915);
								}
							}
						}
					}
				}
				for (y = y252 + 20, yp_0 = 0;
					y < y252 + 20 + 36;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 8, h = 3, w = 3, c = 64, f = 32
					// T (x, 4) (8 / 2)
					for (x472 = x473, x472_p_1 = x473_p_0, x472_p_0 = 0;
						x472 < x473 + 8;
						x472 += 2, x472_p_1 += 2, x472_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h204, hp_0 = 0;
							h < h204 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 3, c = 64, f = 32
							// T (w, 3) (3 / 1)
							for (w = w222, wp_0 = 0;
								w < w222 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
								// T (x, 2) (2 / 1)
								for (x = x472, xp_2 = x472_p_1, xp_1 = x472_p_0, xp_0 = 0;
									x < x472 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2916 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2917 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_2918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_2920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_2922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_2924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_2926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_2928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_2930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_2932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_2934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_2936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_2937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_2938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_2939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c378, cp_1 = c378_p_0, cp_0 = 0;
												c < c378 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2916);
												mem_vec_2916 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2917);
												mem_vec_2917 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2918);
												mem_vec_2918 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2919);
												mem_vec_2919 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2920);
												mem_vec_2920 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2921);
												mem_vec_2921 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2922);
												mem_vec_2922 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2923);
												mem_vec_2923 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2924);
												mem_vec_2924 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2925);
												mem_vec_2925 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2926);
												mem_vec_2926 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2927);
												mem_vec_2927 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2928);
												mem_vec_2928 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2929);
												mem_vec_2929 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2930);
												mem_vec_2930 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2931);
												mem_vec_2931 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2932);
												mem_vec_2932 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2933);
												mem_vec_2933 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2934);
												mem_vec_2934 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2935);
												mem_vec_2935 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2936);
												mem_vec_2936 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2937);
												mem_vec_2937 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2938);
												mem_vec_2938 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2939);
												mem_vec_2939 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2916);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2917);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2918);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2919);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2920);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2921);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2922);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2923);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2924);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2925);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2926);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2927);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2928);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2929);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2930);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2931);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2932);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2933);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2934);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2935);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2936);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2937);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2938);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2939);
								}
							}
						}
					}
				}
		}
	}
}


}