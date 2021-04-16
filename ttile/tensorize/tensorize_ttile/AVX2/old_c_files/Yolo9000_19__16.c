#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (8, c); T (17, x); T (1, y)]
*/
IND_TYPE c, cp_0, c72_p_0, cp_1, c72, f, fp_0, x, xp_0, x72_p_0, xp_1, x72, y, yp_0, y72_p_0, yp_1, y72;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y73 = 0;
IND_TYPE x73 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c73 = 0;
IND_TYPE f48 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_864 ,mem_vec_865 ,mem_vec_866 ,mem_vec_867 ,mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y72 = y73, y72_p_0 = 0;
	y72 < y73 + 17;
	y72 += 17, y72_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 17) (17 / 1)
	for (x72 = x73, x72_p_0 = 0;
		x72 < x73 + 17;
		x72 += 1, x72_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 512
		// T (c, 8) (1024 / 128)
		for (c72 = c73, c72_p_0 = 0;
			c72 < c73 + 1024;
			c72 += 128, c72_p_0 += 128){
			// y = 17, x = 1, h = 1, w = 1, c = 128, f = 512
			// T (f, 16) (512 / 32)
			for (f = f48, fp_0 = 0;
				f < f48 + 512;
				f += 32, fp_0 += 32){
					for (y = y72, yp_1 = y72_p_0, yp_0 = 0;
						y < y72 + 12;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
							x < x72 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_864 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_865 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_866 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_867 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_876 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_877 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_878 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_879 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (c, 128) (128 / 1)
									for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
										c < c72 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_864);
										mem_vec_864 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_865);
										mem_vec_865 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_866);
										mem_vec_866 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_867);
										mem_vec_867 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_868);
										mem_vec_868 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_869);
										mem_vec_869 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_870);
										mem_vec_870 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_871);
										mem_vec_871 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_872);
										mem_vec_872 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_873);
										mem_vec_873 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_874);
										mem_vec_874 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_875);
										mem_vec_875 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_876);
										mem_vec_876 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_877);
										mem_vec_877 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_878);
										mem_vec_878 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_879);
										mem_vec_879 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_864);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_865);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_866);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_867);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_868);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_869);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_870);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_871);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_872);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_873);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_874);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_875);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_876);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_877);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_878);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_879);
						}
					}
					for (y = y72 + 12, yp_1 = y72_p_0, yp_0 = 0;
						y < y72 + 12 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
							x < x72 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_880 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_881 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_882 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_883 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_884 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_885 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_886 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_887 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_888 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_889 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_890 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_891 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_892 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_893 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_894 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_895 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_896 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_897 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_898 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_899 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (c, 128) (128 / 1)
									for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
										c < c72 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_880);
										mem_vec_880 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_881);
										mem_vec_881 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_882);
										mem_vec_882 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_883);
										mem_vec_883 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_884);
										mem_vec_884 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_885);
										mem_vec_885 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_886);
										mem_vec_886 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_887);
										mem_vec_887 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_888);
										mem_vec_888 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_889);
										mem_vec_889 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_890);
										mem_vec_890 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_891);
										mem_vec_891 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_892);
										mem_vec_892 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_893);
										mem_vec_893 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_894);
										mem_vec_894 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_895);
										mem_vec_895 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_896);
										mem_vec_896 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_897);
										mem_vec_897 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_898);
										mem_vec_898 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_899);
										mem_vec_899 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_880);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_881);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_882);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_883);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_884);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_885);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_886);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_887);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_888);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_889);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_890);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_891);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_892);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_893);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_894);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_895);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_896);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_897);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_898);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_899);
						}
					}
			}
		}
	}
}


}