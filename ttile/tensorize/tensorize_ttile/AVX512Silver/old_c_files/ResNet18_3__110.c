#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); T (32, c); Hoist_vars [c]; T (1, x); T (2, c);
  T (1, x); T (7, y); T (2, f); T (56, x); T (1, y); T (1, x); T (1, y)]
*/
IND_TYPE c, cp_0, c192_p_0, cp_1, c192, f, fp_0, x, xp_0, x320_p_0, x321_p_0, x322_p_0, xp_1, x320_p_1, x321_p_1, xp_2, x320_p_2, xp_3, x320, x321, x322, y, yp_0, y256_p_0, y257_p_0, yp_1, y256_p_1, yp_2, y256, y257;

assert((Y == 56));
assert((X == 56));
assert((H == 1));
assert((W == 1));
assert((C == 64));
assert((F == 64));
IND_TYPE y258 = 0;
IND_TYPE x323 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c193 = 0;
IND_TYPE f128 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7;
__m512 mem_vec_910 ,mem_vec_911 ,mem_vec_912 ,mem_vec_913 ,mem_vec_914 ,mem_vec_915 ,mem_vec_916 ,mem_vec_917 ,mem_vec_918 ,mem_vec_919 ,mem_vec_920 ,mem_vec_921 ,mem_vec_922 ,mem_vec_923 ,mem_vec_924 ,mem_vec_925 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
// T (y, 1) (56 / 56)
for (y257 = y258, y257_p_0 = 0;
	y257 < y258 + 56;
	y257 += 56, y257_p_0 += 56){
	// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
	// T (x, 1) (56 / 56)
	for (x322 = x323, x322_p_0 = 0;
		x322 < x323 + 56;
		x322 += 56, x322_p_0 += 56){
		// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
		// T (y, 1) (56 / 56)
		for (y256 = y257, y256_p_1 = y257_p_0, y256_p_0 = 0;
			y256 < y257 + 56;
			y256 += 56, y256_p_1 += 56, y256_p_0 += 56){
			// y = 56, x = 56, h = 1, w = 1, c = 64, f = 64
			// T (x, 56) (56 / 1)
			for (x321 = x322, x321_p_1 = x322_p_0, x321_p_0 = 0;
				x321 < x322 + 56;
				x321 += 1, x321_p_1 += 1, x321_p_0 += 1){
				// y = 56, x = 1, h = 1, w = 1, c = 64, f = 64
				// T (f, 2) (64 / 32)
				for (f = f128, fp_0 = 0;
					f < f128 + 64;
					f += 32, fp_0 += 32){
					// y = 56, x = 1, h = 1, w = 1, c = 64, f = 32
					// T (y, 7) (56 / 8)
					for (y = y256, yp_2 = y256_p_1, yp_1 = y256_p_0, yp_0 = 0;
						y < y256 + 56;
						y += 8, yp_2 += 8, yp_1 += 8, yp_0 += 8){
						// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
						// T (x, 1) (1 / 1)
						for (x320 = x321, x320_p_2 = x321_p_1, x320_p_1 = x321_p_0, x320_p_0 = 0;
							x320 < x321 + 1;
							x320 += 1, x320_p_2 += 1, x320_p_1 += 1, x320_p_0 += 1){
							// y = 8, x = 1, h = 1, w = 1, c = 64, f = 32
							// T (c, 2) (64 / 32)
							for (c192 = c193, c192_p_0 = 0;
								c192 < c193 + 64;
								c192 += 32, c192_p_0 += 32){
								// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
								// T (x, 1) (1 / 1)
								for (x = x320, xp_3 = x320_p_2, xp_2 = x320_p_1, xp_1 = x320_p_0, xp_0 = 0;
									x < x320 + 1;
									x += 1, xp_3 += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_910 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_911 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_912 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_913 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											// y = 8, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c192, cp_1 = c192_p_0, cp_0 = 0;
												c < c192 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_910);
												mem_vec_910 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_911);
												mem_vec_911 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_912);
												mem_vec_912 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_913);
												mem_vec_913 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_914);
												mem_vec_914 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_915);
												mem_vec_915 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_916);
												mem_vec_916 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_917);
												mem_vec_917 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_918);
												mem_vec_918 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_919);
												mem_vec_919 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_920);
												mem_vec_920 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_921);
												mem_vec_921 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_922);
												mem_vec_922 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_923);
												mem_vec_923 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_924);
												mem_vec_924 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_925);
												mem_vec_925 = vec_25;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_910);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_911);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_912);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_913);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_914);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_915);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_916);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_917);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_918);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_919);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_920);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_921);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_922);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_923);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_924);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_925);
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