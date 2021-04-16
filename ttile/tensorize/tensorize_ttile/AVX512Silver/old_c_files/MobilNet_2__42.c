#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (4, y); U (3, w); T (64, c); Hoist_vars [c]; T (56, x);
  T (3, h); T (1, c); T (2, f); T (1, x); T (7, y); T (2, y)]
*/
IND_TYPE c, cp_0, c384_p_0, cp_1, c384, f, fp_0, h, hp_0, x, xp_0, x435_p_0, xp_1, x435, y, yp_0, y327_p_0, yp_1, y327;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y328 = 0;
IND_TYPE x436 = 0;
IND_TYPE h181 = 0;
IND_TYPE w = 0;
IND_TYPE c385 = 0;
IND_TYPE f233 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2951 ,mem_vec_2952 ,mem_vec_2953 ,mem_vec_2954 ,mem_vec_2955 ,mem_vec_2956 ,mem_vec_2957 ,mem_vec_2958 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (y, 2) (56 / 28)
for (y327 = y328, y327_p_0 = 0;
	y327 < y328 + 56;
	y327 += 28, y327_p_0 += 28){
	// y = 28, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (y, 7) (28 / 4)
	for (y = y327, yp_1 = y327_p_0, yp_0 = 0;
		y < y327 + 28;
		y += 4, yp_1 += 4, yp_0 += 4){
		// y = 4, x = 56, h = 3, w = 3, c = 64, f = 64
		// T (x, 1) (56 / 56)
		for (x435 = x436, x435_p_0 = 0;
			x435 < x436 + 56;
			x435 += 56, x435_p_0 += 56){
			// y = 4, x = 56, h = 3, w = 3, c = 64, f = 64
			// T (f, 2) (64 / 32)
			for (f = f233, fp_0 = 0;
				f < f233 + 64;
				f += 32, fp_0 += 32){
				// y = 4, x = 56, h = 3, w = 3, c = 64, f = 32
				// T (c, 1) (64 / 64)
				for (c384 = c385, c384_p_0 = 0;
					c384 < c385 + 64;
					c384 += 64, c384_p_0 += 64){
					// y = 4, x = 56, h = 3, w = 3, c = 64, f = 32
					// T (h, 3) (3 / 1)
					for (h = h181, hp_0 = 0;
						h < h181 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 56, h = 1, w = 3, c = 64, f = 32
						// T (x, 56) (56 / 1)
						for (x = x435, xp_1 = x435_p_0, xp_0 = 0;
							x < x435 + 56;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_2951 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2952 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_2956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_2957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_2958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c384, cp_1 = c384_p_0, cp_0 = 0;
										c < c384 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2951);
										mem_vec_2951 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2952);
										mem_vec_2952 = vec_3;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2953);
										mem_vec_2953 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2954);
										mem_vec_2954 = vec_7;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2955);
										mem_vec_2955 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2956);
										mem_vec_2956 = vec_10;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2957);
										mem_vec_2957 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2958);
										mem_vec_2958 = vec_13;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_2951);
										mem_vec_2951 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_2952);
										mem_vec_2952 = vec_17;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
										vec_20 = _mm512_set1_ps(scal_5);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_2953);
										mem_vec_2953 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_2954);
										mem_vec_2954 = vec_21;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
										vec_23 = _mm512_set1_ps(scal_6);


										vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_2955);
										mem_vec_2955 = vec_22;



										vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_2956);
										mem_vec_2956 = vec_24;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
										vec_26 = _mm512_set1_ps(scal_7);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_2957);
										mem_vec_2957 = vec_25;



										vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_2958);
										mem_vec_2958 = vec_27;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_2951);
										mem_vec_2951 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_2952);
										mem_vec_2952 = vec_31;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
										vec_34 = _mm512_set1_ps(scal_9);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_2953);
										mem_vec_2953 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2954);
										mem_vec_2954 = vec_35;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
										vec_37 = _mm512_set1_ps(scal_10);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_2955);
										mem_vec_2955 = vec_36;



										vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_2956);
										mem_vec_2956 = vec_38;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
										vec_40 = _mm512_set1_ps(scal_11);


										vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_2957);
										mem_vec_2957 = vec_39;



										vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_2958);
										mem_vec_2958 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2951);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2952);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2953);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2954);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2955);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2956);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2957);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2958);
						}
					}
				}
			}
		}
	}
}


}