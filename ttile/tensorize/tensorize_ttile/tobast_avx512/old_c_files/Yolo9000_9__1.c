#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (17, x); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]; T (4, f);
  T (256, c); T (1, x)]
*/
IND_TYPE c, cp_0, c990_p_0, cp_1, c990, f, fp_0, x, xp_0, x1320_p_0, x1321_p_0, xp_1, x1320_p_1, xp_2, x1320, x1321, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y660 = 0;
IND_TYPE x1322 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c991 = 0;
IND_TYPE f660 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_12728 ,mem_vec_12729 ,mem_vec_12730 ,mem_vec_12731 ,mem_vec_12732 ,mem_vec_12733 ,mem_vec_12734 ,mem_vec_12735 ,mem_vec_12736 ,mem_vec_12737 ,mem_vec_12738 ,mem_vec_12739 ,mem_vec_12740 ,mem_vec_12741 ,mem_vec_12742 ,mem_vec_12743 ,mem_vec_12744 ,mem_vec_12745 ,mem_vec_12746 ,mem_vec_12747 ,mem_vec_12748 ,mem_vec_12749 ,mem_vec_12750 ,mem_vec_12751 ,mem_vec_12752 ,mem_vec_12753 ,mem_vec_12754 ,mem_vec_12755 ,mem_vec_12756 ,mem_vec_12757 ,mem_vec_12758 ,mem_vec_12759 ,mem_vec_12760 ,mem_vec_12761 ,mem_vec_12762 ,mem_vec_12763 ,mem_vec_12764 ,mem_vec_12765 ,mem_vec_12766 ,mem_vec_12767 ,mem_vec_12768 ,mem_vec_12769 ,mem_vec_12770 ,mem_vec_12771 ,mem_vec_12772 ,mem_vec_12773 ,mem_vec_12774 ,mem_vec_12775 ,mem_vec_12776 ,mem_vec_12777 ,mem_vec_12778 ,mem_vec_12779 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 1) (68 / 68)
for (x1321 = x1322, x1321_p_0 = 0;
	x1321 < x1322 + 68;
	x1321 += 68, x1321_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (c, 256) (256 / 1)
	for (c990 = c991, c990_p_0 = 0;
		c990 < c991 + 256;
		c990 += 1, c990_p_0 += 1){
		// y = 68, x = 68, h = 1, w = 1, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f660, fp_0 = 0;
			f < f660 + 128;
			f += 32, fp_0 += 32){
				for (y = y660, yp_0 = 0;
					y < y660 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 68, h = 1, w = 1, c = 1, f = 32
					// T (x, 4) (68 / 17)
					for (x1320 = x1321, x1320_p_1 = x1321_p_0, x1320_p_0 = 0;
						x1320 < x1321 + 68;
						x1320 += 17, x1320_p_1 += 17, x1320_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
						// T (x, 17) (17 / 1)
						for (x = x1320, xp_2 = x1320_p_1, xp_1 = x1320_p_0, xp_0 = 0;
							x < x1320 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_12728 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_12729 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_12730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_12731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_12732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_12733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_12734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_12735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_12736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_12737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_12738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_12739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_12740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_12741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_12742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_12743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_12744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_12745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_12746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_12747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_12748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_12749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_12750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_12751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c990, cp_1 = c990_p_0, cp_0 = 0;
										c < c990 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12728);
										mem_vec_12728 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12729);
										mem_vec_12729 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12730);
										mem_vec_12730 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12731);
										mem_vec_12731 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12732);
										mem_vec_12732 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12733);
										mem_vec_12733 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12734);
										mem_vec_12734 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12735);
										mem_vec_12735 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12736);
										mem_vec_12736 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12737);
										mem_vec_12737 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12738);
										mem_vec_12738 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12739);
										mem_vec_12739 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12740);
										mem_vec_12740 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12741);
										mem_vec_12741 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12742);
										mem_vec_12742 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12743);
										mem_vec_12743 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12744);
										mem_vec_12744 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12745);
										mem_vec_12745 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12746);
										mem_vec_12746 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12747);
										mem_vec_12747 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12748);
										mem_vec_12748 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12749);
										mem_vec_12749 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12750);
										mem_vec_12750 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12751);
										mem_vec_12751 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12728);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12729);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12730);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12731);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12732);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12733);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12734);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12735);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12736);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12737);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12738);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12739);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12740);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12741);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_12742);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_12743);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_12744);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_12745);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_12746);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_12747);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_12748);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_12749);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_12750);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_12751);
						}
					}
				}
				for (y = y660 + 12, yp_0 = 0;
					y < y660 + 12 + 56;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 68, h = 1, w = 1, c = 1, f = 32
					// T (x, 4) (68 / 17)
					for (x1320 = x1321, x1320_p_1 = x1321_p_0, x1320_p_0 = 0;
						x1320 < x1321 + 68;
						x1320 += 17, x1320_p_1 += 17, x1320_p_0 += 17){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1, f = 32
						// T (x, 17) (17 / 1)
						for (x = x1320, xp_2 = x1320_p_1, xp_1 = x1320_p_0, xp_0 = 0;
							x < x1320 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_12752 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_12753 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_12754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_12755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_12756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_12757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_12758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_12759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_12760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_12761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_12762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_12763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_12764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_12765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_12766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_12767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_12768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_12769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_12770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_12771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_12772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_12773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_12774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_12775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_12776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_12777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_12778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_12779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c990, cp_1 = c990_p_0, cp_0 = 0;
										c < c990 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_12752);
										mem_vec_12752 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_12753);
										mem_vec_12753 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_12754);
										mem_vec_12754 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_12755);
										mem_vec_12755 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_12756);
										mem_vec_12756 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_12757);
										mem_vec_12757 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_12758);
										mem_vec_12758 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_12759);
										mem_vec_12759 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_12760);
										mem_vec_12760 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_12761);
										mem_vec_12761 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_12762);
										mem_vec_12762 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_12763);
										mem_vec_12763 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_12764);
										mem_vec_12764 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_12765);
										mem_vec_12765 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_12766);
										mem_vec_12766 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_12767);
										mem_vec_12767 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_12768);
										mem_vec_12768 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_12769);
										mem_vec_12769 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_12770);
										mem_vec_12770 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_12771);
										mem_vec_12771 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_12772);
										mem_vec_12772 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_12773);
										mem_vec_12773 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_12774);
										mem_vec_12774 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_12775);
										mem_vec_12775 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_12776);
										mem_vec_12776 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_12777);
										mem_vec_12777 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_12778);
										mem_vec_12778 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_12779);
										mem_vec_12779 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12752);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12753);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12754);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12755);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12756);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12757);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12758);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12759);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12760);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12761);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12762);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12763);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12764);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12765);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_12766);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_12767);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_12768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_12769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_12770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_12771);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_12772);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_12773);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_12774);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_12775);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_12776);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_12777);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_12778);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_12779);
						}
					}
				}
		}
	}
}


}