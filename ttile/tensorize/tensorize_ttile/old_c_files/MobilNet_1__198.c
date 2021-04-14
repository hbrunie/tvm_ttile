#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (7, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 8), (Arg 11))]; T (8, c);
  T (2, x)]
*/
IND_TYPE c, cp_0, c240_p_0, cp_1, c240, h, hp_0, w, wp_0, x, xp_0, x320_p_0, x321_p_0, xp_1, x320_p_1, xp_2, x320, x321, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y160 = 0;
IND_TYPE x322 = 0;
IND_TYPE h140 = 0;
IND_TYPE w160 = 0;
IND_TYPE c241 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1844 ,mem_vec_1845 ,mem_vec_1846 ,mem_vec_1847 ,mem_vec_1848 ,mem_vec_1849 ,mem_vec_1850 ,mem_vec_1851 ,mem_vec_1852 ,mem_vec_1853 ,mem_vec_1854 ,mem_vec_1855 ,mem_vec_1856 ,mem_vec_1857 ,mem_vec_1858 ,mem_vec_1859 ,mem_vec_1860 ,mem_vec_1861 ,mem_vec_1862 ,mem_vec_1863 ,mem_vec_1864 ,mem_vec_1865 ,mem_vec_1866 ,mem_vec_1867 ,mem_vec_1868 ,mem_vec_1869 ,mem_vec_1870 ,mem_vec_1871 ,mem_vec_1872 ,mem_vec_1873 ,mem_vec_1874 ,mem_vec_1875 ,mem_vec_1876 ,mem_vec_1877 ,mem_vec_1878 ,mem_vec_1879 ,mem_vec_1880 ,mem_vec_1881 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 2) (112 / 56)
for (x321 = x322, x321_p_0 = 0;
	x321 < x322 + 112;
	x321 += 56, x321_p_0 += 56){
	// y = 112, x = 56, h = 3, w = 3, c = 32, f = 32
	// T (c, 8) (32 / 4)
	for (c240 = c241, c240_p_0 = 0;
		c240 < c241 + 32;
		c240 += 4, c240_p_0 += 4){
			for (y = y160, yp_0 = 0;
				y < y160 + 24;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 56, h = 3, w = 3, c = 4, f = 32
				// T (x, 7) (56 / 8)
				for (x320 = x321, x320_p_1 = x321_p_0, x320_p_0 = 0;
					x320 < x321 + 56;
					x320 += 8, x320_p_1 += 8, x320_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h140, hp_0 = 0;
						h < h140 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w160, wp_0 = 0;
							w < w160 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 4, f = 32
							// T (x, 8) (8 / 1)
							for (x = x320, xp_2 = x320_p_1, xp_1 = x320_p_0, xp_0 = 0;
								x < x320 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1845 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c240, cp_1 = c240_p_0, cp_0 = 0;
											c < c240 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1844);
											mem_vec_1844 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1845);
											mem_vec_1845 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1846);
											mem_vec_1846 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1847);
											mem_vec_1847 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1848);
											mem_vec_1848 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1849);
											mem_vec_1849 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1850);
											mem_vec_1850 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1851);
											mem_vec_1851 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1852);
											mem_vec_1852 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1853);
											mem_vec_1853 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1854);
											mem_vec_1854 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1855);
											mem_vec_1855 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1856);
											mem_vec_1856 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1857);
											mem_vec_1857 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1858);
											mem_vec_1858 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1859);
											mem_vec_1859 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1859);
							}
						}
					}
				}
			}
			for (y = y160 + 24, yp_0 = 0;
				y < y160 + 24 + 88;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 56, h = 3, w = 3, c = 4, f = 32
				// T (x, 7) (56 / 8)
				for (x320 = x321, x320_p_1 = x321_p_0, x320_p_0 = 0;
					x320 < x321 + 56;
					x320 += 8, x320_p_1 += 8, x320_p_0 += 8){
					// y = ph_y, x = 8, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h140, hp_0 = 0;
						h < h140 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 8, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w160, wp_0 = 0;
							w < w160 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 8, h = 1, w = 1, c = 4, f = 32
							// T (x, 8) (8 / 1)
							for (x = x320, xp_2 = x320_p_1, xp_1 = x320_p_0, xp_0 = 0;
								x < x320 + 8;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1860 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1861 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_1876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_1877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_1878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_1879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_1880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_1881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c240, cp_1 = c240_p_0, cp_0 = 0;
											c < c240 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1860);
											mem_vec_1860 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1861);
											mem_vec_1861 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1862);
											mem_vec_1862 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1863);
											mem_vec_1863 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1864);
											mem_vec_1864 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1865);
											mem_vec_1865 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1866);
											mem_vec_1866 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1867);
											mem_vec_1867 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1868);
											mem_vec_1868 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1869);
											mem_vec_1869 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1870);
											mem_vec_1870 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1871);
											mem_vec_1871 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1872);
											mem_vec_1872 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1873);
											mem_vec_1873 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1874);
											mem_vec_1874 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1875);
											mem_vec_1875 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1876);
											mem_vec_1876 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1877);
											mem_vec_1877 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1878);
											mem_vec_1878 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1879);
											mem_vec_1879 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1880);
											mem_vec_1880 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1881);
											mem_vec_1881 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1867);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1869);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1871);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1872);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1873);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1874);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1875);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1876);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1877);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1878);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1879);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1880);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1881);
							}
						}
					}
				}
			}
	}
}


}