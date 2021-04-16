#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (4, c); T (4, f); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (2, x)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x64_p_0, x65_p_0, xp_1, x64_p_1, xp_2, x64, x65, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y32 = 0;
IND_TYPE x66 = 0;
IND_TYPE h32 = 0;
IND_TYPE w32 = 0;
IND_TYPE c49 = 0;
IND_TYPE f32 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,mem_vec_822 ,mem_vec_823 ,mem_vec_824 ,mem_vec_825 ,mem_vec_826 ,mem_vec_827 ,mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 2) (136 / 68)
for (x65 = x66, x65_p_0 = 0;
	x65 < x66 + 136;
	x65 += 68, x65_p_0 += 68){
		for (y = y32, yp_0 = 0;
			y < y32 + 70;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 128
			// T (x, 2) (68 / 34)
			for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
				x64 < x65 + 68;
				x64 += 34, x64_p_1 += 34, x64_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f32, fp_0 = 0;
					f < f32 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c48 = c49, c48_p_0 = 0;
						c48 < c49 + 64;
						c48 += 16, c48_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w32, wp_0 = 0;
							w < w32 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
								x < x64 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h32, hp_0 = 0;
									h < h32 + 3;
									h += 1, hp_0 += 1){
											mem_vec_798 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_799 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
												c < c48 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_798);
												mem_vec_798 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_799);
												mem_vec_799 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_800);
												mem_vec_800 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_801);
												mem_vec_801 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_802);
												mem_vec_802 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_803);
												mem_vec_803 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_804);
												mem_vec_804 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_805);
												mem_vec_805 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_806);
												mem_vec_806 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_807);
												mem_vec_807 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_808);
												mem_vec_808 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_809);
												mem_vec_809 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_810);
												mem_vec_810 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_811);
												mem_vec_811 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_812);
												mem_vec_812 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_813);
												mem_vec_813 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_814);
												mem_vec_814 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_815);
												mem_vec_815 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_816);
												mem_vec_816 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_817);
												mem_vec_817 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_798);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_799);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_800);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_801);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_802);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_803);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_804);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_805);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_806);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_807);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_808);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_809);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_817);
								}
							}
						}
					}
				}
			}
		}
		for (y = y32 + 70, yp_0 = 0;
			y < y32 + 70 + 66;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 68, h = 3, w = 3, c = 64, f = 128
			// T (x, 2) (68 / 34)
			for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
				x64 < x65 + 68;
				x64 += 34, x64_p_1 += 34, x64_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f32, fp_0 = 0;
					f < f32 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c48 = c49, c48_p_0 = 0;
						c48 < c49 + 64;
						c48 += 16, c48_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w32, wp_0 = 0;
							w < w32 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
								x < x64 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h32, hp_0 = 0;
									h < h32 + 3;
									h += 1, hp_0 += 1){
											mem_vec_818 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_819 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
												c < c48 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_818);
												mem_vec_818 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_819);
												mem_vec_819 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_820);
												mem_vec_820 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_821);
												mem_vec_821 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_822);
												mem_vec_822 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_823);
												mem_vec_823 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_824);
												mem_vec_824 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_825);
												mem_vec_825 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_826);
												mem_vec_826 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_827);
												mem_vec_827 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_828);
												mem_vec_828 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_829);
												mem_vec_829 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_830);
												mem_vec_830 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_831);
												mem_vec_831 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_832);
												mem_vec_832 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_833);
												mem_vec_833 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_834);
												mem_vec_834 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_835);
												mem_vec_835 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_836);
												mem_vec_836 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_837);
												mem_vec_837 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_838);
												mem_vec_838 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_839);
												mem_vec_839 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_839);
								}
							}
						}
					}
				}
			}
		}
}


}