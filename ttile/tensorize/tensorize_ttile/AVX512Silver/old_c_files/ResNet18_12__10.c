#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (16, c); T (8, f); T (2, f)]
*/
IND_TYPE c, cp_0, c327_p_0, cp_1, c327, f, fp_0, f237_p_0, fp_1, f237, h, hp_0, w, wp_0, x, xp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y = 0;
IND_TYPE x188 = 0;
IND_TYPE h142 = 0;
IND_TYPE w142 = 0;
IND_TYPE c328 = 0;
IND_TYPE f238 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_1505 ,mem_vec_1506 ,mem_vec_1507 ,mem_vec_1508 ,mem_vec_1509 ,mem_vec_1510 ,mem_vec_1511 ,mem_vec_1512 ,mem_vec_1513 ,mem_vec_1514 ,mem_vec_1515 ,mem_vec_1516 ,mem_vec_1517 ,mem_vec_1518 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
// T (f, 2) (512 / 256)
for (f237 = f238, f237_p_0 = 0;
	f237 < f238 + 512;
	f237 += 256, f237_p_0 += 256){
	// y = 7, x = 7, h = 3, w = 3, c = 512, f = 256
	// T (f, 8) (256 / 32)
	for (f = f237, fp_1 = f237_p_0, fp_0 = 0;
		f < f237 + 256;
		f += 32, fp_1 += 32, fp_0 += 32){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 32
		// T (c, 16) (512 / 32)
		for (c327 = c328, c327_p_0 = 0;
			c327 < c328 + 512;
			c327 += 32, c327_p_0 += 32){
			// y = 7, x = 7, h = 3, w = 3, c = 32, f = 32
			// T (x, 7) (7 / 1)
			for (x = x188, xp_0 = 0;
				x < x188 + 7;
				x += 1, xp_0 += 1){
				// y = 7, x = 1, h = 3, w = 3, c = 32, f = 32
				// T (h, 3) (3 / 1)
				for (h = h142, hp_0 = 0;
					h < h142 + 3;
					h += 1, hp_0 += 1){
					// y = 7, x = 1, h = 1, w = 3, c = 32, f = 32
					// T (w, 3) (3 / 1)
					for (w = w142, wp_0 = 0;
						w < w142 + 3;
						w += 1, wp_0 += 1){
								mem_vec_1505 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_1506 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_1507 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_1508 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_1509 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_1510 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_1511 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_1512 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_1513 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_1514 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_1515 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_1516 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_1517 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_1518 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								// y = 7, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c327, cp_1 = c327_p_0, cp_0 = 0;
									c < c327 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1505);
									mem_vec_1505 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1506);
									mem_vec_1506 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_1507);
									mem_vec_1507 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_1508);
									mem_vec_1508 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_1509);
									mem_vec_1509 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_1510);
									mem_vec_1510 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_1511);
									mem_vec_1511 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_1512);
									mem_vec_1512 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1513);
									mem_vec_1513 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1514);
									mem_vec_1514 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_1515);
									mem_vec_1515 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_1516);
									mem_vec_1516 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_1517);
									mem_vec_1517 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_1518);
									mem_vec_1518 = vec_22;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1505);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1506);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1507);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1508);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1509);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1510);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1511);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1512);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1513);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1514);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1515);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_1516);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1517);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_1518);
					}
				}
			}
		}
	}
}


}