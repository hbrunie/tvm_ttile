#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (17, x); T (64, c);
  Lambda_apply y [((Iter 4), (Arg 3)); ((Iter 1), (Arg 5))]; T (8, f);
  T (1, c); T (1, y)]
*/
IND_TYPE c, cp_0, c628_p_0, c629_p_0, cp_1, c628_p_1, cp_2, c628, c629, f, fp_0, x, xp_0, y, yp_0, y471_p_0, yp_1, y471;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y472 = 0;
IND_TYPE x314 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c630 = 0;
IND_TYPE f314 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_6144 ,mem_vec_6145 ,mem_vec_6146 ,mem_vec_6147 ,mem_vec_6148 ,mem_vec_6149 ,mem_vec_6150 ,mem_vec_6151 ,mem_vec_6152 ,mem_vec_6153 ,mem_vec_6154 ,mem_vec_6155 ,mem_vec_6156 ,mem_vec_6157 ,mem_vec_6158 ,mem_vec_6159 ,mem_vec_6160 ,mem_vec_6161 ,mem_vec_6162 ,mem_vec_6163 ,mem_vec_6164 ,mem_vec_6165 ,mem_vec_6166 ,mem_vec_6167 ,mem_vec_6168 ,mem_vec_6169 ,mem_vec_6170 ,mem_vec_6171 ,mem_vec_6172 ,mem_vec_6173 ,mem_vec_6174 ,mem_vec_6175 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y471 = y472, y471_p_0 = 0;
	y471 < y472 + 17;
	y471 += 17, y471_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 1) (1024 / 1024)
	for (c629 = c630, c629_p_0 = 0;
		c629 < c630 + 1024;
		c629 += 1024, c629_p_0 += 1024){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (f, 8) (512 / 64)
		for (f = f314, fp_0 = 0;
			f < f314 + 512;
			f += 64, fp_0 += 64){
				for (y = y471, yp_1 = y471_p_0, yp_0 = 0;
					y < y471 + 12;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 64) (1024 / 16)
					for (c628 = c629, c628_p_1 = c629_p_0, c628_p_0 = 0;
						c628 < c629 + 1024;
						c628 += 16, c628_p_1 += 16, c628_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x314, xp_0 = 0;
							x < x314 + 17;
							x += 1, xp_0 += 1){
									mem_vec_6144 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6145 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6146 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_6147 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_6148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_6151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_6152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_6155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c628, cp_2 = c628_p_1, cp_1 = c628_p_0, cp_0 = 0;
										c < c628 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6144);
										mem_vec_6144 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6145);
										mem_vec_6145 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6146);
										mem_vec_6146 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6147);
										mem_vec_6147 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6148);
										mem_vec_6148 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6149);
										mem_vec_6149 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6150);
										mem_vec_6150 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6151);
										mem_vec_6151 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6152);
										mem_vec_6152 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6153);
										mem_vec_6153 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6154);
										mem_vec_6154 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6155);
										mem_vec_6155 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6149);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6151);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6155);
						}
					}
				}
				for (y = y471 + 12, yp_1 = y471_p_0, yp_0 = 0;
					y < y471 + 12 + 5;
					y += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 64
					// T (c, 64) (1024 / 16)
					for (c628 = c629, c628_p_1 = c629_p_0, c628_p_0 = 0;
						c628 < c629 + 1024;
						c628 += 16, c628_p_1 += 16, c628_p_0 += 16){
						// y = ph_y, x = 17, h = 1, w = 1, c = 16, f = 64
						// T (x, 17) (17 / 1)
						for (x = x314, xp_0 = 0;
							x < x314 + 17;
							x += 1, xp_0 += 1){
									mem_vec_6156 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_6157 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_6158 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_6159 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_6160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_6161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_6162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_6163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_6164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_6165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_6166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_6167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_6168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_6169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_6170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_6171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_6172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_6173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_6174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_6175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 64
									// T (c, 16) (16 / 1)
									for (c = c628, cp_2 = c628_p_1, cp_1 = c628_p_0, cp_0 = 0;
										c < c628 + 16;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6156);
										mem_vec_6156 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6157);
										mem_vec_6157 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_6158);
										mem_vec_6158 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_6159);
										mem_vec_6159 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_6160);
										mem_vec_6160 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_6161);
										mem_vec_6161 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_6162);
										mem_vec_6162 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_6163);
										mem_vec_6163 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6164);
										mem_vec_6164 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6165);
										mem_vec_6165 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_6166);
										mem_vec_6166 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_6167);
										mem_vec_6167 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_6168);
										mem_vec_6168 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_6169);
										mem_vec_6169 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_6170);
										mem_vec_6170 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_6171);
										mem_vec_6171 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_6172);
										mem_vec_6172 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_6173);
										mem_vec_6173 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_6174);
										mem_vec_6174 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_6175);
										mem_vec_6175 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_6158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6159);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_6162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_6163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_6166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_6167);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6168);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6169);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_6170);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_6171);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6172);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6173);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_6174);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_6175);
						}
					}
				}
		}
	}
}


}