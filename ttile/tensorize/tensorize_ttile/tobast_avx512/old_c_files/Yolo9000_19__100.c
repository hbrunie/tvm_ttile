#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (8, c); Hoist_vars [c]; T (1, x); T (32, c);
  T (8, f); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (4, c)]
*/
IND_TYPE c, cp_0, c1192_p_0, c1193_p_0, cp_1, c1192_p_1, cp_2, c1192, c1193, f, fp_0, x, xp_0, x894_p_0, xp_1, x894, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y596 = 0;
IND_TYPE x895 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1194 = 0;
IND_TYPE f596 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_10032 ,mem_vec_10033 ,mem_vec_10034 ,mem_vec_10035 ,mem_vec_10036 ,mem_vec_10037 ,mem_vec_10038 ,mem_vec_10039 ,mem_vec_10040 ,mem_vec_10041 ,mem_vec_10042 ,mem_vec_10043 ,mem_vec_10044 ,mem_vec_10045 ,mem_vec_10046 ,mem_vec_10047 ,mem_vec_10048 ,mem_vec_10049 ,mem_vec_10050 ,mem_vec_10051 ,mem_vec_10052 ,mem_vec_10053 ,mem_vec_10054 ,mem_vec_10055 ,mem_vec_10056 ,mem_vec_10057 ,mem_vec_10058 ,mem_vec_10059 ,mem_vec_10060 ,mem_vec_10061 ,mem_vec_10062 ,mem_vec_10063 ,mem_vec_10064 ,mem_vec_10065 ,mem_vec_10066 ,mem_vec_10067 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (c, 4) (1024 / 256)
for (c1193 = c1194, c1193_p_0 = 0;
	c1193 < c1194 + 1024;
	c1193 += 256, c1193_p_0 += 256){
		for (y = y596, yp_0 = 0;
			y < y596 + 12;
			y += 4, yp_0 += 4){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (x, 17) (17 / 1)
			for (x894 = x895, x894_p_0 = 0;
				x894 < x895 + 17;
				x894 += 1, x894_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 512
				// T (f, 8) (512 / 64)
				for (f = f596, fp_0 = 0;
					f < f596 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
					// T (c, 32) (256 / 8)
					for (c1192 = c1193, c1192_p_1 = c1193_p_0, c1192_p_0 = 0;
						c1192 < c1193 + 256;
						c1192 += 8, c1192_p_1 += 8, c1192_p_0 += 8){
						// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (x, 1) (1 / 1)
						for (x = x894, xp_1 = x894_p_0, xp_0 = 0;
							x < x894 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10032 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10033 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10034 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10035 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1192, cp_2 = c1192_p_1, cp_1 = c1192_p_0, cp_0 = 0;
										c < c1192 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10032);
										mem_vec_10032 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10033);
										mem_vec_10033 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10034);
										mem_vec_10034 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10035);
										mem_vec_10035 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10036);
										mem_vec_10036 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10037);
										mem_vec_10037 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10038);
										mem_vec_10038 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10039);
										mem_vec_10039 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10040);
										mem_vec_10040 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10041);
										mem_vec_10041 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10042);
										mem_vec_10042 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10043);
										mem_vec_10043 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10044);
										mem_vec_10044 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10045);
										mem_vec_10045 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10046);
										mem_vec_10046 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10047);
										mem_vec_10047 = vec_23;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10032);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10033);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10034);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10035);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10036);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10037);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10038);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10039);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10040);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10041);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10042);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10043);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10044);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10045);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10046);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10047);
						}
					}
				}
			}
		}
		for (y = y596 + 12, yp_0 = 0;
			y < y596 + 12 + 5;
			y += 5, yp_0 += 5){
			// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 512
			// T (x, 17) (17 / 1)
			for (x894 = x895, x894_p_0 = 0;
				x894 < x895 + 17;
				x894 += 1, x894_p_0 += 1){
				// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 512
				// T (f, 8) (512 / 64)
				for (f = f596, fp_0 = 0;
					f < f596 + 512;
					f += 64, fp_0 += 64){
					// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
					// T (c, 32) (256 / 8)
					for (c1192 = c1193, c1192_p_1 = c1193_p_0, c1192_p_0 = 0;
						c1192 < c1193 + 256;
						c1192 += 8, c1192_p_1 += 8, c1192_p_0 += 8){
						// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
						// T (x, 1) (1 / 1)
						for (x = x894, xp_1 = x894_p_0, xp_0 = 0;
							x < x894 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10048 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10049 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10050 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_10051 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_10052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_10055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_10056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_10059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_10060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_10063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_10064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_10067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 8, f = 64
									// T (c, 8) (8 / 1)
									for (c = c1192, cp_2 = c1192_p_1, cp_1 = c1192_p_0, cp_0 = 0;
										c < c1192 + 8;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10048);
										mem_vec_10048 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10049);
										mem_vec_10049 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_10050);
										mem_vec_10050 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_10051);
										mem_vec_10051 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_10052);
										mem_vec_10052 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_10053);
										mem_vec_10053 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_10054);
										mem_vec_10054 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_10055);
										mem_vec_10055 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10056);
										mem_vec_10056 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10057);
										mem_vec_10057 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_10058);
										mem_vec_10058 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_10059);
										mem_vec_10059 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_10060);
										mem_vec_10060 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_10061);
										mem_vec_10061 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_10062);
										mem_vec_10062 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_10063);
										mem_vec_10063 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_10064);
										mem_vec_10064 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_10065);
										mem_vec_10065 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_10066);
										mem_vec_10066 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_10067);
										mem_vec_10067 = vec_28;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10048);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10049);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_10050);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_10051);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10052);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10053);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_10054);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_10055);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10056);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10057);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_10058);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_10059);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10060);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10061);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_10062);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_10063);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10064);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10065);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_10066);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_10067);
						}
					}
				}
			}
		}
}


}