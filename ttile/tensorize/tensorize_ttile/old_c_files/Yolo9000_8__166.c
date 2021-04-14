#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (68, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 5), (Arg 11)); ((Iter 1), (Arg 13))];
  T (1, f); T (1, c); T (8, f); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c786_p_0, cp_1, c786, f, fp_0, f1048_p_0, f1049_p_0, fp_1, f1048_p_1, fp_2, f1048, f1049, h, hp_0, w, wp_0, x, xp_0, x838_p_0, xp_1, x838, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y524 = 0;
IND_TYPE x839 = 0;
IND_TYPE h524 = 0;
IND_TYPE w472 = 0;
IND_TYPE c787 = 0;
IND_TYPE f1050 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9660 ,mem_vec_9661 ,mem_vec_9662 ,mem_vec_9663 ,mem_vec_9664 ,mem_vec_9665 ,mem_vec_9666 ,mem_vec_9667 ,mem_vec_9668 ,mem_vec_9669 ,mem_vec_9670 ,mem_vec_9671 ,mem_vec_9672 ,mem_vec_9673 ,mem_vec_9674 ,mem_vec_9675 ,mem_vec_9676 ,mem_vec_9677 ,mem_vec_9678 ,mem_vec_9679 ,mem_vec_9680 ,mem_vec_9681 ,mem_vec_9682 ,mem_vec_9683 ,mem_vec_9684 ,mem_vec_9685 ,mem_vec_9686 ,mem_vec_9687 ,mem_vec_9688 ,mem_vec_9689 ,mem_vec_9690 ,mem_vec_9691 ,mem_vec_9692 ,mem_vec_9693 ,mem_vec_9694 ,mem_vec_9695 ,mem_vec_9696 ,mem_vec_9697 ,mem_vec_9698 ,mem_vec_9699 ,mem_vec_9700 ,mem_vec_9701 ,mem_vec_9702 ,mem_vec_9703 ,mem_vec_9704 ,mem_vec_9705 ,mem_vec_9706 ,mem_vec_9707 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 1) (256 / 256)
for (f1049 = f1050, f1049_p_0 = 0;
	f1049 < f1050 + 256;
	f1049 += 256, f1049_p_0 += 256){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
	// T (x, 1) (68 / 68)
	for (x838 = x839, x838_p_0 = 0;
		x838 < x839 + 68;
		x838 += 68, x838_p_0 += 68){
		// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
		// T (f, 8) (256 / 32)
		for (f1048 = f1049, f1048_p_1 = f1049_p_0, f1048_p_0 = 0;
			f1048 < f1049 + 256;
			f1048 += 32, f1048_p_1 += 32, f1048_p_0 += 32){
			// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
			// T (c, 1) (128 / 128)
			for (c786 = c787, c786_p_0 = 0;
				c786 < c787 + 128;
				c786 += 128, c786_p_0 += 128){
				// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
				// T (f, 1) (32 / 32)
				for (f = f1048, fp_2 = f1048_p_1, fp_1 = f1048_p_0, fp_0 = 0;
					f < f1048 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y524, yp_0 = 0;
							y < y524 + 55;
							y += 11, yp_0 += 11){
							// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h524, hp_0 = 0;
								h < h524 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 68, h = 1, w = 3, c = 128, f = 32
								// T (w, 3) (3 / 1)
								for (w = w472, wp_0 = 0;
									w < w472 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 68, h = 1, w = 1, c = 128, f = 32
									// T (x, 68) (68 / 1)
									for (x = x838, xp_1 = x838_p_0, xp_0 = 0;
										x < x838 + 68;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9660 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9661 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c786, cp_1 = c786_p_0, cp_0 = 0;
													c < c786 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9660);
													mem_vec_9660 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9661);
													mem_vec_9661 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9662);
													mem_vec_9662 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9663);
													mem_vec_9663 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9664);
													mem_vec_9664 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9665);
													mem_vec_9665 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9666);
													mem_vec_9666 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9667);
													mem_vec_9667 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9668);
													mem_vec_9668 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9669);
													mem_vec_9669 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9670);
													mem_vec_9670 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9671);
													mem_vec_9671 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9672);
													mem_vec_9672 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9673);
													mem_vec_9673 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9674);
													mem_vec_9674 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9675);
													mem_vec_9675 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9676);
													mem_vec_9676 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9677);
													mem_vec_9677 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9678);
													mem_vec_9678 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9679);
													mem_vec_9679 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9680);
													mem_vec_9680 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9681);
													mem_vec_9681 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9660);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9661);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9662);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9663);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9664);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9665);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9666);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9667);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9668);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9669);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9670);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9671);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9672);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9673);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9674);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9675);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9676);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9677);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9678);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9679);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9680);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9681);
									}
								}
							}
						}
						for (y = y524 + 55, yp_0 = 0;
							y < y524 + 55 + 13;
							y += 13, yp_0 += 13){
							// y = ph_y, x = 68, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h524, hp_0 = 0;
								h < h524 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 68, h = 1, w = 3, c = 128, f = 32
								// T (w, 3) (3 / 1)
								for (w = w472, wp_0 = 0;
									w < w472 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 68, h = 1, w = 1, c = 128, f = 32
									// T (x, 68) (68 / 1)
									for (x = x838, xp_1 = x838_p_0, xp_0 = 0;
										x < x838 + 68;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9682 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9683 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_9695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_9696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_9697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_9698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_9699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_9700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_9701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_9702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_9703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_9704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_9705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_9706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_9707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c786, cp_1 = c786_p_0, cp_0 = 0;
													c < c786 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9682);
													mem_vec_9682 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9683);
													mem_vec_9683 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_9684);
													mem_vec_9684 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_9685);
													mem_vec_9685 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_9686);
													mem_vec_9686 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_9687);
													mem_vec_9687 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_9688);
													mem_vec_9688 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_9689);
													mem_vec_9689 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9690);
													mem_vec_9690 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9691);
													mem_vec_9691 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_9692);
													mem_vec_9692 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_9693);
													mem_vec_9693 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_9694);
													mem_vec_9694 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_9695);
													mem_vec_9695 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_9696);
													mem_vec_9696 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_9697);
													mem_vec_9697 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_9698);
													mem_vec_9698 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_9699);
													mem_vec_9699 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9700);
													mem_vec_9700 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9701);
													mem_vec_9701 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_9702);
													mem_vec_9702 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_9703);
													mem_vec_9703 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_9704);
													mem_vec_9704 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_9705);
													mem_vec_9705 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_9706);
													mem_vec_9706 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_9707);
													mem_vec_9707 = vec_40;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9682);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9683);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9684);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9685);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9686);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9687);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9688);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9689);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9690);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9691);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9692);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9693);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_9694);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_9695);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_9696);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_9697);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_9698);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_9699);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_9700);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_9701);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_9702);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_9703);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_9704);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_9705);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_9706);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_9707);
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