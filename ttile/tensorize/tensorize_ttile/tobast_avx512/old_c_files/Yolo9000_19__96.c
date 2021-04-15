#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (17, x); T (8, c);
  T (8, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (64, c)]
*/
IND_TYPE c, cp_0, c1104_p_0, c1105_p_0, cp_1, c1104_p_1, cp_2, c1104, c1105, f, fp_0, x, xp_0, x828_p_0, xp_1, x828, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y552 = 0;
IND_TYPE x829 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1106 = 0;
IND_TYPE f552 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_9240 ,mem_vec_9241 ,mem_vec_9242 ,mem_vec_9243 ,mem_vec_9244 ,mem_vec_9245 ,mem_vec_9246 ,mem_vec_9247 ,mem_vec_9248 ,mem_vec_9249 ,mem_vec_9250 ,mem_vec_9251 ,mem_vec_9252 ,mem_vec_9253 ,mem_vec_9254 ,mem_vec_9255 ,mem_vec_9256 ,mem_vec_9257 ,mem_vec_9258 ,mem_vec_9259 ,mem_vec_9260 ,mem_vec_9261 ,mem_vec_9262 ,mem_vec_9263 ,mem_vec_9264 ,mem_vec_9265 ,mem_vec_9266 ,mem_vec_9267 ,mem_vec_9268 ,mem_vec_9269 ,mem_vec_9270 ,mem_vec_9271 ,mem_vec_9272 ,mem_vec_9273 ,mem_vec_9274 ,mem_vec_9275 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 64) (1024 / 16)
for (c1105 = c1106, c1105_p_0 = 0;
	c1105 < c1106 + 1024;
	c1105 += 16, c1105_p_0 += 16){
		for (y = y552, yp_0 = 0;
			y < y552 + 12;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 512
			// T (x, 1) (17 / 17)
			for (x828 = x829, x828_p_0 = 0;
				x828 < x829 + 17;
				x828 += 17, x828_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 512
				// T (f, 8) (512 / 64)
				for (f = f552, fp_0 = 0;
					f < f552 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
					// T (c, 8) (16 / 2)
					for (c1104 = c1105, c1104_p_1 = c1105_p_0, c1104_p_0 = 0;
						c1104 < c1105 + 16;
						c1104 += 2, c1104_p_1 += 2, c1104_p_0 += 2){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 64
						// T (x, 17) (17 / 1)
						for (x = x828, xp_1 = x828_p_0, xp_0 = 0;
							x < x828 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9240 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9241 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9242 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9243 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1104, cp_2 = c1104_p_1, cp_1 = c1104_p_0, cp_0 = 0;
										c < c1104 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9240);
										mem_vec_9240 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9241);
										mem_vec_9241 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9242);
										mem_vec_9242 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9243);
										mem_vec_9243 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9244);
										mem_vec_9244 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9245);
										mem_vec_9245 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9246);
										mem_vec_9246 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9247);
										mem_vec_9247 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9248);
										mem_vec_9248 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9249);
										mem_vec_9249 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9250);
										mem_vec_9250 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9251);
										mem_vec_9251 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9252);
										mem_vec_9252 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9253);
										mem_vec_9253 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9254);
										mem_vec_9254 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9255);
										mem_vec_9255 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9240);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9241);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9242);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9243);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9244);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9245);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9246);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9247);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9251);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9255);
						}
					}
				}
			}
		}
		for (y = y552 + 12, yp_0 = 0;
			y < y552 + 12 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 512
			// T (x, 1) (17 / 17)
			for (x828 = x829, x828_p_0 = 0;
				x828 < x829 + 17;
				x828 += 17, x828_p_0 += 17){
				// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 512
				// T (f, 8) (512 / 64)
				for (f = f552, fp_0 = 0;
					f < f552 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
					// T (c, 8) (16 / 2)
					for (c1104 = c1105, c1104_p_1 = c1105_p_0, c1104_p_0 = 0;
						c1104 < c1105 + 16;
						c1104 += 2, c1104_p_1 += 2, c1104_p_0 += 2){
						// y = ph_y, x = 17, h = 1, w = 1, c = 2, f = 64
						// T (x, 17) (17 / 1)
						for (x = x828, xp_1 = x828_p_0, xp_0 = 0;
							x < x828 + 17;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_9256 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_9257 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_9258 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_9259 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_9260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_9261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_9262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_9263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_9264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_9265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_9266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_9267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_9268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_9269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_9270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_9271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_9272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_9273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_9274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_9275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
									// T (c, 2) (2 / 1)
									for (c = c1104, cp_2 = c1104_p_1, cp_1 = c1104_p_0, cp_0 = 0;
										c < c1104 + 2;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9256);
										mem_vec_9256 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9257);
										mem_vec_9257 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9258);
										mem_vec_9258 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9259);
										mem_vec_9259 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9260);
										mem_vec_9260 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9261);
										mem_vec_9261 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9262);
										mem_vec_9262 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9263);
										mem_vec_9263 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9264);
										mem_vec_9264 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9265);
										mem_vec_9265 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9266);
										mem_vec_9266 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9267);
										mem_vec_9267 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9268);
										mem_vec_9268 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9269);
										mem_vec_9269 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9270);
										mem_vec_9270 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9271);
										mem_vec_9271 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9272);
										mem_vec_9272 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9273);
										mem_vec_9273 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9274);
										mem_vec_9274 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9275);
										mem_vec_9275 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9271);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9275);
						}
					}
				}
			}
		}
}


}