#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (32, c); Hoist_vars [c]; T (3, w); T (3, h);
  T (7, x); T (2, c); T (1, y); T (16, f); T (2, c); T (8, c)]
*/
IND_TYPE c, cp_0, c835_p_0, c836_p_0, c837_p_0, cp_1, c835_p_1, c836_p_1, cp_2, c835_p_2, cp_3, c835, c836, c837, f, fp_0, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y334 = 0;
IND_TYPE x334 = 0;
IND_TYPE h277 = 0;
IND_TYPE w281 = 0;
IND_TYPE c838 = 0;
IND_TYPE f334 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_4676 ,mem_vec_4677 ,mem_vec_4678 ,mem_vec_4679 ,mem_vec_4680 ,mem_vec_4681 ,mem_vec_4682 ,mem_vec_4683 ,mem_vec_4684 ,mem_vec_4685 ,mem_vec_4686 ,mem_vec_4687 ,mem_vec_4688 ,mem_vec_4689 ,mem_vec_4690 ,mem_vec_4691 ,mem_vec_4692 ,mem_vec_4693 ,mem_vec_4694 ,mem_vec_4695 ,mem_vec_4696 ,mem_vec_4697 ,mem_vec_4698 ,mem_vec_4699 ,mem_vec_4700 ,mem_vec_4701 ,mem_vec_4702 ,mem_vec_4703 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (c, 8) (1024 / 128)
for (c837 = c838, c837_p_0 = 0;
	c837 < c838 + 1024;
	c837 += 128, c837_p_0 += 128){
	// y = 7, x = 7, h = 3, w = 3, c = 128, f = 1024
	// T (c, 2) (128 / 64)
	for (c836 = c837, c836_p_1 = c837_p_0, c836_p_0 = 0;
		c836 < c837 + 128;
		c836 += 64, c836_p_1 += 64, c836_p_0 += 64){
		// y = 7, x = 7, h = 3, w = 3, c = 64, f = 1024
		// T (f, 16) (1024 / 64)
		for (f = f334, fp_0 = 0;
			f < f334 + 1024;
			f += 64, fp_0 += 64){
			// y = 7, x = 7, h = 3, w = 3, c = 64, f = 64
			// T (y, 1) (7 / 7)
			for (y = y334, yp_0 = 0;
				y < y334 + 7;
				y += 7, yp_0 += 7){
				// y = 7, x = 7, h = 3, w = 3, c = 64, f = 64
				// T (c, 2) (64 / 32)
				for (c835 = c836, c835_p_2 = c836_p_1, c835_p_1 = c836_p_0, c835_p_0 = 0;
					c835 < c836 + 64;
					c835 += 32, c835_p_2 += 32, c835_p_1 += 32, c835_p_0 += 32){
					// y = 7, x = 7, h = 3, w = 3, c = 32, f = 64
					// T (x, 7) (7 / 1)
					for (x = x334, xp_0 = 0;
						x < x334 + 7;
						x += 1, xp_0 += 1){
						// y = 7, x = 1, h = 3, w = 3, c = 32, f = 64
						// T (h, 3) (3 / 1)
						for (h = h277, hp_0 = 0;
							h < h277 + 3;
							h += 1, hp_0 += 1){
							// y = 7, x = 1, h = 1, w = 3, c = 32, f = 64
							// T (w, 3) (3 / 1)
							for (w = w281, wp_0 = 0;
								w < w281 + 3;
								w += 1, wp_0 += 1){
										mem_vec_4676 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_4677 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_4678 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_4679 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_4680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_4681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_4682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_4683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_4684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_4685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_4686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_4687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_4688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_4689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_4690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_4691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_4692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_4693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_4694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_4695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_4696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_4697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_4698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_4699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_4700 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_4701 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_4702 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_4703 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 32, f = 64
										// T (c, 32) (32 / 1)
										for (c = c835, cp_3 = c835_p_2, cp_2 = c835_p_1, cp_1 = c835_p_0, cp_0 = 0;
											c < c835 + 32;
											c += 1, cp_3 += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_4676);
											mem_vec_4676 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_4677);
											mem_vec_4677 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_4678);
											mem_vec_4678 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_4679);
											mem_vec_4679 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_4680);
											mem_vec_4680 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_4681);
											mem_vec_4681 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_4682);
											mem_vec_4682 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_4683);
											mem_vec_4683 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_4684);
											mem_vec_4684 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_4685);
											mem_vec_4685 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_4686);
											mem_vec_4686 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_4687);
											mem_vec_4687 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_4688);
											mem_vec_4688 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_4689);
											mem_vec_4689 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_4690);
											mem_vec_4690 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_4691);
											mem_vec_4691 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_4692);
											mem_vec_4692 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_4693);
											mem_vec_4693 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_4694);
											mem_vec_4694 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_4695);
											mem_vec_4695 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_4696);
											mem_vec_4696 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_4697);
											mem_vec_4697 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_4698);
											mem_vec_4698 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_4699);
											mem_vec_4699 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_4700);
											mem_vec_4700 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_4701);
											mem_vec_4701 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_4702);
											mem_vec_4702 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_4703);
											mem_vec_4703 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_4676);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_4677);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_4678);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_4679);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_4680);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_4681);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_4682);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_4683);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_4684);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_4685);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_4686);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_4687);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_4688);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_4689);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_4690);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_4691);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_4692);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_4693);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_4694);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_4695);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_4696);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_4697);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_4698);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_4699);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_4700);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_4701);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_4702);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_4703);
							}
						}
					}
				}
			}
		}
	}
}


}