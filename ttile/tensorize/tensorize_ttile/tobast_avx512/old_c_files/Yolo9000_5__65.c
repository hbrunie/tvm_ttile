#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (1, c); Hoist_vars [c]; T (4, x); T (34, y);
  T (128, c); T (34, x)]
*/
IND_TYPE c, cp_0, c188_p_0, cp_1, c188, x, xp_0, x244_p_0, xp_1, x244, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y144 = 0;
IND_TYPE x245 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c189 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_1152 ,mem_vec_1153 ,mem_vec_1154 ,mem_vec_1155 ,mem_vec_1156 ,mem_vec_1157 ,mem_vec_1158 ,mem_vec_1159 ,mem_vec_1160 ,mem_vec_1161 ,mem_vec_1162 ,mem_vec_1163 ,mem_vec_1164 ,mem_vec_1165 ,mem_vec_1166 ,mem_vec_1167 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 34) (136 / 4)
for (x244 = x245, x244_p_0 = 0;
	x244 < x245 + 136;
	x244 += 4, x244_p_0 += 4){
	// y = 136, x = 4, h = 1, w = 1, c = 128, f = 64
	// T (c, 128) (128 / 1)
	for (c188 = c189, c188_p_0 = 0;
		c188 < c189 + 128;
		c188 += 1, c188_p_0 += 1){
		// y = 136, x = 4, h = 1, w = 1, c = 1, f = 64
		// T (y, 34) (136 / 4)
		for (y = y144, yp_0 = 0;
			y < y144 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 4, h = 1, w = 1, c = 1, f = 64
			// T (x, 4) (4 / 1)
			for (x = x244, xp_1 = x244_p_0, xp_0 = 0;
				x < x244 + 4;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_1152 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_1153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_1154 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_1155 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_1156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_1157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_1158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_1159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_1160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_1161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_1162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_1163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_1164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_1165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_1166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_1167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (c, 1) (1 / 1)
						for (c = c188, cp_1 = c188_p_0, cp_0 = 0;
							c < c188 + 1;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1152);
							mem_vec_1152 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1153);
							mem_vec_1153 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1154);
							mem_vec_1154 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1155);
							mem_vec_1155 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1156);
							mem_vec_1156 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1157);
							mem_vec_1157 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1158);
							mem_vec_1158 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1159);
							mem_vec_1159 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1160);
							mem_vec_1160 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1161);
							mem_vec_1161 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1162);
							mem_vec_1162 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1163);
							mem_vec_1163 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1164);
							mem_vec_1164 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1165);
							mem_vec_1165 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1166);
							mem_vec_1166 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1167);
							mem_vec_1167 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1152);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1153);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1154);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1155);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1156);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1157);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1158);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1159);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1160);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1161);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1162);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1163);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1164);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1165);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1166);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1167);
			}
		}
	}
}


}