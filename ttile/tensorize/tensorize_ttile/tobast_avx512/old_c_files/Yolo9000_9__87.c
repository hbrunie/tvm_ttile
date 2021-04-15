#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (68, x); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (4, f);
  T (64, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1098_p_0, cp_1, c1098, f, fp_0, x, xp_0, x1464_p_0, x1465_p_0, xp_1, x1464_p_1, xp_2, x1464, x1465, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y732 = 0;
IND_TYPE x1466 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1099 = 0;
IND_TYPE f732 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14604 ,mem_vec_14605 ,mem_vec_14606 ,mem_vec_14607 ,mem_vec_14608 ,mem_vec_14609 ,mem_vec_14610 ,mem_vec_14611 ,mem_vec_14612 ,mem_vec_14613 ,mem_vec_14614 ,mem_vec_14615 ,mem_vec_14616 ,mem_vec_14617 ,mem_vec_14618 ,mem_vec_14619 ,mem_vec_14620 ,mem_vec_14621 ,mem_vec_14622 ,mem_vec_14623 ,mem_vec_14624 ,mem_vec_14625 ,mem_vec_14626 ,mem_vec_14627 ,mem_vec_14628 ,mem_vec_14629 ,mem_vec_14630 ,mem_vec_14631 ,mem_vec_14632 ,mem_vec_14633 ,mem_vec_14634 ,mem_vec_14635 ,mem_vec_14636 ,mem_vec_14637 ,mem_vec_14638 ,mem_vec_14639 ,mem_vec_14640 ,mem_vec_14641 ,mem_vec_14642 ,mem_vec_14643 ,mem_vec_14644 ,mem_vec_14645 ,mem_vec_14646 ,mem_vec_14647 ,mem_vec_14648 ,mem_vec_14649 ,mem_vec_14650 ,mem_vec_14651 ,mem_vec_14652 ,mem_vec_14653 ,mem_vec_14654 ,mem_vec_14655 ,mem_vec_14656 ,mem_vec_14657 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 1) (68 / 68)
for (x1465 = x1466, x1465_p_0 = 0;
	x1465 < x1466 + 68;
	x1465 += 68, x1465_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (c, 64) (256 / 4)
	for (c1098 = c1099, c1098_p_0 = 0;
		c1098 < c1099 + 256;
		c1098 += 4, c1098_p_0 += 4){
		// y = 68, x = 68, h = 1, w = 1, c = 4, f = 128
		// T (f, 4) (128 / 32)
		for (f = f732, fp_0 = 0;
			f < f732 + 128;
			f += 32, fp_0 += 32){
				for (y = y732, yp_0 = 0;
					y < y732 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 68, h = 1, w = 1, c = 4, f = 32
					// T (x, 1) (68 / 68)
					for (x1464 = x1465, x1464_p_1 = x1465_p_0, x1464_p_0 = 0;
						x1464 < x1465 + 68;
						x1464 += 68, x1464_p_1 += 68, x1464_p_0 += 68){
						// y = ph_y, x = 68, h = 1, w = 1, c = 4, f = 32
						// T (x, 68) (68 / 1)
						for (x = x1464, xp_2 = x1464_p_1, xp_1 = x1464_p_0, xp_0 = 0;
							x < x1464 + 68;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14604 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14605 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_14628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_14629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
										c < c1098 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14604);
										mem_vec_14604 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14605);
										mem_vec_14605 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14606);
										mem_vec_14606 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14607);
										mem_vec_14607 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14608);
										mem_vec_14608 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14609);
										mem_vec_14609 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14610);
										mem_vec_14610 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14611);
										mem_vec_14611 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14612);
										mem_vec_14612 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14613);
										mem_vec_14613 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14614);
										mem_vec_14614 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14615);
										mem_vec_14615 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14616);
										mem_vec_14616 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14617);
										mem_vec_14617 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14618);
										mem_vec_14618 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14619);
										mem_vec_14619 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14620);
										mem_vec_14620 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14621);
										mem_vec_14621 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14622);
										mem_vec_14622 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14623);
										mem_vec_14623 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14624);
										mem_vec_14624 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14625);
										mem_vec_14625 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14626);
										mem_vec_14626 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14627);
										mem_vec_14627 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_14628);
										mem_vec_14628 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_14629);
										mem_vec_14629 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14604);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14605);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14606);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14607);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14608);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14609);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14610);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14611);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14612);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14613);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14614);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14615);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14616);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14617);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14618);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14619);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14620);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14621);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14622);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14623);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_14628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_14629);
						}
					}
				}
				for (y = y732 + 26, yp_0 = 0;
					y < y732 + 26 + 42;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 68, h = 1, w = 1, c = 4, f = 32
					// T (x, 1) (68 / 68)
					for (x1464 = x1465, x1464_p_1 = x1465_p_0, x1464_p_0 = 0;
						x1464 < x1465 + 68;
						x1464 += 68, x1464_p_1 += 68, x1464_p_0 += 68){
						// y = ph_y, x = 68, h = 1, w = 1, c = 4, f = 32
						// T (x, 68) (68 / 1)
						for (x = x1464, xp_2 = x1464_p_1, xp_1 = x1464_p_0, xp_0 = 0;
							x < x1464 + 68;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14630 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14631 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_14654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_14655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_14656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_14657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c1098, cp_1 = c1098_p_0, cp_0 = 0;
										c < c1098 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14630);
										mem_vec_14630 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14631);
										mem_vec_14631 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14632);
										mem_vec_14632 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14633);
										mem_vec_14633 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14634);
										mem_vec_14634 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14635);
										mem_vec_14635 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14636);
										mem_vec_14636 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14637);
										mem_vec_14637 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14638);
										mem_vec_14638 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14639);
										mem_vec_14639 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14640);
										mem_vec_14640 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14641);
										mem_vec_14641 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14642);
										mem_vec_14642 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14643);
										mem_vec_14643 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14644);
										mem_vec_14644 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14645);
										mem_vec_14645 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14646);
										mem_vec_14646 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14647);
										mem_vec_14647 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14648);
										mem_vec_14648 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14649);
										mem_vec_14649 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14650);
										mem_vec_14650 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14651);
										mem_vec_14651 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14652);
										mem_vec_14652 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14653);
										mem_vec_14653 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_14654);
										mem_vec_14654 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_14655);
										mem_vec_14655 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_14656);
										mem_vec_14656 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_14657);
										mem_vec_14657 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14631);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14632);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14633);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14634);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14635);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14636);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14637);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14638);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14639);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14640);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14641);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14642);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14643);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14644);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14645);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14646);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14647);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14648);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14649);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14650);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14651);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14652);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14653);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_14654);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_14655);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_14656);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_14657);
						}
					}
				}
		}
	}
}


}