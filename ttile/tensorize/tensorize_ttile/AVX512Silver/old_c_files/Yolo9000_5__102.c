#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (2, f);
  T (34, x); T (8, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x594_p_0, xp_1, x594, y, yp_0, y594_p_0, yp_1, y594;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y595 = 0;
IND_TYPE x595 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c443 = 0;
IND_TYPE f349 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_8028 ,mem_vec_8029 ,mem_vec_8030 ,mem_vec_8031 ,mem_vec_8032 ,mem_vec_8033 ,mem_vec_8034 ,mem_vec_8035 ,mem_vec_8036 ,mem_vec_8037 ,mem_vec_8038 ,mem_vec_8039 ,mem_vec_8040 ,mem_vec_8041 ,mem_vec_8042 ,mem_vec_8043 ,mem_vec_8044 ,mem_vec_8045 ,mem_vec_8046 ,mem_vec_8047 ,mem_vec_8048 ,mem_vec_8049 ,mem_vec_8050 ,mem_vec_8051 ,mem_vec_8052 ,mem_vec_8053 ,mem_vec_8054 ,mem_vec_8055 ,mem_vec_8056 ,mem_vec_8057 ,mem_vec_8058 ,mem_vec_8059 ,mem_vec_8060 ,mem_vec_8061 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 8) (136 / 17)
for (y594 = y595, y594_p_0 = 0;
	y594 < y595 + 136;
	y594 += 17, y594_p_0 += 17){
	// y = 17, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 34) (136 / 4)
	for (x594 = x595, x594_p_0 = 0;
		x594 < x595 + 136;
		x594 += 4, x594_p_0 += 4){
		// y = 17, x = 4, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f349, fp_0 = 0;
			f < f349 + 64;
			f += 32, fp_0 += 32){
				for (y = y594, yp_1 = y594_p_0, yp_0 = 0;
					y < y594 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x594, xp_1 = x594_p_0, xp_0 = 0;
						x < x594 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_8028 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_8029 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_8030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_8031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_8032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_8033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_8034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_8035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_8036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_8037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_8038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_8039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_8040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_8041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_8042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_8043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c443, cp_0 = 0;
									c < c443 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8028);
									mem_vec_8028 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8029);
									mem_vec_8029 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8030);
									mem_vec_8030 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8031);
									mem_vec_8031 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8032);
									mem_vec_8032 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8033);
									mem_vec_8033 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8034);
									mem_vec_8034 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8035);
									mem_vec_8035 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8036);
									mem_vec_8036 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8037);
									mem_vec_8037 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8038);
									mem_vec_8038 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8039);
									mem_vec_8039 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8040);
									mem_vec_8040 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8041);
									mem_vec_8041 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8042);
									mem_vec_8042 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8043);
									mem_vec_8043 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8028);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8029);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8030);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8031);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8032);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8033);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8034);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8035);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8036);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8037);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8038);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8039);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8040);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8041);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8042);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8043);
					}
				}
				for (y = y594 + 8, yp_1 = y594_p_0, yp_0 = 0;
					y < y594 + 8 + 9;
					y += 9, yp_1 += 9, yp_0 += 9){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
					// T (x, 4) (4 / 1)
					for (x = x594, xp_1 = x594_p_0, xp_0 = 0;
						x < x594 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_8044 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_8045 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_8046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_8047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_8048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_8049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_8050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_8051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_8052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_8053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_8054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_8055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_8056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_8057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_8058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_8059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_8060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_8061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c443, cp_0 = 0;
									c < c443 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8044);
									mem_vec_8044 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8045);
									mem_vec_8045 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_8046);
									mem_vec_8046 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_8047);
									mem_vec_8047 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_8048);
									mem_vec_8048 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_8049);
									mem_vec_8049 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8050);
									mem_vec_8050 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8051);
									mem_vec_8051 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_8052);
									mem_vec_8052 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_8053);
									mem_vec_8053 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_8054);
									mem_vec_8054 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_8055);
									mem_vec_8055 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_8056);
									mem_vec_8056 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_8057);
									mem_vec_8057 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8058);
									mem_vec_8058 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8059);
									mem_vec_8059 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_8060);
									mem_vec_8060 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_8061);
									mem_vec_8061 = vec_28;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8044);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8045);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8046);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8047);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8048);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8049);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8050);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8051);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8052);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8053);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8054);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8055);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8056);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8057);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_8058);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_8059);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_8060);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_8061);
					}
				}
		}
	}
}


}