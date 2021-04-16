#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (4, c); T (1, f);
  Lambda_apply y [((Iter 5), (Arg 6)); ((Iter 2), (Arg 13))]; T (56, x);
  T (4, f); T (2, f)]
*/
IND_TYPE c, cp_0, c456_p_0, cp_1, c456, f, fp_0, f388_p_0, f389_p_0, fp_1, f388_p_1, fp_2, f388, f389, w, wp_0, x, xp_0, x523_p_0, xp_1, x523, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y342 = 0;
IND_TYPE x524 = 0;
IND_TYPE h = 0;
IND_TYPE w219 = 0;
IND_TYPE c457 = 0;
IND_TYPE f390 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_36 ,scal_37 ,scal_38 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2887 ,mem_vec_2888 ,mem_vec_2889 ,mem_vec_2890 ,mem_vec_2891 ,mem_vec_2892 ,mem_vec_2893 ,mem_vec_2894 ,mem_vec_2895 ,mem_vec_2896 ,mem_vec_2897 ,mem_vec_2898 ,mem_vec_2899 ,mem_vec_2900 ,mem_vec_2901 ,mem_vec_2902 ,mem_vec_2903 ,mem_vec_2904 ,mem_vec_2905 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f389 = f390, f389_p_0 = 0;
	f389 < f390 + 128;
	f389 += 64, f389_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 64
	// T (f, 4) (64 / 16)
	for (f388 = f389, f388_p_1 = f389_p_0, f388_p_0 = 0;
		f388 < f389 + 64;
		f388 += 16, f388_p_1 += 16, f388_p_0 += 16){
		// y = 56, x = 56, h = 3, w = 3, c = 128, f = 16
		// T (x, 56) (56 / 1)
		for (x523 = x524, x523_p_0 = 0;
			x523 < x524 + 56;
			x523 += 1, x523_p_0 += 1){
				for (y = y342, yp_0 = 0;
					y < y342 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
					// T (f, 1) (16 / 16)
					for (f = f388, fp_2 = f388_p_1, fp_1 = f388_p_0, fp_0 = 0;
						f < f388 + 16;
						f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
						// T (c, 4) (128 / 32)
						for (c456 = c457, c456_p_0 = 0;
							c456 < c457 + 128;
							c456 += 32, c456_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w219, wp_0 = 0;
								w < w219 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
								// T (x, 1) (1 / 1)
								for (x = x523, xp_1 = x523_p_0, xp_0 = 0;
									x < x523 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2887 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c456, cp_1 = c456_p_0, cp_0 = 0;
												c < c456 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2887);
												mem_vec_2887 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2888);
												mem_vec_2888 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2889);
												mem_vec_2889 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2890);
												mem_vec_2890 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2891);
												mem_vec_2891 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2892);
												mem_vec_2892 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_14 = _mm512_set1_ps(scal_6);
												vec_15 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_13 = _mm512_fmadd_ps(vec_14, vec_15, mem_vec_2887);
												mem_vec_2887 = vec_13;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_17 = _mm512_set1_ps(scal_7);


												vec_16 = _mm512_fmadd_ps(vec_17, vec_15, mem_vec_2888);
												mem_vec_2888 = vec_16;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_19 = _mm512_set1_ps(scal_8);


												vec_18 = _mm512_fmadd_ps(vec_19, vec_15, mem_vec_2889);
												mem_vec_2889 = vec_18;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_21 = _mm512_set1_ps(scal_9);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_15, mem_vec_2890);
												mem_vec_2890 = vec_20;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_23 = _mm512_set1_ps(scal_10);


												vec_22 = _mm512_fmadd_ps(vec_23, vec_15, mem_vec_2891);
												mem_vec_2891 = vec_22;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_25 = _mm512_set1_ps(scal_11);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_15, mem_vec_2892);
												mem_vec_2892 = vec_24;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_27 = _mm512_set1_ps(scal_12);
												vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_2887);
												mem_vec_2887 = vec_26;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_30 = _mm512_set1_ps(scal_13);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_28, mem_vec_2888);
												mem_vec_2888 = vec_29;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_32 = _mm512_set1_ps(scal_14);


												vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_2889);
												mem_vec_2889 = vec_31;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_34 = _mm512_set1_ps(scal_15);


												vec_33 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_2890);
												mem_vec_2890 = vec_33;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_36 = _mm512_set1_ps(scal_16);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_28, mem_vec_2891);
												mem_vec_2891 = vec_35;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_38 = _mm512_set1_ps(scal_17);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_2892);
												mem_vec_2892 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2887);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2888);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2889);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2890);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2891);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2892);
								}
							}
						}
					}
				}
				for (y = y342 + 30, yp_0 = 0;
					y < y342 + 30 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
					// T (f, 1) (16 / 16)
					for (f = f388, fp_2 = f388_p_1, fp_1 = f388_p_0, fp_0 = 0;
						f < f388 + 16;
						f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
						// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
						// T (c, 4) (128 / 32)
						for (c456 = c457, c456_p_0 = 0;
							c456 < c457 + 128;
							c456 += 32, c456_p_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w219, wp_0 = 0;
								w < w219 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
								// T (x, 1) (1 / 1)
								for (x = x523, xp_1 = x523_p_0, xp_0 = 0;
									x < x523 + 1;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_2893 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_2894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_2895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_2896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_2897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_2898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_2899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_2900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_2901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_2902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_2903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_2904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_2905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
											// T (c, 32) (32 / 1)
											for (c = c456, cp_1 = c456_p_0, cp_0 = 0;
												c < c456 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2893);
												mem_vec_2893 = vec_0;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_4 = _mm512_set1_ps(scal_1);


												vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_2894);
												mem_vec_2894 = vec_3;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_6 = _mm512_set1_ps(scal_2);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2895);
												mem_vec_2895 = vec_5;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_8 = _mm512_set1_ps(scal_3);


												vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_2896);
												mem_vec_2896 = vec_7;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_10 = _mm512_set1_ps(scal_4);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2897);
												mem_vec_2897 = vec_9;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_12 = _mm512_set1_ps(scal_5);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2898);
												mem_vec_2898 = vec_11;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_14 = _mm512_set1_ps(scal_6);


												vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_2899);
												mem_vec_2899 = vec_13;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_16 = _mm512_set1_ps(scal_7);


												vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_2900);
												mem_vec_2900 = vec_15;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_18 = _mm512_set1_ps(scal_8);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2901);
												mem_vec_2901 = vec_17;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_20 = _mm512_set1_ps(scal_9);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2902);
												mem_vec_2902 = vec_19;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_22 = _mm512_set1_ps(scal_10);


												vec_21 = _mm512_fmadd_ps(vec_22, vec_2, mem_vec_2903);
												mem_vec_2903 = vec_21;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_24 = _mm512_set1_ps(scal_11);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2904);
												mem_vec_2904 = vec_23;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_26 = _mm512_set1_ps(scal_12);


												vec_25 = _mm512_fmadd_ps(vec_26, vec_2, mem_vec_2905);
												mem_vec_2905 = vec_25;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_28 = _mm512_set1_ps(scal_13);
												vec_29 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_27 = _mm512_fmadd_ps(vec_28, vec_29, mem_vec_2893);
												mem_vec_2893 = vec_27;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_31 = _mm512_set1_ps(scal_14);


												vec_30 = _mm512_fmadd_ps(vec_31, vec_29, mem_vec_2894);
												mem_vec_2894 = vec_30;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_15);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_29, mem_vec_2895);
												mem_vec_2895 = vec_32;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_16);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_29, mem_vec_2896);
												mem_vec_2896 = vec_34;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_37 = _mm512_set1_ps(scal_17);


												vec_36 = _mm512_fmadd_ps(vec_37, vec_29, mem_vec_2897);
												mem_vec_2897 = vec_36;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_18);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_29, mem_vec_2898);
												mem_vec_2898 = vec_38;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_19);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_29, mem_vec_2899);
												mem_vec_2899 = vec_40;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_43 = _mm512_set1_ps(scal_20);


												vec_42 = _mm512_fmadd_ps(vec_43, vec_29, mem_vec_2900);
												mem_vec_2900 = vec_42;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_45 = _mm512_set1_ps(scal_21);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_29, mem_vec_2901);
												mem_vec_2901 = vec_44;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_22);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_29, mem_vec_2902);
												mem_vec_2902 = vec_46;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
												vec_49 = _mm512_set1_ps(scal_23);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_29, mem_vec_2903);
												mem_vec_2903 = vec_48;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
												vec_51 = _mm512_set1_ps(scal_24);


												vec_50 = _mm512_fmadd_ps(vec_51, vec_29, mem_vec_2904);
												mem_vec_2904 = vec_50;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_25);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_29, mem_vec_2905);
												mem_vec_2905 = vec_52;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_55 = _mm512_set1_ps(scal_26);
												vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_54 = _mm512_fmadd_ps(vec_55, vec_56, mem_vec_2893);
												mem_vec_2893 = vec_54;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_58 = _mm512_set1_ps(scal_27);


												vec_57 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_2894);
												mem_vec_2894 = vec_57;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_60 = _mm512_set1_ps(scal_28);


												vec_59 = _mm512_fmadd_ps(vec_60, vec_56, mem_vec_2895);
												mem_vec_2895 = vec_59;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_62 = _mm512_set1_ps(scal_29);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_56, mem_vec_2896);
												mem_vec_2896 = vec_61;
												scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_30);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_2897);
												mem_vec_2897 = vec_63;
												scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_66 = _mm512_set1_ps(scal_31);


												vec_65 = _mm512_fmadd_ps(vec_66, vec_56, mem_vec_2898);
												mem_vec_2898 = vec_65;
												scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_68 = _mm512_set1_ps(scal_32);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_56, mem_vec_2899);
												mem_vec_2899 = vec_67;
												scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_33);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_2900);
												mem_vec_2900 = vec_69;
												scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_72 = _mm512_set1_ps(scal_34);


												vec_71 = _mm512_fmadd_ps(vec_72, vec_56, mem_vec_2901);
												mem_vec_2901 = vec_71;
												scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_74 = _mm512_set1_ps(scal_35);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_56, mem_vec_2902);
												mem_vec_2902 = vec_73;
												scal_36 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_36);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_2903);
												mem_vec_2903 = vec_75;
												scal_37 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
												vec_78 = _mm512_set1_ps(scal_37);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_56, mem_vec_2904);
												mem_vec_2904 = vec_77;
												scal_38 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h + 2) + c];
												vec_80 = _mm512_set1_ps(scal_38);


												vec_79 = _mm512_fmadd_ps(vec_80, vec_56, mem_vec_2905);
												mem_vec_2905 = vec_79;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2893);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2894);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2895);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2896);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2897);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2898);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2899);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2900);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2901);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2902);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2903);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2904);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_2905);
								}
							}
						}
					}
				}
		}
	}
}


}