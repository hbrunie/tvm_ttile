#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (17, x);
  T (3, w); T (17, y); T (2, f); T (1, c); T (4, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 6))]; T (1, f);
  T (4, x)]
*/
IND_TYPE c, cp_0, c792_p_0, cp_1, c792, f, fp_0, f664_p_0, fp_1, f664, w, wp_0, x, xp_0, x1056_p_0, x1057_p_0, xp_1, x1056_p_1, xp_2, x1056, x1057, y, yp_0, y792_p_0, yp_1, y792;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y793 = 0;
IND_TYPE x1058 = 0;
IND_TYPE h = 0;
IND_TYPE w478 = 0;
IND_TYPE c793 = 0;
IND_TYPE f665 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_7472 ,mem_vec_7473 ,mem_vec_7474 ,mem_vec_7475 ,mem_vec_7476 ,mem_vec_7477 ,mem_vec_7478 ,mem_vec_7479 ,mem_vec_7480 ,mem_vec_7481 ,mem_vec_7482 ,mem_vec_7483 ,mem_vec_7484 ,mem_vec_7485 ,mem_vec_7486 ,mem_vec_7487 ,mem_vec_7488 ,mem_vec_7489 ,mem_vec_7490 ,mem_vec_7491 ,mem_vec_7492 ,mem_vec_7493 ,mem_vec_7494 ,mem_vec_7495 ,mem_vec_7496 ,mem_vec_7497 ,mem_vec_7498 ,mem_vec_7499 ,mem_vec_7500 ,mem_vec_7501 ,mem_vec_7502 ,mem_vec_7503 ,mem_vec_7504 ,mem_vec_7505 ,mem_vec_7506 ,mem_vec_7507 ,mem_vec_7508 ,mem_vec_7509 ,mem_vec_7510 ,mem_vec_7511 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 4) (272 / 68)
for (x1057 = x1058, x1057_p_0 = 0;
	x1057 < x1058 + 272;
	x1057 += 68, x1057_p_0 += 68){
	// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
	// T (f, 1) (64 / 64)
	for (f664 = f665, f664_p_0 = 0;
		f664 < f665 + 64;
		f664 += 64, f664_p_0 += 64){
			for (y792 = y793, y792_p_0 = 0;
				y792 < y793 + 68;
				y792 += 68, y792_p_0 += 68){
				// y = 17 * ph_y, x = 68, h = 3, w = 3, c = 32, f = 64
				// T (x, 4) (68 / 17)
				for (x1056 = x1057, x1056_p_1 = x1057_p_0, x1056_p_0 = 0;
					x1056 < x1057 + 68;
					x1056 += 17, x1056_p_1 += 17, x1056_p_0 += 17){
					// y = 17 * ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c792 = c793, c792_p_0 = 0;
						c792 < c793 + 32;
						c792 += 32, c792_p_0 += 32){
						// y = 17 * ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
						// T (f, 2) (64 / 32)
						for (f = f664, fp_1 = f664_p_0, fp_0 = 0;
							f < f664 + 64;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 17 * ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (y, 17) (17 * ph_y / ph_y)
							for (y = y792, yp_1 = y792_p_0, yp_0 = 0;
								y < y792 + 68;
								y += 4, yp_1 += 4, yp_0 += 4){
								// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w478, wp_0 = 0;
									w < w478 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
									// T (x, 17) (17 / 1)
									for (x = x1056, xp_2 = x1056_p_1, xp_1 = x1056_p_0, xp_0 = 0;
										x < x1056 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7472 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7473 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_7474 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7475 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_7476 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7477 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_7478 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7479 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_7480 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7481 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_7482 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7483 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_7484 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7485 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_7486 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7487 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c792, cp_1 = c792_p_0, cp_0 = 0;
													c < c792 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7472);
													mem_vec_7472 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7473);
													mem_vec_7473 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7474);
													mem_vec_7474 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7475);
													mem_vec_7475 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7476);
													mem_vec_7476 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7477);
													mem_vec_7477 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7478);
													mem_vec_7478 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7479);
													mem_vec_7479 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7480);
													mem_vec_7480 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7481);
													mem_vec_7481 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7482);
													mem_vec_7482 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7483);
													mem_vec_7483 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7484);
													mem_vec_7484 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7485);
													mem_vec_7485 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7486);
													mem_vec_7486 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7487);
													mem_vec_7487 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_7472);
													mem_vec_7472 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_7473);
													mem_vec_7473 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_7474);
													mem_vec_7474 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_7475);
													mem_vec_7475 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_7476);
													mem_vec_7476 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_7477);
													mem_vec_7477 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_7478);
													mem_vec_7478 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_7479);
													mem_vec_7479 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_7480);
													mem_vec_7480 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_7481);
													mem_vec_7481 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_7482);
													mem_vec_7482 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_7483);
													mem_vec_7483 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_7484);
													mem_vec_7484 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_7485);
													mem_vec_7485 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_7486);
													mem_vec_7486 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_7487);
													mem_vec_7487 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_7472);
													mem_vec_7472 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_7473);
													mem_vec_7473 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_7474);
													mem_vec_7474 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_7475);
													mem_vec_7475 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_7476);
													mem_vec_7476 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_7477);
													mem_vec_7477 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_7478);
													mem_vec_7478 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_7479);
													mem_vec_7479 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_7480);
													mem_vec_7480 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_7481);
													mem_vec_7481 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_7482);
													mem_vec_7482 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_7483);
													mem_vec_7483 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_7484);
													mem_vec_7484 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_7485);
													mem_vec_7485 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_7486);
													mem_vec_7486 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_7487);
													mem_vec_7487 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7472);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7473);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7474);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7475);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7476);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7477);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7478);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7479);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7480);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7481);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7482);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7483);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7484);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7485);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7486);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7487);
									}
								}
							}
						}
					}
				}
			}
			for (y792 = y793 + 68, y792_p_0 = 0;
				y792 < y793 + 68 + 204;
				y792 += 102, y792_p_0 += 102){
				// y = 17 * ph_y, x = 68, h = 3, w = 3, c = 32, f = 64
				// T (x, 4) (68 / 17)
				for (x1056 = x1057, x1056_p_1 = x1057_p_0, x1056_p_0 = 0;
					x1056 < x1057 + 68;
					x1056 += 17, x1056_p_1 += 17, x1056_p_0 += 17){
					// y = 17 * ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
					// T (c, 1) (32 / 32)
					for (c792 = c793, c792_p_0 = 0;
						c792 < c793 + 32;
						c792 += 32, c792_p_0 += 32){
						// y = 17 * ph_y, x = 17, h = 3, w = 3, c = 32, f = 64
						// T (f, 2) (64 / 32)
						for (f = f664, fp_1 = f664_p_0, fp_0 = 0;
							f < f664 + 64;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 17 * ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
							// T (y, 17) (17 * ph_y / ph_y)
							for (y = y792, yp_1 = y792_p_0, yp_0 = 0;
								y < y792 + 102;
								y += 6, yp_1 += 6, yp_0 += 6){
								// y = ph_y, x = 17, h = 3, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w478, wp_0 = 0;
									w < w478 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 17, h = 3, w = 1, c = 32, f = 32
									// T (x, 17) (17 / 1)
									for (x = x1056, xp_2 = x1056_p_1, xp_1 = x1056_p_0, xp_0 = 0;
										x < x1056 + 17;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_7488 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_7489 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_7490 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_7491 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_7492 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_7493 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_7494 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_7495 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_7496 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_7497 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_7498 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_7499 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_7500 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_7501 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_7502 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_7503 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_7504 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_7505 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_7506 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_7507 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_7508 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_7509 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_7510 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_7511 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 32
												// T (c, 32) (32 / 1)
												for (c = c792, cp_1 = c792_p_0, cp_0 = 0;
													c < c792 + 32;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_7488);
													mem_vec_7488 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_7489);
													mem_vec_7489 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_7490);
													mem_vec_7490 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_7491);
													mem_vec_7491 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_7492);
													mem_vec_7492 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_7493);
													mem_vec_7493 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_7494);
													mem_vec_7494 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_7495);
													mem_vec_7495 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_7496);
													mem_vec_7496 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_7497);
													mem_vec_7497 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_7498);
													mem_vec_7498 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_7499);
													mem_vec_7499 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_7500);
													mem_vec_7500 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_7501);
													mem_vec_7501 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_7502);
													mem_vec_7502 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_7503);
													mem_vec_7503 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_7504);
													mem_vec_7504 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_7505);
													mem_vec_7505 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_7506);
													mem_vec_7506 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_7507);
													mem_vec_7507 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_7508);
													mem_vec_7508 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_7509);
													mem_vec_7509 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_7510);
													mem_vec_7510 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_7511);
													mem_vec_7511 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_7488);
													mem_vec_7488 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_7489);
													mem_vec_7489 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_7490);
													mem_vec_7490 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_7491);
													mem_vec_7491 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_7492);
													mem_vec_7492 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_7493);
													mem_vec_7493 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_7494);
													mem_vec_7494 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_7495);
													mem_vec_7495 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_7496);
													mem_vec_7496 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_7497);
													mem_vec_7497 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_7498);
													mem_vec_7498 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_7499);
													mem_vec_7499 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_7500);
													mem_vec_7500 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_7501);
													mem_vec_7501 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_7502);
													mem_vec_7502 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_7503);
													mem_vec_7503 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_7504);
													mem_vec_7504 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_7505);
													mem_vec_7505 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_7506);
													mem_vec_7506 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_7507);
													mem_vec_7507 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_7508);
													mem_vec_7508 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_7509);
													mem_vec_7509 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_7510);
													mem_vec_7510 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_7511);
													mem_vec_7511 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_7488);
													mem_vec_7488 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_7489);
													mem_vec_7489 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_7490);
													mem_vec_7490 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_7491);
													mem_vec_7491 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_7492);
													mem_vec_7492 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_7493);
													mem_vec_7493 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_7494);
													mem_vec_7494 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_7495);
													mem_vec_7495 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_7496);
													mem_vec_7496 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_7497);
													mem_vec_7497 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_7498);
													mem_vec_7498 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_7499);
													mem_vec_7499 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_7500);
													mem_vec_7500 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_7501);
													mem_vec_7501 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_7502);
													mem_vec_7502 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_7503);
													mem_vec_7503 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_7504);
													mem_vec_7504 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_7505);
													mem_vec_7505 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_7506);
													mem_vec_7506 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_7507);
													mem_vec_7507 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_7508);
													mem_vec_7508 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_7509);
													mem_vec_7509 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_7510);
													mem_vec_7510 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_7511);
													mem_vec_7511 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7488);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_7489);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7490);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_7491);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7492);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_7493);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7494);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_7495);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7496);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_7497);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7498);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_7499);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7500);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_7501);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7502);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_7503);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7504);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_7505);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7506);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_7507);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7508);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_7509);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7510);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_7511);
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