#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (128, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (2, f); T (2, c); T (7, x); T (1, y); T (4, f)]
*/
IND_TYPE c, cp_0, c90_p_0, cp_1, c90, f, fp_0, f90_p_0, fp_1, f90, h, hp_0, w, wp_0, x, xp_0, x90_p_0, xp_1, x90, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y60 = 0;
IND_TYPE x91 = 0;
IND_TYPE h60 = 0;
IND_TYPE w60 = 0;
IND_TYPE c91 = 0;
IND_TYPE f91 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 4) (256 / 64)
for (f90 = f91, f90_p_0 = 0;
	f90 < f91 + 256;
	f90 += 64, f90_p_0 += 64){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 64
	// T (y, 1) (14 / 14)
	for (y = y60, yp_0 = 0;
		y < y60 + 14;
		y += 14, yp_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 64
		// T (x, 7) (14 / 2)
		for (x90 = x91, x90_p_0 = 0;
			x90 < x91 + 14;
			x90 += 2, x90_p_0 += 2){
			// y = 14, x = 2, h = 3, w = 3, c = 256, f = 64
			// T (c, 2) (256 / 128)
			for (c90 = c91, c90_p_0 = 0;
				c90 < c91 + 256;
				c90 += 128, c90_p_0 += 128){
				// y = 14, x = 2, h = 3, w = 3, c = 128, f = 64
				// T (f, 2) (64 / 32)
				for (f = f90, fp_1 = f90_p_0, fp_0 = 0;
					f < f90 + 64;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 14, x = 2, h = 3, w = 3, c = 128, f = 32
					// T (h, 3) (3 / 1)
					for (h = h60, hp_0 = 0;
						h < h60 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 2, h = 1, w = 3, c = 128, f = 32
						// T (w, 3) (3 / 1)
						for (w = w60, wp_0 = 0;
							w < w60 + 3;
							w += 1, wp_0 += 1){
							// y = 14, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 2) (2 / 1)
							for (x = x90, xp_1 = x90_p_0, xp_0 = 0;
								x < x90 + 2;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 128, f = 32
										// T (c, 128) (128 / 1)
										for (c = c90, cp_1 = c90_p_0, cp_0 = 0;
											c < c90 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_840);
											mem_vec_840 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_841);
											mem_vec_841 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_842);
											mem_vec_842 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_843);
											mem_vec_843 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_844);
											mem_vec_844 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_845);
											mem_vec_845 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_846);
											mem_vec_846 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_847);
											mem_vec_847 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_848);
											mem_vec_848 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_849);
											mem_vec_849 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_850);
											mem_vec_850 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_851);
											mem_vec_851 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_852);
											mem_vec_852 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_853);
											mem_vec_853 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_854);
											mem_vec_854 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_855);
											mem_vec_855 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_856);
											mem_vec_856 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_857);
											mem_vec_857 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_858);
											mem_vec_858 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_859);
											mem_vec_859 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_860);
											mem_vec_860 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_861);
											mem_vec_861 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_862);
											mem_vec_862 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_863);
											mem_vec_863 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_864);
											mem_vec_864 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_865);
											mem_vec_865 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_866);
											mem_vec_866 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_867);
											mem_vec_867 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_841);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_842);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_851);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_852);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_853);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_854);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_855);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_856);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_857);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_858);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_859);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_860);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_861);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_862);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_863);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_864);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_865);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_866);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_867);
							}
						}
					}
				}
			}
		}
	}
}


}