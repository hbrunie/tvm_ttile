#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (17, x); T (34, y);
  T (8, c); T (8, x)]
*/
IND_TYPE c, cp_0, c146_p_0, cp_1, c146, x, xp_0, x202_p_0, xp_1, x202, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y116 = 0;
IND_TYPE x203 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c147 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 8) (136 / 17)
for (x202 = x203, x202_p_0 = 0;
	x202 < x203 + 136;
	x202 += 17, x202_p_0 += 17){
	// y = 136, x = 17, h = 1, w = 1, c = 128, f = 64
	// T (c, 8) (128 / 16)
	for (c146 = c147, c146_p_0 = 0;
		c146 < c147 + 128;
		c146 += 16, c146_p_0 += 16){
		// y = 136, x = 17, h = 1, w = 1, c = 16, f = 64
		// T (y, 34) (136 / 4)
		for (y = y116, yp_0 = 0;
			y < y116 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 17, h = 1, w = 1, c = 16, f = 64
			// T (x, 17) (17 / 1)
			for (x = x202, xp_1 = x202_p_0, xp_0 = 0;
				x < x202 + 17;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
						// T (c, 16) (16 / 1)
						for (c = c146, cp_1 = c146_p_0, cp_0 = 0;
							c < c146 + 16;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_928);
							mem_vec_928 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_929);
							mem_vec_929 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_930);
							mem_vec_930 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_931);
							mem_vec_931 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_932);
							mem_vec_932 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_933);
							mem_vec_933 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_934);
							mem_vec_934 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_935);
							mem_vec_935 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_936);
							mem_vec_936 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_937);
							mem_vec_937 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_938);
							mem_vec_938 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_939);
							mem_vec_939 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_940);
							mem_vec_940 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_941);
							mem_vec_941 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_942);
							mem_vec_942 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_943);
							mem_vec_943 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_928);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_929);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_930);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_931);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_932);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_933);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_934);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_935);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_936);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_937);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_938);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_939);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_940);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_941);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_942);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_943);
			}
		}
	}
}


}