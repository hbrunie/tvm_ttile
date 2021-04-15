#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, f);
  T (64, c); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1538_p_0, cp_1, c1538, f, fp_0, f1080_p_0, f1081_p_0, fp_1, f1080_p_1, fp_2, f1080, f1081, h, hp_0, x, xp_0, x1496_p_0, x1497_p_0, xp_1, x1496_p_1, xp_2, x1496, x1497, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y748 = 0;
IND_TYPE x1498 = 0;
IND_TYPE h438 = 0;
IND_TYPE w = 0;
IND_TYPE c1539 = 0;
IND_TYPE f1082 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_15944 ,mem_vec_15945 ,mem_vec_15946 ,mem_vec_15947 ,mem_vec_15948 ,mem_vec_15949 ,mem_vec_15950 ,mem_vec_15951 ,mem_vec_15952 ,mem_vec_15953 ,mem_vec_15954 ,mem_vec_15955 ,mem_vec_15956 ,mem_vec_15957 ,mem_vec_15958 ,mem_vec_15959 ,mem_vec_15960 ,mem_vec_15961 ,mem_vec_15962 ,mem_vec_15963 ,mem_vec_15964 ,mem_vec_15965 ,mem_vec_15966 ,mem_vec_15967 ,mem_vec_15968 ,mem_vec_15969 ,mem_vec_15970 ,mem_vec_15971 ,mem_vec_15972 ,mem_vec_15973 ,mem_vec_15974 ,mem_vec_15975 ,mem_vec_15976 ,mem_vec_15977 ,mem_vec_15978 ,mem_vec_15979 ,mem_vec_15980 ,mem_vec_15981 ,mem_vec_15982 ,mem_vec_15983 ,mem_vec_15984 ,mem_vec_15985 ,mem_vec_15986 ,mem_vec_15987 ,mem_vec_15988 ,mem_vec_15989 ,mem_vec_15990 ,mem_vec_15991 ,mem_vec_15992 ,mem_vec_15993 ,mem_vec_15994 ,mem_vec_15995 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f1081 = f1082, f1081_p_0 = 0;
	f1081 < f1082 + 512;
	f1081 += 128, f1081_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (x, 1) (34 / 34)
	for (x1497 = x1498, x1497_p_0 = 0;
		x1497 < x1498 + 34;
		x1497 += 34, x1497_p_0 += 34){
		// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
		// T (c, 64) (256 / 4)
		for (c1538 = c1539, c1538_p_0 = 0;
			c1538 < c1539 + 256;
			c1538 += 4, c1538_p_0 += 4){
			// y = 34, x = 34, h = 3, w = 3, c = 4, f = 128
			// T (f, 2) (128 / 64)
			for (f1080 = f1081, f1080_p_1 = f1081_p_0, f1080_p_0 = 0;
				f1080 < f1081 + 128;
				f1080 += 64, f1080_p_1 += 64, f1080_p_0 += 64){
					for (y = y748, yp_0 = 0;
						y < y748 + 6;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
						// T (x, 1) (34 / 34)
						for (x1496 = x1497, x1496_p_1 = x1497_p_0, x1496_p_0 = 0;
							x1496 < x1497 + 34;
							x1496 += 34, x1496_p_1 += 34, x1496_p_0 += 34){
							// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1080, fp_2 = f1080_p_1, fp_1 = f1080_p_0, fp_0 = 0;
								f < f1080 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h438, hp_0 = 0;
									h < h438 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 3, c = 4, f = 32
									// T (x, 34) (34 / 1)
									for (x = x1496, xp_2 = x1496_p_1, xp_1 = x1496_p_0, xp_0 = 0;
										x < x1496 + 34;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_15944 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_15945 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_15946 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_15947 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_15948 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_15949 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_15950 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_15951 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_15952 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_15953 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_15954 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_15955 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_15956 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_15957 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_15958 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_15959 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_15960 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_15961 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_15962 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_15963 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_15964 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_15965 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_15966 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_15967 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1538, cp_1 = c1538_p_0, cp_0 = 0;
													c < c1538 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_15944);
													mem_vec_15944 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_15945);
													mem_vec_15945 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_15946);
													mem_vec_15946 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_15947);
													mem_vec_15947 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_15948);
													mem_vec_15948 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_15949);
													mem_vec_15949 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_15950);
													mem_vec_15950 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_15951);
													mem_vec_15951 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_15952);
													mem_vec_15952 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_15953);
													mem_vec_15953 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_15954);
													mem_vec_15954 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_15955);
													mem_vec_15955 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_15956);
													mem_vec_15956 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_15957);
													mem_vec_15957 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_15958);
													mem_vec_15958 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_15959);
													mem_vec_15959 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_15960);
													mem_vec_15960 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_15961);
													mem_vec_15961 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_15962);
													mem_vec_15962 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_15963);
													mem_vec_15963 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_15964);
													mem_vec_15964 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_15965);
													mem_vec_15965 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_15966);
													mem_vec_15966 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_15967);
													mem_vec_15967 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_15944);
													mem_vec_15944 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_15945);
													mem_vec_15945 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_15946);
													mem_vec_15946 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_15947);
													mem_vec_15947 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_15948);
													mem_vec_15948 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_15949);
													mem_vec_15949 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_15950);
													mem_vec_15950 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_15951);
													mem_vec_15951 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_15952);
													mem_vec_15952 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_15953);
													mem_vec_15953 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_15954);
													mem_vec_15954 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_15955);
													mem_vec_15955 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_15956);
													mem_vec_15956 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_15957);
													mem_vec_15957 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_15958);
													mem_vec_15958 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_15959);
													mem_vec_15959 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_15960);
													mem_vec_15960 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_15961);
													mem_vec_15961 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_15962);
													mem_vec_15962 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_15963);
													mem_vec_15963 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_15964);
													mem_vec_15964 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_15965);
													mem_vec_15965 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_15966);
													mem_vec_15966 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_15967);
													mem_vec_15967 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_15944);
													mem_vec_15944 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_15945);
													mem_vec_15945 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_15946);
													mem_vec_15946 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_15947);
													mem_vec_15947 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_15948);
													mem_vec_15948 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_15949);
													mem_vec_15949 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_15950);
													mem_vec_15950 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_15951);
													mem_vec_15951 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_15952);
													mem_vec_15952 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_15953);
													mem_vec_15953 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_15954);
													mem_vec_15954 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_15955);
													mem_vec_15955 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_15956);
													mem_vec_15956 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_15957);
													mem_vec_15957 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_15958);
													mem_vec_15958 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_15959);
													mem_vec_15959 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_15960);
													mem_vec_15960 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_15961);
													mem_vec_15961 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_15962);
													mem_vec_15962 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_15963);
													mem_vec_15963 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_15964);
													mem_vec_15964 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_15965);
													mem_vec_15965 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_15966);
													mem_vec_15966 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_15967);
													mem_vec_15967 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15944);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_15945);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15946);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_15947);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15948);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_15949);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15950);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_15951);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15952);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_15953);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15954);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_15955);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15956);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_15957);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15958);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_15959);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15960);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_15961);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15962);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_15963);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15964);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_15965);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15966);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_15967);
									}
								}
							}
						}
					}
					for (y = y748 + 6, yp_0 = 0;
						y < y748 + 6 + 28;
						y += 7, yp_0 += 7){
						// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
						// T (x, 1) (34 / 34)
						for (x1496 = x1497, x1496_p_1 = x1497_p_0, x1496_p_0 = 0;
							x1496 < x1497 + 34;
							x1496 += 34, x1496_p_1 += 34, x1496_p_0 += 34){
							// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
							// T (f, 2) (64 / 32)
							for (f = f1080, fp_2 = f1080_p_1, fp_1 = f1080_p_0, fp_0 = 0;
								f < f1080 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h438, hp_0 = 0;
									h < h438 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 3, c = 4, f = 32
									// T (x, 34) (34 / 1)
									for (x = x1496, xp_2 = x1496_p_1, xp_1 = x1496_p_0, xp_0 = 0;
										x < x1496 + 34;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_15968 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_15969 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_15970 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_15971 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_15972 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_15973 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_15974 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_15975 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_15976 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_15977 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_15978 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_15979 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_15980 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_15981 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_15982 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_15983 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_15984 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_15985 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_15986 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_15987 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_15988 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_15989 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_15990 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_15991 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_15992 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_15993 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_15994 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_15995 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1538, cp_1 = c1538_p_0, cp_0 = 0;
													c < c1538 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_15968);
													mem_vec_15968 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_15969);
													mem_vec_15969 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_15970);
													mem_vec_15970 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_15971);
													mem_vec_15971 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_15972);
													mem_vec_15972 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_15973);
													mem_vec_15973 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_15974);
													mem_vec_15974 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_15975);
													mem_vec_15975 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_15976);
													mem_vec_15976 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_15977);
													mem_vec_15977 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_15978);
													mem_vec_15978 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_15979);
													mem_vec_15979 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_15980);
													mem_vec_15980 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_15981);
													mem_vec_15981 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_15982);
													mem_vec_15982 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_15983);
													mem_vec_15983 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_15984);
													mem_vec_15984 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_15985);
													mem_vec_15985 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_15986);
													mem_vec_15986 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_15987);
													mem_vec_15987 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_15988);
													mem_vec_15988 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_15989);
													mem_vec_15989 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_15990);
													mem_vec_15990 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_15991);
													mem_vec_15991 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_15992);
													mem_vec_15992 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_15993);
													mem_vec_15993 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_15994);
													mem_vec_15994 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_15995);
													mem_vec_15995 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_15968);
													mem_vec_15968 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_15969);
													mem_vec_15969 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_15970);
													mem_vec_15970 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_15971);
													mem_vec_15971 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_15972);
													mem_vec_15972 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_15973);
													mem_vec_15973 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_15974);
													mem_vec_15974 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_15975);
													mem_vec_15975 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_15976);
													mem_vec_15976 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_15977);
													mem_vec_15977 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_15978);
													mem_vec_15978 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_15979);
													mem_vec_15979 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_15980);
													mem_vec_15980 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_15981);
													mem_vec_15981 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_15982);
													mem_vec_15982 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_15983);
													mem_vec_15983 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_15984);
													mem_vec_15984 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_15985);
													mem_vec_15985 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_15986);
													mem_vec_15986 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_15987);
													mem_vec_15987 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_15988);
													mem_vec_15988 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_15989);
													mem_vec_15989 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_15990);
													mem_vec_15990 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_15991);
													mem_vec_15991 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_15992);
													mem_vec_15992 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_15993);
													mem_vec_15993 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_15994);
													mem_vec_15994 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_15995);
													mem_vec_15995 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_15968);
													mem_vec_15968 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_15969);
													mem_vec_15969 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_15970);
													mem_vec_15970 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_15971);
													mem_vec_15971 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_15972);
													mem_vec_15972 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_15973);
													mem_vec_15973 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_15974);
													mem_vec_15974 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_15975);
													mem_vec_15975 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_15976);
													mem_vec_15976 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_15977);
													mem_vec_15977 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_15978);
													mem_vec_15978 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_15979);
													mem_vec_15979 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_15980);
													mem_vec_15980 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_15981);
													mem_vec_15981 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_15982);
													mem_vec_15982 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_15983);
													mem_vec_15983 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_15984);
													mem_vec_15984 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_15985);
													mem_vec_15985 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_15986);
													mem_vec_15986 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_15987);
													mem_vec_15987 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_15988);
													mem_vec_15988 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_15989);
													mem_vec_15989 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_15990);
													mem_vec_15990 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_15991);
													mem_vec_15991 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_15992);
													mem_vec_15992 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_15993);
													mem_vec_15993 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_15994);
													mem_vec_15994 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_15995);
													mem_vec_15995 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_15968);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_15969);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_15970);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_15971);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_15972);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_15973);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_15974);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_15975);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_15976);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_15977);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_15978);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_15979);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_15980);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_15981);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_15982);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_15983);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_15984);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_15985);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_15986);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_15987);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_15988);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_15989);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_15990);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_15991);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_15992);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_15993);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_15994);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_15995);
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