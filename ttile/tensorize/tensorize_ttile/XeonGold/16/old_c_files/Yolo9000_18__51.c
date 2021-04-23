#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (17, x); T (2, c);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 1), (Arg 9))]; T (32, f);
  T (1, c); T (16, c)]
*/
IND_TYPE c, cp_0, c165_p_0, c166_p_0, c167_p_0, cp_1, c165_p_1, c166_p_1, cp_2, c165_p_2, cp_3, c165, c166, c167, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 1024));
IND_TYPE y66 = 0;
IND_TYPE x66 = 0;
IND_TYPE h60 = 0;
IND_TYPE w60 = 0;
IND_TYPE c168 = 0;
IND_TYPE f66 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8;
__m512 mem_vec_1266 ,mem_vec_1267 ,mem_vec_1268 ,mem_vec_1269 ,mem_vec_1270 ,mem_vec_1271 ,mem_vec_1272 ,mem_vec_1273 ,mem_vec_1274 ,mem_vec_1275 ,mem_vec_1276 ,mem_vec_1277 ,mem_vec_1278 ,mem_vec_1279 ,mem_vec_1280 ,mem_vec_1281 ,mem_vec_1282 ,mem_vec_1283 ,mem_vec_1284 ,mem_vec_1285 ,mem_vec_1286 ,mem_vec_1287 ,mem_vec_1288 ,mem_vec_1289 ,mem_vec_1290 ,mem_vec_1291 ,mem_vec_1292 ,mem_vec_1293 ,mem_vec_1294 ,mem_vec_1295 ,mem_vec_1296 ,mem_vec_1297 ,mem_vec_1298 ,mem_vec_1299 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 3, w = 3, c = 512, f = 1024
// T (c, 16) (512 / 32)
for (c167 = c168, c167_p_0 = 0;
	c167 < c168 + 512;
	c167 += 32, c167_p_0 += 32){
	// y = 17, x = 17, h = 3, w = 3, c = 32, f = 1024
	// T (c, 1) (32 / 32)
	for (c166 = c167, c166_p_1 = c167_p_0, c166_p_0 = 0;
		c166 < c167 + 32;
		c166 += 32, c166_p_1 += 32, c166_p_0 += 32){
		// y = 17, x = 17, h = 3, w = 3, c = 32, f = 1024
		// T (f, 32) (1024 / 32)
		for (f = f66, fp_0 = 0;
			f < f66 + 1024;
			f += 32, fp_0 += 32){
				for (y = y66, yp_0 = 0;
					y < y66 + 8;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c165 = c166, c165_p_2 = c166_p_1, c165_p_1 = c166_p_0, c165_p_0 = 0;
						c165 < c166 + 32;
						c165 += 16, c165_p_2 += 16, c165_p_1 += 16, c165_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x66, xp_0 = 0;
							x < x66 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h60, hp_0 = 0;
								h < h60 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w60, wp_0 = 0;
									w < w60 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1266 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1267 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_1281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c165, cp_3 = c165_p_2, cp_2 = c165_p_1, cp_1 = c165_p_0, cp_0 = 0;
												c < c165 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1266);
												mem_vec_1266 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1267);
												mem_vec_1267 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1268);
												mem_vec_1268 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1269);
												mem_vec_1269 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1270);
												mem_vec_1270 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1271);
												mem_vec_1271 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1272);
												mem_vec_1272 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1273);
												mem_vec_1273 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1274);
												mem_vec_1274 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1275);
												mem_vec_1275 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1276);
												mem_vec_1276 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1277);
												mem_vec_1277 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1278);
												mem_vec_1278 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1279);
												mem_vec_1279 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1280);
												mem_vec_1280 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1281);
												mem_vec_1281 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1266);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1267);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1268);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1269);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1270);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1271);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1272);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1273);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1274);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1275);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1276);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1277);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1278);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1279);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1280);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1281);
								}
							}
						}
					}
				}
				for (y = y66 + 8, yp_0 = 0;
					y < y66 + 8 + 9;
					y += 9, yp_0 += 9){
					// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c165 = c166, c165_p_2 = c166_p_1, c165_p_1 = c166_p_0, c165_p_0 = 0;
						c165 < c166 + 32;
						c165 += 16, c165_p_2 += 16, c165_p_1 += 16, c165_p_0 += 16){
						// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
						// T (x, 17) (17 / 1)
						for (x = x66, xp_0 = 0;
							x < x66 + 17;
							x += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h60, hp_0 = 0;
								h < h60 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w60, wp_0 = 0;
									w < w60 + 3;
									w += 1, wp_0 += 1){
											mem_vec_1282 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1283 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_1293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_1294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_1295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_1296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_1297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_1298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_1299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c165, cp_3 = c165_p_2, cp_2 = c165_p_1, cp_1 = c165_p_0, cp_0 = 0;
												c < c165 + 16;
												c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1282);
												mem_vec_1282 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1283);
												mem_vec_1283 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1284);
												mem_vec_1284 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1285);
												mem_vec_1285 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1286);
												mem_vec_1286 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1287);
												mem_vec_1287 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1288);
												mem_vec_1288 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1289);
												mem_vec_1289 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1290);
												mem_vec_1290 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1291);
												mem_vec_1291 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1292);
												mem_vec_1292 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1293);
												mem_vec_1293 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1294);
												mem_vec_1294 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1295);
												mem_vec_1295 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_1296);
												mem_vec_1296 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_1297);
												mem_vec_1297 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_1298);
												mem_vec_1298 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_1299);
												mem_vec_1299 = vec_28;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1282);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1283);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1284);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1285);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1286);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1287);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1288);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1289);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1290);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1291);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1292);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1293);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1294);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1295);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1296);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_1297);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1298);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_1299);
								}
							}
						}
					}
				}
		}
	}
}


}