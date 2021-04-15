#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (64, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1092_p_0, cp_1, c1092, f, fp_0, x, xp_0, x1456_p_0, x1457_p_0, xp_1, x1456_p_1, xp_2, x1456, x1457, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y728 = 0;
IND_TYPE x1458 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1093 = 0;
IND_TYPE f728 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_15208 ,mem_vec_15209 ,mem_vec_15210 ,mem_vec_15211 ,mem_vec_15212 ,mem_vec_15213 ,mem_vec_15214 ,mem_vec_15215 ,mem_vec_15216 ,mem_vec_15217 ,mem_vec_15218 ,mem_vec_15219 ,mem_vec_15220 ,mem_vec_15221 ,mem_vec_15222 ,mem_vec_15223 ,mem_vec_15224 ,mem_vec_15225 ,mem_vec_15226 ,mem_vec_15227 ,mem_vec_15228 ,mem_vec_15229 ,mem_vec_15230 ,mem_vec_15231 ,mem_vec_15232 ,mem_vec_15233 ,mem_vec_15234 ,mem_vec_15235 ,mem_vec_15236 ,mem_vec_15237 ,mem_vec_15238 ,mem_vec_15239 ,mem_vec_15240 ,mem_vec_15241 ,mem_vec_15242 ,mem_vec_15243 ,mem_vec_15244 ,mem_vec_15245 ,mem_vec_15246 ,mem_vec_15247 ,mem_vec_15248 ,mem_vec_15249 ,mem_vec_15250 ,mem_vec_15251 ,mem_vec_15252 ,mem_vec_15253 ,mem_vec_15254 ,mem_vec_15255 ,mem_vec_15256 ,mem_vec_15257 ,mem_vec_15258 ,mem_vec_15259 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x1457 = x1458, x1457_p_0 = 0;
	x1457 < x1458 + 34;
	x1457 += 34, x1457_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 64) (512 / 8)
	for (c1092 = c1093, c1092_p_0 = 0;
		c1092 < c1093 + 512;
		c1092 += 8, c1092_p_0 += 8){
		// y = 34, x = 34, h = 1, w = 1, c = 8, f = 256
		// T (f, 4) (256 / 64)
		for (f = f728, fp_0 = 0;
			f < f728 + 256;
			f += 64, fp_0 += 64){
				for (y = y728, yp_0 = 0;
					y < y728 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 64
					// T (x, 34) (34 / 1)
					for (x1456 = x1457, x1456_p_1 = x1457_p_0, x1456_p_0 = 0;
						x1456 < x1457 + 34;
						x1456 += 1, x1456_p_1 += 1, x1456_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1456, xp_2 = x1456_p_1, xp_1 = x1456_p_0, xp_0 = 0;
							x < x1456 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15208 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15209 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15210 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15211 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_15212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_15215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_15216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_15219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_15220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_15223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_15224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_15227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_15228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_15231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1092, cp_1 = c1092_p_0, cp_0 = 0;
										c < c1092 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15208);
										mem_vec_15208 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15209);
										mem_vec_15209 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15210);
										mem_vec_15210 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15211);
										mem_vec_15211 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15212);
										mem_vec_15212 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15213);
										mem_vec_15213 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15214);
										mem_vec_15214 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15215);
										mem_vec_15215 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15216);
										mem_vec_15216 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15217);
										mem_vec_15217 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15218);
										mem_vec_15218 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15219);
										mem_vec_15219 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15220);
										mem_vec_15220 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15221);
										mem_vec_15221 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15222);
										mem_vec_15222 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15223);
										mem_vec_15223 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15224);
										mem_vec_15224 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15225);
										mem_vec_15225 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15226);
										mem_vec_15226 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15227);
										mem_vec_15227 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15228);
										mem_vec_15228 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15229);
										mem_vec_15229 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15230);
										mem_vec_15230 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15231);
										mem_vec_15231 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15208);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15209);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15210);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15211);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15212);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15213);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15214);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15215);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15216);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15217);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15218);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15219);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15220);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15221);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15222);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15223);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15224);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15225);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15226);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15227);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15228);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15229);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15230);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15231);
						}
					}
				}
				for (y = y728 + 6, yp_0 = 0;
					y < y728 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 64
					// T (x, 34) (34 / 1)
					for (x1456 = x1457, x1456_p_1 = x1457_p_0, x1456_p_0 = 0;
						x1456 < x1457 + 34;
						x1456 += 1, x1456_p_1 += 1, x1456_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1456, xp_2 = x1456_p_1, xp_1 = x1456_p_0, xp_0 = 0;
							x < x1456 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15232 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15233 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15234 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15235 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_15236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_15239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_15240 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15241 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15242 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_15243 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_15244 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15245 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15246 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_15247 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_15248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_15251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_15252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_15255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_15256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_15259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1092, cp_1 = c1092_p_0, cp_0 = 0;
										c < c1092 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15232);
										mem_vec_15232 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15233);
										mem_vec_15233 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15234);
										mem_vec_15234 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15235);
										mem_vec_15235 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15236);
										mem_vec_15236 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15237);
										mem_vec_15237 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15238);
										mem_vec_15238 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15239);
										mem_vec_15239 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15240);
										mem_vec_15240 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15241);
										mem_vec_15241 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15242);
										mem_vec_15242 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15243);
										mem_vec_15243 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15244);
										mem_vec_15244 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15245);
										mem_vec_15245 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15246);
										mem_vec_15246 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15247);
										mem_vec_15247 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15248);
										mem_vec_15248 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15249);
										mem_vec_15249 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15250);
										mem_vec_15250 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15251);
										mem_vec_15251 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15252);
										mem_vec_15252 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15253);
										mem_vec_15253 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15254);
										mem_vec_15254 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15255);
										mem_vec_15255 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_15256);
										mem_vec_15256 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_15257);
										mem_vec_15257 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_15258);
										mem_vec_15258 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_15259);
										mem_vec_15259 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15232);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15233);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15234);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15235);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15236);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15237);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15238);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15239);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15240);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15241);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15242);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15243);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15244);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15245);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15246);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15247);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15248);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15249);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15250);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15251);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_15258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_15259);
						}
					}
				}
		}
	}
}


}