#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (4, x);
  T (3, w); Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))];
  T (1, f); T (8, c); T (2, f); T (8, c); T (14, x); T (1, f)]
*/
IND_TYPE c, cp_0, c966_p_0, c967_p_0, cp_1, c966_p_1, cp_2, c966, c967, f, fp_0, f892_p_0, f893_p_0, fp_1, f892_p_1, fp_2, f892, f893, w, wp_0, x, xp_0, x840_p_0, xp_1, x840, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y516 = 0;
IND_TYPE x841 = 0;
IND_TYPE h = 0;
IND_TYPE w438 = 0;
IND_TYPE c968 = 0;
IND_TYPE f894 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7904 ,mem_vec_7905 ,mem_vec_7906 ,mem_vec_7907 ,mem_vec_7908 ,mem_vec_7909 ,mem_vec_7910 ,mem_vec_7911 ,mem_vec_7912 ,mem_vec_7913 ,mem_vec_7914 ,mem_vec_7915 ,mem_vec_7916 ,mem_vec_7917 ,mem_vec_7918 ,mem_vec_7919 ,mem_vec_7920 ,mem_vec_7921 ,mem_vec_7922 ,mem_vec_7923 ,mem_vec_7924 ,mem_vec_7925 ,mem_vec_7926 ,mem_vec_7927 ,mem_vec_7928 ,mem_vec_7929 ,mem_vec_7930 ,mem_vec_7931 ,mem_vec_7932 ,mem_vec_7933 ,mem_vec_7934 ,mem_vec_7935 ,mem_vec_7936 ,mem_vec_7937 ,mem_vec_7938 ,mem_vec_7939 ,mem_vec_7940 ,mem_vec_7941 ,mem_vec_7942 ,mem_vec_7943 ,mem_vec_7944 ,mem_vec_7945 ,mem_vec_7946 ,mem_vec_7947 ,mem_vec_7948 ,mem_vec_7949 ,mem_vec_7950 ,mem_vec_7951 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f893 = f894, f893_p_0 = 0;
	f893 < f894 + 64;
	f893 += 64, f893_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 14) (56 / 4)
	for (x840 = x841, x840_p_0 = 0;
		x840 < x841 + 56;
		x840 += 4, x840_p_0 += 4){
		// y = 56, x = 4, h = 3, w = 3, c = 64, f = 64
		// T (c, 8) (64 / 8)
		for (c967 = c968, c967_p_0 = 0;
			c967 < c968 + 64;
			c967 += 8, c967_p_0 += 8){
			// y = 56, x = 4, h = 3, w = 3, c = 8, f = 64
			// T (f, 2) (64 / 32)
			for (f892 = f893, f892_p_1 = f893_p_0, f892_p_0 = 0;
				f892 < f893 + 64;
				f892 += 32, f892_p_1 += 32, f892_p_0 += 32){
				// y = 56, x = 4, h = 3, w = 3, c = 8, f = 32
				// T (c, 8) (8 / 1)
				for (c966 = c967, c966_p_1 = c967_p_0, c966_p_0 = 0;
					c966 < c967 + 8;
					c966 += 1, c966_p_1 += 1, c966_p_0 += 1){
					// y = 56, x = 4, h = 3, w = 3, c = 1, f = 32
					// T (f, 1) (32 / 32)
					for (f = f892, fp_2 = f892_p_1, fp_1 = f892_p_0, fp_0 = 0;
						f < f892 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y516, yp_0 = 0;
								y < y516 + 35;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 4, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w438, wp_0 = 0;
									w < w438 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 1, f = 32
									// T (x, 4) (4 / 1)
									for (x = x840, xp_1 = x840_p_0, xp_0 = 0;
										x < x840 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7904 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7905 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_7906 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7907 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_7908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_7910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_7912 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7913 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_7914 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7915 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_7916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_7918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_7920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_7921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_7922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_7923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c966, cp_2 = c966_p_1, cp_1 = c966_p_0, cp_0 = 0;
													c < c966 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7904);
													mem_vec_7904 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7905);
													mem_vec_7905 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7906);
													mem_vec_7906 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7907);
													mem_vec_7907 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7908);
													mem_vec_7908 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7909);
													mem_vec_7909 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7910);
													mem_vec_7910 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7911);
													mem_vec_7911 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7912);
													mem_vec_7912 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7913);
													mem_vec_7913 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7914);
													mem_vec_7914 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7915);
													mem_vec_7915 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7916);
													mem_vec_7916 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7917);
													mem_vec_7917 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7918);
													mem_vec_7918 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7919);
													mem_vec_7919 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7920);
													mem_vec_7920 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7921);
													mem_vec_7921 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7922);
													mem_vec_7922 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7923);
													mem_vec_7923 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_7904);
													mem_vec_7904 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_7905);
													mem_vec_7905 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_7906);
													mem_vec_7906 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_7907);
													mem_vec_7907 = vec_36;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_7908);
													mem_vec_7908 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_7909);
													mem_vec_7909 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_7910);
													mem_vec_7910 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_7911);
													mem_vec_7911 = vec_42;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_7912);
													mem_vec_7912 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_7913);
													mem_vec_7913 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_7914);
													mem_vec_7914 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_7915);
													mem_vec_7915 = vec_47;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_7916);
													mem_vec_7916 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_7917);
													mem_vec_7917 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_7918);
													mem_vec_7918 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_7919);
													mem_vec_7919 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_7920);
													mem_vec_7920 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_7921);
													mem_vec_7921 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_7922);
													mem_vec_7922 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_7923);
													mem_vec_7923 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_7904);
													mem_vec_7904 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_7905);
													mem_vec_7905 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_7906);
													mem_vec_7906 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_7907);
													mem_vec_7907 = vec_65;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_7908);
													mem_vec_7908 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_7909);
													mem_vec_7909 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_7910);
													mem_vec_7910 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_7911);
													mem_vec_7911 = vec_71;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_7912);
													mem_vec_7912 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_7913);
													mem_vec_7913 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_7914);
													mem_vec_7914 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_7915);
													mem_vec_7915 = vec_76;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_7916);
													mem_vec_7916 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_7917);
													mem_vec_7917 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_7918);
													mem_vec_7918 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_7919);
													mem_vec_7919 = vec_81;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_7920);
													mem_vec_7920 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_7921);
													mem_vec_7921 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_7922);
													mem_vec_7922 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_7923);
													mem_vec_7923 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7904);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7905);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7906);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7907);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7908);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7909);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7910);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7911);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7912);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7913);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7914);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7915);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7916);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7917);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7918);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7919);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7920);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7921);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7922);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7923);
									}
								}
							}
							for (y = y516 + 35, yp_0 = 0;
								y < y516 + 35 + 21;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 4, h = 3, w = 3, c = 1, f = 32
								// T (w, 3) (3 / 1)
								for (w = w438, wp_0 = 0;
									w < w438 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 1, f = 32
									// T (x, 4) (4 / 1)
									for (x = x840, xp_1 = x840_p_0, xp_0 = 0;
										x < x840 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7924 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7925 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_7926 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7927 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_7928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_7930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_7932 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7933 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_7934 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7935 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_7936 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7937 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_7938 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7939 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_7940 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_7941 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_7942 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_7943 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_7944 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_7945 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_7946 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_7947 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_7948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_7949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_7950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_7951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c966, cp_2 = c966_p_1, cp_1 = c966_p_0, cp_0 = 0;
													c < c966 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7924);
													mem_vec_7924 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7925);
													mem_vec_7925 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7926);
													mem_vec_7926 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7927);
													mem_vec_7927 = vec_7;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7928);
													mem_vec_7928 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7929);
													mem_vec_7929 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7930);
													mem_vec_7930 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7931);
													mem_vec_7931 = vec_13;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7932);
													mem_vec_7932 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7933);
													mem_vec_7933 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7934);
													mem_vec_7934 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7935);
													mem_vec_7935 = vec_18;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7936);
													mem_vec_7936 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7937);
													mem_vec_7937 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7938);
													mem_vec_7938 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7939);
													mem_vec_7939 = vec_23;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7940);
													mem_vec_7940 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7941);
													mem_vec_7941 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7942);
													mem_vec_7942 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7943);
													mem_vec_7943 = vec_28;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7944);
													mem_vec_7944 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7945);
													mem_vec_7945 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_7946);
													mem_vec_7946 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_7947);
													mem_vec_7947 = vec_33;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_7948);
													mem_vec_7948 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_7949);
													mem_vec_7949 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_7950);
													mem_vec_7950 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_7951);
													mem_vec_7951 = vec_38;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_7924);
													mem_vec_7924 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_7925);
													mem_vec_7925 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_7926);
													mem_vec_7926 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_7927);
													mem_vec_7927 = vec_46;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_7928);
													mem_vec_7928 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_7929);
													mem_vec_7929 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_7930);
													mem_vec_7930 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_7931);
													mem_vec_7931 = vec_52;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_7932);
													mem_vec_7932 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_7933);
													mem_vec_7933 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_7934);
													mem_vec_7934 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_7935);
													mem_vec_7935 = vec_57;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_7936);
													mem_vec_7936 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_7937);
													mem_vec_7937 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_7938);
													mem_vec_7938 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_7939);
													mem_vec_7939 = vec_62;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_7940);
													mem_vec_7940 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_7941);
													mem_vec_7941 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_7942);
													mem_vec_7942 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_7943);
													mem_vec_7943 = vec_67;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_7944);
													mem_vec_7944 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_7945);
													mem_vec_7945 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_7946);
													mem_vec_7946 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_7947);
													mem_vec_7947 = vec_72;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_7948);
													mem_vec_7948 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_7949);
													mem_vec_7949 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_7950);
													mem_vec_7950 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_7951);
													mem_vec_7951 = vec_77;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_7924);
													mem_vec_7924 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_7925);
													mem_vec_7925 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_7926);
													mem_vec_7926 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_7927);
													mem_vec_7927 = vec_85;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_7928);
													mem_vec_7928 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_7929);
													mem_vec_7929 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_7930);
													mem_vec_7930 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_7931);
													mem_vec_7931 = vec_91;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_7932);
													mem_vec_7932 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_7933);
													mem_vec_7933 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_7934);
													mem_vec_7934 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_7935);
													mem_vec_7935 = vec_96;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_7936);
													mem_vec_7936 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_7937);
													mem_vec_7937 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_7938);
													mem_vec_7938 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_7939);
													mem_vec_7939 = vec_101;
													scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_7940);
													mem_vec_7940 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_7941);
													mem_vec_7941 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_7942);
													mem_vec_7942 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_7943);
													mem_vec_7943 = vec_106;
													scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_7944);
													mem_vec_7944 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_7945);
													mem_vec_7945 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_7946);
													mem_vec_7946 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_7947);
													mem_vec_7947 = vec_111;
													scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_7948);
													mem_vec_7948 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_7949);
													mem_vec_7949 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_7950);
													mem_vec_7950 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_7951);
													mem_vec_7951 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7924);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7925);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7926);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7927);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7928);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7929);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7930);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7931);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7932);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7933);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7934);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7935);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7936);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7937);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7938);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7939);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7940);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7941);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7942);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7943);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7944);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7945);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7946);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_7947);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7948);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_7949);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7950);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_7951);
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