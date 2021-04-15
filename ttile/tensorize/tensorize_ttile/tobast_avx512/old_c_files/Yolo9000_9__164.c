#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (2, x); T (34, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (4, f);
  T (1, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1116_p_0, cp_1, c1116, f, fp_0, x, xp_0, x1488_p_0, x1489_p_0, xp_1, x1488_p_1, xp_2, x1488, x1489, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y744 = 0;
IND_TYPE x1490 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1117 = 0;
IND_TYPE f744 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14928 ,mem_vec_14929 ,mem_vec_14930 ,mem_vec_14931 ,mem_vec_14932 ,mem_vec_14933 ,mem_vec_14934 ,mem_vec_14935 ,mem_vec_14936 ,mem_vec_14937 ,mem_vec_14938 ,mem_vec_14939 ,mem_vec_14940 ,mem_vec_14941 ,mem_vec_14942 ,mem_vec_14943 ,mem_vec_14944 ,mem_vec_14945 ,mem_vec_14946 ,mem_vec_14947 ,mem_vec_14948 ,mem_vec_14949 ,mem_vec_14950 ,mem_vec_14951 ,mem_vec_14952 ,mem_vec_14953 ,mem_vec_14954 ,mem_vec_14955 ,mem_vec_14956 ,mem_vec_14957 ,mem_vec_14958 ,mem_vec_14959 ,mem_vec_14960 ,mem_vec_14961 ,mem_vec_14962 ,mem_vec_14963 ,mem_vec_14964 ,mem_vec_14965 ,mem_vec_14966 ,mem_vec_14967 ,mem_vec_14968 ,mem_vec_14969 ,mem_vec_14970 ,mem_vec_14971 ,mem_vec_14972 ,mem_vec_14973 ,mem_vec_14974 ,mem_vec_14975 ,mem_vec_14976 ,mem_vec_14977 ,mem_vec_14978 ,mem_vec_14979 ,mem_vec_14980 ,mem_vec_14981 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 1) (68 / 68)
for (x1489 = x1490, x1489_p_0 = 0;
	x1489 < x1490 + 68;
	x1489 += 68, x1489_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (c, 1) (256 / 256)
	for (c1116 = c1117, c1116_p_0 = 0;
		c1116 < c1117 + 256;
		c1116 += 256, c1116_p_0 += 256){
		// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f = f744, fp_0 = 0;
			f < f744 + 128;
			f += 32, fp_0 += 32){
				for (y = y744, yp_0 = 0;
					y < y744 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
					// T (x, 34) (68 / 2)
					for (x1488 = x1489, x1488_p_1 = x1489_p_0, x1488_p_0 = 0;
						x1488 < x1489 + 68;
						x1488 += 2, x1488_p_1 += 2, x1488_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 256, f = 32
						// T (x, 2) (2 / 1)
						for (x = x1488, xp_2 = x1488_p_1, xp_1 = x1488_p_0, xp_0 = 0;
							x < x1488 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14928 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14929 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_14952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_14953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c1116, cp_1 = c1116_p_0, cp_0 = 0;
										c < c1116 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14928);
										mem_vec_14928 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14929);
										mem_vec_14929 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14930);
										mem_vec_14930 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14931);
										mem_vec_14931 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14932);
										mem_vec_14932 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14933);
										mem_vec_14933 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14934);
										mem_vec_14934 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14935);
										mem_vec_14935 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14936);
										mem_vec_14936 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14937);
										mem_vec_14937 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14938);
										mem_vec_14938 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14939);
										mem_vec_14939 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14940);
										mem_vec_14940 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14941);
										mem_vec_14941 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14942);
										mem_vec_14942 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14943);
										mem_vec_14943 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14944);
										mem_vec_14944 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14945);
										mem_vec_14945 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14946);
										mem_vec_14946 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14947);
										mem_vec_14947 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14948);
										mem_vec_14948 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14949);
										mem_vec_14949 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14950);
										mem_vec_14950 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14951);
										mem_vec_14951 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_14952);
										mem_vec_14952 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_14953);
										mem_vec_14953 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14928);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14929);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14930);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14931);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14932);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14933);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14934);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14935);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14936);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14937);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14938);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14939);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14940);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14941);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14942);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14943);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14944);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14945);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14946);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14947);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14948);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14949);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14950);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14951);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_14952);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_14953);
						}
					}
				}
				for (y = y744 + 26, yp_0 = 0;
					y < y744 + 26 + 42;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
					// T (x, 34) (68 / 2)
					for (x1488 = x1489, x1488_p_1 = x1489_p_0, x1488_p_0 = 0;
						x1488 < x1489 + 68;
						x1488 += 2, x1488_p_1 += 2, x1488_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 256, f = 32
						// T (x, 2) (2 / 1)
						for (x = x1488, xp_2 = x1488_p_1, xp_1 = x1488_p_0, xp_0 = 0;
							x < x1488 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14954 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14955 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_14969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_14970 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_14971 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_14972 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_14973 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_14974 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_14975 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_14976 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_14977 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_14978 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_14979 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_14980 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_14981 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c1116, cp_1 = c1116_p_0, cp_0 = 0;
										c < c1116 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14954);
										mem_vec_14954 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14955);
										mem_vec_14955 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14956);
										mem_vec_14956 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14957);
										mem_vec_14957 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14958);
										mem_vec_14958 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14959);
										mem_vec_14959 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14960);
										mem_vec_14960 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14961);
										mem_vec_14961 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14962);
										mem_vec_14962 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14963);
										mem_vec_14963 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14964);
										mem_vec_14964 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14965);
										mem_vec_14965 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14966);
										mem_vec_14966 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14967);
										mem_vec_14967 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14968);
										mem_vec_14968 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14969);
										mem_vec_14969 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14970);
										mem_vec_14970 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14971);
										mem_vec_14971 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14972);
										mem_vec_14972 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14973);
										mem_vec_14973 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_14974);
										mem_vec_14974 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_14975);
										mem_vec_14975 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_14976);
										mem_vec_14976 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_14977);
										mem_vec_14977 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_14978);
										mem_vec_14978 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_14979);
										mem_vec_14979 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_14980);
										mem_vec_14980 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_14981);
										mem_vec_14981 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14954);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14955);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14956);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14957);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14958);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14959);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14960);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14961);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14962);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14963);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14964);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14965);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14966);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14967);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14968);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14969);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14970);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14971);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14972);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14973);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_14974);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_14975);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_14976);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_14977);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_14978);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_14979);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_14980);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_14981);
						}
					}
				}
		}
	}
}


}