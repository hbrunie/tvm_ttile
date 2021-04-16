#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (64, c); Hoist_vars [c]; T (14, x); T (4, f);
  T (2, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x15_p_0, xp_1, x15, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y10 = 0;
IND_TYPE x16 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c10 = 0;
IND_TYPE f10 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_126 ,mem_vec_127 ,mem_vec_128 ,mem_vec_129 ,mem_vec_130 ,mem_vec_131 ,mem_vec_132 ,mem_vec_133 ,mem_vec_134 ,mem_vec_135 ,mem_vec_136 ,mem_vec_137 ,mem_vec_138 ,mem_vec_139 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (y, 4) (28 / 7)
for (y = y10, yp_0 = 0;
	y < y10 + 28;
	y += 7, yp_0 += 7){
	// y = 7, x = 28, h = 1, w = 1, c = 64, f = 128
	// T (x, 2) (28 / 14)
	for (x15 = x16, x15_p_0 = 0;
		x15 < x16 + 28;
		x15 += 14, x15_p_0 += 14){
		// y = 7, x = 14, h = 1, w = 1, c = 64, f = 128
		// T (f, 4) (128 / 32)
		for (f = f10, fp_0 = 0;
			f < f10 + 128;
			f += 32, fp_0 += 32){
			// y = 7, x = 14, h = 1, w = 1, c = 64, f = 32
			// T (x, 14) (14 / 1)
			for (x = x15, xp_1 = x15_p_0, xp_0 = 0;
				x < x15 + 14;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_126 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_127 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_132 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_133 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_134 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
						mem_vec_135 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
						mem_vec_136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
						mem_vec_137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
						mem_vec_138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
						mem_vec_139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
						// y = 7, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (c, 64) (64 / 1)
						for (c = c10, cp_0 = 0;
							c < c10 + 64;
							c += 1, cp_0 += 1){
							scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_126);
							mem_vec_126 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_127);
							mem_vec_127 = vec_3;
							scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
							vec_6 = _mm512_set1_ps(scal_1);


							vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_128);
							mem_vec_128 = vec_5;



							vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_129);
							mem_vec_129 = vec_7;
							scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
							vec_9 = _mm512_set1_ps(scal_2);


							vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_130);
							mem_vec_130 = vec_8;



							vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_131);
							mem_vec_131 = vec_10;
							scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
							vec_12 = _mm512_set1_ps(scal_3);


							vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_132);
							mem_vec_132 = vec_11;



							vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_133);
							mem_vec_133 = vec_13;
							scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
							vec_15 = _mm512_set1_ps(scal_4);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_134);
							mem_vec_134 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_135);
							mem_vec_135 = vec_16;
							scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
							vec_18 = _mm512_set1_ps(scal_5);


							vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_136);
							mem_vec_136 = vec_17;



							vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_137);
							mem_vec_137 = vec_19;
							scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
							vec_21 = _mm512_set1_ps(scal_6);


							vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_138);
							mem_vec_138 = vec_20;



							vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_139);
							mem_vec_139 = vec_22;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_126);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_127);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_128);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_129);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_130);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_131);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_132);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_133);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_134);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_135);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_136);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_137);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_138);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_139);
			}
		}
	}
}


}