#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, h); T (7, x);
  T (3, w); T (8, c); T (1, f); T (4, y); T (4, x); T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c513_p_0, cp_1, c513, f, fp_0, f604_p_0, f605_p_0, fp_1, f604_p_1, fp_2, f604, f605, h, hp_0, w, wp_0, x, xp_0, x537_p_0, xp_1, x537, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y382 = 0;
IND_TYPE x538 = 0;
IND_TYPE h328 = 0;
IND_TYPE w228 = 0;
IND_TYPE c514 = 0;
IND_TYPE f606 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_4830 ,mem_vec_4831 ,mem_vec_4832 ,mem_vec_4833 ,mem_vec_4834 ,mem_vec_4835 ,mem_vec_4836 ,mem_vec_4837 ,mem_vec_4838 ,mem_vec_4839 ,mem_vec_4840 ,mem_vec_4841 ,mem_vec_4842 ,mem_vec_4843 ,mem_vec_4844 ,mem_vec_4845 ,mem_vec_4846 ,mem_vec_4847 ,mem_vec_4848 ,mem_vec_4849 ,mem_vec_4850 ,mem_vec_4851 ,mem_vec_4852 ,mem_vec_4853 ,mem_vec_4854 ,mem_vec_4855 ,mem_vec_4856 ,mem_vec_4857 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f605 = f606, f605_p_0 = 0;
	f605 < f606 + 256;
	f605 += 64, f605_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (f, 1) (64 / 64)
	for (f604 = f605, f604_p_1 = f605_p_0, f604_p_0 = 0;
		f604 < f605 + 64;
		f604 += 64, f604_p_1 += 64, f604_p_0 += 64){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
		// T (x, 4) (28 / 7)
		for (x537 = x538, x537_p_0 = 0;
			x537 < x538 + 28;
			x537 += 7, x537_p_0 += 7){
			// y = 28, x = 7, h = 3, w = 3, c = 256, f = 64
			// T (y, 4) (28 / 7)
			for (y = y382, yp_0 = 0;
				y < y382 + 28;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 256, f = 64
				// T (f, 1) (64 / 64)
				for (f = f604, fp_2 = f604_p_1, fp_1 = f604_p_0, fp_0 = 0;
					f < f604 + 64;
					f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
					// y = 7, x = 7, h = 3, w = 3, c = 256, f = 64
					// T (c, 8) (256 / 32)
					for (c513 = c514, c513_p_0 = 0;
						c513 < c514 + 256;
						c513 += 32, c513_p_0 += 32){
						// y = 7, x = 7, h = 3, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w228, wp_0 = 0;
							w < w228 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 3, w = 1, c = 32, f = 64
							// T (x, 7) (7 / 1)
							for (x = x537, xp_1 = x537_p_0, xp_0 = 0;
								x < x537 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = 7, x = 1, h = 3, w = 1, c = 32, f = 64
								// T (h, 3) (3 / 1)
								for (h = h328, hp_0 = 0;
									h < h328 + 3;
									h += 1, hp_0 += 1){
											mem_vec_4830 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_4831 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_4832 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_4833 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_4834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_4835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_4836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_4837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_4838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_4839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_4840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_4841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_4842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_4843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_4844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_4845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_4846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_4847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_4848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_4849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_4850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_4851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_4852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_4853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_4854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_4855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_4856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_4857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
											// T (c, 32) (32 / 1)
											for (c = c513, cp_1 = c513_p_0, cp_0 = 0;
												c < c513 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4830);
												mem_vec_4830 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4831);
												mem_vec_4831 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4832);
												mem_vec_4832 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4833);
												mem_vec_4833 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4834);
												mem_vec_4834 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4835);
												mem_vec_4835 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4836);
												mem_vec_4836 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4837);
												mem_vec_4837 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4838);
												mem_vec_4838 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4839);
												mem_vec_4839 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4840);
												mem_vec_4840 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4841);
												mem_vec_4841 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4842);
												mem_vec_4842 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4843);
												mem_vec_4843 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4844);
												mem_vec_4844 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4845);
												mem_vec_4845 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4846);
												mem_vec_4846 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4847);
												mem_vec_4847 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4848);
												mem_vec_4848 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4849);
												mem_vec_4849 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4850);
												mem_vec_4850 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4851);
												mem_vec_4851 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4852);
												mem_vec_4852 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4853);
												mem_vec_4853 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_4854);
												mem_vec_4854 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_4855);
												mem_vec_4855 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_4856);
												mem_vec_4856 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_4857);
												mem_vec_4857 = vec_38;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4839);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4842);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_4852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_4853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_4856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_4857);
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