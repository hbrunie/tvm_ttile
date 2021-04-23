#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (64, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (1, c); T (2, c)]
*/
IND_TYPE c, cp_0, c115_p_0, c116_p_0, c117_p_0, cp_1, c115_p_1, c116_p_1, cp_2, c115_p_2, cp_3, c115, c116, c117, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y46 = 0;
IND_TYPE x46 = 0;
IND_TYPE h40 = 0;
IND_TYPE w40 = 0;
IND_TYPE c118 = 0;
IND_TYPE f46 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 2) (512 / 256)
for (c117 = c118, c117_p_0 = 0;
	c117 < c118 + 512;
	c117 += 256, c117_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
	// T (c, 1) (256 / 256)
	for (c116 = c117, c116_p_1 = c117_p_0, c116_p_0 = 0;
		c116 < c117 + 256;
		c116 += 256, c116_p_1 += 256, c116_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f46, fp_0 = 0;
			f < f46 + 1024;
			f += 32, fp_0 += 32){
				for (y = y46, yp_0 = 0;
					y < y46 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 64) (256 / 4)
					for (c115 = c116, c115_p_2 = c116_p_1, c115_p_1 = c116_p_0, c115_p_0 = 0;
						c115 < c116 + 256;
						c115 += 4, c115_p_2 += 4, c115_p_1 += 4, c115_p_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x46, xp_0 = 0;
							x < x46 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h40, hp_0 = 0;
								h < h40 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w40, wp_0 = 0;
									w < w40 + 3;
									w += 1, wp_0 += 1){
											mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c115, cp_3 = c115_p_2, cp_2 = c115_p_1, cp_1 = c115_p_0, cp_0 = 0;
												c < c115 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_926);
												mem_vec_926 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_927);
												mem_vec_927 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_928);
												mem_vec_928 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_929);
												mem_vec_929 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_930);
												mem_vec_930 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_931);
												mem_vec_931 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_932);
												mem_vec_932 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_933);
												mem_vec_933 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_934);
												mem_vec_934 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_935);
												mem_vec_935 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_936);
												mem_vec_936 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_937);
												mem_vec_937 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_938);
												mem_vec_938 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_939);
												mem_vec_939 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_940);
												mem_vec_940 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_941);
												mem_vec_941 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_926);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_927);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_928);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_929);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_930);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_931);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_932);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_933);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_934);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_935);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_936);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_937);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_938);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_939);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_940);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_941);
								}
							}
						}
					}
				}
				for (y = y46 + 8, yp_0 = 0;
					y < y46 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 64) (256 / 4)
					for (c115 = c116, c115_p_2 = c116_p_1, c115_p_1 = c116_p_0, c115_p_0 = 0;
						c115 < c116 + 256;
						c115 += 4, c115_p_2 += 4, c115_p_1 += 4, c115_p_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x46, xp_0 = 0;
							x < x46 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h40, hp_0 = 0;
								h < h40 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w40, wp_0 = 0;
									w < w40 + 3;
									w += 1, wp_0 += 1){
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
											mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c115, cp_3 = c115_p_2, cp_2 = c115_p_1, cp_1 = c115_p_0, cp_0 = 0;
												c < c115 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
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
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_958);
												mem_vec_958 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_959);
												mem_vec_959 = vec_28;
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
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_959);
								}
							}
						}
					}
				}
		}
	}
}


}