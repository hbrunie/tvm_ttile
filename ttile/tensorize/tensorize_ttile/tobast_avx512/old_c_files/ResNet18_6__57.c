#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (4, y); U (3, w); T (64, c); Hoist_vars [c]; T (28, x);
  T (3, h); T (2, f); T (2, c); T (1, x); T (7, y); T (2, f)]
*/
IND_TYPE c, cp_0, c156_p_0, cp_1, c156, f, fp_0, f156_p_0, fp_1, f156, h, hp_0, x, xp_0, x156_p_0, xp_1, x156, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y104 = 0;
IND_TYPE x157 = 0;
IND_TYPE h82 = 0;
IND_TYPE w = 0;
IND_TYPE c157 = 0;
IND_TYPE f157 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 2) (128 / 64)
for (f156 = f157, f156_p_0 = 0;
	f156 < f157 + 128;
	f156 += 64, f156_p_0 += 64){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 64
	// T (y, 7) (28 / 4)
	for (y = y104, yp_0 = 0;
		y < y104 + 28;
		y += 4, yp_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 128, f = 64
		// T (x, 1) (28 / 28)
		for (x156 = x157, x156_p_0 = 0;
			x156 < x157 + 28;
			x156 += 28, x156_p_0 += 28){
			// y = 4, x = 28, h = 3, w = 3, c = 128, f = 64
			// T (c, 2) (128 / 64)
			for (c156 = c157, c156_p_0 = 0;
				c156 < c157 + 128;
				c156 += 64, c156_p_0 += 64){
				// y = 4, x = 28, h = 3, w = 3, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f156, fp_1 = f156_p_0, fp_0 = 0;
					f < f156 + 64;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 28, h = 3, w = 3, c = 64, f = 32
					// T (h, 3) (3 / 1)
					for (h = h82, hp_0 = 0;
						h < h82 + 3;
						h += 1, hp_0 += 1){
						// y = 4, x = 28, h = 1, w = 3, c = 64, f = 32
						// T (x, 28) (28 / 1)
						for (x = x156, xp_1 = x156_p_0, xp_0 = 0;
							x < x156 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_802 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_803 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c156, cp_1 = c156_p_0, cp_0 = 0;
										c < c156 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_802);
										mem_vec_802 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_803);
										mem_vec_803 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_804);
										mem_vec_804 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_805);
										mem_vec_805 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_806);
										mem_vec_806 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_807);
										mem_vec_807 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_808);
										mem_vec_808 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_809);
										mem_vec_809 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_802);
										mem_vec_802 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_803);
										mem_vec_803 = vec_17;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_20 = _mm512_set1_ps(scal_5);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_804);
										mem_vec_804 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_805);
										mem_vec_805 = vec_21;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_23 = _mm512_set1_ps(scal_6);


										vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_806);
										mem_vec_806 = vec_22;



										vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_807);
										mem_vec_807 = vec_24;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_26 = _mm512_set1_ps(scal_7);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_808);
										mem_vec_808 = vec_25;



										vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_809);
										mem_vec_809 = vec_27;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_29 = _mm512_set1_ps(scal_8);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_802);
										mem_vec_802 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_803);
										mem_vec_803 = vec_31;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_34 = _mm512_set1_ps(scal_9);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_804);
										mem_vec_804 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_805);
										mem_vec_805 = vec_35;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_37 = _mm512_set1_ps(scal_10);


										vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_806);
										mem_vec_806 = vec_36;



										vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_807);
										mem_vec_807 = vec_38;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_40 = _mm512_set1_ps(scal_11);


										vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_808);
										mem_vec_808 = vec_39;



										vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_809);
										mem_vec_809 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_802);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_803);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_804);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_805);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_806);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_807);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_808);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_809);
						}
					}
				}
			}
		}
	}
}


}