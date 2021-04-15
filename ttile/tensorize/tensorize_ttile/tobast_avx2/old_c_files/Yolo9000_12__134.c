#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (8, c); T (2, x);
  Lambda_apply y [((Iter 3), (Arg 8)); ((Iter 1), (Arg 10))]; T (2, c);
  T (32, f); T (17, x); T (1, c)]
*/
IND_TYPE c, cp_0, c240_p_0, c241_p_0, c242_p_0, cp_1, c240_p_1, c241_p_1, cp_2, c240_p_2, cp_3, c240, c241, c242, f, fp_0, w, wp_0, x, xp_0, x192_p_0, x193_p_0, xp_1, x192_p_1, xp_2, x192, x193, y, yp_0;

assert((Y == 34));
assert((X == 34));
assert((H == 3));
assert((W == 3));
assert((C == 256));
assert((F == 512));
IND_TYPE y96 = 0;
IND_TYPE x194 = 0;
IND_TYPE h = 0;
IND_TYPE w96 = 0;
IND_TYPE c243 = 0;
IND_TYPE f96 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_15 ,scal_16 ,scal_17 ,scal_18 ,scal_19 ,scal_2 ,scal_20 ,scal_21 ,scal_22 ,scal_23 ,scal_24 ,scal_25 ,scal_26 ,scal_27 ,scal_28 ,scal_29 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m256 mem_vec_1728 ,mem_vec_1729 ,mem_vec_1730 ,mem_vec_1731 ,mem_vec_1732 ,mem_vec_1733 ,mem_vec_1734 ,mem_vec_1735 ,mem_vec_1736 ,mem_vec_1737 ,mem_vec_1738 ,mem_vec_1739 ,mem_vec_1740 ,mem_vec_1741 ,mem_vec_1742 ,mem_vec_1743 ,mem_vec_1744 ,mem_vec_1745 ,mem_vec_1746 ,mem_vec_1747 ,mem_vec_1748 ,mem_vec_1749 ,mem_vec_1750 ,mem_vec_1751 ,mem_vec_1752 ,mem_vec_1753 ,mem_vec_1754 ,mem_vec_1755 ,mem_vec_1756 ,mem_vec_1757 ,mem_vec_1758 ,mem_vec_1759 ,mem_vec_1760 ,mem_vec_1761 ,mem_vec_1762 ,mem_vec_1763 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_87 ,vec_88 ,vec_89 ,vec_9 ,vec_90 ,vec_91 ,vec_92 ,vec_93 ,vec_94 ,vec_95;
// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
// T (c, 1) (256 / 256)
for (c242 = c243, c242_p_0 = 0;
	c242 < c243 + 256;
	c242 += 256, c242_p_0 += 256){
	// y = 34, x = 34, h = 3, w = 3, c = 256, f = 512
	// T (x, 17) (34 / 2)
	for (x193 = x194, x193_p_0 = 0;
		x193 < x194 + 34;
		x193 += 2, x193_p_0 += 2){
		// y = 34, x = 2, h = 3, w = 3, c = 256, f = 512
		// T (f, 32) (512 / 16)
		for (f = f96, fp_0 = 0;
			f < f96 + 512;
			f += 16, fp_0 += 16){
			// y = 34, x = 2, h = 3, w = 3, c = 256, f = 16
			// T (c, 2) (256 / 128)
			for (c241 = c242, c241_p_1 = c242_p_0, c241_p_0 = 0;
				c241 < c242 + 256;
				c241 += 128, c241_p_1 += 128, c241_p_0 += 128){
					for (y = y96, yp_0 = 0;
						y < y96 + 24;
						y += 8, yp_0 += 8){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 16
						// T (x, 2) (2 / 1)
						for (x192 = x193, x192_p_1 = x193_p_0, x192_p_0 = 0;
							x192 < x193 + 2;
							x192 += 1, x192_p_1 += 1, x192_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
							// T (c, 8) (128 / 16)
							for (c240 = c241, c240_p_2 = c241_p_1, c240_p_1 = c241_p_0, c240_p_0 = 0;
								c240 < c241 + 128;
								c240 += 16, c240_p_2 += 16, c240_p_1 += 16, c240_p_0 += 16){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
								// T (w, 3) (3 / 1)
								for (w = w96, wp_0 = 0;
									w < w96 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
									// T (x, 1) (1 / 1)
									for (x = x192, xp_2 = x192_p_1, xp_1 = x192_p_0, xp_0 = 0;
										x < x192 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1728 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1729 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1730 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1731 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1732 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1733 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1734 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1735 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1736 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1737 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1738 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1739 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_1740 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1741 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_1742 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1743 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
												// T (c, 16) (16 / 1)
												for (c = c240, cp_3 = c240_p_2, cp_2 = c240_p_1, cp_1 = c240_p_0, cp_0 = 0;
													c < c240 + 16;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1728);
													mem_vec_1728 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1729);
													mem_vec_1729 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_1730);
													mem_vec_1730 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_1731);
													mem_vec_1731 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_1732);
													mem_vec_1732 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_1733);
													mem_vec_1733 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_1734);
													mem_vec_1734 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_1735);
													mem_vec_1735 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1736);
													mem_vec_1736 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1737);
													mem_vec_1737 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1738);
													mem_vec_1738 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1739);
													mem_vec_1739 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_1740);
													mem_vec_1740 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_1741);
													mem_vec_1741 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_1742);
													mem_vec_1742 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_1743);
													mem_vec_1743 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_27 = _mm256_set1_ps(scal_8);
													vec_28 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_26 = _mm256_fmadd_ps(vec_27, vec_28, mem_vec_1728);
													mem_vec_1728 = vec_26;

													vec_30 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_29 = _mm256_fmadd_ps(vec_27, vec_30, mem_vec_1729);
													mem_vec_1729 = vec_29;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_32 = _mm256_set1_ps(scal_9);


													vec_31 = _mm256_fmadd_ps(vec_32, vec_28, mem_vec_1730);
													mem_vec_1730 = vec_31;



													vec_33 = _mm256_fmadd_ps(vec_32, vec_30, mem_vec_1731);
													mem_vec_1731 = vec_33;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_35 = _mm256_set1_ps(scal_10);


													vec_34 = _mm256_fmadd_ps(vec_35, vec_28, mem_vec_1732);
													mem_vec_1732 = vec_34;



													vec_36 = _mm256_fmadd_ps(vec_35, vec_30, mem_vec_1733);
													mem_vec_1733 = vec_36;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_28, mem_vec_1734);
													mem_vec_1734 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_30, mem_vec_1735);
													mem_vec_1735 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_28, mem_vec_1736);
													mem_vec_1736 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_30, mem_vec_1737);
													mem_vec_1737 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_28, mem_vec_1738);
													mem_vec_1738 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_30, mem_vec_1739);
													mem_vec_1739 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_28, mem_vec_1740);
													mem_vec_1740 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_30, mem_vec_1741);
													mem_vec_1741 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_28, mem_vec_1742);
													mem_vec_1742 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_30, mem_vec_1743);
													mem_vec_1743 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_53 = _mm256_set1_ps(scal_16);
													vec_54 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_52 = _mm256_fmadd_ps(vec_53, vec_54, mem_vec_1728);
													mem_vec_1728 = vec_52;

													vec_56 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_55 = _mm256_fmadd_ps(vec_53, vec_56, mem_vec_1729);
													mem_vec_1729 = vec_55;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_58 = _mm256_set1_ps(scal_17);


													vec_57 = _mm256_fmadd_ps(vec_58, vec_54, mem_vec_1730);
													mem_vec_1730 = vec_57;



													vec_59 = _mm256_fmadd_ps(vec_58, vec_56, mem_vec_1731);
													mem_vec_1731 = vec_59;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_61 = _mm256_set1_ps(scal_18);


													vec_60 = _mm256_fmadd_ps(vec_61, vec_54, mem_vec_1732);
													mem_vec_1732 = vec_60;



													vec_62 = _mm256_fmadd_ps(vec_61, vec_56, mem_vec_1733);
													mem_vec_1733 = vec_62;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_64 = _mm256_set1_ps(scal_19);


													vec_63 = _mm256_fmadd_ps(vec_64, vec_54, mem_vec_1734);
													mem_vec_1734 = vec_63;



													vec_65 = _mm256_fmadd_ps(vec_64, vec_56, mem_vec_1735);
													mem_vec_1735 = vec_65;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_67 = _mm256_set1_ps(scal_20);


													vec_66 = _mm256_fmadd_ps(vec_67, vec_54, mem_vec_1736);
													mem_vec_1736 = vec_66;



													vec_68 = _mm256_fmadd_ps(vec_67, vec_56, mem_vec_1737);
													mem_vec_1737 = vec_68;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_54, mem_vec_1738);
													mem_vec_1738 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_56, mem_vec_1739);
													mem_vec_1739 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_54, mem_vec_1740);
													mem_vec_1740 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_56, mem_vec_1741);
													mem_vec_1741 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_54, mem_vec_1742);
													mem_vec_1742 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_56, mem_vec_1743);
													mem_vec_1743 = vec_77;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1728);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1729);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1730);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1731);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1732);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1733);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1734);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1735);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1736);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1737);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1738);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1739);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1740);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1741);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1742);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_1743);
									}
								}
							}
						}
					}
					for (y = y96 + 24, yp_0 = 0;
						y < y96 + 24 + 10;
						y += 10, yp_0 += 10){
						// y = ph_y, x = 2, h = 3, w = 3, c = 128, f = 16
						// T (x, 2) (2 / 1)
						for (x192 = x193, x192_p_1 = x193_p_0, x192_p_0 = 0;
							x192 < x193 + 2;
							x192 += 1, x192_p_1 += 1, x192_p_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 128, f = 16
							// T (c, 8) (128 / 16)
							for (c240 = c241, c240_p_2 = c241_p_1, c240_p_1 = c241_p_0, c240_p_0 = 0;
								c240 < c241 + 128;
								c240 += 16, c240_p_2 += 16, c240_p_1 += 16, c240_p_0 += 16){
								// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 16
								// T (w, 3) (3 / 1)
								for (w = w96, wp_0 = 0;
									w < w96 + 3;
									w += 1, wp_0 += 1){
									// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
									// T (x, 1) (1 / 1)
									for (x = x192, xp_2 = x192_p_1, xp_1 = x192_p_0, xp_0 = 0;
										x < x192 + 1;
										x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
												mem_vec_1744 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f]);
												mem_vec_1745 = _mm256_loadu_ps(&output[(F * Y) * x + F * y + f + 8]);
												mem_vec_1746 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
												mem_vec_1747 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8]);
												mem_vec_1748 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
												mem_vec_1749 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8]);
												mem_vec_1750 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
												mem_vec_1751 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8]);
												mem_vec_1752 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
												mem_vec_1753 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8]);
												mem_vec_1754 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
												mem_vec_1755 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8]);
												mem_vec_1756 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
												mem_vec_1757 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8]);
												mem_vec_1758 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
												mem_vec_1759 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8]);
												mem_vec_1760 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
												mem_vec_1761 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8]);
												mem_vec_1762 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
												mem_vec_1763 = _mm256_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8]);
												// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 16
												// T (c, 16) (16 / 1)
												for (c = c240, cp_3 = c240_p_2, cp_2 = c240_p_1, cp_1 = c240_p_0, cp_0 = 0;
													c < c240 + 16;
													c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
													scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
													vec_1 = _mm256_set1_ps(scal_0);
													vec_2 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

													vec_0 = _mm256_fmadd_ps(vec_1, vec_2, mem_vec_1744);
													mem_vec_1744 = vec_0;

													vec_4 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 8]);

													vec_3 = _mm256_fmadd_ps(vec_1, vec_4, mem_vec_1745);
													mem_vec_1745 = vec_3;
													scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
													vec_6 = _mm256_set1_ps(scal_1);


													vec_5 = _mm256_fmadd_ps(vec_6, vec_2, mem_vec_1746);
													mem_vec_1746 = vec_5;



													vec_7 = _mm256_fmadd_ps(vec_6, vec_4, mem_vec_1747);
													mem_vec_1747 = vec_7;
													scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
													vec_9 = _mm256_set1_ps(scal_2);


													vec_8 = _mm256_fmadd_ps(vec_9, vec_2, mem_vec_1748);
													mem_vec_1748 = vec_8;



													vec_10 = _mm256_fmadd_ps(vec_9, vec_4, mem_vec_1749);
													mem_vec_1749 = vec_10;
													scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
													vec_12 = _mm256_set1_ps(scal_3);


													vec_11 = _mm256_fmadd_ps(vec_12, vec_2, mem_vec_1750);
													mem_vec_1750 = vec_11;



													vec_13 = _mm256_fmadd_ps(vec_12, vec_4, mem_vec_1751);
													mem_vec_1751 = vec_13;
													scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
													vec_15 = _mm256_set1_ps(scal_4);


													vec_14 = _mm256_fmadd_ps(vec_15, vec_2, mem_vec_1752);
													mem_vec_1752 = vec_14;



													vec_16 = _mm256_fmadd_ps(vec_15, vec_4, mem_vec_1753);
													mem_vec_1753 = vec_16;
													scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
													vec_18 = _mm256_set1_ps(scal_5);


													vec_17 = _mm256_fmadd_ps(vec_18, vec_2, mem_vec_1754);
													mem_vec_1754 = vec_17;



													vec_19 = _mm256_fmadd_ps(vec_18, vec_4, mem_vec_1755);
													mem_vec_1755 = vec_19;
													scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
													vec_21 = _mm256_set1_ps(scal_6);


													vec_20 = _mm256_fmadd_ps(vec_21, vec_2, mem_vec_1756);
													mem_vec_1756 = vec_20;



													vec_22 = _mm256_fmadd_ps(vec_21, vec_4, mem_vec_1757);
													mem_vec_1757 = vec_22;
													scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
													vec_24 = _mm256_set1_ps(scal_7);


													vec_23 = _mm256_fmadd_ps(vec_24, vec_2, mem_vec_1758);
													mem_vec_1758 = vec_23;



													vec_25 = _mm256_fmadd_ps(vec_24, vec_4, mem_vec_1759);
													mem_vec_1759 = vec_25;
													scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
													vec_27 = _mm256_set1_ps(scal_8);


													vec_26 = _mm256_fmadd_ps(vec_27, vec_2, mem_vec_1760);
													mem_vec_1760 = vec_26;



													vec_28 = _mm256_fmadd_ps(vec_27, vec_4, mem_vec_1761);
													mem_vec_1761 = vec_28;
													scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
													vec_30 = _mm256_set1_ps(scal_9);


													vec_29 = _mm256_fmadd_ps(vec_30, vec_2, mem_vec_1762);
													mem_vec_1762 = vec_29;



													vec_31 = _mm256_fmadd_ps(vec_30, vec_4, mem_vec_1763);
													mem_vec_1763 = vec_31;
													scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
													vec_33 = _mm256_set1_ps(scal_10);
													vec_34 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

													vec_32 = _mm256_fmadd_ps(vec_33, vec_34, mem_vec_1744);
													mem_vec_1744 = vec_32;

													vec_36 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 8]);

													vec_35 = _mm256_fmadd_ps(vec_33, vec_36, mem_vec_1745);
													mem_vec_1745 = vec_35;
													scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
													vec_38 = _mm256_set1_ps(scal_11);


													vec_37 = _mm256_fmadd_ps(vec_38, vec_34, mem_vec_1746);
													mem_vec_1746 = vec_37;



													vec_39 = _mm256_fmadd_ps(vec_38, vec_36, mem_vec_1747);
													mem_vec_1747 = vec_39;
													scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
													vec_41 = _mm256_set1_ps(scal_12);


													vec_40 = _mm256_fmadd_ps(vec_41, vec_34, mem_vec_1748);
													mem_vec_1748 = vec_40;



													vec_42 = _mm256_fmadd_ps(vec_41, vec_36, mem_vec_1749);
													mem_vec_1749 = vec_42;
													scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
													vec_44 = _mm256_set1_ps(scal_13);


													vec_43 = _mm256_fmadd_ps(vec_44, vec_34, mem_vec_1750);
													mem_vec_1750 = vec_43;



													vec_45 = _mm256_fmadd_ps(vec_44, vec_36, mem_vec_1751);
													mem_vec_1751 = vec_45;
													scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
													vec_47 = _mm256_set1_ps(scal_14);


													vec_46 = _mm256_fmadd_ps(vec_47, vec_34, mem_vec_1752);
													mem_vec_1752 = vec_46;



													vec_48 = _mm256_fmadd_ps(vec_47, vec_36, mem_vec_1753);
													mem_vec_1753 = vec_48;
													scal_15 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 1) + c];
													vec_50 = _mm256_set1_ps(scal_15);


													vec_49 = _mm256_fmadd_ps(vec_50, vec_34, mem_vec_1754);
													mem_vec_1754 = vec_49;



													vec_51 = _mm256_fmadd_ps(vec_50, vec_36, mem_vec_1755);
													mem_vec_1755 = vec_51;
													scal_16 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 1) + c];
													vec_53 = _mm256_set1_ps(scal_16);


													vec_52 = _mm256_fmadd_ps(vec_53, vec_34, mem_vec_1756);
													mem_vec_1756 = vec_52;



													vec_54 = _mm256_fmadd_ps(vec_53, vec_36, mem_vec_1757);
													mem_vec_1757 = vec_54;
													scal_17 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 1) + c];
													vec_56 = _mm256_set1_ps(scal_17);


													vec_55 = _mm256_fmadd_ps(vec_56, vec_34, mem_vec_1758);
													mem_vec_1758 = vec_55;



													vec_57 = _mm256_fmadd_ps(vec_56, vec_36, mem_vec_1759);
													mem_vec_1759 = vec_57;
													scal_18 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 1) + c];
													vec_59 = _mm256_set1_ps(scal_18);


													vec_58 = _mm256_fmadd_ps(vec_59, vec_34, mem_vec_1760);
													mem_vec_1760 = vec_58;



													vec_60 = _mm256_fmadd_ps(vec_59, vec_36, mem_vec_1761);
													mem_vec_1761 = vec_60;
													scal_19 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 1) + c];
													vec_62 = _mm256_set1_ps(scal_19);


													vec_61 = _mm256_fmadd_ps(vec_62, vec_34, mem_vec_1762);
													mem_vec_1762 = vec_61;



													vec_63 = _mm256_fmadd_ps(vec_62, vec_36, mem_vec_1763);
													mem_vec_1763 = vec_63;
													scal_20 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
													vec_65 = _mm256_set1_ps(scal_20);
													vec_66 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

													vec_64 = _mm256_fmadd_ps(vec_65, vec_66, mem_vec_1744);
													mem_vec_1744 = vec_64;

													vec_68 = _mm256_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 8]);

													vec_67 = _mm256_fmadd_ps(vec_65, vec_68, mem_vec_1745);
													mem_vec_1745 = vec_67;
													scal_21 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
													vec_70 = _mm256_set1_ps(scal_21);


													vec_69 = _mm256_fmadd_ps(vec_70, vec_66, mem_vec_1746);
													mem_vec_1746 = vec_69;



													vec_71 = _mm256_fmadd_ps(vec_70, vec_68, mem_vec_1747);
													mem_vec_1747 = vec_71;
													scal_22 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
													vec_73 = _mm256_set1_ps(scal_22);


													vec_72 = _mm256_fmadd_ps(vec_73, vec_66, mem_vec_1748);
													mem_vec_1748 = vec_72;



													vec_74 = _mm256_fmadd_ps(vec_73, vec_68, mem_vec_1749);
													mem_vec_1749 = vec_74;
													scal_23 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
													vec_76 = _mm256_set1_ps(scal_23);


													vec_75 = _mm256_fmadd_ps(vec_76, vec_66, mem_vec_1750);
													mem_vec_1750 = vec_75;



													vec_77 = _mm256_fmadd_ps(vec_76, vec_68, mem_vec_1751);
													mem_vec_1751 = vec_77;
													scal_24 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
													vec_79 = _mm256_set1_ps(scal_24);


													vec_78 = _mm256_fmadd_ps(vec_79, vec_66, mem_vec_1752);
													mem_vec_1752 = vec_78;



													vec_80 = _mm256_fmadd_ps(vec_79, vec_68, mem_vec_1753);
													mem_vec_1753 = vec_80;
													scal_25 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h + 2) + c];
													vec_82 = _mm256_set1_ps(scal_25);


													vec_81 = _mm256_fmadd_ps(vec_82, vec_66, mem_vec_1754);
													mem_vec_1754 = vec_81;



													vec_83 = _mm256_fmadd_ps(vec_82, vec_68, mem_vec_1755);
													mem_vec_1755 = vec_83;
													scal_26 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h + 2) + c];
													vec_85 = _mm256_set1_ps(scal_26);


													vec_84 = _mm256_fmadd_ps(vec_85, vec_66, mem_vec_1756);
													mem_vec_1756 = vec_84;



													vec_86 = _mm256_fmadd_ps(vec_85, vec_68, mem_vec_1757);
													mem_vec_1757 = vec_86;
													scal_27 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h + 2) + c];
													vec_88 = _mm256_set1_ps(scal_27);


													vec_87 = _mm256_fmadd_ps(vec_88, vec_66, mem_vec_1758);
													mem_vec_1758 = vec_87;



													vec_89 = _mm256_fmadd_ps(vec_88, vec_68, mem_vec_1759);
													mem_vec_1759 = vec_89;
													scal_28 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h + 2) + c];
													vec_91 = _mm256_set1_ps(scal_28);


													vec_90 = _mm256_fmadd_ps(vec_91, vec_66, mem_vec_1760);
													mem_vec_1760 = vec_90;



													vec_92 = _mm256_fmadd_ps(vec_91, vec_68, mem_vec_1761);
													mem_vec_1761 = vec_92;
													scal_29 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h + 2) + c];
													vec_94 = _mm256_set1_ps(scal_29);


													vec_93 = _mm256_fmadd_ps(vec_94, vec_66, mem_vec_1762);
													mem_vec_1762 = vec_93;



													vec_95 = _mm256_fmadd_ps(vec_94, vec_68, mem_vec_1763);
													mem_vec_1763 = vec_95;
												}
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1744);
											_mm256_storeu_ps(&output[(F * Y) * x + F * y + f + 8], mem_vec_1745);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1746);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 8], mem_vec_1747);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1748);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 8], mem_vec_1749);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1750);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 8], mem_vec_1751);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1752);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 8], mem_vec_1753);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_1754);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 8], mem_vec_1755);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_1756);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 8], mem_vec_1757);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_1758);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 8], mem_vec_1759);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_1760);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 8], mem_vec_1761);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_1762);
											_mm256_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 8], mem_vec_1763);
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