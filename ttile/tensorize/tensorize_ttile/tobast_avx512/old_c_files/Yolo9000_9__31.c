#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (8, c); Hoist_vars [c]; T (34, x); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 13)); ((Iter 3), (Arg 14))]; T (4, f);
  T (32, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1134_p_0, cp_1, c1134, f, fp_0, x, xp_0, x1512_p_0, x1513_p_0, xp_1, x1512_p_1, xp_2, x1512, x1513, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y756 = 0;
IND_TYPE x1514 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1135 = 0;
IND_TYPE f756 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_15252 ,mem_vec_15253 ,mem_vec_15254 ,mem_vec_15255 ,mem_vec_15256 ,mem_vec_15257 ,mem_vec_15258 ,mem_vec_15259 ,mem_vec_15260 ,mem_vec_15261 ,mem_vec_15262 ,mem_vec_15263 ,mem_vec_15264 ,mem_vec_15265 ,mem_vec_15266 ,mem_vec_15267 ,mem_vec_15268 ,mem_vec_15269 ,mem_vec_15270 ,mem_vec_15271 ,mem_vec_15272 ,mem_vec_15273 ,mem_vec_15274 ,mem_vec_15275 ,mem_vec_15276 ,mem_vec_15277 ,mem_vec_15278 ,mem_vec_15279 ,mem_vec_15280 ,mem_vec_15281 ,mem_vec_15282 ,mem_vec_15283 ,mem_vec_15284 ,mem_vec_15285 ,mem_vec_15286 ,mem_vec_15287 ,mem_vec_15288 ,mem_vec_15289 ,mem_vec_15290 ,mem_vec_15291 ,mem_vec_15292 ,mem_vec_15293 ,mem_vec_15294 ,mem_vec_15295 ,mem_vec_15296 ,mem_vec_15297 ,mem_vec_15298 ,mem_vec_15299 ,mem_vec_15300 ,mem_vec_15301 ,mem_vec_15302 ,mem_vec_15303 ,mem_vec_15304 ,mem_vec_15305 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 2) (68 / 34)
for (x1513 = x1514, x1513_p_0 = 0;
	x1513 < x1514 + 68;
	x1513 += 34, x1513_p_0 += 34){
	// y = 68, x = 34, h = 1, w = 1, c = 256, f = 128
	// T (c, 32) (256 / 8)
	for (c1134 = c1135, c1134_p_0 = 0;
		c1134 < c1135 + 256;
		c1134 += 8, c1134_p_0 += 8){
		// y = 68, x = 34, h = 1, w = 1, c = 8, f = 128
		// T (f, 4) (128 / 32)
		for (f = f756, fp_0 = 0;
			f < f756 + 128;
			f += 32, fp_0 += 32){
				for (y = y756, yp_0 = 0;
					y < y756 + 26;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
					// T (x, 1) (34 / 34)
					for (x1512 = x1513, x1512_p_1 = x1513_p_0, x1512_p_0 = 0;
						x1512 < x1513 + 34;
						x1512 += 34, x1512_p_1 += 34, x1512_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
						// T (x, 34) (34 / 1)
						for (x = x1512, xp_2 = x1512_p_1, xp_1 = x1512_p_0, xp_0 = 0;
							x < x1512 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_15267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_15268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_15269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_15270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_15271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_15272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_15273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_15274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_15275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_15276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_15277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c1134, cp_1 = c1134_p_0, cp_0 = 0;
										c < c1134 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15252);
										mem_vec_15252 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15253);
										mem_vec_15253 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_15254);
										mem_vec_15254 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_15255);
										mem_vec_15255 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_15256);
										mem_vec_15256 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_15257);
										mem_vec_15257 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_15258);
										mem_vec_15258 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_15259);
										mem_vec_15259 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15260);
										mem_vec_15260 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15261);
										mem_vec_15261 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_15262);
										mem_vec_15262 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_15263);
										mem_vec_15263 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_15264);
										mem_vec_15264 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_15265);
										mem_vec_15265 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_15266);
										mem_vec_15266 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_15267);
										mem_vec_15267 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_15268);
										mem_vec_15268 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_15269);
										mem_vec_15269 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15270);
										mem_vec_15270 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15271);
										mem_vec_15271 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_15272);
										mem_vec_15272 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_15273);
										mem_vec_15273 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_15274);
										mem_vec_15274 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_15275);
										mem_vec_15275 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_15276);
										mem_vec_15276 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_15277);
										mem_vec_15277 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15252);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15253);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15254);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15255);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15256);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15257);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15258);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15259);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15260);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15261);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15262);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15263);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15264);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15265);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_15266);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_15267);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_15268);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_15269);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_15270);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_15271);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_15272);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_15273);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_15274);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_15275);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_15276);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_15277);
						}
					}
				}
				for (y = y756 + 26, yp_0 = 0;
					y < y756 + 26 + 42;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
					// T (x, 1) (34 / 34)
					for (x1512 = x1513, x1512_p_1 = x1513_p_0, x1512_p_0 = 0;
						x1512 < x1513 + 34;
						x1512 += 34, x1512_p_1 += 34, x1512_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 8, f = 32
						// T (x, 34) (34 / 1)
						for (x = x1512, xp_2 = x1512_p_1, xp_1 = x1512_p_0, xp_0 = 0;
							x < x1512 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15278 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15279 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_15293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_15294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_15295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_15296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_15297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_15298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_15299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_15300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_15301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_15302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_15303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_15304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_15305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 32
									// T (c, 8) (8 / 1)
									for (c = c1134, cp_1 = c1134_p_0, cp_0 = 0;
										c < c1134 + 8;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15278);
										mem_vec_15278 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15279);
										mem_vec_15279 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_15280);
										mem_vec_15280 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_15281);
										mem_vec_15281 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_15282);
										mem_vec_15282 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_15283);
										mem_vec_15283 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_15284);
										mem_vec_15284 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_15285);
										mem_vec_15285 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15286);
										mem_vec_15286 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15287);
										mem_vec_15287 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_15288);
										mem_vec_15288 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_15289);
										mem_vec_15289 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_15290);
										mem_vec_15290 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_15291);
										mem_vec_15291 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_15292);
										mem_vec_15292 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_15293);
										mem_vec_15293 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_15294);
										mem_vec_15294 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_15295);
										mem_vec_15295 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15296);
										mem_vec_15296 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15297);
										mem_vec_15297 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_15298);
										mem_vec_15298 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_15299);
										mem_vec_15299 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_15300);
										mem_vec_15300 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_15301);
										mem_vec_15301 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_15302);
										mem_vec_15302 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_15303);
										mem_vec_15303 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_15304);
										mem_vec_15304 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_15305);
										mem_vec_15305 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15278);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15279);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15280);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15281);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15282);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15283);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15284);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15285);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15286);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15287);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15288);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15289);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15290);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15291);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_15292);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_15293);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_15294);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_15295);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_15296);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_15297);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_15298);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_15299);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_15300);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_15301);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_15302);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_15303);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_15304);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_15305);
						}
					}
				}
		}
	}
}


}