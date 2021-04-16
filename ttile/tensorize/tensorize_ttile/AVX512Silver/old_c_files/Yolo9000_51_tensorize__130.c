
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        void gen_conv1(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (8, y);
  T (1, c); T (136, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]]
*/
IND_TYPE c, cp_0, c111_p_0, cp_1, c111, x, xp_0, x147_p_0, xp_1, x147, y, yp_0, y147_p_0, yp_1, y147;
IND_TYPE y148 = 0;
IND_TYPE x148 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c112 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1972 ,mem_vec_1973 ,mem_vec_1974 ,mem_vec_1975 ,mem_vec_1976 ,mem_vec_1977 ,mem_vec_1978 ,mem_vec_1979 ,mem_vec_1980 ,mem_vec_1981 ,mem_vec_1982 ,mem_vec_1983 ,mem_vec_1984 ,mem_vec_1985 ,mem_vec_1986 ,mem_vec_1987 ,mem_vec_1988 ,mem_vec_1989 ,mem_vec_1990 ,mem_vec_1991 ,mem_vec_1992 ,mem_vec_1993 ,mem_vec_1994 ,mem_vec_1995 ,mem_vec_1996 ,mem_vec_1997 ,mem_vec_1998 ,mem_vec_1999 ,mem_vec_2000 ,mem_vec_2001 ,mem_vec_2002 ,mem_vec_2003 ,mem_vec_2004 ,mem_vec_2005 ,mem_vec_2006 ,mem_vec_2007 ,mem_vec_2008 ,mem_vec_2009 ,mem_vec_2010 ,mem_vec_2011 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y147 = 0;
y147_p_0 = 0;
x147 = 0;
x147_p_0 = 0;
c111 = 0;
c111_p_0 = 0;
y = 0;
yp_1 = 0;
					for (x = x147, xp_1 = x147_p_0, xp_0 = 0;x < x147 + 1;x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_1972 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
								mem_vec_1973 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
								mem_vec_1974 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
								mem_vec_1975 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
								mem_vec_1976 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
								mem_vec_1977 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
								mem_vec_1978 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
								mem_vec_1979 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
								mem_vec_1980 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
								mem_vec_1981 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
								mem_vec_1982 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
								mem_vec_1983 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c111, cp_1 = c111_p_0, cp_0 = 0;c < c111 + 128;c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1972);
									mem_vec_1972 = vec_0;
									vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1973);
									mem_vec_1973 = vec_3;
									vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1974);
									mem_vec_1974 = vec_5;
									vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1975);
									mem_vec_1975 = vec_7;
									scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);
									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1976);
									mem_vec_1976 = vec_9;
									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1977);
									mem_vec_1977 = vec_11;
									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1978);
									mem_vec_1978 = vec_12;
									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1979);
									mem_vec_1979 = vec_13;
									scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);
									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1980);
									mem_vec_1980 = vec_14;
									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1981);
									mem_vec_1981 = vec_16;
									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1982);
									mem_vec_1982 = vec_17;
									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1983);
									mem_vec_1983 = vec_18;
								}
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1972);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1973);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1974);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1975);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1976);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1977);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1978);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1979);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1980);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1981);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1982);
							_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1983);
					}
}
