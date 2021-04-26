#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (2, c); T (4, f); T (8, x);
  Lambda_apply y [((Iter 9), (Arg 9)); ((Iter 5), (Arg 11))]; T (1, x)]
*/
IND_TYPE c, cp_0, c360_p_0, cp_1, c360, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x423_p_0, x424_p_0, xp_1, x423_p_1, xp_2, x423, x424, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y267 = 0;
IND_TYPE x425 = 0;
IND_TYPE h209 = 0;
IND_TYPE w237 = 0;
IND_TYPE c361 = 0;
IND_TYPE f240 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4797 ,mem_vec_4798 ,mem_vec_4799 ,mem_vec_4800 ,mem_vec_4801 ,mem_vec_4802 ,mem_vec_4803 ,mem_vec_4804 ,mem_vec_4805 ,mem_vec_4806 ,mem_vec_4807 ,mem_vec_4808 ,mem_vec_4809 ,mem_vec_4810 ,mem_vec_4811 ,mem_vec_4812 ,mem_vec_4813 ,mem_vec_4814 ,mem_vec_4815 ,mem_vec_4816 ,mem_vec_4817 ,mem_vec_4818 ,mem_vec_4819 ,mem_vec_4820 ,mem_vec_4821 ,mem_vec_4822 ,mem_vec_4823 ,mem_vec_4824 ,mem_vec_4825 ,mem_vec_4826 ,mem_vec_4827 ,mem_vec_4828 ,mem_vec_4829 ,mem_vec_4830 ,mem_vec_4831 ,mem_vec_4832 ,mem_vec_4833 ,mem_vec_4834 ,mem_vec_4835 ,mem_vec_4836 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x424 = x425, x424_p_0 = 0;
	x424 < x425 + 136;
	x424 += 136, x424_p_0 += 136){
		for (y = y267, yp_0 = 0;
			y < y267 + 81;
			y += 9, yp_0 += 9){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 8) (136 / 17)
			for (x423 = x424, x423_p_1 = x424_p_0, x423_p_0 = 0;
				x423 < x424 + 136;
				x423 += 17, x423_p_1 += 17, x423_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f240, fp_0 = 0;
					f < f240 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 2) (64 / 32)
					for (c360 = c361, c360_p_0 = 0;
						c360 < c361 + 64;
						c360 += 32, c360_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w237, wp_0 = 0;
							w < w237 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
							// T (x, 17) (17 / 1)
							for (x = x423, xp_2 = x423_p_1, xp_1 = x423_p_0, xp_0 = 0;
								x < x423 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h209, hp_0 = 0;
									h < h209 + 3;
									h += 1, hp_0 += 1){
											mem_vec_4797 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4798 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c360, cp_1 = c360_p_0, cp_0 = 0;
												c < c360 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4797);
												mem_vec_4797 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4798);
												mem_vec_4798 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4799);
												mem_vec_4799 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4800);
												mem_vec_4800 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4801);
												mem_vec_4801 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4802);
												mem_vec_4802 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4803);
												mem_vec_4803 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4804);
												mem_vec_4804 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4805);
												mem_vec_4805 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4806);
												mem_vec_4806 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4807);
												mem_vec_4807 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4808);
												mem_vec_4808 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4809);
												mem_vec_4809 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4810);
												mem_vec_4810 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4811);
												mem_vec_4811 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4812);
												mem_vec_4812 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4813);
												mem_vec_4813 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4814);
												mem_vec_4814 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4797);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4798);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4799);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4800);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4801);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4802);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4803);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4804);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4805);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4806);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4807);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4808);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4809);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4814);
								}
							}
						}
					}
				}
			}
		}
		for (y = y267 + 81, yp_0 = 0;
			y < y267 + 81 + 55;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 8) (136 / 17)
			for (x423 = x424, x423_p_1 = x424_p_0, x423_p_0 = 0;
				x423 < x424 + 136;
				x423 += 17, x423_p_1 += 17, x423_p_0 += 17){
				// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f240, fp_0 = 0;
					f < f240 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (c, 2) (64 / 32)
					for (c360 = c361, c360_p_0 = 0;
						c360 < c361 + 64;
						c360 += 32, c360_p_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w237, wp_0 = 0;
							w < w237 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
							// T (x, 17) (17 / 1)
							for (x = x423, xp_2 = x423_p_1, xp_1 = x423_p_0, xp_0 = 0;
								x < x423 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h209, hp_0 = 0;
									h < h209 + 3;
									h += 1, hp_0 += 1){
											mem_vec_4815 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4816 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_4830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_4831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_4832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_4833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_4834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_4835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_4836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c360, cp_1 = c360_p_0, cp_0 = 0;
												c < c360 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4815);
												mem_vec_4815 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4816);
												mem_vec_4816 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4817);
												mem_vec_4817 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4818);
												mem_vec_4818 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4819);
												mem_vec_4819 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4820);
												mem_vec_4820 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4821);
												mem_vec_4821 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4822);
												mem_vec_4822 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4823);
												mem_vec_4823 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4824);
												mem_vec_4824 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4825);
												mem_vec_4825 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4826);
												mem_vec_4826 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4827);
												mem_vec_4827 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4828);
												mem_vec_4828 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4829);
												mem_vec_4829 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4830);
												mem_vec_4830 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4831);
												mem_vec_4831 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4832);
												mem_vec_4832 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4833);
												mem_vec_4833 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4834);
												mem_vec_4834 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4835);
												mem_vec_4835 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4836);
												mem_vec_4836 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4829);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4836);
								}
							}
						}
					}
				}
			}
		}
}


}