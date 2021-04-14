#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (34, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 1), (Arg 14))]; T (8, f);
  T (256, c); T (1, x)]
*/
IND_TYPE c, cp_0, c720_p_0, cp_1, c720, f, fp_0, x, xp_0, x960_p_0, x961_p_0, xp_1, x960_p_1, xp_2, x960, x961, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y480 = 0;
IND_TYPE x962 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c721 = 0;
IND_TYPE f480 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_10028 ,mem_vec_10029 ,mem_vec_10030 ,mem_vec_10031 ,mem_vec_10032 ,mem_vec_10033 ,mem_vec_10034 ,mem_vec_10035 ,mem_vec_10036 ,mem_vec_10037 ,mem_vec_10038 ,mem_vec_10039 ,mem_vec_10040 ,mem_vec_10041 ,mem_vec_10042 ,mem_vec_10043 ,mem_vec_10044 ,mem_vec_10045 ,mem_vec_10046 ,mem_vec_10047 ,mem_vec_10048 ,mem_vec_10049 ,mem_vec_10050 ,mem_vec_10051 ,mem_vec_10052 ,mem_vec_10053 ,mem_vec_10054 ,mem_vec_10055 ,mem_vec_10056 ,mem_vec_10057 ,mem_vec_10058 ,mem_vec_10059 ,mem_vec_10060 ,mem_vec_10061 ,mem_vec_10062 ,mem_vec_10063 ,mem_vec_10064 ,mem_vec_10065 ,mem_vec_10066 ,mem_vec_10067 ,mem_vec_10068 ,mem_vec_10069 ,mem_vec_10070 ,mem_vec_10071 ,mem_vec_10072 ,mem_vec_10073 ,mem_vec_10074 ,mem_vec_10075 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x961 = x962, x961_p_0 = 0;
	x961 < x962 + 34;
	x961 += 34, x961_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 256) (512 / 2)
	for (c720 = c721, c720_p_0 = 0;
		c720 < c721 + 512;
		c720 += 2, c720_p_0 += 2){
		// y = 34, x = 34, h = 1, w = 1, c = 2, f = 256
		// T (f, 8) (256 / 32)
		for (f = f480, fp_0 = 0;
			f < f480 + 256;
			f += 32, fp_0 += 32){
				for (y = y480, yp_0 = 0;
					y < y480 + 20;
					y += 10, yp_0 += 10){
					// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
					// T (x, 34) (34 / 1)
					for (x960 = x961, x960_p_1 = x961_p_0, x960_p_0 = 0;
						x960 < x961 + 34;
						x960 += 1, x960_p_1 += 1, x960_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
						// T (x, 1) (1 / 1)
						for (x = x960, xp_2 = x960_p_1, xp_1 = x960_p_0, xp_0 = 0;
							x < x960 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10028 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10029 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_10046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_10047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c720, cp_1 = c720_p_0, cp_0 = 0;
										c < c720 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10028);
										mem_vec_10028 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10029);
										mem_vec_10029 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10030);
										mem_vec_10030 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10031);
										mem_vec_10031 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10032);
										mem_vec_10032 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10033);
										mem_vec_10033 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10034);
										mem_vec_10034 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10035);
										mem_vec_10035 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10036);
										mem_vec_10036 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10037);
										mem_vec_10037 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10038);
										mem_vec_10038 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10039);
										mem_vec_10039 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10040);
										mem_vec_10040 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10041);
										mem_vec_10041 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10042);
										mem_vec_10042 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10043);
										mem_vec_10043 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10044);
										mem_vec_10044 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10045);
										mem_vec_10045 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10046);
										mem_vec_10046 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10047);
										mem_vec_10047 = vec_31;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10028);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10029);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10030);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10031);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10032);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10033);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10034);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10035);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10036);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10037);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10038);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10039);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10040);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10041);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10042);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10043);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10044);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10045);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10046);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10047);
						}
					}
				}
				for (y = y480 + 20, yp_0 = 0;
					y < y480 + 20 + 14;
					y += 14, yp_0 += 14){
					// y = ph_y, x = 34, h = 1, w = 1, c = 2, f = 32
					// T (x, 34) (34 / 1)
					for (x960 = x961, x960_p_1 = x961_p_0, x960_p_0 = 0;
						x960 < x961 + 34;
						x960 += 1, x960_p_1 += 1, x960_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
						// T (x, 1) (1 / 1)
						for (x = x960, xp_2 = x960_p_1, xp_1 = x960_p_0, xp_0 = 0;
							x < x960 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_10048 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_10049 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_10050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_10051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_10052 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_10053 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_10054 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_10055 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_10056 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_10057 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_10058 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_10059 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_10060 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_10061 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_10062 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_10063 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
									mem_vec_10064 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
									mem_vec_10065 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
									mem_vec_10066 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
									mem_vec_10067 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
									mem_vec_10068 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
									mem_vec_10069 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
									mem_vec_10070 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
									mem_vec_10071 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
									mem_vec_10072 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
									mem_vec_10073 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
									mem_vec_10074 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
									mem_vec_10075 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
									// T (c, 2) (2 / 1)
									for (c = c720, cp_1 = c720_p_0, cp_0 = 0;
										c < c720 + 2;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_10048);
										mem_vec_10048 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_10049);
										mem_vec_10049 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm512_set1_ps(scal_1);


										vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_10050);
										mem_vec_10050 = vec_5;



										vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_10051);
										mem_vec_10051 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm512_set1_ps(scal_2);


										vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_10052);
										mem_vec_10052 = vec_8;



										vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_10053);
										mem_vec_10053 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm512_set1_ps(scal_3);


										vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_10054);
										mem_vec_10054 = vec_11;



										vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_10055);
										mem_vec_10055 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm512_set1_ps(scal_4);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_10056);
										mem_vec_10056 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_10057);
										mem_vec_10057 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm512_set1_ps(scal_5);


										vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_10058);
										mem_vec_10058 = vec_17;



										vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_10059);
										mem_vec_10059 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm512_set1_ps(scal_6);


										vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_10060);
										mem_vec_10060 = vec_20;



										vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_10061);
										mem_vec_10061 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm512_set1_ps(scal_7);


										vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_10062);
										mem_vec_10062 = vec_23;



										vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_10063);
										mem_vec_10063 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
										vec_27 = _mm512_set1_ps(scal_8);


										vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_10064);
										mem_vec_10064 = vec_26;



										vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_10065);
										mem_vec_10065 = vec_28;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
										vec_30 = _mm512_set1_ps(scal_9);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_10066);
										mem_vec_10066 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_10067);
										mem_vec_10067 = vec_31;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
										vec_33 = _mm512_set1_ps(scal_10);


										vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_10068);
										mem_vec_10068 = vec_32;



										vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_10069);
										mem_vec_10069 = vec_34;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
										vec_36 = _mm512_set1_ps(scal_11);


										vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_10070);
										mem_vec_10070 = vec_35;



										vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_10071);
										mem_vec_10071 = vec_37;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
										vec_39 = _mm512_set1_ps(scal_12);


										vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_10072);
										mem_vec_10072 = vec_38;



										vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_10073);
										mem_vec_10073 = vec_40;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
										vec_42 = _mm512_set1_ps(scal_13);


										vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_10074);
										mem_vec_10074 = vec_41;



										vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_10075);
										mem_vec_10075 = vec_43;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10048);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10049);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10050);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10051);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10052);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10053);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10054);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10055);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10056);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10057);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10058);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10059);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10060);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10061);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_10062);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_10063);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_10064);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_10065);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_10066);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_10067);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_10068);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_10069);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_10070);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_10071);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_10072);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_10073);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_10074);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_10075);
						}
					}
				}
		}
	}
}


}