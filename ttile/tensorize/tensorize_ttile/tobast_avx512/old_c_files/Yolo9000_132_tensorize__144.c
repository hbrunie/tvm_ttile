void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (256, c); T (34, x)]
*/
IND_TYPE c, cp_0, c1194_p_0, cp_1, c1194, f, fp_0, x, xp_0, x1592_p_0, x1593_p_0, xp_1, x1592_p_1, xp_2, x1592, x1593, y, yp_0;
IND_TYPE y796 = 0;
IND_TYPE x1594 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1195 = 0;
IND_TYPE f796 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_16976 ,mem_vec_16977 ,mem_vec_16978 ,mem_vec_16979 ,mem_vec_16980 ,mem_vec_16981 ,mem_vec_16982 ,mem_vec_16983 ,mem_vec_16984 ,mem_vec_16985 ,mem_vec_16986 ,mem_vec_16987 ,mem_vec_16988 ,mem_vec_16989 ,mem_vec_16990 ,mem_vec_16991 ,mem_vec_16992 ,mem_vec_16993 ,mem_vec_16994 ,mem_vec_16995 ,mem_vec_16996 ,mem_vec_16997 ,mem_vec_16998 ,mem_vec_16999 ,mem_vec_17000 ,mem_vec_17001 ,mem_vec_17002 ,mem_vec_17003 ,mem_vec_17004 ,mem_vec_17005 ,mem_vec_17006 ,mem_vec_17007 ,mem_vec_17008 ,mem_vec_17009 ,mem_vec_17010 ,mem_vec_17011 ,mem_vec_17012 ,mem_vec_17013 ,mem_vec_17014 ,mem_vec_17015 ,mem_vec_17016 ,mem_vec_17017 ,mem_vec_17018 ,mem_vec_17019 ,mem_vec_17020 ,mem_vec_17021 ,mem_vec_17022 ,mem_vec_17023 ,mem_vec_17024 ,mem_vec_17025 ,mem_vec_17026 ,mem_vec_17027 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 34) (34 / 1)
x1593 = 0;
x1593_p_0 = 0;
c1194 = 0;
c1194_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_0 = 0;
x1592 = 0;
x1592_p_1 = 0;
						for (x = x1592, xp_2 = x1592_p_1, xp_1 = x1592_p_0, xp_0 = 0;x < x1592 + 1;x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_17000 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_17001 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_17002 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_17003 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_17004 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_17005 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_17006 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_17007 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_17008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_17009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_17010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_17011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_17012 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_17013 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_17014 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_17015 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_17016 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_17017 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_17018 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_17019 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_17020 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_17021 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_17022 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_17023 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									mem_vec_17024 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_17025 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_17026 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
									mem_vec_17027 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1194, cp_1 = c1194_p_0, cp_0 = 0;c < c1194 + 2;c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_17000);
										mem_vec_17000 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_17001);
										mem_vec_17001 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_17002);
										mem_vec_17002 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_17003);
										mem_vec_17003 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_17004);
										mem_vec_17004 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_17005);
										mem_vec_17005 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_17006);
										mem_vec_17006 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_17007);
										mem_vec_17007 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_17008);
										mem_vec_17008 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_17009);
										mem_vec_17009 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_17010);
										mem_vec_17010 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_17011);
										mem_vec_17011 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_17012);
										mem_vec_17012 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_17013);
										mem_vec_17013 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_17014);
										mem_vec_17014 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_17015);
										mem_vec_17015 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_17016);
										mem_vec_17016 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_17017);
										mem_vec_17017 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_17018);
										mem_vec_17018 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_17019);
										mem_vec_17019 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_17020);
										mem_vec_17020 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_17021);
										mem_vec_17021 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_17022);
										mem_vec_17022 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_17023);
										mem_vec_17023 = vec_33;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_17024);
										mem_vec_17024 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_17025);
										mem_vec_17025 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_17026);
										mem_vec_17026 = vec_37;
										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_17027);
										mem_vec_17027 = vec_38;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_17000);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_17001);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_17002);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_17003);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_17004);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_17005);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_17006);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_17007);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_17008);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_17009);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_17010);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_17011);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_17012);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_17013);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_17014);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_17015);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_17016);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_17017);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_17018);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_17019);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_17020);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_17021);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_17022);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_17023);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_17024);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_17025);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_17026);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_17027);
						}
}
