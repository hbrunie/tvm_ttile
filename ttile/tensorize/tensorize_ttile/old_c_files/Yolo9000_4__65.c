#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (2, x);
  Lambda_apply y [((Iter 7), (Arg 13)); ((Iter 3), (Arg 15))]; T (4, f);
  T (2, c); T (68, x)]
*/
IND_TYPE c, cp_0, c858_p_0, cp_1, c858, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x1144_p_0, x1145_p_0, xp_1, x1144_p_1, xp_2, x1144, x1145, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y572 = 0;
IND_TYPE x1146 = 0;
IND_TYPE h572 = 0;
IND_TYPE w542 = 0;
IND_TYPE c859 = 0;
IND_TYPE f572 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11844 ,mem_vec_11845 ,mem_vec_11846 ,mem_vec_11847 ,mem_vec_11848 ,mem_vec_11849 ,mem_vec_11850 ,mem_vec_11851 ,mem_vec_11852 ,mem_vec_11853 ,mem_vec_11854 ,mem_vec_11855 ,mem_vec_11856 ,mem_vec_11857 ,mem_vec_11858 ,mem_vec_11859 ,mem_vec_11860 ,mem_vec_11861 ,mem_vec_11862 ,mem_vec_11863 ,mem_vec_11864 ,mem_vec_11865 ,mem_vec_11866 ,mem_vec_11867 ,mem_vec_11868 ,mem_vec_11869 ,mem_vec_11870 ,mem_vec_11871 ,mem_vec_11872 ,mem_vec_11873 ,mem_vec_11874 ,mem_vec_11875 ,mem_vec_11876 ,mem_vec_11877 ,mem_vec_11878 ,mem_vec_11879 ,mem_vec_11880 ,mem_vec_11881 ,mem_vec_11882 ,mem_vec_11883 ,mem_vec_11884 ,mem_vec_11885 ,mem_vec_11886 ,mem_vec_11887 ,mem_vec_11888 ,mem_vec_11889 ,mem_vec_11890 ,mem_vec_11891 ,mem_vec_11892 ,mem_vec_11893 ,mem_vec_11894 ,mem_vec_11895 ,mem_vec_11896 ,mem_vec_11897 ,mem_vec_11898 ,mem_vec_11899 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 68) (136 / 2)
for (x1145 = x1146, x1145_p_0 = 0;
	x1145 < x1146 + 136;
	x1145 += 2, x1145_p_0 += 2){
	// y = 136, x = 2, h = 3, w = 3, c = 64, f = 128
	// T (c, 2) (64 / 32)
	for (c858 = c859, c858_p_0 = 0;
		c858 < c859 + 64;
		c858 += 32, c858_p_0 += 32){
		// y = 136, x = 2, h = 3, w = 3, c = 32, f = 128
		// T (f, 4) (128 / 32)
		for (f = f572, fp_0 = 0;
			f < f572 + 128;
			f += 32, fp_0 += 32){
				for (y = y572, yp_0 = 0;
					y < y572 + 91;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
					// T (x, 2) (2 / 1)
					for (x1144 = x1145, x1144_p_1 = x1145_p_0, x1144_p_0 = 0;
						x1144 < x1145 + 2;
						x1144 += 1, x1144_p_1 += 1, x1144_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h572, hp_0 = 0;
							h < h572 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w542, wp_0 = 0;
								w < w542 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1144, xp_2 = x1144_p_1, xp_1 = x1144_p_0, xp_0 = 0;
									x < x1144 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11845 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_11855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_11856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_11857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_11858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_11859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_11860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_11861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_11862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_11863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_11864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_11865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_11866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_11867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_11868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_11869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c858, cp_1 = c858_p_0, cp_0 = 0;
												c < c858 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11844);
												mem_vec_11844 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11845);
												mem_vec_11845 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11846);
												mem_vec_11846 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11847);
												mem_vec_11847 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11848);
												mem_vec_11848 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11849);
												mem_vec_11849 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11850);
												mem_vec_11850 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11851);
												mem_vec_11851 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11852);
												mem_vec_11852 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11853);
												mem_vec_11853 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11854);
												mem_vec_11854 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11855);
												mem_vec_11855 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11856);
												mem_vec_11856 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11857);
												mem_vec_11857 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11858);
												mem_vec_11858 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11859);
												mem_vec_11859 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11860);
												mem_vec_11860 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11861);
												mem_vec_11861 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11862);
												mem_vec_11862 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11863);
												mem_vec_11863 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11864);
												mem_vec_11864 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11865);
												mem_vec_11865 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11866);
												mem_vec_11866 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11867);
												mem_vec_11867 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11868);
												mem_vec_11868 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11869);
												mem_vec_11869 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11857);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11859);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11860);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11861);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11862);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11863);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11864);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11865);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11866);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11867);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_11868);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_11869);
								}
							}
						}
					}
				}
				for (y = y572 + 91, yp_0 = 0;
					y < y572 + 91 + 45;
					y += 15, yp_0 += 15){
					// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 32
					// T (x, 2) (2 / 1)
					for (x1144 = x1145, x1144_p_1 = x1145_p_0, x1144_p_0 = 0;
						x1144 < x1145 + 2;
						x1144 += 1, x1144_p_1 += 1, x1144_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (h, 3) (3 / 1)
						for (h = h572, hp_0 = 0;
							h < h572 + 3;
							h += 1, hp_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
							// T (w, 3) (3 / 1)
							for (w = w542, wp_0 = 0;
								w < w542 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1144, xp_2 = x1144_p_1, xp_1 = x1144_p_0, xp_0 = 0;
									x < x1144 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_11870 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_11871 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_11872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_11873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_11874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_11875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_11876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_11877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_11878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_11879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_11880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_11881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_11882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_11883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_11884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_11885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_11886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_11887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_11888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_11889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_11890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_11891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_11892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_11893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_11894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_11895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_11896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_11897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_11898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_11899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c858, cp_1 = c858_p_0, cp_0 = 0;
												c < c858 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11870);
												mem_vec_11870 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11871);
												mem_vec_11871 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11872);
												mem_vec_11872 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11873);
												mem_vec_11873 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11874);
												mem_vec_11874 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11875);
												mem_vec_11875 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11876);
												mem_vec_11876 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11877);
												mem_vec_11877 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11878);
												mem_vec_11878 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11879);
												mem_vec_11879 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11880);
												mem_vec_11880 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11881);
												mem_vec_11881 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11882);
												mem_vec_11882 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11883);
												mem_vec_11883 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11884);
												mem_vec_11884 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11885);
												mem_vec_11885 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11886);
												mem_vec_11886 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11887);
												mem_vec_11887 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11888);
												mem_vec_11888 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11889);
												mem_vec_11889 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11890);
												mem_vec_11890 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11891);
												mem_vec_11891 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11892);
												mem_vec_11892 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11893);
												mem_vec_11893 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11894);
												mem_vec_11894 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11895);
												mem_vec_11895 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_11896);
												mem_vec_11896 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_11897);
												mem_vec_11897 = vec_43;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_11898);
												mem_vec_11898 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_11899);
												mem_vec_11899 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11870);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11871);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11872);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11873);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11874);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11875);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11876);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11877);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11878);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11879);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11880);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11881);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11882);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11883);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11884);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11885);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11886);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11887);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11888);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11889);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11890);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11891);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11892);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11893);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_11894);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_11895);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_11896);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_11897);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_11898);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_11899);
								}
							}
						}
					}
				}
		}
	}
}


}