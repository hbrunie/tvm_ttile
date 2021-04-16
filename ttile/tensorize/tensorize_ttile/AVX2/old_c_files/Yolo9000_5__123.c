#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (1, c);
  T (1, x); T (4, y); T (2, f); T (1, x); T (2, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c159_p_0, cp_1, c159, f, fp_0, x, xp_0, x265_p_0, x266_p_0, x267_p_0, xp_1, x265_p_1, x266_p_1, xp_2, x265_p_2, xp_3, x265, x266, x267, y, yp_0, y212_p_0, y213_p_0, yp_1, y212_p_1, yp_2, y212, y213;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y214 = 0;
IND_TYPE x268 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c160 = 0;
IND_TYPE f106 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1508 ,mem_vec_1509 ,mem_vec_1510 ,mem_vec_1511 ,mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,mem_vec_1516 ,mem_vec_1517 ,mem_vec_1518 ,mem_vec_1519 ,mem_vec_1520 ,mem_vec_1521 ,mem_vec_1522 ,mem_vec_1523 ,mem_vec_1524 ,mem_vec_1525 ,mem_vec_1526 ,mem_vec_1527 ,mem_vec_1528 ,mem_vec_1529 ,mem_vec_1530 ,mem_vec_1531 ,mem_vec_1532 ,mem_vec_1533 ,mem_vec_1534 ,mem_vec_1535 ,mem_vec_1536 ,mem_vec_1537 ,mem_vec_1538 ,mem_vec_1539 ,mem_vec_1540 ,mem_vec_1541 ,mem_vec_1542 ,mem_vec_1543 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y213 = y214, y213_p_0 = 0;
		y213 < y214 + 96;
		y213 += 32, y213_p_0 += 32){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x267 = x268, x267_p_0 = 0;
			x267 < x268 + 136;
			x267 += 2, x267_p_0 += 2){
			// y = 2 * (4 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y212 = y213, y212_p_1 = y213_p_0, y212_p_0 = 0;
				y212 < y213 + 32;
				y212 += 16, y212_p_1 += 16, y212_p_0 += 16){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x266 = x267, x266_p_1 = x267_p_0, x266_p_0 = 0;
					x266 < x267 + 2;
					x266 += 2, x266_p_1 += 2, x266_p_0 += 2){
					// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f106, fp_0 = 0;
						f < f106 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y212, yp_2 = y212_p_1, yp_1 = y212_p_0, yp_0 = 0;
							y < y212 + 16;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x265 = x266, x265_p_2 = x266_p_1, x265_p_1 = x266_p_0, x265_p_0 = 0;
								x265 < x266 + 2;
								x265 += 2, x265_p_2 += 2, x265_p_1 += 2, x265_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c159 = c160, c159_p_0 = 0;
									c159 < c160 + 128;
									c159 += 128, c159_p_0 += 128){
									// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
									// T (x, 2) (2 / 1)
									for (x = x265, xp_3 = x265_p_2, xp_2 = x265_p_1, xp_1 = x265_p_0, xp_0 = 0;
										x < x265 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1508 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1509 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1510 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1511 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1512 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1513 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1514 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1515 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c159, cp_1 = c159_p_0, cp_0 = 0;
													c < c159 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1508);
													mem_vec_1508 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1509);
													mem_vec_1509 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1510);
													mem_vec_1510 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1511);
													mem_vec_1511 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1512);
													mem_vec_1512 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1513);
													mem_vec_1513 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1514);
													mem_vec_1514 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1515);
													mem_vec_1515 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1516);
													mem_vec_1516 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1517);
													mem_vec_1517 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1518);
													mem_vec_1518 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1519);
													mem_vec_1519 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1520);
													mem_vec_1520 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1521);
													mem_vec_1521 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1522);
													mem_vec_1522 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1523);
													mem_vec_1523 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1508);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1509);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1510);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1511);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1512);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1513);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1514);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1515);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1516);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1517);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1518);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1519);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1520);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1521);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1522);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1523);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y213 = y214 + 96, y213_p_0 = 0;
		y213 < y214 + 96 + 40;
		y213 += 40, y213_p_0 += 40){
		// y = 2 * (4 * ph_y), x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x267 = x268, x267_p_0 = 0;
			x267 < x268 + 136;
			x267 += 2, x267_p_0 += 2){
			// y = 2 * (4 * ph_y), x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
			for (y212 = y213, y212_p_1 = y213_p_0, y212_p_0 = 0;
				y212 < y213 + 40;
				y212 += 20, y212_p_1 += 20, y212_p_0 += 20){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x266 = x267, x266_p_1 = x267_p_0, x266_p_0 = 0;
					x266 < x267 + 2;
					x266 += 2, x266_p_1 += 2, x266_p_0 += 2){
					// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f106, fp_0 = 0;
						f < f106 + 64;
						f += 32, fp_0 += 32){
						// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 4) (4 * ph_y / ph_y)
						for (y = y212, yp_2 = y212_p_1, yp_1 = y212_p_0, yp_0 = 0;
							y < y212 + 20;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x265 = x266, x265_p_2 = x266_p_1, x265_p_1 = x266_p_0, x265_p_0 = 0;
								x265 < x266 + 2;
								x265 += 2, x265_p_2 += 2, x265_p_1 += 2, x265_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 1) (128 / 128)
								for (c159 = c160, c159_p_0 = 0;
									c159 < c160 + 128;
									c159 += 128, c159_p_0 += 128){
									// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
									// T (x, 2) (2 / 1)
									for (x = x265, xp_3 = x265_p_2, xp_2 = x265_p_1, xp_1 = x265_p_0, xp_0 = 0;
										x < x265 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1524 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1525 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1526 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1527 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1528 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1529 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1530 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1531 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_1540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c159, cp_1 = c159_p_0, cp_0 = 0;
													c < c159 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1524);
													mem_vec_1524 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1525);
													mem_vec_1525 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1526);
													mem_vec_1526 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1527);
													mem_vec_1527 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1528);
													mem_vec_1528 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1529);
													mem_vec_1529 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1530);
													mem_vec_1530 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1531);
													mem_vec_1531 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1532);
													mem_vec_1532 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1533);
													mem_vec_1533 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1534);
													mem_vec_1534 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1535);
													mem_vec_1535 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1536);
													mem_vec_1536 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1537);
													mem_vec_1537 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1538);
													mem_vec_1538 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1539);
													mem_vec_1539 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1540);
													mem_vec_1540 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1541);
													mem_vec_1541 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1542);
													mem_vec_1542 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1543);
													mem_vec_1543 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1524);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1525);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1526);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1527);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1528);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1529);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1530);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1531);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1532);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1533);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1534);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1535);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1536);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1537);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1538);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1539);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1540);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1541);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1542);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1543);
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