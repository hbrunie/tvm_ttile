#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (16, y); T (2, c); T (2, f); T (136, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (2, x)]
*/
IND_TYPE c, cp_0, c369_p_0, cp_1, c369, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x492_p_0, x493_p_0, xp_1, x492_p_1, xp_2, x492, x493, y, yp_0, y457_p_0, yp_1, y457;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y458 = 0;
IND_TYPE x494 = 0;
IND_TYPE h148 = 0;
IND_TYPE w231 = 0;
IND_TYPE c370 = 0;
IND_TYPE f241 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m256 mem_vec_4740 ,mem_vec_4741 ,mem_vec_4742 ,mem_vec_4743 ,mem_vec_4744 ,mem_vec_4745 ,mem_vec_4746 ,mem_vec_4747 ,mem_vec_4748 ,mem_vec_4749 ,mem_vec_4750 ,mem_vec_4751 ,mem_vec_4752 ,mem_vec_4753 ,mem_vec_4754 ,mem_vec_4755 ,mem_vec_4756 ,mem_vec_4757 ,mem_vec_4758 ,mem_vec_4759 ,mem_vec_4760 ,mem_vec_4761 ,mem_vec_4762 ,mem_vec_4763 ,mem_vec_4764 ,mem_vec_4765 ,mem_vec_4766 ,mem_vec_4767 ,mem_vec_4768 ,mem_vec_4769 ,mem_vec_4770 ,mem_vec_4771 ,mem_vec_4772 ,mem_vec_4773 ,mem_vec_4774 ,mem_vec_4775 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 2) (272 / 136)
for (x493 = x494, x493_p_0 = 0;
	x493 < x494 + 272;
	x493 += 136, x493_p_0 += 136){
		for (y457 = y458, y457_p_0 = 0;
			y457 < y458 + 192;
			y457 += 64, y457_p_0 += 64){
			// y = 16 * ph_y, x = 136, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (136 / 1)
			for (x492 = x493, x492_p_1 = x493_p_0, x492_p_0 = 0;
				x492 < x493 + 136;
				x492 += 1, x492_p_1 += 1, x492_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f241, fp_0 = 0;
					f < f241 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c369 = c370, c369_p_0 = 0;
						c369 < c370 + 32;
						c369 += 16, c369_p_0 += 16){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y457, yp_1 = y457_p_0, yp_0 = 0;
							y < y457 + 64;
							y += 4, yp_1 += 4, yp_0 += 4){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x492, xp_2 = x492_p_1, xp_1 = x492_p_0, xp_0 = 0;
								x < x492 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h148, hp_0 = 0;
									h < h148 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (w, 3) (3 / 1)
									for (w = w231, wp_0 = 0;
										w < w231 + 3;
										w += 1, wp_0 += 1){
												mem_vec_4740 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4741 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4742 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4743 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4744 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4745 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c369, cp_1 = c369_p_0, cp_0 = 0;
													c < c369 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4740);
													mem_vec_4740 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4741);
													mem_vec_4741 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4742);
													mem_vec_4742 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4743);
													mem_vec_4743 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4744);
													mem_vec_4744 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4745);
													mem_vec_4745 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4746);
													mem_vec_4746 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4747);
													mem_vec_4747 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4748);
													mem_vec_4748 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4749);
													mem_vec_4749 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4750);
													mem_vec_4750 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4751);
													mem_vec_4751 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4752);
													mem_vec_4752 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4753);
													mem_vec_4753 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4754);
													mem_vec_4754 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4755);
													mem_vec_4755 = vec_23;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4740);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4741);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4742);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4743);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4744);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4745);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4746);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4747);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4748);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4749);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4750);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4751);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4752);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4753);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4754);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4755);
									}
								}
							}
						}
					}
				}
			}
		}
		for (y457 = y458 + 192, y457_p_0 = 0;
			y457 < y458 + 192 + 80;
			y457 += 80, y457_p_0 += 80){
			// y = 16 * ph_y, x = 136, h = 3, w = 3, c = 32, f = 64
			// T (x, 136) (136 / 1)
			for (x492 = x493, x492_p_1 = x493_p_0, x492_p_0 = 0;
				x492 < x493 + 136;
				x492 += 1, x492_p_1 += 1, x492_p_0 += 1){
				// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (f, 2) (64 / 32)
				for (f = f241, fp_0 = 0;
					f < f241 + 64;
					f += 32, fp_0 += 32){
					// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
					// T (c, 2) (32 / 16)
					for (c369 = c370, c369_p_0 = 0;
						c369 < c370 + 32;
						c369 += 16, c369_p_0 += 16){
						// y = 16 * ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
						// T (y, 16) (16 * ph_y / ph_y)
						for (y = y457, yp_1 = y457_p_0, yp_0 = 0;
							y < y457 + 80;
							y += 5, yp_1 += 5, yp_0 += 5){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (x, 1) (1 / 1)
							for (x = x492, xp_2 = x492_p_1, xp_1 = x492_p_0, xp_0 = 0;
								x < x492 + 1;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h148, hp_0 = 0;
									h < h148 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
									// T (w, 3) (3 / 1)
									for (w = w231, wp_0 = 0;
										w < w231 + 3;
										w += 1, wp_0 += 1){
												mem_vec_4756 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4757 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_4758 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4759 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_4760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_4762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_4764 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4765 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_4766 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4767 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_4768 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4769 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_4770 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4771 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_4772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_4774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c369, cp_1 = c369_p_0, cp_0 = 0;
													c < c369 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_4756);
													mem_vec_4756 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_4757);
													mem_vec_4757 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_4758);
													mem_vec_4758 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_4759);
													mem_vec_4759 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_4760);
													mem_vec_4760 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_4761);
													mem_vec_4761 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_4762);
													mem_vec_4762 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_4763);
													mem_vec_4763 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_4764);
													mem_vec_4764 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_4765);
													mem_vec_4765 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_4766);
													mem_vec_4766 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_4767);
													mem_vec_4767 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_4768);
													mem_vec_4768 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_4769);
													mem_vec_4769 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_4770);
													mem_vec_4770 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_4771);
													mem_vec_4771 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_4772);
													mem_vec_4772 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_4773);
													mem_vec_4773 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_4774);
													mem_vec_4774 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_4775);
													mem_vec_4775 = vec_28;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4756);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_4757);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4758);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_4759);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4760);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_4761);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4762);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_4763);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4764);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_4765);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4766);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_4767);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4768);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_4769);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4770);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_4771);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4772);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_4773);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4774);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_4775);
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