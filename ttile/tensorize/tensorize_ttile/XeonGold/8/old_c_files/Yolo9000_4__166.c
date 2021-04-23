#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, h); T (34, x);
  T (3, w); T (4, c); T (4, f); T (4, x);
  Lambda_apply y [((Iter 7), (Arg 10)); ((Iter 6), (Arg 11))]; T (1, x)]
*/
IND_TYPE c, cp_0, c45_p_0, cp_1, c45, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x60_p_0, x61_p_0, xp_1, x60_p_1, xp_2, x60, x61, y, yp_0;

assert((Y == 136));
assert((X == 136));
assert((H == 3));
assert((W == 3));
assert((C == 64));
assert((F == 128));
IND_TYPE y30 = 0;
IND_TYPE x62 = 0;
IND_TYPE h30 = 0;
IND_TYPE w30 = 0;
IND_TYPE c46 = 0;
IND_TYPE f30 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_756 ,mem_vec_757 ,mem_vec_758 ,mem_vec_759 ,mem_vec_760 ,mem_vec_761 ,mem_vec_762 ,mem_vec_763 ,mem_vec_764 ,mem_vec_765 ,mem_vec_766 ,mem_vec_767 ,mem_vec_768 ,mem_vec_769 ,mem_vec_770 ,mem_vec_771 ,mem_vec_772 ,mem_vec_773 ,mem_vec_774 ,mem_vec_775 ,mem_vec_776 ,mem_vec_777 ,mem_vec_778 ,mem_vec_779 ,mem_vec_780 ,mem_vec_781 ,mem_vec_782 ,mem_vec_783 ,mem_vec_784 ,mem_vec_785 ,mem_vec_786 ,mem_vec_787 ,mem_vec_788 ,mem_vec_789 ,mem_vec_790 ,mem_vec_791 ,mem_vec_792 ,mem_vec_793 ,mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 3, w = 3, c = 64, f = 128
// T (x, 1) (136 / 136)
for (x61 = x62, x61_p_0 = 0;
	x61 < x62 + 136;
	x61 += 136, x61_p_0 += 136){
		for (y = y30, yp_0 = 0;
			y < y30 + 70;
			y += 10, yp_0 += 10){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x60 = x61, x60_p_1 = x61_p_0, x60_p_0 = 0;
				x60 < x61 + 136;
				x60 += 34, x60_p_1 += 34, x60_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f30, fp_0 = 0;
					f < f30 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c45 = c46, c45_p_0 = 0;
						c45 < c46 + 64;
						c45 += 16, c45_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w30, wp_0 = 0;
							w < w30 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x60, xp_2 = x60_p_1, xp_1 = x60_p_0, xp_0 = 0;
								x < x60 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h30, hp_0 = 0;
									h < h30 + 3;
									h += 1, hp_0 += 1){
											mem_vec_756 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_757 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_767 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_768 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_769 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_770 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_771 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_772 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_773 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_774 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_775 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
												c < c45 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_756);
												mem_vec_756 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_757);
												mem_vec_757 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_758);
												mem_vec_758 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_759);
												mem_vec_759 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_760);
												mem_vec_760 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_761);
												mem_vec_761 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_762);
												mem_vec_762 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_763);
												mem_vec_763 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_764);
												mem_vec_764 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_765);
												mem_vec_765 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_766);
												mem_vec_766 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_767);
												mem_vec_767 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_768);
												mem_vec_768 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_769);
												mem_vec_769 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_770);
												mem_vec_770 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_771);
												mem_vec_771 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_772);
												mem_vec_772 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_773);
												mem_vec_773 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_774);
												mem_vec_774 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_775);
												mem_vec_775 = vec_31;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_756);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_757);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_758);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_759);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_760);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_761);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_762);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_763);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_764);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_765);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_766);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_767);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_768);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_769);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_770);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_771);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_772);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_773);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_774);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_775);
								}
							}
						}
					}
				}
			}
		}
		for (y = y30 + 70, yp_0 = 0;
			y < y30 + 70 + 66;
			y += 11, yp_0 += 11){
			// y = ph_y, x = 136, h = 3, w = 3, c = 64, f = 128
			// T (x, 4) (136 / 34)
			for (x60 = x61, x60_p_1 = x61_p_0, x60_p_0 = 0;
				x60 < x61 + 136;
				x60 += 34, x60_p_1 += 34, x60_p_0 += 34){
				// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 128
				// T (f, 4) (128 / 32)
				for (f = f30, fp_0 = 0;
					f < f30 + 128;
					f += 32, fp_0 += 32){
					// y = ph_y, x = 34, h = 3, w = 3, c = 64, f = 32
					// T (c, 4) (64 / 16)
					for (c45 = c46, c45_p_0 = 0;
						c45 < c46 + 64;
						c45 += 16, c45_p_0 += 16){
						// y = ph_y, x = 34, h = 3, w = 3, c = 16, f = 32
						// T (w, 3) (3 / 1)
						for (w = w30, wp_0 = 0;
							w < w30 + 3;
							w += 1, wp_0 += 1){
							// y = ph_y, x = 34, h = 3, w = 1, c = 16, f = 32
							// T (x, 34) (34 / 1)
							for (x = x60, xp_2 = x60_p_1, xp_1 = x60_p_0, xp_0 = 0;
								x < x60 + 34;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
								// y = ph_y, x = 1, h = 3, w = 1, c = 16, f = 32
								// T (h, 3) (3 / 1)
								for (h = h30, hp_0 = 0;
									h < h30 + 3;
									h += 1, hp_0 += 1){
											mem_vec_776 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_777 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_778 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_779 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_780 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_781 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_782 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_783 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_784 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_785 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_786 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_787 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_788 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_789 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_790 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_791 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_792 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_793 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_794 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_795 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c45, cp_1 = c45_p_0, cp_0 = 0;
												c < c45 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_776);
												mem_vec_776 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_777);
												mem_vec_777 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_778);
												mem_vec_778 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_779);
												mem_vec_779 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_780);
												mem_vec_780 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_781);
												mem_vec_781 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_782);
												mem_vec_782 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_783);
												mem_vec_783 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_784);
												mem_vec_784 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_785);
												mem_vec_785 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_786);
												mem_vec_786 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_787);
												mem_vec_787 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_788);
												mem_vec_788 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_789);
												mem_vec_789 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_790);
												mem_vec_790 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_791);
												mem_vec_791 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_792);
												mem_vec_792 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_793);
												mem_vec_793 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_794);
												mem_vec_794 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_795);
												mem_vec_795 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_796);
												mem_vec_796 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_797);
												mem_vec_797 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_776);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_777);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_778);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_779);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_780);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_781);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_782);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_783);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_784);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_785);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_786);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_787);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_788);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_789);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_790);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_791);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_792);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_793);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_794);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_795);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_796);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_797);
								}
							}
						}
					}
				}
			}
		}
}


}