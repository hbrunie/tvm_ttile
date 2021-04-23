#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (17, x);
  T (3, w); T (8, c); T (1, f);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 4), (Arg 11))]; T (4, x);
  T (1, f); T (8, f)]
*/
IND_TYPE c, cp_0, c375_p_0, cp_1, c375, f, fp_0, f494_p_0, f495_p_0, fp_1, f494_p_1, fp_2, f494, f495, h, hp_0, w, wp_0, x, xp_0, x375_p_0, xp_1, x375, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y253 = 0;
IND_TYPE x376 = 0;
IND_TYPE h247 = 0;
IND_TYPE w227 = 0;
IND_TYPE c376 = 0;
IND_TYPE f496 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_4750 ,mem_vec_4751 ,mem_vec_4752 ,mem_vec_4753 ,mem_vec_4754 ,mem_vec_4755 ,mem_vec_4756 ,mem_vec_4757 ,mem_vec_4758 ,mem_vec_4759 ,mem_vec_4760 ,mem_vec_4761 ,mem_vec_4762 ,mem_vec_4763 ,mem_vec_4764 ,mem_vec_4765 ,mem_vec_4766 ,mem_vec_4767 ,mem_vec_4768 ,mem_vec_4769 ,mem_vec_4770 ,mem_vec_4771 ,mem_vec_4772 ,mem_vec_4773 ,mem_vec_4774 ,mem_vec_4775 ,mem_vec_4776 ,mem_vec_4777 ,mem_vec_4778 ,mem_vec_4779 ,mem_vec_4780 ,mem_vec_4781 ,mem_vec_4782 ,mem_vec_4783 ,mem_vec_4784 ,mem_vec_4785 ,mem_vec_4786 ,mem_vec_4787 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f495 = f496, f495_p_0 = 0;
	f495 < f496 + 256;
	f495 += 32, f495_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (f, 1) (32 / 32)
	for (f494 = f495, f494_p_1 = f495_p_0, f494_p_0 = 0;
		f494 < f495 + 32;
		f494 += 32, f494_p_1 += 32, f494_p_0 += 32){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
		// T (x, 4) (68 / 17)
		for (x375 = x376, x375_p_0 = 0;
			x375 < x376 + 68;
			x375 += 17, x375_p_0 += 17){
				for (y = y253, yp_0 = 0;
					y < y253 + 24;
					y += 8, yp_0 += 8){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f494, fp_2 = f494_p_1, fp_1 = f494_p_0, fp_0 = 0;
						f < f494 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c375 = c376, c375_p_0 = 0;
							c375 < c376 + 128;
							c375 += 16, c375_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w227, wp_0 = 0;
								w < w227 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x375, xp_1 = x375_p_0, xp_0 = 0;
									x < x375 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h247, hp_0 = 0;
										h < h247 + 3;
										h += 1, hp_0 += 1){
												mem_vec_4750 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4751 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_4761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_4762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_4763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_4764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_4765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c375, cp_1 = c375_p_0, cp_0 = 0;
													c < c375 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4750);
													mem_vec_4750 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4751);
													mem_vec_4751 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4752);
													mem_vec_4752 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4753);
													mem_vec_4753 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4754);
													mem_vec_4754 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4755);
													mem_vec_4755 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4756);
													mem_vec_4756 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4757);
													mem_vec_4757 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4758);
													mem_vec_4758 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4759);
													mem_vec_4759 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4760);
													mem_vec_4760 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4761);
													mem_vec_4761 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4762);
													mem_vec_4762 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4763);
													mem_vec_4763 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4764);
													mem_vec_4764 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4765);
													mem_vec_4765 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4750);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4751);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4752);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4753);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4754);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4755);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4756);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4757);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4758);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4759);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4760);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4761);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4762);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4763);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4764);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4765);
									}
								}
							}
						}
					}
				}
				for (y = y253 + 24, yp_0 = 0;
					y < y253 + 24 + 44;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
					// T (f, 1) (32 / 32)
					for (f = f494, fp_2 = f494_p_1, fp_1 = f494_p_0, fp_0 = 0;
						f < f494 + 32;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						// y = ph_y, x = 17, h = 3, w = 3, c = 128, f = 32
						// T (c, 8) (128 / 16)
						for (c375 = c376, c375_p_0 = 0;
							c375 < c376 + 128;
							c375 += 16, c375_p_0 += 16){
							// y = ph_y, x = 17, h = 3, w = 3, c = 16, f = 32
							// T (w, 3) (3 / 1)
							for (w = w227, wp_0 = 0;
								w < w227 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 17, h = 3, w = 1, c = 16, f = 32
								// T (x, 17) (17 / 1)
								for (x = x375, xp_1 = x375_p_0, xp_0 = 0;
									x < x375 + 17;
									x += 1, xp_1 += 1, xp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
									// T (h, 3) (3 / 1)
									for (h = h247, hp_0 = 0;
										h < h247 + 3;
										h += 1, hp_0 += 1){
												mem_vec_4766 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_4767 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_4768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_4769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_4770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_4771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_4772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_4773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_4774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_4775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_4776 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_4777 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_4778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_4779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_4780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_4781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_4782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_4783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_4784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_4785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_4786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_4787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c375, cp_1 = c375_p_0, cp_0 = 0;
													c < c375 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4766);
													mem_vec_4766 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4767);
													mem_vec_4767 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_4768);
													mem_vec_4768 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_4769);
													mem_vec_4769 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_4770);
													mem_vec_4770 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_4771);
													mem_vec_4771 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_4772);
													mem_vec_4772 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_4773);
													mem_vec_4773 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4774);
													mem_vec_4774 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4775);
													mem_vec_4775 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_4776);
													mem_vec_4776 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_4777);
													mem_vec_4777 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_4778);
													mem_vec_4778 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_4779);
													mem_vec_4779 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_4780);
													mem_vec_4780 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_4781);
													mem_vec_4781 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_4782);
													mem_vec_4782 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_4783);
													mem_vec_4783 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4784);
													mem_vec_4784 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4785);
													mem_vec_4785 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_4786);
													mem_vec_4786 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_4787);
													mem_vec_4787 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4766);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4767);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4768);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4769);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4770);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4771);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4772);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4773);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4774);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4775);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4776);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4777);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4778);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4779);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_4780);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_4781);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_4782);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_4783);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_4784);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_4785);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_4786);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_4787);
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