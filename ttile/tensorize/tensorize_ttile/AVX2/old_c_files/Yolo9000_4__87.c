#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (64, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (1, c); T (1, f); T (34, y); T (1, x); T (4, f); T (34, x)]
*/
IND_TYPE c, cp_0, c72_p_0, cp_1, c72, f, fp_0, f63_p_0, fp_1, f63, h, hp_0, x, xp_0, x96_p_0, x97_p_0, xp_1, x96_p_1, xp_2, x96, x97, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y57 = 0;
IND_TYPE x98 = 0;
IND_TYPE h33 = 0;
IND_TYPE w = 0;
IND_TYPE c73 = 0;
IND_TYPE f64 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 34) (136 / 4)
for (x97 = x98, x97_p_0 = 0;
	x97 < x98 + 136;
	x97 += 4, x97_p_0 += 4){
	// y = 136, x = 4, h = 3, w = 3, c = 64, f = 128
	// T (f, 4) (128 / 32)
	for (f63 = f64, f63_p_0 = 0;
		f63 < f64 + 128;
		f63 += 32, f63_p_0 += 32){
		// y = 136, x = 4, h = 3, w = 3, c = 64, f = 32
		// T (x, 1) (4 / 4)
		for (x96 = x97, x96_p_1 = x97_p_0, x96_p_0 = 0;
			x96 < x97 + 4;
			x96 += 4, x96_p_1 += 4, x96_p_0 += 4){
			// y = 136, x = 4, h = 3, w = 3, c = 64, f = 32
			// T (y, 34) (136 / 4)
			for (y = y57, yp_0 = 0;
				y < y57 + 136;
				y += 4, yp_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 64, f = 32
				// T (f, 1) (32 / 32)
				for (f = f63, fp_1 = f63_p_0, fp_0 = 0;
					f < f63 + 32;
					f += 32, fp_1 += 32, fp_0 += 32){
					// y = 4, x = 4, h = 3, w = 3, c = 64, f = 32
					// T (c, 1) (64 / 64)
					for (c72 = c73, c72_p_0 = 0;
						c72 < c73 + 64;
						c72 += 64, c72_p_0 += 64){
						// y = 4, x = 4, h = 3, w = 3, c = 64, f = 32
						// T (h, 3) (3 / 1)
						for (h = h33, hp_0 = 0;
							h < h33 + 3;
							h += 1, hp_0 += 1){
							// y = 4, x = 4, h = 1, w = 3, c = 64, f = 32
							// T (x, 4) (4 / 1)
							for (x = x96, xp_2 = x96_p_1, xp_1 = x96_p_0, xp_0 = 0;
								x < x96 + 4;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_668 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_669 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
										mem_vec_670 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_671 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
										mem_vec_672 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_673 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
										mem_vec_674 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_675 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
										mem_vec_676 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_677 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
										mem_vec_678 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_679 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
										mem_vec_680 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_681 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
										mem_vec_682 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_683 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
										// y = 4, x = 1, h = 1, w = 3, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c72, cp_1 = c72_p_0, cp_0 = 0;
											c < c72 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm256_set1_ps(scal_0);
											vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_668);
											mem_vec_668 = vec_0;

											vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

											vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_669);
											mem_vec_669 = vec_3;

											vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_670);
											mem_vec_670 = vec_5;

											vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

											vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_671);
											mem_vec_671 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm256_set1_ps(scal_1);


											vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_672);
											mem_vec_672 = vec_9;



											vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_673);
											mem_vec_673 = vec_11;



											vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_674);
											mem_vec_674 = vec_12;



											vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_675);
											mem_vec_675 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm256_set1_ps(scal_2);


											vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_676);
											mem_vec_676 = vec_14;



											vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_677);
											mem_vec_677 = vec_16;



											vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_678);
											mem_vec_678 = vec_17;



											vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_679);
											mem_vec_679 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm256_set1_ps(scal_3);


											vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_680);
											mem_vec_680 = vec_19;



											vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_681);
											mem_vec_681 = vec_21;



											vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_682);
											mem_vec_682 = vec_22;



											vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_683);
											mem_vec_683 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
											vec_25 = _mm256_set1_ps(scal_4);
											vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

											vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_668);
											mem_vec_668 = vec_24;

											vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

											vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_669);
											mem_vec_669 = vec_27;

											vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

											vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_670);
											mem_vec_670 = vec_29;

											vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

											vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_671);
											mem_vec_671 = vec_31;
											scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
											vec_34 = _mm256_set1_ps(scal_5);


											vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_672);
											mem_vec_672 = vec_33;



											vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_673);
											mem_vec_673 = vec_35;



											vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_674);
											mem_vec_674 = vec_36;



											vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_675);
											mem_vec_675 = vec_37;
											scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
											vec_39 = _mm256_set1_ps(scal_6);


											vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_676);
											mem_vec_676 = vec_38;



											vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_677);
											mem_vec_677 = vec_40;



											vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_678);
											mem_vec_678 = vec_41;



											vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_679);
											mem_vec_679 = vec_42;
											scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
											vec_44 = _mm256_set1_ps(scal_7);


											vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_680);
											mem_vec_680 = vec_43;



											vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_681);
											mem_vec_681 = vec_45;



											vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_682);
											mem_vec_682 = vec_46;



											vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_683);
											mem_vec_683 = vec_47;
											scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
											vec_49 = _mm256_set1_ps(scal_8);
											vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

											vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_668);
											mem_vec_668 = vec_48;

											vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

											vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_669);
											mem_vec_669 = vec_51;

											vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

											vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_670);
											mem_vec_670 = vec_53;

											vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

											vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_671);
											mem_vec_671 = vec_55;
											scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
											vec_58 = _mm256_set1_ps(scal_9);


											vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_672);
											mem_vec_672 = vec_57;



											vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_673);
											mem_vec_673 = vec_59;



											vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_674);
											mem_vec_674 = vec_60;



											vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_675);
											mem_vec_675 = vec_61;
											scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
											vec_63 = _mm256_set1_ps(scal_10);


											vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_676);
											mem_vec_676 = vec_62;



											vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_677);
											mem_vec_677 = vec_64;



											vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_678);
											mem_vec_678 = vec_65;



											vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_679);
											mem_vec_679 = vec_66;
											scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
											vec_68 = _mm256_set1_ps(scal_11);


											vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_680);
											mem_vec_680 = vec_67;



											vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_681);
											mem_vec_681 = vec_69;



											vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_682);
											mem_vec_682 = vec_70;



											vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_683);
											mem_vec_683 = vec_71;
										}
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_668);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_669);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_670);
									_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_671);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_672);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_673);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_674);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_675);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_676);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_677);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_678);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_679);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_680);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_681);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_682);
									_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_683);
							}
						}
					}
				}
			}
		}
	}
}


}