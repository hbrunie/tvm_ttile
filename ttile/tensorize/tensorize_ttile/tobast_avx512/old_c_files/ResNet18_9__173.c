#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, w); T (8, c); Hoist_vars [c]; T (14, x);
  T (3, h); Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 1), (Arg 8))];
  T (8, f); T (16, c); T (1, f); T (2, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1158_p_0, c1159_p_0, cp_1, c1158_p_1, cp_2, c1158, c1159, f, fp_0, f1150_p_0, f1151_p_0, fp_1, f1150_p_1, fp_2, f1150, f1151, h, hp_0, x, xp_0, x934_p_0, xp_1, x934, y, yp_0;

assert((Y == 14));
assert((X == 14));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y624 = 0;
IND_TYPE x935 = 0;
IND_TYPE h550 = 0;
IND_TYPE w = 0;
IND_TYPE c1160 = 0;
IND_TYPE f1152 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_6668 ,mem_vec_6669 ,mem_vec_6670 ,mem_vec_6671 ,mem_vec_6672 ,mem_vec_6673 ,mem_vec_6674 ,mem_vec_6675 ,mem_vec_6676 ,mem_vec_6677 ,mem_vec_6678 ,mem_vec_6679 ,mem_vec_6680 ,mem_vec_6681 ,mem_vec_6682 ,mem_vec_6683 ,mem_vec_6684 ,mem_vec_6685 ,mem_vec_6686 ,mem_vec_6687 ,mem_vec_6688 ,mem_vec_6689 ,mem_vec_6690 ,mem_vec_6691 ,mem_vec_6692 ,mem_vec_6693 ,mem_vec_6694 ,mem_vec_6695 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_8 ,vec_9;
// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1151 = f1152, f1151_p_0 = 0;
	f1151 < f1152 + 256;
	f1151 += 256, f1151_p_0 += 256){
	// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
	// T (x, 1) (14 / 14)
	for (x934 = x935, x934_p_0 = 0;
		x934 < x935 + 14;
		x934 += 14, x934_p_0 += 14){
		// y = 14, x = 14, h = 3, w = 3, c = 256, f = 256
		// T (c, 2) (256 / 128)
		for (c1159 = c1160, c1159_p_0 = 0;
			c1159 < c1160 + 256;
			c1159 += 128, c1159_p_0 += 128){
			// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
			// T (f, 1) (256 / 256)
			for (f1150 = f1151, f1150_p_1 = f1151_p_0, f1150_p_0 = 0;
				f1150 < f1151 + 256;
				f1150 += 256, f1150_p_1 += 256, f1150_p_0 += 256){
				// y = 14, x = 14, h = 3, w = 3, c = 128, f = 256
				// T (c, 16) (128 / 8)
				for (c1158 = c1159, c1158_p_1 = c1159_p_0, c1158_p_0 = 0;
					c1158 < c1159 + 128;
					c1158 += 8, c1158_p_1 += 8, c1158_p_0 += 8){
					// y = 14, x = 14, h = 3, w = 3, c = 8, f = 256
					// T (f, 8) (256 / 32)
					for (f = f1150, fp_2 = f1150_p_1, fp_1 = f1150_p_0, fp_0 = 0;
						f < f1150 + 256;
						f += 32, fp_2 += 32, fp_1 += 32, fp_0 += 32){
							for (y = y624, yp_0 = 0;
								y < y624 + 6;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h550, hp_0 = 0;
									h < h550 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
									// T (x, 14) (14 / 1)
									for (x = x934, xp_1 = x934_p_0, xp_0 = 0;
										x < x934 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6668 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6669 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1158, cp_2 = c1158_p_1, cp_1 = c1158_p_0, cp_0 = 0;
													c < c1158 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6668);
													mem_vec_6668 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6669);
													mem_vec_6669 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6670);
													mem_vec_6670 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6671);
													mem_vec_6671 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6672);
													mem_vec_6672 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6673);
													mem_vec_6673 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6674);
													mem_vec_6674 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6675);
													mem_vec_6675 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6676);
													mem_vec_6676 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6677);
													mem_vec_6677 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6678);
													mem_vec_6678 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6679);
													mem_vec_6679 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);
													vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_20 = _mm512_fmadd_ps(vec_21, vec_22, mem_vec_6668);
													mem_vec_6668 = vec_20;

													vec_24 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_23 = _mm512_fmadd_ps(vec_21, vec_24, mem_vec_6669);
													mem_vec_6669 = vec_23;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_26 = _mm512_set1_ps(scal_7);


													vec_25 = _mm512_fmadd_ps(vec_26, vec_22, mem_vec_6670);
													mem_vec_6670 = vec_25;



													vec_27 = _mm512_fmadd_ps(vec_26, vec_24, mem_vec_6671);
													mem_vec_6671 = vec_27;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_29 = _mm512_set1_ps(scal_8);


													vec_28 = _mm512_fmadd_ps(vec_29, vec_22, mem_vec_6672);
													mem_vec_6672 = vec_28;



													vec_30 = _mm512_fmadd_ps(vec_29, vec_24, mem_vec_6673);
													mem_vec_6673 = vec_30;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_22, mem_vec_6674);
													mem_vec_6674 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_24, mem_vec_6675);
													mem_vec_6675 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_22, mem_vec_6676);
													mem_vec_6676 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_24, mem_vec_6677);
													mem_vec_6677 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_22, mem_vec_6678);
													mem_vec_6678 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_24, mem_vec_6679);
													mem_vec_6679 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);
													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_40 = _mm512_fmadd_ps(vec_41, vec_42, mem_vec_6668);
													mem_vec_6668 = vec_40;

													vec_44 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_43 = _mm512_fmadd_ps(vec_41, vec_44, mem_vec_6669);
													mem_vec_6669 = vec_43;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_46 = _mm512_set1_ps(scal_13);


													vec_45 = _mm512_fmadd_ps(vec_46, vec_42, mem_vec_6670);
													mem_vec_6670 = vec_45;



													vec_47 = _mm512_fmadd_ps(vec_46, vec_44, mem_vec_6671);
													mem_vec_6671 = vec_47;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_49 = _mm512_set1_ps(scal_14);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_6672);
													mem_vec_6672 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_44, mem_vec_6673);
													mem_vec_6673 = vec_50;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_52 = _mm512_set1_ps(scal_15);


													vec_51 = _mm512_fmadd_ps(vec_52, vec_42, mem_vec_6674);
													mem_vec_6674 = vec_51;



													vec_53 = _mm512_fmadd_ps(vec_52, vec_44, mem_vec_6675);
													mem_vec_6675 = vec_53;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_55 = _mm512_set1_ps(scal_16);


													vec_54 = _mm512_fmadd_ps(vec_55, vec_42, mem_vec_6676);
													mem_vec_6676 = vec_54;



													vec_56 = _mm512_fmadd_ps(vec_55, vec_44, mem_vec_6677);
													mem_vec_6677 = vec_56;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_58 = _mm512_set1_ps(scal_17);


													vec_57 = _mm512_fmadd_ps(vec_58, vec_42, mem_vec_6678);
													mem_vec_6678 = vec_57;



													vec_59 = _mm512_fmadd_ps(vec_58, vec_44, mem_vec_6679);
													mem_vec_6679 = vec_59;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6668);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6669);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6670);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6671);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6672);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6673);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6674);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6675);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6676);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6677);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6678);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6679);
									}
								}
							}
							for (y = y624 + 6, yp_0 = 0;
								y < y624 + 6 + 8;
								y += 8, yp_0 += 8){
								// y = ph_y, x = 14, h = 3, w = 3, c = 8, f = 32
								// T (h, 3) (3 / 1)
								for (h = h550, hp_0 = 0;
									h < h550 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 14, h = 1, w = 3, c = 8, f = 32
									// T (x, 14) (14 / 1)
									for (x = x934, xp_1 = x934_p_0, xp_0 = 0;
										x < x934 + 14;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_6680 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_6681 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_6682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_6683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_6684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_6685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_6686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_6687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_6688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_6689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_6690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_6691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_6692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_6693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
												mem_vec_6694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_6695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 8, f = 32
												// T (c, 8) (8 / 1)
												for (c = c1158, cp_2 = c1158_p_1, cp_1 = c1158_p_0, cp_0 = 0;
													c < c1158 + 8;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_6680);
													mem_vec_6680 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_6681);
													mem_vec_6681 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm512_set1_ps(scal_1);


													vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_6682);
													mem_vec_6682 = vec_5;



													vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_6683);
													mem_vec_6683 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm512_set1_ps(scal_2);


													vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_6684);
													mem_vec_6684 = vec_8;



													vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_6685);
													mem_vec_6685 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm512_set1_ps(scal_3);


													vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_6686);
													mem_vec_6686 = vec_11;



													vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_6687);
													mem_vec_6687 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm512_set1_ps(scal_4);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_6688);
													mem_vec_6688 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_6689);
													mem_vec_6689 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm512_set1_ps(scal_5);


													vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_6690);
													mem_vec_6690 = vec_17;



													vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_6691);
													mem_vec_6691 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm512_set1_ps(scal_6);


													vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_6692);
													mem_vec_6692 = vec_20;



													vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_6693);
													mem_vec_6693 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm512_set1_ps(scal_7);


													vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_6694);
													mem_vec_6694 = vec_23;



													vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_6695);
													mem_vec_6695 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_27 = _mm512_set1_ps(scal_8);
													vec_28 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_26 = _mm512_fmadd_ps(vec_27, vec_28, mem_vec_6680);
													mem_vec_6680 = vec_26;

													vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_29 = _mm512_fmadd_ps(vec_27, vec_30, mem_vec_6681);
													mem_vec_6681 = vec_29;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_32 = _mm512_set1_ps(scal_9);


													vec_31 = _mm512_fmadd_ps(vec_32, vec_28, mem_vec_6682);
													mem_vec_6682 = vec_31;



													vec_33 = _mm512_fmadd_ps(vec_32, vec_30, mem_vec_6683);
													mem_vec_6683 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_35 = _mm512_set1_ps(scal_10);


													vec_34 = _mm512_fmadd_ps(vec_35, vec_28, mem_vec_6684);
													mem_vec_6684 = vec_34;



													vec_36 = _mm512_fmadd_ps(vec_35, vec_30, mem_vec_6685);
													mem_vec_6685 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_38 = _mm512_set1_ps(scal_11);


													vec_37 = _mm512_fmadd_ps(vec_38, vec_28, mem_vec_6686);
													mem_vec_6686 = vec_37;



													vec_39 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_6687);
													mem_vec_6687 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_41 = _mm512_set1_ps(scal_12);


													vec_40 = _mm512_fmadd_ps(vec_41, vec_28, mem_vec_6688);
													mem_vec_6688 = vec_40;



													vec_42 = _mm512_fmadd_ps(vec_41, vec_30, mem_vec_6689);
													mem_vec_6689 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_44 = _mm512_set1_ps(scal_13);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_28, mem_vec_6690);
													mem_vec_6690 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_30, mem_vec_6691);
													mem_vec_6691 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 6 + h) + c];
													vec_47 = _mm512_set1_ps(scal_14);


													vec_46 = _mm512_fmadd_ps(vec_47, vec_28, mem_vec_6692);
													mem_vec_6692 = vec_46;



													vec_48 = _mm512_fmadd_ps(vec_47, vec_30, mem_vec_6693);
													mem_vec_6693 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 7 + h) + c];
													vec_50 = _mm512_set1_ps(scal_15);


													vec_49 = _mm512_fmadd_ps(vec_50, vec_28, mem_vec_6694);
													mem_vec_6694 = vec_49;



													vec_51 = _mm512_fmadd_ps(vec_50, vec_30, mem_vec_6695);
													mem_vec_6695 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_53 = _mm512_set1_ps(scal_16);
													vec_54 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_52 = _mm512_fmadd_ps(vec_53, vec_54, mem_vec_6680);
													mem_vec_6680 = vec_52;

													vec_56 = _mm512_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_55 = _mm512_fmadd_ps(vec_53, vec_56, mem_vec_6681);
													mem_vec_6681 = vec_55;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_58 = _mm512_set1_ps(scal_17);


													vec_57 = _mm512_fmadd_ps(vec_58, vec_54, mem_vec_6682);
													mem_vec_6682 = vec_57;



													vec_59 = _mm512_fmadd_ps(vec_58, vec_56, mem_vec_6683);
													mem_vec_6683 = vec_59;
													scal_18 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_61 = _mm512_set1_ps(scal_18);


													vec_60 = _mm512_fmadd_ps(vec_61, vec_54, mem_vec_6684);
													mem_vec_6684 = vec_60;



													vec_62 = _mm512_fmadd_ps(vec_61, vec_56, mem_vec_6685);
													mem_vec_6685 = vec_62;
													scal_19 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_64 = _mm512_set1_ps(scal_19);


													vec_63 = _mm512_fmadd_ps(vec_64, vec_54, mem_vec_6686);
													mem_vec_6686 = vec_63;



													vec_65 = _mm512_fmadd_ps(vec_64, vec_56, mem_vec_6687);
													mem_vec_6687 = vec_65;
													scal_20 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_67 = _mm512_set1_ps(scal_20);


													vec_66 = _mm512_fmadd_ps(vec_67, vec_54, mem_vec_6688);
													mem_vec_6688 = vec_66;



													vec_68 = _mm512_fmadd_ps(vec_67, vec_56, mem_vec_6689);
													mem_vec_6689 = vec_68;
													scal_21 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_70 = _mm512_set1_ps(scal_21);


													vec_69 = _mm512_fmadd_ps(vec_70, vec_54, mem_vec_6690);
													mem_vec_6690 = vec_69;



													vec_71 = _mm512_fmadd_ps(vec_70, vec_56, mem_vec_6691);
													mem_vec_6691 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 6 + h) + c];
													vec_73 = _mm512_set1_ps(scal_22);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_54, mem_vec_6692);
													mem_vec_6692 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_56, mem_vec_6693);
													mem_vec_6693 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 7 + h) + c];
													vec_76 = _mm512_set1_ps(scal_23);


													vec_75 = _mm512_fmadd_ps(vec_76, vec_54, mem_vec_6694);
													mem_vec_6694 = vec_75;



													vec_77 = _mm512_fmadd_ps(vec_76, vec_56, mem_vec_6695);
													mem_vec_6695 = vec_77;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_6680);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_6681);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_6682);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_6683);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_6684);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_6685);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_6686);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_6687);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_6688);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_6689);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_6690);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_6691);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_6692);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_6693);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_6694);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_6695);
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