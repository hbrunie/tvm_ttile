#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (1, c); Hoist_vars [c]; T (4, x); T (17, x);
  Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))]; T (4, f);
  T (256, c); T (1, x)]
*/
IND_TYPE c, cp_0, c894_p_0, cp_1, c894, f, fp_0, x, xp_0, x1192_p_0, x1193_p_0, xp_1, x1192_p_1, xp_2, x1192, x1193, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y596 = 0;
IND_TYPE x1194 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c895 = 0;
IND_TYPE f596 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_11168 ,mem_vec_11169 ,mem_vec_11170 ,mem_vec_11171 ,mem_vec_11172 ,mem_vec_11173 ,mem_vec_11174 ,mem_vec_11175 ,mem_vec_11176 ,mem_vec_11177 ,mem_vec_11178 ,mem_vec_11179 ,mem_vec_11180 ,mem_vec_11181 ,mem_vec_11182 ,mem_vec_11183 ,mem_vec_11184 ,mem_vec_11185 ,mem_vec_11186 ,mem_vec_11187 ,mem_vec_11188 ,mem_vec_11189 ,mem_vec_11190 ,mem_vec_11191 ,mem_vec_11192 ,mem_vec_11193 ,mem_vec_11194 ,mem_vec_11195 ,mem_vec_11196 ,mem_vec_11197 ,mem_vec_11198 ,mem_vec_11199 ,mem_vec_11200 ,mem_vec_11201 ,mem_vec_11202 ,mem_vec_11203 ,mem_vec_11204 ,mem_vec_11205 ,mem_vec_11206 ,mem_vec_11207 ,mem_vec_11208 ,mem_vec_11209 ,mem_vec_11210 ,mem_vec_11211 ,mem_vec_11212 ,mem_vec_11213 ,mem_vec_11214 ,mem_vec_11215 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 1) (68 / 68)
for (x1193 = x1194, x1193_p_0 = 0;
	x1193 < x1194 + 68;
	x1193 += 68, x1193_p_0 += 68){
	// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (c, 256) (256 / 1)
	for (c894 = c895, c894_p_0 = 0;
		c894 < c895 + 256;
		c894 += 1, c894_p_0 += 1){
		// y = 68, x = 68, h = 1, w = 1, c = 1, f = 128
		// T (f, 4) (128 / 32)
		for (f = f596, fp_0 = 0;
			f < f596 + 128;
			f += 32, fp_0 += 32){
				for (y = y596, yp_0 = 0;
					y < y596 + 55;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 68, h = 1, w = 1, c = 1, f = 32
					// T (x, 17) (68 / 4)
					for (x1192 = x1193, x1192_p_1 = x1193_p_0, x1192_p_0 = 0;
						x1192 < x1193 + 68;
						x1192 += 4, x1192_p_1 += 4, x1192_p_0 += 4){
						// y = ph_y, x = 4, h = 1, w = 1, c = 1, f = 32
						// T (x, 4) (4 / 1)
						for (x = x1192, xp_2 = x1192_p_1, xp_1 = x1192_p_0, xp_0 = 0;
							x < x1192 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11168 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11169 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_11183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_11184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_11185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_11186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_11187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_11188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_11189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c894, cp_1 = c894_p_0, cp_0 = 0;
										c < c894 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11168);
										mem_vec_11168 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11169);
										mem_vec_11169 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11170);
										mem_vec_11170 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11171);
										mem_vec_11171 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11172);
										mem_vec_11172 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11173);
										mem_vec_11173 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11174);
										mem_vec_11174 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11175);
										mem_vec_11175 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11176);
										mem_vec_11176 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11177);
										mem_vec_11177 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11178);
										mem_vec_11178 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11179);
										mem_vec_11179 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11180);
										mem_vec_11180 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11181);
										mem_vec_11181 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11182);
										mem_vec_11182 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11183);
										mem_vec_11183 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11184);
										mem_vec_11184 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11185);
										mem_vec_11185 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11186);
										mem_vec_11186 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11187);
										mem_vec_11187 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11188);
										mem_vec_11188 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11189);
										mem_vec_11189 = vec_34;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11168);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11169);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11170);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11171);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11172);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11173);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11174);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11175);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11176);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11179);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11180);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11181);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11182);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11183);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11184);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11185);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11186);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11187);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11188);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11189);
						}
					}
				}
				for (y = y596 + 55, yp_0 = 0;
					y < y596 + 55 + 13;
					y += 13, yp_0 += 13){
					// y = ph_y, x = 68, h = 1, w = 1, c = 1, f = 32
					// T (x, 17) (68 / 4)
					for (x1192 = x1193, x1192_p_1 = x1193_p_0, x1192_p_0 = 0;
						x1192 < x1193 + 68;
						x1192 += 4, x1192_p_1 += 4, x1192_p_0 += 4){
						// y = ph_y, x = 4, h = 1, w = 1, c = 1, f = 32
						// T (x, 4) (4 / 1)
						for (x = x1192, xp_2 = x1192_p_1, xp_1 = x1192_p_0, xp_0 = 0;
							x < x1192 + 4;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_11190 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_11191 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_11192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_11193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_11194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_11195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_11196 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_11197 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_11198 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_11199 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_11200 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_11201 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_11202 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_11203 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_11204 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_11205 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_11206 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_11207 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_11208 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_11209 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_11210 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_11211 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_11212 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_11213 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_11214 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_11215 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 1, f = 32
									// T (c, 1) (1 / 1)
									for (c = c894, cp_1 = c894_p_0, cp_0 = 0;
										c < c894 + 1;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_11190);
										mem_vec_11190 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_11191);
										mem_vec_11191 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_11192);
										mem_vec_11192 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_11193);
										mem_vec_11193 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_11194);
										mem_vec_11194 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_11195);
										mem_vec_11195 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_11196);
										mem_vec_11196 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_11197);
										mem_vec_11197 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_11198);
										mem_vec_11198 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_11199);
										mem_vec_11199 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_11200);
										mem_vec_11200 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_11201);
										mem_vec_11201 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_11202);
										mem_vec_11202 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_11203);
										mem_vec_11203 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_11204);
										mem_vec_11204 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_11205);
										mem_vec_11205 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_11206);
										mem_vec_11206 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_11207);
										mem_vec_11207 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_11208);
										mem_vec_11208 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_11209);
										mem_vec_11209 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_11210);
										mem_vec_11210 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_11211);
										mem_vec_11211 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_11212);
										mem_vec_11212 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_11213);
										mem_vec_11213 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_11214);
										mem_vec_11214 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_11215);
										mem_vec_11215 = vec_40;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11190);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11191);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11195);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11196);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11197);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11198);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11199);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11200);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11201);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11202);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11203);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_11204);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_11205);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_11206);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_11207);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_11208);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_11209);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_11210);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_11211);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_11212);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_11213);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_11214);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_11215);
						}
					}
				}
		}
	}
}


}