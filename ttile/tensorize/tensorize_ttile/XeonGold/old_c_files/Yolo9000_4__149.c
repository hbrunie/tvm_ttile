#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (4, c); T (4, f); T (1, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (4, x)]
*/
IND_TYPE c, cp_0, c51_p_0, cp_1, c51, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x68_p_0, x69_p_0, xp_1, x68_p_1, xp_2, x68, x69, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y34 = 0;
IND_TYPE x70 = 0;
IND_TYPE h34 = 0;
IND_TYPE w34 = 0;
IND_TYPE c52 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 4) (136 / 34)
for (x69 = x70, x69_p_0 = 0;
	x69 < x70 + 136;
	x69 += 34, x69_p_0 += 34){
		for (y = y34, yp_0 = 0;
			y < y34 + 70;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
			// T (x, 1) (34 / 34)
			for (x68 = x69, x68_p_1 = x69_p_0, x68_p_0 = 0;
				x68 < x69 + 34;
				x68 += 34, x68_p_1 += 34, x68_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f34, fp_0 = 0;
					f < f34 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c51 = c52, c51_p_0 = 0;
						c51 < c52 + 64;
						c51 += 16, c51_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w34, wp_0 = 0;
							w < w34 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x68, xp_2 = x68_p_1, xp_1 = x68_p_0, xp_0 = 0;
								x < x68 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h34, hp_0 = 0;
									h < h34 + 3;
									h += 1, hp_0 += 1){
											mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
												c < c51 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_840);
												mem_vec_840 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_841);
												mem_vec_841 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_842);
												mem_vec_842 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_843);
												mem_vec_843 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_844);
												mem_vec_844 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_845);
												mem_vec_845 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_846);
												mem_vec_846 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_847);
												mem_vec_847 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_848);
												mem_vec_848 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_849);
												mem_vec_849 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_850);
												mem_vec_850 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_851);
												mem_vec_851 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_852);
												mem_vec_852 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_853);
												mem_vec_853 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_854);
												mem_vec_854 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_855);
												mem_vec_855 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_856);
												mem_vec_856 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_857);
												mem_vec_857 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_858);
												mem_vec_858 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_859);
												mem_vec_859 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_842);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_857);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_859);
								}
							}
						}
					}
				}
			}
		}
		for (y = y34 + 70, yp_0 = 0;
			y < y34 + 70 + 66;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
			// T (x, 1) (34 / 34)
			for (x68 = x69, x68_p_1 = x69_p_0, x68_p_0 = 0;
				x68 < x69 + 34;
				x68 += 34, x68_p_1 += 34, x68_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f34, fp_0 = 0;
					f < f34 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c51 = c52, c51_p_0 = 0;
						c51 < c52 + 64;
						c51 += 16, c51_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w34, wp_0 = 0;
							w < w34 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x68, xp_2 = x68_p_1, xp_1 = x68_p_0, xp_0 = 0;
								x < x68 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h34, hp_0 = 0;
									h < h34 + 3;
									h += 1, hp_0 += 1){
											mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
												c < c51 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_860);
												mem_vec_860 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_861);
												mem_vec_861 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_862);
												mem_vec_862 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_863);
												mem_vec_863 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_864);
												mem_vec_864 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_865);
												mem_vec_865 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_866);
												mem_vec_866 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_867);
												mem_vec_867 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_868);
												mem_vec_868 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_869);
												mem_vec_869 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_870);
												mem_vec_870 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_871);
												mem_vec_871 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_872);
												mem_vec_872 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_873);
												mem_vec_873 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_874);
												mem_vec_874 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_875);
												mem_vec_875 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_876);
												mem_vec_876 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_877);
												mem_vec_877 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_878);
												mem_vec_878 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_879);
												mem_vec_879 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_880);
												mem_vec_880 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_881);
												mem_vec_881 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_860);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_861);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_862);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_863);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_864);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_865);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_866);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_867);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_868);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_869);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_870);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_871);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_872);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_873);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_874);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_875);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_876);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_877);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_878);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_879);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_880);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_881);
								}
							}
						}
					}
				}
			}
		}
}


}