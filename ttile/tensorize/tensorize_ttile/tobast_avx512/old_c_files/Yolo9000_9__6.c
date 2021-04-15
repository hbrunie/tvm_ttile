#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (17, x); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (4, f);
  T (256, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1104_p_0, cp_1, c1104, f, fp_0, x, xp_0, x1472_p_0, x1473_p_0, xp_1, x1472_p_1, xp_2, x1472, x1473, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y736 = 0;
IND_TYPE x1474 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1105 = 0;
IND_TYPE f736 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14712 ,mem_vec_14713 ,mem_vec_14714 ,mem_vec_14715 ,mem_vec_14716 ,mem_vec_14717 ,mem_vec_14718 ,mem_vec_14719 ,mem_vec_14720 ,mem_vec_14721 ,mem_vec_14722 ,mem_vec_14723 ,mem_vec_14724 ,mem_vec_14725 ,mem_vec_14726 ,mem_vec_14727 ,mem_vec_14728 ,mem_vec_14729 ,mem_vec_14730 ,mem_vec_14731 ,mem_vec_14732 ,mem_vec_14733 ,mem_vec_14734 ,mem_vec_14735 ,mem_vec_14736 ,mem_vec_14737 ,mem_vec_14738 ,mem_vec_14739 ,mem_vec_14740 ,mem_vec_14741 ,mem_vec_14742 ,mem_vec_14743 ,mem_vec_14744 ,mem_vec_14745 ,mem_vec_14746 ,mem_vec_14747 ,mem_vec_14748 ,mem_vec_14749 ,mem_vec_14750 ,mem_vec_14751 ,mem_vec_14752 ,mem_vec_14753 ,mem_vec_14754 ,mem_vec_14755 ,mem_vec_14756 ,mem_vec_14757 ,mem_vec_14758 ,mem_vec_14759 ,mem_vec_14760 ,mem_vec_14761 ,mem_vec_14762 ,mem_vec_14763 ,mem_vec_14764 ,mem_vec_14765 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 1) (68 / 68)
for (x1473 = x1474, x1473_p_0 = 0;
	x1473 < x1474 + 68;
	x1473 += 68, x1473_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (c, 256) (256 / 1)
	for (c1104 = c1105, c1104_p_0 = 0;
		c1104 < c1105 + 256;
		c1104 += 1, c1104_p_0 += 1){
		// y = 68, x = 68, h = 1, w = 1, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f736, fp_0 = 0;
			f < f736 + 128;
			f += 32, fp_0 += 32){
				for (y = y736, yp_0 = 0;
					y < y736 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 68, h = 1, w = 1, c = 1, f = 32
					// T (x, 4) (68 / 17)
					for (x1472 = x1473, x1472_p_1 = x1473_p_0, x1472_p_0 = 0;
						x1472 < x1473 + 68;
						x1472 += 17, x1472_p_1 += 17, x1472_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
						// T (x, 17) (17 / 1)
						for (x = x1472, xp_2 = x1472_p_1, xp_1 = x1472_p_0, xp_0 = 0;
							x < x1472 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14712 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14713 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_14736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_14737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c1104, cp_1 = c1104_p_0, cp_0 = 0;
										c < c1104 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14712);
										mem_vec_14712 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14713);
										mem_vec_14713 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14714);
										mem_vec_14714 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14715);
										mem_vec_14715 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14716);
										mem_vec_14716 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14717);
										mem_vec_14717 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14718);
										mem_vec_14718 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14719);
										mem_vec_14719 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14720);
										mem_vec_14720 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14721);
										mem_vec_14721 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14722);
										mem_vec_14722 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14723);
										mem_vec_14723 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14724);
										mem_vec_14724 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14725);
										mem_vec_14725 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14726);
										mem_vec_14726 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14727);
										mem_vec_14727 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14728);
										mem_vec_14728 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14729);
										mem_vec_14729 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14730);
										mem_vec_14730 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14731);
										mem_vec_14731 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14732);
										mem_vec_14732 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14733);
										mem_vec_14733 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14734);
										mem_vec_14734 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14735);
										mem_vec_14735 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_14736);
										mem_vec_14736 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_14737);
										mem_vec_14737 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14712);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14713);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14714);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14715);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14716);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14717);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14718);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14719);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14720);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14721);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14722);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14723);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14724);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14725);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14726);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14727);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14735);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_14736);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_14737);
						}
					}
				}
				for (y = y736 + 26, yp_0 = 0;
					y < y736 + 26 + 42;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 68, h = 1, w = 1, c = 1, f = 32
					// T (x, 4) (68 / 17)
					for (x1472 = x1473, x1472_p_1 = x1473_p_0, x1472_p_0 = 0;
						x1472 < x1473 + 68;
						x1472 += 17, x1472_p_1 += 17, x1472_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
						// T (x, 17) (17 / 1)
						for (x = x1472, xp_2 = x1472_p_1, xp_1 = x1472_p_0, xp_0 = 0;
							x < x1472 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14738 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14739 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_14762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_14763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_14764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_14765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c1104, cp_1 = c1104_p_0, cp_0 = 0;
										c < c1104 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14738);
										mem_vec_14738 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14739);
										mem_vec_14739 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14740);
										mem_vec_14740 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14741);
										mem_vec_14741 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14742);
										mem_vec_14742 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14743);
										mem_vec_14743 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14744);
										mem_vec_14744 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14745);
										mem_vec_14745 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14746);
										mem_vec_14746 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14747);
										mem_vec_14747 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14748);
										mem_vec_14748 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14749);
										mem_vec_14749 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14750);
										mem_vec_14750 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14751);
										mem_vec_14751 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14752);
										mem_vec_14752 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14753);
										mem_vec_14753 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14754);
										mem_vec_14754 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14755);
										mem_vec_14755 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14756);
										mem_vec_14756 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14757);
										mem_vec_14757 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14758);
										mem_vec_14758 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14759);
										mem_vec_14759 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14760);
										mem_vec_14760 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14761);
										mem_vec_14761 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_14762);
										mem_vec_14762 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_14763);
										mem_vec_14763 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_14764);
										mem_vec_14764 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_14765);
										mem_vec_14765 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14738);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14739);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14740);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14741);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14742);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14743);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14744);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14745);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14746);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14747);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14748);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14749);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14750);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14751);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14752);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14753);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14754);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14755);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14756);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14757);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14758);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14759);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14760);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14761);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_14762);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_14763);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_14764);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_14765);
						}
					}
				}
		}
	}
}


}