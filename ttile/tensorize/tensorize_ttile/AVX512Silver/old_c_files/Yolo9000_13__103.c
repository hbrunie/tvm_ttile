#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (2, c);
  T (4, f); T (2, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]]
*/
IND_TYPE c, cp_0, c54_p_0, cp_1, c54, f, fp_0, x, xp_0, x72_p_0, x73_p_0, xp_1, x72_p_1, xp_2, x72, x73, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y36 = 0;
IND_TYPE x74 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c55 = 0;
IND_TYPE f36 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_824 ,mem_vec_825 ,mem_vec_826 ,mem_vec_827 ,mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,mem_vec_836 ,mem_vec_837 ,mem_vec_838 ,mem_vec_839 ,mem_vec_840 ,mem_vec_841 ,mem_vec_842 ,mem_vec_843 ,mem_vec_844 ,mem_vec_845 ,mem_vec_846 ,mem_vec_847 ,mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y = y36, yp_0 = 0;
		y < y36 + 4;
		y += 4, yp_0 += 4){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x73 = x74, x73_p_0 = 0;
			x73 < x74 + 34;
			x73 += 34, x73_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (x, 2) (34 / 17)
			for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
				x72 < x73 + 34;
				x72 += 17, x72_p_1 += 17, x72_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f36, fp_0 = 0;
					f < f36 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 2) (512 / 256)
					for (c54 = c55, c54_p_0 = 0;
						c54 < c55 + 512;
						c54 += 256, c54_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
							x < x72 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_824 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_825 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_826 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_827 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
										c < c54 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_824);
										mem_vec_824 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_825);
										mem_vec_825 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_826);
										mem_vec_826 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_827);
										mem_vec_827 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_828);
										mem_vec_828 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_829);
										mem_vec_829 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_830);
										mem_vec_830 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_831);
										mem_vec_831 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_832);
										mem_vec_832 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_833);
										mem_vec_833 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_834);
										mem_vec_834 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_835);
										mem_vec_835 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_836);
										mem_vec_836 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_837);
										mem_vec_837 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_838);
										mem_vec_838 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_839);
										mem_vec_839 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_824);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_825);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_826);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_827);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_828);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_829);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_830);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_831);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_832);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_833);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_834);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_835);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_836);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_837);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_838);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_839);
						}
					}
				}
			}
		}
	}
	for (y = y36 + 4, yp_0 = 0;
		y < y36 + 4 + 30;
		y += 6, yp_0 += 6){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x73 = x74, x73_p_0 = 0;
			x73 < x74 + 34;
			x73 += 34, x73_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (x, 2) (34 / 17)
			for (x72 = x73, x72_p_1 = x73_p_0, x72_p_0 = 0;
				x72 < x73 + 34;
				x72 += 17, x72_p_1 += 17, x72_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f36, fp_0 = 0;
					f < f36 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 2) (512 / 256)
					for (c54 = c55, c54_p_0 = 0;
						c54 < c55 + 512;
						c54 += 256, c54_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x72, xp_2 = x72_p_1, xp_1 = x72_p_0, xp_0 = 0;
							x < x72 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_840 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_841 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_842 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c54, cp_1 = c54_p_0, cp_0 = 0;
										c < c54 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_840);
										mem_vec_840 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_841);
										mem_vec_841 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_842);
										mem_vec_842 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_843);
										mem_vec_843 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_844);
										mem_vec_844 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_845);
										mem_vec_845 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_846);
										mem_vec_846 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_847);
										mem_vec_847 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_848);
										mem_vec_848 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_849);
										mem_vec_849 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_850);
										mem_vec_850 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_851);
										mem_vec_851 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_852);
										mem_vec_852 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_853);
										mem_vec_853 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_854);
										mem_vec_854 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_855);
										mem_vec_855 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_856);
										mem_vec_856 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_857);
										mem_vec_857 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_858);
										mem_vec_858 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_859);
										mem_vec_859 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_860);
										mem_vec_860 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_861);
										mem_vec_861 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_862);
										mem_vec_862 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_863);
										mem_vec_863 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_840);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_841);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_842);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_843);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_844);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_845);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_846);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_847);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_848);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_849);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_850);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_851);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_852);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_853);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_854);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_855);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_856);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_857);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_858);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_859);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_860);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_861);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_862);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_863);
						}
					}
				}
			}
		}
	}


}