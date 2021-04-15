#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (1, x); T (2, f); T (1, c);
  Lambda_apply y [((Iter 6), (Arg 11)); ((Iter 5), (Arg 14))]; T (272, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c63_p_0, cp_1, c63, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x72_p_0, xp_1, x72, y, yp_0, y72_p_0, yp_1, y72;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y73 = 0;
IND_TYPE x73 = 0;
IND_TYPE h33 = 0;
IND_TYPE w42 = 0;
IND_TYPE c64 = 0;
IND_TYPE f42 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_699 ,mem_vec_700 ,mem_vec_701 ,mem_vec_702 ,mem_vec_703 ,mem_vec_704 ,mem_vec_705 ,mem_vec_706 ,mem_vec_707 ,mem_vec_708 ,mem_vec_709 ,mem_vec_710 ,mem_vec_711 ,mem_vec_712 ,mem_vec_713 ,mem_vec_714 ,mem_vec_715 ,mem_vec_716 ,mem_vec_717 ,mem_vec_718 ,mem_vec_719 ,mem_vec_720 ,mem_vec_721 ,mem_vec_722 ,mem_vec_723 ,mem_vec_724 ,mem_vec_725 ,mem_vec_726 ,mem_vec_727 ,mem_vec_728 ,mem_vec_729 ,mem_vec_730 ,mem_vec_731 ,mem_vec_732 ,mem_vec_733 ,mem_vec_734 ,mem_vec_735 ,mem_vec_736 ,mem_vec_737 ,mem_vec_738 ,mem_vec_739 ,mem_vec_740 ,mem_vec_741 ,mem_vec_742 ,mem_vec_743 ,mem_vec_744 ,mem_vec_745 ,mem_vec_746 ,mem_vec_747 ,mem_vec_748 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 272, x = 272, h = 3, w = 3, c = 32, f = 64
// T (y, 2) (272 / 136)
for (y72 = y73, y72_p_0 = 0;
	y72 < y73 + 272;
	y72 += 136, y72_p_0 += 136){
	// y = 136, x = 272, h = 3, w = 3, c = 32, f = 64
	// T (x, 272) (272 / 1)
	for (x72 = x73, x72_p_0 = 0;
		x72 < x73 + 272;
		x72 += 1, x72_p_0 += 1){
			for (y = y72, yp_1 = y72_p_0, yp_0 = 0;
				y < y72 + 66;
				y += 11, yp_1 += 11, yp_0 += 11){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 1) (32 / 32)
				for (c63 = c64, c63_p_0 = 0;
					c63 < c64 + 32;
					c63 += 32, c63_p_0 += 32){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (f, 2) (64 / 32)
					for (f = f42, fp_0 = 0;
						f < f42 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (x, 1) (1 / 1)
						for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
							x < x72 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h33, hp_0 = 0;
								h < h33 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w42, wp_0 = 0;
									w < w42 + 3;
									w += 1, wp_0 += 1){
											mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_700 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_704 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_705 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_706 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_707 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_708 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_709 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_710 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_711 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_712 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_713 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_714 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_715 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_716 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_717 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_718 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
												c < c63 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_699);
												mem_vec_699 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_700);
												mem_vec_700 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_701);
												mem_vec_701 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_702);
												mem_vec_702 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_703);
												mem_vec_703 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_704);
												mem_vec_704 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_705);
												mem_vec_705 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_706);
												mem_vec_706 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_707);
												mem_vec_707 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_708);
												mem_vec_708 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_709);
												mem_vec_709 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_710);
												mem_vec_710 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_711);
												mem_vec_711 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_712);
												mem_vec_712 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_713);
												mem_vec_713 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_714);
												mem_vec_714 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_715);
												mem_vec_715 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_716);
												mem_vec_716 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_717);
												mem_vec_717 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_718);
												mem_vec_718 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_719);
												mem_vec_719 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_720);
												mem_vec_720 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_699);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_700);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_701);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_702);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_703);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_704);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_705);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_706);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_707);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_708);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_709);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_710);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_711);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_712);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_713);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_714);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_715);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_716);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_717);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_718);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_719);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_720);
								}
							}
						}
					}
				}
			}
			for (y = y72 + 66, yp_1 = y72_p_0, yp_0 = 0;
				y < y72 + 66 + 70;
				y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
				// T (c, 1) (32 / 32)
				for (c63 = c64, c63_p_0 = 0;
					c63 < c64 + 32;
					c63 += 32, c63_p_0 += 32){
					// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 64
					// T (f, 2) (64 / 32)
					for (f = f42, fp_0 = 0;
						f < f42 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
						// T (x, 1) (1 / 1)
						for (x = x72, xp_1 = x72_p_0, xp_0 = 0;
							x < x72 + 1;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 32, f = 32
							// T (h, 3) (3 / 1)
							for (h = h33, hp_0 = 0;
								h < h33 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 32, f = 32
								// T (w, 3) (3 / 1)
								for (w = w42, wp_0 = 0;
									w < w42 + 3;
									w += 1, wp_0 += 1){
											mem_vec_721 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_722 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_739 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_740 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 32, f = 32
											// T (c, 32) (32 / 1)
											for (c = c63, cp_1 = c63_p_0, cp_0 = 0;
												c < c63 + 32;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_721);
												mem_vec_721 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_722);
												mem_vec_722 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_723);
												mem_vec_723 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_724);
												mem_vec_724 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_725);
												mem_vec_725 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_726);
												mem_vec_726 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_727);
												mem_vec_727 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_728);
												mem_vec_728 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_729);
												mem_vec_729 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_730);
												mem_vec_730 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_731);
												mem_vec_731 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_732);
												mem_vec_732 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_733);
												mem_vec_733 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_734);
												mem_vec_734 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_735);
												mem_vec_735 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_736);
												mem_vec_736 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_737);
												mem_vec_737 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_738);
												mem_vec_738 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_739);
												mem_vec_739 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_740);
												mem_vec_740 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_741);
												mem_vec_741 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_742);
												mem_vec_742 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_743);
												mem_vec_743 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_744);
												mem_vec_744 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_745);
												mem_vec_745 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_746);
												mem_vec_746 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_747);
												mem_vec_747 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_748);
												mem_vec_748 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_721);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_722);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_723);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_724);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_725);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_726);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_727);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_728);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_729);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_730);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_731);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_732);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_733);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_734);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_735);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_736);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_737);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_738);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_739);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_740);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_741);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_742);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_743);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_744);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_745);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_746);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_747);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_748);
								}
							}
						}
					}
				}
			}
	}
}


}