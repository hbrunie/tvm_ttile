#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (2, x); T (8, y); T (28, x); T (1, y)]
*/
IND_TYPE c, cp_0, c444_p_0, cp_1, c444, x, xp_0, x727_p_0, x728_p_0, xp_1, x727_p_1, xp_2, x727, x728, y, yp_0, y579_p_0, yp_1, y579;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y580 = 0;
IND_TYPE x729 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c445 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_2842 ,mem_vec_2843 ,mem_vec_2844 ,mem_vec_2845 ,mem_vec_2846 ,mem_vec_2847 ,mem_vec_2848 ,mem_vec_2849 ,mem_vec_2850 ,mem_vec_2851 ,mem_vec_2852 ,mem_vec_2853 ,mem_vec_2854 ,mem_vec_2855 ,mem_vec_2856 ,mem_vec_2857 ,mem_vec_2858 ,mem_vec_2859 ,mem_vec_2860 ,mem_vec_2861 ,mem_vec_2862 ,mem_vec_2863 ,mem_vec_2864 ,mem_vec_2865 ,mem_vec_2866 ,mem_vec_2867 ,mem_vec_2868 ,mem_vec_2869 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y579 = y580, y579_p_0 = 0;
	y579 < y580 + 56;
	y579 += 56, y579_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x728 = x729, x728_p_0 = 0;
		x728 < x729 + 56;
		x728 += 2, x728_p_0 += 2){
		// y = 56, x = 2, h = 1, w = 1, c = 64, f = 64
		// T (y, 8) (56 / 7)
		for (y = y579, yp_1 = y579_p_0, yp_0 = 0;
			y < y579 + 56;
			y += 7, yp_1 += 7, yp_0 += 7){
			// y = 7, x = 2, h = 1, w = 1, c = 64, f = 64
			// T (x, 2) (2 / 1)
			for (x727 = x728, x727_p_1 = x728_p_0, x727_p_0 = 0;
				x727 < x728 + 2;
				x727 += 1, x727_p_1 += 1, x727_p_0 += 1){
				// y = 7, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c444 = c445, c444_p_0 = 0;
					c444 < c445 + 64;
					c444 += 32, c444_p_0 += 32){
					// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
					// T (x, 1) (1 / 1)
					for (x = x727, xp_2 = x727_p_1, xp_1 = x727_p_0, xp_0 = 0;
						x < x727 + 1;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_2842 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_2843 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_2844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_2845 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_2846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_2847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_2848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_2849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_2850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_2851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_2852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_2853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_2854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_2855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_2856 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_2857 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_2858 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_2859 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_2860 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_2861 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_2862 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_2863 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_2864 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_2865 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								mem_vec_2866 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_2867 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_2868 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
								mem_vec_2869 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
								// T (c, 32) (32 / 1)
								for (c = c444, cp_1 = c444_p_0, cp_0 = 0;
									c < c444 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2842);
									mem_vec_2842 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2843);
									mem_vec_2843 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2844);
									mem_vec_2844 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2845);
									mem_vec_2845 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2846);
									mem_vec_2846 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2847);
									mem_vec_2847 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2848);
									mem_vec_2848 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2849);
									mem_vec_2849 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2850);
									mem_vec_2850 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2851);
									mem_vec_2851 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2852);
									mem_vec_2852 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2853);
									mem_vec_2853 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2854);
									mem_vec_2854 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2855);
									mem_vec_2855 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2856);
									mem_vec_2856 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2857);
									mem_vec_2857 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_2858);
									mem_vec_2858 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_2859);
									mem_vec_2859 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_2860);
									mem_vec_2860 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_2861);
									mem_vec_2861 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2862);
									mem_vec_2862 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2863);
									mem_vec_2863 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_2864);
									mem_vec_2864 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_2865);
									mem_vec_2865 = vec_33;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_35 = _mm512_set1_ps(scal_6);


									vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_2866);
									mem_vec_2866 = vec_34;



									vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_2867);
									mem_vec_2867 = vec_36;



									vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_2868);
									mem_vec_2868 = vec_37;



									vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_2869);
									mem_vec_2869 = vec_38;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2842);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2843);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2844);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2845);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2846);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2847);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2848);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2849);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2850);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2851);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2852);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2853);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2854);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2855);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2856);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2857);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2858);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2859);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_2860);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_2861);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2862);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2863);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_2864);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_2865);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2866);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2867);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_2868);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_2869);
					}
				}
			}
		}
	}
}


}