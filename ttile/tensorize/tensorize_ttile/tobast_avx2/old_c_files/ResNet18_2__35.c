#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (2, x);
  T (3, h); Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))];
  T (2, f); T (8, c); T (1, f); T (1, c); T (28, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1276_p_0, c1277_p_0, cp_1, c1276_p_1, cp_2, c1276, c1277, f, fp_0, f1180_p_0, f1181_p_0, fp_1, f1180_p_1, fp_2, f1180, f1181, h, hp_0, x, xp_0, x1104_p_0, xp_1, x1104, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y680 = 0;
IND_TYPE x1105 = 0;
IND_TYPE h470 = 0;
IND_TYPE w = 0;
IND_TYPE c1278 = 0;
IND_TYPE f1182 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11536 ,mem_vec_11537 ,mem_vec_11538 ,mem_vec_11539 ,mem_vec_11540 ,mem_vec_11541 ,mem_vec_11542 ,mem_vec_11543 ,mem_vec_11544 ,mem_vec_11545 ,mem_vec_11546 ,mem_vec_11547 ,mem_vec_11548 ,mem_vec_11549 ,mem_vec_11550 ,mem_vec_11551 ,mem_vec_11552 ,mem_vec_11553 ,mem_vec_11554 ,mem_vec_11555 ,mem_vec_11556 ,mem_vec_11557 ,mem_vec_11558 ,mem_vec_11559 ,mem_vec_11560 ,mem_vec_11561 ,mem_vec_11562 ,mem_vec_11563 ,mem_vec_11564 ,mem_vec_11565 ,mem_vec_11566 ,mem_vec_11567 ,mem_vec_11568 ,mem_vec_11569 ,mem_vec_11570 ,mem_vec_11571 ,mem_vec_11572 ,mem_vec_11573 ,mem_vec_11574 ,mem_vec_11575 ,mem_vec_11576 ,mem_vec_11577 ,mem_vec_11578 ,mem_vec_11579 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f1181 = f1182, f1181_p_0 = 0;
	f1181 < f1182 + 64;
	f1181 += 64, f1181_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 28) (56 / 2)
	for (x1104 = x1105, x1104_p_0 = 0;
		x1104 < x1105 + 56;
		x1104 += 2, x1104_p_0 += 2){
		// y = 56, x = 2, h = 3, w = 3, c = 64, f = 64
		// T (c, 1) (64 / 64)
		for (c1277 = c1278, c1277_p_0 = 0;
			c1277 < c1278 + 64;
			c1277 += 64, c1277_p_0 += 64){
			// y = 56, x = 2, h = 3, w = 3, c = 64, f = 64
			// T (f, 1) (64 / 64)
			for (f1180 = f1181, f1180_p_1 = f1181_p_0, f1180_p_0 = 0;
				f1180 < f1181 + 64;
				f1180 += 64, f1180_p_1 += 64, f1180_p_0 += 64){
				// y = 56, x = 2, h = 3, w = 3, c = 64, f = 64
				// T (c, 8) (64 / 8)
				for (c1276 = c1277, c1276_p_1 = c1277_p_0, c1276_p_0 = 0;
					c1276 < c1277 + 64;
					c1276 += 8, c1276_p_1 += 8, c1276_p_0 += 8){
					// y = 56, x = 2, h = 3, w = 3, c = 8, f = 64
					// T (f, 2) (64 / 32)
					for (f = f1180, fp_2 = f1180_p_1, fp_1 = f1180_p_0, fp_0 = 0;
						f < f1180 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y680, yp_0 = 0;
								y < y680 + 28;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h470, hp_0 = 0;
									h < h470 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1104, xp_1 = x1104_p_0, xp_0 = 0;
										x < x1104 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11536 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11537 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11538 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11539 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11540 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11541 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11542 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11543 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11544 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11545 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11546 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11547 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11548 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11549 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11550 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11551 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1276, cp_2 = c1276_p_1, cp_1 = c1276_p_0, cp_0 = 0;
													c < c1276 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11536);
													mem_vec_11536 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11537);
													mem_vec_11537 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11538);
													mem_vec_11538 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11539);
													mem_vec_11539 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11540);
													mem_vec_11540 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11541);
													mem_vec_11541 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11542);
													mem_vec_11542 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11543);
													mem_vec_11543 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11544);
													mem_vec_11544 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11545);
													mem_vec_11545 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11546);
													mem_vec_11546 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11547);
													mem_vec_11547 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11548);
													mem_vec_11548 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11549);
													mem_vec_11549 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11550);
													mem_vec_11550 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11551);
													mem_vec_11551 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_11536);
													mem_vec_11536 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_11537);
													mem_vec_11537 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_11538);
													mem_vec_11538 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_11539);
													mem_vec_11539 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_11540);
													mem_vec_11540 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_11541);
													mem_vec_11541 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_11542);
													mem_vec_11542 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_11543);
													mem_vec_11543 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_11544);
													mem_vec_11544 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_11545);
													mem_vec_11545 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_11546);
													mem_vec_11546 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_11547);
													mem_vec_11547 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_11548);
													mem_vec_11548 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_11549);
													mem_vec_11549 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_11550);
													mem_vec_11550 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_11551);
													mem_vec_11551 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_11536);
													mem_vec_11536 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_11537);
													mem_vec_11537 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_11538);
													mem_vec_11538 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_11539);
													mem_vec_11539 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_11540);
													mem_vec_11540 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_11541);
													mem_vec_11541 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_11542);
													mem_vec_11542 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_11543);
													mem_vec_11543 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_11544);
													mem_vec_11544 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_11545);
													mem_vec_11545 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_11546);
													mem_vec_11546 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_11547);
													mem_vec_11547 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_11548);
													mem_vec_11548 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_11549);
													mem_vec_11549 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_11550);
													mem_vec_11550 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_11551);
													mem_vec_11551 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11536);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11537);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11538);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11539);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11540);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11541);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11542);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11543);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11544);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11545);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11546);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11547);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11548);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11549);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11550);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11551);
									}
								}
							}
							for (y = y680 + 28, yp_0 = 0;
								y < y680 + 28 + 28;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 2, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h470, hp_0 = 0;
									h < h470 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 2, h = 1, w = 3, c = 8, f = 32
									// T (x, 2) (2 / 1)
									for (x = x1104, xp_1 = x1104_p_0, xp_0 = 0;
										x < x1104 + 2;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11552 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11553 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11554 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11555 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11556 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11557 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11558 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11559 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11560 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11561 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11562 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11563 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11564 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11565 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11566 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11567 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11568 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11569 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11570 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11571 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_11572 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11573 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11574 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11575 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_11576 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_11577 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_11578 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_11579 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1276, cp_2 = c1276_p_1, cp_1 = c1276_p_0, cp_0 = 0;
													c < c1276 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11552);
													mem_vec_11552 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11553);
													mem_vec_11553 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11554);
													mem_vec_11554 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11555);
													mem_vec_11555 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11556);
													mem_vec_11556 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11557);
													mem_vec_11557 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11558);
													mem_vec_11558 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11559);
													mem_vec_11559 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11560);
													mem_vec_11560 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11561);
													mem_vec_11561 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11562);
													mem_vec_11562 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11563);
													mem_vec_11563 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11564);
													mem_vec_11564 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11565);
													mem_vec_11565 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11566);
													mem_vec_11566 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11567);
													mem_vec_11567 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11568);
													mem_vec_11568 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11569);
													mem_vec_11569 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11570);
													mem_vec_11570 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11571);
													mem_vec_11571 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11572);
													mem_vec_11572 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11573);
													mem_vec_11573 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11574);
													mem_vec_11574 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11575);
													mem_vec_11575 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_11576);
													mem_vec_11576 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_11577);
													mem_vec_11577 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_11578);
													mem_vec_11578 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_11579);
													mem_vec_11579 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_11552);
													mem_vec_11552 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_11553);
													mem_vec_11553 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_11554);
													mem_vec_11554 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_11555);
													mem_vec_11555 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_11556);
													mem_vec_11556 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_11557);
													mem_vec_11557 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_11558);
													mem_vec_11558 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_11559);
													mem_vec_11559 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_11560);
													mem_vec_11560 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_11561);
													mem_vec_11561 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_11562);
													mem_vec_11562 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_11563);
													mem_vec_11563 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_11564);
													mem_vec_11564 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_11565);
													mem_vec_11565 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_11566);
													mem_vec_11566 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_11567);
													mem_vec_11567 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_11568);
													mem_vec_11568 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_11569);
													mem_vec_11569 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_11570);
													mem_vec_11570 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_11571);
													mem_vec_11571 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_11572);
													mem_vec_11572 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_11573);
													mem_vec_11573 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_11574);
													mem_vec_11574 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_11575);
													mem_vec_11575 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_11576);
													mem_vec_11576 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_11577);
													mem_vec_11577 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_11578);
													mem_vec_11578 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_11579);
													mem_vec_11579 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_11552);
													mem_vec_11552 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_11553);
													mem_vec_11553 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_11554);
													mem_vec_11554 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_11555);
													mem_vec_11555 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_11556);
													mem_vec_11556 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_11557);
													mem_vec_11557 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_11558);
													mem_vec_11558 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_11559);
													mem_vec_11559 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_11560);
													mem_vec_11560 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_11561);
													mem_vec_11561 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_11562);
													mem_vec_11562 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_11563);
													mem_vec_11563 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_11564);
													mem_vec_11564 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_11565);
													mem_vec_11565 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_11566);
													mem_vec_11566 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_11567);
													mem_vec_11567 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_11568);
													mem_vec_11568 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_11569);
													mem_vec_11569 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_11570);
													mem_vec_11570 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_11571);
													mem_vec_11571 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_11572);
													mem_vec_11572 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_11573);
													mem_vec_11573 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_11574);
													mem_vec_11574 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_11575);
													mem_vec_11575 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_11576);
													mem_vec_11576 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_11577);
													mem_vec_11577 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_11578);
													mem_vec_11578 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_11579);
													mem_vec_11579 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11552);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11553);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11554);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11555);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11556);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11557);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11558);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11559);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11560);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11561);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11562);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11563);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11564);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11565);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11566);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11567);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11568);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11569);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11570);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11571);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11572);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11573);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11574);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11575);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_11576);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_11577);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_11578);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_11579);
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