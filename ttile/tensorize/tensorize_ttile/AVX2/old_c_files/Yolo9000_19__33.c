#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (1, c); Hoist_vars [c]; T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (16, f);
  T (1024, c); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c126_p_0, cp_1, c126, f, fp_0, x, xp_0, x126_p_0, xp_1, x126, y, yp_0, y126_p_0, yp_1, y126;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y127 = 0;
IND_TYPE x127 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c127 = 0;
IND_TYPE f84 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,mem_vec_1516 ,mem_vec_1517 ,mem_vec_1518 ,mem_vec_1519 ,mem_vec_1520 ,mem_vec_1521 ,mem_vec_1522 ,mem_vec_1523 ,mem_vec_1524 ,mem_vec_1525 ,mem_vec_1526 ,mem_vec_1527 ,mem_vec_1528 ,mem_vec_1529 ,mem_vec_1530 ,mem_vec_1531 ,mem_vec_1532 ,mem_vec_1533 ,mem_vec_1534 ,mem_vec_1535 ,mem_vec_1536 ,mem_vec_1537 ,mem_vec_1538 ,mem_vec_1539 ,mem_vec_1540 ,mem_vec_1541 ,mem_vec_1542 ,mem_vec_1543 ,mem_vec_1544 ,mem_vec_1545 ,mem_vec_1546 ,mem_vec_1547 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y126 = y127, y126_p_0 = 0;
	y126 < y127 + 17;
	y126 += 17, y126_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (x, 1) (17 / 17)
	for (x126 = x127, x126_p_0 = 0;
		x126 < x127 + 17;
		x126 += 17, x126_p_0 += 17){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1024) (1024 / 1)
		for (c126 = c127, c126_p_0 = 0;
			c126 < c127 + 1024;
			c126 += 1, c126_p_0 += 1){
			// y = 17, x = 17, h = 1, w = 1, c = 1, f = 512
			// T (f, 16) (512 / 32)
			for (f = f84, fp_0 = 0;
				f < f84 + 512;
				f += 32, fp_0 += 32){
					for (y = y126, yp_1 = y126_p_0, yp_0 = 0;
						y < y126 + 12;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
						// T (x, 17) (17 / 1)
						for (x = x126, xp_1 = x126_p_0, xp_0 = 0;
							x < x126 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1512 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1513 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1514 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1515 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1516 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1517 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1518 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1519 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1520 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1521 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1522 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1523 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1524 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1525 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1526 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1527 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c126, cp_1 = c126_p_0, cp_0 = 0;
										c < c126 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1512);
										mem_vec_1512 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1513);
										mem_vec_1513 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1514);
										mem_vec_1514 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1515);
										mem_vec_1515 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1516);
										mem_vec_1516 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1517);
										mem_vec_1517 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1518);
										mem_vec_1518 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1519);
										mem_vec_1519 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1520);
										mem_vec_1520 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1521);
										mem_vec_1521 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1522);
										mem_vec_1522 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1523);
										mem_vec_1523 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1524);
										mem_vec_1524 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1525);
										mem_vec_1525 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1526);
										mem_vec_1526 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1527);
										mem_vec_1527 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1512);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1513);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1514);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1515);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1516);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1517);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1518);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1519);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1520);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1521);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1522);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1523);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1524);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1525);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1526);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1527);
						}
					}
					for (y = y126 + 12, yp_1 = y126_p_0, yp_0 = 0;
						y < y126 + 12 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
						// T (x, 17) (17 / 1)
						for (x = x126, xp_1 = x126_p_0, xp_0 = 0;
							x < x126 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1528 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1529 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1530 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1531 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1532 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1533 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1534 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1535 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1536 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1537 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1538 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1539 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_1546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c126, cp_1 = c126_p_0, cp_0 = 0;
										c < c126 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1528);
										mem_vec_1528 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1529);
										mem_vec_1529 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1530);
										mem_vec_1530 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1531);
										mem_vec_1531 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1532);
										mem_vec_1532 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1533);
										mem_vec_1533 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1534);
										mem_vec_1534 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1535);
										mem_vec_1535 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1536);
										mem_vec_1536 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1537);
										mem_vec_1537 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1538);
										mem_vec_1538 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1539);
										mem_vec_1539 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1540);
										mem_vec_1540 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1541);
										mem_vec_1541 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1542);
										mem_vec_1542 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1543);
										mem_vec_1543 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1544);
										mem_vec_1544 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1545);
										mem_vec_1545 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1546);
										mem_vec_1546 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1547);
										mem_vec_1547 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1528);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1529);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1530);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1531);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1532);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1533);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1534);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1535);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1536);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1537);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1538);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1539);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1540);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1541);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1542);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1543);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1544);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1545);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1546);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1547);
						}
					}
			}
		}
	}
}


}