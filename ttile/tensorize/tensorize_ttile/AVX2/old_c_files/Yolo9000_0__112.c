#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, h); T (3, c); Hoist_vars [c]; T (2, x);
  T (1, c); T (3, w); T (34, y); T (272, x); T (4, y); T (1, y)]
*/
IND_TYPE c, cp_0, c76_p_0, cp_1, c76, w, wp_0, x, xp_0, x92_p_0, xp_1, x92, y, yp_0, y104_p_0, y105_p_0, yp_1, y104_p_1, yp_2, y104, y105;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y106 = 0;
IND_TYPE x93 = 0;
IND_TYPE h = 0;
IND_TYPE w54 = 0;
IND_TYPE c77 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_466 ,mem_vec_467 ,mem_vec_468 ,mem_vec_469 ,mem_vec_470 ,mem_vec_471 ,mem_vec_472 ,mem_vec_473 ,mem_vec_474 ,mem_vec_475 ,mem_vec_476 ,mem_vec_477 ,mem_vec_478 ,mem_vec_479 ,mem_vec_480 ,mem_vec_481 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 1) (544 / 544)
for (y105 = y106, y105_p_0 = 0;
	y105 < y106 + 544;
	y105 += 544, y105_p_0 += 544){
	// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 4) (544 / 136)
	for (y104 = y105, y104_p_1 = y105_p_0, y104_p_0 = 0;
		y104 < y105 + 544;
		y104 += 136, y104_p_1 += 136, y104_p_0 += 136){
		// y = 136, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 272) (544 / 2)
		for (x92 = x93, x92_p_0 = 0;
			x92 < x93 + 544;
			x92 += 2, x92_p_0 += 2){
			// y = 136, x = 2, h = 3, w = 3, c = 3, f = 32
			// T (y, 34) (136 / 4)
			for (y = y104, yp_2 = y104_p_1, yp_1 = y104_p_0, yp_0 = 0;
				y < y104 + 136;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 2, h = 3, w = 3, c = 3, f = 32
				// T (w, 3) (3 / 1)
				for (w = w54, wp_0 = 0;
					w < w54 + 3;
					w += 1, wp_0 += 1){
					// y = 4, x = 2, h = 3, w = 1, c = 3, f = 32
					// T (c, 1) (3 / 3)
					for (c76 = c77, c76_p_0 = 0;
						c76 < c77 + 3;
						c76 += 3, c76_p_0 += 3){
						// y = 4, x = 2, h = 3, w = 1, c = 3, f = 32
						// T (x, 2) (2 / 1)
						for (x = x92, xp_1 = x92_p_0, xp_0 = 0;
							x < x92 + 2;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_466 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_467 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_468 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_469 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_470 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_471 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_472 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_473 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_474 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_475 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 3, w = 1, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c76, cp_1 = c76_p_0, cp_0 = 0;
										c < c76 + 3;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_466);
										mem_vec_466 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_467);
										mem_vec_467 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_468);
										mem_vec_468 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_469);
										mem_vec_469 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_470);
										mem_vec_470 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_471);
										mem_vec_471 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_472);
										mem_vec_472 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_473);
										mem_vec_473 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_474);
										mem_vec_474 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_475);
										mem_vec_475 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_476);
										mem_vec_476 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_477);
										mem_vec_477 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_478);
										mem_vec_478 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_479);
										mem_vec_479 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_480);
										mem_vec_480 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_481);
										mem_vec_481 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_466);
										mem_vec_466 = vec_24;

										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_467);
										mem_vec_467 = vec_27;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

										vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_468);
										mem_vec_468 = vec_29;

										vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

										vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_469);
										mem_vec_469 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_34 = _mm256_set1_ps(scal_5);


										vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_470);
										mem_vec_470 = vec_33;



										vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_471);
										mem_vec_471 = vec_35;



										vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_472);
										mem_vec_472 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_473);
										mem_vec_473 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_474);
										mem_vec_474 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_475);
										mem_vec_475 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_476);
										mem_vec_476 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_477);
										mem_vec_477 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_478);
										mem_vec_478 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_479);
										mem_vec_479 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_480);
										mem_vec_480 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_481);
										mem_vec_481 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_466);
										mem_vec_466 = vec_48;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_467);
										mem_vec_467 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

										vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_468);
										mem_vec_468 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

										vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_469);
										mem_vec_469 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_58 = _mm256_set1_ps(scal_9);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_470);
										mem_vec_470 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_471);
										mem_vec_471 = vec_59;



										vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_472);
										mem_vec_472 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_473);
										mem_vec_473 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_63 = _mm256_set1_ps(scal_10);


										vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_474);
										mem_vec_474 = vec_62;



										vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_475);
										mem_vec_475 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_476);
										mem_vec_476 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_477);
										mem_vec_477 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_478);
										mem_vec_478 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_479);
										mem_vec_479 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_480);
										mem_vec_480 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_481);
										mem_vec_481 = vec_71;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_466);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_467);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_468);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_469);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_470);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_471);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_472);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_473);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_474);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_475);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_476);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_477);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_478);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_479);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_480);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_481);
						}
					}
				}
			}
		}
	}
}


}