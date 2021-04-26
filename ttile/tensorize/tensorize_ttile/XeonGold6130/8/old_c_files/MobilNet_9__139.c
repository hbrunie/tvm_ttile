#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (8, c); T (1, y); T (16, f); T (1, c); T (4, c)]
*/
IND_TYPE c, cp_0, c165_p_0, c166_p_0, c167_p_0, cp_1, c165_p_1, c166_p_1, cp_2, c165_p_2, cp_3, c165, c166, c167, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y66 = 0;
IND_TYPE x66 = 0;
IND_TYPE h57 = 0;
IND_TYPE w57 = 0;
IND_TYPE c168 = 0;
IND_TYPE f66 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 4) (1024 / 256)
for (c167 = c168, c167_p_0 = 0;
	c167 < c168 + 1024;
	c167 += 256, c167_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 256, f = 1024
	// T (c, 1) (256 / 256)
	for (c166 = c167, c166_p_1 = c167_p_0, c166_p_0 = 0;
		c166 < c167 + 256;
		c166 += 256, c166_p_1 += 256, c166_p_0 += 256){
		// y = 7, x = 7, h = 3, w = 3, c = 256, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f66, fp_0 = 0;
			f < f66 + 1024;
			f += 64, fp_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 256, f = 64
			// T (y, 1) (7 / 7)
			for (y = y66, yp_0 = 0;
				y < y66 + 7;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 256, f = 64
				// T (c, 8) (256 / 32)
				for (c165 = c166, c165_p_2 = c166_p_1, c165_p_1 = c166_p_0, c165_p_0 = 0;
					c165 < c166 + 256;
					c165 += 32, c165_p_2 += 32, c165_p_1 += 32, c165_p_0 += 32){
					// y = 7, x = 7, h = 3, w = 3, c = 32, f = 64
					// T (x, 7) (7 / 1)
					for (x = x66, xp_0 = 0;
						x < x66 + 7;
						x += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h57, hp_0 = 0;
							h < h57 + 3;
							h += 1, hp_0 += 1){
							// y = 7, x = 1, h = 1, w = 3, c = 32, f = 64
							// T (w, 3) (3 / 1)
							for (w = w57, wp_0 = 0;
								w < w57 + 3;
								w += 1, wp_0 += 1){
										mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c165, cp_3 = c165_p_2, cp_2 = c165_p_1, cp_1 = c165_p_0, cp_0 = 0;
											c < c165 + 32;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_924);
											mem_vec_924 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_925);
											mem_vec_925 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_926);
											mem_vec_926 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_927);
											mem_vec_927 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_928);
											mem_vec_928 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_929);
											mem_vec_929 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_930);
											mem_vec_930 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_931);
											mem_vec_931 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_932);
											mem_vec_932 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_933);
											mem_vec_933 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_934);
											mem_vec_934 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_935);
											mem_vec_935 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_936);
											mem_vec_936 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_937);
											mem_vec_937 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_938);
											mem_vec_938 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_939);
											mem_vec_939 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_940);
											mem_vec_940 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_941);
											mem_vec_941 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_942);
											mem_vec_942 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_943);
											mem_vec_943 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_944);
											mem_vec_944 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_945);
											mem_vec_945 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_946);
											mem_vec_946 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_947);
											mem_vec_947 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_948);
											mem_vec_948 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_949);
											mem_vec_949 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_950);
											mem_vec_950 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_951);
											mem_vec_951 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_924);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_925);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_926);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_927);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_928);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_929);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_930);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_931);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_932);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_933);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_934);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_935);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_936);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_937);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_938);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_939);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_940);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_941);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_942);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_943);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_944);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_945);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_946);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_947);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_948);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_949);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_950);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_951);
							}
						}
					}
				}
			}
		}
	}
}


}