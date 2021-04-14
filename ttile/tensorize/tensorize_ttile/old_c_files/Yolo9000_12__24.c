#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (34, x);
  T (3, h); T (1, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (8, f);
  T (64, c); T (1, f)]
*/
IND_TYPE c, cp_0, c1232_p_0, cp_1, c1232, f, fp_0, f1336_p_0, f1337_p_0, fp_1, f1336_p_1, fp_2, f1336, f1337, h, hp_0, x, xp_0, x1232_p_0, xp_1, x1232, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y760 = 0;
IND_TYPE x1233 = 0;
IND_TYPE h600 = 0;
IND_TYPE w = 0;
IND_TYPE c1233 = 0;
IND_TYPE f1338 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14910 ,mem_vec_14911 ,mem_vec_14912 ,mem_vec_14913 ,mem_vec_14914 ,mem_vec_14915 ,mem_vec_14916 ,mem_vec_14917 ,mem_vec_14918 ,mem_vec_14919 ,mem_vec_14920 ,mem_vec_14921 ,mem_vec_14922 ,mem_vec_14923 ,mem_vec_14924 ,mem_vec_14925 ,mem_vec_14926 ,mem_vec_14927 ,mem_vec_14928 ,mem_vec_14929 ,mem_vec_14930 ,mem_vec_14931 ,mem_vec_14932 ,mem_vec_14933 ,mem_vec_14934 ,mem_vec_14935 ,mem_vec_14936 ,mem_vec_14937 ,mem_vec_14938 ,mem_vec_14939 ,mem_vec_14940 ,mem_vec_14941 ,mem_vec_14942 ,mem_vec_14943 ,mem_vec_14944 ,mem_vec_14945 ,mem_vec_14946 ,mem_vec_14947 ,mem_vec_14948 ,mem_vec_14949 ,mem_vec_14950 ,mem_vec_14951 ,mem_vec_14952 ,mem_vec_14953 ,mem_vec_14954 ,mem_vec_14955 ,mem_vec_14956 ,mem_vec_14957 ,mem_vec_14958 ,mem_vec_14959 ,mem_vec_14960 ,mem_vec_14961 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f1337 = f1338, f1337_p_0 = 0;
	f1337 < f1338 + 512;
	f1337 += 512, f1337_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 64) (256 / 4)
	for (c1232 = c1233, c1232_p_0 = 0;
		c1232 < c1233 + 256;
		c1232 += 4, c1232_p_0 += 4){
		// y = 34, x = 34, h = 3, w = 3, c = 4, f = 512
		// T (f, 8) (512 / 64)
		for (f1336 = f1337, f1336_p_1 = f1337_p_0, f1336_p_0 = 0;
			f1336 < f1337 + 512;
			f1336 += 64, f1336_p_1 += 64, f1336_p_0 += 64){
				for (y = y760, yp_0 = 0;
					y < y760 + 6;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
					// T (x, 1) (34 / 34)
					for (x1232 = x1233, x1232_p_0 = 0;
						x1232 < x1233 + 34;
						x1232 += 34, x1232_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
						// T (f, 1) (64 / 64)
						for (f = f1336, fp_2 = f1336_p_1, fp_1 = f1336_p_0, fp_0 = 0;
							f < f1336 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h600, hp_0 = 0;
								h < h600 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 4, f = 64
								// T (x, 34) (34 / 1)
								for (x = x1232, xp_1 = x1232_p_0, xp_0 = 0;
									x < x1232 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14910 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14911 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14912 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_14913 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_14914 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14915 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14916 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_14917 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_14918 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14919 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14920 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_14921 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_14922 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14923 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14924 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_14925 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_14926 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14927 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14928 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_14929 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_14930 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14931 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14932 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_14933 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c1232, cp_1 = c1232_p_0, cp_0 = 0;
												c < c1232 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14910);
												mem_vec_14910 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14911);
												mem_vec_14911 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14912);
												mem_vec_14912 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14913);
												mem_vec_14913 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14914);
												mem_vec_14914 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14915);
												mem_vec_14915 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14916);
												mem_vec_14916 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14917);
												mem_vec_14917 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14918);
												mem_vec_14918 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14919);
												mem_vec_14919 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14920);
												mem_vec_14920 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14921);
												mem_vec_14921 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14922);
												mem_vec_14922 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14923);
												mem_vec_14923 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14924);
												mem_vec_14924 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14925);
												mem_vec_14925 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14926);
												mem_vec_14926 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14927);
												mem_vec_14927 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14928);
												mem_vec_14928 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14929);
												mem_vec_14929 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14930);
												mem_vec_14930 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14931);
												mem_vec_14931 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14932);
												mem_vec_14932 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14933);
												mem_vec_14933 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_14910);
												mem_vec_14910 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_14911);
												mem_vec_14911 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_14912);
												mem_vec_14912 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_14913);
												mem_vec_14913 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14914);
												mem_vec_14914 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_14915);
												mem_vec_14915 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_14916);
												mem_vec_14916 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_14917);
												mem_vec_14917 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_14918);
												mem_vec_14918 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_14919);
												mem_vec_14919 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_14920);
												mem_vec_14920 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_14921);
												mem_vec_14921 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_14922);
												mem_vec_14922 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_14923);
												mem_vec_14923 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_14924);
												mem_vec_14924 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_14925);
												mem_vec_14925 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14926);
												mem_vec_14926 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_14927);
												mem_vec_14927 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_14928);
												mem_vec_14928 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_14929);
												mem_vec_14929 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_14930);
												mem_vec_14930 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_14931);
												mem_vec_14931 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_14932);
												mem_vec_14932 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_14933);
												mem_vec_14933 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_14910);
												mem_vec_14910 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_14911);
												mem_vec_14911 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_14912);
												mem_vec_14912 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_14913);
												mem_vec_14913 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_14914);
												mem_vec_14914 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_14915);
												mem_vec_14915 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_14916);
												mem_vec_14916 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_14917);
												mem_vec_14917 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_14918);
												mem_vec_14918 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_14919);
												mem_vec_14919 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_14920);
												mem_vec_14920 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_14921);
												mem_vec_14921 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_14922);
												mem_vec_14922 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_14923);
												mem_vec_14923 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_14924);
												mem_vec_14924 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_14925);
												mem_vec_14925 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_14926);
												mem_vec_14926 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_14927);
												mem_vec_14927 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_14928);
												mem_vec_14928 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_14929);
												mem_vec_14929 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_14930);
												mem_vec_14930 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_14931);
												mem_vec_14931 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_14932);
												mem_vec_14932 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_14933);
												mem_vec_14933 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14910);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14911);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14912);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14913);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14914);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14915);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14916);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14917);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14918);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14919);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14920);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14921);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14922);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14923);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14924);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14925);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14926);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14927);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14928);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14929);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14930);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14931);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14932);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14933);
								}
							}
						}
					}
				}
				for (y = y760 + 6, yp_0 = 0;
					y < y760 + 6 + 28;
					y += 7, yp_0 += 7){
					// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
					// T (x, 1) (34 / 34)
					for (x1232 = x1233, x1232_p_0 = 0;
						x1232 < x1233 + 34;
						x1232 += 34, x1232_p_0 += 34){
						// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
						// T (f, 1) (64 / 64)
						for (f = f1336, fp_2 = f1336_p_1, fp_1 = f1336_p_0, fp_0 = 0;
							f < f1336 + 64;
							f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							// y = ph_y, x = 34, h = 3, w = 3, c = 4, f = 64
							// T (h, 3) (3 / 1)
							for (h = h600, hp_0 = 0;
								h < h600 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 4, f = 64
								// T (x, 34) (34 / 1)
								for (x = x1232, xp_1 = x1232_p_0, xp_0 = 0;
									x < x1232 + 34;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14934 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14935 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14936 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_14937 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_14938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_14941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_14942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_14945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_14946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_14949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_14950 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14951 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_14953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_14954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_14957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											mem_vec_14958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
											mem_vec_14961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 64
											// T (c, 4) (4 / 1)
											for (c = c1232, cp_1 = c1232_p_0, cp_0 = 0;
												c < c1232 + 4;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14934);
												mem_vec_14934 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14935);
												mem_vec_14935 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_14936);
												mem_vec_14936 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_14937);
												mem_vec_14937 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_14938);
												mem_vec_14938 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_14939);
												mem_vec_14939 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_14940);
												mem_vec_14940 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_14941);
												mem_vec_14941 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14942);
												mem_vec_14942 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14943);
												mem_vec_14943 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_14944);
												mem_vec_14944 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_14945);
												mem_vec_14945 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_14946);
												mem_vec_14946 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_14947);
												mem_vec_14947 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_14948);
												mem_vec_14948 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_14949);
												mem_vec_14949 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_14950);
												mem_vec_14950 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_14951);
												mem_vec_14951 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_14952);
												mem_vec_14952 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_14953);
												mem_vec_14953 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14954);
												mem_vec_14954 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14955);
												mem_vec_14955 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_14956);
												mem_vec_14956 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_14957);
												mem_vec_14957 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_14958);
												mem_vec_14958 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_14959);
												mem_vec_14959 = vec_36;



												vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_14960);
												mem_vec_14960 = vec_37;



												vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_14961);
												mem_vec_14961 = vec_38;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_40 = _mm512_set1_ps(scal_7);
												vec_41 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_39 = _mm512_fmadd_ps(vec_40, vec_41, mem_vec_14934);
												mem_vec_14934 = vec_39;

												vec_43 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_42 = _mm512_fmadd_ps(vec_40, vec_43, mem_vec_14935);
												mem_vec_14935 = vec_42;

												vec_45 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_44 = _mm512_fmadd_ps(vec_40, vec_45, mem_vec_14936);
												mem_vec_14936 = vec_44;

												vec_47 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_46 = _mm512_fmadd_ps(vec_40, vec_47, mem_vec_14937);
												mem_vec_14937 = vec_46;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_41, mem_vec_14938);
												mem_vec_14938 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_43, mem_vec_14939);
												mem_vec_14939 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_45, mem_vec_14940);
												mem_vec_14940 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_47, mem_vec_14941);
												mem_vec_14941 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_41, mem_vec_14942);
												mem_vec_14942 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_43, mem_vec_14943);
												mem_vec_14943 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_45, mem_vec_14944);
												mem_vec_14944 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_47, mem_vec_14945);
												mem_vec_14945 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_41, mem_vec_14946);
												mem_vec_14946 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_43, mem_vec_14947);
												mem_vec_14947 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_45, mem_vec_14948);
												mem_vec_14948 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_47, mem_vec_14949);
												mem_vec_14949 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_41, mem_vec_14950);
												mem_vec_14950 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_43, mem_vec_14951);
												mem_vec_14951 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_45, mem_vec_14952);
												mem_vec_14952 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_47, mem_vec_14953);
												mem_vec_14953 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);


												vec_68 = _mm512_fmadd_ps(vec_69, vec_41, mem_vec_14954);
												mem_vec_14954 = vec_68;



												vec_70 = _mm512_fmadd_ps(vec_69, vec_43, mem_vec_14955);
												mem_vec_14955 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_69, vec_45, mem_vec_14956);
												mem_vec_14956 = vec_71;



												vec_72 = _mm512_fmadd_ps(vec_69, vec_47, mem_vec_14957);
												mem_vec_14957 = vec_72;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
												vec_74 = _mm512_set1_ps(scal_13);


												vec_73 = _mm512_fmadd_ps(vec_74, vec_41, mem_vec_14958);
												mem_vec_14958 = vec_73;



												vec_75 = _mm512_fmadd_ps(vec_74, vec_43, mem_vec_14959);
												mem_vec_14959 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_74, vec_45, mem_vec_14960);
												mem_vec_14960 = vec_76;



												vec_77 = _mm512_fmadd_ps(vec_74, vec_47, mem_vec_14961);
												mem_vec_14961 = vec_77;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_79 = _mm512_set1_ps(scal_14);
												vec_80 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_78 = _mm512_fmadd_ps(vec_79, vec_80, mem_vec_14934);
												mem_vec_14934 = vec_78;

												vec_82 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_81 = _mm512_fmadd_ps(vec_79, vec_82, mem_vec_14935);
												mem_vec_14935 = vec_81;

												vec_84 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_83 = _mm512_fmadd_ps(vec_79, vec_84, mem_vec_14936);
												mem_vec_14936 = vec_83;

												vec_86 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_85 = _mm512_fmadd_ps(vec_79, vec_86, mem_vec_14937);
												mem_vec_14937 = vec_85;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_80, mem_vec_14938);
												mem_vec_14938 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_82, mem_vec_14939);
												mem_vec_14939 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_84, mem_vec_14940);
												mem_vec_14940 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_86, mem_vec_14941);
												mem_vec_14941 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_80, mem_vec_14942);
												mem_vec_14942 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_82, mem_vec_14943);
												mem_vec_14943 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_84, mem_vec_14944);
												mem_vec_14944 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_86, mem_vec_14945);
												mem_vec_14945 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_80, mem_vec_14946);
												mem_vec_14946 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_82, mem_vec_14947);
												mem_vec_14947 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_84, mem_vec_14948);
												mem_vec_14948 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_86, mem_vec_14949);
												mem_vec_14949 = vec_101;
												scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_103 = _mm512_set1_ps(scal_18);


												vec_102 = _mm512_fmadd_ps(vec_103, vec_80, mem_vec_14950);
												mem_vec_14950 = vec_102;



												vec_104 = _mm512_fmadd_ps(vec_103, vec_82, mem_vec_14951);
												mem_vec_14951 = vec_104;



												vec_105 = _mm512_fmadd_ps(vec_103, vec_84, mem_vec_14952);
												mem_vec_14952 = vec_105;



												vec_106 = _mm512_fmadd_ps(vec_103, vec_86, mem_vec_14953);
												mem_vec_14953 = vec_106;
												scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_108 = _mm512_set1_ps(scal_19);


												vec_107 = _mm512_fmadd_ps(vec_108, vec_80, mem_vec_14954);
												mem_vec_14954 = vec_107;



												vec_109 = _mm512_fmadd_ps(vec_108, vec_82, mem_vec_14955);
												mem_vec_14955 = vec_109;



												vec_110 = _mm512_fmadd_ps(vec_108, vec_84, mem_vec_14956);
												mem_vec_14956 = vec_110;



												vec_111 = _mm512_fmadd_ps(vec_108, vec_86, mem_vec_14957);
												mem_vec_14957 = vec_111;
												scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
												vec_113 = _mm512_set1_ps(scal_20);


												vec_112 = _mm512_fmadd_ps(vec_113, vec_80, mem_vec_14958);
												mem_vec_14958 = vec_112;



												vec_114 = _mm512_fmadd_ps(vec_113, vec_82, mem_vec_14959);
												mem_vec_14959 = vec_114;



												vec_115 = _mm512_fmadd_ps(vec_113, vec_84, mem_vec_14960);
												mem_vec_14960 = vec_115;



												vec_116 = _mm512_fmadd_ps(vec_113, vec_86, mem_vec_14961);
												mem_vec_14961 = vec_116;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14934);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14935);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_14936);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_14937);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14938);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14939);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_14940);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_14941);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14942);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14943);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_14944);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_14945);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14946);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14947);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_14948);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_14949);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14950);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14951);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_14952);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_14953);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14954);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14955);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_14956);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_14957);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14959);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_14960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_14961);
								}
							}
						}
					}
				}
		}
	}
}


}