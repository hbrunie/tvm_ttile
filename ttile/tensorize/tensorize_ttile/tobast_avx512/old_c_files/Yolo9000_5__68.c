#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (2, x); T (34, y);
  T (8, c); T (68, x)]
*/
IND_TYPE c, cp_0, c206_p_0, cp_1, c206, x, xp_0, x262_p_0, xp_1, x262, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y156 = 0;
IND_TYPE x263 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c207 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_1248 ,mem_vec_1249 ,mem_vec_1250 ,mem_vec_1251 ,mem_vec_1252 ,mem_vec_1253 ,mem_vec_1254 ,mem_vec_1255 ,mem_vec_1256 ,mem_vec_1257 ,mem_vec_1258 ,mem_vec_1259 ,mem_vec_1260 ,mem_vec_1261 ,mem_vec_1262 ,mem_vec_1263 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 68) (136 / 2)
for (x262 = x263, x262_p_0 = 0;
	x262 < x263 + 136;
	x262 += 2, x262_p_0 += 2){
	// y = 136, x = 2, h = 1, w = 1, c = 128, f = 64
	// T (c, 8) (128 / 16)
	for (c206 = c207, c206_p_0 = 0;
		c206 < c207 + 128;
		c206 += 16, c206_p_0 += 16){
		// y = 136, x = 2, h = 1, w = 1, c = 16, f = 64
		// T (y, 34) (136 / 4)
		for (y = y156, yp_0 = 0;
			y < y156 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 2, h = 1, w = 1, c = 16, f = 64
			// T (x, 2) (2 / 1)
			for (x = x262, xp_1 = x262_p_0, xp_0 = 0;
				x < x262 + 2;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_1248 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_1249 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_1250 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_1251 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_1252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_1253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_1254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_1255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_1256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_1257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_1258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_1259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_1260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_1261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_1262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_1263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
						// T (c, 16) (16 / 1)
						for (c = c206, cp_1 = c206_p_0, cp_0 = 0;
							c < c206 + 16;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1248);
							mem_vec_1248 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1249);
							mem_vec_1249 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1250);
							mem_vec_1250 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1251);
							mem_vec_1251 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1252);
							mem_vec_1252 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1253);
							mem_vec_1253 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1254);
							mem_vec_1254 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1255);
							mem_vec_1255 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1256);
							mem_vec_1256 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1257);
							mem_vec_1257 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1258);
							mem_vec_1258 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1259);
							mem_vec_1259 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1260);
							mem_vec_1260 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1261);
							mem_vec_1261 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1262);
							mem_vec_1262 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1263);
							mem_vec_1263 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1248);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1249);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1250);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1251);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1252);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1253);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1254);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1255);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1256);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1257);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1258);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1259);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1260);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1261);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1262);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1263);
			}
		}
	}
}


}