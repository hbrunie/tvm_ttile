#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (4, x); T (1, x);
  Lambda_apply y [((Iter 4), (Arg 7)); ((Iter 5), (Arg 8))]; T (4, f);
  T (32, c); T (17, x)]
*/
IND_TYPE c, cp_0, c138_p_0, cp_1, c138, f, fp_0, x, xp_0, x184_p_0, x185_p_0, xp_1, x184_p_1, xp_2, x184, x185, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y92 = 0;
IND_TYPE x186 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c139 = 0;
IND_TYPE f92 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_932 ,mem_vec_933 ,mem_vec_934 ,mem_vec_935 ,mem_vec_936 ,mem_vec_937 ,mem_vec_938 ,mem_vec_939 ,mem_vec_940 ,mem_vec_941 ,mem_vec_942 ,mem_vec_943 ,mem_vec_944 ,mem_vec_945 ,mem_vec_946 ,mem_vec_947 ,mem_vec_948 ,mem_vec_949 ,mem_vec_950 ,mem_vec_951 ,mem_vec_952 ,mem_vec_953 ,mem_vec_954 ,mem_vec_955 ,mem_vec_956 ,mem_vec_957 ,mem_vec_958 ,mem_vec_959 ,mem_vec_960 ,mem_vec_961 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 17) (68 / 4)
for (x185 = x186, x185_p_0 = 0;
	x185 < x186 + 68;
	x185 += 4, x185_p_0 += 4){
	// y = 68, x = 4, h = 1, w = 1, c = 256, f = 128
	// T (c, 32) (256 / 8)
	for (c138 = c139, c138_p_0 = 0;
		c138 < c139 + 256;
		c138 += 8, c138_p_0 += 8){
		// y = 68, x = 4, h = 1, w = 1, c = 8, f = 128
		// T (f, 4) (128 / 32)
		for (f = f92, fp_0 = 0;
			f < f92 + 128;
			f += 32, fp_0 += 32){
				for (y = y92, yp_0 = 0;
					y < y92 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 4, h = 1, w = 1, c = 8, f = 32
					// T (x, 1) (4 / 4)
					for (x184 = x185, x184_p_1 = x185_p_0, x184_p_0 = 0;
						x184 < x185 + 4;
						x184 += 4, x184_p_1 += 4, x184_p_0 += 4){
						// y = ph_y, x = 4, h = 1, w = 1, c = 8, f = 32
						// T (x, 4) (4 / 1)
						for (x = x184, xp_2 = x184_p_1, xp_1 = x184_p_0, xp_0 = 0;
							x < x184 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_932 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_933 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
										c < c138 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_932);
										mem_vec_932 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_933);
										mem_vec_933 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_934);
										mem_vec_934 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_935);
										mem_vec_935 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_936);
										mem_vec_936 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_937);
										mem_vec_937 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_938);
										mem_vec_938 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_939);
										mem_vec_939 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_940);
										mem_vec_940 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_941);
										mem_vec_941 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_942);
										mem_vec_942 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_943);
										mem_vec_943 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_944);
										mem_vec_944 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_945);
										mem_vec_945 = vec_22;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_932);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_933);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_934);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_935);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_936);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_937);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_938);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_939);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_940);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_941);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_942);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_943);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_944);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_945);
						}
					}
				}
				for (y = y92 + 28, yp_0 = 0;
					y < y92 + 28 + 40;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 4, h = 1, w = 1, c = 8, f = 32
					// T (x, 1) (4 / 4)
					for (x184 = x185, x184_p_1 = x185_p_0, x184_p_0 = 0;
						x184 < x185 + 4;
						x184 += 4, x184_p_1 += 4, x184_p_0 += 4){
						// y = ph_y, x = 4, h = 1, w = 1, c = 8, f = 32
						// T (x, 4) (4 / 1)
						for (x = x184, xp_2 = x184_p_1, xp_1 = x184_p_0, xp_0 = 0;
							x < x184 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_946 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_947 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
										c < c138 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_946);
										mem_vec_946 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_947);
										mem_vec_947 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_948);
										mem_vec_948 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_949);
										mem_vec_949 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_950);
										mem_vec_950 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_951);
										mem_vec_951 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_952);
										mem_vec_952 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_953);
										mem_vec_953 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_954);
										mem_vec_954 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_955);
										mem_vec_955 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_956);
										mem_vec_956 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_957);
										mem_vec_957 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_958);
										mem_vec_958 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_959);
										mem_vec_959 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_960);
										mem_vec_960 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_961);
										mem_vec_961 = vec_25;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_946);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_947);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_948);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_949);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_950);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_951);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_952);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_953);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_954);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_955);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_956);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_957);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_958);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_959);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_960);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_961);
						}
					}
				}
		}
	}
}


}