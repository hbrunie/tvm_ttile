#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (128, c); Hoist_vars [c]; T (4, x); T (4, y);
  T (1, c); T (34, x);
  Lambda_apply y [((Iter 1), (Arg 4)); ((Iter 5), (Arg 6))]]
*/
IND_TYPE c, cp_0, c194_p_0, cp_1, c194, x, xp_0, x258_p_0, xp_1, x258, y, yp_0, y258_p_0, yp_1, y258;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y259 = 0;
IND_TYPE x259 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c195 = 0;
IND_TYPE f = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5;
__m512 mem_vec_3604 ,mem_vec_3605 ,mem_vec_3606 ,mem_vec_3607 ,mem_vec_3608 ,mem_vec_3609 ,mem_vec_3610 ,mem_vec_3611 ,mem_vec_3612 ,mem_vec_3613 ,mem_vec_3614 ,mem_vec_3615 ,mem_vec_3616 ,mem_vec_3617 ,mem_vec_3618 ,mem_vec_3619 ,mem_vec_3620 ,mem_vec_3621 ,mem_vec_3622 ,mem_vec_3623 ,mem_vec_3624 ,mem_vec_3625 ,mem_vec_3626 ,mem_vec_3627 ,mem_vec_3628 ,mem_vec_3629 ,mem_vec_3630 ,mem_vec_3631 ,mem_vec_3632 ,mem_vec_3633 ,mem_vec_3634 ,mem_vec_3635 ,mem_vec_3636 ,mem_vec_3637 ,mem_vec_3638 ,mem_vec_3639 ,mem_vec_3640 ,mem_vec_3641 ,mem_vec_3642 ,mem_vec_3643 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y258 = y259, y258_p_0 = 0;
		y258 < y259 + 16;
		y258 += 16, y258_p_0 += 16){
		// y = 4 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 34) (136 / 4)
		for (x258 = x259, x258_p_0 = 0;
			x258 < x259 + 136;
			x258 += 4, x258_p_0 += 4){
			// y = 4 * ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c194 = c195, c194_p_0 = 0;
				c194 < c195 + 128;
				c194 += 128, c194_p_0 += 128){
				// y = 4 * ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (y, 4) (4 * ph_y / ph_y)
				for (y = y258, yp_1 = y258_p_0, yp_0 = 0;
					y < y258 + 16;
					y += 4, yp_1 += 4, yp_0 += 4){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
					// T (x, 4) (4 / 1)
					for (x = x258, xp_1 = x258_p_0, xp_0 = 0;
						x < x258 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3604 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3605 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3606 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_3607 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_3608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_3611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_3612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_3615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_3616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_3619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c194, cp_1 = c194_p_0, cp_0 = 0;
									c < c194 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3604);
									mem_vec_3604 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3605);
									mem_vec_3605 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3606);
									mem_vec_3606 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3607);
									mem_vec_3607 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3608);
									mem_vec_3608 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3609);
									mem_vec_3609 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3610);
									mem_vec_3610 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3611);
									mem_vec_3611 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3612);
									mem_vec_3612 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3613);
									mem_vec_3613 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3614);
									mem_vec_3614 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3615);
									mem_vec_3615 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3616);
									mem_vec_3616 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3617);
									mem_vec_3617 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3618);
									mem_vec_3618 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3619);
									mem_vec_3619 = vec_23;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3604);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3605);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3606);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3607);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3608);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3609);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3610);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3611);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3612);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3613);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3614);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3615);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3616);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3617);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3618);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3619);
					}
				}
			}
		}
	}
	for (y258 = y259 + 16, y258_p_0 = 0;
		y258 < y259 + 16 + 120;
		y258 += 24, y258_p_0 += 24){
		// y = 4 * ph_y, x = 136, h = 1, w = 1, c = 128, f = 64
		// T (x, 34) (136 / 4)
		for (x258 = x259, x258_p_0 = 0;
			x258 < x259 + 136;
			x258 += 4, x258_p_0 += 4){
			// y = 4 * ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
			// T (c, 1) (128 / 128)
			for (c194 = c195, c194_p_0 = 0;
				c194 < c195 + 128;
				c194 += 128, c194_p_0 += 128){
				// y = 4 * ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
				// T (y, 4) (4 * ph_y / ph_y)
				for (y = y258, yp_1 = y258_p_0, yp_0 = 0;
					y < y258 + 24;
					y += 6, yp_1 += 6, yp_0 += 6){
					// y = ph_y, x = 4, h = 1, w = 1, c = 128, f = 64
					// T (x, 4) (4 / 1)
					for (x = x258, xp_1 = x258_p_0, xp_0 = 0;
						x < x258 + 4;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_3620 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_3621 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_3622 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
								mem_vec_3623 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
								mem_vec_3624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_3625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_3626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
								mem_vec_3627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
								mem_vec_3628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_3629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_3630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
								mem_vec_3631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
								mem_vec_3632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_3633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_3634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
								mem_vec_3635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
								mem_vec_3636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_3637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_3638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
								mem_vec_3639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
								mem_vec_3640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_3641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_3642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
								mem_vec_3643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 64
								// T (c, 128) (128 / 1)
								for (c = c194, cp_1 = c194_p_0, cp_0 = 0;
									c < c194 + 128;
									c += 1, cp_1 += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_3620);
									mem_vec_3620 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_3621);
									mem_vec_3621 = vec_3;

									vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

									vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_3622);
									mem_vec_3622 = vec_5;

									vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

									vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_3623);
									mem_vec_3623 = vec_7;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_10 = _mm512_set1_ps(scal_1);


									vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_3624);
									mem_vec_3624 = vec_9;



									vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_3625);
									mem_vec_3625 = vec_11;



									vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_3626);
									mem_vec_3626 = vec_12;



									vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_3627);
									mem_vec_3627 = vec_13;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_15 = _mm512_set1_ps(scal_2);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_3628);
									mem_vec_3628 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_3629);
									mem_vec_3629 = vec_16;



									vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_3630);
									mem_vec_3630 = vec_17;



									vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_3631);
									mem_vec_3631 = vec_18;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_20 = _mm512_set1_ps(scal_3);


									vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_3632);
									mem_vec_3632 = vec_19;



									vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_3633);
									mem_vec_3633 = vec_21;



									vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_3634);
									mem_vec_3634 = vec_22;



									vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_3635);
									mem_vec_3635 = vec_23;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_25 = _mm512_set1_ps(scal_4);


									vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_3636);
									mem_vec_3636 = vec_24;



									vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_3637);
									mem_vec_3637 = vec_26;



									vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_3638);
									mem_vec_3638 = vec_27;



									vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_3639);
									mem_vec_3639 = vec_28;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_30 = _mm512_set1_ps(scal_5);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_3640);
									mem_vec_3640 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_3641);
									mem_vec_3641 = vec_31;



									vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_3642);
									mem_vec_3642 = vec_32;



									vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_3643);
									mem_vec_3643 = vec_33;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_3620);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_3621);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_3622);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_3623);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_3624);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_3625);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_3626);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_3627);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_3628);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_3629);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_3630);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_3631);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_3632);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_3633);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_3634);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_3635);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_3636);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_3637);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_3638);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_3639);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_3640);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_3641);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_3642);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_3643);
					}
				}
			}
		}
	}


}