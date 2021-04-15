#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (17, x); T (1, c);
  T (2, f); T (2, x);
  Lambda_apply y [((Iter 1), (Arg 6)); ((Iter 4), (Arg 7))]; T (2, x);
  T (2, y)]
*/
IND_TYPE c, cp_0, c36_p_0, cp_1, c36, f, fp_0, x, xp_0, x48_p_0, x49_p_0, xp_1, x48_p_1, xp_2, x48, x49, y, yp_0, y36_p_0, yp_1, y36;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y37 = 0;
IND_TYPE x50 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c37 = 0;
IND_TYPE f24 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 2) (68 / 34)
for (y36 = y37, y36_p_0 = 0;
	y36 < y37 + 68;
	y36 += 34, y36_p_0 += 34){
	// y = 34, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 2) (68 / 34)
	for (x49 = x50, x49_p_0 = 0;
		x49 < x50 + 68;
		x49 += 34, x49_p_0 += 34){
			for (y = y36, yp_1 = y36_p_0, yp_0 = 0;
				y < y36 + 6;
				y += 6, yp_1 += 6, yp_0 += 6){
				// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
				// T (x, 2) (34 / 17)
				for (x48 = x49, x48_p_1 = x49_p_0, x48_p_0 = 0;
					x48 < x49 + 34;
					x48 += 17, x48_p_1 += 17, x48_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f24, fp_0 = 0;
						f < f24 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c36 = c37, c36_p_0 = 0;
							c36 < c37 + 256;
							c36 += 256, c36_p_0 += 256){
							// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
							// T (x, 17) (17 / 1)
							for (x = x48, xp_2 = x48_p_1, xp_1 = x48_p_0, xp_0 = 0;
								x < x48 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_624 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_625 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_626 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_627 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
											c < c36 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_624);
											mem_vec_624 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_625);
											mem_vec_625 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_626);
											mem_vec_626 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_627);
											mem_vec_627 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_628);
											mem_vec_628 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_629);
											mem_vec_629 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_630);
											mem_vec_630 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_631);
											mem_vec_631 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_632);
											mem_vec_632 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_633);
											mem_vec_633 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_634);
											mem_vec_634 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_635);
											mem_vec_635 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_636);
											mem_vec_636 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_637);
											mem_vec_637 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_638);
											mem_vec_638 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_639);
											mem_vec_639 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_640);
											mem_vec_640 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_641);
											mem_vec_641 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_642);
											mem_vec_642 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_643);
											mem_vec_643 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_644);
											mem_vec_644 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_645);
											mem_vec_645 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_646);
											mem_vec_646 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_647);
											mem_vec_647 = vec_33;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_624);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_625);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_626);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_627);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_628);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_629);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_630);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_631);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_632);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_633);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_634);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_635);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_636);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_637);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_638);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_639);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_640);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_641);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_642);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_643);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_644);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_645);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_647);
							}
						}
					}
				}
			}
			for (y = y36 + 6, yp_1 = y36_p_0, yp_0 = 0;
				y < y36 + 6 + 28;
				y += 7, yp_1 += 7, yp_0 += 7){
				// y = ph_y, x = 34, h = 1, w = 1, c = 256, f = 128
				// T (x, 2) (34 / 17)
				for (x48 = x49, x48_p_1 = x49_p_0, x48_p_0 = 0;
					x48 < x49 + 34;
					x48 += 17, x48_p_1 += 17, x48_p_0 += 17){
					// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f24, fp_0 = 0;
						f < f24 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c36 = c37, c36_p_0 = 0;
							c36 < c37 + 256;
							c36 += 256, c36_p_0 += 256){
							// y = ph_y, x = 17, h = 1, w = 1, c = 256, f = 64
							// T (x, 17) (17 / 1)
							for (x = x48, xp_2 = x48_p_1, xp_1 = x48_p_0, xp_0 = 0;
								x < x48 + 17;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c36, cp_1 = c36_p_0, cp_0 = 0;
											c < c36 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_648);
											mem_vec_648 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_649);
											mem_vec_649 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_650);
											mem_vec_650 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_651);
											mem_vec_651 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_652);
											mem_vec_652 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_653);
											mem_vec_653 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_654);
											mem_vec_654 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_655);
											mem_vec_655 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_656);
											mem_vec_656 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_657);
											mem_vec_657 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_658);
											mem_vec_658 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_659);
											mem_vec_659 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_660);
											mem_vec_660 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_661);
											mem_vec_661 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_662);
											mem_vec_662 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_663);
											mem_vec_663 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_664);
											mem_vec_664 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_665);
											mem_vec_665 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_666);
											mem_vec_666 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_667);
											mem_vec_667 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_668);
											mem_vec_668 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_669);
											mem_vec_669 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_670);
											mem_vec_670 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_671);
											mem_vec_671 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_672);
											mem_vec_672 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_673);
											mem_vec_673 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_674);
											mem_vec_674 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_675);
											mem_vec_675 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_651);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_656);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_657);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_658);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_659);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_660);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_661);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_662);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_663);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_664);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_665);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_669);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_670);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_671);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_672);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_673);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_674);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_675);
							}
						}
					}
				}
			}
	}
}


}