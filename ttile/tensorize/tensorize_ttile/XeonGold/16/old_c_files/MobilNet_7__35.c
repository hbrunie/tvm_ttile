#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (14, x); T (2, c); T (2, y); T (8, f); T (8, c)]
*/
IND_TYPE c, cp_0, c221_p_0, c222_p_0, cp_1, c221_p_1, cp_2, c221, c222, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y122 = 0;
IND_TYPE x122 = 0;
IND_TYPE h91 = 0;
IND_TYPE w114 = 0;
IND_TYPE c223 = 0;
IND_TYPE f145 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1386 ,mem_vec_1387 ,mem_vec_1388 ,mem_vec_1389 ,mem_vec_1390 ,mem_vec_1391 ,mem_vec_1392 ,mem_vec_1393 ,mem_vec_1394 ,mem_vec_1395 ,mem_vec_1396 ,mem_vec_1397 ,mem_vec_1398 ,mem_vec_1399 ,mem_vec_1400 ,mem_vec_1401 ,mem_vec_1402 ,mem_vec_1403 ,mem_vec_1404 ,mem_vec_1405 ,mem_vec_1406 ,mem_vec_1407 ,mem_vec_1408 ,mem_vec_1409 ,mem_vec_1410 ,mem_vec_1411 ,mem_vec_1412 ,mem_vec_1413 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (c, 8) (512 / 64)
for (c222 = c223, c222_p_0 = 0;
	c222 < c223 + 512;
	c222 += 64, c222_p_0 += 64){
	// y = 14, x = 14, h = 3, w = 3, c = 64, f = 512
	// T (f, 8) (512 / 64)
	for (f = f145, fp_0 = 0;
		f < f145 + 512;
		f += 64, fp_0 += 64){
		// y = 14, x = 14, h = 3, w = 3, c = 64, f = 64
		// T (y, 2) (14 / 7)
		for (y = y122, yp_0 = 0;
			y < y122 + 14;
			y += 7, yp_0 += 7){
			// y = 7, x = 14, h = 3, w = 3, c = 64, f = 64
			// T (c, 2) (64 / 32)
			for (c221 = c222, c221_p_1 = c222_p_0, c221_p_0 = 0;
				c221 < c222 + 64;
				c221 += 32, c221_p_1 += 32, c221_p_0 += 32){
				// y = 7, x = 14, h = 3, w = 3, c = 32, f = 64
				// T (x, 14) (14 / 1)
				for (x = x122, xp_0 = 0;
					x < x122 + 14;
					x += 1, xp_0 += 1){
					// y = 7, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (h, 3) (3 / 1)
					for (h = h91, hp_0 = 0;
						h < h91 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 1, h = 1, w = 3, c = 32, f = 64
						// T (w, 3) (3 / 1)
						for (w = w114, wp_0 = 0;
							w < w114 + 3;
							w += 1, wp_0 += 1){
									mem_vec_1386 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1387 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1388 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
									mem_vec_1389 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
									mem_vec_1390 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1391 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1392 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
									mem_vec_1393 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
									mem_vec_1394 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1395 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1396 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
									mem_vec_1397 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
									mem_vec_1398 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1399 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1400 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
									mem_vec_1401 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
									mem_vec_1402 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_1403 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
									mem_vec_1404 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
									mem_vec_1405 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
									mem_vec_1406 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_1407 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
									mem_vec_1408 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
									mem_vec_1409 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
									mem_vec_1410 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_1411 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
									mem_vec_1412 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
									mem_vec_1413 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
									// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
									// T (c, 32) (32 / 1)
									for (c = c221, cp_2 = c221_p_1, cp_1 = c221_p_0, cp_0 = 0;
										c < c221 + 32;
										c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm512_set1_ps(scal_0);
										vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1386);
										mem_vec_1386 = vec_0;

										vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1387);
										mem_vec_1387 = vec_3;

										vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

										vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1388);
										mem_vec_1388 = vec_5;

										vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

										vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1389);
										mem_vec_1389 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm512_set1_ps(scal_1);


										vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1390);
										mem_vec_1390 = vec_9;



										vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1391);
										mem_vec_1391 = vec_11;



										vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1392);
										mem_vec_1392 = vec_12;



										vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1393);
										mem_vec_1393 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm512_set1_ps(scal_2);


										vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1394);
										mem_vec_1394 = vec_14;



										vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1395);
										mem_vec_1395 = vec_16;



										vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1396);
										mem_vec_1396 = vec_17;



										vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1397);
										mem_vec_1397 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm512_set1_ps(scal_3);


										vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1398);
										mem_vec_1398 = vec_19;



										vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1399);
										mem_vec_1399 = vec_21;



										vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1400);
										mem_vec_1400 = vec_22;



										vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1401);
										mem_vec_1401 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_25 = _mm512_set1_ps(scal_4);


										vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1402);
										mem_vec_1402 = vec_24;



										vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1403);
										mem_vec_1403 = vec_26;



										vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1404);
										mem_vec_1404 = vec_27;



										vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1405);
										mem_vec_1405 = vec_28;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_30 = _mm512_set1_ps(scal_5);


										vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_1406);
										mem_vec_1406 = vec_29;



										vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_1407);
										mem_vec_1407 = vec_31;



										vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_1408);
										mem_vec_1408 = vec_32;



										vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_1409);
										mem_vec_1409 = vec_33;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_35 = _mm512_set1_ps(scal_6);


										vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_1410);
										mem_vec_1410 = vec_34;



										vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_1411);
										mem_vec_1411 = vec_36;



										vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_1412);
										mem_vec_1412 = vec_37;



										vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_1413);
										mem_vec_1413 = vec_38;
									}
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1386);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1387);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1388);
								_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1389);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1390);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1391);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1392);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1393);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1394);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1395);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1396);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1397);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1398);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1399);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1400);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1401);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1402);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1403);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1404);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1405);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1406);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1407);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_1408);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_1409);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1410);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1411);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_1412);
								_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_1413);
						}
					}
				}
			}
		}
	}
}


}