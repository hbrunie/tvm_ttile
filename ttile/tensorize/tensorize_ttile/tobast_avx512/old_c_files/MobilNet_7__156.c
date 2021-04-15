#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (2, c); Hoist_vars [c]; T (7, x);
  T (3, h); Lambda_apply y [((Iter 2), (Arg 4)); ((Iter 1), (Arg 6))];
  T (8, f); T (64, c); T (2, f); T (4, c); T (2, x); T (1, f)]
*/
IND_TYPE c, cp_0, c772_p_0, c773_p_0, cp_1, c772_p_1, cp_2, c772, c773, f, fp_0, f632_p_0, f633_p_0, fp_1, f632_p_1, fp_2, f632, f633, h, hp_0, x, xp_0, x596_p_0, xp_1, x596, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 512));
assert((F == 512));
IND_TYPE y400 = 0;
IND_TYPE x597 = 0;
IND_TYPE h340 = 0;
IND_TYPE w = 0;
IND_TYPE c774 = 0;
IND_TYPE f634 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3836 ,mem_vec_3837 ,mem_vec_3838 ,mem_vec_3839 ,mem_vec_3840 ,mem_vec_3841 ,mem_vec_3842 ,mem_vec_3843 ,mem_vec_3844 ,mem_vec_3845 ,mem_vec_3846 ,mem_vec_3847 ,mem_vec_3848 ,mem_vec_3849 ,mem_vec_3850 ,mem_vec_3851 ,mem_vec_3852 ,mem_vec_3853 ,mem_vec_3854 ,mem_vec_3855 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
// T (f, 1) (512 / 512)
for (f633 = f634, f633_p_0 = 0;
	f633 < f634 + 512;
	f633 += 512, f633_p_0 += 512){
	// y = 14, x = 14, h = 3, w = 3, c = 512, f = 512
	// T (x, 2) (14 / 7)
	for (x596 = x597, x596_p_0 = 0;
		x596 < x597 + 14;
		x596 += 7, x596_p_0 += 7){
		// y = 14, x = 7, h = 3, w = 3, c = 512, f = 512
		// T (c, 4) (512 / 128)
		for (c773 = c774, c773_p_0 = 0;
			c773 < c774 + 512;
			c773 += 128, c773_p_0 += 128){
			// y = 14, x = 7, h = 3, w = 3, c = 128, f = 512
			// T (f, 2) (512 / 256)
			for (f632 = f633, f632_p_1 = f633_p_0, f632_p_0 = 0;
				f632 < f633 + 512;
				f632 += 256, f632_p_1 += 256, f632_p_0 += 256){
				// y = 14, x = 7, h = 3, w = 3, c = 128, f = 256
				// T (c, 64) (128 / 2)
				for (c772 = c773, c772_p_1 = c773_p_0, c772_p_0 = 0;
					c772 < c773 + 128;
					c772 += 2, c772_p_1 += 2, c772_p_0 += 2){
					// y = 14, x = 7, h = 3, w = 3, c = 2, f = 256
					// T (f, 8) (256 / 32)
					for (f = f632, fp_2 = f632_p_1, fp_1 = f632_p_0, fp_0 = 0;
						f < f632 + 256;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y400, yp_0 = 0;
								y < y400 + 8;
								y += 4, yp_0 += 4){
								// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h340, hp_0 = 0;
									h < h340 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 32
									// T (x, 7) (7 / 1)
									for (x = x596, xp_1 = x596_p_0, xp_0 = 0;
										x < x596 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3836 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3837 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c772, cp_2 = c772_p_1, cp_1 = c772_p_0, cp_0 = 0;
													c < c772 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3836);
													mem_vec_3836 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3837);
													mem_vec_3837 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3838);
													mem_vec_3838 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3839);
													mem_vec_3839 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3840);
													mem_vec_3840 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3841);
													mem_vec_3841 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3842);
													mem_vec_3842 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3843);
													mem_vec_3843 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);
													vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_3836);
													mem_vec_3836 = vec_14;

													vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_3837);
													mem_vec_3837 = vec_17;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_20 = _mm512_set1_ps(scal_5);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_16, mem_vec_3838);
													mem_vec_3838 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_18, mem_vec_3839);
													mem_vec_3839 = vec_21;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_23 = _mm512_set1_ps(scal_6);


													vec_22 = _mm512_fmadd_ps(vec_23, vec_16, mem_vec_3840);
													mem_vec_3840 = vec_22;



													vec_24 = _mm512_fmadd_ps(vec_23, vec_18, mem_vec_3841);
													mem_vec_3841 = vec_24;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_16, mem_vec_3842);
													mem_vec_3842 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_18, mem_vec_3843);
													mem_vec_3843 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);
													vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_3836);
													mem_vec_3836 = vec_28;

													vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_3837);
													mem_vec_3837 = vec_31;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_34 = _mm512_set1_ps(scal_9);


													vec_33 = _mm512_fmadd_ps(vec_34, vec_30, mem_vec_3838);
													mem_vec_3838 = vec_33;



													vec_35 = _mm512_fmadd_ps(vec_34, vec_32, mem_vec_3839);
													mem_vec_3839 = vec_35;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_37 = _mm512_set1_ps(scal_10);


													vec_36 = _mm512_fmadd_ps(vec_37, vec_30, mem_vec_3840);
													mem_vec_3840 = vec_36;



													vec_38 = _mm512_fmadd_ps(vec_37, vec_32, mem_vec_3841);
													mem_vec_3841 = vec_38;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_40 = _mm512_set1_ps(scal_11);


													vec_39 = _mm512_fmadd_ps(vec_40, vec_30, mem_vec_3842);
													mem_vec_3842 = vec_39;



													vec_41 = _mm512_fmadd_ps(vec_40, vec_32, mem_vec_3843);
													mem_vec_3843 = vec_41;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3836);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3837);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3838);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3839);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3840);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3841);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3842);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3843);
									}
								}
							}
							for (y = y400 + 8, yp_0 = 0;
								y < y400 + 8 + 6;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 7, h = 3, w = 3, c = 2, f = 32
								// T (h, 3) (3 / 1)
								for (h = h340, hp_0 = 0;
									h < h340 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 7, h = 1, w = 3, c = 2, f = 32
									// T (x, 7) (7 / 1)
									for (x = x596, xp_1 = x596_p_0, xp_0 = 0;
										x < x596 + 7;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_3844 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_3845 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_3846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_3847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_3848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_3849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_3850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_3851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_3852 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_3853 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_3854 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_3855 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 2, f = 32
												// T (c, 2) (2 / 1)
												for (c = c772, cp_2 = c772_p_1, cp_1 = c772_p_0, cp_0 = 0;
													c < c772 + 2;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3844);
													mem_vec_3844 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3845);
													mem_vec_3845 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3846);
													mem_vec_3846 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3847);
													mem_vec_3847 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3848);
													mem_vec_3848 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3849);
													mem_vec_3849 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3850);
													mem_vec_3850 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3851);
													mem_vec_3851 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3852);
													mem_vec_3852 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3853);
													mem_vec_3853 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3854);
													mem_vec_3854 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3855);
													mem_vec_3855 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_3844);
													mem_vec_3844 = vec_20;

													vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_3845);
													mem_vec_3845 = vec_23;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_3846);
													mem_vec_3846 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_3847);
													mem_vec_3847 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);


													vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_3848);
													mem_vec_3848 = vec_28;



													vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_3849);
													mem_vec_3849 = vec_30;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_3850);
													mem_vec_3850 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_3851);
													mem_vec_3851 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_3852);
													mem_vec_3852 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_3853);
													mem_vec_3853 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_3854);
													mem_vec_3854 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_3855);
													mem_vec_3855 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);
													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_3844);
													mem_vec_3844 = vec_40;

													vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_3845);
													mem_vec_3845 = vec_43;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);


													vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_3846);
													mem_vec_3846 = vec_45;



													vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_3847);
													mem_vec_3847 = vec_47;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_3848);
													mem_vec_3848 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_3849);
													mem_vec_3849 = vec_50;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_52 = _mm512_set1_ps(scal_15);


													vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_3850);
													mem_vec_3850 = vec_51;



													vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_3851);
													mem_vec_3851 = vec_53;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_55 = _mm512_set1_ps(scal_16);


													vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_3852);
													mem_vec_3852 = vec_54;



													vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_3853);
													mem_vec_3853 = vec_56;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_58 = _mm512_set1_ps(scal_17);


													vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_3854);
													mem_vec_3854 = vec_57;



													vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_3855);
													mem_vec_3855 = vec_59;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3844);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3845);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3846);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3847);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3848);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3849);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3850);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3851);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3852);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3853);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3854);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3855);
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