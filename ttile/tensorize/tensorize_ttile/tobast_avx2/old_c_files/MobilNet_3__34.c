#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (7, x);
  Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))]; T (4, f);
  T (64, c); T (8, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1124_p_0, cp_1, c1124, f, fp_0, f1152_p_0, f1153_p_0, fp_1, f1152_p_1, fp_2, f1152, f1153, h, hp_0, x, xp_0, x1360_p_0, x1361_p_0, xp_1, x1360_p_1, xp_2, x1360, x1361, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y680 = 0;
IND_TYPE x1362 = 0;
IND_TYPE h442 = 0;
IND_TYPE w = 0;
IND_TYPE c1125 = 0;
IND_TYPE f1154 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11936 ,mem_vec_11937 ,mem_vec_11938 ,mem_vec_11939 ,mem_vec_11940 ,mem_vec_11941 ,mem_vec_11942 ,mem_vec_11943 ,mem_vec_11944 ,mem_vec_11945 ,mem_vec_11946 ,mem_vec_11947 ,mem_vec_11948 ,mem_vec_11949 ,mem_vec_11950 ,mem_vec_11951 ,mem_vec_11952 ,mem_vec_11953 ,mem_vec_11954 ,mem_vec_11955 ,mem_vec_11956 ,mem_vec_11957 ,mem_vec_11958 ,mem_vec_11959 ,mem_vec_11960 ,mem_vec_11961 ,mem_vec_11962 ,mem_vec_11963 ,mem_vec_11964 ,mem_vec_11965 ,mem_vec_11966 ,mem_vec_11967 ,mem_vec_11968 ,mem_vec_11969 ,mem_vec_11970 ,mem_vec_11971 ,mem_vec_11972 ,mem_vec_11973 ,mem_vec_11974 ,mem_vec_11975 ,mem_vec_11976 ,mem_vec_11977 ,mem_vec_11978 ,mem_vec_11979 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f1153 = f1154, f1153_p_0 = 0;
	f1153 < f1154 + 128;
	f1153 += 128, f1153_p_0 += 128){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (x, 8) (56 / 7)
	for (x1361 = x1362, x1361_p_0 = 0;
		x1361 < x1362 + 56;
		x1361 += 7, x1361_p_0 += 7){
		// y = 56, x = 7, h = 3, w = 3, c = 128, f = 128
		// T (c, 64) (128 / 2)
		for (c1124 = c1125, c1124_p_0 = 0;
			c1124 < c1125 + 128;
			c1124 += 2, c1124_p_0 += 2){
			// y = 56, x = 7, h = 3, w = 3, c = 2, f = 128
			// T (f, 4) (128 / 32)
			for (f1152 = f1153, f1152_p_1 = f1153_p_0, f1152_p_0 = 0;
				f1152 < f1153 + 128;
				f1152 += 32, f1152_p_1 += 32, f1152_p_0 += 32){
					for (y = y680, yp_0 = 0;
						y < y680 + 28;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 32
						// T (x, 7) (7 / 1)
						for (x1360 = x1361, x1360_p_1 = x1361_p_0, x1360_p_0 = 0;
							x1360 < x1361 + 7;
							x1360 += 1, x1360_p_1 += 1, x1360_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1152, fp_2 = f1152_p_1, fp_1 = f1152_p_0, fp_0 = 0;
								f < f1152 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h442, hp_0 = 0;
									h < h442 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1360, xp_2 = x1360_p_1, xp_1 = x1360_p_0, xp_0 = 0;
										x < x1360 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11936 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11937 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11938 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11939 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1124, cp_1 = c1124_p_0, cp_0 = 0;
													c < c1124 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11936);
													mem_vec_11936 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11937);
													mem_vec_11937 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11938);
													mem_vec_11938 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11939);
													mem_vec_11939 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11940);
													mem_vec_11940 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11941);
													mem_vec_11941 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11942);
													mem_vec_11942 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11943);
													mem_vec_11943 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11944);
													mem_vec_11944 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11945);
													mem_vec_11945 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11946);
													mem_vec_11946 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11947);
													mem_vec_11947 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11948);
													mem_vec_11948 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11949);
													mem_vec_11949 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11950);
													mem_vec_11950 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11951);
													mem_vec_11951 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11936);
													mem_vec_11936 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11937);
													mem_vec_11937 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11938);
													mem_vec_11938 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11939);
													mem_vec_11939 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11940);
													mem_vec_11940 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11941);
													mem_vec_11941 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11942);
													mem_vec_11942 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11943);
													mem_vec_11943 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11944);
													mem_vec_11944 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11945);
													mem_vec_11945 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11946);
													mem_vec_11946 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11947);
													mem_vec_11947 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11948);
													mem_vec_11948 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11949);
													mem_vec_11949 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11950);
													mem_vec_11950 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11951);
													mem_vec_11951 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11936);
													mem_vec_11936 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11937);
													mem_vec_11937 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11938);
													mem_vec_11938 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11939);
													mem_vec_11939 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11940);
													mem_vec_11940 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11941);
													mem_vec_11941 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11942);
													mem_vec_11942 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11943);
													mem_vec_11943 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11944);
													mem_vec_11944 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11945);
													mem_vec_11945 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11946);
													mem_vec_11946 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11947);
													mem_vec_11947 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11948);
													mem_vec_11948 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11949);
													mem_vec_11949 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11950);
													mem_vec_11950 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11951);
													mem_vec_11951 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11936);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11937);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11938);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11939);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11940);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11941);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11942);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11943);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11944);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11945);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11946);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11947);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11948);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11949);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11950);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11951);
									}
								}
							}
						}
					}
					for (y = y680 + 28, yp_0 = 0;
						y < y680 + 28 + 28;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 32
						// T (x, 7) (7 / 1)
						for (x1360 = x1361, x1360_p_1 = x1361_p_0, x1360_p_0 = 0;
							x1360 < x1361 + 7;
							x1360 += 1, x1360_p_1 += 1, x1360_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (f, 1) (32 / 32)
							for (f = f1152, fp_2 = f1152_p_1, fp_1 = f1152_p_0, fp_0 = 0;
								f < f1152 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h442, hp_0 = 0;
									h < h442 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1360, xp_2 = x1360_p_1, xp_1 = x1360_p_0, xp_0 = 0;
										x < x1360 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11952 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11953 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11954 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11955 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11960 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11961 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11968 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11969 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11970 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11971 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_11972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_11976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_11978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1124, cp_1 = c1124_p_0, cp_0 = 0;
													c < c1124 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11952);
													mem_vec_11952 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11953);
													mem_vec_11953 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11954);
													mem_vec_11954 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11955);
													mem_vec_11955 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11956);
													mem_vec_11956 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11957);
													mem_vec_11957 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11958);
													mem_vec_11958 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11959);
													mem_vec_11959 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11960);
													mem_vec_11960 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11961);
													mem_vec_11961 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11962);
													mem_vec_11962 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11963);
													mem_vec_11963 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11964);
													mem_vec_11964 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11965);
													mem_vec_11965 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11966);
													mem_vec_11966 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11967);
													mem_vec_11967 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11968);
													mem_vec_11968 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11969);
													mem_vec_11969 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11970);
													mem_vec_11970 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11971);
													mem_vec_11971 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11972);
													mem_vec_11972 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11973);
													mem_vec_11973 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11974);
													mem_vec_11974 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11975);
													mem_vec_11975 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_11976);
													mem_vec_11976 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_11977);
													mem_vec_11977 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_11978);
													mem_vec_11978 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_11979);
													mem_vec_11979 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_11952);
													mem_vec_11952 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_11953);
													mem_vec_11953 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_11954);
													mem_vec_11954 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_11955);
													mem_vec_11955 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_11956);
													mem_vec_11956 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_11957);
													mem_vec_11957 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_11958);
													mem_vec_11958 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_11959);
													mem_vec_11959 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_11960);
													mem_vec_11960 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_11961);
													mem_vec_11961 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_11962);
													mem_vec_11962 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_11963);
													mem_vec_11963 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_11964);
													mem_vec_11964 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_11965);
													mem_vec_11965 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_11966);
													mem_vec_11966 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_11967);
													mem_vec_11967 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_11968);
													mem_vec_11968 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_11969);
													mem_vec_11969 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_11970);
													mem_vec_11970 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_11971);
													mem_vec_11971 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_11972);
													mem_vec_11972 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_11973);
													mem_vec_11973 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_11974);
													mem_vec_11974 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_11975);
													mem_vec_11975 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_11976);
													mem_vec_11976 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_11977);
													mem_vec_11977 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_11978);
													mem_vec_11978 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_11979);
													mem_vec_11979 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_11952);
													mem_vec_11952 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_11953);
													mem_vec_11953 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_11954);
													mem_vec_11954 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_11955);
													mem_vec_11955 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_11956);
													mem_vec_11956 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_11957);
													mem_vec_11957 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_11958);
													mem_vec_11958 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_11959);
													mem_vec_11959 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_11960);
													mem_vec_11960 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_11961);
													mem_vec_11961 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_11962);
													mem_vec_11962 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_11963);
													mem_vec_11963 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_11964);
													mem_vec_11964 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_11965);
													mem_vec_11965 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_11966);
													mem_vec_11966 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_11967);
													mem_vec_11967 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_11968);
													mem_vec_11968 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_11969);
													mem_vec_11969 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_11970);
													mem_vec_11970 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_11971);
													mem_vec_11971 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_11972);
													mem_vec_11972 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_11973);
													mem_vec_11973 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_11974);
													mem_vec_11974 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_11975);
													mem_vec_11975 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_11976);
													mem_vec_11976 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_11977);
													mem_vec_11977 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_11978);
													mem_vec_11978 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_11979);
													mem_vec_11979 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11952);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11953);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11954);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11955);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11956);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11957);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11958);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11959);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11960);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11961);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11962);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11963);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11964);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11965);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11966);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11967);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11968);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11969);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11970);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11971);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11972);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11973);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11974);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11975);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11976);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_11977);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11978);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_11979);
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