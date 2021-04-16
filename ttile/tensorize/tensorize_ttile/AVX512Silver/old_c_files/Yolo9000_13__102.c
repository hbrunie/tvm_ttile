#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (2, c);
  T (4, f); T (1, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]]
*/
IND_TYPE c, cp_0, c57_p_0, cp_1, c57, f, fp_0, x, xp_0, x76_p_0, x77_p_0, xp_1, x76_p_1, xp_2, x76, x77, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y38 = 0;
IND_TYPE x78 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c58 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y = y38, yp_0 = 0;
		y < y38 + 4;
		y += 4, yp_0 += 4){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 2) (34 / 17)
		for (x77 = x78, x77_p_0 = 0;
			x77 < x78 + 34;
			x77 += 17, x77_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
			// T (x, 1) (17 / 17)
			for (x76 = x77, x76_p_1 = x77_p_0, x76_p_0 = 0;
				x76 < x77 + 17;
				x76 += 17, x76_p_1 += 17, x76_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f38, fp_0 = 0;
					f < f38 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 2) (512 / 256)
					for (c57 = c58, c57_p_0 = 0;
						c57 < c58 + 512;
						c57 += 256, c57_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x76, xp_2 = x76_p_1, xp_1 = x76_p_0, xp_0 = 0;
							x < x76 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_864 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_865 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_866 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_867 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
										c < c57 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_864);
										mem_vec_864 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_865);
										mem_vec_865 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_866);
										mem_vec_866 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_867);
										mem_vec_867 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_868);
										mem_vec_868 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_869);
										mem_vec_869 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_870);
										mem_vec_870 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_871);
										mem_vec_871 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_872);
										mem_vec_872 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_873);
										mem_vec_873 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_874);
										mem_vec_874 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_875);
										mem_vec_875 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_876);
										mem_vec_876 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_877);
										mem_vec_877 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_878);
										mem_vec_878 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_879);
										mem_vec_879 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_864);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_865);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_866);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_867);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_868);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_869);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_870);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_871);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_872);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_873);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_874);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_875);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_876);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_877);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_878);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_879);
						}
					}
				}
			}
		}
	}
	for (y = y38 + 4, yp_0 = 0;
		y < y38 + 4 + 30;
		y += 6, yp_0 += 6){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 2) (34 / 17)
		for (x77 = x78, x77_p_0 = 0;
			x77 < x78 + 34;
			x77 += 17, x77_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
			// T (x, 1) (17 / 17)
			for (x76 = x77, x76_p_1 = x77_p_0, x76_p_0 = 0;
				x76 < x77 + 17;
				x76 += 17, x76_p_1 += 17, x76_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f38, fp_0 = 0;
					f < f38 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 2) (512 / 256)
					for (c57 = c58, c57_p_0 = 0;
						c57 < c58 + 512;
						c57 += 256, c57_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x76, xp_2 = x76_p_1, xp_1 = x76_p_0, xp_0 = 0;
							x < x76 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_880 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_881 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_882 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_883 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_886 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_887 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c57, cp_1 = c57_p_0, cp_0 = 0;
										c < c57 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_880);
										mem_vec_880 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_881);
										mem_vec_881 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_882);
										mem_vec_882 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_883);
										mem_vec_883 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_884);
										mem_vec_884 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_885);
										mem_vec_885 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_886);
										mem_vec_886 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_887);
										mem_vec_887 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_888);
										mem_vec_888 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_889);
										mem_vec_889 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_890);
										mem_vec_890 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_891);
										mem_vec_891 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_892);
										mem_vec_892 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_893);
										mem_vec_893 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_894);
										mem_vec_894 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_895);
										mem_vec_895 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_896);
										mem_vec_896 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_897);
										mem_vec_897 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_898);
										mem_vec_898 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_899);
										mem_vec_899 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_900);
										mem_vec_900 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_901);
										mem_vec_901 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_902);
										mem_vec_902 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_903);
										mem_vec_903 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_880);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_881);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_882);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_883);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_884);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_885);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_886);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_887);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_888);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_889);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_890);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_891);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_892);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_893);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_894);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_895);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_896);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_897);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_898);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_899);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_900);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_901);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_902);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_903);
						}
					}
				}
			}
		}
	}


}