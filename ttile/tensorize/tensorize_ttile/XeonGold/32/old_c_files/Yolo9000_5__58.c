#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x);
  Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))]; T (2, f);
  T (68, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x63_p_0, xp_1, x63, y, yp_0, y63_p_0, yp_1, y63;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y64 = 0;
IND_TYPE x64 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c42 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_868 ,mem_vec_869 ,mem_vec_870 ,mem_vec_871 ,mem_vec_872 ,mem_vec_873 ,mem_vec_874 ,mem_vec_875 ,mem_vec_876 ,mem_vec_877 ,mem_vec_878 ,mem_vec_879 ,mem_vec_880 ,mem_vec_881 ,mem_vec_882 ,mem_vec_883 ,mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
for (y63 = y64, y63_p_0 = 0;
	y63 < y64 + 136;
	y63 += 68, y63_p_0 += 68){
	// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 68) (136 / 2)
	for (x63 = x64, x63_p_0 = 0;
		x63 < x64 + 136;
		x63 += 2, x63_p_0 += 2){
		// y = 68, x = 2, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f42, fp_0 = 0;
			f < f42 + 64;
			f += 32, fp_0 += 32){
				for (y = y63, yp_1 = y63_p_0, yp_0 = 0;
					y < y63 + 18;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x63, xp_1 = x63_p_0, xp_0 = 0;
						x < x63 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_868 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_869 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_870 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_871 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_872 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_873 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_874 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_875 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_876 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_877 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_878 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_879 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_880 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_881 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_882 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_883 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_884 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_885 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c42, cp_0 = 0;
									c < c42 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_868);
									mem_vec_868 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_869);
									mem_vec_869 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_870);
									mem_vec_870 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_871);
									mem_vec_871 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_872);
									mem_vec_872 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_873);
									mem_vec_873 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_874);
									mem_vec_874 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_875);
									mem_vec_875 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_876);
									mem_vec_876 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_877);
									mem_vec_877 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_878);
									mem_vec_878 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_879);
									mem_vec_879 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_880);
									mem_vec_880 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_881);
									mem_vec_881 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_882);
									mem_vec_882 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_883);
									mem_vec_883 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_884);
									mem_vec_884 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_885);
									mem_vec_885 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_868);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_869);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_870);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_871);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_872);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_873);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_874);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_875);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_876);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_877);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_878);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_879);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_880);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_881);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_882);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_883);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_884);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_885);
					}
				}
				for (y = y63 + 18, yp_1 = y63_p_0, yp_0 = 0;
					y < y63 + 18 + 50;
					y += 10, yp_1 += 10, yp_0 += 10){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
					// T (x, 2) (2 / 1)
					for (x = x63, xp_1 = x63_p_0, xp_0 = 0;
						x < x63 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_886 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_887 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c42, cp_0 = 0;
									c < c42 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_886);
									mem_vec_886 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_887);
									mem_vec_887 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_888);
									mem_vec_888 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_889);
									mem_vec_889 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_890);
									mem_vec_890 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_891);
									mem_vec_891 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_892);
									mem_vec_892 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_893);
									mem_vec_893 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_894);
									mem_vec_894 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_895);
									mem_vec_895 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_896);
									mem_vec_896 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_897);
									mem_vec_897 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_898);
									mem_vec_898 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_899);
									mem_vec_899 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_900);
									mem_vec_900 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_901);
									mem_vec_901 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_902);
									mem_vec_902 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_903);
									mem_vec_903 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_904);
									mem_vec_904 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_905);
									mem_vec_905 = vec_31;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_886);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_887);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_888);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_889);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_890);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_891);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_892);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_893);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_894);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_895);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_896);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_897);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_898);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_899);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_900);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_901);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_902);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_903);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_904);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_905);
					}
				}
		}
	}
}


}