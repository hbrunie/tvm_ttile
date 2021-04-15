#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (14, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))];
  T (1, f); T (2, c); T (2, f); T (16, c); T (4, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1212_p_0, c1213_p_0, cp_1, c1212_p_1, cp_2, c1212, c1213, f, fp_0, f1116_p_0, f1117_p_0, fp_1, f1116_p_1, fp_2, f1116, f1117, h, hp_0, x, xp_0, x1056_p_0, xp_1, x1056, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y648 = 0;
IND_TYPE x1057 = 0;
IND_TYPE h438 = 0;
IND_TYPE w = 0;
IND_TYPE c1214 = 0;
IND_TYPE f1118 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_10832 ,mem_vec_10833 ,mem_vec_10834 ,mem_vec_10835 ,mem_vec_10836 ,mem_vec_10837 ,mem_vec_10838 ,mem_vec_10839 ,mem_vec_10840 ,mem_vec_10841 ,mem_vec_10842 ,mem_vec_10843 ,mem_vec_10844 ,mem_vec_10845 ,mem_vec_10846 ,mem_vec_10847 ,mem_vec_10848 ,mem_vec_10849 ,mem_vec_10850 ,mem_vec_10851 ,mem_vec_10852 ,mem_vec_10853 ,mem_vec_10854 ,mem_vec_10855 ,mem_vec_10856 ,mem_vec_10857 ,mem_vec_10858 ,mem_vec_10859 ,mem_vec_10860 ,mem_vec_10861 ,mem_vec_10862 ,mem_vec_10863 ,mem_vec_10864 ,mem_vec_10865 ,mem_vec_10866 ,mem_vec_10867 ,mem_vec_10868 ,mem_vec_10869 ,mem_vec_10870 ,mem_vec_10871 ,mem_vec_10872 ,mem_vec_10873 ,mem_vec_10874 ,mem_vec_10875 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f1117 = f1118, f1117_p_0 = 0;
	f1117 < f1118 + 64;
	f1117 += 64, f1117_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 4) (56 / 14)
	for (x1056 = x1057, x1056_p_0 = 0;
		x1056 < x1057 + 56;
		x1056 += 14, x1056_p_0 += 14){
		// y = 56, x = 14, h = 3, w = 3, c = 64, f = 64
		// T (c, 16) (64 / 4)
		for (c1213 = c1214, c1213_p_0 = 0;
			c1213 < c1214 + 64;
			c1213 += 4, c1213_p_0 += 4){
			// y = 56, x = 14, h = 3, w = 3, c = 4, f = 64
			// T (f, 2) (64 / 32)
			for (f1116 = f1117, f1116_p_1 = f1117_p_0, f1116_p_0 = 0;
				f1116 < f1117 + 64;
				f1116 += 32, f1116_p_1 += 32, f1116_p_0 += 32){
				// y = 56, x = 14, h = 3, w = 3, c = 4, f = 32
				// T (c, 2) (4 / 2)
				for (c1212 = c1213, c1212_p_1 = c1213_p_0, c1212_p_0 = 0;
					c1212 < c1213 + 4;
					c1212 += 2, c1212_p_1 += 2, c1212_p_0 += 2){
					// y = 56, x = 14, h = 3, w = 3, c = 2, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1116, fp_2 = f1116_p_1, fp_1 = f1116_p_0, fp_0 = 0;
						f < f1116 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y648, yp_0 = 0;
								y < y648 + 28;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h438, hp_0 = 0;
									h < h438 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 2, f = 32
									// T (x, 14) (14 / 1)
									for (x = x1056, xp_1 = x1056_p_0, xp_0 = 0;
										x < x1056 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10832 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10833 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10834 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10835 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10836 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10837 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10838 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10839 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10840 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10841 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10842 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10843 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10844 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10845 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10846 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10847 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1212, cp_2 = c1212_p_1, cp_1 = c1212_p_0, cp_0 = 0;
													c < c1212 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10832);
													mem_vec_10832 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10833);
													mem_vec_10833 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10834);
													mem_vec_10834 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10835);
													mem_vec_10835 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10836);
													mem_vec_10836 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10837);
													mem_vec_10837 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10838);
													mem_vec_10838 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10839);
													mem_vec_10839 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10840);
													mem_vec_10840 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10841);
													mem_vec_10841 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10842);
													mem_vec_10842 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10843);
													mem_vec_10843 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10844);
													mem_vec_10844 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10845);
													mem_vec_10845 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10846);
													mem_vec_10846 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10847);
													mem_vec_10847 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_10832);
													mem_vec_10832 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_10833);
													mem_vec_10833 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_10834);
													mem_vec_10834 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_10835);
													mem_vec_10835 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_10836);
													mem_vec_10836 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_10837);
													mem_vec_10837 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_10838);
													mem_vec_10838 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_10839);
													mem_vec_10839 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_10840);
													mem_vec_10840 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_10841);
													mem_vec_10841 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_10842);
													mem_vec_10842 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_10843);
													mem_vec_10843 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_10844);
													mem_vec_10844 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_10845);
													mem_vec_10845 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_10846);
													mem_vec_10846 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_10847);
													mem_vec_10847 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_10832);
													mem_vec_10832 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_10833);
													mem_vec_10833 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_10834);
													mem_vec_10834 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_10835);
													mem_vec_10835 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_10836);
													mem_vec_10836 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_10837);
													mem_vec_10837 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_10838);
													mem_vec_10838 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_10839);
													mem_vec_10839 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_10840);
													mem_vec_10840 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_10841);
													mem_vec_10841 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_10842);
													mem_vec_10842 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_10843);
													mem_vec_10843 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_10844);
													mem_vec_10844 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_10845);
													mem_vec_10845 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_10846);
													mem_vec_10846 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_10847);
													mem_vec_10847 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10832);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10833);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10834);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10835);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10836);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10837);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10838);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10839);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10840);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10841);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10842);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10843);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10844);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10845);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10846);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10847);
									}
								}
							}
							for (y = y648 + 28, yp_0 = 0;
								y < y648 + 28 + 28;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 14, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h438, hp_0 = 0;
									h < h438 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 2, f = 32
									// T (x, 14) (14 / 1)
									for (x = x1056, xp_1 = x1056_p_0, xp_0 = 0;
										x < x1056 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_10848 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_10849 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_10850 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_10851 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_10852 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_10853 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_10854 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_10855 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_10856 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_10857 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_10858 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_10859 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_10860 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_10861 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_10862 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_10863 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_10864 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_10865 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_10866 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_10867 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_10868 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_10869 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_10870 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_10871 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_10872 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_10873 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_10874 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_10875 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1212, cp_2 = c1212_p_1, cp_1 = c1212_p_0, cp_0 = 0;
													c < c1212 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_10848);
													mem_vec_10848 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_10849);
													mem_vec_10849 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_10850);
													mem_vec_10850 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_10851);
													mem_vec_10851 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_10852);
													mem_vec_10852 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_10853);
													mem_vec_10853 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_10854);
													mem_vec_10854 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_10855);
													mem_vec_10855 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_10856);
													mem_vec_10856 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_10857);
													mem_vec_10857 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_10858);
													mem_vec_10858 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_10859);
													mem_vec_10859 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_10860);
													mem_vec_10860 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_10861);
													mem_vec_10861 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_10862);
													mem_vec_10862 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_10863);
													mem_vec_10863 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_10864);
													mem_vec_10864 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_10865);
													mem_vec_10865 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_10866);
													mem_vec_10866 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_10867);
													mem_vec_10867 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_10868);
													mem_vec_10868 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_10869);
													mem_vec_10869 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_10870);
													mem_vec_10870 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_10871);
													mem_vec_10871 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_10872);
													mem_vec_10872 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_10873);
													mem_vec_10873 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_10874);
													mem_vec_10874 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_10875);
													mem_vec_10875 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_10848);
													mem_vec_10848 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_10849);
													mem_vec_10849 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_10850);
													mem_vec_10850 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_10851);
													mem_vec_10851 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_10852);
													mem_vec_10852 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_10853);
													mem_vec_10853 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_10854);
													mem_vec_10854 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_10855);
													mem_vec_10855 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_10856);
													mem_vec_10856 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_10857);
													mem_vec_10857 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_10858);
													mem_vec_10858 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_10859);
													mem_vec_10859 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_10860);
													mem_vec_10860 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_10861);
													mem_vec_10861 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_10862);
													mem_vec_10862 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_10863);
													mem_vec_10863 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_10864);
													mem_vec_10864 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_10865);
													mem_vec_10865 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_10866);
													mem_vec_10866 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_10867);
													mem_vec_10867 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_10868);
													mem_vec_10868 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_10869);
													mem_vec_10869 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_10870);
													mem_vec_10870 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_10871);
													mem_vec_10871 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_10872);
													mem_vec_10872 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_10873);
													mem_vec_10873 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_10874);
													mem_vec_10874 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_10875);
													mem_vec_10875 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_10848);
													mem_vec_10848 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_10849);
													mem_vec_10849 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_10850);
													mem_vec_10850 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_10851);
													mem_vec_10851 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_10852);
													mem_vec_10852 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_10853);
													mem_vec_10853 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_10854);
													mem_vec_10854 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_10855);
													mem_vec_10855 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_10856);
													mem_vec_10856 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_10857);
													mem_vec_10857 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_10858);
													mem_vec_10858 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_10859);
													mem_vec_10859 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_10860);
													mem_vec_10860 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_10861);
													mem_vec_10861 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_10862);
													mem_vec_10862 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_10863);
													mem_vec_10863 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_10864);
													mem_vec_10864 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_10865);
													mem_vec_10865 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_10866);
													mem_vec_10866 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_10867);
													mem_vec_10867 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_10868);
													mem_vec_10868 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_10869);
													mem_vec_10869 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_10870);
													mem_vec_10870 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_10871);
													mem_vec_10871 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_10872);
													mem_vec_10872 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_10873);
													mem_vec_10873 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_10874);
													mem_vec_10874 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_10875);
													mem_vec_10875 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_10848);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_10849);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_10850);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_10851);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_10852);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_10853);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_10854);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_10855);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_10856);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_10857);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_10858);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_10859);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_10860);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_10861);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_10862);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_10863);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_10864);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_10865);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_10866);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_10867);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_10868);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_10869);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_10870);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_10871);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_10872);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_10873);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_10874);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_10875);
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