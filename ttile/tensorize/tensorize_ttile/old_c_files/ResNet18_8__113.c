#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x); T (3, w);
  T (3, h); T (2, f); T (1, c); T (7, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (4, f)]
*/
IND_TYPE c, cp_0, c816_p_0, cp_1, c816, f, fp_0, f888_p_0, fp_1, f888, h, hp_0, w, wp_0, x, xp_0, x816_p_0, xp_1, x816, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y544 = 0;
IND_TYPE x817 = 0;
IND_TYPE h470 = 0;
IND_TYPE w494 = 0;
IND_TYPE c817 = 0;
IND_TYPE f889 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7772 ,mem_vec_7773 ,mem_vec_7774 ,mem_vec_7775 ,mem_vec_7776 ,mem_vec_7777 ,mem_vec_7778 ,mem_vec_7779 ,mem_vec_7780 ,mem_vec_7781 ,mem_vec_7782 ,mem_vec_7783 ,mem_vec_7784 ,mem_vec_7785 ,mem_vec_7786 ,mem_vec_7787 ,mem_vec_7788 ,mem_vec_7789 ,mem_vec_7790 ,mem_vec_7791 ,mem_vec_7792 ,mem_vec_7793 ,mem_vec_7794 ,mem_vec_7795 ,mem_vec_7796 ,mem_vec_7797 ,mem_vec_7798 ,mem_vec_7799 ,mem_vec_7800 ,mem_vec_7801 ,mem_vec_7802 ,mem_vec_7803 ,mem_vec_7804 ,mem_vec_7805 ,mem_vec_7806 ,mem_vec_7807 ,mem_vec_7808 ,mem_vec_7809 ,mem_vec_7810 ,mem_vec_7811 ,mem_vec_7812 ,mem_vec_7813 ,mem_vec_7814 ,mem_vec_7815 ,mem_vec_7816 ,mem_vec_7817 ,mem_vec_7818 ,mem_vec_7819 ,mem_vec_7820 ,mem_vec_7821 ,mem_vec_7822 ,mem_vec_7823 ,mem_vec_7824 ,mem_vec_7825 ,mem_vec_7826 ,mem_vec_7827 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f888 = f889, f888_p_0 = 0;
	f888 < f889 + 256;
	f888 += 64, f888_p_0 += 64){
		for (y = y544, yp_0 = 0;
			y < y544 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 7) (28 / 4)
			for (x816 = x817, x816_p_0 = 0;
				x816 < x817 + 28;
				x816 += 4, x816_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 64
				// T (c, 1) (128 / 128)
				for (c816 = c817, c816_p_0 = 0;
					c816 < c817 + 128;
					c816 += 128, c816_p_0 += 128){
					// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f888, fp_1 = f888_p_0, fp_0 = 0;
						f < f888 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h470, hp_0 = 0;
							h < h470 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w494, wp_0 = 0;
								w < w494 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
								// T (x, 4) (4 / 1)
								for (x = x816, xp_1 = x816_p_0, xp_0 = 0;
									x < x816 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7772 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7773 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_7794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_7796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_7797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c816, cp_1 = c816_p_0, cp_0 = 0;
												c < c816 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7772);
												mem_vec_7772 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7773);
												mem_vec_7773 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7774);
												mem_vec_7774 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7775);
												mem_vec_7775 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7776);
												mem_vec_7776 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7777);
												mem_vec_7777 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7778);
												mem_vec_7778 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7779);
												mem_vec_7779 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7780);
												mem_vec_7780 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7781);
												mem_vec_7781 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7782);
												mem_vec_7782 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7783);
												mem_vec_7783 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7784);
												mem_vec_7784 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7785);
												mem_vec_7785 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7786);
												mem_vec_7786 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7787);
												mem_vec_7787 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7788);
												mem_vec_7788 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7789);
												mem_vec_7789 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7790);
												mem_vec_7790 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7791);
												mem_vec_7791 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7792);
												mem_vec_7792 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7793);
												mem_vec_7793 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7794);
												mem_vec_7794 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7795);
												mem_vec_7795 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7796);
												mem_vec_7796 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7797);
												mem_vec_7797 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7772);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7773);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7774);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7775);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7776);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7777);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7778);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7779);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7780);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7781);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7782);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7783);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7784);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7785);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7786);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7787);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7788);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7789);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7790);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7791);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7792);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7793);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7794);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7795);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7796);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7797);
								}
							}
						}
					}
				}
			}
		}
		for (y = y544 + 13, yp_0 = 0;
			y < y544 + 13 + 15;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (x, 7) (28 / 4)
			for (x816 = x817, x816_p_0 = 0;
				x816 < x817 + 28;
				x816 += 4, x816_p_0 += 4){
				// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 64
				// T (c, 1) (128 / 128)
				for (c816 = c817, c816_p_0 = 0;
					c816 < c817 + 128;
					c816 += 128, c816_p_0 += 128){
					// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f888, fp_1 = f888_p_0, fp_0 = 0;
						f < f888 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 3, w = 3, c = 128, f = 32
						// T (h, 3) (3 / 1)
						for (h = h470, hp_0 = 0;
							h < h470 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 4, h = 1, w = 3, c = 128, f = 32
							// T (w, 3) (3 / 1)
							for (w = w494, wp_0 = 0;
								w < w494 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
								// T (x, 4) (4 / 1)
								for (x = x816, xp_1 = x816_p_0, xp_0 = 0;
									x < x816 + 4;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_7798 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_7799 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_7800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_7801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_7802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_7803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_7804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_7805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_7806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_7807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_7808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_7809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_7810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_7811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_7812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_7813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_7814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_7815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_7816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_7817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_7818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_7819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_7820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_7821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_7822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_7823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_7824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_7825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_7826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_7827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
											// T (c, 128) (128 / 1)
											for (c = c816, cp_1 = c816_p_0, cp_0 = 0;
												c < c816 + 128;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7798);
												mem_vec_7798 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7799);
												mem_vec_7799 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7800);
												mem_vec_7800 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7801);
												mem_vec_7801 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7802);
												mem_vec_7802 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7803);
												mem_vec_7803 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7804);
												mem_vec_7804 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7805);
												mem_vec_7805 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7806);
												mem_vec_7806 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7807);
												mem_vec_7807 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7808);
												mem_vec_7808 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7809);
												mem_vec_7809 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7810);
												mem_vec_7810 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7811);
												mem_vec_7811 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7812);
												mem_vec_7812 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7813);
												mem_vec_7813 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7814);
												mem_vec_7814 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7815);
												mem_vec_7815 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7816);
												mem_vec_7816 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7817);
												mem_vec_7817 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7818);
												mem_vec_7818 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7819);
												mem_vec_7819 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7820);
												mem_vec_7820 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7821);
												mem_vec_7821 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7822);
												mem_vec_7822 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7823);
												mem_vec_7823 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_7824);
												mem_vec_7824 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_7825);
												mem_vec_7825 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_7826);
												mem_vec_7826 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_7827);
												mem_vec_7827 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7798);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7799);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7800);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7801);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7802);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7803);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7804);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7805);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7806);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7807);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7808);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7809);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_7824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_7825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_7826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_7827);
								}
							}
						}
					}
				}
			}
		}
}


}