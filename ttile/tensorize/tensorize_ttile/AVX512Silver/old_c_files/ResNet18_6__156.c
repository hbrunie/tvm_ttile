#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (4, c); T (4, f); T (1, x); T (4, y); T (1, f)]
*/
IND_TYPE c, cp_0, c96_p_0, cp_1, c96, f, fp_0, f96_p_0, fp_1, f96, h, hp_0, w, wp_0, x, xp_0, x90_p_0, xp_1, x90, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y64 = 0;
IND_TYPE x91 = 0;
IND_TYPE h47 = 0;
IND_TYPE w54 = 0;
IND_TYPE c97 = 0;
IND_TYPE f97 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f96 = f97, f96_p_0 = 0;
	f96 < f97 + 128;
	f96 += 128, f96_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 4) (28 / 7)
	for (y = y64, yp_0 = 0;
		y < y64 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (28 / 28)
		for (x90 = x91, x90_p_0 = 0;
			x90 < x91 + 28;
			x90 += 28, x90_p_0 += 28){
			// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 4) (128 / 32)
			for (f = f96, fp_1 = f96_p_0, fp_0 = 0;
				f < f96 + 128;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 7, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 4) (128 / 32)
				for (c96 = c97, c96_p_0 = 0;
					c96 < c97 + 128;
					c96 += 32, c96_p_0 += 32){
					// y = 7, x = 28, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w54, wp_0 = 0;
						w < w54 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 28, h = 3, w = 1, c = 32, f = 32
						// T (x, 28) (28 / 1)
						for (x = x90, xp_1 = x90_p_0, xp_0 = 0;
							x < x90 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 7, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h47, hp_0 = 0;
								h < h47 + 3;
								h += 1, hp_0 += 1){
										mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c96, cp_1 = c96_p_0, cp_0 = 0;
											c < c96 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_851);
											mem_vec_851 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_852);
											mem_vec_852 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_853);
											mem_vec_853 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_854);
											mem_vec_854 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_855);
											mem_vec_855 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_856);
											mem_vec_856 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_857);
											mem_vec_857 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_858);
											mem_vec_858 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_859);
											mem_vec_859 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_860);
											mem_vec_860 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_861);
											mem_vec_861 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_862);
											mem_vec_862 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_863);
											mem_vec_863 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_864);
											mem_vec_864 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_864);
							}
						}
					}
				}
			}
		}
	}
}


}