#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (32, c); Hoist_vars [c]; T (7, x);
  T (3, h); T (16, x); T (28, y); T (1, c); T (1, x)]
*/
IND_TYPE c, cp_0, c504_p_0, cp_1, c504, h, hp_0, x, xp_0, x642_p_0, x643_p_0, xp_1, x642_p_1, xp_2, x642, x643, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y336 = 0;
IND_TYPE x644 = 0;
IND_TYPE h186 = 0;
IND_TYPE w = 0;
IND_TYPE c505 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3480 ,mem_vec_3481 ,mem_vec_3482 ,mem_vec_3483 ,mem_vec_3484 ,mem_vec_3485 ,mem_vec_3486 ,mem_vec_3487 ,mem_vec_3488 ,mem_vec_3489 ,mem_vec_3490 ,mem_vec_3491 ,mem_vec_3492 ,mem_vec_3493 ,mem_vec_3494 ,mem_vec_3495 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 1) (112 / 112)
for (x643 = x644, x643_p_0 = 0;
	x643 < x644 + 112;
	x643 += 112, x643_p_0 += 112){
	// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
	// T (c, 1) (32 / 32)
	for (c504 = c505, c504_p_0 = 0;
		c504 < c505 + 32;
		c504 += 32, c504_p_0 += 32){
		// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
		// T (y, 28) (112 / 4)
		for (y = y336, yp_0 = 0;
			y < y336 + 112;
			y += 4, yp_0 += 4){
			// y = 4, x = 112, h = 3, w = 3, c = 32, f = 32
			// T (x, 16) (112 / 7)
			for (x642 = x643, x642_p_1 = x643_p_0, x642_p_0 = 0;
				x642 < x643 + 112;
				x642 += 7, x642_p_1 += 7, x642_p_0 += 7){
				// y = 4, x = 7, h = 3, w = 3, c = 32, f = 32
				// T (h, 3) (3 / 1)
				for (h = h186, hp_0 = 0;
					h < h186 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 7, h = 1, w = 3, c = 32, f = 32
					// T (x, 7) (7 / 1)
					for (x = x642, xp_2 = x642_p_1, xp_1 = x642_p_0, xp_0 = 0;
						x < x642 + 7;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3480 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3481 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_3482 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3483 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_3484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_3486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_3488 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3489 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_3490 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3491 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_3492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_3494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (c, 32) (32 / 1)
								for (c = c504, cp_1 = c504_p_0, cp_0 = 0;
									c < c504 + 32;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3480);
									mem_vec_3480 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3481);
									mem_vec_3481 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3482);
									mem_vec_3482 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3483);
									mem_vec_3483 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3484);
									mem_vec_3484 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3485);
									mem_vec_3485 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3486);
									mem_vec_3486 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3487);
									mem_vec_3487 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3488);
									mem_vec_3488 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3489);
									mem_vec_3489 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3490);
									mem_vec_3490 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3491);
									mem_vec_3491 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3492);
									mem_vec_3492 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3493);
									mem_vec_3493 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3494);
									mem_vec_3494 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3495);
									mem_vec_3495 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_25 = _mm256_set1_ps(scal_4);
									vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_3480);
									mem_vec_3480 = vec_24;

									vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

									vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_3481);
									mem_vec_3481 = vec_27;

									vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_3482);
									mem_vec_3482 = vec_29;

									vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

									vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_3483);
									mem_vec_3483 = vec_31;
									scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_34 = _mm256_set1_ps(scal_5);


									vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_3484);
									mem_vec_3484 = vec_33;



									vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_3485);
									mem_vec_3485 = vec_35;



									vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_3486);
									mem_vec_3486 = vec_36;



									vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_3487);
									mem_vec_3487 = vec_37;
									scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_39 = _mm256_set1_ps(scal_6);


									vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_3488);
									mem_vec_3488 = vec_38;



									vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_3489);
									mem_vec_3489 = vec_40;



									vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_3490);
									mem_vec_3490 = vec_41;



									vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_3491);
									mem_vec_3491 = vec_42;
									scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_44 = _mm256_set1_ps(scal_7);


									vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_3492);
									mem_vec_3492 = vec_43;



									vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_3493);
									mem_vec_3493 = vec_45;



									vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_3494);
									mem_vec_3494 = vec_46;



									vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_3495);
									mem_vec_3495 = vec_47;
									scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_49 = _mm256_set1_ps(scal_8);
									vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_3480);
									mem_vec_3480 = vec_48;

									vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

									vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_3481);
									mem_vec_3481 = vec_51;

									vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_3482);
									mem_vec_3482 = vec_53;

									vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

									vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_3483);
									mem_vec_3483 = vec_55;
									scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_58 = _mm256_set1_ps(scal_9);


									vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_3484);
									mem_vec_3484 = vec_57;



									vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_3485);
									mem_vec_3485 = vec_59;



									vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_3486);
									mem_vec_3486 = vec_60;



									vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_3487);
									mem_vec_3487 = vec_61;
									scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_63 = _mm256_set1_ps(scal_10);


									vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_3488);
									mem_vec_3488 = vec_62;



									vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_3489);
									mem_vec_3489 = vec_64;



									vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_3490);
									mem_vec_3490 = vec_65;



									vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_3491);
									mem_vec_3491 = vec_66;
									scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_68 = _mm256_set1_ps(scal_11);


									vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_3492);
									mem_vec_3492 = vec_67;



									vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_3493);
									mem_vec_3493 = vec_69;



									vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_3494);
									mem_vec_3494 = vec_70;



									vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_3495);
									mem_vec_3495 = vec_71;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3480);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3481);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3482);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3483);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3484);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3485);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3486);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3487);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3488);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3489);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3490);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3491);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3492);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3493);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3494);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3495);
					}
				}
			}
		}
	}
}


}