#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); T (16, c); Hoist_vars [c]; T (3, h); T (28, x);
  T (3, w); T (8, c); T (2, f); T (1, x); T (7, y); T (2, f)]
*/
IND_TYPE c, cp_0, c366_p_0, cp_1, c366, f, fp_0, f366_p_0, fp_1, f366, h, hp_0, w, wp_0, x, xp_0, x311_p_0, xp_1, x311, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y244 = 0;
IND_TYPE x312 = 0;
IND_TYPE h176 = 0;
IND_TYPE w187 = 0;
IND_TYPE c367 = 0;
IND_TYPE f367 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3;
__m512 mem_vec_2244 ,mem_vec_2245 ,mem_vec_2246 ,mem_vec_2247 ,mem_vec_2248 ,mem_vec_2249 ,mem_vec_2250 ,mem_vec_2251 ,mem_vec_2252 ,mem_vec_2253 ,mem_vec_2254 ,mem_vec_2255 ,mem_vec_2256 ,mem_vec_2257 ,mem_vec_2258 ,mem_vec_2259 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 2) (256 / 128)
for (f366 = f367, f366_p_0 = 0;
	f366 < f367 + 256;
	f366 += 128, f366_p_0 += 128){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 128
	// T (y, 7) (28 / 4)
	for (y = y244, yp_0 = 0;
		y < y244 + 28;
		y += 4, yp_0 += 4){
		// y = 4, x = 28, h = 3, w = 3, c = 128, f = 128
		// T (x, 1) (28 / 28)
		for (x311 = x312, x311_p_0 = 0;
			x311 < x312 + 28;
			x311 += 28, x311_p_0 += 28){
			// y = 4, x = 28, h = 3, w = 3, c = 128, f = 128
			// T (f, 2) (128 / 64)
			for (f = f366, fp_1 = f366_p_0, fp_0 = 0;
				f < f366 + 128;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 4, x = 28, h = 3, w = 3, c = 128, f = 64
				// T (c, 8) (128 / 16)
				for (c366 = c367, c366_p_0 = 0;
					c366 < c367 + 128;
					c366 += 16, c366_p_0 += 16){
					// y = 4, x = 28, h = 3, w = 3, c = 16, f = 64
					// T (w, 3) (3 / 1)
					for (w = w187, wp_0 = 0;
						w < w187 + 3;
						w += 1, wp_0 += 1){
						// y = 4, x = 28, h = 3, w = 1, c = 16, f = 64
						// T (x, 28) (28 / 1)
						for (x = x311, xp_1 = x311_p_0, xp_0 = 0;
							x < x311 + 28;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = 4, x = 1, h = 3, w = 1, c = 16, f = 64
							// T (h, 3) (3 / 1)
							for (h = h176, hp_0 = 0;
								h < h176 + 3;
								h += 1, hp_0 += 1){
										mem_vec_2244 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_2245 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_2246 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_2247 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_2248 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_2249 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_2250 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_2251 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_2252 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_2253 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_2254 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_2255 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_2256 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_2257 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_2258 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_2259 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = 4, x = 1, h = 1, w = 1, c = 16, f = 64
										// T (c, 16) (16 / 1)
										for (c = c366, cp_1 = c366_p_0, cp_0 = 0;
											c < c366 + 16;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2244);
											mem_vec_2244 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2245);
											mem_vec_2245 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_2246);
											mem_vec_2246 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_2247);
											mem_vec_2247 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_2248);
											mem_vec_2248 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_2249);
											mem_vec_2249 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_2250);
											mem_vec_2250 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_2251);
											mem_vec_2251 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2252);
											mem_vec_2252 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2253);
											mem_vec_2253 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_2254);
											mem_vec_2254 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_2255);
											mem_vec_2255 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_2256);
											mem_vec_2256 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_2257);
											mem_vec_2257 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_2258);
											mem_vec_2258 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_2259);
											mem_vec_2259 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2244);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2245);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_2246);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_2247);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2248);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2249);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_2250);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_2251);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2252);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2253);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_2254);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_2255);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2256);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2257);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_2258);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_2259);
							}
						}
					}
				}
			}
		}
	}
}


}