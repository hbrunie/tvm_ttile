#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (16, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (4, f); T (1, x);
  Lambda_apply y [((Iter 7), (Arg 5)); ((Iter 3), (Arg 7))]; T (1, f);
  T (8, c); T (4, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1184_p_0, cp_1, c1184, f, fp_0, f1232_p_0, f1233_p_0, fp_1, f1232_p_1, fp_2, f1232, f1233, h, hp_0, x, xp_0, x1440_p_0, x1441_p_0, xp_1, x1440_p_1, xp_2, x1440, x1441, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y720 = 0;
IND_TYPE x1442 = 0;
IND_TYPE h482 = 0;
IND_TYPE w = 0;
IND_TYPE c1185 = 0;
IND_TYPE f1234 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_12880 ,mem_vec_12881 ,mem_vec_12882 ,mem_vec_12883 ,mem_vec_12884 ,mem_vec_12885 ,mem_vec_12886 ,mem_vec_12887 ,mem_vec_12888 ,mem_vec_12889 ,mem_vec_12890 ,mem_vec_12891 ,mem_vec_12892 ,mem_vec_12893 ,mem_vec_12894 ,mem_vec_12895 ,mem_vec_12896 ,mem_vec_12897 ,mem_vec_12898 ,mem_vec_12899 ,mem_vec_12900 ,mem_vec_12901 ,mem_vec_12902 ,mem_vec_12903 ,mem_vec_12904 ,mem_vec_12905 ,mem_vec_12906 ,mem_vec_12907 ,mem_vec_12908 ,mem_vec_12909 ,mem_vec_12910 ,mem_vec_12911 ,mem_vec_12912 ,mem_vec_12913 ,mem_vec_12914 ,mem_vec_12915 ,mem_vec_12916 ,mem_vec_12917 ,mem_vec_12918 ,mem_vec_12919 ,mem_vec_12920 ,mem_vec_12921 ,mem_vec_12922 ,mem_vec_12923 ,mem_vec_12924 ,mem_vec_12925 ,mem_vec_12926 ,mem_vec_12927 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (f, 1) (128 / 128)
for (f1233 = f1234, f1233_p_0 = 0;
	f1233 < f1234 + 128;
	f1233 += 128, f1233_p_0 += 128){
	// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
	// T (x, 4) (56 / 14)
	for (x1441 = x1442, x1441_p_0 = 0;
		x1441 < x1442 + 56;
		x1441 += 14, x1441_p_0 += 14){
		// y = 56, x = 14, h = 3, w = 3, c = 128, f = 128
		// T (c, 8) (128 / 16)
		for (c1184 = c1185, c1184_p_0 = 0;
			c1184 < c1185 + 128;
			c1184 += 16, c1184_p_0 += 16){
			// y = 56, x = 14, h = 3, w = 3, c = 16, f = 128
			// T (f, 1) (128 / 128)
			for (f1232 = f1233, f1232_p_1 = f1233_p_0, f1232_p_0 = 0;
				f1232 < f1233 + 128;
				f1232 += 128, f1232_p_1 += 128, f1232_p_0 += 128){
					for (y = y720, yp_0 = 0;
						y < y720 + 35;
						y += 5, yp_0 += 5){
						// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 128
						// T (x, 1) (14 / 14)
						for (x1440 = x1441, x1440_p_1 = x1441_p_0, x1440_p_0 = 0;
							x1440 < x1441 + 14;
							x1440 += 14, x1440_p_1 += 14, x1440_p_0 += 14){
							// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 128
							// T (f, 4) (128 / 32)
							for (f = f1232, fp_2 = f1232_p_1, fp_1 = f1232_p_0, fp_0 = 0;
								f < f1232 + 128;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h482, hp_0 = 0;
									h < h482 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 16, f = 32
									// T (x, 14) (14 / 1)
									for (x = x1440, xp_2 = x1440_p_1, xp_1 = x1440_p_0, xp_0 = 0;
										x < x1440 + 14;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12880 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12881 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_12882 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12883 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_12884 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12885 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_12886 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12887 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_12888 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12889 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_12890 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12891 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12892 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12893 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_12894 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12895 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_12896 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12897 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_12898 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12899 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1184, cp_1 = c1184_p_0, cp_0 = 0;
													c < c1184 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12880);
													mem_vec_12880 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12881);
													mem_vec_12881 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12882);
													mem_vec_12882 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12883);
													mem_vec_12883 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12884);
													mem_vec_12884 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12885);
													mem_vec_12885 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12886);
													mem_vec_12886 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12887);
													mem_vec_12887 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12888);
													mem_vec_12888 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12889);
													mem_vec_12889 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12890);
													mem_vec_12890 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12891);
													mem_vec_12891 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12892);
													mem_vec_12892 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12893);
													mem_vec_12893 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12894);
													mem_vec_12894 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12895);
													mem_vec_12895 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12896);
													mem_vec_12896 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12897);
													mem_vec_12897 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12898);
													mem_vec_12898 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12899);
													mem_vec_12899 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_12880);
													mem_vec_12880 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_12881);
													mem_vec_12881 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_12882);
													mem_vec_12882 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_12883);
													mem_vec_12883 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_12884);
													mem_vec_12884 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_12885);
													mem_vec_12885 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_12886);
													mem_vec_12886 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_12887);
													mem_vec_12887 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_12888);
													mem_vec_12888 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_12889);
													mem_vec_12889 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_12890);
													mem_vec_12890 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_12891);
													mem_vec_12891 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_12892);
													mem_vec_12892 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_12893);
													mem_vec_12893 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_12894);
													mem_vec_12894 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_12895);
													mem_vec_12895 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_12896);
													mem_vec_12896 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_12897);
													mem_vec_12897 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_12898);
													mem_vec_12898 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_12899);
													mem_vec_12899 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_12880);
													mem_vec_12880 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_12881);
													mem_vec_12881 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_12882);
													mem_vec_12882 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_12883);
													mem_vec_12883 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_12884);
													mem_vec_12884 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_12885);
													mem_vec_12885 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_12886);
													mem_vec_12886 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_12887);
													mem_vec_12887 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_12888);
													mem_vec_12888 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_12889);
													mem_vec_12889 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_12890);
													mem_vec_12890 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_12891);
													mem_vec_12891 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_12892);
													mem_vec_12892 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_12893);
													mem_vec_12893 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_12894);
													mem_vec_12894 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_12895);
													mem_vec_12895 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_12896);
													mem_vec_12896 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_12897);
													mem_vec_12897 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_12898);
													mem_vec_12898 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_12899);
													mem_vec_12899 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12880);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12881);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12882);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12883);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12884);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12885);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12886);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12887);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12888);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12889);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12890);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12891);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12892);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12893);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12894);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12895);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12896);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12897);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12898);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12899);
									}
								}
							}
						}
					}
					for (y = y720 + 35, yp_0 = 0;
						y < y720 + 35 + 21;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 128
						// T (x, 1) (14 / 14)
						for (x1440 = x1441, x1440_p_1 = x1441_p_0, x1440_p_0 = 0;
							x1440 < x1441 + 14;
							x1440 += 14, x1440_p_1 += 14, x1440_p_0 += 14){
							// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 128
							// T (f, 4) (128 / 32)
							for (f = f1232, fp_2 = f1232_p_1, fp_1 = f1232_p_0, fp_0 = 0;
								f < f1232 + 128;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 14, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h482, hp_0 = 0;
									h < h482 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 16, f = 32
									// T (x, 14) (14 / 1)
									for (x = x1440, xp_2 = x1440_p_1, xp_1 = x1440_p_0, xp_0 = 0;
										x < x1440 + 14;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_12900 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_12901 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_12902 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_12903 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_12904 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_12905 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_12906 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_12907 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_12908 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_12909 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_12910 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_12911 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_12912 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_12913 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_12914 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_12915 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_12916 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_12917 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_12918 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_12919 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_12920 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_12921 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_12922 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_12923 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_12924 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_12925 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_12926 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_12927 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1184, cp_1 = c1184_p_0, cp_0 = 0;
													c < c1184 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_12900);
													mem_vec_12900 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_12901);
													mem_vec_12901 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_12902);
													mem_vec_12902 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_12903);
													mem_vec_12903 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_12904);
													mem_vec_12904 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_12905);
													mem_vec_12905 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_12906);
													mem_vec_12906 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_12907);
													mem_vec_12907 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_12908);
													mem_vec_12908 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_12909);
													mem_vec_12909 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_12910);
													mem_vec_12910 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_12911);
													mem_vec_12911 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_12912);
													mem_vec_12912 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_12913);
													mem_vec_12913 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_12914);
													mem_vec_12914 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_12915);
													mem_vec_12915 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_12916);
													mem_vec_12916 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_12917);
													mem_vec_12917 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_12918);
													mem_vec_12918 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_12919);
													mem_vec_12919 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_12920);
													mem_vec_12920 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_12921);
													mem_vec_12921 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_12922);
													mem_vec_12922 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_12923);
													mem_vec_12923 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_12924);
													mem_vec_12924 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_12925);
													mem_vec_12925 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_12926);
													mem_vec_12926 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_12927);
													mem_vec_12927 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_12900);
													mem_vec_12900 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_12901);
													mem_vec_12901 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_12902);
													mem_vec_12902 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_12903);
													mem_vec_12903 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_12904);
													mem_vec_12904 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_12905);
													mem_vec_12905 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_12906);
													mem_vec_12906 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_12907);
													mem_vec_12907 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_12908);
													mem_vec_12908 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_12909);
													mem_vec_12909 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_12910);
													mem_vec_12910 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_12911);
													mem_vec_12911 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_12912);
													mem_vec_12912 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_12913);
													mem_vec_12913 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_12914);
													mem_vec_12914 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_12915);
													mem_vec_12915 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_12916);
													mem_vec_12916 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_12917);
													mem_vec_12917 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_12918);
													mem_vec_12918 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_12919);
													mem_vec_12919 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_12920);
													mem_vec_12920 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_12921);
													mem_vec_12921 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_12922);
													mem_vec_12922 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_12923);
													mem_vec_12923 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_12924);
													mem_vec_12924 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_12925);
													mem_vec_12925 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_12926);
													mem_vec_12926 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_12927);
													mem_vec_12927 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_12900);
													mem_vec_12900 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_12901);
													mem_vec_12901 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_12902);
													mem_vec_12902 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_12903);
													mem_vec_12903 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_12904);
													mem_vec_12904 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_12905);
													mem_vec_12905 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_12906);
													mem_vec_12906 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_12907);
													mem_vec_12907 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_12908);
													mem_vec_12908 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_12909);
													mem_vec_12909 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_12910);
													mem_vec_12910 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_12911);
													mem_vec_12911 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_12912);
													mem_vec_12912 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_12913);
													mem_vec_12913 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_12914);
													mem_vec_12914 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_12915);
													mem_vec_12915 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_12916);
													mem_vec_12916 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_12917);
													mem_vec_12917 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_12918);
													mem_vec_12918 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_12919);
													mem_vec_12919 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_12920);
													mem_vec_12920 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_12921);
													mem_vec_12921 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_12922);
													mem_vec_12922 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_12923);
													mem_vec_12923 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_12924);
													mem_vec_12924 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_12925);
													mem_vec_12925 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_12926);
													mem_vec_12926 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_12927);
													mem_vec_12927 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_12900);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_12901);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_12902);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_12903);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_12904);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_12905);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_12906);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_12907);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_12908);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_12909);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_12910);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_12911);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_12912);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_12913);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_12914);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_12915);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_12916);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_12917);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_12918);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_12919);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_12920);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_12921);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_12922);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_12923);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_12924);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_12925);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_12926);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_12927);
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