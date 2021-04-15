void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (4, f);
  T (256, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1008_p_0, cp_1, c1008, f, fp_0, x, xp_0, x1344_p_0, x1345_p_0, xp_1, x1344_p_1, xp_2, x1344, x1345, y, yp_0;
IND_TYPE y672 = 0;
IND_TYPE x1346 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1009 = 0;
IND_TYPE f672 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_13896 ,mem_vec_13897 ,mem_vec_13898 ,mem_vec_13899 ,mem_vec_13900 ,mem_vec_13901 ,mem_vec_13902 ,mem_vec_13903 ,mem_vec_13904 ,mem_vec_13905 ,mem_vec_13906 ,mem_vec_13907 ,mem_vec_13908 ,mem_vec_13909 ,mem_vec_13910 ,mem_vec_13911 ,mem_vec_13912 ,mem_vec_13913 ,mem_vec_13914 ,mem_vec_13915 ,mem_vec_13916 ,mem_vec_13917 ,mem_vec_13918 ,mem_vec_13919 ,mem_vec_13920 ,mem_vec_13921 ,mem_vec_13922 ,mem_vec_13923 ,mem_vec_13924 ,mem_vec_13925 ,mem_vec_13926 ,mem_vec_13927 ,mem_vec_13928 ,mem_vec_13929 ,mem_vec_13930 ,mem_vec_13931 ,mem_vec_13932 ,mem_vec_13933 ,mem_vec_13934 ,mem_vec_13935 ,mem_vec_13936 ,mem_vec_13937 ,mem_vec_13938 ,mem_vec_13939 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
x1345 = 0;
x1345_p_0 = 0;
c1008 = 0;
c1008_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1344 = 0;
x1344_p_1 = 0;
						for (x = x1344, xp_2 = x1344_p_1, xp_1 = x1344_p_0, xp_0 = 0;x < x1344 + 17;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13912 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_13913 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_13914 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_13915 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_13916 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_13917 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_13918 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_13919 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_13920 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_13921 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_13922 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_13923 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_13924 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_13925 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_13926 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_13927 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_13928 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_13929 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_13930 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_13931 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_13932 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_13933 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_13934 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_13935 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									mem_vec_13936 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_13937 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_13938 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
									mem_vec_13939 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1008, cp_1 = c1008_p_0, cp_0 = 0;c < c1008 + 2;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13912);
										mem_vec_13912 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13913);
										mem_vec_13913 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13914);
										mem_vec_13914 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13915);
										mem_vec_13915 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13916);
										mem_vec_13916 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13917);
										mem_vec_13917 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13918);
										mem_vec_13918 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13919);
										mem_vec_13919 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13920);
										mem_vec_13920 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13921);
										mem_vec_13921 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13922);
										mem_vec_13922 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13923);
										mem_vec_13923 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13924);
										mem_vec_13924 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13925);
										mem_vec_13925 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13926);
										mem_vec_13926 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13927);
										mem_vec_13927 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13928);
										mem_vec_13928 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13929);
										mem_vec_13929 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13930);
										mem_vec_13930 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13931);
										mem_vec_13931 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13932);
										mem_vec_13932 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13933);
										mem_vec_13933 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13934);
										mem_vec_13934 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13935);
										mem_vec_13935 = vec_33;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_13936);
										mem_vec_13936 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_13937);
										mem_vec_13937 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_13938);
										mem_vec_13938 = vec_37;
										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_13939);
										mem_vec_13939 = vec_38;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_13912);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_13913);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_13914);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_13915);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_13916);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_13917);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_13918);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_13919);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_13920);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_13921);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_13922);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_13923);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_13924);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_13925);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_13926);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_13927);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_13928);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_13929);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_13930);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_13931);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_13932);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_13933);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_13934);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_13935);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_13936);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_13937);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_13938);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_13939);
						}
}
