#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (3, w);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (1, f);
  T (8, c); T (32, f)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, f104_p_0, f105_p_0, fp_1, f104_p_1, fp_2, f104, f105, h, hp_0, w, wp_0, x, xp_0, x78_p_0, xp_1, x78, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y52 = 0;
IND_TYPE x79 = 0;
IND_TYPE h52 = 0;
IND_TYPE w52 = 0;
IND_TYPE c79 = 0;
IND_TYPE f106 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (f, 32) (1024 / 32)
for (f105 = f106, f105_p_0 = 0;
	f105 < f106 + 1024;
	f105 += 32, f105_p_0 += 32){
	// y = 17, x = 17, h = 3, w = 3, c = 512, f = 32
	// T (c, 8) (512 / 64)
	for (c78 = c79, c78_p_0 = 0;
		c78 < c79 + 512;
		c78 += 64, c78_p_0 += 64){
		// y = 17, x = 17, h = 3, w = 3, c = 64, f = 32
		// T (f, 1) (32 / 32)
		for (f104 = f105, f104_p_1 = f105_p_0, f104_p_0 = 0;
			f104 < f105 + 32;
			f104 += 32, f104_p_1 += 32, f104_p_0 += 32){
				for (y = y52, yp_0 = 0;
					y < y52 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (x, 1) (17 / 17)
					for (x78 = x79, x78_p_0 = 0;
						x78 < x79 + 17;
						x78 += 17, x78_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (f, 1) (32 / 32)
						for (f = f104, fp_2 = f104_p_1, fp_1 = f104_p_0, fp_0 = 0;
							f < f104 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h52, hp_0 = 0;
								h < h52 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 32
									// T (x, 17) (17 / 1)
									for (x = x78, xp_1 = x78_p_0, xp_0 = 0;
										x < x78 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_884 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_885 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
													c < c78 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_884);
													mem_vec_884 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_885);
													mem_vec_885 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_886);
													mem_vec_886 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_887);
													mem_vec_887 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_888);
													mem_vec_888 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_889);
													mem_vec_889 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_890);
													mem_vec_890 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_891);
													mem_vec_891 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_892);
													mem_vec_892 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_893);
													mem_vec_893 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_894);
													mem_vec_894 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_895);
													mem_vec_895 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_896);
													mem_vec_896 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_897);
													mem_vec_897 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_898);
													mem_vec_898 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_899);
													mem_vec_899 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_884);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_885);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_886);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_887);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_888);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_889);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_890);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_891);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_892);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_893);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_894);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_895);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_896);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_897);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_898);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_899);
									}
								}
							}
						}
					}
				}
				for (y = y52 + 8, yp_0 = 0;
					y < y52 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
					// T (x, 1) (17 / 17)
					for (x78 = x79, x78_p_0 = 0;
						x78 < x79 + 17;
						x78 += 17, x78_p_0 += 17){
						// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
						// T (f, 1) (32 / 32)
						for (f = f104, fp_2 = f104_p_1, fp_1 = f104_p_0, fp_0 = 0;
							f < f104 + 32;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 17, h = 3, w = 3, c = 64, f = 32
							// T (h, 3) (3 / 1)
							for (h = h52, hp_0 = 0;
								h < h52 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 17, h = 1, w = 3, c = 64, f = 32
								// T (w, 3) (3 / 1)
								for (w = w52, wp_0 = 0;
									w < w52 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 32
									// T (x, 17) (17 / 1)
									for (x = x78, xp_1 = x78_p_0, xp_0 = 0;
										x < x78 + 17;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
												// T (c, 64) (64 / 1)
												for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
													c < c78 + 64;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_900);
													mem_vec_900 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_901);
													mem_vec_901 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_902);
													mem_vec_902 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_903);
													mem_vec_903 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_904);
													mem_vec_904 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_905);
													mem_vec_905 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_906);
													mem_vec_906 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_907);
													mem_vec_907 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_908);
													mem_vec_908 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_909);
													mem_vec_909 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_910);
													mem_vec_910 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_911);
													mem_vec_911 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_912);
													mem_vec_912 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_913);
													mem_vec_913 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_914);
													mem_vec_914 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_915);
													mem_vec_915 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_916);
													mem_vec_916 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_917);
													mem_vec_917 = vec_28;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_900);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_901);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_902);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_903);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_904);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_905);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_906);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_907);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_908);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_909);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_910);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_911);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_912);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_913);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_914);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_915);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_916);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_917);
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