#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (3, f); ULambda y; T (512, c); Hoist_vars [c]; T (17, x); T (2, c);
  Lambda_apply y [((Iter 2), (Arg 5)); ((Iter 1), (Arg 7))]; T (589, f);
  T (1, y); T (1, c); T (1, f)]
*/
IND_TYPE c, cp_0, c788_p_0, c789_p_0, cp_1, c788_p_1, cp_2, c788, c789, f, fp_0, f591_p_0, fp_1, f591, x, xp_0, y, yp_0, y591_p_0, yp_1, y591;

assert((Y == 17));
assert((X == 17));
assert((H == 1));
assert((W == 1));
assert((C == 1024));
assert((F == 28272));
IND_TYPE y592 = 0;
IND_TYPE x394 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c790 = 0;
IND_TYPE f592 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_8625 ,mem_vec_8626 ,mem_vec_8627 ,mem_vec_8628 ,mem_vec_8629 ,mem_vec_8630 ,mem_vec_8631 ,mem_vec_8632 ,mem_vec_8633 ,mem_vec_8634 ,mem_vec_8635 ,mem_vec_8636 ,mem_vec_8637 ,mem_vec_8638 ,mem_vec_8639 ,mem_vec_8640 ,mem_vec_8641 ,mem_vec_8642 ,mem_vec_8643 ,mem_vec_8644 ,mem_vec_8645 ,mem_vec_8646 ,mem_vec_8647 ,mem_vec_8648 ,mem_vec_8649 ,mem_vec_8650 ,mem_vec_8651 ,mem_vec_8652 ,mem_vec_8653 ,mem_vec_8654 ,mem_vec_8655 ,mem_vec_8656 ,mem_vec_8657 ,mem_vec_8658 ,mem_vec_8659 ,mem_vec_8660 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
// T (f, 1) (28272 / 28272)
for (f591 = f592, f591_p_0 = 0;
	f591 < f592 + 28272;
	f591 += 28272, f591_p_0 += 28272){
	// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
	// T (c, 1) (1024 / 1024)
	for (c789 = c790, c789_p_0 = 0;
		c789 < c790 + 1024;
		c789 += 1024, c789_p_0 += 1024){
		// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
		// T (y, 1) (17 / 17)
		for (y591 = y592, y591_p_0 = 0;
			y591 < y592 + 17;
			y591 += 17, y591_p_0 += 17){
			// y = 17, x = 17, h = 1, w = 1, c = 1024, f = 28272
			// T (f, 589) (28272 / 48)
			for (f = f591, fp_1 = f591_p_0, fp_0 = 0;
				f < f591 + 28272;
				f += 48, fp_1 += 48, fp_0 += 48){
					for (y = y591, yp_1 = y591_p_0, yp_0 = 0;
						y < y591 + 10;
						y += 5, yp_1 += 5, yp_0 += 5){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 48
						// T (c, 2) (1024 / 512)
						for (c788 = c789, c788_p_1 = c789_p_0, c788_p_0 = 0;
							c788 < c789 + 1024;
							c788 += 512, c788_p_1 += 512, c788_p_0 += 512){
							// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 48
							// T (x, 17) (17 / 1)
							for (x = x394, xp_0 = 0;
								x < x394 + 17;
								x += 1, xp_0 += 1){
										mem_vec_8625 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8626 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8627 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8628 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8629 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8630 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8631 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8632 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8633 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8634 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8635 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8636 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8637 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8638 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8639 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 48
										// T (c, 512) (512 / 1)
										for (c = c788, cp_2 = c788_p_1, cp_1 = c788_p_0, cp_0 = 0;
											c < c788 + 512;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8625);
											mem_vec_8625 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8626);
											mem_vec_8626 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8627);
											mem_vec_8627 = vec_5;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_8 = _mm512_set1_ps(scal_1);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8628);
											mem_vec_8628 = vec_7;



											vec_9 = _mm512_fmadd_ps(vec_8, vec_4, mem_vec_8629);
											mem_vec_8629 = vec_9;



											vec_10 = _mm512_fmadd_ps(vec_8, vec_6, mem_vec_8630);
											mem_vec_8630 = vec_10;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_12 = _mm512_set1_ps(scal_2);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8631);
											mem_vec_8631 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8632);
											mem_vec_8632 = vec_13;



											vec_14 = _mm512_fmadd_ps(vec_12, vec_6, mem_vec_8633);
											mem_vec_8633 = vec_14;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_16 = _mm512_set1_ps(scal_3);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_8634);
											mem_vec_8634 = vec_15;



											vec_17 = _mm512_fmadd_ps(vec_16, vec_4, mem_vec_8635);
											mem_vec_8635 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_16, vec_6, mem_vec_8636);
											mem_vec_8636 = vec_18;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_20 = _mm512_set1_ps(scal_4);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8637);
											mem_vec_8637 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8638);
											mem_vec_8638 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8639);
											mem_vec_8639 = vec_22;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8625);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8626);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8627);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8628);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8629);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8630);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8631);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8632);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8633);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8634);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8635);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8636);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8637);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8638);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8639);
							}
						}
					}
					for (y = y591 + 10, yp_1 = y591_p_0, yp_0 = 0;
						y < y591 + 10 + 7;
						y += 7, yp_1 += 7, yp_0 += 7){
						// y = ph_y, x = 17, h = 1, w = 1, c = 1024, f = 48
						// T (c, 2) (1024 / 512)
						for (c788 = c789, c788_p_1 = c789_p_0, c788_p_0 = 0;
							c788 < c789 + 1024;
							c788 += 512, c788_p_1 += 512, c788_p_0 += 512){
							// y = ph_y, x = 17, h = 1, w = 1, c = 512, f = 48
							// T (x, 17) (17 / 1)
							for (x = x394, xp_0 = 0;
								x < x394 + 17;
								x += 1, xp_0 += 1){
										mem_vec_8640 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_8641 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_8642 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_8643 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_8644 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_8645 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_8646 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_8647 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_8648 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_8649 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_8650 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_8651 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_8652 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_8653 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_8654 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_8655 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_8656 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_8657 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_8658 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_8659 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_8660 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 512, f = 48
										// T (c, 512) (512 / 1)
										for (c = c788, cp_2 = c788_p_1, cp_1 = c788_p_0, cp_0 = 0;
											c < c788 + 512;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_8640);
											mem_vec_8640 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_8641);
											mem_vec_8641 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_8642);
											mem_vec_8642 = vec_5;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_8 = _mm512_set1_ps(scal_1);


											vec_7 = _mm512_fmadd_ps(vec_8, vec_2, mem_vec_8643);
											mem_vec_8643 = vec_7;



											vec_9 = _mm512_fmadd_ps(vec_8, vec_4, mem_vec_8644);
											mem_vec_8644 = vec_9;



											vec_10 = _mm512_fmadd_ps(vec_8, vec_6, mem_vec_8645);
											mem_vec_8645 = vec_10;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_12 = _mm512_set1_ps(scal_2);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_8646);
											mem_vec_8646 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_8647);
											mem_vec_8647 = vec_13;



											vec_14 = _mm512_fmadd_ps(vec_12, vec_6, mem_vec_8648);
											mem_vec_8648 = vec_14;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_16 = _mm512_set1_ps(scal_3);


											vec_15 = _mm512_fmadd_ps(vec_16, vec_2, mem_vec_8649);
											mem_vec_8649 = vec_15;



											vec_17 = _mm512_fmadd_ps(vec_16, vec_4, mem_vec_8650);
											mem_vec_8650 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_16, vec_6, mem_vec_8651);
											mem_vec_8651 = vec_18;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_20 = _mm512_set1_ps(scal_4);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_8652);
											mem_vec_8652 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_8653);
											mem_vec_8653 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_8654);
											mem_vec_8654 = vec_22;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_24 = _mm512_set1_ps(scal_5);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_8655);
											mem_vec_8655 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_8656);
											mem_vec_8656 = vec_25;



											vec_26 = _mm512_fmadd_ps(vec_24, vec_6, mem_vec_8657);
											mem_vec_8657 = vec_26;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_28 = _mm512_set1_ps(scal_6);


											vec_27 = _mm512_fmadd_ps(vec_28, vec_2, mem_vec_8658);
											mem_vec_8658 = vec_27;



											vec_29 = _mm512_fmadd_ps(vec_28, vec_4, mem_vec_8659);
											mem_vec_8659 = vec_29;



											vec_30 = _mm512_fmadd_ps(vec_28, vec_6, mem_vec_8660);
											mem_vec_8660 = vec_30;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_8640);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_8641);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_8642);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_8643);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_8644);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_8645);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_8646);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_8647);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_8648);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_8649);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_8650);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_8651);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_8652);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_8653);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_8654);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_8655);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_8656);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_8657);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_8658);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_8659);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_8660);
							}
						}
					}
			}
		}
	}
}


}