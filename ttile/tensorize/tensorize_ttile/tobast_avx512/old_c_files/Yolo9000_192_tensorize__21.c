void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (128, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (4, c)]
*/
IND_TYPE c, cp_0, c1464_p_0, c1465_p_0, cp_1, c1464_p_1, cp_2, c1464, c1465, f, fp_0, x, xp_0, x1098_p_0, xp_1, x1098, y, yp_0;
IND_TYPE y732 = 0;
IND_TYPE x1099 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1466 = 0;
IND_TYPE f732 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_12984 ,mem_vec_12985 ,mem_vec_12986 ,mem_vec_12987 ,mem_vec_12988 ,mem_vec_12989 ,mem_vec_12990 ,mem_vec_12991 ,mem_vec_12992 ,mem_vec_12993 ,mem_vec_12994 ,mem_vec_12995 ,mem_vec_12996 ,mem_vec_12997 ,mem_vec_12998 ,mem_vec_12999 ,mem_vec_13000 ,mem_vec_13001 ,mem_vec_13002 ,mem_vec_13003 ,mem_vec_13004 ,mem_vec_13005 ,mem_vec_13006 ,mem_vec_13007 ,mem_vec_13008 ,mem_vec_13009 ,mem_vec_13010 ,mem_vec_13011 ,mem_vec_13012 ,mem_vec_13013 ,mem_vec_13014 ,mem_vec_13015 ,mem_vec_13016 ,mem_vec_13017 ,mem_vec_13018 ,mem_vec_13019 ,mem_vec_13020 ,mem_vec_13021 ,mem_vec_13022 ,mem_vec_13023 ,mem_vec_13024 ,mem_vec_13025 ,mem_vec_13026 ,mem_vec_13027 ,mem_vec_13028 ,mem_vec_13029 ,mem_vec_13030 ,mem_vec_13031 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 4) (1024 / 256)
c1465 = 0;
c1465_p_0 = 0;
y = 0;
yp_0 = 0;
x1098 = 0;
x1098_p_0 = 0;
f = 0;
fp_0 = 0;
c1464 = 0;
c1464_p_1 = 0;
						for (x = x1098, xp_1 = x1098_p_0, xp_0 = 0;x < x1098 + 17;x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13004 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_13005 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_13006 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_13007 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_13008 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_13009 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_13010 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_13011 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_13012 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_13013 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_13014 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_13015 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_13016 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_13017 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_13018 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_13019 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_13020 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_13021 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_13022 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_13023 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_13024 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_13025 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_13026 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_13027 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									mem_vec_13028 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f]);
									mem_vec_13029 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16]);
									mem_vec_13030 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32]);
									mem_vec_13031 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1464, cp_2 = c1464_p_1, cp_1 = c1464_p_0, cp_0 = 0;c < c1464 + 2;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13004);
										mem_vec_13004 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13005);
										mem_vec_13005 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_13006);
										mem_vec_13006 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_13007);
										mem_vec_13007 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_13008);
										mem_vec_13008 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_13009);
										mem_vec_13009 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_13010);
										mem_vec_13010 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_13011);
										mem_vec_13011 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13012);
										mem_vec_13012 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13013);
										mem_vec_13013 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_13014);
										mem_vec_13014 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_13015);
										mem_vec_13015 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_13016);
										mem_vec_13016 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_13017);
										mem_vec_13017 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_13018);
										mem_vec_13018 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_13019);
										mem_vec_13019 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_13020);
										mem_vec_13020 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_13021);
										mem_vec_13021 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_13022);
										mem_vec_13022 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_13023);
										mem_vec_13023 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13024);
										mem_vec_13024 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13025);
										mem_vec_13025 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_13026);
										mem_vec_13026 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_13027);
										mem_vec_13027 = vec_33;
										scal_6 = input[strideA1 * (x + w) + strideA2 * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);
										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_13028);
										mem_vec_13028 = vec_34;
										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_13029);
										mem_vec_13029 = vec_36;
										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_13030);
										mem_vec_13030 = vec_37;
										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_13031);
										mem_vec_13031 = vec_38;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_13004);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_13005);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_13006);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_13007);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_13008);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_13009);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_13010);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_13011);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_13012);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_13013);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_13014);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_13015);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_13016);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_13017);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_13018);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_13019);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_13020);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_13021);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_13022);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_13023);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_13024);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_13025);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_13026);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_13027);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f], mem_vec_13028);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 16], mem_vec_13029);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 32], mem_vec_13030);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 6) + f + 48], mem_vec_13031);
						}
}
