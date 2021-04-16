#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (2, x); T (4, y);
  T (1, c); T (68, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]]
*/
IND_TYPE c, cp_0, c197_p_0, cp_1, c197, x, xp_0, x261_p_0, xp_1, x261, y, yp_0, y261_p_0, yp_1, y261;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y262 = 0;
IND_TYPE x262 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c198 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_3644 ,mem_vec_3645 ,mem_vec_3646 ,mem_vec_3647 ,mem_vec_3648 ,mem_vec_3649 ,mem_vec_3650 ,mem_vec_3651 ,mem_vec_3652 ,mem_vec_3653 ,mem_vec_3654 ,mem_vec_3655 ,mem_vec_3656 ,mem_vec_3657 ,mem_vec_3658 ,mem_vec_3659 ,mem_vec_3660 ,mem_vec_3661 ,mem_vec_3662 ,mem_vec_3663 ,mem_vec_3664 ,mem_vec_3665 ,mem_vec_3666 ,mem_vec_3667 ,mem_vec_3668 ,mem_vec_3669 ,mem_vec_3670 ,mem_vec_3671 ,mem_vec_3672 ,mem_vec_3673 ,mem_vec_3674 ,mem_vec_3675 ,mem_vec_3676 ,mem_vec_3677 ,mem_vec_3678 ,mem_vec_3679 ,mem_vec_3680 ,mem_vec_3681 ,mem_vec_3682 ,mem_vec_3683 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y261 = y262, y261_p_0 = 0;
		y261 < y262 + 16;
		y261 += 16, y261_p_0 += 16){
		// y = 4 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x261 = x262, x261_p_0 = 0;
			x261 < x262 + 136;
			x261 += 2, x261_p_0 += 2){
			// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c197 = c198, c197_p_0 = 0;
				c197 < c198 + 128;
				c197 += 128, c197_p_0 += 128){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (y, 4) (4 * ph_y / ph_y)
				for (y = y261, yp_1 = y261_p_0, yp_0 = 0;
					y < y261 + 16;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x261, xp_1 = x261_p_0, xp_0 = 0;
						x < x261 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3644 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3645 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3646 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_3647 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_3648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_3651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_3652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_3655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_3656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_3659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c197, cp_1 = c197_p_0, cp_0 = 0;
									c < c197 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3644);
									mem_vec_3644 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3645);
									mem_vec_3645 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3646);
									mem_vec_3646 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3647);
									mem_vec_3647 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3648);
									mem_vec_3648 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3649);
									mem_vec_3649 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3650);
									mem_vec_3650 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3651);
									mem_vec_3651 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3652);
									mem_vec_3652 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3653);
									mem_vec_3653 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3654);
									mem_vec_3654 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3655);
									mem_vec_3655 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3656);
									mem_vec_3656 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3657);
									mem_vec_3657 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3658);
									mem_vec_3658 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3659);
									mem_vec_3659 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3644);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3645);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3646);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3647);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3648);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3649);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3650);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3651);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3652);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3653);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3654);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3655);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3656);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3657);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3658);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3659);
					}
				}
			}
		}
	}
	for (y261 = y262 + 16, y261_p_0 = 0;
		y261 < y262 + 16 + 120;
		y261 += 24, y261_p_0 += 24){
		// y = 4 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 68) (136 / 2)
		for (x261 = x262, x261_p_0 = 0;
			x261 < x262 + 136;
			x261 += 2, x261_p_0 += 2){
			// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c197 = c198, c197_p_0 = 0;
				c197 < c198 + 128;
				c197 += 128, c197_p_0 += 128){
				// y = 4 * ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
				// T (y, 4) (4 * ph_y / ph_y)
				for (y = y261, yp_1 = y261_p_0, yp_0 = 0;
					y < y261 + 24;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 2, h = 1, w = 1, c = 128, f = 64
					// T (x, 2) (2 / 1)
					for (x = x261, xp_1 = x261_p_0, xp_0 = 0;
						x < x261 + 2;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3660 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3661 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3662 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_3663 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_3664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_3667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_3668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_3671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_3672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_3675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_3676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_3677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_3678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_3679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_3680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_3681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_3682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_3683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c197, cp_1 = c197_p_0, cp_0 = 0;
									c < c197 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3660);
									mem_vec_3660 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3661);
									mem_vec_3661 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3662);
									mem_vec_3662 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3663);
									mem_vec_3663 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3664);
									mem_vec_3664 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3665);
									mem_vec_3665 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3666);
									mem_vec_3666 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3667);
									mem_vec_3667 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3668);
									mem_vec_3668 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3669);
									mem_vec_3669 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3670);
									mem_vec_3670 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3671);
									mem_vec_3671 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3672);
									mem_vec_3672 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3673);
									mem_vec_3673 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3674);
									mem_vec_3674 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3675);
									mem_vec_3675 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3676);
									mem_vec_3676 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3677);
									mem_vec_3677 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3678);
									mem_vec_3678 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3679);
									mem_vec_3679 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3680);
									mem_vec_3680 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3681);
									mem_vec_3681 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3682);
									mem_vec_3682 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3683);
									mem_vec_3683 = vec_33;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3660);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3661);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3662);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3663);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3664);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3665);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3666);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3667);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3668);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3669);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3670);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3671);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3672);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3673);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3674);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3675);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3676);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3677);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3678);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3679);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3680);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3681);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3682);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3683);
					}
				}
			}
		}
	}


}