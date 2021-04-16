#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (8, y); U (3, h); T (16, c); Hoist_vars [c]; T (2, x);
  T (2, c); T (3, w); T (1, x); T (2, f); T (14, y); T (56, x)]
*/
IND_TYPE c, cp_0, c111_p_0, cp_1, c111, f, fp_0, w, wp_0, x, xp_0, x112_p_0, x113_p_0, xp_1, x112_p_1, xp_2, x112, x113, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y110 = 0;
IND_TYPE x114 = 0;
IND_TYPE h = 0;
IND_TYPE w74 = 0;
IND_TYPE c112 = 0;
IND_TYPE f38 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_592 ,mem_vec_593 ,mem_vec_594 ,mem_vec_595 ,mem_vec_596 ,mem_vec_597 ,mem_vec_598 ,mem_vec_599 ,mem_vec_600 ,mem_vec_601 ,mem_vec_602 ,mem_vec_603 ,mem_vec_604 ,mem_vec_605 ,mem_vec_606 ,mem_vec_607 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 56) (112 / 2)
for (x113 = x114, x113_p_0 = 0;
	x113 < x114 + 112;
	x113 += 2, x113_p_0 += 2){
	// y = 112, x = 2, h = 3, w = 3, c = 32, f = 32
	// T (y, 14) (112 / 8)
	for (y = y110, yp_0 = 0;
		y < y110 + 112;
		y += 8, yp_0 += 8){
		// y = 8, x = 2, h = 3, w = 3, c = 32, f = 32
		// T (f, 2) (32 / 16)
		for (f = f38, fp_0 = 0;
			f < f38 + 32;
			f += 16, fp_0 += 16){
			// y = 8, x = 2, h = 3, w = 3, c = 32, f = 16
			// T (x, 1) (2 / 2)
			for (x112 = x113, x112_p_1 = x113_p_0, x112_p_0 = 0;
				x112 < x113 + 2;
				x112 += 2, x112_p_1 += 2, x112_p_0 += 2){
				// y = 8, x = 2, h = 3, w = 3, c = 32, f = 16
				// T (w, 3) (3 / 1)
				for (w = w74, wp_0 = 0;
					w < w74 + 3;
					w += 1, wp_0 += 1){
					// y = 8, x = 2, h = 3, w = 1, c = 32, f = 16
					// T (c, 2) (32 / 16)
					for (c111 = c112, c111_p_0 = 0;
						c111 < c112 + 32;
						c111 += 16, c111_p_0 += 16){
						// y = 8, x = 2, h = 3, w = 1, c = 16, f = 16
						// T (x, 2) (2 / 1)
						for (x = x112, xp_2 = x112_p_1, xp_1 = x112_p_0, xp_0 = 0;
							x < x112 + 2;
							x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
									mem_vec_592 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
									mem_vec_593 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
									mem_vec_594 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
									mem_vec_595 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
									mem_vec_596 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
									mem_vec_597 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
									mem_vec_598 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
									mem_vec_599 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
									mem_vec_600 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
									mem_vec_601 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
									mem_vec_602 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
									mem_vec_603 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
									mem_vec_604 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
									mem_vec_605 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
									mem_vec_606 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
									mem_vec_607 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
									// y = 8, x = 1, h = 3, w = 1, c = 16, f = 16
									// T (c, 16) (16 / 1)
									for (c = c111, cp_1 = c111_p_0, cp_0 = 0;
										c < c111 + 16;
										c += 1, cp_1 += 1, cp_0 += 1){
										scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
										vec_1 = _mm256_set1_ps(scal_0);
										vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

										vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_592);
										mem_vec_592 = vec_0;

										vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

										vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_593);
										mem_vec_593 = vec_3;
										scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
										vec_6 = _mm256_set1_ps(scal_1);


										vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_594);
										mem_vec_594 = vec_5;



										vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_595);
										mem_vec_595 = vec_7;
										scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
										vec_9 = _mm256_set1_ps(scal_2);


										vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_596);
										mem_vec_596 = vec_8;



										vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_597);
										mem_vec_597 = vec_10;
										scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
										vec_12 = _mm256_set1_ps(scal_3);


										vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_598);
										mem_vec_598 = vec_11;



										vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_599);
										mem_vec_599 = vec_13;
										scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
										vec_15 = _mm256_set1_ps(scal_4);


										vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_600);
										mem_vec_600 = vec_14;



										vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_601);
										mem_vec_601 = vec_16;
										scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
										vec_18 = _mm256_set1_ps(scal_5);


										vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_602);
										mem_vec_602 = vec_17;



										vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_603);
										mem_vec_603 = vec_19;
										scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
										vec_21 = _mm256_set1_ps(scal_6);


										vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_604);
										mem_vec_604 = vec_20;



										vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_605);
										mem_vec_605 = vec_22;
										scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
										vec_24 = _mm256_set1_ps(scal_7);


										vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_606);
										mem_vec_606 = vec_23;



										vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_607);
										mem_vec_607 = vec_25;
										scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
										vec_27 = _mm256_set1_ps(scal_8);
										vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

										vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_592);
										mem_vec_592 = vec_26;

										vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

										vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_593);
										mem_vec_593 = vec_29;
										scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
										vec_32 = _mm256_set1_ps(scal_9);


										vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_594);
										mem_vec_594 = vec_31;



										vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_595);
										mem_vec_595 = vec_33;
										scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
										vec_35 = _mm256_set1_ps(scal_10);


										vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_596);
										mem_vec_596 = vec_34;



										vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_597);
										mem_vec_597 = vec_36;
										scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
										vec_38 = _mm256_set1_ps(scal_11);


										vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_598);
										mem_vec_598 = vec_37;



										vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_599);
										mem_vec_599 = vec_39;
										scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
										vec_41 = _mm256_set1_ps(scal_12);


										vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_600);
										mem_vec_600 = vec_40;



										vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_601);
										mem_vec_601 = vec_42;
										scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
										vec_44 = _mm256_set1_ps(scal_13);


										vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_602);
										mem_vec_602 = vec_43;



										vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_603);
										mem_vec_603 = vec_45;
										scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
										vec_47 = _mm256_set1_ps(scal_14);


										vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_604);
										mem_vec_604 = vec_46;



										vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_605);
										mem_vec_605 = vec_48;
										scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
										vec_50 = _mm256_set1_ps(scal_15);


										vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_606);
										mem_vec_606 = vec_49;



										vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_607);
										mem_vec_607 = vec_51;
										scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
										vec_53 = _mm256_set1_ps(scal_16);
										vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

										vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_592);
										mem_vec_592 = vec_52;

										vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

										vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_593);
										mem_vec_593 = vec_55;
										scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
										vec_58 = _mm256_set1_ps(scal_17);


										vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_594);
										mem_vec_594 = vec_57;



										vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_595);
										mem_vec_595 = vec_59;
										scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
										vec_61 = _mm256_set1_ps(scal_18);


										vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_596);
										mem_vec_596 = vec_60;



										vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_597);
										mem_vec_597 = vec_62;
										scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
										vec_64 = _mm256_set1_ps(scal_19);


										vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_598);
										mem_vec_598 = vec_63;



										vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_599);
										mem_vec_599 = vec_65;
										scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
										vec_67 = _mm256_set1_ps(scal_20);


										vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_600);
										mem_vec_600 = vec_66;



										vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_601);
										mem_vec_601 = vec_68;
										scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
										vec_70 = _mm256_set1_ps(scal_21);


										vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_602);
										mem_vec_602 = vec_69;



										vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_603);
										mem_vec_603 = vec_71;
										scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
										vec_73 = _mm256_set1_ps(scal_22);


										vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_604);
										mem_vec_604 = vec_72;



										vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_605);
										mem_vec_605 = vec_74;
										scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
										vec_76 = _mm256_set1_ps(scal_23);


										vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_606);
										mem_vec_606 = vec_75;



										vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_607);
										mem_vec_607 = vec_77;
									}
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_592);
								_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_593);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_594);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_595);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_596);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_597);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_598);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_599);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_600);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_601);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_602);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_603);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_604);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_605);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_606);
								_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_607);
						}
					}
				}
			}
		}
	}
}


}