#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (1, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 5)); ((Iter 1), (Arg 9))];
  T (2, f); T (1, c); T (2, f); T (128, c); T (14, x); T (2, f)]
*/
IND_TYPE c, cp_0, c1194_p_0, c1195_p_0, cp_1, c1194_p_1, cp_2, c1194, c1195, f, fp_0, f1170_p_0, f1171_p_0, fp_1, f1170_p_1, fp_2, f1170, f1171, h, hp_0, x, xp_0, x958_p_0, xp_1, x958, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y640 = 0;
IND_TYPE x959 = 0;
IND_TYPE h582 = 0;
IND_TYPE w = 0;
IND_TYPE c1196 = 0;
IND_TYPE f1172 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6732 ,mem_vec_6733 ,mem_vec_6734 ,mem_vec_6735 ,mem_vec_6736 ,mem_vec_6737 ,mem_vec_6738 ,mem_vec_6739 ,mem_vec_6740 ,mem_vec_6741 ,mem_vec_6742 ,mem_vec_6743 ,mem_vec_6744 ,mem_vec_6745 ,mem_vec_6746 ,mem_vec_6747 ,mem_vec_6748 ,mem_vec_6749 ,mem_vec_6750 ,mem_vec_6751 ,mem_vec_6752 ,mem_vec_6753 ,mem_vec_6754 ,mem_vec_6755 ,mem_vec_6756 ,mem_vec_6757 ,mem_vec_6758 ,mem_vec_6759 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 2) (256 / 128)
for (f1171 = f1172, f1171_p_0 = 0;
	f1171 < f1172 + 256;
	f1171 += 128, f1171_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 128
	// T (x, 14) (14 / 1)
	for (x958 = x959, x958_p_0 = 0;
		x958 < x959 + 14;
		x958 += 1, x958_p_0 += 1){
		// y = 14, x = 1, h = 3, w = 3, c = 256, f = 128
		// T (c, 128) (256 / 2)
		for (c1195 = c1196, c1195_p_0 = 0;
			c1195 < c1196 + 256;
			c1195 += 2, c1195_p_0 += 2){
			// y = 14, x = 1, h = 3, w = 3, c = 2, f = 128
			// T (f, 2) (128 / 64)
			for (f1170 = f1171, f1170_p_1 = f1171_p_0, f1170_p_0 = 0;
				f1170 < f1171 + 128;
				f1170 += 64, f1170_p_1 += 64, f1170_p_0 += 64){
				// y = 14, x = 1, h = 3, w = 3, c = 2, f = 64
				// T (c, 1) (2 / 2)
				for (c1194 = c1195, c1194_p_1 = c1195_p_0, c1194_p_0 = 0;
					c1194 < c1195 + 2;
					c1194 += 2, c1194_p_1 += 2, c1194_p_0 += 2){
					// y = 14, x = 1, h = 3, w = 3, c = 2, f = 64
					// T (f, 2) (64 / 32)
					for (f = f1170, fp_2 = f1170_p_1, fp_1 = f1170_p_0, fp_0 = 0;
						f < f1170 + 64;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y640, yp_0 = 0;
								y < y640 + 5;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h582, hp_0 = 0;
									h < h582 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x958, xp_1 = x958_p_0, xp_0 = 0;
										x < x958 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6732 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6733 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1194, cp_2 = c1194_p_1, cp_1 = c1194_p_0, cp_0 = 0;
													c < c1194 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6732);
													mem_vec_6732 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6733);
													mem_vec_6733 = vec_3;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6734);
													mem_vec_6734 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6735);
													mem_vec_6735 = vec_7;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6736);
													mem_vec_6736 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6737);
													mem_vec_6737 = vec_10;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6738);
													mem_vec_6738 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6739);
													mem_vec_6739 = vec_13;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6740);
													mem_vec_6740 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6741);
													mem_vec_6741 = vec_16;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_6732);
													mem_vec_6732 = vec_17;

													vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_6733);
													mem_vec_6733 = vec_20;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_6734);
													mem_vec_6734 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_6735);
													mem_vec_6735 = vec_24;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_6736);
													mem_vec_6736 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_6737);
													mem_vec_6737 = vec_27;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);


													vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_6738);
													mem_vec_6738 = vec_28;



													vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_6739);
													mem_vec_6739 = vec_30;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_6740);
													mem_vec_6740 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_6741);
													mem_vec_6741 = vec_33;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);
													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_6732);
													mem_vec_6732 = vec_34;

													vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_6733);
													mem_vec_6733 = vec_37;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_6734);
													mem_vec_6734 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_6735);
													mem_vec_6735 = vec_41;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_43 = _mm512_set1_ps(scal_12);


													vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_6736);
													mem_vec_6736 = vec_42;



													vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_6737);
													mem_vec_6737 = vec_44;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);


													vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_6738);
													mem_vec_6738 = vec_45;



													vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_6739);
													mem_vec_6739 = vec_47;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_6740);
													mem_vec_6740 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_6741);
													mem_vec_6741 = vec_50;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6732);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6733);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6734);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6735);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6736);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6737);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6738);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6739);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6740);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6741);
									}
								}
							}
							for (y = y640 + 5, yp_0 = 0;
								y < y640 + 5 + 9;
								y += 9, yp_0 += 9){
								// y = ph_y, x = 1, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h582, hp_0 = 0;
									h < h582 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
									// T (x, 1) (1 / 1)
									for (x = x958, xp_1 = x958_p_0, xp_0 = 0;
										x < x958 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6742 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6743 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c1194, cp_2 = c1194_p_1, cp_1 = c1194_p_0, cp_0 = 0;
													c < c1194 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6742);
													mem_vec_6742 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6743);
													mem_vec_6743 = vec_3;
													scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6744);
													mem_vec_6744 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6745);
													mem_vec_6745 = vec_7;
													scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6746);
													mem_vec_6746 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6747);
													mem_vec_6747 = vec_10;
													scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6748);
													mem_vec_6748 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6749);
													mem_vec_6749 = vec_13;
													scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6750);
													mem_vec_6750 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6751);
													mem_vec_6751 = vec_16;
													scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6752);
													mem_vec_6752 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6753);
													mem_vec_6753 = vec_19;
													scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6754);
													mem_vec_6754 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6755);
													mem_vec_6755 = vec_22;
													scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6756);
													mem_vec_6756 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6757);
													mem_vec_6757 = vec_25;
													scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6758);
													mem_vec_6758 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6759);
													mem_vec_6759 = vec_28;
													scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * y + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);
													vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_6742);
													mem_vec_6742 = vec_29;

													vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_6743);
													mem_vec_6743 = vec_32;
													scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 1) + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_31, mem_vec_6744);
													mem_vec_6744 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_33, mem_vec_6745);
													mem_vec_6745 = vec_36;
													scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 2) + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_31, mem_vec_6746);
													mem_vec_6746 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_33, mem_vec_6747);
													mem_vec_6747 = vec_39;
													scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 3) + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);


													vec_40 = _mm512_fmadd_ps(vec_41, vec_31, mem_vec_6748);
													mem_vec_6748 = vec_40;



													vec_42 = _mm512_fmadd_ps(vec_41, vec_33, mem_vec_6749);
													mem_vec_6749 = vec_42;
													scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 4) + h) + c];
													vec_44 = _mm512_set1_ps(scal_13);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_6750);
													mem_vec_6750 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_6751);
													mem_vec_6751 = vec_45;
													scal_14 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 5) + h) + c];
													vec_47 = _mm512_set1_ps(scal_14);


													vec_46 = _mm512_fmadd_ps(vec_47, vec_31, mem_vec_6752);
													mem_vec_6752 = vec_46;



													vec_48 = _mm512_fmadd_ps(vec_47, vec_33, mem_vec_6753);
													mem_vec_6753 = vec_48;
													scal_15 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 6) + h) + c];
													vec_50 = _mm512_set1_ps(scal_15);


													vec_49 = _mm512_fmadd_ps(vec_50, vec_31, mem_vec_6754);
													mem_vec_6754 = vec_49;



													vec_51 = _mm512_fmadd_ps(vec_50, vec_33, mem_vec_6755);
													mem_vec_6755 = vec_51;
													scal_16 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 7) + h) + c];
													vec_53 = _mm512_set1_ps(scal_16);


													vec_52 = _mm512_fmadd_ps(vec_53, vec_31, mem_vec_6756);
													mem_vec_6756 = vec_52;



													vec_54 = _mm512_fmadd_ps(vec_53, vec_33, mem_vec_6757);
													mem_vec_6757 = vec_54;
													scal_17 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 1) + C * (2 * (y + 8) + h) + c];
													vec_56 = _mm512_set1_ps(scal_17);


													vec_55 = _mm512_fmadd_ps(vec_56, vec_31, mem_vec_6758);
													mem_vec_6758 = vec_55;



													vec_57 = _mm512_fmadd_ps(vec_56, vec_33, mem_vec_6759);
													mem_vec_6759 = vec_57;
													scal_18 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * y + h) + c];
													vec_59 = _mm512_set1_ps(scal_18);
													vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_6742);
													mem_vec_6742 = vec_58;

													vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_6743);
													mem_vec_6743 = vec_61;
													scal_19 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 1) + h) + c];
													vec_64 = _mm512_set1_ps(scal_19);


													vec_63 = _mm512_fmadd_ps(vec_64, vec_60, mem_vec_6744);
													mem_vec_6744 = vec_63;



													vec_65 = _mm512_fmadd_ps(vec_64, vec_62, mem_vec_6745);
													mem_vec_6745 = vec_65;
													scal_20 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 2) + h) + c];
													vec_67 = _mm512_set1_ps(scal_20);


													vec_66 = _mm512_fmadd_ps(vec_67, vec_60, mem_vec_6746);
													mem_vec_6746 = vec_66;



													vec_68 = _mm512_fmadd_ps(vec_67, vec_62, mem_vec_6747);
													mem_vec_6747 = vec_68;
													scal_21 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 3) + h) + c];
													vec_70 = _mm512_set1_ps(scal_21);


													vec_69 = _mm512_fmadd_ps(vec_70, vec_60, mem_vec_6748);
													mem_vec_6748 = vec_69;



													vec_71 = _mm512_fmadd_ps(vec_70, vec_62, mem_vec_6749);
													mem_vec_6749 = vec_71;
													scal_22 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 4) + h) + c];
													vec_73 = _mm512_set1_ps(scal_22);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_6750);
													mem_vec_6750 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_6751);
													mem_vec_6751 = vec_74;
													scal_23 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 5) + h) + c];
													vec_76 = _mm512_set1_ps(scal_23);


													vec_75 = _mm512_fmadd_ps(vec_76, vec_60, mem_vec_6752);
													mem_vec_6752 = vec_75;



													vec_77 = _mm512_fmadd_ps(vec_76, vec_62, mem_vec_6753);
													mem_vec_6753 = vec_77;
													scal_24 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 6) + h) + c];
													vec_79 = _mm512_set1_ps(scal_24);


													vec_78 = _mm512_fmadd_ps(vec_79, vec_60, mem_vec_6754);
													mem_vec_6754 = vec_78;



													vec_80 = _mm512_fmadd_ps(vec_79, vec_62, mem_vec_6755);
													mem_vec_6755 = vec_80;
													scal_25 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 7) + h) + c];
													vec_82 = _mm512_set1_ps(scal_25);


													vec_81 = _mm512_fmadd_ps(vec_82, vec_60, mem_vec_6756);
													mem_vec_6756 = vec_81;



													vec_83 = _mm512_fmadd_ps(vec_82, vec_62, mem_vec_6757);
													mem_vec_6757 = vec_83;
													scal_26 = input[(C * (2 * Y + H - 1)) * (2 * x + w + 2) + C * (2 * (y + 8) + h) + c];
													vec_85 = _mm512_set1_ps(scal_26);


													vec_84 = _mm512_fmadd_ps(vec_85, vec_60, mem_vec_6758);
													mem_vec_6758 = vec_84;



													vec_86 = _mm512_fmadd_ps(vec_85, vec_62, mem_vec_6759);
													mem_vec_6759 = vec_86;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6742);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6743);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6744);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6745);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6746);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6747);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6748);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6749);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6750);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6751);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6752);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6753);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6754);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6755);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6756);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6757);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6758);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6759);
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