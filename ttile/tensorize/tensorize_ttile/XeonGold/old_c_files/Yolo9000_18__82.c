#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (16, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (1, c); T (2, c)]
*/
IND_TYPE c, cp_0, c105_p_0, c106_p_0, c107_p_0, cp_1, c105_p_1, c106_p_1, cp_2, c105_p_2, cp_3, c105, c106, c107, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y42 = 0;
IND_TYPE x42 = 0;
IND_TYPE h36 = 0;
IND_TYPE w36 = 0;
IND_TYPE c108 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 2) (512 / 256)
for (c107 = c108, c107_p_0 = 0;
	c107 < c108 + 512;
	c107 += 256, c107_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
	// T (c, 1) (256 / 256)
	for (c106 = c107, c106_p_1 = c107_p_0, c106_p_0 = 0;
		c106 < c107 + 256;
		c106 += 256, c106_p_1 += 256, c106_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f42, fp_0 = 0;
			f < f42 + 1024;
			f += 32, fp_0 += 32){
				for (y = y42, yp_0 = 0;
					y < y42 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 16) (256 / 16)
					for (c105 = c106, c105_p_2 = c106_p_1, c105_p_1 = c106_p_0, c105_p_0 = 0;
						c105 < c106 + 256;
						c105 += 16, c105_p_2 += 16, c105_p_1 += 16, c105_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x42, xp_0 = 0;
							x < x42 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h36, hp_0 = 0;
								h < h36 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w36, wp_0 = 0;
									w < w36 + 3;
									w += 1, wp_0 += 1){
											mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c105, cp_3 = c105_p_2, cp_2 = c105_p_1, cp_1 = c105_p_0, cp_0 = 0;
												c < c105 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_858);
												mem_vec_858 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_859);
												mem_vec_859 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_860);
												mem_vec_860 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_861);
												mem_vec_861 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_862);
												mem_vec_862 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_863);
												mem_vec_863 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_864);
												mem_vec_864 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_865);
												mem_vec_865 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_866);
												mem_vec_866 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_867);
												mem_vec_867 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_868);
												mem_vec_868 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_869);
												mem_vec_869 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_870);
												mem_vec_870 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_871);
												mem_vec_871 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_872);
												mem_vec_872 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_873);
												mem_vec_873 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_859);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_860);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_861);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_862);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_863);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_864);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_865);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_866);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_867);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_868);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_869);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_870);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_871);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_872);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_873);
								}
							}
						}
					}
				}
				for (y = y42 + 8, yp_0 = 0;
					y < y42 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 16) (256 / 16)
					for (c105 = c106, c105_p_2 = c106_p_1, c105_p_1 = c106_p_0, c105_p_0 = 0;
						c105 < c106 + 256;
						c105 += 16, c105_p_2 += 16, c105_p_1 += 16, c105_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x42, xp_0 = 0;
							x < x42 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h36, hp_0 = 0;
								h < h36 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w36, wp_0 = 0;
									w < w36 + 3;
									w += 1, wp_0 += 1){
											mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c105, cp_3 = c105_p_2, cp_2 = c105_p_1, cp_1 = c105_p_0, cp_0 = 0;
												c < c105 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_874);
												mem_vec_874 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_875);
												mem_vec_875 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_876);
												mem_vec_876 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_877);
												mem_vec_877 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_878);
												mem_vec_878 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_879);
												mem_vec_879 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_880);
												mem_vec_880 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_881);
												mem_vec_881 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_882);
												mem_vec_882 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_883);
												mem_vec_883 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_884);
												mem_vec_884 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_885);
												mem_vec_885 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_886);
												mem_vec_886 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_887);
												mem_vec_887 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_888);
												mem_vec_888 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_889);
												mem_vec_889 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_890);
												mem_vec_890 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_891);
												mem_vec_891 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_874);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_875);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_876);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_877);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_878);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_879);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_880);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_881);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_882);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_883);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_884);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_885);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_886);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_887);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_888);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_889);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_890);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_891);
								}
							}
						}
					}
				}
		}
	}
}


}