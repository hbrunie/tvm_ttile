#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (4, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))];
  T (1, f); T (16, c); T (2, f); T (2, c); T (14, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1380_p_0, c1381_p_0, cp_1, c1380_p_1, cp_2, c1380, c1381, f, fp_0, f1284_p_0, f1285_p_0, fp_1, f1284_p_1, fp_2, f1284, f1285, h, hp_0, x, xp_0, x1182_p_0, xp_1, x1182, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y732 = 0;
IND_TYPE x1183 = 0;
IND_TYPE h522 = 0;
IND_TYPE w = 0;
IND_TYPE c1382 = 0;
IND_TYPE f1286 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_12752 ,mem_vec_12753 ,mem_vec_12754 ,mem_vec_12755 ,mem_vec_12756 ,mem_vec_12757 ,mem_vec_12758 ,mem_vec_12759 ,mem_vec_12760 ,mem_vec_12761 ,mem_vec_12762 ,mem_vec_12763 ,mem_vec_12764 ,mem_vec_12765 ,mem_vec_12766 ,mem_vec_12767 ,mem_vec_12768 ,mem_vec_12769 ,mem_vec_12770 ,mem_vec_12771 ,mem_vec_12772 ,mem_vec_12773 ,mem_vec_12774 ,mem_vec_12775 ,mem_vec_12776 ,mem_vec_12777 ,mem_vec_12778 ,mem_vec_12779 ,mem_vec_12780 ,mem_vec_12781 ,mem_vec_12782 ,mem_vec_12783 ,mem_vec_12784 ,mem_vec_12785 ,mem_vec_12786 ,mem_vec_12787 ,mem_vec_12788 ,mem_vec_12789 ,mem_vec_12790 ,mem_vec_12791 ,mem_vec_12792 ,mem_vec_12793 ,mem_vec_12794 ,mem_vec_12795 ,mem_vec_12796 ,mem_vec_12797 ,mem_vec_12798 ,mem_vec_12799 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f1285 = f1286, f1285_p_0 = 0;
	f1285 < f1286 + 64;
	f1285 += 64, f1285_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 14) (56 / 4)
	for (x1182 = x1183, x1182_p_0 = 0;
		x1182 < x1183 + 56;
		x1182 += 4, x1182_p_0 += 4){
		// y = 56, x = 4, h = 3, w = 3, c = 64, f = 64
		// T (c, 2) (64 / 32)
		for (c1381 = c1382, c1381_p_0 = 0;
			c1381 < c1382 + 64;
			c1381 += 32, c1381_p_0 += 32){
			// y = 56, x = 4, h = 3, w = 3, c = 32, f = 64
			// T (f, 2) (64 / 32)
			for (f1284 = f1285, f1284_p_1 = f1285_p_0, f1284_p_0 = 0;
				f1284 < f1285 + 64;
				f1284 += 32, f1284_p_1 += 32, f1284_p_0 += 32){
				// y = 56, x = 4, h = 3, w = 3, c = 32, f = 32
				// T (c, 16) (32 / 2)
				for (c1380 = c1381, c1380_p_1 = c1381_p_0, c1380_p_0 = 0;
					c1380 < c1381 + 32;
					c1380 += 2, c1380_p_1 += 2, c1380_p_0 += 2){
					// y = 56, x = 4, h = 3, w = 3, c = 2, f = 32
					// T (f, 1) (32 / 32)
					for (f = f1284, fp_2 = f1284_p_1, fp_1 = f1284_p_0, fp_0 = 0;
						f < f1284 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y732, yp_0 = 0;
								y < y732 + 35;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h522, hp_0 = 0;
									h < h522 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 2, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1182, xp_1 = x1182_p_0, xp_0 = 0;
										x < x1182 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12752 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12753 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_12754 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12755 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_12756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_12758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_12760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_12762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_12766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_12768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_12770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1380, cp_2 = c1380_p_1, cp_1 = c1380_p_0, cp_0 = 0;
													c < c1380 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12752);
													mem_vec_12752 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12753);
													mem_vec_12753 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12754);
													mem_vec_12754 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12755);
													mem_vec_12755 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12756);
													mem_vec_12756 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12757);
													mem_vec_12757 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12758);
													mem_vec_12758 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12759);
													mem_vec_12759 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12760);
													mem_vec_12760 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12761);
													mem_vec_12761 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12762);
													mem_vec_12762 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12763);
													mem_vec_12763 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12764);
													mem_vec_12764 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12765);
													mem_vec_12765 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12766);
													mem_vec_12766 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12767);
													mem_vec_12767 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12768);
													mem_vec_12768 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12769);
													mem_vec_12769 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12770);
													mem_vec_12770 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12771);
													mem_vec_12771 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_12752);
													mem_vec_12752 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_12753);
													mem_vec_12753 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_12754);
													mem_vec_12754 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_12755);
													mem_vec_12755 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_12756);
													mem_vec_12756 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_12757);
													mem_vec_12757 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_12758);
													mem_vec_12758 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_12759);
													mem_vec_12759 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_12760);
													mem_vec_12760 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_12761);
													mem_vec_12761 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_12762);
													mem_vec_12762 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_12763);
													mem_vec_12763 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_12764);
													mem_vec_12764 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_12765);
													mem_vec_12765 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_12766);
													mem_vec_12766 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_12767);
													mem_vec_12767 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_12768);
													mem_vec_12768 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_12769);
													mem_vec_12769 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_12770);
													mem_vec_12770 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_12771);
													mem_vec_12771 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_12752);
													mem_vec_12752 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_12753);
													mem_vec_12753 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_12754);
													mem_vec_12754 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_12755);
													mem_vec_12755 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_12756);
													mem_vec_12756 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_12757);
													mem_vec_12757 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_12758);
													mem_vec_12758 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_12759);
													mem_vec_12759 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_12760);
													mem_vec_12760 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_12761);
													mem_vec_12761 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_12762);
													mem_vec_12762 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_12763);
													mem_vec_12763 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_12764);
													mem_vec_12764 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_12765);
													mem_vec_12765 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_12766);
													mem_vec_12766 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_12767);
													mem_vec_12767 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_12768);
													mem_vec_12768 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_12769);
													mem_vec_12769 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_12770);
													mem_vec_12770 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_12771);
													mem_vec_12771 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12752);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12753);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12754);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12755);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12756);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12757);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12758);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12759);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12760);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12761);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12762);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12763);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12764);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12765);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12766);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12767);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12768);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12769);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12770);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12771);
									}
								}
							}
							for (y = y732 + 35, yp_0 = 0;
								y < y732 + 35 + 21;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 4, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h522, hp_0 = 0;
									h < h522 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 4, h = 1, w = 3, c = 2, f = 32
									// T (x, 4) (4 / 1)
									for (x = x1182, xp_1 = x1182_p_0, xp_0 = 0;
										x < x1182 + 4;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12772 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12773 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_12774 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12775 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_12776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_12778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_12780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_12782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_12786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_12788 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12789 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_12790 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12791 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_12792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_12794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_12796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_12798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1380, cp_2 = c1380_p_1, cp_1 = c1380_p_0, cp_0 = 0;
													c < c1380 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12772);
													mem_vec_12772 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12773);
													mem_vec_12773 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12774);
													mem_vec_12774 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12775);
													mem_vec_12775 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12776);
													mem_vec_12776 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12777);
													mem_vec_12777 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12778);
													mem_vec_12778 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12779);
													mem_vec_12779 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12780);
													mem_vec_12780 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12781);
													mem_vec_12781 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12782);
													mem_vec_12782 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12783);
													mem_vec_12783 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12784);
													mem_vec_12784 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12785);
													mem_vec_12785 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12786);
													mem_vec_12786 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12787);
													mem_vec_12787 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12788);
													mem_vec_12788 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12789);
													mem_vec_12789 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12790);
													mem_vec_12790 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12791);
													mem_vec_12791 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_12792);
													mem_vec_12792 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_12793);
													mem_vec_12793 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_12794);
													mem_vec_12794 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_12795);
													mem_vec_12795 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_12796);
													mem_vec_12796 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_12797);
													mem_vec_12797 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_12798);
													mem_vec_12798 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_12799);
													mem_vec_12799 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_12772);
													mem_vec_12772 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_12773);
													mem_vec_12773 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_12774);
													mem_vec_12774 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_12775);
													mem_vec_12775 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_12776);
													mem_vec_12776 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_12777);
													mem_vec_12777 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_12778);
													mem_vec_12778 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_12779);
													mem_vec_12779 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_12780);
													mem_vec_12780 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_12781);
													mem_vec_12781 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_12782);
													mem_vec_12782 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_12783);
													mem_vec_12783 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_12784);
													mem_vec_12784 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_12785);
													mem_vec_12785 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_12786);
													mem_vec_12786 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_12787);
													mem_vec_12787 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_12788);
													mem_vec_12788 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_12789);
													mem_vec_12789 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_12790);
													mem_vec_12790 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_12791);
													mem_vec_12791 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_12792);
													mem_vec_12792 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_12793);
													mem_vec_12793 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_12794);
													mem_vec_12794 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_12795);
													mem_vec_12795 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_12796);
													mem_vec_12796 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_12797);
													mem_vec_12797 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_12798);
													mem_vec_12798 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_12799);
													mem_vec_12799 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_12772);
													mem_vec_12772 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_12773);
													mem_vec_12773 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_12774);
													mem_vec_12774 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_12775);
													mem_vec_12775 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_12776);
													mem_vec_12776 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_12777);
													mem_vec_12777 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_12778);
													mem_vec_12778 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_12779);
													mem_vec_12779 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_12780);
													mem_vec_12780 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_12781);
													mem_vec_12781 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_12782);
													mem_vec_12782 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_12783);
													mem_vec_12783 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_12784);
													mem_vec_12784 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_12785);
													mem_vec_12785 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_12786);
													mem_vec_12786 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_12787);
													mem_vec_12787 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_12788);
													mem_vec_12788 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_12789);
													mem_vec_12789 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_12790);
													mem_vec_12790 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_12791);
													mem_vec_12791 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_12792);
													mem_vec_12792 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_12793);
													mem_vec_12793 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_12794);
													mem_vec_12794 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_12795);
													mem_vec_12795 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_12796);
													mem_vec_12796 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_12797);
													mem_vec_12797 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_12798);
													mem_vec_12798 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_12799);
													mem_vec_12799 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12772);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12773);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12774);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12775);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12776);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12777);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12778);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12779);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12780);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12781);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12782);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12783);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12784);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12785);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12786);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12787);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12788);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12789);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12790);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12791);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12792);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_12793);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12794);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_12795);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12796);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_12797);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12798);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_12799);
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