#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (8, c); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (8, f);
  T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c414_p_0, cp_1, c414, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x426_p_0, x427_p_0, xp_1, x426_p_1, xp_2, x426, x427, y, yp_0, y300_p_0, yp_1, y300;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y301 = 0;
IND_TYPE x428 = 0;
IND_TYPE h264 = 0;
IND_TYPE w174 = 0;
IND_TYPE c415 = 0;
IND_TYPE f504 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3820 ,mem_vec_3821 ,mem_vec_3822 ,mem_vec_3823 ,mem_vec_3824 ,mem_vec_3825 ,mem_vec_3826 ,mem_vec_3827 ,mem_vec_3828 ,mem_vec_3829 ,mem_vec_3830 ,mem_vec_3831 ,mem_vec_3832 ,mem_vec_3833 ,mem_vec_3834 ,mem_vec_3835 ,mem_vec_3836 ,mem_vec_3837 ,mem_vec_3838 ,mem_vec_3839 ,mem_vec_3840 ,mem_vec_3841 ,mem_vec_3842 ,mem_vec_3843 ,mem_vec_3844 ,mem_vec_3845 ,mem_vec_3846 ,mem_vec_3847 ,mem_vec_3848 ,mem_vec_3849 ,mem_vec_3850 ,mem_vec_3851 ,mem_vec_3852 ,mem_vec_3853 ,mem_vec_3854 ,mem_vec_3855 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (y, 1) (28 / 28)
for (y300 = y301, y300_p_0 = 0;
	y300 < y301 + 28;
	y300 += 28, y300_p_0 += 28){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 1) (28 / 28)
	for (x427 = x428, x427_p_0 = 0;
		x427 < x428 + 28;
		x427 += 28, x427_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f504, fp_0 = 0;
			f < f504 + 256;
			f += 32, fp_0 += 32){
				for (y = y300, yp_1 = y300_p_0, yp_0 = 0;
					y < y300 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
					// T (x, 2) (28 / 14)
					for (x426 = x427, x426_p_1 = x427_p_0, x426_p_0 = 0;
						x426 < x427 + 28;
						x426 += 14, x426_p_1 += 14, x426_p_0 += 14){
						// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 32
						// T (c, 8) (256 / 32)
						for (c414 = c415, c414_p_0 = 0;
							c414 < c415 + 256;
							c414 += 32, c414_p_0 += 32){
							// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w174, wp_0 = 0;
								w < w174 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x426, xp_2 = x426_p_1, xp_1 = x426_p_0, xp_0 = 0;
									x < x426 + 14;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h264, hp_0 = 0;
										h < h264 + 3;
										h += 1, hp_0 += 1){
												mem_vec_3820 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3821 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c414, cp_1 = c414_p_0, cp_0 = 0;
													c < c414 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3820);
													mem_vec_3820 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3821);
													mem_vec_3821 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3822);
													mem_vec_3822 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3823);
													mem_vec_3823 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3824);
													mem_vec_3824 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3825);
													mem_vec_3825 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3826);
													mem_vec_3826 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3827);
													mem_vec_3827 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3828);
													mem_vec_3828 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3829);
													mem_vec_3829 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3830);
													mem_vec_3830 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3831);
													mem_vec_3831 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3832);
													mem_vec_3832 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3833);
													mem_vec_3833 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3834);
													mem_vec_3834 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3835);
													mem_vec_3835 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3820);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3821);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3822);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3823);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3824);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3825);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3826);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3827);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3828);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3829);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3830);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3831);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3832);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3833);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3834);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3835);
									}
								}
							}
						}
					}
				}
				for (y = y300 + 8, yp_1 = y300_p_0, yp_0 = 0;
					y < y300 + 8 + 20;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 32
					// T (x, 2) (28 / 14)
					for (x426 = x427, x426_p_1 = x427_p_0, x426_p_0 = 0;
						x426 < x427 + 28;
						x426 += 14, x426_p_1 += 14, x426_p_0 += 14){
						// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 32
						// T (c, 8) (256 / 32)
						for (c414 = c415, c414_p_0 = 0;
							c414 < c415 + 256;
							c414 += 32, c414_p_0 += 32){
							// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w174, wp_0 = 0;
								w < w174 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
								// T (x, 14) (14 / 1)
								for (x = x426, xp_2 = x426_p_1, xp_1 = x426_p_0, xp_0 = 0;
									x < x426 + 14;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
									// T (h, 3) (3 / 1)
									for (h = h264, hp_0 = 0;
										h < h264 + 3;
										h += 1, hp_0 += 1){
												mem_vec_3836 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3837 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_3852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_3854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c414, cp_1 = c414_p_0, cp_0 = 0;
													c < c414 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3836);
													mem_vec_3836 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3837);
													mem_vec_3837 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3838);
													mem_vec_3838 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3839);
													mem_vec_3839 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3840);
													mem_vec_3840 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3841);
													mem_vec_3841 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3842);
													mem_vec_3842 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3843);
													mem_vec_3843 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3844);
													mem_vec_3844 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3845);
													mem_vec_3845 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3846);
													mem_vec_3846 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3847);
													mem_vec_3847 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3848);
													mem_vec_3848 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3849);
													mem_vec_3849 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3850);
													mem_vec_3850 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3851);
													mem_vec_3851 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3852);
													mem_vec_3852 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3853);
													mem_vec_3853 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3854);
													mem_vec_3854 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3855);
													mem_vec_3855 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3836);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3837);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3838);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3839);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3840);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3841);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3842);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3843);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3844);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3845);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3846);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3847);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3848);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3849);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3850);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3851);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3852);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3853);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3854);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3855);
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