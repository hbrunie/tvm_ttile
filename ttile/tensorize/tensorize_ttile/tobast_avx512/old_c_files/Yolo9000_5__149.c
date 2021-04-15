#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (4, c); Hoist_vars [c]; T (4, x); T (34, y);
  T (32, c); T (34, x)]
*/
IND_TYPE c, cp_0, c176_p_0, cp_1, c176, x, xp_0, x232_p_0, xp_1, x232, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y136 = 0;
IND_TYPE x233 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c177 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_1088 ,mem_vec_1089 ,mem_vec_1090 ,mem_vec_1091 ,mem_vec_1092 ,mem_vec_1093 ,mem_vec_1094 ,mem_vec_1095 ,mem_vec_1096 ,mem_vec_1097 ,mem_vec_1098 ,mem_vec_1099 ,mem_vec_1100 ,mem_vec_1101 ,mem_vec_1102 ,mem_vec_1103 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 34) (136 / 4)
for (x232 = x233, x232_p_0 = 0;
	x232 < x233 + 136;
	x232 += 4, x232_p_0 += 4){
	// y = 136, x = 4, h = 1, w = 1, c = 128, f = 64
	// T (c, 32) (128 / 4)
	for (c176 = c177, c176_p_0 = 0;
		c176 < c177 + 128;
		c176 += 4, c176_p_0 += 4){
		// y = 136, x = 4, h = 1, w = 1, c = 4, f = 64
		// T (y, 34) (136 / 4)
		for (y = y136, yp_0 = 0;
			y < y136 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 4, h = 1, w = 1, c = 4, f = 64
			// T (x, 4) (4 / 1)
			for (x = x232, xp_1 = x232_p_0, xp_0 = 0;
				x < x232 + 4;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_1088 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_1089 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_1090 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_1091 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_1092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_1093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_1094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_1095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_1096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_1097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_1098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_1099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_1100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_1101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_1102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_1103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 4, f = 64
						// T (c, 4) (4 / 1)
						for (c = c176, cp_1 = c176_p_0, cp_0 = 0;
							c < c176 + 4;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1088);
							mem_vec_1088 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1089);
							mem_vec_1089 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1090);
							mem_vec_1090 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1091);
							mem_vec_1091 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1092);
							mem_vec_1092 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1093);
							mem_vec_1093 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1094);
							mem_vec_1094 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1095);
							mem_vec_1095 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1096);
							mem_vec_1096 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1097);
							mem_vec_1097 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1098);
							mem_vec_1098 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1099);
							mem_vec_1099 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1100);
							mem_vec_1100 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1101);
							mem_vec_1101 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1102);
							mem_vec_1102 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1103);
							mem_vec_1103 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1088);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1089);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1090);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1091);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1092);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1093);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1094);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1095);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1096);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1097);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1098);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1099);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1100);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1101);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1102);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1103);
			}
		}
	}
}


}