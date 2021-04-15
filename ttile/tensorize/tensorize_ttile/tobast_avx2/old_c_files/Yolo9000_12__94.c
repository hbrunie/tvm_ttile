#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (256, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (16, f); T (1, x);
  Lambda_apply y [((Iter 5), (Arg 4)); ((Iter 2), (Arg 7))]; T (1, f);
  T (1, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1202_p_0, cp_1, c1202, f, fp_0, f632_p_0, f633_p_0, fp_1, f632_p_1, fp_2, f632, f633, w, wp_0, x, xp_0, x1048_p_0, x1049_p_0, xp_1, x1048_p_1, xp_2, x1048, x1049, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y524 = 0;
IND_TYPE x1050 = 0;
IND_TYPE h = 0;
IND_TYPE w524 = 0;
IND_TYPE c1203 = 0;
IND_TYPE f634 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10888 ,mem_vec_10889 ,mem_vec_10890 ,mem_vec_10891 ,mem_vec_10892 ,mem_vec_10893 ,mem_vec_10894 ,mem_vec_10895 ,mem_vec_10896 ,mem_vec_10897 ,mem_vec_10898 ,mem_vec_10899 ,mem_vec_10900 ,mem_vec_10901 ,mem_vec_10902 ,mem_vec_10903 ,mem_vec_10904 ,mem_vec_10905 ,mem_vec_10906 ,mem_vec_10907 ,mem_vec_10908 ,mem_vec_10909 ,mem_vec_10910 ,mem_vec_10911 ,mem_vec_10912 ,mem_vec_10913 ,mem_vec_10914 ,mem_vec_10915 ,mem_vec_10916 ,mem_vec_10917 ,mem_vec_10918 ,mem_vec_10919 ,mem_vec_10920 ,mem_vec_10921 ,mem_vec_10922 ,mem_vec_10923 ,mem_vec_10924 ,mem_vec_10925 ,mem_vec_10926 ,mem_vec_10927 ,mem_vec_10928 ,mem_vec_10929 ,mem_vec_10930 ,mem_vec_10931 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f633 = f634, f633_p_0 = 0;
	f633 < f634 + 512;
	f633 += 512, f633_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 17) (34 / 2)
	for (x1049 = x1050, x1049_p_0 = 0;
		x1049 < x1050 + 34;
		x1049 += 2, x1049_p_0 += 2){
		// y = 34, x = 2, h = 3, w = 3, c = 256, f = 512
		// T (c, 1) (256 / 256)
		for (c1202 = c1203, c1202_p_0 = 0;
			c1202 < c1203 + 256;
			c1202 += 256, c1202_p_0 += 256){
			// y = 34, x = 2, h = 3, w = 3, c = 256, f = 512
			// T (f, 1) (512 / 512)
			for (f632 = f633, f632_p_1 = f633_p_0, f632_p_0 = 0;
				f632 < f633 + 512;
				f632 += 512, f632_p_1 += 512, f632_p_0 += 512){
					for (y = y524, yp_0 = 0;
						y < y524 + 20;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 512
						// T (x, 1) (2 / 2)
						for (x1048 = x1049, x1048_p_1 = x1049_p_0, x1048_p_0 = 0;
							x1048 < x1049 + 2;
							x1048 += 2, x1048_p_1 += 2, x1048_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 512
							// T (f, 16) (512 / 32)
							for (f = f632, fp_2 = f632_p_1, fp_1 = f632_p_0, fp_0 = 0;
								f < f632 + 512;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 32
								// T (w, 3) (3 / 1)
								for (w = w524, wp_0 = 0;
									w < w524 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 256, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1048, xp_2 = x1048_p_1, xp_1 = x1048_p_0, xp_0 = 0;
										x < x1048 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10888 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10889 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10890 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10891 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10892 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10893 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10894 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10895 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10896 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10897 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10898 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10899 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10900 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10901 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10902 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10903 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c1202, cp_1 = c1202_p_0, cp_0 = 0;
													c < c1202 + 256;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10888);
													mem_vec_10888 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10889);
													mem_vec_10889 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10890);
													mem_vec_10890 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10891);
													mem_vec_10891 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10892);
													mem_vec_10892 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10893);
													mem_vec_10893 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10894);
													mem_vec_10894 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10895);
													mem_vec_10895 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10896);
													mem_vec_10896 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10897);
													mem_vec_10897 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10898);
													mem_vec_10898 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10899);
													mem_vec_10899 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10900);
													mem_vec_10900 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10901);
													mem_vec_10901 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10902);
													mem_vec_10902 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10903);
													mem_vec_10903 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_10888);
													mem_vec_10888 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_10889);
													mem_vec_10889 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_10890);
													mem_vec_10890 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_10891);
													mem_vec_10891 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_10892);
													mem_vec_10892 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_10893);
													mem_vec_10893 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_10894);
													mem_vec_10894 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_10895);
													mem_vec_10895 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_10896);
													mem_vec_10896 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_10897);
													mem_vec_10897 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_10898);
													mem_vec_10898 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_10899);
													mem_vec_10899 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_10900);
													mem_vec_10900 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_10901);
													mem_vec_10901 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_10902);
													mem_vec_10902 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_10903);
													mem_vec_10903 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_10888);
													mem_vec_10888 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_10889);
													mem_vec_10889 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_10890);
													mem_vec_10890 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_10891);
													mem_vec_10891 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_10892);
													mem_vec_10892 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_10893);
													mem_vec_10893 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_10894);
													mem_vec_10894 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_10895);
													mem_vec_10895 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_10896);
													mem_vec_10896 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_10897);
													mem_vec_10897 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_10898);
													mem_vec_10898 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_10899);
													mem_vec_10899 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_10900);
													mem_vec_10900 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_10901);
													mem_vec_10901 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_10902);
													mem_vec_10902 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_10903);
													mem_vec_10903 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10888);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10889);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10890);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10891);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10892);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10893);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10894);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10895);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10896);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10897);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10898);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10899);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10900);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10901);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10902);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10903);
									}
								}
							}
						}
					}
					for (y = y524 + 20, yp_0 = 0;
						y < y524 + 20 + 14;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 512
						// T (x, 1) (2 / 2)
						for (x1048 = x1049, x1048_p_1 = x1049_p_0, x1048_p_0 = 0;
							x1048 < x1049 + 2;
							x1048 += 2, x1048_p_1 += 2, x1048_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 512
							// T (f, 16) (512 / 32)
							for (f = f632, fp_2 = f632_p_1, fp_1 = f632_p_0, fp_0 = 0;
								f < f632 + 512;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 32
								// T (w, 3) (3 / 1)
								for (w = w524, wp_0 = 0;
									w < w524 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 256, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1048, xp_2 = x1048_p_1, xp_1 = x1048_p_0, xp_0 = 0;
										x < x1048 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10904 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10905 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10906 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10907 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10912 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10913 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10914 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10915 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_10924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_10926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_10928 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_10929 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_10930 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_10931 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c1202, cp_1 = c1202_p_0, cp_0 = 0;
													c < c1202 + 256;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10904);
													mem_vec_10904 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10905);
													mem_vec_10905 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10906);
													mem_vec_10906 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10907);
													mem_vec_10907 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10908);
													mem_vec_10908 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10909);
													mem_vec_10909 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10910);
													mem_vec_10910 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10911);
													mem_vec_10911 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10912);
													mem_vec_10912 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10913);
													mem_vec_10913 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10914);
													mem_vec_10914 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10915);
													mem_vec_10915 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10916);
													mem_vec_10916 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10917);
													mem_vec_10917 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10918);
													mem_vec_10918 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10919);
													mem_vec_10919 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10920);
													mem_vec_10920 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10921);
													mem_vec_10921 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10922);
													mem_vec_10922 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10923);
													mem_vec_10923 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10924);
													mem_vec_10924 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10925);
													mem_vec_10925 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10926);
													mem_vec_10926 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10927);
													mem_vec_10927 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_10928);
													mem_vec_10928 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_10929);
													mem_vec_10929 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_10930);
													mem_vec_10930 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_10931);
													mem_vec_10931 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_10904);
													mem_vec_10904 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_10905);
													mem_vec_10905 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_10906);
													mem_vec_10906 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_10907);
													mem_vec_10907 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_10908);
													mem_vec_10908 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_10909);
													mem_vec_10909 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_10910);
													mem_vec_10910 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_10911);
													mem_vec_10911 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_10912);
													mem_vec_10912 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_10913);
													mem_vec_10913 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_10914);
													mem_vec_10914 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_10915);
													mem_vec_10915 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_10916);
													mem_vec_10916 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_10917);
													mem_vec_10917 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_10918);
													mem_vec_10918 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_10919);
													mem_vec_10919 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_10920);
													mem_vec_10920 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_10921);
													mem_vec_10921 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_10922);
													mem_vec_10922 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_10923);
													mem_vec_10923 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_10924);
													mem_vec_10924 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_10925);
													mem_vec_10925 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_10926);
													mem_vec_10926 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_10927);
													mem_vec_10927 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_10928);
													mem_vec_10928 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_10929);
													mem_vec_10929 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_10930);
													mem_vec_10930 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_10931);
													mem_vec_10931 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_10904);
													mem_vec_10904 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_10905);
													mem_vec_10905 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_10906);
													mem_vec_10906 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_10907);
													mem_vec_10907 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_10908);
													mem_vec_10908 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_10909);
													mem_vec_10909 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_10910);
													mem_vec_10910 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_10911);
													mem_vec_10911 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_10912);
													mem_vec_10912 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_10913);
													mem_vec_10913 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_10914);
													mem_vec_10914 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_10915);
													mem_vec_10915 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_10916);
													mem_vec_10916 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_10917);
													mem_vec_10917 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_10918);
													mem_vec_10918 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_10919);
													mem_vec_10919 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_10920);
													mem_vec_10920 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_10921);
													mem_vec_10921 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_10922);
													mem_vec_10922 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_10923);
													mem_vec_10923 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_10924);
													mem_vec_10924 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_10925);
													mem_vec_10925 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_10926);
													mem_vec_10926 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_10927);
													mem_vec_10927 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_10928);
													mem_vec_10928 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_10929);
													mem_vec_10929 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_10930);
													mem_vec_10930 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_10931);
													mem_vec_10931 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10904);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10905);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10906);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10907);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10908);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10909);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10910);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10911);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10912);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10913);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10914);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10915);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10916);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10917);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10918);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10919);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10920);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10921);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10922);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10923);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10924);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10925);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10926);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10927);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10928);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_10929);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10930);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_10931);
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