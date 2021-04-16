#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (16, c);
  T (1, y); T (8, f); T (1, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]]
*/
IND_TYPE c, cp_0, c64_p_0, c65_p_0, cp_1, c64_p_1, cp_2, c64, c65, f, fp_0, x, xp_0, y, yp_0, y48_p_0, yp_1, y48;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y49 = 0;
IND_TYPE x32 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c66 = 0;
IND_TYPE f32 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y48 = y49, y48_p_0 = 0;
		y48 < y49 + 5;
		y48 += 5, y48_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c65 = c66, c65_p_0 = 0;
			c65 < c66 + 1024;
			c65 += 1024, c65_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f32, fp_0 = 0;
				f < f32 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y48, yp_1 = y48_p_0, yp_0 = 0;
					y < y48 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 16) (1024 / 64)
					for (c64 = c65, c64_p_1 = c65_p_0, c64_p_0 = 0;
						c64 < c65 + 1024;
						c64 += 64, c64_p_1 += 64, c64_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x32, xp_0 = 0;
							x < x32 + 17;
							x += 1, xp_0 += 1){
									mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c64, cp_2 = c64_p_1, cp_1 = c64_p_0, cp_0 = 0;
										c < c64 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_656);
										mem_vec_656 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_657);
										mem_vec_657 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_658);
										mem_vec_658 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_659);
										mem_vec_659 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_660);
										mem_vec_660 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_661);
										mem_vec_661 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_662);
										mem_vec_662 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_663);
										mem_vec_663 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_664);
										mem_vec_664 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_665);
										mem_vec_665 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_666);
										mem_vec_666 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_667);
										mem_vec_667 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_668);
										mem_vec_668 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_669);
										mem_vec_669 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_670);
										mem_vec_670 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_671);
										mem_vec_671 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_672);
										mem_vec_672 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_673);
										mem_vec_673 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_674);
										mem_vec_674 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_675);
										mem_vec_675 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_656);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_657);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_658);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_659);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_660);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_661);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_662);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_663);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_664);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_665);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_666);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_667);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_668);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_669);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_670);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_671);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_672);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_673);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_674);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_675);
						}
					}
				}
			}
		}
	}
	for (y48 = y49 + 5, y48_p_0 = 0;
		y48 < y49 + 5 + 12;
		y48 += 6, y48_p_0 += 6){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c65 = c66, c65_p_0 = 0;
			c65 < c66 + 1024;
			c65 += 1024, c65_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f32, fp_0 = 0;
				f < f32 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y48, yp_1 = y48_p_0, yp_0 = 0;
					y < y48 + 6;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 16) (1024 / 64)
					for (c64 = c65, c64_p_1 = c65_p_0, c64_p_0 = 0;
						c64 < c65 + 1024;
						c64 += 64, c64_p_1 += 64, c64_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x32, xp_0 = 0;
							x < x32 + 17;
							x += 1, xp_0 += 1){
									mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c64, cp_2 = c64_p_1, cp_1 = c64_p_0, cp_0 = 0;
										c < c64 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_676);
										mem_vec_676 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_677);
										mem_vec_677 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_678);
										mem_vec_678 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_679);
										mem_vec_679 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_680);
										mem_vec_680 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_681);
										mem_vec_681 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_682);
										mem_vec_682 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_683);
										mem_vec_683 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_684);
										mem_vec_684 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_685);
										mem_vec_685 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_686);
										mem_vec_686 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_687);
										mem_vec_687 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_688);
										mem_vec_688 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_689);
										mem_vec_689 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_690);
										mem_vec_690 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_691);
										mem_vec_691 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_692);
										mem_vec_692 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_693);
										mem_vec_693 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_694);
										mem_vec_694 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_695);
										mem_vec_695 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_696);
										mem_vec_696 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_697);
										mem_vec_697 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_698);
										mem_vec_698 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_699);
										mem_vec_699 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_676);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_677);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_678);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_679);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_680);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_681);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_682);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_683);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_684);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_685);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_686);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_687);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_688);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_689);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_690);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_691);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_692);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_693);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_694);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_695);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_696);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_697);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_698);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_699);
						}
					}
				}
			}
		}
	}


}