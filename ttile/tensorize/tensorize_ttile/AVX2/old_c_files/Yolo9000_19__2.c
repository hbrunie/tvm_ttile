#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (1, x); T (1, y);
  T (16, f); T (32, c); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c87_p_0, cp_1, c87, f, fp_0, x, xp_0, x87_p_0, xp_1, x87, y, yp_0, y87_p_0, yp_1, y87;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y88 = 0;
IND_TYPE x88 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c88 = 0;
IND_TYPE f58 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1044 ,mem_vec_1045 ,mem_vec_1046 ,mem_vec_1047 ,mem_vec_1048 ,mem_vec_1049 ,mem_vec_1050 ,mem_vec_1051 ,mem_vec_1052 ,mem_vec_1053 ,mem_vec_1054 ,mem_vec_1055 ,mem_vec_1056 ,mem_vec_1057 ,mem_vec_1058 ,mem_vec_1059 ,mem_vec_1060 ,mem_vec_1061 ,mem_vec_1062 ,mem_vec_1063 ,mem_vec_1064 ,mem_vec_1065 ,mem_vec_1066 ,mem_vec_1067 ,mem_vec_1068 ,mem_vec_1069 ,mem_vec_1070 ,mem_vec_1071 ,mem_vec_1072 ,mem_vec_1073 ,mem_vec_1074 ,mem_vec_1075 ,mem_vec_1076 ,mem_vec_1077 ,mem_vec_1078 ,mem_vec_1079 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y87 = y88, y87_p_0 = 0;
		y87 < y88 + 12;
		y87 += 4, y87_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 17) (17 / 1)
		for (x87 = x88, x87_p_0 = 0;
			x87 < x88 + 17;
			x87 += 1, x87_p_0 += 1){
			// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 512
			// T (c, 32) (1024 / 32)
			for (c87 = c88, c87_p_0 = 0;
				c87 < c88 + 1024;
				c87 += 32, c87_p_0 += 32){
				// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 512
				// T (f, 16) (512 / 32)
				for (f = f58, fp_0 = 0;
					f < f58 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y87, yp_1 = y87_p_0, yp_0 = 0;
						y < y87 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
						// T (x, 1) (1 / 1)
						for (x = x87, xp_1 = x87_p_0, xp_0 = 0;
							x < x87 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1044 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1045 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1046 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1047 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1052 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1053 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1054 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1055 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1056 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1057 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1058 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1059 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c87, cp_1 = c87_p_0, cp_0 = 0;
										c < c87 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1044);
										mem_vec_1044 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1045);
										mem_vec_1045 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1046);
										mem_vec_1046 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1047);
										mem_vec_1047 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1048);
										mem_vec_1048 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1049);
										mem_vec_1049 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1050);
										mem_vec_1050 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1051);
										mem_vec_1051 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1052);
										mem_vec_1052 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1053);
										mem_vec_1053 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1054);
										mem_vec_1054 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1055);
										mem_vec_1055 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1056);
										mem_vec_1056 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1057);
										mem_vec_1057 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1058);
										mem_vec_1058 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1059);
										mem_vec_1059 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1044);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1045);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1046);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1047);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1048);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1049);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1050);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1051);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1052);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1053);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1054);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1055);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1056);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1057);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1058);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1059);
						}
					}
				}
			}
		}
	}
	for (y87 = y88 + 12, y87_p_0 = 0;
		y87 < y88 + 12 + 5;
		y87 += 5, y87_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 17) (17 / 1)
		for (x87 = x88, x87_p_0 = 0;
			x87 < x88 + 17;
			x87 += 1, x87_p_0 += 1){
			// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 512
			// T (c, 32) (1024 / 32)
			for (c87 = c88, c87_p_0 = 0;
				c87 < c88 + 1024;
				c87 += 32, c87_p_0 += 32){
				// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 512
				// T (f, 16) (512 / 32)
				for (f = f58, fp_0 = 0;
					f < f58 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y87, yp_1 = y87_p_0, yp_0 = 0;
						y < y87 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
						// T (x, 1) (1 / 1)
						for (x = x87, xp_1 = x87_p_0, xp_0 = 0;
							x < x87 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1060 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1061 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1062 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1063 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1064 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1065 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1066 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1067 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1068 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1069 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1070 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1071 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1072 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1073 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1074 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1075 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1076 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1077 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_1078 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1079 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
									// T (c, 32) (32 / 1)
									for (c = c87, cp_1 = c87_p_0, cp_0 = 0;
										c < c87 + 32;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1060);
										mem_vec_1060 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1061);
										mem_vec_1061 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1062);
										mem_vec_1062 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1063);
										mem_vec_1063 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1064);
										mem_vec_1064 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1065);
										mem_vec_1065 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1066);
										mem_vec_1066 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1067);
										mem_vec_1067 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1068);
										mem_vec_1068 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1069);
										mem_vec_1069 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1070);
										mem_vec_1070 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1071);
										mem_vec_1071 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1072);
										mem_vec_1072 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1073);
										mem_vec_1073 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1074);
										mem_vec_1074 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1075);
										mem_vec_1075 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1076);
										mem_vec_1076 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1077);
										mem_vec_1077 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1078);
										mem_vec_1078 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1079);
										mem_vec_1079 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1060);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1061);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1062);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1063);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1064);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1065);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1066);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1067);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1068);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1069);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1070);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1071);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1072);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1073);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1074);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1075);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1076);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1077);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1078);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1079);
						}
					}
				}
			}
		}
	}


}