#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (1, x); T (1, y);
  T (16, f); T (4, c); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c108_p_0, cp_1, c108, f, fp_0, x, xp_0, x108_p_0, xp_1, x108, y, yp_0, y108_p_0, yp_1, y108;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y109 = 0;
IND_TYPE x109 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c109 = 0;
IND_TYPE f72 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1296 ,mem_vec_1297 ,mem_vec_1298 ,mem_vec_1299 ,mem_vec_1300 ,mem_vec_1301 ,mem_vec_1302 ,mem_vec_1303 ,mem_vec_1304 ,mem_vec_1305 ,mem_vec_1306 ,mem_vec_1307 ,mem_vec_1308 ,mem_vec_1309 ,mem_vec_1310 ,mem_vec_1311 ,mem_vec_1312 ,mem_vec_1313 ,mem_vec_1314 ,mem_vec_1315 ,mem_vec_1316 ,mem_vec_1317 ,mem_vec_1318 ,mem_vec_1319 ,mem_vec_1320 ,mem_vec_1321 ,mem_vec_1322 ,mem_vec_1323 ,mem_vec_1324 ,mem_vec_1325 ,mem_vec_1326 ,mem_vec_1327 ,mem_vec_1328 ,mem_vec_1329 ,mem_vec_1330 ,mem_vec_1331 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y108 = y109, y108_p_0 = 0;
		y108 < y109 + 12;
		y108 += 4, y108_p_0 += 4){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 17) (17 / 1)
		for (x108 = x109, x108_p_0 = 0;
			x108 < x109 + 17;
			x108 += 1, x108_p_0 += 1){
			// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 512
			// T (c, 4) (1024 / 256)
			for (c108 = c109, c108_p_0 = 0;
				c108 < c109 + 1024;
				c108 += 256, c108_p_0 += 256){
				// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 512
				// T (f, 16) (512 / 32)
				for (f = f72, fp_0 = 0;
					f < f72 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y108, yp_1 = y108_p_0, yp_0 = 0;
						y < y108 + 4;
						y += 4, yp_1 += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x108, xp_1 = x108_p_0, xp_0 = 0;
							x < x108 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1296 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1297 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1298 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1299 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1300 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1301 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1302 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1303 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1304 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1305 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1306 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1307 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1308 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1309 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1310 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1311 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c108, cp_1 = c108_p_0, cp_0 = 0;
										c < c108 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1296);
										mem_vec_1296 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1297);
										mem_vec_1297 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1298);
										mem_vec_1298 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1299);
										mem_vec_1299 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1300);
										mem_vec_1300 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1301);
										mem_vec_1301 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1302);
										mem_vec_1302 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1303);
										mem_vec_1303 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1304);
										mem_vec_1304 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1305);
										mem_vec_1305 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1306);
										mem_vec_1306 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1307);
										mem_vec_1307 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1308);
										mem_vec_1308 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1309);
										mem_vec_1309 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1310);
										mem_vec_1310 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1311);
										mem_vec_1311 = vec_23;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1296);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1297);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1298);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1299);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1300);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1301);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1302);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1303);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1304);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1305);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1306);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1307);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1308);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1309);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1310);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1311);
						}
					}
				}
			}
		}
	}
	for (y108 = y109 + 12, y108_p_0 = 0;
		y108 < y109 + 12 + 5;
		y108 += 5, y108_p_0 += 5){
		// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 512
		// T (x, 17) (17 / 1)
		for (x108 = x109, x108_p_0 = 0;
			x108 < x109 + 17;
			x108 += 1, x108_p_0 += 1){
			// y = ph_y, x = 1, h = 1, w = 1, c = 1024, f = 512
			// T (c, 4) (1024 / 256)
			for (c108 = c109, c108_p_0 = 0;
				c108 < c109 + 1024;
				c108 += 256, c108_p_0 += 256){
				// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 512
				// T (f, 16) (512 / 32)
				for (f = f72, fp_0 = 0;
					f < f72 + 512;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
					// T (y, 1) (ph_y / ph_y)
					for (y = y108, yp_1 = y108_p_0, yp_0 = 0;
						y < y108 + 5;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
						// T (x, 1) (1 / 1)
						for (x = x108, xp_1 = x108_p_0, xp_0 = 0;
							x < x108 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1312 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1313 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1314 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1315 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1316 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1317 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1318 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1319 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1320 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1321 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1322 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1323 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1324 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1325 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1326 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1327 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									mem_vec_1328 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1329 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_1330 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1331 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
									// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
									// T (c, 256) (256 / 1)
									for (c = c108, cp_1 = c108_p_0, cp_0 = 0;
										c < c108 + 256;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1312);
										mem_vec_1312 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1313);
										mem_vec_1313 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1314);
										mem_vec_1314 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1315);
										mem_vec_1315 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1316);
										mem_vec_1316 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1317);
										mem_vec_1317 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1318);
										mem_vec_1318 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1319);
										mem_vec_1319 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1320);
										mem_vec_1320 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1321);
										mem_vec_1321 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1322);
										mem_vec_1322 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1323);
										mem_vec_1323 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1324);
										mem_vec_1324 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1325);
										mem_vec_1325 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1326);
										mem_vec_1326 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1327);
										mem_vec_1327 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);


										vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1328);
										mem_vec_1328 = vec_24;



										vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1329);
										mem_vec_1329 = vec_26;



										vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1330);
										mem_vec_1330 = vec_27;



										vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1331);
										mem_vec_1331 = vec_28;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1312);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1313);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1314);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1315);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1316);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1317);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1318);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1319);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1320);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1321);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1322);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1323);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1324);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1325);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1326);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1327);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1328);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1329);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1330);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1331);
						}
					}
				}
			}
		}
	}


}