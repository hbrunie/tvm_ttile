#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (64, c); Hoist_vars [c]; T (17, x); T (4, c);
  T (1, y); T (8, f); T (4, c);
  Lambda_apply y [((Iter 3), (Arg 3)); ((Iter 2), (Arg 4))]]
*/
IND_TYPE c, cp_0, c396_p_0, c397_p_0, cp_1, c396_p_1, cp_2, c396, c397, f, fp_0, x, xp_0, y, yp_0, y297_p_0, yp_1, y297;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y298 = 0;
IND_TYPE x198 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c398 = 0;
IND_TYPE f198 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_3980 ,mem_vec_3981 ,mem_vec_3982 ,mem_vec_3983 ,mem_vec_3984 ,mem_vec_3985 ,mem_vec_3986 ,mem_vec_3987 ,mem_vec_3988 ,mem_vec_3989 ,mem_vec_3990 ,mem_vec_3991 ,mem_vec_3992 ,mem_vec_3993 ,mem_vec_3994 ,mem_vec_3995 ,mem_vec_3996 ,mem_vec_3997 ,mem_vec_3998 ,mem_vec_3999 ,mem_vec_4000 ,mem_vec_4001 ,mem_vec_4002 ,mem_vec_4003 ,mem_vec_4004 ,mem_vec_4005 ,mem_vec_4006 ,mem_vec_4007 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y297 = y298, y297_p_0 = 0;
		y297 < y298 + 9;
		y297 += 3, y297_p_0 += 3){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 4) (1024 / 256)
		for (c397 = c398, c397_p_0 = 0;
			c397 < c398 + 1024;
			c397 += 256, c397_p_0 += 256){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (f, 8) (512 / 64)
			for (f = f198, fp_0 = 0;
				f < f198 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y297, yp_1 = y297_p_0, yp_0 = 0;
					y < y297 + 3;
					y += 3, yp_1 += 3, yp_0 += 3){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 4) (256 / 64)
					for (c396 = c397, c396_p_1 = c397_p_0, c396_p_0 = 0;
						c396 < c397 + 256;
						c396 += 64, c396_p_1 += 64, c396_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x198, xp_0 = 0;
							x < x198 + 17;
							x += 1, xp_0 += 1){
									mem_vec_3980 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3981 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3982 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3983 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3984 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3985 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3986 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3987 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_3988 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_3989 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_3990 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_3991 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c396, cp_2 = c396_p_1, cp_1 = c396_p_0, cp_0 = 0;
										c < c396 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3980);
										mem_vec_3980 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3981);
										mem_vec_3981 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3982);
										mem_vec_3982 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3983);
										mem_vec_3983 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3984);
										mem_vec_3984 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3985);
										mem_vec_3985 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3986);
										mem_vec_3986 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3987);
										mem_vec_3987 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3988);
										mem_vec_3988 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3989);
										mem_vec_3989 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3990);
										mem_vec_3990 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3991);
										mem_vec_3991 = vec_18;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3980);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3981);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3982);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3983);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3984);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3985);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3986);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3987);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3988);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3989);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3990);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3991);
						}
					}
				}
			}
		}
	}
	for (y297 = y298 + 9, y297_p_0 = 0;
		y297 < y298 + 9 + 8;
		y297 += 4, y297_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (c, 4) (1024 / 256)
		for (c397 = c398, c397_p_0 = 0;
			c397 < c398 + 1024;
			c397 += 256, c397_p_0 += 256){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (f, 8) (512 / 64)
			for (f = f198, fp_0 = 0;
				f < f198 + 512;
				f += 64, fp_0 += 64){
				// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y297, yp_1 = y297_p_0, yp_0 = 0;
					y < y297 + 4;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
					// T (c, 4) (256 / 64)
					for (c396 = c397, c396_p_1 = c397_p_0, c396_p_0 = 0;
						c396 < c397 + 256;
						c396 += 64, c396_p_1 += 64, c396_p_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 64, f = 64
						// T (x, 17) (17 / 1)
						for (x = x198, xp_0 = 0;
							x < x198 + 17;
							x += 1, xp_0 += 1){
									mem_vec_3992 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_3993 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_3994 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_3995 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_3996 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_3997 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_3998 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_3999 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_4000 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4001 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4002 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_4003 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_4004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_4007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 64
									// T (c, 64) (64 / 1)
									for (c = c396, cp_2 = c396_p_1, cp_1 = c396_p_0, cp_0 = 0;
										c < c396 + 64;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3992);
										mem_vec_3992 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3993);
										mem_vec_3993 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3994);
										mem_vec_3994 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3995);
										mem_vec_3995 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3996);
										mem_vec_3996 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3997);
										mem_vec_3997 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3998);
										mem_vec_3998 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3999);
										mem_vec_3999 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4000);
										mem_vec_4000 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4001);
										mem_vec_4001 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4002);
										mem_vec_4002 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4003);
										mem_vec_4003 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4004);
										mem_vec_4004 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4005);
										mem_vec_4005 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4006);
										mem_vec_4006 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4007);
										mem_vec_4007 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3992);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3993);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3994);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3995);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3996);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3997);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3998);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3999);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4000);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4001);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4002);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4003);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4004);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4005);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4006);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4007);
						}
					}
				}
			}
		}
	}


}