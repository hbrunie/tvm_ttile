#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (2, c);
  T (4, f); T (1, x); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]]
*/
IND_TYPE c, cp_0, c51_p_0, cp_1, c51, f, fp_0, x, xp_0, x68_p_0, x69_p_0, xp_1, x68_p_1, xp_2, x68, x69, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y34 = 0;
IND_TYPE x70 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c52 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,mem_vec_822 ,mem_vec_823 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y = y34, yp_0 = 0;
		y < y34 + 6;
		y += 6, yp_0 += 6){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 2) (34 / 17)
		for (x69 = x70, x69_p_0 = 0;
			x69 < x70 + 34;
			x69 += 17, x69_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
			// T (x, 1) (17 / 17)
			for (x68 = x69, x68_p_1 = x69_p_0, x68_p_0 = 0;
				x68 < x69 + 17;
				x68 += 17, x68_p_1 += 17, x68_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f34, fp_0 = 0;
					f < f34 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 2) (512 / 256)
					for (c51 = c52, c51_p_0 = 0;
						c51 < c52 + 512;
						c51 += 256, c51_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x68, xp_2 = x68_p_1, xp_1 = x68_p_0, xp_0 = 0;
							x < x68 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
										c < c51 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_772);
										mem_vec_772 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_773);
										mem_vec_773 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_774);
										mem_vec_774 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_775);
										mem_vec_775 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_776);
										mem_vec_776 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_777);
										mem_vec_777 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_778);
										mem_vec_778 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_779);
										mem_vec_779 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_780);
										mem_vec_780 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_781);
										mem_vec_781 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_782);
										mem_vec_782 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_783);
										mem_vec_783 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_784);
										mem_vec_784 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_785);
										mem_vec_785 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_786);
										mem_vec_786 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_787);
										mem_vec_787 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_788);
										mem_vec_788 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_789);
										mem_vec_789 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_790);
										mem_vec_790 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_791);
										mem_vec_791 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_792);
										mem_vec_792 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_793);
										mem_vec_793 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_794);
										mem_vec_794 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_795);
										mem_vec_795 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_772);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_773);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_774);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_775);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_776);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_777);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_778);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_779);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_780);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_781);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_782);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_783);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_784);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_785);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_786);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_787);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_788);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_789);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_790);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_791);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_792);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_793);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_794);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_795);
						}
					}
				}
			}
		}
	}
	for (y = y34 + 6, yp_0 = 0;
		y < y34 + 6 + 28;
		y += 7, yp_0 += 7){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 2) (34 / 17)
		for (x69 = x70, x69_p_0 = 0;
			x69 < x70 + 34;
			x69 += 17, x69_p_0 += 17){
			// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
			// T (x, 1) (17 / 17)
			for (x68 = x69, x68_p_1 = x69_p_0, x68_p_0 = 0;
				x68 < x69 + 17;
				x68 += 17, x68_p_1 += 17, x68_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 256
				// T (f, 4) (256 / 64)
				for (f = f34, fp_0 = 0;
					f < f34 + 256;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 64
					// T (c, 2) (512 / 256)
					for (c51 = c52, c51_p_0 = 0;
						c51 < c52 + 512;
						c51 += 256, c51_p_0 += 256){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (x, 17) (17 / 1)
						for (x = x68, xp_2 = x68_p_1, xp_1 = x68_p_0, xp_0 = 0;
							x < x68 + 17;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_796 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_797 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_798 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_799 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
									// T (c, 256) (256 / 1)
									for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
										c < c51 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_796);
										mem_vec_796 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_797);
										mem_vec_797 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_798);
										mem_vec_798 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_799);
										mem_vec_799 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_800);
										mem_vec_800 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_801);
										mem_vec_801 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_802);
										mem_vec_802 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_803);
										mem_vec_803 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_804);
										mem_vec_804 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_805);
										mem_vec_805 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_806);
										mem_vec_806 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_807);
										mem_vec_807 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_808);
										mem_vec_808 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_809);
										mem_vec_809 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_810);
										mem_vec_810 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_811);
										mem_vec_811 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_812);
										mem_vec_812 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_813);
										mem_vec_813 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_814);
										mem_vec_814 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_815);
										mem_vec_815 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_816);
										mem_vec_816 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_817);
										mem_vec_817 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_818);
										mem_vec_818 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_819);
										mem_vec_819 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_820);
										mem_vec_820 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_821);
										mem_vec_821 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_822);
										mem_vec_822 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_823);
										mem_vec_823 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_796);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_797);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_798);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_799);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_800);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_801);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_802);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_803);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_804);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_805);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_806);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_807);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_808);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_809);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_810);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_811);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_812);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_813);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_814);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_815);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_816);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_817);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_818);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_819);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_820);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_821);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_822);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_823);
						}
					}
				}
			}
		}
	}


}