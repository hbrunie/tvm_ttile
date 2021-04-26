#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (64, c); Hoist_vars [c]; T (2, x); T (8, c);
  T (17, x); T (1, y); T (8, f); T (1, x);
  Lambda_apply y [((Iter 1), (Arg 8)); ((Iter 2), (Arg 13))]]
*/
IND_TYPE c, cp_0, c51_p_0, cp_1, c51, f, fp_0, x, xp_0, x68_p_0, x69_p_0, xp_1, x68_p_1, xp_2, x68, x69, y, yp_0, y43_p_0, yp_1, y43;

assert((Y == 34));
assert((X == 34));
assert((H == 1));
assert((W == 1));
assert((C == 512));
assert((F == 256));
IND_TYPE y44 = 0;
IND_TYPE x70 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c52 = 0;
IND_TYPE f34 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_794 ,mem_vec_795 ,mem_vec_796 ,mem_vec_797 ,mem_vec_798 ,mem_vec_799 ,mem_vec_800 ,mem_vec_801 ,mem_vec_802 ,mem_vec_803 ,mem_vec_804 ,mem_vec_805 ,mem_vec_806 ,mem_vec_807 ,mem_vec_808 ,mem_vec_809 ,mem_vec_810 ,mem_vec_811 ,mem_vec_812 ,mem_vec_813 ,mem_vec_814 ,mem_vec_815 ,mem_vec_816 ,mem_vec_817 ,mem_vec_818 ,mem_vec_819 ,mem_vec_820 ,mem_vec_821 ,mem_vec_822 ,mem_vec_823 ,mem_vec_824 ,mem_vec_825 ,mem_vec_826 ,mem_vec_827 ,mem_vec_828 ,mem_vec_829 ,mem_vec_830 ,mem_vec_831 ,mem_vec_832 ,mem_vec_833 ,mem_vec_834 ,mem_vec_835 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y43 = y44, y43_p_0 = 0;
		y43 < y44 + 8;
		y43 += 8, y43_p_0 += 8){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x69 = x70, x69_p_0 = 0;
			x69 < x70 + 34;
			x69 += 34, x69_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f34, fp_0 = 0;
				f < f34 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y43, yp_1 = y43_p_0, yp_0 = 0;
					y < y43 + 8;
					y += 8, yp_1 += 8, yp_0 += 8){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x68 = x69, x68_p_1 = x69_p_0, x68_p_0 = 0;
						x68 < x69 + 34;
						x68 += 2, x68_p_1 += 2, x68_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (c, 8) (512 / 64)
						for (c51 = c52, c51_p_0 = 0;
							c51 < c52 + 512;
							c51 += 64, c51_p_0 += 64){
							// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (x, 2) (2 / 1)
							for (x = x68, xp_2 = x68_p_1, xp_1 = x68_p_0, xp_0 = 0;
								x < x68 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_794 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_795 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_796 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_797 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_798 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_799 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_800 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_801 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_802 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_803 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_804 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_805 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
											c < c51 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_794);
											mem_vec_794 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_795);
											mem_vec_795 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_796);
											mem_vec_796 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_797);
											mem_vec_797 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_798);
											mem_vec_798 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_799);
											mem_vec_799 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_800);
											mem_vec_800 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_801);
											mem_vec_801 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_802);
											mem_vec_802 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_803);
											mem_vec_803 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_804);
											mem_vec_804 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_805);
											mem_vec_805 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_806);
											mem_vec_806 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_807);
											mem_vec_807 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_808);
											mem_vec_808 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_809);
											mem_vec_809 = vec_25;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_794);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_795);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_796);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_797);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_798);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_799);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_800);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_801);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_802);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_803);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_804);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_805);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_806);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_807);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_808);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_809);
							}
						}
					}
				}
			}
		}
	}
	for (y43 = y44 + 8, y43_p_0 = 0;
		y43 < y44 + 8 + 26;
		y43 += 13, y43_p_0 += 13){
		// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
		// T (x, 1) (34 / 34)
		for (x69 = x70, x69_p_0 = 0;
			x69 < x70 + 34;
			x69 += 34, x69_p_0 += 34){
			// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 256
			// T (f, 8) (256 / 32)
			for (f = f34, fp_0 = 0;
				f < f34 + 256;
				f += 32, fp_0 += 32){
				// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
				// T (y, 1) (ph_y / ph_y)
				for (y = y43, yp_1 = y43_p_0, yp_0 = 0;
					y < y43 + 13;
					y += 13, yp_1 += 13, yp_0 += 13){
					// y = ph_y, x = 34, h = 1, w = 1, c = 512, f = 32
					// T (x, 17) (34 / 2)
					for (x68 = x69, x68_p_1 = x69_p_0, x68_p_0 = 0;
						x68 < x69 + 34;
						x68 += 2, x68_p_1 += 2, x68_p_0 += 2){
						// y = ph_y, x = 2, h = 1, w = 1, c = 512, f = 32
						// T (c, 8) (512 / 64)
						for (c51 = c52, c51_p_0 = 0;
							c51 < c52 + 512;
							c51 += 64, c51_p_0 += 64){
							// y = ph_y, x = 2, h = 1, w = 1, c = 64, f = 32
							// T (x, 2) (2 / 1)
							for (x = x68, xp_2 = x68_p_1, xp_1 = x68_p_0, xp_0 = 0;
								x < x68 + 2;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_810 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_811 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_824 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_825 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 64, f = 32
										// T (c, 64) (64 / 1)
										for (c = c51, cp_1 = c51_p_0, cp_0 = 0;
											c < c51 + 64;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_810);
											mem_vec_810 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_811);
											mem_vec_811 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_812);
											mem_vec_812 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_813);
											mem_vec_813 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_814);
											mem_vec_814 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_815);
											mem_vec_815 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_816);
											mem_vec_816 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_817);
											mem_vec_817 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_818);
											mem_vec_818 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_819);
											mem_vec_819 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_820);
											mem_vec_820 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_821);
											mem_vec_821 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_822);
											mem_vec_822 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_823);
											mem_vec_823 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_824);
											mem_vec_824 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_825);
											mem_vec_825 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_826);
											mem_vec_826 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_827);
											mem_vec_827 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_828);
											mem_vec_828 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_829);
											mem_vec_829 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_830);
											mem_vec_830 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_831);
											mem_vec_831 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_832);
											mem_vec_832 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_833);
											mem_vec_833 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_834);
											mem_vec_834 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_835);
											mem_vec_835 = vec_40;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_810);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_811);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_812);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_813);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_814);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_815);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_816);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_817);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_818);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_819);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_820);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_821);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_822);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_823);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_824);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_825);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_826);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_827);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_829);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_830);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_831);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_832);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_833);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_834);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_835);
							}
						}
					}
				}
			}
		}
	}


}