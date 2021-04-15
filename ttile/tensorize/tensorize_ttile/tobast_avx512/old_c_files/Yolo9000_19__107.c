#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (8, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (64, c)]
*/
IND_TYPE c, cp_0, c1568_p_0, c1569_p_0, cp_1, c1568_p_1, cp_2, c1568, c1569, f, fp_0, x, xp_0, x1176_p_0, xp_1, x1176, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y784 = 0;
IND_TYPE x1177 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1570 = 0;
IND_TYPE f784 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_14232 ,mem_vec_14233 ,mem_vec_14234 ,mem_vec_14235 ,mem_vec_14236 ,mem_vec_14237 ,mem_vec_14238 ,mem_vec_14239 ,mem_vec_14240 ,mem_vec_14241 ,mem_vec_14242 ,mem_vec_14243 ,mem_vec_14244 ,mem_vec_14245 ,mem_vec_14246 ,mem_vec_14247 ,mem_vec_14248 ,mem_vec_14249 ,mem_vec_14250 ,mem_vec_14251 ,mem_vec_14252 ,mem_vec_14253 ,mem_vec_14254 ,mem_vec_14255 ,mem_vec_14256 ,mem_vec_14257 ,mem_vec_14258 ,mem_vec_14259 ,mem_vec_14260 ,mem_vec_14261 ,mem_vec_14262 ,mem_vec_14263 ,mem_vec_14264 ,mem_vec_14265 ,mem_vec_14266 ,mem_vec_14267 ,mem_vec_14268 ,mem_vec_14269 ,mem_vec_14270 ,mem_vec_14271 ,mem_vec_14272 ,mem_vec_14273 ,mem_vec_14274 ,mem_vec_14275 ,mem_vec_14276 ,mem_vec_14277 ,mem_vec_14278 ,mem_vec_14279 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 64) (1024 / 16)
for (c1569 = c1570, c1569_p_0 = 0;
	c1569 < c1570 + 1024;
	c1569 += 16, c1569_p_0 += 16){
		for (y = y784, yp_0 = 0;
			y < y784 + 10;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 512
			// T (x, 17) (17 / 1)
			for (x1176 = x1177, x1176_p_0 = 0;
				x1176 < x1177 + 17;
				x1176 += 1, x1176_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 512
				// T (f, 8) (512 / 64)
				for (f = f784, fp_0 = 0;
					f < f784 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
					// T (c, 8) (16 / 2)
					for (c1568 = c1569, c1568_p_1 = c1569_p_0, c1568_p_0 = 0;
						c1568 < c1569 + 16;
						c1568 += 2, c1568_p_1 += 2, c1568_p_0 += 2){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1176, xp_1 = x1176_p_0, xp_0 = 0;
							x < x1176 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14232 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14233 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14234 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14235 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1568, cp_2 = c1568_p_1, cp_1 = c1568_p_0, cp_0 = 0;
										c < c1568 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14232);
										mem_vec_14232 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14233);
										mem_vec_14233 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14234);
										mem_vec_14234 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14235);
										mem_vec_14235 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14236);
										mem_vec_14236 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14237);
										mem_vec_14237 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14238);
										mem_vec_14238 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14239);
										mem_vec_14239 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14240);
										mem_vec_14240 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14241);
										mem_vec_14241 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14242);
										mem_vec_14242 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14243);
										mem_vec_14243 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14244);
										mem_vec_14244 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14245);
										mem_vec_14245 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14246);
										mem_vec_14246 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14247);
										mem_vec_14247 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14248);
										mem_vec_14248 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14249);
										mem_vec_14249 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14250);
										mem_vec_14250 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14251);
										mem_vec_14251 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14232);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14233);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14234);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14235);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14236);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14237);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14238);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14239);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14240);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14241);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14242);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14243);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14244);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14245);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14246);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14247);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14251);
						}
					}
				}
			}
		}
		for (y = y784 + 10, yp_0 = 0;
			y < y784 + 10 + 7;
			y += 7, yp_0 += 7){
			// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 512
			// T (x, 17) (17 / 1)
			for (x1176 = x1177, x1176_p_0 = 0;
				x1176 < x1177 + 17;
				x1176 += 1, x1176_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 512
				// T (f, 8) (512 / 64)
				for (f = f784, fp_0 = 0;
					f < f784 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
					// T (c, 8) (16 / 2)
					for (c1568 = c1569, c1568_p_1 = c1569_p_0, c1568_p_0 = 0;
						c1568 < c1569 + 16;
						c1568 += 2, c1568_p_1 += 2, c1568_p_0 += 2){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1176, xp_1 = x1176_p_0, xp_0 = 0;
							x < x1176 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_14252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_14253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_14254 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_14255 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_14256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_14257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_14258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_14259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_14260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_14261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_14262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_14263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_14264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_14265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_14266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_14267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_14268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_14269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_14270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_14271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_14272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_14273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_14274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_14275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_14276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_14277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_14278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_14279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1568, cp_2 = c1568_p_1, cp_1 = c1568_p_0, cp_0 = 0;
										c < c1568 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14252);
										mem_vec_14252 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14253);
										mem_vec_14253 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14254);
										mem_vec_14254 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14255);
										mem_vec_14255 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14256);
										mem_vec_14256 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14257);
										mem_vec_14257 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14258);
										mem_vec_14258 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14259);
										mem_vec_14259 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14260);
										mem_vec_14260 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14261);
										mem_vec_14261 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14262);
										mem_vec_14262 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14263);
										mem_vec_14263 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14264);
										mem_vec_14264 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14265);
										mem_vec_14265 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14266);
										mem_vec_14266 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14267);
										mem_vec_14267 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14268);
										mem_vec_14268 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14269);
										mem_vec_14269 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14270);
										mem_vec_14270 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14271);
										mem_vec_14271 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14272);
										mem_vec_14272 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14273);
										mem_vec_14273 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14274);
										mem_vec_14274 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14275);
										mem_vec_14275 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14276);
										mem_vec_14276 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14277);
										mem_vec_14277 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14278);
										mem_vec_14278 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14279);
										mem_vec_14279 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14271);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14277);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14279);
						}
					}
				}
			}
		}
}


}