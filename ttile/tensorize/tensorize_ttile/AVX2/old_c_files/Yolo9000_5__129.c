#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (32, c); Hoist_vars [c]; T (2, x); T (4, c);
  T (1, x); T (8, y); T (2, f); T (1, x); T (1, y); T (68, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c138_p_0, cp_1, c138, f, fp_0, x, xp_0, x230_p_0, x231_p_0, x232_p_0, xp_1, x230_p_1, x231_p_1, xp_2, x230_p_2, xp_3, x230, x231, x232, y, yp_0, y184_p_0, y185_p_0, yp_1, y184_p_1, yp_2, y184, y185;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y186 = 0;
IND_TYPE x233 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c139 = 0;
IND_TYPE f92 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_1256 ,mem_vec_1257 ,mem_vec_1258 ,mem_vec_1259 ,mem_vec_1260 ,mem_vec_1261 ,mem_vec_1262 ,mem_vec_1263 ,mem_vec_1264 ,mem_vec_1265 ,mem_vec_1266 ,mem_vec_1267 ,mem_vec_1268 ,mem_vec_1269 ,mem_vec_1270 ,mem_vec_1271 ,mem_vec_1272 ,mem_vec_1273 ,mem_vec_1274 ,mem_vec_1275 ,mem_vec_1276 ,mem_vec_1277 ,mem_vec_1278 ,mem_vec_1279 ,mem_vec_1280 ,mem_vec_1281 ,mem_vec_1282 ,mem_vec_1283 ,mem_vec_1284 ,mem_vec_1285 ,mem_vec_1286 ,mem_vec_1287 ,mem_vec_1288 ,mem_vec_1289 ,mem_vec_1290 ,mem_vec_1291 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y185 = y186, y185_p_0 = 0;
		y185 < y186 + 96;
		y185 += 32, y185_p_0 += 32){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x232 = x233, x232_p_0 = 0;
			x232 < x233 + 136;
			x232 += 2, x232_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y184 = y185, y184_p_1 = y185_p_0, y184_p_0 = 0;
				y184 < y185 + 32;
				y184 += 32, y184_p_1 += 32, y184_p_0 += 32){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x231 = x232, x231_p_1 = x232_p_0, x231_p_0 = 0;
					x231 < x232 + 2;
					x231 += 2, x231_p_1 += 2, x231_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f92, fp_0 = 0;
						f < f92 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y184, yp_2 = y184_p_1, yp_1 = y184_p_0, yp_0 = 0;
							y < y184 + 32;
							y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x230 = x231, x230_p_2 = x231_p_1, x230_p_1 = x231_p_0, x230_p_0 = 0;
								x230 < x231 + 2;
								x230 += 2, x230_p_2 += 2, x230_p_1 += 2, x230_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c138 = c139, c138_p_0 = 0;
									c138 < c139 + 128;
									c138 += 32, c138_p_0 += 32){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x230, xp_3 = x230_p_2, xp_2 = x230_p_1, xp_1 = x230_p_0, xp_0 = 0;
										x < x230 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1256 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1257 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1258 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1259 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1260 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1261 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1262 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1263 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1264 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1265 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1266 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1267 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1268 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1269 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1270 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1271 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
													c < c138 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1256);
													mem_vec_1256 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1257);
													mem_vec_1257 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1258);
													mem_vec_1258 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1259);
													mem_vec_1259 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1260);
													mem_vec_1260 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1261);
													mem_vec_1261 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1262);
													mem_vec_1262 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1263);
													mem_vec_1263 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1264);
													mem_vec_1264 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1265);
													mem_vec_1265 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1266);
													mem_vec_1266 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1267);
													mem_vec_1267 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1268);
													mem_vec_1268 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1269);
													mem_vec_1269 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1270);
													mem_vec_1270 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1271);
													mem_vec_1271 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1256);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1257);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1258);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1259);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1260);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1261);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1262);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1263);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1264);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1265);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1266);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1267);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1268);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1269);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1270);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1271);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y185 = y186 + 96, y185_p_0 = 0;
		y185 < y186 + 96 + 40;
		y185 += 40, y185_p_0 += 40){
		// y = 8 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x232 = x233, x232_p_0 = 0;
			x232 < x233 + 136;
			x232 += 2, x232_p_0 += 2){
			// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (y, 1) (8 * ph_y / 8 * ph_y)
			for (y184 = y185, y184_p_1 = y185_p_0, y184_p_0 = 0;
				y184 < y185 + 40;
				y184 += 40, y184_p_1 += 40, y184_p_0 += 40){
				// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (x, 1) (2 / 2)
				for (x231 = x232, x231_p_1 = x232_p_0, x231_p_0 = 0;
					x231 < x232 + 2;
					x231 += 2, x231_p_1 += 2, x231_p_0 += 2){
					// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (f, 2) (64 / 32)
					for (f = f92, fp_0 = 0;
						f < f92 + 64;
						f += 32, fp_0 += 32){
						// y = 8 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
						// T (y, 8) (8 * ph_y / ph_y)
						for (y = y184, yp_2 = y184_p_1, yp_1 = y184_p_0, yp_0 = 0;
							y < y184 + 40;
							y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
							// T (x, 1) (2 / 2)
							for (x230 = x231, x230_p_2 = x231_p_1, x230_p_1 = x231_p_0, x230_p_0 = 0;
								x230 < x231 + 2;
								x230 += 2, x230_p_2 += 2, x230_p_1 += 2, x230_p_0 += 2){
								// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 32
								// T (c, 4) (128 / 32)
								for (c138 = c139, c138_p_0 = 0;
									c138 < c139 + 128;
									c138 += 32, c138_p_0 += 32){
									// y = ph_y, x = 2, h = 1, w = 1, c = 32, f = 32
									// T (x, 2) (2 / 1)
									for (x = x230, xp_3 = x230_p_2, xp_2 = x230_p_1, xp_1 = x230_p_0, xp_0 = 0;
										x < x230 + 2;
										x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1272 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1273 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1274 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_1275 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_1276 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1277 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1278 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_1279 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_1280 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1281 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1282 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_1283 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_1284 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1285 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1286 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_1287 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_1288 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1289 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1290 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_1291 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
													c < c138 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1272);
													mem_vec_1272 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1273);
													mem_vec_1273 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1274);
													mem_vec_1274 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1275);
													mem_vec_1275 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1276);
													mem_vec_1276 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1277);
													mem_vec_1277 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1278);
													mem_vec_1278 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1279);
													mem_vec_1279 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1280);
													mem_vec_1280 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1281);
													mem_vec_1281 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1282);
													mem_vec_1282 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1283);
													mem_vec_1283 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1284);
													mem_vec_1284 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1285);
													mem_vec_1285 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1286);
													mem_vec_1286 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1287);
													mem_vec_1287 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_1288);
													mem_vec_1288 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_1289);
													mem_vec_1289 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_1290);
													mem_vec_1290 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_1291);
													mem_vec_1291 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1272);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1273);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1274);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1275);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1276);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1277);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1278);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1279);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1280);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1281);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1282);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1283);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1284);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1285);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1286);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1287);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1288);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1289);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1290);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_1291);
									}
								}
							}
						}
					}
				}
			}
		}
	}


}