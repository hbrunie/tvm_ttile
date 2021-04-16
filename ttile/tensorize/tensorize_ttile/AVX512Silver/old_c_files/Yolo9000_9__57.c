#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x); T (4, y); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]]
*/
IND_TYPE c, cp_0, c51_p_0, cp_1, c51, f, fp_0, x, xp_0, x68_p_0, x69_p_0, xp_1, x68_p_1, xp_2, x68, x69, y, yp_0, y51_p_0, yp_1, y51;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y52 = 0;
IND_TYPE x70 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c52 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_636 ,mem_vec_637 ,mem_vec_638 ,mem_vec_639 ,mem_vec_640 ,mem_vec_641 ,mem_vec_642 ,mem_vec_643 ,mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y51 = y52, y51_p_0 = 0;
		y51 < y52 + 48;
		y51 += 16, y51_p_0 += 16){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x69 = x70, x69_p_0 = 0;
			x69 < x70 + 68;
			x69 += 68, x69_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y51, yp_1 = y51_p_0, yp_0 = 0;
				y < y51 + 16;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x68 = x69, x68_p_1 = x69_p_0, x68_p_0 = 0;
					x68 < x69 + 68;
					x68 += 68, x68_p_1 += 68, x68_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f34, fp_0 = 0;
						f < f34 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c51 = c52, c51_p_0 = 0;
							c51 < c52 + 256;
							c51 += 256, c51_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x68, xp_2 = x68_p_1, xp_1 = x68_p_0, xp_0 = 0;
								x < x68 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_636 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_637 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_638 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_639 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_640 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_641 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_642 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
											c < c51 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_636);
											mem_vec_636 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_637);
											mem_vec_637 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_638);
											mem_vec_638 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_639);
											mem_vec_639 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_640);
											mem_vec_640 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_641);
											mem_vec_641 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_642);
											mem_vec_642 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_643);
											mem_vec_643 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_644);
											mem_vec_644 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_645);
											mem_vec_645 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_646);
											mem_vec_646 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_647);
											mem_vec_647 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_648);
											mem_vec_648 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_649);
											mem_vec_649 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_650);
											mem_vec_650 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_651);
											mem_vec_651 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_636);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_637);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_638);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_639);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_640);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_641);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_642);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_643);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_644);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_645);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_651);
							}
						}
					}
				}
			}
		}
	}
	for (y51 = y52 + 48, y51_p_0 = 0;
		y51 < y52 + 48 + 20;
		y51 += 20, y51_p_0 += 20){
		// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x69 = x70, x69_p_0 = 0;
			x69 < x70 + 68;
			x69 += 68, x69_p_0 += 68){
			// y = 4 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 4) (4 * ph_y / ph_y)
			for (y = y51, yp_1 = y51_p_0, yp_0 = 0;
				y < y51 + 20;
				y += 5, yp_1 += 5, yp_0 += 5){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x68 = x69, x68_p_1 = x69_p_0, x68_p_0 = 0;
					x68 < x69 + 68;
					x68 += 68, x68_p_1 += 68, x68_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f34, fp_0 = 0;
						f < f34 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c51 = c52, c51_p_0 = 0;
							c51 < c52 + 256;
							c51 += 256, c51_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x68, xp_2 = x68_p_1, xp_1 = x68_p_0, xp_0 = 0;
								x < x68 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
											c < c51 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_652);
											mem_vec_652 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_653);
											mem_vec_653 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_654);
											mem_vec_654 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_655);
											mem_vec_655 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_656);
											mem_vec_656 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_657);
											mem_vec_657 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_658);
											mem_vec_658 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_659);
											mem_vec_659 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_660);
											mem_vec_660 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_661);
											mem_vec_661 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_662);
											mem_vec_662 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_663);
											mem_vec_663 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_664);
											mem_vec_664 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_665);
											mem_vec_665 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_666);
											mem_vec_666 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_667);
											mem_vec_667 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_668);
											mem_vec_668 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_669);
											mem_vec_669 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_670);
											mem_vec_670 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_671);
											mem_vec_671 = vec_28;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_656);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_657);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_658);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_659);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_660);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_661);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_662);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_663);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_664);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_665);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_669);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_670);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_671);
							}
						}
					}
				}
			}
		}
	}


}