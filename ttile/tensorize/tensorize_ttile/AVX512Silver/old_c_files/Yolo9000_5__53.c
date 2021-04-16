#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]; T (2, f);
  T (68, x); T (4, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x351_p_0, xp_1, x351, y, yp_0, y351_p_0, yp_1, y351;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y352 = 0;
IND_TYPE x352 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c262 = 0;
IND_TYPE f206 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4828 ,mem_vec_4829 ,mem_vec_4830 ,mem_vec_4831 ,mem_vec_4832 ,mem_vec_4833 ,mem_vec_4834 ,mem_vec_4835 ,mem_vec_4836 ,mem_vec_4837 ,mem_vec_4838 ,mem_vec_4839 ,mem_vec_4840 ,mem_vec_4841 ,mem_vec_4842 ,mem_vec_4843 ,mem_vec_4844 ,mem_vec_4845 ,mem_vec_4846 ,mem_vec_4847 ,mem_vec_4848 ,mem_vec_4849 ,mem_vec_4850 ,mem_vec_4851 ,mem_vec_4852 ,mem_vec_4853 ,mem_vec_4854 ,mem_vec_4855 ,mem_vec_4856 ,mem_vec_4857 ,mem_vec_4858 ,mem_vec_4859 ,mem_vec_4860 ,mem_vec_4861 ,mem_vec_4862 ,mem_vec_4863 ,mem_vec_4864 ,mem_vec_4865 ,mem_vec_4866 ,mem_vec_4867 ,mem_vec_4868 ,mem_vec_4869 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 4) (136 / 34)
for (y351 = y352, y351_p_0 = 0;
	y351 < y352 + 136;
	y351 += 34, y351_p_0 += 34){
	// y = 34, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x351 = x352, x351_p_0 = 0;
		x351 < x352 + 136;
		x351 += 2, x351_p_0 += 2){
		// y = 34, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f206, fp_0 = 0;
			f < f206 + 64;
			f += 32, fp_0 += 32){
				for (y = y351, yp_1 = y351_p_0, yp_0 = 0;
					y < y351 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x351, xp_1 = x351_p_0, xp_0 = 0;
						x < x351 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4828 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4829 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_4843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c262, cp_0 = 0;
									c < c262 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4828);
									mem_vec_4828 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4829);
									mem_vec_4829 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4830);
									mem_vec_4830 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4831);
									mem_vec_4831 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4832);
									mem_vec_4832 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4833);
									mem_vec_4833 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4834);
									mem_vec_4834 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4835);
									mem_vec_4835 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4836);
									mem_vec_4836 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4837);
									mem_vec_4837 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4838);
									mem_vec_4838 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4839);
									mem_vec_4839 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4840);
									mem_vec_4840 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4841);
									mem_vec_4841 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4842);
									mem_vec_4842 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4843);
									mem_vec_4843 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4828);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4829);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4830);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4831);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4832);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4833);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4834);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4835);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4836);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4837);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4838);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4839);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4840);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4841);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4842);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4843);
					}
				}
				for (y = y351 + 8, yp_1 = y351_p_0, yp_0 = 0;
					y < y351 + 8 + 26;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x351, xp_1 = x351_p_0, xp_0 = 0;
						x < x351 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_4844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_4845 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_4846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_4847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_4848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_4849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_4850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_4851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_4852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_4853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_4854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_4855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_4856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_4857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_4858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_4859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_4860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_4861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_4862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_4863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_4864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_4865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_4866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_4867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								mem_vec_4868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
								mem_vec_4869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c262, cp_0 = 0;
									c < c262 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4844);
									mem_vec_4844 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4845);
									mem_vec_4845 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4846);
									mem_vec_4846 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4847);
									mem_vec_4847 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4848);
									mem_vec_4848 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4849);
									mem_vec_4849 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4850);
									mem_vec_4850 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4851);
									mem_vec_4851 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4852);
									mem_vec_4852 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4853);
									mem_vec_4853 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4854);
									mem_vec_4854 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4855);
									mem_vec_4855 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4856);
									mem_vec_4856 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4857);
									mem_vec_4857 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4858);
									mem_vec_4858 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4859);
									mem_vec_4859 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4860);
									mem_vec_4860 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4861);
									mem_vec_4861 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4862);
									mem_vec_4862 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4863);
									mem_vec_4863 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4864);
									mem_vec_4864 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4865);
									mem_vec_4865 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_4866);
									mem_vec_4866 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_4867);
									mem_vec_4867 = vec_37;
									scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
									vec_39 = _mm512_set1_ps(scal_12);


									vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_4868);
									mem_vec_4868 = vec_38;



									vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_4869);
									mem_vec_4869 = vec_40;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4844);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4845);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4846);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4847);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4848);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4849);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4850);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4851);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4852);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4853);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4854);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4855);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4856);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4857);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4858);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4859);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4860);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4861);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4862);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4863);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4864);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4865);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_4866);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_4867);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_4868);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_4869);
					}
				}
		}
	}
}


}