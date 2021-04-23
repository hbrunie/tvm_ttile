#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (3, c); Hoist_vars [c]; T (1, x); T (1, c);
  T (3, w); T (3, h); T (17, y); T (544, x); T (1, x); T (4, y)]
*/
IND_TYPE c, cp_0, c93_p_0, cp_1, c93, h, hp_0, w, wp_0, x, xp_0, x172_p_0, x173_p_0, xp_1, x172_p_1, xp_2, x172, x173, y, yp_0, y165_p_0, yp_1, y165;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y166 = 0;
IND_TYPE x174 = 0;
IND_TYPE h50 = 0;
IND_TYPE w86 = 0;
IND_TYPE c94 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 4) (544 / 136)
for (y165 = y166, y165_p_0 = 0;
	y165 < y166 + 544;
	y165 += 136, y165_p_0 += 136){
	// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (x, 1) (544 / 544)
	for (x173 = x174, x173_p_0 = 0;
		x173 < x174 + 544;
		x173 += 544, x173_p_0 += 544){
		// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 544) (544 / 1)
		for (x172 = x173, x172_p_1 = x173_p_0, x172_p_0 = 0;
			x172 < x173 + 544;
			x172 += 1, x172_p_1 += 1, x172_p_0 += 1){
			// y = 136, x = 1, h = 3, w = 3, c = 3, f = 32
			// T (y, 17) (136 / 8)
			for (y = y165, yp_1 = y165_p_0, yp_0 = 0;
				y < y165 + 136;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 1, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h50, hp_0 = 0;
					h < h50 + 3;
					h += 1, hp_0 += 1){
					// y = 8, x = 1, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w86, wp_0 = 0;
						w < w86 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c93 = c94, c93_p_0 = 0;
							c93 < c94 + 3;
							c93 += 3, c93_p_0 += 3){
							// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
							// T (x, 1) (1 / 1)
							for (x = x172, xp_2 = x172_p_1, xp_1 = x172_p_0, xp_0 = 0;
								x < x172 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c93, cp_1 = c93_p_0, cp_0 = 0;
											c < c93 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_922);
											mem_vec_922 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_923);
											mem_vec_923 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_924);
											mem_vec_924 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_925);
											mem_vec_925 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_926);
											mem_vec_926 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_927);
											mem_vec_927 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_928);
											mem_vec_928 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_929);
											mem_vec_929 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_930);
											mem_vec_930 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_931);
											mem_vec_931 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_932);
											mem_vec_932 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_933);
											mem_vec_933 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_934);
											mem_vec_934 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_935);
											mem_vec_935 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_936);
											mem_vec_936 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_937);
											mem_vec_937 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_922);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_923);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_924);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_925);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_926);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_927);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_928);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_929);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_930);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_931);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_932);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_933);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_934);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_935);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_936);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_937);
							}
						}
					}
				}
			}
		}
	}
}


}