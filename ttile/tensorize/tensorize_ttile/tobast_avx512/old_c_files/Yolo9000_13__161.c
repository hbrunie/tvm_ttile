#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (4, f);
  T (16, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1080_p_0, cp_1, c1080, f, fp_0, x, xp_0, x1440_p_0, x1441_p_0, xp_1, x1440_p_1, xp_2, x1440, x1441, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y720 = 0;
IND_TYPE x1442 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1081 = 0;
IND_TYPE f720 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_15000 ,mem_vec_15001 ,mem_vec_15002 ,mem_vec_15003 ,mem_vec_15004 ,mem_vec_15005 ,mem_vec_15006 ,mem_vec_15007 ,mem_vec_15008 ,mem_vec_15009 ,mem_vec_15010 ,mem_vec_15011 ,mem_vec_15012 ,mem_vec_15013 ,mem_vec_15014 ,mem_vec_15015 ,mem_vec_15016 ,mem_vec_15017 ,mem_vec_15018 ,mem_vec_15019 ,mem_vec_15020 ,mem_vec_15021 ,mem_vec_15022 ,mem_vec_15023 ,mem_vec_15024 ,mem_vec_15025 ,mem_vec_15026 ,mem_vec_15027 ,mem_vec_15028 ,mem_vec_15029 ,mem_vec_15030 ,mem_vec_15031 ,mem_vec_15032 ,mem_vec_15033 ,mem_vec_15034 ,mem_vec_15035 ,mem_vec_15036 ,mem_vec_15037 ,mem_vec_15038 ,mem_vec_15039 ,mem_vec_15040 ,mem_vec_15041 ,mem_vec_15042 ,mem_vec_15043 ,mem_vec_15044 ,mem_vec_15045 ,mem_vec_15046 ,mem_vec_15047 ,mem_vec_15048 ,mem_vec_15049 ,mem_vec_15050 ,mem_vec_15051 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
// T (x, 1) (34 / 34)
for (x1441 = x1442, x1441_p_0 = 0;
	x1441 < x1442 + 34;
	x1441 += 34, x1441_p_0 += 34){
	// y = 34, x = 34, h = 1, w = 1, c = 512, f = 256
	// T (c, 16) (512 / 32)
	for (c1080 = c1081, c1080_p_0 = 0;
		c1080 < c1081 + 512;
		c1080 += 32, c1080_p_0 += 32){
		// y = 34, x = 34, h = 1, w = 1, c = 32, f = 256
		// T (f, 4) (256 / 64)
		for (f = f720, fp_0 = 0;
			f < f720 + 256;
			f += 64, fp_0 += 64){
				for (y = y720, yp_0 = 0;
					y < y720 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 1, w = 1, c = 32, f = 64
					// T (x, 34) (34 / 1)
					for (x1440 = x1441, x1440_p_1 = x1441_p_0, x1440_p_0 = 0;
						x1440 < x1441 + 34;
						x1440 += 1, x1440_p_1 += 1, x1440_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1440, xp_2 = x1440_p_1, xp_1 = x1440_p_0, xp_0 = 0;
							x < x1440 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15000 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15001 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15002 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15003 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_15004 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15005 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15006 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_15007 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_15008 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15009 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15010 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_15011 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_15012 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15013 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15014 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_15015 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_15016 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15017 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15018 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_15019 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_15020 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15021 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15022 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_15023 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1080, cp_1 = c1080_p_0, cp_0 = 0;
										c < c1080 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15000);
										mem_vec_15000 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15001);
										mem_vec_15001 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15002);
										mem_vec_15002 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15003);
										mem_vec_15003 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15004);
										mem_vec_15004 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15005);
										mem_vec_15005 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15006);
										mem_vec_15006 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15007);
										mem_vec_15007 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15008);
										mem_vec_15008 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15009);
										mem_vec_15009 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15010);
										mem_vec_15010 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15011);
										mem_vec_15011 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15012);
										mem_vec_15012 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15013);
										mem_vec_15013 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15014);
										mem_vec_15014 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15015);
										mem_vec_15015 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15016);
										mem_vec_15016 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15017);
										mem_vec_15017 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15018);
										mem_vec_15018 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15019);
										mem_vec_15019 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15020);
										mem_vec_15020 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15021);
										mem_vec_15021 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15022);
										mem_vec_15022 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15023);
										mem_vec_15023 = vec_33;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15000);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15001);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15002);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15003);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15004);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15005);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15006);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15007);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15008);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15009);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15010);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15011);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15012);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15013);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15014);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15015);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15016);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15017);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15018);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15019);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15020);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15021);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15022);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15023);
						}
					}
				}
				for (y = y720 + 6, yp_0 = 0;
					y < y720 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 1, w = 1, c = 32, f = 64
					// T (x, 34) (34 / 1)
					for (x1440 = x1441, x1440_p_1 = x1441_p_0, x1440_p_0 = 0;
						x1440 < x1441 + 34;
						x1440 += 1, x1440_p_1 += 1, x1440_p_0 += 1){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
						// T (x, 1) (1 / 1)
						for (x = x1440, xp_2 = x1440_p_1, xp_1 = x1440_p_0, xp_0 = 0;
							x < x1440 + 1;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_15024 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_15025 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_15026 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_15027 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_15028 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_15029 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_15030 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_15031 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_15032 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_15033 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_15034 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_15035 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_15036 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_15037 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_15038 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_15039 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_15040 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_15041 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_15042 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_15043 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_15044 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_15045 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_15046 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_15047 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_15048 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_15049 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_15050 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_15051 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c1080, cp_1 = c1080_p_0, cp_0 = 0;
										c < c1080 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_15024);
										mem_vec_15024 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_15025);
										mem_vec_15025 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_15026);
										mem_vec_15026 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_15027);
										mem_vec_15027 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_15028);
										mem_vec_15028 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_15029);
										mem_vec_15029 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_15030);
										mem_vec_15030 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_15031);
										mem_vec_15031 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_15032);
										mem_vec_15032 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_15033);
										mem_vec_15033 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_15034);
										mem_vec_15034 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_15035);
										mem_vec_15035 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_15036);
										mem_vec_15036 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_15037);
										mem_vec_15037 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_15038);
										mem_vec_15038 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_15039);
										mem_vec_15039 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_15040);
										mem_vec_15040 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_15041);
										mem_vec_15041 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_15042);
										mem_vec_15042 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_15043);
										mem_vec_15043 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_15044);
										mem_vec_15044 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_15045);
										mem_vec_15045 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_15046);
										mem_vec_15046 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_15047);
										mem_vec_15047 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_15048);
										mem_vec_15048 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_15049);
										mem_vec_15049 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_15050);
										mem_vec_15050 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_15051);
										mem_vec_15051 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15024);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15025);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_15026);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_15027);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15028);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15029);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_15030);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_15031);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15032);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15033);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_15034);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_15035);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15036);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15037);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_15038);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_15039);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15040);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15041);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_15042);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_15043);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15044);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15045);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_15046);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_15047);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15048);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15049);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_15050);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_15051);
						}
					}
				}
		}
	}
}


}