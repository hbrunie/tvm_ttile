#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (14, x);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))];
  T (1, f); T (64, c); T (1, f); T (1, c); T (1, x); T (8, f)]
*/
IND_TYPE c, cp_0, c694_p_0, c695_p_0, cp_1, c694_p_1, cp_2, c694, c695, f, fp_0, f686_p_0, f687_p_0, fp_1, f686_p_1, fp_2, f686, f687, h, hp_0, x, xp_0, x586_p_0, xp_1, x586, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y392 = 0;
IND_TYPE x587 = 0;
IND_TYPE h318 = 0;
IND_TYPE w = 0;
IND_TYPE c696 = 0;
IND_TYPE f688 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3740 ,mem_vec_3741 ,mem_vec_3742 ,mem_vec_3743 ,mem_vec_3744 ,mem_vec_3745 ,mem_vec_3746 ,mem_vec_3747 ,mem_vec_3748 ,mem_vec_3749 ,mem_vec_3750 ,mem_vec_3751 ,mem_vec_3752 ,mem_vec_3753 ,mem_vec_3754 ,mem_vec_3755 ,mem_vec_3756 ,mem_vec_3757 ,mem_vec_3758 ,mem_vec_3759 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 8) (256 / 32)
for (f687 = f688, f687_p_0 = 0;
	f687 < f688 + 256;
	f687 += 32, f687_p_0 += 32){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
	// T (x, 1) (14 / 14)
	for (x586 = x587, x586_p_0 = 0;
		x586 < x587 + 14;
		x586 += 14, x586_p_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
		// T (c, 1) (256 / 256)
		for (c695 = c696, c695_p_0 = 0;
			c695 < c696 + 256;
			c695 += 256, c695_p_0 += 256){
			// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
			// T (f, 1) (32 / 32)
			for (f686 = f687, f686_p_1 = f687_p_0, f686_p_0 = 0;
				f686 < f687 + 32;
				f686 += 32, f686_p_1 += 32, f686_p_0 += 32){
				// y = 14, x = 14, h = 3, w = 3, c = 256, f = 32
				// T (c, 64) (256 / 4)
				for (c694 = c695, c694_p_1 = c695_p_0, c694_p_0 = 0;
					c694 < c695 + 256;
					c694 += 4, c694_p_1 += 4, c694_p_0 += 4){
					// y = 14, x = 14, h = 3, w = 3, c = 4, f = 32
					// T (f, 1) (32 / 32)
					for (f = f686, fp_2 = f686_p_1, fp_1 = f686_p_0, fp_0 = 0;
						f < f686 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y392, yp_0 = 0;
								y < y392 + 8;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h318, hp_0 = 0;
									h < h318 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 4, f = 32
									// T (x, 14) (14 / 1)
									for (x = x586, xp_1 = x586_p_0, xp_0 = 0;
										x < x586 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3740 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3741 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c694, cp_2 = c694_p_1, cp_1 = c694_p_0, cp_0 = 0;
													c < c694 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3740);
													mem_vec_3740 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3741);
													mem_vec_3741 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3742);
													mem_vec_3742 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3743);
													mem_vec_3743 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3744);
													mem_vec_3744 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3745);
													mem_vec_3745 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3746);
													mem_vec_3746 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3747);
													mem_vec_3747 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_3740);
													mem_vec_3740 = vec_14;

													vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_3741);
													mem_vec_3741 = vec_17;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_20 = _mm512_set1_ps(scal_5);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_3742);
													mem_vec_3742 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_3743);
													mem_vec_3743 = vec_21;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_3744);
													mem_vec_3744 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_3745);
													mem_vec_3745 = vec_24;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_3746);
													mem_vec_3746 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_3747);
													mem_vec_3747 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_3740);
													mem_vec_3740 = vec_28;

													vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_3741);
													mem_vec_3741 = vec_31;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_34 = _mm512_set1_ps(scal_9);


													vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_3742);
													mem_vec_3742 = vec_33;



													vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_3743);
													mem_vec_3743 = vec_35;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_37 = _mm512_set1_ps(scal_10);


													vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_3744);
													mem_vec_3744 = vec_36;



													vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_3745);
													mem_vec_3745 = vec_38;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_3746);
													mem_vec_3746 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_3747);
													mem_vec_3747 = vec_41;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3740);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3741);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3742);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3743);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3744);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3745);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3746);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3747);
									}
								}
							}
							for (y = y392 + 8, yp_0 = 0;
								y < y392 + 8 + 6;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 14, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h318, hp_0 = 0;
									h < h318 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 4, f = 32
									// T (x, 14) (14 / 1)
									for (x = x586, xp_1 = x586_p_0, xp_0 = 0;
										x < x586 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3748 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3749 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c694, cp_2 = c694_p_1, cp_1 = c694_p_0, cp_0 = 0;
													c < c694 + 4;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3748);
													mem_vec_3748 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3749);
													mem_vec_3749 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3750);
													mem_vec_3750 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3751);
													mem_vec_3751 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3752);
													mem_vec_3752 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3753);
													mem_vec_3753 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3754);
													mem_vec_3754 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3755);
													mem_vec_3755 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3756);
													mem_vec_3756 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3757);
													mem_vec_3757 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3758);
													mem_vec_3758 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3759);
													mem_vec_3759 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_3748);
													mem_vec_3748 = vec_20;

													vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_3749);
													mem_vec_3749 = vec_23;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_3750);
													mem_vec_3750 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_3751);
													mem_vec_3751 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);


													vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_3752);
													mem_vec_3752 = vec_28;



													vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_3753);
													mem_vec_3753 = vec_30;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_3754);
													mem_vec_3754 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_3755);
													mem_vec_3755 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_3756);
													mem_vec_3756 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_3757);
													mem_vec_3757 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_3758);
													mem_vec_3758 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_3759);
													mem_vec_3759 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);
													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_3748);
													mem_vec_3748 = vec_40;

													vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_3749);
													mem_vec_3749 = vec_43;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);


													vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_3750);
													mem_vec_3750 = vec_45;



													vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_3751);
													mem_vec_3751 = vec_47;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_3752);
													mem_vec_3752 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_3753);
													mem_vec_3753 = vec_50;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_52 = _mm512_set1_ps(scal_15);


													vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_3754);
													mem_vec_3754 = vec_51;



													vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_3755);
													mem_vec_3755 = vec_53;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_55 = _mm512_set1_ps(scal_16);


													vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_3756);
													mem_vec_3756 = vec_54;



													vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_3757);
													mem_vec_3757 = vec_56;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_58 = _mm512_set1_ps(scal_17);


													vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_3758);
													mem_vec_3758 = vec_57;



													vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_3759);
													mem_vec_3759 = vec_59;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3748);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3749);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3750);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3751);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3752);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3753);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3754);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3755);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3756);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3757);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3758);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3759);
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