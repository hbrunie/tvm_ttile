#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (2, x); T (17, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 1), (Arg 14))]; T (8, f);
  T (128, c); T (1, x)]
*/
IND_TYPE c, cp_0, c624_p_0, cp_1, c624, f, fp_0, x, xp_0, x832_p_0, x833_p_0, xp_1, x832_p_1, xp_2, x832, x833, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y416 = 0;
IND_TYPE x834 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c625 = 0;
IND_TYPE f416 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_8192 ,mem_vec_8193 ,mem_vec_8194 ,mem_vec_8195 ,mem_vec_8196 ,mem_vec_8197 ,mem_vec_8198 ,mem_vec_8199 ,mem_vec_8200 ,mem_vec_8201 ,mem_vec_8202 ,mem_vec_8203 ,mem_vec_8204 ,mem_vec_8205 ,mem_vec_8206 ,mem_vec_8207 ,mem_vec_8208 ,mem_vec_8209 ,mem_vec_8210 ,mem_vec_8211 ,mem_vec_8212 ,mem_vec_8213 ,mem_vec_8214 ,mem_vec_8215 ,mem_vec_8216 ,mem_vec_8217 ,mem_vec_8218 ,mem_vec_8219 ,mem_vec_8220 ,mem_vec_8221 ,mem_vec_8222 ,mem_vec_8223 ,mem_vec_8224 ,mem_vec_8225 ,mem_vec_8226 ,mem_vec_8227 ,mem_vec_8228 ,mem_vec_8229 ,mem_vec_8230 ,mem_vec_8231 ,mem_vec_8232 ,mem_vec_8233 ,mem_vec_8234 ,mem_vec_8235 ,mem_vec_8236 ,mem_vec_8237 ,mem_vec_8238 ,mem_vec_8239 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x833 = x834, x833_p_0 = 0;
	x833 < x834 + 34;
	x833 += 34, x833_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 128) (512 / 4)
	for (c624 = c625, c624_p_0 = 0;
		c624 < c625 + 512;
		c624 += 4, c624_p_0 += 4){
		// y = 34, x = 34, h = 1, w = 1, c = 4, f = 256
		// T (f, 8) (256 / 32)
		for (f = f416, fp_0 = 0;
			f < f416 + 256;
			f += 32, fp_0 += 32){
				for (y = y416, yp_0 = 0;
					y < y416 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (34 / 2)
					for (x832 = x833, x832_p_1 = x833_p_0, x832_p_0 = 0;
						x832 < x833 + 34;
						x832 += 2, x832_p_1 += 2, x832_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
						// T (x, 2) (2 / 1)
						for (x = x832, xp_2 = x832_p_1, xp_1 = x832_p_0, xp_0 = 0;
							x < x832 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8192 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8193 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_8208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_8209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_8210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_8211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c624, cp_1 = c624_p_0, cp_0 = 0;
										c < c624 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8192);
										mem_vec_8192 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8193);
										mem_vec_8193 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8194);
										mem_vec_8194 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8195);
										mem_vec_8195 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8196);
										mem_vec_8196 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8197);
										mem_vec_8197 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8198);
										mem_vec_8198 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8199);
										mem_vec_8199 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8200);
										mem_vec_8200 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8201);
										mem_vec_8201 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8202);
										mem_vec_8202 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8203);
										mem_vec_8203 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8204);
										mem_vec_8204 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8205);
										mem_vec_8205 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8206);
										mem_vec_8206 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8207);
										mem_vec_8207 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8208);
										mem_vec_8208 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8209);
										mem_vec_8209 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8210);
										mem_vec_8210 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8211);
										mem_vec_8211 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8195);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8196);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8197);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8199);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8200);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8201);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8202);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8203);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8204);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8205);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8206);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8207);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8208);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8209);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8210);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8211);
						}
					}
				}
				for (y = y416 + 20, yp_0 = 0;
					y < y416 + 20 + 14;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 34, h = 1, w = 1, c = 4, f = 32
					// T (x, 17) (34 / 2)
					for (x832 = x833, x832_p_1 = x833_p_0, x832_p_0 = 0;
						x832 < x833 + 34;
						x832 += 2, x832_p_1 += 2, x832_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
						// T (x, 2) (2 / 1)
						for (x = x832, xp_2 = x832_p_1, xp_1 = x832_p_0, xp_0 = 0;
							x < x832 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_8212 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_8213 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_8214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_8215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_8216 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_8217 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_8218 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_8219 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_8220 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_8221 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_8222 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_8223 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_8224 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_8225 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_8226 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_8227 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_8228 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_8229 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_8230 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_8231 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_8232 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_8233 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_8234 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_8235 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_8236 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_8237 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_8238 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_8239 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
									// T (c, 4) (4 / 1)
									for (c = c624, cp_1 = c624_p_0, cp_0 = 0;
										c < c624 + 4;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8212);
										mem_vec_8212 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8213);
										mem_vec_8213 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8214);
										mem_vec_8214 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8215);
										mem_vec_8215 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8216);
										mem_vec_8216 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8217);
										mem_vec_8217 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8218);
										mem_vec_8218 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8219);
										mem_vec_8219 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8220);
										mem_vec_8220 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8221);
										mem_vec_8221 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8222);
										mem_vec_8222 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8223);
										mem_vec_8223 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8224);
										mem_vec_8224 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8225);
										mem_vec_8225 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8226);
										mem_vec_8226 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8227);
										mem_vec_8227 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8228);
										mem_vec_8228 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8229);
										mem_vec_8229 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_8230);
										mem_vec_8230 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_8231);
										mem_vec_8231 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_8232);
										mem_vec_8232 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_8233);
										mem_vec_8233 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_8234);
										mem_vec_8234 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_8235);
										mem_vec_8235 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_8236);
										mem_vec_8236 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_8237);
										mem_vec_8237 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_8238);
										mem_vec_8238 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_8239);
										mem_vec_8239 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8212);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8213);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8214);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8215);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8216);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8217);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8218);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8219);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8220);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8221);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8222);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8223);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8224);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8225);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8226);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8227);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8228);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8229);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_8230);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_8231);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_8232);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_8233);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_8234);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_8235);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_8236);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_8237);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_8238);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_8239);
						}
					}
				}
		}
	}
}


}