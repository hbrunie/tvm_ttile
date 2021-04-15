#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, h); T (2, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (1, x); T (136, y); T (16, c); T (136, x); T (1, x)]
*/
IND_TYPE c, cp_0, c216_p_0, cp_1, c216, w, wp_0, x, xp_0, x360_p_0, x361_p_0, x362_p_0, xp_1, x360_p_1, x361_p_1, xp_2, x360_p_2, xp_3, x360, x361, x362, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y144 = 0;
IND_TYPE x363 = 0;
IND_TYPE h = 0;
IND_TYPE w144 = 0;
IND_TYPE c217 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 1) (272 / 272)
for (x362 = x363, x362_p_0 = 0;
	x362 < x363 + 272;
	x362 += 272, x362_p_0 += 272){
	// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 136) (272 / 2)
	for (x361 = x362, x361_p_1 = x362_p_0, x361_p_0 = 0;
		x361 < x362 + 272;
		x361 += 2, x361_p_1 += 2, x361_p_0 += 2){
		// y = 272, x = 2, h = 3, w = 3, c = 32, f = 64
		// T (c, 16) (32 / 2)
		for (c216 = c217, c216_p_0 = 0;
			c216 < c217 + 32;
			c216 += 2, c216_p_0 += 2){
			// y = 272, x = 2, h = 3, w = 3, c = 2, f = 64
			// T (y, 136) (272 / 2)
			for (y = y144, yp_0 = 0;
				y < y144 + 272;
				y += 2, yp_0 += 2){
				// y = 2, x = 2, h = 3, w = 3, c = 2, f = 64
				// T (x, 1) (2 / 2)
				for (x360 = x361, x360_p_2 = x361_p_1, x360_p_1 = x361_p_0, x360_p_0 = 0;
					x360 < x361 + 2;
					x360 += 2, x360_p_2 += 2, x360_p_1 += 2, x360_p_0 += 2){
					// y = 2, x = 2, h = 3, w = 3, c = 2, f = 64
					// T (w, 3) (3 / 1)
					for (w = w144, wp_0 = 0;
						w < w144 + 3;
						w += 1, wp_0 += 1){
						// y = 2, x = 2, h = 3, w = 1, c = 2, f = 64
						// T (x, 2) (2 / 1)
						for (x = x360, xp_3 = x360_p_2, xp_2 = x360_p_1, xp_1 = x360_p_0, xp_0 = 0;
							x < x360 + 2;
							x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									// y = 2, x = 1, h = 3, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c216, cp_1 = c216_p_0, cp_0 = 0;
										c < c216 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_912);
										mem_vec_912 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_913);
										mem_vec_913 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_914);
										mem_vec_914 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_915);
										mem_vec_915 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_916);
										mem_vec_916 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_917);
										mem_vec_917 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_918);
										mem_vec_918 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_919);
										mem_vec_919 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_912);
										mem_vec_912 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_913);
										mem_vec_913 = vec_17;

										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_914);
										mem_vec_914 = vec_19;

										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_915);
										mem_vec_915 = vec_21;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_916);
										mem_vec_916 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_917);
										mem_vec_917 = vec_25;



										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_918);
										mem_vec_918 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_919);
										mem_vec_919 = vec_27;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_912);
										mem_vec_912 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_913);
										mem_vec_913 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_914);
										mem_vec_914 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_915);
										mem_vec_915 = vec_35;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_916);
										mem_vec_916 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_917);
										mem_vec_917 = vec_39;



										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_918);
										mem_vec_918 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_919);
										mem_vec_919 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_917);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_918);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_919);
						}
					}
				}
			}
		}
	}
}


}