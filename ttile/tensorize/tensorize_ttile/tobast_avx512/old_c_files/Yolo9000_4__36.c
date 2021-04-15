#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (4, y); U (3, w); T (8, c); Hoist_vars [c]; T (68, x);
  T (3, h); T (34, y); T (2, f); T (8, c); T (1, f); T (2, x); T (4, f)]
*/
IND_TYPE c, cp_0, c162_p_0, cp_1, c162, f, fp_0, f116_p_0, f117_p_0, fp_1, f116_p_1, fp_2, f116, f117, h, hp_0, x, xp_0, x210_p_0, xp_1, x210, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y108 = 0;
IND_TYPE x211 = 0;
IND_TYPE h84 = 0;
IND_TYPE w = 0;
IND_TYPE c163 = 0;
IND_TYPE f118 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_752 ,mem_vec_753 ,mem_vec_754 ,mem_vec_755 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (f, 4) (128 / 32)
for (f117 = f118, f117_p_0 = 0;
	f117 < f118 + 128;
	f117 += 32, f117_p_0 += 32){
	// y = 136, x = 136, h = 3, w = 3, c = 64, f = 32
	// T (x, 2) (136 / 68)
	for (x210 = x211, x210_p_0 = 0;
		x210 < x211 + 136;
		x210 += 68, x210_p_0 += 68){
		// y = 136, x = 68, h = 3, w = 3, c = 64, f = 32
		// T (f, 1) (32 / 32)
		for (f116 = f117, f116_p_1 = f117_p_0, f116_p_0 = 0;
			f116 < f117 + 32;
			f116 += 32, f116_p_1 += 32, f116_p_0 += 32){
			// y = 136, x = 68, h = 3, w = 3, c = 64, f = 32
			// T (c, 8) (64 / 8)
			for (c162 = c163, c162_p_0 = 0;
				c162 < c163 + 64;
				c162 += 8, c162_p_0 += 8){
				// y = 136, x = 68, h = 3, w = 3, c = 8, f = 32
				// T (f, 2) (32 / 16)
				for (f = f116, fp_2 = f116_p_1, fp_1 = f116_p_0, fp_0 = 0;
					f < f116 + 32;
					f += 16, fp_2 += 16, fp_1 += 16, fp_0 += 16){
					// y = 136, x = 68, h = 3, w = 3, c = 8, f = 16
					// T (y, 34) (136 / 4)
					for (y = y108, yp_0 = 0;
						y < y108 + 136;
						y += 4, yp_0 += 4){
						// y = 4, x = 68, h = 3, w = 3, c = 8, f = 16
						// T (h, 3) (3 / 1)
						for (h = h84, hp_0 = 0;
							h < h84 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 68, h = 1, w = 3, c = 8, f = 16
							// T (x, 68) (68 / 1)
							for (x = x210, xp_1 = x210_p_0, xp_0 = 0;
								x < x210 + 68;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_752 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										// y = 4, x = 1, h = 1, w = 3, c = 8, f = 16
										// T (c, 8) (8 / 1)
										for (c = c162, cp_1 = c162_p_0, cp_0 = 0;
											c < c162 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_752);
											mem_vec_752 = vec_0;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_4 = _mm512_set1_ps(scal_1);


											vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_753);
											mem_vec_753 = vec_3;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_6 = _mm512_set1_ps(scal_2);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_754);
											mem_vec_754 = vec_5;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_8 = _mm512_set1_ps(scal_3);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_755);
											mem_vec_755 = vec_7;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_10 = _mm512_set1_ps(scal_4);
											vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_752);
											mem_vec_752 = vec_9;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_13 = _mm512_set1_ps(scal_5);


											vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_753);
											mem_vec_753 = vec_12;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_6);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_754);
											mem_vec_754 = vec_14;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_17 = _mm512_set1_ps(scal_7);


											vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_755);
											mem_vec_755 = vec_16;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_19 = _mm512_set1_ps(scal_8);
											vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_752);
											mem_vec_752 = vec_18;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_22 = _mm512_set1_ps(scal_9);


											vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_753);
											mem_vec_753 = vec_21;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_24 = _mm512_set1_ps(scal_10);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_754);
											mem_vec_754 = vec_23;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_26 = _mm512_set1_ps(scal_11);


											vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_755);
											mem_vec_755 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_752);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_753);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_754);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_755);
							}
						}
					}
				}
			}
		}
	}
}


}