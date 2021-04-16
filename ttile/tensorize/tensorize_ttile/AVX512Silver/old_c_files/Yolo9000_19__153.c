#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (1, y); T (8, f); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]]
*/
IND_TYPE c, cp_0, c60_p_0, c61_p_0, cp_1, c60_p_1, cp_2, c60, c61, f, fp_0, x, xp_0, y, yp_0, y45_p_0, yp_1, y45;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y46 = 0;
IND_TYPE x30 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c62 = 0;
IND_TYPE f30 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y45 = y46, y45_p_0 = 0;
		y45 < y46 + 5;
		y45 += 5, y45_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c61 = c62, c61_p_0 = 0;
			c61 < c62 + 1024;
			c61 += 1024, c61_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f30, fp_0 = 0;
				f < f30 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
					y < y45 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 8) (1024 / 128)
					for (c60 = c61, c60_p_1 = c61_p_0, c60_p_0 = 0;
						c60 < c61 + 1024;
						c60 += 128, c60_p_1 += 128, c60_p_0 += 128){
						// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
						// T (x, 17) (17 / 1)
						for (x = x30, xp_0 = 0;
							x < x30 + 17;
							x += 1, xp_0 += 1){
									mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c60, cp_2 = c60_p_1, cp_1 = c60_p_0, cp_0 = 0;
										c < c60 + 128;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_612);
										mem_vec_612 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_613);
										mem_vec_613 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_614);
										mem_vec_614 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_615);
										mem_vec_615 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_616);
										mem_vec_616 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_617);
										mem_vec_617 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_618);
										mem_vec_618 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_619);
										mem_vec_619 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_620);
										mem_vec_620 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_621);
										mem_vec_621 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_622);
										mem_vec_622 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_623);
										mem_vec_623 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_624);
										mem_vec_624 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_625);
										mem_vec_625 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_626);
										mem_vec_626 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_627);
										mem_vec_627 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_628);
										mem_vec_628 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_629);
										mem_vec_629 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_630);
										mem_vec_630 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_631);
										mem_vec_631 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_612);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_613);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_614);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_615);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_616);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_617);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_618);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_619);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_620);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_621);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_622);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_623);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_629);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_631);
						}
					}
				}
			}
		}
	}
	for (y45 = y46 + 5, y45_p_0 = 0;
		y45 < y46 + 5 + 12;
		y45 += 6, y45_p_0 += 6){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c61 = c62, c61_p_0 = 0;
			c61 < c62 + 1024;
			c61 += 1024, c61_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f30, fp_0 = 0;
				f < f30 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
					y < y45 + 6;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 8) (1024 / 128)
					for (c60 = c61, c60_p_1 = c61_p_0, c60_p_0 = 0;
						c60 < c61 + 1024;
						c60 += 128, c60_p_1 += 128, c60_p_0 += 128){
						// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
						// T (x, 17) (17 / 1)
						for (x = x30, xp_0 = 0;
							x < x30 + 17;
							x += 1, xp_0 += 1){
									mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c60, cp_2 = c60_p_1, cp_1 = c60_p_0, cp_0 = 0;
										c < c60 + 128;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_632);
										mem_vec_632 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_633);
										mem_vec_633 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_634);
										mem_vec_634 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_635);
										mem_vec_635 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_636);
										mem_vec_636 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_637);
										mem_vec_637 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_638);
										mem_vec_638 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_639);
										mem_vec_639 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_640);
										mem_vec_640 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_641);
										mem_vec_641 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_642);
										mem_vec_642 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_643);
										mem_vec_643 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_644);
										mem_vec_644 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_645);
										mem_vec_645 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_646);
										mem_vec_646 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_647);
										mem_vec_647 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_648);
										mem_vec_648 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_649);
										mem_vec_649 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_650);
										mem_vec_650 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_651);
										mem_vec_651 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_652);
										mem_vec_652 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_653);
										mem_vec_653 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_654);
										mem_vec_654 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_655);
										mem_vec_655 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_635);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_636);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_637);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_638);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_639);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_640);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_641);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_642);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_643);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_644);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_645);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_646);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_647);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_648);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_649);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_650);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_651);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_652);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_653);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_654);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_655);
						}
					}
				}
			}
		}
	}


}