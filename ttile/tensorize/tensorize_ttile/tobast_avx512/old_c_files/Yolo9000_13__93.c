#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (17, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (64, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1116_p_0, cp_1, c1116, f, fp_0, x, xp_0, x1488_p_0, x1489_p_0, xp_1, x1488_p_1, xp_2, x1488, x1489, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y744 = 0;
IND_TYPE x1490 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1117 = 0;
IND_TYPE f744 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_15624 ,mem_vec_15625 ,mem_vec_15626 ,mem_vec_15627 ,mem_vec_15628 ,mem_vec_15629 ,mem_vec_15630 ,mem_vec_15631 ,mem_vec_15632 ,mem_vec_15633 ,mem_vec_15634 ,mem_vec_15635 ,mem_vec_15636 ,mem_vec_15637 ,mem_vec_15638 ,mem_vec_15639 ,mem_vec_15640 ,mem_vec_15641 ,mem_vec_15642 ,mem_vec_15643 ,mem_vec_15644 ,mem_vec_15645 ,mem_vec_15646 ,mem_vec_15647 ,mem_vec_15648 ,mem_vec_15649 ,mem_vec_15650 ,mem_vec_15651 ,mem_vec_15652 ,mem_vec_15653 ,mem_vec_15654 ,mem_vec_15655 ,mem_vec_15656 ,mem_vec_15657 ,mem_vec_15658 ,mem_vec_15659 ,mem_vec_15660 ,mem_vec_15661 ,mem_vec_15662 ,mem_vec_15663 ,mem_vec_15664 ,mem_vec_15665 ,mem_vec_15666 ,mem_vec_15667 ,mem_vec_15668 ,mem_vec_15669 ,mem_vec_15670 ,mem_vec_15671 ,mem_vec_15672 ,mem_vec_15673 ,mem_vec_15674 ,mem_vec_15675 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
for (x1489 = x1490, x1489_p_0 = 0;
	x1489 < x1490 + 34;
	x1489 += 17, x1489_p_0 += 17){
	// y = 34, x = 17, h = 1, w = 1, c = 512, f = 256
	// T (c, 64) (512 / 8)
	for (c1116 = c1117, c1116_p_0 = 0;
		c1116 < c1117 + 512;
		c1116 += 8, c1116_p_0 += 8){
		// y = 34, x = 17, h = 1, w = 1, c = 8, f = 256
		// T (f, 4) (256 / 64)
		for (f = f744, fp_0 = 0;
			f < f744 + 256;
			f += 64, fp_0 += 64){
				for (y = y744, yp_0 = 0;
					y < y744 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
					// T (x, 1) (17 / 17)
					for (x1488 = x1489, x1488_p_1 = x1489_p_0, x1488_p_0 = 0;
						x1488 < x1489 + 17;
						x1488 += 17, x1488_p_1 += 17, x1488_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
						// T (x, 17) (17 / 1)
						for (x = x1488, xp_2 = x1488_p_1, xp_1 = x1488_p_0, xp_0 = 0;
							x < x1488 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15624 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15625 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15626 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15627 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_15628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_15631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_15632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_15635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_15636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_15639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_15640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_15643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_15644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_15647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1116, cp_1 = c1116_p_0, cp_0 = 0;
										c < c1116 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15624);
										mem_vec_15624 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15625);
										mem_vec_15625 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15626);
										mem_vec_15626 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15627);
										mem_vec_15627 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15628);
										mem_vec_15628 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15629);
										mem_vec_15629 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15630);
										mem_vec_15630 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15631);
										mem_vec_15631 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15632);
										mem_vec_15632 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15633);
										mem_vec_15633 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15634);
										mem_vec_15634 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15635);
										mem_vec_15635 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15636);
										mem_vec_15636 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15637);
										mem_vec_15637 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15638);
										mem_vec_15638 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15639);
										mem_vec_15639 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15640);
										mem_vec_15640 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15641);
										mem_vec_15641 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15642);
										mem_vec_15642 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15643);
										mem_vec_15643 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15644);
										mem_vec_15644 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15645);
										mem_vec_15645 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15646);
										mem_vec_15646 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15647);
										mem_vec_15647 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15629);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15631);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15635);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15636);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15637);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15638);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15639);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15640);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15641);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15642);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15643);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15644);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15645);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15646);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15647);
						}
					}
				}
				for (y = y744 + 6, yp_0 = 0;
					y < y744 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
					// T (x, 1) (17 / 17)
					for (x1488 = x1489, x1488_p_1 = x1489_p_0, x1488_p_0 = 0;
						x1488 < x1489 + 17;
						x1488 += 17, x1488_p_1 += 17, x1488_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
						// T (x, 17) (17 / 1)
						for (x = x1488, xp_2 = x1488_p_1, xp_1 = x1488_p_0, xp_0 = 0;
							x < x1488 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15648 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15649 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15650 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15651 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_15652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_15655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_15656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_15659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_15660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_15663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_15664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_15667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_15668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_15671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_15672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_15675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1116, cp_1 = c1116_p_0, cp_0 = 0;
										c < c1116 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15648);
										mem_vec_15648 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15649);
										mem_vec_15649 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15650);
										mem_vec_15650 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15651);
										mem_vec_15651 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15652);
										mem_vec_15652 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15653);
										mem_vec_15653 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15654);
										mem_vec_15654 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15655);
										mem_vec_15655 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15656);
										mem_vec_15656 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15657);
										mem_vec_15657 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15658);
										mem_vec_15658 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15659);
										mem_vec_15659 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15660);
										mem_vec_15660 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15661);
										mem_vec_15661 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15662);
										mem_vec_15662 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15663);
										mem_vec_15663 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15664);
										mem_vec_15664 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15665);
										mem_vec_15665 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15666);
										mem_vec_15666 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15667);
										mem_vec_15667 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15668);
										mem_vec_15668 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15669);
										mem_vec_15669 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15670);
										mem_vec_15670 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15671);
										mem_vec_15671 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_15672);
										mem_vec_15672 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_15673);
										mem_vec_15673 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_15674);
										mem_vec_15674 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_15675);
										mem_vec_15675 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15648);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15649);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15650);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15651);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15652);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15653);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15654);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15655);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15656);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15657);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15658);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15659);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15660);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15661);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15662);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15663);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15664);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15665);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15666);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15667);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15668);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15669);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15670);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15671);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15672);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15673);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_15674);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_15675);
						}
					}
				}
		}
	}
}


}