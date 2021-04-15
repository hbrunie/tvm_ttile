#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (2, x); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (4, f);
  T (128, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1146_p_0, cp_1, c1146, f, fp_0, x, xp_0, x1528_p_0, x1529_p_0, xp_1, x1528_p_1, xp_2, x1528, x1529, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y764 = 0;
IND_TYPE x1530 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1147 = 0;
IND_TYPE f764 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_15468 ,mem_vec_15469 ,mem_vec_15470 ,mem_vec_15471 ,mem_vec_15472 ,mem_vec_15473 ,mem_vec_15474 ,mem_vec_15475 ,mem_vec_15476 ,mem_vec_15477 ,mem_vec_15478 ,mem_vec_15479 ,mem_vec_15480 ,mem_vec_15481 ,mem_vec_15482 ,mem_vec_15483 ,mem_vec_15484 ,mem_vec_15485 ,mem_vec_15486 ,mem_vec_15487 ,mem_vec_15488 ,mem_vec_15489 ,mem_vec_15490 ,mem_vec_15491 ,mem_vec_15492 ,mem_vec_15493 ,mem_vec_15494 ,mem_vec_15495 ,mem_vec_15496 ,mem_vec_15497 ,mem_vec_15498 ,mem_vec_15499 ,mem_vec_15500 ,mem_vec_15501 ,mem_vec_15502 ,mem_vec_15503 ,mem_vec_15504 ,mem_vec_15505 ,mem_vec_15506 ,mem_vec_15507 ,mem_vec_15508 ,mem_vec_15509 ,mem_vec_15510 ,mem_vec_15511 ,mem_vec_15512 ,mem_vec_15513 ,mem_vec_15514 ,mem_vec_15515 ,mem_vec_15516 ,mem_vec_15517 ,mem_vec_15518 ,mem_vec_15519 ,mem_vec_15520 ,mem_vec_15521 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 2) (68 / 34)
for (x1529 = x1530, x1529_p_0 = 0;
	x1529 < x1530 + 68;
	x1529 += 34, x1529_p_0 += 34){
	// y = 68, x = 34, h = 1, w = 1, c = 256, f = 128
	// T (c, 128) (256 / 2)
	for (c1146 = c1147, c1146_p_0 = 0;
		c1146 < c1147 + 256;
		c1146 += 2, c1146_p_0 += 2){
		// y = 68, x = 34, h = 1, w = 1, c = 2, f = 128
		// T (f, 4) (128 / 32)
		for (f = f764, fp_0 = 0;
			f < f764 + 128;
			f += 32, fp_0 += 32){
				for (y = y764, yp_0 = 0;
					y < y764 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
					// T (x, 17) (34 / 2)
					for (x1528 = x1529, x1528_p_1 = x1529_p_0, x1528_p_0 = 0;
						x1528 < x1529 + 34;
						x1528 += 2, x1528_p_1 += 2, x1528_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
						// T (x, 2) (2 / 1)
						for (x = x1528, xp_2 = x1528_p_1, xp_1 = x1528_p_0, xp_0 = 0;
							x < x1528 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15468 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15469 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15470 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15471 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15472 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15473 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15474 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15475 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15476 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15477 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15478 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15479 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15480 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15481 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15482 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_15483 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_15484 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_15485 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_15486 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_15487 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_15488 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_15489 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_15490 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_15491 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_15492 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_15493 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c1146, cp_1 = c1146_p_0, cp_0 = 0;
										c < c1146 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15468);
										mem_vec_15468 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15469);
										mem_vec_15469 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_15470);
										mem_vec_15470 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_15471);
										mem_vec_15471 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_15472);
										mem_vec_15472 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_15473);
										mem_vec_15473 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_15474);
										mem_vec_15474 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_15475);
										mem_vec_15475 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15476);
										mem_vec_15476 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15477);
										mem_vec_15477 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_15478);
										mem_vec_15478 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_15479);
										mem_vec_15479 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_15480);
										mem_vec_15480 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_15481);
										mem_vec_15481 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_15482);
										mem_vec_15482 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_15483);
										mem_vec_15483 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_15484);
										mem_vec_15484 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_15485);
										mem_vec_15485 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15486);
										mem_vec_15486 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15487);
										mem_vec_15487 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_15488);
										mem_vec_15488 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_15489);
										mem_vec_15489 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_15490);
										mem_vec_15490 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_15491);
										mem_vec_15491 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_15492);
										mem_vec_15492 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_15493);
										mem_vec_15493 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15468);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15469);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15470);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15471);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15472);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15473);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15474);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15475);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15476);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15477);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15478);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15479);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15480);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15481);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_15482);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_15483);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_15484);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_15485);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_15486);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_15487);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_15488);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_15489);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_15490);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_15491);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_15492);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_15493);
						}
					}
				}
				for (y = y764 + 26, yp_0 = 0;
					y < y764 + 26 + 42;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
					// T (x, 17) (34 / 2)
					for (x1528 = x1529, x1528_p_1 = x1529_p_0, x1528_p_0 = 0;
						x1528 < x1529 + 34;
						x1528 += 2, x1528_p_1 += 2, x1528_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
						// T (x, 2) (2 / 1)
						for (x = x1528, xp_2 = x1528_p_1, xp_1 = x1528_p_0, xp_0 = 0;
							x < x1528 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15494 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15495 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15506 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_15509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_15510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_15511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_15512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_15513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_15514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_15515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_15516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_15517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_15518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_15519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_15520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_15521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c1146, cp_1 = c1146_p_0, cp_0 = 0;
										c < c1146 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15494);
										mem_vec_15494 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15495);
										mem_vec_15495 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_15496);
										mem_vec_15496 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_15497);
										mem_vec_15497 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_15498);
										mem_vec_15498 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_15499);
										mem_vec_15499 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_15500);
										mem_vec_15500 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_15501);
										mem_vec_15501 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15502);
										mem_vec_15502 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15503);
										mem_vec_15503 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_15504);
										mem_vec_15504 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_15505);
										mem_vec_15505 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_15506);
										mem_vec_15506 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_15507);
										mem_vec_15507 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_15508);
										mem_vec_15508 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_15509);
										mem_vec_15509 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_15510);
										mem_vec_15510 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_15511);
										mem_vec_15511 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15512);
										mem_vec_15512 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15513);
										mem_vec_15513 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_15514);
										mem_vec_15514 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_15515);
										mem_vec_15515 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_15516);
										mem_vec_15516 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_15517);
										mem_vec_15517 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_15518);
										mem_vec_15518 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_15519);
										mem_vec_15519 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_15520);
										mem_vec_15520 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_15521);
										mem_vec_15521 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15494);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15495);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15496);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15497);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15498);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15499);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15500);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15501);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15502);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15503);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15504);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15505);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15506);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15507);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_15508);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_15509);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_15510);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_15511);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_15512);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_15513);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_15514);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_15515);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_15516);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_15517);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_15518);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_15519);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_15520);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_15521);
						}
					}
				}
		}
	}
}


}