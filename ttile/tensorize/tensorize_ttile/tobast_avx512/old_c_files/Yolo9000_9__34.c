#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (4, f);
  T (16, c); T (17, x)]
*/
IND_TYPE c, cp_0, c786_p_0, cp_1, c786, f, fp_0, x, xp_0, x1048_p_0, x1049_p_0, xp_1, x1048_p_1, xp_2, x1048, x1049, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y524 = 0;
IND_TYPE x1050 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c787 = 0;
IND_TYPE f524 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9552 ,mem_vec_9553 ,mem_vec_9554 ,mem_vec_9555 ,mem_vec_9556 ,mem_vec_9557 ,mem_vec_9558 ,mem_vec_9559 ,mem_vec_9560 ,mem_vec_9561 ,mem_vec_9562 ,mem_vec_9563 ,mem_vec_9564 ,mem_vec_9565 ,mem_vec_9566 ,mem_vec_9567 ,mem_vec_9568 ,mem_vec_9569 ,mem_vec_9570 ,mem_vec_9571 ,mem_vec_9572 ,mem_vec_9573 ,mem_vec_9574 ,mem_vec_9575 ,mem_vec_9576 ,mem_vec_9577 ,mem_vec_9578 ,mem_vec_9579 ,mem_vec_9580 ,mem_vec_9581 ,mem_vec_9582 ,mem_vec_9583 ,mem_vec_9584 ,mem_vec_9585 ,mem_vec_9586 ,mem_vec_9587 ,mem_vec_9588 ,mem_vec_9589 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 17) (68 / 4)
for (x1049 = x1050, x1049_p_0 = 0;
	x1049 < x1050 + 68;
	x1049 += 4, x1049_p_0 += 4){
	// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
	// T (c, 16) (256 / 16)
	for (c786 = c787, c786_p_0 = 0;
		c786 < c787 + 256;
		c786 += 16, c786_p_0 += 16){
		// y = 68, x = 4, h = 1, w = 1, c = 16, f = 128
		// T (f, 4) (128 / 32)
		for (f = f524, fp_0 = 0;
			f < f524 + 128;
			f += 32, fp_0 += 32){
				for (y = y524, yp_0 = 0;
					y < y524 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
					// T (x, 4) (4 / 1)
					for (x1048 = x1049, x1048_p_1 = x1049_p_0, x1048_p_0 = 0;
						x1048 < x1049 + 4;
						x1048 += 1, x1048_p_1 += 1, x1048_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1048, xp_2 = x1048_p_1, xp_1 = x1048_p_0, xp_0 = 0;
							x < x1048 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9552 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_9563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_9564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_9565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_9566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_9567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_9568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_9569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c786, cp_1 = c786_p_0, cp_0 = 0;
										c < c786 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9552);
										mem_vec_9552 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9553);
										mem_vec_9553 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9554);
										mem_vec_9554 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9555);
										mem_vec_9555 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9556);
										mem_vec_9556 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9557);
										mem_vec_9557 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9558);
										mem_vec_9558 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9559);
										mem_vec_9559 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9560);
										mem_vec_9560 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9561);
										mem_vec_9561 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9562);
										mem_vec_9562 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9563);
										mem_vec_9563 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9564);
										mem_vec_9564 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9565);
										mem_vec_9565 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9566);
										mem_vec_9566 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9567);
										mem_vec_9567 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9568);
										mem_vec_9568 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9569);
										mem_vec_9569 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9552);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9553);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9554);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9555);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9556);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9557);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9558);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9559);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9560);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9561);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9562);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9563);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9564);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9565);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9566);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9567);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9568);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9569);
						}
					}
				}
				for (y = y524 + 18, yp_0 = 0;
					y < y524 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
					// T (x, 4) (4 / 1)
					for (x1048 = x1049, x1048_p_1 = x1049_p_0, x1048_p_0 = 0;
						x1048 < x1049 + 4;
						x1048 += 1, x1048_p_1 += 1, x1048_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1048, xp_2 = x1048_p_1, xp_1 = x1048_p_0, xp_0 = 0;
							x < x1048 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9570 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9571 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9578 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9579 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9580 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_9581 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_9582 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_9583 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_9584 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_9585 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_9586 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_9587 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_9588 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_9589 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c786, cp_1 = c786_p_0, cp_0 = 0;
										c < c786 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9570);
										mem_vec_9570 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9571);
										mem_vec_9571 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9572);
										mem_vec_9572 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9573);
										mem_vec_9573 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9574);
										mem_vec_9574 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9575);
										mem_vec_9575 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9576);
										mem_vec_9576 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9577);
										mem_vec_9577 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9578);
										mem_vec_9578 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9579);
										mem_vec_9579 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9580);
										mem_vec_9580 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9581);
										mem_vec_9581 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9582);
										mem_vec_9582 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9583);
										mem_vec_9583 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9584);
										mem_vec_9584 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9585);
										mem_vec_9585 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9586);
										mem_vec_9586 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9587);
										mem_vec_9587 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9588);
										mem_vec_9588 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9589);
										mem_vec_9589 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9570);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9571);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9572);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9573);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9574);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9575);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9576);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9577);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9578);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9579);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9580);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9581);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9582);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9583);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9584);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9585);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9586);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9587);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9588);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9589);
						}
					}
				}
		}
	}
}


}