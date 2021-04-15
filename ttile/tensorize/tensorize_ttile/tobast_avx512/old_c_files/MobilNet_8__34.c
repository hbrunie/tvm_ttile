#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (4, c); Hoist_vars [c]; T (7, x);
  T (3, w); T (8, c); T (8, f);
  Lambda_apply y [((Iter 2), (Arg 2)); ((Iter 1), (Arg 3))]; T (16, c)]
*/
IND_TYPE c, cp_0, c856_p_0, c857_p_0, cp_1, c856_p_1, cp_2, c856, c857, f, fp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y374 = 0;
IND_TYPE x512 = 0;
IND_TYPE h = 0;
IND_TYPE w376 = 0;
IND_TYPE c858 = 0;
IND_TYPE f680 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_4072 ,mem_vec_4073 ,mem_vec_4074 ,mem_vec_4075 ,mem_vec_4076 ,mem_vec_4077 ,mem_vec_4078 ,mem_vec_4079 ,mem_vec_4080 ,mem_vec_4081 ,mem_vec_4082 ,mem_vec_4083 ,mem_vec_4084 ,mem_vec_4085 ,mem_vec_4086 ,mem_vec_4087 ,mem_vec_4088 ,mem_vec_4089 ,mem_vec_4090 ,mem_vec_4091 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (c, 16) (512 / 32)
for (c857 = c858, c857_p_0 = 0;
	c857 < c858 + 512;
	c857 += 32, c857_p_0 += 32){
		for (y = y374, yp_0 = 0;
			y < y374 + 4;
			y += 2, yp_0 += 2){
			// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 512
			// T (f, 8) (512 / 64)
			for (f = f680, fp_0 = 0;
				f < f680 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
				// T (c, 8) (32 / 4)
				for (c856 = c857, c856_p_1 = c857_p_0, c856_p_0 = 0;
					c856 < c857 + 32;
					c856 += 4, c856_p_1 += 4, c856_p_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w376, wp_0 = 0;
						w < w376 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 64
						// T (x, 7) (7 / 1)
						for (x = x512, xp_0 = 0;
							x < x512 + 7;
							x += 1, xp_0 += 1){
									mem_vec_4072 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4073 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4074 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4075 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c856, cp_2 = c856_p_1, cp_1 = c856_p_0, cp_0 = 0;
										c < c856 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4072);
										mem_vec_4072 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4073);
										mem_vec_4073 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4074);
										mem_vec_4074 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4075);
										mem_vec_4075 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4076);
										mem_vec_4076 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4077);
										mem_vec_4077 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4078);
										mem_vec_4078 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4079);
										mem_vec_4079 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_15 = _mm512_set1_ps(scal_2);
										vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_4072);
										mem_vec_4072 = vec_14;

										vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_4073);
										mem_vec_4073 = vec_17;

										vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_4074);
										mem_vec_4074 = vec_19;

										vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_4075);
										mem_vec_4075 = vec_21;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_24 = _mm512_set1_ps(scal_3);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_4076);
										mem_vec_4076 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_4077);
										mem_vec_4077 = vec_25;



										vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_4078);
										mem_vec_4078 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_4079);
										mem_vec_4079 = vec_27;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_29 = _mm512_set1_ps(scal_4);
										vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_4072);
										mem_vec_4072 = vec_28;

										vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_4073);
										mem_vec_4073 = vec_31;

										vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_4074);
										mem_vec_4074 = vec_33;

										vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_4075);
										mem_vec_4075 = vec_35;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_38 = _mm512_set1_ps(scal_5);


										vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_4076);
										mem_vec_4076 = vec_37;



										vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_4077);
										mem_vec_4077 = vec_39;



										vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_4078);
										mem_vec_4078 = vec_40;



										vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_4079);
										mem_vec_4079 = vec_41;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4072);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4073);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4074);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4075);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4076);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4077);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4078);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4079);
						}
					}
				}
			}
		}
		for (y = y374 + 4, yp_0 = 0;
			y < y374 + 4 + 3;
			y += 3, yp_0 += 3){
			// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 512
			// T (f, 8) (512 / 64)
			for (f = f680, fp_0 = 0;
				f < f680 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 7, h = 3, w = 3, c = 32, f = 64
				// T (c, 8) (32 / 4)
				for (c856 = c857, c856_p_1 = c857_p_0, c856_p_0 = 0;
					c856 < c857 + 32;
					c856 += 4, c856_p_1 += 4, c856_p_0 += 4){
					// y = ph_y, x = 7, h = 3, w = 3, c = 4, f = 64
					// T (w, 3) (3 / 1)
					for (w = w376, wp_0 = 0;
						w < w376 + 3;
						w += 1, wp_0 += 1){
						// y = ph_y, x = 7, h = 3, w = 1, c = 4, f = 64
						// T (x, 7) (7 / 1)
						for (x = x512, xp_0 = 0;
							x < x512 + 7;
							x += 1, xp_0 += 1){
									mem_vec_4080 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4081 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4082 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4083 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 3, w = 1, c = 4, f = 64
									// T (c, 4) (4 / 1)
									for (c = c856, cp_2 = c856_p_1, cp_1 = c856_p_0, cp_0 = 0;
										c < c856 + 4;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4080);
										mem_vec_4080 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4081);
										mem_vec_4081 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4082);
										mem_vec_4082 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4083);
										mem_vec_4083 = vec_7;
										scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4084);
										mem_vec_4084 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4085);
										mem_vec_4085 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4086);
										mem_vec_4086 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4087);
										mem_vec_4087 = vec_13;
										scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4088);
										mem_vec_4088 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4089);
										mem_vec_4089 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4090);
										mem_vec_4090 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4091);
										mem_vec_4091 = vec_18;
										scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
										vec_20 = _mm512_set1_ps(scal_3);
										vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_19 = _mm512_fmadd_ps(vec_20, vec_21, mem_vec_4080);
										mem_vec_4080 = vec_19;

										vec_23 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_22 = _mm512_fmadd_ps(vec_20, vec_23, mem_vec_4081);
										mem_vec_4081 = vec_22;

										vec_25 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

										vec_24 = _mm512_fmadd_ps(vec_20, vec_25, mem_vec_4082);
										mem_vec_4082 = vec_24;

										vec_27 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

										vec_26 = _mm512_fmadd_ps(vec_20, vec_27, mem_vec_4083);
										mem_vec_4083 = vec_26;
										scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
										vec_29 = _mm512_set1_ps(scal_4);


										vec_28 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_4084);
										mem_vec_4084 = vec_28;



										vec_30 = _mm512_fmadd_ps(vec_29, vec_23, mem_vec_4085);
										mem_vec_4085 = vec_30;



										vec_31 = _mm512_fmadd_ps(vec_29, vec_25, mem_vec_4086);
										mem_vec_4086 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_29, vec_27, mem_vec_4087);
										mem_vec_4087 = vec_32;
										scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
										vec_34 = _mm512_set1_ps(scal_5);


										vec_33 = _mm512_fmadd_ps(vec_34, vec_21, mem_vec_4088);
										mem_vec_4088 = vec_33;



										vec_35 = _mm512_fmadd_ps(vec_34, vec_23, mem_vec_4089);
										mem_vec_4089 = vec_35;



										vec_36 = _mm512_fmadd_ps(vec_34, vec_25, mem_vec_4090);
										mem_vec_4090 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_34, vec_27, mem_vec_4091);
										mem_vec_4091 = vec_37;
										scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
										vec_39 = _mm512_set1_ps(scal_6);
										vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_38 = _mm512_fmadd_ps(vec_39, vec_40, mem_vec_4080);
										mem_vec_4080 = vec_38;

										vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_41 = _mm512_fmadd_ps(vec_39, vec_42, mem_vec_4081);
										mem_vec_4081 = vec_41;

										vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

										vec_43 = _mm512_fmadd_ps(vec_39, vec_44, mem_vec_4082);
										mem_vec_4082 = vec_43;

										vec_46 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

										vec_45 = _mm512_fmadd_ps(vec_39, vec_46, mem_vec_4083);
										mem_vec_4083 = vec_45;
										scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
										vec_48 = _mm512_set1_ps(scal_7);


										vec_47 = _mm512_fmadd_ps(vec_48, vec_40, mem_vec_4084);
										mem_vec_4084 = vec_47;



										vec_49 = _mm512_fmadd_ps(vec_48, vec_42, mem_vec_4085);
										mem_vec_4085 = vec_49;



										vec_50 = _mm512_fmadd_ps(vec_48, vec_44, mem_vec_4086);
										mem_vec_4086 = vec_50;



										vec_51 = _mm512_fmadd_ps(vec_48, vec_46, mem_vec_4087);
										mem_vec_4087 = vec_51;
										scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
										vec_53 = _mm512_set1_ps(scal_8);


										vec_52 = _mm512_fmadd_ps(vec_53, vec_40, mem_vec_4088);
										mem_vec_4088 = vec_52;



										vec_54 = _mm512_fmadd_ps(vec_53, vec_42, mem_vec_4089);
										mem_vec_4089 = vec_54;



										vec_55 = _mm512_fmadd_ps(vec_53, vec_44, mem_vec_4090);
										mem_vec_4090 = vec_55;



										vec_56 = _mm512_fmadd_ps(vec_53, vec_46, mem_vec_4091);
										mem_vec_4091 = vec_56;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4080);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4081);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4082);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4083);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4084);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4085);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4086);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4087);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4088);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4089);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4090);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4091);
						}
					}
				}
			}
		}
}


}