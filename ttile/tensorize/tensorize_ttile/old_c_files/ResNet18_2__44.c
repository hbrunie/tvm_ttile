#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (4, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, x); T (7, y); T (2, f); T (16, c); T (14, x)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x64_p_0, x65_p_0, xp_1, x64_p_1, xp_2, x64, x65, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y32 = 0;
IND_TYPE x66 = 0;
IND_TYPE h32 = 0;
IND_TYPE w32 = 0;
IND_TYPE c49 = 0;
IND_TYPE f32 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_256 ,mem_vec_257 ,mem_vec_258 ,mem_vec_259 ,mem_vec_260 ,mem_vec_261 ,mem_vec_262 ,mem_vec_263 ,mem_vec_264 ,mem_vec_265 ,mem_vec_266 ,mem_vec_267 ,mem_vec_268 ,mem_vec_269 ,mem_vec_270 ,mem_vec_271 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (x, 14) (56 / 4)
for (x65 = x66, x65_p_0 = 0;
	x65 < x66 + 56;
	x65 += 4, x65_p_0 += 4){
	// y = 56, x = 4, h = 3, w = 3, c = 64, f = 64
	// T (c, 16) (64 / 4)
	for (c48 = c49, c48_p_0 = 0;
		c48 < c49 + 64;
		c48 += 4, c48_p_0 += 4){
		// y = 56, x = 4, h = 3, w = 3, c = 4, f = 64
		// T (f, 2) (64 / 32)
		for (f = f32, fp_0 = 0;
			f < f32 + 64;
			f += 32, fp_0 += 32){
			// y = 56, x = 4, h = 3, w = 3, c = 4, f = 32
			// T (y, 7) (56 / 8)
			for (y = y32, yp_0 = 0;
				y < y32 + 56;
				y += 8, yp_0 += 8){
				// y = 8, x = 4, h = 3, w = 3, c = 4, f = 32
				// T (x, 4) (4 / 1)
				for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
					x64 < x65 + 4;
					x64 += 1, x64_p_1 += 1, x64_p_0 += 1){
					// y = 8, x = 1, h = 3, w = 3, c = 4, f = 32
					// T (h, 3) (3 / 1)
					for (h = h32, hp_0 = 0;
						h < h32 + 3;
						h += 1, hp_0 += 1){
						// y = 8, x = 1, h = 1, w = 3, c = 4, f = 32
						// T (w, 3) (3 / 1)
						for (w = w32, wp_0 = 0;
							w < w32 + 3;
							w += 1, wp_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 4, f = 32
							// T (x, 1) (1 / 1)
							for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
								x < x64 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_256 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_257 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_260 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_261 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_262 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_263 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_264 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_265 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_266 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_267 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_268 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_269 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_270 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_271 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = 8, x = 1, h = 1, w = 1, c = 4, f = 32
										// T (c, 4) (4 / 1)
										for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
											c < c48 + 4;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_256);
											mem_vec_256 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_257);
											mem_vec_257 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_258);
											mem_vec_258 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_259);
											mem_vec_259 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_260);
											mem_vec_260 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_261);
											mem_vec_261 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_262);
											mem_vec_262 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_263);
											mem_vec_263 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_264);
											mem_vec_264 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_265);
											mem_vec_265 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_266);
											mem_vec_266 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_267);
											mem_vec_267 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_268);
											mem_vec_268 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_269);
											mem_vec_269 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_270);
											mem_vec_270 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_271);
											mem_vec_271 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_259);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_260);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_261);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_262);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_263);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_264);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_265);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_266);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_267);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_268);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_269);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_270);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_271);
							}
						}
					}
				}
			}
		}
	}
}


}