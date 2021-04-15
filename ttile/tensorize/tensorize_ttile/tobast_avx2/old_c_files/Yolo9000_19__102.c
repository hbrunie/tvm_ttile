#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (2, c); Hoist_vars [c]; T (1, x); T (2, f);
  T (1, x); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (4, f); T (512, c); T (17, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1164_p_0, cp_1, c1164, f, fp_0, f1552_p_0, f1553_p_0, fp_1, f1552_p_1, fp_2, f1552, f1553, x, xp_0, x1552_p_0, x1553_p_0, xp_1, x1552_p_1, xp_2, x1552, x1553, y, yp_0;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 512));
IND_TYPE y776 = 0;
IND_TYPE x1554 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c1165 = 0;
IND_TYPE f1554 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_13968 ,mem_vec_13969 ,mem_vec_13970 ,mem_vec_13971 ,mem_vec_13972 ,mem_vec_13973 ,mem_vec_13974 ,mem_vec_13975 ,mem_vec_13976 ,mem_vec_13977 ,mem_vec_13978 ,mem_vec_13979 ,mem_vec_13980 ,mem_vec_13981 ,mem_vec_13982 ,mem_vec_13983 ,mem_vec_13984 ,mem_vec_13985 ,mem_vec_13986 ,mem_vec_13987 ,mem_vec_13988 ,mem_vec_13989 ,mem_vec_13990 ,mem_vec_13991 ,mem_vec_13992 ,mem_vec_13993 ,mem_vec_13994 ,mem_vec_13995 ,mem_vec_13996 ,mem_vec_13997 ,mem_vec_13998 ,mem_vec_13999 ,mem_vec_14000 ,mem_vec_14001 ,mem_vec_14002 ,mem_vec_14003 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 512
// T (f, 2) (512 / 256)
for (f1553 = f1554, f1553_p_0 = 0;
	f1553 < f1554 + 512;
	f1553 += 256, f1553_p_0 += 256){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 256
	// T (x, 17) (17 / 1)
	for (x1553 = x1554, x1553_p_0 = 0;
		x1553 < x1554 + 17;
		x1553 += 1, x1553_p_0 += 1){
		// y = 17, x = 1, h = 1, w = 1, c = 1024, f = 256
		// T (c, 512) (1024 / 2)
		for (c1164 = c1165, c1164_p_0 = 0;
			c1164 < c1165 + 1024;
			c1164 += 2, c1164_p_0 += 2){
			// y = 17, x = 1, h = 1, w = 1, c = 2, f = 256
			// T (f, 4) (256 / 64)
			for (f1552 = f1553, f1552_p_1 = f1553_p_0, f1552_p_0 = 0;
				f1552 < f1553 + 256;
				f1552 += 64, f1552_p_1 += 64, f1552_p_0 += 64){
					for (y = y776, yp_0 = 0;
						y < y776 + 12;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x1552 = x1553, x1552_p_1 = x1553_p_0, x1552_p_0 = 0;
							x1552 < x1553 + 1;
							x1552 += 1, x1552_p_1 += 1, x1552_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1552, fp_2 = f1552_p_1, fp_1 = f1552_p_0, fp_0 = 0;
								f < f1552 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1552, xp_2 = x1552_p_1, xp_1 = x1552_p_0, xp_0 = 0;
									x < x1552 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13968 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13969 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13970 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13971 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13980 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13981 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13982 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13983 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1164, cp_1 = c1164_p_0, cp_0 = 0;
												c < c1164 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13968);
												mem_vec_13968 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13969);
												mem_vec_13969 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13970);
												mem_vec_13970 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13971);
												mem_vec_13971 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13972);
												mem_vec_13972 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13973);
												mem_vec_13973 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13974);
												mem_vec_13974 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13975);
												mem_vec_13975 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13976);
												mem_vec_13976 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13977);
												mem_vec_13977 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13978);
												mem_vec_13978 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13979);
												mem_vec_13979 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13980);
												mem_vec_13980 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13981);
												mem_vec_13981 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13982);
												mem_vec_13982 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13983);
												mem_vec_13983 = vec_23;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13968);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13969);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13970);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13971);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13972);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13973);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13974);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13975);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13976);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13977);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13978);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13979);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13980);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13981);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13982);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13983);
								}
							}
						}
					}
					for (y = y776 + 12, yp_0 = 0;
						y < y776 + 12 + 5;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
						// T (x, 1) (1 / 1)
						for (x1552 = x1553, x1552_p_1 = x1553_p_0, x1552_p_0 = 0;
							x1552 < x1553 + 1;
							x1552 += 1, x1552_p_1 += 1, x1552_p_0 += 1){
							// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1552, fp_2 = f1552_p_1, fp_1 = f1552_p_0, fp_0 = 0;
								f < f1552 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
								// T (x, 1) (1 / 1)
								for (x = x1552, xp_2 = x1552_p_1, xp_1 = x1552_p_0, xp_0 = 0;
									x < x1552 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_13984 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_13985 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
											mem_vec_13986 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_13987 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
											mem_vec_13988 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_13989 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
											mem_vec_13990 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_13991 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
											mem_vec_13992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_13993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
											mem_vec_13994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_13995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
											mem_vec_13996 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_13997 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
											mem_vec_13998 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_13999 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
											mem_vec_14000 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14001 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
											mem_vec_14002 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14003 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1164, cp_1 = c1164_p_0, cp_0 = 0;
												c < c1164 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm256_set1_ps(scal_0);
												vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13984);
												mem_vec_13984 = vec_0;

												vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

												vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13985);
												mem_vec_13985 = vec_3;

												vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13986);
												mem_vec_13986 = vec_5;

												vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

												vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13987);
												mem_vec_13987 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm256_set1_ps(scal_1);


												vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13988);
												mem_vec_13988 = vec_9;



												vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13989);
												mem_vec_13989 = vec_11;



												vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13990);
												mem_vec_13990 = vec_12;



												vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13991);
												mem_vec_13991 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm256_set1_ps(scal_2);


												vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13992);
												mem_vec_13992 = vec_14;



												vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13993);
												mem_vec_13993 = vec_16;



												vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13994);
												mem_vec_13994 = vec_17;



												vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13995);
												mem_vec_13995 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm256_set1_ps(scal_3);


												vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13996);
												mem_vec_13996 = vec_19;



												vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13997);
												mem_vec_13997 = vec_21;



												vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13998);
												mem_vec_13998 = vec_22;



												vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13999);
												mem_vec_13999 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm256_set1_ps(scal_4);


												vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14000);
												mem_vec_14000 = vec_24;



												vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14001);
												mem_vec_14001 = vec_26;



												vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14002);
												mem_vec_14002 = vec_27;



												vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14003);
												mem_vec_14003 = vec_28;
											}
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13984);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13985);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13986);
										_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13987);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13988);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13989);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13990);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13991);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13992);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13993);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13994);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13995);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13996);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13997);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13998);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13999);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14000);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14001);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14002);
										_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14003);
								}
							}
						}
					}
			}
		}
	}
}


}