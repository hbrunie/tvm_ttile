#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (128, c); Hoist_vars [c]; T (8, x); T (1, y);
  T (2, f); T (17, x); T (17, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x441_p_0, xp_1, x441, y, yp_0, y441_p_0, yp_1, y441;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y442 = 0;
IND_TYPE x442 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c331 = 0;
IND_TYPE f257 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_6162 ,mem_vec_6163 ,mem_vec_6164 ,mem_vec_6165 ,mem_vec_6166 ,mem_vec_6167 ,mem_vec_6168 ,mem_vec_6169 ,mem_vec_6170 ,mem_vec_6171 ,mem_vec_6172 ,mem_vec_6173 ,mem_vec_6174 ,mem_vec_6175 ,mem_vec_6176 ,mem_vec_6177 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 17) (136 / 8)
for (y441 = y442, y441_p_0 = 0;
	y441 < y442 + 136;
	y441 += 8, y441_p_0 += 8){
	// y = 8, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 17) (136 / 8)
	for (x441 = x442, x441_p_0 = 0;
		x441 < x442 + 136;
		x441 += 8, x441_p_0 += 8){
		// y = 8, x = 8, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f257, fp_0 = 0;
			f < f257 + 64;
			f += 32, fp_0 += 32){
			// y = 8, x = 8, h = 1, w = 1, c = 128, f = 32
			// T (y, 1) (8 / 8)
			for (y = y441, yp_1 = y441_p_0, yp_0 = 0;
				y < y441 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = 8, x = 8, h = 1, w = 1, c = 128, f = 32
				// T (x, 8) (8 / 1)
				for (x = x441, xp_1 = x441_p_0, xp_0 = 0;
					x < x441 + 8;
					x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_6162 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_6163 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_6164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
							mem_vec_6165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
							mem_vec_6166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
							mem_vec_6167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
							mem_vec_6168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
							mem_vec_6169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
							mem_vec_6170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
							mem_vec_6171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
							mem_vec_6172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
							mem_vec_6173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
							mem_vec_6174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
							mem_vec_6175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
							mem_vec_6176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
							mem_vec_6177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
							// y = 8, x = 1, h = 1, w = 1, c = 128, f = 32
							// T (c, 128) (128 / 1)
							for (c = c331, cp_0 = 0;
								c < c331 + 128;
								c += 1, cp_0 += 1){
								scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
								vec_1 = _mm512_set1_ps(scal_0);
								vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

								vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6162);
								mem_vec_6162 = vec_0;

								vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

								vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6163);
								mem_vec_6163 = vec_3;
								scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
								vec_6 = _mm512_set1_ps(scal_1);


								vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6164);
								mem_vec_6164 = vec_5;



								vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6165);
								mem_vec_6165 = vec_7;
								scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
								vec_9 = _mm512_set1_ps(scal_2);


								vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6166);
								mem_vec_6166 = vec_8;



								vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6167);
								mem_vec_6167 = vec_10;
								scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
								vec_12 = _mm512_set1_ps(scal_3);


								vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6168);
								mem_vec_6168 = vec_11;



								vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6169);
								mem_vec_6169 = vec_13;
								scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
								vec_15 = _mm512_set1_ps(scal_4);


								vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6170);
								mem_vec_6170 = vec_14;



								vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6171);
								mem_vec_6171 = vec_16;
								scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
								vec_18 = _mm512_set1_ps(scal_5);


								vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6172);
								mem_vec_6172 = vec_17;



								vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6173);
								mem_vec_6173 = vec_19;
								scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
								vec_21 = _mm512_set1_ps(scal_6);


								vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6174);
								mem_vec_6174 = vec_20;



								vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6175);
								mem_vec_6175 = vec_22;
								scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
								vec_24 = _mm512_set1_ps(scal_7);


								vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6176);
								mem_vec_6176 = vec_23;



								vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6177);
								mem_vec_6177 = vec_25;
							}
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6162);
						_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6163);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6164);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6165);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6166);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6167);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6168);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6169);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6170);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6171);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6172);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6173);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6174);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6175);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6176);
						_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6177);
				}
			}
		}
	}
}


}