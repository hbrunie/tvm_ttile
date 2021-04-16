#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (2, x);
  T (1, c); T (3, w); T (1, x); T (4, y); T (4, f); T (136, x); T (2, y);
  Lambda_apply y [((Iter 1), (Arg 10)); ((Iter 2), (Arg 12))]]
*/
IND_TYPE c, cp_0, c264_p_0, cp_1, c264, f, fp_0, w, wp_0, x, xp_0, x352_p_0, x353_p_0, xp_1, x352_p_1, xp_2, x352, x353, y, yp_0, y318_p_0, y319_p_0, yp_1, y318_p_1, yp_2, y318, y319;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y320 = 0;
IND_TYPE x354 = 0;
IND_TYPE h = 0;
IND_TYPE w161 = 0;
IND_TYPE c265 = 0;
IND_TYPE f171 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_33 ,scal_34 ,scal_35 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_3136 ,mem_vec_3137 ,mem_vec_3138 ,mem_vec_3139 ,mem_vec_3140 ,mem_vec_3141 ,mem_vec_3142 ,mem_vec_3143 ,mem_vec_3144 ,mem_vec_3145 ,mem_vec_3146 ,mem_vec_3147 ,mem_vec_3148 ,mem_vec_3149 ,mem_vec_3150 ,mem_vec_3151 ,mem_vec_3152 ,mem_vec_3153 ,mem_vec_3154 ,mem_vec_3155 ,mem_vec_3156 ,mem_vec_3157 ,mem_vec_3158 ,mem_vec_3159 ,mem_vec_3160 ,mem_vec_3161 ,mem_vec_3162 ,mem_vec_3163 ,mem_vec_3164 ,mem_vec_3165 ,mem_vec_3166 ,mem_vec_3167 ,mem_vec_3168 ,mem_vec_3169 ,mem_vec_3170 ,mem_vec_3171 ,mem_vec_3172 ,mem_vec_3173 ,mem_vec_3174 ,mem_vec_3175 ,mem_vec_3176 ,mem_vec_3177 ,mem_vec_3178 ,mem_vec_3179 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
	for (y319 = y320, y319_p_0 = 0;
		y319 < y320 + 80;
		y319 += 80, y319_p_0 += 80){
		// y = 2 * (4 * ph_y), x = 272, h = 3, w = 3, c = 32, f = 64
		// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
		for (y318 = y319, y318_p_1 = y319_p_0, y318_p_0 = 0;
			y318 < y319 + 80;
			y318 += 40, y318_p_1 += 40, y318_p_0 += 40){
			// y = 4 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (272 / 2)
			for (x353 = x354, x353_p_0 = 0;
				x353 < x354 + 272;
				x353 += 2, x353_p_0 += 2){
				// y = 4 * ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
				// T (f, 4) (64 / 16)
				for (f = f171, fp_0 = 0;
					f < f171 + 64;
					f += 16, fp_0 += 16){
					// y = 4 * ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
					// T (y, 4) (4 * ph_y / ph_y)
					for (y = y318, yp_2 = y318_p_1, yp_1 = y318_p_0, yp_0 = 0;
						y < y318 + 40;
						y += 10, yp_2 += 10, yp_1 += 10, yp_0 += 10){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
						// T (x, 1) (2 / 2)
						for (x352 = x353, x352_p_1 = x353_p_0, x352_p_0 = 0;
							x352 < x353 + 2;
							x352 += 2, x352_p_1 += 2, x352_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w161, wp_0 = 0;
								w < w161 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 32, f = 16
								// T (c, 1) (32 / 32)
								for (c264 = c265, c264_p_0 = 0;
									c264 < c265 + 32;
									c264 += 32, c264_p_0 += 32){
									// y = ph_y, x = 2, h = 3, w = 1, c = 32, f = 16
									// T (x, 2) (2 / 1)
									for (x = x352, xp_2 = x352_p_1, xp_1 = x352_p_0, xp_0 = 0;
										x < x352 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3136 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3137 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3138 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3139 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3144 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3145 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_3146 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3147 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_3148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_3150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_3152 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3153 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_3154 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3155 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
												// T (c, 32) (32 / 1)
												for (c = c264, cp_1 = c264_p_0, cp_0 = 0;
													c < c264 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3136);
													mem_vec_3136 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3137);
													mem_vec_3137 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3138);
													mem_vec_3138 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3139);
													mem_vec_3139 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3140);
													mem_vec_3140 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3141);
													mem_vec_3141 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3142);
													mem_vec_3142 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3143);
													mem_vec_3143 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3144);
													mem_vec_3144 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3145);
													mem_vec_3145 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3146);
													mem_vec_3146 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3147);
													mem_vec_3147 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3148);
													mem_vec_3148 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3149);
													mem_vec_3149 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3150);
													mem_vec_3150 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3151);
													mem_vec_3151 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3152);
													mem_vec_3152 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3153);
													mem_vec_3153 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3154);
													mem_vec_3154 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3155);
													mem_vec_3155 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_33 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_3136);
													mem_vec_3136 = vec_32;

													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_3137);
													mem_vec_3137 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_3138);
													mem_vec_3138 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_3139);
													mem_vec_3139 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_3140);
													mem_vec_3140 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_3141);
													mem_vec_3141 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_3142);
													mem_vec_3142 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_3143);
													mem_vec_3143 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_3144);
													mem_vec_3144 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_3145);
													mem_vec_3145 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_3146);
													mem_vec_3146 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_3147);
													mem_vec_3147 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_3148);
													mem_vec_3148 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_3149);
													mem_vec_3149 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_3150);
													mem_vec_3150 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_3151);
													mem_vec_3151 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_3152);
													mem_vec_3152 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_3153);
													mem_vec_3153 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_3154);
													mem_vec_3154 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_3155);
													mem_vec_3155 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_65 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_3136);
													mem_vec_3136 = vec_64;

													vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_3137);
													mem_vec_3137 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_3138);
													mem_vec_3138 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_3139);
													mem_vec_3139 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_3140);
													mem_vec_3140 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_3141);
													mem_vec_3141 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_3142);
													mem_vec_3142 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_3143);
													mem_vec_3143 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_3144);
													mem_vec_3144 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_3145);
													mem_vec_3145 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_3146);
													mem_vec_3146 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_3147);
													mem_vec_3147 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_3148);
													mem_vec_3148 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_3149);
													mem_vec_3149 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_3150);
													mem_vec_3150 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_3151);
													mem_vec_3151 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_3152);
													mem_vec_3152 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_3153);
													mem_vec_3153 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_3154);
													mem_vec_3154 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_3155);
													mem_vec_3155 = vec_95;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3136);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3137);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3138);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3139);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3140);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3141);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3142);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3143);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3144);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3145);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3146);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3147);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3148);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3149);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3150);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3151);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3152);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3153);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3154);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_3155);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	for (y319 = y320 + 80, y319_p_0 = 0;
		y319 < y320 + 80 + 192;
		y319 += 96, y319_p_0 += 96){
		// y = 2 * (4 * ph_y), x = 272, h = 3, w = 3, c = 32, f = 64
		// T (y, 2) (2 * (4 * ph_y) / 4 * ph_y)
		for (y318 = y319, y318_p_1 = y319_p_0, y318_p_0 = 0;
			y318 < y319 + 96;
			y318 += 48, y318_p_1 += 48, y318_p_0 += 48){
			// y = 4 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (272 / 2)
			for (x353 = x354, x353_p_0 = 0;
				x353 < x354 + 272;
				x353 += 2, x353_p_0 += 2){
				// y = 4 * ph_y, x = 2, h = 3, w = 3, c = 32, f = 64
				// T (f, 4) (64 / 16)
				for (f = f171, fp_0 = 0;
					f < f171 + 64;
					f += 16, fp_0 += 16){
					// y = 4 * ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
					// T (y, 4) (4 * ph_y / ph_y)
					for (y = y318, yp_2 = y318_p_1, yp_1 = y318_p_0, yp_0 = 0;
						y < y318 + 48;
						y += 12, yp_2 += 12, yp_1 += 12, yp_0 += 12){
						// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
						// T (x, 1) (2 / 2)
						for (x352 = x353, x352_p_1 = x353_p_0, x352_p_0 = 0;
							x352 < x353 + 2;
							x352 += 2, x352_p_1 += 2, x352_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 32, f = 16
							// T (w, 3) (3 / 1)
							for (w = w161, wp_0 = 0;
								w < w161 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 1, c = 32, f = 16
								// T (c, 1) (32 / 32)
								for (c264 = c265, c264_p_0 = 0;
									c264 < c265 + 32;
									c264 += 32, c264_p_0 += 32){
									// y = ph_y, x = 2, h = 3, w = 1, c = 32, f = 16
									// T (x, 2) (2 / 1)
									for (x = x352, xp_2 = x352_p_1, xp_1 = x352_p_0, xp_0 = 0;
										x < x352 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3156 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3157 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_3158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_3160 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3161 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_3162 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3163 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_3164 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3165 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_3166 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3167 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_3168 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_3169 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_3170 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_3171 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_3172 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_3173 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_3174 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_3175 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												mem_vec_3176 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_3177 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
												mem_vec_3178 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_3179 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
												// T (c, 32) (32 / 1)
												for (c = c264, cp_1 = c264_p_0, cp_0 = 0;
													c < c264 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_3156);
													mem_vec_3156 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_3157);
													mem_vec_3157 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_3158);
													mem_vec_3158 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_3159);
													mem_vec_3159 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_3160);
													mem_vec_3160 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_3161);
													mem_vec_3161 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_3162);
													mem_vec_3162 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_3163);
													mem_vec_3163 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_3164);
													mem_vec_3164 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_3165);
													mem_vec_3165 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_3166);
													mem_vec_3166 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_3167);
													mem_vec_3167 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_3168);
													mem_vec_3168 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_3169);
													mem_vec_3169 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_3170);
													mem_vec_3170 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_3171);
													mem_vec_3171 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_3172);
													mem_vec_3172 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_3173);
													mem_vec_3173 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_3174);
													mem_vec_3174 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_3175);
													mem_vec_3175 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm256_set1_ps(scal_10);


													vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_3176);
													mem_vec_3176 = vec_32;



													vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_3177);
													mem_vec_3177 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm256_set1_ps(scal_11);


													vec_35 = _mm256_fmadd_ps(vec_36, vec_2, mem_vec_3178);
													mem_vec_3178 = vec_35;



													vec_37 = _mm256_fmadd_ps(vec_36, vec_4, mem_vec_3179);
													mem_vec_3179 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_12);
													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_38 = _mm256_fmadd_ps(vec_39, vec_40, mem_vec_3156);
													mem_vec_3156 = vec_38;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_41 = _mm256_fmadd_ps(vec_39, vec_42, mem_vec_3157);
													mem_vec_3157 = vec_41;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_3158);
													mem_vec_3158 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_3159);
													mem_vec_3159 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_40, mem_vec_3160);
													mem_vec_3160 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_42, mem_vec_3161);
													mem_vec_3161 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_40, mem_vec_3162);
													mem_vec_3162 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_42, mem_vec_3163);
													mem_vec_3163 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_40, mem_vec_3164);
													mem_vec_3164 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_42, mem_vec_3165);
													mem_vec_3165 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_40, mem_vec_3166);
													mem_vec_3166 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_42, mem_vec_3167);
													mem_vec_3167 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_3168);
													mem_vec_3168 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_3169);
													mem_vec_3169 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_40, mem_vec_3170);
													mem_vec_3170 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_42, mem_vec_3171);
													mem_vec_3171 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_65 = _mm256_set1_ps(scal_20);


													vec_64 = _mm256_fmadd_ps(vec_65, vec_40, mem_vec_3172);
													mem_vec_3172 = vec_64;



													vec_66 = _mm256_fmadd_ps(vec_65, vec_42, mem_vec_3173);
													mem_vec_3173 = vec_66;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_68 = _mm256_set1_ps(scal_21);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_40, mem_vec_3174);
													mem_vec_3174 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_42, mem_vec_3175);
													mem_vec_3175 = vec_69;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
													vec_71 = _mm256_set1_ps(scal_22);


													vec_70 = _mm256_fmadd_ps(vec_71, vec_40, mem_vec_3176);
													mem_vec_3176 = vec_70;



													vec_72 = _mm256_fmadd_ps(vec_71, vec_42, mem_vec_3177);
													mem_vec_3177 = vec_72;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_23);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_40, mem_vec_3178);
													mem_vec_3178 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_42, mem_vec_3179);
													mem_vec_3179 = vec_75;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_77 = _mm256_set1_ps(scal_24);
													vec_78 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_76 = _mm256_fmadd_ps(vec_77, vec_78, mem_vec_3156);
													mem_vec_3156 = vec_76;

													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_79 = _mm256_fmadd_ps(vec_77, vec_80, mem_vec_3157);
													mem_vec_3157 = vec_79;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_78, mem_vec_3158);
													mem_vec_3158 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_80, mem_vec_3159);
													mem_vec_3159 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_78, mem_vec_3160);
													mem_vec_3160 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_80, mem_vec_3161);
													mem_vec_3161 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_78, mem_vec_3162);
													mem_vec_3162 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_3163);
													mem_vec_3163 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_78, mem_vec_3164);
													mem_vec_3164 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_80, mem_vec_3165);
													mem_vec_3165 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_78, mem_vec_3166);
													mem_vec_3166 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_80, mem_vec_3167);
													mem_vec_3167 = vec_95;
													scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_97 = _mm256_set1_ps(scal_30);


													vec_96 = _mm256_fmadd_ps(vec_97, vec_78, mem_vec_3168);
													mem_vec_3168 = vec_96;



													vec_98 = _mm256_fmadd_ps(vec_97, vec_80, mem_vec_3169);
													mem_vec_3169 = vec_98;
													scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_100 = _mm256_set1_ps(scal_31);


													vec_99 = _mm256_fmadd_ps(vec_100, vec_78, mem_vec_3170);
													mem_vec_3170 = vec_99;



													vec_101 = _mm256_fmadd_ps(vec_100, vec_80, mem_vec_3171);
													mem_vec_3171 = vec_101;
													scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_32);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_78, mem_vec_3172);
													mem_vec_3172 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_3173);
													mem_vec_3173 = vec_104;
													scal_33 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_106 = _mm256_set1_ps(scal_33);


													vec_105 = _mm256_fmadd_ps(vec_106, vec_78, mem_vec_3174);
													mem_vec_3174 = vec_105;



													vec_107 = _mm256_fmadd_ps(vec_106, vec_80, mem_vec_3175);
													mem_vec_3175 = vec_107;
													scal_34 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
													vec_109 = _mm256_set1_ps(scal_34);


													vec_108 = _mm256_fmadd_ps(vec_109, vec_78, mem_vec_3176);
													mem_vec_3176 = vec_108;



													vec_110 = _mm256_fmadd_ps(vec_109, vec_80, mem_vec_3177);
													mem_vec_3177 = vec_110;
													scal_35 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h + 2) + c];
													vec_112 = _mm256_set1_ps(scal_35);


													vec_111 = _mm256_fmadd_ps(vec_112, vec_78, mem_vec_3178);
													mem_vec_3178 = vec_111;



													vec_113 = _mm256_fmadd_ps(vec_112, vec_80, mem_vec_3179);
													mem_vec_3179 = vec_113;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3156);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_3157);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3158);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_3159);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3160);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_3161);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3162);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_3163);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3164);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_3165);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3166);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_3167);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3168);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_3169);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3170);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_3171);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3172);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_3173);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3174);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_3175);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3176);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_3177);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3178);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 8], mem_vec_3179);
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