#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (1, x); T (512, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, c)]
*/
IND_TYPE c, cp_0, c1176_p_0, c1177_p_0, cp_1, c1176_p_1, cp_2, c1176, c1177, f, fp_0, x, xp_0, x882_p_0, xp_1, x882, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y588 = 0;
IND_TYPE x883 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1178 = 0;
IND_TYPE f588 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_9888 ,mem_vec_9889 ,mem_vec_9890 ,mem_vec_9891 ,mem_vec_9892 ,mem_vec_9893 ,mem_vec_9894 ,mem_vec_9895 ,mem_vec_9896 ,mem_vec_9897 ,mem_vec_9898 ,mem_vec_9899 ,mem_vec_9900 ,mem_vec_9901 ,mem_vec_9902 ,mem_vec_9903 ,mem_vec_9904 ,mem_vec_9905 ,mem_vec_9906 ,mem_vec_9907 ,mem_vec_9908 ,mem_vec_9909 ,mem_vec_9910 ,mem_vec_9911 ,mem_vec_9912 ,mem_vec_9913 ,mem_vec_9914 ,mem_vec_9915 ,mem_vec_9916 ,mem_vec_9917 ,mem_vec_9918 ,mem_vec_9919 ,mem_vec_9920 ,mem_vec_9921 ,mem_vec_9922 ,mem_vec_9923 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 2) (1024 / 512)
for (c1177 = c1178, c1177_p_0 = 0;
	c1177 < c1178 + 1024;
	c1177 += 512, c1177_p_0 += 512){
		for (y = y588, yp_0 = 0;
			y < y588 + 12;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (x, 17) (17 / 1)
			for (x882 = x883, x882_p_0 = 0;
				x882 < x883 + 17;
				x882 += 1, x882_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 512
				// T (f, 8) (512 / 64)
				for (f = f588, fp_0 = 0;
					f < f588 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 64
					// T (c, 512) (512 / 1)
					for (c1176 = c1177, c1176_p_1 = c1177_p_0, c1176_p_0 = 0;
						c1176 < c1177 + 512;
						c1176 += 1, c1176_p_1 += 1, c1176_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x = x882, xp_1 = x882_p_0, xp_0 = 0;
							x < x882 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9888 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9889 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9890 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9891 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1176, cp_2 = c1176_p_1, cp_1 = c1176_p_0, cp_0 = 0;
										c < c1176 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9888);
										mem_vec_9888 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9889);
										mem_vec_9889 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9890);
										mem_vec_9890 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9891);
										mem_vec_9891 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9892);
										mem_vec_9892 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9893);
										mem_vec_9893 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9894);
										mem_vec_9894 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9895);
										mem_vec_9895 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9896);
										mem_vec_9896 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9897);
										mem_vec_9897 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9898);
										mem_vec_9898 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9899);
										mem_vec_9899 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9900);
										mem_vec_9900 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9901);
										mem_vec_9901 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9902);
										mem_vec_9902 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9903);
										mem_vec_9903 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9888);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9889);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9890);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9891);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9892);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9893);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9894);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9895);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9896);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9897);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9898);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9899);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9900);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9901);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9902);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9903);
						}
					}
				}
			}
		}
		for (y = y588 + 12, yp_0 = 0;
			y < y588 + 12 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 512
			// T (x, 17) (17 / 1)
			for (x882 = x883, x882_p_0 = 0;
				x882 < x883 + 17;
				x882 += 1, x882_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 512
				// T (f, 8) (512 / 64)
				for (f = f588, fp_0 = 0;
					f < f588 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 64
					// T (c, 512) (512 / 1)
					for (c1176 = c1177, c1176_p_1 = c1177_p_0, c1176_p_0 = 0;
						c1176 < c1177 + 512;
						c1176 += 1, c1176_p_1 += 1, c1176_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
						// T (x, 1) (1 / 1)
						for (x = x882, xp_1 = x882_p_0, xp_0 = 0;
							x < x882 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9904 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9905 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9906 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9907 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_9920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_9923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 64
									// T (c, 1) (1 / 1)
									for (c = c1176, cp_2 = c1176_p_1, cp_1 = c1176_p_0, cp_0 = 0;
										c < c1176 + 1;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9904);
										mem_vec_9904 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9905);
										mem_vec_9905 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9906);
										mem_vec_9906 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9907);
										mem_vec_9907 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9908);
										mem_vec_9908 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9909);
										mem_vec_9909 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9910);
										mem_vec_9910 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9911);
										mem_vec_9911 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9912);
										mem_vec_9912 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9913);
										mem_vec_9913 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9914);
										mem_vec_9914 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9915);
										mem_vec_9915 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9916);
										mem_vec_9916 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9917);
										mem_vec_9917 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9918);
										mem_vec_9918 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9919);
										mem_vec_9919 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9920);
										mem_vec_9920 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9921);
										mem_vec_9921 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9922);
										mem_vec_9922 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9923);
										mem_vec_9923 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9904);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9905);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9906);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9907);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9908);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9909);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9910);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9911);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9917);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9918);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9919);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9920);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9921);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9922);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9923);
						}
					}
				}
			}
		}
}


}