#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (2, c); Hoist_vars [c]; T (2, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 9)); ((Iter 5), (Arg 10))];
  T (8, f); T (64, c); T (1, f); T (34, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1170_p_0, cp_1, c1170, f, fp_0, f1484_p_0, f1485_p_0, fp_1, f1484_p_1, fp_2, f1484, f1485, w, wp_0, x, xp_0, x1260_p_0, xp_1, x1260, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y780 = 0;
IND_TYPE x1261 = 0;
IND_TYPE h = 0;
IND_TYPE w728 = 0;
IND_TYPE c1171 = 0;
IND_TYPE f1486 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_14932 ,mem_vec_14933 ,mem_vec_14934 ,mem_vec_14935 ,mem_vec_14936 ,mem_vec_14937 ,mem_vec_14938 ,mem_vec_14939 ,mem_vec_14940 ,mem_vec_14941 ,mem_vec_14942 ,mem_vec_14943 ,mem_vec_14944 ,mem_vec_14945 ,mem_vec_14946 ,mem_vec_14947 ,mem_vec_14948 ,mem_vec_14949 ,mem_vec_14950 ,mem_vec_14951 ,mem_vec_14952 ,mem_vec_14953 ,mem_vec_14954 ,mem_vec_14955 ,mem_vec_14956 ,mem_vec_14957 ,mem_vec_14958 ,mem_vec_14959 ,mem_vec_14960 ,mem_vec_14961 ,mem_vec_14962 ,mem_vec_14963 ,mem_vec_14964 ,mem_vec_14965 ,mem_vec_14966 ,mem_vec_14967 ,mem_vec_14968 ,mem_vec_14969 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1485 = f1486, f1485_p_0 = 0;
	f1485 < f1486 + 256;
	f1485 += 256, f1485_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 34) (68 / 2)
	for (x1260 = x1261, x1260_p_0 = 0;
		x1260 < x1261 + 68;
		x1260 += 2, x1260_p_0 += 2){
		// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
		// T (f, 1) (256 / 256)
		for (f1484 = f1485, f1484_p_1 = f1485_p_0, f1484_p_0 = 0;
			f1484 < f1485 + 256;
			f1484 += 256, f1484_p_1 += 256, f1484_p_0 += 256){
			// y = 68, x = 2, h = 3, w = 3, c = 128, f = 256
			// T (c, 64) (128 / 2)
			for (c1170 = c1171, c1170_p_0 = 0;
				c1170 < c1171 + 128;
				c1170 += 2, c1170_p_0 += 2){
				// y = 68, x = 2, h = 3, w = 3, c = 2, f = 256
				// T (f, 8) (256 / 32)
				for (f = f1484, fp_2 = f1484_p_1, fp_1 = f1484_p_0, fp_0 = 0;
					f < f1484 + 256;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y780, yp_0 = 0;
							y < y780 + 18;
							y += 9, yp_0 += 9){
							// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w728, wp_0 = 0;
								w < w728 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 2, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1260, xp_1 = x1260_p_0, xp_0 = 0;
									x < x1260 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14932 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14933 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14934 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14935 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14936 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14937 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14938 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14939 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14940 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14941 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14942 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14943 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14944 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14945 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14946 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_14947 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_14948 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_14949 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1170, cp_1 = c1170_p_0, cp_0 = 0;
												c < c1170 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14932);
												mem_vec_14932 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14933);
												mem_vec_14933 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14934);
												mem_vec_14934 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14935);
												mem_vec_14935 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14936);
												mem_vec_14936 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14937);
												mem_vec_14937 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14938);
												mem_vec_14938 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14939);
												mem_vec_14939 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14940);
												mem_vec_14940 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14941);
												mem_vec_14941 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14942);
												mem_vec_14942 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14943);
												mem_vec_14943 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14944);
												mem_vec_14944 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14945);
												mem_vec_14945 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14946);
												mem_vec_14946 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14947);
												mem_vec_14947 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14948);
												mem_vec_14948 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14949);
												mem_vec_14949 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm512_set1_ps(scal_9);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_14932);
												mem_vec_14932 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_14933);
												mem_vec_14933 = vec_32;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_35 = _mm512_set1_ps(scal_10);


												vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_14934);
												mem_vec_14934 = vec_34;



												vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_14935);
												mem_vec_14935 = vec_36;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_14936);
												mem_vec_14936 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_14937);
												mem_vec_14937 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_14938);
												mem_vec_14938 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_14939);
												mem_vec_14939 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_14940);
												mem_vec_14940 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_14941);
												mem_vec_14941 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_14942);
												mem_vec_14942 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_14943);
												mem_vec_14943 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_14944);
												mem_vec_14944 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_14945);
												mem_vec_14945 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_14946);
												mem_vec_14946 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_14947);
												mem_vec_14947 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_14948);
												mem_vec_14948 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_14949);
												mem_vec_14949 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm512_set1_ps(scal_18);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_14932);
												mem_vec_14932 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_14933);
												mem_vec_14933 = vec_61;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_64 = _mm512_set1_ps(scal_19);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_14934);
												mem_vec_14934 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_14935);
												mem_vec_14935 = vec_65;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_67 = _mm512_set1_ps(scal_20);


												vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_14936);
												mem_vec_14936 = vec_66;



												vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_14937);
												mem_vec_14937 = vec_68;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_14938);
												mem_vec_14938 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_14939);
												mem_vec_14939 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_14940);
												mem_vec_14940 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_14941);
												mem_vec_14941 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_14942);
												mem_vec_14942 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_14943);
												mem_vec_14943 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_14944);
												mem_vec_14944 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_14945);
												mem_vec_14945 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_14946);
												mem_vec_14946 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_14947);
												mem_vec_14947 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_14948);
												mem_vec_14948 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_14949);
												mem_vec_14949 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14932);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14933);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14934);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14935);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14936);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14937);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14938);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14939);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14940);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14941);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14942);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14943);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14944);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14945);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14946);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14947);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14948);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14949);
								}
							}
						}
						for (y = y780 + 18, yp_0 = 0;
							y < y780 + 18 + 50;
							y += 10, yp_0 += 10){
							// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 32
							// T (w, 3) (3 / 1)
							for (w = w728, wp_0 = 0;
								w < w728 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 2, f = 32
								// T (x, 2) (2 / 1)
								for (x = x1260, xp_1 = x1260_p_0, xp_0 = 0;
									x < x1260 + 2;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_14950 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_14951 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_14952 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_14953 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_14954 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_14955 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_14956 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_14957 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_14958 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_14959 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_14960 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_14961 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_14962 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_14963 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_14964 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_14965 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_14966 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_14967 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_14968 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_14969 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 2, f = 32
											// T (c, 2) (2 / 1)
											for (c = c1170, cp_1 = c1170_p_0, cp_0 = 0;
												c < c1170 + 2;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_14950);
												mem_vec_14950 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_14951);
												mem_vec_14951 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_14952);
												mem_vec_14952 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_14953);
												mem_vec_14953 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_14954);
												mem_vec_14954 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_14955);
												mem_vec_14955 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_14956);
												mem_vec_14956 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_14957);
												mem_vec_14957 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_14958);
												mem_vec_14958 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_14959);
												mem_vec_14959 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_14960);
												mem_vec_14960 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_14961);
												mem_vec_14961 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_14962);
												mem_vec_14962 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_14963);
												mem_vec_14963 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_14964);
												mem_vec_14964 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_14965);
												mem_vec_14965 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_14966);
												mem_vec_14966 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_14967);
												mem_vec_14967 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_14968);
												mem_vec_14968 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_14969);
												mem_vec_14969 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_33 = _mm512_set1_ps(scal_10);
												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_32 = _mm512_fmadd_ps(vec_33, vec_34, mem_vec_14950);
												mem_vec_14950 = vec_32;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_35 = _mm512_fmadd_ps(vec_33, vec_36, mem_vec_14951);
												mem_vec_14951 = vec_35;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_38 = _mm512_set1_ps(scal_11);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_14952);
												mem_vec_14952 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_14953);
												mem_vec_14953 = vec_39;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_41 = _mm512_set1_ps(scal_12);


												vec_40 = _mm512_fmadd_ps(vec_41, vec_34, mem_vec_14954);
												mem_vec_14954 = vec_40;



												vec_42 = _mm512_fmadd_ps(vec_41, vec_36, mem_vec_14955);
												mem_vec_14955 = vec_42;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_13);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_34, mem_vec_14956);
												mem_vec_14956 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_14957);
												mem_vec_14957 = vec_45;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_47 = _mm512_set1_ps(scal_14);


												vec_46 = _mm512_fmadd_ps(vec_47, vec_34, mem_vec_14958);
												mem_vec_14958 = vec_46;



												vec_48 = _mm512_fmadd_ps(vec_47, vec_36, mem_vec_14959);
												mem_vec_14959 = vec_48;
												scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
												vec_50 = _mm512_set1_ps(scal_15);


												vec_49 = _mm512_fmadd_ps(vec_50, vec_34, mem_vec_14960);
												mem_vec_14960 = vec_49;



												vec_51 = _mm512_fmadd_ps(vec_50, vec_36, mem_vec_14961);
												mem_vec_14961 = vec_51;
												scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
												vec_53 = _mm512_set1_ps(scal_16);


												vec_52 = _mm512_fmadd_ps(vec_53, vec_34, mem_vec_14962);
												mem_vec_14962 = vec_52;



												vec_54 = _mm512_fmadd_ps(vec_53, vec_36, mem_vec_14963);
												mem_vec_14963 = vec_54;
												scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
												vec_56 = _mm512_set1_ps(scal_17);


												vec_55 = _mm512_fmadd_ps(vec_56, vec_34, mem_vec_14964);
												mem_vec_14964 = vec_55;



												vec_57 = _mm512_fmadd_ps(vec_56, vec_36, mem_vec_14965);
												mem_vec_14965 = vec_57;
												scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
												vec_59 = _mm512_set1_ps(scal_18);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_34, mem_vec_14966);
												mem_vec_14966 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_14967);
												mem_vec_14967 = vec_60;
												scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
												vec_62 = _mm512_set1_ps(scal_19);


												vec_61 = _mm512_fmadd_ps(vec_62, vec_34, mem_vec_14968);
												mem_vec_14968 = vec_61;



												vec_63 = _mm512_fmadd_ps(vec_62, vec_36, mem_vec_14969);
												mem_vec_14969 = vec_63;
												scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_65 = _mm512_set1_ps(scal_20);
												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_64 = _mm512_fmadd_ps(vec_65, vec_66, mem_vec_14950);
												mem_vec_14950 = vec_64;

												vec_68 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_67 = _mm512_fmadd_ps(vec_65, vec_68, mem_vec_14951);
												mem_vec_14951 = vec_67;
												scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_70 = _mm512_set1_ps(scal_21);


												vec_69 = _mm512_fmadd_ps(vec_70, vec_66, mem_vec_14952);
												mem_vec_14952 = vec_69;



												vec_71 = _mm512_fmadd_ps(vec_70, vec_68, mem_vec_14953);
												mem_vec_14953 = vec_71;
												scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_22);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_14954);
												mem_vec_14954 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_68, mem_vec_14955);
												mem_vec_14955 = vec_74;
												scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_76 = _mm512_set1_ps(scal_23);


												vec_75 = _mm512_fmadd_ps(vec_76, vec_66, mem_vec_14956);
												mem_vec_14956 = vec_75;



												vec_77 = _mm512_fmadd_ps(vec_76, vec_68, mem_vec_14957);
												mem_vec_14957 = vec_77;
												scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_79 = _mm512_set1_ps(scal_24);


												vec_78 = _mm512_fmadd_ps(vec_79, vec_66, mem_vec_14958);
												mem_vec_14958 = vec_78;



												vec_80 = _mm512_fmadd_ps(vec_79, vec_68, mem_vec_14959);
												mem_vec_14959 = vec_80;
												scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
												vec_82 = _mm512_set1_ps(scal_25);


												vec_81 = _mm512_fmadd_ps(vec_82, vec_66, mem_vec_14960);
												mem_vec_14960 = vec_81;



												vec_83 = _mm512_fmadd_ps(vec_82, vec_68, mem_vec_14961);
												mem_vec_14961 = vec_83;
												scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
												vec_85 = _mm512_set1_ps(scal_26);


												vec_84 = _mm512_fmadd_ps(vec_85, vec_66, mem_vec_14962);
												mem_vec_14962 = vec_84;



												vec_86 = _mm512_fmadd_ps(vec_85, vec_68, mem_vec_14963);
												mem_vec_14963 = vec_86;
												scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
												vec_88 = _mm512_set1_ps(scal_27);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_66, mem_vec_14964);
												mem_vec_14964 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_68, mem_vec_14965);
												mem_vec_14965 = vec_89;
												scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
												vec_91 = _mm512_set1_ps(scal_28);


												vec_90 = _mm512_fmadd_ps(vec_91, vec_66, mem_vec_14966);
												mem_vec_14966 = vec_90;



												vec_92 = _mm512_fmadd_ps(vec_91, vec_68, mem_vec_14967);
												mem_vec_14967 = vec_92;
												scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
												vec_94 = _mm512_set1_ps(scal_29);


												vec_93 = _mm512_fmadd_ps(vec_94, vec_66, mem_vec_14968);
												mem_vec_14968 = vec_93;



												vec_95 = _mm512_fmadd_ps(vec_94, vec_68, mem_vec_14969);
												mem_vec_14969 = vec_95;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14950);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14951);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14952);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14953);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14954);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14955);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14956);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14957);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14958);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14959);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14960);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14961);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_14962);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_14963);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_14964);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_14965);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_14966);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_14967);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_14968);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_14969);
								}
							}
						}
				}
			}
		}
	}
}


}