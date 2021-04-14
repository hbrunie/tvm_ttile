#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (4, f); T (16, c); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (1, f)]
*/
IND_TYPE c, cp_0, c774_p_0, cp_1, c774, f, fp_0, f774_p_0, fp_1, f774, h, hp_0, w, wp_0, x, xp_0, x774_p_0, xp_1, x774, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y516 = 0;
IND_TYPE x775 = 0;
IND_TYPE h448 = 0;
IND_TYPE w486 = 0;
IND_TYPE c775 = 0;
IND_TYPE f775 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7884 ,mem_vec_7885 ,mem_vec_7886 ,mem_vec_7887 ,mem_vec_7888 ,mem_vec_7889 ,mem_vec_7890 ,mem_vec_7891 ,mem_vec_7892 ,mem_vec_7893 ,mem_vec_7894 ,mem_vec_7895 ,mem_vec_7896 ,mem_vec_7897 ,mem_vec_7898 ,mem_vec_7899 ,mem_vec_7900 ,mem_vec_7901 ,mem_vec_7902 ,mem_vec_7903 ,mem_vec_7904 ,mem_vec_7905 ,mem_vec_7906 ,mem_vec_7907 ,mem_vec_7908 ,mem_vec_7909 ,mem_vec_7910 ,mem_vec_7911 ,mem_vec_7912 ,mem_vec_7913 ,mem_vec_7914 ,mem_vec_7915 ,mem_vec_7916 ,mem_vec_7917 ,mem_vec_7918 ,mem_vec_7919 ,mem_vec_7920 ,mem_vec_7921 ,mem_vec_7922 ,mem_vec_7923 ,mem_vec_7924 ,mem_vec_7925 ,mem_vec_7926 ,mem_vec_7927 ,mem_vec_7928 ,mem_vec_7929 ,mem_vec_7930 ,mem_vec_7931 ,mem_vec_7932 ,mem_vec_7933 ,mem_vec_7934 ,mem_vec_7935 ,mem_vec_7936 ,mem_vec_7937 ,mem_vec_7938 ,mem_vec_7939 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f774 = f775, f774_p_0 = 0;
	f774 < f775 + 128;
	f774 += 128, f774_p_0 += 128){
		for (y = y516, yp_0 = 0;
			y < y516 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (28 / 14)
			for (x774 = x775, x774_p_0 = 0;
				x774 < x775 + 28;
				x774 += 14, x774_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
				// T (c, 16) (128 / 8)
				for (c774 = c775, c774_p_0 = 0;
					c774 < c775 + 128;
					c774 += 8, c774_p_0 += 8){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 128
					// T (f, 4) (128 / 32)
					for (f = f774, fp_1 = f774_p_0, fp_0 = 0;
						f < f774 + 128;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h448, hp_0 = 0;
							h < h448 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w486, wp_0 = 0;
								w < w486 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 8, f = 32
								// T (x, 14) (14 / 1)
								for (x = x774, xp_1 = x774_p_0, xp_0 = 0;
									x < x774 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7884 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7885 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_7906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_7908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_7909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c774, cp_1 = c774_p_0, cp_0 = 0;
												c < c774 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7884);
												mem_vec_7884 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7885);
												mem_vec_7885 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7886);
												mem_vec_7886 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7887);
												mem_vec_7887 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7888);
												mem_vec_7888 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7889);
												mem_vec_7889 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7890);
												mem_vec_7890 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7891);
												mem_vec_7891 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7892);
												mem_vec_7892 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7893);
												mem_vec_7893 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7894);
												mem_vec_7894 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7895);
												mem_vec_7895 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7896);
												mem_vec_7896 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7897);
												mem_vec_7897 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7898);
												mem_vec_7898 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7899);
												mem_vec_7899 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7900);
												mem_vec_7900 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7901);
												mem_vec_7901 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7902);
												mem_vec_7902 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7903);
												mem_vec_7903 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7904);
												mem_vec_7904 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7905);
												mem_vec_7905 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7906);
												mem_vec_7906 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7907);
												mem_vec_7907 = vec_37;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7908);
												mem_vec_7908 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7909);
												mem_vec_7909 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7884);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7885);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7886);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7887);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7888);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7889);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7890);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7891);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7892);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7893);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7894);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7895);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7896);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7897);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7898);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7899);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7900);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7901);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7902);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7903);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7904);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7905);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7906);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7907);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7908);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7909);
								}
							}
						}
					}
				}
			}
		}
		for (y = y516 + 13, yp_0 = 0;
			y < y516 + 13 + 15;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (28 / 14)
			for (x774 = x775, x774_p_0 = 0;
				x774 < x775 + 28;
				x774 += 14, x774_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
				// T (c, 16) (128 / 8)
				for (c774 = c775, c774_p_0 = 0;
					c774 < c775 + 128;
					c774 += 8, c774_p_0 += 8){
					// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 128
					// T (f, 4) (128 / 32)
					for (f = f774, fp_1 = f774_p_0, fp_0 = 0;
						f < f774 + 128;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
						// T (h, 3) (3 / 1)
						for (h = h448, hp_0 = 0;
							h < h448 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
							// T (w, 3) (3 / 1)
							for (w = w486, wp_0 = 0;
								w < w486 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 1, c = 8, f = 32
								// T (x, 14) (14 / 1)
								for (x = x774, xp_1 = x774_p_0, xp_0 = 0;
									x < x774 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7910 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7911 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_7932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_7934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_7935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_7936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_7937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_7938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_7939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
											// T (c, 8) (8 / 1)
											for (c = c774, cp_1 = c774_p_0, cp_0 = 0;
												c < c774 + 8;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7910);
												mem_vec_7910 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7911);
												mem_vec_7911 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7912);
												mem_vec_7912 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7913);
												mem_vec_7913 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7914);
												mem_vec_7914 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7915);
												mem_vec_7915 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7916);
												mem_vec_7916 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7917);
												mem_vec_7917 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7918);
												mem_vec_7918 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7919);
												mem_vec_7919 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7920);
												mem_vec_7920 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7921);
												mem_vec_7921 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7922);
												mem_vec_7922 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7923);
												mem_vec_7923 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7924);
												mem_vec_7924 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7925);
												mem_vec_7925 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7926);
												mem_vec_7926 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7927);
												mem_vec_7927 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7928);
												mem_vec_7928 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7929);
												mem_vec_7929 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7930);
												mem_vec_7930 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7931);
												mem_vec_7931 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7932);
												mem_vec_7932 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7933);
												mem_vec_7933 = vec_37;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7934);
												mem_vec_7934 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7935);
												mem_vec_7935 = vec_40;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_7936);
												mem_vec_7936 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_7937);
												mem_vec_7937 = vec_43;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 14) + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_7938);
												mem_vec_7938 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_7939);
												mem_vec_7939 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7910);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7911);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7912);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7913);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7914);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7915);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7916);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7917);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7918);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7919);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7920);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7921);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7922);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7923);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7924);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7925);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7926);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7927);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7928);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7929);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7930);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7931);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7932);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7933);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7934);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7935);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_7936);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_7937);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_7938);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_7939);
								}
							}
						}
					}
				}
			}
		}
}


}