#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (16, c);
  T (1, y); T (8, f); T (1, c);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c300_p_0, c301_p_0, cp_1, c300_p_1, cp_2, c300, c301, f, fp_0, x, xp_0, y, yp_0, y225_p_0, yp_1, y225;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y226 = 0;
IND_TYPE x150 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c302 = 0;
IND_TYPE f150 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_3080 ,mem_vec_3081 ,mem_vec_3082 ,mem_vec_3083 ,mem_vec_3084 ,mem_vec_3085 ,mem_vec_3086 ,mem_vec_3087 ,mem_vec_3088 ,mem_vec_3089 ,mem_vec_3090 ,mem_vec_3091 ,mem_vec_3092 ,mem_vec_3093 ,mem_vec_3094 ,mem_vec_3095 ,mem_vec_3096 ,mem_vec_3097 ,mem_vec_3098 ,mem_vec_3099 ,mem_vec_3100 ,mem_vec_3101 ,mem_vec_3102 ,mem_vec_3103 ,mem_vec_3104 ,mem_vec_3105 ,mem_vec_3106 ,mem_vec_3107 ,mem_vec_3108 ,mem_vec_3109 ,mem_vec_3110 ,mem_vec_3111 ,mem_vec_3112 ,mem_vec_3113 ,mem_vec_3114 ,mem_vec_3115 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y225 = y226, y225_p_0 = 0;
		y225 < y226 + 12;
		y225 += 4, y225_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c301 = c302, c301_p_0 = 0;
			c301 < c302 + 1024;
			c301 += 1024, c301_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f150, fp_0 = 0;
				f < f150 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y225, yp_1 = y225_p_0, yp_0 = 0;
					y < y225 + 4;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 16) (1024 / 64)
					for (c300 = c301, c300_p_1 = c301_p_0, c300_p_0 = 0;
						c300 < c301 + 1024;
						c300 += 64, c300_p_1 += 64, c300_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x150, xp_0 = 0;
							x < x150 + 17;
							x += 1, xp_0 += 1){
									mem_vec_3080 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3081 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3082 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3083 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_3088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_3091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_3092 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3093 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3094 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_3095 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c300, cp_2 = c300_p_1, cp_1 = c300_p_0, cp_0 = 0;
										c < c300 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3080);
										mem_vec_3080 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3081);
										mem_vec_3081 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3082);
										mem_vec_3082 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3083);
										mem_vec_3083 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3084);
										mem_vec_3084 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3085);
										mem_vec_3085 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3086);
										mem_vec_3086 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3087);
										mem_vec_3087 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3088);
										mem_vec_3088 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3089);
										mem_vec_3089 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3090);
										mem_vec_3090 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3091);
										mem_vec_3091 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3092);
										mem_vec_3092 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3093);
										mem_vec_3093 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3094);
										mem_vec_3094 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3095);
										mem_vec_3095 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3080);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3081);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3082);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3083);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3084);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3085);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3086);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3087);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3088);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3089);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3090);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3091);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3092);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3093);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3094);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3095);
						}
					}
				}
			}
		}
	}
	for (y225 = y226 + 12, y225_p_0 = 0;
		y225 < y226 + 12 + 5;
		y225 += 5, y225_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 1) (1024 / 1024)
		for (c301 = c302, c301_p_0 = 0;
			c301 < c302 + 1024;
			c301 += 1024, c301_p_0 += 1024){
			// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
			// T (f, 8) (512 / 64)
			for (f = f150, fp_0 = 0;
				f < f150 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y225, yp_1 = y225_p_0, yp_0 = 0;
					y < y225 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 16) (1024 / 64)
					for (c300 = c301, c300_p_1 = c301_p_0, c300_p_0 = 0;
						c300 < c301 + 1024;
						c300 += 64, c300_p_1 += 64, c300_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x150, xp_0 = 0;
							x < x150 + 17;
							x += 1, xp_0 += 1){
									mem_vec_3096 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3097 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3098 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3099 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_3104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_3107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_3108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_3109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_3110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_3111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_3112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_3113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_3114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_3115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c300, cp_2 = c300_p_1, cp_1 = c300_p_0, cp_0 = 0;
										c < c300 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3096);
										mem_vec_3096 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3097);
										mem_vec_3097 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3098);
										mem_vec_3098 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3099);
										mem_vec_3099 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3100);
										mem_vec_3100 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3101);
										mem_vec_3101 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3102);
										mem_vec_3102 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3103);
										mem_vec_3103 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3104);
										mem_vec_3104 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3105);
										mem_vec_3105 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3106);
										mem_vec_3106 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3107);
										mem_vec_3107 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3108);
										mem_vec_3108 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3109);
										mem_vec_3109 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3110);
										mem_vec_3110 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3111);
										mem_vec_3111 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3112);
										mem_vec_3112 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3113);
										mem_vec_3113 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3114);
										mem_vec_3114 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3115);
										mem_vec_3115 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3096);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3097);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3098);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3099);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3100);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3101);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3102);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3103);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3104);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3105);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3106);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3107);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3108);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3109);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3110);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3111);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3112);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3113);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3114);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3115);
						}
					}
				}
			}
		}
	}


}