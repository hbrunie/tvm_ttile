#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; U (3, h); T (16, c); Hoist_vars [c]; T (1, x);
  T (3, w); T (2, c); T (1, x); T (1, y); T (17, y); T (272, x);
  Lambda_apply y [((Iter 3), (Arg 2)); ((Iter 2), (Arg 5))]]
*/
IND_TYPE c, cp_0, c549_p_0, cp_1, c549, w, wp_0, x, xp_0, x732_p_0, x733_p_0, xp_1, x732_p_1, xp_2, x732, x733, y, yp_0, y726_p_0, y727_p_0, yp_1, y726_p_1, yp_2, y726, y727;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y728 = 0;
IND_TYPE x734 = 0;
IND_TYPE h = 0;
IND_TYPE w273 = 0;
IND_TYPE c550 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_14 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_1743 ,mem_vec_1744 ,mem_vec_1745 ,mem_vec_1746 ,mem_vec_1747 ,mem_vec_1748 ,mem_vec_1749 ,mem_vec_1750 ,mem_vec_1751 ,mem_vec_1752 ,mem_vec_1753 ,mem_vec_1754 ,mem_vec_1755 ,mem_vec_1756 ,mem_vec_1757 ,mem_vec_1758 ,mem_vec_1759 ,mem_vec_1760 ,mem_vec_1761 ,mem_vec_1762 ,mem_vec_1763 ,mem_vec_1764 ,mem_vec_1765 ,mem_vec_1766 ,mem_vec_1767 ,mem_vec_1768 ,mem_vec_1769 ,mem_vec_1770 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_44 ,vec_45 ,vec_46 ,vec_47 ,vec_48 ,vec_49 ,vec_5 ,vec_50 ,vec_51 ,vec_52 ,vec_53 ,vec_54 ,vec_55 ,vec_56 ,vec_57 ,vec_58 ,vec_59 ,vec_6 ,vec_60 ,vec_61 ,vec_62 ,vec_63 ,vec_64 ,vec_65 ,vec_66 ,vec_67 ,vec_68 ,vec_69 ,vec_7 ,vec_70 ,vec_71 ,vec_72 ,vec_73 ,vec_74 ,vec_75 ,vec_76 ,vec_77 ,vec_78 ,vec_79 ,vec_8 ,vec_80 ,vec_81 ,vec_82 ,vec_83 ,vec_84 ,vec_85 ,vec_86 ,vec_9;
	for (y727 = y728, y727_p_0 = 0;
		y727 < y728 + 102;
		y727 += 34, y727_p_0 += 34){
		// y = 17 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 272) (272 / 1)
		for (x733 = x734, x733_p_0 = 0;
			x733 < x734 + 272;
			x733 += 1, x733_p_0 += 1){
			// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 17) (17 * ph_y / ph_y)
			for (y726 = y727, y726_p_1 = y727_p_0, y726_p_0 = 0;
				y726 < y727 + 34;
				y726 += 2, y726_p_1 += 2, y726_p_0 += 2){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y726, yp_2 = y726_p_1, yp_1 = y726_p_0, yp_0 = 0;
					y < y726 + 2;
					y += 2, yp_2 += 2, yp_1 += 2, yp_0 += 2){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (x, 1) (1 / 1)
					for (x732 = x733, x732_p_1 = x733_p_0, x732_p_0 = 0;
						x732 < x733 + 1;
						x732 += 1, x732_p_1 += 1, x732_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (c, 2) (32 / 16)
						for (c549 = c550, c549_p_0 = 0;
							c549 < c550 + 32;
							c549 += 16, c549_p_0 += 16){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
							// T (w, 3) (3 / 1)
							for (w = w273, wp_0 = 0;
								w < w273 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
								// T (x, 1) (1 / 1)
								for (x = x732, xp_2 = x732_p_1, xp_1 = x732_p_0, xp_0 = 0;
									x < x732 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1743 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1744 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1745 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_1746 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_1747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_1750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
											// T (c, 16) (16 / 1)
											for (c = c549, cp_1 = c549_p_0, cp_0 = 0;
												c < c549 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1743);
												mem_vec_1743 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1744);
												mem_vec_1744 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1745);
												mem_vec_1745 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1746);
												mem_vec_1746 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1747);
												mem_vec_1747 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1748);
												mem_vec_1748 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1749);
												mem_vec_1749 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1750);
												mem_vec_1750 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_15 = _mm512_set1_ps(scal_2);
												vec_16 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_14 = _mm512_fmadd_ps(vec_15, vec_16, mem_vec_1743);
												mem_vec_1743 = vec_14;

												vec_18 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_17 = _mm512_fmadd_ps(vec_15, vec_18, mem_vec_1744);
												mem_vec_1744 = vec_17;

												vec_20 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_19 = _mm512_fmadd_ps(vec_15, vec_20, mem_vec_1745);
												mem_vec_1745 = vec_19;

												vec_22 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_21 = _mm512_fmadd_ps(vec_15, vec_22, mem_vec_1746);
												mem_vec_1746 = vec_21;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_24 = _mm512_set1_ps(scal_3);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_16, mem_vec_1747);
												mem_vec_1747 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_18, mem_vec_1748);
												mem_vec_1748 = vec_25;



												vec_26 = _mm512_fmadd_ps(vec_24, vec_20, mem_vec_1749);
												mem_vec_1749 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_24, vec_22, mem_vec_1750);
												mem_vec_1750 = vec_27;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_29 = _mm512_set1_ps(scal_4);
												vec_30 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_28 = _mm512_fmadd_ps(vec_29, vec_30, mem_vec_1743);
												mem_vec_1743 = vec_28;

												vec_32 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_31 = _mm512_fmadd_ps(vec_29, vec_32, mem_vec_1744);
												mem_vec_1744 = vec_31;

												vec_34 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_33 = _mm512_fmadd_ps(vec_29, vec_34, mem_vec_1745);
												mem_vec_1745 = vec_33;

												vec_36 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_35 = _mm512_fmadd_ps(vec_29, vec_36, mem_vec_1746);
												mem_vec_1746 = vec_35;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_38 = _mm512_set1_ps(scal_5);


												vec_37 = _mm512_fmadd_ps(vec_38, vec_30, mem_vec_1747);
												mem_vec_1747 = vec_37;



												vec_39 = _mm512_fmadd_ps(vec_38, vec_32, mem_vec_1748);
												mem_vec_1748 = vec_39;



												vec_40 = _mm512_fmadd_ps(vec_38, vec_34, mem_vec_1749);
												mem_vec_1749 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_38, vec_36, mem_vec_1750);
												mem_vec_1750 = vec_41;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1743);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1744);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1745);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1746);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1747);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1748);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1749);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1750);
								}
							}
						}
					}
				}
			}
		}
	}
	for (y727 = y728 + 102, y727_p_0 = 0;
		y727 < y728 + 102 + 170;
		y727 += 85, y727_p_0 += 85){
		// y = 17 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 272) (272 / 1)
		for (x733 = x734, x733_p_0 = 0;
			x733 < x734 + 272;
			x733 += 1, x733_p_0 += 1){
			// y = 17 * ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
			// T (y, 17) (17 * ph_y / ph_y)
			for (y726 = y727, y726_p_1 = y727_p_0, y726_p_0 = 0;
				y726 < y727 + 85;
				y726 += 5, y726_p_1 += 5, y726_p_0 += 5){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (y, 1) (ph_y / ph_y)
				for (y = y726, yp_2 = y726_p_1, yp_1 = y726_p_0, yp_0 = 0;
					y < y726 + 5;
					y += 5, yp_2 += 5, yp_1 += 5, yp_0 += 5){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (x, 1) (1 / 1)
					for (x732 = x733, x732_p_1 = x733_p_0, x732_p_0 = 0;
						x732 < x733 + 1;
						x732 += 1, x732_p_1 += 1, x732_p_0 += 1){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (c, 2) (32 / 16)
						for (c549 = c550, c549_p_0 = 0;
							c549 < c550 + 32;
							c549 += 16, c549_p_0 += 16){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 64
							// T (w, 3) (3 / 1)
							for (w = w273, wp_0 = 0;
								w < w273 + 3;
								w += 1, wp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
								// T (x, 1) (1 / 1)
								for (x = x732, xp_2 = x732_p_1, xp_1 = x732_p_0, xp_0 = 0;
									x < x732 + 1;
									x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
											mem_vec_1751 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_1752 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_1753 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
											mem_vec_1754 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
											mem_vec_1755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_1756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_1757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
											mem_vec_1758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
											mem_vec_1759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_1760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_1761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
											mem_vec_1762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
											mem_vec_1763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_1764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_1765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
											mem_vec_1766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
											mem_vec_1767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_1768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_1769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
											mem_vec_1770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
											// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 64
											// T (c, 16) (16 / 1)
											for (c = c549, cp_1 = c549_p_0, cp_0 = 0;
												c < c549 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_1751);
												mem_vec_1751 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_1752);
												mem_vec_1752 = vec_3;

												vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

												vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_1753);
												mem_vec_1753 = vec_5;

												vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

												vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_1754);
												mem_vec_1754 = vec_7;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_10 = _mm512_set1_ps(scal_1);


												vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_1755);
												mem_vec_1755 = vec_9;



												vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_1756);
												mem_vec_1756 = vec_11;



												vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_1757);
												mem_vec_1757 = vec_12;



												vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_1758);
												mem_vec_1758 = vec_13;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_15 = _mm512_set1_ps(scal_2);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_1759);
												mem_vec_1759 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_1760);
												mem_vec_1760 = vec_16;



												vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_1761);
												mem_vec_1761 = vec_17;



												vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_1762);
												mem_vec_1762 = vec_18;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_20 = _mm512_set1_ps(scal_3);


												vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_1763);
												mem_vec_1763 = vec_19;



												vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_1764);
												mem_vec_1764 = vec_21;



												vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_1765);
												mem_vec_1765 = vec_22;



												vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_1766);
												mem_vec_1766 = vec_23;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_25 = _mm512_set1_ps(scal_4);


												vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_1767);
												mem_vec_1767 = vec_24;



												vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_1768);
												mem_vec_1768 = vec_26;



												vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_1769);
												mem_vec_1769 = vec_27;



												vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_1770);
												mem_vec_1770 = vec_28;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 1) + c];
												vec_30 = _mm512_set1_ps(scal_5);
												vec_31 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f]);

												vec_29 = _mm512_fmadd_ps(vec_30, vec_31, mem_vec_1751);
												mem_vec_1751 = vec_29;

												vec_33 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 16]);

												vec_32 = _mm512_fmadd_ps(vec_30, vec_33, mem_vec_1752);
												mem_vec_1752 = vec_32;

												vec_35 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 32]);

												vec_34 = _mm512_fmadd_ps(vec_30, vec_35, mem_vec_1753);
												mem_vec_1753 = vec_34;

												vec_37 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 1) + F * c + f + 48]);

												vec_36 = _mm512_fmadd_ps(vec_30, vec_37, mem_vec_1754);
												mem_vec_1754 = vec_36;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 1) + c];
												vec_39 = _mm512_set1_ps(scal_6);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_31, mem_vec_1755);
												mem_vec_1755 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_33, mem_vec_1756);
												mem_vec_1756 = vec_40;



												vec_41 = _mm512_fmadd_ps(vec_39, vec_35, mem_vec_1757);
												mem_vec_1757 = vec_41;



												vec_42 = _mm512_fmadd_ps(vec_39, vec_37, mem_vec_1758);
												mem_vec_1758 = vec_42;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 1) + c];
												vec_44 = _mm512_set1_ps(scal_7);


												vec_43 = _mm512_fmadd_ps(vec_44, vec_31, mem_vec_1759);
												mem_vec_1759 = vec_43;



												vec_45 = _mm512_fmadd_ps(vec_44, vec_33, mem_vec_1760);
												mem_vec_1760 = vec_45;



												vec_46 = _mm512_fmadd_ps(vec_44, vec_35, mem_vec_1761);
												mem_vec_1761 = vec_46;



												vec_47 = _mm512_fmadd_ps(vec_44, vec_37, mem_vec_1762);
												mem_vec_1762 = vec_47;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 1) + c];
												vec_49 = _mm512_set1_ps(scal_8);


												vec_48 = _mm512_fmadd_ps(vec_49, vec_31, mem_vec_1763);
												mem_vec_1763 = vec_48;



												vec_50 = _mm512_fmadd_ps(vec_49, vec_33, mem_vec_1764);
												mem_vec_1764 = vec_50;



												vec_51 = _mm512_fmadd_ps(vec_49, vec_35, mem_vec_1765);
												mem_vec_1765 = vec_51;



												vec_52 = _mm512_fmadd_ps(vec_49, vec_37, mem_vec_1766);
												mem_vec_1766 = vec_52;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 1) + c];
												vec_54 = _mm512_set1_ps(scal_9);


												vec_53 = _mm512_fmadd_ps(vec_54, vec_31, mem_vec_1767);
												mem_vec_1767 = vec_53;



												vec_55 = _mm512_fmadd_ps(vec_54, vec_33, mem_vec_1768);
												mem_vec_1768 = vec_55;



												vec_56 = _mm512_fmadd_ps(vec_54, vec_35, mem_vec_1769);
												mem_vec_1769 = vec_56;



												vec_57 = _mm512_fmadd_ps(vec_54, vec_37, mem_vec_1770);
												mem_vec_1770 = vec_57;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h + 2) + c];
												vec_59 = _mm512_set1_ps(scal_10);
												vec_60 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f]);

												vec_58 = _mm512_fmadd_ps(vec_59, vec_60, mem_vec_1751);
												mem_vec_1751 = vec_58;

												vec_62 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 16]);

												vec_61 = _mm512_fmadd_ps(vec_59, vec_62, mem_vec_1752);
												mem_vec_1752 = vec_61;

												vec_64 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 32]);

												vec_63 = _mm512_fmadd_ps(vec_59, vec_64, mem_vec_1753);
												mem_vec_1753 = vec_63;

												vec_66 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * (h + 2) + F * c + f + 48]);

												vec_65 = _mm512_fmadd_ps(vec_59, vec_66, mem_vec_1754);
												mem_vec_1754 = vec_65;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h + 2) + c];
												vec_68 = _mm512_set1_ps(scal_11);


												vec_67 = _mm512_fmadd_ps(vec_68, vec_60, mem_vec_1755);
												mem_vec_1755 = vec_67;



												vec_69 = _mm512_fmadd_ps(vec_68, vec_62, mem_vec_1756);
												mem_vec_1756 = vec_69;



												vec_70 = _mm512_fmadd_ps(vec_68, vec_64, mem_vec_1757);
												mem_vec_1757 = vec_70;



												vec_71 = _mm512_fmadd_ps(vec_68, vec_66, mem_vec_1758);
												mem_vec_1758 = vec_71;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h + 2) + c];
												vec_73 = _mm512_set1_ps(scal_12);


												vec_72 = _mm512_fmadd_ps(vec_73, vec_60, mem_vec_1759);
												mem_vec_1759 = vec_72;



												vec_74 = _mm512_fmadd_ps(vec_73, vec_62, mem_vec_1760);
												mem_vec_1760 = vec_74;



												vec_75 = _mm512_fmadd_ps(vec_73, vec_64, mem_vec_1761);
												mem_vec_1761 = vec_75;



												vec_76 = _mm512_fmadd_ps(vec_73, vec_66, mem_vec_1762);
												mem_vec_1762 = vec_76;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h + 2) + c];
												vec_78 = _mm512_set1_ps(scal_13);


												vec_77 = _mm512_fmadd_ps(vec_78, vec_60, mem_vec_1763);
												mem_vec_1763 = vec_77;



												vec_79 = _mm512_fmadd_ps(vec_78, vec_62, mem_vec_1764);
												mem_vec_1764 = vec_79;



												vec_80 = _mm512_fmadd_ps(vec_78, vec_64, mem_vec_1765);
												mem_vec_1765 = vec_80;



												vec_81 = _mm512_fmadd_ps(vec_78, vec_66, mem_vec_1766);
												mem_vec_1766 = vec_81;
												scal_14 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h + 2) + c];
												vec_83 = _mm512_set1_ps(scal_14);


												vec_82 = _mm512_fmadd_ps(vec_83, vec_60, mem_vec_1767);
												mem_vec_1767 = vec_82;



												vec_84 = _mm512_fmadd_ps(vec_83, vec_62, mem_vec_1768);
												mem_vec_1768 = vec_84;



												vec_85 = _mm512_fmadd_ps(vec_83, vec_64, mem_vec_1769);
												mem_vec_1769 = vec_85;



												vec_86 = _mm512_fmadd_ps(vec_83, vec_66, mem_vec_1770);
												mem_vec_1770 = vec_86;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_1751);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_1752);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_1753);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_1754);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_1755);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_1756);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_1757);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_1758);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_1759);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_1760);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_1761);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_1762);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_1763);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_1764);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_1765);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_1766);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_1767);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_1768);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_1769);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_1770);
								}
							}
						}
					}
				}
			}
		}
	}


}