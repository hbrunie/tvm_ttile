#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (34, x); T (2, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (4, f);
  T (128, c); T (1, x)]
*/
IND_TYPE c, cp_0, c714_p_0, cp_1, c714, f, fp_0, x, xp_0, x952_p_0, x953_p_0, xp_1, x952_p_1, xp_2, x952, x953, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y476 = 0;
IND_TYPE x954 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c715 = 0;
IND_TYPE f476 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8640 ,mem_vec_8641 ,mem_vec_8642 ,mem_vec_8643 ,mem_vec_8644 ,mem_vec_8645 ,mem_vec_8646 ,mem_vec_8647 ,mem_vec_8648 ,mem_vec_8649 ,mem_vec_8650 ,mem_vec_8651 ,mem_vec_8652 ,mem_vec_8653 ,mem_vec_8654 ,mem_vec_8655 ,mem_vec_8656 ,mem_vec_8657 ,mem_vec_8658 ,mem_vec_8659 ,mem_vec_8660 ,mem_vec_8661 ,mem_vec_8662 ,mem_vec_8663 ,mem_vec_8664 ,mem_vec_8665 ,mem_vec_8666 ,mem_vec_8667 ,mem_vec_8668 ,mem_vec_8669 ,mem_vec_8670 ,mem_vec_8671 ,mem_vec_8672 ,mem_vec_8673 ,mem_vec_8674 ,mem_vec_8675 ,mem_vec_8676 ,mem_vec_8677 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 1) (68 / 68)
for (x953 = x954, x953_p_0 = 0;
	x953 < x954 + 68;
	x953 += 68, x953_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (c, 128) (256 / 2)
	for (c714 = c715, c714_p_0 = 0;
		c714 < c715 + 256;
		c714 += 2, c714_p_0 += 2){
		// y = 68, x = 68, h = 1, w = 1, c = 2, f = 128
		// T (f, 4) (128 / 32)
		for (f = f476, fp_0 = 0;
			f < f476 + 128;
			f += 32, fp_0 += 32){
				for (y = y476, yp_0 = 0;
					y < y476 + 18;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 68, h = 1, w = 1, c = 2, f = 32
					// T (x, 2) (68 / 34)
					for (x952 = x953, x952_p_1 = x953_p_0, x952_p_0 = 0;
						x952 < x953 + 68;
						x952 += 34, x952_p_1 += 34, x952_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
						// T (x, 34) (34 / 1)
						for (x = x952, xp_2 = x952_p_1, xp_1 = x952_p_0, xp_0 = 0;
							x < x952 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8640 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8641 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_8656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_8657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c714, cp_1 = c714_p_0, cp_0 = 0;
										c < c714 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8640);
										mem_vec_8640 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8641);
										mem_vec_8641 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8642);
										mem_vec_8642 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8643);
										mem_vec_8643 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8644);
										mem_vec_8644 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8645);
										mem_vec_8645 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8646);
										mem_vec_8646 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8647);
										mem_vec_8647 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8648);
										mem_vec_8648 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8649);
										mem_vec_8649 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8650);
										mem_vec_8650 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8651);
										mem_vec_8651 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8652);
										mem_vec_8652 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8653);
										mem_vec_8653 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8654);
										mem_vec_8654 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8655);
										mem_vec_8655 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8656);
										mem_vec_8656 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8657);
										mem_vec_8657 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8640);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8641);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8642);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8643);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8644);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8645);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8646);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8647);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8648);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8649);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8650);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8651);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8652);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8653);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8654);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8655);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8656);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8657);
						}
					}
				}
				for (y = y476 + 18, yp_0 = 0;
					y < y476 + 18 + 50;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 68, h = 1, w = 1, c = 2, f = 32
					// T (x, 2) (68 / 34)
					for (x952 = x953, x952_p_1 = x953_p_0, x952_p_0 = 0;
						x952 < x953 + 68;
						x952 += 34, x952_p_1 += 34, x952_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
						// T (x, 34) (34 / 1)
						for (x = x952, xp_2 = x952_p_1, xp_1 = x952_p_0, xp_0 = 0;
							x < x952 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8658 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8659 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_8674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_8675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_8676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_8677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c714, cp_1 = c714_p_0, cp_0 = 0;
										c < c714 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8658);
										mem_vec_8658 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8659);
										mem_vec_8659 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8660);
										mem_vec_8660 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8661);
										mem_vec_8661 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8662);
										mem_vec_8662 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8663);
										mem_vec_8663 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8664);
										mem_vec_8664 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8665);
										mem_vec_8665 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8666);
										mem_vec_8666 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8667);
										mem_vec_8667 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8668);
										mem_vec_8668 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8669);
										mem_vec_8669 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8670);
										mem_vec_8670 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8671);
										mem_vec_8671 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8672);
										mem_vec_8672 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8673);
										mem_vec_8673 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8674);
										mem_vec_8674 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8675);
										mem_vec_8675 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8676);
										mem_vec_8676 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8677);
										mem_vec_8677 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8658);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8659);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8660);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8661);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8662);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8663);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8664);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8665);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8666);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8667);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8668);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8669);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8670);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8671);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8672);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8673);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8674);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8675);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8676);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8677);
						}
					}
				}
		}
	}
}


}