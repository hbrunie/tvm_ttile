#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (256, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (1, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (4, f);
  T (1, c); T (17, x); T (4, f)]
*/
IND_TYPE c, cp_0, c1412_p_0, cp_1, c1412, f, fp_0, f912_p_0, f913_p_0, fp_1, f912_p_1, fp_2, f912, f913, h, hp_0, x, xp_0, x1328_p_0, x1329_p_0, xp_1, x1328_p_1, xp_2, x1328, x1329, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y664 = 0;
IND_TYPE x1330 = 0;
IND_TYPE h354 = 0;
IND_TYPE w = 0;
IND_TYPE c1413 = 0;
IND_TYPE f914 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_14120 ,mem_vec_14121 ,mem_vec_14122 ,mem_vec_14123 ,mem_vec_14124 ,mem_vec_14125 ,mem_vec_14126 ,mem_vec_14127 ,mem_vec_14128 ,mem_vec_14129 ,mem_vec_14130 ,mem_vec_14131 ,mem_vec_14132 ,mem_vec_14133 ,mem_vec_14134 ,mem_vec_14135 ,mem_vec_14136 ,mem_vec_14137 ,mem_vec_14138 ,mem_vec_14139 ,mem_vec_14140 ,mem_vec_14141 ,mem_vec_14142 ,mem_vec_14143 ,mem_vec_14144 ,mem_vec_14145 ,mem_vec_14146 ,mem_vec_14147 ,mem_vec_14148 ,mem_vec_14149 ,mem_vec_14150 ,mem_vec_14151 ,mem_vec_14152 ,mem_vec_14153 ,mem_vec_14154 ,mem_vec_14155 ,mem_vec_14156 ,mem_vec_14157 ,mem_vec_14158 ,mem_vec_14159 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 4) (512 / 128)
for (f913 = f914, f913_p_0 = 0;
	f913 < f914 + 512;
	f913 += 128, f913_p_0 += 128){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 128
	// T (x, 17) (34 / 2)
	for (x1329 = x1330, x1329_p_0 = 0;
		x1329 < x1330 + 34;
		x1329 += 2, x1329_p_0 += 2){
		// y = 34, x = 2, h = 3, w = 3, c = 256, f = 128
		// T (c, 1) (256 / 256)
		for (c1412 = c1413, c1412_p_0 = 0;
			c1412 < c1413 + 256;
			c1412 += 256, c1412_p_0 += 256){
			// y = 34, x = 2, h = 3, w = 3, c = 256, f = 128
			// T (f, 4) (128 / 32)
			for (f912 = f913, f912_p_1 = f913_p_0, f912_p_0 = 0;
				f912 < f913 + 128;
				f912 += 32, f912_p_1 += 32, f912_p_0 += 32){
					for (y = y664, yp_0 = 0;
						y < y664 + 4;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 32
						// T (x, 2) (2 / 1)
						for (x1328 = x1329, x1328_p_1 = x1329_p_0, x1328_p_0 = 0;
							x1328 < x1329 + 2;
							x1328 += 1, x1328_p_1 += 1, x1328_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
							// T (f, 1) (32 / 32)
							for (f = f912, fp_2 = f912_p_1, fp_1 = f912_p_0, fp_0 = 0;
								f < f912 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
								// T (h, 3) (3 / 1)
								for (h = h354, hp_0 = 0;
									h < h354 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1328, xp_2 = x1328_p_1, xp_1 = x1328_p_0, xp_0 = 0;
										x < x1328 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_14120 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_14121 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_14122 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_14123 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_14124 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_14125 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_14126 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_14127 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_14128 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_14129 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_14130 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_14131 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_14132 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_14133 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_14134 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_14135 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c1412, cp_1 = c1412_p_0, cp_0 = 0;
													c < c1412 + 256;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14120);
													mem_vec_14120 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14121);
													mem_vec_14121 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14122);
													mem_vec_14122 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14123);
													mem_vec_14123 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14124);
													mem_vec_14124 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14125);
													mem_vec_14125 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14126);
													mem_vec_14126 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14127);
													mem_vec_14127 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14128);
													mem_vec_14128 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14129);
													mem_vec_14129 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14130);
													mem_vec_14130 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14131);
													mem_vec_14131 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14132);
													mem_vec_14132 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14133);
													mem_vec_14133 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14134);
													mem_vec_14134 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14135);
													mem_vec_14135 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_14120);
													mem_vec_14120 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_14121);
													mem_vec_14121 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_14122);
													mem_vec_14122 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_14123);
													mem_vec_14123 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_14124);
													mem_vec_14124 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_14125);
													mem_vec_14125 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_14126);
													mem_vec_14126 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_14127);
													mem_vec_14127 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_14128);
													mem_vec_14128 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_14129);
													mem_vec_14129 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_14130);
													mem_vec_14130 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_14131);
													mem_vec_14131 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_14132);
													mem_vec_14132 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_14133);
													mem_vec_14133 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_14134);
													mem_vec_14134 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_14135);
													mem_vec_14135 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_14120);
													mem_vec_14120 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_14121);
													mem_vec_14121 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_14122);
													mem_vec_14122 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_14123);
													mem_vec_14123 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_14124);
													mem_vec_14124 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_14125);
													mem_vec_14125 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_14126);
													mem_vec_14126 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_14127);
													mem_vec_14127 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_14128);
													mem_vec_14128 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_14129);
													mem_vec_14129 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_14130);
													mem_vec_14130 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_14131);
													mem_vec_14131 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_14132);
													mem_vec_14132 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_14133);
													mem_vec_14133 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_14134);
													mem_vec_14134 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_14135);
													mem_vec_14135 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14120);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14121);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14122);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14123);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14124);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14125);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14126);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14127);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14128);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14129);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14130);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14131);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14132);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14133);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14134);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14135);
									}
								}
							}
						}
					}
					for (y = y664 + 4, yp_0 = 0;
						y < y664 + 4 + 30;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 2, h = 3, w = 3, c = 256, f = 32
						// T (x, 2) (2 / 1)
						for (x1328 = x1329, x1328_p_1 = x1329_p_0, x1328_p_0 = 0;
							x1328 < x1329 + 2;
							x1328 += 1, x1328_p_1 += 1, x1328_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
							// T (f, 1) (32 / 32)
							for (f = f912, fp_2 = f912_p_1, fp_1 = f912_p_0, fp_0 = 0;
								f < f912 + 32;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 1, h = 3, w = 3, c = 256, f = 32
								// T (h, 3) (3 / 1)
								for (h = h354, hp_0 = 0;
									h < h354 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1328, xp_2 = x1328_p_1, xp_1 = x1328_p_0, xp_0 = 0;
										x < x1328 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_14136 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_14137 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_14138 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_14139 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_14140 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_14141 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_14142 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_14143 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_14144 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_14145 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_14146 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_14147 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_14148 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_14149 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_14150 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_14151 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_14152 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_14153 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_14154 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_14155 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_14156 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_14157 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_14158 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_14159 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 256, f = 32
												// T (c, 256) (256 / 1)
												for (c = c1412, cp_1 = c1412_p_0, cp_0 = 0;
													c < c1412 + 256;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_14136);
													mem_vec_14136 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_14137);
													mem_vec_14137 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_14138);
													mem_vec_14138 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_14139);
													mem_vec_14139 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_14140);
													mem_vec_14140 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_14141);
													mem_vec_14141 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_14142);
													mem_vec_14142 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_14143);
													mem_vec_14143 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_14144);
													mem_vec_14144 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_14145);
													mem_vec_14145 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_14146);
													mem_vec_14146 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_14147);
													mem_vec_14147 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_14148);
													mem_vec_14148 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_14149);
													mem_vec_14149 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_14150);
													mem_vec_14150 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_14151);
													mem_vec_14151 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_14152);
													mem_vec_14152 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_14153);
													mem_vec_14153 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_14154);
													mem_vec_14154 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_14155);
													mem_vec_14155 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_14156);
													mem_vec_14156 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_14157);
													mem_vec_14157 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_14158);
													mem_vec_14158 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_14159);
													mem_vec_14159 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_14136);
													mem_vec_14136 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_14137);
													mem_vec_14137 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_14138);
													mem_vec_14138 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_14139);
													mem_vec_14139 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_14140);
													mem_vec_14140 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_14141);
													mem_vec_14141 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_14142);
													mem_vec_14142 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_14143);
													mem_vec_14143 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_14144);
													mem_vec_14144 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_14145);
													mem_vec_14145 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_14146);
													mem_vec_14146 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_14147);
													mem_vec_14147 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_14148);
													mem_vec_14148 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_14149);
													mem_vec_14149 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_14150);
													mem_vec_14150 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_14151);
													mem_vec_14151 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_14152);
													mem_vec_14152 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_14153);
													mem_vec_14153 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_14154);
													mem_vec_14154 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_14155);
													mem_vec_14155 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_14156);
													mem_vec_14156 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_14157);
													mem_vec_14157 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_14158);
													mem_vec_14158 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_14159);
													mem_vec_14159 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_14136);
													mem_vec_14136 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_14137);
													mem_vec_14137 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_14138);
													mem_vec_14138 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_14139);
													mem_vec_14139 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_14140);
													mem_vec_14140 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_14141);
													mem_vec_14141 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_14142);
													mem_vec_14142 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_14143);
													mem_vec_14143 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_14144);
													mem_vec_14144 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_14145);
													mem_vec_14145 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_14146);
													mem_vec_14146 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_14147);
													mem_vec_14147 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_14148);
													mem_vec_14148 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_14149);
													mem_vec_14149 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_14150);
													mem_vec_14150 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_14151);
													mem_vec_14151 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_14152);
													mem_vec_14152 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_14153);
													mem_vec_14153 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_14154);
													mem_vec_14154 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_14155);
													mem_vec_14155 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_14156);
													mem_vec_14156 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_14157);
													mem_vec_14157 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_14158);
													mem_vec_14158 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_14159);
													mem_vec_14159 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_14136);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_14137);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_14138);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_14139);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_14140);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_14141);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_14142);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_14143);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_14144);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_14145);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_14146);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_14147);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_14148);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_14149);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_14150);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_14151);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_14152);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_14153);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_14154);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_14155);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_14156);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_14157);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_14158);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_14159);
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