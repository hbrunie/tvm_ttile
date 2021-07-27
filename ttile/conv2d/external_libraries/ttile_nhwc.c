#include <assert.h>
#include <immintrin.h>
#include <stdio.h>
#include <x86intrin.h>
#include "ttile.h"

void ttile_conv2d(float * params, float * input, float * output,
        int W, int H,
        int C, int F,
        int X, int Y) {
	/*
	   [V f; U (8, f); U (4, c); R h; R w; Hoist_vars [h;w]; T (14, x); T (2, y);
	   Pack params; T (2, f); T (32, c); T (4, x); T (28, y)]
	   */
	int c, cp_0, cg, cl, f, fp_0, fg, fl, h, hall, w, wall, x, x0, xp_0, x0_p_0, xp_1, y, y0, yp_0, y0_p_0, yp_1;
	float * params0 = (float *)aligned_alloc(1024, sizeof(float) * (256 * H) * W);
	assert((Y == 56));
	assert((X == 56));
	assert((H == 3));
	assert((W == 3));
	assert((C == 128));
	assert((F == 128));
	int y1 = 0;
	int x1 = 0;
	int c0 = 0;
	int f0 = 0;
	float scal_0 ,scal_1 ,scal_2 ,scal_3;
	__m256 mem_vec_0 ,mem_vec_1 ,mem_vec_2 ,mem_vec_3 ,mem_vec_4 ,mem_vec_5 ,mem_vec_6 ,mem_vec_7 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_7 ,vec_8 ,vec_9;
	// y = 56, x = 56, h = H, w = W, c = 128, f = 128
	// T (y, 28) (56 / 2)
	for (y0 = y1, y0_p_0 = 0;
			y0 < y1 + 56;
			y0 += 2, y0_p_0 += 2){
		// y = 2, x = 56, h = H, w = W, c = 128, f = 128
		// T (x, 4) (56 / 14)
		for (x0 = x1, x0_p_0 = 0;
				x0 < x1 + 56;
				x0 += 14, x0_p_0 += 14){
			// y = 2, x = 14, h = H, w = W, c = 128, f = 128
			// T (c, 32) (128 / 4)
			for (c = c0, cp_0 = 0;
					c < c0 + 128;
					c += 4, cp_0 += 4){
				// y = 2, x = 14, h = H, w = W, c = 4, f = 128
				// T (f, 2) (128 / 64)
				for (f = f0, fp_0 = 0;
						f < f0 + 128;
						f += 64, fp_0 += 64){
					// Pack params into params0
					for (wall = 0;
							wall < W;
							wall += 1){
						for (hall = 0;
								hall < H;
								hall += 1){
							for (cg = c, cl = 0;
									cg < c + 4;
									cg += 1, cl += 1){
								for (fg = f, fl = 0;
										fg < f + 64;
										fg += 8, fl += 8){
									vec_0 = _mm256_load_ps(&params[((F * C) * H) * wall + (F * C) * hall + F * cg + fg]);
									_mm256_store_ps(&params0[(256 * H) * wall + 256 * hall + 64 * cl + fl], vec_0);
								}
							}
						}
					}
					// y = 2, x = 14, h = H, w = W, c = 4, f = 64
					// T (y, 2) (2 / 1)
					for (y = y0, yp_1 = y0_p_0, yp_0 = 0;
							y < y0 + 2;
							y += 1, yp_1 += 1, yp_0 += 1){
						// y = 1, x = 14, h = H, w = W, c = 4, f = 64
						// T (x, 14) (14 / 1)
						for (x = x0, xp_1 = x0_p_0, xp_0 = 0;
								x < x0 + 14;
								x += 1, xp_1 += 1, xp_0 += 1){
							mem_vec_0 = _mm256_load_ps(&output[(F * Y) * x + F * y + f]);
							mem_vec_1 = _mm256_load_ps(&output[(F * Y) * x + F * y + f + 8]);
							mem_vec_2 = _mm256_load_ps(&output[(F * Y) * x + F * y + f + 16]);
							mem_vec_3 = _mm256_load_ps(&output[(F * Y) * x + F * y + f + 24]);
							mem_vec_4 = _mm256_load_ps(&output[(F * Y) * x + F * y + f + 32]);
							mem_vec_5 = _mm256_load_ps(&output[(F * Y) * x + F * y + f + 40]);
							mem_vec_6 = _mm256_load_ps(&output[(F * Y) * x + F * y + f + 48]);
							mem_vec_7 = _mm256_load_ps(&output[(F * Y) * x + F * y + f + 56]);
							// y = 1, x = 1, h = H, w = W, c = 4, f = 64
							// R w (W / 1)
							for (w = 0;
									w < W;
									w += 1){
								// y = 1, x = 1, h = H, w = 1, c = 4, f = 64
								// R h (H / 1)
								for (h = 0;
										h < H;
										h += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_0);
									mem_vec_0 = vec_0;

									vec_4 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1);
									mem_vec_1 = vec_3;

									vec_6 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_2);
									mem_vec_2 = vec_5;

									vec_8 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3);
									mem_vec_3 = vec_7;

									vec_10 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 32]);

									vec_9 = _mm256_fmadd_ps(vec_1, vec_10, mem_vec_4);
									mem_vec_4 = vec_9;

									vec_12 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 40]);

									vec_11 = _mm256_fmadd_ps(vec_1, vec_12, mem_vec_5);
									mem_vec_5 = vec_11;

									vec_14 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 48]);

									vec_13 = _mm256_fmadd_ps(vec_1, vec_14, mem_vec_6);
									mem_vec_6 = vec_13;

									vec_16 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 56]);

									vec_15 = _mm256_fmadd_ps(vec_1, vec_16, mem_vec_7);
									mem_vec_7 = vec_15;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c + 1];
									vec_18 = _mm256_set1_ps(scal_1);
									vec_19 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 64]);

									vec_17 = _mm256_fmadd_ps(vec_18, vec_19, mem_vec_0);
									mem_vec_0 = vec_17;

									vec_21 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 72]);

									vec_20 = _mm256_fmadd_ps(vec_18, vec_21, mem_vec_1);
									mem_vec_1 = vec_20;

									vec_23 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 80]);

									vec_22 = _mm256_fmadd_ps(vec_18, vec_23, mem_vec_2);
									mem_vec_2 = vec_22;

									vec_25 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 88]);

									vec_24 = _mm256_fmadd_ps(vec_18, vec_25, mem_vec_3);
									mem_vec_3 = vec_24;

									vec_27 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 96]);

									vec_26 = _mm256_fmadd_ps(vec_18, vec_27, mem_vec_4);
									mem_vec_4 = vec_26;

									vec_29 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 104]);

									vec_28 = _mm256_fmadd_ps(vec_18, vec_29, mem_vec_5);
									mem_vec_5 = vec_28;

									vec_31 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 112]);

									vec_30 = _mm256_fmadd_ps(vec_18, vec_31, mem_vec_6);
									mem_vec_6 = vec_30;

									vec_33 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 120]);

									vec_32 = _mm256_fmadd_ps(vec_18, vec_33, mem_vec_7);
									mem_vec_7 = vec_32;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c + 2];
									vec_35 = _mm256_set1_ps(scal_2);
									vec_36 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 128]);

									vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_0);
									mem_vec_0 = vec_34;

									vec_38 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 136]);

									vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_1);
									mem_vec_1 = vec_37;

									vec_40 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 144]);

									vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_2);
									mem_vec_2 = vec_39;

									vec_42 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 152]);

									vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_3);
									mem_vec_3 = vec_41;

									vec_44 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 160]);

									vec_43 = _mm256_fmadd_ps(vec_35, vec_44, mem_vec_4);
									mem_vec_4 = vec_43;

									vec_46 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 168]);

									vec_45 = _mm256_fmadd_ps(vec_35, vec_46, mem_vec_5);
									mem_vec_5 = vec_45;

									vec_48 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 176]);

									vec_47 = _mm256_fmadd_ps(vec_35, vec_48, mem_vec_6);
									mem_vec_6 = vec_47;

									vec_50 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 184]);

									vec_49 = _mm256_fmadd_ps(vec_35, vec_50, mem_vec_7);
									mem_vec_7 = vec_49;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c + 3];
									vec_52 = _mm256_set1_ps(scal_3);
									vec_53 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 192]);

									vec_51 = _mm256_fmadd_ps(vec_52, vec_53, mem_vec_0);
									mem_vec_0 = vec_51;

									vec_55 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 200]);

									vec_54 = _mm256_fmadd_ps(vec_52, vec_55, mem_vec_1);
									mem_vec_1 = vec_54;

									vec_57 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 208]);

									vec_56 = _mm256_fmadd_ps(vec_52, vec_57, mem_vec_2);
									mem_vec_2 = vec_56;

									vec_59 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 216]);

									vec_58 = _mm256_fmadd_ps(vec_52, vec_59, mem_vec_3);
									mem_vec_3 = vec_58;

									vec_61 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 224]);

									vec_60 = _mm256_fmadd_ps(vec_52, vec_61, mem_vec_4);
									mem_vec_4 = vec_60;

									vec_63 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 232]);

									vec_62 = _mm256_fmadd_ps(vec_52, vec_63, mem_vec_5);
									mem_vec_5 = vec_62;

									vec_65 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 240]);

									vec_64 = _mm256_fmadd_ps(vec_52, vec_65, mem_vec_6);
									mem_vec_6 = vec_64;

									vec_67 = _mm256_load_ps(&params0[(256 * H) * w + 256 * h + 248]);

									vec_66 = _mm256_fmadd_ps(vec_52, vec_67, mem_vec_7);
									mem_vec_7 = vec_66;
								}
							}
							_mm256_store_ps(&output[(F * Y) * x + F * y + f], mem_vec_0);
							_mm256_store_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1);
							_mm256_store_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2);
							_mm256_store_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3);
							_mm256_store_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4);
							_mm256_store_ps(&output[(F * Y) * x + F * y + f + 40], mem_vec_5);
							_mm256_store_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_6);
							_mm256_store_ps(&output[(F * Y) * x + F * y + f + 56], mem_vec_7);
						}
					}
				}
			}
		}
	}
	free(params0);

}
