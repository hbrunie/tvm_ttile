#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (2, x); T (17, x);
  Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))]; T (4, f);
  T (64, c); T (2, x)]
*/
IND_TYPE c, cp_0, c918_p_0, cp_1, c918, f, fp_0, x, xp_0, x1224_p_0, x1225_p_0, xp_1, x1224_p_1, xp_2, x1224, x1225, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y612 = 0;
IND_TYPE x1226 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c919 = 0;
IND_TYPE f612 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11552 ,mem_vec_11553 ,mem_vec_11554 ,mem_vec_11555 ,mem_vec_11556 ,mem_vec_11557 ,mem_vec_11558 ,mem_vec_11559 ,mem_vec_11560 ,mem_vec_11561 ,mem_vec_11562 ,mem_vec_11563 ,mem_vec_11564 ,mem_vec_11565 ,mem_vec_11566 ,mem_vec_11567 ,mem_vec_11568 ,mem_vec_11569 ,mem_vec_11570 ,mem_vec_11571 ,mem_vec_11572 ,mem_vec_11573 ,mem_vec_11574 ,mem_vec_11575 ,mem_vec_11576 ,mem_vec_11577 ,mem_vec_11578 ,mem_vec_11579 ,mem_vec_11580 ,mem_vec_11581 ,mem_vec_11582 ,mem_vec_11583 ,mem_vec_11584 ,mem_vec_11585 ,mem_vec_11586 ,mem_vec_11587 ,mem_vec_11588 ,mem_vec_11589 ,mem_vec_11590 ,mem_vec_11591 ,mem_vec_11592 ,mem_vec_11593 ,mem_vec_11594 ,mem_vec_11595 ,mem_vec_11596 ,mem_vec_11597 ,mem_vec_11598 ,mem_vec_11599 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 2) (68 / 34)
for (x1225 = x1226, x1225_p_0 = 0;
	x1225 < x1226 + 68;
	x1225 += 34, x1225_p_0 += 34){
	// y = 68, x = 34, h = 1, w = 1, c = 256, f = 128
	// T (c, 64) (256 / 4)
	for (c918 = c919, c918_p_0 = 0;
		c918 < c919 + 256;
		c918 += 4, c918_p_0 += 4){
		// y = 68, x = 34, h = 1, w = 1, c = 4, f = 128
		// T (f, 4) (128 / 32)
		for (f = f612, fp_0 = 0;
			f < f612 + 128;
			f += 32, fp_0 += 32){
				for (y = y612, yp_0 = 0;
					y < y612 + 55;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (34 / 2)
					for (x1224 = x1225, x1224_p_1 = x1225_p_0, x1224_p_0 = 0;
						x1224 < x1225 + 34;
						x1224 += 2, x1224_p_1 += 2, x1224_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
						// T (x, 2) (2 / 1)
						for (x = x1224, xp_2 = x1224_p_1, xp_1 = x1224_p_0, xp_0 = 0;
							x < x1224 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11552 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_11567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_11568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_11569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_11570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_11571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_11572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_11573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c918, cp_1 = c918_p_0, cp_0 = 0;
										c < c918 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11552);
										mem_vec_11552 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11553);
										mem_vec_11553 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11554);
										mem_vec_11554 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11555);
										mem_vec_11555 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11556);
										mem_vec_11556 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11557);
										mem_vec_11557 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11558);
										mem_vec_11558 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11559);
										mem_vec_11559 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11560);
										mem_vec_11560 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11561);
										mem_vec_11561 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11562);
										mem_vec_11562 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11563);
										mem_vec_11563 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11564);
										mem_vec_11564 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11565);
										mem_vec_11565 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11566);
										mem_vec_11566 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11567);
										mem_vec_11567 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11568);
										mem_vec_11568 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11569);
										mem_vec_11569 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11570);
										mem_vec_11570 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11571);
										mem_vec_11571 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11572);
										mem_vec_11572 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11573);
										mem_vec_11573 = vec_34;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11552);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11553);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11554);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11555);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11556);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11557);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11558);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11559);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11560);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11561);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11562);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11563);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11564);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11565);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11566);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11567);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11568);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11569);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11570);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11571);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11572);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11573);
						}
					}
				}
				for (y = y612 + 55, yp_0 = 0;
					y < y612 + 55 + 13;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (34 / 2)
					for (x1224 = x1225, x1224_p_1 = x1225_p_0, x1224_p_0 = 0;
						x1224 < x1225 + 34;
						x1224 += 2, x1224_p_1 += 2, x1224_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
						// T (x, 2) (2 / 1)
						for (x = x1224, xp_2 = x1224_p_1, xp_1 = x1224_p_0, xp_0 = 0;
							x < x1224 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11574 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11575 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_11589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_11590 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_11591 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_11592 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_11593 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_11594 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_11595 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_11596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_11597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_11598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_11599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c918, cp_1 = c918_p_0, cp_0 = 0;
										c < c918 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11574);
										mem_vec_11574 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11575);
										mem_vec_11575 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11576);
										mem_vec_11576 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11577);
										mem_vec_11577 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11578);
										mem_vec_11578 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11579);
										mem_vec_11579 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11580);
										mem_vec_11580 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11581);
										mem_vec_11581 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11582);
										mem_vec_11582 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11583);
										mem_vec_11583 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11584);
										mem_vec_11584 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11585);
										mem_vec_11585 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11586);
										mem_vec_11586 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11587);
										mem_vec_11587 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11588);
										mem_vec_11588 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11589);
										mem_vec_11589 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11590);
										mem_vec_11590 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11591);
										mem_vec_11591 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11592);
										mem_vec_11592 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11593);
										mem_vec_11593 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11594);
										mem_vec_11594 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11595);
										mem_vec_11595 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11596);
										mem_vec_11596 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11597);
										mem_vec_11597 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11598);
										mem_vec_11598 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11599);
										mem_vec_11599 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11585);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11587);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11588);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11589);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11590);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11591);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11592);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11593);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11594);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11595);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11596);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11597);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_11598);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_11599);
						}
					}
				}
		}
	}
}


}