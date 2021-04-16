#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, c);
  T (136, x); T (4, y)]
*/
IND_TYPE c, cp_0, c299_p_0, cp_1, c299, x, xp_0, x399_p_0, xp_1, x399, y, yp_0, y399_p_0, yp_1, y399;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y400 = 0;
IND_TYPE x400 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c300 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_5534 ,mem_vec_5535 ,mem_vec_5536 ,mem_vec_5537 ,mem_vec_5538 ,mem_vec_5539 ,mem_vec_5540 ,mem_vec_5541 ,mem_vec_5542 ,mem_vec_5543 ,mem_vec_5544 ,mem_vec_5545 ,mem_vec_5546 ,mem_vec_5547 ,mem_vec_5548 ,mem_vec_5549 ,mem_vec_5550 ,mem_vec_5551 ,mem_vec_5552 ,mem_vec_5553 ,mem_vec_5554 ,mem_vec_5555 ,mem_vec_5556 ,mem_vec_5557 ,mem_vec_5558 ,mem_vec_5559 ,mem_vec_5560 ,mem_vec_5561 ,mem_vec_5562 ,mem_vec_5563 ,mem_vec_5564 ,mem_vec_5565 ,mem_vec_5566 ,mem_vec_5567 ,mem_vec_5568 ,mem_vec_5569 ,mem_vec_5570 ,mem_vec_5571 ,mem_vec_5572 ,mem_vec_5573 ,mem_vec_5574 ,mem_vec_5575 ,mem_vec_5576 ,mem_vec_5577 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y399 = y400, y399_p_0 = 0;
	y399 < y400 + 136;
	y399 += 34, y399_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x399 = x400, x399_p_0 = 0;
		x399 < x400 + 136;
		x399 += 1, x399_p_0 += 1){
		// y = 34, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (c, 1) (128 / 128)
		for (c299 = c300, c299_p_0 = 0;
			c299 < c300 + 128;
			c299 += 128, c299_p_0 += 128){
				for (y = y399, yp_1 = y399_p_0, yp_0 = 0;
					y < y399 + 20;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (x, 1) (1 / 1)
					for (x = x399, xp_1 = x399_p_0, xp_0 = 0;
						x < x399 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_5534 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5535 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5536 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_5537 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_5538 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5539 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5540 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_5541 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_5542 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5543 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5544 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_5545 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_5546 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5547 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5548 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_5549 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c299, cp_1 = c299_p_0, cp_0 = 0;
									c < c299 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5534);
									mem_vec_5534 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5535);
									mem_vec_5535 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5536);
									mem_vec_5536 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5537);
									mem_vec_5537 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5538);
									mem_vec_5538 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5539);
									mem_vec_5539 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5540);
									mem_vec_5540 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5541);
									mem_vec_5541 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5542);
									mem_vec_5542 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5543);
									mem_vec_5543 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5544);
									mem_vec_5544 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5545);
									mem_vec_5545 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5546);
									mem_vec_5546 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5547);
									mem_vec_5547 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5548);
									mem_vec_5548 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5549);
									mem_vec_5549 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5534);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5535);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5536);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5537);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5538);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5539);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5540);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5541);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5542);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5543);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5544);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5545);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5546);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5547);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5548);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5549);
					}
				}
				for (y = y399 + 20, yp_1 = y399_p_0, yp_0 = 0;
					y < y399 + 20 + 14;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
					// T (x, 1) (1 / 1)
					for (x = x399, xp_1 = x399_p_0, xp_0 = 0;
						x < x399 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_5550 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5551 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5552 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_5553 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_5554 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5555 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5556 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_5557 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_5558 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5559 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5560 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_5561 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_5562 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5563 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5564 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_5565 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_5566 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_5567 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_5568 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_5569 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_5570 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_5571 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_5572 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_5573 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_5574 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_5575 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_5576 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_5577 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c299, cp_1 = c299_p_0, cp_0 = 0;
									c < c299 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5550);
									mem_vec_5550 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5551);
									mem_vec_5551 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5552);
									mem_vec_5552 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5553);
									mem_vec_5553 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5554);
									mem_vec_5554 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5555);
									mem_vec_5555 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5556);
									mem_vec_5556 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5557);
									mem_vec_5557 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5558);
									mem_vec_5558 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5559);
									mem_vec_5559 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5560);
									mem_vec_5560 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5561);
									mem_vec_5561 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5562);
									mem_vec_5562 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5563);
									mem_vec_5563 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5564);
									mem_vec_5564 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5565);
									mem_vec_5565 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5566);
									mem_vec_5566 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5567);
									mem_vec_5567 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5568);
									mem_vec_5568 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5569);
									mem_vec_5569 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5570);
									mem_vec_5570 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5571);
									mem_vec_5571 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5572);
									mem_vec_5572 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5573);
									mem_vec_5573 = vec_33;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_5574);
									mem_vec_5574 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_5575);
									mem_vec_5575 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_5576);
									mem_vec_5576 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_5577);
									mem_vec_5577 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5550);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5551);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5552);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5553);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5554);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5555);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5556);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5557);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5558);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5559);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5560);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5561);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5562);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5563);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5564);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5565);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5566);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5567);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5568);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5569);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5570);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5571);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5572);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5573);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5574);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5575);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_5576);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_5577);
					}
				}
		}
	}
}


}