void gen_conv2(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F, int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (1, y); T (8, f); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 2), (Arg 6))]]
*/
IND_TYPE c, cp_0, c164_p_0, c165_p_0, cp_1, c164_p_1, cp_2, c164, c165, f, fp_0, x, xp_0, y, yp_0, y123_p_0, yp_1, y123;
IND_TYPE y124 = 0;
IND_TYPE x82 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c166 = 0;
IND_TYPE f82 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_1760 ,mem_vec_1761 ,mem_vec_1762 ,mem_vec_1763 ,mem_vec_1764 ,mem_vec_1765 ,mem_vec_1766 ,mem_vec_1767 ,mem_vec_1768 ,mem_vec_1769 ,mem_vec_1770 ,mem_vec_1771 ,mem_vec_1772 ,mem_vec_1773 ,mem_vec_1774 ,mem_vec_1775 ,mem_vec_1776 ,mem_vec_1777 ,mem_vec_1778 ,mem_vec_1779 ,mem_vec_1780 ,mem_vec_1781 ,mem_vec_1782 ,mem_vec_1783 ,mem_vec_1784 ,mem_vec_1785 ,mem_vec_1786 ,mem_vec_1787 ,mem_vec_1788 ,mem_vec_1789 ,mem_vec_1790 ,mem_vec_1791 ,mem_vec_1792 ,mem_vec_1793 ,mem_vec_1794 ,mem_vec_1795 ,mem_vec_1796 ,mem_vec_1797 ,mem_vec_1798 ,mem_vec_1799 ,mem_vec_1800 ,mem_vec_1801 ,mem_vec_1802 ,mem_vec_1803 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
y123 = 0;
y123_p_0 = 0;
c165 = 0;
c165_p_0 = 0;
f = 0;
fp_0 = 0;
y = 0;
yp_1 = 0;
c164 = 0;
c164_p_1 = 0;
						for (x = x82, xp_0 = 0;x < x82 + 17;x += 1, xp_0 += 1){
									mem_vec_1780 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f]);
									mem_vec_1781 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 16]);
									mem_vec_1782 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 32]);
									mem_vec_1783 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * y + f + 48]);
									mem_vec_1784 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f]);
									mem_vec_1785 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16]);
									mem_vec_1786 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32]);
									mem_vec_1787 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48]);
									mem_vec_1788 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f]);
									mem_vec_1789 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16]);
									mem_vec_1790 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32]);
									mem_vec_1791 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48]);
									mem_vec_1792 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f]);
									mem_vec_1793 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16]);
									mem_vec_1794 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32]);
									mem_vec_1795 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48]);
									mem_vec_1796 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f]);
									mem_vec_1797 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16]);
									mem_vec_1798 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32]);
									mem_vec_1799 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48]);
									mem_vec_1800 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f]);
									mem_vec_1801 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16]);
									mem_vec_1802 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32]);
									mem_vec_1803 = _mm512_loadu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
									// T (c, 128) (128 / 1)
									for (c = c164, cp_2 = c164_p_1, cp_1 = c164_p_0, cp_0 = 0;c < c164 + 128;c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[strideA1 * (x + w) + strideA2 * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f]);
										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1780);
										mem_vec_1780 = vec_0;
										vec_4 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 16]);
										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1781);
										mem_vec_1781 = vec_3;
										vec_6 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 32]);
										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1782);
										mem_vec_1782 = vec_5;
										vec_8 = _mm512_loadu_ps(&params[strideW1 * w + strideW2 * h + strideW3 * c + f + 48]);
										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1783);
										mem_vec_1783 = vec_7;
										scal_1 = input[strideA1 * (x + w) + strideA2 * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);
										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1784);
										mem_vec_1784 = vec_9;
										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1785);
										mem_vec_1785 = vec_11;
										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1786);
										mem_vec_1786 = vec_12;
										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1787);
										mem_vec_1787 = vec_13;
										scal_2 = input[strideA1 * (x + w) + strideA2 * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1788);
										mem_vec_1788 = vec_14;
										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1789);
										mem_vec_1789 = vec_16;
										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1790);
										mem_vec_1790 = vec_17;
										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1791);
										mem_vec_1791 = vec_18;
										scal_3 = input[strideA1 * (x + w) + strideA2 * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1792);
										mem_vec_1792 = vec_19;
										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1793);
										mem_vec_1793 = vec_21;
										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1794);
										mem_vec_1794 = vec_22;
										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1795);
										mem_vec_1795 = vec_23;
										scal_4 = input[strideA1 * (x + w) + strideA2 * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);
										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1796);
										mem_vec_1796 = vec_24;
										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1797);
										mem_vec_1797 = vec_26;
										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1798);
										mem_vec_1798 = vec_27;
										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1799);
										mem_vec_1799 = vec_28;
										scal_5 = input[strideA1 * (x + w) + strideA2 * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);
										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1800);
										mem_vec_1800 = vec_29;
										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1801);
										mem_vec_1801 = vec_31;
										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1802);
										mem_vec_1802 = vec_32;
										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1803);
										mem_vec_1803 = vec_33;
									}
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f], mem_vec_1780);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 16], mem_vec_1781);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 32], mem_vec_1782);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * y + f + 48], mem_vec_1783);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f], mem_vec_1784);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 16], mem_vec_1785);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 32], mem_vec_1786);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 1) + f + 48], mem_vec_1787);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f], mem_vec_1788);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 16], mem_vec_1789);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 32], mem_vec_1790);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 2) + f + 48], mem_vec_1791);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f], mem_vec_1792);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 16], mem_vec_1793);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 32], mem_vec_1794);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 3) + f + 48], mem_vec_1795);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f], mem_vec_1796);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 16], mem_vec_1797);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 32], mem_vec_1798);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 4) + f + 48], mem_vec_1799);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f], mem_vec_1800);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 16], mem_vec_1801);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 32], mem_vec_1802);
								_mm512_storeu_ps(&output[strideO1 * x + strideO2 * (y + 5) + f + 48], mem_vec_1803);
						}
}
