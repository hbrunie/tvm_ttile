#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (2, x);
  Lambda_apply y [((Iter 6), (Arg 9)); ((Iter 1), (Arg 14))]; T (4, f);
  T (128, c); T (34, x)]
*/
IND_TYPE c, cp_0, c870_p_0, cp_1, c870, f, fp_0, x, xp_0, x1160_p_0, x1161_p_0, xp_1, x1160_p_1, xp_2, x1160, x1161, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y580 = 0;
IND_TYPE x1162 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c871 = 0;
IND_TYPE f580 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10792 ,mem_vec_10793 ,mem_vec_10794 ,mem_vec_10795 ,mem_vec_10796 ,mem_vec_10797 ,mem_vec_10798 ,mem_vec_10799 ,mem_vec_10800 ,mem_vec_10801 ,mem_vec_10802 ,mem_vec_10803 ,mem_vec_10804 ,mem_vec_10805 ,mem_vec_10806 ,mem_vec_10807 ,mem_vec_10808 ,mem_vec_10809 ,mem_vec_10810 ,mem_vec_10811 ,mem_vec_10812 ,mem_vec_10813 ,mem_vec_10814 ,mem_vec_10815 ,mem_vec_10816 ,mem_vec_10817 ,mem_vec_10818 ,mem_vec_10819 ,mem_vec_10820 ,mem_vec_10821 ,mem_vec_10822 ,mem_vec_10823 ,mem_vec_10824 ,mem_vec_10825 ,mem_vec_10826 ,mem_vec_10827 ,mem_vec_10828 ,mem_vec_10829 ,mem_vec_10830 ,mem_vec_10831 ,mem_vec_10832 ,mem_vec_10833 ,mem_vec_10834 ,mem_vec_10835 ,mem_vec_10836 ,mem_vec_10837 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 34) (68 / 2)
for (x1161 = x1162, x1161_p_0 = 0;
	x1161 < x1162 + 68;
	x1161 += 2, x1161_p_0 += 2){
	// y = 68, x = 2, h = 1, w = 1, c = 256, f = 128
	// T (c, 128) (256 / 2)
	for (c870 = c871, c870_p_0 = 0;
		c870 < c871 + 256;
		c870 += 2, c870_p_0 += 2){
		// y = 68, x = 2, h = 1, w = 1, c = 2, f = 128
		// T (f, 4) (128 / 32)
		for (f = f580, fp_0 = 0;
			f < f580 + 128;
			f += 32, fp_0 += 32){
				for (y = y580, yp_0 = 0;
					y < y580 + 54;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
					// T (x, 2) (2 / 1)
					for (x1160 = x1161, x1160_p_1 = x1161_p_0, x1160_p_0 = 0;
						x1160 < x1161 + 2;
						x1160 += 1, x1160_p_1 += 1, x1160_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1160, xp_2 = x1160_p_1, xp_1 = x1160_p_0, xp_0 = 0;
							x < x1160 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10792 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10793 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c870, cp_1 = c870_p_0, cp_0 = 0;
										c < c870 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10792);
										mem_vec_10792 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10793);
										mem_vec_10793 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10794);
										mem_vec_10794 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10795);
										mem_vec_10795 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10796);
										mem_vec_10796 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10797);
										mem_vec_10797 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10798);
										mem_vec_10798 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10799);
										mem_vec_10799 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10800);
										mem_vec_10800 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10801);
										mem_vec_10801 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10802);
										mem_vec_10802 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10803);
										mem_vec_10803 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10804);
										mem_vec_10804 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10805);
										mem_vec_10805 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10806);
										mem_vec_10806 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10807);
										mem_vec_10807 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10808);
										mem_vec_10808 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10809);
										mem_vec_10809 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10792);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10793);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10794);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10795);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10796);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10797);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10798);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10799);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10800);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10801);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10802);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10803);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10804);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10805);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10806);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10807);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10808);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10809);
						}
					}
				}
				for (y = y580 + 54, yp_0 = 0;
					y < y580 + 54 + 14;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 2, h = 1, w = 1, c = 2, f = 32
					// T (x, 2) (2 / 1)
					for (x1160 = x1161, x1160_p_1 = x1161_p_0, x1160_p_0 = 0;
						x1160 < x1161 + 2;
						x1160 += 1, x1160_p_1 += 1, x1160_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1160, xp_2 = x1160_p_1, xp_1 = x1160_p_0, xp_0 = 0;
							x < x1160 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10810 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10811 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_10828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_10829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_10830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_10831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_10832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_10833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_10834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_10835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_10836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_10837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c870, cp_1 = c870_p_0, cp_0 = 0;
										c < c870 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10810);
										mem_vec_10810 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10811);
										mem_vec_10811 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10812);
										mem_vec_10812 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10813);
										mem_vec_10813 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10814);
										mem_vec_10814 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10815);
										mem_vec_10815 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10816);
										mem_vec_10816 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10817);
										mem_vec_10817 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10818);
										mem_vec_10818 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10819);
										mem_vec_10819 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10820);
										mem_vec_10820 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10821);
										mem_vec_10821 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10822);
										mem_vec_10822 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10823);
										mem_vec_10823 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10824);
										mem_vec_10824 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10825);
										mem_vec_10825 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10826);
										mem_vec_10826 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10827);
										mem_vec_10827 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10828);
										mem_vec_10828 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10829);
										mem_vec_10829 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10830);
										mem_vec_10830 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10831);
										mem_vec_10831 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10832);
										mem_vec_10832 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10833);
										mem_vec_10833 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_10834);
										mem_vec_10834 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_10835);
										mem_vec_10835 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_10836);
										mem_vec_10836 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_10837);
										mem_vec_10837 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10810);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10811);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10812);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10813);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10814);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10815);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10816);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10817);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10818);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10819);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10820);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10821);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10822);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10823);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10824);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10825);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10826);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10827);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10828);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10829);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10830);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10831);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10832);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10833);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_10834);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_10835);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_10836);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_10837);
						}
					}
				}
		}
	}
}


}