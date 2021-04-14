#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (4, c); Hoist_vars [c]; T (2, x); T (3, w);
  T (3, h); T (56, x);
  Lambda_apply y [((Iter 9), (Arg 11)); ((Iter 1), (Arg 13))]; T (8, c);
  T (1, x)]
*/
IND_TYPE c, cp_0, c612_p_0, cp_1, c612, h, hp_0, w, wp_0, x, xp_0, x816_p_0, x817_p_0, xp_1, x816_p_1, xp_2, x816, x817, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y408 = 0;
IND_TYPE x818 = 0;
IND_TYPE h388 = 0;
IND_TYPE w408 = 0;
IND_TYPE c613 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7252 ,mem_vec_7253 ,mem_vec_7254 ,mem_vec_7255 ,mem_vec_7256 ,mem_vec_7257 ,mem_vec_7258 ,mem_vec_7259 ,mem_vec_7260 ,mem_vec_7261 ,mem_vec_7262 ,mem_vec_7263 ,mem_vec_7264 ,mem_vec_7265 ,mem_vec_7266 ,mem_vec_7267 ,mem_vec_7268 ,mem_vec_7269 ,mem_vec_7270 ,mem_vec_7271 ,mem_vec_7272 ,mem_vec_7273 ,mem_vec_7274 ,mem_vec_7275 ,mem_vec_7276 ,mem_vec_7277 ,mem_vec_7278 ,mem_vec_7279 ,mem_vec_7280 ,mem_vec_7281 ,mem_vec_7282 ,mem_vec_7283 ,mem_vec_7284 ,mem_vec_7285 ,mem_vec_7286 ,mem_vec_7287 ,mem_vec_7288 ,mem_vec_7289 ,mem_vec_7290 ,mem_vec_7291 ,mem_vec_7292 ,mem_vec_7293 ,mem_vec_7294 ,mem_vec_7295 ,mem_vec_7296 ,mem_vec_7297 ,mem_vec_7298 ,mem_vec_7299 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 1) (112 / 112)
for (x817 = x818, x817_p_0 = 0;
	x817 < x818 + 112;
	x817 += 112, x817_p_0 += 112){
	// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 8) (32 / 4)
	for (c612 = c613, c612_p_0 = 0;
		c612 < c613 + 32;
		c612 += 4, c612_p_0 += 4){
			for (y = y408, yp_0 = 0;
				y < y408 + 99;
				y += 11, yp_0 += 11){
				// y = ph_y, x = 112, h = 3, w = 3, c = 4, f = 32
				// T (x, 56) (112 / 2)
				for (x816 = x817, x816_p_1 = x817_p_0, x816_p_0 = 0;
					x816 < x817 + 112;
					x816 += 2, x816_p_1 += 2, x816_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h388, hp_0 = 0;
						h < h388 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w408, wp_0 = 0;
							w < w408 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
							// T (x, 2) (2 / 1)
							for (x = x816, xp_2 = x816_p_1, xp_1 = x816_p_0, xp_0 = 0;
								x < x816 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7252 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7253 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_7272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_7273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c612, cp_1 = c612_p_0, cp_0 = 0;
											c < c612 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7252);
											mem_vec_7252 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7253);
											mem_vec_7253 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7254);
											mem_vec_7254 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7255);
											mem_vec_7255 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7256);
											mem_vec_7256 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7257);
											mem_vec_7257 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7258);
											mem_vec_7258 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7259);
											mem_vec_7259 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7260);
											mem_vec_7260 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7261);
											mem_vec_7261 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7262);
											mem_vec_7262 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7263);
											mem_vec_7263 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7264);
											mem_vec_7264 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7265);
											mem_vec_7265 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7266);
											mem_vec_7266 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7267);
											mem_vec_7267 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7268);
											mem_vec_7268 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7269);
											mem_vec_7269 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7270);
											mem_vec_7270 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7271);
											mem_vec_7271 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7272);
											mem_vec_7272 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7273);
											mem_vec_7273 = vec_34;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7259);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7261);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7262);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7263);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7264);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7265);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7266);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7267);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7268);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7269);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7270);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7271);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7272);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7273);
							}
						}
					}
				}
			}
			for (y = y408 + 99, yp_0 = 0;
				y < y408 + 99 + 13;
				y += 13, yp_0 += 13){
				// y = ph_y, x = 112, h = 3, w = 3, c = 4, f = 32
				// T (x, 56) (112 / 2)
				for (x816 = x817, x816_p_1 = x817_p_0, x816_p_0 = 0;
					x816 < x817 + 112;
					x816 += 2, x816_p_1 += 2, x816_p_0 += 2){
					// y = ph_y, x = 2, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h388, hp_0 = 0;
						h < h388 + 3;
						h += 1, hp_0 += 1){
						// y = ph_y, x = 2, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w408, wp_0 = 0;
							w < w408 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 2, h = 1, w = 1, c = 4, f = 32
							// T (x, 2) (2 / 1)
							for (x = x816, xp_2 = x816_p_1, xp_1 = x816_p_0, xp_0 = 0;
								x < x816 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7274 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7275 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7292 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7293 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_7294 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_7295 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_7296 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_7297 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_7298 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_7299 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c612, cp_1 = c612_p_0, cp_0 = 0;
											c < c612 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7274);
											mem_vec_7274 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7275);
											mem_vec_7275 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7276);
											mem_vec_7276 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7277);
											mem_vec_7277 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7278);
											mem_vec_7278 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7279);
											mem_vec_7279 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7280);
											mem_vec_7280 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7281);
											mem_vec_7281 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7282);
											mem_vec_7282 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7283);
											mem_vec_7283 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7284);
											mem_vec_7284 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7285);
											mem_vec_7285 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7286);
											mem_vec_7286 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7287);
											mem_vec_7287 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7288);
											mem_vec_7288 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7289);
											mem_vec_7289 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7290);
											mem_vec_7290 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7291);
											mem_vec_7291 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7292);
											mem_vec_7292 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7293);
											mem_vec_7293 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7294);
											mem_vec_7294 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7295);
											mem_vec_7295 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7296);
											mem_vec_7296 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7297);
											mem_vec_7297 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7298);
											mem_vec_7298 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7299);
											mem_vec_7299 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7274);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7275);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7276);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7277);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7278);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7279);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7280);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7281);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7282);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7283);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7284);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7285);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7286);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7287);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7291);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7292);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7293);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7294);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7295);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7296);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7297);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7298);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7299);
							}
						}
					}
				}
			}
	}
}


}