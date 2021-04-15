#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (1, c); Hoist_vars [c]; T (2, x);
  T (3, w); T (2, c); T (17, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (2, c);
  T (32, f); T (1, x); T (64, c)]
*/
IND_TYPE c, cp_0, c100_p_0, c101_p_0, c102_p_0, cp_1, c100_p_1, c101_p_1, cp_2, c100_p_2, cp_3, c100, c101, c102, f, fp_0, w, wp_0, x, xp_0, x80_p_0, x81_p_0, xp_1, x80_p_1, xp_2, x80, x81, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y40 = 0;
IND_TYPE x82 = 0;
IND_TYPE h = 0;
IND_TYPE w40 = 0;
IND_TYPE c103 = 0;
IND_TYPE f40 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,mem_vec_749 ,mem_vec_750 ,mem_vec_751 ,mem_vec_752 ,mem_vec_753 ,mem_vec_754 ,mem_vec_755 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 64) (256 / 4)
for (c102 = c103, c102_p_0 = 0;
	c102 < c103 + 256;
	c102 += 4, c102_p_0 += 4){
	// y = 34, x = 34, h = 3, w = 3, c = 4, f = 512
	// T (x, 1) (34 / 34)
	for (x81 = x82, x81_p_0 = 0;
		x81 < x82 + 34;
		x81 += 34, x81_p_0 += 34){
		// y = 34, x = 34, h = 3, w = 3, c = 4, f = 512
		// T (f, 32) (512 / 16)
		for (f = f40, fp_0 = 0;
			f < f40 + 512;
			f += 16, fp_0 += 16){
			// y = 34, x = 34, h = 3, w = 3, c = 4, f = 16
			// T (c, 2) (4 / 2)
			for (c101 = c102, c101_p_1 = c102_p_0, c101_p_0 = 0;
				c101 < c102 + 4;
				c101 += 2, c101_p_1 += 2, c101_p_0 += 2){
					for (y = y40, yp_0 = 0;
						y < y40 + 24;
						y += 8, yp_0 += 8){
						// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 16
						// T (x, 17) (34 / 2)
						for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
							x80 < x81 + 34;
							x80 += 2, x80_p_1 += 2, x80_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 16
							// T (c, 2) (2 / 1)
							for (c100 = c101, c100_p_2 = c101_p_1, c100_p_1 = c101_p_0, c100_p_0 = 0;
								c100 < c101 + 2;
								c100 += 1, c100_p_2 += 1, c100_p_1 += 1, c100_p_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 16
								// T (w, 3) (3 / 1)
								for (w = w40, wp_0 = 0;
									w < w40 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 1, f = 16
									// T (x, 2) (2 / 1)
									for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
										x < x80 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_720 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_721 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_722 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_723 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_724 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_725 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_726 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_727 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_728 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_729 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_732 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_733 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_734 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_735 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
												// T (c, 1) (1 / 1)
												for (c = c100, cp_3 = c100_p_2, cp_2 = c100_p_1, cp_1 = c100_p_0, cp_0 = 0;
													c < c100 + 1;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_720);
													mem_vec_720 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_721);
													mem_vec_721 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_722);
													mem_vec_722 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_723);
													mem_vec_723 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_724);
													mem_vec_724 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_725);
													mem_vec_725 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_726);
													mem_vec_726 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_727);
													mem_vec_727 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_728);
													mem_vec_728 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_729);
													mem_vec_729 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_730);
													mem_vec_730 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_731);
													mem_vec_731 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_732);
													mem_vec_732 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_733);
													mem_vec_733 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_734);
													mem_vec_734 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_735);
													mem_vec_735 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_27 = _mm256_set1_ps(scal_8);
													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_720);
													mem_vec_720 = vec_26;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_721);
													mem_vec_721 = vec_29;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_32 = _mm256_set1_ps(scal_9);


													vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_722);
													mem_vec_722 = vec_31;



													vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_723);
													mem_vec_723 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_10);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_724);
													mem_vec_724 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_725);
													mem_vec_725 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_726);
													mem_vec_726 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_727);
													mem_vec_727 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_728);
													mem_vec_728 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_729);
													mem_vec_729 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_730);
													mem_vec_730 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_731);
													mem_vec_731 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_732);
													mem_vec_732 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_733);
													mem_vec_733 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_734);
													mem_vec_734 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_735);
													mem_vec_735 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_53 = _mm256_set1_ps(scal_16);
													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_720);
													mem_vec_720 = vec_52;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_721);
													mem_vec_721 = vec_55;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_17);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_722);
													mem_vec_722 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_723);
													mem_vec_723 = vec_59;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_61 = _mm256_set1_ps(scal_18);


													vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_724);
													mem_vec_724 = vec_60;



													vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_725);
													mem_vec_725 = vec_62;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_64 = _mm256_set1_ps(scal_19);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_726);
													mem_vec_726 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_727);
													mem_vec_727 = vec_65;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_67 = _mm256_set1_ps(scal_20);


													vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_728);
													mem_vec_728 = vec_66;



													vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_729);
													mem_vec_729 = vec_68;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_730);
													mem_vec_730 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_731);
													mem_vec_731 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_732);
													mem_vec_732 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_733);
													mem_vec_733 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_734);
													mem_vec_734 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_735);
													mem_vec_735 = vec_77;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_720);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_721);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_722);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_723);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_724);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_725);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_726);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_727);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_728);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_729);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_730);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_731);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_732);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_733);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_734);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_735);
									}
								}
							}
						}
					}
					for (y = y40 + 24, yp_0 = 0;
						y < y40 + 24 + 10;
						y += 10, yp_0 += 10){
						// y = ph_y, x = 34, h = 3, w = 3, c = 2, f = 16
						// T (x, 17) (34 / 2)
						for (x80 = x81, x80_p_1 = x81_p_0, x80_p_0 = 0;
							x80 < x81 + 34;
							x80 += 2, x80_p_1 += 2, x80_p_0 += 2){
							// y = ph_y, x = 2, h = 3, w = 3, c = 2, f = 16
							// T (c, 2) (2 / 1)
							for (c100 = c101, c100_p_2 = c101_p_1, c100_p_1 = c101_p_0, c100_p_0 = 0;
								c100 < c101 + 2;
								c100 += 1, c100_p_2 += 1, c100_p_1 += 1, c100_p_0 += 1){
								// y = ph_y, x = 2, h = 3, w = 3, c = 1, f = 16
								// T (w, 3) (3 / 1)
								for (w = w40, wp_0 = 0;
									w < w40 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 2, h = 3, w = 1, c = 1, f = 16
									// T (x, 2) (2 / 1)
									for (x = x80, xp_2 = x80_p_1, xp_1 = x80_p_0, xp_0 = 0;
										x < x80 + 2;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_736 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_737 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_738 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_739 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_740 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_741 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 1, f = 16
												// T (c, 1) (1 / 1)
												for (c = c100, cp_3 = c100_p_2, cp_2 = c100_p_1, cp_1 = c100_p_0, cp_0 = 0;
													c < c100 + 1;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_736);
													mem_vec_736 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_737);
													mem_vec_737 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_738);
													mem_vec_738 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_739);
													mem_vec_739 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_740);
													mem_vec_740 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_741);
													mem_vec_741 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_742);
													mem_vec_742 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_743);
													mem_vec_743 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_744);
													mem_vec_744 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_745);
													mem_vec_745 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_746);
													mem_vec_746 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_747);
													mem_vec_747 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_748);
													mem_vec_748 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_749);
													mem_vec_749 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_750);
													mem_vec_750 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_751);
													mem_vec_751 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_752);
													mem_vec_752 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_753);
													mem_vec_753 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_754);
													mem_vec_754 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_755);
													mem_vec_755 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_33 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_736);
													mem_vec_736 = vec_32;

													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_737);
													mem_vec_737 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_738);
													mem_vec_738 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_739);
													mem_vec_739 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_740);
													mem_vec_740 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_741);
													mem_vec_741 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_742);
													mem_vec_742 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_743);
													mem_vec_743 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_744);
													mem_vec_744 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_745);
													mem_vec_745 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_746);
													mem_vec_746 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_747);
													mem_vec_747 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_748);
													mem_vec_748 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_749);
													mem_vec_749 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_750);
													mem_vec_750 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_751);
													mem_vec_751 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_752);
													mem_vec_752 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_753);
													mem_vec_753 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_754);
													mem_vec_754 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_755);
													mem_vec_755 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_65 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_736);
													mem_vec_736 = vec_64;

													vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_737);
													mem_vec_737 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_738);
													mem_vec_738 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_739);
													mem_vec_739 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_740);
													mem_vec_740 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_741);
													mem_vec_741 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_742);
													mem_vec_742 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_743);
													mem_vec_743 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_744);
													mem_vec_744 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_745);
													mem_vec_745 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_746);
													mem_vec_746 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_747);
													mem_vec_747 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_748);
													mem_vec_748 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_749);
													mem_vec_749 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_750);
													mem_vec_750 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_751);
													mem_vec_751 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_752);
													mem_vec_752 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_753);
													mem_vec_753 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_754);
													mem_vec_754 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_755);
													mem_vec_755 = vec_95;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_736);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_737);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_738);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_739);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_740);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_741);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_742);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_743);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_744);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_745);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_746);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_747);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_748);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_749);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_750);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_751);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_752);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_753);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_754);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_755);
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