#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (3, c); Hoist_vars [c]; T (136, x); T (1, c);
  T (3, w); T (3, h); T (34, y); T (4, x); T (4, y); T (1, y)]
*/
IND_TYPE c, cp_0, c190_p_0, cp_1, c190, h, hp_0, w, wp_0, x, xp_0, x242_p_0, xp_1, x242, y, yp_0, y262_p_0, y263_p_0, yp_1, y262_p_1, yp_2, y262, y263;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y264 = 0;
IND_TYPE x243 = 0;
IND_TYPE h104 = 0;
IND_TYPE w130 = 0;
IND_TYPE c191 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m256 mem_vec_1712 ,mem_vec_1713 ,mem_vec_1714 ,mem_vec_1715 ,mem_vec_1716 ,mem_vec_1717 ,mem_vec_1718 ,mem_vec_1719 ,mem_vec_1720 ,mem_vec_1721 ,mem_vec_1722 ,mem_vec_1723 ,mem_vec_1724 ,mem_vec_1725 ,mem_vec_1726 ,mem_vec_1727 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 1) (544 / 544)
for (y263 = y264, y263_p_0 = 0;
	y263 < y264 + 544;
	y263 += 544, y263_p_0 += 544){
	// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 4) (544 / 136)
	for (y262 = y263, y262_p_1 = y263_p_0, y262_p_0 = 0;
		y262 < y263 + 544;
		y262 += 136, y262_p_1 += 136, y262_p_0 += 136){
		// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 4) (544 / 136)
		for (x242 = x243, x242_p_0 = 0;
			x242 < x243 + 544;
			x242 += 136, x242_p_0 += 136){
			// y = 136, x = 136, h = 3, w = 3, c = 3, f = 32
			// T (y, 34) (136 / 4)
			for (y = y262, yp_2 = y262_p_1, yp_1 = y262_p_0, yp_0 = 0;
				y < y262 + 136;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 136, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h104, hp_0 = 0;
					h < h104 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 136, h = 1, w = 3, c = 3, f = 32
					// T (w, 3) (3 / 1)
					for (w = w130, wp_0 = 0;
						w < w130 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 136, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c190 = c191, c190_p_0 = 0;
							c190 < c191 + 3;
							c190 += 3, c190_p_0 += 3){
							// y = 4, x = 136, h = 1, w = 1, c = 3, f = 32
							// T (x, 136) (136 / 1)
							for (x = x242, xp_1 = x242_p_0, xp_0 = 0;
								x < x242 + 136;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1712 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1713 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_1714 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1715 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_1716 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1717 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_1718 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1719 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_1720 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1721 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_1722 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1723 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_1724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_1726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c190, cp_1 = c190_p_0, cp_0 = 0;
											c < c190 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1712);
											mem_vec_1712 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1713);
											mem_vec_1713 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1714);
											mem_vec_1714 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1715);
											mem_vec_1715 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1716);
											mem_vec_1716 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1717);
											mem_vec_1717 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1718);
											mem_vec_1718 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1719);
											mem_vec_1719 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1720);
											mem_vec_1720 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1721);
											mem_vec_1721 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1722);
											mem_vec_1722 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1723);
											mem_vec_1723 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1724);
											mem_vec_1724 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1725);
											mem_vec_1725 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1726);
											mem_vec_1726 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1727);
											mem_vec_1727 = vec_23;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1712);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1713);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1714);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1715);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1716);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1717);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1718);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1719);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1720);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1721);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1722);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1723);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1724);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1725);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1726);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1727);
							}
						}
					}
				}
			}
		}
	}
}


}