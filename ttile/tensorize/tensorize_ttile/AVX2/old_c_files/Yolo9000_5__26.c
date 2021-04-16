#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (4, y); T (2, f); T (1, x); T (2, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c165_p_0, cp_1, c165, f, fp_0, x, xp_0, x275_p_0, x276_p_0, x277_p_0, xp_1, x275_p_1, x276_p_1, xp_2, x275_p_2, xp_3, x275, x276, x277, y, yp_0, y220_p_0, y221_p_0, yp_1, y220_p_1, yp_2, y220, y221;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y222 = 0;
IND_TYPE x278 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c166 = 0;
IND_TYPE f110 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1580 ,mem_vec_1581 ,mem_vec_1582 ,mem_vec_1583 ,mem_vec_1584 ,mem_vec_1585 ,mem_vec_1586 ,mem_vec_1587 ,mem_vec_1588 ,mem_vec_1589 ,mem_vec_1590 ,mem_vec_1591 ,mem_vec_1592 ,mem_vec_1593 ,mem_vec_1594 ,mem_vec_1595 ,mem_vec_1596 ,mem_vec_1597 ,mem_vec_1598 ,mem_vec_1599 ,mem_vec_1600 ,mem_vec_1601 ,mem_vec_1602 ,mem_vec_1603 ,mem_vec_1604 ,mem_vec_1605 ,mem_vec_1606 ,mem_vec_1607 ,mem_vec_1608 ,mem_vec_1609 ,mem_vec_1610 ,mem_vec_1611 ,mem_vec_1612 ,mem_vec_1613 ,mem_vec_1614 ,mem_vec_1615 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y221 = y222, y221_p_0 = 0;
		y221 < y222 + 96;
		y221 += 32, y221_p_0 += 32){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x277 = x278, x277_p_0 = 0;
			x277 < x278 + 136;
			x277 += 2, x277_p_0 += 2){
			// y = 2 * (4 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y220 = y221, y220_p_1 = y221_p_0, y220_p_0 = 0;
				y220 < y221 + 32;
				y220 += 16, y220_p_1 += 16, y220_p_0 += 16){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x276 = x277, x276_p_1 = x277_p_0, x276_p_0 = 0;
					x276 < x277 + 2;
					x276 += 2, x276_p_1 += 2, x276_p_0 += 2){
					// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f110, fp_0 = 0;
						f < f110 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y220, yp_2 = y220_p_1, yp_1 = y220_p_0, yp_0 = 0;
							y < y220 + 16;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x275 = x276, x275_p_2 = x276_p_1, x275_p_1 = x276_p_0, x275_p_0 = 0;
								x275 < x276 + 2;
								x275 += 2, x275_p_2 += 2, x275_p_1 += 2, x275_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c165 = c166, c165_p_0 = 0;
									c165 < c166 + 128;
									c165 += 32, c165_p_0 += 32){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x275, xp_3 = x275_p_2, xp_2 = x275_p_1, xp_1 = x275_p_0, xp_0 = 0;
										x < x275 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1580 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1581 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1582 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1583 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1584 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1585 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1586 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1587 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1588 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1589 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1590 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1591 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1592 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1593 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c165, cp_1 = c165_p_0, cp_0 = 0;
													c < c165 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1580);
													mem_vec_1580 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1581);
													mem_vec_1581 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1582);
													mem_vec_1582 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1583);
													mem_vec_1583 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1584);
													mem_vec_1584 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1585);
													mem_vec_1585 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1586);
													mem_vec_1586 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1587);
													mem_vec_1587 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1588);
													mem_vec_1588 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1589);
													mem_vec_1589 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1590);
													mem_vec_1590 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1591);
													mem_vec_1591 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1592);
													mem_vec_1592 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1593);
													mem_vec_1593 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1594);
													mem_vec_1594 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1595);
													mem_vec_1595 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1580);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1581);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1582);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1583);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1584);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1585);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1586);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1587);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1588);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1589);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1590);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1591);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1592);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1593);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1594);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1595);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y221 = y222 + 96, y221_p_0 = 0;
		y221 < y222 + 96 + 40;
		y221 += 40, y221_p_0 += 40){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x277 = x278, x277_p_0 = 0;
			x277 < x278 + 136;
			x277 += 2, x277_p_0 += 2){
			// y = 2 * (4 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y220 = y221, y220_p_1 = y221_p_0, y220_p_0 = 0;
				y220 < y221 + 40;
				y220 += 20, y220_p_1 += 20, y220_p_0 += 20){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x276 = x277, x276_p_1 = x277_p_0, x276_p_0 = 0;
					x276 < x277 + 2;
					x276 += 2, x276_p_1 += 2, x276_p_0 += 2){
					// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f110, fp_0 = 0;
						f < f110 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y220, yp_2 = y220_p_1, yp_1 = y220_p_0, yp_0 = 0;
							y < y220 + 20;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x275 = x276, x275_p_2 = x276_p_1, x275_p_1 = x276_p_0, x275_p_0 = 0;
								x275 < x276 + 2;
								x275 += 2, x275_p_2 += 2, x275_p_1 += 2, x275_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c165 = c166, c165_p_0 = 0;
									c165 < c166 + 128;
									c165 += 32, c165_p_0 += 32){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x275, xp_3 = x275_p_2, xp_2 = x275_p_1, xp_1 = x275_p_0, xp_0 = 0;
										x < x275 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1596 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1597 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1598 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1599 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1602 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1603 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1608 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1609 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1610 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1611 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_1612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c165, cp_1 = c165_p_0, cp_0 = 0;
													c < c165 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1596);
													mem_vec_1596 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1597);
													mem_vec_1597 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1598);
													mem_vec_1598 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1599);
													mem_vec_1599 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1600);
													mem_vec_1600 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1601);
													mem_vec_1601 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1602);
													mem_vec_1602 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1603);
													mem_vec_1603 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1604);
													mem_vec_1604 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1605);
													mem_vec_1605 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1606);
													mem_vec_1606 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1607);
													mem_vec_1607 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1608);
													mem_vec_1608 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1609);
													mem_vec_1609 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1610);
													mem_vec_1610 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1611);
													mem_vec_1611 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1612);
													mem_vec_1612 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1613);
													mem_vec_1613 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1614);
													mem_vec_1614 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1615);
													mem_vec_1615 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1596);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1597);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1598);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1599);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1600);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1601);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1602);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1603);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1604);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1605);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1606);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1607);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1608);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1609);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1610);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1611);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1612);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1613);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1614);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1615);
									}
								}
							}
						}
					}
				}
			}
		}
	}


}