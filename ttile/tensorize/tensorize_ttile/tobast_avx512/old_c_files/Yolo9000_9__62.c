#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (17, x);
  Lambda_apply y [((Iter 4), (Arg 7)); ((Iter 5), (Arg 8))]; T (4, f);
  T (4, c); T (2, x)]
*/
IND_TYPE c, cp_0, c126_p_0, cp_1, c126, f, fp_0, x, xp_0, x168_p_0, x169_p_0, xp_1, x168_p_1, xp_2, x168, x169, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y84 = 0;
IND_TYPE x170 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c127 = 0;
IND_TYPE f84 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,mem_vec_822 ,mem_vec_823 ,mem_vec_824 ,mem_vec_825 ,mem_vec_826 ,mem_vec_827 ,mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,mem_vec_840 ,mem_vec_841 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 2) (68 / 34)
for (x169 = x170, x169_p_0 = 0;
	x169 < x170 + 68;
	x169 += 34, x169_p_0 += 34){
	// y = 68, x = 34, h = 1, w = 1, c = 256, f = 128
	// T (c, 4) (256 / 64)
	for (c126 = c127, c126_p_0 = 0;
		c126 < c127 + 256;
		c126 += 64, c126_p_0 += 64){
		// y = 68, x = 34, h = 1, w = 1, c = 64, f = 128
		// T (f, 4) (128 / 32)
		for (f = f84, fp_0 = 0;
			f < f84 + 128;
			f += 32, fp_0 += 32){
				for (y = y84, yp_0 = 0;
					y < y84 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 64, f = 32
					// T (x, 17) (34 / 2)
					for (x168 = x169, x168_p_1 = x169_p_0, x168_p_0 = 0;
						x168 < x169 + 34;
						x168 += 2, x168_p_1 += 2, x168_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x = x168, xp_2 = x168_p_1, xp_1 = x168_p_0, xp_0 = 0;
							x < x168 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_812 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_813 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c126, cp_1 = c126_p_0, cp_0 = 0;
										c < c126 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_812);
										mem_vec_812 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_813);
										mem_vec_813 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_814);
										mem_vec_814 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_815);
										mem_vec_815 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_816);
										mem_vec_816 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_817);
										mem_vec_817 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_818);
										mem_vec_818 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_819);
										mem_vec_819 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_820);
										mem_vec_820 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_821);
										mem_vec_821 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_822);
										mem_vec_822 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_823);
										mem_vec_823 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_824);
										mem_vec_824 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_825);
										mem_vec_825 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_812);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_813);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_814);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_815);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_816);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_817);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_818);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_819);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_820);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_821);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_822);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_823);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_824);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_825);
						}
					}
				}
				for (y = y84 + 28, yp_0 = 0;
					y < y84 + 28 + 40;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 64, f = 32
					// T (x, 17) (34 / 2)
					for (x168 = x169, x168_p_1 = x169_p_0, x168_p_0 = 0;
						x168 < x169 + 34;
						x168 += 2, x168_p_1 += 2, x168_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
						// T (x, 2) (2 / 1)
						for (x = x168, xp_2 = x168_p_1, xp_1 = x168_p_0, xp_0 = 0;
							x < x168 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_826 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_827 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c126, cp_1 = c126_p_0, cp_0 = 0;
										c < c126 + 64;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_826);
										mem_vec_826 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_827);
										mem_vec_827 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_828);
										mem_vec_828 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_829);
										mem_vec_829 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_830);
										mem_vec_830 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_831);
										mem_vec_831 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_832);
										mem_vec_832 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_833);
										mem_vec_833 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_834);
										mem_vec_834 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_835);
										mem_vec_835 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_836);
										mem_vec_836 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_837);
										mem_vec_837 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_838);
										mem_vec_838 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_839);
										mem_vec_839 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_840);
										mem_vec_840 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_841);
										mem_vec_841 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_826);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_827);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_828);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_829);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_830);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_831);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_832);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_833);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_834);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_835);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_836);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_837);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_838);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_839);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_840);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_841);
						}
					}
				}
		}
	}
}


}