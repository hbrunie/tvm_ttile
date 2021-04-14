#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (1, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (4, y); T (1, f); T (256, c); T (1, f); T (1, c); T (14, x);
  T (4, f)]
*/
IND_TYPE c, cp_0, c264_p_0, c265_p_0, cp_1, c264_p_1, cp_2, c264, c265, f, fp_0, f252_p_0, f253_p_0, fp_1, f252_p_1, fp_2, f252, f253, h, hp_0, w, wp_0, x, xp_0, x198_p_0, xp_1, x198, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y132 = 0;
IND_TYPE x199 = 0;
IND_TYPE h132 = 0;
IND_TYPE w132 = 0;
IND_TYPE c266 = 0;
IND_TYPE f254 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1848 ,mem_vec_1849 ,mem_vec_1850 ,mem_vec_1851 ,mem_vec_1852 ,mem_vec_1853 ,mem_vec_1854 ,mem_vec_1855 ,mem_vec_1856 ,mem_vec_1857 ,mem_vec_1858 ,mem_vec_1859 ,mem_vec_1860 ,mem_vec_1861 ,mem_vec_1862 ,mem_vec_1863 ,mem_vec_1864 ,mem_vec_1865 ,mem_vec_1866 ,mem_vec_1867 ,mem_vec_1868 ,mem_vec_1869 ,mem_vec_1870 ,mem_vec_1871 ,mem_vec_1872 ,mem_vec_1873 ,mem_vec_1874 ,mem_vec_1875 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f253 = f254, f253_p_0 = 0;
	f253 < f254 + 256;
	f253 += 64, f253_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 64
	// T (x, 14) (28 / 2)
	for (x198 = x199, x198_p_0 = 0;
		x198 < x199 + 28;
		x198 += 2, x198_p_0 += 2){
		// y = 28, x = 2, h = 3, w = 3, c = 256, f = 64
		// T (c, 1) (256 / 256)
		for (c265 = c266, c265_p_0 = 0;
			c265 < c266 + 256;
			c265 += 256, c265_p_0 += 256){
			// y = 28, x = 2, h = 3, w = 3, c = 256, f = 64
			// T (f, 1) (64 / 64)
			for (f252 = f253, f252_p_1 = f253_p_0, f252_p_0 = 0;
				f252 < f253 + 64;
				f252 += 64, f252_p_1 += 64, f252_p_0 += 64){
				// y = 28, x = 2, h = 3, w = 3, c = 256, f = 64
				// T (c, 256) (256 / 1)
				for (c264 = c265, c264_p_1 = c265_p_0, c264_p_0 = 0;
					c264 < c265 + 256;
					c264 += 1, c264_p_1 += 1, c264_p_0 += 1){
					// y = 28, x = 2, h = 3, w = 3, c = 1, f = 64
					// T (f, 1) (64 / 64)
					for (f = f252, fp_2 = f252_p_1, fp_1 = f252_p_0, fp_0 = 0;
						f < f252 + 64;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = 28, x = 2, h = 3, w = 3, c = 1, f = 64
						// T (y, 4) (28 / 7)
						for (y = y132, yp_0 = 0;
							y < y132 + 28;
							y += 7, yp_0 += 7){
							// y = 7, x = 2, h = 3, w = 3, c = 1, f = 64
							// T (h, 3) (3 / 1)
							for (h = h132, hp_0 = 0;
								h < h132 + 3;
								h += 1, hp_0 += 1){
								// y = 7, x = 2, h = 1, w = 3, c = 1, f = 64
								// T (w, 3) (3 / 1)
								for (w = w132, wp_0 = 0;
									w < w132 + 3;
									w += 1, wp_0 += 1){
									// y = 7, x = 2, h = 1, w = 1, c = 1, f = 64
									// T (x, 2) (2 / 1)
									for (x = x198, xp_1 = x198_p_0, xp_0 = 0;
										x < x198 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1848 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1849 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1850 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_1851 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_1852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_1855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_1856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_1859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_1860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_1863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_1864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_1867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_1868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_1870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_1871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												mem_vec_1872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_1874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
												mem_vec_1875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
												// y = 7, x = 1, h = 1, w = 1, c = 1, f = 64
												// T (c, 1) (1 / 1)
												for (c = c264, cp_2 = c264_p_1, cp_1 = c264_p_0, cp_0 = 0;
													c < c264 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1848);
													mem_vec_1848 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1849);
													mem_vec_1849 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1850);
													mem_vec_1850 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1851);
													mem_vec_1851 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1852);
													mem_vec_1852 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1853);
													mem_vec_1853 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1854);
													mem_vec_1854 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1855);
													mem_vec_1855 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1856);
													mem_vec_1856 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1857);
													mem_vec_1857 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1858);
													mem_vec_1858 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1859);
													mem_vec_1859 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1860);
													mem_vec_1860 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1861);
													mem_vec_1861 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1862);
													mem_vec_1862 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1863);
													mem_vec_1863 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1864);
													mem_vec_1864 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1865);
													mem_vec_1865 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1866);
													mem_vec_1866 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1867);
													mem_vec_1867 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1868);
													mem_vec_1868 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1869);
													mem_vec_1869 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1870);
													mem_vec_1870 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1871);
													mem_vec_1871 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm512_set1_ps(scal_6);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1872);
													mem_vec_1872 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1873);
													mem_vec_1873 = vec_36;



													vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1874);
													mem_vec_1874 = vec_37;



													vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1875);
													mem_vec_1875 = vec_38;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1848);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1849);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1850);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1851);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1852);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1853);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1854);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1855);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1856);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1857);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1858);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1859);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1860);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1861);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1862);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1863);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1864);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1865);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1866);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1867);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1868);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1869);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1870);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1871);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1872);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1873);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1874);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1875);
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