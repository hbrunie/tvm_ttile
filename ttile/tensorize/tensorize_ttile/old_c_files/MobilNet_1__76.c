#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (112, x); T (2, y); T (1, c);
  Lambda_apply y [((Iter 3), (Arg 10)); ((Iter 2), (Arg 13))]]
*/
IND_TYPE c, cp_0, c63_p_0, cp_1, c63, h, hp_0, w, wp_0, x, xp_0, y, yp_0, y63_p_0, yp_1, y63;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y64 = 0;
IND_TYPE x42 = 0;
IND_TYPE h42 = 0;
IND_TYPE w42 = 0;
IND_TYPE c64 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,mem_vec_822 ,mem_vec_823 ,mem_vec_824 ,mem_vec_825 ,mem_vec_826 ,mem_vec_827 ,mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y63 = y64, y63_p_0 = 0;
		y63 < y64 + 60;
		y63 += 20, y63_p_0 += 20){
		// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c63 = c64, c63_p_0 = 0;
			c63 < c64 + 32;
			c63 += 32, c63_p_0 += 32){
			// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
				y < y63 + 20;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x42, xp_0 = 0;
					x < x42 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h42, hp_0 = 0;
						h < h42 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w42, wp_0 = 0;
							w < w42 + 3;
							w += 1, wp_0 += 1){
									mem_vec_814 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_815 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
										c < c63 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_814);
										mem_vec_814 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_815);
										mem_vec_815 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_816);
										mem_vec_816 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_817);
										mem_vec_817 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_818);
										mem_vec_818 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_819);
										mem_vec_819 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_820);
										mem_vec_820 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_821);
										mem_vec_821 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_822);
										mem_vec_822 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_823);
										mem_vec_823 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_824);
										mem_vec_824 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_825);
										mem_vec_825 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_826);
										mem_vec_826 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_827);
										mem_vec_827 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_828);
										mem_vec_828 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_829);
										mem_vec_829 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_830);
										mem_vec_830 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_831);
										mem_vec_831 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_832);
										mem_vec_832 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_833);
										mem_vec_833 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_814);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_815);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_816);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_817);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_818);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_819);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_820);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_821);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_822);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_823);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_824);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_825);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_826);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_827);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_828);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_829);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_830);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_831);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_832);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_833);
						}
					}
				}
			}
		}
	}
	for (y63 = y64 + 60, y63_p_0 = 0;
		y63 < y64 + 60 + 52;
		y63 += 26, y63_p_0 += 26){
		// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (c, 1) (32 / 32)
		for (c63 = c64, c63_p_0 = 0;
			c63 < c64 + 32;
			c63 += 32, c63_p_0 += 32){
			// y = 2 * ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
				y < y63 + 26;
				y += 13, yp_1 += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 3, w = 3, c = 32, f = 32
				// T (x, 112) (112 / 1)
				for (x = x42, xp_0 = 0;
					x < x42 + 112;
					x += 1, xp_0 += 1){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (h, 3) (3 / 1)
					for (h = h42, hp_0 = 0;
						h < h42 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w42, wp_0 = 0;
							w < w42 + 3;
							w += 1, wp_0 += 1){
									mem_vec_834 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_835 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
										c < c63 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_834);
										mem_vec_834 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_835);
										mem_vec_835 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_836);
										mem_vec_836 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_837);
										mem_vec_837 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_838);
										mem_vec_838 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_839);
										mem_vec_839 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_840);
										mem_vec_840 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_841);
										mem_vec_841 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_842);
										mem_vec_842 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_843);
										mem_vec_843 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_844);
										mem_vec_844 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_845);
										mem_vec_845 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_846);
										mem_vec_846 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_847);
										mem_vec_847 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_848);
										mem_vec_848 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_849);
										mem_vec_849 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_850);
										mem_vec_850 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_851);
										mem_vec_851 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_852);
										mem_vec_852 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_853);
										mem_vec_853 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_854);
										mem_vec_854 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_855);
										mem_vec_855 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_856);
										mem_vec_856 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_857);
										mem_vec_857 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_858);
										mem_vec_858 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_859);
										mem_vec_859 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_834);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_835);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_836);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_837);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_838);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_839);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_840);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_841);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_842);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_843);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_844);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_845);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_846);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_847);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_848);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_849);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_850);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_851);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_852);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_853);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_854);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_855);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_856);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_857);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_858);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_859);
						}
					}
				}
			}
		}
	}


}