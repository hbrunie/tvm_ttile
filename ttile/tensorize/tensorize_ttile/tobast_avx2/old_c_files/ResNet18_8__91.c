#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (2, x);
  T (3, h); T (8, f); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (1, f);
  T (64, c); T (14, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1294_p_0, cp_1, c1294, f, fp_0, f1370_p_0, f1371_p_0, fp_1, f1370_p_1, fp_2, f1370, f1371, h, hp_0, x, xp_0, x1558_p_0, x1559_p_0, xp_1, x1558_p_1, xp_2, x1558, x1559, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y788 = 0;
IND_TYPE x1560 = 0;
IND_TYPE h600 = 0;
IND_TYPE w = 0;
IND_TYPE c1295 = 0;
IND_TYPE f1372 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11884 ,mem_vec_11885 ,mem_vec_11886 ,mem_vec_11887 ,mem_vec_11888 ,mem_vec_11889 ,mem_vec_11890 ,mem_vec_11891 ,mem_vec_11892 ,mem_vec_11893 ,mem_vec_11894 ,mem_vec_11895 ,mem_vec_11896 ,mem_vec_11897 ,mem_vec_11898 ,mem_vec_11899 ,mem_vec_11900 ,mem_vec_11901 ,mem_vec_11902 ,mem_vec_11903 ,mem_vec_11904 ,mem_vec_11905 ,mem_vec_11906 ,mem_vec_11907 ,mem_vec_11908 ,mem_vec_11909 ,mem_vec_11910 ,mem_vec_11911 ,mem_vec_11912 ,mem_vec_11913 ,mem_vec_11914 ,mem_vec_11915 ,mem_vec_11916 ,mem_vec_11917 ,mem_vec_11918 ,mem_vec_11919 ,mem_vec_11920 ,mem_vec_11921 ,mem_vec_11922 ,mem_vec_11923 ,mem_vec_11924 ,mem_vec_11925 ,mem_vec_11926 ,mem_vec_11927 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1371 = f1372, f1371_p_0 = 0;
	f1371 < f1372 + 256;
	f1371 += 256, f1371_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 128, f = 256
	// T (x, 14) (28 / 2)
	for (x1559 = x1560, x1559_p_0 = 0;
		x1559 < x1560 + 28;
		x1559 += 2, x1559_p_0 += 2){
		// y = 28, x = 2, h = 3, w = 3, c = 128, f = 256
		// T (c, 64) (128 / 2)
		for (c1294 = c1295, c1294_p_0 = 0;
			c1294 < c1295 + 128;
			c1294 += 2, c1294_p_0 += 2){
			// y = 28, x = 2, h = 3, w = 3, c = 2, f = 256
			// T (f, 1) (256 / 256)
			for (f1370 = f1371, f1370_p_1 = f1371_p_0, f1370_p_0 = 0;
				f1370 < f1371 + 256;
				f1370 += 256, f1370_p_1 += 256, f1370_p_0 += 256){
					for (y = y788, yp_0 = 0;
						y < y788 + 10;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 256
						// T (x, 1) (2 / 2)
						for (x1558 = x1559, x1558_p_1 = x1559_p_0, x1558_p_0 = 0;
							x1558 < x1559 + 2;
							x1558 += 2, x1558_p_1 += 2, x1558_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1370, fp_2 = f1370_p_1, fp_1 = f1370_p_0, fp_0 = 0;
								f < f1370 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h600, hp_0 = 0;
									h < h600 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1558, xp_2 = x1558_p_1, xp_1 = x1558_p_0, xp_0 = 0;
										x < x1558 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11884 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11885 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11886 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11887 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11888 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11889 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11890 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11891 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11892 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11893 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11894 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11895 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11896 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11897 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11898 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11899 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11900 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11901 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11902 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11903 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1294, cp_1 = c1294_p_0, cp_0 = 0;
													c < c1294 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11884);
													mem_vec_11884 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11885);
													mem_vec_11885 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11886);
													mem_vec_11886 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11887);
													mem_vec_11887 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11888);
													mem_vec_11888 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11889);
													mem_vec_11889 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11890);
													mem_vec_11890 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11891);
													mem_vec_11891 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11892);
													mem_vec_11892 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11893);
													mem_vec_11893 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11894);
													mem_vec_11894 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11895);
													mem_vec_11895 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11896);
													mem_vec_11896 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11897);
													mem_vec_11897 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11898);
													mem_vec_11898 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11899);
													mem_vec_11899 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11900);
													mem_vec_11900 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11901);
													mem_vec_11901 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11902);
													mem_vec_11902 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11903);
													mem_vec_11903 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11884);
													mem_vec_11884 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11885);
													mem_vec_11885 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11886);
													mem_vec_11886 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11887);
													mem_vec_11887 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11888);
													mem_vec_11888 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11889);
													mem_vec_11889 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11890);
													mem_vec_11890 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11891);
													mem_vec_11891 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11892);
													mem_vec_11892 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11893);
													mem_vec_11893 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11894);
													mem_vec_11894 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11895);
													mem_vec_11895 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11896);
													mem_vec_11896 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11897);
													mem_vec_11897 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11898);
													mem_vec_11898 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11899);
													mem_vec_11899 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11900);
													mem_vec_11900 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11901);
													mem_vec_11901 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11902);
													mem_vec_11902 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11903);
													mem_vec_11903 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11884);
													mem_vec_11884 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11885);
													mem_vec_11885 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11886);
													mem_vec_11886 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11887);
													mem_vec_11887 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11888);
													mem_vec_11888 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11889);
													mem_vec_11889 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11890);
													mem_vec_11890 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11891);
													mem_vec_11891 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11892);
													mem_vec_11892 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11893);
													mem_vec_11893 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11894);
													mem_vec_11894 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11895);
													mem_vec_11895 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11896);
													mem_vec_11896 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11897);
													mem_vec_11897 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11898);
													mem_vec_11898 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11899);
													mem_vec_11899 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11900);
													mem_vec_11900 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11901);
													mem_vec_11901 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11902);
													mem_vec_11902 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11903);
													mem_vec_11903 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11884);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11885);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11886);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11887);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11888);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11889);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11890);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11891);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11892);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11893);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11894);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11895);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11896);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11897);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11898);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11899);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11900);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11901);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11902);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11903);
									}
								}
							}
						}
					}
					for (y = y788 + 10, yp_0 = 0;
						y < y788 + 10 + 18;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 256
						// T (x, 1) (2 / 2)
						for (x1558 = x1559, x1558_p_1 = x1559_p_0, x1558_p_0 = 0;
							x1558 < x1559 + 2;
							x1558 += 2, x1558_p_1 += 2, x1558_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 256
							// T (f, 8) (256 / 32)
							for (f = f1370, fp_2 = f1370_p_1, fp_1 = f1370_p_0, fp_0 = 0;
								f < f1370 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h600, hp_0 = 0;
									h < h600 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 2, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1558, xp_2 = x1558_p_1, xp_1 = x1558_p_0, xp_0 = 0;
										x < x1558 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11904 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11905 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11906 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11907 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11912 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11913 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11914 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11915 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_11924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1294, cp_1 = c1294_p_0, cp_0 = 0;
													c < c1294 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11904);
													mem_vec_11904 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11905);
													mem_vec_11905 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11906);
													mem_vec_11906 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11907);
													mem_vec_11907 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11908);
													mem_vec_11908 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11909);
													mem_vec_11909 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11910);
													mem_vec_11910 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11911);
													mem_vec_11911 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11912);
													mem_vec_11912 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11913);
													mem_vec_11913 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11914);
													mem_vec_11914 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11915);
													mem_vec_11915 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11916);
													mem_vec_11916 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11917);
													mem_vec_11917 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11918);
													mem_vec_11918 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11919);
													mem_vec_11919 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11920);
													mem_vec_11920 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11921);
													mem_vec_11921 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11922);
													mem_vec_11922 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11923);
													mem_vec_11923 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11924);
													mem_vec_11924 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11925);
													mem_vec_11925 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11926);
													mem_vec_11926 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11927);
													mem_vec_11927 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_11904);
													mem_vec_11904 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_11905);
													mem_vec_11905 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_11906);
													mem_vec_11906 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_11907);
													mem_vec_11907 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_11908);
													mem_vec_11908 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_11909);
													mem_vec_11909 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_11910);
													mem_vec_11910 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_11911);
													mem_vec_11911 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_11912);
													mem_vec_11912 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_11913);
													mem_vec_11913 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_11914);
													mem_vec_11914 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_11915);
													mem_vec_11915 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_11916);
													mem_vec_11916 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_11917);
													mem_vec_11917 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_11918);
													mem_vec_11918 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_11919);
													mem_vec_11919 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_11920);
													mem_vec_11920 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_11921);
													mem_vec_11921 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_11922);
													mem_vec_11922 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_11923);
													mem_vec_11923 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_11924);
													mem_vec_11924 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_11925);
													mem_vec_11925 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_11926);
													mem_vec_11926 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_11927);
													mem_vec_11927 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_11904);
													mem_vec_11904 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_11905);
													mem_vec_11905 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_11906);
													mem_vec_11906 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_11907);
													mem_vec_11907 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_11908);
													mem_vec_11908 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_11909);
													mem_vec_11909 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_11910);
													mem_vec_11910 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_11911);
													mem_vec_11911 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_11912);
													mem_vec_11912 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_11913);
													mem_vec_11913 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_11914);
													mem_vec_11914 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_11915);
													mem_vec_11915 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_11916);
													mem_vec_11916 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_11917);
													mem_vec_11917 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_11918);
													mem_vec_11918 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_11919);
													mem_vec_11919 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_11920);
													mem_vec_11920 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_11921);
													mem_vec_11921 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_11922);
													mem_vec_11922 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_11923);
													mem_vec_11923 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_11924);
													mem_vec_11924 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_11925);
													mem_vec_11925 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_11926);
													mem_vec_11926 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_11927);
													mem_vec_11927 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11904);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11905);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11906);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11907);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11908);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11909);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11910);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11911);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11912);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11913);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11914);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11915);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11916);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11917);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11918);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11919);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11920);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11921);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11922);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11923);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11924);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11925);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11926);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11927);
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