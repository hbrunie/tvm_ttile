#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (2, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]; T (8, f);
  T (16, c); T (17, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1112_p_0, cp_1, c1112, f, fp_0, f512_p_0, f513_p_0, fp_1, f512_p_1, fp_2, f512, f513, w, wp_0, x, xp_0, x928_p_0, x929_p_0, xp_1, x928_p_1, xp_2, x928, x929, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y464 = 0;
IND_TYPE x930 = 0;
IND_TYPE h = 0;
IND_TYPE w464 = 0;
IND_TYPE c1113 = 0;
IND_TYPE f514 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9608 ,mem_vec_9609 ,mem_vec_9610 ,mem_vec_9611 ,mem_vec_9612 ,mem_vec_9613 ,mem_vec_9614 ,mem_vec_9615 ,mem_vec_9616 ,mem_vec_9617 ,mem_vec_9618 ,mem_vec_9619 ,mem_vec_9620 ,mem_vec_9621 ,mem_vec_9622 ,mem_vec_9623 ,mem_vec_9624 ,mem_vec_9625 ,mem_vec_9626 ,mem_vec_9627 ,mem_vec_9628 ,mem_vec_9629 ,mem_vec_9630 ,mem_vec_9631 ,mem_vec_9632 ,mem_vec_9633 ,mem_vec_9634 ,mem_vec_9635 ,mem_vec_9636 ,mem_vec_9637 ,mem_vec_9638 ,mem_vec_9639 ,mem_vec_9640 ,mem_vec_9641 ,mem_vec_9642 ,mem_vec_9643 ,mem_vec_9644 ,mem_vec_9645 ,mem_vec_9646 ,mem_vec_9647 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f513 = f514, f513_p_0 = 0;
	f513 < f514 + 512;
	f513 += 512, f513_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 17) (34 / 2)
	for (x929 = x930, x929_p_0 = 0;
		x929 < x930 + 34;
		x929 += 2, x929_p_0 += 2){
		// y = 34, x = 2, h = 3, w = 3, c = 256, f = 512
		// T (c, 16) (256 / 16)
		for (c1112 = c1113, c1112_p_0 = 0;
			c1112 < c1113 + 256;
			c1112 += 16, c1112_p_0 += 16){
			// y = 34, x = 2, h = 3, w = 3, c = 16, f = 512
			// T (f, 8) (512 / 64)
			for (f512 = f513, f512_p_1 = f513_p_0, f512_p_0 = 0;
				f512 < f513 + 512;
				f512 += 64, f512_p_1 += 64, f512_p_0 += 64){
					for (y = y464, yp_0 = 0;
						y < y464 + 4;
						y += 4, yp_0 += 4){
						// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
						// T (x, 1) (2 / 2)
						for (x928 = x929, x928_p_1 = x929_p_0, x928_p_0 = 0;
							x928 < x929 + 2;
							x928 += 2, x928_p_1 += 2, x928_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
							// T (f, 2) (64 / 32)
							for (f = f512, fp_2 = f512_p_1, fp_1 = f512_p_0, fp_0 = 0;
								f < f512 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w464, wp_0 = 0;
									w < w464 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 32
									// T (x, 2) (2 / 1)
									for (x = x928, xp_2 = x928_p_1, xp_1 = x928_p_0, xp_0 = 0;
										x < x928 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9608 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9609 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9610 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9611 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_9612 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9613 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9614 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9615 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_9616 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9617 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9618 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9619 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_9620 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9621 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9622 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9623 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1112, cp_1 = c1112_p_0, cp_0 = 0;
													c < c1112 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9608);
													mem_vec_9608 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9609);
													mem_vec_9609 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9610);
													mem_vec_9610 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9611);
													mem_vec_9611 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9612);
													mem_vec_9612 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9613);
													mem_vec_9613 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9614);
													mem_vec_9614 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9615);
													mem_vec_9615 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9616);
													mem_vec_9616 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9617);
													mem_vec_9617 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9618);
													mem_vec_9618 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9619);
													mem_vec_9619 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9620);
													mem_vec_9620 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9621);
													mem_vec_9621 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9622);
													mem_vec_9622 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9623);
													mem_vec_9623 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_25 = _mm256_set1_ps(scal_4);
													vec_26 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_24 = _mm256_fmadd_ps(vec_25, vec_26, mem_vec_9608);
													mem_vec_9608 = vec_24;

													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_27 = _mm256_fmadd_ps(vec_25, vec_28, mem_vec_9609);
													mem_vec_9609 = vec_27;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_29 = _mm256_fmadd_ps(vec_25, vec_30, mem_vec_9610);
													mem_vec_9610 = vec_29;

													vec_32 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_31 = _mm256_fmadd_ps(vec_25, vec_32, mem_vec_9611);
													mem_vec_9611 = vec_31;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_34 = _mm256_set1_ps(scal_5);


													vec_33 = _mm256_fmadd_ps(vec_34, vec_26, mem_vec_9612);
													mem_vec_9612 = vec_33;



													vec_35 = _mm256_fmadd_ps(vec_34, vec_28, mem_vec_9613);
													mem_vec_9613 = vec_35;



													vec_36 = _mm256_fmadd_ps(vec_34, vec_30, mem_vec_9614);
													mem_vec_9614 = vec_36;



													vec_37 = _mm256_fmadd_ps(vec_34, vec_32, mem_vec_9615);
													mem_vec_9615 = vec_37;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_26, mem_vec_9616);
													mem_vec_9616 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_28, mem_vec_9617);
													mem_vec_9617 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_30, mem_vec_9618);
													mem_vec_9618 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_32, mem_vec_9619);
													mem_vec_9619 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_26, mem_vec_9620);
													mem_vec_9620 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_9621);
													mem_vec_9621 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_9622);
													mem_vec_9622 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_32, mem_vec_9623);
													mem_vec_9623 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_49 = _mm256_set1_ps(scal_8);
													vec_50 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_48 = _mm256_fmadd_ps(vec_49, vec_50, mem_vec_9608);
													mem_vec_9608 = vec_48;

													vec_52 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_51 = _mm256_fmadd_ps(vec_49, vec_52, mem_vec_9609);
													mem_vec_9609 = vec_51;

													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_53 = _mm256_fmadd_ps(vec_49, vec_54, mem_vec_9610);
													mem_vec_9610 = vec_53;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_55 = _mm256_fmadd_ps(vec_49, vec_56, mem_vec_9611);
													mem_vec_9611 = vec_55;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_9);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_50, mem_vec_9612);
													mem_vec_9612 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_52, mem_vec_9613);
													mem_vec_9613 = vec_59;



													vec_60 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_9614);
													mem_vec_9614 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_9615);
													mem_vec_9615 = vec_61;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_63 = _mm256_set1_ps(scal_10);


													vec_62 = _mm256_fmadd_ps(vec_63, vec_50, mem_vec_9616);
													mem_vec_9616 = vec_62;



													vec_64 = _mm256_fmadd_ps(vec_63, vec_52, mem_vec_9617);
													mem_vec_9617 = vec_64;



													vec_65 = _mm256_fmadd_ps(vec_63, vec_54, mem_vec_9618);
													mem_vec_9618 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_63, vec_56, mem_vec_9619);
													mem_vec_9619 = vec_66;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_50, mem_vec_9620);
													mem_vec_9620 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_52, mem_vec_9621);
													mem_vec_9621 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_54, mem_vec_9622);
													mem_vec_9622 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_56, mem_vec_9623);
													mem_vec_9623 = vec_71;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9608);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9609);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9610);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9611);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9612);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9613);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9614);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9615);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9616);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9617);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9618);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9619);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9620);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9621);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9622);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9623);
									}
								}
							}
						}
					}
					for (y = y464 + 4, yp_0 = 0;
						y < y464 + 4 + 30;
						y += 6, yp_0 += 6){
						// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
						// T (x, 1) (2 / 2)
						for (x928 = x929, x928_p_1 = x929_p_0, x928_p_0 = 0;
							x928 < x929 + 2;
							x928 += 2, x928_p_1 += 2, x928_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 64
							// T (f, 2) (64 / 32)
							for (f = f512, fp_2 = f512_p_1, fp_1 = f512_p_0, fp_0 = 0;
								f < f512 + 64;
								f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
								// y = ph_y, x = 2, h = 3, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w464, wp_0 = 0;
									w < w464 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 16, f = 32
									// T (x, 2) (2 / 1)
									for (x = x928, xp_2 = x928_p_1, xp_1 = x928_p_0, xp_0 = 0;
										x < x928 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9624 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9625 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9626 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9627 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_9628 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9629 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9630 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9631 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_9632 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9633 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9634 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9635 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_9636 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9637 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9638 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9639 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_9640 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9641 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9642 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9643 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_9644 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9645 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_9646 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9647 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c1112, cp_1 = c1112_p_0, cp_0 = 0;
													c < c1112 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9624);
													mem_vec_9624 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9625);
													mem_vec_9625 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_9626);
													mem_vec_9626 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_9627);
													mem_vec_9627 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_9628);
													mem_vec_9628 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_9629);
													mem_vec_9629 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_9630);
													mem_vec_9630 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_9631);
													mem_vec_9631 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9632);
													mem_vec_9632 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9633);
													mem_vec_9633 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_9634);
													mem_vec_9634 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_9635);
													mem_vec_9635 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_9636);
													mem_vec_9636 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_9637);
													mem_vec_9637 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_9638);
													mem_vec_9638 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_9639);
													mem_vec_9639 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_9640);
													mem_vec_9640 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_9641);
													mem_vec_9641 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_9642);
													mem_vec_9642 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_9643);
													mem_vec_9643 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9644);
													mem_vec_9644 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9645);
													mem_vec_9645 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_9646);
													mem_vec_9646 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_9647);
													mem_vec_9647 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_9624);
													mem_vec_9624 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_9625);
													mem_vec_9625 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_9626);
													mem_vec_9626 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_9627);
													mem_vec_9627 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_9628);
													mem_vec_9628 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_9629);
													mem_vec_9629 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_9630);
													mem_vec_9630 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_9631);
													mem_vec_9631 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_9632);
													mem_vec_9632 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_9633);
													mem_vec_9633 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_9634);
													mem_vec_9634 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_9635);
													mem_vec_9635 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_9636);
													mem_vec_9636 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_9637);
													mem_vec_9637 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_9638);
													mem_vec_9638 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_9639);
													mem_vec_9639 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_9640);
													mem_vec_9640 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_9641);
													mem_vec_9641 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_9642);
													mem_vec_9642 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_9643);
													mem_vec_9643 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_9644);
													mem_vec_9644 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_9645);
													mem_vec_9645 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_9646);
													mem_vec_9646 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_9647);
													mem_vec_9647 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_9624);
													mem_vec_9624 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_9625);
													mem_vec_9625 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_9626);
													mem_vec_9626 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_9627);
													mem_vec_9627 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_9628);
													mem_vec_9628 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_9629);
													mem_vec_9629 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_9630);
													mem_vec_9630 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_9631);
													mem_vec_9631 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_9632);
													mem_vec_9632 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_9633);
													mem_vec_9633 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_9634);
													mem_vec_9634 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_9635);
													mem_vec_9635 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_9636);
													mem_vec_9636 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_9637);
													mem_vec_9637 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_9638);
													mem_vec_9638 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_9639);
													mem_vec_9639 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_9640);
													mem_vec_9640 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_9641);
													mem_vec_9641 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_9642);
													mem_vec_9642 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_9643);
													mem_vec_9643 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_9644);
													mem_vec_9644 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_9645);
													mem_vec_9645 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_9646);
													mem_vec_9646 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_9647);
													mem_vec_9647 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9624);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9625);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9626);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_9627);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9628);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9629);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9630);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_9631);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9632);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9633);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9634);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_9635);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9636);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9637);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9638);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_9639);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9640);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9641);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9642);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_9643);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9644);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9645);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9646);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_9647);
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