#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (16, c); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (32, f);
  T (2, c); T (17, x)]
*/
IND_TYPE c, cp_0, c162_p_0, c163_p_0, cp_1, c162_p_1, cp_2, c162, c163, f, fp_0, w, wp_0, x, xp_0, x162_p_0, x163_p_0, xp_1, x162_p_1, xp_2, x162, x163, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y108 = 0;
IND_TYPE x164 = 0;
IND_TYPE h = 0;
IND_TYPE w106 = 0;
IND_TYPE c164 = 0;
IND_TYPE f216 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1956 ,mem_vec_1957 ,mem_vec_1958 ,mem_vec_1959 ,mem_vec_1960 ,mem_vec_1961 ,mem_vec_1962 ,mem_vec_1963 ,mem_vec_1964 ,mem_vec_1965 ,mem_vec_1966 ,mem_vec_1967 ,mem_vec_1968 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (x, 17) (34 / 2)
for (x163 = x164, x163_p_0 = 0;
	x163 < x164 + 34;
	x163 += 2, x163_p_0 += 2){
	// y = 34, x = 2, h = 3, w = 3, c = 256, f = 512
	// T (c, 2) (256 / 128)
	for (c163 = c164, c163_p_0 = 0;
		c163 < c164 + 256;
		c163 += 128, c163_p_0 += 128){
		// y = 34, x = 2, h = 3, w = 3, c = 128, f = 512
		// T (f, 32) (512 / 16)
		for (f = f216, fp_0 = 0;
			f < f216 + 512;
			f += 16, fp_0 += 16){
				for (y = y108, yp_0 = 0;
					y < y108 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 16
					// T (x, 1) (2 / 2)
					for (x162 = x163, x162_p_1 = x163_p_0, x162_p_0 = 0;
						x162 < x163 + 2;
						x162 += 2, x162_p_1 += 2, x162_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 16
						// T (c, 16) (128 / 8)
						for (c162 = c163, c162_p_1 = c163_p_0, c162_p_0 = 0;
							c162 < c163 + 128;
							c162 += 8, c162_p_1 += 8, c162_p_0 += 8){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 16
							// T (w, 3) (3 / 1)
							for (w = w106, wp_0 = 0;
								w < w106 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 16
								// T (x, 2) (2 / 1)
								for (x = x162, xp_2 = x162_p_1, xp_1 = x162_p_0, xp_0 = 0;
									x < x162 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1956 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c162, cp_2 = c162_p_1, cp_1 = c162_p_0, cp_0 = 0;
												c < c162 + 8;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1956);
												mem_vec_1956 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1957);
												mem_vec_1957 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1958);
												mem_vec_1958 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1959);
												mem_vec_1959 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1960);
												mem_vec_1960 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1961);
												mem_vec_1961 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_14 = _mm512_set1_ps(scal_6);
												vec_15 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_13 = _mm512_fmadd_ps(vec_14, vec_15, mem_vec_1956);
												mem_vec_1956 = vec_13;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_17 = _mm512_set1_ps(scal_7);


												vec_16 = _mm512_fmadd_ps(vec_17, vec_15, mem_vec_1957);
												mem_vec_1957 = vec_16;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_19 = _mm512_set1_ps(scal_8);


												vec_18 = _mm512_fmadd_ps(vec_19, vec_15, mem_vec_1958);
												mem_vec_1958 = vec_18;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_21 = _mm512_set1_ps(scal_9);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_15, mem_vec_1959);
												mem_vec_1959 = vec_20;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_23 = _mm512_set1_ps(scal_10);


												vec_22 = _mm512_fmadd_ps(vec_23, vec_15, mem_vec_1960);
												mem_vec_1960 = vec_22;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_25 = _mm512_set1_ps(scal_11);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_15, mem_vec_1961);
												mem_vec_1961 = vec_24;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_27 = _mm512_set1_ps(scal_12);
												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_1956);
												mem_vec_1956 = vec_26;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_30 = _mm512_set1_ps(scal_13);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_28, mem_vec_1957);
												mem_vec_1957 = vec_29;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_32 = _mm512_set1_ps(scal_14);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_1958);
												mem_vec_1958 = vec_31;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_34 = _mm512_set1_ps(scal_15);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_1959);
												mem_vec_1959 = vec_33;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_36 = _mm512_set1_ps(scal_16);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_28, mem_vec_1960);
												mem_vec_1960 = vec_35;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_38 = _mm512_set1_ps(scal_17);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_1961);
												mem_vec_1961 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1956);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1957);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1959);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1961);
								}
							}
						}
					}
				}
				for (y = y108 + 6, yp_0 = 0;
					y < y108 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 16
					// T (x, 1) (2 / 2)
					for (x162 = x163, x162_p_1 = x163_p_0, x162_p_0 = 0;
						x162 < x163 + 2;
						x162 += 2, x162_p_1 += 2, x162_p_0 += 2){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 16
						// T (c, 16) (128 / 8)
						for (c162 = c163, c162_p_1 = c163_p_0, c162_p_0 = 0;
							c162 < c163 + 128;
							c162 += 8, c162_p_1 += 8, c162_p_0 += 8){
							// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 16
							// T (w, 3) (3 / 1)
							for (w = w106, wp_0 = 0;
								w < w106 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 8, f = 16
								// T (x, 2) (2 / 1)
								for (x = x162, xp_2 = x162_p_1, xp_1 = x162_p_0, xp_0 = 0;
									x < x162 + 2;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1962 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 16
											// T (c, 8) (8 / 1)
											for (c = c162, cp_2 = c162_p_1, cp_1 = c162_p_0, cp_0 = 0;
												c < c162 + 8;
												c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1962);
												mem_vec_1962 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_1963);
												mem_vec_1963 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1964);
												mem_vec_1964 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_1965);
												mem_vec_1965 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1966);
												mem_vec_1966 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1967);
												mem_vec_1967 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_14 = _mm512_set1_ps(scal_6);


												vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_1968);
												mem_vec_1968 = vec_13;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_16 = _mm512_set1_ps(scal_7);
												vec_17 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_15 = _mm512_fmadd_ps(vec_16, vec_17, mem_vec_1962);
												mem_vec_1962 = vec_15;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_19 = _mm512_set1_ps(scal_8);


												vec_18 = _mm512_fmadd_ps(vec_19, vec_17, mem_vec_1963);
												mem_vec_1963 = vec_18;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_21 = _mm512_set1_ps(scal_9);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_17, mem_vec_1964);
												mem_vec_1964 = vec_20;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_23 = _mm512_set1_ps(scal_10);


												vec_22 = _mm512_fmadd_ps(vec_23, vec_17, mem_vec_1965);
												mem_vec_1965 = vec_22;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_25 = _mm512_set1_ps(scal_11);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_17, mem_vec_1966);
												mem_vec_1966 = vec_24;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_27 = _mm512_set1_ps(scal_12);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_17, mem_vec_1967);
												mem_vec_1967 = vec_26;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_29 = _mm512_set1_ps(scal_13);


												vec_28 = _mm512_fmadd_ps(vec_29, vec_17, mem_vec_1968);
												mem_vec_1968 = vec_28;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_31 = _mm512_set1_ps(scal_14);
												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_30 = _mm512_fmadd_ps(vec_31, vec_32, mem_vec_1962);
												mem_vec_1962 = vec_30;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_34 = _mm512_set1_ps(scal_15);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_1963);
												mem_vec_1963 = vec_33;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_36 = _mm512_set1_ps(scal_16);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_32, mem_vec_1964);
												mem_vec_1964 = vec_35;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_38 = _mm512_set1_ps(scal_17);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_1965);
												mem_vec_1965 = vec_37;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_40 = _mm512_set1_ps(scal_18);


												vec_39 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_1966);
												mem_vec_1966 = vec_39;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_42 = _mm512_set1_ps(scal_19);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_32, mem_vec_1967);
												mem_vec_1967 = vec_41;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_44 = _mm512_set1_ps(scal_20);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_32, mem_vec_1968);
												mem_vec_1968 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1962);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1963);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1964);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1965);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1966);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1967);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1968);
								}
							}
						}
					}
				}
		}
	}
}


}