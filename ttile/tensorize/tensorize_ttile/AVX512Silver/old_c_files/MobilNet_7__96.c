#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (64, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); T (2, c); T (1, y); T (16, f); T (4, c)]
*/
IND_TYPE c, cp_0, c168_p_0, c169_p_0, cp_1, c168_p_1, cp_2, c168, c169, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y88 = 0;
IND_TYPE x88 = 0;
IND_TYPE h68 = 0;
IND_TYPE w68 = 0;
IND_TYPE c170 = 0;
IND_TYPE f96 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,mem_vec_926 ,mem_vec_927 ,mem_vec_928 ,mem_vec_929 ,mem_vec_930 ,mem_vec_931 ,mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 4) (512 / 128)
for (c169 = c170, c169_p_0 = 0;
	c169 < c170 + 512;
	c169 += 128, c169_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 128, f = 512
	// T (f, 16) (512 / 32)
	for (f = f96, fp_0 = 0;
		f < f96 + 512;
		f += 32, fp_0 += 32){
		// y = 14, x = 14, h = 3, w = 3, c = 128, f = 32
		// T (y, 1) (14 / 14)
		for (y = y88, yp_0 = 0;
			y < y88 + 14;
			y += 14, yp_0 += 14){
			// y = 14, x = 14, h = 3, w = 3, c = 128, f = 32
			// T (c, 2) (128 / 64)
			for (c168 = c169, c168_p_1 = c169_p_0, c168_p_0 = 0;
				c168 < c169 + 128;
				c168 += 64, c168_p_1 += 64, c168_p_0 += 64){
				// y = 14, x = 14, h = 3, w = 3, c = 64, f = 32
				// T (x, 14) (14 / 1)
				for (x = x88, xp_0 = 0;
					x < x88 + 14;
					x += 1, xp_0 += 1){
					// y = 14, x = 1, h = 3, w = 3, c = 64, f = 32
					// T (h, 3) (3 / 1)
					for (h = h68, hp_0 = 0;
						h < h68 + 3;
						h += 1, hp_0 += 1){
						// y = 14, x = 1, h = 1, w = 3, c = 64, f = 32
						// T (w, 3) (3 / 1)
						for (w = w68, wp_0 = 0;
							w < w68 + 3;
							w += 1, wp_0 += 1){
									mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = 14, x = 1, h = 1, w = 1, c = 64, f = 32
									// T (c, 64) (64 / 1)
									for (c = c168, cp_2 = c168_p_1, cp_1 = c168_p_0, cp_0 = 0;
										c < c168 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_910);
										mem_vec_910 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_911);
										mem_vec_911 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_912);
										mem_vec_912 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_913);
										mem_vec_913 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_914);
										mem_vec_914 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_915);
										mem_vec_915 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_916);
										mem_vec_916 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_917);
										mem_vec_917 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_918);
										mem_vec_918 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_919);
										mem_vec_919 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_920);
										mem_vec_920 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_921);
										mem_vec_921 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_922);
										mem_vec_922 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_923);
										mem_vec_923 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_924);
										mem_vec_924 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_925);
										mem_vec_925 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_926);
										mem_vec_926 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_927);
										mem_vec_927 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_928);
										mem_vec_928 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_929);
										mem_vec_929 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_930);
										mem_vec_930 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_931);
										mem_vec_931 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_932);
										mem_vec_932 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_933);
										mem_vec_933 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_934);
										mem_vec_934 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_935);
										mem_vec_935 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_936);
										mem_vec_936 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_937);
										mem_vec_937 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_910);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_911);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_917);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_918);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_919);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_920);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_921);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_922);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_923);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_924);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_925);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_926);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_927);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_928);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_929);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_930);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_931);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_932);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_933);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_934);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_935);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_936);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_937);
						}
					}
				}
			}
		}
	}
}


}