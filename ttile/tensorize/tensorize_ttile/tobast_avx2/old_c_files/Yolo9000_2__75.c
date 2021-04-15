#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, w); T (4, c); Hoist_vars [c]; T (1, x);
  T (3, h); T (17, y); T (2, f); T (8, c); T (68, x);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 6))]; T (1, f);
  T (4, x)]
*/
IND_TYPE c, cp_0, c1086_p_0, cp_1, c1086, f, fp_0, f958_p_0, fp_1, f958, h, hp_0, x, xp_0, x1448_p_0, x1449_p_0, xp_1, x1448_p_1, xp_2, x1448, x1449, y, yp_0, y1086_p_0, yp_1, y1086;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y1087 = 0;
IND_TYPE x1450 = 0;
IND_TYPE h514 = 0;
IND_TYPE w = 0;
IND_TYPE c1087 = 0;
IND_TYPE f959 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_11768 ,mem_vec_11769 ,mem_vec_11770 ,mem_vec_11771 ,mem_vec_11772 ,mem_vec_11773 ,mem_vec_11774 ,mem_vec_11775 ,mem_vec_11776 ,mem_vec_11777 ,mem_vec_11778 ,mem_vec_11779 ,mem_vec_11780 ,mem_vec_11781 ,mem_vec_11782 ,mem_vec_11783 ,mem_vec_11784 ,mem_vec_11785 ,mem_vec_11786 ,mem_vec_11787 ,mem_vec_11788 ,mem_vec_11789 ,mem_vec_11790 ,mem_vec_11791 ,mem_vec_11792 ,mem_vec_11793 ,mem_vec_11794 ,mem_vec_11795 ,mem_vec_11796 ,mem_vec_11797 ,mem_vec_11798 ,mem_vec_11799 ,mem_vec_11800 ,mem_vec_11801 ,mem_vec_11802 ,mem_vec_11803 ,mem_vec_11804 ,mem_vec_11805 ,mem_vec_11806 ,mem_vec_11807 ,mem_vec_11808 ,mem_vec_11809 ,mem_vec_11810 ,mem_vec_11811 ,vec_0 ,vec_1 ,vec_10 ,vec_100 ,vec_101 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95 ,vec_96 ,vec_97 ,vec_98 ,vec_99;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (x, 4) (272 / 68)
for (x1449 = x1450, x1449_p_0 = 0;
	x1449 < x1450 + 272;
	x1449 += 68, x1449_p_0 += 68){
	// y = 272, x = 68, h = 3, w = 3, c = 32, f = 64
	// T (f, 1) (64 / 64)
	for (f958 = f959, f958_p_0 = 0;
		f958 < f959 + 64;
		f958 += 64, f958_p_0 += 64){
			for (y1086 = y1087, y1086_p_0 = 0;
				y1086 < y1087 + 170;
				y1086 += 85, y1086_p_0 += 85){
				// y = 17 * ph_y, x = 68, h = 3, w = 3, c = 32, f = 64
				// T (x, 68) (68 / 1)
				for (x1448 = x1449, x1448_p_1 = x1449_p_0, x1448_p_0 = 0;
					x1448 < x1449 + 68;
					x1448 += 1, x1448_p_1 += 1, x1448_p_0 += 1){
					// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 8) (32 / 4)
					for (c1086 = c1087, c1086_p_0 = 0;
						c1086 < c1087 + 32;
						c1086 += 4, c1086_p_0 += 4){
						// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (f, 2) (64 / 32)
						for (f = f958, fp_1 = f958_p_0, fp_0 = 0;
							f < f958 + 64;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (y, 17) (17 * ph_y / ph_y)
							for (y = y1086, yp_1 = y1086_p_0, yp_0 = 0;
								y < y1086 + 85;
								y += 5, yp_1 += 5, yp_0 += 5){
								// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h514, hp_0 = 0;
									h < h514 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1448, xp_2 = x1448_p_1, xp_1 = x1448_p_0, xp_0 = 0;
										x < x1448 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11768 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11769 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11770 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11771 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11772 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11773 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11774 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11775 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11776 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11777 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11778 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11779 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11780 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11781 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11782 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11783 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11784 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11785 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11786 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11787 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1086, cp_1 = c1086_p_0, cp_0 = 0;
													c < c1086 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11768);
													mem_vec_11768 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11769);
													mem_vec_11769 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11770);
													mem_vec_11770 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11771);
													mem_vec_11771 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11772);
													mem_vec_11772 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11773);
													mem_vec_11773 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11774);
													mem_vec_11774 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11775);
													mem_vec_11775 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11776);
													mem_vec_11776 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11777);
													mem_vec_11777 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11778);
													mem_vec_11778 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11779);
													mem_vec_11779 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11780);
													mem_vec_11780 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11781);
													mem_vec_11781 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11782);
													mem_vec_11782 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11783);
													mem_vec_11783 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11784);
													mem_vec_11784 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11785);
													mem_vec_11785 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11786);
													mem_vec_11786 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11787);
													mem_vec_11787 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);
													vec_31 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_29 = _mm256_fmadd_ps(vec_30, vec_31, mem_vec_11768);
													mem_vec_11768 = vec_29;

													vec_33 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_32 = _mm256_fmadd_ps(vec_30, vec_33, mem_vec_11769);
													mem_vec_11769 = vec_32;

													vec_35 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_34 = _mm256_fmadd_ps(vec_30, vec_35, mem_vec_11770);
													mem_vec_11770 = vec_34;

													vec_37 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_36 = _mm256_fmadd_ps(vec_30, vec_37, mem_vec_11771);
													mem_vec_11771 = vec_36;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_39 = _mm256_set1_ps(scal_6);


													vec_38 = _mm256_fmadd_ps(vec_39, vec_31, mem_vec_11772);
													mem_vec_11772 = vec_38;



													vec_40 = _mm256_fmadd_ps(vec_39, vec_33, mem_vec_11773);
													mem_vec_11773 = vec_40;



													vec_41 = _mm256_fmadd_ps(vec_39, vec_35, mem_vec_11774);
													mem_vec_11774 = vec_41;



													vec_42 = _mm256_fmadd_ps(vec_39, vec_37, mem_vec_11775);
													mem_vec_11775 = vec_42;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_31, mem_vec_11776);
													mem_vec_11776 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_33, mem_vec_11777);
													mem_vec_11777 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_35, mem_vec_11778);
													mem_vec_11778 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_37, mem_vec_11779);
													mem_vec_11779 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_31, mem_vec_11780);
													mem_vec_11780 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_33, mem_vec_11781);
													mem_vec_11781 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_35, mem_vec_11782);
													mem_vec_11782 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_37, mem_vec_11783);
													mem_vec_11783 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_31, mem_vec_11784);
													mem_vec_11784 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_33, mem_vec_11785);
													mem_vec_11785 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_35, mem_vec_11786);
													mem_vec_11786 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_37, mem_vec_11787);
													mem_vec_11787 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);
													vec_60 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_58 = _mm256_fmadd_ps(vec_59, vec_60, mem_vec_11768);
													mem_vec_11768 = vec_58;

													vec_62 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_61 = _mm256_fmadd_ps(vec_59, vec_62, mem_vec_11769);
													mem_vec_11769 = vec_61;

													vec_64 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_63 = _mm256_fmadd_ps(vec_59, vec_64, mem_vec_11770);
													mem_vec_11770 = vec_63;

													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_65 = _mm256_fmadd_ps(vec_59, vec_66, mem_vec_11771);
													mem_vec_11771 = vec_65;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_68 = _mm256_set1_ps(scal_11);


													vec_67 = _mm256_fmadd_ps(vec_68, vec_60, mem_vec_11772);
													mem_vec_11772 = vec_67;



													vec_69 = _mm256_fmadd_ps(vec_68, vec_62, mem_vec_11773);
													mem_vec_11773 = vec_69;



													vec_70 = _mm256_fmadd_ps(vec_68, vec_64, mem_vec_11774);
													mem_vec_11774 = vec_70;



													vec_71 = _mm256_fmadd_ps(vec_68, vec_66, mem_vec_11775);
													mem_vec_11775 = vec_71;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_73 = _mm256_set1_ps(scal_12);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_60, mem_vec_11776);
													mem_vec_11776 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_62, mem_vec_11777);
													mem_vec_11777 = vec_74;



													vec_75 = _mm256_fmadd_ps(vec_73, vec_64, mem_vec_11778);
													mem_vec_11778 = vec_75;



													vec_76 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_11779);
													mem_vec_11779 = vec_76;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_60, mem_vec_11780);
													mem_vec_11780 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_62, mem_vec_11781);
													mem_vec_11781 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_64, mem_vec_11782);
													mem_vec_11782 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_66, mem_vec_11783);
													mem_vec_11783 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_60, mem_vec_11784);
													mem_vec_11784 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_62, mem_vec_11785);
													mem_vec_11785 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_64, mem_vec_11786);
													mem_vec_11786 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_66, mem_vec_11787);
													mem_vec_11787 = vec_86;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11768);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11769);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11770);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11771);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11772);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11773);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11774);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11775);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11776);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11777);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11778);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11779);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11780);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11781);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11782);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11783);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11784);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11785);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11786);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11787);
									}
								}
							}
						}
					}
				}
			}
			for (y1086 = y1087 + 170, y1086_p_0 = 0;
				y1086 < y1087 + 170 + 102;
				y1086 += 102, y1086_p_0 += 102){
				// y = 17 * ph_y, x = 68, h = 3, w = 3, c = 32, f = 64
				// T (x, 68) (68 / 1)
				for (x1448 = x1449, x1448_p_1 = x1449_p_0, x1448_p_0 = 0;
					x1448 < x1449 + 68;
					x1448 += 1, x1448_p_1 += 1, x1448_p_0 += 1){
					// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (c, 8) (32 / 4)
					for (c1086 = c1087, c1086_p_0 = 0;
						c1086 < c1087 + 32;
						c1086 += 4, c1086_p_0 += 4){
						// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 4, f = 64
						// T (f, 2) (64 / 32)
						for (f = f958, fp_1 = f958_p_0, fp_0 = 0;
							f < f958 + 64;
							f += 32, fp_1 += 32, fp_0 += 32){
							// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
							// T (y, 17) (17 * ph_y / ph_y)
							for (y = y1086, yp_1 = y1086_p_0, yp_0 = 0;
								y < y1086 + 102;
								y += 6, yp_1 += 6, yp_0 += 6){
								// y = ph_y, x = 1, h = 3, w = 3, c = 4, f = 32
								// T (h, 3) (3 / 1)
								for (h = h514, hp_0 = 0;
									h < h514 + 3;
									h += 1, hp_0 += 1){
									// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
									// T (x, 1) (1 / 1)
									for (x = x1448, xp_2 = x1448_p_1, xp_1 = x1448_p_0, xp_0 = 0;
										x < x1448 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_11788 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_11789 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_11790 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
												mem_vec_11791 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 24]);
												mem_vec_11792 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_11793 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_11794 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
												mem_vec_11795 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24]);
												mem_vec_11796 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_11797 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_11798 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
												mem_vec_11799 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24]);
												mem_vec_11800 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_11801 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_11802 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
												mem_vec_11803 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24]);
												mem_vec_11804 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_11805 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_11806 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
												mem_vec_11807 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24]);
												mem_vec_11808 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_11809 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_11810 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
												mem_vec_11811 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24]);
												// y = ph_y, x = 1, h = 1, w = 3, c = 4, f = 32
												// T (c, 4) (4 / 1)
												for (c = c1086, cp_1 = c1086_p_0, cp_0 = 0;
													c < c1086 + 4;
													c += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_11788);
													mem_vec_11788 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_11789);
													mem_vec_11789 = vec_3;

													vec_6 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

													vec_5 = _mm256_fmadd_ps(vec_1, vec_6, mem_vec_11790);
													mem_vec_11790 = vec_5;

													vec_8 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 24]);

													vec_7 = _mm256_fmadd_ps(vec_1, vec_8, mem_vec_11791);
													mem_vec_11791 = vec_7;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_10 = _mm256_set1_ps(scal_1);


													vec_9 = _mm256_fmadd_ps(vec_10, vec_2, mem_vec_11792);
													mem_vec_11792 = vec_9;



													vec_11 = _mm256_fmadd_ps(vec_10, vec_4, mem_vec_11793);
													mem_vec_11793 = vec_11;



													vec_12 = _mm256_fmadd_ps(vec_10, vec_6, mem_vec_11794);
													mem_vec_11794 = vec_12;



													vec_13 = _mm256_fmadd_ps(vec_10, vec_8, mem_vec_11795);
													mem_vec_11795 = vec_13;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_15 = _mm256_set1_ps(scal_2);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_11796);
													mem_vec_11796 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_11797);
													mem_vec_11797 = vec_16;



													vec_17 = _mm256_fmadd_ps(vec_15, vec_6, mem_vec_11798);
													mem_vec_11798 = vec_17;



													vec_18 = _mm256_fmadd_ps(vec_15, vec_8, mem_vec_11799);
													mem_vec_11799 = vec_18;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_20 = _mm256_set1_ps(scal_3);


													vec_19 = _mm256_fmadd_ps(vec_20, vec_2, mem_vec_11800);
													mem_vec_11800 = vec_19;



													vec_21 = _mm256_fmadd_ps(vec_20, vec_4, mem_vec_11801);
													mem_vec_11801 = vec_21;



													vec_22 = _mm256_fmadd_ps(vec_20, vec_6, mem_vec_11802);
													mem_vec_11802 = vec_22;



													vec_23 = _mm256_fmadd_ps(vec_20, vec_8, mem_vec_11803);
													mem_vec_11803 = vec_23;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_25 = _mm256_set1_ps(scal_4);


													vec_24 = _mm256_fmadd_ps(vec_25, vec_2, mem_vec_11804);
													mem_vec_11804 = vec_24;



													vec_26 = _mm256_fmadd_ps(vec_25, vec_4, mem_vec_11805);
													mem_vec_11805 = vec_26;



													vec_27 = _mm256_fmadd_ps(vec_25, vec_6, mem_vec_11806);
													mem_vec_11806 = vec_27;



													vec_28 = _mm256_fmadd_ps(vec_25, vec_8, mem_vec_11807);
													mem_vec_11807 = vec_28;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_30 = _mm256_set1_ps(scal_5);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_11808);
													mem_vec_11808 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_11809);
													mem_vec_11809 = vec_31;



													vec_32 = _mm256_fmadd_ps(vec_30, vec_6, mem_vec_11810);
													mem_vec_11810 = vec_32;



													vec_33 = _mm256_fmadd_ps(vec_30, vec_8, mem_vec_11811);
													mem_vec_11811 = vec_33;
													scal_6 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + h) + c];
													vec_35 = _mm256_set1_ps(scal_6);
													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f]);

													vec_34 = _mm256_fmadd_ps(vec_35, vec_36, mem_vec_11788);
													mem_vec_11788 = vec_34;

													vec_38 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 8]);

													vec_37 = _mm256_fmadd_ps(vec_35, vec_38, mem_vec_11789);
													mem_vec_11789 = vec_37;

													vec_40 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 16]);

													vec_39 = _mm256_fmadd_ps(vec_35, vec_40, mem_vec_11790);
													mem_vec_11790 = vec_39;

													vec_42 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 1) + (F * C) * h + F * c + f + 24]);

													vec_41 = _mm256_fmadd_ps(vec_35, vec_42, mem_vec_11791);
													mem_vec_11791 = vec_41;
													scal_7 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 1 + h) + c];
													vec_44 = _mm256_set1_ps(scal_7);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_11792);
													mem_vec_11792 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_38, mem_vec_11793);
													mem_vec_11793 = vec_45;



													vec_46 = _mm256_fmadd_ps(vec_44, vec_40, mem_vec_11794);
													mem_vec_11794 = vec_46;



													vec_47 = _mm256_fmadd_ps(vec_44, vec_42, mem_vec_11795);
													mem_vec_11795 = vec_47;
													scal_8 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 2 + h) + c];
													vec_49 = _mm256_set1_ps(scal_8);


													vec_48 = _mm256_fmadd_ps(vec_49, vec_36, mem_vec_11796);
													mem_vec_11796 = vec_48;



													vec_50 = _mm256_fmadd_ps(vec_49, vec_38, mem_vec_11797);
													mem_vec_11797 = vec_50;



													vec_51 = _mm256_fmadd_ps(vec_49, vec_40, mem_vec_11798);
													mem_vec_11798 = vec_51;



													vec_52 = _mm256_fmadd_ps(vec_49, vec_42, mem_vec_11799);
													mem_vec_11799 = vec_52;
													scal_9 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 3 + h) + c];
													vec_54 = _mm256_set1_ps(scal_9);


													vec_53 = _mm256_fmadd_ps(vec_54, vec_36, mem_vec_11800);
													mem_vec_11800 = vec_53;



													vec_55 = _mm256_fmadd_ps(vec_54, vec_38, mem_vec_11801);
													mem_vec_11801 = vec_55;



													vec_56 = _mm256_fmadd_ps(vec_54, vec_40, mem_vec_11802);
													mem_vec_11802 = vec_56;



													vec_57 = _mm256_fmadd_ps(vec_54, vec_42, mem_vec_11803);
													mem_vec_11803 = vec_57;
													scal_10 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 4 + h) + c];
													vec_59 = _mm256_set1_ps(scal_10);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_11804);
													mem_vec_11804 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_38, mem_vec_11805);
													mem_vec_11805 = vec_60;



													vec_61 = _mm256_fmadd_ps(vec_59, vec_40, mem_vec_11806);
													mem_vec_11806 = vec_61;



													vec_62 = _mm256_fmadd_ps(vec_59, vec_42, mem_vec_11807);
													mem_vec_11807 = vec_62;
													scal_11 = input[(C * (Y + H - 1)) * (x + w + 1) + C * (y + 5 + h) + c];
													vec_64 = _mm256_set1_ps(scal_11);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_36, mem_vec_11808);
													mem_vec_11808 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_38, mem_vec_11809);
													mem_vec_11809 = vec_65;



													vec_66 = _mm256_fmadd_ps(vec_64, vec_40, mem_vec_11810);
													mem_vec_11810 = vec_66;



													vec_67 = _mm256_fmadd_ps(vec_64, vec_42, mem_vec_11811);
													mem_vec_11811 = vec_67;
													scal_12 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + h) + c];
													vec_69 = _mm256_set1_ps(scal_12);
													vec_70 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f]);

													vec_68 = _mm256_fmadd_ps(vec_69, vec_70, mem_vec_11788);
													mem_vec_11788 = vec_68;

													vec_72 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 8]);

													vec_71 = _mm256_fmadd_ps(vec_69, vec_72, mem_vec_11789);
													mem_vec_11789 = vec_71;

													vec_74 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 16]);

													vec_73 = _mm256_fmadd_ps(vec_69, vec_74, mem_vec_11790);
													mem_vec_11790 = vec_73;

													vec_76 = _mm256_loadu_ps(&params[((F * C) * H) * (w + 2) + (F * C) * h + F * c + f + 24]);

													vec_75 = _mm256_fmadd_ps(vec_69, vec_76, mem_vec_11791);
													mem_vec_11791 = vec_75;
													scal_13 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 1 + h) + c];
													vec_78 = _mm256_set1_ps(scal_13);


													vec_77 = _mm256_fmadd_ps(vec_78, vec_70, mem_vec_11792);
													mem_vec_11792 = vec_77;



													vec_79 = _mm256_fmadd_ps(vec_78, vec_72, mem_vec_11793);
													mem_vec_11793 = vec_79;



													vec_80 = _mm256_fmadd_ps(vec_78, vec_74, mem_vec_11794);
													mem_vec_11794 = vec_80;



													vec_81 = _mm256_fmadd_ps(vec_78, vec_76, mem_vec_11795);
													mem_vec_11795 = vec_81;
													scal_14 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 2 + h) + c];
													vec_83 = _mm256_set1_ps(scal_14);


													vec_82 = _mm256_fmadd_ps(vec_83, vec_70, mem_vec_11796);
													mem_vec_11796 = vec_82;



													vec_84 = _mm256_fmadd_ps(vec_83, vec_72, mem_vec_11797);
													mem_vec_11797 = vec_84;



													vec_85 = _mm256_fmadd_ps(vec_83, vec_74, mem_vec_11798);
													mem_vec_11798 = vec_85;



													vec_86 = _mm256_fmadd_ps(vec_83, vec_76, mem_vec_11799);
													mem_vec_11799 = vec_86;
													scal_15 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 3 + h) + c];
													vec_88 = _mm256_set1_ps(scal_15);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_70, mem_vec_11800);
													mem_vec_11800 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_72, mem_vec_11801);
													mem_vec_11801 = vec_89;



													vec_90 = _mm256_fmadd_ps(vec_88, vec_74, mem_vec_11802);
													mem_vec_11802 = vec_90;



													vec_91 = _mm256_fmadd_ps(vec_88, vec_76, mem_vec_11803);
													mem_vec_11803 = vec_91;
													scal_16 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 4 + h) + c];
													vec_93 = _mm256_set1_ps(scal_16);


													vec_92 = _mm256_fmadd_ps(vec_93, vec_70, mem_vec_11804);
													mem_vec_11804 = vec_92;



													vec_94 = _mm256_fmadd_ps(vec_93, vec_72, mem_vec_11805);
													mem_vec_11805 = vec_94;



													vec_95 = _mm256_fmadd_ps(vec_93, vec_74, mem_vec_11806);
													mem_vec_11806 = vec_95;



													vec_96 = _mm256_fmadd_ps(vec_93, vec_76, mem_vec_11807);
													mem_vec_11807 = vec_96;
													scal_17 = input[(C * (Y + H - 1)) * (x + w + 2) + C * (y + 5 + h) + c];
													vec_98 = _mm256_set1_ps(scal_17);


													vec_97 = _mm256_fmadd_ps(vec_98, vec_70, mem_vec_11808);
													mem_vec_11808 = vec_97;



													vec_99 = _mm256_fmadd_ps(vec_98, vec_72, mem_vec_11809);
													mem_vec_11809 = vec_99;



													vec_100 = _mm256_fmadd_ps(vec_98, vec_74, mem_vec_11810);
													mem_vec_11810 = vec_100;



													vec_101 = _mm256_fmadd_ps(vec_98, vec_76, mem_vec_11811);
													mem_vec_11811 = vec_101;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_11788);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_11789);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_11790);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 24], mem_vec_11791);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_11792);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_11793);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_11794);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 24], mem_vec_11795);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_11796);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_11797);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_11798);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 24], mem_vec_11799);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_11800);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_11801);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_11802);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 24], mem_vec_11803);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_11804);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_11805);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_11806);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 24], mem_vec_11807);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_11808);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_11809);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_11810);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 24], mem_vec_11811);
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