#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (16, c); T (34, x)]
*/
IND_TYPE c, cp_0, c1182_p_0, cp_1, c1182, f, fp_0, x, xp_0, x1576_p_0, x1577_p_0, xp_1, x1576_p_1, xp_2, x1576, x1577, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y788 = 0;
IND_TYPE x1578 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1183 = 0;
IND_TYPE f788 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_16768 ,mem_vec_16769 ,mem_vec_16770 ,mem_vec_16771 ,mem_vec_16772 ,mem_vec_16773 ,mem_vec_16774 ,mem_vec_16775 ,mem_vec_16776 ,mem_vec_16777 ,mem_vec_16778 ,mem_vec_16779 ,mem_vec_16780 ,mem_vec_16781 ,mem_vec_16782 ,mem_vec_16783 ,mem_vec_16784 ,mem_vec_16785 ,mem_vec_16786 ,mem_vec_16787 ,mem_vec_16788 ,mem_vec_16789 ,mem_vec_16790 ,mem_vec_16791 ,mem_vec_16792 ,mem_vec_16793 ,mem_vec_16794 ,mem_vec_16795 ,mem_vec_16796 ,mem_vec_16797 ,mem_vec_16798 ,mem_vec_16799 ,mem_vec_16800 ,mem_vec_16801 ,mem_vec_16802 ,mem_vec_16803 ,mem_vec_16804 ,mem_vec_16805 ,mem_vec_16806 ,mem_vec_16807 ,mem_vec_16808 ,mem_vec_16809 ,mem_vec_16810 ,mem_vec_16811 ,mem_vec_16812 ,mem_vec_16813 ,mem_vec_16814 ,mem_vec_16815 ,mem_vec_16816 ,mem_vec_16817 ,mem_vec_16818 ,mem_vec_16819 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 34) (34 / 1)
for (x1577 = x1578, x1577_p_0 = 0;
	x1577 < x1578 + 34;
	x1577 += 1, x1577_p_0 += 1){
	// y = 34, x = 1, h = 1, w = 1, c = 512, f = 256
	// T (c, 16) (512 / 32)
	for (c1182 = c1183, c1182_p_0 = 0;
		c1182 < c1183 + 512;
		c1182 += 32, c1182_p_0 += 32){
		// y = 34, x = 1, h = 1, w = 1, c = 32, f = 256
		// T (f, 4) (256 / 64)
		for (f = f788, fp_0 = 0;
			f < f788 + 256;
			f += 64, fp_0 += 64){
				for (y = y788, yp_0 = 0;
					y < y788 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
					// T (x, 1) (1 / 1)
					for (x1576 = x1577, x1576_p_1 = x1577_p_0, x1576_p_0 = 0;
						x1576 < x1577 + 1;
						x1576 += 1, x1576_p_1 += 1, x1576_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1576, xp_2 = x1576_p_1, xp_1 = x1576_p_0, xp_0 = 0;
							x < x1576 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16768 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16769 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16770 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_16771 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_16775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_16776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_16779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_16780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_16783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_16784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_16787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_16788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_16791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1182, cp_1 = c1182_p_0, cp_0 = 0;
										c < c1182 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16768);
										mem_vec_16768 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16769);
										mem_vec_16769 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16770);
										mem_vec_16770 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16771);
										mem_vec_16771 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16772);
										mem_vec_16772 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16773);
										mem_vec_16773 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16774);
										mem_vec_16774 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16775);
										mem_vec_16775 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16776);
										mem_vec_16776 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16777);
										mem_vec_16777 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16778);
										mem_vec_16778 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16779);
										mem_vec_16779 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16780);
										mem_vec_16780 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16781);
										mem_vec_16781 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16782);
										mem_vec_16782 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16783);
										mem_vec_16783 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16784);
										mem_vec_16784 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16785);
										mem_vec_16785 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16786);
										mem_vec_16786 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16787);
										mem_vec_16787 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16788);
										mem_vec_16788 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16789);
										mem_vec_16789 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16790);
										mem_vec_16790 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16791);
										mem_vec_16791 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16768);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16769);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16770);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16771);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16772);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16773);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16774);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16775);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16776);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16777);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16778);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16779);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16780);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16781);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16782);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16783);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16784);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16785);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_16786);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_16787);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16788);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16789);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_16790);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_16791);
						}
					}
				}
				for (y = y788 + 6, yp_0 = 0;
					y < y788 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
					// T (x, 1) (1 / 1)
					for (x1576 = x1577, x1576_p_1 = x1577_p_0, x1576_p_0 = 0;
						x1576 < x1577 + 1;
						x1576 += 1, x1576_p_1 += 1, x1576_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1576, xp_2 = x1576_p_1, xp_1 = x1576_p_0, xp_0 = 0;
							x < x1576 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_16792 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_16793 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_16794 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_16795 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_16796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_16797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_16798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_16799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_16800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_16801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_16802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_16803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_16804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_16805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_16806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_16807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_16808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_16809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_16810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_16811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_16812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_16813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_16814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_16815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_16816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_16817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_16818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_16819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1182, cp_1 = c1182_p_0, cp_0 = 0;
										c < c1182 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_16792);
										mem_vec_16792 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_16793);
										mem_vec_16793 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_16794);
										mem_vec_16794 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_16795);
										mem_vec_16795 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_16796);
										mem_vec_16796 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_16797);
										mem_vec_16797 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_16798);
										mem_vec_16798 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_16799);
										mem_vec_16799 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_16800);
										mem_vec_16800 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_16801);
										mem_vec_16801 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_16802);
										mem_vec_16802 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_16803);
										mem_vec_16803 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_16804);
										mem_vec_16804 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_16805);
										mem_vec_16805 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_16806);
										mem_vec_16806 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_16807);
										mem_vec_16807 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_16808);
										mem_vec_16808 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_16809);
										mem_vec_16809 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_16810);
										mem_vec_16810 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_16811);
										mem_vec_16811 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_16812);
										mem_vec_16812 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_16813);
										mem_vec_16813 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_16814);
										mem_vec_16814 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_16815);
										mem_vec_16815 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_16816);
										mem_vec_16816 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_16817);
										mem_vec_16817 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_16818);
										mem_vec_16818 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_16819);
										mem_vec_16819 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_16792);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_16793);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_16794);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_16795);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_16796);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_16797);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_16798);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_16799);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_16800);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_16801);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_16802);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_16803);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_16804);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_16805);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_16806);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_16807);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_16808);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_16809);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_16810);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_16811);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_16812);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_16813);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_16814);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_16815);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_16816);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_16817);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_16818);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_16819);
						}
					}
				}
		}
	}
}


}