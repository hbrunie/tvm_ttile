#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (1, c); Hoist_vars [c]; T (14, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 2), (Arg 5))];
  T (4, f); T (64, c); T (1, f); T (8, c); T (1, x); T (4, f)]
*/
IND_TYPE c, cp_0, c556_p_0, c557_p_0, cp_1, c556_p_1, cp_2, c556, c557, f, fp_0, f416_p_0, f417_p_0, fp_1, f416_p_1, fp_2, f416, f417, h, hp_0, x, xp_0, x434_p_0, xp_1, x434, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y292 = 0;
IND_TYPE x435 = 0;
IND_TYPE h232 = 0;
IND_TYPE w = 0;
IND_TYPE c558 = 0;
IND_TYPE f418 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_2828 ,mem_vec_2829 ,mem_vec_2830 ,mem_vec_2831 ,mem_vec_2832 ,mem_vec_2833 ,mem_vec_2834 ,mem_vec_2835 ,mem_vec_2836 ,mem_vec_2837 ,mem_vec_2838 ,mem_vec_2839 ,mem_vec_2840 ,mem_vec_2841 ,mem_vec_2842 ,mem_vec_2843 ,mem_vec_2844 ,mem_vec_2845 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 4) (512 / 128)
for (f417 = f418, f417_p_0 = 0;
	f417 < f418 + 512;
	f417 += 128, f417_p_0 += 128){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 128
	// T (x, 1) (14 / 14)
	for (x434 = x435, x434_p_0 = 0;
		x434 < x435 + 14;
		x434 += 14, x434_p_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 512, f = 128
		// T (c, 8) (512 / 64)
		for (c557 = c558, c557_p_0 = 0;
			c557 < c558 + 512;
			c557 += 64, c557_p_0 += 64){
			// y = 14, x = 14, h = 3, w = 3, c = 64, f = 128
			// T (f, 1) (128 / 128)
			for (f416 = f417, f416_p_1 = f417_p_0, f416_p_0 = 0;
				f416 < f417 + 128;
				f416 += 128, f416_p_1 += 128, f416_p_0 += 128){
				// y = 14, x = 14, h = 3, w = 3, c = 64, f = 128
				// T (c, 64) (64 / 1)
				for (c556 = c557, c556_p_1 = c557_p_0, c556_p_0 = 0;
					c556 < c557 + 64;
					c556 += 1, c556_p_1 += 1, c556_p_0 += 1){
					// y = 14, x = 14, h = 3, w = 3, c = 1, f = 128
					// T (f, 4) (128 / 32)
					for (f = f416, fp_2 = f416_p_1, fp_1 = f416_p_0, fp_0 = 0;
						f < f416 + 128;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y292, yp_0 = 0;
								y < y292 + 4;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h232, hp_0 = 0;
									h < h232 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 1, f = 32
									// T (x, 14) (14 / 1)
									for (x = x434, xp_1 = x434_p_0, xp_0 = 0;
										x < x434 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2828 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2829 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c556, cp_2 = c556_p_1, cp_1 = c556_p_0, cp_0 = 0;
													c < c556 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2828);
													mem_vec_2828 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2829);
													mem_vec_2829 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2830);
													mem_vec_2830 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2831);
													mem_vec_2831 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2832);
													mem_vec_2832 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2833);
													mem_vec_2833 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2834);
													mem_vec_2834 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2835);
													mem_vec_2835 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_2828);
													mem_vec_2828 = vec_14;

													vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_2829);
													mem_vec_2829 = vec_17;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_20 = _mm512_set1_ps(scal_5);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_2830);
													mem_vec_2830 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_2831);
													mem_vec_2831 = vec_21;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_2832);
													mem_vec_2832 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_2833);
													mem_vec_2833 = vec_24;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_2834);
													mem_vec_2834 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_2835);
													mem_vec_2835 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_2828);
													mem_vec_2828 = vec_28;

													vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_2829);
													mem_vec_2829 = vec_31;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_34 = _mm512_set1_ps(scal_9);


													vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_2830);
													mem_vec_2830 = vec_33;



													vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_2831);
													mem_vec_2831 = vec_35;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_37 = _mm512_set1_ps(scal_10);


													vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_2832);
													mem_vec_2832 = vec_36;



													vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_2833);
													mem_vec_2833 = vec_38;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_2834);
													mem_vec_2834 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_2835);
													mem_vec_2835 = vec_41;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2828);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2829);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2830);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2831);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2832);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2833);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2834);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2835);
									}
								}
							}
							for (y = y292 + 4, yp_0 = 0;
								y < y292 + 4 + 10;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 14, h = 3, w = 3, c = 1, f = 32
								// T (h, 3) (3 / 1)
								for (h = h232, hp_0 = 0;
									h < h232 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 1, f = 32
									// T (x, 14) (14 / 1)
									for (x = x434, xp_1 = x434_p_0, xp_0 = 0;
										x < x434 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_2836 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_2837 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_2838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_2839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_2840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_2841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_2842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_2843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_2844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_2845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 1, f = 32
												// T (c, 1) (1 / 1)
												for (c = c556, cp_2 = c556_p_1, cp_1 = c556_p_0, cp_0 = 0;
													c < c556 + 1;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_2836);
													mem_vec_2836 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_2837);
													mem_vec_2837 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_2838);
													mem_vec_2838 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_2839);
													mem_vec_2839 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_2840);
													mem_vec_2840 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_2841);
													mem_vec_2841 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_2842);
													mem_vec_2842 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_2843);
													mem_vec_2843 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_2844);
													mem_vec_2844 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_2845);
													mem_vec_2845 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);
													vec_19 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_17 = _mm512_fmadd_ps(vec_18, vec_19, mem_vec_2836);
													mem_vec_2836 = vec_17;

													vec_21 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_20 = _mm512_fmadd_ps(vec_18, vec_21, mem_vec_2837);
													mem_vec_2837 = vec_20;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_19, mem_vec_2838);
													mem_vec_2838 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_21, mem_vec_2839);
													mem_vec_2839 = vec_24;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_19, mem_vec_2840);
													mem_vec_2840 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_21, mem_vec_2841);
													mem_vec_2841 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);


													vec_28 = _mm512_fmadd_ps(vec_29, vec_19, mem_vec_2842);
													mem_vec_2842 = vec_28;



													vec_30 = _mm512_fmadd_ps(vec_29, vec_21, mem_vec_2843);
													mem_vec_2843 = vec_30;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_19, mem_vec_2844);
													mem_vec_2844 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_21, mem_vec_2845);
													mem_vec_2845 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);
													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_2836);
													mem_vec_2836 = vec_34;

													vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_2837);
													mem_vec_2837 = vec_37;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_36, mem_vec_2838);
													mem_vec_2838 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_38, mem_vec_2839);
													mem_vec_2839 = vec_41;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_43 = _mm512_set1_ps(scal_12);


													vec_42 = _mm512_fmadd_ps(vec_43, vec_36, mem_vec_2840);
													mem_vec_2840 = vec_42;



													vec_44 = _mm512_fmadd_ps(vec_43, vec_38, mem_vec_2841);
													mem_vec_2841 = vec_44;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);


													vec_45 = _mm512_fmadd_ps(vec_46, vec_36, mem_vec_2842);
													mem_vec_2842 = vec_45;



													vec_47 = _mm512_fmadd_ps(vec_46, vec_38, mem_vec_2843);
													mem_vec_2843 = vec_47;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_2844);
													mem_vec_2844 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_2845);
													mem_vec_2845 = vec_50;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_2836);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_2837);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_2838);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_2839);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_2840);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_2841);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_2842);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_2843);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_2844);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_2845);
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