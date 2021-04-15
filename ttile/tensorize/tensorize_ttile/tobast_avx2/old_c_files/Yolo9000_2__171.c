#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, w); Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))];
  T (2, f); T (16, c); T (136, x); T (16, y); T (1, f); T (2, x)]
*/
IND_TYPE c, cp_0, c750_p_0, cp_1, c750, f, fp_0, f622_p_0, fp_1, f622, w, wp_0, x, xp_0, x1000_p_0, x1001_p_0, xp_1, x1000_p_1, xp_2, x1000, x1001, y, yp_0, y750_p_0, yp_1, y750;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y751 = 0;
IND_TYPE x1002 = 0;
IND_TYPE h = 0;
IND_TYPE w450 = 0;
IND_TYPE c751 = 0;
IND_TYPE f623 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6944 ,mem_vec_6945 ,mem_vec_6946 ,mem_vec_6947 ,mem_vec_6948 ,mem_vec_6949 ,mem_vec_6950 ,mem_vec_6951 ,mem_vec_6952 ,mem_vec_6953 ,mem_vec_6954 ,mem_vec_6955 ,mem_vec_6956 ,mem_vec_6957 ,mem_vec_6958 ,mem_vec_6959 ,mem_vec_6960 ,mem_vec_6961 ,mem_vec_6962 ,mem_vec_6963 ,mem_vec_6964 ,mem_vec_6965 ,mem_vec_6966 ,mem_vec_6967 ,mem_vec_6968 ,mem_vec_6969 ,mem_vec_6970 ,mem_vec_6971 ,mem_vec_6972 ,mem_vec_6973 ,mem_vec_6974 ,mem_vec_6975 ,mem_vec_6976 ,mem_vec_6977 ,mem_vec_6978 ,mem_vec_6979 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x1001 = x1002, x1001_p_0 = 0;
	x1001 < x1002 + 272;
	x1001 += 136, x1001_p_0 += 136){
	// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
	// T (f, 1) (64 / 64)
	for (f622 = f623, f622_p_0 = 0;
		f622 < f623 + 64;
		f622 += 64, f622_p_0 += 64){
		// y = 272, x = 136, h = 3, w = 3, c = 32, f = 64
		// T (y, 16) (272 / 17)
		for (y750 = y751, y750_p_0 = 0;
			y750 < y751 + 272;
			y750 += 17, y750_p_0 += 17){
			// y = 17, x = 136, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (136 / 1)
			for (x1000 = x1001, x1000_p_1 = x1001_p_0, x1000_p_0 = 0;
				x1000 < x1001 + 136;
				x1000 += 1, x1000_p_1 += 1, x1000_p_0 += 1){
				// y = 17, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 16) (32 / 2)
				for (c750 = c751, c750_p_0 = 0;
					c750 < c751 + 32;
					c750 += 2, c750_p_0 += 2){
					// y = 17, x = 1, h = 3, w = 3, c = 2, f = 64
					// T (f, 2) (64 / 32)
					for (f = f622, fp_1 = f622_p_0, fp_0 = 0;
						f < f622 + 64;
						f += 32, fp_1 += 32, fp_0 += 32){
							for (y = y750, yp_1 = y750_p_0, yp_0 = 0;
								y < y750 + 12;
								y += 4, yp_1 += 4, yp_0 += 4){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w450, wp_0 = 0;
									w < w450 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1000, xp_2 = x1000_p_1, xp_1 = x1000_p_0, xp_0 = 0;
										x < x1000 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6944 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6945 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_6946 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6947 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_6948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_6952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_6954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_6956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_6958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c750, cp_1 = c750_p_0, cp_0 = 0;
													c < c750 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6944);
													mem_vec_6944 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6945);
													mem_vec_6945 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6946);
													mem_vec_6946 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6947);
													mem_vec_6947 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6948);
													mem_vec_6948 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6949);
													mem_vec_6949 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6950);
													mem_vec_6950 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6951);
													mem_vec_6951 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6952);
													mem_vec_6952 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6953);
													mem_vec_6953 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6954);
													mem_vec_6954 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6955);
													mem_vec_6955 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6956);
													mem_vec_6956 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6957);
													mem_vec_6957 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6958);
													mem_vec_6958 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6959);
													mem_vec_6959 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_6944);
													mem_vec_6944 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_6945);
													mem_vec_6945 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_6946);
													mem_vec_6946 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_6947);
													mem_vec_6947 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_6948);
													mem_vec_6948 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_6949);
													mem_vec_6949 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_6950);
													mem_vec_6950 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_6951);
													mem_vec_6951 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_6952);
													mem_vec_6952 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_6953);
													mem_vec_6953 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_6954);
													mem_vec_6954 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_6955);
													mem_vec_6955 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_6956);
													mem_vec_6956 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6957);
													mem_vec_6957 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6958);
													mem_vec_6958 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_6959);
													mem_vec_6959 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_6944);
													mem_vec_6944 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_6945);
													mem_vec_6945 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_6946);
													mem_vec_6946 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_6947);
													mem_vec_6947 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_6948);
													mem_vec_6948 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_6949);
													mem_vec_6949 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6950);
													mem_vec_6950 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6951);
													mem_vec_6951 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_6952);
													mem_vec_6952 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_6953);
													mem_vec_6953 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_6954);
													mem_vec_6954 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_6955);
													mem_vec_6955 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_6956);
													mem_vec_6956 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_6957);
													mem_vec_6957 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_6958);
													mem_vec_6958 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_6959);
													mem_vec_6959 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6944);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6945);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6946);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6947);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6948);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6949);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6950);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6951);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6952);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6953);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6954);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6955);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6956);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6957);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6958);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6959);
									}
								}
							}
							for (y = y750 + 12, yp_1 = y750_p_0, yp_0 = 0;
								y < y750 + 12 + 5;
								y += 5, yp_1 += 5, yp_0 += 5){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (w, 3) (3 / 1)
								for (w = w450, wp_0 = 0;
									w < w450 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1000, xp_2 = x1000_p_1, xp_1 = x1000_p_0, xp_0 = 0;
										x < x1000 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6960 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6961 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_6962 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6963 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_6964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_6968 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6969 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_6970 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6971 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_6972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_6974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_6976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_6978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c750, cp_1 = c750_p_0, cp_0 = 0;
													c < c750 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6960);
													mem_vec_6960 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6961);
													mem_vec_6961 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6962);
													mem_vec_6962 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6963);
													mem_vec_6963 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6964);
													mem_vec_6964 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6965);
													mem_vec_6965 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6966);
													mem_vec_6966 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6967);
													mem_vec_6967 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6968);
													mem_vec_6968 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6969);
													mem_vec_6969 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6970);
													mem_vec_6970 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6971);
													mem_vec_6971 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6972);
													mem_vec_6972 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6973);
													mem_vec_6973 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6974);
													mem_vec_6974 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6975);
													mem_vec_6975 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6976);
													mem_vec_6976 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6977);
													mem_vec_6977 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6978);
													mem_vec_6978 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6979);
													mem_vec_6979 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_6960);
													mem_vec_6960 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_6961);
													mem_vec_6961 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_6962);
													mem_vec_6962 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_6963);
													mem_vec_6963 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_6964);
													mem_vec_6964 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_6965);
													mem_vec_6965 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_6966);
													mem_vec_6966 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_6967);
													mem_vec_6967 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_6968);
													mem_vec_6968 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_6969);
													mem_vec_6969 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_6970);
													mem_vec_6970 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_6971);
													mem_vec_6971 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_6972);
													mem_vec_6972 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_6973);
													mem_vec_6973 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_6974);
													mem_vec_6974 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_6975);
													mem_vec_6975 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_6976);
													mem_vec_6976 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_6977);
													mem_vec_6977 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_6978);
													mem_vec_6978 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_6979);
													mem_vec_6979 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_6960);
													mem_vec_6960 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_6961);
													mem_vec_6961 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_6962);
													mem_vec_6962 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_6963);
													mem_vec_6963 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_6964);
													mem_vec_6964 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_6965);
													mem_vec_6965 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_6966);
													mem_vec_6966 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_6967);
													mem_vec_6967 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_6968);
													mem_vec_6968 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_6969);
													mem_vec_6969 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_6970);
													mem_vec_6970 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_6971);
													mem_vec_6971 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_6972);
													mem_vec_6972 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_6973);
													mem_vec_6973 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_6974);
													mem_vec_6974 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_6975);
													mem_vec_6975 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_6976);
													mem_vec_6976 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_6977);
													mem_vec_6977 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_6978);
													mem_vec_6978 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_6979);
													mem_vec_6979 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6960);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6961);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6962);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6963);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6964);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6965);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6966);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6967);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6968);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6969);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6970);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6971);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6972);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6973);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6974);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6975);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6976);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6977);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6978);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6979);
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