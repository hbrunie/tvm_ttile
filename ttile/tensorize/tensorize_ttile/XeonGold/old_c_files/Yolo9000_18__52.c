#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (64, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (2, c); T (1, c)]
*/
IND_TYPE c, cp_0, c95_p_0, c96_p_0, c97_p_0, cp_1, c95_p_1, c96_p_1, cp_2, c95_p_2, cp_3, c95, c96, c97, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y38 = 0;
IND_TYPE x38 = 0;
IND_TYPE h32 = 0;
IND_TYPE w32 = 0;
IND_TYPE c98 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_790 ,mem_vec_791 ,mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,mem_vec_822 ,mem_vec_823 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 1) (512 / 512)
for (c97 = c98, c97_p_0 = 0;
	c97 < c98 + 512;
	c97 += 512, c97_p_0 += 512){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
	// T (c, 2) (512 / 256)
	for (c96 = c97, c96_p_1 = c97_p_0, c96_p_0 = 0;
		c96 < c97 + 512;
		c96 += 256, c96_p_1 += 256, c96_p_0 += 256){
		// y = 17, x = 17, h = 3, w = 3, c = 256, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f38, fp_0 = 0;
			f < f38 + 1024;
			f += 32, fp_0 += 32){
				for (y = y38, yp_0 = 0;
					y < y38 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 64) (256 / 4)
					for (c95 = c96, c95_p_2 = c96_p_1, c95_p_1 = c96_p_0, c95_p_0 = 0;
						c95 < c96 + 256;
						c95 += 4, c95_p_2 += 4, c95_p_1 += 4, c95_p_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x38, xp_0 = 0;
							x < x38 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h32, hp_0 = 0;
								h < h32 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w32, wp_0 = 0;
									w < w32 + 3;
									w += 1, wp_0 += 1){
											mem_vec_790 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_791 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c95, cp_3 = c95_p_2, cp_2 = c95_p_1, cp_1 = c95_p_0, cp_0 = 0;
												c < c95 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_790);
												mem_vec_790 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_791);
												mem_vec_791 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_792);
												mem_vec_792 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_793);
												mem_vec_793 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_794);
												mem_vec_794 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_795);
												mem_vec_795 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_796);
												mem_vec_796 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_797);
												mem_vec_797 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_798);
												mem_vec_798 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_799);
												mem_vec_799 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_800);
												mem_vec_800 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_801);
												mem_vec_801 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_802);
												mem_vec_802 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_803);
												mem_vec_803 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_804);
												mem_vec_804 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_805);
												mem_vec_805 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_790);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_791);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_792);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_793);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_794);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_795);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_796);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_797);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_798);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_799);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_800);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_801);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_802);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_803);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_804);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_805);
								}
							}
						}
					}
				}
				for (y = y38 + 8, yp_0 = 0;
					y < y38 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 32
					// T (c, 64) (256 / 4)
					for (c95 = c96, c95_p_2 = c96_p_1, c95_p_1 = c96_p_0, c95_p_0 = 0;
						c95 < c96 + 256;
						c95 += 4, c95_p_2 += 4, c95_p_1 += 4, c95_p_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 4, f = 32
						// T (x, 17) (17 / 1)
						for (x = x38, xp_0 = 0;
							x < x38 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (h, 3) (3 / 1)
							for (h = h32, hp_0 = 0;
								h < h32 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
								// T (w, 3) (3 / 1)
								for (w = w32, wp_0 = 0;
									w < w32 + 3;
									w += 1, wp_0 += 1){
											mem_vec_806 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_807 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
											// T (c, 4) (4 / 1)
											for (c = c95, cp_3 = c95_p_2, cp_2 = c95_p_1, cp_1 = c95_p_0, cp_0 = 0;
												c < c95 + 4;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_806);
												mem_vec_806 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_807);
												mem_vec_807 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_808);
												mem_vec_808 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_809);
												mem_vec_809 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_810);
												mem_vec_810 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_811);
												mem_vec_811 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_812);
												mem_vec_812 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_813);
												mem_vec_813 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_814);
												mem_vec_814 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_815);
												mem_vec_815 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_816);
												mem_vec_816 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_817);
												mem_vec_817 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_818);
												mem_vec_818 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_819);
												mem_vec_819 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_820);
												mem_vec_820 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_821);
												mem_vec_821 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_822);
												mem_vec_822 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_823);
												mem_vec_823 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_806);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_807);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_808);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_809);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_823);
								}
							}
						}
					}
				}
		}
	}
}


}