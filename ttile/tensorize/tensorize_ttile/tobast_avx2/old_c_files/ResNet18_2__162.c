#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (8, c); Hoist_vars [c]; T (8, x);
  T (3, w); Lambda_apply y [((Iter 7), (Arg 4)); ((Iter 4), (Arg 7))];
  T (2, f); T (1, c); T (1, f); T (8, c); T (7, x); T (1, f)]
*/
IND_TYPE c, cp_0, c844_p_0, c845_p_0, cp_1, c844_p_1, cp_2, c844, c845, f, fp_0, f748_p_0, f749_p_0, fp_1, f748_p_1, fp_2, f748, f749, w, wp_0, x, xp_0, x780_p_0, xp_1, x780, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 64));
IND_TYPE y464 = 0;
IND_TYPE x781 = 0;
IND_TYPE h = 0;
IND_TYPE w378 = 0;
IND_TYPE c846 = 0;
IND_TYPE f750 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_6424 ,mem_vec_6425 ,mem_vec_6426 ,mem_vec_6427 ,mem_vec_6428 ,mem_vec_6429 ,mem_vec_6430 ,mem_vec_6431 ,mem_vec_6432 ,mem_vec_6433 ,mem_vec_6434 ,mem_vec_6435 ,mem_vec_6436 ,mem_vec_6437 ,mem_vec_6438 ,mem_vec_6439 ,mem_vec_6440 ,mem_vec_6441 ,mem_vec_6442 ,mem_vec_6443 ,mem_vec_6444 ,mem_vec_6445 ,mem_vec_6446 ,mem_vec_6447 ,mem_vec_6448 ,mem_vec_6449 ,mem_vec_6450 ,mem_vec_6451 ,mem_vec_6452 ,mem_vec_6453 ,mem_vec_6454 ,mem_vec_6455 ,mem_vec_6456 ,mem_vec_6457 ,mem_vec_6458 ,mem_vec_6459 ,mem_vec_6460 ,mem_vec_6461 ,mem_vec_6462 ,mem_vec_6463 ,mem_vec_6464 ,mem_vec_6465 ,mem_vec_6466 ,mem_vec_6467 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_105 ,vec_106 ,vec_107 ,vec_108 ,vec_109 ,vec_11 ,vec_110 ,vec_111 ,vec_112 ,vec_113 ,vec_114 ,vec_115 ,vec_116 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
// T (f, 1) (64 / 64)
for (f749 = f750, f749_p_0 = 0;
	f749 < f750 + 64;
	f749 += 64, f749_p_0 += 64){
	// y = 56, x = 56, h = 3, w = 3, c = 64, f = 64
	// T (x, 7) (56 / 8)
	for (x780 = x781, x780_p_0 = 0;
		x780 < x781 + 56;
		x780 += 8, x780_p_0 += 8){
		// y = 56, x = 8, h = 3, w = 3, c = 64, f = 64
		// T (c, 8) (64 / 8)
		for (c845 = c846, c845_p_0 = 0;
			c845 < c846 + 64;
			c845 += 8, c845_p_0 += 8){
			// y = 56, x = 8, h = 3, w = 3, c = 8, f = 64
			// T (f, 1) (64 / 64)
			for (f748 = f749, f748_p_1 = f749_p_0, f748_p_0 = 0;
				f748 < f749 + 64;
				f748 += 64, f748_p_1 += 64, f748_p_0 += 64){
				// y = 56, x = 8, h = 3, w = 3, c = 8, f = 64
				// T (c, 1) (8 / 8)
				for (c844 = c845, c844_p_1 = c845_p_0, c844_p_0 = 0;
					c844 < c845 + 8;
					c844 += 8, c844_p_1 += 8, c844_p_0 += 8){
					// y = 56, x = 8, h = 3, w = 3, c = 8, f = 64
					// T (f, 2) (64 / 32)
					for (f = f748, fp_2 = f748_p_1, fp_1 = f748_p_0, fp_0 = 0;
						f < f748 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y464, yp_0 = 0;
								y < y464 + 28;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 8, h = 3, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w378, wp_0 = 0;
									w < w378 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 8, h = 3, w = 1, c = 8, f = 32
									// T (x, 8) (8 / 1)
									for (x = x780, xp_1 = x780_p_0, xp_0 = 0;
										x < x780 + 8;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6424 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6425 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_6426 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6427 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_6428 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6429 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6430 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6431 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_6432 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6433 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_6434 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6435 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_6436 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6437 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_6438 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6439 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c844, cp_2 = c844_p_1, cp_1 = c844_p_0, cp_0 = 0;
													c < c844 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6424);
													mem_vec_6424 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6425);
													mem_vec_6425 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6426);
													mem_vec_6426 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6427);
													mem_vec_6427 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6428);
													mem_vec_6428 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6429);
													mem_vec_6429 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6430);
													mem_vec_6430 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6431);
													mem_vec_6431 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6432);
													mem_vec_6432 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6433);
													mem_vec_6433 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6434);
													mem_vec_6434 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6435);
													mem_vec_6435 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6436);
													mem_vec_6436 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6437);
													mem_vec_6437 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6438);
													mem_vec_6438 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6439);
													mem_vec_6439 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_6424);
													mem_vec_6424 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_6425);
													mem_vec_6425 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_6426);
													mem_vec_6426 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_6427);
													mem_vec_6427 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_6428);
													mem_vec_6428 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_6429);
													mem_vec_6429 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_6430);
													mem_vec_6430 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_6431);
													mem_vec_6431 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_6432);
													mem_vec_6432 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_6433);
													mem_vec_6433 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_6434);
													mem_vec_6434 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_6435);
													mem_vec_6435 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_6436);
													mem_vec_6436 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_6437);
													mem_vec_6437 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_6438);
													mem_vec_6438 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_6439);
													mem_vec_6439 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_6424);
													mem_vec_6424 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_6425);
													mem_vec_6425 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_6426);
													mem_vec_6426 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_6427);
													mem_vec_6427 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_6428);
													mem_vec_6428 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_6429);
													mem_vec_6429 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_6430);
													mem_vec_6430 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_6431);
													mem_vec_6431 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_6432);
													mem_vec_6432 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_6433);
													mem_vec_6433 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_6434);
													mem_vec_6434 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_6435);
													mem_vec_6435 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_6436);
													mem_vec_6436 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_6437);
													mem_vec_6437 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_6438);
													mem_vec_6438 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_6439);
													mem_vec_6439 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6424);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6425);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6426);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6427);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6428);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6429);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6430);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6431);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6432);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6433);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6434);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6435);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6436);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6437);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6438);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6439);
									}
								}
							}
							for (y = y464 + 28, yp_0 = 0;
								y < y464 + 28 + 28;
								y += 7, yp_0 += 7){
								// y = ph_y, x = 8, h = 3, w = 3, c = 8, f = 32
								// T (w, 3) (3 / 1)
								for (w = w378, wp_0 = 0;
									w < w378 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 8, h = 3, w = 1, c = 8, f = 32
									// T (x, 8) (8 / 1)
									for (x = x780, xp_1 = x780_p_0, xp_0 = 0;
										x < x780 + 8;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6440 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6441 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_6442 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6443 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_6444 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6445 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_6446 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6447 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_6448 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6449 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_6450 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6451 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_6452 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6453 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_6454 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6455 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_6456 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6457 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_6458 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6459 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_6460 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6461 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_6462 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6463 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												mem_vec_6464 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6465 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_6466 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6467 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c844, cp_2 = c844_p_1, cp_1 = c844_p_0, cp_0 = 0;
													c < c844 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_6440);
													mem_vec_6440 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_6441);
													mem_vec_6441 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_6442);
													mem_vec_6442 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_6443);
													mem_vec_6443 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_6444);
													mem_vec_6444 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_6445);
													mem_vec_6445 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_6446);
													mem_vec_6446 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_6447);
													mem_vec_6447 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_6448);
													mem_vec_6448 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_6449);
													mem_vec_6449 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_6450);
													mem_vec_6450 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_6451);
													mem_vec_6451 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_6452);
													mem_vec_6452 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_6453);
													mem_vec_6453 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_6454);
													mem_vec_6454 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_6455);
													mem_vec_6455 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_6456);
													mem_vec_6456 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_6457);
													mem_vec_6457 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_6458);
													mem_vec_6458 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_6459);
													mem_vec_6459 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_6460);
													mem_vec_6460 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_6461);
													mem_vec_6461 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_6462);
													mem_vec_6462 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_6463);
													mem_vec_6463 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_2, mem_vec_6464);
													mem_vec_6464 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_4, mem_vec_6465);
													mem_vec_6465 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_35, vec_6, mem_vec_6466);
													mem_vec_6466 = vec_37;



													vec_38 = _mm256_fmadd_ps(vec_35, vec_8, mem_vec_6467);
													mem_vec_6467 = vec_38;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_40 = _mm256_set1_ps(scal_7);
													vec_41 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_39 = _mm256_fmadd_ps(vec_40, vec_41, mem_vec_6440);
													mem_vec_6440 = vec_39;

													vec_43 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_42 = _mm256_fmadd_ps(vec_40, vec_43, mem_vec_6441);
													mem_vec_6441 = vec_42;

													vec_45 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_44 = _mm256_fmadd_ps(vec_40, vec_45, mem_vec_6442);
													mem_vec_6442 = vec_44;

													vec_47 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_46 = _mm256_fmadd_ps(vec_40, vec_47, mem_vec_6443);
													mem_vec_6443 = vec_46;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_41, mem_vec_6444);
													mem_vec_6444 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_43, mem_vec_6445);
													mem_vec_6445 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_45, mem_vec_6446);
													mem_vec_6446 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_47, mem_vec_6447);
													mem_vec_6447 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_41, mem_vec_6448);
													mem_vec_6448 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_43, mem_vec_6449);
													mem_vec_6449 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_45, mem_vec_6450);
													mem_vec_6450 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_47, mem_vec_6451);
													mem_vec_6451 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_41, mem_vec_6452);
													mem_vec_6452 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_43, mem_vec_6453);
													mem_vec_6453 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_45, mem_vec_6454);
													mem_vec_6454 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_47, mem_vec_6455);
													mem_vec_6455 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_41, mem_vec_6456);
													mem_vec_6456 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_43, mem_vec_6457);
													mem_vec_6457 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_45, mem_vec_6458);
													mem_vec_6458 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_47, mem_vec_6459);
													mem_vec_6459 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_69 = _mm256_set1_ps(scal_12);


													vec_68 = _mm256_fmadd_ps(vec_69, vec_41, mem_vec_6460);
													mem_vec_6460 = vec_68;



													vec_70 = _mm256_fmadd_ps(vec_69, vec_43, mem_vec_6461);
													mem_vec_6461 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_69, vec_45, mem_vec_6462);
													mem_vec_6462 = vec_71;



													vec_72 = _mm256_fmadd_ps(vec_69, vec_47, mem_vec_6463);
													mem_vec_6463 = vec_72;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_74 = _mm256_set1_ps(scal_13);


													vec_73 = _mm256_fmadd_ps(vec_74, vec_41, mem_vec_6464);
													mem_vec_6464 = vec_73;



													vec_75 = _mm256_fmadd_ps(vec_74, vec_43, mem_vec_6465);
													mem_vec_6465 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_74, vec_45, mem_vec_6466);
													mem_vec_6466 = vec_76;



													vec_77 = _mm256_fmadd_ps(vec_74, vec_47, mem_vec_6467);
													mem_vec_6467 = vec_77;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_14);
													vec_80 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_78 = _mm256_fmadd_ps(vec_79, vec_80, mem_vec_6440);
													mem_vec_6440 = vec_78;

													vec_82 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_81 = _mm256_fmadd_ps(vec_79, vec_82, mem_vec_6441);
													mem_vec_6441 = vec_81;

													vec_84 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_83 = _mm256_fmadd_ps(vec_79, vec_84, mem_vec_6442);
													mem_vec_6442 = vec_83;

													vec_86 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_85 = _mm256_fmadd_ps(vec_79, vec_86, mem_vec_6443);
													mem_vec_6443 = vec_85;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_80, mem_vec_6444);
													mem_vec_6444 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_82, mem_vec_6445);
													mem_vec_6445 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_84, mem_vec_6446);
													mem_vec_6446 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_86, mem_vec_6447);
													mem_vec_6447 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_80, mem_vec_6448);
													mem_vec_6448 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_82, mem_vec_6449);
													mem_vec_6449 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_84, mem_vec_6450);
													mem_vec_6450 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_86, mem_vec_6451);
													mem_vec_6451 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_80, mem_vec_6452);
													mem_vec_6452 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_82, mem_vec_6453);
													mem_vec_6453 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_84, mem_vec_6454);
													mem_vec_6454 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_86, mem_vec_6455);
													mem_vec_6455 = vec_101;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_18);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_80, mem_vec_6456);
													mem_vec_6456 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_82, mem_vec_6457);
													mem_vec_6457 = vec_104;



													vec_105 = _mm256_fmadd_ps(vec_103, vec_84, mem_vec_6458);
													mem_vec_6458 = vec_105;



													vec_106 = _mm256_fmadd_ps(vec_103, vec_86, mem_vec_6459);
													mem_vec_6459 = vec_106;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_108 = _mm256_set1_ps(scal_19);


													vec_107 = _mm256_fmadd_ps(vec_108, vec_80, mem_vec_6460);
													mem_vec_6460 = vec_107;



													vec_109 = _mm256_fmadd_ps(vec_108, vec_82, mem_vec_6461);
													mem_vec_6461 = vec_109;



													vec_110 = _mm256_fmadd_ps(vec_108, vec_84, mem_vec_6462);
													mem_vec_6462 = vec_110;



													vec_111 = _mm256_fmadd_ps(vec_108, vec_86, mem_vec_6463);
													mem_vec_6463 = vec_111;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_113 = _mm256_set1_ps(scal_20);


													vec_112 = _mm256_fmadd_ps(vec_113, vec_80, mem_vec_6464);
													mem_vec_6464 = vec_112;



													vec_114 = _mm256_fmadd_ps(vec_113, vec_82, mem_vec_6465);
													mem_vec_6465 = vec_114;



													vec_115 = _mm256_fmadd_ps(vec_113, vec_84, mem_vec_6466);
													mem_vec_6466 = vec_115;



													vec_116 = _mm256_fmadd_ps(vec_113, vec_86, mem_vec_6467);
													mem_vec_6467 = vec_116;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6440);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_6441);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6442);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_6443);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6444);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_6445);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6446);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_6447);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6448);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_6449);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6450);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_6451);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6452);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_6453);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6454);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_6455);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6456);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_6457);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6458);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_6459);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6460);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_6461);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6462);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_6463);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6464);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_6465);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6466);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 24], mem_vec_6467);
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