#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (4, f); T (1, x); T (2, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, f, fp_0, x, xp_0, x60_p_0, x61_p_0, xp_1, x60_p_1, xp_2, x60, x61, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y30 = 0;
IND_TYPE x62 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c46 = 0;
IND_TYPE f30 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y = y30, yp_0 = 0;
		y < y30 + 20;
		y += 4, yp_0 += 4){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 2) (34 / 17)
		for (x61 = x62, x61_p_0 = 0;
			x61 < x62 + 34;
			x61 += 17, x61_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
			// T (x, 1) (17 / 17)
			for (x60 = x61, x60_p_1 = x61_p_0, x60_p_0 = 0;
				x60 < x61 + 17;
				x60 += 17, x60_p_1 += 17, x60_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f30, fp_0 = 0;
					f < f30 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 8) (512 / 64)
					for (c45 = c46, c45_p_0 = 0;
						c45 < c46 + 512;
						c45 += 64, c45_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x60, xp_2 = x60_p_1, xp_1 = x60_p_0, xp_0 = 0;
							x < x60 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
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
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
										c < c45 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
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
						}
					}
				}
			}
		}
	}
	for (y = y30 + 20, yp_0 = 0;
		y < y30 + 20 + 14;
		y += 7, yp_0 += 7){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 2) (34 / 17)
		for (x61 = x62, x61_p_0 = 0;
			x61 < x62 + 34;
			x61 += 17, x61_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
			// T (x, 1) (17 / 17)
			for (x60 = x61, x60_p_1 = x61_p_0, x60_p_0 = 0;
				x60 < x61 + 17;
				x60 += 17, x60_p_1 += 17, x60_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f30, fp_0 = 0;
					f < f30 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 8) (512 / 64)
					for (c45 = c46, c45_p_0 = 0;
						c45 < c46 + 512;
						c45 += 64, c45_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x60, xp_2 = x60_p_1, xp_1 = x60_p_0, xp_0 = 0;
							x < x60 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
										c < c45 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_692);
										mem_vec_692 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_693);
										mem_vec_693 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_694);
										mem_vec_694 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_695);
										mem_vec_695 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_696);
										mem_vec_696 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_697);
										mem_vec_697 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_698);
										mem_vec_698 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_699);
										mem_vec_699 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_700);
										mem_vec_700 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_701);
										mem_vec_701 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_702);
										mem_vec_702 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_703);
										mem_vec_703 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_704);
										mem_vec_704 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_705);
										mem_vec_705 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_706);
										mem_vec_706 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_707);
										mem_vec_707 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_708);
										mem_vec_708 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_709);
										mem_vec_709 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_710);
										mem_vec_710 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_711);
										mem_vec_711 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_712);
										mem_vec_712 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_713);
										mem_vec_713 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_714);
										mem_vec_714 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_715);
										mem_vec_715 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_716);
										mem_vec_716 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_717);
										mem_vec_717 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_718);
										mem_vec_718 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_719);
										mem_vec_719 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_692);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_693);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_694);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_695);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_696);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_697);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_698);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_699);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_700);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_701);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_702);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_703);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_704);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_705);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_706);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_707);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_709);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_710);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_711);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_712);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_713);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_714);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_715);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_716);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_717);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_718);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_719);
						}
					}
				}
			}
		}
	}


}