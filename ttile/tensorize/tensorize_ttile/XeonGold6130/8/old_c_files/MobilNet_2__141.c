#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (32, c); Hoist_vars [c]; T (3, h); T (7, x);
  T (3, w); T (2, c); T (2, f); T (2, x); T (4, y); T (4, x)]
*/
IND_TYPE c, cp_0, c306_p_0, cp_1, c306, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x382_p_0, x383_p_0, xp_1, x382_p_1, xp_2, x382, x383, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y217 = 0;
IND_TYPE x384 = 0;
IND_TYPE h179 = 0;
IND_TYPE w184 = 0;
IND_TYPE c307 = 0;
IND_TYPE f176 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3156 ,mem_vec_3157 ,mem_vec_3158 ,mem_vec_3159 ,mem_vec_3160 ,mem_vec_3161 ,mem_vec_3162 ,mem_vec_3163 ,mem_vec_3164 ,mem_vec_3165 ,mem_vec_3166 ,mem_vec_3167 ,mem_vec_3168 ,mem_vec_3169 ,mem_vec_3170 ,mem_vec_3171 ,mem_vec_3172 ,mem_vec_3173 ,mem_vec_3174 ,mem_vec_3175 ,mem_vec_3176 ,mem_vec_3177 ,mem_vec_3178 ,mem_vec_3179 ,mem_vec_3180 ,mem_vec_3181 ,mem_vec_3182 ,mem_vec_3183 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 4) (56 / 14)
for (x383 = x384, x383_p_0 = 0;
	x383 < x384 + 56;
	x383 += 14, x383_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 64, f = 64
	// T (y, 4) (56 / 14)
	for (y = y217, yp_0 = 0;
		y < y217 + 56;
		y += 14, yp_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 64, f = 64
		// T (x, 2) (14 / 7)
		for (x382 = x383, x382_p_1 = x383_p_0, x382_p_0 = 0;
			x382 < x383 + 14;
			x382 += 7, x382_p_1 += 7, x382_p_0 += 7){
			// y = 14, x = 7, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f176, fp_0 = 0;
				f < f176 + 64;
				f += 32, fp_0 += 32){
				// y = 14, x = 7, h = 3, w = 3, c = 64, f = 32
				// T (c, 2) (64 / 32)
				for (c306 = c307, c306_p_0 = 0;
					c306 < c307 + 64;
					c306 += 32, c306_p_0 += 32){
					// y = 14, x = 7, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w184, wp_0 = 0;
						w < w184 + 3;
						w += 1, wp_0 += 1){
						// y = 14, x = 7, h = 3, w = 1, c = 32, f = 32
						// T (x, 7) (7 / 1)
						for (x = x382, xp_2 = x382_p_1, xp_1 = x382_p_0, xp_0 = 0;
							x < x382 + 7;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 14, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h179, hp_0 = 0;
								h < h179 + 3;
								h += 1, hp_0 += 1){
										mem_vec_3156 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_3157 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_3158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_3159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_3160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_3161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_3162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_3163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_3164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_3165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_3166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_3167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_3168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_3169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_3170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_3171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_3172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_3173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_3174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_3175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_3176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_3177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_3178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_3179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_3180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_3181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_3182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_3183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c306, cp_1 = c306_p_0, cp_0 = 0;
											c < c306 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3156);
											mem_vec_3156 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3157);
											mem_vec_3157 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3158);
											mem_vec_3158 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3159);
											mem_vec_3159 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3160);
											mem_vec_3160 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3161);
											mem_vec_3161 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3162);
											mem_vec_3162 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3163);
											mem_vec_3163 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3164);
											mem_vec_3164 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3165);
											mem_vec_3165 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3166);
											mem_vec_3166 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3167);
											mem_vec_3167 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3168);
											mem_vec_3168 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3169);
											mem_vec_3169 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3170);
											mem_vec_3170 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3171);
											mem_vec_3171 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3172);
											mem_vec_3172 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3173);
											mem_vec_3173 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3174);
											mem_vec_3174 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3175);
											mem_vec_3175 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3176);
											mem_vec_3176 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3177);
											mem_vec_3177 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3178);
											mem_vec_3178 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3179);
											mem_vec_3179 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3180);
											mem_vec_3180 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3181);
											mem_vec_3181 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3182);
											mem_vec_3182 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3183);
											mem_vec_3183 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3156);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3157);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3158);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3159);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3160);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3161);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3162);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3163);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3164);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3165);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3166);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3167);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3168);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3169);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3170);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3171);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3177);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3178);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3179);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3180);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3181);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3182);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3183);
							}
						}
					}
				}
			}
		}
	}
}


}