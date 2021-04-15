#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (4, f); T (17, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (4, f);
  T (1, c); T (2, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1382_p_0, cp_1, c1382, f, fp_0, f872_p_0, f873_p_0, fp_1, f872_p_1, fp_2, f872, f873, h, hp_0, x, xp_0, x1288_p_0, x1289_p_0, xp_1, x1288_p_1, xp_2, x1288, x1289, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y644 = 0;
IND_TYPE x1290 = 0;
IND_TYPE h334 = 0;
IND_TYPE w = 0;
IND_TYPE c1383 = 0;
IND_TYPE f874 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_13720 ,mem_vec_13721 ,mem_vec_13722 ,mem_vec_13723 ,mem_vec_13724 ,mem_vec_13725 ,mem_vec_13726 ,mem_vec_13727 ,mem_vec_13728 ,mem_vec_13729 ,mem_vec_13730 ,mem_vec_13731 ,mem_vec_13732 ,mem_vec_13733 ,mem_vec_13734 ,mem_vec_13735 ,mem_vec_13736 ,mem_vec_13737 ,mem_vec_13738 ,mem_vec_13739 ,mem_vec_13740 ,mem_vec_13741 ,mem_vec_13742 ,mem_vec_13743 ,mem_vec_13744 ,mem_vec_13745 ,mem_vec_13746 ,mem_vec_13747 ,mem_vec_13748 ,mem_vec_13749 ,mem_vec_13750 ,mem_vec_13751 ,mem_vec_13752 ,mem_vec_13753 ,mem_vec_13754 ,mem_vec_13755 ,mem_vec_13756 ,mem_vec_13757 ,mem_vec_13758 ,mem_vec_13759 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f873 = f874, f873_p_0 = 0;
	f873 < f874 + 512;
	f873 += 512, f873_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 2) (34 / 17)
	for (x1289 = x1290, x1289_p_0 = 0;
		x1289 < x1290 + 34;
		x1289 += 17, x1289_p_0 += 17){
		// y = 34, x = 17, h = 3, w = 3, c = 256, f = 512
		// T (c, 1) (256 / 256)
		for (c1382 = c1383, c1382_p_0 = 0;
			c1382 < c1383 + 256;
			c1382 += 256, c1382_p_0 += 256){
			// y = 34, x = 17, h = 3, w = 3, c = 256, f = 512
			// T (f, 4) (512 / 128)
			for (f872 = f873, f872_p_1 = f873_p_0, f872_p_0 = 0;
				f872 < f873 + 512;
				f872 += 128, f872_p_1 += 128, f872_p_0 += 128){
					for (y = y644, yp_0 = 0;
						y < y644 + 4;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 128
						// T (x, 17) (17 / 1)
						for (x1288 = x1289, x1288_p_1 = x1289_p_0, x1288_p_0 = 0;
							x1288 < x1289 + 17;
							x1288 += 1, x1288_p_1 += 1, x1288_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 128
							// T (f, 4) (128 / 32)
							for (f = f872, fp_2 = f872_p_1, fp_1 = f872_p_0, fp_0 = 0;
								f < f872 + 128;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
								// T (h, 3) (3 / 1)
								for (h = h334, hp_0 = 0;
									h < h334 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1288, xp_2 = x1288_p_1, xp_1 = x1288_p_0, xp_0 = 0;
										x < x1288 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13720 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_13721 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_13722 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_13723 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_13724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_13725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_13726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_13727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_13728 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_13729 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_13730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_13731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_13732 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13733 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_13734 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_13735 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c1382, cp_1 = c1382_p_0, cp_0 = 0;
													c < c1382 + 256;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13720);
													mem_vec_13720 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13721);
													mem_vec_13721 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13722);
													mem_vec_13722 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13723);
													mem_vec_13723 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13724);
													mem_vec_13724 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13725);
													mem_vec_13725 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13726);
													mem_vec_13726 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13727);
													mem_vec_13727 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13728);
													mem_vec_13728 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13729);
													mem_vec_13729 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13730);
													mem_vec_13730 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13731);
													mem_vec_13731 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13732);
													mem_vec_13732 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13733);
													mem_vec_13733 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13734);
													mem_vec_13734 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13735);
													mem_vec_13735 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_13720);
													mem_vec_13720 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_13721);
													mem_vec_13721 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_13722);
													mem_vec_13722 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_13723);
													mem_vec_13723 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_13724);
													mem_vec_13724 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_13725);
													mem_vec_13725 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_13726);
													mem_vec_13726 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_13727);
													mem_vec_13727 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_13728);
													mem_vec_13728 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_13729);
													mem_vec_13729 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_13730);
													mem_vec_13730 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_13731);
													mem_vec_13731 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_13732);
													mem_vec_13732 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_13733);
													mem_vec_13733 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_13734);
													mem_vec_13734 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_13735);
													mem_vec_13735 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_13720);
													mem_vec_13720 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_13721);
													mem_vec_13721 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_13722);
													mem_vec_13722 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_13723);
													mem_vec_13723 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_13724);
													mem_vec_13724 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_13725);
													mem_vec_13725 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_13726);
													mem_vec_13726 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_13727);
													mem_vec_13727 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_13728);
													mem_vec_13728 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_13729);
													mem_vec_13729 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_13730);
													mem_vec_13730 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_13731);
													mem_vec_13731 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_13732);
													mem_vec_13732 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_13733);
													mem_vec_13733 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_13734);
													mem_vec_13734 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_13735);
													mem_vec_13735 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13720);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13721);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13722);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13723);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13724);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13725);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13726);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13727);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13728);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13729);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13730);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13731);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13732);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13733);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13734);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13735);
									}
								}
							}
						}
					}
					for (y = y644 + 4, yp_0 = 0;
						y < y644 + 4 + 30;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 17, h = 3, w = 3, c = 256, f = 128
						// T (x, 17) (17 / 1)
						for (x1288 = x1289, x1288_p_1 = x1289_p_0, x1288_p_0 = 0;
							x1288 < x1289 + 17;
							x1288 += 1, x1288_p_1 += 1, x1288_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 128
							// T (f, 4) (128 / 32)
							for (f = f872, fp_2 = f872_p_1, fp_1 = f872_p_0, fp_0 = 0;
								f < f872 + 128;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
								// T (h, 3) (3 / 1)
								for (h = h334, hp_0 = 0;
									h < h334 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1288, xp_2 = x1288_p_1, xp_1 = x1288_p_0, xp_0 = 0;
										x < x1288 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_13736 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_13737 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_13738 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_13739 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_13740 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_13741 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_13742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_13743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_13744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_13745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_13746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_13747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_13748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_13749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_13750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_13751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_13752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_13753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_13754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_13755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_13756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_13757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_13758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_13759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c1382, cp_1 = c1382_p_0, cp_0 = 0;
													c < c1382 + 256;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_13736);
													mem_vec_13736 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_13737);
													mem_vec_13737 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_13738);
													mem_vec_13738 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_13739);
													mem_vec_13739 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_13740);
													mem_vec_13740 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_13741);
													mem_vec_13741 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_13742);
													mem_vec_13742 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_13743);
													mem_vec_13743 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_13744);
													mem_vec_13744 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_13745);
													mem_vec_13745 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_13746);
													mem_vec_13746 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_13747);
													mem_vec_13747 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_13748);
													mem_vec_13748 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_13749);
													mem_vec_13749 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_13750);
													mem_vec_13750 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_13751);
													mem_vec_13751 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_13752);
													mem_vec_13752 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_13753);
													mem_vec_13753 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_13754);
													mem_vec_13754 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_13755);
													mem_vec_13755 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_13756);
													mem_vec_13756 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_13757);
													mem_vec_13757 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_13758);
													mem_vec_13758 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_13759);
													mem_vec_13759 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_13736);
													mem_vec_13736 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_13737);
													mem_vec_13737 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_13738);
													mem_vec_13738 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_13739);
													mem_vec_13739 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_13740);
													mem_vec_13740 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_13741);
													mem_vec_13741 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_13742);
													mem_vec_13742 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_13743);
													mem_vec_13743 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_13744);
													mem_vec_13744 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_13745);
													mem_vec_13745 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_13746);
													mem_vec_13746 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_13747);
													mem_vec_13747 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_13748);
													mem_vec_13748 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_13749);
													mem_vec_13749 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_13750);
													mem_vec_13750 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_13751);
													mem_vec_13751 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_13752);
													mem_vec_13752 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_13753);
													mem_vec_13753 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_13754);
													mem_vec_13754 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_13755);
													mem_vec_13755 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_13756);
													mem_vec_13756 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_13757);
													mem_vec_13757 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_13758);
													mem_vec_13758 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_13759);
													mem_vec_13759 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_13736);
													mem_vec_13736 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_13737);
													mem_vec_13737 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_13738);
													mem_vec_13738 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_13739);
													mem_vec_13739 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_13740);
													mem_vec_13740 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_13741);
													mem_vec_13741 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_13742);
													mem_vec_13742 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_13743);
													mem_vec_13743 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_13744);
													mem_vec_13744 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_13745);
													mem_vec_13745 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_13746);
													mem_vec_13746 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_13747);
													mem_vec_13747 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_13748);
													mem_vec_13748 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_13749);
													mem_vec_13749 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_13750);
													mem_vec_13750 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_13751);
													mem_vec_13751 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_13752);
													mem_vec_13752 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_13753);
													mem_vec_13753 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_13754);
													mem_vec_13754 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_13755);
													mem_vec_13755 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_13756);
													mem_vec_13756 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_13757);
													mem_vec_13757 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_13758);
													mem_vec_13758 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_13759);
													mem_vec_13759 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_13736);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_13737);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_13738);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_13739);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_13740);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_13741);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_13742);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_13743);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_13744);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_13745);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_13746);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_13747);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_13748);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_13749);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_13750);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_13751);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_13752);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_13753);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_13754);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_13755);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_13756);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_13757);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_13758);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_13759);
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