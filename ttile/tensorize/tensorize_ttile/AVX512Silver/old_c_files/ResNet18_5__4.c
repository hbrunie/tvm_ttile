#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (28, x); T (2, c);
  T (1, x); T (4, y); T (1, f); T (2, f)]
*/
IND_TYPE c, cp_0, c139_p_0, cp_1, c139, f, fp_0, f139_p_0, fp_1, f139, x, xp_0, x150_p_0, xp_1, x150, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 128));
IND_TYPE y100 = 0;
IND_TYPE x151 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c140 = 0;
IND_TYPE f140 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_884 ,mem_vec_885 ,mem_vec_886 ,mem_vec_887 ,mem_vec_888 ,mem_vec_889 ,mem_vec_890 ,mem_vec_891 ,mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 1, w = 1, c = 64, f = 128
// T (f, 2) (128 / 64)
for (f139 = f140, f139_p_0 = 0;
	f139 < f140 + 128;
	f139 += 64, f139_p_0 += 64){
	// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
	// T (f, 1) (64 / 64)
	for (f = f139, fp_1 = f139_p_0, fp_0 = 0;
		f < f139 + 64;
		f += 64, fp_1 += 64, fp_0 += 64){
		// y = 28, x = 28, h = 1, w = 1, c = 64, f = 64
		// T (y, 4) (28 / 7)
		for (y = y100, yp_0 = 0;
			y < y100 + 28;
			y += 7, yp_0 += 7){
			// y = 7, x = 28, h = 1, w = 1, c = 64, f = 64
			// T (x, 1) (28 / 28)
			for (x150 = x151, x150_p_0 = 0;
				x150 < x151 + 28;
				x150 += 28, x150_p_0 += 28){
				// y = 7, x = 28, h = 1, w = 1, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c139 = c140, c139_p_0 = 0;
					c139 < c140 + 64;
					c139 += 32, c139_p_0 += 32){
					// y = 7, x = 28, h = 1, w = 1, c = 32, f = 64
					// T (x, 28) (28 / 1)
					for (x = x150, xp_1 = x150_p_0, xp_0 = 0;
						x < x150 + 28;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_884 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_885 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_886 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_887 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_888 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_889 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_890 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_891 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_892 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_893 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_894 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_895 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c139, cp_1 = c139_p_0, cp_0 = 0;
									c < c139 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_884);
									mem_vec_884 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_885);
									mem_vec_885 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_886);
									mem_vec_886 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_887);
									mem_vec_887 = vec_7;
									scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_888);
									mem_vec_888 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_889);
									mem_vec_889 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_890);
									mem_vec_890 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_891);
									mem_vec_891 = vec_13;
									scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_892);
									mem_vec_892 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_893);
									mem_vec_893 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_894);
									mem_vec_894 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_895);
									mem_vec_895 = vec_18;
									scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_896);
									mem_vec_896 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_897);
									mem_vec_897 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_898);
									mem_vec_898 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_899);
									mem_vec_899 = vec_23;
									scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_900);
									mem_vec_900 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_901);
									mem_vec_901 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_902);
									mem_vec_902 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_903);
									mem_vec_903 = vec_28;
									scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_904);
									mem_vec_904 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_905);
									mem_vec_905 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_906);
									mem_vec_906 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_907);
									mem_vec_907 = vec_33;
									scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_908);
									mem_vec_908 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_909);
									mem_vec_909 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_910);
									mem_vec_910 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_911);
									mem_vec_911 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_884);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_885);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_886);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_887);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_888);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_889);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_890);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_891);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_892);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_893);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_894);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_895);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_896);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_897);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_898);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_899);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_900);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_901);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_902);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_903);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_904);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_905);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_906);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_907);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_908);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_909);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_910);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_911);
					}
				}
			}
		}
	}
}


}