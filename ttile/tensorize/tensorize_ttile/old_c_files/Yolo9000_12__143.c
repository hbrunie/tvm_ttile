#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (1, x); T (3, w);
  T (3, h); T (4, f); T (34, x);
  Lambda_apply y [((Iter 2), (Arg 11)); ((Iter 1), (Arg 12))]; T (4, f);
  T (16, c); T (1, f)]
*/
IND_TYPE c, cp_0, c468_p_0, cp_1, c468, f, fp_0, f624_p_0, f625_p_0, fp_1, f624_p_1, fp_2, f624, f625, h, hp_0, w, wp_0, x, xp_0, x468_p_0, xp_1, x468, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y312 = 0;
IND_TYPE x469 = 0;
IND_TYPE h312 = 0;
IND_TYPE w312 = 0;
IND_TYPE c469 = 0;
IND_TYPE f626 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6792 ,mem_vec_6793 ,mem_vec_6794 ,mem_vec_6795 ,mem_vec_6796 ,mem_vec_6797 ,mem_vec_6798 ,mem_vec_6799 ,mem_vec_6800 ,mem_vec_6801 ,mem_vec_6802 ,mem_vec_6803 ,mem_vec_6804 ,mem_vec_6805 ,mem_vec_6806 ,mem_vec_6807 ,mem_vec_6808 ,mem_vec_6809 ,mem_vec_6810 ,mem_vec_6811 ,mem_vec_6812 ,mem_vec_6813 ,mem_vec_6814 ,mem_vec_6815 ,mem_vec_6816 ,mem_vec_6817 ,mem_vec_6818 ,mem_vec_6819 ,mem_vec_6820 ,mem_vec_6821 ,mem_vec_6822 ,mem_vec_6823 ,mem_vec_6824 ,mem_vec_6825 ,mem_vec_6826 ,mem_vec_6827 ,mem_vec_6828 ,mem_vec_6829 ,mem_vec_6830 ,mem_vec_6831 ,mem_vec_6832 ,mem_vec_6833 ,mem_vec_6834 ,mem_vec_6835 ,mem_vec_6836 ,mem_vec_6837 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (f, 1) (512 / 512)
for (f625 = f626, f625_p_0 = 0;
	f625 < f626 + 512;
	f625 += 512, f625_p_0 += 512){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (c, 16) (256 / 16)
	for (c468 = c469, c468_p_0 = 0;
		c468 < c469 + 256;
		c468 += 16, c468_p_0 += 16){
		// y = 34, x = 34, h = 3, w = 3, c = 16, f = 512
		// T (f, 4) (512 / 128)
		for (f624 = f625, f624_p_1 = f625_p_0, f624_p_0 = 0;
			f624 < f625 + 512;
			f624 += 128, f624_p_1 += 128, f624_p_0 += 128){
				for (y = y312, yp_0 = 0;
					y < y312 + 22;
					y += 11, yp_0 += 11){
					// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 128
					// T (x, 34) (34 / 1)
					for (x468 = x469, x468_p_0 = 0;
						x468 < x469 + 34;
						x468 += 1, x468_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 128
						// T (f, 4) (128 / 32)
						for (f = f624, fp_2 = f624_p_1, fp_1 = f624_p_0, fp_0 = 0;
							f < f624 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h312, hp_0 = 0;
								h < h312 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w312, wp_0 = 0;
									w < w312 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (x, 1) (1 / 1)
									for (x = x468, xp_1 = x468_p_0, xp_0 = 0;
										x < x468 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6792 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6793 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c468, cp_1 = c468_p_0, cp_0 = 0;
													c < c468 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6792);
													mem_vec_6792 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6793);
													mem_vec_6793 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6794);
													mem_vec_6794 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6795);
													mem_vec_6795 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6796);
													mem_vec_6796 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6797);
													mem_vec_6797 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6798);
													mem_vec_6798 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6799);
													mem_vec_6799 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6800);
													mem_vec_6800 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6801);
													mem_vec_6801 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6802);
													mem_vec_6802 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6803);
													mem_vec_6803 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6804);
													mem_vec_6804 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6805);
													mem_vec_6805 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6806);
													mem_vec_6806 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6807);
													mem_vec_6807 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6808);
													mem_vec_6808 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6809);
													mem_vec_6809 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6810);
													mem_vec_6810 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6811);
													mem_vec_6811 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6812);
													mem_vec_6812 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6813);
													mem_vec_6813 = vec_34;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6792);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6793);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6794);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6795);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6796);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6797);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6798);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6799);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6800);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6801);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6802);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6803);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6804);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6805);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6806);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6807);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6808);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6809);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6810);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6811);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6812);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6813);
									}
								}
							}
						}
					}
				}
				for (y = y312 + 22, yp_0 = 0;
					y < y312 + 22 + 12;
					y += 12, yp_0 += 12){
					// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 128
					// T (x, 34) (34 / 1)
					for (x468 = x469, x468_p_0 = 0;
						x468 < x469 + 34;
						x468 += 1, x468_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 128
						// T (f, 4) (128 / 32)
						for (f = f624, fp_2 = f624_p_1, fp_1 = f624_p_0, fp_0 = 0;
							f < f624 + 128;
							f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h312, hp_0 = 0;
								h < h312 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w312, wp_0 = 0;
									w < w312 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
									// T (x, 1) (1 / 1)
									for (x = x468, xp_1 = x468_p_0, xp_0 = 0;
										x < x468 + 1;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6814 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6815 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												mem_vec_6830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_6831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
												mem_vec_6832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_6833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
												mem_vec_6834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
												mem_vec_6835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
												mem_vec_6836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
												mem_vec_6837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
												// T (c, 16) (16 / 1)
												for (c = c468, cp_1 = c468_p_0, cp_0 = 0;
													c < c468 + 16;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6814);
													mem_vec_6814 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6815);
													mem_vec_6815 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6816);
													mem_vec_6816 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6817);
													mem_vec_6817 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6818);
													mem_vec_6818 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6819);
													mem_vec_6819 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6820);
													mem_vec_6820 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6821);
													mem_vec_6821 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6822);
													mem_vec_6822 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6823);
													mem_vec_6823 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6824);
													mem_vec_6824 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6825);
													mem_vec_6825 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6826);
													mem_vec_6826 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6827);
													mem_vec_6827 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6828);
													mem_vec_6828 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6829);
													mem_vec_6829 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);


													vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_6830);
													mem_vec_6830 = vec_26;



													vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_6831);
													mem_vec_6831 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm512_set1_ps(scal_9);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_6832);
													mem_vec_6832 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_6833);
													mem_vec_6833 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
													vec_33 = _mm512_set1_ps(scal_10);


													vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_6834);
													mem_vec_6834 = vec_32;



													vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_6835);
													mem_vec_6835 = vec_34;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
													vec_36 = _mm512_set1_ps(scal_11);


													vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_6836);
													mem_vec_6836 = vec_35;



													vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_6837);
													mem_vec_6837 = vec_37;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6814);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6815);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6816);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6817);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6818);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6819);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6820);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6821);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6822);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6823);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6824);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6825);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6826);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6827);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6828);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6829);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_6830);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_6831);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_6832);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_6833);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_6834);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_6835);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_6836);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_6837);
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