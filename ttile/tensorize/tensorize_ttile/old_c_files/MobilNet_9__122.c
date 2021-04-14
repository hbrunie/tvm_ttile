#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (4, f); U (7, y); T (512, c); Hoist_vars [c]; T (7, x); T (3, w);
  T (3, h); T (1, c); T (8, f); T (1, y); T (2, c); T (2, f)]
*/
IND_TYPE c, cp_0, c96_p_0, c97_p_0, cp_1, c96_p_1, cp_2, c96, c97, f, fp_0, f72_p_0, fp_1, f72, h, hp_0, w, wp_0, x, xp_0, y, yp_0;

assert((Y == 7));
assert((X == 7));
assert((H == 3));
assert((W == 3));
assert((C == 1024));
assert((F == 1024));
IND_TYPE y48 = 0;
IND_TYPE x48 = 0;
IND_TYPE h48 = 0;
IND_TYPE w48 = 0;
IND_TYPE c98 = 0;
IND_TYPE f73 = 0;
float scal_0 ,scal_1 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6;
__m512 mem_vec_672 ,mem_vec_673 ,mem_vec_674 ,mem_vec_675 ,mem_vec_676 ,mem_vec_677 ,mem_vec_678 ,mem_vec_679 ,mem_vec_680 ,mem_vec_681 ,mem_vec_682 ,mem_vec_683 ,mem_vec_684 ,mem_vec_685 ,mem_vec_686 ,mem_vec_687 ,mem_vec_688 ,mem_vec_689 ,mem_vec_690 ,mem_vec_691 ,mem_vec_692 ,mem_vec_693 ,mem_vec_694 ,mem_vec_695 ,mem_vec_696 ,mem_vec_697 ,mem_vec_698 ,mem_vec_699 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_4 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 1024
// T (f, 2) (1024 / 512)
for (f72 = f73, f72_p_0 = 0;
	f72 < f73 + 1024;
	f72 += 512, f72_p_0 += 512){
	// y = 7, x = 7, h = 3, w = 3, c = 1024, f = 512
	// T (c, 2) (1024 / 512)
	for (c97 = c98, c97_p_0 = 0;
		c97 < c98 + 1024;
		c97 += 512, c97_p_0 += 512){
		// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
		// T (y, 1) (7 / 7)
		for (y = y48, yp_0 = 0;
			y < y48 + 7;
			y += 7, yp_0 += 7){
			// y = 7, x = 7, h = 3, w = 3, c = 512, f = 512
			// T (f, 8) (512 / 64)
			for (f = f72, fp_1 = f72_p_0, fp_0 = 0;
				f < f72 + 512;
				f += 64, fp_1 += 64, fp_0 += 64){
				// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
				// T (c, 1) (512 / 512)
				for (c96 = c97, c96_p_1 = c97_p_0, c96_p_0 = 0;
					c96 < c97 + 512;
					c96 += 512, c96_p_1 += 512, c96_p_0 += 512){
					// y = 7, x = 7, h = 3, w = 3, c = 512, f = 64
					// T (h, 3) (3 / 1)
					for (h = h48, hp_0 = 0;
						h < h48 + 3;
						h += 1, hp_0 += 1){
						// y = 7, x = 7, h = 1, w = 3, c = 512, f = 64
						// T (w, 3) (3 / 1)
						for (w = w48, wp_0 = 0;
							w < w48 + 3;
							w += 1, wp_0 += 1){
							// y = 7, x = 7, h = 1, w = 1, c = 512, f = 64
							// T (x, 7) (7 / 1)
							for (x = x48, xp_0 = 0;
								x < x48 + 7;
								x += 1, xp_0 += 1){
										mem_vec_672 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_673 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_674 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 32]);
										mem_vec_675 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 48]);
										mem_vec_676 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_677 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_678 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32]);
										mem_vec_679 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48]);
										mem_vec_680 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_681 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_682 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32]);
										mem_vec_683 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48]);
										mem_vec_684 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_685 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_686 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32]);
										mem_vec_687 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48]);
										mem_vec_688 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_689 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_690 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32]);
										mem_vec_691 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48]);
										mem_vec_692 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_693 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_694 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32]);
										mem_vec_695 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48]);
										mem_vec_696 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_697 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_698 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32]);
										mem_vec_699 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48]);
										// y = 7, x = 1, h = 1, w = 1, c = 512, f = 64
										// T (c, 512) (512 / 1)
										for (c = c96, cp_2 = c96_p_1, cp_1 = c96_p_0, cp_0 = 0;
											c < c96 + 512;
											c += 1, cp_2 += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_672);
											mem_vec_672 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_673);
											mem_vec_673 = vec_3;

											vec_6 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 32]);

											vec_5 = _mm512_fmadd_ps(vec_1, vec_6, mem_vec_674);
											mem_vec_674 = vec_5;

											vec_8 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 48]);

											vec_7 = _mm512_fmadd_ps(vec_1, vec_8, mem_vec_675);
											mem_vec_675 = vec_7;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_10 = _mm512_set1_ps(scal_1);


											vec_9 = _mm512_fmadd_ps(vec_10, vec_2, mem_vec_676);
											mem_vec_676 = vec_9;



											vec_11 = _mm512_fmadd_ps(vec_10, vec_4, mem_vec_677);
											mem_vec_677 = vec_11;



											vec_12 = _mm512_fmadd_ps(vec_10, vec_6, mem_vec_678);
											mem_vec_678 = vec_12;



											vec_13 = _mm512_fmadd_ps(vec_10, vec_8, mem_vec_679);
											mem_vec_679 = vec_13;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_15 = _mm512_set1_ps(scal_2);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_680);
											mem_vec_680 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_681);
											mem_vec_681 = vec_16;



											vec_17 = _mm512_fmadd_ps(vec_15, vec_6, mem_vec_682);
											mem_vec_682 = vec_17;



											vec_18 = _mm512_fmadd_ps(vec_15, vec_8, mem_vec_683);
											mem_vec_683 = vec_18;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_20 = _mm512_set1_ps(scal_3);


											vec_19 = _mm512_fmadd_ps(vec_20, vec_2, mem_vec_684);
											mem_vec_684 = vec_19;



											vec_21 = _mm512_fmadd_ps(vec_20, vec_4, mem_vec_685);
											mem_vec_685 = vec_21;



											vec_22 = _mm512_fmadd_ps(vec_20, vec_6, mem_vec_686);
											mem_vec_686 = vec_22;



											vec_23 = _mm512_fmadd_ps(vec_20, vec_8, mem_vec_687);
											mem_vec_687 = vec_23;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_25 = _mm512_set1_ps(scal_4);


											vec_24 = _mm512_fmadd_ps(vec_25, vec_2, mem_vec_688);
											mem_vec_688 = vec_24;



											vec_26 = _mm512_fmadd_ps(vec_25, vec_4, mem_vec_689);
											mem_vec_689 = vec_26;



											vec_27 = _mm512_fmadd_ps(vec_25, vec_6, mem_vec_690);
											mem_vec_690 = vec_27;



											vec_28 = _mm512_fmadd_ps(vec_25, vec_8, mem_vec_691);
											mem_vec_691 = vec_28;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_30 = _mm512_set1_ps(scal_5);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_692);
											mem_vec_692 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_693);
											mem_vec_693 = vec_31;



											vec_32 = _mm512_fmadd_ps(vec_30, vec_6, mem_vec_694);
											mem_vec_694 = vec_32;



											vec_33 = _mm512_fmadd_ps(vec_30, vec_8, mem_vec_695);
											mem_vec_695 = vec_33;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_35 = _mm512_set1_ps(scal_6);


											vec_34 = _mm512_fmadd_ps(vec_35, vec_2, mem_vec_696);
											mem_vec_696 = vec_34;



											vec_36 = _mm512_fmadd_ps(vec_35, vec_4, mem_vec_697);
											mem_vec_697 = vec_36;



											vec_37 = _mm512_fmadd_ps(vec_35, vec_6, mem_vec_698);
											mem_vec_698 = vec_37;



											vec_38 = _mm512_fmadd_ps(vec_35, vec_8, mem_vec_699);
											mem_vec_699 = vec_38;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_672);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_673);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 32], mem_vec_674);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 48], mem_vec_675);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_676);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_677);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 32], mem_vec_678);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 48], mem_vec_679);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_680);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_681);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 32], mem_vec_682);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 48], mem_vec_683);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_684);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_685);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 32], mem_vec_686);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 48], mem_vec_687);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_688);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_689);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 32], mem_vec_690);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 48], mem_vec_691);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_692);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_693);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 32], mem_vec_694);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 48], mem_vec_695);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_696);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_697);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 32], mem_vec_698);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 48], mem_vec_699);
							}
						}
					}
				}
			}
		}
	}
}


}