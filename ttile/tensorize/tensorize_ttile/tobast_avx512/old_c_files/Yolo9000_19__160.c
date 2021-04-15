#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (128, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, c)]
*/
IND_TYPE c, cp_0, c1144_p_0, c1145_p_0, cp_1, c1144_p_1, cp_2, c1144, c1145, f, fp_0, x, xp_0, x858_p_0, xp_1, x858, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y572 = 0;
IND_TYPE x859 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1146 = 0;
IND_TYPE f572 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_9600 ,mem_vec_9601 ,mem_vec_9602 ,mem_vec_9603 ,mem_vec_9604 ,mem_vec_9605 ,mem_vec_9606 ,mem_vec_9607 ,mem_vec_9608 ,mem_vec_9609 ,mem_vec_9610 ,mem_vec_9611 ,mem_vec_9612 ,mem_vec_9613 ,mem_vec_9614 ,mem_vec_9615 ,mem_vec_9616 ,mem_vec_9617 ,mem_vec_9618 ,mem_vec_9619 ,mem_vec_9620 ,mem_vec_9621 ,mem_vec_9622 ,mem_vec_9623 ,mem_vec_9624 ,mem_vec_9625 ,mem_vec_9626 ,mem_vec_9627 ,mem_vec_9628 ,mem_vec_9629 ,mem_vec_9630 ,mem_vec_9631 ,mem_vec_9632 ,mem_vec_9633 ,mem_vec_9634 ,mem_vec_9635 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 1) (1024 / 1024)
for (c1145 = c1146, c1145_p_0 = 0;
	c1145 < c1146 + 1024;
	c1145 += 1024, c1145_p_0 += 1024){
		for (y = y572, yp_0 = 0;
			y < y572 + 12;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (x, 17) (17 / 1)
			for (x858 = x859, x858_p_0 = 0;
				x858 < x859 + 17;
				x858 += 1, x858_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 512
				// T (f, 8) (512 / 64)
				for (f = f572, fp_0 = 0;
					f < f572 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 64
					// T (c, 128) (1024 / 8)
					for (c1144 = c1145, c1144_p_1 = c1145_p_0, c1144_p_0 = 0;
						c1144 < c1145 + 1024;
						c1144 += 8, c1144_p_1 += 8, c1144_p_0 += 8){
						// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (x, 1) (1 / 1)
						for (x = x858, xp_1 = x858_p_0, xp_0 = 0;
							x < x858 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9600 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9601 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9602 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9603 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1144, cp_2 = c1144_p_1, cp_1 = c1144_p_0, cp_0 = 0;
										c < c1144 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9600);
										mem_vec_9600 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9601);
										mem_vec_9601 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9602);
										mem_vec_9602 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9603);
										mem_vec_9603 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9604);
										mem_vec_9604 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9605);
										mem_vec_9605 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9606);
										mem_vec_9606 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9607);
										mem_vec_9607 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9608);
										mem_vec_9608 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9609);
										mem_vec_9609 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9610);
										mem_vec_9610 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9611);
										mem_vec_9611 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9612);
										mem_vec_9612 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9613);
										mem_vec_9613 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9614);
										mem_vec_9614 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9615);
										mem_vec_9615 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9600);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9601);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9602);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9603);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9604);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9605);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9606);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9607);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9608);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9609);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9610);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9611);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9612);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9613);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9614);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9615);
						}
					}
				}
			}
		}
		for (y = y572 + 12, yp_0 = 0;
			y < y572 + 12 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (x, 17) (17 / 1)
			for (x858 = x859, x858_p_0 = 0;
				x858 < x859 + 17;
				x858 += 1, x858_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 512
				// T (f, 8) (512 / 64)
				for (f = f572, fp_0 = 0;
					f < f572 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 64
					// T (c, 128) (1024 / 8)
					for (c1144 = c1145, c1144_p_1 = c1145_p_0, c1144_p_0 = 0;
						c1144 < c1145 + 1024;
						c1144 += 8, c1144_p_1 += 8, c1144_p_0 += 8){
						// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (x, 1) (1 / 1)
						for (x = x858, xp_1 = x858_p_0, xp_0 = 0;
							x < x858 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9616 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9617 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9618 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9619 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_9632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_9635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1144, cp_2 = c1144_p_1, cp_1 = c1144_p_0, cp_0 = 0;
										c < c1144 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9616);
										mem_vec_9616 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9617);
										mem_vec_9617 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9618);
										mem_vec_9618 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9619);
										mem_vec_9619 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9620);
										mem_vec_9620 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9621);
										mem_vec_9621 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9622);
										mem_vec_9622 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9623);
										mem_vec_9623 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9624);
										mem_vec_9624 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9625);
										mem_vec_9625 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9626);
										mem_vec_9626 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9627);
										mem_vec_9627 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9628);
										mem_vec_9628 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9629);
										mem_vec_9629 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9630);
										mem_vec_9630 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9631);
										mem_vec_9631 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9632);
										mem_vec_9632 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9633);
										mem_vec_9633 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9634);
										mem_vec_9634 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9635);
										mem_vec_9635 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9616);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9617);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9618);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9619);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9620);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9621);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9622);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9623);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9629);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9631);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9635);
						}
					}
				}
			}
		}
}


}