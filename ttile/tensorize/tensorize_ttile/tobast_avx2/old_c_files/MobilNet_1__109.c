#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (4, y); U (3, w); T (1, c); Hoist_vars [c]; T (4, x);
  T (3, h); T (4, x); T (28, y); T (32, c); T (7, x)]
*/
IND_TYPE c, cp_0, c594_p_0, cp_1, c594, h, hp_0, x, xp_0, x762_p_0, x763_p_0, xp_1, x762_p_1, xp_2, x762, x763, y, yp_0;

assert((Y == 112));
assert((X == 112));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 32));
IND_TYPE y396 = 0;
IND_TYPE x764 = 0;
IND_TYPE h246 = 0;
IND_TYPE w = 0;
IND_TYPE c595 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3960 ,mem_vec_3961 ,mem_vec_3962 ,mem_vec_3963 ,mem_vec_3964 ,mem_vec_3965 ,mem_vec_3966 ,mem_vec_3967 ,mem_vec_3968 ,mem_vec_3969 ,mem_vec_3970 ,mem_vec_3971 ,mem_vec_3972 ,mem_vec_3973 ,mem_vec_3974 ,mem_vec_3975 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 3, w = 3, c = 32, f = 32
// T (x, 7) (112 / 16)
for (x763 = x764, x763_p_0 = 0;
	x763 < x764 + 112;
	x763 += 16, x763_p_0 += 16){
	// y = 112, x = 16, h = 3, w = 3, c = 32, f = 32
	// T (c, 32) (32 / 1)
	for (c594 = c595, c594_p_0 = 0;
		c594 < c595 + 32;
		c594 += 1, c594_p_0 += 1){
		// y = 112, x = 16, h = 3, w = 3, c = 1, f = 32
		// T (y, 28) (112 / 4)
		for (y = y396, yp_0 = 0;
			y < y396 + 112;
			y += 4, yp_0 += 4){
			// y = 4, x = 16, h = 3, w = 3, c = 1, f = 32
			// T (x, 4) (16 / 4)
			for (x762 = x763, x762_p_1 = x763_p_0, x762_p_0 = 0;
				x762 < x763 + 16;
				x762 += 4, x762_p_1 += 4, x762_p_0 += 4){
				// y = 4, x = 4, h = 3, w = 3, c = 1, f = 32
				// T (h, 3) (3 / 1)
				for (h = h246, hp_0 = 0;
					h < h246 + 3;
					h += 1, hp_0 += 1){
					// y = 4, x = 4, h = 1, w = 3, c = 1, f = 32
					// T (x, 4) (4 / 1)
					for (x = x762, xp_2 = x762_p_1, xp_1 = x762_p_0, xp_0 = 0;
						x < x762 + 4;
						x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3960 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3961 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
								mem_vec_3962 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3963 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
								mem_vec_3964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
								mem_vec_3966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
								mem_vec_3968 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3969 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
								mem_vec_3970 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3971 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
								mem_vec_3972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
								mem_vec_3974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
								// y = 4, x = 1, h = 1, w = 3, c = 1, f = 32
								// T (c, 1) (1 / 1)
								for (c = c594, cp_1 = c594_p_0, cp_0 = 0;
									c < c594 + 1;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm256_set1_ps(scal_0);
									vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3960);
									mem_vec_3960 = vec_0;

									vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

									vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3961);
									mem_vec_3961 = vec_3;

									vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_3962);
									mem_vec_3962 = vec_5;

									vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

									vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_3963);
									mem_vec_3963 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm256_set1_ps(scal_1);


									vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_3964);
									mem_vec_3964 = vec_9;



									vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_3965);
									mem_vec_3965 = vec_11;



									vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_3966);
									mem_vec_3966 = vec_12;



									vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_3967);
									mem_vec_3967 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm256_set1_ps(scal_2);


									vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3968);
									mem_vec_3968 = vec_14;



									vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3969);
									mem_vec_3969 = vec_16;



									vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_3970);
									mem_vec_3970 = vec_17;



									vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_3971);
									mem_vec_3971 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm256_set1_ps(scal_3);


									vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_3972);
									mem_vec_3972 = vec_19;



									vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_3973);
									mem_vec_3973 = vec_21;



									vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_3974);
									mem_vec_3974 = vec_22;



									vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_3975);
									mem_vec_3975 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
									vec_25 = _mm256_set1_ps(scal_4);
									vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

									vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_3960);
									mem_vec_3960 = vec_24;

									vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

									vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_3961);
									mem_vec_3961 = vec_27;

									vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

									vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_3962);
									mem_vec_3962 = vec_29;

									vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

									vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_3963);
									mem_vec_3963 = vec_31;
									scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
									vec_34 = _mm256_set1_ps(scal_5);


									vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_3964);
									mem_vec_3964 = vec_33;



									vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_3965);
									mem_vec_3965 = vec_35;



									vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_3966);
									mem_vec_3966 = vec_36;



									vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_3967);
									mem_vec_3967 = vec_37;
									scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
									vec_39 = _mm256_set1_ps(scal_6);


									vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_3968);
									mem_vec_3968 = vec_38;



									vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_3969);
									mem_vec_3969 = vec_40;



									vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_3970);
									mem_vec_3970 = vec_41;



									vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_3971);
									mem_vec_3971 = vec_42;
									scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
									vec_44 = _mm256_set1_ps(scal_7);


									vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_3972);
									mem_vec_3972 = vec_43;



									vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_3973);
									mem_vec_3973 = vec_45;



									vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_3974);
									mem_vec_3974 = vec_46;



									vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_3975);
									mem_vec_3975 = vec_47;
									scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
									vec_49 = _mm256_set1_ps(scal_8);
									vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

									vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_3960);
									mem_vec_3960 = vec_48;

									vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

									vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_3961);
									mem_vec_3961 = vec_51;

									vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

									vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_3962);
									mem_vec_3962 = vec_53;

									vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

									vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_3963);
									mem_vec_3963 = vec_55;
									scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
									vec_58 = _mm256_set1_ps(scal_9);


									vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_3964);
									mem_vec_3964 = vec_57;



									vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_3965);
									mem_vec_3965 = vec_59;



									vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_3966);
									mem_vec_3966 = vec_60;



									vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_3967);
									mem_vec_3967 = vec_61;
									scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
									vec_63 = _mm256_set1_ps(scal_10);


									vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_3968);
									mem_vec_3968 = vec_62;



									vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_3969);
									mem_vec_3969 = vec_64;



									vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_3970);
									mem_vec_3970 = vec_65;



									vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_3971);
									mem_vec_3971 = vec_66;
									scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
									vec_68 = _mm256_set1_ps(scal_11);


									vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_3972);
									mem_vec_3972 = vec_67;



									vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_3973);
									mem_vec_3973 = vec_69;



									vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_3974);
									mem_vec_3974 = vec_70;



									vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_3975);
									mem_vec_3975 = vec_71;
								}
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3960);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3961);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3962);
							_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_3963);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3964);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3965);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3966);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_3967);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3968);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3969);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3970);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_3971);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3972);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3973);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3974);
							_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_3975);
					}
				}
			}
		}
	}
}


}