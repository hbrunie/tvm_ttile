#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (16, c); T (17, x)]
*/
IND_TYPE c, cp_0, c1164_p_0, cp_1, c1164, f, fp_0, x, xp_0, x1552_p_0, x1553_p_0, xp_1, x1552_p_1, xp_2, x1552, x1553, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y776 = 0;
IND_TYPE x1554 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1165 = 0;
IND_TYPE f776 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_16456 ,mem_vec_16457 ,mem_vec_16458 ,mem_vec_16459 ,mem_vec_16460 ,mem_vec_16461 ,mem_vec_16462 ,mem_vec_16463 ,mem_vec_16464 ,mem_vec_16465 ,mem_vec_16466 ,mem_vec_16467 ,mem_vec_16468 ,mem_vec_16469 ,mem_vec_16470 ,mem_vec_16471 ,mem_vec_16472 ,mem_vec_16473 ,mem_vec_16474 ,mem_vec_16475 ,mem_vec_16476 ,mem_vec_16477 ,mem_vec_16478 ,mem_vec_16479 ,mem_vec_16480 ,mem_vec_16481 ,mem_vec_16482 ,mem_vec_16483 ,mem_vec_16484 ,mem_vec_16485 ,mem_vec_16486 ,mem_vec_16487 ,mem_vec_16488 ,mem_vec_16489 ,mem_vec_16490 ,mem_vec_16491 ,mem_vec_16492 ,mem_vec_16493 ,mem_vec_16494 ,mem_vec_16495 ,mem_vec_16496 ,mem_vec_16497 ,mem_vec_16498 ,mem_vec_16499 ,mem_vec_16500 ,mem_vec_16501 ,mem_vec_16502 ,mem_vec_16503 ,mem_vec_16504 ,mem_vec_16505 ,mem_vec_16506 ,mem_vec_16507 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 17) (34 / 2)
for (x1553 = x1554, x1553_p_0 = 0;
	x1553 < x1554 + 34;
	x1553 += 2, x1553_p_0 += 2){
	// y = 34, x = 2, h = 1, w = 1, c = 512, f = 256
	// T (c, 16) (512 / 32)
	for (c1164 = c1165, c1164_p_0 = 0;
		c1164 < c1165 + 512;
		c1164 += 32, c1164_p_0 += 32){
		// y = 34, x = 2, h = 1, w = 1, c = 32, f = 256
		// T (f, 4) (256 / 64)
		for (f = f776, fp_0 = 0;
			f < f776 + 256;
			f += 64, fp_0 += 64){
				for (y = y776, yp_0 = 0;
					y < y776 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 64
					// T (x, 2) (2 / 1)
					for (x1552 = x1553, x1552_p_1 = x1553_p_0, x1552_p_0 = 0;
						x1552 < x1553 + 2;
						x1552 += 1, x1552_p_1 += 1, x1552_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1552, xp_2 = x1552_p_1, xp_1 = x1552_p_0, xp_0 = 0;
							x < x1552 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16456 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16457 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16458 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_16459 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16460 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16461 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16462 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_16463 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_16464 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16465 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16466 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_16467 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_16468 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16469 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_16471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_16472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_16475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_16476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_16479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1164, cp_1 = c1164_p_0, cp_0 = 0;
										c < c1164 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16456);
										mem_vec_16456 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16457);
										mem_vec_16457 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16458);
										mem_vec_16458 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16459);
										mem_vec_16459 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16460);
										mem_vec_16460 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16461);
										mem_vec_16461 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16462);
										mem_vec_16462 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16463);
										mem_vec_16463 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16464);
										mem_vec_16464 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16465);
										mem_vec_16465 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16466);
										mem_vec_16466 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16467);
										mem_vec_16467 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16468);
										mem_vec_16468 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16469);
										mem_vec_16469 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16470);
										mem_vec_16470 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16471);
										mem_vec_16471 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16472);
										mem_vec_16472 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16473);
										mem_vec_16473 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16474);
										mem_vec_16474 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16475);
										mem_vec_16475 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16476);
										mem_vec_16476 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16477);
										mem_vec_16477 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16478);
										mem_vec_16478 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16479);
										mem_vec_16479 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16456);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16457);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16458);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16459);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16460);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16461);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16462);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16463);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16464);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16465);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16466);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16467);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16468);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16469);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16470);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16471);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16472);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16473);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_16474);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_16475);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16476);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16477);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_16478);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_16479);
						}
					}
				}
				for (y = y776 + 6, yp_0 = 0;
					y < y776 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 64
					// T (x, 2) (2 / 1)
					for (x1552 = x1553, x1552_p_1 = x1553_p_0, x1552_p_0 = 0;
						x1552 < x1553 + 2;
						x1552 += 1, x1552_p_1 += 1, x1552_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1552, xp_2 = x1552_p_1, xp_1 = x1552_p_0, xp_0 = 0;
							x < x1552 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16480 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16481 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16482 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_16483 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_16487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_16488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_16491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_16492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_16495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_16496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_16499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_16500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_16503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_16504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_16505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_16506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_16507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1164, cp_1 = c1164_p_0, cp_0 = 0;
										c < c1164 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16480);
										mem_vec_16480 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16481);
										mem_vec_16481 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16482);
										mem_vec_16482 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16483);
										mem_vec_16483 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16484);
										mem_vec_16484 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16485);
										mem_vec_16485 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16486);
										mem_vec_16486 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16487);
										mem_vec_16487 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16488);
										mem_vec_16488 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16489);
										mem_vec_16489 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16490);
										mem_vec_16490 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16491);
										mem_vec_16491 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16492);
										mem_vec_16492 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16493);
										mem_vec_16493 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16494);
										mem_vec_16494 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16495);
										mem_vec_16495 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16496);
										mem_vec_16496 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16497);
										mem_vec_16497 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16498);
										mem_vec_16498 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16499);
										mem_vec_16499 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16500);
										mem_vec_16500 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16501);
										mem_vec_16501 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16502);
										mem_vec_16502 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16503);
										mem_vec_16503 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_16504);
										mem_vec_16504 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_16505);
										mem_vec_16505 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_16506);
										mem_vec_16506 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_16507);
										mem_vec_16507 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16480);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16481);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16482);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16483);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16484);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16485);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16486);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16487);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16488);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16489);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16490);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16491);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16493);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16495);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_16498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_16499);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16500);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16501);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_16502);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_16503);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_16504);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_16505);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_16506);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_16507);
						}
					}
				}
		}
	}
}


}