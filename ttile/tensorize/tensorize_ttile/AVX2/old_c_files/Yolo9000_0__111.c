#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (3, c); Hoist_vars [c]; T (68, x);
  T (1, c); T (3, w); T (68, y); T (8, x); T (1, y); T (2, y)]
*/
IND_TYPE c, cp_0, c481_p_0, cp_1, c481, w, wp_0, x, xp_0, x617_p_0, xp_1, x617, y, yp_0, y664_p_0, y665_p_0, yp_1, y664_p_1, yp_2, y664, y665;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y666 = 0;
IND_TYPE x618 = 0;
IND_TYPE h = 0;
IND_TYPE w332 = 0;
IND_TYPE c482 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_4364 ,mem_vec_4365 ,mem_vec_4366 ,mem_vec_4367 ,mem_vec_4368 ,mem_vec_4369 ,mem_vec_4370 ,mem_vec_4371 ,mem_vec_4372 ,mem_vec_4373 ,mem_vec_4374 ,mem_vec_4375 ,mem_vec_4376 ,mem_vec_4377 ,mem_vec_4378 ,mem_vec_4379 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
for (y665 = y666, y665_p_0 = 0;
	y665 < y666 + 544;
	y665 += 272, y665_p_0 += 272){
	// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 1) (272 / 272)
	for (y664 = y665, y664_p_1 = y665_p_0, y664_p_0 = 0;
		y664 < y665 + 272;
		y664 += 272, y664_p_1 += 272, y664_p_0 += 272){
		// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 8) (544 / 68)
		for (x617 = x618, x617_p_0 = 0;
			x617 < x618 + 544;
			x617 += 68, x617_p_0 += 68){
			// y = 272, x = 68, h = 3, w = 3, c = 3, f = 32
			// T (y, 68) (272 / 4)
			for (y = y664, yp_2 = y664_p_1, yp_1 = y664_p_0, yp_0 = 0;
				y < y664 + 272;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 68, h = 3, w = 3, c = 3, f = 32
				// T (w, 3) (3 / 1)
				for (w = w332, wp_0 = 0;
					w < w332 + 3;
					w += 1, wp_0 += 1){
					// y = 4, x = 68, h = 3, w = 1, c = 3, f = 32
					// T (c, 1) (3 / 3)
					for (c481 = c482, c481_p_0 = 0;
						c481 < c482 + 3;
						c481 += 3, c481_p_0 += 3){
						// y = 4, x = 68, h = 3, w = 1, c = 3, f = 32
						// T (x, 68) (68 / 1)
						for (x = x617, xp_1 = x617_p_0, xp_0 = 0;
							x < x617 + 68;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_4364 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_4365 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_4366 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_4367 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_4368 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_4369 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_4370 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_4371 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_4372 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_4373 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_4374 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_4375 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_4376 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_4377 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_4378 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_4379 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 3, w = 1, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c481, cp_1 = c481_p_0, cp_0 = 0;
										c < c481 + 3;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4364);
										mem_vec_4364 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4365);
										mem_vec_4365 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4366);
										mem_vec_4366 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4367);
										mem_vec_4367 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4368);
										mem_vec_4368 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4369);
										mem_vec_4369 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4370);
										mem_vec_4370 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4371);
										mem_vec_4371 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4372);
										mem_vec_4372 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4373);
										mem_vec_4373 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4374);
										mem_vec_4374 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4375);
										mem_vec_4375 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4376);
										mem_vec_4376 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4377);
										mem_vec_4377 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4378);
										mem_vec_4378 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4379);
										mem_vec_4379 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_4364);
										mem_vec_4364 = vec_24;

										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_4365);
										mem_vec_4365 = vec_27;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_4366);
										mem_vec_4366 = vec_29;

										vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_4367);
										mem_vec_4367 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_34 = _mm256_set1_ps(scal_5);


										vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_4368);
										mem_vec_4368 = vec_33;



										vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_4369);
										mem_vec_4369 = vec_35;



										vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_4370);
										mem_vec_4370 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_4371);
										mem_vec_4371 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_4372);
										mem_vec_4372 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_4373);
										mem_vec_4373 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_4374);
										mem_vec_4374 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_4375);
										mem_vec_4375 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_4376);
										mem_vec_4376 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_4377);
										mem_vec_4377 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_4378);
										mem_vec_4378 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_4379);
										mem_vec_4379 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_4364);
										mem_vec_4364 = vec_48;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_4365);
										mem_vec_4365 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_4366);
										mem_vec_4366 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_4367);
										mem_vec_4367 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_58 = _mm256_set1_ps(scal_9);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_4368);
										mem_vec_4368 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_4369);
										mem_vec_4369 = vec_59;



										vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_4370);
										mem_vec_4370 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_4371);
										mem_vec_4371 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_63 = _mm256_set1_ps(scal_10);


										vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_4372);
										mem_vec_4372 = vec_62;



										vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_4373);
										mem_vec_4373 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_4374);
										mem_vec_4374 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_4375);
										mem_vec_4375 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_4376);
										mem_vec_4376 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_4377);
										mem_vec_4377 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_4378);
										mem_vec_4378 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_4379);
										mem_vec_4379 = vec_71;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4364);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4365);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4366);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4367);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4368);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4369);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4370);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4371);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4372);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4373);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4374);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4375);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4376);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4377);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4378);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4379);
						}
					}
				}
			}
		}
	}
}


}