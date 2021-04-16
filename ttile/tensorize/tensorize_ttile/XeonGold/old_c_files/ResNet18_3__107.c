#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (64, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (1, x); T (2, y); T (2, f); T (1, x); T (2, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c135_p_0, cp_1, c135, f, fp_0, x, xp_0, x225_p_0, x226_p_0, x227_p_0, xp_1, x225_p_1, x226_p_1, xp_2, x225_p_2, xp_3, x225, x226, x227, y, yp_0, y180_p_0, y181_p_0, yp_1, y180_p_1, yp_2, y180, y181;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y182 = 0;
IND_TYPE x228 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c136 = 0;
IND_TYPE f90 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y181 = y182, y181_p_0 = 0;
	y181 < y182 + 56;
	y181 += 56, y181_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x227 = x228, x227_p_0 = 0;
		x227 < x228 + 56;
		x227 += 2, x227_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 2) (56 / 28)
		for (y180 = y181, y180_p_1 = y181_p_0, y180_p_0 = 0;
			y180 < y181 + 56;
			y180 += 28, y180_p_1 += 28, y180_p_0 += 28){
			// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (2 / 2)
			for (x226 = x227, x226_p_1 = x227_p_0, x226_p_0 = 0;
				x226 < x227 + 2;
				x226 += 2, x226_p_1 += 2, x226_p_0 += 2){
				// y = 28, x = 2, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f90, fp_0 = 0;
					f < f90 + 64;
					f += 32, fp_0 += 32){
					// y = 28, x = 2, h = 1, w = 1, c = 64, f = 32
					// T (y, 2) (28 / 14)
					for (y = y180, yp_2 = y180_p_1, yp_1 = y180_p_0, yp_0 = 0;
						y < y180 + 28;
						y += 14, yp_2 += 14, yp_1 += 14, yp_0 += 14){
						// y = 14, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (2 / 2)
						for (x225 = x226, x225_p_2 = x226_p_1, x225_p_1 = x226_p_0, x225_p_0 = 0;
							x225 < x226 + 2;
							x225 += 2, x225_p_2 += 2, x225_p_1 += 2, x225_p_0 += 2){
							// y = 14, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (c, 1) (64 / 64)
							for (c135 = c136, c135_p_0 = 0;
								c135 < c136 + 64;
								c135 += 64, c135_p_0 += 64){
								// y = 14, x = 2, h = 1, w = 1, c = 64, f = 32
								// T (x, 2) (2 / 1)
								for (x = x225, xp_3 = x225_p_2, xp_2 = x225_p_1, xp_1 = x225_p_0, xp_0 = 0;
									x < x225 + 2;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = 14, x = 1, h = 1, w = 1, c = 64, f = 32
											// T (c, 64) (64 / 1)
											for (c = c135, cp_1 = c135_p_0, cp_0 = 0;
												c < c135 + 64;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_864);
												mem_vec_864 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_865);
												mem_vec_865 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_866);
												mem_vec_866 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_867);
												mem_vec_867 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_868);
												mem_vec_868 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_869);
												mem_vec_869 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_870);
												mem_vec_870 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_871);
												mem_vec_871 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_872);
												mem_vec_872 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_873);
												mem_vec_873 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_874);
												mem_vec_874 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_875);
												mem_vec_875 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_876);
												mem_vec_876 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_877);
												mem_vec_877 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_878);
												mem_vec_878 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_879);
												mem_vec_879 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_880);
												mem_vec_880 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_881);
												mem_vec_881 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_882);
												mem_vec_882 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_883);
												mem_vec_883 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_884);
												mem_vec_884 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_885);
												mem_vec_885 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_886);
												mem_vec_886 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_887);
												mem_vec_887 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_888);
												mem_vec_888 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_889);
												mem_vec_889 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_890);
												mem_vec_890 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_891);
												mem_vec_891 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_864);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_865);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_866);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_867);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_868);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_869);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_870);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_871);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_872);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_873);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_874);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_875);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_876);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_877);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_878);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_879);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_880);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_881);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_882);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_883);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_884);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_885);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_886);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_887);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_888);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_889);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_890);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_891);
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