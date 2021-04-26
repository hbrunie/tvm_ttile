#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x); T (2, c);
  T (4, f); T (17, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 12)); ((Iter 4), (Arg 14))]]
*/
IND_TYPE c, cp_0, c138_p_0, cp_1, c138, f, fp_0, x, xp_0, x184_p_0, x185_p_0, xp_1, x184_p_1, xp_2, x184, x185, y, yp_0, y138_p_0, yp_1, y138;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y139 = 0;
IND_TYPE x186 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c139 = 0;
IND_TYPE f92 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2296 ,mem_vec_2297 ,mem_vec_2298 ,mem_vec_2299 ,mem_vec_2300 ,mem_vec_2301 ,mem_vec_2302 ,mem_vec_2303 ,mem_vec_2304 ,mem_vec_2305 ,mem_vec_2306 ,mem_vec_2307 ,mem_vec_2308 ,mem_vec_2309 ,mem_vec_2310 ,mem_vec_2311 ,mem_vec_2312 ,mem_vec_2313 ,mem_vec_2314 ,mem_vec_2315 ,mem_vec_2316 ,mem_vec_2317 ,mem_vec_2318 ,mem_vec_2319 ,mem_vec_2320 ,mem_vec_2321 ,mem_vec_2322 ,mem_vec_2323 ,mem_vec_2324 ,mem_vec_2325 ,mem_vec_2326 ,mem_vec_2327 ,mem_vec_2328 ,mem_vec_2329 ,mem_vec_2330 ,mem_vec_2331 ,mem_vec_2332 ,mem_vec_2333 ,mem_vec_2334 ,mem_vec_2335 ,mem_vec_2336 ,mem_vec_2337 ,mem_vec_2338 ,mem_vec_2339 ,mem_vec_2340 ,mem_vec_2341 ,mem_vec_2342 ,mem_vec_2343 ,mem_vec_2344 ,mem_vec_2345 ,mem_vec_2346 ,mem_vec_2347 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y138 = y139, y138_p_0 = 0;
		y138 < y139 + 12;
		y138 += 12, y138_p_0 += 12){
		// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x185 = x186, x185_p_0 = 0;
			x185 < x186 + 68;
			x185 += 68, x185_p_0 += 68){
			// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 1) (ph_y / ph_y)
			for (y = y138, yp_1 = y138_p_0, yp_0 = 0;
				y < y138 + 12;
				y += 12, yp_1 += 12, yp_0 += 12){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 17) (68 / 4)
				for (x184 = x185, x184_p_1 = x185_p_0, x184_p_0 = 0;
					x184 < x185 + 68;
					x184 += 4, x184_p_1 += 4, x184_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f92, fp_0 = 0;
						f < f92 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 2) (256 / 128)
						for (c138 = c139, c138_p_0 = 0;
							c138 < c139 + 256;
							c138 += 128, c138_p_0 += 128){
							// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
							// T (x, 4) (4 / 1)
							for (x = x184, xp_2 = x184_p_1, xp_1 = x184_p_0, xp_0 = 0;
								x < x184 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2296 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2297 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2300 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2301 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2302 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2303 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2304 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2305 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2306 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2307 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2308 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2309 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2310 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2311 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_2312 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_2313 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_2314 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_2315 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_2316 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_2317 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_2318 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_2319 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
										// T (c, 128) (128 / 1)
										for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
											c < c138 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2296);
											mem_vec_2296 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2297);
											mem_vec_2297 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2298);
											mem_vec_2298 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2299);
											mem_vec_2299 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2300);
											mem_vec_2300 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2301);
											mem_vec_2301 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2302);
											mem_vec_2302 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2303);
											mem_vec_2303 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2304);
											mem_vec_2304 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2305);
											mem_vec_2305 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2306);
											mem_vec_2306 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2307);
											mem_vec_2307 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2308);
											mem_vec_2308 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2309);
											mem_vec_2309 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2310);
											mem_vec_2310 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2311);
											mem_vec_2311 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2312);
											mem_vec_2312 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2313);
											mem_vec_2313 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2314);
											mem_vec_2314 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2315);
											mem_vec_2315 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2316);
											mem_vec_2316 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2317);
											mem_vec_2317 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2318);
											mem_vec_2318 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2319);
											mem_vec_2319 = vec_37;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2299);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2300);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2301);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2302);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2303);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2304);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2305);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2306);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2307);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2308);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2309);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2310);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2311);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2312);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2313);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2314);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2315);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2316);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2317);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2318);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2319);
							}
						}
					}
				}
			}
		}
	}
	for (y138 = y139 + 12, y138_p_0 = 0;
		y138 < y139 + 12 + 56;
		y138 += 14, y138_p_0 += 14){
		// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x185 = x186, x185_p_0 = 0;
			x185 < x186 + 68;
			x185 += 68, x185_p_0 += 68){
			// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 1) (ph_y / ph_y)
			for (y = y138, yp_1 = y138_p_0, yp_0 = 0;
				y < y138 + 14;
				y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 17) (68 / 4)
				for (x184 = x185, x184_p_1 = x185_p_0, x184_p_0 = 0;
					x184 < x185 + 68;
					x184 += 4, x184_p_1 += 4, x184_p_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f92, fp_0 = 0;
						f < f92 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 1, w = 1, c = 256, f = 32
						// T (c, 2) (256 / 128)
						for (c138 = c139, c138_p_0 = 0;
							c138 < c139 + 256;
							c138 += 128, c138_p_0 += 128){
							// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 32
							// T (x, 4) (4 / 1)
							for (x = x184, xp_2 = x184_p_1, xp_1 = x184_p_0, xp_0 = 0;
								x < x184 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_2320 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2321 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2322 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2323 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2324 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2325 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2326 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2327 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2328 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_2329 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_2330 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_2331 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_2332 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_2333 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_2334 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_2335 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_2336 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_2337 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_2338 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_2339 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_2340 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_2341 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_2342 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_2343 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_2344 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_2345 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_2346 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_2347 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
										// T (c, 128) (128 / 1)
										for (c = c138, cp_1 = c138_p_0, cp_0 = 0;
											c < c138 + 128;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2320);
											mem_vec_2320 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2321);
											mem_vec_2321 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2322);
											mem_vec_2322 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2323);
											mem_vec_2323 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2324);
											mem_vec_2324 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2325);
											mem_vec_2325 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2326);
											mem_vec_2326 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2327);
											mem_vec_2327 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2328);
											mem_vec_2328 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2329);
											mem_vec_2329 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_2330);
											mem_vec_2330 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_2331);
											mem_vec_2331 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_2332);
											mem_vec_2332 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_2333);
											mem_vec_2333 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_2334);
											mem_vec_2334 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_2335);
											mem_vec_2335 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_2336);
											mem_vec_2336 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_2337);
											mem_vec_2337 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_2338);
											mem_vec_2338 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_2339);
											mem_vec_2339 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_2340);
											mem_vec_2340 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_2341);
											mem_vec_2341 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_2342);
											mem_vec_2342 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_2343);
											mem_vec_2343 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_2344);
											mem_vec_2344 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_2345);
											mem_vec_2345 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_2346);
											mem_vec_2346 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_2347);
											mem_vec_2347 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2320);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2321);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2322);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2323);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2324);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2325);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2326);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2327);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2328);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2329);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_2330);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_2331);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_2332);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_2333);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_2334);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_2335);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_2336);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_2337);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_2338);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_2339);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_2340);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_2341);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_2342);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_2343);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_2344);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_2345);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_2346);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_2347);
							}
						}
					}
				}
			}
		}
	}


}