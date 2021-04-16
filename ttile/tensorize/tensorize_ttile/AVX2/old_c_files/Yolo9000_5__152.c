#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (2, x); T (8, y); T (2, f); T (1, x); T (1, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c186_p_0, cp_1, c186, f, fp_0, x, xp_0, x310_p_0, x311_p_0, x312_p_0, xp_1, x310_p_1, x311_p_1, xp_2, x310_p_2, xp_3, x310, x311, x312, y, yp_0, y248_p_0, y249_p_0, yp_1, y248_p_1, yp_2, y248, y249;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y250 = 0;
IND_TYPE x313 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c187 = 0;
IND_TYPE f124 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1832 ,mem_vec_1833 ,mem_vec_1834 ,mem_vec_1835 ,mem_vec_1836 ,mem_vec_1837 ,mem_vec_1838 ,mem_vec_1839 ,mem_vec_1840 ,mem_vec_1841 ,mem_vec_1842 ,mem_vec_1843 ,mem_vec_1844 ,mem_vec_1845 ,mem_vec_1846 ,mem_vec_1847 ,mem_vec_1848 ,mem_vec_1849 ,mem_vec_1850 ,mem_vec_1851 ,mem_vec_1852 ,mem_vec_1853 ,mem_vec_1854 ,mem_vec_1855 ,mem_vec_1856 ,mem_vec_1857 ,mem_vec_1858 ,mem_vec_1859 ,mem_vec_1860 ,mem_vec_1861 ,mem_vec_1862 ,mem_vec_1863 ,mem_vec_1864 ,mem_vec_1865 ,mem_vec_1866 ,mem_vec_1867 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y249 = y250, y249_p_0 = 0;
		y249 < y250 + 96;
		y249 += 32, y249_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x312 = x313, x312_p_0 = 0;
			x312 < x313 + 136;
			x312 += 2, x312_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y248 = y249, y248_p_1 = y249_p_0, y248_p_0 = 0;
				y248 < y249 + 32;
				y248 += 32, y248_p_1 += 32, y248_p_0 += 32){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x311 = x312, x311_p_1 = x312_p_0, x311_p_0 = 0;
					x311 < x312 + 2;
					x311 += 2, x311_p_1 += 2, x311_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f124, fp_0 = 0;
						f < f124 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y248, yp_2 = y248_p_1, yp_1 = y248_p_0, yp_0 = 0;
							y < y248 + 32;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x310 = x311, x310_p_2 = x311_p_1, x310_p_1 = x311_p_0, x310_p_0 = 0;
								x310 < x311 + 2;
								x310 += 1, x310_p_2 += 1, x310_p_1 += 1, x310_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c186 = c187, c186_p_0 = 0;
									c186 < c187 + 128;
									c186 += 128, c186_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x310, xp_3 = x310_p_2, xp_2 = x310_p_1, xp_1 = x310_p_0, xp_0 = 0;
										x < x310 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1832 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1833 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1834 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1835 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c186, cp_1 = c186_p_0, cp_0 = 0;
													c < c186 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1832);
													mem_vec_1832 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1833);
													mem_vec_1833 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1834);
													mem_vec_1834 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1835);
													mem_vec_1835 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1836);
													mem_vec_1836 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1837);
													mem_vec_1837 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1838);
													mem_vec_1838 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1839);
													mem_vec_1839 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1840);
													mem_vec_1840 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1841);
													mem_vec_1841 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1842);
													mem_vec_1842 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1843);
													mem_vec_1843 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1844);
													mem_vec_1844 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1845);
													mem_vec_1845 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1846);
													mem_vec_1846 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1847);
													mem_vec_1847 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1832);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1833);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1834);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1835);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1836);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1837);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1838);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1839);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1840);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1841);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1842);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1843);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1844);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1845);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1846);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1847);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y249 = y250 + 96, y249_p_0 = 0;
		y249 < y250 + 96 + 40;
		y249 += 40, y249_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x312 = x313, x312_p_0 = 0;
			x312 < x313 + 136;
			x312 += 2, x312_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y248 = y249, y248_p_1 = y249_p_0, y248_p_0 = 0;
				y248 < y249 + 40;
				y248 += 40, y248_p_1 += 40, y248_p_0 += 40){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x311 = x312, x311_p_1 = x312_p_0, x311_p_0 = 0;
					x311 < x312 + 2;
					x311 += 2, x311_p_1 += 2, x311_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f124, fp_0 = 0;
						f < f124 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y248, yp_2 = y248_p_1, yp_1 = y248_p_0, yp_0 = 0;
							y < y248 + 40;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x310 = x311, x310_p_2 = x311_p_1, x310_p_1 = x311_p_0, x310_p_0 = 0;
								x310 < x311 + 2;
								x310 += 1, x310_p_2 += 1, x310_p_1 += 1, x310_p_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c186 = c187, c186_p_0 = 0;
									c186 < c187 + 128;
									c186 += 128, c186_p_0 += 128){
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (x, 1) (1 / 1)
									for (x = x310, xp_3 = x310_p_2, xp_2 = x310_p_1, xp_1 = x310_p_0, xp_0 = 0;
										x < x310 + 1;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1848 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1849 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1850 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1851 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1852 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1853 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1854 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1855 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1856 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1857 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1858 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1859 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1860 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1861 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_1864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c186, cp_1 = c186_p_0, cp_0 = 0;
													c < c186 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1848);
													mem_vec_1848 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1849);
													mem_vec_1849 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1850);
													mem_vec_1850 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1851);
													mem_vec_1851 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1852);
													mem_vec_1852 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1853);
													mem_vec_1853 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1854);
													mem_vec_1854 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1855);
													mem_vec_1855 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1856);
													mem_vec_1856 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1857);
													mem_vec_1857 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1858);
													mem_vec_1858 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1859);
													mem_vec_1859 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1860);
													mem_vec_1860 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1861);
													mem_vec_1861 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1862);
													mem_vec_1862 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1863);
													mem_vec_1863 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1864);
													mem_vec_1864 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1865);
													mem_vec_1865 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1866);
													mem_vec_1866 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1867);
													mem_vec_1867 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1848);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1849);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1850);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1851);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1852);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1853);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1854);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1855);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1856);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1857);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1858);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1859);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1860);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1861);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1862);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1863);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1864);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1865);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1866);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1867);
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