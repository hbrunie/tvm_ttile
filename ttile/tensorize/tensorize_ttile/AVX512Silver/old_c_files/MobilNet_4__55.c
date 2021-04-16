#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (1, f); T (1, x); T (4, y); T (4, f)]
*/
IND_TYPE c, cp_0, c111_p_0, cp_1, c111, f, fp_0, f111_p_0, fp_1, f111, h, hp_0, w, wp_0, x, xp_0, x105_p_0, xp_1, x105, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y74 = 0;
IND_TYPE x106 = 0;
IND_TYPE h57 = 0;
IND_TYPE w64 = 0;
IND_TYPE c112 = 0;
IND_TYPE f112 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 4) (128 / 32)
for (f111 = f112, f111_p_0 = 0;
	f111 < f112 + 128;
	f111 += 32, f111_p_0 += 32){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 32
	// T (y, 4) (28 / 7)
	for (y = y74, yp_0 = 0;
		y < y74 + 28;
		y += 7, yp_0 += 7){
		// y = 7, x = 28, h = 3, w = 3, c = 128, f = 32
		// T (x, 1) (28 / 28)
		for (x105 = x106, x105_p_0 = 0;
			x105 < x106 + 28;
			x105 += 28, x105_p_0 += 28){
			// y = 7, x = 28, h = 3, w = 3, c = 128, f = 32
			// T (f, 1) (32 / 32)
			for (f = f111, fp_1 = f111_p_0, fp_0 = 0;
				f < f111 + 32;
				f += 32, fp_1 += 32, fp_0 += 32){
				// y = 7, x = 28, h = 3, w = 3, c = 128, f = 32
				// T (c, 8) (128 / 16)
				for (c111 = c112, c111_p_0 = 0;
					c111 < c112 + 128;
					c111 += 16, c111_p_0 += 16){
					// y = 7, x = 28, h = 3, w = 3, c = 16, f = 32
					// T (w, 3) (3 / 1)
					for (w = w64, wp_0 = 0;
						w < w64 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 28, h = 3, w = 1, c = 16, f = 32
						// T (x, 28) (28 / 1)
						for (x = x105, xp_1 = x105_p_0, xp_0 = 0;
							x < x105 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 7, x = 1, h = 3, w = 1, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h57, hp_0 = 0;
								h < h57 + 3;
								h += 1, hp_0 += 1){
										mem_vec_921 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										// y = 7, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c111, cp_1 = c111_p_0, cp_0 = 0;
											c < c111 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_921);
											mem_vec_921 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_922);
											mem_vec_922 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_923);
											mem_vec_923 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_924);
											mem_vec_924 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_925);
											mem_vec_925 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_926);
											mem_vec_926 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_927);
											mem_vec_927 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_928);
											mem_vec_928 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_929);
											mem_vec_929 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_930);
											mem_vec_930 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_931);
											mem_vec_931 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_932);
											mem_vec_932 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_933);
											mem_vec_933 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_934);
											mem_vec_934 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_921);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_922);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_923);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_924);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_925);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_926);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_927);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_928);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_929);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_930);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_931);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_932);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_933);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_934);
							}
						}
					}
				}
			}
		}
	}
}


}