#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (4, f); T (1, x); T (4, y); T (1, f)]
*/
IND_TYPE c, cp_0, c105_p_0, cp_1, c105, f, fp_0, f105_p_0, fp_1, f105, h, hp_0, w, wp_0, x, xp_0, x99_p_0, xp_1, x99, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y70 = 0;
IND_TYPE x100 = 0;
IND_TYPE h53 = 0;
IND_TYPE w60 = 0;
IND_TYPE c106 = 0;
IND_TYPE f106 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f105 = f106, f105_p_0 = 0;
	f105 < f106 + 128;
	f105 += 128, f105_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 4) (28 / 7)
	for (y = y70, yp_0 = 0;
		y < y70 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (28 / 28)
		for (x99 = x100, x99_p_0 = 0;
			x99 < x100 + 28;
			x99 += 28, x99_p_0 += 28){
			// y = 7, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 4) (128 / 32)
			for (f = f105, fp_1 = f105_p_0, fp_0 = 0;
				f < f105 + 128;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 7, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 8) (128 / 16)
				for (c105 = c106, c105_p_0 = 0;
					c105 < c106 + 128;
					c105 += 16, c105_p_0 += 16){
					// y = 7, x = 28, h = 3, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w60, wp_0 = 0;
						w < w60 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 28, h = 3, w = 1, c = 16, f = 32
						// T (x, 28) (28 / 1)
						for (x = x99, xp_1 = x99_p_0, xp_0 = 0;
							x < x99 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 7, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h53, hp_0 = 0;
								h < h53 + 3;
								h += 1, hp_0 += 1){
										mem_vec_893 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_894 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c105, cp_1 = c105_p_0, cp_0 = 0;
											c < c105 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_893);
											mem_vec_893 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_894);
											mem_vec_894 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_895);
											mem_vec_895 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_896);
											mem_vec_896 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_897);
											mem_vec_897 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_898);
											mem_vec_898 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_899);
											mem_vec_899 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_900);
											mem_vec_900 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_901);
											mem_vec_901 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_902);
											mem_vec_902 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_903);
											mem_vec_903 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_904);
											mem_vec_904 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_905);
											mem_vec_905 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_906);
											mem_vec_906 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_893);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_894);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_895);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_896);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_897);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_898);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_899);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_900);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_901);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_902);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_903);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_904);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_905);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_906);
							}
						}
					}
				}
			}
		}
	}
}


}