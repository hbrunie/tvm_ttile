#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (2, c); T (4, f); T (1, x); T (17, y); T (4, x)]
*/
IND_TYPE c, cp_0, c78_p_0, cp_1, c78, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x104_p_0, x105_p_0, xp_1, x104_p_1, xp_2, x104, x105, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y52 = 0;
IND_TYPE x106 = 0;
IND_TYPE h52 = 0;
IND_TYPE w52 = 0;
IND_TYPE c79 = 0;
IND_TYPE f52 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_1172 ,mem_vec_1173 ,mem_vec_1174 ,mem_vec_1175 ,mem_vec_1176 ,mem_vec_1177 ,mem_vec_1178 ,mem_vec_1179 ,mem_vec_1180 ,mem_vec_1181 ,mem_vec_1182 ,mem_vec_1183 ,mem_vec_1184 ,mem_vec_1185 ,mem_vec_1186 ,mem_vec_1187 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 4) (136 / 34)
for (x105 = x106, x105_p_0 = 0;
	x105 < x106 + 136;
	x105 += 34, x105_p_0 += 34){
	// y = 136, x = 34, h = 3, w = 3, c = 64, f = 128
	// T (y, 17) (136 / 8)
	for (y = y52, yp_0 = 0;
		y < y52 + 136;
		y += 8, yp_0 += 8){
		// y = 8, x = 34, h = 3, w = 3, c = 64, f = 128
		// T (x, 1) (34 / 34)
		for (x104 = x105, x104_p_1 = x105_p_0, x104_p_0 = 0;
			x104 < x105 + 34;
			x104 += 34, x104_p_1 += 34, x104_p_0 += 34){
			// y = 8, x = 34, h = 3, w = 3, c = 64, f = 128
			// T (f, 4) (128 / 32)
			for (f = f52, fp_0 = 0;
				f < f52 + 128;
				f += 32, fp_0 += 32){
				// y = 8, x = 34, h = 3, w = 3, c = 64, f = 32
				// T (c, 2) (64 / 32)
				for (c78 = c79, c78_p_0 = 0;
					c78 < c79 + 64;
					c78 += 32, c78_p_0 += 32){
					// y = 8, x = 34, h = 3, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w52, wp_0 = 0;
						w < w52 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 34, h = 3, w = 1, c = 32, f = 32
						// T (x, 34) (34 / 1)
						for (x = x104, xp_2 = x104_p_1, xp_1 = x104_p_0, xp_0 = 0;
							x < x104 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
							// y = 8, x = 1, h = 3, w = 1, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h52, hp_0 = 0;
								h < h52 + 3;
								h += 1, hp_0 += 1){
										mem_vec_1172 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1173 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
										// T (c, 32) (32 / 1)
										for (c = c78, cp_1 = c78_p_0, cp_0 = 0;
											c < c78 + 32;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1172);
											mem_vec_1172 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1173);
											mem_vec_1173 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1174);
											mem_vec_1174 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1175);
											mem_vec_1175 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1176);
											mem_vec_1176 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1177);
											mem_vec_1177 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1178);
											mem_vec_1178 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1179);
											mem_vec_1179 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1180);
											mem_vec_1180 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1181);
											mem_vec_1181 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1182);
											mem_vec_1182 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1183);
											mem_vec_1183 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1184);
											mem_vec_1184 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1185);
											mem_vec_1185 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1186);
											mem_vec_1186 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1187);
											mem_vec_1187 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1172);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1173);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1174);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1175);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1176);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1177);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1178);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1179);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1180);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1181);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1182);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1183);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1184);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1185);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1186);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1187);
							}
						}
					}
				}
			}
		}
	}
}


}