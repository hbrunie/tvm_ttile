#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (14, x);
  T (3, h); T (1, c); T (2, f);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))]; T (2, x);
  T (2, f); T (1, f)]
*/
IND_TYPE c, cp_0, c363_p_0, cp_1, c363, f, fp_0, f436_p_0, f437_p_0, fp_1, f436_p_1, fp_2, f436, f437, h, hp_0, x, xp_0, x375_p_0, xp_1, x375, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y266 = 0;
IND_TYPE x376 = 0;
IND_TYPE h230 = 0;
IND_TYPE w = 0;
IND_TYPE c364 = 0;
IND_TYPE f438 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3072 ,mem_vec_3073 ,mem_vec_3074 ,mem_vec_3075 ,mem_vec_3076 ,mem_vec_3077 ,mem_vec_3078 ,mem_vec_3079 ,mem_vec_3080 ,mem_vec_3081 ,mem_vec_3082 ,mem_vec_3083 ,mem_vec_3084 ,mem_vec_3085 ,mem_vec_3086 ,mem_vec_3087 ,mem_vec_3088 ,mem_vec_3089 ,mem_vec_3090 ,mem_vec_3091 ,mem_vec_3092 ,mem_vec_3093 ,mem_vec_3094 ,mem_vec_3095 ,mem_vec_3096 ,mem_vec_3097 ,mem_vec_3098 ,mem_vec_3099 ,mem_vec_3100 ,mem_vec_3101 ,mem_vec_3102 ,mem_vec_3103 ,mem_vec_3104 ,mem_vec_3105 ,mem_vec_3106 ,mem_vec_3107 ,mem_vec_3108 ,mem_vec_3109 ,mem_vec_3110 ,mem_vec_3111 ,mem_vec_3112 ,mem_vec_3113 ,mem_vec_3114 ,mem_vec_3115 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f437 = f438, f437_p_0 = 0;
	f437 < f438 + 256;
	f437 += 256, f437_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (f, 2) (256 / 128)
	for (f436 = f437, f436_p_1 = f437_p_0, f436_p_0 = 0;
		f436 < f437 + 256;
		f436 += 128, f436_p_1 += 128, f436_p_0 += 128){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 128
		// T (x, 2) (28 / 14)
		for (x375 = x376, x375_p_0 = 0;
			x375 < x376 + 28;
			x375 += 14, x375_p_0 += 14){
				for (y = y266, yp_0 = 0;
					y < y266 + 10;
					y += 5, yp_0 += 5){
					// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f436, fp_2 = f436_p_1, fp_1 = f436_p_0, fp_0 = 0;
						f < f436 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c363 = c364, c363_p_0 = 0;
							c363 < c364 + 256;
							c363 += 256, c363_p_0 += 256){
							// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h230, hp_0 = 0;
								h < h230 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 256, f = 64
								// T (x, 14) (14 / 1)
								for (x = x375, xp_1 = x375_p_0, xp_0 = 0;
									x < x375 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3072 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3073 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3074 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_3075 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_3076 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3077 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3078 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_3079 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_3080 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3081 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3082 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_3083 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_3084 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3085 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3086 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_3087 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_3088 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3089 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3090 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_3091 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c363, cp_1 = c363_p_0, cp_0 = 0;
												c < c363 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3072);
												mem_vec_3072 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3073);
												mem_vec_3073 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3074);
												mem_vec_3074 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3075);
												mem_vec_3075 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3076);
												mem_vec_3076 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3077);
												mem_vec_3077 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3078);
												mem_vec_3078 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3079);
												mem_vec_3079 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3080);
												mem_vec_3080 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3081);
												mem_vec_3081 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3082);
												mem_vec_3082 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3083);
												mem_vec_3083 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3084);
												mem_vec_3084 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3085);
												mem_vec_3085 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3086);
												mem_vec_3086 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3087);
												mem_vec_3087 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3088);
												mem_vec_3088 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3089);
												mem_vec_3089 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3090);
												mem_vec_3090 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3091);
												mem_vec_3091 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_3072);
												mem_vec_3072 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_3073);
												mem_vec_3073 = vec_32;

												vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_3074);
												mem_vec_3074 = vec_34;

												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_3075);
												mem_vec_3075 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_3076);
												mem_vec_3076 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_3077);
												mem_vec_3077 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_3078);
												mem_vec_3078 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_3079);
												mem_vec_3079 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_3080);
												mem_vec_3080 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_3081);
												mem_vec_3081 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_3082);
												mem_vec_3082 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_3083);
												mem_vec_3083 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_3084);
												mem_vec_3084 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_3085);
												mem_vec_3085 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_3086);
												mem_vec_3086 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_3087);
												mem_vec_3087 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_3088);
												mem_vec_3088 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_3089);
												mem_vec_3089 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_3090);
												mem_vec_3090 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_3091);
												mem_vec_3091 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_3072);
												mem_vec_3072 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_3073);
												mem_vec_3073 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_3074);
												mem_vec_3074 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_3075);
												mem_vec_3075 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_3076);
												mem_vec_3076 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_3077);
												mem_vec_3077 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_3078);
												mem_vec_3078 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_3079);
												mem_vec_3079 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_73 = _mm512_set1_ps(scal_12);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_3080);
												mem_vec_3080 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_3081);
												mem_vec_3081 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_3082);
												mem_vec_3082 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_3083);
												mem_vec_3083 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_3084);
												mem_vec_3084 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_3085);
												mem_vec_3085 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_3086);
												mem_vec_3086 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_3087);
												mem_vec_3087 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_3088);
												mem_vec_3088 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_3089);
												mem_vec_3089 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_3090);
												mem_vec_3090 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_3091);
												mem_vec_3091 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3072);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3073);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3074);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3075);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3076);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3077);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3078);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3079);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3080);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3081);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3082);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3083);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3084);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3085);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3086);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3087);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3088);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3089);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3090);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3091);
								}
							}
						}
					}
				}
				for (y = y266 + 10, yp_0 = 0;
					y < y266 + 10 + 18;
					y += 6, yp_0 += 6){
					// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f436, fp_2 = f436_p_1, fp_1 = f436_p_0, fp_0 = 0;
						f < f436 + 128;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
						// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c363 = c364, c363_p_0 = 0;
							c363 < c364 + 256;
							c363 += 256, c363_p_0 += 256){
							// y = ph_y, x = 14, h = 3, w = 3, c = 256, f = 64
							// T (h, 3) (3 / 1)
							for (h = h230, hp_0 = 0;
								h < h230 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 14, h = 1, w = 3, c = 256, f = 64
								// T (x, 14) (14 / 1)
								for (x = x375, xp_1 = x375_p_0, xp_0 = 0;
									x < x375 + 14;
									x += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_3092 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3093 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3094 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_3095 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_3096 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3097 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3098 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_3099 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_3100 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3101 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3102 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_3103 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_3104 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3105 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3106 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_3107 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_3108 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3109 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3110 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_3111 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											mem_vec_3112 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3113 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3114 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
											mem_vec_3115 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
											// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 64
											// T (c, 256) (256 / 1)
											for (c = c363, cp_1 = c363_p_0, cp_0 = 0;
												c < c363 + 256;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3092);
												mem_vec_3092 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3093);
												mem_vec_3093 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3094);
												mem_vec_3094 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3095);
												mem_vec_3095 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3096);
												mem_vec_3096 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3097);
												mem_vec_3097 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3098);
												mem_vec_3098 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3099);
												mem_vec_3099 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3100);
												mem_vec_3100 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3101);
												mem_vec_3101 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3102);
												mem_vec_3102 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3103);
												mem_vec_3103 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3104);
												mem_vec_3104 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3105);
												mem_vec_3105 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3106);
												mem_vec_3106 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3107);
												mem_vec_3107 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3108);
												mem_vec_3108 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3109);
												mem_vec_3109 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3110);
												mem_vec_3110 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3111);
												mem_vec_3111 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_30 = _mm512_set1_ps(scal_5);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3112);
												mem_vec_3112 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3113);
												mem_vec_3113 = vec_31;



												vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3114);
												mem_vec_3114 = vec_32;



												vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3115);
												mem_vec_3115 = vec_33;
												scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
												vec_35 = _mm512_set1_ps(scal_6);
												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

												vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_3092);
												mem_vec_3092 = vec_34;

												vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

												vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_3093);
												mem_vec_3093 = vec_37;

												vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 32]);

												vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_3094);
												mem_vec_3094 = vec_39;

												vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 48]);

												vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_3095);
												mem_vec_3095 = vec_41;
												scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_3096);
												mem_vec_3096 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_3097);
												mem_vec_3097 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_3098);
												mem_vec_3098 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_3099);
												mem_vec_3099 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_3100);
												mem_vec_3100 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_3101);
												mem_vec_3101 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_3102);
												mem_vec_3102 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_3103);
												mem_vec_3103 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_3104);
												mem_vec_3104 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_3105);
												mem_vec_3105 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_3106);
												mem_vec_3106 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_3107);
												mem_vec_3107 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
												vec_59 = _mm512_set1_ps(scal_10);


												vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_3108);
												mem_vec_3108 = vec_58;



												vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_3109);
												mem_vec_3109 = vec_60;



												vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_3110);
												mem_vec_3110 = vec_61;



												vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_3111);
												mem_vec_3111 = vec_62;
												scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
												vec_64 = _mm512_set1_ps(scal_11);


												vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_3112);
												mem_vec_3112 = vec_63;



												vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_3113);
												mem_vec_3113 = vec_65;



												vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_3114);
												mem_vec_3114 = vec_66;



												vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_3115);
												mem_vec_3115 = vec_67;
												scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
												vec_69 = _mm512_set1_ps(scal_12);
												vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

												vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_3092);
												mem_vec_3092 = vec_68;

												vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

												vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_3093);
												mem_vec_3093 = vec_71;

												vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 32]);

												vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_3094);
												mem_vec_3094 = vec_73;

												vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 48]);

												vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_3095);
												mem_vec_3095 = vec_75;
												scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_3096);
												mem_vec_3096 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_3097);
												mem_vec_3097 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_3098);
												mem_vec_3098 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_3099);
												mem_vec_3099 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_3100);
												mem_vec_3100 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_3101);
												mem_vec_3101 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_3102);
												mem_vec_3102 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_3103);
												mem_vec_3103 = vec_86;
												scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
												vec_88 = _mm512_set1_ps(scal_15);


												vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_3104);
												mem_vec_3104 = vec_87;



												vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_3105);
												mem_vec_3105 = vec_89;



												vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_3106);
												mem_vec_3106 = vec_90;



												vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_3107);
												mem_vec_3107 = vec_91;
												scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
												vec_93 = _mm512_set1_ps(scal_16);


												vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_3108);
												mem_vec_3108 = vec_92;



												vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_3109);
												mem_vec_3109 = vec_94;



												vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_3110);
												mem_vec_3110 = vec_95;



												vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_3111);
												mem_vec_3111 = vec_96;
												scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
												vec_98 = _mm512_set1_ps(scal_17);


												vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_3112);
												mem_vec_3112 = vec_97;



												vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_3113);
												mem_vec_3113 = vec_99;



												vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_3114);
												mem_vec_3114 = vec_100;



												vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_3115);
												mem_vec_3115 = vec_101;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3092);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3093);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3094);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3095);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3096);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3097);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3098);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3099);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3100);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3101);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3102);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3103);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3104);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3105);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3106);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3107);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3108);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3109);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3110);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3111);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3112);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3113);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3114);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3115);
								}
							}
						}
					}
				}
		}
	}
}


}