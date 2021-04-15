#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (32, c); Hoist_vars [c]; T (4, x);
  T (3, w); T (1, c); T (1, y); T (34, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (8, f);
  T (2, c); T (1, x)]
*/
IND_TYPE c, cp_0, c1096_p_0, c1097_p_0, cp_1, c1096_p_1, cp_2, c1096, c1097, f, fp_0, w, wp_0, x, xp_0, x1122_p_0, x1123_p_0, xp_1, x1122_p_1, xp_2, x1122, x1123, y, yp_0, y826_p_0, yp_1, y826;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y827 = 0;
IND_TYPE x1124 = 0;
IND_TYPE h = 0;
IND_TYPE w552 = 0;
IND_TYPE c1098 = 0;
IND_TYPE f608 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_30 ,scal_31 ,scal_32 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_9728 ,mem_vec_9729 ,mem_vec_9730 ,mem_vec_9731 ,mem_vec_9732 ,mem_vec_9733 ,mem_vec_9734 ,mem_vec_9735 ,mem_vec_9736 ,mem_vec_9737 ,mem_vec_9738 ,mem_vec_9739 ,mem_vec_9740 ,mem_vec_9741 ,mem_vec_9742 ,mem_vec_9743 ,mem_vec_9744 ,mem_vec_9745 ,mem_vec_9746 ,mem_vec_9747 ,mem_vec_9748 ,mem_vec_9749 ,mem_vec_9750 ,mem_vec_9751 ,mem_vec_9752 ,mem_vec_9753 ,mem_vec_9754 ,mem_vec_9755 ,mem_vec_9756 ,mem_vec_9757 ,mem_vec_9758 ,mem_vec_9759 ,mem_vec_9760 ,mem_vec_9761 ,mem_vec_9762 ,mem_vec_9763 ,mem_vec_9764 ,mem_vec_9765 ,mem_vec_9766 ,mem_vec_9767 ,mem_vec_9768 ,mem_vec_9769 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_102 ,vec_103 ,vec_104 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x1123 = x1124, x1123_p_0 = 0;
	x1123 < x1124 + 136;
	x1123 += 136, x1123_p_0 += 136){
	// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
	// T (c, 2) (64 / 32)
	for (c1097 = c1098, c1097_p_0 = 0;
		c1097 < c1098 + 64;
		c1097 += 32, c1097_p_0 += 32){
		// y = 136, x = 136, h = 3, w = 3, c = 32, f = 128
		// T (f, 8) (128 / 16)
		for (f = f608, fp_0 = 0;
			f < f608 + 128;
			f += 16, fp_0 += 16){
				for (y826 = y827, y826_p_0 = 0;
					y826 < y827 + 70;
					y826 += 10, y826_p_0 += 10){
					// y = ph_y, x = 136, h = 3, w = 3, c = 32, f = 16
					// T (x, 34) (136 / 4)
					for (x1122 = x1123, x1122_p_1 = x1123_p_0, x1122_p_0 = 0;
						x1122 < x1123 + 136;
						x1122 += 4, x1122_p_1 += 4, x1122_p_0 += 4){
						// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
						// T (y, 1) (ph_y / ph_y)
						for (y = y826, yp_1 = y826_p_0, yp_0 = 0;
							y < y826 + 10;
							y += 10, yp_1 += 10, yp_0 += 10){
							// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
							// T (c, 1) (32 / 32)
							for (c1096 = c1097, c1096_p_1 = c1097_p_0, c1096_p_0 = 0;
								c1096 < c1097 + 32;
								c1096 += 32, c1096_p_1 += 32, c1096_p_0 += 32){
								// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w552, wp_0 = 0;
									w < w552 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 32, f = 16
									// T (x, 4) (4 / 1)
									for (x = x1122, xp_2 = x1122_p_1, xp_1 = x1122_p_0, xp_0 = 0;
										x < x1122 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9728 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9729 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9732 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9733 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9734 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9735 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9736 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9737 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9738 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9739 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_9740 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9741 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_9742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_9744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_9746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
												// T (c, 32) (32 / 1)
												for (c = c1096, cp_2 = c1096_p_1, cp_1 = c1096_p_0, cp_0 = 0;
													c < c1096 + 32;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9728);
													mem_vec_9728 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9729);
													mem_vec_9729 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_9730);
													mem_vec_9730 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_9731);
													mem_vec_9731 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_9732);
													mem_vec_9732 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_9733);
													mem_vec_9733 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_9734);
													mem_vec_9734 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_9735);
													mem_vec_9735 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9736);
													mem_vec_9736 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9737);
													mem_vec_9737 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_9738);
													mem_vec_9738 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_9739);
													mem_vec_9739 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_9740);
													mem_vec_9740 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_9741);
													mem_vec_9741 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_9742);
													mem_vec_9742 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_9743);
													mem_vec_9743 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_9744);
													mem_vec_9744 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_9745);
													mem_vec_9745 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9746);
													mem_vec_9746 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9747);
													mem_vec_9747 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_33 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_9728);
													mem_vec_9728 = vec_32;

													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_9729);
													mem_vec_9729 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_9730);
													mem_vec_9730 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_9731);
													mem_vec_9731 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_9732);
													mem_vec_9732 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_9733);
													mem_vec_9733 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_9734);
													mem_vec_9734 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_9735);
													mem_vec_9735 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_9736);
													mem_vec_9736 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_9737);
													mem_vec_9737 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_9738);
													mem_vec_9738 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_9739);
													mem_vec_9739 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_9740);
													mem_vec_9740 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_9741);
													mem_vec_9741 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_9742);
													mem_vec_9742 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_9743);
													mem_vec_9743 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_9744);
													mem_vec_9744 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_9745);
													mem_vec_9745 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_9746);
													mem_vec_9746 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_9747);
													mem_vec_9747 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_65 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_9728);
													mem_vec_9728 = vec_64;

													vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_9729);
													mem_vec_9729 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_9730);
													mem_vec_9730 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_9731);
													mem_vec_9731 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_9732);
													mem_vec_9732 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_9733);
													mem_vec_9733 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_9734);
													mem_vec_9734 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_9735);
													mem_vec_9735 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_9736);
													mem_vec_9736 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_9737);
													mem_vec_9737 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_9738);
													mem_vec_9738 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_9739);
													mem_vec_9739 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_9740);
													mem_vec_9740 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_9741);
													mem_vec_9741 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_9742);
													mem_vec_9742 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_9743);
													mem_vec_9743 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_9744);
													mem_vec_9744 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_9745);
													mem_vec_9745 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_9746);
													mem_vec_9746 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_9747);
													mem_vec_9747 = vec_95;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9728);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9729);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9730);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9731);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9732);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9733);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9734);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9735);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9736);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9737);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9738);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9739);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9740);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_9741);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9742);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_9743);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9744);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_9745);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9746);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_9747);
									}
								}
							}
						}
					}
				}
				for (y826 = y827 + 70, y826_p_0 = 0;
					y826 < y827 + 70 + 66;
					y826 += 11, y826_p_0 += 11){
					// y = ph_y, x = 136, h = 3, w = 3, c = 32, f = 16
					// T (x, 34) (136 / 4)
					for (x1122 = x1123, x1122_p_1 = x1123_p_0, x1122_p_0 = 0;
						x1122 < x1123 + 136;
						x1122 += 4, x1122_p_1 += 4, x1122_p_0 += 4){
						// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
						// T (y, 1) (ph_y / ph_y)
						for (y = y826, yp_1 = y826_p_0, yp_0 = 0;
							y < y826 + 11;
							y += 11, yp_1 += 11, yp_0 += 11){
							// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
							// T (c, 1) (32 / 32)
							for (c1096 = c1097, c1096_p_1 = c1097_p_0, c1096_p_0 = 0;
								c1096 < c1097 + 32;
								c1096 += 32, c1096_p_1 += 32, c1096_p_0 += 32){
								// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 16
								// T (w, 3) (3 / 1)
								for (w = w552, wp_0 = 0;
									w < w552 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 4, h = 3, w = 1, c = 32, f = 16
									// T (x, 4) (4 / 1)
									for (x = x1122, xp_2 = x1122_p_1, xp_1 = x1122_p_0, xp_0 = 0;
										x < x1122 + 4;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9748 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9749 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_9750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_9752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_9754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_9756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_9758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_9760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_9762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_9764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_9766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												mem_vec_9768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 32, f = 16
												// T (c, 32) (32 / 1)
												for (c = c1096, cp_2 = c1096_p_1, cp_1 = c1096_p_0, cp_0 = 0;
													c < c1096 + 32;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_9748);
													mem_vec_9748 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_9749);
													mem_vec_9749 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_9750);
													mem_vec_9750 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_9751);
													mem_vec_9751 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_9752);
													mem_vec_9752 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_9753);
													mem_vec_9753 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_9754);
													mem_vec_9754 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_9755);
													mem_vec_9755 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_9756);
													mem_vec_9756 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_9757);
													mem_vec_9757 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_9758);
													mem_vec_9758 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_9759);
													mem_vec_9759 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_9760);
													mem_vec_9760 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_9761);
													mem_vec_9761 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_9762);
													mem_vec_9762 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_9763);
													mem_vec_9763 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_9764);
													mem_vec_9764 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_9765);
													mem_vec_9765 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_9766);
													mem_vec_9766 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_9767);
													mem_vec_9767 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm256_set1_ps(scal_10);


													vec_32 = _mm256_fmadd_ps(vec_33, vec_2, mem_vec_9768);
													mem_vec_9768 = vec_32;



													vec_34 = _mm256_fmadd_ps(vec_33, vec_4, mem_vec_9769);
													mem_vec_9769 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_36 = _mm256_set1_ps(scal_11);
													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_35 = _mm256_fmadd_ps(vec_36, vec_37, mem_vec_9748);
													mem_vec_9748 = vec_35;

													vec_39 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_38 = _mm256_fmadd_ps(vec_36, vec_39, mem_vec_9749);
													mem_vec_9749 = vec_38;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_37, mem_vec_9750);
													mem_vec_9750 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_39, mem_vec_9751);
													mem_vec_9751 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_9752);
													mem_vec_9752 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_39, mem_vec_9753);
													mem_vec_9753 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_37, mem_vec_9754);
													mem_vec_9754 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_39, mem_vec_9755);
													mem_vec_9755 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_37, mem_vec_9756);
													mem_vec_9756 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_39, mem_vec_9757);
													mem_vec_9757 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_37, mem_vec_9758);
													mem_vec_9758 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_39, mem_vec_9759);
													mem_vec_9759 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_37, mem_vec_9760);
													mem_vec_9760 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_39, mem_vec_9761);
													mem_vec_9761 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_37, mem_vec_9762);
													mem_vec_9762 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_39, mem_vec_9763);
													mem_vec_9763 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_37, mem_vec_9764);
													mem_vec_9764 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_39, mem_vec_9765);
													mem_vec_9765 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_65 = _mm256_set1_ps(scal_20);


													vec_64 = _mm256_fmadd_ps(vec_65, vec_37, mem_vec_9766);
													mem_vec_9766 = vec_64;



													vec_66 = _mm256_fmadd_ps(vec_65, vec_39, mem_vec_9767);
													mem_vec_9767 = vec_66;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 1) + c];
													vec_68 = _mm256_set1_ps(scal_21);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_37, mem_vec_9768);
													mem_vec_9768 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_39, mem_vec_9769);
													mem_vec_9769 = vec_69;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_71 = _mm256_set1_ps(scal_22);
													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_70 = _mm256_fmadd_ps(vec_71, vec_72, mem_vec_9748);
													mem_vec_9748 = vec_70;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_73 = _mm256_fmadd_ps(vec_71, vec_74, mem_vec_9749);
													mem_vec_9749 = vec_73;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_72, mem_vec_9750);
													mem_vec_9750 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_74, mem_vec_9751);
													mem_vec_9751 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_72, mem_vec_9752);
													mem_vec_9752 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_74, mem_vec_9753);
													mem_vec_9753 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_72, mem_vec_9754);
													mem_vec_9754 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_74, mem_vec_9755);
													mem_vec_9755 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_72, mem_vec_9756);
													mem_vec_9756 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_74, mem_vec_9757);
													mem_vec_9757 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_9758);
													mem_vec_9758 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_9759);
													mem_vec_9759 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_72, mem_vec_9760);
													mem_vec_9760 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_74, mem_vec_9761);
													mem_vec_9761 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_72, mem_vec_9762);
													mem_vec_9762 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_74, mem_vec_9763);
													mem_vec_9763 = vec_95;
													scal_30 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_97 = _mm256_set1_ps(scal_30);


													vec_96 = _mm256_fmadd_ps(vec_97, vec_72, mem_vec_9764);
													mem_vec_9764 = vec_96;



													vec_98 = _mm256_fmadd_ps(vec_97, vec_74, mem_vec_9765);
													mem_vec_9765 = vec_98;
													scal_31 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_100 = _mm256_set1_ps(scal_31);


													vec_99 = _mm256_fmadd_ps(vec_100, vec_72, mem_vec_9766);
													mem_vec_9766 = vec_99;



													vec_101 = _mm256_fmadd_ps(vec_100, vec_74, mem_vec_9767);
													mem_vec_9767 = vec_101;
													scal_32 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h + 2) + c];
													vec_103 = _mm256_set1_ps(scal_32);


													vec_102 = _mm256_fmadd_ps(vec_103, vec_72, mem_vec_9768);
													mem_vec_9768 = vec_102;



													vec_104 = _mm256_fmadd_ps(vec_103, vec_74, mem_vec_9769);
													mem_vec_9769 = vec_104;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9748);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_9749);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9750);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_9751);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9752);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_9753);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9754);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_9755);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9756);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_9757);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9758);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_9759);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9760);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_9761);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9762);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_9763);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9764);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_9765);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9766);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_9767);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9768);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 8], mem_vec_9769);
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