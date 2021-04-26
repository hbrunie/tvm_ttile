#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (2, f); T (2, c);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (272, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c75_p_0, cp_1, c75, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x84_p_0, xp_1, x84, y, yp_0, y84_p_0, yp_1, y84;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y85 = 0;
IND_TYPE x85 = 0;
IND_TYPE h41 = 0;
IND_TYPE w50 = 0;
IND_TYPE c76 = 0;
IND_TYPE f50 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 2) (272 / 136)
for (y84 = y85, y84_p_0 = 0;
	y84 < y85 + 272;
	y84 += 136, y84_p_0 += 136){
	// y = 136, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x84 = x85, x84_p_0 = 0;
		x84 < x85 + 272;
		x84 += 1, x84_p_0 += 1){
			for (y = y84, yp_1 = y84_p_0, yp_0 = 0;
				y < y84 + 84;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c75 = c76, c75_p_0 = 0;
					c75 < c76 + 32;
					c75 += 16, c75_p_0 += 16){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (f, 2) (64 / 32)
					for (f = f50, fp_0 = 0;
						f < f50 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
							x < x84 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h41, hp_0 = 0;
								h < h41 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w50, wp_0 = 0;
									w < w50 + 3;
									w += 1, wp_0 += 1){
											mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c75, cp_1 = c75_p_0, cp_0 = 0;
												c < c75 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_899);
												mem_vec_899 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_900);
												mem_vec_900 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_901);
												mem_vec_901 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_902);
												mem_vec_902 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_903);
												mem_vec_903 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_904);
												mem_vec_904 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_905);
												mem_vec_905 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_906);
												mem_vec_906 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_907);
												mem_vec_907 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_908);
												mem_vec_908 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_909);
												mem_vec_909 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_910);
												mem_vec_910 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_911);
												mem_vec_911 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_912);
												mem_vec_912 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_913);
												mem_vec_913 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_914);
												mem_vec_914 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_915);
												mem_vec_915 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_916);
												mem_vec_916 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_917);
												mem_vec_917 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_918);
												mem_vec_918 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_919);
												mem_vec_919 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_920);
												mem_vec_920 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_921);
												mem_vec_921 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_922);
												mem_vec_922 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_899);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_900);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_901);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_902);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_903);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_904);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_905);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_906);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_907);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_908);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_909);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_910);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_911);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_912);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_913);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_914);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_915);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_916);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_917);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_918);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_919);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_920);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_921);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_922);
								}
							}
						}
					}
				}
			}
			for (y = y84 + 84, yp_1 = y84_p_0, yp_0 = 0;
				y < y84 + 84 + 52;
				y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c75 = c76, c75_p_0 = 0;
					c75 < c76 + 32;
					c75 += 16, c75_p_0 += 16){
					// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
					// T (f, 2) (64 / 32)
					for (f = f50, fp_0 = 0;
						f < f50 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x84, xp_1 = x84_p_0, xp_0 = 0;
							x < x84 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h41, hp_0 = 0;
								h < h41 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w50, wp_0 = 0;
									w < w50 + 3;
									w += 1, wp_0 += 1){
											mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c75, cp_1 = c75_p_0, cp_0 = 0;
												c < c75 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_923);
												mem_vec_923 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_924);
												mem_vec_924 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_925);
												mem_vec_925 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_926);
												mem_vec_926 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_927);
												mem_vec_927 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_928);
												mem_vec_928 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_929);
												mem_vec_929 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_930);
												mem_vec_930 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_931);
												mem_vec_931 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_932);
												mem_vec_932 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_933);
												mem_vec_933 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_934);
												mem_vec_934 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_935);
												mem_vec_935 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_936);
												mem_vec_936 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_937);
												mem_vec_937 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_938);
												mem_vec_938 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_939);
												mem_vec_939 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_940);
												mem_vec_940 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_941);
												mem_vec_941 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_942);
												mem_vec_942 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_943);
												mem_vec_943 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_944);
												mem_vec_944 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_945);
												mem_vec_945 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_946);
												mem_vec_946 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_947);
												mem_vec_947 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_948);
												mem_vec_948 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_923);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_924);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_925);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_926);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_927);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_928);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_929);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_930);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_931);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_932);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_933);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_934);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_935);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_936);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_937);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_938);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_939);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_940);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_941);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_942);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_943);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_944);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_945);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_946);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_947);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_948);
								}
							}
						}
					}
				}
			}
	}
}


}