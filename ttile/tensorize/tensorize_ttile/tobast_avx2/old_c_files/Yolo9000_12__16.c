#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (8, f);
  T (128, c); T (2, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1388_p_0, cp_1, c1388, f, fp_0, f880_p_0, f881_p_0, fp_1, f880_p_1, fp_2, f880, f881, h, hp_0, x, xp_0, x1296_p_0, x1297_p_0, xp_1, x1296_p_1, xp_2, x1296, x1297, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y648 = 0;
IND_TYPE x1298 = 0;
IND_TYPE h338 = 0;
IND_TYPE w = 0;
IND_TYPE c1389 = 0;
IND_TYPE f882 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_13800 ,mem_vec_13801 ,mem_vec_13802 ,mem_vec_13803 ,mem_vec_13804 ,mem_vec_13805 ,mem_vec_13806 ,mem_vec_13807 ,mem_vec_13808 ,mem_vec_13809 ,mem_vec_13810 ,mem_vec_13811 ,mem_vec_13812 ,mem_vec_13813 ,mem_vec_13814 ,mem_vec_13815 ,mem_vec_13816 ,mem_vec_13817 ,mem_vec_13818 ,mem_vec_13819 ,mem_vec_13820 ,mem_vec_13821 ,mem_vec_13822 ,mem_vec_13823 ,mem_vec_13824 ,mem_vec_13825 ,mem_vec_13826 ,mem_vec_13827 ,mem_vec_13828 ,mem_vec_13829 ,mem_vec_13830 ,mem_vec_13831 ,mem_vec_13832 ,mem_vec_13833 ,mem_vec_13834 ,mem_vec_13835 ,mem_vec_13836 ,mem_vec_13837 ,mem_vec_13838 ,mem_vec_13839 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 2) (512 / 256)
for (f881 = f882, f881_p_0 = 0;
	f881 < f882 + 512;
	f881 += 256, f881_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 256
	// T (x, 2) (34 / 17)
	for (x1297 = x1298, x1297_p_0 = 0;
		x1297 < x1298 + 34;
		x1297 += 17, x1297_p_0 += 17){
		// y = 34, x = 17, h = 3, w = 3, c = 256, f = 256
		// T (c, 128) (256 / 2)
		for (c1388 = c1389, c1388_p_0 = 0;
			c1388 < c1389 + 256;
			c1388 += 2, c1388_p_0 += 2){
			// y = 34, x = 17, h = 3, w = 3, c = 2, f = 256
			// T (f, 8) (256 / 32)
			for (f880 = f881, f880_p_1 = f881_p_0, f880_p_0 = 0;
				f880 < f881 + 256;
				f880 += 32, f880_p_1 += 32, f880_p_0 += 32){
					for (y = y648, yp_0 = 0;
						y < y648 + 4;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 32
						// T (x, 17) (17 / 1)
						for (x1296 = x1297, x1296_p_1 = x1297_p_0, x1296_p_0 = 0;
							x1296 < x1297 + 17;
							x1296 += 1, x1296_p_1 += 1, x1296_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (f, 1) (32 / 32)
							for (f = f880, fp_2 = f880_p_1, fp_1 = f880_p_0, fp_0 = 0;
								f < f880 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h338, hp_0 = 0;
									h < h338 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1296, xp_2 = x1296_p_1, xp_1 = x1296_p_0, xp_0 = 0;
										x < x1296 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13800 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_13801 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_13802 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_13803 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_13804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_13805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_13806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_13807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_13808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_13809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_13810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_13811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_13812 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13813 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_13814 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_13815 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1388, cp_1 = c1388_p_0, cp_0 = 0;
													c < c1388 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13800);
													mem_vec_13800 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13801);
													mem_vec_13801 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13802);
													mem_vec_13802 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13803);
													mem_vec_13803 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13804);
													mem_vec_13804 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13805);
													mem_vec_13805 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13806);
													mem_vec_13806 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13807);
													mem_vec_13807 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13808);
													mem_vec_13808 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13809);
													mem_vec_13809 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13810);
													mem_vec_13810 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13811);
													mem_vec_13811 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13812);
													mem_vec_13812 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13813);
													mem_vec_13813 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13814);
													mem_vec_13814 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13815);
													mem_vec_13815 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_13800);
													mem_vec_13800 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_13801);
													mem_vec_13801 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_13802);
													mem_vec_13802 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_13803);
													mem_vec_13803 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_13804);
													mem_vec_13804 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_13805);
													mem_vec_13805 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_13806);
													mem_vec_13806 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_13807);
													mem_vec_13807 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_13808);
													mem_vec_13808 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_13809);
													mem_vec_13809 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_13810);
													mem_vec_13810 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_13811);
													mem_vec_13811 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_13812);
													mem_vec_13812 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_13813);
													mem_vec_13813 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_13814);
													mem_vec_13814 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_13815);
													mem_vec_13815 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_13800);
													mem_vec_13800 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_13801);
													mem_vec_13801 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_13802);
													mem_vec_13802 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_13803);
													mem_vec_13803 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_13804);
													mem_vec_13804 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_13805);
													mem_vec_13805 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_13806);
													mem_vec_13806 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_13807);
													mem_vec_13807 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_13808);
													mem_vec_13808 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_13809);
													mem_vec_13809 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_13810);
													mem_vec_13810 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_13811);
													mem_vec_13811 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_13812);
													mem_vec_13812 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_13813);
													mem_vec_13813 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_13814);
													mem_vec_13814 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_13815);
													mem_vec_13815 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13800);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13801);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13802);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13803);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13804);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13805);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13806);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13807);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13808);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13809);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13810);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13811);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13812);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13813);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13814);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13815);
									}
								}
							}
						}
					}
					for (y = y648 + 4, yp_0 = 0;
						y < y648 + 4 + 30;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 3, w = 3, c = 2, f = 32
						// T (x, 17) (17 / 1)
						for (x1296 = x1297, x1296_p_1 = x1297_p_0, x1296_p_0 = 0;
							x1296 < x1297 + 17;
							x1296 += 1, x1296_p_1 += 1, x1296_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
							// T (f, 1) (32 / 32)
							for (f = f880, fp_2 = f880_p_1, fp_1 = f880_p_0, fp_0 = 0;
								f < f880 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h338, hp_0 = 0;
									h < h338 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1296, xp_2 = x1296_p_1, xp_1 = x1296_p_0, xp_0 = 0;
										x < x1296 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13816 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_13817 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_13818 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_13819 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_13820 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_13821 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_13822 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_13823 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_13824 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_13825 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_13826 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_13827 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_13828 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13829 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_13830 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_13831 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_13832 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_13833 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_13834 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_13835 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_13836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_13837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_13838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_13839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1388, cp_1 = c1388_p_0, cp_0 = 0;
													c < c1388 + 2;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13816);
													mem_vec_13816 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13817);
													mem_vec_13817 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13818);
													mem_vec_13818 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13819);
													mem_vec_13819 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13820);
													mem_vec_13820 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13821);
													mem_vec_13821 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13822);
													mem_vec_13822 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13823);
													mem_vec_13823 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13824);
													mem_vec_13824 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13825);
													mem_vec_13825 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13826);
													mem_vec_13826 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13827);
													mem_vec_13827 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13828);
													mem_vec_13828 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13829);
													mem_vec_13829 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13830);
													mem_vec_13830 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13831);
													mem_vec_13831 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13832);
													mem_vec_13832 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13833);
													mem_vec_13833 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13834);
													mem_vec_13834 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13835);
													mem_vec_13835 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_13836);
													mem_vec_13836 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_13837);
													mem_vec_13837 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_13838);
													mem_vec_13838 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_13839);
													mem_vec_13839 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_13816);
													mem_vec_13816 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_13817);
													mem_vec_13817 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_13818);
													mem_vec_13818 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_13819);
													mem_vec_13819 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_13820);
													mem_vec_13820 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_13821);
													mem_vec_13821 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_13822);
													mem_vec_13822 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_13823);
													mem_vec_13823 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_13824);
													mem_vec_13824 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_13825);
													mem_vec_13825 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_13826);
													mem_vec_13826 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_13827);
													mem_vec_13827 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_13828);
													mem_vec_13828 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_13829);
													mem_vec_13829 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_13830);
													mem_vec_13830 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_13831);
													mem_vec_13831 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_13832);
													mem_vec_13832 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_13833);
													mem_vec_13833 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_13834);
													mem_vec_13834 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_13835);
													mem_vec_13835 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_13836);
													mem_vec_13836 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_13837);
													mem_vec_13837 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_13838);
													mem_vec_13838 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_13839);
													mem_vec_13839 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_13816);
													mem_vec_13816 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_13817);
													mem_vec_13817 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_13818);
													mem_vec_13818 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_13819);
													mem_vec_13819 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_13820);
													mem_vec_13820 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_13821);
													mem_vec_13821 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_13822);
													mem_vec_13822 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_13823);
													mem_vec_13823 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_13824);
													mem_vec_13824 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_13825);
													mem_vec_13825 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_13826);
													mem_vec_13826 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_13827);
													mem_vec_13827 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_13828);
													mem_vec_13828 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_13829);
													mem_vec_13829 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_13830);
													mem_vec_13830 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_13831);
													mem_vec_13831 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_13832);
													mem_vec_13832 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_13833);
													mem_vec_13833 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_13834);
													mem_vec_13834 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_13835);
													mem_vec_13835 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_13836);
													mem_vec_13836 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_13837);
													mem_vec_13837 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_13838);
													mem_vec_13838 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_13839);
													mem_vec_13839 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13816);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13817);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13818);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13819);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13820);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13821);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13822);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13823);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13824);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13825);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13826);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13827);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13828);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13829);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13830);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13831);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13832);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13833);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13834);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13835);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13836);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_13837);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13838);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_13839);
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