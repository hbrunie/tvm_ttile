#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (16, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (4, x); T (2, f); T (2, c); T (2, y); T (68, x);
  Lambda_apply y [((Iter 6), (Arg 11)); ((Iter 5), (Arg 14))]]
*/
IND_TYPE c, cp_0, c441_p_0, cp_1, c441, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x539_p_0, xp_1, x539, y, yp_0, y482_p_0, yp_1, y482;

assert((Y == 272));
assert((X == 272));
assert((H == 3));
assert((W == 3));
assert((C == 32));
assert((F == 64));
IND_TYPE y483 = 0;
IND_TYPE x540 = 0;
IND_TYPE h253 = 0;
IND_TYPE w237 = 0;
IND_TYPE c442 = 0;
IND_TYPE f237 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_3717 ,mem_vec_3718 ,mem_vec_3719 ,mem_vec_3720 ,mem_vec_3721 ,mem_vec_3722 ,mem_vec_3723 ,mem_vec_3724 ,mem_vec_3725 ,mem_vec_3726 ,mem_vec_3727 ,mem_vec_3728 ,mem_vec_3729 ,mem_vec_3730 ,mem_vec_3731 ,mem_vec_3732 ,mem_vec_3733 ,mem_vec_3734 ,mem_vec_3735 ,mem_vec_3736 ,mem_vec_3737 ,mem_vec_3738 ,mem_vec_3739 ,mem_vec_3740 ,mem_vec_3741 ,mem_vec_3742 ,mem_vec_3743 ,mem_vec_3744 ,mem_vec_3745 ,mem_vec_3746 ,mem_vec_3747 ,mem_vec_3748 ,mem_vec_3749 ,mem_vec_3750 ,mem_vec_3751 ,mem_vec_3752 ,mem_vec_3753 ,mem_vec_3754 ,mem_vec_3755 ,mem_vec_3756 ,mem_vec_3757 ,mem_vec_3758 ,mem_vec_3759 ,mem_vec_3760 ,mem_vec_3761 ,mem_vec_3762 ,mem_vec_3763 ,mem_vec_3764 ,mem_vec_3765 ,mem_vec_3766 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y482 = y483, y482_p_0 = 0;
		y482 < y483 + 132;
		y482 += 22, y482_p_0 += 22){
		// y = 2 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 68) (272 / 4)
		for (x539 = x540, x539_p_0 = 0;
			x539 < x540 + 272;
			x539 += 4, x539_p_0 += 4){
			// y = 2 * ph_y, x = 4, h = 3, w = 3, c = 32, f = 64
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y482, yp_1 = y482_p_0, yp_0 = 0;
				y < y482 + 22;
				y += 11, yp_1 += 11, yp_0 += 11){
				// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c441 = c442, c441_p_0 = 0;
					c441 < c442 + 32;
					c441 += 16, c441_p_0 += 16){
					// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 64
					// T (f, 2) (64 / 32)
					for (f = f237, fp_0 = 0;
						f < f237 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
						// T (x, 4) (4 / 1)
						for (x = x539, xp_1 = x539_p_0, xp_0 = 0;
							x < x539 + 4;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h253, hp_0 = 0;
								h < h253 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w237, wp_0 = 0;
									w < w237 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3717 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3718 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3719 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3720 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3721 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3722 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3723 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3724 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3725 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3726 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3727 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3728 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3729 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3730 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3731 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3732 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3733 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3734 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3735 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3736 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_3737 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_3738 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c441, cp_1 = c441_p_0, cp_0 = 0;
												c < c441 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3717);
												mem_vec_3717 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3718);
												mem_vec_3718 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3719);
												mem_vec_3719 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3720);
												mem_vec_3720 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3721);
												mem_vec_3721 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3722);
												mem_vec_3722 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3723);
												mem_vec_3723 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3724);
												mem_vec_3724 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3725);
												mem_vec_3725 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3726);
												mem_vec_3726 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3727);
												mem_vec_3727 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3728);
												mem_vec_3728 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3729);
												mem_vec_3729 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3730);
												mem_vec_3730 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3731);
												mem_vec_3731 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3732);
												mem_vec_3732 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3733);
												mem_vec_3733 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3734);
												mem_vec_3734 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3735);
												mem_vec_3735 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3736);
												mem_vec_3736 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3737);
												mem_vec_3737 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3738);
												mem_vec_3738 = vec_34;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3717);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3718);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3719);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3720);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3721);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3722);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3723);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3724);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3725);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3726);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3727);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3728);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3729);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3730);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3731);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3732);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3733);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3734);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3735);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3736);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3737);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3738);
								}
							}
						}
					}
				}
			}
		}
	}
	for (y482 = y483 + 132, y482_p_0 = 0;
		y482 < y483 + 132 + 140;
		y482 += 28, y482_p_0 += 28){
		// y = 2 * ph_y, x = 272, h = 3, w = 3, c = 32, f = 64
		// T (x, 68) (272 / 4)
		for (x539 = x540, x539_p_0 = 0;
			x539 < x540 + 272;
			x539 += 4, x539_p_0 += 4){
			// y = 2 * ph_y, x = 4, h = 3, w = 3, c = 32, f = 64
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y482, yp_1 = y482_p_0, yp_0 = 0;
				y < y482 + 28;
				y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 4, h = 3, w = 3, c = 32, f = 64
				// T (c, 2) (32 / 16)
				for (c441 = c442, c441_p_0 = 0;
					c441 < c442 + 32;
					c441 += 16, c441_p_0 += 16){
					// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 64
					// T (f, 2) (64 / 32)
					for (f = f237, fp_0 = 0;
						f < f237 + 64;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 4, h = 3, w = 3, c = 16, f = 32
						// T (x, 4) (4 / 1)
						for (x = x539, xp_1 = x539_p_0, xp_0 = 0;
							x < x539 + 4;
							x += 1, xp_1 += 1, xp_0 += 1){
							// y = ph_y, x = 1, h = 3, w = 3, c = 16, f = 32
							// T (h, 3) (3 / 1)
							for (h = h253, hp_0 = 0;
								h < h253 + 3;
								h += 1, hp_0 += 1){
								// y = ph_y, x = 1, h = 1, w = 3, c = 16, f = 32
								// T (w, 3) (3 / 1)
								for (w = w237, wp_0 = 0;
									w < w237 + 3;
									w += 1, wp_0 += 1){
											mem_vec_3739 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
											mem_vec_3740 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
											mem_vec_3741 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
											mem_vec_3742 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
											mem_vec_3743 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
											mem_vec_3744 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
											mem_vec_3745 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
											mem_vec_3746 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
											mem_vec_3747 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
											mem_vec_3748 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
											mem_vec_3749 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
											mem_vec_3750 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
											mem_vec_3751 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
											mem_vec_3752 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
											mem_vec_3753 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
											mem_vec_3754 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
											mem_vec_3755 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
											mem_vec_3756 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
											mem_vec_3757 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
											mem_vec_3758 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
											mem_vec_3759 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
											mem_vec_3760 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
											mem_vec_3761 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
											mem_vec_3762 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
											mem_vec_3763 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
											mem_vec_3764 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
											mem_vec_3765 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
											mem_vec_3766 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
											// y = ph_y, x = 1, h = 1, w = 1, c = 16, f = 32
											// T (c, 16) (16 / 1)
											for (c = c441, cp_1 = c441_p_0, cp_0 = 0;
												c < c441 + 16;
												c += 1, cp_1 += 1, cp_0 += 1){
												scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
												vec_1 = _mm512_set1_ps(scal_0);
												vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

												vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3739);
												mem_vec_3739 = vec_0;

												vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

												vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3740);
												mem_vec_3740 = vec_3;
												scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
												vec_6 = _mm512_set1_ps(scal_1);


												vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_3741);
												mem_vec_3741 = vec_5;



												vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_3742);
												mem_vec_3742 = vec_7;
												scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
												vec_9 = _mm512_set1_ps(scal_2);


												vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_3743);
												mem_vec_3743 = vec_8;



												vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_3744);
												mem_vec_3744 = vec_10;
												scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
												vec_12 = _mm512_set1_ps(scal_3);


												vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_3745);
												mem_vec_3745 = vec_11;



												vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_3746);
												mem_vec_3746 = vec_13;
												scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
												vec_15 = _mm512_set1_ps(scal_4);


												vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3747);
												mem_vec_3747 = vec_14;



												vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3748);
												mem_vec_3748 = vec_16;
												scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
												vec_18 = _mm512_set1_ps(scal_5);


												vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_3749);
												mem_vec_3749 = vec_17;



												vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_3750);
												mem_vec_3750 = vec_19;
												scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
												vec_21 = _mm512_set1_ps(scal_6);


												vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_3751);
												mem_vec_3751 = vec_20;



												vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_3752);
												mem_vec_3752 = vec_22;
												scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
												vec_24 = _mm512_set1_ps(scal_7);


												vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_3753);
												mem_vec_3753 = vec_23;



												vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_3754);
												mem_vec_3754 = vec_25;
												scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
												vec_27 = _mm512_set1_ps(scal_8);


												vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_3755);
												mem_vec_3755 = vec_26;



												vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_3756);
												mem_vec_3756 = vec_28;
												scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
												vec_30 = _mm512_set1_ps(scal_9);


												vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3757);
												mem_vec_3757 = vec_29;



												vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3758);
												mem_vec_3758 = vec_31;
												scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
												vec_33 = _mm512_set1_ps(scal_10);


												vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_3759);
												mem_vec_3759 = vec_32;



												vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_3760);
												mem_vec_3760 = vec_34;
												scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
												vec_36 = _mm512_set1_ps(scal_11);


												vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_3761);
												mem_vec_3761 = vec_35;



												vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_3762);
												mem_vec_3762 = vec_37;
												scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
												vec_39 = _mm512_set1_ps(scal_12);


												vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_3763);
												mem_vec_3763 = vec_38;



												vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_3764);
												mem_vec_3764 = vec_40;
												scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
												vec_42 = _mm512_set1_ps(scal_13);


												vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_3765);
												mem_vec_3765 = vec_41;



												vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_3766);
												mem_vec_3766 = vec_43;
											}
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3739);
										_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3740);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3741);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3742);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3743);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3744);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3745);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3746);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3747);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3748);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3749);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3750);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_3751);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_3752);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_3753);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_3754);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_3755);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_3756);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_3757);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_3758);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_3759);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_3760);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_3761);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_3762);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_3763);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_3764);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_3765);
										_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_3766);
								}
							}
						}
					}
				}
			}
		}
	}


}