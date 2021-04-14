#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 1), (Arg 14))]; T (8, f);
  T (4, c); T (1, f)]
*/
IND_TYPE c, cp_0, c276_p_0, cp_1, c276, f, fp_0, f368_p_0, f369_p_0, fp_1, f368_p_1, fp_2, f368, f369, h, hp_0, w, wp_0, x, xp_0, x276_p_0, xp_1, x276, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y184 = 0;
IND_TYPE x277 = 0;
IND_TYPE h184 = 0;
IND_TYPE w184 = 0;
IND_TYPE c277 = 0;
IND_TYPE f370 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3776 ,mem_vec_3777 ,mem_vec_3778 ,mem_vec_3779 ,mem_vec_3780 ,mem_vec_3781 ,mem_vec_3782 ,mem_vec_3783 ,mem_vec_3784 ,mem_vec_3785 ,mem_vec_3786 ,mem_vec_3787 ,mem_vec_3788 ,mem_vec_3789 ,mem_vec_3790 ,mem_vec_3791 ,mem_vec_3792 ,mem_vec_3793 ,mem_vec_3794 ,mem_vec_3795 ,mem_vec_3796 ,mem_vec_3797 ,mem_vec_3798 ,mem_vec_3799 ,mem_vec_3800 ,mem_vec_3801 ,mem_vec_3802 ,mem_vec_3803 ,mem_vec_3804 ,mem_vec_3805 ,mem_vec_3806 ,mem_vec_3807 ,mem_vec_3808 ,mem_vec_3809 ,mem_vec_3810 ,mem_vec_3811 ,mem_vec_3812 ,mem_vec_3813 ,mem_vec_3814 ,mem_vec_3815 ,mem_vec_3816 ,mem_vec_3817 ,mem_vec_3818 ,mem_vec_3819 ,mem_vec_3820 ,mem_vec_3821 ,mem_vec_3822 ,mem_vec_3823 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f369 = f370, f369_p_0 = 0;
	f369 < f370 + 512;
	f369 += 512, f369_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 4) (256 / 64)
	for (c276 = c277, c276_p_0 = 0;
		c276 < c277 + 256;
		c276 += 64, c276_p_0 += 64){
		// y = 34, x = 34, h = 3, w = 3, c = 64, f = 512
		// T (f, 8) (512 / 64)
		for (f368 = f369, f368_p_1 = f369_p_0, f368_p_0 = 0;
			f368 < f369 + 512;
			f368 += 64, f368_p_1 += 64, f368_p_0 += 64){
				for (y = y184, yp_0 = 0;
					y < y184 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
					// T (x, 1) (34 / 34)
					for (x276 = x277, x276_p_0 = 0;
						x276 < x277 + 34;
						x276 += 34, x276_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
						// T (f, 2) (64 / 32)
						for (f = f368, fp_2 = f368_p_1, fp_1 = f368_p_0, fp_0 = 0;
							f < f368 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h184, hp_0 = 0;
								h < h184 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w184, wp_0 = 0;
									w < w184 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 64, f = 32
									// T (x, 34) (34 / 1)
									for (x = x276, xp_1 = x276_p_0, xp_0 = 0;
										x < x276 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3776 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3777 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_3792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_3794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c276, cp_1 = c276_p_0, cp_0 = 0;
													c < c276 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3776);
													mem_vec_3776 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3777);
													mem_vec_3777 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3778);
													mem_vec_3778 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3779);
													mem_vec_3779 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3780);
													mem_vec_3780 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3781);
													mem_vec_3781 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3782);
													mem_vec_3782 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3783);
													mem_vec_3783 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3784);
													mem_vec_3784 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3785);
													mem_vec_3785 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3786);
													mem_vec_3786 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3787);
													mem_vec_3787 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3788);
													mem_vec_3788 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3789);
													mem_vec_3789 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3790);
													mem_vec_3790 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3791);
													mem_vec_3791 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3792);
													mem_vec_3792 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3793);
													mem_vec_3793 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3794);
													mem_vec_3794 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3795);
													mem_vec_3795 = vec_31;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3776);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3777);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3778);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3779);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3780);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3781);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3782);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3783);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3784);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3785);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3786);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3787);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3788);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3789);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3790);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3791);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3792);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3793);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3794);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3795);
									}
								}
							}
						}
					}
				}
				for (y = y184 + 20, yp_0 = 0;
					y < y184 + 20 + 14;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
					// T (x, 1) (34 / 34)
					for (x276 = x277, x276_p_0 = 0;
						x276 < x277 + 34;
						x276 += 34, x276_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 64
						// T (f, 2) (64 / 32)
						for (f = f368, fp_2 = f368_p_1, fp_1 = f368_p_0, fp_0 = 0;
							f < f368 + 64;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h184, hp_0 = 0;
								h < h184 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w184, wp_0 = 0;
									w < w184 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 64, f = 32
									// T (x, 34) (34 / 1)
									for (x = x276, xp_1 = x276_p_0, xp_0 = 0;
										x < x276 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3796 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3797 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_3808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_3810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_3812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_3814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_3816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_3817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_3818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_3819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_3820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_3821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_3822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_3823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c276, cp_1 = c276_p_0, cp_0 = 0;
													c < c276 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3796);
													mem_vec_3796 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3797);
													mem_vec_3797 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3798);
													mem_vec_3798 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3799);
													mem_vec_3799 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3800);
													mem_vec_3800 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3801);
													mem_vec_3801 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3802);
													mem_vec_3802 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3803);
													mem_vec_3803 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3804);
													mem_vec_3804 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3805);
													mem_vec_3805 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3806);
													mem_vec_3806 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3807);
													mem_vec_3807 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3808);
													mem_vec_3808 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3809);
													mem_vec_3809 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3810);
													mem_vec_3810 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3811);
													mem_vec_3811 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3812);
													mem_vec_3812 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3813);
													mem_vec_3813 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3814);
													mem_vec_3814 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3815);
													mem_vec_3815 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3816);
													mem_vec_3816 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3817);
													mem_vec_3817 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3818);
													mem_vec_3818 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3819);
													mem_vec_3819 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3820);
													mem_vec_3820 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3821);
													mem_vec_3821 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3822);
													mem_vec_3822 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3823);
													mem_vec_3823 = vec_43;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3796);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3797);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3798);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3799);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3800);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3801);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3802);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3803);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3804);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3805);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3806);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3807);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3808);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3809);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3810);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3811);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3812);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3813);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3814);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3815);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3816);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3817);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3818);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3819);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3820);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3821);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3822);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3823);
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