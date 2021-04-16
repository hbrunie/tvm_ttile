#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (4, f); T (1, x); T (7, y); T (2, x)]
*/
IND_TYPE c, cp_0, c126_p_0, cp_1, c126, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x144_p_0, x145_p_0, xp_1, x144_p_1, xp_2, x144, x145, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y106 = 0;
IND_TYPE x146 = 0;
IND_TYPE h67 = 0;
IND_TYPE w63 = 0;
IND_TYPE c127 = 0;
IND_TYPE f78 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 2) (56 / 28)
for (x145 = x146, x145_p_0 = 0;
	x145 < x146 + 56;
	x145 += 28, x145_p_0 += 28){
	// y = 56, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 7) (56 / 8)
	for (y = y106, yp_0 = 0;
		y < y106 + 56;
		y += 8, yp_0 += 8){
		// y = 8, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (28 / 28)
		for (x144 = x145, x144_p_1 = x145_p_0, x144_p_0 = 0;
			x144 < x145 + 28;
			x144 += 28, x144_p_1 += 28, x144_p_0 += 28){
			// y = 8, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 4) (128 / 32)
			for (f = f78, fp_0 = 0;
				f < f78 + 128;
				f += 32, fp_0 += 32){
				// y = 8, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 8) (128 / 16)
				for (c126 = c127, c126_p_0 = 0;
					c126 < c127 + 128;
					c126 += 16, c126_p_0 += 16){
					// y = 8, x = 28, h = 3, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w63, wp_0 = 0;
						w < w63 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 28, h = 3, w = 1, c = 16, f = 32
						// T (x, 28) (28 / 1)
						for (x = x144, xp_2 = x144_p_1, xp_1 = x144_p_0, xp_0 = 0;
							x < x144 + 28;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 8, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h67, hp_0 = 0;
								h < h67 + 3;
								h += 1, hp_0 += 1){
										mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c126, cp_1 = c126_p_0, cp_0 = 0;
											c < c126 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_856);
											mem_vec_856 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_857);
											mem_vec_857 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_858);
											mem_vec_858 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_859);
											mem_vec_859 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_860);
											mem_vec_860 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_861);
											mem_vec_861 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_862);
											mem_vec_862 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_863);
											mem_vec_863 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_864);
											mem_vec_864 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_865);
											mem_vec_865 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_866);
											mem_vec_866 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_867);
											mem_vec_867 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_868);
											mem_vec_868 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_869);
											mem_vec_869 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_870);
											mem_vec_870 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_871);
											mem_vec_871 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_867);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_868);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_869);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_870);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_871);
							}
						}
					}
				}
			}
		}
	}
}


}