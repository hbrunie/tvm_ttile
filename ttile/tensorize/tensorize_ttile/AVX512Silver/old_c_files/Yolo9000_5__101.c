#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (2, f);
  T (34, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x348_p_0, xp_1, x348, y, yp_0, y348_p_0, yp_1, y348;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y349 = 0;
IND_TYPE x349 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c260 = 0;
IND_TYPE f204 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4786 ,mem_vec_4787 ,mem_vec_4788 ,mem_vec_4789 ,mem_vec_4790 ,mem_vec_4791 ,mem_vec_4792 ,mem_vec_4793 ,mem_vec_4794 ,mem_vec_4795 ,mem_vec_4796 ,mem_vec_4797 ,mem_vec_4798 ,mem_vec_4799 ,mem_vec_4800 ,mem_vec_4801 ,mem_vec_4802 ,mem_vec_4803 ,mem_vec_4804 ,mem_vec_4805 ,mem_vec_4806 ,mem_vec_4807 ,mem_vec_4808 ,mem_vec_4809 ,mem_vec_4810 ,mem_vec_4811 ,mem_vec_4812 ,mem_vec_4813 ,mem_vec_4814 ,mem_vec_4815 ,mem_vec_4816 ,mem_vec_4817 ,mem_vec_4818 ,mem_vec_4819 ,mem_vec_4820 ,mem_vec_4821 ,mem_vec_4822 ,mem_vec_4823 ,mem_vec_4824 ,mem_vec_4825 ,mem_vec_4826 ,mem_vec_4827 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y348 = y349, y348_p_0 = 0;
	y348 < y349 + 136;
	y348 += 34, y348_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 34) (136 / 4)
	for (x348 = x349, x348_p_0 = 0;
		x348 < x349 + 136;
		x348 += 4, x348_p_0 += 4){
		// y = 34, x = 4, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f204, fp_0 = 0;
			f < f204 + 64;
			f += 32, fp_0 += 32){
				for (y = y348, yp_1 = y348_p_0, yp_0 = 0;
					y < y348 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x348, xp_1 = x348_p_0, xp_0 = 0;
						x < x348 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4786 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4787 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_4801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c260, cp_0 = 0;
									c < c260 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4786);
									mem_vec_4786 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4787);
									mem_vec_4787 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4788);
									mem_vec_4788 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4789);
									mem_vec_4789 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4790);
									mem_vec_4790 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4791);
									mem_vec_4791 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4792);
									mem_vec_4792 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4793);
									mem_vec_4793 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4794);
									mem_vec_4794 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4795);
									mem_vec_4795 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4796);
									mem_vec_4796 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4797);
									mem_vec_4797 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4798);
									mem_vec_4798 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4799);
									mem_vec_4799 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4800);
									mem_vec_4800 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4801);
									mem_vec_4801 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4786);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4787);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4788);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4789);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4790);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4791);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4792);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4793);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4794);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4795);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4796);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4797);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4798);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4799);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4800);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4801);
					}
				}
				for (y = y348 + 8, yp_1 = y348_p_0, yp_0 = 0;
					y < y348 + 8 + 26;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x348, xp_1 = x348_p_0, xp_0 = 0;
						x < x348 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4802 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4803 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_4817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_4818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_4819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_4820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_4821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_4822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_4823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_4824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_4825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_4826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_4827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c260, cp_0 = 0;
									c < c260 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4802);
									mem_vec_4802 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4803);
									mem_vec_4803 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4804);
									mem_vec_4804 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4805);
									mem_vec_4805 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4806);
									mem_vec_4806 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4807);
									mem_vec_4807 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4808);
									mem_vec_4808 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4809);
									mem_vec_4809 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4810);
									mem_vec_4810 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4811);
									mem_vec_4811 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4812);
									mem_vec_4812 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4813);
									mem_vec_4813 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4814);
									mem_vec_4814 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4815);
									mem_vec_4815 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4816);
									mem_vec_4816 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4817);
									mem_vec_4817 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4818);
									mem_vec_4818 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4819);
									mem_vec_4819 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4820);
									mem_vec_4820 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4821);
									mem_vec_4821 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4822);
									mem_vec_4822 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4823);
									mem_vec_4823 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4824);
									mem_vec_4824 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4825);
									mem_vec_4825 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4826);
									mem_vec_4826 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4827);
									mem_vec_4827 = vec_40;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4802);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4803);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4804);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4805);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4806);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4807);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4808);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4809);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4810);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4811);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4812);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4813);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4814);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4815);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4816);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4817);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4818);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4819);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4820);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4821);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4822);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4823);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4824);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4825);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_4826);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_4827);
					}
				}
		}
	}
}


}