#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 3)); ((Iter 2), (Arg 7))]; T (8, c)]
*/
IND_TYPE c, cp_0, c936_p_0, c937_p_0, cp_1, c936_p_1, cp_2, c936, c937, f, fp_0, x, xp_0, x702_p_0, xp_1, x702, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y468 = 0;
IND_TYPE x703 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c938 = 0;
IND_TYPE f468 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_7592 ,mem_vec_7593 ,mem_vec_7594 ,mem_vec_7595 ,mem_vec_7596 ,mem_vec_7597 ,mem_vec_7598 ,mem_vec_7599 ,mem_vec_7600 ,mem_vec_7601 ,mem_vec_7602 ,mem_vec_7603 ,mem_vec_7604 ,mem_vec_7605 ,mem_vec_7606 ,mem_vec_7607 ,mem_vec_7608 ,mem_vec_7609 ,mem_vec_7610 ,mem_vec_7611 ,mem_vec_7612 ,mem_vec_7613 ,mem_vec_7614 ,mem_vec_7615 ,mem_vec_7616 ,mem_vec_7617 ,mem_vec_7618 ,mem_vec_7619 ,mem_vec_7620 ,mem_vec_7621 ,mem_vec_7622 ,mem_vec_7623 ,mem_vec_7624 ,mem_vec_7625 ,mem_vec_7626 ,mem_vec_7627 ,mem_vec_7628 ,mem_vec_7629 ,mem_vec_7630 ,mem_vec_7631 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 8) (1024 / 128)
for (c937 = c938, c937_p_0 = 0;
	c937 < c938 + 1024;
	c937 += 128, c937_p_0 += 128){
		for (y = y468, yp_0 = 0;
			y < y468 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 1) (17 / 17)
			for (x702 = x703, x702_p_0 = 0;
				x702 < x703 + 17;
				x702 += 17, x702_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f468, fp_0 = 0;
					f < f468 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 8) (128 / 16)
					for (c936 = c937, c936_p_1 = c937_p_0, c936_p_0 = 0;
						c936 < c937 + 128;
						c936 += 16, c936_p_1 += 16, c936_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x702, xp_1 = x702_p_0, xp_0 = 0;
							x < x702 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7592 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7593 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7594 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7595 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7596 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7597 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7598 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7599 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7600 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7601 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7602 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7603 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c936, cp_2 = c936_p_1, cp_1 = c936_p_0, cp_0 = 0;
										c < c936 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7592);
										mem_vec_7592 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7593);
										mem_vec_7593 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7594);
										mem_vec_7594 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7595);
										mem_vec_7595 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7596);
										mem_vec_7596 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7597);
										mem_vec_7597 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7598);
										mem_vec_7598 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7599);
										mem_vec_7599 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7600);
										mem_vec_7600 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7601);
										mem_vec_7601 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7602);
										mem_vec_7602 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7603);
										mem_vec_7603 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7592);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7593);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7594);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7595);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7596);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7597);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7598);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7599);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7600);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7601);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7602);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7603);
						}
					}
				}
			}
		}
		for (y = y468 + 3, yp_0 = 0;
			y < y468 + 3 + 14;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
			// T (x, 1) (17 / 17)
			for (x702 = x703, x702_p_0 = 0;
				x702 < x703 + 17;
				x702 += 17, x702_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 512
				// T (f, 8) (512 / 64)
				for (f = f468, fp_0 = 0;
					f < f468 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 64
					// T (c, 8) (128 / 16)
					for (c936 = c937, c936_p_1 = c937_p_0, c936_p_0 = 0;
						c936 < c937 + 128;
						c936 += 16, c936_p_1 += 16, c936_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x702, xp_1 = x702_p_0, xp_0 = 0;
							x < x702 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_7604 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_7605 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_7606 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_7607 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_7608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_7609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_7610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_7611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_7612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_7613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_7614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_7615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_7616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_7617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_7618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_7619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_7620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_7621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_7622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_7623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_7624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_7625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_7626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_7627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_7628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_7629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_7630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_7631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c936, cp_2 = c936_p_1, cp_1 = c936_p_0, cp_0 = 0;
										c < c936 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7604);
										mem_vec_7604 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7605);
										mem_vec_7605 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_7606);
										mem_vec_7606 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_7607);
										mem_vec_7607 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_7608);
										mem_vec_7608 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_7609);
										mem_vec_7609 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_7610);
										mem_vec_7610 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_7611);
										mem_vec_7611 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7612);
										mem_vec_7612 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7613);
										mem_vec_7613 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_7614);
										mem_vec_7614 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_7615);
										mem_vec_7615 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_7616);
										mem_vec_7616 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_7617);
										mem_vec_7617 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_7618);
										mem_vec_7618 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_7619);
										mem_vec_7619 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_7620);
										mem_vec_7620 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_7621);
										mem_vec_7621 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_7622);
										mem_vec_7622 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_7623);
										mem_vec_7623 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7624);
										mem_vec_7624 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7625);
										mem_vec_7625 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_7626);
										mem_vec_7626 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_7627);
										mem_vec_7627 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_7628);
										mem_vec_7628 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_7629);
										mem_vec_7629 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_7630);
										mem_vec_7630 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_7631);
										mem_vec_7631 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7604);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7605);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_7606);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_7607);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7608);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7609);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_7610);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_7611);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7612);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7613);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_7614);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_7615);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7616);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7617);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_7618);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_7619);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7620);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7621);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_7622);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_7623);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7624);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7625);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_7626);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_7627);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7628);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7629);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_7630);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_7631);
						}
					}
				}
			}
		}
}


}