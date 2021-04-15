#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (256, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1168_p_0, c1169_p_0, cp_1, c1168_p_1, cp_2, c1168, c1169, f, fp_0, x, xp_0, x876_p_0, xp_1, x876, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y584 = 0;
IND_TYPE x877 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1170 = 0;
IND_TYPE f584 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_9816 ,mem_vec_9817 ,mem_vec_9818 ,mem_vec_9819 ,mem_vec_9820 ,mem_vec_9821 ,mem_vec_9822 ,mem_vec_9823 ,mem_vec_9824 ,mem_vec_9825 ,mem_vec_9826 ,mem_vec_9827 ,mem_vec_9828 ,mem_vec_9829 ,mem_vec_9830 ,mem_vec_9831 ,mem_vec_9832 ,mem_vec_9833 ,mem_vec_9834 ,mem_vec_9835 ,mem_vec_9836 ,mem_vec_9837 ,mem_vec_9838 ,mem_vec_9839 ,mem_vec_9840 ,mem_vec_9841 ,mem_vec_9842 ,mem_vec_9843 ,mem_vec_9844 ,mem_vec_9845 ,mem_vec_9846 ,mem_vec_9847 ,mem_vec_9848 ,mem_vec_9849 ,mem_vec_9850 ,mem_vec_9851 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 2) (1024 / 512)
for (c1169 = c1170, c1169_p_0 = 0;
	c1169 < c1170 + 1024;
	c1169 += 512, c1169_p_0 += 512){
		for (y = y584, yp_0 = 0;
			y < y584 + 12;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (x, 17) (17 / 1)
			for (x876 = x877, x876_p_0 = 0;
				x876 < x877 + 17;
				x876 += 1, x876_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 512
				// T (f, 8) (512 / 64)
				for (f = f584, fp_0 = 0;
					f < f584 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 64
					// T (c, 256) (512 / 2)
					for (c1168 = c1169, c1168_p_1 = c1169_p_0, c1168_p_0 = 0;
						c1168 < c1169 + 512;
						c1168 += 2, c1168_p_1 += 2, c1168_p_0 += 2){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x876, xp_1 = x876_p_0, xp_0 = 0;
							x < x876 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9816 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9817 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9818 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9819 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1168, cp_2 = c1168_p_1, cp_1 = c1168_p_0, cp_0 = 0;
										c < c1168 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9816);
										mem_vec_9816 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9817);
										mem_vec_9817 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9818);
										mem_vec_9818 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9819);
										mem_vec_9819 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9820);
										mem_vec_9820 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9821);
										mem_vec_9821 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9822);
										mem_vec_9822 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9823);
										mem_vec_9823 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9824);
										mem_vec_9824 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9825);
										mem_vec_9825 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9826);
										mem_vec_9826 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9827);
										mem_vec_9827 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9828);
										mem_vec_9828 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9829);
										mem_vec_9829 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9830);
										mem_vec_9830 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9831);
										mem_vec_9831 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9816);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9817);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9818);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9819);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9820);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9821);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9822);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9823);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9824);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9825);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9826);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9827);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9828);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9829);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9830);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9831);
						}
					}
				}
			}
		}
		for (y = y584 + 12, yp_0 = 0;
			y < y584 + 12 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (x, 17) (17 / 1)
			for (x876 = x877, x876_p_0 = 0;
				x876 < x877 + 17;
				x876 += 1, x876_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 512
				// T (f, 8) (512 / 64)
				for (f = f584, fp_0 = 0;
					f < f584 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 64
					// T (c, 256) (512 / 2)
					for (c1168 = c1169, c1168_p_1 = c1169_p_0, c1168_p_0 = 0;
						c1168 < c1169 + 512;
						c1168 += 2, c1168_p_1 += 2, c1168_p_0 += 2){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x876, xp_1 = x876_p_0, xp_0 = 0;
							x < x876 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9832 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9833 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9834 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9835 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_9848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_9851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1168, cp_2 = c1168_p_1, cp_1 = c1168_p_0, cp_0 = 0;
										c < c1168 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9832);
										mem_vec_9832 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9833);
										mem_vec_9833 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9834);
										mem_vec_9834 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9835);
										mem_vec_9835 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9836);
										mem_vec_9836 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9837);
										mem_vec_9837 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9838);
										mem_vec_9838 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9839);
										mem_vec_9839 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9840);
										mem_vec_9840 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9841);
										mem_vec_9841 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9842);
										mem_vec_9842 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9843);
										mem_vec_9843 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9844);
										mem_vec_9844 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9845);
										mem_vec_9845 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9846);
										mem_vec_9846 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9847);
										mem_vec_9847 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9848);
										mem_vec_9848 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9849);
										mem_vec_9849 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9850);
										mem_vec_9850 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9851);
										mem_vec_9851 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9832);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9833);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9834);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9835);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9836);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9837);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9838);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9839);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9840);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9841);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9842);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9843);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9844);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9845);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9846);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9847);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9848);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9849);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9850);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9851);
						}
					}
				}
			}
		}
}


}