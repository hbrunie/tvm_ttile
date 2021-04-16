#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (8, y);
  T (1, c); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c53_p_0, cp_1, c53, x, xp_0, x72_p_0, xp_1, x72, y, yp_0, y72_p_0, yp_1, y72;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y73 = 0;
IND_TYPE x73 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c54 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_892 ,mem_vec_893 ,mem_vec_894 ,mem_vec_895 ,mem_vec_896 ,mem_vec_897 ,mem_vec_898 ,mem_vec_899 ,mem_vec_900 ,mem_vec_901 ,mem_vec_902 ,mem_vec_903 ,mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y72 = y73, y72_p_0 = 0;
		y72 < y73 + 96;
		y72 += 32, y72_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x72 = x73, x72_p_0 = 0;
			x72 < x73 + 136;
			x72 += 2, x72_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c53 = c54, c53_p_0 = 0;
				c53 < c54 + 128;
				c53 += 128, c53_p_0 += 128){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (y, 8) (8 * ph_y / ph_y)
				for (y = y72, yp_1 = y72_p_0, yp_0 = 0;
					y < y72 + 32;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
						x < x72 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_892 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_893 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_894 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_895 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_896 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_897 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_898 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_899 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_900 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_901 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c53, cp_1 = c53_p_0, cp_0 = 0;
									c < c53 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_892);
									mem_vec_892 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_893);
									mem_vec_893 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_894);
									mem_vec_894 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_895);
									mem_vec_895 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_896);
									mem_vec_896 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_897);
									mem_vec_897 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_898);
									mem_vec_898 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_899);
									mem_vec_899 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_900);
									mem_vec_900 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_901);
									mem_vec_901 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_902);
									mem_vec_902 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_903);
									mem_vec_903 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_904);
									mem_vec_904 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_905);
									mem_vec_905 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_906);
									mem_vec_906 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_907);
									mem_vec_907 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_892);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_893);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_894);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_895);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_896);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_897);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_898);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_899);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_900);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_901);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_902);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_903);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_904);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_905);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_906);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_907);
					}
				}
			}
		}
	}
	for (y72 = y73 + 96, y72_p_0 = 0;
		y72 < y73 + 96 + 40;
		y72 += 40, y72_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x72 = x73, x72_p_0 = 0;
			x72 < x73 + 136;
			x72 += 2, x72_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c53 = c54, c53_p_0 = 0;
				c53 < c54 + 128;
				c53 += 128, c53_p_0 += 128){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (y, 8) (8 * ph_y / ph_y)
				for (y = y72, yp_1 = y72_p_0, yp_0 = 0;
					y < y72 + 40;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
						x < x72 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_908 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_909 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c53, cp_1 = c53_p_0, cp_0 = 0;
									c < c53 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_908);
									mem_vec_908 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_909);
									mem_vec_909 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_910);
									mem_vec_910 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_911);
									mem_vec_911 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_912);
									mem_vec_912 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_913);
									mem_vec_913 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_914);
									mem_vec_914 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_915);
									mem_vec_915 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_916);
									mem_vec_916 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_917);
									mem_vec_917 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_918);
									mem_vec_918 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_919);
									mem_vec_919 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_920);
									mem_vec_920 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_921);
									mem_vec_921 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_922);
									mem_vec_922 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_923);
									mem_vec_923 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_924);
									mem_vec_924 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_925);
									mem_vec_925 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_926);
									mem_vec_926 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_927);
									mem_vec_927 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_908);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_909);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_910);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_911);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_912);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_913);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_914);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_915);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_916);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_917);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_918);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_919);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_920);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_921);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_922);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_923);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_924);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_925);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_926);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_927);
					}
				}
			}
		}
	}


}