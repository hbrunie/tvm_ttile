#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (1, f); ULambda y; U (3, w); T (64, c); Hoist_vars [c]; T (3, h);
  T (34, x); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))];
  T (1, c); T (32, f); T (4, c)]
*/
IND_TYPE c, cp_0, c501_p_0, c502_p_0, cp_1, c501_p_1, cp_2, c501, c502, f, fp_0, h, hp_0, x, xp_0, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y374 = 0;
IND_TYPE x496 = 0;
IND_TYPE h300 = 0;
IND_TYPE w = 0;
IND_TYPE c503 = 0;
IND_TYPE f566 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6136 ,mem_vec_6137 ,mem_vec_6138 ,mem_vec_6139 ,mem_vec_6140 ,mem_vec_6141 ,mem_vec_6142 ,mem_vec_6143 ,mem_vec_6144 ,mem_vec_6145 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 4) (256 / 64)
for (c502 = c503, c502_p_0 = 0;
	c502 < c503 + 256;
	c502 += 64, c502_p_0 += 64){
	// y = 34, x = 34, h = 3, w = 3, c = 64, f = 512
	// T (f, 32) (512 / 16)
	for (f = f566, fp_0 = 0;
		f < f566 + 512;
		f += 16, fp_0 += 16){
		// y = 34, x = 34, h = 3, w = 3, c = 64, f = 16
		// T (c, 1) (64 / 64)
		for (c501 = c502, c501_p_1 = c502_p_0, c501_p_0 = 0;
			c501 < c502 + 64;
			c501 += 64, c501_p_1 += 64, c501_p_0 += 64){
				for (y = y374, yp_0 = 0;
					y < y374 + 4;
					y += 4, yp_0 += 4){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 16
					// T (x, 34) (34 / 1)
					for (x = x496, xp_0 = 0;
						x < x496 + 34;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (h, 3) (3 / 1)
						for (h = h300, hp_0 = 0;
							h < h300 + 3;
							h += 1, hp_0 += 1){
									mem_vec_6136 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c501, cp_2 = c501_p_1, cp_1 = c501_p_0, cp_0 = 0;
										c < c501 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6136);
										mem_vec_6136 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_6137);
										mem_vec_6137 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6138);
										mem_vec_6138 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_6139);
										mem_vec_6139 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);
										vec_11 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_9 = _mm512_fmadd_ps(vec_10, vec_11, mem_vec_6136);
										mem_vec_6136 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_13 = _mm512_set1_ps(scal_5);


										vec_12 = _mm512_fmadd_ps(vec_13, vec_11, mem_vec_6137);
										mem_vec_6137 = vec_12;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_6);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_11, mem_vec_6138);
										mem_vec_6138 = vec_14;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_17 = _mm512_set1_ps(scal_7);


										vec_16 = _mm512_fmadd_ps(vec_17, vec_11, mem_vec_6139);
										mem_vec_6139 = vec_16;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_19 = _mm512_set1_ps(scal_8);
										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_18 = _mm512_fmadd_ps(vec_19, vec_20, mem_vec_6136);
										mem_vec_6136 = vec_18;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_22 = _mm512_set1_ps(scal_9);


										vec_21 = _mm512_fmadd_ps(vec_22, vec_20, mem_vec_6137);
										mem_vec_6137 = vec_21;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_24 = _mm512_set1_ps(scal_10);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_6138);
										mem_vec_6138 = vec_23;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_26 = _mm512_set1_ps(scal_11);


										vec_25 = _mm512_fmadd_ps(vec_26, vec_20, mem_vec_6139);
										mem_vec_6139 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6139);
						}
					}
				}
				for (y = y374 + 4, yp_0 = 0;
					y < y374 + 4 + 30;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 16
					// T (x, 34) (34 / 1)
					for (x = x496, xp_0 = 0;
						x < x496 + 34;
						x += 1, xp_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 64, f = 16
						// T (h, 3) (3 / 1)
						for (h = h300, hp_0 = 0;
							h < h300 + 3;
							h += 1, hp_0 += 1){
									mem_vec_6140 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									// y = ph_y, x = 1, h = 1, w = 3, c = 64, f = 16
									// T (c, 64) (64 / 1)
									for (c = c501, cp_2 = c501_p_1, cp_1 = c501_p_0, cp_0 = 0;
										c < c501 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6140);
										mem_vec_6140 = vec_0;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_4 = _mm512_set1_ps(scal_1);


										vec_3 = _mm512_fmadd_ps(vec_4, vec_2, mem_vec_6141);
										mem_vec_6141 = vec_3;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_6 = _mm512_set1_ps(scal_2);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6142);
										mem_vec_6142 = vec_5;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_8 = _mm512_set1_ps(scal_3);


										vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_6143);
										mem_vec_6143 = vec_7;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_10 = _mm512_set1_ps(scal_4);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6144);
										mem_vec_6144 = vec_9;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_12 = _mm512_set1_ps(scal_5);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6145);
										mem_vec_6145 = vec_11;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_14 = _mm512_set1_ps(scal_6);
										vec_15 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_13 = _mm512_fmadd_ps(vec_14, vec_15, mem_vec_6140);
										mem_vec_6140 = vec_13;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_17 = _mm512_set1_ps(scal_7);


										vec_16 = _mm512_fmadd_ps(vec_17, vec_15, mem_vec_6141);
										mem_vec_6141 = vec_16;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_19 = _mm512_set1_ps(scal_8);


										vec_18 = _mm512_fmadd_ps(vec_19, vec_15, mem_vec_6142);
										mem_vec_6142 = vec_18;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_21 = _mm512_set1_ps(scal_9);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_15, mem_vec_6143);
										mem_vec_6143 = vec_20;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
										vec_23 = _mm512_set1_ps(scal_10);


										vec_22 = _mm512_fmadd_ps(vec_23, vec_15, mem_vec_6144);
										mem_vec_6144 = vec_22;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
										vec_25 = _mm512_set1_ps(scal_11);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_15, mem_vec_6145);
										mem_vec_6145 = vec_24;
										scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_27 = _mm512_set1_ps(scal_12);
										vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_6140);
										mem_vec_6140 = vec_26;
										scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_30 = _mm512_set1_ps(scal_13);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_28, mem_vec_6141);
										mem_vec_6141 = vec_29;
										scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_32 = _mm512_set1_ps(scal_14);


										vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_6142);
										mem_vec_6142 = vec_31;
										scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_34 = _mm512_set1_ps(scal_15);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_28, mem_vec_6143);
										mem_vec_6143 = vec_33;
										scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
										vec_36 = _mm512_set1_ps(scal_16);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_28, mem_vec_6144);
										mem_vec_6144 = vec_35;
										scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
										vec_38 = _mm512_set1_ps(scal_17);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_6145);
										mem_vec_6145 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6145);
						}
					}
				}
		}
	}
}


}