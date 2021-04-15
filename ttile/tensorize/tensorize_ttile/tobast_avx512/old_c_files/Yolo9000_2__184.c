#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (2, y); U (3, w); T (4, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (17, x); T (136, y); T (8, c); T (4, x); T (2, x)]
*/
IND_TYPE c, cp_0, c516_p_0, cp_1, c516, h, hp_0, x, xp_0, x868_p_0, x869_p_0, x870_p_0, xp_1, x868_p_1, x869_p_1, xp_2, x868_p_2, xp_3, x868, x869, x870, y, yp_0;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y364 = 0;
IND_TYPE x871 = 0;
IND_TYPE h268 = 0;
IND_TYPE w = 0;
IND_TYPE c517 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_2080 ,mem_vec_2081 ,mem_vec_2082 ,mem_vec_2083 ,mem_vec_2084 ,mem_vec_2085 ,mem_vec_2086 ,mem_vec_2087 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x870 = x871, x870_p_0 = 0;
	x870 < x871 + 272;
	x870 += 136, x870_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (x, 4) (136 / 34)
	for (x869 = x870, x869_p_1 = x870_p_0, x869_p_0 = 0;
		x869 < x870 + 136;
		x869 += 34, x869_p_1 += 34, x869_p_0 += 34){
		// y = 272, x = 34, h = 3, w = 3, c = 32, f = 64
		// T (c, 8) (32 / 4)
		for (c516 = c517, c516_p_0 = 0;
			c516 < c517 + 32;
			c516 += 4, c516_p_0 += 4){
			// y = 272, x = 34, h = 3, w = 3, c = 4, f = 64
			// T (y, 136) (272 / 2)
			for (y = y364, yp_0 = 0;
				y < y364 + 272;
				y += 2, yp_0 += 2){
				// y = 2, x = 34, h = 3, w = 3, c = 4, f = 64
				// T (x, 17) (34 / 2)
				for (x868 = x869, x868_p_2 = x869_p_1, x868_p_1 = x869_p_0, x868_p_0 = 0;
					x868 < x869 + 34;
					x868 += 2, x868_p_2 += 2, x868_p_1 += 2, x868_p_0 += 2){
					// y = 2, x = 2, h = 3, w = 3, c = 4, f = 64
					// T (h, 3) (3 / 1)
					for (h = h268, hp_0 = 0;
						h < h268 + 3;
						h += 1, hp_0 += 1){
						// y = 2, x = 2, h = 1, w = 3, c = 4, f = 64
						// T (x, 2) (2 / 1)
						for (x = x868, xp_3 = x868_p_2, xp_2 = x868_p_1, xp_1 = x868_p_0, xp_0 = 0;
							x < x868 + 2;
							x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_2080 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_2081 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_2082 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_2083 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_2084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_2085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_2086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_2087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									// y = 2, x = 1, h = 1, w = 3, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
										c < c516 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2080);
										mem_vec_2080 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2081);
										mem_vec_2081 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2082);
										mem_vec_2082 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2083);
										mem_vec_2083 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2084);
										mem_vec_2084 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2085);
										mem_vec_2085 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2086);
										mem_vec_2086 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2087);
										mem_vec_2087 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_2080);
										mem_vec_2080 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_2081);
										mem_vec_2081 = vec_17;

										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_2082);
										mem_vec_2082 = vec_19;

										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_2083);
										mem_vec_2083 = vec_21;
										scal_3 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_24 = _mm512_set1_ps(scal_3);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_2084);
										mem_vec_2084 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_2085);
										mem_vec_2085 = vec_25;



										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_2086);
										mem_vec_2086 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_2087);
										mem_vec_2087 = vec_27;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_2080);
										mem_vec_2080 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_2081);
										mem_vec_2081 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_2082);
										mem_vec_2082 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_2083);
										mem_vec_2083 = vec_35;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_38 = _mm512_set1_ps(scal_5);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_2084);
										mem_vec_2084 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_2085);
										mem_vec_2085 = vec_39;



										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_2086);
										mem_vec_2086 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_2087);
										mem_vec_2087 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2080);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2081);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2082);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2083);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2084);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2085);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2086);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2087);
						}
					}
				}
			}
		}
	}
}


}