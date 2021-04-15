#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (2, c); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (64, c)]
*/
IND_TYPE c, cp_0, c872_p_0, c873_p_0, cp_1, c872_p_1, cp_2, c872, c873, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y382 = 0;
IND_TYPE x520 = 0;
IND_TYPE h = 0;
IND_TYPE w384 = 0;
IND_TYPE c874 = 0;
IND_TYPE f688 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_4152 ,mem_vec_4153 ,mem_vec_4154 ,mem_vec_4155 ,mem_vec_4156 ,mem_vec_4157 ,mem_vec_4158 ,mem_vec_4159 ,mem_vec_4160 ,mem_vec_4161 ,mem_vec_4162 ,mem_vec_4163 ,mem_vec_4164 ,mem_vec_4165 ,mem_vec_4166 ,mem_vec_4167 ,mem_vec_4168 ,mem_vec_4169 ,mem_vec_4170 ,mem_vec_4171 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 64) (512 / 8)
for (c873 = c874, c873_p_0 = 0;
	c873 < c874 + 512;
	c873 += 8, c873_p_0 += 8){
		for (y = y382, yp_0 = 0;
			y < y382 + 4;
			y += 2, yp_0 += 2){
			// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 512
			// T (f, 8) (512 / 64)
			for (f = f688, fp_0 = 0;
				f < f688 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
				// T (c, 2) (8 / 4)
				for (c872 = c873, c872_p_1 = c873_p_0, c872_p_0 = 0;
					c872 < c873 + 8;
					c872 += 4, c872_p_1 += 4, c872_p_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w384, wp_0 = 0;
						w < w384 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 64
						// T (x, 7) (7 / 1)
						for (x = x520, xp_0 = 0;
							x < x520 + 7;
							x += 1, xp_0 += 1){
									mem_vec_4152 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4153 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4154 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4155 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4156 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4157 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4158 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4159 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c872, cp_2 = c872_p_1, cp_1 = c872_p_0, cp_0 = 0;
										c < c872 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4152);
										mem_vec_4152 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4153);
										mem_vec_4153 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4154);
										mem_vec_4154 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4155);
										mem_vec_4155 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4156);
										mem_vec_4156 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4157);
										mem_vec_4157 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4158);
										mem_vec_4158 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4159);
										mem_vec_4159 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_4152);
										mem_vec_4152 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_4153);
										mem_vec_4153 = vec_17;

										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_4154);
										mem_vec_4154 = vec_19;

										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_4155);
										mem_vec_4155 = vec_21;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_4156);
										mem_vec_4156 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_4157);
										mem_vec_4157 = vec_25;



										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_4158);
										mem_vec_4158 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_4159);
										mem_vec_4159 = vec_27;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_4152);
										mem_vec_4152 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_4153);
										mem_vec_4153 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_4154);
										mem_vec_4154 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_4155);
										mem_vec_4155 = vec_35;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_4156);
										mem_vec_4156 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_4157);
										mem_vec_4157 = vec_39;



										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4158);
										mem_vec_4158 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4159);
										mem_vec_4159 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4152);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4153);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4154);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4155);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4156);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4157);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4158);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4159);
						}
					}
				}
			}
		}
		for (y = y382 + 4, yp_0 = 0;
			y < y382 + 4 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 512
			// T (f, 8) (512 / 64)
			for (f = f688, fp_0 = 0;
				f < f688 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 8, f = 64
				// T (c, 2) (8 / 4)
				for (c872 = c873, c872_p_1 = c873_p_0, c872_p_0 = 0;
					c872 < c873 + 8;
					c872 += 4, c872_p_1 += 4, c872_p_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w384, wp_0 = 0;
						w < w384 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 64
						// T (x, 7) (7 / 1)
						for (x = x520, xp_0 = 0;
							x < x520 + 7;
							x += 1, xp_0 += 1){
									mem_vec_4160 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4161 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4162 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4163 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4164 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4165 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4166 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4167 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4168 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4169 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4170 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4171 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c872, cp_2 = c872_p_1, cp_1 = c872_p_0, cp_0 = 0;
										c < c872 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4160);
										mem_vec_4160 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4161);
										mem_vec_4161 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4162);
										mem_vec_4162 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4163);
										mem_vec_4163 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4164);
										mem_vec_4164 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4165);
										mem_vec_4165 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4166);
										mem_vec_4166 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4167);
										mem_vec_4167 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4168);
										mem_vec_4168 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4169);
										mem_vec_4169 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4170);
										mem_vec_4170 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4171);
										mem_vec_4171 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_4160);
										mem_vec_4160 = vec_19;

										vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_4161);
										mem_vec_4161 = vec_22;

										vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_4162);
										mem_vec_4162 = vec_24;

										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_4163);
										mem_vec_4163 = vec_26;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_4);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_4164);
										mem_vec_4164 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_4165);
										mem_vec_4165 = vec_30;



										vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_4166);
										mem_vec_4166 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4167);
										mem_vec_4167 = vec_32;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_4168);
										mem_vec_4168 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_4169);
										mem_vec_4169 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_4170);
										mem_vec_4170 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_4171);
										mem_vec_4171 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_39 = _mm512_set1_ps(scal_6);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_4160);
										mem_vec_4160 = vec_38;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_4161);
										mem_vec_4161 = vec_41;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_4162);
										mem_vec_4162 = vec_43;

										vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_4163);
										mem_vec_4163 = vec_45;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_7);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_4164);
										mem_vec_4164 = vec_47;



										vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_4165);
										mem_vec_4165 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_4166);
										mem_vec_4166 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_4167);
										mem_vec_4167 = vec_51;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_53 = _mm512_set1_ps(scal_8);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_4168);
										mem_vec_4168 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_4169);
										mem_vec_4169 = vec_54;



										vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_4170);
										mem_vec_4170 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_4171);
										mem_vec_4171 = vec_56;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4160);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4161);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4162);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4163);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4164);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4165);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4166);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4167);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4168);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4169);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4170);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4171);
						}
					}
				}
			}
		}
}


}