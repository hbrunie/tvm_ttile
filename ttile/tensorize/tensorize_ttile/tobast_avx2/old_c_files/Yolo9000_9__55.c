#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (1, c); Hoist_vars [c]; T (68, x); T (17, y);
  T (1, f); T (4, f); T (256, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c174_p_0, cp_1, c174, f, fp_0, f232_p_0, f233_p_0, fp_1, f232_p_1, fp_2, f232, f233, x, xp_0, x174_p_0, xp_1, x174, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y116 = 0;
IND_TYPE x175 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c175 = 0;
IND_TYPE f234 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (f, 1) (128 / 128)
for (f233 = f234, f233_p_0 = 0;
	f233 < f234 + 128;
	f233 += 128, f233_p_0 += 128){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x174 = x175, x174_p_0 = 0;
		x174 < x175 + 68;
		x174 += 68, x174_p_0 += 68){
		// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (c, 256) (256 / 1)
		for (c174 = c175, c174_p_0 = 0;
			c174 < c175 + 256;
			c174 += 1, c174_p_0 += 1){
			// y = 68, x = 68, h = 1, w = 1, c = 1, f = 128
			// T (f, 4) (128 / 32)
			for (f232 = f233, f232_p_1 = f233_p_0, f232_p_0 = 0;
				f232 < f233 + 128;
				f232 += 32, f232_p_1 += 32, f232_p_0 += 32){
				// y = 68, x = 68, h = 1, w = 1, c = 1, f = 32
				// T (f, 1) (32 / 32)
				for (f = f232, fp_2 = f232_p_1, fp_1 = f232_p_0, fp_0 = 0;
					f < f232 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
					// y = 68, x = 68, h = 1, w = 1, c = 1, f = 32
					// T (y, 17) (68 / 4)
					for (y = y116, yp_0 = 0;
						y < y116 + 68;
						y += 4, yp_0 += 4){
						// y = 4, x = 68, h = 1, w = 1, c = 1, f = 32
						// T (x, 68) (68 / 1)
						for (x = x174, xp_1 = x174_p_0, xp_0 = 0;
							x < x174 + 68;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_928 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_929 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_930 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_931 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_936 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_937 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_938 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_939 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c174, cp_1 = c174_p_0, cp_0 = 0;
										c < c174 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_928);
										mem_vec_928 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_929);
										mem_vec_929 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_930);
										mem_vec_930 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_931);
										mem_vec_931 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_932);
										mem_vec_932 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_933);
										mem_vec_933 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_934);
										mem_vec_934 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_935);
										mem_vec_935 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_936);
										mem_vec_936 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_937);
										mem_vec_937 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_938);
										mem_vec_938 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_939);
										mem_vec_939 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_940);
										mem_vec_940 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_941);
										mem_vec_941 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_942);
										mem_vec_942 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_943);
										mem_vec_943 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_928);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_929);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_930);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_931);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_932);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_933);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_934);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_935);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_936);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_937);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_938);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_939);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_940);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_941);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_942);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_943);
						}
					}
				}
			}
		}
	}
}


}