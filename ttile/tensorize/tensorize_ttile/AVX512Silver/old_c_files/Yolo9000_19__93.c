#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (4, c);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]; T (8, f);
  T (4, c); T (1, y)]
*/
IND_TYPE c, cp_0, c416_p_0, c417_p_0, cp_1, c416_p_1, cp_2, c416, c417, f, fp_0, x, xp_0, y, yp_0, y312_p_0, yp_1, y312;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y313 = 0;
IND_TYPE x208 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c418 = 0;
IND_TYPE f208 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_4120 ,mem_vec_4121 ,mem_vec_4122 ,mem_vec_4123 ,mem_vec_4124 ,mem_vec_4125 ,mem_vec_4126 ,mem_vec_4127 ,mem_vec_4128 ,mem_vec_4129 ,mem_vec_4130 ,mem_vec_4131 ,mem_vec_4132 ,mem_vec_4133 ,mem_vec_4134 ,mem_vec_4135 ,mem_vec_4136 ,mem_vec_4137 ,mem_vec_4138 ,mem_vec_4139 ,mem_vec_4140 ,mem_vec_4141 ,mem_vec_4142 ,mem_vec_4143 ,mem_vec_4144 ,mem_vec_4145 ,mem_vec_4146 ,mem_vec_4147 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (y, 1) (17 / 17)
for (y312 = y313, y312_p_0 = 0;
	y312 < y313 + 17;
	y312 += 17, y312_p_0 += 17){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
	// T (c, 4) (1024 / 256)
	for (c417 = c418, c417_p_0 = 0;
		c417 < c418 + 1024;
		c417 += 256, c417_p_0 += 256){
		// y = 17, x = 17, h = 1, w = 1, c = 256, f = 512
		// T (f, 8) (512 / 64)
		for (f = f208, fp_0 = 0;
			f < f208 + 512;
			f += 64, fp_0 += 64){
				for (y = y312, yp_1 = y312_p_0, yp_0 = 0;
					y < y312 + 9;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 4) (256 / 64)
					for (c416 = c417, c416_p_1 = c417_p_0, c416_p_0 = 0;
						c416 < c417 + 256;
						c416 += 64, c416_p_1 += 64, c416_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x208, xp_0 = 0;
							x < x208 + 17;
							x += 1, xp_0 += 1){
									mem_vec_4120 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4121 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4122 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4123 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4124 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4125 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4126 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4127 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4128 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4129 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4130 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4131 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c416, cp_2 = c416_p_1, cp_1 = c416_p_0, cp_0 = 0;
										c < c416 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4120);
										mem_vec_4120 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4121);
										mem_vec_4121 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4122);
										mem_vec_4122 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4123);
										mem_vec_4123 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4124);
										mem_vec_4124 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4125);
										mem_vec_4125 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4126);
										mem_vec_4126 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4127);
										mem_vec_4127 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4128);
										mem_vec_4128 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4129);
										mem_vec_4129 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4130);
										mem_vec_4130 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4131);
										mem_vec_4131 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4120);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4121);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4122);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4123);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4124);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4125);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4126);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4127);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4128);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4129);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4130);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4131);
						}
					}
				}
				for (y = y312 + 9, yp_1 = y312_p_0, yp_0 = 0;
					y < y312 + 9 + 8;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 4) (256 / 64)
					for (c416 = c417, c416_p_1 = c417_p_0, c416_p_0 = 0;
						c416 < c417 + 256;
						c416 += 64, c416_p_1 += 64, c416_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x208, xp_0 = 0;
							x < x208 + 17;
							x += 1, xp_0 += 1){
									mem_vec_4132 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4133 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4134 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_4135 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_4136 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4137 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4138 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_4139 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4140 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4141 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4142 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4143 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_4144 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4145 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4146 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_4147 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c416, cp_2 = c416_p_1, cp_1 = c416_p_0, cp_0 = 0;
										c < c416 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4132);
										mem_vec_4132 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4133);
										mem_vec_4133 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4134);
										mem_vec_4134 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4135);
										mem_vec_4135 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4136);
										mem_vec_4136 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4137);
										mem_vec_4137 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4138);
										mem_vec_4138 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4139);
										mem_vec_4139 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4140);
										mem_vec_4140 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4141);
										mem_vec_4141 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4142);
										mem_vec_4142 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4143);
										mem_vec_4143 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4144);
										mem_vec_4144 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4145);
										mem_vec_4145 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4146);
										mem_vec_4146 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4147);
										mem_vec_4147 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4132);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4133);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4134);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4135);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4136);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4137);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4138);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4139);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4140);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4141);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4142);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4143);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4144);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4145);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4146);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4147);
						}
					}
				}
		}
	}
}


}