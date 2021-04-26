#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (4, f); T (1, x); T (1, y); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))]]
*/
IND_TYPE c, cp_0, c459_p_0, cp_1, c459, f, fp_0, x, xp_0, x612_p_0, x613_p_0, xp_1, x612_p_1, xp_2, x612, x613, y, yp_0, y459_p_0, yp_1, y459;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y460 = 0;
IND_TYPE x614 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c460 = 0;
IND_TYPE f306 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7246 ,mem_vec_7247 ,mem_vec_7248 ,mem_vec_7249 ,mem_vec_7250 ,mem_vec_7251 ,mem_vec_7252 ,mem_vec_7253 ,mem_vec_7254 ,mem_vec_7255 ,mem_vec_7256 ,mem_vec_7257 ,mem_vec_7258 ,mem_vec_7259 ,mem_vec_7260 ,mem_vec_7261 ,mem_vec_7262 ,mem_vec_7263 ,mem_vec_7264 ,mem_vec_7265 ,mem_vec_7266 ,mem_vec_7267 ,mem_vec_7268 ,mem_vec_7269 ,mem_vec_7270 ,mem_vec_7271 ,mem_vec_7272 ,mem_vec_7273 ,mem_vec_7274 ,mem_vec_7275 ,mem_vec_7276 ,mem_vec_7277 ,mem_vec_7278 ,mem_vec_7279 ,mem_vec_7280 ,mem_vec_7281 ,mem_vec_7282 ,mem_vec_7283 ,mem_vec_7284 ,mem_vec_7285 ,mem_vec_7286 ,mem_vec_7287 ,mem_vec_7288 ,mem_vec_7289 ,mem_vec_7290 ,mem_vec_7291 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y459 = y460, y459_p_0 = 0;
		y459 < y460 + 8;
		y459 += 8, y459_p_0 += 8){
		// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x613 = x614, x613_p_0 = 0;
			x613 < x614 + 68;
			x613 += 68, x613_p_0 += 68){
			// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 1) (ph_y / ph_y)
			for (y = y459, yp_1 = y459_p_0, yp_0 = 0;
				y < y459 + 8;
				y += 8, yp_1 += 8, yp_0 += 8){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x612 = x613, x612_p_1 = x613_p_0, x612_p_0 = 0;
					x612 < x613 + 68;
					x612 += 68, x612_p_1 += 68, x612_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f306, fp_0 = 0;
						f < f306 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c459 = c460, c459_p_0 = 0;
							c459 < c460 + 256;
							c459 += 256, c459_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
							// T (x, 68) (68 / 1)
							for (x = x612, xp_2 = x612_p_1, xp_1 = x612_p_0, xp_0 = 0;
								x < x612 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7246 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7247 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c459, cp_1 = c459_p_0, cp_0 = 0;
											c < c459 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7246);
											mem_vec_7246 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7247);
											mem_vec_7247 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7248);
											mem_vec_7248 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7249);
											mem_vec_7249 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7250);
											mem_vec_7250 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7251);
											mem_vec_7251 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7252);
											mem_vec_7252 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7253);
											mem_vec_7253 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7254);
											mem_vec_7254 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7255);
											mem_vec_7255 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7256);
											mem_vec_7256 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7257);
											mem_vec_7257 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7258);
											mem_vec_7258 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7259);
											mem_vec_7259 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7260);
											mem_vec_7260 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7261);
											mem_vec_7261 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7251);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7259);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7261);
							}
						}
					}
				}
			}
		}
	}
	for (y459 = y460 + 8, y459_p_0 = 0;
		y459 < y460 + 8 + 60;
		y459 += 15, y459_p_0 += 15){
		// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x613 = x614, x613_p_0 = 0;
			x613 < x614 + 68;
			x613 += 68, x613_p_0 += 68){
			// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 1) (ph_y / ph_y)
			for (y = y459, yp_1 = y459_p_0, yp_0 = 0;
				y < y459 + 15;
				y += 15, yp_1 += 15, yp_0 += 15){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x612 = x613, x612_p_1 = x613_p_0, x612_p_0 = 0;
					x612 < x613 + 68;
					x612 += 68, x612_p_1 += 68, x612_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f306, fp_0 = 0;
						f < f306 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c459 = c460, c459_p_0 = 0;
							c459 < c460 + 256;
							c459 += 256, c459_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
							// T (x, 68) (68 / 1)
							for (x = x612, xp_2 = x612_p_1, xp_1 = x612_p_0, xp_0 = 0;
								x < x612 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7262 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7263 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7272 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7273 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7274 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7275 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7276 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7277 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7278 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7279 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7280 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7281 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_7282 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_7283 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_7284 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_7285 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_7286 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_7287 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_7288 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_7289 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										mem_vec_7290 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
										mem_vec_7291 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c459, cp_1 = c459_p_0, cp_0 = 0;
											c < c459 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7262);
											mem_vec_7262 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7263);
											mem_vec_7263 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7264);
											mem_vec_7264 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7265);
											mem_vec_7265 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7266);
											mem_vec_7266 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7267);
											mem_vec_7267 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7268);
											mem_vec_7268 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7269);
											mem_vec_7269 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7270);
											mem_vec_7270 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7271);
											mem_vec_7271 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7272);
											mem_vec_7272 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7273);
											mem_vec_7273 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7274);
											mem_vec_7274 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7275);
											mem_vec_7275 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7276);
											mem_vec_7276 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7277);
											mem_vec_7277 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7278);
											mem_vec_7278 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7279);
											mem_vec_7279 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7280);
											mem_vec_7280 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7281);
											mem_vec_7281 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7282);
											mem_vec_7282 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7283);
											mem_vec_7283 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7284);
											mem_vec_7284 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7285);
											mem_vec_7285 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7286);
											mem_vec_7286 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7287);
											mem_vec_7287 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_7288);
											mem_vec_7288 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_7289);
											mem_vec_7289 = vec_43;
											scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
											vec_45 = _mm512_set1_ps(scal_14);


											vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_7290);
											mem_vec_7290 = vec_44;



											vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_7291);
											mem_vec_7291 = vec_46;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7262);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7263);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7264);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7265);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7266);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7267);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7268);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7269);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7270);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7271);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7272);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7273);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7274);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7275);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7276);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7277);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7278);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7279);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7280);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7281);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7282);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7283);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7284);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7285);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7286);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7287);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_7288);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_7289);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_7290);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_7291);
							}
						}
					}
				}
			}
		}
	}


}