#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (32, c); Hoist_vars [c]; T (2, x); T (2, c);
  T (1, x); T (2, y); T (2, f); T (1, x); T (2, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c138_p_0, cp_1, c138, f, fp_0, x, xp_0, x230_p_0, x231_p_0, x232_p_0, xp_1, x230_p_1, x231_p_1, xp_2, x230_p_2, xp_3, x230, x231, x232, y, yp_0, y184_p_0, y185_p_0, yp_1, y184_p_1, yp_2, y184, y185;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y186 = 0;
IND_TYPE x233 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c139 = 0;
IND_TYPE f92 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y185 = y186, y185_p_0 = 0;
	y185 < y186 + 56;
	y185 += 56, y185_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x232 = x233, x232_p_0 = 0;
		x232 < x233 + 56;
		x232 += 2, x232_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (56 / 28)
		for (y184 = y185, y184_p_1 = y185_p_0, y184_p_0 = 0;
			y184 < y185 + 56;
			y184 += 28, y184_p_1 += 28, y184_p_0 += 28){
			// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x231 = x232, x231_p_1 = x232_p_0, x231_p_0 = 0;
				x231 < x232 + 2;
				x231 += 2, x231_p_1 += 2, x231_p_0 += 2){
				// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f92, fp_0 = 0;
					f < f92 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 2) (28 / 14)
					for (y = y184, yp_2 = y184_p_1, yp_1 = y184_p_0, yp_0 = 0;
						y < y184 + 28;
						y += 14, yp_2 += 14, yp_1 += 14, yp_0 += 14){
						// y = 14, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x230 = x231, x230_p_2 = x231_p_1, x230_p_1 = x231_p_0, x230_p_0 = 0;
							x230 < x231 + 2;
							x230 += 2, x230_p_2 += 2, x230_p_1 += 2, x230_p_0 += 2){
							// y = 14, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c138 = c139, c138_p_0 = 0;
								c138 < c139 + 64;
								c138 += 32, c138_p_0 += 32){
								// y = 14, x = 2, h = 1, w = 1, c = 32, f = 32
								// T (x, 2) (2 / 1)
								for (x = x230, xp_3 = x230_p_2, xp_2 = x230_p_1, xp_1 = x230_p_0, xp_0 = 0;
									x < x230 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_892 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_893 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = 14, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
												c < c138 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_892);
												mem_vec_892 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_893);
												mem_vec_893 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_894);
												mem_vec_894 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_895);
												mem_vec_895 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_896);
												mem_vec_896 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_897);
												mem_vec_897 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_898);
												mem_vec_898 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_899);
												mem_vec_899 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_900);
												mem_vec_900 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_901);
												mem_vec_901 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_902);
												mem_vec_902 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_903);
												mem_vec_903 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_904);
												mem_vec_904 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_905);
												mem_vec_905 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_906);
												mem_vec_906 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_907);
												mem_vec_907 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_908);
												mem_vec_908 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_909);
												mem_vec_909 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_910);
												mem_vec_910 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_911);
												mem_vec_911 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_912);
												mem_vec_912 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_913);
												mem_vec_913 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_914);
												mem_vec_914 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_915);
												mem_vec_915 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_916);
												mem_vec_916 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_917);
												mem_vec_917 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_918);
												mem_vec_918 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_919);
												mem_vec_919 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_892);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_893);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_894);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_895);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_896);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_897);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_898);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_899);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_900);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_901);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_902);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_903);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_904);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_905);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_906);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_907);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_908);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_909);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_910);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_911);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_912);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_913);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_914);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_915);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_916);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_917);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_918);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_919);
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