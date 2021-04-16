#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (2, f); T (1, x);
  Lambda_apply y [((Iter 3), (Arg 4)); ((Iter 1), (Arg 5))]; T (1, x);
  T (4, y)]
*/
IND_TYPE c, cp_0, c48_p_0, cp_1, c48, f, fp_0, x, xp_0, x64_p_0, x65_p_0, xp_1, x64_p_1, xp_2, x64, x65, y, yp_0, y48_p_0, yp_1, y48;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y49 = 0;
IND_TYPE x66 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c49 = 0;
IND_TYPE f32 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4;
__m512 mem_vec_600 ,mem_vec_601 ,mem_vec_602 ,mem_vec_603 ,mem_vec_604 ,mem_vec_605 ,mem_vec_606 ,mem_vec_607 ,mem_vec_608 ,mem_vec_609 ,mem_vec_610 ,mem_vec_611 ,mem_vec_612 ,mem_vec_613 ,mem_vec_614 ,mem_vec_615 ,mem_vec_616 ,mem_vec_617 ,mem_vec_618 ,mem_vec_619 ,mem_vec_620 ,mem_vec_621 ,mem_vec_622 ,mem_vec_623 ,mem_vec_624 ,mem_vec_625 ,mem_vec_626 ,mem_vec_627 ,mem_vec_628 ,mem_vec_629 ,mem_vec_630 ,mem_vec_631 ,mem_vec_632 ,mem_vec_633 ,mem_vec_634 ,mem_vec_635 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_3 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 68, x = 68, h = 1, w = 1, c = 256, f = 128
// T (y, 4) (68 / 17)
for (y48 = y49, y48_p_0 = 0;
	y48 < y49 + 68;
	y48 += 17, y48_p_0 += 17){
	// y = 17, x = 68, h = 1, w = 1, c = 256, f = 128
	// T (x, 1) (68 / 68)
	for (x65 = x66, x65_p_0 = 0;
		x65 < x66 + 68;
		x65 += 68, x65_p_0 += 68){
			for (y = y48, yp_1 = y48_p_0, yp_0 = 0;
				y < y48 + 12;
				y += 4, yp_1 += 4, yp_0 += 4){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
					x64 < x65 + 68;
					x64 += 68, x64_p_1 += 68, x64_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f32, fp_0 = 0;
						f < f32 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c48 = c49, c48_p_0 = 0;
							c48 < c49 + 256;
							c48 += 256, c48_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
								x < x64 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_600 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_601 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_602 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_603 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_604 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_605 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_606 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_607 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_608 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_609 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_610 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_611 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_612 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_613 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_614 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_615 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
											c < c48 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_600);
											mem_vec_600 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_601);
											mem_vec_601 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_602);
											mem_vec_602 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_603);
											mem_vec_603 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_604);
											mem_vec_604 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_605);
											mem_vec_605 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_606);
											mem_vec_606 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_607);
											mem_vec_607 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_608);
											mem_vec_608 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_609);
											mem_vec_609 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_610);
											mem_vec_610 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_611);
											mem_vec_611 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_612);
											mem_vec_612 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_613);
											mem_vec_613 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_614);
											mem_vec_614 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_615);
											mem_vec_615 = vec_23;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_600);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_601);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_602);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_603);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_604);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_605);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_606);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_607);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_608);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_609);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_610);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_611);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_612);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_613);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_614);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_615);
							}
						}
					}
				}
			}
			for (y = y48 + 12, yp_1 = y48_p_0, yp_0 = 0;
				y < y48 + 12 + 5;
				y += 5, yp_1 += 5, yp_0 += 5){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x64 = x65, x64_p_1 = x65_p_0, x64_p_0 = 0;
					x64 < x65 + 68;
					x64 += 68, x64_p_1 += 68, x64_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 2) (128 / 64)
					for (f = f32, fp_0 = 0;
						f < f32 + 128;
						f += 64, fp_0 += 64){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
						// T (c, 1) (256 / 256)
						for (c48 = c49, c48_p_0 = 0;
							c48 < c49 + 256;
							c48 += 256, c48_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 64
							// T (x, 68) (68 / 1)
							for (x = x64, xp_2 = x64_p_1, xp_1 = x64_p_0, xp_0 = 0;
								x < x64 + 68;
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
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 64
										// T (c, 256) (256 / 1)
										for (c = c48, cp_1 = c48_p_0, cp_0 = 0;
											c < c48 + 256;
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
							}
						}
					}
				}
			}
	}
}


}