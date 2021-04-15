#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 12)); ((Iter 4), (Arg 13))]; T (4, f);
  T (16, c); T (4, x)]
*/
IND_TYPE c, cp_0, c744_p_0, cp_1, c744, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x992_p_0, x993_p_0, xp_1, x992_p_1, xp_2, x992, x993, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y496 = 0;
IND_TYPE x994 = 0;
IND_TYPE h496 = 0;
IND_TYPE w466 = 0;
IND_TYPE c745 = 0;
IND_TYPE f496 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9812 ,mem_vec_9813 ,mem_vec_9814 ,mem_vec_9815 ,mem_vec_9816 ,mem_vec_9817 ,mem_vec_9818 ,mem_vec_9819 ,mem_vec_9820 ,mem_vec_9821 ,mem_vec_9822 ,mem_vec_9823 ,mem_vec_9824 ,mem_vec_9825 ,mem_vec_9826 ,mem_vec_9827 ,mem_vec_9828 ,mem_vec_9829 ,mem_vec_9830 ,mem_vec_9831 ,mem_vec_9832 ,mem_vec_9833 ,mem_vec_9834 ,mem_vec_9835 ,mem_vec_9836 ,mem_vec_9837 ,mem_vec_9838 ,mem_vec_9839 ,mem_vec_9840 ,mem_vec_9841 ,mem_vec_9842 ,mem_vec_9843 ,mem_vec_9844 ,mem_vec_9845 ,mem_vec_9846 ,mem_vec_9847 ,mem_vec_9848 ,mem_vec_9849 ,mem_vec_9850 ,mem_vec_9851 ,mem_vec_9852 ,mem_vec_9853 ,mem_vec_9854 ,mem_vec_9855 ,mem_vec_9856 ,mem_vec_9857 ,mem_vec_9858 ,mem_vec_9859 ,mem_vec_9860 ,mem_vec_9861 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 4) (136 / 34)
for (x993 = x994, x993_p_0 = 0;
	x993 < x994 + 136;
	x993 += 34, x993_p_0 += 34){
	// y = 136, x = 34, h = 3, w = 3, c = 64, f = 128
	// T (c, 16) (64 / 4)
	for (c744 = c745, c744_p_0 = 0;
		c744 < c745 + 64;
		c744 += 4, c744_p_0 += 4){
		// y = 136, x = 34, h = 3, w = 3, c = 4, f = 128
		// T (f, 4) (128 / 32)
		for (f = f496, fp_0 = 0;
			f < f496 + 128;
			f += 32, fp_0 += 32){
				for (y = y496, yp_0 = 0;
					y < y496 + 84;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 32
					// T (x, 2) (34 / 17)
					for (x992 = x993, x992_p_1 = x993_p_0, x992_p_0 = 0;
						x992 < x993 + 34;
						x992 += 17, x992_p_1 += 17, x992_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h496, hp_0 = 0;
							h < h496 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 17, h = 1, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w466, wp_0 = 0;
								w < w466 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
								// T (x, 17) (17 / 1)
								for (x = x992, xp_2 = x992_p_1, xp_1 = x992_p_0, xp_0 = 0;
									x < x992 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9812 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9813 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_9823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_9824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_9825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_9826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_9827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_9828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_9829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_9830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_9831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_9832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_9833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_9834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_9835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c744, cp_1 = c744_p_0, cp_0 = 0;
												c < c744 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9812);
												mem_vec_9812 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9813);
												mem_vec_9813 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9814);
												mem_vec_9814 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9815);
												mem_vec_9815 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9816);
												mem_vec_9816 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9817);
												mem_vec_9817 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9818);
												mem_vec_9818 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9819);
												mem_vec_9819 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9820);
												mem_vec_9820 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9821);
												mem_vec_9821 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9822);
												mem_vec_9822 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9823);
												mem_vec_9823 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9824);
												mem_vec_9824 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9825);
												mem_vec_9825 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9826);
												mem_vec_9826 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9827);
												mem_vec_9827 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9828);
												mem_vec_9828 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9829);
												mem_vec_9829 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9830);
												mem_vec_9830 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9831);
												mem_vec_9831 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9832);
												mem_vec_9832 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9833);
												mem_vec_9833 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9834);
												mem_vec_9834 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9835);
												mem_vec_9835 = vec_37;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9835);
								}
							}
						}
					}
				}
				for (y = y496 + 84, yp_0 = 0;
					y < y496 + 84 + 52;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 32
					// T (x, 2) (34 / 17)
					for (x992 = x993, x992_p_1 = x993_p_0, x992_p_0 = 0;
						x992 < x993 + 34;
						x992 += 17, x992_p_1 += 17, x992_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (h, 3) (3 / 1)
						for (h = h496, hp_0 = 0;
							h < h496 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 17, h = 1, w = 3, c = 4, f = 32
							// T (w, 3) (3 / 1)
							for (w = w466, wp_0 = 0;
								w < w466 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 1, c = 4, f = 32
								// T (x, 17) (17 / 1)
								for (x = x992, xp_2 = x992_p_1, xp_1 = x992_p_0, xp_0 = 0;
									x < x992 + 17;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_9836 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_9837 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_9838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_9839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_9840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_9841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_9842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_9843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_9844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_9845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_9846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_9847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_9848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_9849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_9850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_9851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_9852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_9853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_9854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_9855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_9856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_9857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_9858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_9859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_9860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_9861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c744, cp_1 = c744_p_0, cp_0 = 0;
												c < c744 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9836);
												mem_vec_9836 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9837);
												mem_vec_9837 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9838);
												mem_vec_9838 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9839);
												mem_vec_9839 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9840);
												mem_vec_9840 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9841);
												mem_vec_9841 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9842);
												mem_vec_9842 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9843);
												mem_vec_9843 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9844);
												mem_vec_9844 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9845);
												mem_vec_9845 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9846);
												mem_vec_9846 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9847);
												mem_vec_9847 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9848);
												mem_vec_9848 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9849);
												mem_vec_9849 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9850);
												mem_vec_9850 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9851);
												mem_vec_9851 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9852);
												mem_vec_9852 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9853);
												mem_vec_9853 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9854);
												mem_vec_9854 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9855);
												mem_vec_9855 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9856);
												mem_vec_9856 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9857);
												mem_vec_9857 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9858);
												mem_vec_9858 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9859);
												mem_vec_9859 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9860);
												mem_vec_9860 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9861);
												mem_vec_9861 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9839);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9842);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9857);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9859);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9860);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9861);
								}
							}
						}
					}
				}
		}
	}
}


}