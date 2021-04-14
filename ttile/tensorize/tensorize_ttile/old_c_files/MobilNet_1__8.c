#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (14, x); T (3, w);
  T (3, h); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 8)); ((Iter 8), (Arg 9))]; T (2, c);
  T (8, x)]
*/
IND_TYPE c, cp_0, c210_p_0, cp_1, c210, h, hp_0, w, wp_0, x, xp_0, x280_p_0, x281_p_0, xp_1, x280_p_1, xp_2, x280, x281, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y140 = 0;
IND_TYPE x282 = 0;
IND_TYPE h120 = 0;
IND_TYPE w140 = 0;
IND_TYPE c211 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_1488 ,mem_vec_1489 ,mem_vec_1490 ,mem_vec_1491 ,mem_vec_1492 ,mem_vec_1493 ,mem_vec_1494 ,mem_vec_1495 ,mem_vec_1496 ,mem_vec_1497 ,mem_vec_1498 ,mem_vec_1499 ,mem_vec_1500 ,mem_vec_1501 ,mem_vec_1502 ,mem_vec_1503 ,mem_vec_1504 ,mem_vec_1505 ,mem_vec_1506 ,mem_vec_1507 ,mem_vec_1508 ,mem_vec_1509 ,mem_vec_1510 ,mem_vec_1511 ,mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,mem_vec_1516 ,mem_vec_1517 ,mem_vec_1518 ,mem_vec_1519 ,mem_vec_1520 ,mem_vec_1521 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 8) (112 / 14)
for (x281 = x282, x281_p_0 = 0;
	x281 < x282 + 112;
	x281 += 14, x281_p_0 += 14){
	// y = 112, x = 14, h = 3, w = 3, c = 32, f = 32
	// T (c, 2) (32 / 16)
	for (c210 = c211, c210_p_0 = 0;
		c210 < c211 + 32;
		c210 += 16, c210_p_0 += 16){
			for (y = y140, yp_0 = 0;
				y < y140 + 40;
				y += 8, yp_0 += 8){
				// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
				// T (x, 1) (14 / 14)
				for (x280 = x281, x280_p_1 = x281_p_0, x280_p_0 = 0;
					x280 < x281 + 14;
					x280 += 14, x280_p_1 += 14, x280_p_0 += 14){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h120, hp_0 = 0;
						h < h120 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w140, wp_0 = 0;
							w < w140 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 1, c = 16, f = 32
							// T (x, 14) (14 / 1)
							for (x = x280, xp_2 = x280_p_1, xp_1 = x280_p_0, xp_0 = 0;
								x < x280 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1488 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1489 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c210, cp_1 = c210_p_0, cp_0 = 0;
											c < c210 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1488);
											mem_vec_1488 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1489);
											mem_vec_1489 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1490);
											mem_vec_1490 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1491);
											mem_vec_1491 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1492);
											mem_vec_1492 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1493);
											mem_vec_1493 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1494);
											mem_vec_1494 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1495);
											mem_vec_1495 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1496);
											mem_vec_1496 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1497);
											mem_vec_1497 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1498);
											mem_vec_1498 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1499);
											mem_vec_1499 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1500);
											mem_vec_1500 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1501);
											mem_vec_1501 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1502);
											mem_vec_1502 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1503);
											mem_vec_1503 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1488);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1489);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1490);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1491);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1492);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1493);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1494);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1495);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1496);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1497);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1498);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1499);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1500);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1501);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1502);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1503);
							}
						}
					}
				}
			}
			for (y = y140 + 40, yp_0 = 0;
				y < y140 + 40 + 72;
				y += 9, yp_0 += 9){
				// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
				// T (x, 1) (14 / 14)
				for (x280 = x281, x280_p_1 = x281_p_0, x280_p_0 = 0;
					x280 < x281 + 14;
					x280 += 14, x280_p_1 += 14, x280_p_0 += 14){
					// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
					// T (h, 3) (3 / 1)
					for (h = h120, hp_0 = 0;
						h < h120 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 14, h = 1, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w140, wp_0 = 0;
							w < w140 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 14, h = 1, w = 1, c = 16, f = 32
							// T (x, 14) (14 / 1)
							for (x = x280, xp_2 = x280_p_1, xp_1 = x280_p_0, xp_0 = 0;
								x < x280 + 14;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_1504 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_1505 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_1506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_1507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_1508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_1509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_1510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_1511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_1512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_1513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_1514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_1515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_1516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_1517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_1518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_1519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_1520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_1521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
										// T (c, 16) (16 / 1)
										for (c = c210, cp_1 = c210_p_0, cp_0 = 0;
											c < c210 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1504);
											mem_vec_1504 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1505);
											mem_vec_1505 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1506);
											mem_vec_1506 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1507);
											mem_vec_1507 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1508);
											mem_vec_1508 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1509);
											mem_vec_1509 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1510);
											mem_vec_1510 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1511);
											mem_vec_1511 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1512);
											mem_vec_1512 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1513);
											mem_vec_1513 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1514);
											mem_vec_1514 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1515);
											mem_vec_1515 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1516);
											mem_vec_1516 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1517);
											mem_vec_1517 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1518);
											mem_vec_1518 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1519);
											mem_vec_1519 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1520);
											mem_vec_1520 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1521);
											mem_vec_1521 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1504);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1505);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1506);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1507);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1508);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1509);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1510);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1511);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1512);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1513);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1514);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1515);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1516);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1517);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1518);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1519);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1520);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1521);
							}
						}
					}
				}
			}
	}
}


}