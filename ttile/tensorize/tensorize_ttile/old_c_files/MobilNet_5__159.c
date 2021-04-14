#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (256, c); Hoist_vars [c]; T (28, x);
  T (3, w); Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 3), (Arg 6))];
  T (4, f); T (1, c); T (1, f); T (1, c); T (1, x); T (1, f)]
*/
IND_TYPE c, cp_0, c1276_p_0, c1277_p_0, cp_1, c1276_p_1, cp_2, c1276, c1277, f, fp_0, f1116_p_0, f1117_p_0, fp_1, f1116_p_1, fp_2, f1116, f1117, w, wp_0, x, xp_0, x1002_p_0, xp_1, x1002, y, yp_0;

assert((Y == 28));
assert((X == 28));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 256));
IND_TYPE y668 = 0;
IND_TYPE x1003 = 0;
IND_TYPE h = 0;
IND_TYPE w640 = 0;
IND_TYPE c1278 = 0;
IND_TYPE f1118 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_9726 ,mem_vec_9727 ,mem_vec_9728 ,mem_vec_9729 ,mem_vec_9730 ,mem_vec_9731 ,mem_vec_9732 ,mem_vec_9733 ,mem_vec_9734 ,mem_vec_9735 ,mem_vec_9736 ,mem_vec_9737 ,mem_vec_9738 ,mem_vec_9739 ,mem_vec_9740 ,mem_vec_9741 ,mem_vec_9742 ,mem_vec_9743 ,mem_vec_9744 ,mem_vec_9745 ,mem_vec_9746 ,mem_vec_9747 ,mem_vec_9748 ,mem_vec_9749 ,mem_vec_9750 ,mem_vec_9751 ,mem_vec_9752 ,mem_vec_9753 ,mem_vec_9754 ,mem_vec_9755 ,mem_vec_9756 ,mem_vec_9757 ,mem_vec_9758 ,mem_vec_9759 ,mem_vec_9760 ,mem_vec_9761 ,mem_vec_9762 ,mem_vec_9763 ,mem_vec_9764 ,mem_vec_9765 ,mem_vec_9766 ,mem_vec_9767 ,mem_vec_9768 ,mem_vec_9769 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
// T (f, 1) (256 / 256)
for (f1117 = f1118, f1117_p_0 = 0;
	f1117 < f1118 + 256;
	f1117 += 256, f1117_p_0 += 256){
	// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
	// T (x, 1) (28 / 28)
	for (x1002 = x1003, x1002_p_0 = 0;
		x1002 < x1003 + 28;
		x1002 += 28, x1002_p_0 += 28){
		// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
		// T (c, 1) (256 / 256)
		for (c1277 = c1278, c1277_p_0 = 0;
			c1277 < c1278 + 256;
			c1277 += 256, c1277_p_0 += 256){
			// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
			// T (f, 1) (256 / 256)
			for (f1116 = f1117, f1116_p_1 = f1117_p_0, f1116_p_0 = 0;
				f1116 < f1117 + 256;
				f1116 += 256, f1116_p_1 += 256, f1116_p_0 += 256){
				// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
				// T (c, 1) (256 / 256)
				for (c1276 = c1277, c1276_p_1 = c1277_p_0, c1276_p_0 = 0;
					c1276 < c1277 + 256;
					c1276 += 256, c1276_p_1 += 256, c1276_p_0 += 256){
					// y = 28, x = 28, h = 3, w = 3, c = 256, f = 256
					// T (f, 4) (256 / 64)
					for (f = f1116, fp_2 = f1116_p_1, fp_1 = f1116_p_0, fp_0 = 0;
						f < f1116 + 256;
						f += 64, fp_2 += 64, fp_1 += 64, fp_0 += 64){
							for (y = y668, yp_0 = 0;
								y < y668 + 10;
								y += 5, yp_0 += 5){
								// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 64
								// T (w, 3) (3 / 1)
								for (w = w640, wp_0 = 0;
									w < w640 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 28, h = 3, w = 1, c = 256, f = 64
									// T (x, 28) (28 / 1)
									for (x = x1002, xp_1 = x1002_p_0, xp_0 = 0;
										x < x1002 + 28;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9726 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9727 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9728 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_9729 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_9730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_9733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_9734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_9737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_9738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_9741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_9742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_9745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 64
												// T (c, 256) (256 / 1)
												for (c = c1276, cp_2 = c1276_p_1, cp_1 = c1276_p_0, cp_0 = 0;
													c < c1276 + 256;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9726);
													mem_vec_9726 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9727);
													mem_vec_9727 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9728);
													mem_vec_9728 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9729);
													mem_vec_9729 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9730);
													mem_vec_9730 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9731);
													mem_vec_9731 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9732);
													mem_vec_9732 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9733);
													mem_vec_9733 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9734);
													mem_vec_9734 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9735);
													mem_vec_9735 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9736);
													mem_vec_9736 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9737);
													mem_vec_9737 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9738);
													mem_vec_9738 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9739);
													mem_vec_9739 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9740);
													mem_vec_9740 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9741);
													mem_vec_9741 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9742);
													mem_vec_9742 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9743);
													mem_vec_9743 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9744);
													mem_vec_9744 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9745);
													mem_vec_9745 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_30 = _mm512_set1_ps(scal_5);
													vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_9726);
													mem_vec_9726 = vec_29;

													vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_9727);
													mem_vec_9727 = vec_32;

													vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_9728);
													mem_vec_9728 = vec_34;

													vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_9729);
													mem_vec_9729 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_39 = _mm512_set1_ps(scal_6);


													vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_9730);
													mem_vec_9730 = vec_38;



													vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_9731);
													mem_vec_9731 = vec_40;



													vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_9732);
													mem_vec_9732 = vec_41;



													vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_9733);
													mem_vec_9733 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_9734);
													mem_vec_9734 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_9735);
													mem_vec_9735 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_9736);
													mem_vec_9736 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_9737);
													mem_vec_9737 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_9738);
													mem_vec_9738 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_9739);
													mem_vec_9739 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_9740);
													mem_vec_9740 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_9741);
													mem_vec_9741 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_9742);
													mem_vec_9742 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_9743);
													mem_vec_9743 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_9744);
													mem_vec_9744 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_9745);
													mem_vec_9745 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_59 = _mm512_set1_ps(scal_10);
													vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_9726);
													mem_vec_9726 = vec_58;

													vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_9727);
													mem_vec_9727 = vec_61;

													vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_9728);
													mem_vec_9728 = vec_63;

													vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_9729);
													mem_vec_9729 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_68 = _mm512_set1_ps(scal_11);


													vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_9730);
													mem_vec_9730 = vec_67;



													vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_9731);
													mem_vec_9731 = vec_69;



													vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_9732);
													mem_vec_9732 = vec_70;



													vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_9733);
													mem_vec_9733 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm512_set1_ps(scal_12);


													vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_9734);
													mem_vec_9734 = vec_72;



													vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_9735);
													mem_vec_9735 = vec_74;



													vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_9736);
													mem_vec_9736 = vec_75;



													vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_9737);
													mem_vec_9737 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_9738);
													mem_vec_9738 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_9739);
													mem_vec_9739 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_9740);
													mem_vec_9740 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_9741);
													mem_vec_9741 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_9742);
													mem_vec_9742 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_9743);
													mem_vec_9743 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_9744);
													mem_vec_9744 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_9745);
													mem_vec_9745 = vec_86;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9726);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9727);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9728);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9729);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9730);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9731);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9732);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9733);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9734);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9735);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9736);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9737);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9738);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9739);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9740);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9741);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9742);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9743);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9744);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9745);
									}
								}
							}
							for (y = y668 + 10, yp_0 = 0;
								y < y668 + 10 + 18;
								y += 6, yp_0 += 6){
								// y = ph_y, x = 28, h = 3, w = 3, c = 256, f = 64
								// T (w, 3) (3 / 1)
								for (w = w640, wp_0 = 0;
									w < w640 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 28, h = 3, w = 1, c = 256, f = 64
									// T (x, 28) (28 / 1)
									for (x = x1002, xp_1 = x1002_p_0, xp_0 = 0;
										x < x1002 + 28;
										x += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_9746 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_9747 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_9748 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
												mem_vec_9749 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
												mem_vec_9750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_9751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_9752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
												mem_vec_9753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
												mem_vec_9754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_9755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_9756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
												mem_vec_9757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
												mem_vec_9758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_9759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_9760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
												mem_vec_9761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
												mem_vec_9762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_9763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_9764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
												mem_vec_9765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
												mem_vec_9766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_9767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_9768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
												mem_vec_9769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 256, f = 64
												// T (c, 256) (256 / 1)
												for (c = c1276, cp_2 = c1276_p_1, cp_1 = c1276_p_0, cp_0 = 0;
													c < c1276 + 256;
													c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm512_set1_ps(scal_0);
													vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_9746);
													mem_vec_9746 = vec_0;

													vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_9747);
													mem_vec_9747 = vec_3;

													vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

													vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_9748);
													mem_vec_9748 = vec_5;

													vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

													vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_9749);
													mem_vec_9749 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm512_set1_ps(scal_1);


													vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_9750);
													mem_vec_9750 = vec_9;



													vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_9751);
													mem_vec_9751 = vec_11;



													vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_9752);
													mem_vec_9752 = vec_12;



													vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_9753);
													mem_vec_9753 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm512_set1_ps(scal_2);


													vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_9754);
													mem_vec_9754 = vec_14;



													vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_9755);
													mem_vec_9755 = vec_16;



													vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_9756);
													mem_vec_9756 = vec_17;



													vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_9757);
													mem_vec_9757 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm512_set1_ps(scal_3);


													vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_9758);
													mem_vec_9758 = vec_19;



													vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_9759);
													mem_vec_9759 = vec_21;



													vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_9760);
													mem_vec_9760 = vec_22;



													vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_9761);
													mem_vec_9761 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm512_set1_ps(scal_4);


													vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_9762);
													mem_vec_9762 = vec_24;



													vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_9763);
													mem_vec_9763 = vec_26;



													vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_9764);
													mem_vec_9764 = vec_27;



													vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_9765);
													mem_vec_9765 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm512_set1_ps(scal_5);


													vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_9766);
													mem_vec_9766 = vec_29;



													vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_9767);
													mem_vec_9767 = vec_31;



													vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_9768);
													mem_vec_9768 = vec_32;



													vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_9769);
													mem_vec_9769 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_35 = _mm512_set1_ps(scal_6);
													vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_34 = _mm512_fmadd_ps(vec_35, vec_36, mem_vec_9746);
													mem_vec_9746 = vec_34;

													vec_38 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

													vec_37 = _mm512_fmadd_ps(vec_35, vec_38, mem_vec_9747);
													mem_vec_9747 = vec_37;

													vec_40 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

													vec_39 = _mm512_fmadd_ps(vec_35, vec_40, mem_vec_9748);
													mem_vec_9748 = vec_39;

													vec_42 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

													vec_41 = _mm512_fmadd_ps(vec_35, vec_42, mem_vec_9749);
													mem_vec_9749 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_44 = _mm512_set1_ps(scal_7);


													vec_43 = _mm512_fmadd_ps(vec_44, vec_36, mem_vec_9750);
													mem_vec_9750 = vec_43;



													vec_45 = _mm512_fmadd_ps(vec_44, vec_38, mem_vec_9751);
													mem_vec_9751 = vec_45;



													vec_46 = _mm512_fmadd_ps(vec_44, vec_40, mem_vec_9752);
													mem_vec_9752 = vec_46;



													vec_47 = _mm512_fmadd_ps(vec_44, vec_42, mem_vec_9753);
													mem_vec_9753 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_49 = _mm512_set1_ps(scal_8);


													vec_48 = _mm512_fmadd_ps(vec_49, vec_36, mem_vec_9754);
													mem_vec_9754 = vec_48;



													vec_50 = _mm512_fmadd_ps(vec_49, vec_38, mem_vec_9755);
													mem_vec_9755 = vec_50;



													vec_51 = _mm512_fmadd_ps(vec_49, vec_40, mem_vec_9756);
													mem_vec_9756 = vec_51;



													vec_52 = _mm512_fmadd_ps(vec_49, vec_42, mem_vec_9757);
													mem_vec_9757 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_54 = _mm512_set1_ps(scal_9);


													vec_53 = _mm512_fmadd_ps(vec_54, vec_36, mem_vec_9758);
													mem_vec_9758 = vec_53;



													vec_55 = _mm512_fmadd_ps(vec_54, vec_38, mem_vec_9759);
													mem_vec_9759 = vec_55;



													vec_56 = _mm512_fmadd_ps(vec_54, vec_40, mem_vec_9760);
													mem_vec_9760 = vec_56;



													vec_57 = _mm512_fmadd_ps(vec_54, vec_42, mem_vec_9761);
													mem_vec_9761 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_59 = _mm512_set1_ps(scal_10);


													vec_58 = _mm512_fmadd_ps(vec_59, vec_36, mem_vec_9762);
													mem_vec_9762 = vec_58;



													vec_60 = _mm512_fmadd_ps(vec_59, vec_38, mem_vec_9763);
													mem_vec_9763 = vec_60;



													vec_61 = _mm512_fmadd_ps(vec_59, vec_40, mem_vec_9764);
													mem_vec_9764 = vec_61;



													vec_62 = _mm512_fmadd_ps(vec_59, vec_42, mem_vec_9765);
													mem_vec_9765 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_64 = _mm512_set1_ps(scal_11);


													vec_63 = _mm512_fmadd_ps(vec_64, vec_36, mem_vec_9766);
													mem_vec_9766 = vec_63;



													vec_65 = _mm512_fmadd_ps(vec_64, vec_38, mem_vec_9767);
													mem_vec_9767 = vec_65;



													vec_66 = _mm512_fmadd_ps(vec_64, vec_40, mem_vec_9768);
													mem_vec_9768 = vec_66;



													vec_67 = _mm512_fmadd_ps(vec_64, vec_42, mem_vec_9769);
													mem_vec_9769 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_69 = _mm512_set1_ps(scal_12);
													vec_70 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_68 = _mm512_fmadd_ps(vec_69, vec_70, mem_vec_9746);
													mem_vec_9746 = vec_68;

													vec_72 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

													vec_71 = _mm512_fmadd_ps(vec_69, vec_72, mem_vec_9747);
													mem_vec_9747 = vec_71;

													vec_74 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

													vec_73 = _mm512_fmadd_ps(vec_69, vec_74, mem_vec_9748);
													mem_vec_9748 = vec_73;

													vec_76 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

													vec_75 = _mm512_fmadd_ps(vec_69, vec_76, mem_vec_9749);
													mem_vec_9749 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_78 = _mm512_set1_ps(scal_13);


													vec_77 = _mm512_fmadd_ps(vec_78, vec_70, mem_vec_9750);
													mem_vec_9750 = vec_77;



													vec_79 = _mm512_fmadd_ps(vec_78, vec_72, mem_vec_9751);
													mem_vec_9751 = vec_79;



													vec_80 = _mm512_fmadd_ps(vec_78, vec_74, mem_vec_9752);
													mem_vec_9752 = vec_80;



													vec_81 = _mm512_fmadd_ps(vec_78, vec_76, mem_vec_9753);
													mem_vec_9753 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_83 = _mm512_set1_ps(scal_14);


													vec_82 = _mm512_fmadd_ps(vec_83, vec_70, mem_vec_9754);
													mem_vec_9754 = vec_82;



													vec_84 = _mm512_fmadd_ps(vec_83, vec_72, mem_vec_9755);
													mem_vec_9755 = vec_84;



													vec_85 = _mm512_fmadd_ps(vec_83, vec_74, mem_vec_9756);
													mem_vec_9756 = vec_85;



													vec_86 = _mm512_fmadd_ps(vec_83, vec_76, mem_vec_9757);
													mem_vec_9757 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_88 = _mm512_set1_ps(scal_15);


													vec_87 = _mm512_fmadd_ps(vec_88, vec_70, mem_vec_9758);
													mem_vec_9758 = vec_87;



													vec_89 = _mm512_fmadd_ps(vec_88, vec_72, mem_vec_9759);
													mem_vec_9759 = vec_89;



													vec_90 = _mm512_fmadd_ps(vec_88, vec_74, mem_vec_9760);
													mem_vec_9760 = vec_90;



													vec_91 = _mm512_fmadd_ps(vec_88, vec_76, mem_vec_9761);
													mem_vec_9761 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_93 = _mm512_set1_ps(scal_16);


													vec_92 = _mm512_fmadd_ps(vec_93, vec_70, mem_vec_9762);
													mem_vec_9762 = vec_92;



													vec_94 = _mm512_fmadd_ps(vec_93, vec_72, mem_vec_9763);
													mem_vec_9763 = vec_94;



													vec_95 = _mm512_fmadd_ps(vec_93, vec_74, mem_vec_9764);
													mem_vec_9764 = vec_95;



													vec_96 = _mm512_fmadd_ps(vec_93, vec_76, mem_vec_9765);
													mem_vec_9765 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_98 = _mm512_set1_ps(scal_17);


													vec_97 = _mm512_fmadd_ps(vec_98, vec_70, mem_vec_9766);
													mem_vec_9766 = vec_97;



													vec_99 = _mm512_fmadd_ps(vec_98, vec_72, mem_vec_9767);
													mem_vec_9767 = vec_99;



													vec_100 = _mm512_fmadd_ps(vec_98, vec_74, mem_vec_9768);
													mem_vec_9768 = vec_100;



													vec_101 = _mm512_fmadd_ps(vec_98, vec_76, mem_vec_9769);
													mem_vec_9769 = vec_101;
												}
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_9746);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_9747);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_9748);
											_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_9749);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_9750);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_9751);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_9752);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_9753);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_9754);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_9755);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_9756);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_9757);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_9758);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_9759);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_9760);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_9761);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_9762);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_9763);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_9764);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_9765);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_9766);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_9767);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_9768);
											_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_9769);
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