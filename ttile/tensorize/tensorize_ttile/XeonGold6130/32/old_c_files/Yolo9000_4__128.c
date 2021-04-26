#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (2, c); T (4, f); T (4, x);
  Lambda_apply y [((Iter 11), (Arg 11)); ((Iter 1), (Arg 15))]; T (2, x)]
*/
IND_TYPE c, cp_0, c294_p_0, cp_1, c294, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x335_p_0, x336_p_0, xp_1, x335_p_1, xp_2, x335, x336, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y223 = 0;
IND_TYPE x337 = 0;
IND_TYPE h169 = 0;
IND_TYPE w193 = 0;
IND_TYPE c295 = 0;
IND_TYPE f196 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3821 ,mem_vec_3822 ,mem_vec_3823 ,mem_vec_3824 ,mem_vec_3825 ,mem_vec_3826 ,mem_vec_3827 ,mem_vec_3828 ,mem_vec_3829 ,mem_vec_3830 ,mem_vec_3831 ,mem_vec_3832 ,mem_vec_3833 ,mem_vec_3834 ,mem_vec_3835 ,mem_vec_3836 ,mem_vec_3837 ,mem_vec_3838 ,mem_vec_3839 ,mem_vec_3840 ,mem_vec_3841 ,mem_vec_3842 ,mem_vec_3843 ,mem_vec_3844 ,mem_vec_3845 ,mem_vec_3846 ,mem_vec_3847 ,mem_vec_3848 ,mem_vec_3849 ,mem_vec_3850 ,mem_vec_3851 ,mem_vec_3852 ,mem_vec_3853 ,mem_vec_3854 ,mem_vec_3855 ,mem_vec_3856 ,mem_vec_3857 ,mem_vec_3858 ,mem_vec_3859 ,mem_vec_3860 ,mem_vec_3861 ,mem_vec_3862 ,mem_vec_3863 ,mem_vec_3864 ,mem_vec_3865 ,mem_vec_3866 ,mem_vec_3867 ,mem_vec_3868 ,mem_vec_3869 ,mem_vec_3870 ,mem_vec_3871 ,mem_vec_3872 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (136 / 68)
for (x336 = x337, x336_p_0 = 0;
	x336 < x337 + 136;
	x336 += 68, x336_p_0 += 68){
		for (y = y223, yp_0 = 0;
			y < y223 + 121;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (68 / 17)
			for (x335 = x336, x335_p_1 = x336_p_0, x335_p_0 = 0;
				x335 < x336 + 68;
				x335 += 17, x335_p_1 += 17, x335_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f196, fp_0 = 0;
					f < f196 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 2) (64 / 32)
					for (c294 = c295, c294_p_0 = 0;
						c294 < c295 + 64;
						c294 += 32, c294_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w193, wp_0 = 0;
							w < w193 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
							// T (x, 17) (17 / 1)
							for (x = x335, xp_2 = x335_p_1, xp_1 = x335_p_0, xp_0 = 0;
								x < x335 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h169, hp_0 = 0;
									h < h169 + 3;
									h += 1, hp_0 += 1){
											mem_vec_3821 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3822 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_3841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_3842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c294, cp_1 = c294_p_0, cp_0 = 0;
												c < c294 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3821);
												mem_vec_3821 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3822);
												mem_vec_3822 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3823);
												mem_vec_3823 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3824);
												mem_vec_3824 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3825);
												mem_vec_3825 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3826);
												mem_vec_3826 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3827);
												mem_vec_3827 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3828);
												mem_vec_3828 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3829);
												mem_vec_3829 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3830);
												mem_vec_3830 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3831);
												mem_vec_3831 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3832);
												mem_vec_3832 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3833);
												mem_vec_3833 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3834);
												mem_vec_3834 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3835);
												mem_vec_3835 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3836);
												mem_vec_3836 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3837);
												mem_vec_3837 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3838);
												mem_vec_3838 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3839);
												mem_vec_3839 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3840);
												mem_vec_3840 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3841);
												mem_vec_3841 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3842);
												mem_vec_3842 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3839);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3842);
								}
							}
						}
					}
				}
			}
		}
		for (y = y223 + 121, yp_0 = 0;
			y < y223 + 121 + 15;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (68 / 17)
			for (x335 = x336, x335_p_1 = x336_p_0, x335_p_0 = 0;
				x335 < x336 + 68;
				x335 += 17, x335_p_1 += 17, x335_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f196, fp_0 = 0;
					f < f196 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 2) (64 / 32)
					for (c294 = c295, c294_p_0 = 0;
						c294 < c295 + 64;
						c294 += 32, c294_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w193, wp_0 = 0;
							w < w193 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
							// T (x, 17) (17 / 1)
							for (x = x335, xp_2 = x335_p_1, xp_1 = x335_p_0, xp_0 = 0;
								x < x335 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h169, hp_0 = 0;
									h < h169 + 3;
									h += 1, hp_0 += 1){
											mem_vec_3843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_3863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_3864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_3865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_3866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_3867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_3868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_3869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_3870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_3871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_3872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c294, cp_1 = c294_p_0, cp_0 = 0;
												c < c294 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3843);
												mem_vec_3843 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3844);
												mem_vec_3844 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3845);
												mem_vec_3845 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3846);
												mem_vec_3846 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3847);
												mem_vec_3847 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3848);
												mem_vec_3848 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3849);
												mem_vec_3849 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3850);
												mem_vec_3850 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3851);
												mem_vec_3851 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3852);
												mem_vec_3852 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3853);
												mem_vec_3853 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3854);
												mem_vec_3854 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3855);
												mem_vec_3855 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3856);
												mem_vec_3856 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3857);
												mem_vec_3857 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3858);
												mem_vec_3858 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3859);
												mem_vec_3859 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3860);
												mem_vec_3860 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3861);
												mem_vec_3861 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3862);
												mem_vec_3862 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3863);
												mem_vec_3863 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3864);
												mem_vec_3864 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3865);
												mem_vec_3865 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3866);
												mem_vec_3866 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3867);
												mem_vec_3867 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3868);
												mem_vec_3868 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3869);
												mem_vec_3869 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3870);
												mem_vec_3870 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_3871);
												mem_vec_3871 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_3872);
												mem_vec_3872 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3857);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3859);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3860);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3861);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3862);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3863);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3864);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3865);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3866);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3867);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3868);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3869);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3870);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_3871);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_3872);
								}
							}
						}
					}
				}
			}
		}
}


}