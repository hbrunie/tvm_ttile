#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); U (8, y); U (3, h); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (28, x); T (7, y); T (4, f); T (4, c); T (1, x)]
*/
IND_TYPE c, cp_0, c74_p_0, cp_1, c74, f, fp_0, w, wp_0, x, xp_0, x80_p_0, x81_p_0, xp_1, x80_p_1, xp_2, x80, x81, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y44 = 0;
IND_TYPE x82 = 0;
IND_TYPE h = 0;
IND_TYPE w44 = 0;
IND_TYPE c75 = 0;
IND_TYPE f36 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_338 ,mem_vec_339 ,mem_vec_340 ,mem_vec_341 ,mem_vec_342 ,mem_vec_343 ,mem_vec_344 ,mem_vec_345 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 1) (56 / 56)
for (x81 = x82, x81_p_0 = 0;
	x81 < x82 + 56;
	x81 += 56, x81_p_0 += 56){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (c, 4) (64 / 16)
	for (c74 = c75, c74_p_0 = 0;
		c74 < c75 + 64;
		c74 += 16, c74_p_0 += 16){
		// y = 56, x = 56, h = 3, w = 3, c = 16, f = 64
		// T (f, 4) (64 / 16)
		for (f = f36, fp_0 = 0;
			f < f36 + 64;
			f += 16, fp_0 += 16){
			// y = 56, x = 56, h = 3, w = 3, c = 16, f = 16
			// T (y, 7) (56 / 8)
			for (y = y44, yp_0 = 0;
				y < y44 + 56;
				y += 8, yp_0 += 8){
				// y = 8, x = 56, h = 3, w = 3, c = 16, f = 16
				// T (x, 28) (56 / 2)
				for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
					x80 < x81 + 56;
					x80 += 2, x80_p_1 += 2, x80_p_0 += 2){
					// y = 8, x = 2, h = 3, w = 3, c = 16, f = 16
					// T (w, 3) (3 / 1)
					for (w = w44, wp_0 = 0;
						w < w44 + 3;
						w += 1, wp_0 += 1){
						// y = 8, x = 2, h = 3, w = 1, c = 16, f = 16
						// T (x, 2) (2 / 1)
						for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
							x < x80 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_338 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									// y = 8, x = 1, h = 3, w = 1, c = 16, f = 16
									// T (c, 16) (16 / 1)
									for (c = c74, cp_1 = c74_p_0, cp_0 = 0;
										c < c74 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_338);
										mem_vec_338 = vec_0;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_339);
										mem_vec_339 = vec_3;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_340);
										mem_vec_340 = vec_5;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_341);
										mem_vec_341 = vec_7;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_342);
										mem_vec_342 = vec_9;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_343);
										mem_vec_343 = vec_11;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);


										vec_13 = _mm512_fmadd_ps(vec_14, vec_2, mem_vec_344);
										mem_vec_344 = vec_13;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
										vec_16 = _mm512_set1_ps(scal_7);


										vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_345);
										mem_vec_345 = vec_15;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_18 = _mm512_set1_ps(scal_8);
										vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_338);
										mem_vec_338 = vec_17;
										scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_21 = _mm512_set1_ps(scal_9);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_19, mem_vec_339);
										mem_vec_339 = vec_20;
										scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_23 = _mm512_set1_ps(scal_10);


										vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_340);
										mem_vec_340 = vec_22;
										scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
										vec_25 = _mm512_set1_ps(scal_11);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_19, mem_vec_341);
										mem_vec_341 = vec_24;
										scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
										vec_27 = _mm512_set1_ps(scal_12);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_19, mem_vec_342);
										mem_vec_342 = vec_26;
										scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_13);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_343);
										mem_vec_343 = vec_28;
										scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
										vec_31 = _mm512_set1_ps(scal_14);


										vec_30 = _mm512_fmadd_ps(vec_31, vec_19, mem_vec_344);
										mem_vec_344 = vec_30;
										scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 1) + c];
										vec_33 = _mm512_set1_ps(scal_15);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_19, mem_vec_345);
										mem_vec_345 = vec_32;
										scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_35 = _mm512_set1_ps(scal_16);
										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_338);
										mem_vec_338 = vec_34;
										scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_17);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_339);
										mem_vec_339 = vec_37;
										scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_40 = _mm512_set1_ps(scal_18);


										vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_340);
										mem_vec_340 = vec_39;
										scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
										vec_42 = _mm512_set1_ps(scal_19);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_36, mem_vec_341);
										mem_vec_341 = vec_41;
										scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
										vec_44 = _mm512_set1_ps(scal_20);


										vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_342);
										mem_vec_342 = vec_43;
										scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
										vec_46 = _mm512_set1_ps(scal_21);


										vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_343);
										mem_vec_343 = vec_45;
										scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_22);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_36, mem_vec_344);
										mem_vec_344 = vec_47;
										scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h + 2) + c];
										vec_50 = _mm512_set1_ps(scal_23);


										vec_49 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_345);
										mem_vec_345 = vec_49;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_338);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_339);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_340);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_341);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_342);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_343);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_344);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_345);
						}
					}
				}
			}
		}
	}
}


}