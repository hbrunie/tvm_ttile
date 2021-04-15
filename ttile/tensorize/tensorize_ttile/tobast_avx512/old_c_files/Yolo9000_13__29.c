#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (8, f);
  T (2, c); T (2, x)]
*/
IND_TYPE c, cp_0, c792_p_0, cp_1, c792, f, fp_0, x, xp_0, x1056_p_0, x1057_p_0, xp_1, x1056_p_1, xp_2, x1056, x1057, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y528 = 0;
IND_TYPE x1058 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c793 = 0;
IND_TYPE f528 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10828 ,mem_vec_10829 ,mem_vec_10830 ,mem_vec_10831 ,mem_vec_10832 ,mem_vec_10833 ,mem_vec_10834 ,mem_vec_10835 ,mem_vec_10836 ,mem_vec_10837 ,mem_vec_10838 ,mem_vec_10839 ,mem_vec_10840 ,mem_vec_10841 ,mem_vec_10842 ,mem_vec_10843 ,mem_vec_10844 ,mem_vec_10845 ,mem_vec_10846 ,mem_vec_10847 ,mem_vec_10848 ,mem_vec_10849 ,mem_vec_10850 ,mem_vec_10851 ,mem_vec_10852 ,mem_vec_10853 ,mem_vec_10854 ,mem_vec_10855 ,mem_vec_10856 ,mem_vec_10857 ,mem_vec_10858 ,mem_vec_10859 ,mem_vec_10860 ,mem_vec_10861 ,mem_vec_10862 ,mem_vec_10863 ,mem_vec_10864 ,mem_vec_10865 ,mem_vec_10866 ,mem_vec_10867 ,mem_vec_10868 ,mem_vec_10869 ,mem_vec_10870 ,mem_vec_10871 ,mem_vec_10872 ,mem_vec_10873 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
for (x1057 = x1058, x1057_p_0 = 0;
	x1057 < x1058 + 34;
	x1057 += 17, x1057_p_0 += 17){
	// y = 34, x = 17, h = 1, w = 1, c = 512, f = 256
	// T (c, 2) (512 / 256)
	for (c792 = c793, c792_p_0 = 0;
		c792 < c793 + 512;
		c792 += 256, c792_p_0 += 256){
		// y = 34, x = 17, h = 1, w = 1, c = 256, f = 256
		// T (f, 8) (256 / 32)
		for (f = f528, fp_0 = 0;
			f < f528 + 256;
			f += 32, fp_0 += 32){
				for (y = y528, yp_0 = 0;
					y < y528 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (x, 17) (17 / 1)
					for (x1056 = x1057, x1056_p_1 = x1057_p_0, x1056_p_0 = 0;
						x1056 < x1057 + 17;
						x1056 += 1, x1056_p_1 += 1, x1056_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1056, xp_2 = x1056_p_1, xp_1 = x1056_p_0, xp_0 = 0;
							x < x1056 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10828 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10829 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_10846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_10847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_10848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_10849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c792, cp_1 = c792_p_0, cp_0 = 0;
										c < c792 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10828);
										mem_vec_10828 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10829);
										mem_vec_10829 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10830);
										mem_vec_10830 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10831);
										mem_vec_10831 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10832);
										mem_vec_10832 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10833);
										mem_vec_10833 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10834);
										mem_vec_10834 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10835);
										mem_vec_10835 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10836);
										mem_vec_10836 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10837);
										mem_vec_10837 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10838);
										mem_vec_10838 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10839);
										mem_vec_10839 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10840);
										mem_vec_10840 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10841);
										mem_vec_10841 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10842);
										mem_vec_10842 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10843);
										mem_vec_10843 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10844);
										mem_vec_10844 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10845);
										mem_vec_10845 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10846);
										mem_vec_10846 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10847);
										mem_vec_10847 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10848);
										mem_vec_10848 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10849);
										mem_vec_10849 = vec_34;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10828);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10829);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10830);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10831);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10832);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10833);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10834);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10835);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10836);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10837);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10838);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10839);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10840);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10841);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10842);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10843);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10844);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10845);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10846);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10847);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10848);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10849);
						}
					}
				}
				for (y = y528 + 22, yp_0 = 0;
					y < y528 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 32
					// T (x, 17) (17 / 1)
					for (x1056 = x1057, x1056_p_1 = x1057_p_0, x1056_p_0 = 0;
						x1056 < x1057 + 17;
						x1056 += 1, x1056_p_1 += 1, x1056_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1056, xp_2 = x1056_p_1, xp_1 = x1056_p_0, xp_0 = 0;
							x < x1056 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10850 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10851 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_10868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_10869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_10870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_10871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_10872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_10873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c792, cp_1 = c792_p_0, cp_0 = 0;
										c < c792 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10850);
										mem_vec_10850 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10851);
										mem_vec_10851 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10852);
										mem_vec_10852 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10853);
										mem_vec_10853 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10854);
										mem_vec_10854 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10855);
										mem_vec_10855 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10856);
										mem_vec_10856 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10857);
										mem_vec_10857 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10858);
										mem_vec_10858 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10859);
										mem_vec_10859 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10860);
										mem_vec_10860 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10861);
										mem_vec_10861 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10862);
										mem_vec_10862 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10863);
										mem_vec_10863 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10864);
										mem_vec_10864 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10865);
										mem_vec_10865 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10866);
										mem_vec_10866 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10867);
										mem_vec_10867 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10868);
										mem_vec_10868 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10869);
										mem_vec_10869 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10870);
										mem_vec_10870 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10871);
										mem_vec_10871 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10872);
										mem_vec_10872 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10873);
										mem_vec_10873 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10850);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10851);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10852);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10853);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10854);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10855);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10856);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10857);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10858);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10859);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10860);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10861);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10862);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10863);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10864);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10865);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10866);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10867);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10868);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10869);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10870);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10871);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10872);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10873);
						}
					}
				}
		}
	}
}


}