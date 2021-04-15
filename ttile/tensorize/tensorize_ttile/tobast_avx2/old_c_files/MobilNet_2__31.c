#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (4, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))];
  T (1, f); T (1, c); T (1, f); T (8, c); T (14, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1214_p_0, c1215_p_0, cp_1, c1214_p_1, cp_2, c1214, c1215, f, fp_0, f1140_p_0, f1141_p_0, fp_1, f1140_p_1, fp_2, f1140, f1141, h, hp_0, x, xp_0, x1026_p_0, xp_1, x1026, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y640 = 0;
IND_TYPE x1027 = 0;
IND_TYPE h424 = 0;
IND_TYPE w = 0;
IND_TYPE c1216 = 0;
IND_TYPE f1142 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10936 ,mem_vec_10937 ,mem_vec_10938 ,mem_vec_10939 ,mem_vec_10940 ,mem_vec_10941 ,mem_vec_10942 ,mem_vec_10943 ,mem_vec_10944 ,mem_vec_10945 ,mem_vec_10946 ,mem_vec_10947 ,mem_vec_10948 ,mem_vec_10949 ,mem_vec_10950 ,mem_vec_10951 ,mem_vec_10952 ,mem_vec_10953 ,mem_vec_10954 ,mem_vec_10955 ,mem_vec_10956 ,mem_vec_10957 ,mem_vec_10958 ,mem_vec_10959 ,mem_vec_10960 ,mem_vec_10961 ,mem_vec_10962 ,mem_vec_10963 ,mem_vec_10964 ,mem_vec_10965 ,mem_vec_10966 ,mem_vec_10967 ,mem_vec_10968 ,mem_vec_10969 ,mem_vec_10970 ,mem_vec_10971 ,mem_vec_10972 ,mem_vec_10973 ,mem_vec_10974 ,mem_vec_10975 ,mem_vec_10976 ,mem_vec_10977 ,mem_vec_10978 ,mem_vec_10979 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 2) (64 / 32)
for (f1141 = f1142, f1141_p_0 = 0;
	f1141 < f1142 + 64;
	f1141 += 32, f1141_p_0 += 32){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 32
	// T (x, 14) (56 / 4)
	for (x1026 = x1027, x1026_p_0 = 0;
		x1026 < x1027 + 56;
		x1026 += 4, x1026_p_0 += 4){
		// y = 56, x = 4, h = 3, w = 3, c = 64, f = 32
		// T (c, 8) (64 / 8)
		for (c1215 = c1216, c1215_p_0 = 0;
			c1215 < c1216 + 64;
			c1215 += 8, c1215_p_0 += 8){
			// y = 56, x = 4, h = 3, w = 3, c = 8, f = 32
			// T (f, 1) (32 / 32)
			for (f1140 = f1141, f1140_p_1 = f1141_p_0, f1140_p_0 = 0;
				f1140 < f1141 + 32;
				f1140 += 32, f1140_p_1 += 32, f1140_p_0 += 32){
				// y = 56, x = 4, h = 3, w = 3, c = 8, f = 32
				// T (c, 1) (8 / 8)
				for (c1214 = c1215, c1214_p_1 = c1215_p_0, c1214_p_0 = 0;
					c1214 < c1215 + 8;
					c1214 += 8, c1214_p_1 += 8, c1214_p_0 += 8){
					// y = 56, x = 4, h = 3, w = 3, c = 8, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1140, fp_2 = f1140_p_1, fp_1 = f1140_p_0, fp_0 = 0;
						f < f1140 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y640, yp_0 = 0;
								y < y640 + 28;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h424, hp_0 = 0;
									h < h424 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1026, xp_1 = x1026_p_0, xp_0 = 0;
										x < x1026 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10936 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10937 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10938 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10939 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1214, cp_2 = c1214_p_1, cp_1 = c1214_p_0, cp_0 = 0;
													c < c1214 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10936);
													mem_vec_10936 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10937);
													mem_vec_10937 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10938);
													mem_vec_10938 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10939);
													mem_vec_10939 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10940);
													mem_vec_10940 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10941);
													mem_vec_10941 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10942);
													mem_vec_10942 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10943);
													mem_vec_10943 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10944);
													mem_vec_10944 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10945);
													mem_vec_10945 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10946);
													mem_vec_10946 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10947);
													mem_vec_10947 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10948);
													mem_vec_10948 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10949);
													mem_vec_10949 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10950);
													mem_vec_10950 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10951);
													mem_vec_10951 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_10936);
													mem_vec_10936 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_10937);
													mem_vec_10937 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_10938);
													mem_vec_10938 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_10939);
													mem_vec_10939 = vec_31;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_10940);
													mem_vec_10940 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_10941);
													mem_vec_10941 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_10942);
													mem_vec_10942 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_10943);
													mem_vec_10943 = vec_37;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_10944);
													mem_vec_10944 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_10945);
													mem_vec_10945 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_10946);
													mem_vec_10946 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_10947);
													mem_vec_10947 = vec_42;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_10948);
													mem_vec_10948 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_10949);
													mem_vec_10949 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_10950);
													mem_vec_10950 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_10951);
													mem_vec_10951 = vec_47;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_10936);
													mem_vec_10936 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_10937);
													mem_vec_10937 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_10938);
													mem_vec_10938 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_10939);
													mem_vec_10939 = vec_55;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_10940);
													mem_vec_10940 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_10941);
													mem_vec_10941 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_10942);
													mem_vec_10942 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_10943);
													mem_vec_10943 = vec_61;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_10944);
													mem_vec_10944 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_10945);
													mem_vec_10945 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_10946);
													mem_vec_10946 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_10947);
													mem_vec_10947 = vec_66;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_10948);
													mem_vec_10948 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_10949);
													mem_vec_10949 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_10950);
													mem_vec_10950 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_10951);
													mem_vec_10951 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10936);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10937);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10938);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10939);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10940);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10941);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10942);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10943);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10944);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10945);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10946);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10947);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10948);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10949);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10950);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10951);
									}
								}
							}
							for (y = y640 + 28, yp_0 = 0;
								y < y640 + 28 + 28;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 4, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h424, hp_0 = 0;
									h < h424 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 8, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1026, xp_1 = x1026_p_0, xp_0 = 0;
										x < x1026 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10952 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10953 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10954 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10955 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10960 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10961 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10968 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10969 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10970 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10971 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_10972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_10974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_10976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_10977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_10978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_10979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1214, cp_2 = c1214_p_1, cp_1 = c1214_p_0, cp_0 = 0;
													c < c1214 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10952);
													mem_vec_10952 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10953);
													mem_vec_10953 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10954);
													mem_vec_10954 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10955);
													mem_vec_10955 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10956);
													mem_vec_10956 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10957);
													mem_vec_10957 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10958);
													mem_vec_10958 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10959);
													mem_vec_10959 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10960);
													mem_vec_10960 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10961);
													mem_vec_10961 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10962);
													mem_vec_10962 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10963);
													mem_vec_10963 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10964);
													mem_vec_10964 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10965);
													mem_vec_10965 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10966);
													mem_vec_10966 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10967);
													mem_vec_10967 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10968);
													mem_vec_10968 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10969);
													mem_vec_10969 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10970);
													mem_vec_10970 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10971);
													mem_vec_10971 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10972);
													mem_vec_10972 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10973);
													mem_vec_10973 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10974);
													mem_vec_10974 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10975);
													mem_vec_10975 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_10976);
													mem_vec_10976 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_10977);
													mem_vec_10977 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_10978);
													mem_vec_10978 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_10979);
													mem_vec_10979 = vec_38;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_10952);
													mem_vec_10952 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_10953);
													mem_vec_10953 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_10954);
													mem_vec_10954 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_10955);
													mem_vec_10955 = vec_46;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_10956);
													mem_vec_10956 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_10957);
													mem_vec_10957 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_10958);
													mem_vec_10958 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_10959);
													mem_vec_10959 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_10960);
													mem_vec_10960 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_10961);
													mem_vec_10961 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_10962);
													mem_vec_10962 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_10963);
													mem_vec_10963 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_10964);
													mem_vec_10964 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_10965);
													mem_vec_10965 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_10966);
													mem_vec_10966 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_10967);
													mem_vec_10967 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_10968);
													mem_vec_10968 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_10969);
													mem_vec_10969 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_10970);
													mem_vec_10970 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_10971);
													mem_vec_10971 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_10972);
													mem_vec_10972 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_10973);
													mem_vec_10973 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_10974);
													mem_vec_10974 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_10975);
													mem_vec_10975 = vec_72;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_10976);
													mem_vec_10976 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_10977);
													mem_vec_10977 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_10978);
													mem_vec_10978 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_10979);
													mem_vec_10979 = vec_77;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_10952);
													mem_vec_10952 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_10953);
													mem_vec_10953 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_10954);
													mem_vec_10954 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_10955);
													mem_vec_10955 = vec_85;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_10956);
													mem_vec_10956 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_10957);
													mem_vec_10957 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_10958);
													mem_vec_10958 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_10959);
													mem_vec_10959 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_10960);
													mem_vec_10960 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_10961);
													mem_vec_10961 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_10962);
													mem_vec_10962 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_10963);
													mem_vec_10963 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_10964);
													mem_vec_10964 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_10965);
													mem_vec_10965 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_10966);
													mem_vec_10966 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_10967);
													mem_vec_10967 = vec_101;
													scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_10968);
													mem_vec_10968 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_10969);
													mem_vec_10969 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_10970);
													mem_vec_10970 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_10971);
													mem_vec_10971 = vec_106;
													scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_10972);
													mem_vec_10972 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_10973);
													mem_vec_10973 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_10974);
													mem_vec_10974 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_10975);
													mem_vec_10975 = vec_111;
													scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_10976);
													mem_vec_10976 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_10977);
													mem_vec_10977 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_10978);
													mem_vec_10978 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_10979);
													mem_vec_10979 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10952);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10953);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10954);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10955);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10956);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10957);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10958);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10959);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10960);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10961);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10962);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10963);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10964);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10965);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10966);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10967);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10968);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10969);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10970);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10971);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10972);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10973);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10974);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10975);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10976);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_10977);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10978);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_10979);
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