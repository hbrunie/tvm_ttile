#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (4, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (4, f);
  T (16, c); T (17, x)]
*/
IND_TYPE c, cp_0, c1170_p_0, cp_1, c1170, f, fp_0, x, xp_0, x1560_p_0, x1561_p_0, xp_1, x1560_p_1, xp_2, x1560, x1561, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y780 = 0;
IND_TYPE x1562 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1171 = 0;
IND_TYPE f780 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_15900 ,mem_vec_15901 ,mem_vec_15902 ,mem_vec_15903 ,mem_vec_15904 ,mem_vec_15905 ,mem_vec_15906 ,mem_vec_15907 ,mem_vec_15908 ,mem_vec_15909 ,mem_vec_15910 ,mem_vec_15911 ,mem_vec_15912 ,mem_vec_15913 ,mem_vec_15914 ,mem_vec_15915 ,mem_vec_15916 ,mem_vec_15917 ,mem_vec_15918 ,mem_vec_15919 ,mem_vec_15920 ,mem_vec_15921 ,mem_vec_15922 ,mem_vec_15923 ,mem_vec_15924 ,mem_vec_15925 ,mem_vec_15926 ,mem_vec_15927 ,mem_vec_15928 ,mem_vec_15929 ,mem_vec_15930 ,mem_vec_15931 ,mem_vec_15932 ,mem_vec_15933 ,mem_vec_15934 ,mem_vec_15935 ,mem_vec_15936 ,mem_vec_15937 ,mem_vec_15938 ,mem_vec_15939 ,mem_vec_15940 ,mem_vec_15941 ,mem_vec_15942 ,mem_vec_15943 ,mem_vec_15944 ,mem_vec_15945 ,mem_vec_15946 ,mem_vec_15947 ,mem_vec_15948 ,mem_vec_15949 ,mem_vec_15950 ,mem_vec_15951 ,mem_vec_15952 ,mem_vec_15953 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 17) (68 / 4)
for (x1561 = x1562, x1561_p_0 = 0;
	x1561 < x1562 + 68;
	x1561 += 4, x1561_p_0 += 4){
	// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
	// T (c, 16) (256 / 16)
	for (c1170 = c1171, c1170_p_0 = 0;
		c1170 < c1171 + 256;
		c1170 += 16, c1170_p_0 += 16){
		// y = 68, x = 4, h = 1, w = 1, c = 16, f = 128
		// T (f, 4) (128 / 32)
		for (f = f780, fp_0 = 0;
			f < f780 + 128;
			f += 32, fp_0 += 32){
				for (y = y780, yp_0 = 0;
					y < y780 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
					// T (x, 4) (4 / 1)
					for (x1560 = x1561, x1560_p_1 = x1561_p_0, x1560_p_0 = 0;
						x1560 < x1561 + 4;
						x1560 += 1, x1560_p_1 += 1, x1560_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1560, xp_2 = x1560_p_1, xp_1 = x1560_p_0, xp_0 = 0;
							x < x1560 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15900 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15901 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15902 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15903 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15904 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15905 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15906 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15907 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15908 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15909 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15910 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15911 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_15915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_15916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_15917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_15918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_15919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_15920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_15921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_15922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_15923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_15924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_15925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c1170, cp_1 = c1170_p_0, cp_0 = 0;
										c < c1170 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15900);
										mem_vec_15900 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15901);
										mem_vec_15901 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_15902);
										mem_vec_15902 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_15903);
										mem_vec_15903 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_15904);
										mem_vec_15904 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_15905);
										mem_vec_15905 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_15906);
										mem_vec_15906 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_15907);
										mem_vec_15907 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15908);
										mem_vec_15908 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15909);
										mem_vec_15909 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_15910);
										mem_vec_15910 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_15911);
										mem_vec_15911 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_15912);
										mem_vec_15912 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_15913);
										mem_vec_15913 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_15914);
										mem_vec_15914 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_15915);
										mem_vec_15915 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_15916);
										mem_vec_15916 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_15917);
										mem_vec_15917 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15918);
										mem_vec_15918 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15919);
										mem_vec_15919 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_15920);
										mem_vec_15920 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_15921);
										mem_vec_15921 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_15922);
										mem_vec_15922 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_15923);
										mem_vec_15923 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_15924);
										mem_vec_15924 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_15925);
										mem_vec_15925 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15900);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15901);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15902);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15903);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15904);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15905);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15906);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15907);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15908);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15909);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15910);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15911);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15912);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15913);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_15914);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_15915);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_15916);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_15917);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_15918);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_15919);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_15920);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_15921);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_15922);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_15923);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_15924);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_15925);
						}
					}
				}
				for (y = y780 + 26, yp_0 = 0;
					y < y780 + 26 + 42;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 4, h = 1, w = 1, c = 16, f = 32
					// T (x, 4) (4 / 1)
					for (x1560 = x1561, x1560_p_1 = x1561_p_0, x1560_p_0 = 0;
						x1560 < x1561 + 4;
						x1560 += 1, x1560_p_1 += 1, x1560_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1560, xp_2 = x1560_p_1, xp_1 = x1560_p_0, xp_0 = 0;
							x < x1560 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15926 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15927 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_15941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_15942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_15943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_15944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_15945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_15946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_15947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_15948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_15949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_15950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_15951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_15952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_15953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (c, 16) (16 / 1)
									for (c = c1170, cp_1 = c1170_p_0, cp_0 = 0;
										c < c1170 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15926);
										mem_vec_15926 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15927);
										mem_vec_15927 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_15928);
										mem_vec_15928 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_15929);
										mem_vec_15929 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_15930);
										mem_vec_15930 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_15931);
										mem_vec_15931 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_15932);
										mem_vec_15932 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_15933);
										mem_vec_15933 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15934);
										mem_vec_15934 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15935);
										mem_vec_15935 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_15936);
										mem_vec_15936 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_15937);
										mem_vec_15937 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_15938);
										mem_vec_15938 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_15939);
										mem_vec_15939 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_15940);
										mem_vec_15940 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_15941);
										mem_vec_15941 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_15942);
										mem_vec_15942 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_15943);
										mem_vec_15943 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15944);
										mem_vec_15944 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15945);
										mem_vec_15945 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_15946);
										mem_vec_15946 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_15947);
										mem_vec_15947 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_15948);
										mem_vec_15948 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_15949);
										mem_vec_15949 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_15950);
										mem_vec_15950 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_15951);
										mem_vec_15951 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_15952);
										mem_vec_15952 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_15953);
										mem_vec_15953 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15926);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15927);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15928);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15929);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15930);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15931);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15932);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15933);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15934);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15935);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15936);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15937);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15938);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15939);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_15940);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_15941);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_15942);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_15943);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_15944);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_15945);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_15946);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_15947);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_15948);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_15949);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_15950);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_15951);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_15952);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_15953);
						}
					}
				}
		}
	}
}


}