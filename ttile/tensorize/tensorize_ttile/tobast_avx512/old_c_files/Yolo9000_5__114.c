#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (8, c); Hoist_vars [c]; T (8, x); T (34, y);
  T (16, c); T (17, x)]
*/
IND_TYPE c, cp_0, c158_p_0, cp_1, c158, x, xp_0, x214_p_0, xp_1, x214, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y124 = 0;
IND_TYPE x215 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c159 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_1000 ,mem_vec_1001 ,mem_vec_1002 ,mem_vec_1003 ,mem_vec_1004 ,mem_vec_1005 ,mem_vec_1006 ,mem_vec_1007 ,mem_vec_992 ,mem_vec_993 ,mem_vec_994 ,mem_vec_995 ,mem_vec_996 ,mem_vec_997 ,mem_vec_998 ,mem_vec_999 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (x, 17) (136 / 8)
for (x214 = x215, x214_p_0 = 0;
	x214 < x215 + 136;
	x214 += 8, x214_p_0 += 8){
	// y = 136, x = 8, h = 1, w = 1, c = 128, f = 64
	// T (c, 16) (128 / 8)
	for (c158 = c159, c158_p_0 = 0;
		c158 < c159 + 128;
		c158 += 8, c158_p_0 += 8){
		// y = 136, x = 8, h = 1, w = 1, c = 8, f = 64
		// T (y, 34) (136 / 4)
		for (y = y124, yp_0 = 0;
			y < y124 + 136;
			y += 4, yp_0 += 4){
			// y = 4, x = 8, h = 1, w = 1, c = 8, f = 64
			// T (x, 8) (8 / 1)
			for (x = x214, xp_1 = x214_p_0, xp_0 = 0;
				x < x214 + 8;
				x += 1, xp_1 += 1, xp_0 += 1){
						mem_vec_992 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
						mem_vec_993 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
						mem_vec_994 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
						mem_vec_995 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
						mem_vec_996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
						mem_vec_997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
						mem_vec_998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
						mem_vec_999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
						mem_vec_1000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
						mem_vec_1001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
						mem_vec_1002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
						mem_vec_1003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
						mem_vec_1004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
						mem_vec_1005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
						mem_vec_1006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
						mem_vec_1007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
						// y = 4, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (c, 8) (8 / 1)
						for (c = c158, cp_1 = c158_p_0, cp_0 = 0;
							c < c158 + 8;
							c += 1, cp_1 += 1, cp_0 += 1){
							scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
							vec_1 = _mm512_set1_ps(scal_0);
							vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

							vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_992);
							mem_vec_992 = vec_0;

							vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

							vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_993);
							mem_vec_993 = vec_3;

							vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

							vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_994);
							mem_vec_994 = vec_5;

							vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

							vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_995);
							mem_vec_995 = vec_7;
							scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
							vec_10 = _mm512_set1_ps(scal_1);


							vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_996);
							mem_vec_996 = vec_9;



							vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_997);
							mem_vec_997 = vec_11;



							vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_998);
							mem_vec_998 = vec_12;



							vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_999);
							mem_vec_999 = vec_13;
							scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
							vec_15 = _mm512_set1_ps(scal_2);


							vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1000);
							mem_vec_1000 = vec_14;



							vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1001);
							mem_vec_1001 = vec_16;



							vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1002);
							mem_vec_1002 = vec_17;



							vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1003);
							mem_vec_1003 = vec_18;
							scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
							vec_20 = _mm512_set1_ps(scal_3);


							vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1004);
							mem_vec_1004 = vec_19;



							vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1005);
							mem_vec_1005 = vec_21;



							vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1006);
							mem_vec_1006 = vec_22;



							vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1007);
							mem_vec_1007 = vec_23;
						}
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_992);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_993);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_994);
					_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_995);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_996);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_997);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_998);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_999);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1000);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1001);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1002);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1003);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1004);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1005);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1006);
					_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1007);
			}
		}
	}
}


}