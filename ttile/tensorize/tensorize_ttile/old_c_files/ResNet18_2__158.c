#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (4, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, c); T (4, x); T (8, y); T (16, c)]
*/
IND_TYPE c, cp_0, c120_p_0, c121_p_0, cp_1, c120_p_1, cp_2, c120, c121, h, hp_0, w, wp_0, x, xp_0, x146_p_0, xp_1, x146, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y76 = 0;
IND_TYPE x147 = 0;
IND_TYPE h76 = 0;
IND_TYPE w76 = 0;
IND_TYPE c122 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_848 ,mem_vec_849 ,mem_vec_850 ,mem_vec_851 ,mem_vec_852 ,mem_vec_853 ,mem_vec_854 ,mem_vec_855 ,mem_vec_856 ,mem_vec_857 ,mem_vec_858 ,mem_vec_859 ,mem_vec_860 ,mem_vec_861 ,mem_vec_862 ,mem_vec_863 ,mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 16) (64 / 4)
for (c121 = c122, c121_p_0 = 0;
	c121 < c122 + 64;
	c121 += 4, c121_p_0 += 4){
	// y = 56, x = 56, h = 3, w = 3, c = 4, f = 64
	// T (y, 8) (56 / 7)
	for (y = y76, yp_0 = 0;
		y < y76 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 56, h = 3, w = 3, c = 4, f = 64
		// T (x, 4) (56 / 14)
		for (x146 = x147, x146_p_0 = 0;
			x146 < x147 + 56;
			x146 += 14, x146_p_0 += 14){
			// y = 7, x = 14, h = 3, w = 3, c = 4, f = 64
			// T (c, 1) (4 / 4)
			for (c120 = c121, c120_p_1 = c121_p_0, c120_p_0 = 0;
				c120 < c121 + 4;
				c120 += 4, c120_p_1 += 4, c120_p_0 += 4){
				// y = 7, x = 14, h = 3, w = 3, c = 4, f = 64
				// T (h, 3) (3 / 1)
				for (h = h76, hp_0 = 0;
					h < h76 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 14, h = 1, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w76, wp_0 = 0;
						w < w76 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 14, h = 1, w = 1, c = 4, f = 64
						// T (x, 14) (14 / 1)
						for (x = x146, xp_1 = x146_p_0, xp_0 = 0;
							x < x146 + 14;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_848 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_849 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_850 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_851 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c120, cp_2 = c120_p_1, cp_1 = c120_p_0, cp_0 = 0;
										c < c120 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_848);
										mem_vec_848 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_849);
										mem_vec_849 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_850);
										mem_vec_850 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_851);
										mem_vec_851 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_852);
										mem_vec_852 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_853);
										mem_vec_853 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_854);
										mem_vec_854 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_855);
										mem_vec_855 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_856);
										mem_vec_856 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_857);
										mem_vec_857 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_858);
										mem_vec_858 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_859);
										mem_vec_859 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_860);
										mem_vec_860 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_861);
										mem_vec_861 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_862);
										mem_vec_862 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_863);
										mem_vec_863 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_864);
										mem_vec_864 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_865);
										mem_vec_865 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_866);
										mem_vec_866 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_867);
										mem_vec_867 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_868);
										mem_vec_868 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_869);
										mem_vec_869 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_870);
										mem_vec_870 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_871);
										mem_vec_871 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_872);
										mem_vec_872 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_873);
										mem_vec_873 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_874);
										mem_vec_874 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_875);
										mem_vec_875 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_848);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_849);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_850);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_851);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_852);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_853);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_854);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_855);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_856);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_857);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_858);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_859);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_860);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_861);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_862);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_863);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_864);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_865);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_866);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_867);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_868);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_869);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_870);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_871);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_872);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_873);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_874);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_875);
						}
					}
				}
			}
		}
	}
}


}