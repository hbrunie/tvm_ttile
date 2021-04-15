#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (512, c); Hoist_vars [c]; T (17, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 7)); ((Iter 3), (Arg 9))]; T (8, f);
  T (1, c); T (2, x)]
*/
IND_TYPE c, cp_0, c66_p_0, cp_1, c66, f, fp_0, x, xp_0, x88_p_0, x89_p_0, xp_1, x88_p_1, xp_2, x88, x89, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y44 = 0;
IND_TYPE x90 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c67 = 0;
IND_TYPE f44 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
for (x89 = x90, x89_p_0 = 0;
	x89 < x90 + 34;
	x89 += 17, x89_p_0 += 17){
	// y = 34, x = 17, h = 1, w = 1, c = 512, f = 256
	// T (c, 1) (512 / 512)
	for (c66 = c67, c66_p_0 = 0;
		c66 < c67 + 512;
		c66 += 512, c66_p_0 += 512){
		// y = 34, x = 17, h = 1, w = 1, c = 512, f = 256
		// T (f, 8) (256 / 32)
		for (f = f44, fp_0 = 0;
			f < f44 + 256;
			f += 32, fp_0 += 32){
				for (y = y44, yp_0 = 0;
					y < y44 + 7;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
					// T (x, 1) (17 / 17)
					for (x88 = x89, x88_p_1 = x89_p_0, x88_p_0 = 0;
						x88 < x89 + 17;
						x88 += 17, x88_p_1 += 17, x88_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
						// T (x, 17) (17 / 1)
						for (x = x88, xp_2 = x88_p_1, xp_1 = x88_p_0, xp_0 = 0;
							x < x88 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
										c < c66 + 512;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_704);
										mem_vec_704 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_705);
										mem_vec_705 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_706);
										mem_vec_706 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_707);
										mem_vec_707 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_708);
										mem_vec_708 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_709);
										mem_vec_709 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_710);
										mem_vec_710 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_711);
										mem_vec_711 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_712);
										mem_vec_712 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_713);
										mem_vec_713 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_714);
										mem_vec_714 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_715);
										mem_vec_715 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_716);
										mem_vec_716 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_717);
										mem_vec_717 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_704);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_705);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_706);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_707);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_709);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_710);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_711);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_712);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_713);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_714);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_715);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_716);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_717);
						}
					}
				}
				for (y = y44 + 7, yp_0 = 0;
					y < y44 + 7 + 27;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
					// T (x, 1) (17 / 17)
					for (x88 = x89, x88_p_1 = x89_p_0, x88_p_0 = 0;
						x88 < x89 + 17;
						x88 += 17, x88_p_1 += 17, x88_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 32
						// T (x, 17) (17 / 1)
						for (x = x88, xp_2 = x88_p_1, xp_1 = x88_p_0, xp_0 = 0;
							x < x88 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 32
									// T (c, 512) (512 / 1)
									for (c = c66, cp_1 = c66_p_0, cp_0 = 0;
										c < c66 + 512;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_718);
										mem_vec_718 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_719);
										mem_vec_719 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_720);
										mem_vec_720 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_721);
										mem_vec_721 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_722);
										mem_vec_722 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_723);
										mem_vec_723 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_724);
										mem_vec_724 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_725);
										mem_vec_725 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_726);
										mem_vec_726 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_727);
										mem_vec_727 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_728);
										mem_vec_728 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_729);
										mem_vec_729 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_730);
										mem_vec_730 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_731);
										mem_vec_731 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_732);
										mem_vec_732 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_733);
										mem_vec_733 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_734);
										mem_vec_734 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_735);
										mem_vec_735 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_718);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_719);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_720);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_721);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_722);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_723);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_724);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_725);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_726);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_727);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_735);
						}
					}
				}
		}
	}
}


}