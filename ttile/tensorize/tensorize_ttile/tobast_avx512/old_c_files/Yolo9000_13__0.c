#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (1, x); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (8, f);
  T (128, c); T (1, x)]
*/
IND_TYPE c, cp_0, c60_p_0, cp_1, c60, f, fp_0, x, xp_0, x80_p_0, x81_p_0, xp_1, x80_p_1, xp_2, x80, x81, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y40 = 0;
IND_TYPE x82 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c61 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x81 = x82, x81_p_0 = 0;
	x81 < x82 + 34;
	x81 += 34, x81_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 128) (512 / 4)
	for (c60 = c61, c60_p_0 = 0;
		c60 < c61 + 512;
		c60 += 4, c60_p_0 += 4){
		// y = 34, x = 34, h = 1, w = 1, c = 4, f = 256
		// T (f, 8) (256 / 32)
		for (f = f40, fp_0 = 0;
			f < f40 + 256;
			f += 32, fp_0 += 32){
				for (y = y40, yp_0 = 0;
					y < y40 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
					// T (x, 34) (34 / 1)
					for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
						x80 < x81 + 34;
						x80 += 1, x80_p_1 += 1, x80_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
						// T (x, 1) (1 / 1)
						for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
							x < x80 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
										c < c60 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_640);
										mem_vec_640 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_641);
										mem_vec_641 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_642);
										mem_vec_642 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_643);
										mem_vec_643 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_644);
										mem_vec_644 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_645);
										mem_vec_645 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_646);
										mem_vec_646 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_647);
										mem_vec_647 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_648);
										mem_vec_648 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_649);
										mem_vec_649 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_650);
										mem_vec_650 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_651);
										mem_vec_651 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_652);
										mem_vec_652 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_653);
										mem_vec_653 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_640);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_641);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_642);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_643);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_644);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_645);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_646);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_647);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_648);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_649);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_650);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_651);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_652);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_653);
						}
					}
				}
				for (y = y40 + 7, yp_0 = 0;
					y < y40 + 7 + 27;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
					// T (x, 34) (34 / 1)
					for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
						x80 < x81 + 34;
						x80 += 1, x80_p_1 += 1, x80_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
						// T (x, 1) (1 / 1)
						for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
							x < x80 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c60, cp_1 = c60_p_0, cp_0 = 0;
										c < c60 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_654);
										mem_vec_654 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_655);
										mem_vec_655 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_656);
										mem_vec_656 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_657);
										mem_vec_657 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_658);
										mem_vec_658 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_659);
										mem_vec_659 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_660);
										mem_vec_660 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_661);
										mem_vec_661 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_662);
										mem_vec_662 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_663);
										mem_vec_663 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_664);
										mem_vec_664 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_665);
										mem_vec_665 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_666);
										mem_vec_666 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_667);
										mem_vec_667 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_668);
										mem_vec_668 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_669);
										mem_vec_669 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_670);
										mem_vec_670 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_671);
										mem_vec_671 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_654);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_655);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_656);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_657);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_658);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_659);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_660);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_661);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_662);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_663);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_664);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_665);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_666);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_667);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_668);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_669);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_670);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_671);
						}
					}
				}
		}
	}
}


}