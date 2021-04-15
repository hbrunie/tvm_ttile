#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (4, y); U (3, w); T (3, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (4, y); T (4, x); T (34, y); T (34, x)]
*/
IND_TYPE c, cp_0, h, hp_0, x, xp_0, x82_p_0, x83_p_0, xp_1, x82_p_1, xp_2, x82, x83, y, yp_0, y72_p_0, yp_1, y72;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y73 = 0;
IND_TYPE x84 = 0;
IND_TYPE h36 = 0;
IND_TYPE w = 0;
IND_TYPE c44 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_184 ,mem_vec_185 ,mem_vec_186 ,mem_vec_187 ,mem_vec_188 ,mem_vec_189 ,mem_vec_190 ,mem_vec_191 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (x, 34) (544 / 16)
for (x83 = x84, x83_p_0 = 0;
	x83 < x84 + 544;
	x83 += 16, x83_p_0 += 16){
	// y = 544, x = 16, h = 3, w = 3, c = 3, f = 32
	// T (y, 34) (544 / 16)
	for (y72 = y73, y72_p_0 = 0;
		y72 < y73 + 544;
		y72 += 16, y72_p_0 += 16){
		// y = 16, x = 16, h = 3, w = 3, c = 3, f = 32
		// T (x, 4) (16 / 4)
		for (x82 = x83, x82_p_1 = x83_p_0, x82_p_0 = 0;
			x82 < x83 + 16;
			x82 += 4, x82_p_1 += 4, x82_p_0 += 4){
			// y = 16, x = 4, h = 3, w = 3, c = 3, f = 32
			// T (y, 4) (16 / 4)
			for (y = y72, yp_1 = y72_p_0, yp_0 = 0;
				y < y72 + 16;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h36, hp_0 = 0;
					h < h36 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 4, h = 1, w = 3, c = 3, f = 32
					// T (x, 4) (4 / 1)
					for (x = x82, xp_2 = x82_p_1, xp_1 = x82_p_0, xp_0 = 0;
						x < x82 + 4;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_184 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_185 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
								// T (c, 3) (3 / 1)
								for (c = c44, cp_0 = 0;
									c < c44 + 3;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_184);
									mem_vec_184 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_185);
									mem_vec_185 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_186);
									mem_vec_186 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_187);
									mem_vec_187 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_188);
									mem_vec_188 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_189);
									mem_vec_189 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_190);
									mem_vec_190 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_191);
									mem_vec_191 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);
									vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_184);
									mem_vec_184 = vec_14;

									vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_185);
									mem_vec_185 = vec_17;
									scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_20 = _mm512_set1_ps(scal_5);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_186);
									mem_vec_186 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_187);
									mem_vec_187 = vec_21;
									scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_23 = _mm512_set1_ps(scal_6);


									vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_188);
									mem_vec_188 = vec_22;



									vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_189);
									mem_vec_189 = vec_24;
									scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_26 = _mm512_set1_ps(scal_7);


									vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_190);
									mem_vec_190 = vec_25;



									vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_191);
									mem_vec_191 = vec_27;
									scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_29 = _mm512_set1_ps(scal_8);
									vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_184);
									mem_vec_184 = vec_28;

									vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_185);
									mem_vec_185 = vec_31;
									scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_34 = _mm512_set1_ps(scal_9);


									vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_186);
									mem_vec_186 = vec_33;



									vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_187);
									mem_vec_187 = vec_35;
									scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_37 = _mm512_set1_ps(scal_10);


									vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_188);
									mem_vec_188 = vec_36;



									vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_189);
									mem_vec_189 = vec_38;
									scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_40 = _mm512_set1_ps(scal_11);


									vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_190);
									mem_vec_190 = vec_39;



									vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_191);
									mem_vec_191 = vec_41;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_184);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_185);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_186);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_187);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_188);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_189);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_190);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_191);
					}
				}
			}
		}
	}
}


}