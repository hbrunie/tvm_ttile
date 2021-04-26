#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); U (14, y); T (3, c); Hoist_vars [c]; T (7, x); T (1, c);
  T (7, w); T (7, h); T (16, x); T (2, y); T (2, f); T (4, y)]
*/
IND_TYPE c, cp_0, c69_p_0, cp_1, c69, f, fp_0, h, hp_0, w, wp_0, x, xp_0, x64_p_0, xp_1, x64, y, yp_0, y69_p_0, yp_1, y69;

assert((Y == 112));
assert((X == 112));
assert((H == 7));
assert((W == 7));
assert((C == 3));
assert((F == 64));
IND_TYPE y70 = 0;
IND_TYPE x65 = 0;
IND_TYPE h46 = 0;
IND_TYPE w46 = 0;
IND_TYPE c70 = 0;
IND_TYPE f41 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_644 ,mem_vec_645 ,mem_vec_646 ,mem_vec_647 ,mem_vec_648 ,mem_vec_649 ,mem_vec_650 ,mem_vec_651 ,mem_vec_652 ,mem_vec_653 ,mem_vec_654 ,mem_vec_655 ,mem_vec_656 ,mem_vec_657 ,mem_vec_658 ,mem_vec_659 ,mem_vec_660 ,mem_vec_661 ,mem_vec_662 ,mem_vec_663 ,mem_vec_664 ,mem_vec_665 ,mem_vec_666 ,mem_vec_667 ,mem_vec_668 ,mem_vec_669 ,mem_vec_670 ,mem_vec_671 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 112, x = 112, h = 7, w = 7, c = 3, f = 64
// T (y, 4) (112 / 28)
for (y69 = y70, y69_p_0 = 0;
	y69 < y70 + 112;
	y69 += 28, y69_p_0 += 28){
	// y = 28, x = 112, h = 7, w = 7, c = 3, f = 64
	// T (f, 2) (64 / 32)
	for (f = f41, fp_0 = 0;
		f < f41 + 64;
		f += 32, fp_0 += 32){
		// y = 28, x = 112, h = 7, w = 7, c = 3, f = 32
		// T (y, 2) (28 / 14)
		for (y = y69, yp_1 = y69_p_0, yp_0 = 0;
			y < y69 + 28;
			y += 14, yp_1 += 14, yp_0 += 14){
			// y = 14, x = 112, h = 7, w = 7, c = 3, f = 32
			// T (x, 16) (112 / 7)
			for (x64 = x65, x64_p_0 = 0;
				x64 < x65 + 112;
				x64 += 7, x64_p_0 += 7){
				// y = 14, x = 7, h = 7, w = 7, c = 3, f = 32
				// T (h, 7) (7 / 1)
				for (h = h46, hp_0 = 0;
					h < h46 + 7;
					h += 1, hp_0 += 1){
					// y = 14, x = 7, h = 1, w = 7, c = 3, f = 32
					// T (w, 7) (7 / 1)
					for (w = w46, wp_0 = 0;
						w < w46 + 7;
						w += 1, wp_0 += 1){
						// y = 14, x = 7, h = 1, w = 1, c = 3, f = 32
						// T (c, 1) (3 / 3)
						for (c69 = c70, c69_p_0 = 0;
							c69 < c70 + 3;
							c69 += 3, c69_p_0 += 3){
							// y = 14, x = 7, h = 1, w = 1, c = 3, f = 32
							// T (x, 7) (7 / 1)
							for (x = x64, xp_1 = x64_p_0, xp_0 = 0;
								x < x64 + 7;
								x += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_644 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_645 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_661 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_662 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_663 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_664 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_665 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_666 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_667 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_668 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_669 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_670 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_671 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = 14, x = 1, h = 1, w = 1, c = 3, f = 32
										// T (c, 3) (3 / 1)
										for (c = c69, cp_1 = c69_p_0, cp_0 = 0;
											c < c69 + 3;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_644);
											mem_vec_644 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_645);
											mem_vec_645 = vec_3;
											scal_1 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 1) + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_646);
											mem_vec_646 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_647);
											mem_vec_647 = vec_7;
											scal_2 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 2) + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_648);
											mem_vec_648 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_649);
											mem_vec_649 = vec_10;
											scal_3 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 3) + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_650);
											mem_vec_650 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_651);
											mem_vec_651 = vec_13;
											scal_4 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 4) + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_652);
											mem_vec_652 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_653);
											mem_vec_653 = vec_16;
											scal_5 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 5) + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_654);
											mem_vec_654 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_655);
											mem_vec_655 = vec_19;
											scal_6 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 6) + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_656);
											mem_vec_656 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_657);
											mem_vec_657 = vec_22;
											scal_7 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 7) + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_658);
											mem_vec_658 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_659);
											mem_vec_659 = vec_25;
											scal_8 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 8) + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_660);
											mem_vec_660 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_661);
											mem_vec_661 = vec_28;
											scal_9 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 9) + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_662);
											mem_vec_662 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_663);
											mem_vec_663 = vec_31;
											scal_10 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 10) + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_664);
											mem_vec_664 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_665);
											mem_vec_665 = vec_34;
											scal_11 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 11) + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_666);
											mem_vec_666 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_667);
											mem_vec_667 = vec_37;
											scal_12 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 12) + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_668);
											mem_vec_668 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_669);
											mem_vec_669 = vec_40;
											scal_13 = input[(C * (2 * Y + H - 1)) * (2 * x + w) + C * (2 * (y + 13) + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_670);
											mem_vec_670 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_671);
											mem_vec_671 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_644);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_645);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_651);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_656);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_657);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_658);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_659);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_660);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_661);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_662);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_663);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_664);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_665);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_666);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_667);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_668);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_669);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_670);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_671);
							}
						}
					}
				}
			}
		}
	}
}


}