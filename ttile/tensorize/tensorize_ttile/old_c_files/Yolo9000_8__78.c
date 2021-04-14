#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (34, x); T (3, w);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 4), (Arg 15))];
  T (1, f); T (1, c); T (1, f); T (2, x); T (8, f)]
*/
IND_TYPE c, cp_0, c516_p_0, cp_1, c516, f, fp_0, f688_p_0, f689_p_0, fp_1, f688_p_1, fp_2, f688, f689, h, hp_0, w, wp_0, x, xp_0, x568_p_0, xp_1, x568, y, yp_0;

assert((Y == 68));
assert((X == 68));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 256));
IND_TYPE y344 = 0;
IND_TYPE x569 = 0;
IND_TYPE h344 = 0;
IND_TYPE w292 = 0;
IND_TYPE c517 = 0;
IND_TYPE f690 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_5792 ,mem_vec_5793 ,mem_vec_5794 ,mem_vec_5795 ,mem_vec_5796 ,mem_vec_5797 ,mem_vec_5798 ,mem_vec_5799 ,mem_vec_5800 ,mem_vec_5801 ,mem_vec_5802 ,mem_vec_5803 ,mem_vec_5804 ,mem_vec_5805 ,mem_vec_5806 ,mem_vec_5807 ,mem_vec_5808 ,mem_vec_5809 ,mem_vec_5810 ,mem_vec_5811 ,mem_vec_5812 ,mem_vec_5813 ,mem_vec_5814 ,mem_vec_5815 ,mem_vec_5816 ,mem_vec_5817 ,mem_vec_5818 ,mem_vec_5819 ,mem_vec_5820 ,mem_vec_5821 ,mem_vec_5822 ,mem_vec_5823 ,mem_vec_5824 ,mem_vec_5825 ,mem_vec_5826 ,mem_vec_5827 ,mem_vec_5828 ,mem_vec_5829 ,mem_vec_5830 ,mem_vec_5831 ,mem_vec_5832 ,mem_vec_5833 ,mem_vec_5834 ,mem_vec_5835 ,mem_vec_5836 ,mem_vec_5837 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 3, w = 3, c = 128, f = 256
// T (f, 8) (256 / 32)
for (f689 = f690, f689_p_0 = 0;
	f689 < f690 + 256;
	f689 += 32, f689_p_0 += 32){
	// y = 68, x = 68, h = 3, w = 3, c = 128, f = 32
	// T (x, 2) (68 / 34)
	for (x568 = x569, x568_p_0 = 0;
		x568 < x569 + 68;
		x568 += 34, x568_p_0 += 34){
		// y = 68, x = 34, h = 3, w = 3, c = 128, f = 32
		// T (f, 1) (32 / 32)
		for (f688 = f689, f688_p_1 = f689_p_0, f688_p_0 = 0;
			f688 < f689 + 32;
			f688 += 32, f688_p_1 += 32, f688_p_0 += 32){
			// y = 68, x = 34, h = 3, w = 3, c = 128, f = 32
			// T (c, 1) (128 / 128)
			for (c516 = c517, c516_p_0 = 0;
				c516 < c517 + 128;
				c516 += 128, c516_p_0 += 128){
				// y = 68, x = 34, h = 3, w = 3, c = 128, f = 32
				// T (f, 1) (32 / 32)
				for (f = f688, fp_2 = f688_p_1, fp_1 = f688_p_0, fp_0 = 0;
					f < f688 + 32;
					f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
						for (y = y344, yp_0 = 0;
							y < y344 + 8;
							y += 8, yp_0 += 8){
							// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h344, hp_0 = 0;
								h < h344 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 128, f = 32
								// T (w, 3) (3 / 1)
								for (w = w292, wp_0 = 0;
									w < w292 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 128, f = 32
									// T (x, 34) (34 / 1)
									for (x = x568, xp_1 = x568_p_0, xp_0 = 0;
										x < x568 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5792 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5793 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
													c < c516 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5792);
													mem_vec_5792 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5793);
													mem_vec_5793 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5794);
													mem_vec_5794 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5795);
													mem_vec_5795 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5796);
													mem_vec_5796 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5797);
													mem_vec_5797 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5798);
													mem_vec_5798 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5799);
													mem_vec_5799 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5800);
													mem_vec_5800 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5801);
													mem_vec_5801 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5802);
													mem_vec_5802 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5803);
													mem_vec_5803 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5804);
													mem_vec_5804 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5805);
													mem_vec_5805 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5806);
													mem_vec_5806 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5807);
													mem_vec_5807 = vec_25;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5792);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5793);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5794);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5795);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5796);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5797);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5798);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5799);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5800);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5801);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5802);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5803);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5804);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5805);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5806);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5807);
									}
								}
							}
						}
						for (y = y344 + 8, yp_0 = 0;
							y < y344 + 8 + 60;
							y += 15, yp_0 += 15){
							// y = ph_y, x = 34, h = 3, w = 3, c = 128, f = 32
							// T (h, 3) (3 / 1)
							for (h = h344, hp_0 = 0;
								h < h344 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 34, h = 1, w = 3, c = 128, f = 32
								// T (w, 3) (3 / 1)
								for (w = w292, wp_0 = 0;
									w < w292 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 34, h = 1, w = 1, c = 128, f = 32
									// T (x, 34) (34 / 1)
									for (x = x568, xp_1 = x568_p_0, xp_0 = 0;
										x < x568 + 34;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_5808 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_5809 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_5810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_5811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_5812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_5813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_5814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_5815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_5816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_5817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_5818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_5819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_5820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_5821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_5822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_5823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_5824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_5825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_5826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_5827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_5828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_5829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_5830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_5831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												mem_vec_5832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
												mem_vec_5833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
												mem_vec_5834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
												mem_vec_5835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
												mem_vec_5836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f]);
												mem_vec_5837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
												// T (c, 128) (128 / 1)
												for (c = c516, cp_1 = c516_p_0, cp_0 = 0;
													c < c516 + 128;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_5808);
													mem_vec_5808 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_5809);
													mem_vec_5809 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_5810);
													mem_vec_5810 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_5811);
													mem_vec_5811 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_5812);
													mem_vec_5812 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_5813);
													mem_vec_5813 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_5814);
													mem_vec_5814 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_5815);
													mem_vec_5815 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_5816);
													mem_vec_5816 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_5817);
													mem_vec_5817 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_5818);
													mem_vec_5818 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_5819);
													mem_vec_5819 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_5820);
													mem_vec_5820 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_5821);
													mem_vec_5821 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_5822);
													mem_vec_5822 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_5823);
													mem_vec_5823 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_5824);
													mem_vec_5824 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_5825);
													mem_vec_5825 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_5826);
													mem_vec_5826 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_5827);
													mem_vec_5827 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_5828);
													mem_vec_5828 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_5829);
													mem_vec_5829 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_5830);
													mem_vec_5830 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_5831);
													mem_vec_5831 = vec_37;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
													vec_39 = _mm512_set1_ps(scal_12);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_5832);
													mem_vec_5832 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_5833);
													mem_vec_5833 = vec_40;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
													vec_42 = _mm512_set1_ps(scal_13);


													vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_5834);
													mem_vec_5834 = vec_41;



													vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_5835);
													mem_vec_5835 = vec_43;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 14 + h) + c];
													vec_45 = _mm512_set1_ps(scal_14);


													vec_44 = _mm512_fmadd_ps(vec_45, vec_2, mem_vec_5836);
													mem_vec_5836 = vec_44;



													vec_46 = _mm512_fmadd_ps(vec_45, vec_4, mem_vec_5837);
													mem_vec_5837 = vec_46;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_5808);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_5809);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_5810);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_5811);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_5812);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_5813);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_5814);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_5815);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_5816);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_5817);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_5818);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_5819);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_5820);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_5821);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_5822);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_5823);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_5824);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_5825);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_5826);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_5827);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_5828);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_5829);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_5830);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_5831);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_5832);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_5833);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_5834);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_5835);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f], mem_vec_5836);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 14) + f + 16], mem_vec_5837);
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