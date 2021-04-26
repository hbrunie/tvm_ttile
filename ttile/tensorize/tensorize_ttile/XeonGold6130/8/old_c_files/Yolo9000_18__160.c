#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (8, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (1, c); T (2, c)]
*/
IND_TYPE c, cp_0, c100_p_0, c101_p_0, c102_p_0, cp_1, c100_p_1, c101_p_1, cp_2, c100_p_2, cp_3, c100, c101, c102, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y40 = 0;
IND_TYPE x40 = 0;
IND_TYPE h34 = 0;
IND_TYPE w34 = 0;
IND_TYPE c103 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_824 ,mem_vec_825 ,mem_vec_826 ,mem_vec_827 ,mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 2) (512 / 256)
for (c102 = c103, c102_p_0 = 0;
	c102 < c103 + 512;
	c102 += 256, c102_p_0 += 256){
	// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
	// T (c, 1) (256 / 256)
	for (c101 = c102, c101_p_1 = c102_p_0, c101_p_0 = 0;
		c101 < c102 + 256;
		c101 += 256, c101_p_1 += 256, c101_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f40, fp_0 = 0;
			f < f40 + 1024;
			f += 32, fp_0 += 32){
				for (y = y40, yp_0 = 0;
					y < y40 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c100 = c101, c100_p_2 = c101_p_1, c100_p_1 = c101_p_0, c100_p_0 = 0;
						c100 < c101 + 256;
						c100 += 32, c100_p_2 += 32, c100_p_1 += 32, c100_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x40, xp_0 = 0;
							x < x40 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h34, hp_0 = 0;
								h < h34 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w34, wp_0 = 0;
									w < w34 + 3;
									w += 1, wp_0 += 1){
											mem_vec_824 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_825 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c100, cp_3 = c100_p_2, cp_2 = c100_p_1, cp_1 = c100_p_0, cp_0 = 0;
												c < c100 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_824);
												mem_vec_824 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_825);
												mem_vec_825 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_826);
												mem_vec_826 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_827);
												mem_vec_827 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_828);
												mem_vec_828 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_829);
												mem_vec_829 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_830);
												mem_vec_830 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_831);
												mem_vec_831 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_832);
												mem_vec_832 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_833);
												mem_vec_833 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_834);
												mem_vec_834 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_835);
												mem_vec_835 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_836);
												mem_vec_836 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_837);
												mem_vec_837 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_838);
												mem_vec_838 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_839);
												mem_vec_839 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_839);
								}
							}
						}
					}
				}
				for (y = y40 + 8, yp_0 = 0;
					y < y40 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 8) (256 / 32)
					for (c100 = c101, c100_p_2 = c101_p_1, c100_p_1 = c101_p_0, c100_p_0 = 0;
						c100 < c101 + 256;
						c100 += 32, c100_p_2 += 32, c100_p_1 += 32, c100_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (x, 17) (17 / 1)
						for (x = x40, xp_0 = 0;
							x < x40 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h34, hp_0 = 0;
								h < h34 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w34, wp_0 = 0;
									w < w34 + 3;
									w += 1, wp_0 += 1){
											mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c100, cp_3 = c100_p_2, cp_2 = c100_p_1, cp_1 = c100_p_0, cp_0 = 0;
												c < c100 + 32;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_840);
												mem_vec_840 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_841);
												mem_vec_841 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_842);
												mem_vec_842 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_843);
												mem_vec_843 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_844);
												mem_vec_844 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_845);
												mem_vec_845 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_846);
												mem_vec_846 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_847);
												mem_vec_847 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_848);
												mem_vec_848 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_849);
												mem_vec_849 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_850);
												mem_vec_850 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_851);
												mem_vec_851 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_852);
												mem_vec_852 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_853);
												mem_vec_853 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_854);
												mem_vec_854 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_855);
												mem_vec_855 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_856);
												mem_vec_856 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_857);
												mem_vec_857 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_842);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_857);
								}
							}
						}
					}
				}
		}
	}
}


}