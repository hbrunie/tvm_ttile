#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, h); T (14, x);
  T (3, w); T (4, c); T (4, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 13)); ((Iter 1), (Arg 15))]; T (1, f)]
*/
IND_TYPE c, cp_0, c216_p_0, cp_1, c216, f, fp_0, f216_p_0, fp_1, f216, h, hp_0, w, wp_0, x, xp_0, x200_p_0, xp_1, x200, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y144 = 0;
IND_TYPE x201 = 0;
IND_TYPE h120 = 0;
IND_TYPE w126 = 0;
IND_TYPE c217 = 0;
IND_TYPE f217 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1804 ,mem_vec_1805 ,mem_vec_1806 ,mem_vec_1807 ,mem_vec_1808 ,mem_vec_1809 ,mem_vec_1810 ,mem_vec_1811 ,mem_vec_1812 ,mem_vec_1813 ,mem_vec_1814 ,mem_vec_1815 ,mem_vec_1816 ,mem_vec_1817 ,mem_vec_1818 ,mem_vec_1819 ,mem_vec_1820 ,mem_vec_1821 ,mem_vec_1822 ,mem_vec_1823 ,mem_vec_1824 ,mem_vec_1825 ,mem_vec_1826 ,mem_vec_1827 ,mem_vec_1828 ,mem_vec_1829 ,mem_vec_1830 ,mem_vec_1831 ,mem_vec_1832 ,mem_vec_1833 ,mem_vec_1834 ,mem_vec_1835 ,mem_vec_1836 ,mem_vec_1837 ,mem_vec_1838 ,mem_vec_1839 ,mem_vec_1840 ,mem_vec_1841 ,mem_vec_1842 ,mem_vec_1843 ,mem_vec_1844 ,mem_vec_1845 ,mem_vec_1846 ,mem_vec_1847 ,mem_vec_1848 ,mem_vec_1849 ,mem_vec_1850 ,mem_vec_1851 ,mem_vec_1852 ,mem_vec_1853 ,mem_vec_1854 ,mem_vec_1855 ,mem_vec_1856 ,mem_vec_1857 ,mem_vec_1858 ,mem_vec_1859 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f216 = f217, f216_p_0 = 0;
	f216 < f217 + 128;
	f216 += 128, f216_p_0 += 128){
		for (y = y144, yp_0 = 0;
			y < y144 + 13;
			y += 13, yp_0 += 13){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (28 / 14)
			for (x200 = x201, x200_p_0 = 0;
				x200 < x201 + 28;
				x200 += 14, x200_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
				// T (f, 4) (128 / 32)
				for (f = f216, fp_1 = f216_p_0, fp_0 = 0;
					f < f216 + 128;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c216 = c217, c216_p_0 = 0;
						c216 < c217 + 128;
						c216 += 32, c216_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w126, wp_0 = 0;
							w < w126 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x200, xp_1 = x200_p_0, xp_0 = 0;
								x < x200 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h120, hp_0 = 0;
									h < h120 + 3;
									h += 1, hp_0 += 1){
											mem_vec_1804 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1805 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_1819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_1820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_1821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_1822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_1823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_1824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_1825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_1826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_1827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_1828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_1829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c216, cp_1 = c216_p_0, cp_0 = 0;
												c < c216 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1804);
												mem_vec_1804 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1805);
												mem_vec_1805 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1806);
												mem_vec_1806 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1807);
												mem_vec_1807 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1808);
												mem_vec_1808 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1809);
												mem_vec_1809 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1810);
												mem_vec_1810 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1811);
												mem_vec_1811 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1812);
												mem_vec_1812 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1813);
												mem_vec_1813 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1814);
												mem_vec_1814 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1815);
												mem_vec_1815 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1816);
												mem_vec_1816 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1817);
												mem_vec_1817 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1818);
												mem_vec_1818 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1819);
												mem_vec_1819 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1820);
												mem_vec_1820 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1821);
												mem_vec_1821 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1822);
												mem_vec_1822 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1823);
												mem_vec_1823 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1824);
												mem_vec_1824 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1825);
												mem_vec_1825 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1826);
												mem_vec_1826 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1827);
												mem_vec_1827 = vec_37;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1828);
												mem_vec_1828 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1829);
												mem_vec_1829 = vec_40;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1804);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1805);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1806);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1807);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1808);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1809);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1810);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1811);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1812);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1813);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1814);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1815);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1816);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1817);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1818);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1819);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1820);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1821);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1822);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1823);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1824);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1825);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1826);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1827);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1828);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1829);
								}
							}
						}
					}
				}
			}
		}
		for (y = y144 + 13, yp_0 = 0;
			y < y144 + 13 + 15;
			y += 15, yp_0 += 15){
			// y = ph_y, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (x, 2) (28 / 14)
			for (x200 = x201, x200_p_0 = 0;
				x200 < x201 + 28;
				x200 += 14, x200_p_0 += 14){
				// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 128
				// T (f, 4) (128 / 32)
				for (f = f216, fp_1 = f216_p_0, fp_0 = 0;
					f < f216 + 128;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = ph_y, x = 14, h = 3, w = 3, c = 128, f = 32
					// T (c, 4) (128 / 32)
					for (c216 = c217, c216_p_0 = 0;
						c216 < c217 + 128;
						c216 += 32, c216_p_0 += 32){
						// y = ph_y, x = 14, h = 3, w = 3, c = 32, f = 32
						// T (w, 3) (3 / 1)
						for (w = w126, wp_0 = 0;
							w < w126 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 3, w = 1, c = 32, f = 32
							// T (x, 14) (14 / 1)
							for (x = x200, xp_1 = x200_p_0, xp_0 = 0;
								x < x200 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
								// T (h, 3) (3 / 1)
								for (h = h120, hp_0 = 0;
									h < h120 + 3;
									h += 1, hp_0 += 1){
											mem_vec_1830 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1831 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_1845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_1846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_1847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_1848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_1849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_1850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_1851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_1852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_1853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_1854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_1855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_1856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_1857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											mem_vec_1858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
											mem_vec_1859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c216, cp_1 = c216_p_0, cp_0 = 0;
												c < c216 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1830);
												mem_vec_1830 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1831);
												mem_vec_1831 = vec_3;
												scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1832);
												mem_vec_1832 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1833);
												mem_vec_1833 = vec_7;
												scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1834);
												mem_vec_1834 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1835);
												mem_vec_1835 = vec_10;
												scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1836);
												mem_vec_1836 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1837);
												mem_vec_1837 = vec_13;
												scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1838);
												mem_vec_1838 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1839);
												mem_vec_1839 = vec_16;
												scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1840);
												mem_vec_1840 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1841);
												mem_vec_1841 = vec_19;
												scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1842);
												mem_vec_1842 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1843);
												mem_vec_1843 = vec_22;
												scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1844);
												mem_vec_1844 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1845);
												mem_vec_1845 = vec_25;
												scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1846);
												mem_vec_1846 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1847);
												mem_vec_1847 = vec_28;
												scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1848);
												mem_vec_1848 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1849);
												mem_vec_1849 = vec_31;
												scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_1850);
												mem_vec_1850 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_1851);
												mem_vec_1851 = vec_34;
												scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_1852);
												mem_vec_1852 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_1853);
												mem_vec_1853 = vec_37;
												scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_1854);
												mem_vec_1854 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_1855);
												mem_vec_1855 = vec_40;
												scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_1856);
												mem_vec_1856 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_1857);
												mem_vec_1857 = vec_43;
												scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 14) + h) + c];
												vec_45 = _mm512_set1_ps(scal_14);


												vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_1858);
												mem_vec_1858 = vec_44;



												vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_1859);
												mem_vec_1859 = vec_46;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1830);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1831);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1832);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1833);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1834);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1835);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1836);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1837);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1838);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1839);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1840);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1841);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1842);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1843);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1844);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1845);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1846);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1847);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1848);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_1849);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_1850);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_1851);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_1852);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_1853);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_1854);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_1855);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_1856);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_1857);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_1858);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_1859);
								}
							}
						}
					}
				}
			}
		}
}


}