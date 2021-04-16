#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (3, c); Hoist_vars [c]; T (136, x);
  T (1, c); T (3, h); T (68, y); T (4, x); T (1, y); T (2, y)]
*/
IND_TYPE c, cp_0, c169_p_0, cp_1, c169, h, hp_0, x, xp_0, x215_p_0, xp_1, x215, y, yp_0, y233_p_0, y234_p_0, yp_1, y233_p_1, yp_2, y233, y234;

assert((Y == 544));
assert((X == 544));
assert((H == 3));
assert((W == 3));
assert((C == 3));
assert((F == 32));
IND_TYPE y235 = 0;
IND_TYPE x216 = 0;
IND_TYPE h91 = 0;
IND_TYPE w = 0;
IND_TYPE c170 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1444 ,mem_vec_1445 ,mem_vec_1446 ,mem_vec_1447 ,mem_vec_1448 ,mem_vec_1449 ,mem_vec_1450 ,mem_vec_1451 ,mem_vec_1452 ,mem_vec_1453 ,mem_vec_1454 ,mem_vec_1455 ,mem_vec_1456 ,mem_vec_1457 ,mem_vec_1458 ,mem_vec_1459 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 544, x = 544, h = 3, w = 3, c = 3, f = 32
// T (y, 2) (544 / 272)
for (y234 = y235, y234_p_0 = 0;
	y234 < y235 + 544;
	y234 += 272, y234_p_0 += 272){
	// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
	// T (y, 1) (272 / 272)
	for (y233 = y234, y233_p_1 = y234_p_0, y233_p_0 = 0;
		y233 < y234 + 272;
		y233 += 272, y233_p_1 += 272, y233_p_0 += 272){
		// y = 272, x = 544, h = 3, w = 3, c = 3, f = 32
		// T (x, 4) (544 / 136)
		for (x215 = x216, x215_p_0 = 0;
			x215 < x216 + 544;
			x215 += 136, x215_p_0 += 136){
			// y = 272, x = 136, h = 3, w = 3, c = 3, f = 32
			// T (y, 68) (272 / 4)
			for (y = y233, yp_2 = y233_p_1, yp_1 = y233_p_0, yp_0 = 0;
				y < y233 + 272;
				y += 4, yp_2 += 4, yp_1 += 4, yp_0 += 4){
				// y = 4, x = 136, h = 3, w = 3, c = 3, f = 32
				// T (h, 3) (3 / 1)
				for (h = h91, hp_0 = 0;
					h < h91 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 136, h = 1, w = 3, c = 3, f = 32
					// T (c, 1) (3 / 3)
					for (c169 = c170, c169_p_0 = 0;
						c169 < c170 + 3;
						c169 += 3, c169_p_0 += 3){
						// y = 4, x = 136, h = 1, w = 3, c = 3, f = 32
						// T (x, 136) (136 / 1)
						for (x = x215, xp_1 = x215_p_0, xp_0 = 0;
							x < x215 + 136;
							x += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_1444 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_1445 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_1446 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
									mem_vec_1447 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
									mem_vec_1448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_1449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_1450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
									mem_vec_1451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
									mem_vec_1452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_1453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_1454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
									mem_vec_1455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
									mem_vec_1456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_1457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_1458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
									mem_vec_1459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
									// y = 4, x = 1, h = 1, w = 3, c = 3, f = 32
									// T (c, 3) (3 / 1)
									for (c = c169, cp_1 = c169_p_0, cp_0 = 0;
										c < c169 + 3;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1444);
										mem_vec_1444 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1445);
										mem_vec_1445 = vec_3;

										vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

										vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_1446);
										mem_vec_1446 = vec_5;

										vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

										vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_1447);
										mem_vec_1447 = vec_7;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_10 = _mm256_set1_ps(scal_1);


										vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_1448);
										mem_vec_1448 = vec_9;



										vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_1449);
										mem_vec_1449 = vec_11;



										vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_1450);
										mem_vec_1450 = vec_12;



										vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_1451);
										mem_vec_1451 = vec_13;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_15 = _mm256_set1_ps(scal_2);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1452);
										mem_vec_1452 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1453);
										mem_vec_1453 = vec_16;



										vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_1454);
										mem_vec_1454 = vec_17;



										vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_1455);
										mem_vec_1455 = vec_18;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_20 = _mm256_set1_ps(scal_3);


										vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_1456);
										mem_vec_1456 = vec_19;



										vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_1457);
										mem_vec_1457 = vec_21;



										vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_1458);
										mem_vec_1458 = vec_22;



										vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_1459);
										mem_vec_1459 = vec_23;
										scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
										vec_25 = _mm256_set1_ps(scal_4);
										vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

										vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_1444);
										mem_vec_1444 = vec_24;

										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

										vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_1445);
										mem_vec_1445 = vec_27;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

										vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_1446);
										mem_vec_1446 = vec_29;

										vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

										vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_1447);
										mem_vec_1447 = vec_31;
										scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
										vec_34 = _mm256_set1_ps(scal_5);


										vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_1448);
										mem_vec_1448 = vec_33;



										vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_1449);
										mem_vec_1449 = vec_35;



										vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_1450);
										mem_vec_1450 = vec_36;



										vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_1451);
										mem_vec_1451 = vec_37;
										scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
										vec_39 = _mm256_set1_ps(scal_6);


										vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_1452);
										mem_vec_1452 = vec_38;



										vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_1453);
										mem_vec_1453 = vec_40;



										vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_1454);
										mem_vec_1454 = vec_41;



										vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_1455);
										mem_vec_1455 = vec_42;
										scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
										vec_44 = _mm256_set1_ps(scal_7);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_1456);
										mem_vec_1456 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1457);
										mem_vec_1457 = vec_45;



										vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1458);
										mem_vec_1458 = vec_46;



										vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_1459);
										mem_vec_1459 = vec_47;
										scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
										vec_49 = _mm256_set1_ps(scal_8);
										vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

										vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_1444);
										mem_vec_1444 = vec_48;

										vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

										vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_1445);
										mem_vec_1445 = vec_51;

										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

										vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_1446);
										mem_vec_1446 = vec_53;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

										vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_1447);
										mem_vec_1447 = vec_55;
										scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
										vec_58 = _mm256_set1_ps(scal_9);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_1448);
										mem_vec_1448 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_1449);
										mem_vec_1449 = vec_59;



										vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1450);
										mem_vec_1450 = vec_60;



										vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1451);
										mem_vec_1451 = vec_61;
										scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
										vec_63 = _mm256_set1_ps(scal_10);


										vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_1452);
										mem_vec_1452 = vec_62;



										vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_1453);
										mem_vec_1453 = vec_64;



										vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_1454);
										mem_vec_1454 = vec_65;



										vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_1455);
										mem_vec_1455 = vec_66;
										scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
										vec_68 = _mm256_set1_ps(scal_11);


										vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_1456);
										mem_vec_1456 = vec_67;



										vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_1457);
										mem_vec_1457 = vec_69;



										vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_1458);
										mem_vec_1458 = vec_70;



										vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_1459);
										mem_vec_1459 = vec_71;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1444);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1445);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1446);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_1447);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1448);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1449);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1450);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_1451);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1452);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1453);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1454);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_1455);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1456);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1457);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1458);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_1459);
						}
					}
				}
			}
		}
	}
}


}