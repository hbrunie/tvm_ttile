#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (8, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (2, x); T (8, y); T (2, f); T (16, c); T (4, x)]
*/
IND_TYPE c, cp_0, c84_p_0, cp_1, c84, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x112_p_0, x113_p_0, xp_1, x112_p_1, xp_2, x112, x113, y, yp_0;

assert((Y == 56));
assert((X == 56));
assert((H == 3));
assert((W == 3));
assert((C == 128));
assert((F == 128));
IND_TYPE y56 = 0;
IND_TYPE x114 = 0;
IND_TYPE h56 = 0;
IND_TYPE w56 = 0;
IND_TYPE c85 = 0;
IND_TYPE f56 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 56, x = 56, h = 3, w = 3, c = 128, f = 128
// T (x, 4) (56 / 14)
for (x113 = x114, x113_p_0 = 0;
	x113 < x114 + 56;
	x113 += 14, x113_p_0 += 14){
	// y = 56, x = 14, h = 3, w = 3, c = 128, f = 128
	// T (c, 16) (128 / 8)
	for (c84 = c85, c84_p_0 = 0;
		c84 < c85 + 128;
		c84 += 8, c84_p_0 += 8){
		// y = 56, x = 14, h = 3, w = 3, c = 8, f = 128
		// T (f, 2) (128 / 64)
		for (f = f56, fp_0 = 0;
			f < f56 + 128;
			f += 64, fp_0 += 64){
			// y = 56, x = 14, h = 3, w = 3, c = 8, f = 64
			// T (y, 8) (56 / 7)
			for (y = y56, yp_0 = 0;
				y < y56 + 56;
				y += 7, yp_0 += 7){
				// y = 7, x = 14, h = 3, w = 3, c = 8, f = 64
				// T (x, 2) (14 / 7)
				for (x112 = x113, x112_p_1 = x113_p_0, x112_p_0 = 0;
					x112 < x113 + 14;
					x112 += 7, x112_p_1 += 7, x112_p_0 += 7){
					// y = 7, x = 7, h = 3, w = 3, c = 8, f = 64
					// T (h, 3) (3 / 1)
					for (h = h56, hp_0 = 0;
						h < h56 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 7, h = 1, w = 3, c = 8, f = 64
						// T (w, 3) (3 / 1)
						for (w = w56, wp_0 = 0;
							w < w56 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 1, w = 1, c = 8, f = 64
							// T (x, 7) (7 / 1)
							for (x = x112, xp_2 = x112_p_1, xp_1 = x112_p_0, xp_0 = 0;
								x < x112 + 7;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_616 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_617 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_618 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_619 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_620 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_621 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_622 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_623 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_624 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_625 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_626 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_627 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 8, f = 64
										// T (c, 8) (8 / 1)
										for (c = c84, cp_1 = c84_p_0, cp_0 = 0;
											c < c84 + 8;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_616);
											mem_vec_616 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_617);
											mem_vec_617 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_618);
											mem_vec_618 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_619);
											mem_vec_619 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_620);
											mem_vec_620 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_621);
											mem_vec_621 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_622);
											mem_vec_622 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_623);
											mem_vec_623 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_624);
											mem_vec_624 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_625);
											mem_vec_625 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_626);
											mem_vec_626 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_627);
											mem_vec_627 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_628);
											mem_vec_628 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_629);
											mem_vec_629 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_630);
											mem_vec_630 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_631);
											mem_vec_631 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_632);
											mem_vec_632 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_633);
											mem_vec_633 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_634);
											mem_vec_634 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_635);
											mem_vec_635 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_636);
											mem_vec_636 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_637);
											mem_vec_637 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_638);
											mem_vec_638 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_639);
											mem_vec_639 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_640);
											mem_vec_640 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_641);
											mem_vec_641 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_642);
											mem_vec_642 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_643);
											mem_vec_643 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_616);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_617);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_618);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_619);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_620);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_621);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_622);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_623);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_624);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_625);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_626);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_627);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_628);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_629);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_630);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_631);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_632);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_633);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_634);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_635);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_636);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_637);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_638);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_639);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_640);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_641);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_642);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_643);
							}
						}
					}
				}
			}
		}
	}
}


}