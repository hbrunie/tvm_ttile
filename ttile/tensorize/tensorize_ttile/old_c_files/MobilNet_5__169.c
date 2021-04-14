#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (8, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (4, y); T (1, f); T (8, c); T (2, f); T (4, c); T (2, x);
  T (2, f)]
*/
IND_TYPE c, cp_0, c120_p_0, c121_p_0, cp_1, c120_p_1, cp_2, c120, c121, f, fp_0, f108_p_0, f109_p_0, fp_1, f108_p_1, fp_2, f108, f109, h, hp_0, w, wp_0, x, xp_0, x90_p_0, xp_1, x90, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y60 = 0;
IND_TYPE x91 = 0;
IND_TYPE h60 = 0;
IND_TYPE w60 = 0;
IND_TYPE c122 = 0;
IND_TYPE f110 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f109 = f110, f109_p_0 = 0;
	f109 < f110 + 256;
	f109 += 128, f109_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
	// T (x, 2) (28 / 14)
	for (x90 = x91, x90_p_0 = 0;
		x90 < x91 + 28;
		x90 += 14, x90_p_0 += 14){
		// y = 28, x = 14, h = 3, w = 3, c = 256, f = 128
		// T (c, 4) (256 / 64)
		for (c121 = c122, c121_p_0 = 0;
			c121 < c122 + 256;
			c121 += 64, c121_p_0 += 64){
			// y = 28, x = 14, h = 3, w = 3, c = 64, f = 128
			// T (f, 2) (128 / 64)
			for (f108 = f109, f108_p_1 = f109_p_0, f108_p_0 = 0;
				f108 < f109 + 128;
				f108 += 64, f108_p_1 += 64, f108_p_0 += 64){
				// y = 28, x = 14, h = 3, w = 3, c = 64, f = 64
				// T (c, 8) (64 / 8)
				for (c120 = c121, c120_p_1 = c121_p_0, c120_p_0 = 0;
					c120 < c121 + 64;
					c120 += 8, c120_p_1 += 8, c120_p_0 += 8){
					// y = 28, x = 14, h = 3, w = 3, c = 8, f = 64
					// T (f, 1) (64 / 64)
					for (f = f108, fp_2 = f108_p_1, fp_1 = f108_p_0, fp_0 = 0;
						f < f108 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 28, x = 14, h = 3, w = 3, c = 8, f = 64
						// T (y, 4) (28 / 7)
						for (y = y60, yp_0 = 0;
							y < y60 + 28;
							y += 7, yp_0 += 7){
							// y = 7, x = 14, h = 3, w = 3, c = 8, f = 64
							// T (h, 3) (3 / 1)
							for (h = h60, hp_0 = 0;
								h < h60 + 3;
								h += 1, hp_0 += 1){
								// y = 7, x = 14, h = 1, w = 3, c = 8, f = 64
								// T (w, 3) (3 / 1)
								for (w = w60, wp_0 = 0;
									w < w60 + 3;
									w += 1, wp_0 += 1){
									// y = 7, x = 14, h = 1, w = 1, c = 8, f = 64
									// T (x, 14) (14 / 1)
									for (x = x90, xp_1 = x90_p_0, xp_0 = 0;
										x < x90 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 8, f = 64
												// T (c, 8) (8 / 1)
												for (c = c120, cp_2 = c120_p_1, cp_1 = c120_p_0, cp_0 = 0;
													c < c120 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_840);
													mem_vec_840 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_841);
													mem_vec_841 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_842);
													mem_vec_842 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_843);
													mem_vec_843 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_844);
													mem_vec_844 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_845);
													mem_vec_845 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_846);
													mem_vec_846 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_847);
													mem_vec_847 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_848);
													mem_vec_848 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_849);
													mem_vec_849 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_850);
													mem_vec_850 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_851);
													mem_vec_851 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_852);
													mem_vec_852 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_853);
													mem_vec_853 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_854);
													mem_vec_854 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_855);
													mem_vec_855 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_856);
													mem_vec_856 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_857);
													mem_vec_857 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_858);
													mem_vec_858 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_859);
													mem_vec_859 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_860);
													mem_vec_860 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_861);
													mem_vec_861 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_862);
													mem_vec_862 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_863);
													mem_vec_863 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_864);
													mem_vec_864 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_865);
													mem_vec_865 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_866);
													mem_vec_866 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_867);
													mem_vec_867 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_840);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_841);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_842);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_843);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_844);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_845);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_846);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_847);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_848);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_849);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_850);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_851);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_852);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_853);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_854);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_855);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_856);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_857);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_858);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_859);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_860);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_861);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_862);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_863);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_864);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_865);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_866);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_867);
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


}