#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (128, c); Hoist_vars [c]; T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 5), (Arg 12))]; T (2, f);
  T (136, x); T (2, y)]
*/
IND_TYPE c, cp_0, f, fp_0, x, xp_0, x45_p_0, xp_1, x45, y, yp_0, y45_p_0, yp_1, y45;

assert((Y == 136));
assert((X == 136));
assert((H == 1));
assert((W == 1));
assert((C == 128));
assert((F == 64));
IND_TYPE y46 = 0;
IND_TYPE x46 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c30 = 0;
IND_TYPE f30 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 136, x = 136, h = 1, w = 1, c = 128, f = 64
// T (y, 2) (136 / 68)
for (y45 = y46, y45_p_0 = 0;
	y45 < y46 + 136;
	y45 += 68, y45_p_0 += 68){
	// y = 68, x = 136, h = 1, w = 1, c = 128, f = 64
	// T (x, 136) (136 / 1)
	for (x45 = x46, x45_p_0 = 0;
		x45 < x46 + 136;
		x45 += 1, x45_p_0 += 1){
		// y = 68, x = 1, h = 1, w = 1, c = 128, f = 64
		// T (f, 2) (64 / 32)
		for (f = f30, fp_0 = 0;
			f < f30 + 64;
			f += 32, fp_0 += 32){
				for (y = y45, yp_1 = y45_p_0, yp_0 = 0;
					y < y45 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x45, xp_1 = x45_p_0, xp_0 = 0;
						x < x45 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c30, cp_0 = 0;
									c < c30 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_608);
									mem_vec_608 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_609);
									mem_vec_609 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_610);
									mem_vec_610 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_611);
									mem_vec_611 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_612);
									mem_vec_612 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_613);
									mem_vec_613 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_614);
									mem_vec_614 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_615);
									mem_vec_615 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_616);
									mem_vec_616 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_617);
									mem_vec_617 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_618);
									mem_vec_618 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_619);
									mem_vec_619 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_620);
									mem_vec_620 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_621);
									mem_vec_621 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_622);
									mem_vec_622 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_623);
									mem_vec_623 = vec_25;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_608);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_609);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_610);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_611);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_612);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_613);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_614);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_615);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_616);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_617);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_618);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_619);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_620);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_621);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_622);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_623);
					}
				}
				for (y = y45 + 8, yp_1 = y45_p_0, yp_0 = 0;
					y < y45 + 8 + 60;
					y += 12, yp_1 += 12, yp_0 += 12){
					// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
					// T (x, 1) (1 / 1)
					for (x = x45, xp_1 = x45_p_0, xp_0 = 0;
						x < x45 + 1;
						x += 1, xp_1 += 1, xp_0 += 1){
								mem_vec_624 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
								mem_vec_625 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
								mem_vec_626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
								mem_vec_627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
								mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
								mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
								mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
								mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
								mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
								mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
								mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
								mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
								mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
								mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
								mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
								mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
								mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
								mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
								mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
								mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
								mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
								mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
								mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
								mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
								// y = ph_y, x = 1, h = 1, w = 1, c = 128, f = 32
								// T (c, 128) (128 / 1)
								for (c = c30, cp_0 = 0;
									c < c30 + 128;
									c += 1, cp_0 += 1){
									scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
									vec_1 = _mm512_set1_ps(scal_0);
									vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

									vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_624);
									mem_vec_624 = vec_0;

									vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

									vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_625);
									mem_vec_625 = vec_3;
									scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
									vec_6 = _mm512_set1_ps(scal_1);


									vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_626);
									mem_vec_626 = vec_5;



									vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_627);
									mem_vec_627 = vec_7;
									scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
									vec_9 = _mm512_set1_ps(scal_2);


									vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_628);
									mem_vec_628 = vec_8;



									vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_629);
									mem_vec_629 = vec_10;
									scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
									vec_12 = _mm512_set1_ps(scal_3);


									vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_630);
									mem_vec_630 = vec_11;



									vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_631);
									mem_vec_631 = vec_13;
									scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
									vec_15 = _mm512_set1_ps(scal_4);


									vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_632);
									mem_vec_632 = vec_14;



									vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_633);
									mem_vec_633 = vec_16;
									scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
									vec_18 = _mm512_set1_ps(scal_5);


									vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_634);
									mem_vec_634 = vec_17;



									vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_635);
									mem_vec_635 = vec_19;
									scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
									vec_21 = _mm512_set1_ps(scal_6);


									vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_636);
									mem_vec_636 = vec_20;



									vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_637);
									mem_vec_637 = vec_22;
									scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
									vec_24 = _mm512_set1_ps(scal_7);


									vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_638);
									mem_vec_638 = vec_23;



									vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_639);
									mem_vec_639 = vec_25;
									scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
									vec_27 = _mm512_set1_ps(scal_8);


									vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_640);
									mem_vec_640 = vec_26;



									vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_641);
									mem_vec_641 = vec_28;
									scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
									vec_30 = _mm512_set1_ps(scal_9);


									vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_642);
									mem_vec_642 = vec_29;



									vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_643);
									mem_vec_643 = vec_31;
									scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
									vec_33 = _mm512_set1_ps(scal_10);


									vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_644);
									mem_vec_644 = vec_32;



									vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_645);
									mem_vec_645 = vec_34;
									scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
									vec_36 = _mm512_set1_ps(scal_11);


									vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_646);
									mem_vec_646 = vec_35;



									vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_647);
									mem_vec_647 = vec_37;
								}
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_624);
							_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_625);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_626);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_627);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_628);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_629);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_630);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_631);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_632);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_633);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_634);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_635);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_636);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_637);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_638);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_639);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_640);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_641);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_642);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_643);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_644);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_645);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_646);
							_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_647);
					}
				}
		}
	}
}


}