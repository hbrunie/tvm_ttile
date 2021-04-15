#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (8, f);
  T (4, c); T (2, x)]
*/
IND_TYPE c, cp_0, c798_p_0, cp_1, c798, f, fp_0, x, xp_0, x1064_p_0, x1065_p_0, xp_1, x1064_p_1, xp_2, x1064, x1065, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y532 = 0;
IND_TYPE x1066 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c799 = 0;
IND_TYPE f532 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10920 ,mem_vec_10921 ,mem_vec_10922 ,mem_vec_10923 ,mem_vec_10924 ,mem_vec_10925 ,mem_vec_10926 ,mem_vec_10927 ,mem_vec_10928 ,mem_vec_10929 ,mem_vec_10930 ,mem_vec_10931 ,mem_vec_10932 ,mem_vec_10933 ,mem_vec_10934 ,mem_vec_10935 ,mem_vec_10936 ,mem_vec_10937 ,mem_vec_10938 ,mem_vec_10939 ,mem_vec_10940 ,mem_vec_10941 ,mem_vec_10942 ,mem_vec_10943 ,mem_vec_10944 ,mem_vec_10945 ,mem_vec_10946 ,mem_vec_10947 ,mem_vec_10948 ,mem_vec_10949 ,mem_vec_10950 ,mem_vec_10951 ,mem_vec_10952 ,mem_vec_10953 ,mem_vec_10954 ,mem_vec_10955 ,mem_vec_10956 ,mem_vec_10957 ,mem_vec_10958 ,mem_vec_10959 ,mem_vec_10960 ,mem_vec_10961 ,mem_vec_10962 ,mem_vec_10963 ,mem_vec_10964 ,mem_vec_10965 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 2) (34 / 17)
for (x1065 = x1066, x1065_p_0 = 0;
	x1065 < x1066 + 34;
	x1065 += 17, x1065_p_0 += 17){
	// y = 34, x = 17, h = 1, w = 1, c = 512, f = 256
	// T (c, 4) (512 / 128)
	for (c798 = c799, c798_p_0 = 0;
		c798 < c799 + 512;
		c798 += 128, c798_p_0 += 128){
		// y = 34, x = 17, h = 1, w = 1, c = 128, f = 256
		// T (f, 8) (256 / 32)
		for (f = f532, fp_0 = 0;
			f < f532 + 256;
			f += 32, fp_0 += 32){
				for (y = y532, yp_0 = 0;
					y < y532 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 32
					// T (x, 17) (17 / 1)
					for (x1064 = x1065, x1064_p_1 = x1065_p_0, x1064_p_0 = 0;
						x1064 < x1065 + 17;
						x1064 += 1, x1064_p_1 += 1, x1064_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1064, xp_2 = x1064_p_1, xp_1 = x1064_p_0, xp_0 = 0;
							x < x1064 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10920 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10921 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_10938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_10939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_10940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_10941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (c, 128) (128 / 1)
									for (c = c798, cp_1 = c798_p_0, cp_0 = 0;
										c < c798 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10920);
										mem_vec_10920 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10921);
										mem_vec_10921 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10922);
										mem_vec_10922 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10923);
										mem_vec_10923 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10924);
										mem_vec_10924 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10925);
										mem_vec_10925 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10926);
										mem_vec_10926 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10927);
										mem_vec_10927 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10928);
										mem_vec_10928 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10929);
										mem_vec_10929 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10930);
										mem_vec_10930 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10931);
										mem_vec_10931 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10932);
										mem_vec_10932 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10933);
										mem_vec_10933 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10934);
										mem_vec_10934 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10935);
										mem_vec_10935 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10936);
										mem_vec_10936 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10937);
										mem_vec_10937 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10938);
										mem_vec_10938 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10939);
										mem_vec_10939 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10940);
										mem_vec_10940 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10941);
										mem_vec_10941 = vec_34;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10920);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10921);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10922);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10923);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10924);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10925);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10926);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10927);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10928);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10929);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10930);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10931);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10932);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10933);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10934);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10935);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10936);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10937);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10938);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10939);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10940);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10941);
						}
					}
				}
				for (y = y532 + 22, yp_0 = 0;
					y < y532 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 17, h = 1, w = 1, c = 128, f = 32
					// T (x, 17) (17 / 1)
					for (x1064 = x1065, x1064_p_1 = x1065_p_0, x1064_p_0 = 0;
						x1064 < x1065 + 17;
						x1064 += 1, x1064_p_1 += 1, x1064_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
						// T (x, 1) (1 / 1)
						for (x = x1064, xp_2 = x1064_p_1, xp_1 = x1064_p_0, xp_0 = 0;
							x < x1064 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10942 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10943 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_10960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_10961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_10962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_10963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_10964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_10965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
									// T (c, 128) (128 / 1)
									for (c = c798, cp_1 = c798_p_0, cp_0 = 0;
										c < c798 + 128;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10942);
										mem_vec_10942 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10943);
										mem_vec_10943 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10944);
										mem_vec_10944 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10945);
										mem_vec_10945 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10946);
										mem_vec_10946 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10947);
										mem_vec_10947 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10948);
										mem_vec_10948 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10949);
										mem_vec_10949 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10950);
										mem_vec_10950 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10951);
										mem_vec_10951 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10952);
										mem_vec_10952 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10953);
										mem_vec_10953 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10954);
										mem_vec_10954 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10955);
										mem_vec_10955 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10956);
										mem_vec_10956 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10957);
										mem_vec_10957 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10958);
										mem_vec_10958 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10959);
										mem_vec_10959 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10960);
										mem_vec_10960 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10961);
										mem_vec_10961 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10962);
										mem_vec_10962 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10963);
										mem_vec_10963 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10964);
										mem_vec_10964 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10965);
										mem_vec_10965 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10942);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10943);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10944);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10945);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10946);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10947);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10948);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10949);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10950);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10951);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10952);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10953);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10954);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10955);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10956);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10957);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10958);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10959);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10960);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10961);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10962);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10963);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10964);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10965);
						}
					}
				}
		}
	}
}


}