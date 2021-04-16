void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (1, y); T (2, f); T (1, x); T (8, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c183_p_0, cp_1, c183, f, fp_0, x, xp_0, x305_p_0, x306_p_0, x307_p_0, xp_1, x305_p_1, x306_p_1, xp_2, x305_p_2, xp_3, x305, x306, x307, y, yp_0, y244_p_0, y245_p_0, yp_1, y244_p_1, yp_2, y244, y245;
IND_TYPE y246 = 0;
IND_TYPE x308 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c184 = 0;
IND_TYPE f122 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1796 ,mem_vec_1797 ,mem_vec_1798 ,mem_vec_1799 ,mem_vec_1800 ,mem_vec_1801 ,mem_vec_1802 ,mem_vec_1803 ,mem_vec_1804 ,mem_vec_1805 ,mem_vec_1806 ,mem_vec_1807 ,mem_vec_1808 ,mem_vec_1809 ,mem_vec_1810 ,mem_vec_1811 ,mem_vec_1812 ,mem_vec_1813 ,mem_vec_1814 ,mem_vec_1815 ,mem_vec_1816 ,mem_vec_1817 ,mem_vec_1818 ,mem_vec_1819 ,mem_vec_1820 ,mem_vec_1821 ,mem_vec_1822 ,mem_vec_1823 ,mem_vec_1824 ,mem_vec_1825 ,mem_vec_1826 ,mem_vec_1827 ,mem_vec_1828 ,mem_vec_1829 ,mem_vec_1830 ,mem_vec_1831 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y245 = 0;
y245_p_0 = 0;
x307 = 0;
x307_p_0 = 0;
y244 = 0;
y244_p_1 = 0;
x306 = 0;
x306_p_1 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_2 = 0;
x305 = 0;
x305_p_2 = 0;
c183 = 0;
c183_p_0 = 0;
									for (x = x305, xp_3 = x305_p_2, xp_2 = x305_p_1, xp_1 = x305_p_0, xp_0 = 0;x < x305 + 2;x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1812 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
												mem_vec_1813 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 8]);
												mem_vec_1814 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
												mem_vec_1815 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 24]);
												mem_vec_1816 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
												mem_vec_1817 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8]);
												mem_vec_1818 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
												mem_vec_1819 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24]);
												mem_vec_1820 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
												mem_vec_1821 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8]);
												mem_vec_1822 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
												mem_vec_1823 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24]);
												mem_vec_1824 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
												mem_vec_1825 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8]);
												mem_vec_1826 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
												mem_vec_1827 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24]);
												mem_vec_1828 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
												mem_vec_1829 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8]);
												mem_vec_1830 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
												mem_vec_1831 = _mm256_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c183, cp_1 = c183_p_0, cp_0 = 0;c < c183 + 32;c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1812);
													mem_vec_1812 = vec_0;
													vec_4 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 8]);
													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1813);
													mem_vec_1813 = vec_3;
													vec_6 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1814);
													mem_vec_1814 = vec_5;
													vec_8 = _mm256_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 24]);
													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1815);
													mem_vec_1815 = vec_7;
													scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);
													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1816);
													mem_vec_1816 = vec_9;
													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1817);
													mem_vec_1817 = vec_11;
													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1818);
													mem_vec_1818 = vec_12;
													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1819);
													mem_vec_1819 = vec_13;
													scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);
													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1820);
													mem_vec_1820 = vec_14;
													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1821);
													mem_vec_1821 = vec_16;
													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1822);
													mem_vec_1822 = vec_17;
													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1823);
													mem_vec_1823 = vec_18;
													scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);
													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1824);
													mem_vec_1824 = vec_19;
													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1825);
													mem_vec_1825 = vec_21;
													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1826);
													mem_vec_1826 = vec_22;
													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1827);
													mem_vec_1827 = vec_23;
													scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1828);
													mem_vec_1828 = vec_24;
													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1829);
													mem_vec_1829 = vec_26;
													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1830);
													mem_vec_1830 = vec_27;
													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1831);
													mem_vec_1831 = vec_28;
												}
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1812);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 8], mem_vec_1813);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1814);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 24], mem_vec_1815);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1816);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 8], mem_vec_1817);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1818);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 24], mem_vec_1819);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1820);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 8], mem_vec_1821);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1822);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 24], mem_vec_1823);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1824);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 8], mem_vec_1825);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1826);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 24], mem_vec_1827);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1828);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 8], mem_vec_1829);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1830);
											_mm256_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 24], mem_vec_1831);
									}
}
