#include "../gen_conv.h"
#include "../reorder_avx2.h"

void gen_conv(M_TYPE * const  __restrict__ output,
M_TYPE const * const __restrict__ input, M_TYPE const * const __restrict__ params,
    IND_TYPE X, IND_TYPE W,
    IND_TYPE Y, IND_TYPE H,
	IND_TYPE C, IND_TYPE F) {
/*
[V f; U (2, f); ULambda y; T (256, c); Hoist_vars [c]; T (68, x); T (1, c);
  T (4, f); T (1, x); T (2, y); T (1, x);
  Lambda_apply y [((Iter 2), (Arg 10)); ((Iter 1), (Arg 14))]]
*/
IND_TYPE c, cp_0, c495_p_0, cp_1, c495, f, fp_0, x, xp_0, x660_p_0, x661_p_0, xp_1, x660_p_1, xp_2, x660, x661, y, yp_0, y495_p_0, yp_1, y495;

assert((Y == 68));
assert((X == 68));
assert((H == 1));
assert((W == 1));
assert((C == 256));
assert((F == 128));
IND_TYPE y496 = 0;
IND_TYPE x662 = 0;
IND_TYPE h = 0;
IND_TYPE w = 0;
IND_TYPE c496 = 0;
IND_TYPE f330 = 0;
float scal_0 ,scal_1 ,scal_10 ,scal_11 ,scal_12 ,scal_13 ,scal_2 ,scal_3 ,scal_4 ,scal_5 ,scal_6 ,scal_7 ,scal_8 ,scal_9;
__m512 mem_vec_7804 ,mem_vec_7805 ,mem_vec_7806 ,mem_vec_7807 ,mem_vec_7808 ,mem_vec_7809 ,mem_vec_7810 ,mem_vec_7811 ,mem_vec_7812 ,mem_vec_7813 ,mem_vec_7814 ,mem_vec_7815 ,mem_vec_7816 ,mem_vec_7817 ,mem_vec_7818 ,mem_vec_7819 ,mem_vec_7820 ,mem_vec_7821 ,mem_vec_7822 ,mem_vec_7823 ,mem_vec_7824 ,mem_vec_7825 ,mem_vec_7826 ,mem_vec_7827 ,mem_vec_7828 ,mem_vec_7829 ,mem_vec_7830 ,mem_vec_7831 ,mem_vec_7832 ,mem_vec_7833 ,mem_vec_7834 ,mem_vec_7835 ,mem_vec_7836 ,mem_vec_7837 ,mem_vec_7838 ,mem_vec_7839 ,mem_vec_7840 ,mem_vec_7841 ,mem_vec_7842 ,mem_vec_7843 ,mem_vec_7844 ,mem_vec_7845 ,mem_vec_7846 ,mem_vec_7847 ,mem_vec_7848 ,mem_vec_7849 ,mem_vec_7850 ,mem_vec_7851 ,vec_0 ,vec_1 ,vec_10 ,vec_11 ,vec_12 ,vec_13 ,vec_14 ,vec_15 ,vec_16 ,vec_17 ,vec_18 ,vec_19 ,vec_2 ,vec_20 ,vec_21 ,vec_22 ,vec_23 ,vec_24 ,vec_25 ,vec_26 ,vec_27 ,vec_28 ,vec_29 ,vec_3 ,vec_30 ,vec_31 ,vec_32 ,vec_33 ,vec_34 ,vec_35 ,vec_36 ,vec_37 ,vec_38 ,vec_39 ,vec_4 ,vec_40 ,vec_41 ,vec_42 ,vec_43 ,vec_5 ,vec_6 ,vec_7 ,vec_8 ,vec_9;
	for (y495 = y496, y495_p_0 = 0;
		y495 < y496 + 40;
		y495 += 20, y495_p_0 += 20){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x661 = x662, x661_p_0 = 0;
			x661 < x662 + 68;
			x661 += 68, x661_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y495, yp_1 = y495_p_0, yp_0 = 0;
				y < y495 + 20;
				y += 10, yp_1 += 10, yp_0 += 10){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x660 = x661, x660_p_1 = x661_p_0, x660_p_0 = 0;
					x660 < x661 + 68;
					x660 += 68, x660_p_1 += 68, x660_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f330, fp_0 = 0;
						f < f330 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c495 = c496, c495_p_0 = 0;
							c495 < c496 + 256;
							c495 += 256, c495_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
							// T (x, 68) (68 / 1)
							for (x = x660, xp_2 = x660_p_1, xp_1 = x660_p_0, xp_0 = 0;
								x < x660 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7804 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7805 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7806 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7807 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7808 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7809 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7810 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7811 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7812 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7813 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7814 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7815 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7816 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7817 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7818 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7819 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7820 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7821 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7822 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7823 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c495, cp_1 = c495_p_0, cp_0 = 0;
											c < c495 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7804);
											mem_vec_7804 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7805);
											mem_vec_7805 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7806);
											mem_vec_7806 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7807);
											mem_vec_7807 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7808);
											mem_vec_7808 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7809);
											mem_vec_7809 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7810);
											mem_vec_7810 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7811);
											mem_vec_7811 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7812);
											mem_vec_7812 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7813);
											mem_vec_7813 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7814);
											mem_vec_7814 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7815);
											mem_vec_7815 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7816);
											mem_vec_7816 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7817);
											mem_vec_7817 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7818);
											mem_vec_7818 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7819);
											mem_vec_7819 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7820);
											mem_vec_7820 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7821);
											mem_vec_7821 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7822);
											mem_vec_7822 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7823);
											mem_vec_7823 = vec_31;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7804);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7805);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7806);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7807);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7808);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7809);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7810);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7811);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7812);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7813);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7814);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7815);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7816);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7817);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7818);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7819);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7820);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7821);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7822);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7823);
							}
						}
					}
				}
			}
		}
	}
	for (y495 = y496 + 40, y495_p_0 = 0;
		y495 < y496 + 40 + 28;
		y495 += 28, y495_p_0 += 28){
		// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
		// T (x, 1) (68 / 68)
		for (x661 = x662, x661_p_0 = 0;
			x661 < x662 + 68;
			x661 += 68, x661_p_0 += 68){
			// y = 2 * ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
			// T (y, 2) (2 * ph_y / ph_y)
			for (y = y495, yp_1 = y495_p_0, yp_0 = 0;
				y < y495 + 28;
				y += 14, yp_1 += 14, yp_0 += 14){
				// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
				// T (x, 1) (68 / 68)
				for (x660 = x661, x660_p_1 = x661_p_0, x660_p_0 = 0;
					x660 < x661 + 68;
					x660 += 68, x660_p_1 += 68, x660_p_0 += 68){
					// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 128
					// T (f, 4) (128 / 32)
					for (f = f330, fp_0 = 0;
						f < f330 + 128;
						f += 32, fp_0 += 32){
						// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
						// T (c, 1) (256 / 256)
						for (c495 = c496, c495_p_0 = 0;
							c495 < c496 + 256;
							c495 += 256, c495_p_0 += 256){
							// y = ph_y, x = 68, h = 1, w = 1, c = 256, f = 32
							// T (x, 68) (68 / 1)
							for (x = x660, xp_2 = x660_p_1, xp_1 = x660_p_0, xp_0 = 0;
								x < x660 + 68;
								x += 1, xp_2 += 1, xp_1 += 1, xp_0 += 1){
										mem_vec_7824 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f]);
										mem_vec_7825 = _mm512_loadu_ps(&output[(F * Y) * x + F * y + f + 16]);
										mem_vec_7826 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f]);
										mem_vec_7827 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16]);
										mem_vec_7828 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f]);
										mem_vec_7829 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16]);
										mem_vec_7830 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f]);
										mem_vec_7831 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16]);
										mem_vec_7832 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f]);
										mem_vec_7833 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16]);
										mem_vec_7834 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f]);
										mem_vec_7835 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16]);
										mem_vec_7836 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f]);
										mem_vec_7837 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16]);
										mem_vec_7838 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f]);
										mem_vec_7839 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16]);
										mem_vec_7840 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f]);
										mem_vec_7841 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16]);
										mem_vec_7842 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f]);
										mem_vec_7843 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16]);
										mem_vec_7844 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f]);
										mem_vec_7845 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16]);
										mem_vec_7846 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f]);
										mem_vec_7847 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16]);
										mem_vec_7848 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f]);
										mem_vec_7849 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16]);
										mem_vec_7850 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f]);
										mem_vec_7851 = _mm512_loadu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16]);
										// y = ph_y, x = 1, h = 1, w = 1, c = 256, f = 32
										// T (c, 256) (256 / 1)
										for (c = c495, cp_1 = c495_p_0, cp_0 = 0;
											c < c495 + 256;
											c += 1, cp_1 += 1, cp_0 += 1){
											scal_0 = input[(C * (Y + H - 1)) * (x + w) + C * (y + h) + c];
											vec_1 = _mm512_set1_ps(scal_0);
											vec_2 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f]);

											vec_0 = _mm512_fmadd_ps(vec_1, vec_2, mem_vec_7824);
											mem_vec_7824 = vec_0;

											vec_4 = _mm512_loadu_ps(&params[((F * C) * H) * w + (F * C) * h + F * c + f + 16]);

											vec_3 = _mm512_fmadd_ps(vec_1, vec_4, mem_vec_7825);
											mem_vec_7825 = vec_3;
											scal_1 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 1 + h) + c];
											vec_6 = _mm512_set1_ps(scal_1);


											vec_5 = _mm512_fmadd_ps(vec_6, vec_2, mem_vec_7826);
											mem_vec_7826 = vec_5;



											vec_7 = _mm512_fmadd_ps(vec_6, vec_4, mem_vec_7827);
											mem_vec_7827 = vec_7;
											scal_2 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 2 + h) + c];
											vec_9 = _mm512_set1_ps(scal_2);


											vec_8 = _mm512_fmadd_ps(vec_9, vec_2, mem_vec_7828);
											mem_vec_7828 = vec_8;



											vec_10 = _mm512_fmadd_ps(vec_9, vec_4, mem_vec_7829);
											mem_vec_7829 = vec_10;
											scal_3 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 3 + h) + c];
											vec_12 = _mm512_set1_ps(scal_3);


											vec_11 = _mm512_fmadd_ps(vec_12, vec_2, mem_vec_7830);
											mem_vec_7830 = vec_11;



											vec_13 = _mm512_fmadd_ps(vec_12, vec_4, mem_vec_7831);
											mem_vec_7831 = vec_13;
											scal_4 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 4 + h) + c];
											vec_15 = _mm512_set1_ps(scal_4);


											vec_14 = _mm512_fmadd_ps(vec_15, vec_2, mem_vec_7832);
											mem_vec_7832 = vec_14;



											vec_16 = _mm512_fmadd_ps(vec_15, vec_4, mem_vec_7833);
											mem_vec_7833 = vec_16;
											scal_5 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 5 + h) + c];
											vec_18 = _mm512_set1_ps(scal_5);


											vec_17 = _mm512_fmadd_ps(vec_18, vec_2, mem_vec_7834);
											mem_vec_7834 = vec_17;



											vec_19 = _mm512_fmadd_ps(vec_18, vec_4, mem_vec_7835);
											mem_vec_7835 = vec_19;
											scal_6 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 6 + h) + c];
											vec_21 = _mm512_set1_ps(scal_6);


											vec_20 = _mm512_fmadd_ps(vec_21, vec_2, mem_vec_7836);
											mem_vec_7836 = vec_20;



											vec_22 = _mm512_fmadd_ps(vec_21, vec_4, mem_vec_7837);
											mem_vec_7837 = vec_22;
											scal_7 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 7 + h) + c];
											vec_24 = _mm512_set1_ps(scal_7);


											vec_23 = _mm512_fmadd_ps(vec_24, vec_2, mem_vec_7838);
											mem_vec_7838 = vec_23;



											vec_25 = _mm512_fmadd_ps(vec_24, vec_4, mem_vec_7839);
											mem_vec_7839 = vec_25;
											scal_8 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 8 + h) + c];
											vec_27 = _mm512_set1_ps(scal_8);


											vec_26 = _mm512_fmadd_ps(vec_27, vec_2, mem_vec_7840);
											mem_vec_7840 = vec_26;



											vec_28 = _mm512_fmadd_ps(vec_27, vec_4, mem_vec_7841);
											mem_vec_7841 = vec_28;
											scal_9 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 9 + h) + c];
											vec_30 = _mm512_set1_ps(scal_9);


											vec_29 = _mm512_fmadd_ps(vec_30, vec_2, mem_vec_7842);
											mem_vec_7842 = vec_29;



											vec_31 = _mm512_fmadd_ps(vec_30, vec_4, mem_vec_7843);
											mem_vec_7843 = vec_31;
											scal_10 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 10 + h) + c];
											vec_33 = _mm512_set1_ps(scal_10);


											vec_32 = _mm512_fmadd_ps(vec_33, vec_2, mem_vec_7844);
											mem_vec_7844 = vec_32;



											vec_34 = _mm512_fmadd_ps(vec_33, vec_4, mem_vec_7845);
											mem_vec_7845 = vec_34;
											scal_11 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 11 + h) + c];
											vec_36 = _mm512_set1_ps(scal_11);


											vec_35 = _mm512_fmadd_ps(vec_36, vec_2, mem_vec_7846);
											mem_vec_7846 = vec_35;



											vec_37 = _mm512_fmadd_ps(vec_36, vec_4, mem_vec_7847);
											mem_vec_7847 = vec_37;
											scal_12 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 12 + h) + c];
											vec_39 = _mm512_set1_ps(scal_12);


											vec_38 = _mm512_fmadd_ps(vec_39, vec_2, mem_vec_7848);
											mem_vec_7848 = vec_38;



											vec_40 = _mm512_fmadd_ps(vec_39, vec_4, mem_vec_7849);
											mem_vec_7849 = vec_40;
											scal_13 = input[(C * (Y + H - 1)) * (x + w) + C * (y + 13 + h) + c];
											vec_42 = _mm512_set1_ps(scal_13);


											vec_41 = _mm512_fmadd_ps(vec_42, vec_2, mem_vec_7850);
											mem_vec_7850 = vec_41;



											vec_43 = _mm512_fmadd_ps(vec_42, vec_4, mem_vec_7851);
											mem_vec_7851 = vec_43;
										}
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f], mem_vec_7824);
									_mm512_storeu_ps(&output[(F * Y) * x + F * y + f + 16], mem_vec_7825);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f], mem_vec_7826);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 1) + f + 16], mem_vec_7827);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f], mem_vec_7828);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 2) + f + 16], mem_vec_7829);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f], mem_vec_7830);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 3) + f + 16], mem_vec_7831);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f], mem_vec_7832);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 4) + f + 16], mem_vec_7833);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f], mem_vec_7834);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 5) + f + 16], mem_vec_7835);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f], mem_vec_7836);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 6) + f + 16], mem_vec_7837);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f], mem_vec_7838);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 7) + f + 16], mem_vec_7839);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f], mem_vec_7840);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 8) + f + 16], mem_vec_7841);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f], mem_vec_7842);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 9) + f + 16], mem_vec_7843);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f], mem_vec_7844);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 10) + f + 16], mem_vec_7845);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f], mem_vec_7846);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 11) + f + 16], mem_vec_7847);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f], mem_vec_7848);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 12) + f + 16], mem_vec_7849);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f], mem_vec_7850);
									_mm512_storeu_ps(&output[(F * Y) * x + F * (y + 13) + f + 16], mem_vec_7851);
							}
						}
					}
				}
			}
		}
	}


}