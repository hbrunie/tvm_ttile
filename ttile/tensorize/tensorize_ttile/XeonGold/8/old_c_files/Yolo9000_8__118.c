#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (2, f);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (4, x);
  T (1, f); T (4, f)]
*/
IND_TYPE c, cp_0, c219_p_0, cp_1, c219, f, fp_0, f292_p_0, f293_p_0, fp_1, f292_p_1, fp_2, f292, f293, h, hp_0, w, wp_0, x, xp_0, x219_p_0, xp_1, x219, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y146 = 0;
IND_TYPE x220 = 0;
IND_TYPE h146 = 0;
IND_TYPE w132 = 0;
IND_TYPE c220 = 0;
IND_TYPE f294 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2884 ,mem_vec_2885 ,mem_vec_2886 ,mem_vec_2887 ,mem_vec_2888 ,mem_vec_2889 ,mem_vec_2890 ,mem_vec_2891 ,mem_vec_2892 ,mem_vec_2893 ,mem_vec_2894 ,mem_vec_2895 ,mem_vec_2896 ,mem_vec_2897 ,mem_vec_2898 ,mem_vec_2899 ,mem_vec_2900 ,mem_vec_2901 ,mem_vec_2902 ,mem_vec_2903 ,mem_vec_2904 ,mem_vec_2905 ,mem_vec_2906 ,mem_vec_2907 ,mem_vec_2908 ,mem_vec_2909 ,mem_vec_2910 ,mem_vec_2911 ,mem_vec_2912 ,mem_vec_2913 ,mem_vec_2914 ,mem_vec_2915 ,mem_vec_2916 ,mem_vec_2917 ,mem_vec_2918 ,mem_vec_2919 ,mem_vec_2920 ,mem_vec_2921 ,mem_vec_2922 ,mem_vec_2923 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 4) (256 / 64)
for (f293 = f294, f293_p_0 = 0;
	f293 < f294 + 256;
	f293 += 64, f293_p_0 += 64){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
	// T (f, 1) (64 / 64)
	for (f292 = f293, f292_p_1 = f293_p_0, f292_p_0 = 0;
		f292 < f293 + 64;
		f292 += 64, f292_p_1 += 64, f292_p_0 += 64){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 64
		// T (x, 4) (68 / 17)
		for (x219 = x220, x219_p_0 = 0;
			x219 < x220 + 68;
			x219 += 17, x219_p_0 += 17){
				for (y = y146, yp_0 = 0;
					y < y146 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f292, fp_2 = f292_p_1, fp_1 = f292_p_0, fp_0 = 0;
						f < f292 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c219 = c220, c219_p_0 = 0;
							c219 < c220 + 128;
							c219 += 16, c219_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w132, wp_0 = 0;
								w < w132 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x219, xp_1 = x219_p_0, xp_0 = 0;
									x < x219 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h146, hp_0 = 0;
										h < h146 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2884 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2885 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c219, cp_1 = c219_p_0, cp_0 = 0;
													c < c219 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2884);
													mem_vec_2884 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2885);
													mem_vec_2885 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2886);
													mem_vec_2886 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2887);
													mem_vec_2887 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2888);
													mem_vec_2888 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2889);
													mem_vec_2889 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2890);
													mem_vec_2890 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2891);
													mem_vec_2891 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2892);
													mem_vec_2892 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2893);
													mem_vec_2893 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2894);
													mem_vec_2894 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2895);
													mem_vec_2895 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2896);
													mem_vec_2896 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2897);
													mem_vec_2897 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2898);
													mem_vec_2898 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2899);
													mem_vec_2899 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2884);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2885);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2886);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2887);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2888);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2889);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2890);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2891);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2892);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2893);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2894);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2895);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2896);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2897);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2898);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2899);
									}
								}
							}
						}
					}
				}
				for (y = y146 + 8, yp_0 = 0;
					y < y146 + 8 + 60;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f292, fp_2 = f292_p_1, fp_1 = f292_p_0, fp_0 = 0;
						f < f292 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c219 = c220, c219_p_0 = 0;
							c219 < c220 + 128;
							c219 += 16, c219_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w132, wp_0 = 0;
								w < w132 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x219, xp_1 = x219_p_0, xp_0 = 0;
									x < x219 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h146, hp_0 = 0;
										h < h146 + 3;
										h += 1, hp_0 += 1){
												mem_vec_2900 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2901 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_2910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_2911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_2912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_2913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_2914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_2915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_2916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_2917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_2918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_2919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_2920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_2921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_2922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_2923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c219, cp_1 = c219_p_0, cp_0 = 0;
													c < c219 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2900);
													mem_vec_2900 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2901);
													mem_vec_2901 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2902);
													mem_vec_2902 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2903);
													mem_vec_2903 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2904);
													mem_vec_2904 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2905);
													mem_vec_2905 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2906);
													mem_vec_2906 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2907);
													mem_vec_2907 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2908);
													mem_vec_2908 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2909);
													mem_vec_2909 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2910);
													mem_vec_2910 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2911);
													mem_vec_2911 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2912);
													mem_vec_2912 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2913);
													mem_vec_2913 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2914);
													mem_vec_2914 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2915);
													mem_vec_2915 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2916);
													mem_vec_2916 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2917);
													mem_vec_2917 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2918);
													mem_vec_2918 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2919);
													mem_vec_2919 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2920);
													mem_vec_2920 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2921);
													mem_vec_2921 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2922);
													mem_vec_2922 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2923);
													mem_vec_2923 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2900);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2901);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2902);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2903);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2904);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2905);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2906);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2907);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2908);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2909);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2910);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2911);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2912);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2913);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2914);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2915);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2916);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2917);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2918);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2919);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2920);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2921);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2922);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2923);
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