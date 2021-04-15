#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (8, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (2, f);
  T (16, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1058_p_0, cp_1, c1058, f, fp_0, f440_p_0, f441_p_0, fp_1, f440_p_1, fp_2, f440, f441, w, wp_0, x, xp_0, x856_p_0, x857_p_0, xp_1, x856_p_1, xp_2, x856, x857, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y428 = 0;
IND_TYPE x858 = 0;
IND_TYPE h = 0;
IND_TYPE w428 = 0;
IND_TYPE c1059 = 0;
IND_TYPE f442 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_8888 ,mem_vec_8889 ,mem_vec_8890 ,mem_vec_8891 ,mem_vec_8892 ,mem_vec_8893 ,mem_vec_8894 ,mem_vec_8895 ,mem_vec_8896 ,mem_vec_8897 ,mem_vec_8898 ,mem_vec_8899 ,mem_vec_8900 ,mem_vec_8901 ,mem_vec_8902 ,mem_vec_8903 ,mem_vec_8904 ,mem_vec_8905 ,mem_vec_8906 ,mem_vec_8907 ,mem_vec_8908 ,mem_vec_8909 ,mem_vec_8910 ,mem_vec_8911 ,mem_vec_8912 ,mem_vec_8913 ,mem_vec_8914 ,mem_vec_8915 ,mem_vec_8916 ,mem_vec_8917 ,mem_vec_8918 ,mem_vec_8919 ,mem_vec_8920 ,mem_vec_8921 ,mem_vec_8922 ,mem_vec_8923 ,mem_vec_8924 ,mem_vec_8925 ,mem_vec_8926 ,mem_vec_8927 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f441 = f442, f441_p_0 = 0;
	f441 < f442 + 512;
	f441 += 512, f441_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 1) (34 / 34)
	for (x857 = x858, x857_p_0 = 0;
		x857 < x858 + 34;
		x857 += 34, x857_p_0 += 34){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
		// T (c, 16) (256 / 16)
		for (c1058 = c1059, c1058_p_0 = 0;
			c1058 < c1059 + 256;
			c1058 += 16, c1058_p_0 += 16){
			// y = 34, x = 34, h = 3, w = 3, c = 16, f = 512
			// T (f, 2) (512 / 256)
			for (f440 = f441, f440_p_1 = f441_p_0, f440_p_0 = 0;
				f440 < f441 + 512;
				f440 += 256, f440_p_1 += 256, f440_p_0 += 256){
					for (y = y428, yp_0 = 0;
						y < y428 + 4;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 256
						// T (x, 2) (34 / 17)
						for (x856 = x857, x856_p_1 = x857_p_0, x856_p_0 = 0;
							x856 < x857 + 34;
							x856 += 17, x856_p_1 += 17, x856_p_0 += 17){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 256
							// T (f, 8) (256 / 32)
							for (f = f440, fp_2 = f440_p_1, fp_1 = f440_p_0, fp_0 = 0;
								f < f440 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w428, wp_0 = 0;
									w < w428 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
									// T (x, 17) (17 / 1)
									for (x = x856, xp_2 = x856_p_1, xp_1 = x856_p_0, xp_0 = 0;
										x < x856 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8888 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8889 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8890 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8891 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8892 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8893 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8894 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8895 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8896 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8897 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8898 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8899 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8900 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8901 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8902 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8903 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1058, cp_1 = c1058_p_0, cp_0 = 0;
													c < c1058 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8888);
													mem_vec_8888 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8889);
													mem_vec_8889 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8890);
													mem_vec_8890 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8891);
													mem_vec_8891 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8892);
													mem_vec_8892 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8893);
													mem_vec_8893 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8894);
													mem_vec_8894 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8895);
													mem_vec_8895 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8896);
													mem_vec_8896 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8897);
													mem_vec_8897 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8898);
													mem_vec_8898 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8899);
													mem_vec_8899 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8900);
													mem_vec_8900 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8901);
													mem_vec_8901 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8902);
													mem_vec_8902 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8903);
													mem_vec_8903 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_8888);
													mem_vec_8888 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_8889);
													mem_vec_8889 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_8890);
													mem_vec_8890 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_8891);
													mem_vec_8891 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_8892);
													mem_vec_8892 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_8893);
													mem_vec_8893 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_8894);
													mem_vec_8894 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_8895);
													mem_vec_8895 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_8896);
													mem_vec_8896 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_8897);
													mem_vec_8897 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_8898);
													mem_vec_8898 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_8899);
													mem_vec_8899 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_8900);
													mem_vec_8900 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_8901);
													mem_vec_8901 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_8902);
													mem_vec_8902 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_8903);
													mem_vec_8903 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_8888);
													mem_vec_8888 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_8889);
													mem_vec_8889 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_8890);
													mem_vec_8890 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_8891);
													mem_vec_8891 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_8892);
													mem_vec_8892 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_8893);
													mem_vec_8893 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_8894);
													mem_vec_8894 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_8895);
													mem_vec_8895 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_8896);
													mem_vec_8896 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_8897);
													mem_vec_8897 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_8898);
													mem_vec_8898 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_8899);
													mem_vec_8899 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_8900);
													mem_vec_8900 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_8901);
													mem_vec_8901 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_8902);
													mem_vec_8902 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_8903);
													mem_vec_8903 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8888);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8889);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8890);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8891);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8892);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8893);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8894);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8895);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8896);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8897);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8898);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8899);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8900);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8901);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8902);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8903);
									}
								}
							}
						}
					}
					for (y = y428 + 4, yp_0 = 0;
						y < y428 + 4 + 30;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 256
						// T (x, 2) (34 / 17)
						for (x856 = x857, x856_p_1 = x857_p_0, x856_p_0 = 0;
							x856 < x857 + 34;
							x856 += 17, x856_p_1 += 17, x856_p_0 += 17){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 256
							// T (f, 8) (256 / 32)
							for (f = f440, fp_2 = f440_p_1, fp_1 = f440_p_0, fp_0 = 0;
								f < f440 + 256;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w428, wp_0 = 0;
									w < w428 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
									// T (x, 17) (17 / 1)
									for (x = x856, xp_2 = x856_p_1, xp_1 = x856_p_0, xp_0 = 0;
										x < x856 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_8904 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_8905 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_8906 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_8907 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_8908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_8909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_8910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_8911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_8912 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_8913 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_8914 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_8915 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_8916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_8917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_8918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_8919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_8920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_8921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_8922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_8923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_8924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_8925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_8926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_8927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1058, cp_1 = c1058_p_0, cp_0 = 0;
													c < c1058 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_8904);
													mem_vec_8904 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_8905);
													mem_vec_8905 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_8906);
													mem_vec_8906 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_8907);
													mem_vec_8907 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_8908);
													mem_vec_8908 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_8909);
													mem_vec_8909 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_8910);
													mem_vec_8910 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_8911);
													mem_vec_8911 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_8912);
													mem_vec_8912 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_8913);
													mem_vec_8913 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_8914);
													mem_vec_8914 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_8915);
													mem_vec_8915 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_8916);
													mem_vec_8916 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_8917);
													mem_vec_8917 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_8918);
													mem_vec_8918 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_8919);
													mem_vec_8919 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_8920);
													mem_vec_8920 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_8921);
													mem_vec_8921 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_8922);
													mem_vec_8922 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_8923);
													mem_vec_8923 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_8924);
													mem_vec_8924 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_8925);
													mem_vec_8925 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_8926);
													mem_vec_8926 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_8927);
													mem_vec_8927 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_8904);
													mem_vec_8904 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_8905);
													mem_vec_8905 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_8906);
													mem_vec_8906 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_8907);
													mem_vec_8907 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_8908);
													mem_vec_8908 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_8909);
													mem_vec_8909 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_8910);
													mem_vec_8910 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_8911);
													mem_vec_8911 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_8912);
													mem_vec_8912 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_8913);
													mem_vec_8913 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_8914);
													mem_vec_8914 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_8915);
													mem_vec_8915 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_8916);
													mem_vec_8916 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_8917);
													mem_vec_8917 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_8918);
													mem_vec_8918 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_8919);
													mem_vec_8919 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_8920);
													mem_vec_8920 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_8921);
													mem_vec_8921 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_8922);
													mem_vec_8922 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_8923);
													mem_vec_8923 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_8924);
													mem_vec_8924 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_8925);
													mem_vec_8925 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_8926);
													mem_vec_8926 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_8927);
													mem_vec_8927 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_8904);
													mem_vec_8904 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_8905);
													mem_vec_8905 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_8906);
													mem_vec_8906 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_8907);
													mem_vec_8907 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_8908);
													mem_vec_8908 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_8909);
													mem_vec_8909 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_8910);
													mem_vec_8910 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_8911);
													mem_vec_8911 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_8912);
													mem_vec_8912 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_8913);
													mem_vec_8913 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_8914);
													mem_vec_8914 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_8915);
													mem_vec_8915 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_8916);
													mem_vec_8916 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_8917);
													mem_vec_8917 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_8918);
													mem_vec_8918 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_8919);
													mem_vec_8919 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_8920);
													mem_vec_8920 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_8921);
													mem_vec_8921 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_8922);
													mem_vec_8922 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_8923);
													mem_vec_8923 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_8924);
													mem_vec_8924 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_8925);
													mem_vec_8925 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_8926);
													mem_vec_8926 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_8927);
													mem_vec_8927 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8904);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_8905);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8906);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_8907);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8908);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_8909);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8910);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_8911);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8912);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_8913);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8914);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_8915);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8916);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_8917);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8918);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_8919);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8920);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_8921);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8922);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_8923);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8924);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_8925);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8926);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_8927);
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