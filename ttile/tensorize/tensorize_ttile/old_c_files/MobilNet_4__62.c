#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, f); T (128, c); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 10))]; T (4, f)]
*/
IND_TYPE c, cp_0, c474_p_0, cp_1, c474, f, fp_0, f474_p_0, fp_1, f474, h, hp_0, w, wp_0, x, xp_0, x474_p_0, xp_1, x474, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y316 = 0;
IND_TYPE x475 = 0;
IND_TYPE h248 = 0;
IND_TYPE w286 = 0;
IND_TYPE c475 = 0;
IND_TYPE f475 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3800 ,mem_vec_3801 ,mem_vec_3802 ,mem_vec_3803 ,mem_vec_3804 ,mem_vec_3805 ,mem_vec_3806 ,mem_vec_3807 ,mem_vec_3808 ,mem_vec_3809 ,mem_vec_3810 ,mem_vec_3811 ,mem_vec_3812 ,mem_vec_3813 ,mem_vec_3814 ,mem_vec_3815 ,mem_vec_3816 ,mem_vec_3817 ,mem_vec_3818 ,mem_vec_3819 ,mem_vec_3820 ,mem_vec_3821 ,mem_vec_3822 ,mem_vec_3823 ,mem_vec_3824 ,mem_vec_3825 ,mem_vec_3826 ,mem_vec_3827 ,mem_vec_3828 ,mem_vec_3829 ,mem_vec_3830 ,mem_vec_3831 ,mem_vec_3832 ,mem_vec_3833 ,mem_vec_3834 ,mem_vec_3835 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
for (f474 = f475, f474_p_0 = 0;
	f474 < f475 + 128;
	f474 += 32, f474_p_0 += 32){
		for (y = y316, yp_0 = 0;
			y < y316 + 8;
			y += 8, yp_0 += 8){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 4) (28 / 7)
			for (x474 = x475, x474_p_0 = 0;
				x474 < x475 + 28;
				x474 += 7, x474_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 32
				// T (c, 128) (128 / 1)
				for (c474 = c475, c474_p_0 = 0;
					c474 < c475 + 128;
					c474 += 1, c474_p_0 += 1){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 32
					// T (f, 1) (32 / 32)
					for (f = f474, fp_1 = f474_p_0, fp_0 = 0;
						f < f474 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h248, hp_0 = 0;
							h < h248 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w286, wp_0 = 0;
								w < w286 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 1, f = 32
								// T (x, 7) (7 / 1)
								for (x = x474, xp_1 = x474_p_0, xp_0 = 0;
									x < x474 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3800 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3801 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c474, cp_1 = c474_p_0, cp_0 = 0;
												c < c474 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3800);
												mem_vec_3800 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3801);
												mem_vec_3801 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3802);
												mem_vec_3802 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3803);
												mem_vec_3803 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3804);
												mem_vec_3804 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3805);
												mem_vec_3805 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3806);
												mem_vec_3806 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3807);
												mem_vec_3807 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3808);
												mem_vec_3808 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3809);
												mem_vec_3809 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3810);
												mem_vec_3810 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3811);
												mem_vec_3811 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3812);
												mem_vec_3812 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3813);
												mem_vec_3813 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3814);
												mem_vec_3814 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3815);
												mem_vec_3815 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3800);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3801);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3802);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3803);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3804);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3805);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3806);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3807);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3808);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3809);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3815);
								}
							}
						}
					}
				}
			}
		}
		for (y = y316 + 8, yp_0 = 0;
			y < y316 + 8 + 20;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (x, 4) (28 / 7)
			for (x474 = x475, x474_p_0 = 0;
				x474 < x475 + 28;
				x474 += 7, x474_p_0 += 7){
				// y = ph_y, x = 7, h = 3, w = 3, c = 128, f = 32
				// T (c, 128) (128 / 1)
				for (c474 = c475, c474_p_0 = 0;
					c474 < c475 + 128;
					c474 += 1, c474_p_0 += 1){
					// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 32
					// T (f, 1) (32 / 32)
					for (f = f474, fp_1 = f474_p_0, fp_0 = 0;
						f < f474 + 32;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 7, h = 3, w = 3, c = 1, f = 32
						// T (h, 3) (3 / 1)
						for (h = h248, hp_0 = 0;
							h < h248 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 7, h = 1, w = 3, c = 1, f = 32
							// T (w, 3) (3 / 1)
							for (w = w286, wp_0 = 0;
								w < w286 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 7, h = 1, w = 1, c = 1, f = 32
								// T (x, 7) (7 / 1)
								for (x = x474, xp_1 = x474_p_0, xp_0 = 0;
									x < x474 + 7;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3816 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3817 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
											// T (c, 1) (1 / 1)
											for (c = c474, cp_1 = c474_p_0, cp_0 = 0;
												c < c474 + 1;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3816);
												mem_vec_3816 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3817);
												mem_vec_3817 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3818);
												mem_vec_3818 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3819);
												mem_vec_3819 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3820);
												mem_vec_3820 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3821);
												mem_vec_3821 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3822);
												mem_vec_3822 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3823);
												mem_vec_3823 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3824);
												mem_vec_3824 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3825);
												mem_vec_3825 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3826);
												mem_vec_3826 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3827);
												mem_vec_3827 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3828);
												mem_vec_3828 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3829);
												mem_vec_3829 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3830);
												mem_vec_3830 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3831);
												mem_vec_3831 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3832);
												mem_vec_3832 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3833);
												mem_vec_3833 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3834);
												mem_vec_3834 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3835);
												mem_vec_3835 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3835);
								}
							}
						}
					}
				}
			}
		}
}


}