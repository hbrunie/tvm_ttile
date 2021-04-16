#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, c);
  T (68, x); T (4, y)]
*/
IND_TYPE c, cp_0, c296_p_0, cp_1, c296, x, xp_0, x396_p_0, xp_1, x396, y, yp_0, y396_p_0, yp_1, y396;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y397 = 0;
IND_TYPE x397 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c297 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_5490 ,mem_vec_5491 ,mem_vec_5492 ,mem_vec_5493 ,mem_vec_5494 ,mem_vec_5495 ,mem_vec_5496 ,mem_vec_5497 ,mem_vec_5498 ,mem_vec_5499 ,mem_vec_5500 ,mem_vec_5501 ,mem_vec_5502 ,mem_vec_5503 ,mem_vec_5504 ,mem_vec_5505 ,mem_vec_5506 ,mem_vec_5507 ,mem_vec_5508 ,mem_vec_5509 ,mem_vec_5510 ,mem_vec_5511 ,mem_vec_5512 ,mem_vec_5513 ,mem_vec_5514 ,mem_vec_5515 ,mem_vec_5516 ,mem_vec_5517 ,mem_vec_5518 ,mem_vec_5519 ,mem_vec_5520 ,mem_vec_5521 ,mem_vec_5522 ,mem_vec_5523 ,mem_vec_5524 ,mem_vec_5525 ,mem_vec_5526 ,mem_vec_5527 ,mem_vec_5528 ,mem_vec_5529 ,mem_vec_5530 ,mem_vec_5531 ,mem_vec_5532 ,mem_vec_5533 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y396 = y397, y396_p_0 = 0;
	y396 < y397 + 136;
	y396 += 34, y396_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x396 = x397, x396_p_0 = 0;
		x396 < x397 + 136;
		x396 += 2, x396_p_0 += 2){
		// y = 34, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (c, 1) (128 / 128)
		for (c296 = c297, c296_p_0 = 0;
			c296 < c297 + 128;
			c296 += 128, c296_p_0 += 128){
				for (y = y396, yp_1 = y396_p_0, yp_0 = 0;
					y < y396 + 20;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x396, xp_1 = x396_p_0, xp_0 = 0;
						x < x396 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_5490 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5491 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5492 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_5493 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_5494 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5495 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5496 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_5497 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_5498 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5499 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5500 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_5501 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_5502 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5503 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5504 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_5505 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c296, cp_1 = c296_p_0, cp_0 = 0;
									c < c296 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5490);
									mem_vec_5490 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5491);
									mem_vec_5491 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5492);
									mem_vec_5492 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5493);
									mem_vec_5493 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5494);
									mem_vec_5494 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5495);
									mem_vec_5495 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5496);
									mem_vec_5496 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5497);
									mem_vec_5497 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5498);
									mem_vec_5498 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5499);
									mem_vec_5499 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5500);
									mem_vec_5500 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5501);
									mem_vec_5501 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5502);
									mem_vec_5502 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5503);
									mem_vec_5503 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5504);
									mem_vec_5504 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5505);
									mem_vec_5505 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5490);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5491);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5492);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5493);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5494);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5495);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5496);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5497);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5498);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5499);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5500);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5501);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5502);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5503);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5504);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5505);
					}
				}
				for (y = y396 + 20, yp_1 = y396_p_0, yp_0 = 0;
					y < y396 + 20 + 14;
					y += 7, yp_1 += 7, yp_0 += 7){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x396, xp_1 = x396_p_0, xp_0 = 0;
						x < x396 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_5506 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_5507 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_5508 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_5509 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_5510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_5511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_5512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_5513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_5514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_5515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_5516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_5517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_5518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_5519 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_5520 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_5521 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_5522 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_5523 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_5524 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_5525 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_5526 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_5527 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_5528 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_5529 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_5530 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_5531 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_5532 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_5533 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c296, cp_1 = c296_p_0, cp_0 = 0;
									c < c296 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5506);
									mem_vec_5506 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5507);
									mem_vec_5507 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_5508);
									mem_vec_5508 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_5509);
									mem_vec_5509 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_5510);
									mem_vec_5510 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_5511);
									mem_vec_5511 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_5512);
									mem_vec_5512 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_5513);
									mem_vec_5513 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5514);
									mem_vec_5514 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5515);
									mem_vec_5515 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_5516);
									mem_vec_5516 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_5517);
									mem_vec_5517 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_5518);
									mem_vec_5518 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_5519);
									mem_vec_5519 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_5520);
									mem_vec_5520 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_5521);
									mem_vec_5521 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_5522);
									mem_vec_5522 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_5523);
									mem_vec_5523 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_5524);
									mem_vec_5524 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_5525);
									mem_vec_5525 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5526);
									mem_vec_5526 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5527);
									mem_vec_5527 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_5528);
									mem_vec_5528 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_5529);
									mem_vec_5529 = vec_33;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_5530);
									mem_vec_5530 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_5531);
									mem_vec_5531 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_5532);
									mem_vec_5532 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_5533);
									mem_vec_5533 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5506);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5507);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_5508);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_5509);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5510);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5511);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_5512);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_5513);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5514);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5515);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_5516);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_5517);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5518);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5519);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_5520);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_5521);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5522);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5523);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_5524);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_5525);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5526);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5527);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_5528);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_5529);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5530);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5531);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_5532);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_5533);
					}
				}
		}
	}
}


}