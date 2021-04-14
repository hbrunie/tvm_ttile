#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (1, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, f); T (256, c); T (2, x); T (2, y); T (2, f)]
*/
IND_TYPE c, cp_0, c312_p_0, cp_1, c312, f, fp_0, f312_p_0, fp_1, f312, h, hp_0, w, wp_0, x, xp_0, x312_p_0, xp_1, x312, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y208 = 0;
IND_TYPE x313 = 0;
IND_TYPE h208 = 0;
IND_TYPE w208 = 0;
IND_TYPE c313 = 0;
IND_TYPE f313 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2912 ,mem_vec_2913 ,mem_vec_2914 ,mem_vec_2915 ,mem_vec_2916 ,mem_vec_2917 ,mem_vec_2918 ,mem_vec_2919 ,mem_vec_2920 ,mem_vec_2921 ,mem_vec_2922 ,mem_vec_2923 ,mem_vec_2924 ,mem_vec_2925 ,mem_vec_2926 ,mem_vec_2927 ,mem_vec_2928 ,mem_vec_2929 ,mem_vec_2930 ,mem_vec_2931 ,mem_vec_2932 ,mem_vec_2933 ,mem_vec_2934 ,mem_vec_2935 ,mem_vec_2936 ,mem_vec_2937 ,mem_vec_2938 ,mem_vec_2939 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f312 = f313, f312_p_0 = 0;
	f312 < f313 + 256;
	f312 += 128, f312_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 128
	// T (y, 2) (14 / 7)
	for (y = y208, yp_0 = 0;
		y < y208 + 14;
		y += 7, yp_0 += 7){
		// y = 7, x = 14, h = 3, w = 3, c = 256, f = 128
		// T (x, 2) (14 / 7)
		for (x312 = x313, x312_p_0 = 0;
			x312 < x313 + 14;
			x312 += 7, x312_p_0 += 7){
			// y = 7, x = 7, h = 3, w = 3, c = 256, f = 128
			// T (c, 256) (256 / 1)
			for (c312 = c313, c312_p_0 = 0;
				c312 < c313 + 256;
				c312 += 1, c312_p_0 += 1){
				// y = 7, x = 7, h = 3, w = 3, c = 1, f = 128
				// T (f, 2) (128 / 64)
				for (f = f312, fp_1 = f312_p_0, fp_0 = 0;
					f < f312 + 128;
					f += 64, fp_1 += 64, fp_0 += 64){
					// y = 7, x = 7, h = 3, w = 3, c = 1, f = 64
					// T (h, 3) (3 / 1)
					for (h = h208, hp_0 = 0;
						h < h208 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 7, h = 1, w = 3, c = 1, f = 64
						// T (w, 3) (3 / 1)
						for (w = w208, wp_0 = 0;
							w < w208 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 1, w = 1, c = 1, f = 64
							// T (x, 7) (7 / 1)
							for (x = x312, xp_1 = x312_p_0, xp_0 = 0;
								x < x312 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2912 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2913 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2914 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2915 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_2916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_2920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_2924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_2928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_2931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_2932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_2935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_2936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_2939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 1, f = 64
										// T (c, 1) (1 / 1)
										for (c = c312, cp_1 = c312_p_0, cp_0 = 0;
											c < c312 + 1;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2912);
											mem_vec_2912 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2913);
											mem_vec_2913 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2914);
											mem_vec_2914 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2915);
											mem_vec_2915 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2916);
											mem_vec_2916 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2917);
											mem_vec_2917 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2918);
											mem_vec_2918 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2919);
											mem_vec_2919 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2920);
											mem_vec_2920 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2921);
											mem_vec_2921 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2922);
											mem_vec_2922 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2923);
											mem_vec_2923 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2924);
											mem_vec_2924 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2925);
											mem_vec_2925 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2926);
											mem_vec_2926 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2927);
											mem_vec_2927 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2928);
											mem_vec_2928 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2929);
											mem_vec_2929 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2930);
											mem_vec_2930 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2931);
											mem_vec_2931 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2932);
											mem_vec_2932 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2933);
											mem_vec_2933 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2934);
											mem_vec_2934 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2935);
											mem_vec_2935 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2936);
											mem_vec_2936 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2937);
											mem_vec_2937 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2938);
											mem_vec_2938 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2939);
											mem_vec_2939 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2912);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2913);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2914);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2915);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2916);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2917);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2918);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2919);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2920);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2921);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2922);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2923);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2924);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2925);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2926);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2927);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2928);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2929);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2930);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2931);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2932);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2933);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2934);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2935);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2936);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2937);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2938);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2939);
							}
						}
					}
				}
			}
		}
	}
}


}