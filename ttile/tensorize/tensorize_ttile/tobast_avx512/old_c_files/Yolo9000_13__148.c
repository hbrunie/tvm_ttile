#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (17, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (64, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1062_p_0, cp_1, c1062, f, fp_0, x, xp_0, x1416_p_0, x1417_p_0, xp_1, x1416_p_1, xp_2, x1416, x1417, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y708 = 0;
IND_TYPE x1418 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1063 = 0;
IND_TYPE f708 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_14688 ,mem_vec_14689 ,mem_vec_14690 ,mem_vec_14691 ,mem_vec_14692 ,mem_vec_14693 ,mem_vec_14694 ,mem_vec_14695 ,mem_vec_14696 ,mem_vec_14697 ,mem_vec_14698 ,mem_vec_14699 ,mem_vec_14700 ,mem_vec_14701 ,mem_vec_14702 ,mem_vec_14703 ,mem_vec_14704 ,mem_vec_14705 ,mem_vec_14706 ,mem_vec_14707 ,mem_vec_14708 ,mem_vec_14709 ,mem_vec_14710 ,mem_vec_14711 ,mem_vec_14712 ,mem_vec_14713 ,mem_vec_14714 ,mem_vec_14715 ,mem_vec_14716 ,mem_vec_14717 ,mem_vec_14718 ,mem_vec_14719 ,mem_vec_14720 ,mem_vec_14721 ,mem_vec_14722 ,mem_vec_14723 ,mem_vec_14724 ,mem_vec_14725 ,mem_vec_14726 ,mem_vec_14727 ,mem_vec_14728 ,mem_vec_14729 ,mem_vec_14730 ,mem_vec_14731 ,mem_vec_14732 ,mem_vec_14733 ,mem_vec_14734 ,mem_vec_14735 ,mem_vec_14736 ,mem_vec_14737 ,mem_vec_14738 ,mem_vec_14739 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x1417 = x1418, x1417_p_0 = 0;
	x1417 < x1418 + 34;
	x1417 += 34, x1417_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 64) (512 / 8)
	for (c1062 = c1063, c1062_p_0 = 0;
		c1062 < c1063 + 512;
		c1062 += 8, c1062_p_0 += 8){
		// y = 34, x = 34, h = 1, w = 1, c = 8, f = 256
		// T (f, 4) (256 / 64)
		for (f = f708, fp_0 = 0;
			f < f708 + 256;
			f += 64, fp_0 += 64){
				for (y = y708, yp_0 = 0;
					y < y708 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 64
					// T (x, 2) (34 / 17)
					for (x1416 = x1417, x1416_p_1 = x1417_p_0, x1416_p_0 = 0;
						x1416 < x1417 + 34;
						x1416 += 17, x1416_p_1 += 17, x1416_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
						// T (x, 17) (17 / 1)
						for (x = x1416, xp_2 = x1416_p_1, xp_1 = x1416_p_0, xp_0 = 0;
							x < x1416 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14688 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14689 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14690 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14691 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1062, cp_1 = c1062_p_0, cp_0 = 0;
										c < c1062 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14688);
										mem_vec_14688 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14689);
										mem_vec_14689 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14690);
										mem_vec_14690 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14691);
										mem_vec_14691 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14692);
										mem_vec_14692 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14693);
										mem_vec_14693 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14694);
										mem_vec_14694 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14695);
										mem_vec_14695 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14696);
										mem_vec_14696 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14697);
										mem_vec_14697 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14698);
										mem_vec_14698 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14699);
										mem_vec_14699 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14700);
										mem_vec_14700 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14701);
										mem_vec_14701 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14702);
										mem_vec_14702 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14703);
										mem_vec_14703 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14704);
										mem_vec_14704 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14705);
										mem_vec_14705 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14706);
										mem_vec_14706 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14707);
										mem_vec_14707 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14708);
										mem_vec_14708 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14709);
										mem_vec_14709 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14710);
										mem_vec_14710 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14711);
										mem_vec_14711 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14688);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14689);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14690);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14691);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14692);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14693);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14694);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14695);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14696);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14697);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14698);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14699);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14700);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14701);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14702);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14703);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14704);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14705);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14706);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14707);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14708);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14709);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14710);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14711);
						}
					}
				}
				for (y = y708 + 6, yp_0 = 0;
					y < y708 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 64
					// T (x, 2) (34 / 17)
					for (x1416 = x1417, x1416_p_1 = x1417_p_0, x1416_p_0 = 0;
						x1416 < x1417 + 34;
						x1416 += 17, x1416_p_1 += 17, x1416_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 8, f = 64
						// T (x, 17) (17 / 1)
						for (x = x1416, xp_2 = x1416_p_1, xp_1 = x1416_p_0, xp_0 = 0;
							x < x1416 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14712 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14713 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14714 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14715 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_14736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_14739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1062, cp_1 = c1062_p_0, cp_0 = 0;
										c < c1062 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14712);
										mem_vec_14712 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14713);
										mem_vec_14713 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14714);
										mem_vec_14714 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14715);
										mem_vec_14715 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14716);
										mem_vec_14716 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14717);
										mem_vec_14717 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14718);
										mem_vec_14718 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14719);
										mem_vec_14719 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14720);
										mem_vec_14720 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14721);
										mem_vec_14721 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14722);
										mem_vec_14722 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14723);
										mem_vec_14723 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14724);
										mem_vec_14724 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14725);
										mem_vec_14725 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14726);
										mem_vec_14726 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14727);
										mem_vec_14727 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14728);
										mem_vec_14728 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14729);
										mem_vec_14729 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14730);
										mem_vec_14730 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14731);
										mem_vec_14731 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14732);
										mem_vec_14732 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14733);
										mem_vec_14733 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14734);
										mem_vec_14734 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14735);
										mem_vec_14735 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14736);
										mem_vec_14736 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14737);
										mem_vec_14737 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14738);
										mem_vec_14738 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14739);
										mem_vec_14739 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14712);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14713);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14714);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14715);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14716);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14717);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14718);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14719);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14720);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14721);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14722);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14723);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14724);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14725);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14726);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14727);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14735);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14736);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14737);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14738);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14739);
						}
					}
				}
		}
	}
}


}