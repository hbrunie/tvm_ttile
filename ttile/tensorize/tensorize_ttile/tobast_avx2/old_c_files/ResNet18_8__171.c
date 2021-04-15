#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (8, f); T (28, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f);
  T (8, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1030_p_0, cp_1, c1030, f, fp_0, f1018_p_0, f1019_p_0, fp_1, f1018_p_1, fp_2, f1018, f1019, w, wp_0, x, xp_0, x1206_p_0, x1207_p_0, xp_1, x1206_p_1, xp_2, x1206, x1207, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y612 = 0;
IND_TYPE x1208 = 0;
IND_TYPE h = 0;
IND_TYPE w498 = 0;
IND_TYPE c1031 = 0;
IND_TYPE f1020 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8012 ,mem_vec_8013 ,mem_vec_8014 ,mem_vec_8015 ,mem_vec_8016 ,mem_vec_8017 ,mem_vec_8018 ,mem_vec_8019 ,mem_vec_8020 ,mem_vec_8021 ,mem_vec_8022 ,mem_vec_8023 ,mem_vec_8024 ,mem_vec_8025 ,mem_vec_8026 ,mem_vec_8027 ,mem_vec_8028 ,mem_vec_8029 ,mem_vec_8030 ,mem_vec_8031 ,mem_vec_8032 ,mem_vec_8033 ,mem_vec_8034 ,mem_vec_8035 ,mem_vec_8036 ,mem_vec_8037 ,mem_vec_8038 ,mem_vec_8039 ,mem_vec_8040 ,mem_vec_8041 ,mem_vec_8042 ,mem_vec_8043 ,mem_vec_8044 ,mem_vec_8045 ,mem_vec_8046 ,mem_vec_8047 ,mem_vec_8048 ,mem_vec_8049 ,mem_vec_8050 ,mem_vec_8051 ,mem_vec_8052 ,mem_vec_8053 ,mem_vec_8054 ,mem_vec_8055 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1019 = f1020, f1019_p_0 = 0;
	f1019 < f1020 + 256;
	f1019 += 256, f1019_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
	// T (x, 1) (28 / 28)
	for (x1207 = x1208, x1207_p_0 = 0;
		x1207 < x1208 + 28;
		x1207 += 28, x1207_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
		// T (c, 8) (128 / 16)
		for (c1030 = c1031, c1030_p_0 = 0;
			c1030 < c1031 + 128;
			c1030 += 16, c1030_p_0 += 16){
			// y = 28, x = 28, h = 3, w = 3, c = 16, f = 256
			// T (f, 1) (256 / 256)
			for (f1018 = f1019, f1018_p_1 = f1019_p_0, f1018_p_0 = 0;
				f1018 < f1019 + 256;
				f1018 += 256, f1018_p_1 += 256, f1018_p_0 += 256){
					for (y = y612, yp_0 = 0;
						y < y612 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 256
						// T (x, 28) (28 / 1)
						for (x1206 = x1207, x1206_p_1 = x1207_p_0, x1206_p_0 = 0;
							x1206 < x1207 + 28;
							x1206 += 1, x1206_p_1 += 1, x1206_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1018, fp_2 = f1018_p_1, fp_1 = f1018_p_0, fp_0 = 0;
								f < f1018 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w498, wp_0 = 0;
									w < w498 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1206, xp_2 = x1206_p_1, xp_1 = x1206_p_0, xp_0 = 0;
										x < x1206 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8012 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8013 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8014 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8015 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8016 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8017 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8018 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8019 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8020 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8021 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8022 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8023 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8024 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8025 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8026 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8027 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8028 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8029 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8030 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8031 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1030, cp_1 = c1030_p_0, cp_0 = 0;
													c < c1030 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8012);
													mem_vec_8012 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8013);
													mem_vec_8013 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8014);
													mem_vec_8014 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8015);
													mem_vec_8015 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8016);
													mem_vec_8016 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8017);
													mem_vec_8017 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8018);
													mem_vec_8018 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8019);
													mem_vec_8019 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8020);
													mem_vec_8020 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8021);
													mem_vec_8021 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8022);
													mem_vec_8022 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8023);
													mem_vec_8023 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8024);
													mem_vec_8024 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8025);
													mem_vec_8025 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8026);
													mem_vec_8026 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8027);
													mem_vec_8027 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8028);
													mem_vec_8028 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8029);
													mem_vec_8029 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8030);
													mem_vec_8030 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8031);
													mem_vec_8031 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_8012);
													mem_vec_8012 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_8013);
													mem_vec_8013 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_8014);
													mem_vec_8014 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_8015);
													mem_vec_8015 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_8016);
													mem_vec_8016 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_8017);
													mem_vec_8017 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_8018);
													mem_vec_8018 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_8019);
													mem_vec_8019 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_8020);
													mem_vec_8020 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_8021);
													mem_vec_8021 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_8022);
													mem_vec_8022 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_8023);
													mem_vec_8023 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_8024);
													mem_vec_8024 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_8025);
													mem_vec_8025 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_8026);
													mem_vec_8026 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_8027);
													mem_vec_8027 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_8028);
													mem_vec_8028 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_8029);
													mem_vec_8029 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_8030);
													mem_vec_8030 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_8031);
													mem_vec_8031 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_8012);
													mem_vec_8012 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_8013);
													mem_vec_8013 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_8014);
													mem_vec_8014 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_8015);
													mem_vec_8015 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_8016);
													mem_vec_8016 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_8017);
													mem_vec_8017 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_8018);
													mem_vec_8018 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_8019);
													mem_vec_8019 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_8020);
													mem_vec_8020 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_8021);
													mem_vec_8021 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_8022);
													mem_vec_8022 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_8023);
													mem_vec_8023 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_8024);
													mem_vec_8024 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_8025);
													mem_vec_8025 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_8026);
													mem_vec_8026 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_8027);
													mem_vec_8027 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_8028);
													mem_vec_8028 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_8029);
													mem_vec_8029 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_8030);
													mem_vec_8030 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_8031);
													mem_vec_8031 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8012);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8013);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8014);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8015);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8016);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8017);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8018);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8019);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8020);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8021);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8022);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8023);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8024);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8025);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8026);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8027);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8028);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8029);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8030);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8031);
									}
								}
							}
						}
					}
					for (y = y612 + 10, yp_0 = 0;
						y < y612 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 28, h = 3, w = 3, c = 16, f = 256
						// T (x, 28) (28 / 1)
						for (x1206 = x1207, x1206_p_1 = x1207_p_0, x1206_p_0 = 0;
							x1206 < x1207 + 28;
							x1206 += 1, x1206_p_1 += 1, x1206_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1018, fp_2 = f1018_p_1, fp_1 = f1018_p_0, fp_0 = 0;
								f < f1018 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w498, wp_0 = 0;
									w < w498 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1206, xp_2 = x1206_p_1, xp_1 = x1206_p_0, xp_0 = 0;
										x < x1206 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8032 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8033 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8034 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8035 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8036 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8037 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8038 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8039 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8040 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8041 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8042 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8043 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8044 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8045 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8046 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8047 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8048 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8049 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8050 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8051 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_8052 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8053 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_8054 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8055 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1030, cp_1 = c1030_p_0, cp_0 = 0;
													c < c1030 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8032);
													mem_vec_8032 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8033);
													mem_vec_8033 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8034);
													mem_vec_8034 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8035);
													mem_vec_8035 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8036);
													mem_vec_8036 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8037);
													mem_vec_8037 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8038);
													mem_vec_8038 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8039);
													mem_vec_8039 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8040);
													mem_vec_8040 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8041);
													mem_vec_8041 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8042);
													mem_vec_8042 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8043);
													mem_vec_8043 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8044);
													mem_vec_8044 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8045);
													mem_vec_8045 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8046);
													mem_vec_8046 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8047);
													mem_vec_8047 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8048);
													mem_vec_8048 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8049);
													mem_vec_8049 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8050);
													mem_vec_8050 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8051);
													mem_vec_8051 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8052);
													mem_vec_8052 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8053);
													mem_vec_8053 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_8054);
													mem_vec_8054 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_8055);
													mem_vec_8055 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_8032);
													mem_vec_8032 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_8033);
													mem_vec_8033 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_8034);
													mem_vec_8034 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_8035);
													mem_vec_8035 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8036);
													mem_vec_8036 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_8037);
													mem_vec_8037 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_8038);
													mem_vec_8038 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_8039);
													mem_vec_8039 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_8040);
													mem_vec_8040 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_8041);
													mem_vec_8041 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_8042);
													mem_vec_8042 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_8043);
													mem_vec_8043 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_8044);
													mem_vec_8044 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_8045);
													mem_vec_8045 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_8046);
													mem_vec_8046 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_8047);
													mem_vec_8047 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8048);
													mem_vec_8048 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_8049);
													mem_vec_8049 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_8050);
													mem_vec_8050 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_8051);
													mem_vec_8051 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_8052);
													mem_vec_8052 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_8053);
													mem_vec_8053 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_8054);
													mem_vec_8054 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_8055);
													mem_vec_8055 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_8032);
													mem_vec_8032 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_8033);
													mem_vec_8033 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_8034);
													mem_vec_8034 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_8035);
													mem_vec_8035 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_8036);
													mem_vec_8036 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_8037);
													mem_vec_8037 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_8038);
													mem_vec_8038 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_8039);
													mem_vec_8039 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_8040);
													mem_vec_8040 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_8041);
													mem_vec_8041 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_8042);
													mem_vec_8042 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_8043);
													mem_vec_8043 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_8044);
													mem_vec_8044 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8045);
													mem_vec_8045 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8046);
													mem_vec_8046 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_8047);
													mem_vec_8047 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_8048);
													mem_vec_8048 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_8049);
													mem_vec_8049 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_8050);
													mem_vec_8050 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_8051);
													mem_vec_8051 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_8052);
													mem_vec_8052 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_8053);
													mem_vec_8053 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_8054);
													mem_vec_8054 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_8055);
													mem_vec_8055 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8032);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8033);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8034);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8035);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8036);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8037);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8038);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8039);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8040);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8041);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8042);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8043);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8044);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8045);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8046);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8047);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8048);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8049);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8050);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8051);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8052);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8053);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8054);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_8055);
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