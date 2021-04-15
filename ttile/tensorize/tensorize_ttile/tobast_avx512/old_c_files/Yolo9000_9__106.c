#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (34, x); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]; T (4, f);
  T (1, c); T (2, x)]
*/
IND_TYPE c, cp_0, c1014_p_0, cp_1, c1014, f, fp_0, x, xp_0, x1352_p_0, x1353_p_0, xp_1, x1352_p_1, xp_2, x1352, x1353, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y676 = 0;
IND_TYPE x1354 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1015 = 0;
IND_TYPE f676 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_13144 ,mem_vec_13145 ,mem_vec_13146 ,mem_vec_13147 ,mem_vec_13148 ,mem_vec_13149 ,mem_vec_13150 ,mem_vec_13151 ,mem_vec_13152 ,mem_vec_13153 ,mem_vec_13154 ,mem_vec_13155 ,mem_vec_13156 ,mem_vec_13157 ,mem_vec_13158 ,mem_vec_13159 ,mem_vec_13160 ,mem_vec_13161 ,mem_vec_13162 ,mem_vec_13163 ,mem_vec_13164 ,mem_vec_13165 ,mem_vec_13166 ,mem_vec_13167 ,mem_vec_13168 ,mem_vec_13169 ,mem_vec_13170 ,mem_vec_13171 ,mem_vec_13172 ,mem_vec_13173 ,mem_vec_13174 ,mem_vec_13175 ,mem_vec_13176 ,mem_vec_13177 ,mem_vec_13178 ,mem_vec_13179 ,mem_vec_13180 ,mem_vec_13181 ,mem_vec_13182 ,mem_vec_13183 ,mem_vec_13184 ,mem_vec_13185 ,mem_vec_13186 ,mem_vec_13187 ,mem_vec_13188 ,mem_vec_13189 ,mem_vec_13190 ,mem_vec_13191 ,mem_vec_13192 ,mem_vec_13193 ,mem_vec_13194 ,mem_vec_13195 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (x, 2) (68 / 34)
for (x1353 = x1354, x1353_p_0 = 0;
	x1353 < x1354 + 68;
	x1353 += 34, x1353_p_0 += 34){
	// y = 68, x = 34, h = 1, w = 1, c = 256, f = 128
	// T (c, 1) (256 / 256)
	for (c1014 = c1015, c1014_p_0 = 0;
		c1014 < c1015 + 256;
		c1014 += 256, c1014_p_0 += 256){
		// y = 68, x = 34, h = 1, w = 1, c = 256, f = 128
		// T (f, 4) (128 / 32)
		for (f = f676, fp_0 = 0;
			f < f676 + 128;
			f += 32, fp_0 += 32){
				for (y = y676, yp_0 = 0;
					y < y676 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 32
					// T (x, 1) (34 / 34)
					for (x1352 = x1353, x1352_p_1 = x1353_p_0, x1352_p_0 = 0;
						x1352 < x1353 + 34;
						x1352 += 34, x1352_p_1 += 34, x1352_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 32
						// T (x, 34) (34 / 1)
						for (x = x1352, xp_2 = x1352_p_1, xp_1 = x1352_p_0, xp_0 = 0;
							x < x1352 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13144 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13145 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13148 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13149 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13150 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13151 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13152 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_13153 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_13154 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_13155 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_13156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_13157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_13158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_13159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_13160 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_13161 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_13162 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_13163 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_13164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_13165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_13166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_13167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c1014, cp_1 = c1014_p_0, cp_0 = 0;
										c < c1014 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13144);
										mem_vec_13144 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13145);
										mem_vec_13145 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13146);
										mem_vec_13146 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13147);
										mem_vec_13147 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13148);
										mem_vec_13148 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13149);
										mem_vec_13149 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13150);
										mem_vec_13150 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13151);
										mem_vec_13151 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13152);
										mem_vec_13152 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13153);
										mem_vec_13153 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13154);
										mem_vec_13154 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13155);
										mem_vec_13155 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13156);
										mem_vec_13156 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13157);
										mem_vec_13157 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13158);
										mem_vec_13158 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13159);
										mem_vec_13159 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13160);
										mem_vec_13160 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13161);
										mem_vec_13161 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13162);
										mem_vec_13162 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13163);
										mem_vec_13163 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13164);
										mem_vec_13164 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13165);
										mem_vec_13165 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13166);
										mem_vec_13166 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13167);
										mem_vec_13167 = vec_37;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13147);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13148);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13149);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13150);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13151);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13155);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13159);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13167);
						}
					}
				}
				for (y = y676 + 12, yp_0 = 0;
					y < y676 + 12 + 56;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 32
					// T (x, 1) (34 / 34)
					for (x1352 = x1353, x1352_p_1 = x1353_p_0, x1352_p_0 = 0;
						x1352 < x1353 + 34;
						x1352 += 34, x1352_p_1 += 34, x1352_p_0 += 34){
						// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 32
						// T (x, 34) (34 / 1)
						for (x = x1352, xp_2 = x1352_p_1, xp_1 = x1352_p_0, xp_0 = 0;
							x < x1352 + 34;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_13168 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_13169 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_13170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_13171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_13172 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_13173 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_13174 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_13175 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_13176 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_13177 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_13178 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_13179 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_13180 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_13181 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_13182 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_13183 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_13184 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_13185 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_13186 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_13187 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_13188 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_13189 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_13190 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_13191 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_13192 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_13193 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_13194 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_13195 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c1014, cp_1 = c1014_p_0, cp_0 = 0;
										c < c1014 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_13168);
										mem_vec_13168 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_13169);
										mem_vec_13169 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_13170);
										mem_vec_13170 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_13171);
										mem_vec_13171 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_13172);
										mem_vec_13172 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_13173);
										mem_vec_13173 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_13174);
										mem_vec_13174 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_13175);
										mem_vec_13175 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_13176);
										mem_vec_13176 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_13177);
										mem_vec_13177 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_13178);
										mem_vec_13178 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_13179);
										mem_vec_13179 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_13180);
										mem_vec_13180 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_13181);
										mem_vec_13181 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_13182);
										mem_vec_13182 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_13183);
										mem_vec_13183 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_13184);
										mem_vec_13184 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_13185);
										mem_vec_13185 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_13186);
										mem_vec_13186 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_13187);
										mem_vec_13187 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_13188);
										mem_vec_13188 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_13189);
										mem_vec_13189 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_13190);
										mem_vec_13190 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_13191);
										mem_vec_13191 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_13192);
										mem_vec_13192 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_13193);
										mem_vec_13193 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_13194);
										mem_vec_13194 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_13195);
										mem_vec_13195 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13168);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13169);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13170);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13171);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13172);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13173);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13174);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13175);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13176);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13177);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13178);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13179);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_13180);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_13181);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_13182);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_13183);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_13184);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_13185);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_13186);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_13187);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_13188);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_13189);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_13190);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_13191);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_13192);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_13193);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_13194);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_13195);
						}
					}
				}
		}
	}
}


}