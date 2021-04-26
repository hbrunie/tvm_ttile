#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (32, c); Hoist_vars [c]; T (3, h); T (7, x);
  T (3, w); T (2, c); T (2, f); T (1, x); T (4, y); T (8, x)]
*/
IND_TYPE c, cp_0, c315_p_0, cp_1, c315, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x394_p_0, x395_p_0, xp_1, x394_p_1, xp_2, x394, x395, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y223 = 0;
IND_TYPE x396 = 0;
IND_TYPE h185 = 0;
IND_TYPE w190 = 0;
IND_TYPE c316 = 0;
IND_TYPE f182 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3240 ,mem_vec_3241 ,mem_vec_3242 ,mem_vec_3243 ,mem_vec_3244 ,mem_vec_3245 ,mem_vec_3246 ,mem_vec_3247 ,mem_vec_3248 ,mem_vec_3249 ,mem_vec_3250 ,mem_vec_3251 ,mem_vec_3252 ,mem_vec_3253 ,mem_vec_3254 ,mem_vec_3255 ,mem_vec_3256 ,mem_vec_3257 ,mem_vec_3258 ,mem_vec_3259 ,mem_vec_3260 ,mem_vec_3261 ,mem_vec_3262 ,mem_vec_3263 ,mem_vec_3264 ,mem_vec_3265 ,mem_vec_3266 ,mem_vec_3267 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 8) (56 / 7)
for (x395 = x396, x395_p_0 = 0;
	x395 < x396 + 56;
	x395 += 7, x395_p_0 += 7){
	// y = 56, x = 7, h = 3, w = 3, c = 64, f = 64
	// T (y, 4) (56 / 14)
	for (y = y223, yp_0 = 0;
		y < y223 + 56;
		y += 14, yp_0 += 14){
		// y = 14, x = 7, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (7 / 7)
		for (x394 = x395, x394_p_1 = x395_p_0, x394_p_0 = 0;
			x394 < x395 + 7;
			x394 += 7, x394_p_1 += 7, x394_p_0 += 7){
			// y = 14, x = 7, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f182, fp_0 = 0;
				f < f182 + 64;
				f += 32, fp_0 += 32){
				// y = 14, x = 7, h = 3, w = 3, c = 64, f = 32
				// T (c, 2) (64 / 32)
				for (c315 = c316, c315_p_0 = 0;
					c315 < c316 + 64;
					c315 += 32, c315_p_0 += 32){
					// y = 14, x = 7, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w190, wp_0 = 0;
						w < w190 + 3;
						w += 1, wp_0 += 1){
						// y = 14, x = 7, h = 3, w = 1, c = 32, f = 32
						// T (x, 7) (7 / 1)
						for (x = x394, xp_2 = x394_p_1, xp_1 = x394_p_0, xp_0 = 0;
							x < x394 + 7;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 14, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h185, hp_0 = 0;
								h < h185 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3240 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3241 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_3260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_3262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_3264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_3265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_3266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_3267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c315, cp_1 = c315_p_0, cp_0 = 0;
											c < c315 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3240);
											mem_vec_3240 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3241);
											mem_vec_3241 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3242);
											mem_vec_3242 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3243);
											mem_vec_3243 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3244);
											mem_vec_3244 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3245);
											mem_vec_3245 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3246);
											mem_vec_3246 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3247);
											mem_vec_3247 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3248);
											mem_vec_3248 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3249);
											mem_vec_3249 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3250);
											mem_vec_3250 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3251);
											mem_vec_3251 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3252);
											mem_vec_3252 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3253);
											mem_vec_3253 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3254);
											mem_vec_3254 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3255);
											mem_vec_3255 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3256);
											mem_vec_3256 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3257);
											mem_vec_3257 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3258);
											mem_vec_3258 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3259);
											mem_vec_3259 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3260);
											mem_vec_3260 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3261);
											mem_vec_3261 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3262);
											mem_vec_3262 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3263);
											mem_vec_3263 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3264);
											mem_vec_3264 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3265);
											mem_vec_3265 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3266);
											mem_vec_3266 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3267);
											mem_vec_3267 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3240);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3241);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3242);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3243);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3244);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3251);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3259);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3261);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3262);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3263);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3264);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3265);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3266);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3267);
							}
						}
					}
				}
			}
		}
	}
}


}