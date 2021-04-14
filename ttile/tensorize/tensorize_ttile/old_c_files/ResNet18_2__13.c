#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (2, c); Hoist_vars [c]; T (8, x); T (3, w);
  T (3, h); T (16, c); T (7, x); T (8, y); T (2, c)]
*/
IND_TYPE c, cp_0, c128_p_0, c129_p_0, cp_1, c128_p_1, cp_2, c128, c129, h, hp_0, w, wp_0, x, xp_0, x152_p_0, xp_1, x152, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y80 = 0;
IND_TYPE x153 = 0;
IND_TYPE h80 = 0;
IND_TYPE w80 = 0;
IND_TYPE c130 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_904 ,mem_vec_905 ,mem_vec_906 ,mem_vec_907 ,mem_vec_908 ,mem_vec_909 ,mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (c, 2) (64 / 32)
for (c129 = c130, c129_p_0 = 0;
	c129 < c130 + 64;
	c129 += 32, c129_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 32, f = 64
	// T (y, 8) (56 / 7)
	for (y = y80, yp_0 = 0;
		y < y80 + 56;
		y += 7, yp_0 += 7){
		// y = 7, x = 56, h = 3, w = 3, c = 32, f = 64
		// T (x, 7) (56 / 8)
		for (x152 = x153, x152_p_0 = 0;
			x152 < x153 + 56;
			x152 += 8, x152_p_0 += 8){
			// y = 7, x = 8, h = 3, w = 3, c = 32, f = 64
			// T (c, 16) (32 / 2)
			for (c128 = c129, c128_p_1 = c129_p_0, c128_p_0 = 0;
				c128 < c129 + 32;
				c128 += 2, c128_p_1 += 2, c128_p_0 += 2){
				// y = 7, x = 8, h = 3, w = 3, c = 2, f = 64
				// T (h, 3) (3 / 1)
				for (h = h80, hp_0 = 0;
					h < h80 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 8, h = 1, w = 3, c = 2, f = 64
					// T (w, 3) (3 / 1)
					for (w = w80, wp_0 = 0;
						w < w80 + 3;
						w += 1, wp_0 += 1){
						// y = 7, x = 8, h = 1, w = 1, c = 2, f = 64
						// T (x, 8) (8 / 1)
						for (x = x152, xp_1 = x152_p_0, xp_0 = 0;
							x < x152 + 8;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_904 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_905 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_906 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_907 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c128, cp_2 = c128_p_1, cp_1 = c128_p_0, cp_0 = 0;
										c < c128 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_904);
										mem_vec_904 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_905);
										mem_vec_905 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_906);
										mem_vec_906 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_907);
										mem_vec_907 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_908);
										mem_vec_908 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_909);
										mem_vec_909 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_910);
										mem_vec_910 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_911);
										mem_vec_911 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_912);
										mem_vec_912 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_913);
										mem_vec_913 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_914);
										mem_vec_914 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_915);
										mem_vec_915 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_916);
										mem_vec_916 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_917);
										mem_vec_917 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_918);
										mem_vec_918 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_919);
										mem_vec_919 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_920);
										mem_vec_920 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_921);
										mem_vec_921 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_922);
										mem_vec_922 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_923);
										mem_vec_923 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_924);
										mem_vec_924 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_925);
										mem_vec_925 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_926);
										mem_vec_926 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_927);
										mem_vec_927 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_928);
										mem_vec_928 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_929);
										mem_vec_929 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_930);
										mem_vec_930 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_931);
										mem_vec_931 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_904);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_905);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_906);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_907);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_908);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_909);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_910);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_911);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_917);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_918);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_919);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_920);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_921);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_922);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_923);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_924);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_925);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_926);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_927);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_928);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_929);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_930);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_931);
						}
					}
				}
			}
		}
	}
}


}